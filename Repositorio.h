#pragma once
// Plantilla generica de coleccion con propiedad (ownership) de sus elementos.
// Se usa en TODOS los modulos: pacientes, medicos, sedes, citas, comprobantes, etc.
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <map>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T>
class Repositorio {
    std::vector<std::unique_ptr<T>> elementos_;
public:
    Repositorio() = default;
    Repositorio(const Repositorio&) = delete;
    Repositorio& operator=(const Repositorio&) = delete;

    T* agregar(std::unique_ptr<T> elemento) {
        elementos_.push_back(std::move(elemento));
        return elementos_.back().get();
    }

    template <typename Predicado>
    T* buscar(Predicado cumple) const {
        for (const auto& e : elementos_) if (cumple(*e)) return e.get();
        return nullptr;
    }

    template <typename Predicado>
    std::vector<T*> filtrar(Predicado cumple) const {
        std::vector<T*> r;
        for (const auto& e : elementos_) if (cumple(*e)) r.push_back(e.get());
        return r;
    }

    template <typename Predicado>
    int contar(Predicado cumple) const {
        int n = 0;
        for (const auto& e : elementos_) if (cumple(*e)) ++n;
        return n;
    }

    std::size_t tamano() const { return elementos_.size(); }
    bool vacio() const { return elementos_.empty(); }
    auto begin() const { return elementos_.begin(); }
    auto end() const { return elementos_.end(); }
};

// Agrupa y cuenta los elementos de cualquier contenedor segun una clave calculada.
template <typename Contenedor, typename FuncionClave>
auto contarPor(const Contenedor& contenedor, FuncionClave claveDe) {
    using Clave = std::decay_t<decltype(claveDe(**std::begin(contenedor)))>;
    std::map<Clave, int> conteo;
    for (const auto& e : contenedor) ++conteo[claveDe(*e)];
    return conteo;
}

// Ordena un conteo de mayor a menor (desempate por clave) para rankings.
template <typename Clave>
std::vector<std::pair<Clave, int>> ordenarPorConteo(const std::map<Clave, int>& conteo) {
    std::vector<std::pair<Clave, int>> v(conteo.begin(), conteo.end());
    std::stable_sort(v.begin(), v.end(),
                     [](const auto& a, const auto& b) { return a.second > b.second; });
    return v;
}

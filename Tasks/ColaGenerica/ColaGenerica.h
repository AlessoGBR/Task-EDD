#ifndef COLA_GENERICA_H
#define COLA_GENERICA_H

#include <iostream>
#include <stdexcept>

template<typename T>
class ColaGenerica {
private:
    T *elementos;
    int capacidad;
    int frente;
    int final;
    int cantidad;

public:
    ColaGenerica(int tamanio) : capacidad(tamanio), frente(0), final(-1), cantidad(0) {
        elementos = new T[capacidad];
    }

    ~ColaGenerica() {
        delete[] elementos;
    }

    void encolar(T dato) {
        if (estaLlena()) {
            std::cout << "LA COLA YA SE ENCUENTRA LLENA \n";
        }
        final = (final + 1) % capacidad;
        elementos[final] = dato;
        cantidad++;
    }

    T desencolar() {
        if (estaVacia()) {
            std::cout << "LA COLA ESTA VACIA \n";
        }
        T dato = elementos[frente];
        frente = (frente + 1) % capacidad;
        cantidad--;
        return dato;
    }

    bool estaVacia() const {
        return cantidad == 0;
    }

    bool estaLlena() const {
        return cantidad == capacidad;
    }

    void mostrar() const {
        if (estaVacia()) {
            std::cout << "COLA VACIA" << std::endl;
            return;
        }
        int index = frente;
        for (int i = 0; i < cantidad; i++) {
            std::cout << elementos[index] << " ";
            index = (index + 1) % capacidad;
        }
        std::cout << std::endl;
    }
};

#endif // COLA_GENERICA_H

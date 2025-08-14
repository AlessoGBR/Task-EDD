#include <iostream>
#include <string>
#include "ColaGenerica/ColaGenerica.h"

using namespace std;

template<typename T>
void menuCola(ColaGenerica<T> &cola) {
    int opcion;
    T valor;
    do {
        cout << "\n=====================" << endl;
        cout << "OPCIONES CON LA COLA" << endl;
        cout << "1. ENCOLAR" << endl;
        cout << "2. DESENCOLAR" << endl;
        cout << "3. IMPRIMIR COLA" << endl;
        cout << "4. VERIFICAR SI ESTA VACIA" << endl;
        cout << "5. SALIR" << endl;
        cout << "OPCION: " << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (!cola.estaLlena()) {
                    cout << "\n=====================" << endl;
                    cout << "VALOR A ENCOLAR:" << endl;
                    cin >> valor;
                    cola.encolar(valor);
                } else {
                    cout << "\n=====================" << endl;
                    cout << "LA COLA YA SE ENCUENTRA LLENA" << endl;
                }
                break;
            case 2:
                cout << "\n=====================" << endl;
                cout << "VALOR DESENCOLADO: " << cola.desencolar() << endl;
                break;
            case 3:
                cout << "\n=====================" << endl;
                cola.mostrar();
                break;
            case 4:
                cout << "\n=====================" << endl;
                cout << (cola.estaVacia() ? "VACIA" : "NO VACIA") << endl;
                break;
        }
    } while (opcion != 5);
}

int main() {
    int tamanio, tipo;
    cout << "\n=====================" << endl;
    cout << "INGRESE EL TAMANIO DE LA COLA" << endl;
    cin >> tamanio;
    cout << "\n=====================" << endl;
    cout << "TIPO DE DATOS DE LA COLA:\n1. ENTEROS\n2. STRINGS\n3. CARACTERES\n4. BOOLEANOS\nOPCION: ";
    cin >> tipo;

    switch (tipo) {
        case 1: {
            ColaGenerica<int> cola(tamanio);
            menuCola(cola);
            break;
        }
        case 2: {
            ColaGenerica<string> cola(tamanio);
            menuCola(cola);
            break;
        }
        case 3: {
            ColaGenerica<char> cola(tamanio);
            menuCola(cola);
            break;
        }
        case 4: {
            ColaGenerica<bool> cola(tamanio);
            menuCola(cola);
            break;
        }
        default:
            cout << "\n=====================" << endl;
            cout << "OPCION INVALIDA" << endl;
    }

    return 0;
}

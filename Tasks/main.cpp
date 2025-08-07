#include <iostream>
using namespace std;

//METODO DE BURBUJA USANDO PUNTEROS
void ordenarBurbujaPunteros(int *inicio, int *fin) {
    for (int *i = inicio; i != fin; i++) {
        for (int *j = inicio; j < fin - 1; j++) {
            if (*j > *(j + 1)) {
                int temp = *j;
                *j = *(j + 1);
                *(j + 1) = temp;
            }
        }
    }
}

// BUSQUEDA BINARIA
int busquedaBinaria(int arreglo[], int tamanio, int valor) {
    int izquierda = 0;
    int derecha = tamanio - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arreglo[medio] == valor) {
            return medio;
        }

        if (arreglo[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1;
}

// IMPRIMIR ARREGLO
void imprimirArreglo(const int* arreglo, int tamanio) {
    cout << "ARREGLO ACTUAL: ";
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// ACTUALIZAR ARREGLO
void actualizarElemento(int &elemento, int nuevoValor) {
    elemento = nuevoValor;
    cout << "ELEMENTO ACTUALIZADO A: " << elemento << endl;
}

int main() {
    int tamanio;
    cout << "=====================" << endl;
    cout << "INGRESE EL TAMANIO DEL ARREGLO: ";
    cin >> tamanio;

    int *arreglo = new int[tamanio];
    cout << "=====================" << endl;
    cout << "INGRESE LOS ELEMENTOS DEL ARREGLO:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "ELEMENTO " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    int opcion;
    do {
        cout << "=====================" << endl;
        cout << "\nMENU DE OPCIONES" << endl;
        cout << "1. ORDENAR METODO BURBUJA" << endl;
        cout << "2. BUSQUEDA BINARIA (ARREGLO ORDENADO)" << endl;
        cout << "3. ACTUALIZAR ELEMENTO" << endl;
        cout << "4. IMPRIMIR ARREGLO" << endl;
        cout << "5. SALIR" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "=====================" << endl;
                ordenarBurbujaPunteros(arreglo, arreglo + tamanio);
                cout << "ARREGLO ORDENADO CORRECTAMENTE." << endl;
                imprimirArreglo(arreglo, tamanio);
                break;

            case 2: {
                int valor;
                cout << "=====================" << endl;
                cout << "INGRESE EL VALOR A BUSCAR: ";
                cin >> valor;

                int posicion = busquedaBinaria(arreglo, tamanio, valor);
                if (posicion != -1) {
                    cout << "EL VALOR " << valor << " SE ENCUENTRA EN LA POSICION " << posicion << endl;
                } else {
                    cout << "EL VALOR " << valor << " NO SE ENCUENTRA EN EL ARREGLO." << endl;
                    cout << "NOTA: LA BUSQUEDA BINARIA REQUIERE EL ARREGLO ORDENADO." << endl;
                }
                break;
            }

            case 3: {
                int posicion, nuevoValor;
                cout << "=====================" << endl;
                cout << "INGRESE LA POSICION A ACTUALIZAR (0-" << tamanio - 1 << "): ";
                cin >> posicion;

                if (posicion >= 0 && posicion < tamanio) {
                    cout << "INGRESE EL NUEVO VALOR: ";
                    cin >> nuevoValor;
                    actualizarElemento(arreglo[posicion], nuevoValor);
                    imprimirArreglo(arreglo, tamanio);
                } else {
                    cout << "POSICION INVALIDA." << endl;
                }
                break;
            }

            case 4:
                cout << "=====================" << endl;
                imprimirArreglo(arreglo, tamanio);
                break;

            case 5:
                cout << "=====================" << endl;
                cout << "SALIENDO DEL PROGRAMA..." << endl;
                break;

            default:
                cout << "OPCION INVALIDA. INTENTE DE NUEVO." << endl;
        }
    } while (opcion != 5);

    delete[] arreglo;

    return 0;
}

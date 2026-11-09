
#include <iostream>
using namespace std;

// ==========================================
// ESTRUCTURA DEL NODO
// ==========================================

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// ==========================================
// INSERTAR ELEMENTOS EN EL ARBOL
// ==========================================

Nodo* insertar(Nodo* raiz, int valor) {

    if (raiz == nullptr) {
        return new Nodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    }
    else if (valor > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// ==========================================
// RECORRIDO INORDEN
// IZQUIERDA - RAIZ - DERECHA
// ==========================================

void inorden(Nodo* raiz) {

    if (raiz != nullptr) {

        inorden(raiz->izquierda);

        cout << raiz->dato << " ";

        inorden(raiz->derecha);
    }
}

// ==========================================
// RECORRIDO PREORDEN
// RAIZ - IZQUIERDA - DERECHA
// ==========================================

void preorden(Nodo* raiz) {

    if (raiz != nullptr) {

        cout << raiz->dato << " ";

        preorden(raiz->izquierda);

        preorden(raiz->derecha);
    }
}

// ==========================================
// RECORRIDO POSORDEN
// IZQUIERDA - DERECHA - RAIZ
// ==========================================

void posorden(Nodo* raiz) {

    if (raiz != nullptr) {

        posorden(raiz->izquierda);

        posorden(raiz->derecha);

        cout << raiz->dato << " ";
    }
}

// ==========================================
// LIBERAR MEMORIA DEL ARBOL
// ==========================================

void liberarArbol(Nodo* raiz) {

    if (raiz != nullptr) {

        liberarArbol(raiz->izquierda);

        liberarArbol(raiz->derecha);

        delete raiz;
    }
}

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================

int main() {

    Nodo* raiz = nullptr;

    int cantidad;
    int valor;

    cout << "====================================\n";
    cout << "       ARBOLES BINARIOS EN C++\n";
    cout << "====================================\n";

    cout << "\nCuantos elementos desea ingresar? ";
    cin >> cantidad;

    // Ingresar elementos al arbol.
    for (int i = 0; i < cantidad; i++) {

        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> valor;

        raiz = insertar(raiz, valor);
    }

    // Mostrar recorridos.
    cout << "\n====================================\n";
    cout << "       RECORRIDOS DEL ARBOL\n";
    cout << "====================================\n";

    cout << "\nRecorrido INORDEN: ";
    inorden(raiz);

    cout << "\n\nRecorrido PREORDEN: ";
    preorden(raiz);

    cout << "\n\nRecorrido POSORDEN: ";
    posorden(raiz);

    cout << "\n\n====================================\n";

    // Liberar memoria.
    liberarArbol(raiz);

    return 0;
}

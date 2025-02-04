#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;
    Nodo* fin;
    int size;
};

// Función para crear una nueva cola
Cola* crearCola() {
    Cola* nuevaCola = new Cola();
    nuevaCola->frente = nullptr;
    nuevaCola->fin = nullptr;
    nuevaCola->size = 0;
    return nuevaCola;
}

// Función para agregar un elemento a la cola
void enqueue(Cola* c, int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = nullptr;

    if (c->fin == nullptr) {
        c->frente = nuevoNodo;
    } else {
        c->fin->siguiente = nuevoNodo;
    }
    c->fin = nuevoNodo;
    c->size++;
}

// Función para eliminar el elemento al frente de la cola
void dequeue(Cola* c) {
    if (c->frente != nullptr) {
        Nodo* nodoAux = c->frente;
        c->frente = c->frente->siguiente;
        if (c->frente == nullptr) {
            c->fin = nullptr;
        }
        delete nodoAux;
        c->size--;
    } else {
        std::cout << "La cola está vacía." << std::endl;
    }
}

// Función para ver el primer elemento de la cola
int front(Cola* c) {
    if (c->frente != nullptr) {
        return c->frente->valor;
    }
    std::cout << "La cola está vacía." << std::endl;
    return -1;  // Indicador de error
}

// Función para verificar si la cola está vacía
bool isEmpty(Cola* c) {
    return c->size == 0;
}

int main() {
    Cola* nuevaCola = crearCola();

    enqueue(nuevaCola, 5);
    enqueue(nuevaCola, 10);
    enqueue(nuevaCola, 15);

    std::cout << "Elemento al frente de la cola: " << front(nuevaCola) << std::endl;

    dequeue(nuevaCola);
    std::cout << "Elemento al frente después de eliminar: " << front(nuevaCola) << std::endl;

    dequeue(nuevaCola);
    dequeue(nuevaCola);
    dequeue(nuevaCola);  // Intentar eliminar de una cola vacía

    std::cout << "¿Está vacía la cola? " << (isEmpty(nuevaCola) ? "Sí" : "No") << std::endl;

    delete nuevaCola;
    return 0;
}

#include <iostream>
using namespace std;

int busquedaBinario(int n, int arreglo[], int tamanio) {
    int leftBound = 0, rightBoud = tamanio;
    while (leftBound < rightBoud) {
        int middle = (rightBoud + leftBound) / 2;

        if (arreglo[middle] == n) {
            return middle;
        }
        else if (arreglo[middle] < n) {
            leftBound = middle + 1;
        }
        else {
            rightBoud = middle - 1;
        }
    }

    return -1;
}

int main() {
    int arreglo[] = {1, 3, 5, 7, 9, 11};
    int tamanio = sizeof(arreglo) / sizeof(arreglo[0]);
    
    int resultado = busquedaBinario(11, arreglo, tamanio);
    
    if (resultado != -1) {
        cout << "El número se encuentra en el índice: " << resultado << endl;
    } else {
        cout << "El número no se encuentra en el arreglo." << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

//This function sorts the elements of the array
void burbuja(int cal[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cal[j] > cal[j + 1]) {
                int temp = cal[j];
                cal[j] = cal[j + 1];
                cal[j + 1] = temp;
            }
        }
    }
}
//Function that prints the array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int tam{0};
    cout<<"Ingrese cuantas calificaciones quiere ingresar: ";
    cin>>tam;

    int calificaciones[tam];
    for(int i =0; i< tam; i++)
    {
        cout<<"Ingrese calificacion: "<<endl;
        cin>>calificaciones[i];
    }
    cout << "Array antes de ordenar: ";
    imprimirArray(calificaciones, tam);
    
    burbuja(calificaciones, tam); 
    
    cout << "Array después de ordenar: ";
    imprimirArray(calificaciones, tam);
    
    return 0;
}

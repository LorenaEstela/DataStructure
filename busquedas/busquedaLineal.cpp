#include <iostream>

using namespace std;


int busquedalineal(int n, int arreglo[], int tamanio)
{
    for(int i =0; i<tamanio; i++)
    {
        if(arreglo[i]==n){
            cout<<"Numero encontrado : " <<arreglo[i]<<endl;
            cout<<"Posicion: "<<i;
            return arreglo[i];
        }
    }
    cout<<"El numero no se encuentra en la lista";
    return -1;
}

int main()
{
    int lista[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n;
    int tamanio = sizeof(lista)/sizeof(lista[0]);

    cout<<"Numero que desea buscar: ";
    cin>>n;
    int resultado = busquedalineal(n, lista,tamanio);

    return 0;
}
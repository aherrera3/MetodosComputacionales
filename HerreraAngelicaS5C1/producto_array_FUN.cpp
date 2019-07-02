#include <iostream>
using namespace std;

//Declaracion de funciones
int * producto(int arr1[5], int arr2[5]);
int producto_punto(int arr1[5], int arr2[5]);

int *apuntador;
int arr[5];

int arr1[5] = {1,2,3,4,5};
int arr2[5] = {10,20,30,40,50};

int prod;

int main ()
{   
    producto(arr1,arr2);
    //cout << "El producto entre arr1 por arr2 es: "  << producto(arr1,arr2) << endl;
    cout << "El producto  punto entre arr1 por arr2 es: " << producto_punto(arr1,arr2) << endl;
           
    return 0;
}

int * producto (int arr1[5], int arr2[5])
{       
    for(int i = 0; i<5 ; i++)
    {
        arr[i] = arr1[i] * arr2[i]; 
    }
    
    apuntador = arr;
    
    cout << "El producto entre arr1 por arr2 es: " << *apuntador << endl;
}

int producto_punto(int arr1[5], int arr2[5])
{       
    prod = 0;
    
    for(int i = 0; i<5 ; i++)
    {
        prod = prod + arr1[i] * arr2[i];   
    }
    
    return prod;
}



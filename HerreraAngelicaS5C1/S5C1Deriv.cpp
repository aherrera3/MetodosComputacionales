#include <iostream>
using namespace std;

//Declaracion de variables
int *apuntador;  //declaracion del apuntador

//Declaracion de mi funcion
int derivada();

int main()
{
    int a, b, start, stop, n, arr[5];
    
    cout<<"Introduce el primer número entero :";
    cin>>a;
    
    cout<<"Introduce el segundo número entero :";
    cin>>b;
    
    cout << "Introduce el número de puntos del intervalo:";
    cin >> n;
    
    if(a<b)
    {
        start = a;
        stop = b;
    }
    
    else
    {
        start = b;
        stop = a;
    }
    
    arr[0] = start;
    arr[-1] = stop;     
    
    /*
    for(int i = 1; i<"algo" ; i++)
    {
        start = start + n;
        arr[i] = start;
    }    
    */
    return 0;
}

int derivada()
{
    return 0;   
}
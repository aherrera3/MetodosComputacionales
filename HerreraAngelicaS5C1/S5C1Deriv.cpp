#include <iostream>
using namespace std;

//Declaracion de variables
int *apuntador;  //declaracion del apuntador

//Declaracion de mi funcion
int derivada();

int main()
{
    double a, b, start, stop, dx;
    int n;
    
    cout<<"Introduce el primer número entero: ";
    cin>>a;
    
    cout<<"Introduce el segundo número entero: ";
    cin>>b;
    
    cout << "Introduce el número de puntos del intervalo: "; //cuento como puntos a mis dos extremos
    cin >> n;
    
    double x[n];
    
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
    
    dx = (stop-start)/(n-1);    
    x[0] = start;
    cout << "mi arreglo x es: [" << x[0] << ", ";
   
    for(int i = 1; i<n ; i++)
    {
        x[i] = x[i-1] + dx;
        
        if(i == n-1) cout << x[i] << "]" << endl;
        
        else cout << x[i] << ", ";
    }    
    
    return 0;
}

int derivada()
{
    return 0;   
}
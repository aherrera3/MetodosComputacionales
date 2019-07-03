#include <iostream>
#include <cmath>
using namespace std;

//Declaracion de variables
int *apuntador;  //declaracion del apuntador
double a, b, start, stop, dx;
int n;

//Declaracion de mi funcion
int derivada(double);

int main()
{   
    cout<<"Introduce el primer número entero: ";
    cin>>a;
    
    cout<<"Introduce el segundo número entero: ";
    cin>>b;
    
    cout << "Introduce el número de puntos del intervalo: "; //cuento como puntos a mis dos extremos
    cin >> n;
    
    double x[n], coseno[n];
    
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
    coseno[0] = cos(x[0]);   //toma a los x como radianes
    
    //cout << "mi arreglo x es: [" << x[0] << ", ";
    cout << "mi coseno(x) es: [" << coseno[0] << ", ";    
   
    for(int i = 1; i<n ; i++)
    {
        x[i] = x[i-1] + dx;
        coseno[i] = cos(x[i]);
        
        if(i == n-1) {
           // cout << x[i] << "]" << endl;
            cout << coseno[i] << "]" << endl;
        }        
        else {
           // cout << x[i] << ", ";
            cout << coseno[i] << ", ";
        }
    }        
    
    return 0;
}

int * derivada(double f)
{
    for(int i = 2 ; i<=n ; i++)
    {
        der[i] = (f[i]-f[i-2])/(2*dx)
    }
    
    
    return der;   
}

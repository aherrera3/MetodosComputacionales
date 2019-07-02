#include <iostream>
using namespace std;

//Declaración de funciones
double factorial(double n);

//Método constructor
int main ()
{
    double n;
    
    cout<<"Introduce un número: ";
    cin>>n;
    
    cout << "Su factorial es: " <<factorial(n) <<endl;
    
    return 0;
}

//Función que calcula el factorial de un numero
double factorial(double n)  
{   
    for(int i=n-1; i>0; i--)
    {
        n = n*i;   
    }
    
    return n; 
}


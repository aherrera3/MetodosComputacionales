#include <iostream>
using namespace std;

//Declaración de funciones
int factorial(int n);

int main ()
{
    int n;
    
    cout<<"Introduce un número";
    cin>>n;
    
    cout << factorial(n);
    
    return 0;
}

int factorial(int n)  
{   
    for(int i=n-1; i>0; i--)
    {
        n = n*i;   
    }
    
    return n; 
}


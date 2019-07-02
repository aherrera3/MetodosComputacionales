#include <iostream>
using namespace std;

int main ()
{
    int a, b, start, stop, contador;
    
    cout<<"Introduce el primer número entero :";
    cin>>a;
    
    cout<<"Introduce el segundo número entero :";
    cin>>b;
    
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
    
    cout << "Los números primos entre " << start << " y " << stop << " son: " << endl;
    
    for(int i=start ; i<=stop ; i++)
    {
        contador = 0;
        
        for(int j=2 ; j<i ; j++)
        {
            if(i%j==0)
            {
                contador = contador +1;
            }   
        }
        
        if(contador == 0)
        {
            int primo = i;
            cout << primo << endl;
        }
    }   
    
    return 0;
}

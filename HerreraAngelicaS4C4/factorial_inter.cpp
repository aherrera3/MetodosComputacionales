#include <iostream>
using namespace std;

int main ()
{
    double n;
    
    cout<<"Introduce un número ";
    cin>>n;
    
    for(int i=n-1; i>0; i--)
    {
        n = n*i;   
    }
    
    cout << "Su factorial es: " << n << endl;    
    
    return 0;
}

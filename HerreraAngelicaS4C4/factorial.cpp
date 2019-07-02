#include <iostream>
using namespace std;

int main()
{
    double n = 77;
    
    for(int i=n-1; i>0; i--)
    {
        n = n*i;   
    }
    
    cout << "El factorial de n=77 es: " << n << endl;
    
    return 0;
}
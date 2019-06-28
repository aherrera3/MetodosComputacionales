#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    
    for(int i=n-1; i>0; i--)
    {
        n = n*i;   
    }
    
    cout << n;
    
    return 0;
}
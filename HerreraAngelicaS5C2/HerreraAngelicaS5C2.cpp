//ec dif: y'= -y

#include <iostream>
using namespace std;

//variables globales
double x[100], y[100], dx, start, stop;
int n;

//declaracion de funciones
double derivada(double);
void euler();

int main()
{
    n = 100;
    start = 0;
    stop = 2;
    dx = (stop-start)/n;
    
    //condiciones iniciales
    x[0] = start;
    y[0] = 1;
        
    euler();
    
    return 0;
}

double derivada(double y)
{
    return -y;
}

void euler()
{
    for(int i=1; i<=n ;i++)
    {
        x[i] = x[i-1] + dx;
        y[i] = y[i-1] + dx*derivada(y[i-1]);     
        
        cout << x[i] << " " << y[i] << endl;
    }        
}




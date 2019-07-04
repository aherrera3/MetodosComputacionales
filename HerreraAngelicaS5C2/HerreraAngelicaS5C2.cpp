//ec dif: y'= -y

#include <iostream>
using namespace std;

//variables globales
double x[100], y[100], dx, start, stop, k1, k2, k3, k4, slope;
int n;

//declaracion de funciones
double derivada(double);
void euler();
void runge_kutta();
void leap_frog();

int main()
{
    n = 100;
    start = 0;
    stop = 2;
    dx = (stop-start)/n;
    
    //condiciones iniciales
    x[0] = start;
    y[0] = 1;
        
    //euler();
    //runge_kutta();
    leap_frog();
    
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

//Runge-kutta de 4 orden
void runge_kutta()
{
    for(int i=1 ; i<=n; i++)
    {
        k1 = dx*derivada(y[i-1]);
        k2 = dx*derivada(y[i-1] + 0.5*k1);
        k3 = dx*derivada(y[i-1] + 0.5*k2);
        k4 = dx*derivada(y[i-1] + k3);
            
        slope = (k1 + 2*k2 + 2*k3 + k4)/6;
        
        x[i] = x[i-1] + dx;
        y[i] = y[i-1] + slope;
        
        cout << x[i] << " " << y[i] << endl;
    }    
}


void leap_frog()
{
    x[1] = x[0] + dx;
    y[1] = y[0] + dx*derivada(y[0]);
 
    for(int i=2; i<=n; i++)
    {
        x[i] = x[i-1] + dx;
        y[i] = y[i-2] + 2*dx*derivada(y[i-1]);
        
        cout << x[i] << " " << y[i] << endl;
    }
    
}




// x'' = -G m r / r**3

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

//variables globales
double G, m, dt, r[400], t[400], x[400], y[400], z[400], vx[400], vy[400]; 
int n;

//Declaracion de las funciones
double leap_frog(double, double);

int main()
{
    ifstream infile("EarthOrbit.dat");
    
    int i = 0;
    while(!infile.eof())   //si no ha llegado al final del archivo
    {
        infile >> t[i] >> x[i] >> y[i] >> z[i];    // tomo los 4 valores de cada fila

        // do something with them
        r[i] = sqrt(pow(x[i],2) + pow(y[i],2) + pow(z[i],2));
        i++;
    }
    
    G = 6.674 * pow(10,-11);   //constante gravitacional  [N m^2/kg^2]
    m = 1.989 * pow(10,30); 
    
    n = 100;
    dt = 0.993840/n;
    cout << "mi dt es: " << n;  
    
    //c.i
    x[0] = 0.1163;
    y[0] = 0.9772;
    vx[0] = -6.35;
    vy[0] = 0.606;
    
    
    for(int i=1; i<n ; i++)
    {
        v[i] = v[i-1] + dt*(-G*m*/r[i]);
        x[i] = euler(x[i-1], v[i-1]);    
    }
    
    
    return 0;    
}

double euler(double x_antes, double v_antes)
{
    return x_antes + dt*v_antes;
}
   

/*
double leap_frog(double x_antes_antes, double v_antes)
{
    return x_antes_antes + 2*dt*v_actual;
}
*/
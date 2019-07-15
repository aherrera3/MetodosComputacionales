// x'' = -G m r / r**3

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

//variables globales
double G, m, dt, t[400], x[400], y[400], z[400], vx[400], vy[400]; 
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
        i++;
    }
    
    G = 6.674 * pow(10,-11);   //constante gravitacional  [N m^2/kg^2]
    m = 1.989 * pow(10,30); 
    
    dt = t[1] - t[0];
    n = 0.993840/dt +1;
    cout << "mi n es: " << n;  
    
    //c.i
    x[0] = 0.1163;
    y[0] = 0.9772;
    
    vx[0] = -6.35;
    vy[0] = 0.606;    
    
    return 0;    
}
/*
double leap_frog(double x_antes_antes, double v_antes)
{
    return x_antes_antes + 2*dt*v_actual;
}
*/
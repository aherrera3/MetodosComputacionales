// x'' = -G m r / r**3

#include <iostream>
#include <fstream>
#include <math.h>      /* sqrt, pow() */
using namespace std; 

//variables globales
double G, m, dt, r[1000], t[1000], x[1000], y[1000], vx[1000], vy[1000]; 
double  r_[1000], x_[1000], y_[1000], vx_[1000], vy_[1000];
double  _r_[1000], _x_[1000], _y_[1000], _vx_[1000], _vy_[1000]; 
int n;

//Declaracion de las funciones
double leap_frog(double, double);
double leap_frog(double, double);
double runge_kutta(double, double); 

int main()
{
    /*
    ifstream infile("EarthOrbit.dat");
    
    int i = 0;
    while(!infile.eof())   //si no ha llegado al final del archivo
    {
        infile >> t[i] >> x[i] >> y[i] >> z[i];    // tomo los 4 valores de cada fila

        // do something with them
        r[i] = sqrt(pow(x[i],2) + pow(y[i],2) + pow(z[i],2));
        i++;
    }
    */
    
    G = 6.674 * pow(10,-11);   //constante gravitacional  [N m^2/kg^2]
    m = 1.989 * pow(10,30); 
    
    n = 1000;
    t[0] = 0.0;
    t[n-1] = 20.0;   //20 orbitas = 20 años
        
    dt = (t[n-1]-t[0])/(n-1);
    cout << "mi dt es: " << dt;  
    
    //c.i
    x[0] = 0.1163;  //para euler
    y[0] = 0.9772;
    vx[0] = -6.35;
    vy[0] = 0.606;
    
    x_[0] = x[0];    //para leap-frog
    y_[0] = y[0];
    vx_[0] = vx[0];
    vy_[0] = vy[0];
    
    _x_[0] = x[0];    //para runge-kutta
    _y_[0] = y[0];
    _vx_[0] = vx[0];
    _vy_[0] = vy[0];
    
    r[0] = sqrt(pow(x[0],2) + pow(y[0],2));          //para euler
    r_[0] = sqrt(pow(x[0],2) + pow(y[0],2));         //para leap-frog  
    _r_[0] = sqrt(pow(x[0],2) + pow(y[0],2));        //para runge-kutta
    
    
    for(int i=1; i<n; i++)
    {
        //euler
        v[i] = v[i-1] + dt*aceleracion(x[i-1], r[i-1]);
        x[i] = euler(x[i-1], v[i-1]);    
    }
    
    
    
    return 0;    
}

double aceleracion(double pos_antes, double r_antes)
{
    return -G*m*pos_antes/pow(r_antes,3);
}

double euler(double pos_antes, double v_antes)
{
    return pos_antes + dt*v_antes;
}

double leap_frog(double pos_antes_antes, double v_actual)
{
    return pos_antes_antes + 2*dt*v_actual;
}

double runge_kutta(double pos_antes, double v_antes, double r_antes)
{
    double k1_1 = pos_antes;
    double k1_2 = aceleracion(pos_antes, r_antes);
    
    double pos1 = pos_antes + (dt/2) * k1_1;
    double v1 = v_antes + (dt/2) * k1_2;
    
    double k2_1 = v1;
    double k2_2 = aceleracion(pos1, r_antes);
    
    double pos2 = pos_antes + (dt/2) * k2_1;
    double v2 = v_antes + (dt/2) * k2_2;

    double k3_1 = v2;
    double k3_2 = aceleracion(pos2, r_antes);

    double pos3 = pos_antes + dt * k3_1;
    double v3  = v_antes + dt * k3_2;

    double k4_1 = v3;
    double k4_2 = aceleracion(pos3, r_antes);
 
    double k1_promedio = (k1_der_1 + 2*k2_der_1 + 2*k3_der_1 + k4_der_1)/6 ;
    double k2_promedio = (k1_der_2 + 2*k2_der_2 + 2*k3_der_2 + k4_der_2)/6 ;  

    double pos_ahora = pos_antes + dt * k1_promedio;
    double v_ahora = v_antes + dt * k2_promedio;
    
    return pos_ahora;
} 

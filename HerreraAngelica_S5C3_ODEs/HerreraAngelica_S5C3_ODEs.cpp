//m x'' = -k x

#include <iostream>
#include <fstream>
using namespace std;

//variables globales
double m, k, t[1000], x[1000], v[1000], dt, x_siguiente, v_siguiente;
int n;

double leap_frog(double, double, double, double);

int main()
{
    //abro y creo un archivo llamado datos.dat
    ofstream archivo;
    archivo.open("datos.dat");
    
    m = 2.0;
    k = 300.0;
    
    n = 100;
    t[0] = 0.0;
    t[n-1] = 5.0;
    
    dt = (t[n-1]-t[0])/(n-1);
    
    //c.i
    t[0] = 0.0;
    x[0] = 0.1;
    v[0] = 0.0;
    
    t[1] = t[0] + dt;
    t[2] = t[1] + dt;
    
    //para primer paso (por euler)
    
    v[1] = v[0] + dt*(-k/m)*x[0];  
    x[1] = x[0] + dt*v[0];
    
    //segundo paso para leap-frog
    x[2] = leap_frog(x[0], x[1] , v[0], v[1]);
    
    //hace un for hasta 2.
    archivo << t[0] << " " << x[0] << endl;
    archivo << t[1] << " " << x[1] << endl;
    archivo << t[2] << " " << x[2] << endl;
    
    //para el resto de pasos (leap-frog)
    for(int i = 3; i<n; i++)
    {
        t[i] = t[i-1] + dt;
        x[i] = leap_frog(x[i-2], x[i-1] , v[i-2], v[i-1]);
        
        archivo << t[i] << " " << x[i] << endl;
    }
    
    archivo.close();
    
    return 0;
}

double leap_frog(double x_antes, double x_ahora, double v_antes, double v_ahora)
{
    v_siguiente = v_antes + 2*dt*(-k/m)*x_ahora;
    x_siguiente = x_antes + 2*dt*v_ahora;
    
    return x_siguiente;
}


/*
double runge_kutta(double x_antes, double v_antes)
{
    double k1_der_1 = derivada(v_antes);
    double k1_der_2 = derivada_segunda(x_antes);
    
    double x1 = x_antes + (dt/2) * k1_der_1;
    double v1 = v_antes + (dt/2) * k1_der_2;
    
    double k2_der_1 = derivada(v1);
    double k2_der_2 = derivada_segunda(x1);
    
    double x2 =  x_antes + (dt/2) * k2_der_1;
    double v2 = v_antes + (dt/2) * k2_der_2;
    
    double k3_der_1 = derivada(v2);
    double k3_der_2 = derivada_segunda(x2);
    
    double x3 =  x_antes + dt * k3_der_1;
    double v3  = v_antes + dt * k3_der_2;
        
    double k4_der_1 = derivada(v3);
    double k4_der_2 = derivada_segunda(x3);
    
    
    double k1_promedio = (k1_der_1 + 2*k2_der_1 + 2*k3_der_1 + k4_der_1 )/6 ;
    double k2_promedio = (k1_der_2 + 2*k2_der_2 + 2*k3_der_2 + k4_der_2 )/6 ;  
        
    double x_ahora = x_antes + dt * k1_promedio;
    double v_ahora = v_antes + dt * k2_promedio;
    
    return x_ahora;
    
} 

*/

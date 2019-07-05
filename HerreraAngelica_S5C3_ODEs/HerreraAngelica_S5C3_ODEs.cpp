//m x'' = -k x

#include <iostream>
#include <fstream>
using namespace std;

//variables globales
double m, k, t[1000], x[1000], v[1000], dt;
int n;

double derivada(double, double);
double segunda_derivada(double, double);
double runge_kutta(double, double);

int main()
{
    m = 2.0;
    k = 300.0;
    
    n = 100;
    t[0] = 0;
    t[n-1] = 5;
    
    dt = (t[n-1]-t[0])/(n-1);
    
    //c.i
    t[0] = 0;   //posicion en t=0 
    x[0] = 0.1;
    v[0] = 0;
    
    cout << t[0] << endl;
    
    for(int i = 1; i<n; i++)
    {
        t[i] = t[i-1] + dt;
        x[i] = runge_kutta(x[i-1], v[i-1]);
        cout << x[i] << endl;
    }
    
    return 0;
}

double derivada(double v)
{
    return v;
}

double derivada_segunda(double x)
{
    return -k/m * x;
}


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
/*  

void leap_frog()
{   
    v[0] = (k/m) * x[1] * (dt/2) + v[1];
    
    x[0] = ;
    
    for(int i=2; i<=n; i++)
    {
        v[i+1] = -k*2*dt/m * x[i] + v[t-1];
        
        x[i] = -m/k * (v[i+1]-v[i-1])/(2*dt);
        
        cout << x[i] << " " << y[i] << endl;
    }

*/

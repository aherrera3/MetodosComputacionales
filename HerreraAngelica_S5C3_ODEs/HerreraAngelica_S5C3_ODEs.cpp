//m x'' = -k x

#include <iostream>
#include <fstream>
using namespace std;

//variables globales
double m, k, x_1[100], x_2[100], t[100], x[100];
double derivada(double, double);
double segunda_derivada(double, double);
void runge_kutta(double, double);

int main()
{
    m = 2.0;
    k = 300.0;
    
    n = 100;
    t[0] = 0;
    t[n] = 5;
    
    dt = (t_final-t_inicial)/n
    
    //c.i
    t[0] = 0;   //posicion en t=0
    v[0] = 0;  
    x[0] = 0.1;
    x_1[0] = 0;
    x_2[0] = 0;
    
    return 0;
}

double derivada_x1(double x_1, double x_2)
{
    return x_2;
}

double derivada_x2(double x_1, double x_2)
{
    return -k/m * x_1;
}


void runge_kutta(double x1_antes, double x2_antes)
{
    k1_der_1 = derivada_x1(x_antes);
    k1_der_2 = derivada_x2(x_antes);
    
    x11 = x1_antes + (dt/2) * k1_der_1;
    x21 = x2_antes + (dt/2) * k1_der_2;
    
    k2_der_1 = derivada_x1(x11, x21);
    k2_der_2 = derivada_x2(x11, x21);
    
    x12 =  x1_antes + (dt/2) * k2_der_1;
    x22 = x2_antes + (dt/2) * k2_der_2;
    
    k3_der_1 = derivada_x1(x12);
    k3_der_2 = derivada_x2(x22);
    
    x13 =  x1_antes + dt * k3_der_1;  
    x23  = x2_antes + dt * k3_der_2;
        
    k4_der_1 = derivada_x1(x13);
    k4_der_2 = derivada_x2(x23);  
    
    
    k1_promedio = (k1_der_1 + 2*k2_der_1 + 2*k3_der_1 + k4_der_1 )/6 ;
    k2_promedio = (k1_der_2 + 2*k2_der_2 + 2*k3_der_2 + k4_der_2 )/6 ;  
    
    t_ahora = t_antes + dt;
    x1_ahora = x1_antes + h * k1_promedio;
    x2_ahora = x2_antes + h * k2_promedio;
    
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

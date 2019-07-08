//m x'' = -k x

#include <iostream>
#include <fstream>
using namespace std;

//variables globales
double m, k, t[2000], x[2000], v[2000], dt;
int n;

//declaracion de mi funcion
double leap_frog(double, double);

int main()
{
    //abro y creo un archivo llamado datos.dat
    ofstream archivo;
    archivo.open("datos.dat");
    
    m = 2.0;
    k = 300.0;
    
    n = 1000;
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
    
    //segundo paso con leap-frog
    x[2] = leap_frog(x[0], v[1]);
    
    cout << "t" << "    " << "x" << "    " << "v" << endl;    
    for(int i=0; i<3;i++)
    {
        archivo << t[i] << " " << x[i] << endl; 
        cout << t[i] << "    " << x[i] << "    " << v[i-1] << endl;    
    }
    //para el resto de pasos (leap-frog)
    for(int i = 2; i<n-1; i++)
    {
        t[i+1] = t[i] + dt;
        v[i] = v[i-2] + 2*dt*(-k/m)*x[i-1];
        x[i+1] = leap_frog(x[i-1] , v[i]);
        
        archivo << t[i+1] << " " << x[i+1] << endl;
        cout << t[i] << "    " << x[i] << "    " << v[i-1] << endl; 
        if(i==n-2) cout << t[i+1] << "    " << x[i+1] << "    " << v[i] << endl;
    }
    
    archivo.close();
    
    return 0;
}

double leap_frog( double x_antes_antes, double v_actual)
{
    double x_siguiente = x_antes_antes + 2*dt*v_actual;
    
    return x_siguiente;
}



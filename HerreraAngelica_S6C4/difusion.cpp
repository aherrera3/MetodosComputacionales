#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double l, nu, dx, dt, r, x[100], y[100];
    double T[100][100];
    int n;
    
    l = 1.0;
    nu = 0.001;   //coeficiente de difusion
    dx = 0.01;
    n = l/dx;
    dt = dx*dx*0.25/nu;   //r=0.25
    r = nu*dt/(dx*dx);
    
    cout << n << endl;
    x[0] = 0.0;
    y[0] = 0.0;
    
    //lleno mis arreglos x y y
    for(int i=1; i<n; i++)
    {
        x[i] = x[i-1] + dx;
        y[i] = y[i-1] + dx;
    }
    
    ofstream matriz;
    matriz.open("matriz.dat");
    
    ofstream datos;
    datos.open("datos.dat");
    
    //llenos los valores de temperaturas de la placa
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(y[i]>=l/2.0-0.2 && y[i]<=l/2.0+ 0.2 && x[j]>=0.2 && x[j]<=0.4)   //si esta dentro de mis valores de x y y correctos
            {
                T[i][j] = 100.0;
            }
            
            else T[i][j] = 50.0;
            
            matriz << T[i][j] << " ";
        }
        matriz << endl;
        
        datos << x[i] << " " << y[i] << endl;
    }
    
    datos.close();
    matriz.close();
    
    return 0;
}



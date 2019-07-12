#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double l, nu, dx, dt, r, x[100], y[100];
    double t[10000], T[100][100], T_presente[100][100], T_futuro[100][100];
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
    t[0] = 0.0;
    
    
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
                T_presente[i][j] =  T[i][j];
            }
            
            else 
            {
                T[i][j] = 50.0;
                T_presente[i][j] =  T[i][j];
            }
            
            matriz << T[i][j] << " ";
        }
        matriz << endl;
        datos << x[i] << " " << y[i] << endl;
    }
    
    datos.close();
    matriz.close();

    //cond de frontera fijas a T=50
    for(int i=0; i<n; i++)
    {
        T_futuro[i][0] = 50.0;
        T_futuro[i][n-1] = 50.0;
        
        for(int j=0; j<n; j++)
        {
            T_futuro[0][j] = 50.0;
            T_futuro[n-1][j] =50.0;
        }
    }
    
    
    //archivos para pasar mi matriz T en diferentes tiempos
    ofstream archivo_t1;
    archivo_t1.open("t1.dat");
    
    ofstream archivo_t2;
    archivo_t2.open("t2.dat");
    
    
    for(int k=1; k<=10000; k++) //for del tiempo
    {
        //t[k] = t[k-1] + dt;
        
        //hago mi nuevo futuro
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<n ; j++)
            {
                T_futuro[i][j] = r*(T_presente[i+1][j] - 2*T_presente[i][j] + T_presente[i-1][j] + T_presente[i][j+1] - 2*T_presente[i][j] + T_presente[i][j-1]) + T_presente[i][j];
            }
        }
    
        //actualizo mi presente
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n ; j++)
            {
                T_presente[i][j] = T_futuro[i][j];
            
                if(k==100) archivo_t1 << T_presente[i][j] << " ";
                if(k==2500) archivo_t2 << T_presente[i][j] << " ";
            }
            
            if(k==100) archivo_t1 << endl;
            if(k==2500) archivo_t2 << endl;
        }
    }
    
    archivo_t1.close();
    archivo_t2.close();
    
    return 0;
}



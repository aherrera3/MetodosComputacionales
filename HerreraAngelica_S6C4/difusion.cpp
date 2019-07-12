#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double l, nu, dx, dt, r, x[100], y[100];
    double t[5000], T[100][100], T_presente[100][100], T_futuro[100][100], T_mean[10000];
    double T_pre[100][100], T_fut[100][100], T_mean_[10000];
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
    
    ofstream t_inicial;
    t_inicial.open("t_inicial.dat");
    
    ofstream datos;
    datos.open("datos.dat");
    
    //llenos los valores de temperaturas de la placa y cond de frontera fijas a T=50 para mi primer futuro
    for(int i=0; i<n; i++)
    {
        //cond de fronteras fijas
        T_futuro[i][0] = 50.0;
        T_futuro[i][n-1] = 50.0;
        
        for(int j=0; j<n; j++)
        {
            //cond de fronteras fijas
            T_futuro[0][j] = 50.0;
            T_futuro[n-1][j] =50.0;
            if(y[i]>=l/2.0-0.2 && y[i]<=l/2.0+ 0.2 && x[j]>=0.2 && x[j]<=0.4)   //si esta dentro de mis valores de x y y correctos
            {
                T[i][j] = 100.0;
                T_presente[i][j] =  T[i][j];
                T_pre[i][j] = T[i][j];
            }
            
            else 
            {
                T[i][j] = 50.0;
                T_presente[i][j] =  T[i][j];
                T_pre[i][j] = T[i][j];
            }
            
            t_inicial << T[i][j] << " ";
        }
        t_inicial << endl;
        datos << x[i] << " " << y[i] << endl;
    }
    
    datos.close();
    t_inicial.close();
   
    
    //archivos para pasar mi matriz T en diferentes tiempos
    ofstream archivo_t1;
    archivo_t1.open("t1.dat");
    
    ofstream archivo_t2;
    archivo_t2.open("t2.dat");
    
    ofstream archivo_t1_;
    archivo_t1_.open("t1_libres.dat");
    
    ofstream archivo_t2_;
    archivo_t2_.open("t2_libres.dat");
    
    
    for(int k=1; k<=5000; k++) //for del tiempo
    {
        //t[k] = t[k-1] + dt;
        
        //cond de frontera libres
        for(int i=0; i<n; i++)
        {
            T_fut[i][0] = T_fut[i][1];
            T_fut[i][n-1] = T_fut[i][n-2];
            
            for(int j=0; j<n ; j++)
            {
                T_fut[0][j] = T_fut[1][j];
                T_fut[n-1][j] = T_fut[n-2][j];   //bien
                
                if(i!=0 && j!=0 && i!=n-1 && j!=n-1)
                {
                    T_futuro[i][j] = r*(T_presente[i+1][j] - 2*T_presente[i][j] + T_presente[i-1][j] + T_presente[i][j+1] - 2*T_presente[i][j] + T_presente[i][j-1]) + T_presente[i][j];
                    T_fut[i][j] = r*(T_pre[i+1][j] - 2*T_pre[i][j] + T_pre[i-1][j] + T_pre[i][j+1] - 2*T_pre[i][j] + T_pre[i][j-1]) + T_pre[i][j];
                }
            }
        }
    
        //actualizo mis presentes
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n ; j++)
            {
                T_presente[i][j] = T_futuro[i][j];
                T_pre[i][j] = T_fut[i][j];
            
                if(k==100)
                {
                    archivo_t1 << T_presente[i][j] << " ";
                    archivo_t1_ << T_pre[i][j] << " ";
                }
                if(k==2500) 
                {
                    archivo_t2 << T_presente[i][j] << " ";
                    archivo_t2_ << T_pre[i][j] << " ";
                }
            }
            
            if(k==100) 
            {
                archivo_t1 << endl;
                archivo_t1_ << endl;
            }
            if(k==2500) 
            {
                archivo_t2 << endl;
                archivo_t2_ << endl;
            }
        }
    }
    
    archivo_t1.close();
    archivo_t2.close();
    archivo_t1_.close();
    archivo_t2_.close();
    
    return 0;
}



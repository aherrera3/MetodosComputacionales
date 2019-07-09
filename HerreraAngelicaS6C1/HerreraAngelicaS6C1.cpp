//ec de adveccion

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double dt, dx, v, r, u_inicial[2000], x[2000], u_futuro[2000], u_presente[2000];  //u_inicial es mi pulso en t=0
    int n;
    
    ofstream archivo;
    archivo.open("datos.dat");
    
    v = 1;
    dx = 0.01;
    
    //dx = (x[n]-x[0])/(n-1);
    n = (2.0-0.0)/(dx) +1;
    
    x[0] = 0.0;
    x[n] = 2.0;
    
    dt = dx*0.25/v;
    r = v*dt/dx;     //debe ser menor que 1
    
    cout << "mi r es = " << r << endl;
    
    u_inicial[0] = 1.0;
    
    cout << x[0] << "   " << u_inicial[0] << endl;
    
    //construyo mi funcion pulso rectangular en t=0
    for(int i=1; i<n ;i++)
    {
        x[i] = x[i-1] + dx;
        if(x[i]>=0.75 && x[i]<=1.25) u_inicial[i] =  2.0; 
        else u_inicial[i] = 1.0;
        
        cout << x[i] << "   " << u_inicial[i] << endl; 
    }
    
    u_futuro[0] = 1.0;
    u_presente[0] = u_futuro[0];
    
    //hago mi primer futuro para obtener mi primer presente
    for(int i=1; i<n; i++)
    {
        u_futuro[i] = r*(u_inicial[i] - u_inicial[i-1]) + u_inicial[i]; 
        u_presente[i] = u_futuro[i];
    }
    
    //para todos los demas futuros
    int j=0;
    int n_tiempo = 100;
    
    archivo << x[0] << " " << u_inicial[0] << " " << u_presente[0] << endl;
    while(j<=n_tiempo)
    {
        for(int i=1; i<n; i++)
        {
            u_futuro[i] = r*(u_presente[i] - u_presente[i-1]) + u_presente[i];
            u_presente[i] = u_futuro[i];
            
            if(j==n_tiempo) archivo << x[i] << " " << u_inicial[i] << " " << u_presente[i] << endl;
        }
        j++;
    }
    archivo.close();
    
    return 0;
}
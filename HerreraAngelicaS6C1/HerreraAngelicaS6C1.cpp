//ec de adveccion

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double dt, dx, v, r, u_inicial[2000], t[2000], x[2000], u_futuro[2000], u_presente[2000], u_pasado[2000];//u_inicial es mi pulso en t=0
    int n;
    
    v = 1;
    n = 80;
    
    x[0] = 0.0;
    x[n] = 2.0;
    
    dx = (x[n]-x[0])/(n-1);
    dt = dx*0.25/v;
    r = v*dt/dx;     //debe ser menor que 1
    
    cout << "mi r es = " << r << endl;
    
    u_inicial[0] = 0.0;
    u_presente[0] = u_presente[0];
    
    cout << x[0] << "   " << u_inicial[0] << endl;
    
    //construyo mi funcion pulso rectangular en t=0
    for(int i=1; i<n ;i++)
    {
        x[i] = x[i-1] + dx;
        if(x[i]>=0.75 && x[i]<=1.25)
        {
            u_inicial[i] =  2.0;    
            u_presente[i] = u_inicial[i];
        }
        else
        {
            u_inicial[i] = 1.0;
            u_presente[i] = u_inicial[i];
        }
        
        cout << x[i] << "   " << u_inicial[i] << endl; 
    }
    
    u_futuro[0] = 0.0;
    u_pasado[0] = u_inicial[0];
    
    //para todos mis tiempos
    while(int j<100)
    {
        for(int i=1; i<n ;i++)
        {
            u_futuro[i] = r*(u_presente[i] - u_presente[i-1]) + u_presente[i];;
        }
        
    for(int i=1; i<n ;i++) 
    {
        u_pasado[i] = u_inicial[i];
        u_presente[i] = u_futuro[i];
    }
    
    //para todos mis siguientes tiempos
    
    
    }
    
    
    
    return 0;
}
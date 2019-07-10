#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double dt, dx, c, r, l, A0, u[2000], x[2000], t[2000], u_pasado[2000], u_futuro[2000], u_presente[2000]; 
    double t1[2000], t2[2000], t3[2000], t4[2000];
    int n;
    
    l = 1.0;
    dx = 0.005;
    c = 300.0;
    n = l/dx;        //n es 200
    dt = dx*0.25/c;
    r = c*dt/dx;
    A0 = 0.01;
    
    x[0] = 0.0;
    x[n] = l;
    t[0] = 0.0;
    
    //cond de frontera para extremos fijos
    u[0] = 0.0;
    u_pasado[0] = 0.0;
    u_presente[0] = 0.0;
    u_futuro[0] = 0.0;
    u[n-1] = 0.0;
    u_pasado[n-1] = 0.0;
    u_presente[n-1] = 0.0;
    u_futuro[n-1] = 0.0;
      
    //defino mi cuerda en t=0, el cual sera mi primer pasado, y lleno mi arreglo x.
    for(int i=1; i<n; i++)
    {
        x[i] = x[i-1] + dx;
        if(x[i] <= l/2) 
        {
            u[i] = (2*A0/l)*x[i];
            u_pasado[i] = u[i];
        }
        
        else
        {
            u[i] = -(2*A0/l)*x[i] + 2*A0;
            u_pasado[i] = u[i];
        }
    }
   
    //construyo mi primer presente
    for(int i=1; i<n; i++)
    {
        u_presente[i] = (r*r/2.0) *(u_pasado[i+1] -2.0*u_pasado[i] + u_pasado[i-1]) + u_pasado[i];
    }
    
    //construyo mi funcion u en mis siguientes tiempos
    cout << "mi dt es : " << dt << endl; 
   
    for(int a=1; a<=1000; a++)
    {
        //if(t[a] >= 0.1) break;
            
        for(int i=1; i<n; i++)
        {
            u_futuro[i] = r*r *(u_presente[i+1] -2.0*u_presente[i] + u_presente[i-1]) + 2.0*u_presente[i] - u_pasado[i];
        }
      
        //construyo mis nuevos pasados y presentes
        for(int j=1; j<n; j++) 
        {
            u_pasado[j] = u_presente[j];
            u_presente[j] = u_futuro[j];
            
            if(a==200) t1[j] = u_presente[j];
            if(a==400) t2[j] = u_presente[j];
            if(a==600) t3[j] = u_presente[j];
            if(a==800) t4[j] = u_presente[j];            
        }
        
        t[a] = t[a-1] + dt;
    }
        
    //paso datos de extremos fijos
    ofstream archivo;
    archivo.open("datos.dat");
    
    for(int i=0; i<n; i++)
    {
        archivo << x[i] << " " << u[i] << " " << t1[i] << " " << t2[i] << " " << t3[i] << " " << t4[i] << endl;
    }
    archivo.close();
    
    
    //UN EXTREMO LIBRE
    
    
    return 0;    
}
    

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#define M_PI 3.14159265358979323846 /* pi */

int main()
{
    double dt, dx, c, r, l, A0, u[2000], x[2000], t[2000], u_pasado[2000], u_futuro[2000], u_presente[2000];
    double u_pre[2000], u_pas[2000], u_fut[2000];  //para caso 2
    double u_caso3[2000], u_pre_caso3[2000], u_pas_caso3[2000], u_fut_caso3[2000]; //para caso 3
    double t1[2000], t2[2000], t3[2000], t4[2000], t1_[2000], t2_[2000], t3_[2000], t4_[2000], _t1_[2000], _t2_[2000], _t3_[2000], _t4_[2000];
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
    
    //con de frontera para extremo libre
    u_pre[0] = 0.0;
    u_pas[0] = 0.0;
    u_fut[0] = 0.0;    
    
    u_caso3[0] = 0.0;
    u_pas_caso3[0] = 0.0;
    u_fut_caso3[0] = 0.0;
    t[1] = t[0] + dt;
    
    //defino mi cuerda en t=0, el cual sera mi primer pasado, y lleno mi arreglo x.
    for(int i=1; i<n; i++)
    {
        x[i] = x[i-1] + dx;
        
        u_caso3[i] = 0.0; 
        u_pas_caso3[i] = u_caso3[i];
        
        if(x[i] <= l/2) 
        {
            u[i] = (2*A0/l)*x[i];
            u_pasado[i] = u[i];
            u_pas[i] = u[i];
        }
        
        else
        {
            u[i] = -(2*A0/l)*x[i] + 2*A0;
            u_pasado[i] = u[i];
            u_pas[i] = u[i];
        }
    }
   
    //construyo mi primer presente
    for(int i=1; i<n; i++)
    {
        u_presente[i] = (r*r/2.0) *(u_pasado[i+1] -2.0*u_pasado[i] + u_pasado[i-1]) + u_pasado[i];
        u_pre[i] = u_presente[i];
        u_pre[n-1] = u_pre[n-2];
        
        u_pre_caso3[i] = (r*r/2.0) *(u_pas_caso3[i+1] -2.0*u_pas_caso3[i] + u_pas_caso3[i-1]) + u_pas_caso3[i];
        u_pre_caso3[i-1] = A0*cos(3.0*c*t[1]*M_PI/l);
    }
    
    //construyo mi funcion u en mis siguientes tiempos
    cout << "mi dt es : " << dt << endl; 
   
    for(int a=1; a<=1000; a++)
    {
        //if(t[a] >= 0.1) break;
        t[a] = t[a-1] + dt;
            
        for(int i=1; i<n; i++)
        {
            u_futuro[i] = r*r *(u_presente[i+1] -2.0*u_presente[i] + u_presente[i-1]) + 2.0*u_presente[i] - u_pasado[i];
            u_fut[i] = r*r *(u_pre[i+1] - 2.0*u_pre[i] + u_pre[i-1]) + 2.0*u_pre[i] - u_pas[i];
            u_fut[n-1] = u_fut[n-2];
            
            u_fut_caso3[i] = r*r *(u_pre_caso3[i+1] -2.0*u_pre_caso3[i] + u_pre_caso3[i-1]) + 2.0*u_pre_caso3[i] - u_pas_caso3[i];
            u_fut_caso3[i-1] = A0*cos(3.0*c*t[a]*M_PI/l);   
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
            
            u_pas[j] = u_pre[j];
            u_pre[j] = u_fut[j];
            
            if(a==200) t1_[j] = u_pre[j];
            if(a==400) t2_[j] = u_pre[j];
            if(a==600) t3_[j] = u_pre[j];
            if(a==800) t4_[j] = u_pre[j];   
            
            u_pas_caso3[j] = u_pre_caso3[j];
            u_pre_caso3[j] = u_fut_caso3[j];
            
            if(a==200) _t1_[j] = u_pre_caso3[j];
            if(a==400) _t2_[j] = u_pre_caso3[j];
            if(a==600) _t3_[j] = u_pre_caso3[j];
            if(a==800) _t4_[j] = u_pre_caso3[j]; 
        }
    }
        
    //paso datos de extremos fijos
    ofstream archivo;
    archivo.open("datos.dat");
    
    ofstream archivo1;
    archivo1.open("datos1.dat");
    
    ofstream archivo2;
    archivo2.open("datos2.dat");
    
    for(int i=0; i<n; i++)
    {
        archivo << x[i] << " " << u[i] << " " << t1[i] << " " << t2[i] << " " << t3[i] << " " << t4[i] << endl;
        archivo1 << x[i] << " " << u[i] << " " << t1_[i] << " " << t2_[i] << " " << t3_[i] << " " << t4_[i] << endl;
        archivo2 << x[i] << " " << u_caso3[i] << " " << _t1_[i] << " " << _t2_[i] << " " << _t3_[i] << " " << _t4_[i] << endl;
    }
    archivo.close();
    archivo1.close();
    archivo2.close();
    
    return 0;    
}

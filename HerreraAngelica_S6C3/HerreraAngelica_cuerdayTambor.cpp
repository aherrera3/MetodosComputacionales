#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#define M_PI 3.14159265358979323846

int main()
{
    double dt, dx, c, r, l, A0, sigma, u[2000], x[2000], t[10000], u_pasado[2000], u_futuro[2000], u_presente[2000];
    double u_pre[2000], u_pas[2000], u_fut[2000];  //para caso 2
    double u_caso3[2000], u_pre_caso3[2000], u_pas_caso3[2000], u_fut_caso3[2000]; //para caso 3
    double t1[2000], t2[2000], t3[2000], t4[2000], t1_[2000], t2_[2000], t3_[2000], t4_[2000], _t1_[2000], _t2_[2000], _t3_[2000], _t4_[2000];
    double f[2000][2000], f_presente[2000][2000], f_pasado[2000][2000], f_futuro[2000][2000];  //para membrana
    int n;
    
    l = 1.0;
    dx = 0.005;
    c = 300.0;
    n = l/dx;        //n es 200
    dt = dx*0.25/c;
    r = c*dt/dx;
    A0 = 0.01;
    sigma = 0.1;
    
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
    u_pre_caso3[0] = 0.0;
    u_fut_caso3[0] = 0.0;
    
    f[0][0] = 0.0;
    f_pasado[0][0] = 0.0;
    f_presente[0][0] = 0.0;
    f_futuro[0][0] = 0.0;
    
    //defino mi cuerda en t=0, el cual sera mi primer pasado, y lleno mi arreglo x.
    for(int i=1; i<n; i++)
    {
        u_caso3[i] = 0.0; 
        u_pas_caso3[i] = u_caso3[i];
        
        for(int j=1; j<n; j++)
        {
            x[j] = x[j-1] + dx;
            f[i][j] = A0*exp(-(x[i]-l/2)*(x[i]-l/2)/(2*sigma*sigma));   //gaussiana centrada en x=0;
        }
        
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
        if(i==n-1) u_pre_caso3[i] = A0*sin(3.0*c*t[0]*M_PI/l);
    }
    
    //construyo mi funcion u en mis siguientes tiempos
    cout << "mi dt es : " << dt << endl; 
   
    for(int k=1; k<10000; k++)
    {
        //if(t[a] >= 0.1) break;
        t[k] = t[k-1] + dt;
            
        for(int i=1; i<n; i++)
        {
            u_futuro[i] = r*r *(u_presente[i+1] -2.0*u_presente[i] + u_presente[i-1]) + 2.0*u_presente[i] - u_pasado[i];
            u_fut[i] = r*r *(u_pre[i+1] - 2.0*u_pre[i] + u_pre[i-1]) + 2.0*u_pre[i] - u_pas[i];
            u_fut[n-1] = u_fut[n-2];
            
            u_fut_caso3[i] = r*r *(u_pre_caso3[i+1] -2.0*u_pre_caso3[i] + u_pre_caso3[i-1]) + 2.0*u_pre_caso3[i] - u_pas_caso3[i];
            if(i==n-1) u_fut_caso3[i] = A0*sin(3.0*c*t[k]*M_PI/l);   
        }
      
        //construyo mis nuevos pasados y presentes
        for(int j=1; j<n; j++) 
        {
            u_pasado[j] = u_presente[j];
            u_presente[j] = u_futuro[j];
            
            if(k==200) t1[j] = u_presente[j];
            if(k==400) t2[j] = u_presente[j];
            if(k==600) t3[j] = u_presente[j];
            if(k==800) t4[j] = u_presente[j];    
            
            u_pas[j] = u_pre[j];
            u_pre[j] = u_fut[j];
            
            if(k==200) t1_[j] = u_pre[j];
            if(k==400) t2_[j] = u_pre[j];
            if(k==600) t3_[j] = u_pre[j];
            if(k==800) t4_[j] = u_pre[j];   
            
            u_pas_caso3[j] = u_pre_caso3[j];
            u_pre_caso3[j] = u_fut_caso3[j];
            
            if(k==500) _t1_[j] = u_pre_caso3[j];
            if(k==4000) _t2_[j] = u_pre_caso3[j];
            if(k==7000) _t3_[j] = u_pre_caso3[j];
            if(k==9000) _t4_[j] = u_pre_caso3[j]; 
        }
    }
        
    //paso datos de extremos fijos
    ofstream archivo;
    archivo.open("datos.dat");
    
    ofstream archivo1;
    archivo1.open("datos1.dat");
    
    ofstream archivo2;
    archivo2.open("datos2.dat");
    
    ofstream archivo3;
    archivo3.open("datos3.dat");
    
    for(int i=0; i<n; i++)
    {
        archivo << x[i] << " " << u[i] << " " << t1[i] << " " << t2[i] << " " << t3[i] << " " << t4[i] << endl;
        archivo1 << x[i] << " " << u[i] << " " << t1_[i] << " " << t2_[i] << " " << t3_[i] << " " << t4_[i] << endl;
        archivo2 << x[i] << " " << u_caso3[i] << " " << _t1_[i] << " " << _t2_[i] << " " << _t3_[i] << " " << _t4_[i] << endl;
        archivo3 << x[i] << " " << f[i][j] << endl;
    }
    archivo.close();
    archivo1.close();
    archivo2.close();
    archivo3.close();
    
    return 0;    
}







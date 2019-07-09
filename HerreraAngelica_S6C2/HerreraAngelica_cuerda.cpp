#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream archivo;
    archivo.open("datos.dat");
    
    double dt, dx, c, r, l, A0, u[2000], x[2000], t[2000], u_pasado[2000], u_futuro[2000], u_presente[2000];  //u_inicial es mi pulso en t=0
    int n;
    
    l = 1.0;
    dx = 0.005;
    c = 300.0;
    n = l/dx;        //n es 200
    dt = dx*0.25/c;
    r = c/(dt*dx);
    A0 = 0.01;
    
    x[n] = 0;
    x[0] = 0;
    t[0] = 0;
    
    //cond de frontera para extremos fijos
    u[0] = 0;
    u_pasado[0] = 0;
    u_presente[0] = 0;
    u_futuro[0] = 0;
    
    //archivo << x[0] << " " << u[0] << endl;
      
    //defino mi cuerda en t=0, el cual sera mi primer pasado
    for(int i=1; i<=n; i++)
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
        
        //archivo << x[i] << " " << u[i] << endl;
    }
   
    //construyo mi primer presente
    for(int i=1; i<=n; i++)
    {
        u_presente[i] = (r*r/2) *(u_pasado[i+1] -2*u_pasado[i] + u_pasado[i-1] ) + u_pasado[i];
    }
    
    //construyo mi funcion u en mis siguientes tiempos
    cout << "mi dt es : " << dt << endl; 
    archivo << x[0] << " " << u[0] << " " << u_futuro[0] << endl;
   
    int a = 1;
    while(t[a]<=0.1)
    {
        for(int i=1; i<=n; i++)
        {
            u_futuro[i] = r*r *(u_presente[i+1] -2*u_presente[i] + u_presente[i-1] ) + 2*u_presente[i] - u_pasado[i];
        }
            //construyo mis nuevos pasados y presentes
        for(int j=1; j<=n; j++)
        {
            u_pasado[j] = u_presente[j];
            u_presente[j] = u_futuro[j];
        }
            
        t[a] = t[a-1] + dt;
    }     
            
    archivo.close();
    return 0;    
}
    




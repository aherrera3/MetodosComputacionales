// x'' = -G m r / r**3

#include <iostream>
#include <fstream>
#include <math.h>      /* sqrt, pow() */
using namespace std; 

//variables globales
double G, m, dt, r[10000], t[10000], x[10000], y[10000], vx[10000], vy[10000]; 
double  r_[10000], x_[10000], y_[10000], vx_[10000], vy_[10000];   //leap-frog
double  _r_[10000], _x_[10000], _y_[10000], _vx_[10000], _vy_[10000];    //runge-kutta
int n;

//Declaracion de las funciones
double euler(double, double);
double leap_frog(double, double);
double runge_kutta(); 
double aceleracion(double, double);

int main()
{
    //creo archivos 
    
    ofstream archivo;
    archivo.open("euler.dat");
    ofstream archivo1;
    archivo1.open("leap_frog.dat");
    
    G = 1.98256*pow(10,-29);    //6.674*pow(10,-11);   //constante gravitacional  [N m^2/kg^2]
    m = 1.989*pow(10,30);
    
    n = 1000;
    //n1 = 10000;
   //n2 = 50000;
    
    //c.i
    x[0] = 0.1163;  //para euler
    y[0] = 0.9772;
    vx[0] = -6.35;
    vy[0] = 0.606;
    
    x_[0] = x[0];    //para leap-frog
    y_[0] = y[0];
    vx_[0] = vx[0];
    vy_[0] = vy[0];
    
    _x_[0] = x[0];    //para runge-kutta
    _y_[0] = y[0];
    _vx_[0] = vx[0];
    _vy_[0] = vy[0];
    
    r[0] = sqrt(pow(x[0],2) + pow(y[0],2));          //para euler
    r_[0] = r[0];                                   //para leap-frog  
    _r_[0] = r[0];                                 //para runge-kutta
    
    cout << "mi r es :" << r[0] << endl;
     
    archivo << t[0] << " " << x[0] << " " << y[0] << " " << vx[0] << " " << vy[0] << endl;
    archivo1 << t[0] << " " << x_[0] << " " << y_[0] << " " << vx_[0] << " " << vy_[0] << endl;
    
    for(int i=1; i<n; i++)
    {
        t[i] = t[i-1] + dt; 
        
        //euler
        vx[i] = vx[i-1] + dt*aceleracion(x[i-1], r[i-1]);
        vy[i] = vy[i-1] + dt*aceleracion(y[i-1], r[i-1]);
        x[i] = euler(x[i-1], vx[i-1]);
        y[i] = euler(y[i-1], vy[i-1]);
        
        r[i] = sqrt(pow(x[i],2) + pow(y[i],2));
        /*
        if(i<=n-1)    //si tengo n=1000 puntos
        {
            double t[1000];
            t[0] = 0.0;
            t[n-1] = 20.0;   //20 orbitas = 20 años
            dt = (t[n-1]-t[0])/(n-1);
            
            archivo << t[i] << " " << x[i] << " " << y[i] << " " << vx[i] << " " << vy[i] << endl;
            
        }
        */
        //leap-frog
        if(i==1)
        {
            x_[i] = x[i];
            y_[i] = y[i];
            vx_[i] = vx[i];
            vy_[i] = vy[i];
        }
        
        else
        {
            vx_[i] = vx_[i-2] + 2*dt*aceleracion(x_[i-1], r_[i-1]);
            vy_[i] = vy_[i-2] + 2*dt*aceleracion(y_[i-1], r_[i-1]);
            x_[i] = leap_frog(x_[i-2], vx_[i-1]);
            y_[i] = leap_frog(y_[i-2], vy_[i-1]);
        }
        
        r_[i] = sqrt(pow(x_[i],2) + pow(y_[i],2));
        
        
        archivo << t[i] << " " << x[i] << " " << y[i] << " " << vx[i] << " " << vy[i] << endl;
        archivo1 << t[i] << " " << x_[i] << " " << y_[i] << " " << vx_[i] << " " << vy_[i] << endl;
    }
    
    archivo.close();
    archivo1.close();
    
    //runge kutta
    runge_kutta();
    
    return 0;    
}

double aceleracion(double pos_antes, double r_antes)
{
    return -G*m*pos_antes/pow(r_antes,3);
}

double euler(double pos_antes, double v_antes)
{
    return pos_antes + dt*v_antes;
}

double leap_frog(double pos_antes_antes, double v_antes)
{
    return pos_antes_antes + 2*dt*v_antes;
}

double runge_kutta()
{
    ofstream archivo2;
    archivo2.open("runge_kutta.dat");
    
    archivo2 << t[0] << " " << _x_[0] << " " << _y_[0] << " " << _vx_[0] << " " << _vy_[0] << endl;
    
    for(int i=1; i<n; i++)
    {
        double k1_1_x = _vx_[i-1];
        double k1_2_x = aceleracion(_x_[i-1], _r_[i-1]);
        double k1_1_y = _vy_[i-1];
        double k1_2_y = aceleracion(_y_[i-1], _r_[i-1]);
    
        double pos1_x = _x_[i-1] + (dt/2) * k1_1_x;
        double v1_x = _vx_[i-1] + (dt/2) * k1_2_x;
        double pos1_y = _y_[i-1] + (dt/2) * k1_1_y;
        double v1_y = _vy_[i-1] + (dt/2) * k1_2_y;
    
        double k2_1_x = v1_x;
        double k2_2_x = aceleracion(pos1_x, _r_[i-1]);
        double k2_1_y = v1_y;
        double k2_2_y = aceleracion(pos1_y, _r_[i-1]);
    
        double pos2_x = _x_[i-1] + (dt/2) * k2_1_x;
        double v2_x = _vx_[i-1] + (dt/2) * k2_2_x;
        double pos2_y = _y_[i-1] + (dt/2) * k2_1_y;
        double v2_y = _vy_[i-1] + (dt/2) * k2_2_y;

        double k3_1_x = v2_x;
        double k3_2_x = aceleracion(pos2_x, _r_[i-1]);
        double k3_1_y = v2_y;
        double k3_2_y = aceleracion(pos2_y, _r_[i-1]);

        double pos3_x = _x_[i-1] + dt * k3_1_x;
        double v3_x  = _vx_[i-1] + dt * k3_2_x;
        double pos3_y = _y_[i-1] + dt * k3_1_y;
        double v3_y  = _vy_[i-1] + dt * k3_2_y;

        double k4_1_x = v3_x;
        double k4_2_x = aceleracion(pos3_x, _r_[i-1]);
        double k4_1_y = v3_y;
        double k4_2_y = aceleracion(pos3_y, _r_[i-1]);
 
        double k1_promedio_x = (k1_1_x + 2*k2_1_x + 2*k3_1_x + k4_1_x)/6 ;
        double k2_promedio_x = (k1_2_x + 2*k2_2_x + 2*k3_2_x + k4_2_x)/6 ; 
        double k1_promedio_y = (k1_1_y + 2*k2_1_y + 2*k3_1_y + k4_1_y)/6 ;
        double k2_promedio_y = (k1_2_y + 2*k2_2_y + 2*k3_2_y + k4_2_y)/6 ; 

        _vx_[i] = _vx_[i-1] + dt*k2_promedio_x;
        _x_[i] = _x_[i-1] + dt*k1_promedio_x;
        _vy_[i] = _vy_[i-1] + dt*k2_promedio_y;
        _y_[i] = _y_[i-1] + dt*k1_promedio_y;
        
        _r_[i] = sqrt(pow(_x_[i],2) + pow(_y_[i],2));
        
        archivo2 << t[i] << " " << _x_[i] << " " << _y_[i] << " " << _vx_[i] << " " << _vy_[i]  << endl;
    }
    
    archivo2.close();
} 

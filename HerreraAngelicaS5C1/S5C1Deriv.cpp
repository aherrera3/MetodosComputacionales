#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//variables globales
double *p_x;             //apuntador a mi arreglo x
double *p_coseno;        //apuntador a mi arreglo coseno
double *p_derivada;      //aputador a mi arreglo de derivadas 
double a, b, start, stop, dx, x[1000], coseno[1000], der[1000];
int n;

//declaro mi funcion derivada
double * derivada(double*, double*);

//metodo constructor
int main()
{   
    //abro y creo un archivo llamado datos.dat
    ofstream archivo;
    archivo.open("datos.dat");
    
    cout<<"Introduce el primer número entero: ";
    cin>>a;
    
    cout<<"Introduce el segundo número entero: ";
    cin>>b;
    
    cout << "Introduce el número de puntos del intervalo: "; //cuento como puntos a mis dos extremos
    cin >> n;
    
    if(a<b)
    {
        start = a;
        stop = b;
    }
    
    else
    {
        start = b;
        stop = a;
    }
    
    dx = (stop-start)/(n-1);
    x[0] = start;
    coseno[0] = cos(x[0]);   //toma a los x como radianes    
   
    for(int i = 1; i<n ; i++)
    {
        x[i] = x[i-1] + dx;
        coseno[i] = cos(x[i]);
    }  
    
    //inicializo mis pointers de los arreglos x y coseno
    p_x = x;
    p_coseno = coseno;
    
    for(int i = 0; i<n-1 ;i++)
    {
        archivo << x[i] << " " << coseno[i] << " " << derivada(p_x, p_coseno)[i] << endl;  
    }
    
    archivo.close();
    
    return 0;
}


/*Funcion que calcula la derivada de coseno
Return: pointer en donde se contiene la informacion de la derivada de coseno
Parametros: apuntadores de coseno y de x
*/

double * derivada(double *p_x, double *p_coseno)
{
    for(int i = 0 ; i<n ; i++) der[i] = (p_coseno[i+1]-p_coseno[i])/(dx);    //derivo por forward a todos mis elementos
         
    p_derivada = der;    
    return p_derivada;   
} 

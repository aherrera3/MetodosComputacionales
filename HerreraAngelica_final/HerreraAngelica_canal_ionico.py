import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("Canal_ionico.txt", delimiter= "\t")

x = datos[:,0]
y = datos[:,1]

x_min = min(x)
x_max = max(x)
y_min = min(y)
y_max = max(y)
N = len(x)
#print(y_min, x_min, x_max, y_max)
# estimar el radio

radios = []  # posibles radios dentro de puntos
def caminata(x,y):
    r_viejo = np.random.uniform(0, y_max)
    for i in range(N):
        r_nuevo = np.random.uniform(0, y_max)
        
        if(r_viejo )
        x_viejo = r_viejo*x[i]
        y_viejo = r_viejo*y[i]
    
    print(r_viejo)
    
    
    #return radios

caminata(x,y)
r_mejor = 1#max(radios)

angulos = np.linspace(0, 2*np.pi, N)
x_c = r_mejor*np.cos(angulos)
y_c = r_mejor*np.sin(angulos)

plt.figure()
plt.scatter(x,y)
plt.plot(x_c, y_c, c="b")
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("Canal.png")

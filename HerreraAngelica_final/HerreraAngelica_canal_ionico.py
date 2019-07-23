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
    for j in range(10000):
        x_aleatorio = np.random.uniform(x_min, x_max)
        y_aleatorio = np.random.uniform(y_min, x_max)
        r_aleatorio = np.sqrt(x_aleatorio**2 + y_aleatorio**2)/2
    
        contador = 0;
        for i in range(N):        
            r_datos = np.sqrt(x[i]**2 + y[i]**2)/2
            if(r_aleatorio<r_datos):
                contador=contador+1
                
        if(contador==N):  # me sirve
            radios.append(r_aleatorio)
     
    return radios;

print("mis radios son : ", caminata(x,y))    
r_mejor = max(caminata(x,y))
print("mi r mejor es : ", r_mejor)

angulos = np.linspace(0, 2*np.pi, N)
x_c = r_mejor*np.cos(angulos)
y_c = r_mejor*np.sin(angulos)

plt.figure()
plt.scatter(x,y)
plt.plot(x_c, y_c, c="b")
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("Canal.png")

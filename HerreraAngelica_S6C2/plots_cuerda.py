import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("datos.dat")

x = datos[:,0]
u = datos[:,1]
u_futuro= datos[:,2]

plt.figure()
plt.plot(x, u)
plt.plot(x, u_futuro)
plt.xlabel("x")
plt.ylabel("u")
#plt.title("Solucion x a la EDO m x'' = -k x")
plt.grid()
plt.savefig("HerreraAngelicaS6C1")
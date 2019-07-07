import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("datos.dat")

t = datos[:,0]
x = datos[:,1]

plt.figure()
plt.plot(t, x, label = "por leap-frog")
plt.xlabel("t")
plt.ylabel("x (t)")
plt.legend()
plt.title("Solucion x a la EDO m x'' = -k x")
plt.grid()
plt.savefig("S5C3PLOT")
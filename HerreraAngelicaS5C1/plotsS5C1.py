#script para realizar grafica de coseno y su derivada
import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("datos.dat")

x = datos[:,0]
cos = datos[:,1]
sen = datos[:,2]

plt.figure()
plt.plot(x, cos, label="coseno")
plt.plot(x, sen, label="derivada numerica de coseno")
plt.xlabel("x (radianes)")
plt.ylabel("f (x)")
plt.legend()
plt.title("Coseno con su derivada numerica")
plt.grid()
plt.savefig("S5C1PLOT.pdf")

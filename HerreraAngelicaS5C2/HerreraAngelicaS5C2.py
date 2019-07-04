import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("datos.dat")

x = datos[:,0]
y = datos[:,1]

plt.figure()
plt.plot(x, y, label="solucion y")
plt.xlabel("x")
plt.ylabel("y (x)")
plt.legend()
plt.title("solucion y por medio de euler")
plt.grid()
plt.savefig("S5C2PLOT")
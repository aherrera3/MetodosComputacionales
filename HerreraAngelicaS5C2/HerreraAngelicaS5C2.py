import numpy as np
import matplotlib.pyplot as plt

datos_euler = np.genfromtxt("datos_euler.dat")
datos_runge = np.genfromtxt("datos_runge.dat")

x = datos_euler[:,0]
euler = datos_euler[:,1]

x1 = datos_runge[:,0]
runge = datos_runge[:,1]

plt.figure()
plt.plot(x, euler, label="por euler")
plt.plot(x1, runge, label="por runge-kutta")
plt.xlabel("x")
plt.ylabel("y (x)")
plt.legend()
plt.title("Solucion y a la EDO y'=-y ")
plt.grid()
plt.savefig("S5C2PLOT")
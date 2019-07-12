import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

datos = np.genfromtxt("datos.dat")
x = datos[:,0]
y = datos[:,1]

matriz = np.genfromtxt("matriz.dat")
t1 = np.genfromtxt("t1.dat")
t2 = np.genfromtxt("t2.dat")


x,y = np.meshgrid(x, y)

plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, matriz)
ax.set_title('T(x,y,t) inicial')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_inicial")


plt.figure()
ax1 = plt.axes(projection='3d')
ax1.plot_surface(x, y, t1)
ax1.set_title('T(x,y,t) en t=100s')
plt.xlabel("x")
plt.ylabel("y")
ax1.set_zlabel("z")
plt.savefig("T_100s")


plt.figure()
ax2 = plt.axes(projection='3d')
ax2.plot_surface(x, y, t2)
ax2.set_title('T(x,y,t) en t=2500s')
plt.xlabel("x")
plt.ylabel("y")
ax2.set_zlabel("z")
plt.savefig("T_2500s")

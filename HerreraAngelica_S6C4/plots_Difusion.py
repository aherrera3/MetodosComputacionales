import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

datos = np.genfromtxt("datos.dat")
x = datos[:,0]
y = datos[:,1]

x,y = np.meshgrid(x, y)

matriz = np.genfromtxt("t_inicial.dat")
t1 = np.genfromtxt("t1.dat")
t2 = np.genfromtxt("t2.dat")

plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, matriz)
ax.set_title('T(x,y,t) inicial')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_inicial")


plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, t1)
ax.set_title('T(x,y,t) en t=100s')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_100s")


plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, t2)
ax.set_title('T(x,y,t) en t=2500s')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_2500s")


#extremos libres

t1_libres = np.genfromtxt("t1_libres.dat")
t2_libres = np.genfromtxt("t2_libres.dat")

plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, t1_libres)
ax.set_title('T(x,y,t) en t=100s ext libres')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_100s_libres")


plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, t2_libres)
ax.set_title('T(x,y,t) en t=2500s ext libres')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_2500s_libres")


#extremos periodicos

tiempo1 = np.genfromtxt("t1_periodicas.dat")
tiempo2 = np.genfromtxt("t2_periodicas.dat")

plt.figure()
ax4 = plt.axes(projection='3d')
ax4.plot_surface(x, y, tiempo1)
ax4.set_title('T(x,y,t) en t=100s ext periodicos')
plt.xlabel("x")
plt.ylabel("y")
ax4.set_zlabel("z")
plt.savefig("T_100s_periodicos")


plt.figure()
ax5 = plt.axes(projection='3d')
ax5.plot_surface(x, y, tiempo2)
ax5.set_title('T(x,y,t) en t=2500s ext periodicos')
plt.xlabel("x")
plt.ylabel("y")
ax5.set_zlabel("z")
plt.savefig("T_2500s_periodicos")


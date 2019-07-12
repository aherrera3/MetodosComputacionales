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

t1_ = np.genfromtxt("t1_libres.dat")
t2_ = np.genfromtxt("t2_libres.dat")

plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, t1_)
ax.set_title('T(x,y,t) en t=100s ext libres')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_100s_libres")


plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(x, y, t2_)
ax.set_title('T(x,y,t) en t=2500s ext libres')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")
plt.savefig("T_2500s_libres")

"""
#extremos periodicos

_t1_ = np.genfromtxt("t1_libres.dat")
_t2_ = np.genfromtxt("t2_libres.dat")

plt.figure()
ax4 = plt.axes(projection='3d')
ax4.plot_surface(x, y, _t1_)
ax4.set_title('T(x,y,t) en t=100s ext libres')
plt.xlabel("x")
plt.ylabel("y")
ax4.set_zlabel("z")
plt.savefig("T_100s_libres")


plt.figure()
ax5 = plt.axes(projection='3d')
ax5.plot_surface(x, y, _t2_)
ax5.set_title('T(x,y,t) en t=2500s ext libres')
plt.xlabel("x")
plt.ylabel("y")
ax5.set_zlabel("z")
plt.savefig("T_2500s_libres")
"""


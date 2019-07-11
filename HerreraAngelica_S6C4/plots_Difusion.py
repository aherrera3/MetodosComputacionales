import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

datos = np.genfromtxt("datos.dat")
x = datos[:,0]
y = datos[:,1]

matriz = np.genfromtxt("matriz.dat")

plt.figure()
ax = plt.axes(projection='3d')
x,y = np.meshgrid(x, y)
ax.plot_surface(x, y, matriz)
ax.set_title('T inicial')
plt.xlabel("x")
plt.ylabel("y")
ax.set_zlabel("z")

plt.savefig("grafica")

import numpy as np
import matplotlib.pyplot as plt


#EDO
euler = np.genfromtxt("euler.dat")
leap_frog = np.genfromtxt("leap_frog")
runge_kutta = np.genfromtxt("runge_kutta")

x = euler[:,0]
y = euler[:,1]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Euler")
plt.grid()
plt.savefig("euler")

x = leap_frog[:,0]
y = leap_frog[:,1]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Leap-Frog")
plt.grid()
plt.savefig("leap_frog")

x = runge_kutta[:,0]
y = runge_kutta[:,1]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta")

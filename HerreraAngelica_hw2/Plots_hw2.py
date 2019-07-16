import numpy as np
import matplotlib.pyplot as plt


#EDO
euler = np.genfromtxt("euler.dat")
leap_frog = np.genfromtxt("leap_frog.dat")
runge_kutta = np.genfromtxt("runge_kutta.dat")

x = euler[:,1]
y = euler[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Euler")
plt.grid()
plt.savefig("euler")

x = leap_frog[:,1]
y = leap_frog[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Leap-Frog")
plt.grid()
plt.savefig("leap_frog")

x = runge_kutta[:,1]
y = runge_kutta[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta")

import numpy as np
import matplotlib.pyplot as plt


#EDO
euler = np.genfromtxt("euler_dt1.dat")
leap_frog = np.genfromtxt("leap_frog_dt1.dat")
#runge_kutta = np.genfromtxt("runge_kutta_dt1.dat")

x = euler[:,1]
y = euler[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Euler")
plt.grid()
plt.savefig("euler_dt1")

x = leap_frog[:,1]
y = leap_frog[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Leap-Frog")
plt.grid()
plt.savefig("leap_frog_dt1")
"""
x = runge_kutta[:,1]
y = runge_kutta[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta_dt1")
"""
#para dt=0.002
euler = np.genfromtxt("euler_dt2.dat")
leap_frog = np.genfromtxt("leap_frog_dt2.dat")
#runge_kutta = np.genfromtxt("runge_kutta_dt2.dat")

x = euler[:,1]
y = euler[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Euler")
plt.grid()
plt.savefig("euler_dt2")

x = leap_frog[:,1]
y = leap_frog[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Leap-Frog")
plt.grid()
plt.savefig("leap_frog_dt2")
"""
x = runge_kutta[:,1]
y = runge_kutta[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta_dt2")
"""

#para dt=0.0002
euler = np.genfromtxt("euler_dt3.dat")
leap_frog = np.genfromtxt("leap_frog_dt3.dat")
#runge_kutta = np.genfromtxt("runge_kutta_dt3.dat")

x = euler[:,1]
y = euler[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Euler")
plt.grid()
plt.savefig("euler_dt3")

x = leap_frog[:,1]
y = leap_frog[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Leap-Frog")
plt.grid()
plt.savefig("leap_frog_dt3")
"""
x = runge_kutta[:,1]
y = runge_kutta[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta_dt3")
"""

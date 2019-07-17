import numpy as np
import matplotlib.pyplot as plt

#GRAFICAS Y vs X
#para dt=0.02
euler_dt1 = np.genfromtxt("euler_dt1.dat")
leap_frog_dt1 = np.genfromtxt("leap_frog_dt1.dat")
runge_kutta_dt1 = np.genfromtxt("runge_kutta_dt1.dat")

#para dt=0.002
euler_dt2 = np.genfromtxt("euler_dt2.dat")
leap_frog_dt2 = np.genfromtxt("leap_frog_dt2.dat")
runge_kutta_dt2 = np.genfromtxt("runge_kutta_dt2.dat")

#para dt=0.0002
euler_dt3 = np.genfromtxt("euler_dt3.dat")
leap_frog_dt3 = np.genfromtxt("leap_frog_dt3.dat")
runge_kutta_dt3 = np.genfromtxt("runge_kutta_dt3.dat")

x1 = euler_dt1[:,1]
x2 = euler_dt2[:,1]
x3 = euler_dt3[:,1]

y1 = euler_dt1[:,2]
y2 = euler_dt2[:,2]
y3 = euler_dt3[:,2]


x1_ = leap_frog_dt1[:,1]
x2_ = leap_frog_dt2[:,1]
x3_ = leap_frog_dt3[:,1]

y1_ = leap_frog_dt1[:,2]
y2_ = leap_frog_dt2[:,2]
y3_ = leap_frog_dt3[:,2]


_x1_ = runge_kutta_dt1[:,1]
_x2_ = runge_kutta_dt2[:,1]
_x3_ = runge_kutta_dt3[:,1]

_y1_ = runge_kutta_dt1[:,2]
_y2_ = runge_kutta_dt2[:,2]
_y3_ = runge_kutta_dt3[:,2]


plt.figure(figsize=(10,7))
plt.subplot(3,3,1)
plt.plot(x1, y1)
plt.title("euler dt=0.02")
plt.ylabel("y")
plt.grid()

plt.subplot(3,3,2)
plt.plot(x2, y2)
plt.title("euler dt=0.002")
plt.grid()

plt.subplot(3,3,3)
plt.plot(x3, y3)
plt.title("euler dt=0.0002")
plt.grid()

plt.subplot(3,3,4)
plt.plot(x1_, y1_)
plt.title("\n \n \n leap-frog dt=0.02")
plt.ylabel("y")
plt.grid()

plt.subplot(3,3,5)
plt.plot(x2_, y2_)
plt.title("\n \n \n leap-frog dt=0.002")
plt.grid()

plt.subplot(3,3,6)
plt.plot(x3_, y3_)
plt.title("\n \n \n  leap-frog dt=0.0002")
plt.grid()

plt.subplot(3,3,7)
plt.plot(_x1_, _y1_)
plt.title("runge-kutta dt=0.02")
plt.ylabel("y")
plt.xlabel("x")
plt.grid()

plt.subplot(3,3,8)
plt.plot(_x2_, _y2_)
plt.title("runge-kutta dt=0.002")
plt.xlabel("x")
plt.grid()

plt.subplot(3,3,9)
plt.plot(_x3_, _y3_)
plt.title("runge-kutta dt=0.0002")
plt.xlabel("x")
plt.grid()

plt.subplots_adjust(hspace = 0.5)
plt.suptitle("y vs x para 20 orbitas de la Tierra")
plt.savefig("y_vs_x")


"""
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

x = runge_kutta[:,1]
y = runge_kutta[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta_dt1")

#para dt=0.002
euler = np.genfromtxt("euler_dt2.dat")
leap_frog = np.genfromtxt("leap_frog_dt2.dat")
runge_kutta = np.genfromtxt("runge_kutta_dt2.dat")

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

x = runge_kutta[:,1]
y = runge_kutta[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta_dt2")


#para dt=0.0002
euler = np.genfromtxt("euler_dt3.dat")
leap_frog = np.genfromtxt("leap_frog_dt3.dat")
runge_kutta = np.genfromtxt("runge_kutta_dt3.dat")

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

x = runge_kutta[:,1]
y = runge_kutta[:,2]

plt.figure()
plt.plot(x,y)
plt.title("20 orbitas de la Tierra por Runge-Kutta")
plt.grid()
plt.savefig("runge_kutta_dt3")
"""

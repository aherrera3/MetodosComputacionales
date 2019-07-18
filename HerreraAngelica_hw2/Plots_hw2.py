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
plt.title("leap-frog dt=0.02")
plt.ylabel("y")
plt.grid()

plt.subplot(3,3,5)
plt.plot(x2_, y2_)
plt.title("leap-frog dt=0.002")
plt.grid()

plt.subplot(3,3,6)
plt.plot(x3_, y3_)
plt.title("leap-frog dt=0.0002")
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


#GRAFICA DE Vy vs Vx
vx1 = euler_dt1[:,3]
vx2 = euler_dt2[:,3]
vx3 = euler_dt3[:,3]

vy1 = euler_dt1[:,4]
vy2 = euler_dt2[:,4]
vy3 = euler_dt3[:,4]

vx1_ = leap_frog_dt1[:,3]
vx2_ = leap_frog_dt2[:,3]
vx3_ = leap_frog_dt3[:,3]

vy1_ = leap_frog_dt1[:,4]
vy2_ = leap_frog_dt2[:,4]
vy3_ = leap_frog_dt3[:,4]

_vx1_ = runge_kutta_dt1[:,3]
_vx2_ = runge_kutta_dt2[:,3]
_vx3_ = runge_kutta_dt3[:,3]

_vy1_ = runge_kutta_dt1[:,4]
_vy2_ = runge_kutta_dt2[:,4]
_vy3_ = runge_kutta_dt3[:,4]

plt.figure(figsize=(10,7))
plt.subplot(3,3,1)
plt.plot(vx1, vy1)
plt.title("euler dt=0.02")
plt.ylabel("vy")
plt.grid()

plt.subplot(3,3,2)
plt.plot(vx2, vy2)
plt.title("euler dt=0.002")
plt.grid()

plt.subplot(3,3,3)
plt.plot(vx3, vy3)
plt.title("euler dt=0.0002")
plt.grid()

plt.subplot(3,3,4)
plt.plot(vx1_, vy1_)
plt.title("leap-frog dt=0.02")
plt.ylabel("vy")
plt.grid()

plt.subplot(3,3,5)
plt.plot(vx2_, vy2_)
plt.title("leap-frog dt=0.002")
plt.grid()

plt.subplot(3,3,6)
plt.plot(vx3_, vy3_)
plt.title("leap-frog dt=0.0002")
plt.grid()

plt.subplot(3,3,7)
plt.plot(_vx1_, _vy1_)
plt.title("runge-kutta dt=0.02")
plt.ylabel("vy")
plt.xlabel("vx")
plt.grid()

plt.subplot(3,3,8)
plt.plot(_vx2_, _vy2_)
plt.title("runge-kutta dt=0.002")
plt.xlabel("vx")
plt.grid()

plt.subplot(3,3,9)
plt.plot(_vx3_, _vy3_)
plt.title("runge-kutta dt=0.0002")
plt.xlabel("vx")
plt.grid()

plt.subplots_adjust(hspace = 0.5)
plt.suptitle("vy vs vx para 20 orbitas de la Tierra")
plt.savefig("vy_vs_vx")



#CALCULO DEL MOMENTO ANGULAR DE LA TIERRA  (L = r x p = r x mv = rmv sen(90))
#Se suponen tierra y sol como masas puntuales, y orbita de la tierra circular
m_s = 1.989e30      #masa del sol
m = 5.972e24#/m_s    #masa de la tierra [kg]

#tiempos
t1 = euler_dt1[:,0]
t2 = euler_dt2[:,0]
t3 = euler_dt3[:,0]
t1_ = leap_frog_dt1[:,0]
t2_ = leap_frog_dt2[:,0]
t3_ = leap_frog_dt3[:,0]
_t1_ = runge_kutta_dt1[:,0]
_t2_ = runge_kutta_dt2[:,0]
_t3_ = runge_kutta_dt3[:,0]

#radios de orbita para euler
r1 = euler_dt1[:,5]
r2 = euler_dt2[:,5]
r3 = euler_dt3[:,5]
#radios de orbita para leap-frog
r1_ = leap_frog_dt1[:,5]
r2_ = leap_frog_dt2[:,5]
r3_ = leap_frog_dt3[:,5]
#radios de orbita para runge-kutta
_r1_ = runge_kutta_dt1[:,5]
_r2_ = runge_kutta_dt2[:,5]
_r3_ = runge_kutta_dt3[:,5]

#magnitud de la velocidad para euler
v1 = np.sqrt(vx1**2 + vy1**2)
v2 = np.sqrt(vx2**2 + vy2**2)
v3 = np.sqrt(vx3**2 + vy3**2)
#magnitud de la velocidad para leap-frog
v1_ = np.sqrt(vx1_**2 + vy1_**2)
v2_ = np.sqrt(vx2_**2 + vy2_**2)
v3_ = np.sqrt(vx3_**2 + vy3_**2)
#magnitud de la velocidad para runge-kutta
_v1_ = np.sqrt(_vx1_**2 + _vy1_**2)
_v2_ = np.sqrt(_vx2_**2 + _vy2_**2)
_v3_ = np.sqrt(_vx3_**2 + _vy3_**2)

#momentos angulares de euler
L1 = r1*m*v1
L2 = r2*m*v2
L3 = r3*m*v3
#momentos angulares de leap-frog
L1_ = r1_*m*v1_
L2_ = r2_*m*v2_
L3_ = r3_*m*v3_
#momentos angulares de runge-kutta
_L1_ = _r1_*m*_v1_
_L2_ = _r2_*m*_v2_
_L3_ = _r3_*m*_v3_

#GRAFICA DE LOS MOMENTOS ANGULARES
plt.figure(figsize=(10,7))
plt.subplot(3,3,1)
plt.plot(t1, L1)
plt.title("euler dt=0.02")
plt.ylabel("L")
plt.grid()

plt.subplot(3,3,2)
plt.plot(t2, L2)
plt.title("euler dt=0.002")
plt.grid()

plt.subplot(3,3,3)
plt.plot(t3, L3)
plt.title("euler dt=0.0002")
plt.grid()

plt.subplot(3,3,4)
plt.plot(t1_, L1_)
plt.title("leap-frog dt=0.02")
plt.ylabel("L")
plt.grid()

plt.subplot(3,3,5)
plt.plot(t2_, L2_)
plt.title("leap-frog dt=0.002")
plt.grid()

plt.subplot(3,3,6)
plt.plot(t3_, L3_)
plt.title("leap-frog dt=0.0002")
plt.grid()

plt.subplot(3,3,7)
plt.plot(_t1_, _L1_)
plt.title("runge-kutta dt=0.02")
plt.ylabel("L")
plt.xlabel("t (años)")
plt.grid()

plt.subplot(3,3,8)
plt.plot(_t2_, _L2_)
plt.title("runge-kutta dt=0.002")
plt.xlabel("t (años)")
plt.grid()

plt.subplot(3,3,9)
plt.plot(_t3_, _L3_)
plt.title("runge-kutta dt=0.0002")
plt.xlabel("t (años)")
plt.grid()

plt.subplots_adjust(hspace = 0.5, wspace=0.3)
plt.suptitle("L vs t para 20 orbitas de la Tierra")
plt.savefig("L_vs_t")








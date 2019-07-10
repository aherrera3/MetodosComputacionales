import numpy as np
import matplotlib.pyplot as plt

#PARA EXTREMOS FIJOS
datos = np.genfromtxt("datos.dat")

x = datos[:,0]
u_t0 = datos[:,1]
u_t1 = datos[:,2]
u_t2 = datos[:,3]
u_t3 = datos[:,4]
u_t4 = datos[:,5]

plt.figure(figsize=(10,7))
plt.subplot(2,2,1)
plt.plot(x,u_t0)
plt.plot(x,u_t1)
plt.title("t1")
plt.ylabel("amplitud")
plt.grid()

plt.subplot(2,2,2)
plt.plot(x,u_t0)
plt.plot(x,u_t2)
plt.title("t2")
plt.grid()

plt.subplot(2,2,3)
plt.plot(x,u_t0)
plt.plot(x,u_t3)
plt.title("t3")
plt.ylabel("amplitud")
plt.xlabel("x")
plt.grid()

plt.subplot(2,2,4)
plt.plot(x,u_t0)
plt.plot(x,u_t4)
plt.title("t4")
plt.xlabel("x")
plt.grid()

plt.suptitle("Cuerda con extremos fijos en diferentes tiempos")
plt.savefig("extremos_fijos")

#PARA UN EXTREMO LIBRE

datos = np.genfromtxt("datos1.dat")

x = datos[:,0]
u_t0_ = datos[:,1]
u_t1_ = datos[:,2]
u_t2_ = datos[:,3]
u_t3_ = datos[:,4]
u_t4_ = datos[:,5]

plt.figure(figsize=(10,7))
plt.subplot(2,2,1)
plt.plot(x,u_t0_)
plt.plot(x,u_t1_)
plt.title("t1")
plt.ylabel("amplitud")
plt.grid()

plt.subplot(2,2,2)
plt.plot(x,u_t0_)
plt.plot(x,u_t2_)
plt.title("t2")
plt.grid()

plt.subplot(2,2,3)
plt.plot(x,u_t0_)
plt.plot(x,u_t3_)
plt.title("t3")
plt.ylabel("amplitud")
plt.xlabel("x")
plt.grid()

plt.subplot(2,2,4)
plt.plot(x,u_t0_)
plt.plot(x,u_t4_)
plt.title("t4")
plt.xlabel("x")
plt.grid()

plt.suptitle("Cuerda con extremos libres en diferentes tiempos")
plt.savefig("extremos_libres")


import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft2, ifft2, fftshift

#Almaceno los datos las dos imágenes
im1 = plt.imread("cara_02_grisesMF.png")   #imagen sorprendida
im2 = plt.imread("cara_03_grisesMF.png")   #imagen feliz

#Transformada de Fourier en 2D de ambas imágenes
fourier_im1 = fft2(im1)
fourier_im2 = fft2(im2)

#Gráfica del espectro de Fourier de cada imagen
from matplotlib.colors import LogNorm
plt.figure()
plt.imshow(abs(fourier_im1), norm=LogNorm())
plt.title("Espectro de Fourier de im1")
plt.savefig("FFT2D_im1.png")

plt.figure()
plt.imshow(abs(fourier_im2), norm=LogNorm())
plt.title("Espectro de Fourier de im2")
plt.savefig("FFT2D_im2.png")

#Grafica de las frecuencias de cada imagen
freq_im1 = fftshift(fourier_im1)
freq_im2 = fftshift(fourier_im2)

plt.figure()
plt.imshow(abs(freq_im1), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de frecuencias de im1")
plt.savefig("freq_im1.png")

plt.figure()
plt.imshow(abs(freq_im2), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de frecuencias de im2")
plt.savefig("freq_im2.png")

#Filtros y sus graficas
#filtro paso alto para imagen de cerca
fc_1 = 1
ind_im1 = np.where(abs(freq_im1) < fc_1)   #indices de mis frecuencias malas
freq_im1[ind_im1] = 0   #mando a 0 las frecuencias malas
trans_im1 = np.copy(fourier_im1)
trans_im1[ind_im1] = 0

plt.figure()
plt.imshow(abs(freq_im1), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de filtrado im1")
plt.savefig("filtro_im1.png")

#filtro paso bajo para imagen de lejos
fc_2 = 10
ind_im2 = np.where(abs(freq_im2) > fc_2)
freq_im2[ind_im2] = 0
trans_im2 = np.copy(fourier_im2)
trans_im2[ind_im2] = 0


plt.figure()
plt.imshow(abs(freq_im2), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de filtrado im2")
plt.savefig("filtro_im2.png")

#Graficas de imagenes filtradas
im1_fil = ifft2(trans_im1)
plt.figure()
plt.imshow(np.real(im1_fil), plt.cm.gray)
plt.title("im1 filtrada")
plt.savefig("im1_filtrada.png")

im2_fil = ifft2(trans_im2)
plt.figure()
plt.imshow(np.real(im2_fil), plt.cm.gray)
plt.title("im2 filtrada")
plt.savefig("im2_filtrada.png")

#Grafica de ambas juntas (imagen hibrida)

im_hibrida = np.real(im1_fil) + np.real(im2_fil)
plt.figure()
plt.imshow(im_hibrida, plt.cm.gray)
plt.title('imagen hibrida')
plt.savefig("im_hibrida.png")



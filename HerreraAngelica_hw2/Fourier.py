import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft2, ifft2, fftshift, ifftshift

# Almaceno los datos las dos imágenes
im1 = plt.imread("cara_03_grisesMF.png")      #imagen feliz
im2 = plt.imread("cara_02_grisesMF.png")      #imagen seria

# Gráfica de las imagenes originales
plt.figure(figsize=(10,10))
plt.subplot(1,2,1)
plt.imshow(im1, plt.cm.gray)
plt.title("im1")
plt.subplot(1,2,2)
plt.imshow(im2, plt.cm.gray)
plt.title("im2")
plt.savefig("originales.pdf")

# Transformada de Fourier en 2D de ambas imágenes
fourier_im1 = fft2(im1)
fourier_im2 = fft2(im2)

# Gráfica del espectro de Fourier de cada imagen
from matplotlib.colors import LogNorm

plt.figure(figsize=(10,10))
plt.subplot(1,2,1)
plt.imshow(abs(fourier_im1), norm=LogNorm())
plt.title("Espectro de Fourier de im1")
plt.subplot(1,2,2)
plt.imshow(abs(fourier_im2), norm=LogNorm())
plt.title("Espectro de Fourier de im2")
plt.savefig("FFtIm.pdf")

# Frecuencias de cada imagen
freq_im1 = fftshift(fourier_im1)
freq_im2 = fftshift(fourier_im2)

# Filtros
# Filtro paso alto para imagen de lejos
fc_1 = 40
freq_im1_ = np.copy(freq_im1)
ind_im1 = np.where(abs(freq_im1_) < fc_1)
freq_im1_[ind_im1] = 0

# Filtro paso bajo para imagen de cerca
fc_2 = 30
freq_im2_ = np.copy(freq_im2)
ind_im2 = np.where(abs(freq_im2_) > fc_2)
freq_im2_[ind_im2] = 0

plt.figure(figsize=(10,10))
plt.subplot(2,2,1)
plt.imshow(abs(freq_im1), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de frecuencias de im1")
plt.subplot(2,2,2)
plt.imshow(abs(freq_im2), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de frecuencias de im2")
plt.subplot(2,2,3)
plt.imshow(abs(freq_im1_), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de filtrado im1")
plt.subplot(2,2,4)
plt.imshow(abs(freq_im2_), norm=LogNorm())
plt.colorbar()
plt.title("Espectro de filtrado im2")
plt.savefig("ImProceso.pdf")

# Saco espectros de Fourier correspondientes a las frecuencias filtradas
trans_im1 = ifftshift(freq_im1_) 
trans_im2 = ifftshift(freq_im2_)

# Suma de espectros correspondientes a frecuencias filtradas
trans = trans_im1*0.3 + trans_im2

# Grafica de ambas juntas (imagen hibrida)
im_hibrida = ifft2(trans)

plt.figure()
plt.imshow(abs(im_hibrida), plt.cm.gray)
plt.title('Imagen hibrida')
plt.savefig("ImHybrid")

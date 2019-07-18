all : Plots_hw2.py FFT2D_im1.png FFT2D_im2.png filtro_im1.png filtro_im2.png freq_im1.png freq_im2.png im_hibrida.png
	python Plots_hw2.py
	python Fourier.py

Plots_hw2.py : euler_dt1.dat leap_frog_dt1.dat runge_kutta_dt1.dat euler_dt2.dat leap_frog_dt2.dat runge_kutta_dt2.dat euler_dt3.dat leap_frog_dt3.dat runge_kutta_dt3.dat
	python Plots_hw2.py

euler_dt1.dat leap_frog_dt1.dat runge_kutta_dt1.dat euler_dt2.dat leap_frog_dt2.dat runge_kutta_dt2.dat euler_dt3.dat leap_frog_dt3.dat runge_kutta_dt3.dat : ODEs.cpp
	g++ ODEs.cpp
	./a.out ODEs.cpp
    
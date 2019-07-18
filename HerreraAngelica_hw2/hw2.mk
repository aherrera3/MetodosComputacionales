Resultados_hw2.pdf : Resultados_hw2.tex FFT2D_im1.png FFT2D_im2.png filtro_im1.png filtro_im2.png freq_im1.png freq_im2.png im_hibrida.png y_vs_x.png vy_vs_vx.png L_vs_t.png E_vs_t.png
	pdflatex Resultados_hw2.tex
    
Resultados_hw2.tex : Fourier.py ODEs.cpp Plots_hw2.py 
	python Fourier.py
	g++ ODEs.cpp
	./a.out ODEs.cpp 
	python Plots_hw2.py    
    
FFT2D_im1.png FFT2D_im2.png filtro_im1.png filtro_im2.png freq_im1.png freq_im2.png im_hibrida.png : Fourier.py
	python Fourier.py
    
y_vs_x.png vy_vs_vx.png L_vs_t.png E_vs_t.png : euler_dt1.dat leap_frog_dt1.dat runge_kutta_dt1.dat euler_dt2.dat leap_frog_dt2.dat runge_kutta_dt2.dat euler_dt3.dat leap_frog_dt3.dat runge_kutta_dt3.dat   
	python Plots_hw2.py

euler_dt1.dat leap_frog_dt1.dat runge_kutta_dt1.dat euler_dt2.dat leap_frog_dt2.dat runge_kutta_dt2.dat euler_dt3.dat leap_frog_dt3.dat runge_kutta_dt3.dat : ODEs.cpp
	g++ ODEs.cpp
	./a.out ODEs.cpp
    
Resultados_hw2.pdf : Resultados_hw2.tex originales.pdf FFtIm.pdf ImProceso.pdf ImHybrid.pdf XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf Ener_met_dt.pdf
	pdflatex Resultados_hw2.tex
    
Resultados_hw2.tex : Fourier.py ODEs.cpp Plots_hw2.py 
	python Fourier.py
	g++ ODEs.cpp
	./a.out ODEs.cpp 
	python Plots_hw2.py    
    
originales.pdf FFtIm.pdf ImProceso.pdf ImHybrid.pdf : Fourier.py
	python Fourier.py
    
XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf Ener_met_dt.pdf : euler_dt1.dat leap_frog_dt1.dat runge_kutta_dt1.dat euler_dt2.dat leap_frog_dt2.dat runge_kutta_dt2.dat euler_dt3.dat leap_frog_dt3.dat runge_kutta_dt3.dat   
	python Plots_hw2.py

euler_dt1.dat leap_frog_dt1.dat runge_kutta_dt1.dat euler_dt2.dat leap_frog_dt2.dat runge_kutta_dt2.dat euler_dt3.dat leap_frog_dt3.dat runge_kutta_dt3.dat : ODEs.cpp
	g++ ODEs.cpp
	./a.out ODEs.cpp
    
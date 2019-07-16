all : Plots_hw2.py
	python Plots_hw2.py

Plots_hw2.py : euler.dat leap_frog.dat runge_kutta.dat
	python Plots_hw2.py

euler.dat : ODEs.cpp
	g++ ODEs.cpp
	./a.out ODEs.cpp
    
leap_frog.dat : ODEs.cpp 
	g++ ODEs.cpp
	./a.out ODEs.cpp
    
runge_kutta.dat : ODEs.cpp
	g++ ODEs.cpp
	./a.out ODEs.cpp
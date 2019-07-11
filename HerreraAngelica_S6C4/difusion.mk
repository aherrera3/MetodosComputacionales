all : plots_Difusion.py
	python plots_Difusion.py

plots_Difusion.py : datos.dat
	python plots_Difusion.py

datos.dat : difusion.cpp
	g++ difusion.cpp
	./a.out difusion.cpp
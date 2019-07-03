all : plotsS5C1.py
	python plotsS5C1.py

plotsS5C1.py : datos.dat
	python plotsS5C1.py

datos.dat : S5C1Deriv.cpp
	g++ S5C1Deriv.cpp
	./a.out S5C1Deriv.cpp

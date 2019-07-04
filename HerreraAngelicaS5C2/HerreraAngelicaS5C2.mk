all : HerreraAngelicaS5C2.py
	python HerreraAngelicaS5C2.py

HerreraAngelicaS5C2.py : datos.dat
	python HerreraAngelicaS5C2.py

datos.dat : HerreraAngelicaS5C2.cpp
	g++ HerreraAngelicaS5C2.cpp
	./a.out HerreraAngelicaS5C2.cpp > datos.dat
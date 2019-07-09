all : HerreraAngelicaS6C1.py
	python HerreraAngelicaS6C1.py

HerreraAngelicaS6C1.py : datos.dat
	python HerreraAngelicaS6C1.py

datos.dat : HerreraAngelicaS6C1.cpp
	g++ HerreraAngelicaS6C1.cpp
	./a.out HerreraAngelicaS6C1.cpp
all : plots_cuerda.py
	python plots_cuerda.py

plots_cuerda.py : datos.dat
	python plots_cuerda.py

datos.dat : HerreraAngelica_cuerda.cpp
	g++ HerreraAngelica_cuerda.cpp
	./a.out HerreraAngelica_cuerda.cpp
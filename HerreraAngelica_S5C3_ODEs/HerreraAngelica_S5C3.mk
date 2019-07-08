all : HerreraAngelica_S5C3_plots.py
	python HerreraAngelica_S5C3_plots.py

HerreraAngelica_S5C3_plots.py : datos.dat
	python HerreraAngelica_S5C3_plots.py

datos.dat : HerreraAngelica_S5C3_ODEs.cpp
	g++ HerreraAngelica_S5C3_ODEs.cpp
	./a.out HerreraAngelica_S5C3_ODEs.cpp
all : plots_cuerdayTambor.py
	python plots_cuerdayTambor.py

plots_cuerdayTambor.py : datos.dat
	python plots_cuerdayTambor.py

datos.dat : HerreraAngelica_cuerdayTambor.cpp
	g++ HerreraAngelica_cuerdayTambor.cpp
	./a.out HerreraAngelica_cuerdayTambor.cpp
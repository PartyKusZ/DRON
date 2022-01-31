FLAGI = -g -Iinc -Wall -pedantic   -std=c++17
 
__start__: Dron
	./Dron

Dron: obj/main.o obj/uklad_wspolrzednych.o obj/dron.o  obj/figury_geometryczne.o obj/macierz_obr.o obj/wektor.o obj/scena.o obj/Dr3D_gnuplot_api.o
	g++ ${FLAGI} obj/main.o obj/uklad_wspolrzednych.o obj/scena.o obj/figury_geometryczne.o obj/macierz_obr.o obj/wektor.o obj/Dr3D_gnuplot_api.o obj/dron.o -lpthread  -o Dron 

obj:
	mkdir obj





obj/figury_geometryczne.o: src/figury_geometryczne.cpp inc/figury_geometryczne.hh

	g++ -c ${FLAGI}  src/figury_geometryczne.cpp -o obj/figury_geometryczne.o

obj/uklad_wspolrzednych.o: src/uklad_wspolrzednych.cpp inc/uklad_wspolrzednych.hh

	g++ -c ${FLAGI}  src/uklad_wspolrzednych.cpp -o obj/uklad_wspolrzednych.o

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh

	g++ -c ${FLAGI} src/Dr3D_gnuplot_api.cpp -o obj/Dr3D_gnuplot_api.o	


obj/wektor.o: src/wektor.cpp inc/wektor.hh

	g++ -c ${FLAGI}  src/wektor.cpp -o obj/wektor.o


obj/macierz_obr.o: src/macierz_obr.cpp inc/macierz_obr.hh

	g++ -c ${FLAGI} src/macierz_obr.cpp -o obj/macierz_obr.o


obj/scena.o: src/scena.cpp inc/scena.hh

	g++ -c ${FLAGI} src/scena.cpp -o obj/scena.o

obj/main.o: src/main.cpp

	g++ -c ${FLAGI} src/main.cpp -o obj/main.o 

obj/dron.o :src/dron.cpp inc/dron.hh

	g++ -c ${FLAGI} src/dron.cpp -o obj/dron.o 




clean:
	rm -f obj/*.o Dron
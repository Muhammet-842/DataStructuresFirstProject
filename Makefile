derlecalistir:program calistir
program:main.o dosyaoku.o satirdugum.o satirliste.o yoneticidugum.o yoneticiliste.o
	g++ ./lib/satirdugum.o ./lib/satirliste.o  ./lib/dosyaoku.o ./lib/yoneticidugum.o ./lib/yoneticiliste.o ./lib/main.o -o ./bin/program


main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

dosyaoku.o:
	g++ -I "./include" -c ./src/Dosyaoku.cpp -o ./lib/dosyaoku.o


satirdugum.o:
	g++ -I "./include" -c ./src/SatirDugum.cpp -o ./lib/satirdugum.o
satirliste.o:
	g++ -I "./include" -c ./src/SatirListe.cpp -o ./lib/satirliste.o
yoneticidugum.o:
	g++ -I "./include" -c ./src/YoneticiDugum.cpp -o ./lib/yoneticidugum.o
yoneticiliste.o:
	g++ -I "./include" -c ./src/YoneticiListe.cpp -o ./lib/yoneticiliste.o

calistir:
	./bin/program.exe


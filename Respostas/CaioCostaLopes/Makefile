all: geraos geraexe

geraos: main.c tMapa.c tPacman.c tPosicao.c tMovimento.c tTunel.c
	gcc -c main.c tMapa.c tPacman.c tPosicao.c tMovimento.c tTunel.c

geraexe: main.o tMapa.o tPacman.o tPosicao.o tMovimento.o tTunel.o
	gcc main.o tMapa.o tPacman.o tPosicao.o tMovimento.o tTunel.o -o prog

clean:
	rm -rf *.o prog
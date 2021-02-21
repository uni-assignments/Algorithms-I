CC=g++ 
CFLAGS=-std=gnu++17 -Wall -Wextra
EXEC=./tp02
TMPOUT=tp02.testresult

$(EXEC): main.cpp grafo.o dsu.o
	$(CC) $(CFLAGS) main.cpp grafo.o dsu.o -o $(EXEC)

grafo.o: ./src/grafo.cpp 
	$(CC) $(CFLAGS) -c ./src/grafo.cpp -o grafo.o

dsu.o: ./src/dsu.cpp
	$(CC) $(CFLAGS) -c ./src/dsu.cpp -o dsu.o

test: $(EXEC)
	@bash ./run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf grafo.o
	rm -rf dsu.o
	rm -rf tp02.testresult
	rm -rf tp02

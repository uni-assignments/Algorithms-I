CC=g++ 
CFLAGS=-Wall -Wextra
EXEC=./tp01
TMPOUT=tp01.testresult

$(EXEC): main.cpp grafo.o
	$(CC) $(CFLAGS) main.cpp grafo.o -o $(EXEC)

grafo.o: ./src/grafo.cpp 
	$(CC) $(CFLAGS) -c ./src/grafo.cpp -o grafo.o

test: $(EXEC)
	@bash ./run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf grafo.o
	rm -rf tp01.testresult
	rm -rf tp01

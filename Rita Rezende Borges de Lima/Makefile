CC=g++ 
CFLAGS=-Wall -Wextra
EXEC=./tp01
TMPOUT=tp01.testresult

$(EXEC): main.cpp binary_tree.o node.o
	$(CC) $(CFLAGS) main.cpp binary_tree.o node.o -o $(EXEC)

binary_tree.o: binary_tree.cpp 
	$(CC) $(CFLAGS) -c binary_tree.cpp -o binary_tree.o

node.o: node.cpp 
	$(CC) $(CFLAGS) -c node.cpp -o node.o

test: $(EXEC)
	@bash ./run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf binary_tree.o
	rm -rf node.o
	rm -rf tp01.testresult
	rm -rf tp01

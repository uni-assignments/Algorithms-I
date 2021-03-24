CC=g++ -std=c++17
CFLAGS=-Wall -Wextra
EXEC=./tp03
TMPOUT=tp03.testresult

$(EXEC): main.cpp 
	$(CC) $(CFLAGS) main.cpp -o $(EXEC)

test: $(EXEC)
	@bash ./run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf tp02.testresult
	rm -rf tp02

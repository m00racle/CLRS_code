# makefile for testing run the code
OBJ = temp/test.o temp/testfrm.o
test: $(OBJ)
	${CC} $(OBJ) -o run

temp/test.o: tests/test.c 
	${CC} -c tests/test.c -o temp/test.o 

temp/testfrm.o : utils/testfrm.c
	${CC} -c utils/testfrm.c -o temp/testfrm.o

clean:
	-rm temp/*.o run*
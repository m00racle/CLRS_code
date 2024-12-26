# makefile for testing run the code
OBJ = temp/test.o temp/testfrm.o temp/arrutil.o 
test: $(OBJ)
	${CC} $(OBJ) -o run

temp/test.o: tests/test.c 
	${CC} -c tests/test.c -o temp/test.o 

temp/testfrm.o : utils/testfrm.c
	${CC} -c utils/testfrm.c -o temp/testfrm.o

temp/arrutil.o: utils/arrutil.c 
	${CC} -c utils/arrutil.c -o temp/arrutil.o 

clean:
	-rm temp/*.o run*
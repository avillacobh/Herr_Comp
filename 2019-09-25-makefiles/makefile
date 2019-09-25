OBJ = sum1.o sum2.o sum3.o

all: $(OBJ)  main-sumas.x 

%.o : %.cpp
	g++ -c $< -o $@

%.x : %.cpp
	g++  $^ -o $@


main-sumas.x: main-sumas.cpp $(OBJ)


.PHONY: clean
clean:
	rm -f *.o *.x *~ *#

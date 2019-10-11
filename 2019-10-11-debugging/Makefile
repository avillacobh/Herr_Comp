all: debug-1.x

%.x: %.cpp
	g++ -g -Wall -fsanitize=address -fsanitize=leak -fsanitize=undefined $^ -o $@




.PHONY: clear

clear:
	rm -f *.x a.out *~ *#

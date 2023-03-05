output: full.o
	clang obj/full.o -o bin/full

full.o: full.c tools.h
	clang -c full.c -o obj/full.o

clean:
	rm -rf bin/* obj/*

install-home:
	mv bin/full ~/bin/ccalgo-full

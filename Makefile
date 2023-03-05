output: full.o
	clang obj/full.o -o bin/full

full.o: full.c tools.h
	clang -c full.c -o obj/full.o

clean:
	rm -rf bin/* obj/*

install-home:
	mv bin/full ~/bin/ccalgo-full

hardcoded:
	clang -c full_hardcoded.c -o obj/full_hardcoded.o
	clang obj/full_hardcoded.o -o bin/full_hardcoded

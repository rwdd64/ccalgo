output: main.o flags.o crypt.o tools.o
	clang obj/tools.o obj/main.o obj/flags.o obj/crypt.o -o bin/ccalgo

main.o: src/main.c
	clang -c src/main.c -o obj/main.o

flags.o: src/flags.c
	clang -c src/flags.c -o obj/flags.o

crypt.o: src/crypt.c
	clang -c src/crypt.c -o obj/crypt.o

tools.o: src/tools.c
	clang -c src/tools.c -o obj/tools.o

clean:
	rm -rf bin/* obj/*

install-home:
	mv bin/ccalgo ~/bin/ccalgo

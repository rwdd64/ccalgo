output: encrypt.o decrypt.o
	clang obj/encrypt.o -o bin/encrypt
	clang obj/decrypt.o -o bin/decrypt

encrypt.o: encrypt.c tools.h
	clang -c encrypt.c -o obj/encrypt.o

decrypt.o: decrypt.c tools.h
	clang -c decrypt.c -o obj/decrypt.o

clean:
	rm -rf bin/* obj/*

install-home:
	mv bin/encrypt ~/bin/ccalgo-encrypt
	mv bin/decrypt ~/bin/ccalgo-decrypt

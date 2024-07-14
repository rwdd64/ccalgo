COMPILER=gcc
PLATFORM=linux
OBJS=main.o flags.o crypt.o tools.o
TARGET=ccalgo

output: $(OBJS) folders
	$(COMPILER) obj/tools.o obj/main.o obj/flags.o obj/crypt.o -o bin/$(TARGET)

main.o: src/main.c folders
	$(COMPILER) -c src/main.c -o obj/main.o

flags.o: src/flags.c folders
	$(COMPILER) -c src/flags.c -o obj/flags.o

crypt.o: src/crypt.c folders
	$(COMPILER) -c src/crypt.c -o obj/crypt.o

tools.o: src/tools.c folders
	$(COMPILER) -c src/tools.c -o obj/tools.o

folders:
ifeq ($(PLATFORM), windows)
	MKDIR obj
	MKDIR bin
else
	mkdir obj
	mkdir bin
endif

clean:
ifeq ($(PLATFORM), windows)
	RMDIR /Q /S bin & RMDIR /Q /S obj
else
	rm -rf bin obj
endif

install:
ifeq ($(PLATFORM), windows)
	MOVE bin/ccalgo.exe %systemdrive%%homepath%/bin/
else
	mv bin/ccalgo ~/bin/ccalgo
endif


all: cpu mem threads io

clean:
	rm -f cpu mem threads io

cpu: cpu.c common.h
	gcc -o cpu.o cpu.c -Wall

mem: mem.c common.h
	gcc -o mem.o mem.c -Wall

threads: threads.c common.h common_threads.h
	gcc -o threads.o threads.c -Wall -pthread

io: io.c common.h
	gcc -o io.o io.c -Wall


#all: cpu mem threads io
all: cpu

clean:
	rm -f cpu mem threads io

#cpu: cpu.c common.h
cpu: cpu.c
	gcc -o cpu cpu.c -Wall

#mem: mem.c common.h
#	gcc -o mem mem.c -Wall
#
#threads: threads.c common.h common_threads.h
#	gcc -o threads threads.c -Wall -pthread
#
#io: io.c common.h
#	gcc -o io io.c -Wall


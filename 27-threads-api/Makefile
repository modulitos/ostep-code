CC     := gcc
CFLAGS := -Wall -Werror -I../include

SRCS   := thread_create.c \
	thread_create_simple_args.c \
	thread_create_with_return_args.c

OBJS   := ${SRCS:c=o}
PROGRAMS  := ${SRCS:.c=}

.PHONY: all
all: ${PROGRAMS}

${PROGRAMS} : % : %.o Makefile
	${CC} $< -o $@ -pthread

clean:
	rm -f ${PROGRAMS} ${OBJS}

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $<
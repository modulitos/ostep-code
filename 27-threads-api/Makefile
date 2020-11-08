CC     := gcc
CFLAGS := -Wall -Werror -I../include

SRCS   := thread_create.c \
	thread_create_simple_args.c \
	thread_create_with_return_args.c

OBJS   := ${SRCS:c=o}
PROGRAMS  := ${SRCS:.c=}

.PHONY: all
all: ${PROGRAMS}

${PROGRAMS} : % : %.c Makefile
	${CC} $< -o $@.o -pthread

clean:
	rm -f ${PROGRAMS} ${OBJS}

# We don't need this?
#%.o: %.c Makefile
#	${CC} ${CFLAGS} -c $<
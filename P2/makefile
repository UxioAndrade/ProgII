CC= gcc -Wall
LIBS = -lm
HEADER_FILES_DIR = ./
INCLUDES = -I

MAIN = ejecutable

SRCS = main.c

DEPS = $()/listas.h cola.h

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC( -c $< $(INCLUDES)

cleanall: clean
	rm -f $(MAIN)

clean:
	rm -f *.o *~


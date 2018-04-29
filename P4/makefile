CC= gcc -Wall
HEADER_FILES_DIR =./
INCLUDES = -I $(HEADER_FILES_DIR)

MAIN = ejecutable

SRCS = main.c vectordinamico.c enterosLargos.c

DEPS = vectordinamico.h enterosLargos.h

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(INCLUDES)

cleanall: clean
	rm -f $(MAIN)

clean:
	rm -f *.o 

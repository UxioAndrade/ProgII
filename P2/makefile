CC= gcc -Wall
LIBS = -lm
HEADER_FILES_DIR =./TAD
INCLUDES = -I $(HEADER_FILES_DIR)

MAIN = ejecutable

SRCS = main.c ./TAD/cola.c ./TAD/listas.c

DEPS = $(HEADER_FILES_DIR)/listas.h $(HEADER_FILES_DIR)/cola.h

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(INCLUDES)

cleanall: clean
	rm -f $(MAIN)

clean:
	rm -f *.o ./TAD/*.o ./TAD/*~

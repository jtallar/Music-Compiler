.PHONY=clean all
include Makefile.inc

all: yacc lex compiler

yacc:
	yacc -d parser.y

lex:
	lex scanner.l

compiler: 
	$(CC) $(CFLAGS) lex.yy.c y.tab.c typeUtil.c outPrinter.c -o $@.out $(LIB)

sound:
	$(CC) $(CFLAGS) endianness.c wave.c sound.c prueba.c -o $@.out $(LIB)
# run: lex.yy.c y.tab.c
# 	$(CC) $(SOURCES) $(CFLAGS) -o a.out $(LIB)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I$(LIBRARY) -c $< -o $@

# endianness.o: endianness.c 
# 				$(CC) -c endianness.c 

# wave.o: wave.c 
# 				$(CC) -c wave.c  

# sound.o: sound.c
# 				$(CC) -c sound.c

# prueba.o: prueba.c
# 				$(CC) -c prueba.c				

clean:
	rm -rf *.out *.wav $(OBJECTS)
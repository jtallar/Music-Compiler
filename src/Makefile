.PHONY=clean all
include Makefile.inc

all: compiler

y.tab.c + y.tab.h: parser.y
	$(YACC) $(YACCFLAGS) $<

lex.yy.c: scanner.l y.tab.h
	$(LEX) $<

compiler: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@.out $(LIB)

# sound:
# 	$(CC) $(CFLAGS) sound/endianness.c sound/wave.c sound/sound.c sound/prueba.c -o $@.out $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.out *.wav y.tab.c y.tab.h lex.yy.c $(OBJECTS)
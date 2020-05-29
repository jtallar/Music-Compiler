COMPILER=gcc
FLAGS=-Wall -pedantic -std=c99 -lm

all: endianness.o wave.o sound.o prueba.o
		 $(COMPILER) endianness.o wave.o sound.o prueba.o $(FLAGS)

endianness.o: endianness.c 
				$(COMPILER) -c endianness.c 

wave.o: wave.c 
				$(COMPILER) -c wave.c  

sound.o: sound.c
				$(COMPILER) -c sound.c

prueba.o: prueba.c
				$(COMPILER) -c prueba.c				

clean:
			rm -rf a.out *.wav *.o *.h.gch
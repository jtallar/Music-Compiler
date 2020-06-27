# Wavicii #

#### Trabajo Practico Especial de Autómatas, Teoria de Lenguajes y Compiladores.


*Wavicii es un lenguaje simple, imperativo, y con una gran potencia de crear música.    
Uno de sus objetivos es el de la creación de música en la que redes neuronales y AIs utilicen dicho lenguaje.   
Facilita la creación de música a través de la simpleza de la programación donde el único conocimiento musical requerido son los acordes.*

--- 

## Instalación
Los siguientes comandos se corren en la terminal:
``` bash
$  make					# Generar el parser
$  make clean			# Limpiar archivos auxiliares
```

## Uso
Siendo `program` el programa en lenguaje Wavicii, correr:
```bash
$  ./compiler.out < program > out.c 	# Pasar a c
$  gcc out.c -lm -o a.out 				# Compilar el archivo en c
$  ./a.out								# Correr el ejecutable
```
*El/los archivos .wav se generarán en la misma carpeta en donde se encuentre el archivo `a.out`.*

---

## Autores: 
+ Brula, Matias Alejandro
+ De La Torre, Nicolás
+ Tallar, Julián
+ Vuoso, Julián Matías


####  ITBA 2020 C1 
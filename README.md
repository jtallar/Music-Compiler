# Wavicii #

#### Trabajo Practico Especial de Autómatas, Teoria de Lenguajes y Compiladores.


*Wavicii es un lenguaje simple, imperativo, y con una gran potencia de crear música.    
Uno de sus objetivos es el de la creación de música en la que redes neuronales y AIs utilicen dicho lenguaje.   
Facilita la creación de música a través de la simpleza de la programación donde el único conocimiento musical requerido son los acordes.*

--- 

## Instalación
Los siguientes comandos se corren en la terminal:
``` bash
$  make -C src					# Generar el parser
$  make clean -C src			# Limpiar archivos auxiliares
```

## Uso
Siendo `program` el programa en lenguaje Wavicii, correr:
```bash
$  ./wcc program [nombre]		# Compilar el archivo. De no especificar el nombre del ejecutable de salida será por default a.out
$  ./nombre	[0-100]				# Correr el ejecutable. El numero opcional es el volumen máximo de salida de los audios. Por default es 50
```
*El/los archivos .wav se generarán en la misma carpeta en donde se encuentre el archivo `nombre` (o `a.out` de no especificarlo).*  
En el caso de haber problema de permisos al ejecutar el compilador `./wcc`, correr en la terminal `chmod +x wcc`.


---

## Autores: 
+ Brula, Matias Alejandro
+ De La Torre, Nicolás
+ Tallar, Julián
+ Vuoso, Julián Matías


####  ITBA 2020 C1 
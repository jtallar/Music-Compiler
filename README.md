# Wavicii #

#### Trabajo Practico Especial de Autómatas, Teoria de Lenguajes y Compiladores.


*Wavicii es un lenguaje simple, imperativo, y con una gran potencia de crear música.    
Uno de sus objetivos es el de la creación de música en la que redes neuronales y AIs utilicen dicho lenguaje.   
Facilita la creación de música a través de la simpleza de la programación donde el único conocimiento musical requerido son los acordes.*

--- 

## Instalación
Los siguientes comandos se corren en la terminal:
``` bash
$  make clean -C src			# Limpiar archivos auxiliares
$  make -C src					# Generar el ejecutable del compilador
```

## Uso
Siendo `program` el programa en lenguaje Wavicii, correr:
```bash
$  ./wcc program [nombre]		# Compilar el archivo. De no especificar el nombre del ejecutable de salida será por default a.out
$  ./nombre	[0-100]				# Correr el ejecutable. El numero opcional es el volumen máximo de salida de los audios. Por default es 50
```
*El/los archivos .wav se generarán en la misma carpeta en donde se encuentre el archivo `nombre` (o `a.out` de no especificarlo).*  
En el caso de haber problema de permisos al ejecutar el compilador `./wcc`, correr en la terminal `chmod +x wcc`.

## Pruebas
En la carpeta `lyrics` se encuentran ejemplos para ejecutar, la manera de hacerlo es (luego de haber instalado con `make`):
```bash
$ ./wcc ./lyrics/full_test.txt 	# Este ejemplo muestra el uso de getters y prints. El resto genera melodias al ejecutarlos
```

## Documentación
Se encuentran disponibles en este directorio el archivo `Informe.pdf`, con la explicación de todo lo desarrollado, y el archivo `grammar_bnf.txt`, con la gramática escrita en Backus Nair Form (BNF).

---

## Autores: 
+ Brula, Matias Alejandro
+ De La Torre, Nicolás
+ Tallar, Julián
+ Vuoso, Julián Matías


####  ITBA 2020 C1 
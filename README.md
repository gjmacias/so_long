# so_long - gmacias-
Este proyecto es un pequeño juego en 2D. Está diseñado para trabajar con texturas y sprites junto algunos otros elementos básicos de jugabilidad.
### Indice
* [Que es so_long?](#que-es-so_long)
* [Que utilizamos?](#que-utilizamos)
* [Como funciona?](#como-funciona)
* [Como utilizamos la libreria?](#como-utilizamos-la-libreria)

### Que es so_long?
Este proyecto consiste en la creacion de un juego 2D, donde debes recoger todos los consumibles y escapar en la menor cantidad de movimientos posibles de un mapa creado por ti mismo!

En este ejemplo tenemos los siguientes componentes del juego:

`1111111
1P0C0E1
1111111`

◦ '1': Paredes, para poder jugar todo el mapa debe estar rodeado de ellos.

◦ 'P': Será el jugador y solo podra haber uno en todo el mapa.

◦ 'E': Será la salida y solo podra haber uno en todo el mapa.

◦ 'C': Los consumibles, podran haber tantos como gustes (minimo 1) y deberan ser alcanzables en todo momento.

***Cabe recalcar que el mapa debe ser realizable en todo momento, en caso de que sea imposible, retornara error***

### Que utilizamos?
En nuestro ft_printf tenemos solo las siguentes funciones de librerias externas autorizadas:

| Función  | Descripción														 			|
|-------|-----------------------------------------------------------------------------------|
| malloc | Solicitar un bloque de memoria del tamaño suministrado como parámetro.     													|
| free | Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 											|
| write | Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.								|
| va_start | Permite el acceso a los argumentos de la función variada.														|
| va_arg | Accede al siguiente argumento de la función variada.               											|
| va_copy | Hace una copia de los argumentos de la función variádica.               									|
| va_end | Finaliza el recorrido de los argumentos de la función variada.        |


### Como funciona?

La meta es crear una libreria que contenga todo nuestro codigo para poder utilizarlo en futuros proyectos llamado: *libftprintf.a*

Para crear esta libreria seguimos los siguientes pasos:

	git clone https://github.com/gjmacias/ft_printf
	cd ft_printf
	make

Al revisar el directorio, en alguna parte encontraras la libreria: *libftprintf.a*

### Como utilizamos la libreria?

Para utilizarlo primero debes de  tener la libreria: *libftprintf.a*.
Luego debes añadirlo en el compilador, primero la ruta de libftprintf.a y luego el nombre de la libreria

`gcc archivos.c -L<ruta de libftprintf.a> -lftprintf`

-L tomara la ubicacion de la libreria<br>
-l tomara el nombre de la libreria. en este caso seran los caracteres que vegan despues de `lib` de tu libreria.

y eso seria todo!

# Quizás pueda interesarte!

### - Para ver mi progresion en 42 🌠
[AQUÍ](https://github.com/gjmacias/42BCN)

### - Mi perfil de 42 👾
[AQUÍ](https://profile.intra.42.fr/users/gmacias-)

### - Mis proyectos personales 🧐
[AQUÍ🗒️](https://github.com/gjmacias/autoproyectos)

# Contacto 📥

◦ Email: gmacias-@student.42barcelona.com

[1]: https://www.42barcelona.com/ "42 BCN"

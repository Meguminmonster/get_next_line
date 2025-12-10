# get_next_line
_Este proyecto ha sido creado como parte del currículo de 42 por jpedra-v_

__Descripción__

Este proyecto implementa la función get_next_line, cuyo objetivo es leer una línea completa de un
archivo o entrada estándar por llamada, de manera eficiente y controlando la memoria dinámica
utilizada.

La función soporta leer archivos de cualquier tamaño sin cargar todo el contenido en memoria y 
permite múltiples llamadas consecutivas para obtener líneas sucesivas hasta el final del archivo.

__Instrucciones__

Antes de compilar:
- Entra a get_next_line.c y descomenta el main.
- Crea un archivo .txt 
- Edita del main { int fd = open("a.txt", O_RDONLY); } para introducir el nombre de tu .txt

Compilación:
- cc get_next_line.c get_next_line_utils.c -o get_next_line

Ejecución:
- ./get_next_line

__Recursos__

- Proyectos de antiguos alumnos encontrados en GitHub fueron usados como punto de comparacion.

__Adicionales__

El proyecto ha sido distribuido de la manera en la que ha sido para evitar errores de norminette,
especialmente por un gran numero de funciones en un mismo archivo.

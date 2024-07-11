i. Qué pruebas hicieron:

A nivel general se hicieron pruebas unitarias en todo el código de todas las clases para así reconocer que el código funciona correctamente, por lo que se pudo hacer un buen porcentaje de line coverage en las clases. Tal vez se pudieron hacer más pruebas unitarias que aumentaran el branch coverage pero no se sabía con exactitud que se ramas eran las que no se tenían en cuenta con las pruebas previamente realizadas.

ii. Cómo lograron subir el coverage:

Para subir el coverage, lo que hicimos fue basicamente revisar los archivos .html de los códigos fuente para así determinar por cuales líneas no estaban pasando las pruebas y así poder hacer más pruebas que pudieran pasar por esas líneas de código donde antes no pasaban.

iii. Qué errores encontraron en el programa y con qué prueba lograron 
detectarlo. 

Clase Token: En esta clase, el error que se encontró fue acerca de la precedencia de los operadores, donde la multiplicación tenia una precedencia de 0, igual que el caso por default, lo cual no deberia ser correcto, ya que este operadoir debería tener una precedencia mayor que a la suma y la resta que tenían una precedencia de 1. La prueba con la que detectamos el error, fue en una prueba donde se veía la precedencia de la multiplicación, la cual se notaba que la precedencia de dicho operador estaba mal, ya que el de la suma y resta debía ser menor y más bien era mayor.

Clase Tokenizer: En esta clase, el error encontrado fue sobre el manejo de los decimales, los cuales al poner un decimal por ejemplo "0.0", este se transformaba a "4.8", lo cual no era correcto, haciendo una prueba unitaria que comparaba este decimal y esperaba este mismo numero como resultado, saltó un error donde el valor que se dió fue el 4.8 y no el 0.0. De esta manera, se encontró que el error se derivaba de un error en la línea 53, donde en vez de un char '0', había un 0 como si fuera un entero común.

Clase ShuntingYard:

Clase Postfijo: En esta clase el error estaba a la hora de evaluar la expresión de resta ya que no se estaban restando, se estaban sumando. se le hizo una prueba unitaria y se arregló

Clase Calculadora:En esta clase el error estaba en la palabra exit ya que cuando uno ponía salir, no salía. se le hizo una prueba unitaria y se detectó

iv. Los puntos extra que hayan completado

1.Hay un error en la parte de la calculadora cuando se divide entre 0 ya que no tira error, tira que el resultado es 0, si en la parte de postfijo se cambia el valor a 1 da infinito que sería el error esperado. No se le pudieron hacer pruebas pero está el error.

# Prime_Generator

Miller-Rabin:

En este algoritmo, buscamos probar si un numero es compuesto o pseudoprimo, esto lo haremos primeramente generando un numero random a que es menor o igual a n-1, usamos a y n
para saber si el witness es falso, de donde primero calculamos u, la cual será la mitad de n y seguiremos dividiendo entre 2 hasta que no sea par.
Ahí usaremos la formula para hallar z, z = a^u % n, el cual si es 1 el witness será falso, si no es así continuamos para hallar z e y, donde y pasa a tener el valor de z
y z sera y al cuadrado modulo n, esto se repetira mientras j sea menor que t y z no sea igual a 1.
Si se acaba el bucle y no es falso, entonces el numero es compuesto.

Esto se ve reflejado dentro de Miller Rabin, ya que si el witness del numero que estamos evaluando es verdadero el numero es compuesto y sino es pseudprimo.

GeneratePrime:

Basicamente aqui generamos un numero de cantidad de bits a elegir, donde hallamos m que será su máscara, y comprobamos si el numero es primo mediante Miller Rabin,
si este es verdadero el numero es primo, sino sera compuesto.

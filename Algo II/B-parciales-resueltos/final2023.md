### 1) (Voraz)
- Te vas n dias de vacaciones al medio de la montaña, lejos de toda civilizacion. Llevas con vos lo iomprescindible: una carpa, ropa, una linterna, un buen libro y comida preparada para m raciones diarias, con m > n. Cada racion i tiene una fecha de vencimiento v_i, contada en dias desde el momento en que llegás a la montaña. Por ejemplo una viana con fecha de vencimiento 4 significa que se puede comer hasta el dia numero 4 inclusive.
- Tenes que encontrar la mejor manera de organizar las viandas diaras de manera que la cantidad que se vencen sin ser consumidas sea MÍNIMA. Deberás indicar para cada día j, i<=j<=n, qué vianda es la que comerás, asegurando que nunca comas algo vencido.

##### a) Criterio de selección:
- Se debe seleccionar la comida con la fecha de vencimiento mas proxima, siempre y cuando todavía no haya vencido.

##### b) Estructuras de datos:
- Se recibe un conjunto c: Set of Comida, donde comida es una tupla, y se devolverá una Lista de tuplas también, viandas: List of Comida. Ambas tuplas están definidas como:
~~~ 
type Comida =  tuple
                    v: Nat //fecha de vencimiento
                    cons: Nat //Día en el que tiene que ser consumida dicha racion
                    i: Nat //identificador de dicha ración
                end tuple
~~~

##### c) Funcionamiento:
- El algoritmo llevará una cuenta del día actual, arrancando en 1. Mientras el día actual no sea n, lo que hace es seleccionar la comida con menor fecha de vencimiento entre todas las del conjunto de raciones restantes y verifica que su fecha de vencimiento sea >= al dia actual: si lo es, entonces actualiza su campo de dia en el que debe ser consumida con el dia actual, la agrega por derecha a la lista, suma el dia actual en 1 y finalmente la elimina del conjunto de comidas restantes. Si su fecha de vencimiento es < al dia actual, entonces lo que hace es eliminarla del conjunto y NO suma el dia actual pues tiene que encontrar la proxima comida con menor fecha para la jornada.

### 2) (Backtracking)

- Se tiene un tablero de 9x9 con nros enteros en las casillas. Un jugador se coloca en una casilla a eleccion de la 1ra fila y se mueve avanzando en las filas y moviendose a una columna adyacente o quedándose en la misma columna. En cada movimiento, el jugador suma los puntos correspondientes al nro de la casilla, pero nunca puede pisar una casilla de manera que el puntaje acumulado (con esa casilla) de un valor negativo. El juego termina cuando se llega a la novena fila y el puntaje total es la suma de los valores de cada casilla por la que el jugador pasó.

##### a) 
- La función maxPuntaje(i, c, p) calcula el mayor puntaje obtenible arrancando desde el casillero [i, c] hasta algun casillero de la ultima fila, [n, k], donde k está entre 1 y n, siempre y cuando que el puntaje acumulado p nunca se haga negativo.
##### b)
- Llamada principal:
> max(maxPuntaje(1, 1), maxPuntaje(1, 2), ..., maxPuntaje(1, 9))

##### c) Definición:
$$
\text{maxPuntaje}(i, c, p) = 
\begin{cases}
  p_{ic}       & \text{si }   i=9 \land p+p_{ic} >= 0\\
  -\infty & \text{si }    p + p_{ic}<0 \\
  p_{ic} \ + \max\big(\text{maxPuntaje}(i+1, c - 1, p+p_{ic}),\ \text{maxPuntaje}(i+1, c, p+p_{ic})\big)
  & \text{si } (p+p_{ic}) >= 0 \land (c = 9) \land (i < 9) \\
  p_{ic} \ + \max\big(\text{maxPuntaje}(i+1, c + 1, p+p_{ic}),\ \text{maxPuntaje}(i+1, c, p+p_{ic})\big)
  & \text{si } (p+p_{ic}) >= 0 \land (c = 1) \land (i < 9) \\
  p_{ic} \ + \max\big(\max(\text{maxPuntaje}(i+1, c - 1, p+p_{ic}), \text{maxPuntaje}(i+1, c+1, p+p_{ic})),\ \text{maxPuntaje}(i+1, c, p+p_{ic})\big)
  & \text{si } (p+p_{ic}) >= 0 \land (c < 9) \land (c > 1) \\
\end{cases}
$$


### 3) (P. Dinámica)
- ¿Que dimensiones tiene la tabla? La tabla tiene dimension 3, pues depende de los parámetros i: fila, c: columna y p: puntaje acumulado
- ¿En qué orden se llenará? En orden DECRECIENTE de i, y para cada i, en orden decreciente de c (aunque este podria cambiar), y para cada c, en orden creciente de p

~~~
fun maxValor(p:array[1..9, 1..9] of Int, c: Nat) ret res: Nat
    var tabla[0..9, 0..9, 0]
    
end fun
~~~
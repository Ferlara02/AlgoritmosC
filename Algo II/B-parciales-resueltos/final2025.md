### 1) 
- Sos DJ y tenes una coleccion de N canciones de 15 artistas diferentes, cada una puntuada con un nivel de intensidad v_i, con i entre 1 y N. Tenés que armar un set de 30 canciones para pasar en una fiesta de manera que la intensidad vaya creciendo desde la cancion 1 a la 30 con la condicion de que no podés pasar mas de 3 canciones de un mismo autor. Se pide seleccionar las 30 canciones que pasarás, de manera que la suma total de intensidad sea máxima.

##### a) Criterio de seleccion:
- Seleccionar la cancion con mayor intensidad entre las disponibles, siempre que ya no se hayan pasado 3 canciones del mismo autor

##### b) Estructura de datos: 
- Representare a cada cancion como una tupla definida como:
~~~
type cancion = tuple
                v: Nat //intensidad
                n: Nat //Id
                a: Nat //Numero identificador del autor
               end tuple      
~~~
- Y al conjunto de canciones lo representare: c: Set of Cancion. Devolveré una lista selected: List of Cancion, que es una lista con las canciones a pasar (y con el orden a reproducirlas: la de la izquierda primero)
##### c) Funcionamiento:
- Con un arreglo aut:array[1..15] of Nat, iré llevando la cuenta de cuantas canciones se reprodujeron de cada artista. Mientras no haya 30 canciones elegidas, se irá obteniendo en cada iteracion la cancion del conjunto con mayor intensidad entre todas las no elegidas. Si se reprodujeron menos que 3 canciones de dicho autor, entonces agrego la susodicha a la lista POR IZQUIERDA, la elimino del conjunto y le sumo 1 a la cantidad de reproducciones de dicho autor. 

##### d) Algoritmo:

````C
fun canciones(c: Set of Cancion) ret selected: List of Cancion
    var aut:array[1..15] of Nat
    var c2: Set of Cancion
    var k : Nat
    var cancionAux: Cancion
    selected := empty_list()
    k := 0 //contador para ver cuantas canciones voy agregando
    c2 := copy_set(c)
    //inicializo los contadores de los artistas en 0:
    for i:= 1 to 15 do
        aut[i] := 0
    od
    while(not is_empty_set(c2) && k < 30) do
        cancionAux := get_max_can(c2) //obtengo la cancion con mayor intensidad
        elim(c2, cancionAux)
        if(aut[cancionAux.a] <= 3) then
            addl(selected, cancionAux) //agrego a la lista
            aut[cancionAux.a] := aut[cancionAux.a] + 1
            k := k+1
        fi
    od
    destroy_set(c2)
end fun

(Falta la funcion get_max_can())
````        

### 3) a) (Backtracking)
- Sos la unica programadora de una flamante empresa que provee desarrollo en distintos proyectos. Tenes n proyectos posibles a los cuales ofrecer servicio y la posibilidad de trabajar H horas como máximo. Para cada proyecto i {1..n} ya calculaste la cantidad de horas h_i que requiere de trabajo, y la paga p_i que recibirás si lo hacés. Tenés la posibilidad de pedirle a un amigo que te ayude con algunos proyectos, en cuyo caso te va a tomar la mitad de las horas (division entera), pero vas a cobrar la mitad del dinero (ya que en la otra mitad se la darás a tu amigo). Se debe calcular la máxima ganancia que podés obtener eligiendo que proyectos tomar y cuándo recurrir a la ayuda de tu amigo.

##### i) Que calcula la funcion:
- la funcion maxProfit(i, h) calcula la mayor ganancia que se puede sacar dados 1,..,i proyectos con p1,..,pi valores y sus respectivas cargas horarias h1, .., hi y con la posibilidad de que etc...

> Llamada principal: maxProfit(n, H)

$$
maxProfit(i, h) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } (i = 0 \vee h = 0)\\
maxProfit(i-1, h) & \text{si } i>0 \land h_i/2 > h\\
\max((p_i/2)+maxProfit(i-1,h-h_i/2), maxProfit(i-1,h)) & \text{si } (i>0) \land (h_i/2 \le h) \land (h_i > h)\\
\max(maxProfit(i-1, h), \ \max((p_i/2)+maxProfit(i-1,h-h_i/2), p_i+maxProfit(i-1,h-h_i))) & \text{si } (i>0) \land (h_i \le h) \\
\end{array}
\right.
$$

### 3) b) (P. Dinámica)
-  La tabla debe tener 2 dimensiones, pues depende del valor de la cantidad de proyectos a disposicion y de la cantidad de horas totales restantes. 
- La misma se llena en orden creciente de i, y para cada i, en orden creciente de h. Es decir, de arriba a abajo y de derecha a izquierda.
- Se podría llenar de otra forma? Si, lo importante es que las filas i se calculen de forma creciente, pero para cada fila i, el orden de llenado de las columnas h no es importante porque siempre necesito una fila anterior (que ya está calculada) entonces podria llenar columnas de forma decreciente por ejemplo.

- Codigo:
~~~
fun maxProfit(hp: array[1..N] of Nat, p:array[1..N] of Float, H: Nat) ret res: Float
    var tabla: array[0..N, 0..H] of Float
    {-Caso base-}
    for i:= 0 to N do
        for k := 0 to H do
            if(i = 0 v k = 0) then
                tabla[i, k] := 0
            fi
        od
    od
    {-Caso recursivo-}
    for i:= 1 to N do
        for k := 1 to H do
            if(hp[i]/2 > j) then
                tabla[i, k] := tabla[i-1, k]
            else if(hp[i]/2 <= j ^ hp[i] > j) then
                tabla[i, k] := max(p[i]/2 + tabla[i-1, k-hp[i] div 2])
            else
                tabla[i, k] := max(tabla[i-1,k], max((p[i]/2) + tabla[i-1, k-(hp[i] div 2)], p[i] + tabla[i-1, k-hp[i]])) 
            fi
        od
    od
    res := tabla[N, H]
end fun
~~~
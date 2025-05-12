> 4) 

### I) Criterio de selección: 
- se hará sobre S1,...,Sn, 
siendo cada Sk el tiempo de supervivencia de la respectiva 
ballena k.
* > La primer ballena a salvar siempre será la que menor 
tiempo de supervivencia tiene en tal momento.

### II) Estructura de datos: 
- Dado que el orden es importante, podemos representar 
la secuencia de ballenas a salvar con un arreglo 
(siendo el primer elemento la primer ballena a salvar), 
pero como el tiempo de supervivencia va ligado a cada ballena, 
podemos representar las ballenas recibidas con un arreglo de TUPLAS, 
tanto con el numero de ballena como el tiempo de sup. de la misma. 
Luego, lo que devuelve el algoritmo es una LISTA pero solo con el 
numero de las ballenas.

### III) Funcionamiento: 
- El algoritmo ordenará de menor a mayor las ballenas bajo su 
tiempo de supervivencia.
Lo que hará será ir seleccionando la ballena con el 
menor tiempo de supervivencia de todo un segmento del 
arreglo original. Una vez elegida (salvada), se le descontará t 
a cada una de las otras ballenas. Se repite el proceso, 
seleccionando ahora la ballena con menor tiempo de supervivencia 
sin contar la ya salvada (y mientras el tiempo sea >0).

### IV) Algoritmo:
~~~
~~~~haskell
type ballena = tuple 
                    num : Int 
                    s : Int 
                end tuple 


proc (in/out a:array[1..n] of ballena, in t:Int, out ballenas_a_salvar : List of Int)
    ballenas_a_salvar := empty_list()
    var i :Int 
    i := 1
    var min_pos : Int  
    while i<n do 
        min_pos := min_ball_from(a, i)
        swap(a, i, min_pos)
        if(a[i].s > 0) then 
            addr(ballenas_a_salvar, a[i].num)
        fi 
        i := i+1
        for i to n do 
            a[i].s := a[i].s - t
        od
    od 
end proc

fun min_ball_from(a:array[1..n] of ballena, i : int) ret minp : int
    var j : nat 
    minp := i 
    j := i+1
    while j<=n do 
        if(a[j].s < a[minp].s) then 
            minp := j 
        fi 
        j := j+1 
    od  
end fun 

proc swap (in/out a:array[1..n] of ballena, in i, j : int) 
    var tmp : ballena 
    tmp := a[i]
    a[i] := a[j]
    a[j] :0 tmp 
end proc 


~~~
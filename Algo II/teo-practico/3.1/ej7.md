### 7) 
> Un submarino averiado descansa en el fondo del oceano con n sobrevivientes en su interior. Se conocen las cantidades c1,..., cn de oxígeno que cada uno de ellos consume por minuto. El rescate de sobrevivientes se puede realizar de a uno por vez, y cada operacion de rescate lleva t minutos.

- a) Algoritmo voraz que determine el orden en que deben rescatarse los sobrevivientes para salvar al mayor numero posible de ellos antes de que se agote el total C de oxígeno.

- b) Modificar dicha solucion suponiendo que por c/operacion de rescate se puede llevar a la superficie m sobrevivientes (con m<=n)

### I) Criterio de selección:
- Debo ir seleccionando al sobreviviente que MAYOR OXIGENO consume por minuto, para sacarlo del submarino lo antes posible y que por tanto se maximice el oxígeno restante.

### II) Estructura de datos:
- Recibo un arreglo de tuplas con los datos de cada sobreviviente, una cantidad C de oxigeno en nat, y un tiempo t que es el que tardo en rescatar a cada sobreviviente; y devuelvo una lista con el orden a salvar.

### III) Funcionamiento: 
- Primero ordeno el arreglo de mayor a menor de acuerdo al oxigeno que consume cada uno. Luego, voy recorriendo el arreglo mientras el oxigeno NO sea 0 y desde el primer elemento. Al elemento en el que estoy parado (i) lo agrego a la lista por derecha, luego recorro nuevamente el arreglo desde la posicion SIGUIENTE (i+1) hasta n para calcular el oxigeno consumido -por todos los sobrevivientes restantes- durante el tiempo de rescate t. Dicho resultado será lo que le resto al oxígeno que queda. 

### IV) Algoritmo:

~~~
type survivor = tuple 
                    id : nat
                    c : nat
                end tuple

fun (a:array[1..n] of survivor, c : nat, t : nat) ret l : List of survivor
    var a_aux : array[1..n] of Amigo
    a_aux := copy_array(a)
    //ordeno el arreglo de MAYOR a MENOR en func. de a[k].c (consumo de oxig. de la persona):
    quick_sort_mod(a_aux)
    var resto : nat
    resto := c
    var consumed : nat
    var i : nat
    i := 1
    l := empty_list()
    while(i<=n && resto > 0) do 
        addr(l, a[i])
        consumed := get_consumed(a, i+1, t)
        resto := resto - consumed
        i := i+1
    od
end fun 

fun get_consumed(a:array[1..n] of survivor, i : nat, t) ret consumed : nat
    var x : nat
    x := 0
    if(i<n+1) then 
        for j := i to n do
            x := x + a[j].c * t
        od
    fi
    res := x  
end fun

~~~

### b):

- La modificacion que debo hacer es sólo sobre la funcion principal, dejando las auxiliares como en a): 

~~~ 
fun (a:array[1..n] of survivor, c : nat, t : nat, m : nat) ret l : List of survivor
    var a_aux : array[1..n] of Amigo
    a_aux := copy_array(a)
    quick_sort_mod(a_aux)
    var resto : nat
    resto := c
    var consumed : nat
    var i : nat
    i := 1
    l := empty_list()
    while(resto > 0 && i<=n)
        while(i<=m) do 
            addr(l, a[i])
            i := i+1
        od
        consumed := get_consumed(a, i+1, t)
        resto := resto - consumed
    od
end fun
~~~
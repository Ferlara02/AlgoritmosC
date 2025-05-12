> 5) Suponiendo que conoces los días de partida y regreso
(pi y ri respectivamente) de cada uno de tus amigos,
¿cu´al es el criterio para determinar, en un momento dado, 
a quien conviene prestarle el equipo?
Tener en cuenta que cuando alguien lo devuelve, 
recien a partir del dıa siguiente puede usarlo otro. Escribir
un algoritmo voraz que solucione el problema.


### I) Criterio de selección:
- Debo ir seleccionando al amigo que termina su viaje antes. 

### II) Estructura de datos: 
- Podriamos representar la informacion recibida como un arreglo de tuplas, 
donde cada tupla tiene los campos 
numero : Int, p : Int (fecha de partida), r : int (fecha de regreso). 
Luego la informacion que devolveremos será una lista del mismo tipo amigo. 

### III) Funcionamiento: 

- Ordena el arreglo de menor a mayor segun la fecha de regreso de cada amigo
recorriendo el arreglo. Una vez teniendo el arreglo ordenado, lo recorre una vez más, 
añadiendo a la lista sólo los amigos que tienen fecha de partida POSTERIOR al ultimo dia 
ocupado + 1. El ultimo dia ocupado es la fecha de llegada del ultimo amigo añadido a la lista.

### IV) Algoritmo:

> formato de fecha: 4 digitos: MMDD

~~~
type Amigo = tuple
                num : Int 
                p : Int 
                r : Int 
            end tuple 

//Con conjuntos se re complica una cagad!!
fun select_amigos(C : Set of Amigo) ret l : List of Amigo
    var C_aux : Set of Amigo 
    var C_aux2 : Set of Amigo
    var C_aux3 : Set of Amigo  
    C_aux2 := set_copy(C)
    var amigo_aux : Amigo 
    l := empty_list()
    var min_date : Int 
    min_date := inf
    selected : Amigo
    while (not is_empty_set(C_aux2)) do
        C_aux := set_copy(C_aux2)   
        while(not is_empty_set(C_aux)) do 
            amigo_aux := get(C_aux)
            if(amigo_aux.r < min_date) then 
                selected := amigo_aux
                min_date := amigo_aux.r 
            fi
            elim(C_aux, amigo_aux) 
        od
        addl(l, selected)
        elim(C_aux2, selected)
        C_aux3 := set_copy(C_aux2)
        while(not is_empty_set())....no lo termine    
    od  
end fun

//VERSION CON UN ARREGLO (definitiva)
fun select_amigos(a : array[1..n] of Amigo) ret l : List of Amigo
    quick_sort_mod(a) //variante que ordena segun fecha de regreso
    l := empty_list()
    var ult_dia_ocupado := -1 
    for i := 1 to n do 
        if(a[i].p > ult_dia_ocupado + 1) then 
            addl(l, a)
            ultimo_dia_ocupado := a[i].r
        fi 
    od 
end fun 

//faltaria completar el quick_sort (aunque podria ser cualquier algo de ordenacion)

~~~
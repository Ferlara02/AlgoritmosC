### 8)
>  Usted vive en la montaña, es invierno, y hace mucho frıo. Son las 10 de la noche. Tiene una voraz estufa a leña y n troncos de distintas clases de madera. Todos los troncos son del mismo tamano y en la estufa entra solo uno por vez. Cada tronco i es capaz de irradiar una temperatura ki mientras se quema, y dura una cantidad ti de minutos encendido dentro de la estufa. Se requiere encontrar el orden en que se utilizaran la menor cantidad posible de troncos a quemar entre las 22 y las 12 hs del dıa siguiente, asegurando que entre las 22 y las 6 la estufa irradie constantemente una temperatura no menor a K1; y entre las 6 y las 12 pm, una temperatura no menor a K2.

### I) Criterio de selección:
- Ir eligiendo el tronco con mayor duración dentro de todos los que cumplen que su Ki sea mayor o igual que K1 o K2 (segun corresponda).

### II) Estructura de datos: 
- Recibo un conjunto de tuplas, donde cada tupla representa una leña y contiene la info de la duracion y la temperatura de la misma. Lo que devuelvo es una lista de leñas, que se debe leer de izquierda a derecha, donde el elemento a la izquierda es la primera leña que debo colocar.

### III) Funcionamiento:
- Copio el conjunto de leñas original. 
Mientras la hora sea menor a las 6am obtengo la leña con mayor duracion de un conjunto, si dicha leña cumple que su temperatura es mayor o igual a K1, entonces la añado por derecha a la lista y actualizo la hora actual en base a la duracion de la leña añadida. Posteriormente la elimino del conjunto copia. 
Por el otro lado, si dicha leña no satisface la cond. anterior, NO la agrego a la lista, la elimino del conjunto copia PERO la agrego a un tercer conjunto (que inicialmente es vacío).
Una vez que ya pasaron las 6am, hago una unión del conjunto copia (con las leñas que sobraron y que no necesariamente NO cumplían la condicion) con el conjunto de todas aquellas leñas que su temperatura era menor a K1. Con este nuevo conjunto, y hasta que el mismo no sea vacío y la hora sea menor a las 12, voy obteniendo la leña con mayor duracion. Analogamente a la primer franja horaria, si la leña cumple que su temp. >= a K2, la agrego por derecha a la lista, la elimino del conjunto y actualizo la hora. 
Lo que retorno al final del algoritmo es dicha lista ordenada. 

### IV) Algoritmo:

~~~
type Leña = tuple 
                t : nat
                k : nat
            end tuple

fun (c : Set of Leña, K1 : Nat, K2 : Nat) ret l : List of Leña
    c2 : Set of Leña    
    c2 := copy_set(c)
    c3 : Set of Leña
    c3 := empty_set()
    hora : Nat 
    hora := 0
    leña : Leña
    k_selected : Nat

    //desde las 22hs hasta las 6 hay 360 min:
    while(hora < 360 && not is_empty_set(c2)) do
        leña := get_max_leña(c2)
        if(leña.k >= K1) then
            addr(l, leña)
            elim(c2, leña)
            hora := hora + leña.t
        else 
            elim(c2, leña)
            add_elem(c3, leña)
        fi
    od

    //Uno las leñas que me sobraron de c2 y las que añadi a c3 que no satisfacían leña.k >= k1:
    union(c2, c3)

    while((hora >= 360 && hora < 840) && not is_empty_set(c2)) do 
        leña := get_max_leña(c2)
        if(leña.k >= K2) then 
            addr(l, leña)
            hora := hora + leña.t
        fi 
        elim(c2, leña)
    od

    destroy_set(c2)
    destroy_set(c3)
end fun 

//Obtiene la leña con mayor duracion de un conjunto
fun get_max_leña(c : Set of Leña) ret leña : Leña
    c2 : Set of Leña
    c2 := copy_set(c)
    max_leña : Leña
    max : Nat
    max := 0
    aux : Leña
    while(not is_empty_set(c2)) do
        aux := get_elem(c2)
        if(max < aux.t) then
            max_leña := aux
            max := aux.t
        fi
        elim(c2, aux)
    od
    leña := max_leña
    destroy_set(c2)
end fun

~~~
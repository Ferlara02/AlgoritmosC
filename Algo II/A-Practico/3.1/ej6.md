
### 6) 
> En el horno se encuentran n piezas de panaderıa 
(facturas, medialunas, etc). Cada pieza i que se encuentra
en el horno tiene un tiempo mınimo necesario de coccion ti 
y un tiempo maximo admisible de coccion Ti
Si se la extrae del horno antes de ti quedara cruda 
y si se la extrae despues de Ti se quemara.
Asumiendo que abrir el horno y extraer piezas de ´el no insume tiempo, 
y que ti ≤ Ti para todo i ∈
{1, . . . , n}, ¿que criterio utilizarıa un algoritmo voraz 
para extraer todas las piezas del horno en perfecto estado (ni crudas ni quemadas), 
abriendo el horno el menor numero de veces posible?

### Criterio de selección: 
La idea es que cada vez que abro el horno, quiero sacar la mayor cantidad de piezas posibles. Para ello, voy sacando las piezas que MENOS tardan en quemarse (criterio similar al del telefono, pues ahi elegiamos al que volvia antes) y a la vez verifico que otras piezas puedo sacar que se encuentren en ese intervalo

### II) Estructura
- Recibo un Set de piezas (tupla)

### III) Funcionamiento: 
- Elijo la pieza con menor tiempo máximo. Luego, con ese tiempo, me fijo qué otras piezas contienen en su intervalo dicho Ti. Todas las que verifiquen esta condicion las saco del horno en esa misma apertura (si ninguna lo cumple, simplemente saco una pieza). Continuo hasta que el horno esté vacío.

### IV) Código:

~~~
type pieza = tuple 
                id : string
                t_min : nat
                t_max : nat
            end tuple

fun sacar_piezas(p : Set of pieza) ret res : nat 
    var piezas : Set of pieza 
    piezas := copy_set(p)
    var min_pieza : pieza
    while (not is_empty_set(piezas)) do 
        pieza_min := get_min_pieza(piezas)
        elim(piezas, pieza_min)
        delete_piezas(piezas, pieza_min.t_max)
        res:=res+1
    od 
    destroy_set(piezas)
end fun

{- Consigue la pieza con menor Ti -}
fun get_min_pieza(p : Set of pieza) ret min_pieza : pieza
    var piezas : Set of pieza
    piezas := copy_set(p)
    var pieza_aux : pieza
    var min : nat
    min := infinito
    while (not is_empty_set(piezas)) do 
        pieza_aux := get_elem(piezas)
        elim(piezas, pieza_aux)
        if(pieza_aux.t_max < min) then 
            min := pieza.T_max
            res := pieza_aux
        fi 
    od
    destroy_set(piezas)  
end fun

proc delete_piezas(in/out p : Set of pieza, in t : nat) 
    var piezas : Set of pieza
    piezas := copy_set(p)
    var pieza_aux : pieza
    while (not is_empty_set(piezas)) do 
        pieza_aux := get_elem(piezas)
        elim(piezas, pieza_aux)
        if(pieza_aux.t_min <= t && pieza_aux.t_max >= t) then
            elim(p, pieza_aux)
        fi 
    od
    destroy_set(piezas)
end proc 
~~~


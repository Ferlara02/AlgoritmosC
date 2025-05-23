### 9) 
> (sobredosis de limonada) Es viernes a las 18 y usted tiene ganas de tomar limonada con sus amigos. Hay n bares cerca, donde cada bar i tiene un precio Pi de la pinta de limonada y un horario de happy hour Hi, medido en horas a partir de las 18 (por ejemplo, si el happy hour del bar i es hasta las 19, entonces Hi = 1), en el cual la pinta costará un 50% menos. Usted toma una cantidad fija de 2 pintas por hora y no se considera el tiempo de moverse de un bar a otro. Se desea obtener el menor dinero posible que usted puede gastar para tomar limonada desde las 18 hasta las 02 am (es decir que usted tomará 16 pintas) eligiendo en cada hora el bar que más le convenga.

- Algoritmo voraz que determine el orden de bares a concurrir para gastar el menor dinero posible para tomar limonada desde las 18 hasta las 02 (16 pintas), y que tambien calcule dicho precio minimo.

### I) Criterio de selección:
- Se trata de ir seleccionando, simplemente, el bar que tiene el precio mas bajo en esa hora en particular. 

### II) Estructura de datos:
- Se representa el conjunto de bares como un Set de tuplas, donde cada tupla representa a c/bar, con los campos b: numero de bar (Nat), h: hora limite del happy hour (Nat), y p: precio de la pinta (Float). 
Lo que se devuelve es una lista ordenada, con el bar al que hay que ir a cada hora (arrancando a las 18). Si hay un bar repetido consecutivamente k veces, significa que uno debe quedarse k horas en ese bar. 

### III) Funcionamiento:
- Se debe ir actualizando la hora actual (arrancando en 0 = 18hs) para obtener el bar con el menor precio en tal momento, se lo añade por derecha a la lista y se actualiza la hora (+1). A su vez, se calcula el precio a ser sumado al precio total gastado: si el bar esta en horario de happy hour, el precio de dos pintas es simplemente el precio de la pinta. Si no lo está, el sumado es el precio de la pinta por dos. Esto se repite mientras que la hora sea < 8 (02 am).

### IV) Algoritmo:
~~~
type Bar = tuple 
            b : Nat
            h : Nat
            p : Float
           end tuple

proc cronograma_bares(in c : Set of Bar, out l : List of Bar, out precio : Float)
    var hora : Nat
    hora := 0
    var c2 : Set of Bar
    c2 := copy_set(c)
    var bar : Bar
    precio := 0
    l := empty_list()
    while(hora < 8) do
        bar := get_min_bar(c2, hora)
        addr(l, bar)
        //si está en happy hour, el precio de 2 pintas es simplemente bar.p
        if(bar.h > hora) then
            precio := precio + bar.p
        else 
            precio := precio + bar.p * 2
        fi
        hora := hora + 1
    od

    destroy_set(c2)
end proc

fun get_min_bar(c : Set of Bar, hora : Nat) ret min_bar : Bar
    var c2 : Set of Bar
    c2 := copy_set(c)
    var bar : Bar
    var bar_res : Bar
    min_precio : Float
    min_precio := Infinito
    precio_aux : Float
    while(not is_empty_set(c2)) do
        bar := get_elem(c2)
        if(bar.h > hora) then
            precio_aux := bar.p / 2
        else 
            precio_aux := bar.p
        fi
        if(precio_aux < min_precio) then
            min_precio := precio_aux
            bar_res := bar 
        fi
        elim(c2, bar)
    od
    min_bar := bar_res
    destroy_set(c2)
end fun 
~~~
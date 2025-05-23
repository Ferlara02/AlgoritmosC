> 3) Se desea realizar un viaje en auto con autonomia A (km) 
desde l0 hasta ln
pasando por l1,....ln-1 (en ese orden).
Se conoce cada distancia di <= A entre li-1 e li. 
Y existe una estacion en c/una de las localidades. 
> Algoritmo que compute el menor numero de veces 
que es necesario cargar combustible para realizar 
el viaje, y las localidades donde realizará la carga 
suponiendo que inicialmente el tanque se encuentra vacío.

### I) Criterio de selección: 

- Estando parado en lk-1, y dado dk la distancia entre lk-1 y lk, 
si C > dk, entonces NO CARGO en lk-1 (siendo C el combustible 
que me queda, esto es la autonomia MENOS la distancia recorrida 
hasta ese punto SIN CARGAR COMBUSTIBLE)

### II) Estructura de datos: 
- Teniendo a disposicion el TAD Counter, 
TAD Lista, TAD Pila, TAD Cola, etc. Podríamos representar el 
conjunto de localidades a cargar como una lista of T, siendo li : T, 
y el conjunto de localidades recibidas como un arreglo al igual que 
el conjunto de distancias di.

### III) Funcionamiento:
- Primero se elige l0 (se lo añade a la lista), pues el tanque 
es vacío. A partir de allí vamos calculando lo que me queda 
de AUTONOMÍA a partir de la distancia recorrida 
(sin cargar combustible) y la autonomía. 
Se elige li (localidad en donde estoy parado) al conjunto 
si y solo si se satisface que la distancia entre li y li+1 (di+1) 
es MENOR que la autonomia restante. En caso que no se satisfaga esto, 
NO SE ELIGE li pero si se restablece la autonomia (pues se cargó combustible).

### IV) Algoritmo:

~~~

proc puntos_de_carga(in l:array[1..N+1] of T,  in d:array[2..N+1] of int, in A : int, out puntos_carga : List of T, out cargas : Int)
    puntos_carga := empty_list()
    addl(puntos_carga, l[1])
    var autonomia_rest : Int
    autonomia_rest := A 
    var i : Int 
    i := 1 
    cargas := 0
    while(i<=N) do 
        if(d[i+1] > autonomia_rest) then 
            addr(puntos_carga, l[i])
            autonomia_rest := A 
            carga := carga + 1
        else if(d[i+1] <= autonomia_rest) 
            autonomia_rest := autonomia_rest - d[i+1]
        fi
        i := i+1 
    od  
end proc 

~~~
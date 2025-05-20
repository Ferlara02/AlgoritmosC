### 3)
- Usted quiere irse de vacaciones y debe elegir una ciudad entre K posibles que le interesan. Como no dispone de mucho dinero, desea que el viaje de ida hacia la ciudad pueda realizarse con a lo sumo L litros de nafta.

a) Dar un algoritmo que, dado un grafo representado por una matriz E: array[1..n,1..n] of Nat, donde el elemento E[i,j] indica el costo en litros de nafta necesario para ir desde la ciudad i hasta la ciudad j; un conjunto C de vértices entre 1 y n, representando las ciudades que quieren visitarse; un vértice v, representando la ciudad de origen del viaje; y un natural L, indicando la cantidad de litros de nafta total que puede gastar; devuelva un conjunto D de aquellos vértices de C que puede visitar con los L litros.

~~~
fun visitables(a: array[1..n,1..n] of nat, C: Set of Nat, L: nat) ret D: Set of Nat
    var costos: array[1..n] of nat
    var C2: Set of Nat
    var city: nat
    costos:= Dijkstra(a, v) //array con los costos "optimizados"
    C2:= copy_set(C)
    D:= empty_set()
    while (not is_empty_set(C2)) do
        city:= get_elem(C2)
        elim(C2, city)
        if (costos[city] <= L) then 
            add(D, city) 
        fi
    od
    destroy_set(C2)
end fun
~~~
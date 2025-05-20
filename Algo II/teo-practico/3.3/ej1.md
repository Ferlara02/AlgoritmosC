### 1) 
- Modifique el codigo del algoritmo que resuelve el problema de la moneda utilizando backtracking,
de manera que devuelva qu´e monedas se utilizan, en vez de s´olo la cantidad.

~~~
fun cambio(j : Nat, C: Set of Nat) ret L : List of Nat
    var c : Nat
    var C_aux : Set of Nat
    L := empty_list()
    if j = 0 then 
        S := 0
    else if is_empty(C) then 
        S := ∞
    else 
        C_aux:= set_copy(C)
        c := get(C)
        elim(C_aux,c)
        if (c ≤ j) then 
            S := min(1+cambio(j-c, C), cambio(j, C_aux))
        else 
            S := cambio(j, C_aux)
        fi
    fi
    set_destroy(C_aux)
end fun

~~~
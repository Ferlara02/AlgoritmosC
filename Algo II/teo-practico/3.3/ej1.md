### 1) 
- Modifique el codigo del algoritmo que resuelve el problema de la moneda utilizando backtracking,
de manera que devuelva qu´e monedas se utilizan, en vez de s´olo la cantidad.

~~~
fun cambio(j : Nat, C: Set of Nat) ret L : List of Nat
    var c : Nat
    var C_aux : Set of Nat
    L_res : List of Nat
    L1, L2 : List of Nat
    if j = 0 then 
        L_res := empty_list()
    else if is_empty(C) then 
        L := lista infinita (preguntar)
    else 
        C_aux:= set_copy(C)
        c := get(C)
        elim(C_aux, c)
        if (c ≤ j) then
            L1 := cambio(j-c, C)
            addl(L1, c)
            L2 := cambio(j, C_aux)
            if(length(L1) <= length(L2)) then
                L_res := L1
            else
                L_res := L2
            fi
        else 
            L_res := cambio(j, C_aux)
        fi
    fi

    L := L_res
    set_destroy(C_aux)
end fun

~~~
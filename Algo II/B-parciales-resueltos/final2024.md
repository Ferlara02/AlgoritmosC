### (Backtracking)
- Ya pasaste los 35 años y al fin te pones las pilas para hacer ejercicio fisico. En el gimnasio tenes un plan con n ejercicios donde cada ej. i, 1<=i<=n tiene asociado un valor de entrenamiento e_i. Ademas cada ejercicio i requiere un esfuerzo de brazos b_i, un esfuerzo de zona media z_i y un esfuerzo de piernas p_i.

Se debe encontrar el maximo valor de entrenamiento general obtenible al elegir ejercicios sin que el esfuerzo total en brazos supere el monto B, el esfuerzo total en zona media supere el monto Z y el esfuerzo total en piernas supere el monto P.

##### a) 
- La funcion maxValor(i, b, z, p) calcula dados 1,..,i ejercicios con valor de entrenamiento e_i, esfuerzos b_i, zona media z_i y esfuerzo de piernas p_i el maximo valor de entrenamiento sin superar el esfuerzo restante de brazos B, de zona media Z y de piernas P.

##### b)
> Llamada principal: maxValor(n, B, Z, P)

##### c)

$$
maxValor(i,b, z, p) =
\left\lbrace
\begin{array}{ll}
0 & \text{si } (i = 0)\\
\max((p2_i/C_2)+maxValor(i-1,2), (p3_i/C_3)+maxValor(i-1,3)) & \text{si } (i>0) \land (Color = 1) \\
\max((p1_i/C_1)+maxValor(i-1, 1), (p3_i/C_3)+maxValor(i-1,3)) & \text{si } (i>0) \land (Color = 2) \\
\max((p1_i/C_1)+maxValor(i-1,1), (p2_i/C_2)+maxValor(i-1,2)) & \text{si } (i>0) \land (Color = 3)
\end{array}
\right.
$$
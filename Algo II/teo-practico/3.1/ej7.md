### 7) 
> Un submarino averiado descansa en el fondo del oceano con n sobrevivientes en su interior. Se conocen las cantidades c1,..., cn de oxígeno que cada uno de ellos consume por minuto. El rescate de sobrevivientes se puede realizar de a uno por vez, y cada operacion de rescate lleva t minutos.

- a) Algoritmo voraz que determine el orden en que deben rescatarse los sobrevivientes para salvar al mayor numero posible de ellos antes de que se agote el total C de oxígeno.

- b) Modificar dicha solucion suponiendo que por c/operacion de rescate se puede llevar a la superficie m sobrevivientes (con m<=n)

### I) Criterio de selección:
- Debo ir seleccionando al sobreviviente que MAYOR OXIGENO consume por minuto, para sacarlo del submarino lo antes posible y que por tanto se maximice el oxígeno restante.

### II) Estructura de datos:
- Recibo un arreglo de tuplas con los datos de cada sobreviviente, una cantidad C de oxigeno en nat, y un tiempo t que es el que tardo en rescatar a cada sobreviviente; y devuelvo una lista con el orden a salvar.

### III) Funcionamiento: 
- Primero ordeno el arreglo de mayor a menor de acuerdo al oxigeno que consume cada uno. Luego, voy recorriendo el arreglo desde el primer elemento, verificando si  
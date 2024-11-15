# Busqueda en anchura

Para hacer la busqueda en anchura se usa una cola para imlementarla, 
de esta manera el recorrido se hace por capas.

Primero se saca el primer elemento y se pone en la cola

Luego con un proceso iterativo vamos recorriendo la cola hasta que quede vacia
en cada vuelta, se saca el elemento siguiente, se marca como visitado, se 
pone a cada uno de sus hijos en la cola, y se procesa.

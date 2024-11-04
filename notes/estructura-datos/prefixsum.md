# Prefix Sum

Es un arreglo que tiene una suma acumulativa de ciertos elementos, y para acceder a la suma acumulada en el rango i, j, se hace de la manera: `prefix[j] - prefix[i-1]`, le restamos la suma acumulada antes del primer limite para quedarnos con la suma acumulada del rango.

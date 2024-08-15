# Brute Force Script (Python)

Este script nos permite ver la cantidad de tiempo que una computadora tardaria en romper una contraseña de 4 caracteres
mediante un ataque de fuerza bruta.

## Ejecutar el script

Para ejecutar el script debemos ejecutar el siguiente comando:

```
python3 brute-force.py
```

**Nota: La terminal debe estar situada en la ruta en la que se encuentra el archivo de código fuente.**

## Resultado encontrados

Los siguientes son los resultados arrojados despues de la ejecución del script:

```
# Solo digitos: 10,000 combinaciones (0.05s de ejecucion)
# Digitos y minusculas: 1,679,616 combinaciones (8s de ejecucion)
# Digitos, minusculas y mayusculas: 14,776,336 combinaciones (72s/1min 12s de ejecucion)
# Digitos, minusculas, mayusculas y signos: 92,236,816 combinaciones (380s/6min 20s de ejecucion)
```

**Nota: El script fue ejecutado considerando una longitud de contraseña de 4 caracteres.**

Consideraciones del equipo:

- Lubuntu (64 Bits).
- 2 GB de memoria RAM.
- Procesador AMD Ryzen 5500U

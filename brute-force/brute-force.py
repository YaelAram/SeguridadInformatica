from string import digits, ascii_lowercase, ascii_uppercase, punctuation
import time

# Solo digitos: 10,000 combinaciones (0.05s de ejecucion)
# Digitos y minusculas: 1,679,616 combinaciones (8s de ejecucion)
# Digitos, minusculas y mayusculas: 14,776,336 combinaciones (72s/1min 12s de ejecucion)
# Digitos, minusculas, mayusculas y signos: 92,236,816 combinaciones (380s/6min 20s de ejecucion)

start = time.time()

for j in digits + ascii_lowercase + ascii_uppercase + punctuation:
    for k in digits + ascii_lowercase + ascii_uppercase + punctuation:
        for l in digits + ascii_lowercase + ascii_uppercase + punctuation:
            for m in digits + ascii_lowercase + ascii_uppercase + punctuation:
                print(j, k, l, m)

end = time.time()

print(f"Tiempo total: {end - start}")

# Definimos g2 como una exponencial que forzamos que tienda a 1
g2(x) = A*exp(-B*x) + 1

# Condicones iniciales (necesarias para ajuste exponencial aunque podría linealizarse)
A = 1
B = 1
# Ajuste
fit g2(x) "datanorm.txt" via A, B

# Guardamos los datos
set print "ctesg2.txt"
print A
print B

# Definimos g2 como una exponencial
g2(x) = A*exp(-B*x) + C

# Condicones iniciales (necesarias para ajuste exponencial aunque podría linealizarse)
A = 1
B = 1
C = 1
# Ajuste
fit g2(x) "datanorm.txt" via A, B, C

# Guardamos los datos
set print "ctesg2.txt"
print A
print B
print C

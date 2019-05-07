# a(x) = log|g1(x)|²
a(x) = -m*x + n

# Ajuste
set fit errorvariables
fit a(x) "0.5logg2-1.txt" via m, n

# Guardamos los datos
set print "ctesg1.txt"
print m
print n
print m_err
print n_err
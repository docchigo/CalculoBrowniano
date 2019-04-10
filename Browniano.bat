@echo off
normalizar.exe
"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe" "ajusteg2.plt"
puntoslogg1.exe
"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe" "ajusteg1.plt"
resultados.exe
pause>nul
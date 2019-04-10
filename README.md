# CalculoBrowniano
Un simple programa preparado para analizar los datos dados por un correlador sobre el movimiento browniano

# 1. Instalación

Este programa está especialmente pensado para los sistemas operativos Linux, no obstante se puede hacer funcionar en Windows como se explicará a continuación

# 1.1. Linux

Requisitos: Para seguir este proceso de instalación del programa correctamente es necesario tener en nuestro ordenador git y g++.

Primero de todo clonamos el repositorio en el directorio que queramos para ello podemos usar:

"git clone https://github.com/docchigo/CalculoBrowniano"

Accedemos al directorio que nos hemos descargado:

"cd CalculoBrowniano"

Ahora damos permiso de ejecución al programa que se encargará de compilarnos todo:

"chmod +x Compila"

Y lo ejecutamos:

"./Compila"

Tras esto y teniendo gnuplot instalado no necesitaremos nada más para que el programa funcione.

# 1.2. Windows

Requisitos: Tener un compilador de C++ (puede usarse un IDE como, por ejemplo, CodeBlocks).

Nos descargamos todo el contenido del repositorio (fácilmente desde esta propia página).

Observaremos como hay 3 archivos CPP, necesitamos compilar estos tres archivos. Por simplicidad se pueden abrir los tres archivos con CodeBlocks y usar este IDE para compilar los tres ejecutables (.exe) que serán completamente compatibles con Windows.

Además de eso necesitaremos tener instalado gnuplot para poder usar el programa.

# 2. Utilización

Nuevamente, este programa es más fácil de usar en Linux pues está automatizado. Pero desde Windows también lo podemos usar, solo que tendremos que ir ejecutando los programas y scripts uno a uno y en el orden correcto.

NOTA: Es importante que el archivo que le pasemos al programa sea simplemente el número de canal acompañado del número de cuentas sin nada más, es decir:

1 181072
2 175629
...
...
...
256 131972

Típicamente el número de canales es 256 (al menos lo es en el correlador que estamos usando)

# 2.1 Linux

Aunque si se quiere se pueden ejecutar las partes de este programa una a una (incluso modificarlas). Lo más aconsejable es que se use el script en bash diseñado para ello. Por este motivo le damos permisos de ejecución al script:

"chmod +x Browniano"

Y ya podemos ejecutar el programa que nos pedirá cierta información con la cual calculará el diámetro del coloide y el coeficiente experimental beta:

"./Browniano"

# 2.2 Windows

Hay dos formas de utilizar este programa en Windows, se pueden ir ejecutando uno a uno los programas (lo cual siempre funcionará) o se puede ejecutar el archivo por lotes "Browniano.bat"

A) Ejecución por partes
Usar este programa es fácil pero tenemos que tener la precaución de ir en el orden correcto para que el programa disponga de toda la información a todo momento:

1) Ejecutamos normalizar.exe (haciendo doble click en él por ejemplo). El programa nos pedirá el nombre del archivo con los datos en el formato anteriormente explicado. Lo introducimos y pulsamos intro.

2) Abrimos gnuplot y cargamos el archivo ajusteg2.plt con la orden:

'load "ajusteg2.plt"'

Es importante que gnuplot esté en la carpeta en la que está este fichero, o en caso de no ser así, que antes del nombre se ponga la ruta completa al archivo.

3) Ejecutamos puntoslogg1.exe

4) De la misma forma que explicamos antes (ver 2) abrimos con gnuplot el archivo ajusteg1.plt. Es decir desde gnuplot:

'load "ajusteg1.plt"'

5) Para obtener los resultados hay que ejecutar resultados.exe e introducir además el ángulo y la temperatura (nos los pedirá el programa). AVISO: Si hacemos doble click sobre el programa, este se cerrará antes de que podamos leer nuestros resultados. Por ello es importante ejecutar este programa desde alguna aplicación que nos pause la consola antes de cerrarla. Nuevamente, por simplicidad, se puede ejecutar desde CodeBlocks.

B) Ejecución con "Browniano.bat"

ADVERTENCIA: Para que este método funcione es necesario que gnuplot esté instalado en "C:\Program Files\gnuplot" (instalación por defecto). Este método, aunque está probado en un ordenador con Windows, podría dar problemas. Si algo no funciona hablad conmigo o remitiros al método A).

Ejecutamos el programa "Browniano.bat" haciendo doble click en él. Introducimos los datos que nos soliciten los programas y después de eso debería mostrarnos por pantalla los resultados y quedarse parado hasta que pulsemos una tecla y se cierre.

Y hasta aquí el tutorial del programa. Cualquier duda o problema no dudéis en comentarlo.

Saludos,

docchigo

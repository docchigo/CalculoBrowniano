#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Número de canales a correlacionar
const unsigned int NCANALES = 256;
// Intervalo de tiempo entre medidas
const double Tintervalo = 10e-6; // 10 microsegundos de intervalo

// Suponemos que tenemos un vector con todo los datos bien guardaos
// A intervalos de Tintervalo segundos
// PS: No te lo crees ni tú pero bueno
// Y mostramos los puntos de la f. de autocorrelación normalizada
void escribe_correlacion(ostream& os, const vector<unsigned int>& v) {
	unsigned int m, j, tamc, tam = v.size(); double x, mediasq = 0;
	
	// Calculamos la media al cuadrado de los datos
	for (j = 0; j < tam; j++) mediasq += v[j];
	mediasq /= tam; mediasq *= mediasq;
	
	// Para cada canal calculamos su valor
	for (m = 1; m <= NCANALES; m++) {
		x = 0; tamc = tam - m;
		for (j = 0; j < tamc; j++) x += v[j]*v[j+m];
		x /= tamc * mediasq;
		os << m*Tintervalo << '\t' << x << endl; 
	}
}

// Lee un vector de un archivo con tiempo (se desecha) y número de cuentas
void lee_archivo(istream& is, vector<unsigned int>& v,
const unsigned int inctam = 100) {
	// Incremento del tamaño del vector durante la lectura de datos
	unsigned int i = 0, tam = inctam;
	double t, n;
	// Limpiamos el vector y le damos tamaño inicial inctam
	v.clear(); v.resize(tam, 0);
	// Bucle de lectura
	while (is >> t >> n) {
		v[i] = n; i++;
		if (i >= tam) {
			tam += inctam;
			v.resize(tam, 0);
		}
	}
	// Ajustamos el tamaño del vector al número de datos leídos
	v.resize(i);
} 

double g2_resta_1(double t, double A, double B) {
	return A*exp(-B*t);
}

int main() {
	ifstream fin("datanorm.txt"), fc("ctesg2.txt"); ofstream fout("0.5logg2-1.txt");
	double A, B;
	vector<unsigned int> v; unsigned int i, tam;
	
	fc >> A >> B;
	lee_archivo(fin, v); tam = v.size();
	
	for (i = 0; i < tam; i++)
		fout << i*Tintervalo << '\t'
		<< log(g2_resta_1(i*Tintervalo, A, B)) / 2 << endl;
	
	fin.close(); fout.close(); fc.close();
	return 0;
}

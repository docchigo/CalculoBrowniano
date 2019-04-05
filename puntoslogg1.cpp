#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// Intervalo de tiempo entre medidas
const double Tintervalo = 10e-6; // 10 microsegundos de intervalo

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

// Función que recibe t y los coeficientes de ajuste A y B y devuelve
// g2(x) - 1
double g2_resta_1(double t, double A, double B, double C) {
	return A*exp(-B*t) + C - 1;
}

int main() {
	ifstream fin("datanorm.txt"), fc("ctesg2.txt");
	ofstream fout("0.5logg2-1.txt");
	double A, B, C;
	vector<unsigned int> v; unsigned int i, tam;
	
	fc >> A >> B >> C;
	lee_archivo(fin, v); tam = v.size();
	
	for (i = 0; i < tam; i++)
		fout << i*Tintervalo << '\t'
		<< log(g2_resta_1(i*Tintervalo, A, B, C)) / 2 << endl;
	
	fin.close(); fout.close(); fc.close();
	return 0;
}

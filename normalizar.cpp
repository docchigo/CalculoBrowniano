#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

int main() {
	string filename;
	ifstream fin; ofstream fout("datanorm.txt");
	vector<unsigned int> v; unsigned int i, tam;
	
	cout << "Introduzca el nombre del archivo de datos: ";
	getline(cin, filename);
	
	fin.open(filename.c_str());
	if (!fin.is_open()) {
		cout << "Error al abrir el archivo " << filename << endl;
		return 0; 
	}
	lee_archivo(fin, v); tam = v.size();
	
	for (i = 0; i < tam; i++)
		fout << i*Tintervalo << '\t' <<  (double) v[i] / v[tam-1] << endl;
	
	fin.close(); fout.close();
	return 0;
}

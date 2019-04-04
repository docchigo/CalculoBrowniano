#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846264338327950288419716;

int main() {
	ifstream fin("ctesg1.txt");
	  // Suponemos que el índice de refracción es el del agua n1 = 1.3330
	 // que la viscosidad es la del agua 0.890 mPa*s y que
	// la longitud de onda del laser es 620 nm
	double m, n, O, T, q, D0, n1 = 1.3330, landa0 = 620e-9,
	kB = 1.3806488e-23, visc = .890e-3;
	
	fin >> m >> n; fin.close();
	cout << "Introduzca el ángulo (en grados): "; cin >> O;
	O *= PI / 180; // Pasamos el ángulo a radianes
	cout << "Introduzca la temperatura (en ºC): "; cin >> T;
	T += 273.15; // Pasamos la temperatura a grados Kelvin
	
	// Calculamos q
	q = 4*PI*n1/landa0*sin(O/2);
	// Sacamos D0
	D0 = m / q / q;
	// Calculamos el diámetro y lo mostramos por pantalla
	cout << "El diámetro de las partículas calculado es: "
	<<  kB * T / 6 / PI / visc / D0 * 2 << endl;
	
	// Calculamos y mostramos beta
	cout << "El coeficiente experimental beta es: "
	<< exp(2*n) << endl;
	
	return 0;
}

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
	double m, n, m_err, n_err, D, D_err, s,
	O, O_err = PI/180, T, T_err = 1, q, D0, n1 = 1.3330,
	n1_err = 0.0001, landa0 = 620e-9, landa0_err = 1e-9,
	kB = 1.3806488e-23, visc = .890e-3, visc_err = .001e-3;
	
	fin >> m >> n >> m_err >> n_err; fin.close();
	cout << "Introduzca el ángulo (en grados): "; cin >> O;
	O *= PI / 180; // Pasamos el ángulo a radianes
	cout << "Introduzca la temperatura (en ºC): "; cin >> T;
	T += 273.15; // Pasamos la temperatura a grados Kelvin
	
	// Calculamos q
	s = sin(O/2);
	q = 4*PI*n1/landa0*s;
	// Sacamos D0
	D0 = m / q / q;
	// Calculamos el diámetro y lo mostramos por pantalla
	D = kB * T / 6 / PI / visc / D0 * 2;
	D_err = 16 * PI * kB * n1 * s / visc / m / landa0 / landa0
	* sqrt(pow(n1*s*T_err, 2) + pow(T*s*n1_err, 2) +
	pow(T*n1*cos(O/2)*O_err, 2) + pow(T*n1*s, 2)*(pow(visc_err/visc, 2)
	+ pow(m_err/m, 2) + pow(landa0_err/landa0, 2)));
	cout << "El diámetro de las partículas calculado es: "
	<<  D << " +/- " << D_err << endl;
	
	// Calculamos y mostramos beta
	cout << "El coeficiente experimental beta es: "
	<< exp(2*n) << " +/- " << 2*n*exp(2*n)*n_err << endl;
	
	return 0;
}

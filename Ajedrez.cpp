#include <iostream>
using namespace std;
#include "Juego.h";	//#include "Tablero.h";
#include <iomanip>

int main() {
	tJuego juego;
	char c;

	iniciarTablero(juego);
	mostrarTablero(juego.tablero);

	do {
		cout << "Selecciona la pieza" << endl;
		do {
			cin.get(c);
			if (leerTecla(c) != nada && leerTecla(c) != selec && movValido(juego, leerTecla(c))) {
				cambiarSelec(juego, leerTecla(c));
				mostrarTablero(juego.tablero);
				cout << "Selecciona la pieza" << endl;
			}
		} while (leerTecla(c) != selec);
		hacerMovimiento(juego);
		
	} while (juego.estado != terminado);

	if (juego.estado == terminado) {
		mostrarTablero(juego.tablero);
		system("color 9D");
		cout << setw(40) << "FIN" << endl;
	}

	system("pause");

	return 0;
}
#include <iostream>
#include "Tablero.h";
#include <iomanip>
#include <Windows.h>
using namespace std;

//SUBPROGRAMAS PRIVADOS:
bool casilla_libre(const tTablero& tablero, int fila); 
tColorCasilla color_casilla (const tTablero& tablero, int fila, int col);
void pieza_casilla (tJuego& juego, int fila, int col);
//Para conocer el numero del color de la casilla o de la pieza
int casilla_color(const tColorCasilla num);
int pieza_color(const tColorPieza num);
//Para colorear:
void pintarPantalla(int fondo, int texto);




//Carga el tablero:
void iniciarTablero(tJuego& juego) {
	for (int f = 0; f < numero; f++) {
		for (int c = 0; c < numero; c++) {
			juego.tablero[f][c].color = color_casilla(juego.tablero, f, c);
			juego.tablero[f][c].libre = casilla_libre(juego.tablero, f);
			if (!juego.tablero[f][c].libre) {
				pieza_casilla(juego, f, c);
			}
			juego.tablero[f][c].selec = false;
		}
	}
	juego.tablero[6][4].selec = true;
	juego.fila = 6;
	juego.col = 4;

	juego.estado = jugando;
}
//Mostrar el tablero:
void mostrarTablero(const tTablero& tablero) {
	system("cls");
	
	for (int f = 0; f < numero; f++) {
		for (int j = 0; j < 3; j++) {				//Un tercer bucle para el 3x3:
			for (int c = 0; c < numero; c++) {
				for (int i = 0; i < 3; i++) {		//Un cuarto bucle para el 3x3:

					if (tablero[f][c].libre) {
						if (tablero[f][c].selec) {
							pintarPantalla(6, 0);	// un 0, por ejemplo
							cout << "   ";
						}
						else {
							pintarPantalla(casilla_color(tablero[f][c].color), 0); // un 0, por ejemplo
							cout << "   ";
						}
					}
					else {						
						if (tablero[f][c].selec) {
							pintarPantalla(6, pieza_color(tablero[f][c].pieza.color));
							cout << setw(3) << tablero[f][c].pieza.ficha;
						}
						else {
							pintarPantalla(casilla_color(tablero[f][c].color), pieza_color(tablero[f][c].pieza.color));
							cout << setw(3) << tablero[f][c].pieza.ficha;
						}
					}
				}
			}
			cout << endl;
		}
	}
	pintarPantalla(0, 15);	//Pongo de nuevo el fondo negro
}



//SUBPROGRAMAS PRIVADOS:
bool casilla_libre(const tTablero& tablero, int fila) {
	bool libre = true;

	if (fila == 0 || fila == 1 || fila == 6 || fila == 7) {
		libre = false;
	}

	return libre;
}
tColorCasilla color_casilla(const tTablero& tablero, int fila, int col) {
	tColorCasilla colcas = oscuro;
	int num;

	num = (fila + col) % 2;

	if (num == 0) {
		colcas = claro;
	}

	return colcas;
}
void pieza_casilla(tJuego& juego, int fila, int col) {
	//Solo llegará aquí f = 0, 1, 6, 7
	
	switch (fila) {
	case 0:
		juego.tablero[fila][col].pieza.color = negro;
		if (col == 0 || col == 7) {
			juego.tablero[fila][col].pieza.ficha = torre;
		}
		else if(col == 1 || col == 6) {
			juego.tablero[fila][col].pieza.ficha = caballo;
		}
		else if (col == 2 || col == 5) {
			juego.tablero[fila][col].pieza.ficha = alfil;
		}
		else  if (col == 3) {
			juego.tablero[fila][col].pieza.ficha = reina;
		}
		else 
			juego.tablero[fila][col].pieza.ficha = rey;
		break;

	case 1:
		juego.tablero[fila][col].pieza.color = negro;
		juego.tablero[fila][col].pieza.ficha = peon;
		break;

	case 6:
		juego.tablero[fila][col].pieza.color = blanco;
		juego.tablero[fila][col].pieza.ficha = peon;
		break;

	case 7:
		juego.tablero[fila][col].pieza.color = blanco;
		if (col == 0 || col == 7) {
			juego.tablero[fila][col].pieza.ficha = torre;
		}
		else if (col == 1 || col == 6) {
			juego.tablero[fila][col].pieza.ficha = caballo;
		}
		else if (col == 2 || col == 5) {
			juego.tablero[fila][col].pieza.ficha = alfil;
		}
		else  if (col == 3) {
			juego.tablero[fila][col].pieza.ficha = reina;
		}
		else
			juego.tablero[fila][col].pieza.ficha = rey;
		break;

	default: 
		break;
	}

}
int casilla_color(const tColorCasilla num) {
	int color;

	switch (num) {
	case 0:
		color = 1;	//Azul
		break;
		
	case 1:
		color = 3;	//Aguamarina
		break;

	default:
		break;
	}
	
	return color;
}
int pieza_color(const tColorPieza num) {
	int color;

	switch (num) {
	case 0:
		color = 0;	//Negro
		break;

	case 1:
		color = 7;	//Blanco
		break;
		
	default: 
		break;
	}

	return color;
}
void pintarPantalla(int fondo, int texto) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, texto | (fondo << 4));
}
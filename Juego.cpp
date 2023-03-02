#include <iostream>
#include "Juego.h"
using namespace std;

//CABECERAS PRIVADOS:
tMovimientos leerTecla(char c);
void moverPieza(tJuego& juego, tMovimientos move);
void movimientoFicha(tJuego& juego, tMovimientos move);


void cambiarSelec(tJuego& juego, tMovimientos move) {
	switch (move) {
	case arriba:
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.fila--;
		juego.tablero[juego.fila][juego.col].selec = true;
		break;
	case abajo:
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.fila++;
		juego.tablero[juego.fila][juego.col].selec = true;
		break;
	case derecha:
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.col++;
		juego.tablero[juego.fila][juego.col].selec = true;
		break;
	case izquierda:
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.col--;
		juego.tablero[juego.fila][juego.col].selec = true;
		break;
	}
}
bool movValido(const tJuego& juego, tMovimientos move) {
	bool valido = true;

	if (move == arriba && juego.fila == 0) {
		valido = false;
	}
	else if (move == abajo && juego.fila == numero) {
		valido = false;
	}
	else if (move == izquierda && juego.col == 0) {
		valido = false;
	}
	else if (move == derecha && juego.col == numero) {
		valido = false;
	}


	return valido;
}
void hacerMovimiento(tJuego& juego) {
	char move;

	do {
		cout << "Mueve la ficha" << endl;
		cin.get(move);
		movimientoFicha (juego, leerTecla(move));
		moverPieza(juego, leerTecla(move));
		mostrarTablero(juego.tablero);
	} while (move != 'q' && juego.estado != terminado);
}


//PRIVADOS:
tMovimientos leerTecla(char c) {
	tMovimientos move = nada;

	if (c == 'q') {
		move = selec;
	}
	else {
		switch (c) {
		case 'w': move = arriba; break;
		case 's': move = abajo; break;
		case 'd': move = derecha; break;
		case 'a': move = izquierda; break;
		default:  move = nada; break;
		}
	}

	return move;
}
void moverPieza(tJuego& juego, tMovimientos move) {
	switch (move) {
	case arriba:
		juego.tablero[juego.fila - 1][juego.col].pieza.ficha = juego.tablero[juego.fila][juego.col].pieza.ficha;
		juego.tablero[juego.fila - 1][juego.col].pieza.color = juego.tablero[juego.fila][juego.col].pieza.color;
		juego.tablero[juego.fila][juego.col].libre = true;
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.fila--;
		juego.tablero[juego.fila][juego.col].selec = true;
		juego.tablero[juego.fila][juego.col].libre = false;
		break;
	case abajo:
		juego.tablero[juego.fila + 1][juego.col].pieza.ficha = juego.tablero[juego.fila][juego.col].pieza.ficha;
		juego.tablero[juego.fila + 1][juego.col].pieza.color = juego.tablero[juego.fila][juego.col].pieza.color;
		juego.tablero[juego.fila][juego.col].libre = true;
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.fila++;
		juego.tablero[juego.fila][juego.col].selec = true;
		juego.tablero[juego.fila][juego.col].libre = false;
		break;
	case derecha:
		juego.tablero[juego.fila][juego.col + 1].pieza.ficha = juego.tablero[juego.fila][juego.col].pieza.ficha;
		juego.tablero[juego.fila][juego.col + 1].pieza.color = juego.tablero[juego.fila][juego.col].pieza.color;
		juego.tablero[juego.fila][juego.col].libre = true;
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.col++;
		juego.tablero[juego.fila][juego.col].selec = true;
		juego.tablero[juego.fila][juego.col].libre = false;
		break;
	case izquierda:
		juego.tablero[juego.fila][juego.col - 1].pieza.ficha = juego.tablero[juego.fila][juego.col].pieza.ficha;
		juego.tablero[juego.fila][juego.col - 1].pieza.color = juego.tablero[juego.fila][juego.col].pieza.color;
		juego.tablero[juego.fila][juego.col].libre = true;
		juego.tablero[juego.fila][juego.col].selec = false;
		juego.col--;
		juego.tablero[juego.fila][juego.col].selec = true;
		juego.tablero[juego.fila][juego.col].libre = false;
		break;
	}
}
void movimientoFicha(tJuego& juego, tMovimientos move) {
	if (move == arriba && juego.tablero[juego.fila - 1][juego.col].pieza.ficha == rey) {
		juego.estado = terminado;
	}
	else if (move == abajo && juego.tablero[juego.fila + 1][juego.col].pieza.ficha == rey) {
		juego.estado = terminado;
	}
	else if (move == derecha && juego.tablero[juego.fila][juego.col + 1].pieza.ficha == rey) {
		juego.estado = terminado;
	}
	else if (move == izquierda && juego.tablero[juego.fila][juego.col - 1].pieza.ficha == rey) {
		juego.estado = terminado;
	}

}
#include <iostream>
#include "Tablero.h";

using namespace std;

typedef enum {arriba, abajo, derecha, izquierda, nada, selec} tMovimientos;


//CABECERAS:
void cambiarSelec(tJuego& juego, tMovimientos move);
tMovimientos leerTecla(char c);
bool movValido(const tJuego& juego, tMovimientos move);
void hacerMovimiento(tJuego& juego);
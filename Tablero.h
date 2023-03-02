//Constante global del numero de fil y col:
const int numero = 8;
//Para las columnas del tablero:
typedef enum {A, B, C, D, E, F, G, H} tColumna;
//PIEZAS:
typedef enum {torre, caballo, alfil, reina, rey, peon} tFicha;
typedef enum {negro, blanco} tColorPieza;
typedef struct {
	tFicha ficha;
	tColorPieza color;
} tPieza;

//TABLERO::
typedef enum {oscuro, claro} tColorCasilla;
typedef struct {
	tPieza pieza;
	tColorCasilla color;
	bool libre;
	bool selec;
}tCasilla;
typedef tCasilla tTablero[numero][numero];

typedef enum { jugando, jaque, terminado } tEstado;

typedef struct {
	tTablero tablero;
	int fila, col;
	tEstado estado;
} tJuego;


//SUBPROGRAMAS:
void iniciarTablero(tJuego& juego);
void mostrarTablero(const tTablero& tablero);
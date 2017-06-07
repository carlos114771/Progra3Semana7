#include "Tablero.h"
#include "Jugador.h"

#include <string>
#include <vector>
#include <iostream>

#ifndef JUEGO_H
#define JUEGO_H

using namespace std;

class Juego{
	private:
		Tablero* tablero;
		vector<Jugador*> jugadores;
		vector<int> posiciones;
		int turnoActual;
		void leerJugadores();
	public:
		Juego();
		~Juego();
		int jugar();

};

#endif
#include "Juego.h"
#include "Propiedad.h"
#include "Tablero.h"
#include "Print.h"
#include "Tarjetas.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>
using namespace std;

Juego::Juego(){
	tablero = new Tablero();
	turnoActual=1;

}

Juego::~Juego(){
	delete tablero;
	for (int i = 0; i < jugadores.size(); ++i){
		delete jugadores[i];
	}
	//liberar tarjetas

}

void Juego::leerJugadores(){
	ifstream fileJugadores("Jugadores.txt");
	if (fileJugadores.is_open()){
		for (int i = 0; i < 2; ++i){
			Jugador* jugador = new Jugador();
			fileJugadores>>*jugador;
			jugadores.push_back(jugador);
		}
		fileJugadores.close();
	}
}

int Juego::jugar(){
	//inicializar todo
	leerJugadores();
	//inicializar la posicion de los jugadores
	for (int i = 0; i < jugadores.size(); ++i){
		posiciones.push_back(1);
	}
	Print print;
	while(true){
		//determinar turno
		Jugador* jugadorActual=NULL;
		int posicionJugadorActual;
		for (int i = 0; i < jugadores.size(); ++i){
			if(jugadores[i]->getTurno()==turnoActual){
				posicionJugadorActual=i;
				jugadorActual=jugadores[i];
				//mover el turnoActual hacia adentate
				//turnoActual++;	
				(turnoActual + 1 >jugadores.size())?turnoActual=1:turnoActual++;
			}
		}
		//tirar dados
		int resultadoDados;
		resultadoDados=1;
		//mover el jugador de casilla
		int nuevaCasilla =posiciones[posicionJugadorActual]+resultadoDados;	
		if(nuevaCasilla>=tablero->getCantidadCasillas()){
			nuevaCasilla-=tablero->getCantidadCasillas();
		}
		posiciones[posicionJugadorActual]=nuevaCasilla;

		Casillas* casillaActual=tablero->getCasillas(nuevaCasilla);
		if(casillaActual!=NULL){
			cout<<"El Jugador Cayo en: "<<endl;
			print.printCasilla(casillaActual);
			//determinar tipo de casilla
			cin.get();
			if(typeid(*casillaActual)==typeid(Propiedad)){
				Propiedad* propiedad = dynamic_cast<Propiedad*>(casillaActual);
				if(propiedad->estaLibre()){//si esta libre el jugardor compra
					double precio = propiedad->getPrecio();
					if(jugadorActual->getDinero()>precio){//si tiene dinero, compra
						jugadorActual->agregarCasillas(casillaActual);
						jugadorActual->Pagar(precio);
						propiedad->vender();
					}//si tiene dinero
				}//si esta libre
				else{//si no esta libre
					//determinar si es del jugador actual
					bool esDelJugadorActual=false;
					for (int i = 0; i < jugadorActual->getCasillas().size(); ++i){
						if(jugadorActual->getCasillas()[i]==casillaActual){
							esDelJugadorActual=true;

						}
					}
					if(esDelJugadorActual){
						//TODO: acciones de comprar casas / hoteles
					}else{
						//determinar de quien es
						//determila renta
						//double renta= 
						//pagar la renta
					}
				}
			}			
			
			//acciones por casilla

		}

	}
}
		//loop 
		//determinar a quien le toca jugar
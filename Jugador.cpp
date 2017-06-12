#include "Jugador.h"
#include "Propiedad.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;


bool Jugador::hasPropertyMonopoly(Propiedad* prop){
	string color =prop->getColor();
	int contador=0;
	for (int i = 0; i < casillas.size(); ++i){
		Propiedad* contar = dynamic_cast<Propiedad*>(casillas[i]);
		if(contar != NULL){
			//comparar la variable color  el color contar
			if(color.compare(contar->getColor())==0){
				contador++;

			}
		}

	}//contar
	//TODO: completar funcion
	if(contador==3){
		return true;
	}else{
		return false;
	}
}


Jugador::Jugador(){
	//turno=0;
	dinero =1500;
}

int Jugador::getTurno(){
	return turno;
}

void Jugador::agregarCasillas(Casillas* casilla){
	casillas.push_back(casilla);
}

void Jugador::setTurno(int turno){
	this->turno=turno;
}


string Jugador::getPieza(){
	return pieza;
}

void Jugador::setPieza(string pieza){
	this->pieza=pieza;
}


double Jugador::getDinero(){
	return dinero;
}


double Jugador::recibirDinero(double pdinero){
	if (pdinero>0){
		dinero=dinero+pdinero;
	}
	return dinero;
}

void Jugador::Pagar(double pagar){
	if (pagar>0){
		dinero=dinero-pagar;
	}
	
}

vector<Casillas*>& Jugador::getCasillas(){
	return casillas;
}



/*void Jugador::setDinero(double pdinero){
	if(pdinero>0){
		dinero=dinero+pdinero;
	}
	return dinero;
}

void Jugador::Pagar(double pagar){
	if(pagar>0){
		dinero=dinero-pagar;
	}
	return dinero;
}*/
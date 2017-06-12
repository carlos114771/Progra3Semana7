#ifndef JUGADOR_H
#define JUGADOR_H
#include "Casillas.h"
#include "Propiedad.h"
#include "Print.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jugador{
	private:
		friend class Print;
		string pieza;
		vector<Casillas*> casillas;
		double dinero;
		int turno;
		
	public:
		Jugador();//inicializacion
		
		//turno
		void setTurno(int);//t6
		int getTurno();//t6
		string getPieza();//t6
		void setPieza(string);
		void agregarCasillas(Casillas*);//t6

		vector<Casillas*>& getCasillas();
		double getDinero();//t6
		double recibirDinero(double);//t6
		//double Pagar(double);
		void Pagar(double);//t6

		bool hasPropertyMonopoly(Propiedad*);

		friend istream& operator>>(istream& in, Jugador& jugador){
			in>>jugador.pieza;
			in>>jugador.dinero;
			in>>jugador.turno;

			return in;

		}
};
#endif
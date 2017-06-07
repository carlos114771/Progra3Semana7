#ifndef CASILLAS_H
#define CASILLAS_H
#include <string>
using namespace std;


class Casillas{
	protected:
		int posicion;
		string nombre;

	public:
		//nombre 
		string getNombre();
		void setNombre(string);
		//posicion
		int getPosicion();
		void setPosicion(int);


		//determinar si se puede comprar la casilla
		//determinar el tipo de casilla en forma de una string
		/*Propiedad, Ferrocaril, Salida, Carcel, Impuesto, Arca, Casualidad, Libre, Servicios*/
		virtual string getTipo()= 0;

		//dueño
		//precio		
};


#endif
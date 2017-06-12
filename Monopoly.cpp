#include "Casillas.h"
#include "Propiedad.h"
#include "Jugador.h"
#include "Juego.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Tarjetas.h"
#include "TirarDados.h"
#include "Print.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(){

	Juego* juego = new Juego();
	int retval=juego->jugar();
	delete juego;




	/*Casillas* c = new Propiedad();

	//c->vender();

	delete c;

	Jugador* player= new Jugador();

	//cin>>*player;

	//cout<<player->getPieza()<<endl;
	//cout<<player->getTurno()<<endl;
	//delete player;
//prueba de archivos
	ifstream file("Jugadores.txt");
	if(file.is_open()){
		file>>*player;
		file.close();

	}
	//delete player;
	Propiedad* uno;
	Propiedad* dos;
	uno=new Propiedad();
	dos=new Propiedad();
	ifstream casillasFile("Casillas.txt");
	if(casillasFile.is_open()){
		casillasFile>>*uno;
		casillasFile>>*dos;
		casillasFile.close();
	}

	cout<<uno->getNombre()<<endl<<uno->getColor()<<endl<<dos->getNombre()<<endl<<dos->getColor()<<endl;


	//cout<<"Pieza: "<<player->getPieza()<<endl;
	//cout<<"Dinero: "<<player->getDinero()<<endl;
	delete player;
	delete uno;
	delete dos;
*/
	return 0;
}
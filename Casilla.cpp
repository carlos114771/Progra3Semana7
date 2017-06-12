#include <string>
#include "Casillas.h"
#include <iostream>

using namespace std;

int Casillas::getPosicion(){
	return posicion;
}

void Casillas::setPosicion(int pos){
	posicion=pos;
}

string Casillas::getNombre(){
	return nombre;
}

void Casillas::setNombre(string name){
	nombre = name;
}


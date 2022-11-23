

#include <iostream>
#include "GeneroFile.h"
using namespace std;

int main() {

	

	GeneroFile * f = new GeneroFile("Gen.gn");

	f->abrir();




	f->agregarGenero(new Genero("Rock", ""));
	f->agregarGenero(new Genero("Jazz", ""));
	f->agregarGenero(new Genero("Blues", ""));

	f->Escribir();
	f->cerrar();


	delete f;


}
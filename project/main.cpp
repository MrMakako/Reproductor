

#include <iostream>
#include "GeneroFile.h"

#include "SongInfoFile.h"
using namespace std;


int main() {

	

//	GeneroFile * f = new GeneroFile("Gen.gn");
	SongInfoFile* s = new SongInfoFile();
	
	//f->abrir();
	s->abrir();

	s->GuardarCancion( SongInfo("Back in Blac","Hell","AC/DC","BackInBlac.mp3",1));




	
                   // str1 == "Jane,GoodbyeWorld!"


//	f->agregarGenero(new Genero(" ", ""));

//	f->agregarGenero(new Genero("Jazz", ""));
//	f->agregarGenero(new Genero("Blues", ""));
	s->escribir();

	s->leer();
	///f->Escribir();
	//s->escribir();

	//f->Leer();
	//f->cerrar();
	s->cerrar();

	while (true);
	//delete f;


}
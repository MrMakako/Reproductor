#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Genero.h"
#include "TDAArchivo.h"
#include <vector>

#include <fstream> 
using namespace std;
#ifndef GENERO_FILE_H
#define GENERO_FILE_H
class GeneroFile :public TDAArchivo {

protected:
	vector<Genero> ListaGeneros;


public:


	GeneroFile();

	GeneroFile(std::string Ruta);

	vector<Genero*> generos;
	string dato = "";


	//Metodos Heredados
	void escribir();

	void leer();
	 bool Escribir();
	 bool Leer();
	//Metodo de clase para agregar genero
	bool agregarGenero(Genero*);
	bool EliminarGenero(Genero*);
	bool modificarGenero(Genero*);


private:

	int SIZE_NOMBRE = 20;





};
#endif // !GENERO_FILE_H


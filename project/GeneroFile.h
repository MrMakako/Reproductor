#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Genero.h"
#include "TDAArchivo.h"
#include <fstream> 
using namespace std;

class GeneroFile:public TDAArchivo{

private:
	vector<Genero> ListaGeneros;


public:


	GeneroFile();

	GeneroFile(std::string Ruta);



	void escribir() override;
	void leer() override;





};
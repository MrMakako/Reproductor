//
// Created by Corra on 11/14/2022.
//


#include "TDAArchivo.h"


TDAArchivo::TDAArchivo() {

	Nombre_Archivo= "";
	
}
TDAArchivo::TDAArchivo(const char* Nombre)
{


	Nombre_Archivo = Nombre;




}
void TDAArchivo::cerrar() {
	
	Archivo.close();
	if (Archivo.is_open()) {
		cout << "El Archivo se cerro!!!\n";
	}


}

void TDAArchivo::abrir() {


	Archivo = fstream(Nombre_Archivo.c_str(), ios::in);
	Archivo.open(Nombre_Archivo.c_str(),ios::in);
	if (Archivo.is_open()) {
		cout << "Archivo Encontrado!\n";

	}
	else {
		cout << "No se eonctro o no se pudo abrir el archivo!!!\n";


		Archivo = fstream(Nombre_Archivo.c_str(), ios::out);
		Archivo.close();
	}




}

std::string TDAArchivo::RemoveSpaces(std::string data)
{
	string NewData = "";
	for (int i = 0; i < data.size(); i++) {
		if (data[i] != ' ') {
		
			NewData += data[i];
		}
	
	}

	return NewData;
}

string TDAArchivo::TruncarDatoCode(string Dato, int Size)
{

	Dato.insert(0, Size - Dato.size(), '0');
	return Dato.substr(0, Size);
}

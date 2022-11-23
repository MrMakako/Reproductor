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

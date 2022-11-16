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
	if (!Archivo.is_open()) {
		cout << "El Archivo se cerro!!!\n";
	}
	 

}

void TDAArchivo::abrir() {


	Archivo = fstream(Nombre_Archivo, ios::in);
	if (Archivo) {
		cout << "Archivo Encontrado!\n";

	}




}

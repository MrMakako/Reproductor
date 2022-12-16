#include "GeneroFile.h"

GeneroFile::GeneroFile():TDAArchivo("Gen.gn")
{
//	GeneroFile("Gen.gn");


}

GeneroFile::GeneroFile(std::string Nombre_Archivo) :TDAArchivo(Nombre_Archivo.c_str())
{


	


}

void GeneroFile::escribir()
{
}

void GeneroFile::leer()
{
}

bool GeneroFile::Escribir()
{

	Archivo = fstream(Nombre_Archivo.c_str(),ios::out);
	if (Archivo.is_open()) {
		
		//necsitamos buffer	
		string buffer;
			//En el buffer se guarda todo lo que se va a guardar en el disco//
		//tamano del buffer
		

		for (int i = 0; i < generos.size(); i++) {
			
			Genero* _genero= dynamic_cast<Genero*>( generos[i]);
			if (_genero) {

				dato = generos[i]->getNombre();
				
				string dato_truncado = dato.substr(0, SIZE_NOMBRE);

				dato_truncado.append(SIZE_NOMBRE - dato_truncado.size(),' ');
				buffer += dato_truncado;

			
			}
			


		
		}


		Archivo.write(buffer.data(), buffer.size());
		Archivo.close();
	
	
		return true;
	

	
	}
	else {
	
	}
	return false;

}

bool GeneroFile::Leer()
{
	cerrar();
	ifstream Archivo;
	Archivo.open(Nombre_Archivo);

	if (!Archivo.is_open()) {
		cout << "No se pudo leer";
		return false;
	}

	generos.clear();
	cout << "se pudo leer";
	//Este codifgo se usa para leer por bloques dado, algunos algoritmos generan errores de escritura entre computadores
	//Este es el metodo mas seguro pero menos eficiente....usar char * buffer=new char[20]; intruduce caracteres erroneos sobrepasando
	//la capacidad del buffer dependiendo la computadora.
	vector<char> buffer(20, 0);
	int i = 0;
	cout << "Estos son los Generos\n";
	while (Archivo.read(&buffer[0], SIZE_NOMBRE)) {
	
		//Obtner el nombre
		//Limpiamos
		dato = "";
		for (int i = 0; i < buffer.size();i++) {
			if (buffer[i] != ' ') {
				dato += buffer[i];
			}
			
		}


		
		cout <<"Index:" <<i<<"-" << dato << "-" << endl;
		i++;



	
	
	
	
	}


	Archivo.close();



	return true;

	//Leer





}

bool GeneroFile::agregarGenero(Genero* genero)
{
	generos.push_back(genero);

	return false;
}

string GeneroFile::ObtenerGenero(int index)
{


	cerrar();
	ifstream Archivo;
	Archivo.open(Nombre_Archivo);

	if (!Archivo.is_open()) {
		cout << "No se pudo leer funcion obetner genero!!\n";
		return"";
	}

	generos.clear();
	cout << "se pudo leer";
	//Este codifgo se usa para leer por bloques dado, algunos algoritmos generan errores de escritura entre computadores
	//Este es el metodo mas seguro pero menos eficiente....usar char * buffer=new char[20]; intruduce caracteres erroneos sobrepasando
	//la capacidad del buffer dependiendo la computadora.
	vector<char> buffer(SIZE_NOMBRE, 0);
	int i = 0;
	cout << "Estos son los Generos\n";
	Archivo.seekg(SIZE_NOMBRE * index);
	//Nos posicionamos en el bloque queremos leer de forma que no tnemos que iterar genero por genero.
	if (Archivo.read(&buffer[0], SIZE_NOMBRE)) {

		//Obtner el nombre
		//Limpiamos
		dato = "";
		for (int i = 0; i < buffer.size(); i++) {
			if (buffer[i] != ' ') {
				dato += buffer[i];
			}

		}

		return dato;







	}
	


	Archivo.close();
	//Siempre se debe cerrar el archivo;


	return "";

	return generos[index]->getNombre();



}

bool GeneroFile::EliminarGenero(Genero*)
{
	return false;
}

bool GeneroFile::modificarGenero(Genero*)
{
	return false;
}

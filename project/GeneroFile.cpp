#include "GeneroFile.h"

GeneroFile::GeneroFile()
{
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


	Archivo = fstream(Nombre_Archivo.c_str(), ios::out);
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
				dato_truncado.append(SIZE_NOMBRE - dato_truncado.size(), ' ');
				buffer += dato_truncado;

			
			}
			


		
		}


		Archivo.write(buffer.data(), buffer.size());
	
	
		return true;
	

	
	}
	else {
	
	}
	return false;

}

bool GeneroFile::Leer()
{
	cerrar();
	(Archivo.open(Nombre_Archivo, ios::in));

	if (!Archivo.is_open()) {
		cout << "No se pudo leer";
		return false;
	}

	generos.clear();
	cout << "se pudo leer";
	char* buffer=new char[SIZE_NOMBRE];
	while (Archivo.read(buffer,SIZE_NOMBRE)) {
	
		//Obtner el nombre

	
		dato = buffer;
		dato=boost::trim_right_copy(dato);
		cout << "Estos son los datos recolectados\n";
		cout <<"-" << dato << "-" << endl;
		



	
	
	
	
	}






	return true;

	//Leer





}

bool GeneroFile::agregarGenero(Genero* genero)
{
	generos.push_back(genero);

	return false;
}

bool GeneroFile::EliminarGenero(Genero*)
{
	return false;
}

bool GeneroFile::modificarGenero(Genero*)
{
	return false;
}

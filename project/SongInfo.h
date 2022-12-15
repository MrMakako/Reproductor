#pragma once
#include "Genero.h"
using namespace std;
class SongInfo
{

public:
	SongInfo();
	SongInfo(string nombre,string Disco,string Artista,string Ruta,int genIndex);
	void setNombre(std::string _Nombre);
	void setRuta(const char* _Ruta);
	void setArtista(std::string _Artista);
	void setDisco(std::string _Disco);
	
	std::string getNombre();
	std::string getDisco();
	std::string getArtista();
	std::string getGenIndex();

	Genero getGenero();
	const char* getRuta();


private:
	//Para almacenar el nombre,Disco,Artista, y ruta haremos un hastable con un int y guardarremos archivos individuales....
	//Puesto que no hay limites para cada cancion solo necesario leer el codigo
	std::string Nombre;
	std::string Disco;
	std::string Artista;
	std::string Ruta;
	int GenIndex;
	//El genero de la cancion es el unico que tendra un registro fijo



	




};
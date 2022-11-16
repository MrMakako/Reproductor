#pragma once
#include "Genero.h"
class SongInfo:public Genero
{

public:
	SongInfo();
	void setNombre(std::string _Nombre);
	void setRuta(const char* _Ruta);
	void setArtista(std::string _Artista);
	void setDisco(std::string _Disco);
	
	std::string getNombre();
	std::string getDisco();
	std::string getArtista();
	const char* getRuta();


private:
	std::string Nombre;
	std::string Disco;
	std::string Artista;
	std::string Ruta;

	




};


#include "SongInfo.h"

SongInfo::SongInfo()
{
	Disco = "";
	Nombre = "";
	Artista = "";
	//Ruta = nullptr;
}

SongInfo::SongInfo(string nombre, string Disco, string Artista, string Ruta, int genIndex)
{
	this->Nombre = nombre;
	this->Artista = Artista;
	this->Disco = Disco;
	this->Ruta = Ruta;
	this->GenIndex = genIndex;
	
}

void SongInfo::setNombre(std::string _Nombre)
{	

}

void SongInfo::setRuta(const char* _Ruta)
{
}

void SongInfo::setArtista(std::string _Artista)
{
}

void SongInfo::setDisco(std::string _Disco)
{
}

std::string SongInfo::getNombre()
{
	return Nombre;
}

std::string SongInfo::getDisco()
{
	return Disco;
}

std::string SongInfo::getArtista()
{
	return Artista;
}

std::string SongInfo::getGenIndex()
{
	return std::to_string(GenIndex);
}

Genero SongInfo::getGenero()
{
	return Genero();
}

const char* SongInfo::getRuta()
{
	return Ruta.c_str();
}




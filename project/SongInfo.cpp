#include "SongInfo.h"

SongInfo::SongInfo()
{
	Disco = "";
	Nombre = "";
	Artista = "";
	//Ruta = nullptr;
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

const char* SongInfo::getRuta()
{
	return Ruta.c_str();
}

#pragma once
#ifndef PLAYLISTFILE_H
#define PLAYLISTFILE_H
#include"Playlist.h"
#include <boost/filesystem.hpp>
#include <filesystem>

#include "SongInfo.h"
#include "TDAArchivo.h"

using namespace boost::filesystem;
class PlaylistFile:public Playlist,public TDAArchivo
{

private:
	string PlayListName;
	vector<SongInfo*> SongQueue;

	vector<int> canciones;
	int sizeRegis = 10;
public:
	PlaylistFile();

	~PlaylistFile();
	void CrearPlaylist(string Nombre);
	void AgregarCanciones();
	void MostrarPlaylists();

	string ObtenerPlayListDir(int index);

	void escribir() override;
	void leer() override;
};

#endif // !PLAYLISTFILE_H
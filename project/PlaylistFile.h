#pragma once
#ifndef PLAYLISTFILE_H
#define PLAYLISTFILE_H
#include"Playlist.h"
#include "TDAArchivo.h"
class PlaylistFile:public Playlist,public TDAArchivo
{
public:
	PlaylistFile();
	~PlaylistFile();
	void escribir() override;
	void leer() override;
};

#endif // !PLAYLISTFILE_H
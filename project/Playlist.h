#pragma once
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <vector>
#include "SongInfo.h"
//#include "SongInfo.h"

using namespace std;
using std::vector;

class Playlist :public SongInfo
{
private:
	string nombre;
public:
	Playlist();
	~Playlist();
	//vector <SongInfo> TDAlist;
	void setNombre(string);
	string getNombre();
};

#endif // !PLAYLIST_H
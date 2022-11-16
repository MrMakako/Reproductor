#include <fstream>
#include "SongInfoFile.h"

using namespace std;

std::vector <SongInfo> *SongInfoFile::readFile(string fileName) {
/*   ifstream file;
    file.open(fileName);
    string line;
    TDAList <SongInfo> *list = new TDAList<SongInfo>;
    while (getline(file, line)) {
        SongInfo *songInfo = new SongInfo;
        readSongInfo(line, songInfo);
        list->add(*songInfo);
    }
    file.close();
    return list;*/
    return nullptr;
}

void SongInfoFile::writeFile(string fileName, std::vector <SongInfo> *list) {
   /* ofstream file;
    file.open(fileName);
    for (int i = 0; i < list->getSize(); i++) {
        SongInfo songInfo = list->get(i);
        file << songInfo.getSongName() << "," << songInfo.getDisc() << "," << songInfo.getArtist() << ","
             << songInfo.getGenre() << "," << songInfo.getRutaMp3() << endl;
    }
    file.close();*/
    
}

void SongInfoFile::readSongInfo(string line, SongInfo *songInfo) {
 /*   int pos = 0;
    string songName = line.substr(pos, line.find(",", pos) - pos);
    pos = line.find(",", pos) + 1;
    string disc = line.substr(pos, line.find(",", pos) - pos);
    pos = line.find(",", pos) + 1;
    string artist = line.substr(pos, line.find(",", pos) - pos);
    pos = line.find(",", pos) + 1;
    string genre = line.substr(pos, line.find(",", pos) - pos);
    pos = line.find(",", pos) + 1;
    string rutaMp3 = line.substr(pos, line.find(",", pos) - pos);
    songInfo->setSongName(songName);
    songInfo->setDisc(disc);
    songInfo->setArtist(artist);
    songInfo->setGenre(genre);
    songInfo->setRutaMp3(rutaMp3);
    */
}

void SongInfoFile::escribir()
{
}

void SongInfoFile::leer()
{
}



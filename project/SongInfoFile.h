#ifndef ESTRUCTURADEDATOS_LL_SONGINFOFILE_H
#define ESTRUCTURADEDATOS_LL_SONGINFOFILE_H

#include <vector>
#include "SongInfo.h"
#include <string>
#include"TDAArchivo.h"
#include "SongInfo.h"
using namespace std;
class SongInfoFile:public SongInfo ,public TDAArchivo{
    // Tipo registro
public:
    std::vector <SongInfo> *readFile(string fileName);
    void writeFile(string fileName, std::vector<SongInfo> *list);
    void readSongInfo(string line, SongInfo *songInfo);
    void escribir() override;
    void leer() override;
};


#endif //ESTRUCTURADEDATOS_LL_SONGINFOFILE_H

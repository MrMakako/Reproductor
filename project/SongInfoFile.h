#ifndef ESTRUCTURADEDATOS_LL_SONGINFOFILE_H
#define ESTRUCTURADEDATOS_LL_SONGINFOFILE_H

#include <vector>
#include "SongInfo.h"
#include <string>
#include"TDAArchivo.h"
#include "GeneroFile.h"
#include "SongInfo.h"




using namespace std;
class SongInfoFile:public SongInfo ,public TDAArchivo{




    // Tipo registro tamano fijo con hash table de tamano variable//
private:
    GeneroFile genero_file;
    string ObtenerArtista();
    string ObtenerDisco();
    string ObtenerNombre();
    const char* ObtenerRuta();
    int REGIS_SIZE = 30;
    int GEN_CODE = 10;
    int MAX_SIZE = 130;
    
    
    //Indice que nos dice donde se ubica el genero asi evitamos leer todo el archivo//

    vector<SongInfo> ListaCanciones;
    std::string TruncarDato(std::string dato, int Size);

  //  std::string TruncarDatoCode(std::string Dato, int Size);

public:
    std::vector <SongInfo> *readFile(string fileName);
    void writeFile(string fileName, std::vector<SongInfo> *list);
    void readSongInfo(string line, SongInfo *songInfo);
    void escribir() override;
    void GuardarCancion(SongInfo Cancion);
    SongInfo ObtenerSongInfo(int index);
  

    void leer() override;
    SongInfoFile();
};


#endif //ESTRUCTURADEDATOS_LL_SONGINFOFILE_H

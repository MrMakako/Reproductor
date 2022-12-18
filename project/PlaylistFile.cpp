#include "PlaylistFile.h"
#include "SongInfoFile.h"

PlaylistFile::PlaylistFile() {
}

PlaylistFile::~PlaylistFile() {
}

void PlaylistFile::escribir()
{
    Archivo = fstream(Nombre_Archivo.c_str(), ios::out);
    if (Archivo.is_open()) {
        //necsitamos buffer	
        string buffer;
        string Dato;
        //En el buffer se guarda todo lo que se va a guardar en el disco//
    //tamano del buffer
        for (int i = 0; i < canciones.size(); i++) {
            Dato = TruncarDatoCode(to_string(canciones[i]), sizeRegis);
            buffer.append(Dato);
        }
        Archivo.write(buffer.data(), buffer.size());
        Archivo.close();
    }
    else {

    }
}

void PlaylistFile::leer()
{
    cerrar();
    ifstream Archivo;
    string dato;
    SongInfoFile sngi = SongInfoFile();
    Archivo.open(Nombre_Archivo);

    if (!Archivo.is_open()) {
        cout << "No se pudo leer!!!\n";
    }
    canciones.clear();
    int i = 0;
    vector<char> buffer(sizeRegis, 0);
    while (Archivo.read(&buffer[0], sizeRegis)) {
        dato = "";
        for (int i = 0; i < buffer.size(); i++) {
            dato += buffer[i];
        }
        sngi.ObtenerSongInfo(stoi(dato));
        cout << sngi.getArtista();
        i++;
    }
    Archivo.close();
}

void PlaylistFile::CrearPlaylist(string Nombre)
{
}

void PlaylistFile::AgregarCanciones(string FileDir)
{
}


#include "SongInfoFile.h"

using namespace std;

string SongInfoFile::ObtenerArtista()
{
    return string();

}

string SongInfoFile::ObtenerDisco()
{
    return string();
}

string SongInfoFile::ObtenerNombre()
{
    return string();
}

const char* SongInfoFile::ObtenerRuta()
{
    return nullptr;
}

std::string SongInfoFile::TruncarDato(std::string Dato, int Size)
{
  
    string dato_truncado = Dato.substr(0,Size);
    dato_truncado.append(Size - dato_truncado.size(), ' ');
    return dato_truncado;
}


std::vector <SongInfo> *SongInfoFile::readFile(string fileName) {

    return nullptr;

}

void SongInfoFile::writeFile(string fileName, std::vector <SongInfo> *list) {
 
    
}

void SongInfoFile::readSongInfo(string line, SongInfo *songInfo) {

}

void SongInfoFile::escribir()
{

    Archivo = fstream(Nombre_Archivo.c_str(), ios::out);
    if (Archivo.is_open()) {

        //necsitamos buffer	
        string buffer;
        string Dato;
        //En el buffer se guarda todo lo que se va a guardar en el disco//
    //tamano del buffer


        for (int i = 0; i < ListaCanciones.size(); i++) {
            //Evaluamos que sea una cancion
            SongInfo* _Song = dynamic_cast<SongInfo*>(&ListaCanciones[i]);
            if (_Song) {
                //Primero registremos
                buffer += TruncarDato(ListaCanciones[i].getRuta(), REGIS_SIZE);
                buffer += TruncarDato(ListaCanciones[i].getNombre(), REGIS_SIZE);
                buffer += TruncarDato(ListaCanciones[i].getArtista(), REGIS_SIZE);
                buffer += TruncarDato(ListaCanciones[i].getDisco(), REGIS_SIZE);
                buffer += TruncarDatoCode(ListaCanciones[i].getGenIndex(),GEN_CODE);
                //Registramos el index de genero//
              

                //buffer += 
                 //El ulimo tregistor que se agrega al buffer es el index de genero.
            


            }




        }


        Archivo.write(buffer.data(), buffer.size());
        Archivo.close();


     



    }
    else {

    }


    


}

void SongInfoFile::GuardarCancion(SongInfo Cancion)
{

    ListaCanciones.push_back(Cancion);



}

SongInfo SongInfoFile::ObtenerSongInfo(int index)
{
    cerrar();
    ifstream Archivo;
    string dato;
    Archivo.open(Nombre_Archivo);

    if (!Archivo.is_open()) {
        cout << "No se pudo leer!!!\n";

    }

    ListaCanciones.clear();
    cout << "se pudo leer\n";
    //Este codifgo se usa para leer por bloques dado, algunos algoritmos generan errores de escritura entre computadores
    //Este es el metodo mas seguro pero menos eficiente....usar char * buffer=new char[20]; intruduce caracteres erroneos sobrepasando
    //la capacidad del buffer dependiendo la computadora.
    vector<char> buffer(MAX_SIZE,0);
    GeneroFile* gen_F = new GeneroFile();
    gen_F->abrir();
    SongInfo Song;
    int i = 0;
    Archivo.seekg(index*MAX_SIZE);
    if (Archivo.read(&buffer[0], MAX_SIZE)) {

        //Obtner el nombre
        //Limpiamos
        dato = "";
        for (int i = 0; i < buffer.size(); i++) {
            //  if (buffer[i] != ' ') {
            dato += buffer[i];
            //` }

        }
        //Vamos a contruir un songIngo//--//--//--//--//--//-//-//-//-//-//\\//\\//\\


        string A_Nombre=dato.substr(REGIS_SIZE,REGIS_SIZE*2);
        string A_FileDir = dato.substr(0, REGIS_SIZE);
        string A_Disco = dato.substr(REGIS_SIZE * 3, REGIS_SIZE * 4);
        string A_Artista = dato.substr(REGIS_SIZE * 2, REGIS_SIZE * 3);
        string A_Genero = dato.substr(MAX_SIZE-GEN_CODE, REGIS_SIZE + GEN_CODE);

        Song = SongInfo(A_Nombre,A_Disco,A_Artista,A_FileDir,std::stoi(A_Genero));
        

/ 

    //    cout << dato.substr(0, MAX_SIZE - GEN_CODE) << "Genero:" << << endl;
        i++;







    }

    gen_F->cerrar();
    Archivo.close();



    return SongInfo();
}

void SongInfoFile::leer()
{
    cerrar();
    ifstream Archivo;
    string dato;
    Archivo.open(Nombre_Archivo);

    if (!Archivo.is_open()) {
        cout << "No se pudo leer!!!\n";
      
    }

    ListaCanciones.clear();
    cout << "se pudo leer\n";
    //Este codifgo se usa para leer por bloques dado, algunos algoritmos generan errores de escritura entre computadores
    //Este es el metodo mas seguro pero menos eficiente....usar char * buffer=new char[20]; intruduce caracteres erroneos sobrepasando
    //la capacidad del buffer dependiendo la computadora.
    vector<char> buffer(MAX_SIZE, 0);
    GeneroFile* gen_F = new GeneroFile();
    gen_F->abrir();

    int i = 0;
 
    while (Archivo.read(&buffer[0],MAX_SIZE)) {

        //Obtner el nombre
        //Limpiamos
        dato = "";
        for (int i = 0; i < buffer.size(); i++) {
          //  if (buffer[i] != ' ') {
                dato += buffer[i];
           // }

        }
        string GenIndex=dato.substr(MAX_SIZE-GEN_CODE,MAX_SIZE);

        string gen=gen_F->ObtenerGenero(std::stoi(GenIndex));


        cout << dato.substr(0,MAX_SIZE-GEN_CODE)<<"Genero:"<<gen << endl;
        i++;







    }

    gen_F->cerrar();
    Archivo.close();
    




}

SongInfoFile::SongInfoFile()
{

    Nombre_Archivo = "SongRegis.sr";
    ListaCanciones = vector<SongInfo>();
    genero_file = GeneroFile();
}



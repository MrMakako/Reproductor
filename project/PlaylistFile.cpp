#include "PlaylistFile.h"
#include "SongInfoFile.h"

PlaylistFile::PlaylistFile() {
    Nombre_Archivo = "PlayListsRegis";
}

PlaylistFile::~PlaylistFile() {
}

void PlaylistFile::escribir()
{
    Archivo = fstream(PlayListName.c_str(), ios::out);
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
    Archivo = fstream(Nombre_Archivo+"/"+Nombre+".ply", ios::out | ios::app);
    if (Archivo.is_open()) {

        //necsitamos buffer	
        string buffer="";
        //En el buffer se guarda todo lo que se va a guardar en el disco//
    //tamano del buffer


    


        Archivo.write(buffer.data(), buffer.size());

        Archivo.close();






    }
    else {

        Archivo.write("", 0);

        Archivo.close();

    }
  





}

void PlaylistFile::AgregarCanciones()
{
    //Varaibles
    string dir="";
    int codigo = 0;
    int codigo2 = 0;
    int res = 0;
    SongInfoFile * sng= new SongInfoFile();
    //Entradas
    cout << "Elija una playlist: \n";
    MostrarPlaylists();

    cout << "Codigo>>";
  
    cin >> codigo;
     
    dir = ObtenerPlayListDir(codigo);


        string buffer = "";
        sng->abrir();
        sng->leer();
        sng->cerrar();
        //Entrada para canciones//
        while (true) {
            cout << "Ingrese codigo de cancion>>";
            cin >> codigo2;
            canciones.push_back( codigo2);
            cout << "1.Agregar Otra Cancion\n";
            cin >> res;
            if (res != 1) {
                break;


            }
        }
        PlayListName = dir;
        abrir();
        escribir();
        cerrar();




}

void PlaylistFile::MostrarPlaylists()
{
    int i = 0;
    directory_iterator end_itr;
    //github repo @https://gist.github.com/vivithemage/9517678
    //Ese codigo nos permite iterar entre earhivos en este caso con playlis;
    for (boost::filesystem::directory_iterator itr(Nombre_Archivo); itr !=end_itr ; ++itr)
    {
        // If it's not a directory, list it. If you want to list directories too, just remove this check.
        if (is_regular_file(itr->path())) {
            // assign current file name to current_file and echo it out to the console.
            string current_file = itr->path().string().substr(Nombre_Archivo.length()+1,itr->path().string().length());
            cout <<"Codigo: " << i <<"-----" << current_file << endl;
            i++;
        }
    }
}

string PlaylistFile::ObtenerPlayListDir(int index)
{
    //Para encontrar las playlist iteramos el indice la busqueda es algo tardada si lo hacemos de esta forma
    //podiramos indicarle al usuairo q esepcifique el nombre de modo que la  busqueda seria muchismo mas corta
    //otra opcionseri aguardar un cache de los nombres de estas playlist para q al seleccionar un indice el programa la busque.
    //Esto mas precision y tiempo  a costa de un poco mas de espacio.
    directory_iterator end_itr;
    int i = 0;

    for (boost::filesystem::directory_iterator itr(Nombre_Archivo); itr != end_itr; ++itr)
    {
        // If it's not a directory, list it. If you want to list directories too, just remove this check.
        if (is_regular_file(itr->path())) {
            // assign current file name to current_file and echo it out to the console.
            string current_file = itr->path().string();
            if (i == index) {
                cout << "Agregando a :" << current_file<<"\n";

                return current_file;
                
            }
            i++;
    
        }
       
    }
   

    return "";
}

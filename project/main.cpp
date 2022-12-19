

#include "GeneroFile.h"

#include "SongInfoFile.h"
#include "PlaylistFile.h"
using namespace std;


int main() {

    // Variables
    int opcion;
    int opcion2;
    string nextSong;
    string pauseSong;
    string previousSong;
    string nameGenre;
    //Principales accesos a los registros
    GeneroFile* regisGenero = new GeneroFile("Gen.gn");
    SongInfoFile* regisSong = new SongInfoFile();
    PlaylistFile* regisPlaylist = new PlaylistFile();
    regisPlaylist->escribir();
    regisPlaylist->cerrar();
    
    do {
        cout << "Reproductor de musica" << endl;
        cout << "1. Generos" << endl;
        cout << "2. Canciones" << endl;
        cout << "3. Playlists" << endl;
        cout << "4. Reproducir" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Generos" << endl;
            cout << "1. Agregar genero" << endl;
            cout << "2. Listar generos" << endl;
            cout << "3. Regresar" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;
            switch (opcion) {
            case 1:
                cout << "Agregar genero" << endl;
                cout << "Ingrese el nombre del genero: ";
                cin >> nameGenre;

                regisGenero->abrir();
                regisGenero->agregarGenero(new Genero(nameGenre, ""));
                regisGenero->escribir();
                regisGenero->cerrar();
                

            case 2:
                cout << "Listar generos" << endl;
                regisGenero->abrir();
                regisGenero->leer();
                regisGenero->cerrar();
                break;
            case 3:
                cout << "Regresando" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
            }
            break;
        case 2:
            cout << "Canciones" << endl;
            cout << "1. Agregar cancion" << endl;
            cout << "2. Listar canciones" << endl;
            cout << "3. Regresar" << endl;
            cout << "Ingrese una opcion>> ";
            cin >> opcion2;
            switch (opcion2)
            {
            case 1: {
                int genero;
                string nombre;
                string ruta;
                string album;
                string artista;
                string Disco;
                cout << "Agregar cancion" << endl;

                cout << "Ruta>>";
                cin.clear();
                getline(std::cin>>std::ws, ruta);
                cout << "Nombre>>";
                getline(std::cin >> std::ws,nombre);
                cin.clear();

                cout << "Disco>>";
                getline(std::cin >> std::ws, Disco);
   
                cout << "Artista>>";
                getline(cin>>ws, artista);
                regisGenero->abrir();
                regisGenero->leer();
                regisGenero->cerrar();
                cout << "Genero>>";
                cin >> genero;





                regisSong->abrir();
                regisSong->GuardarCancion(SongInfo(nombre, Disco, artista, ruta, genero));
                regisSong->escribir();

                break;

            
            }case 2: {

                cout << "Listar canciones" << endl;
                regisSong->abrir();
                regisSong->leer();
                regisSong->cerrar();
                break;
            
            }case 3: {
                cout << "Regresando" << endl;
                break;
            
            }
            default:
                cout << "Opcion invalida" << endl;
                break;
            }
            break;
        case 3:
            cout << "Playlists" << endl;
            cout << "1. Crear playlist" << endl;
            cout << "2. Agregar cancion" << endl;
            cout << "3. Regresar" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;
            switch (opcion) {
            case 1: {
                cout << "Agregar playlist" << endl;
                string nombre;
                cout << "Nombre>>";
                cin >> nombre;
                regisPlaylist->CrearPlaylist(nombre);
                break; 
            }
            case 2: {
                cout << "Agregar cancion" << endl;
                regisPlaylist->AgregarCanciones();
                break;
            }
            case 3: {
                cout << "Regresando" << endl;
                break;
            }
            default: {
                cout << "Opcion invalida" << endl;
                break;
            }
            }
            break;
        case 4:
            cout << "Reproduciendo" << endl;
            //Aqui hay que mostrar las playlist 

            break;
        case 5:
            cout << "Saliendo" << endl;
            cout << "Gracias por usar el reproductor de musica" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (opcion != 5);
   
	
	


}
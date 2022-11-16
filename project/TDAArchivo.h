//
// Created by Corra on 11/14/2022.
//

#ifndef MP3_TDAARCHIVO_H
#define MP3_TDAARCHIVO_H

#include "string"
#include <iostream>
#include "fstream"
using namespace std;



class TDAArchivo {

    
    protected:


        char* data;
        int size;
        std::string Nombre_Archivo;
        fstream Archivo;


    public:
        TDAArchivo();
        TDAArchivo(const char* Nombre_Archivo);
        void cerrar();
        void abrir();
        virtual void escribir() = 0;
        virtual void leer() = 0;
};


#endif //MP3_TDAARCHIVO_H

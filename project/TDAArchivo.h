//
// Created by Corra on 11/14/2022.
//

#ifndef MP3_TDAARCHIVO_H
#define MP3_TDAARCHIVO_H

#include "string"
#include <iostream>
#include "fstream"
#include"I_CodeReader.h"
using namespace std;



class TDAArchivo:public I_CodeReader{

    
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
        /// <summary>
        /// //
        /// </summary>
        /// <param name="data"></param>
        /// <returns></returns>

        std::string RemoveSpaces(std::string data);
        string TruncarDatoCode(string Dato, int Size);
        //Esta funcion sera principalmente usada para todas los registros
        virtual void escribir() = 0;
        virtual void leer() = 0;
};


#endif //MP3_TDAARCHIVO_H

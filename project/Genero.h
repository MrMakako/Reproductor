//
// Created by Corra on 11/14/2022.
//

#ifndef MP3_GENERO_H
#define MP3_GENERO_H

#include "string"




class Genero  {

    private:
        std::string nombre;

   //     std::string descripcion;

    public:
       
        Genero(std::string nombre, std::string descripcion);
        Genero();
        std::string getNombre();
     /*  
   
        std::string getDescripcion();
        void setNombre(std::string nombre);
        void setDescripcion(std::string descripcion);

        std::string toString() override;
        bool equals(Object* _object);
        */
};


#endif //MP3_GENERO_H

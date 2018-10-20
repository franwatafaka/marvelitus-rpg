#ifndef CLSPERSONAJES_H
#define CLSPERSONAJES_H

#include <clsSprite.h>


class clsPersonajes : public clsSprite
{
    public:
        //Metodo para iniciar Sprites de Personajes
        int iniciar(char const *ruta[10],int);
        //Setter y Getter Vida
        void setVida(int);
        int getVida();
        //Setter y Getter Daño
        void setDanio(int);
        int getDanio();
        //Setter y Getter Activo
        void setActivo(bool);
        bool getActivo();
        //Constructor Personajes
        clsPersonajes();
        //Destructor Personajes
        ~clsPersonajes();

    protected:
        void inherit(){};

    private:
        int vida;
        int danio;
        bool activo;
};

#endif // CLSPERSONAJES_H

#ifndef CLSPERSONAJE_H
#define CLSPERSONAJE_H

#include <clsSprite.h>
#include <clsEvent.h>
#include <clsFondo.h>
#include "rutasRecursos.h"

class clsPersonaje : public clsSprite
{
public:
    void inherit() {};
    //Metodo para iniciar Sprites de Personajes
    int iniciar(char const * const ruta[],int);
    //Metodo para animar al personaje
    int animar(clsScreen *, tDireccion, clsFondo *);
    //Setter y Getter Vida
    void setVida(int);
    int getVida();
    //Setter y Getter Daño
    void setDanio(int);
    int getDanio();
    //Setter y Getter Activo
    void setActivo(bool);
    bool getActivo();

protected:
    clsScreen *pantalla;
    clsEvent *evento;
    int vida;
    int danio;
    bool activo;
    clsFondo *fondoActual;
    int pasos = 0;

};

#endif // CLSPERSONAJE_H

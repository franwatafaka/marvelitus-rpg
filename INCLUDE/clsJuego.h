#ifndef CLSJUEGO_H
#define CLSJUEGO_H
//--------------------------Includes--------------------------------------------
#include <clsMode.h>
#include <clsEvent.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
#include <clsAudio.h>
#include <clsSoundEffect.h>
#include <clsMusic.h>
#include <clsTimer.h>
#include <clsImagenes.h>
#include "clsPersonajes.h"
//------------------------------------------------------------------------------

class clsJuego
{
public:
    //Metodo para Iniciar Modulo Despedida
    int iniciar(clsScreen*, clsEvent*);
    //Metodo para Correr Modulo Despedida
    int correr();
    //Metodo para manejarEventos del teclado
    int accionTeclado(bool*, Uint16);
    //Metodo para Refrescar cada Ciclo
    void refrescarXciclo();

protected:
    //Objeto Pantalla
    clsScreen *pantalla;
    //Objeto Evento
    clsEvent *evento;
    //Objeto Error
    clsError error;
    //Objeto Fondo
    clsFondo fondo;
    //Objeto Music
    clsMusic musicaMenu;
    //Objeto Timer
    clsTimer tiempo;
    //Objeto Imagenes
    clsImagenes imagen;
    //Objeto Personaje
    clsPersonajes capitanAmerica,dareDevil,ironMan,spiderMan,starLord,thor,
    ronan,enemigos[25];
};

#endif // CLSJUEGO_H

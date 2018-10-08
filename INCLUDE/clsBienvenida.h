#ifndef CLSBIENVENIDA_H
#define CLSBIENVENIDA_H
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
//------------------------------------------------------------------------------

class clsBienvenida
{
    public:
        //Metodo para Iniciar Modulo Bienvenida
        int iniciar(clsScreen*, clsEvent*);
        //Metodo para Correr Modulo Bienvenida
        int correr();
        //Metodo para manejarEventos del teclado
        int accionTeclado(bool*, Uint16);

    protected:
        //Objeto Pantalla
        clsScreen *pantalla;
        //Objeto Evento
        clsEvent *evento;
        //Objeto Error
        clsError error;
        //Objeto fondo
        clsFondo fondo;
        //Objeto Musica
        clsMusic musicaBienvenida;
        //Objeto Timer
        clsTimer tiempo;
};

#endif // CLSBIENVENIDA_H

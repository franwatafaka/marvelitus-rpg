#ifndef CLSMOTOR_H
#define CLSMOTOR_H
//--------------------------Includes ADN-x--------------------------------------
#include <clsMode.h>
#include <clsEvent.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
//--------------------------Includes Programa-----------------------------------
#include "clsBienvenida.h"
#include "clsDespedida.h"
#include "clsJuego.h"
//------------------------------------------------------------------------------

class clsMotor
{
    public:
        //Metodo para Iniciar Motor
        int iniciar();
        //Metodo para Correr Motor
        int correr();
        //Metodo para manejarEventos del teclado
        int accionTeclado(bool*, Uint16);
    private:
        //Objeto de la clase Event
        clsEvent evento;
        //Objeto de la clase Error
        clsError error;
        //Objeto de la clase Mode
        clsMode modoGrafico;
        //Objeto de la clase Screen
        clsScreen pantalla;
        //Objeto de la clase Bienvenida
        clsBienvenida bienvenida;
        //Objeto de la clase Despedida
        clsDespedida despedida;
        //Objeto de la clase Juego
        clsJuego juego;
};

#endif // CLSMOTOR_H

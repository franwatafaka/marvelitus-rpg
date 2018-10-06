#ifndef CLSJUEGO_H
#define CLSJUEGO_H
//--------------------------Includes--------------------------------------------
#include <clsEvent.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
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
        //Objeto fondo
        clsFondo fondo;
};

#endif // CLSJUEGO_H

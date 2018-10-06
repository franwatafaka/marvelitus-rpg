#ifndef CLSDESPEDIDA_H
#define CLSDESPEDIDA_H
//--------------------------Includes--------------------------------------------
#include <clsEvent.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsFondo.h>
//------------------------------------------------------------------------------

class clsDespedida
{
    public:
        //Metodo para Iniciar Modulo Despedida
        int iniciar(clsScreen*, clsEvent*);
        //Metodo para Correr Modulo Despedida
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
    private:
};

#endif // CLSDESPEDIDA_H

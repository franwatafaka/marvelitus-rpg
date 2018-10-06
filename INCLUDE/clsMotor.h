#ifndef CLSMOTOR_H
#define CLSMOTOR_H

#include <clsError.h>
#include <clsEvent.h>
#include <clsScreen.h>
#include <clsMode.h>
#include <adnConsts.h>

class clsMotor
{
    public:
        //Metodo para Iniciar Motor
        int iniciar();
        //Metodo para Correr Motor
        int correr();
        //Metodo para manejarEventos del teclado
        int accionTeclado(bool*, Uint16);

    protected:

    private:
        //Objeto de la clase Event
        clsEvent evento;
        //Objeto de la clase Error
        clsError error;
        //Objeto de la clase Mode
        clsMode modoGrafico;
        //Objeto de la clase Screen
        clsScreen pantalla;
};

#endif // CLSMOTOR_H

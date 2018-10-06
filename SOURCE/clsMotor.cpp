#include "clsMotor.h"

//Metodo para Iniciar Motor
int clsMotor::iniciar()
{
    //Modo Grafico
    error.set(modoGrafico.init(1280,720,32));
    if(error.get())
    {
        return error.get();
    }
    //Pantalla
    error.set(pantalla.init(modoGrafico.getScrWidth(),
    modoGrafico.getScrHeight(),modoGrafico.getScrDepth(),DISABLED,FULLSCREEN));
    if(error.get())
    {
        return error.get();
    }
    return error.get();
}
//Metodo para Correr Motor
int clsMotor::correr()
{
    error.set(0);
    bool salir=false;
    pantalla.clean(GRAY);
    pantalla.refresh();
    while(!salir)
    {
        if(evento.wasEvent())
        {
            if(evento.getEventType() == KEY_PRESSED)
            {
                error.set(accionTeclado(&salir,evento.getKey()));
                if(error.get())
                {
                    return error.get();
                }
            }
        }
    }
    return error.get();
}
//Metodo para manejarEventos del teclado
int clsMotor::accionTeclado(bool* salir, Uint16 tecla)
{
    error.set(0);
    switch(tecla)
    {
    case KEY_ESCAPE:
        {
            *salir = true;
        }
    break;
    }
    return error.get();
}

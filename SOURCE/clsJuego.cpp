#include "clsJuego.h"


//Metodo para Iniciar Modulo Juego
int clsJuego::iniciar(clsScreen* pantalla, clsEvent* evento)
{
    error.set(0);
    this->pantalla = pantalla;
    this->evento = evento;
    error.set(fondo.iniciar());
    if(error.get())
    {
        return error.get();
    }
    cout << "Carga Fondo Juego" << endl;
    fondo.setJuego();
    return error.get();
}

//Metodo para Correr Modulo Juego
int clsJuego::correr()
{
    error.set(0);
    bool salir=false;
    pantalla->clean(BLUE);
    fondo.paste(pantalla->getPtr());
    pantalla->refresh();
    while(!salir)
    {
        if(evento->wasEvent())
        {
            if(evento->getEventType() == KEY_PRESSED)
            {
                error.set(accionTeclado(&salir,evento->getKey()));
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
int clsJuego::accionTeclado(bool* salir, Uint16 tecla)
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


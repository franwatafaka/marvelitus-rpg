#include "clsBienvenida.h"

//Metodo para Iniciar Modulo Bienvenida
int clsBienvenida::iniciar(clsScreen* pantalla, clsEvent* evento)
{
    error.set(0);
    this->pantalla = pantalla;
    this->evento = evento;
    error.set(fondo.iniciar());
    if(error.get())
    {
        return error.get();
    }
    cout << "Carga Fondo Bienvenida" << endl;
    fondo.setBienvenida();
    return error.get();
}

//Metodo para Correr Modulo Bienvenida
int clsBienvenida::correr()
{
    error.set(0);
    bool salir=false;
    pantalla->clean(BLACK);
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
int clsBienvenida::accionTeclado(bool* salir, Uint16 tecla)
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

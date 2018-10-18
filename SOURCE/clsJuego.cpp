#include "clsJuego.h"


//Metodo para Iniciar Modulo Juego
int clsJuego::iniciar(clsScreen* pantalla, clsEvent* evento)
{
    error.set(0);
    this->pantalla = pantalla;
    this->evento = evento;
    error.set(fondo.iniciar());
    error.set(imagen.iniciar());
    if(error.get())
    {
        return error.get();
    }
    error.set(musicaMenu.loadMusic("RESOURCES/SOUNDS/MUSIC/02-Game_Intro.mp3"));
    if(error.get())
    {
        return error.get();
    }
    fondo.setMenu();
    imagen.setMenuPrincipal();
    return error.get();
}

//Metodo para Correr Modulo Juego
int clsJuego::correr()
{
    error.set(0);
    bool salir=false;
    pantalla->clean(BLACK);
    fondo.paste(pantalla->getPtr());
    imagen.paste(pantalla->getPtr());
    pantalla->refresh();
    //Musica de Menu principal
    musicaMenu.playMusic(-1);
    //Inicio del cronometro de tiempo
    tiempo.start();
    while(!salir)
    {
        //Reviso cronomoetro de tiempo
        tiempo.update();
        //Si el tiempo es igual a 1:41
        if(tiempo.getState()== 141000)
        {
            musicaMenu.stopMusic();
            salir = true;
        }
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
    case KEY_W:
        {
            *salir = true;
        }
    break;
    case KEY_S:
        {
            *salir = true;
        }
    break;
    }
    return error.get();
}


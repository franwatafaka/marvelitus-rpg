#include "clsBienvenida.h"
char jug_1[] = "RESOURCES/IMAGES/SPRITES/CHARACTERS/Captain_America_Editable.png";

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
    error.set(musicaBienvenida.loadMusic("RESOURCES/SOUNDS/MUSIC/01-Credits_Intro.mp3"));
    if(error.get())
    {
        return error.get();
    }
    fondo.setBienvenida();
    error.set(jugadores[0].iniciar(jug_1,1));
    if(error.get())
    {
        return error.get();
    }
    return error.get();
}

//Metodo para Correr Modulo Bienvenida
int clsBienvenida::correr()
{
    error.set(0);
    bool salir=false;
    pantalla->clean(BLACK);
    fondo.paste(pantalla->getPtr());
    jugadores[0].paste(pantalla->getPtr());
    pantalla->refresh();
    musicaBienvenida.playMusic(-1);
    tiempo.start();
    while(!salir)
    {
        tiempo.update();
        if(tiempo.getState()== 22000)
        {
            musicaBienvenida.stopMusic();
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
int clsBienvenida::accionTeclado(bool* salir, Uint16 tecla)
{
    error.set(0);
    switch(tecla)
    {
    case KEY_ESCAPE:
        {
            musicaBienvenida.stopMusic();
            *salir = true;
        }
    break;
    }
    return error.get();
}
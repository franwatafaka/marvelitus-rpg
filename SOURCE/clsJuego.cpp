#include "clsJuego.h"
#include "../INCLUDE/rutasSprites.h"

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
    error.set(capitanAmerica.iniciar(capitanAmericaSprites,10));
    if(error.get())
    {
        return error.get();
    }
    error.set(dareDevil.iniciar(dareDevilSprites,10));
    if(error.get())
    {
        return error.get();
    }
    error.set(ironMan.iniciar(ironManSprites,10));
    if(error.get())
    {
        return error.get();
    }
    error.set(spiderMan.iniciar(spiderManSprites,10));
    if(error.get())
    {
        return error.get();
    }
    error.set(starLord.iniciar(starLordSprites,10));
    if(error.get())
    {
        return error.get();
    }
    error.set(thor.iniciar(thorSprites,10));
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
    //Capitan America en Pantalla
    capitanAmerica.setI(8);
    capitanAmerica.setPosX(0);
    capitanAmerica.setPosY(0);
    capitanAmerica.paste(pantalla->getPtr());
    //Dare Devil en Pantalla
    dareDevil.setI(8);
    dareDevil.setPosX(200);
    dareDevil.setPosY(0);
    dareDevil.paste(pantalla->getPtr());
    //Iron_Man en Pantalla
    ironMan.setI(8);
    ironMan.setPosX(400);
    ironMan.setPosY(0);
    ironMan.paste(pantalla->getPtr());
    pantalla->refresh();
    //Spider_Man en Pantalla
    spiderMan.setI(8);
    spiderMan.setPosX(600);
    spiderMan.setPosY(0);
    spiderMan.paste(pantalla->getPtr());
    pantalla->refresh();
    //Star_Lord en Pantalla
    starLord.setI(8);
    starLord.setPosX(800);
    starLord.setPosY(0);
    starLord.paste(pantalla->getPtr());
    pantalla->refresh();
    //Thor en Pantalla
    thor.setI(8);
    thor.setPosX(1000);
    thor.setPosY(0);
    thor.paste(pantalla->getPtr());
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


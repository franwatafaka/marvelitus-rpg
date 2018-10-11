#include "clsFondo.h"

int clsFondo::iniciar()
{
    error.set(0);
    setItems(3);
    //Fondo Presentacion
    setI(0);
    error.set(load("RESOURCES/IMAGES/BACKGROUNDS/presentacion.png"));
    if(error.get())
    {
        return error.get();
    }
    //Fondo Despedida
    setI(1);
    error.set(load("RESOURCES/IMAGES/BACKGROUNDS/despedida.png"));
    if(error.get())
    {
        return error.get();
    }
    //Fondo Presentacion
    setI(2);
    error.set(load("RESOURCES/IMAGES/BACKGROUNDS/main_menu.png"));
    if(error.get())
    {
        return error.get();
    }
    setX(0);
    setY(0);
    return error.get();
}

void clsFondo::setBienvenida()
{
    setI(0);
    cout << "Carga Indice Fondo Bienvenida" << endl;
}

void clsFondo::setDespedida()
{
    setI(1);
    cout << "Carga Indice Fondo Despedida" << endl;
}
void clsFondo::setJuego()
{
    setI(2);
    cout << "Carga Indice Fondo Juego" << endl;
}

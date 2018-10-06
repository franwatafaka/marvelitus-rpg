#include "clsFondo.h"

int clsFondo::iniciar()
{
    error.set(0);
    setItems(2);
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
    setX(0);
    setY(0);
    return error.get();
}

void clsFondo::setBienvenida()
{
    setI(0);
    cout << "Fondo Bienvenida" << endl;
}

void clsFondo::setDespedida()
{
    setI(1);
    cout << "Fondo Despedida" << endl;
}

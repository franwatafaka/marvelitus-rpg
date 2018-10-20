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
    return error.get();
}

void clsFondo::setBienvenida()
{
    setI(0);
    setX(0);
    setY(0);
    cout << "Carga Indice Fondo Bienvenida" << endl;
}

void clsFondo::setDespedida()
{
    setI(1);
    setX(0);
    setY(0);
    cout << "Carga Indice Fondo Despedida" << endl;
}
void clsFondo::setMenu()
{
    setI(2);
    setX(0);
    setY(0);
    cout << "Carga Indice Fondo Menu" << endl;
}

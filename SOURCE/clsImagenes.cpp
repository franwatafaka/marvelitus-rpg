#include "clsImagenes.h"

int clsImagenes::iniciar()
{
    error.set(0);
    setItems(1);
    //Imagen Flecha Derecha
    setI(0);
    error.set(load("RESOURCES/IMAGES/SPRITES/CONTEXT/menu_test.png"));
    if(error.get())
    {
        return error.get();
    }
    setX(500);
    setY(360);
    return error.get();
}

void clsImagenes::setMenuPrincipal()
{
    setI(0);
    cout << "Carga Imagen Menu Principal" << endl;
}

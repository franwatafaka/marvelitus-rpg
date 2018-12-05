#include "clsFondo.h"
#include "../INCLUDE/rutasRecursos.h"

int clsFondo::iniciar(clsScreen * screen)
{
    //Pantalla de fondo igual al puntero de pantalla motor
    pantalla = screen;
    //
    error.set(0);
    setItems(16);
    //
    for(int z=0; z<16; z++)
    {
        setI(z);
        error.set(load(vectorFdo[z]));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
        cout << "Carga fondo " << z  << endl;
    }

    //Ubicacion en Pantalla
    setX(0);
    setY(0);

    return error.get();
}

#include "clsFondo.h"
#include "../INCLUDE/rutasRecursos.h"

int clsFondo::iniciar(clsScreen * screen)
{
    //Pantalla de fondo igual al puntero de pantalla motor
    pantalla = screen;
    //
    setItems(16);
    //
    setI(0);
    error.set(load(fondoDeBienvenida));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(1);
    error.set(load(fondoDeMenu));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(2);
    error.set(load(fondoDeHistoria));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(3);
    error.set(load(fondoDeCapitanAmerica));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(4);
    error.set(load(fondoDeDareDevil));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(5);
    error.set(load(fondoDeIronMan));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(6);
    error.set(load(fondoDeSpiderMan));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(7);
    error.set(load(fondoDeStarLord));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(8);
    error.set(load(fondoDeThor));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(9);
    error.set(load(fondoDeNivel_1));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(10);
    error.set(load(fondoDeNivel_2));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(11);
    error.set(load(fondoDeNivel_3));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(12);
    error.set(load(fondoDeEscenaFinalGana));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(13);
    error.set(load(fondoDeDespedida));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(14);
    error.set(load(fondoDeSeleccionPersonajes));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //
    setI(15);
    error.set(load(fondoDeEscenaFinalPierde));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //Ubicacion en Pantalla
    setX(0);
    setY(0);

    return error.get();
}

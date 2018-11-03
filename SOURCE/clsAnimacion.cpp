#include "clsAnimacion.h"
#include "../INCLUDE/rutasRecursos.h"

//
int clsAnimacion::iniciarCapi()
{
    setItems(30);

    error.set(0);
    //--------------------------------------------------------------------------

    for(int x=0; x<30; x++)
    {
        setI(x);
        error.set(load(spritesAnimacionCapi[x]));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
    }
    setI(0);
    setX(640);
    setY(530);

    //--------------------------------------------------------------------------
    return error.get();
}

//
int clsAnimacion::iniciarDare()
{
    setItems(30);

    error.set(0);
    //--------------------------------------------------------------------------

    for(int x=0; x<30; x++)
    {
        setI(x);
        error.set(load(spritesAnimacionDare[x]));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
    }
    setI(0);
    setX(640);
    setY(530);

    //--------------------------------------------------------------------------
    return error.get();
}

//
int clsAnimacion::iniciarIron()
{
    setItems(30);

    error.set(0);
    //--------------------------------------------------------------------------

    for(int x=0; x<30; x++)
    {
        setI(x);
        error.set(load(spritesAnimacionIron[x]));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
    }
    setI(0);
    setX(640);
    setY(530);

    //--------------------------------------------------------------------------
    return error.get();
}

//
int clsAnimacion::iniciarSpider()
{
    setItems(30);

    error.set(0);
    //--------------------------------------------------------------------------

    for(int x=0; x<30; x++)
    {
        setI(x);
        error.set(load(spritesAnimacionSpider[x]));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
    }
    setI(0);
    setX(640);
    setY(530);

    //--------------------------------------------------------------------------
    return error.get();
}

//
int clsAnimacion::iniciarStar()
{
    setItems(30);

    error.set(0);
    //--------------------------------------------------------------------------

    for(int x=0; x<30; x++)
    {
        setI(x);
        error.set(load(spritesAnimacionStar[x]));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
    }
    setI(0);
    setX(640);
    setY(530);

    //--------------------------------------------------------------------------
    return error.get();
}

//
int clsAnimacion::iniciarThor()
{
    setItems(30);

    error.set(0);
    //--------------------------------------------------------------------------

    for(int x=0; x<30; x++)
    {
        setI(x);
        error.set(load(spritesAnimacionThor[x]));
        if(error.get())
        {
            error.show(true);
            return error.get();
        }
    }
    setI(0);
    setX(640);
    setY(530);

    //--------------------------------------------------------------------------
    return error.get();
}

//
int clsAnimacion::play(clsScreen * screen)
{
    //--------------------------------------------------------------------------
    pantalla = screen;
    contador++;
    paste(pantalla->getPtr());
    pantalla->refresh();
    if(getI() == 29)
    {
        setI(0);
        setX(640);
    }
    else if(getI() < 15)
    {
        if(contador == 10)
        {
            setI(getI()+1);
            setX(getX()+5);
            contador=0;
        }
    }
    else
    {
        if(contador == 10)
        {
            setI(getI()+1);
            setX(getX()-5);
            contador=0;
        }

    }
    //--------------------------------------------------------------------------
    return error.get();
}

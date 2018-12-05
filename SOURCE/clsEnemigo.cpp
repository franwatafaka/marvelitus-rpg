#include "clsEnemigo.h"

const char * const spritesEnemigo[10] =
{
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/00.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/01.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/02.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/03.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/04.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/05.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/06.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/07.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/08.png",
    "RESOURCES/IMAGES/SPRITES/CHARACTERS/ENEMIGO/09.png"
};

int clsEnemigo::init( clsScreen *s)
{
    pantalla =  s;
    error.set(0);
    setItems(9);
    //Sprite personaje
    for(int u=0; u<10; u++)
    {
        setI(u);
        error.set(load(spritesEnemigo[u]));
        cout << "Carga spriteEnemigo " << u << endl;
        if(error.get()){ return error.get();}
    }
    setI(0);
    setX(850);
    setY(500);
    return error.get();
}

int clsEnemigo::animar(clsScreen *pantalla, tDireccion teclaPres, clsFondo *fondo )
{
    error.set(0);

    switch(teclaPres)
    {
    case QUIETO:
    {
        this->setI(0);
        this->setX(this->getX());
        this->setY(this->getY());
        pasos = 0;
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());

    }
    break;
    case ARRIBA:
    {
        if(this->getY() < 310)
        {
            this->setY(310);
        }
        this->setI(this->getI());
        this->setX(this->getX());
        this->setY(this->getY()-10);
        if(pasos < 3)
        {
            setI(0);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(1);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(0);
            pasos = 0;
        }
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
    }
    break;
    case DERECHA:
    {
        if(this->getX() > 1110)
        {
            this->setX(1110);
        }
        this->setI(this->getI());
        this->setX(this->getX()+10);
        this->setY(this->getY());
        if(pasos < 3)
        {
            setI(5);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(6);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(5);
            pasos = 0;
        }
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
    }
    break;
    case ABAJO:
    {
        if(this->getY() > 500)
        {
            this->setY(500);
        }
        this->setI(this->getI());
        this->setX(this->getX());
        this->setY(this->getY()+10);
        if(pasos < 3)
        {
            setI(0);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(1);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(0);
            pasos = 0;
        }
    }
    break;
    case IZQUIERDA:
    {
        if(this->getX() < 20)
        {
            this->setX(20);
        }
        this->setI(this->getI());
        this->setX(this->getX()-10);
        this->setY(this->getY());
        if(pasos < 3)
        {
            setI(0);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(1);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(0);
            pasos = 0;
        }
    }
    break;
    case DS_DER:
    {
        if(this->getY() < 310)
        {
            this->setY(310);
        }
        if(this->getX() > 1110)
        {
            this->setX(1110);
        }
        this->setI(this->getI());
        this->setX(this->getX()+10);
        this->setY(this->getY()-10);
        if(pasos < 3)
        {
            setI(5);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(6);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(5);
            pasos = 0;
        }
    }
    break;
    case DS_IZQ:
    {
        if(this->getY() < 310)
        {
            this->setY(310);
        }
        if(this->getX() < 20)
        {
            this->setX(20);
        }
        this->setI(this->getI());
        this->setX(this->getX()-10);
        this->setY(this->getY()-10);
        if(pasos < 3)
        {
            setI(0);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(1);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(0);
            pasos = 0;
        }
    }
    break;
    case DI_DER:
    {
        if(this->getY() > 500)
        {
            this->setY(500);
        }
        if(this->getX() > 1110)
        {
            this->setX(1110);
        }
        this->setI(this->getI());
        this->setX(this->getX()+10);
        this->setY(this->getY()+10);
        if(pasos < 3)
        {
            setI(6);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(5);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(6);
            pasos = 0;
        }
    }
    break;
    case DI_IZQ:
    {
        if(this->getY() > 500)
        {
            this->setY(500);
        }
        if(this->getX() < 20)
        {
            this->setX(20);
        }
        this->setI(this->getI());
        this->setX(this->getX()-10);
        this->setY(this->getY()+10);
        if(pasos < 3)
        {
            setI(0);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(1);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(0);
            pasos = 0;
        }
    }
    break;
    case ATACA_C:
    {
        for(int v=0; v<4; v++)
        {
            this->setI(2);
            this->setX(this->getX());
            this->setY(this->getY());
        }
        this->setI(3);
        this->setX(this->getX());
        this->setY(this->getY());
    }
    break;
    case ATACA_L:
    {
        for(int v=0; v<4; v++)
        {
            this->setI(7);
            this->setX(this->getX());
            this->setY(this->getY());
        }
        this->setI(8);
        this->setX(this->getX());
        this->setY(this->getY());
    }
    break;
    case DEFIENDE:
    {
        this->setI(4);
        this->setX(this->getX());
        this->setY(this->getY());
        if(evento->wasEvent())
        {
            this->setI(0);
            this->setX(this->getX());
            this->setY(this->getY());
        }
    }
    break;
    }

    return error.get();
}

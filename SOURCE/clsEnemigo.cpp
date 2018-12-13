#include "clsEnemigo.h"
#include "../INCLUDE/rutasRecursos.h"

int clsEnemigo::init( clsScreen *s )
{
    pantalla =  s;
    error.set(0);
    setItems(10);
    //Sprite personaje
    for(int u=0; u<10; u++)
    {
        setI(u);
        error.set(load(spritesEnemigo[u]));
        cout << "Carga spriteEnemigo " << u << endl;
        if(error.get())
        {
            return error.get();
        }
    }
    setI(0);
    setX(850);
    setY(500);
    return error.get();
}

int clsEnemigo::animar(clsScreen *pantalla, clsFondo *fondo, clsPersonaje *oPersonaje)
{
    cout<< "Entre a animar" << endl;
    error.set(0);
    Uint16 teclaPres;
    teclaPres = QUIETO;


    if(posX > 1100 || ( posX > 1100 && !this->getContact(oPersonaje) ) )
    {

            posX--;
        teclaPres = IZQUIERDA;
        cout << "IZQUIERDA" << endl;

    }
     if( posX < 1100 || (posX < 1100 && !this->getContact(oPersonaje)))
    {
        posX++;
        teclaPres = DERECHA;
        cout << "DERECHA" << endl;


    }
    if( this->getContact(oPersonaje) )
    {

        cout<<" ataca "<<endl;
        teclaPres = ATACA_C;
        cout << "ataca atacaaa" << endl;
    }









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
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
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
    case IZQUIERDA:
    {
        if(this->getX() < 20)
        {
            this->setX(20);
        }
        this->setI(this->getI());
        this->setX(this->getX()-10);
        this->setY(this->getY());
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
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
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
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
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
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
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
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
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
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
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
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
    case ATACA_C:
    {
        this->setI(3);
        this->setX(this->getX());
        this->setY(this->getY());
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
    }
    break;
    case ATACA_L:
    {
        this->setI(7);
        this->setX(this->getX());
        this->setY(this->getY());
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
    }
    break;
    case DEFIENDE:
    {
        this->setI(4);
        this->setX(this->getX());
        this->setY(this->getY());
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());
        if(evento->wasEvent())
        {
            this->setI(0);
            this->setX(this->getX());
            this->setY(this->getY());
            fondo->paste(pantalla->getPtr());
            this->paste(pantalla->getPtr());
        }
    }
    break;
    }


    return error.get();
}

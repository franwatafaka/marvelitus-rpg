#include "clsPersonaje.h"

//Metodo para iniciar Personajes
int clsPersonaje::iniciar(char const * const ruta[10], int sprites)
{
    error.set(0);
    setItems(9);
    //Sprite personaje
    for(int x = 0; x<10; x++)
    {
        setI(x);
        error.set(load(ruta[x]));
        cout << "Carga inicializacion personaje " << x << endl;
        if(error.get()){return error.get();}
    }

    setI(0);
    setX(5);
    setY(500);
    return error.get();
}

//Metodo para animar al personaje
int clsPersonaje::animar(clsScreen *screen, tDireccion direction,clsFondo *fondo)
{
    error.set(0);
    pantalla = screen;
    fondoActual = fondo;

    switch(direction)
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
        if(pasos < 3)
        {
            setI(2);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(3);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(2);
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
            setI(2);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(3);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(2);
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
            setI(2);
            pasos++;
        }
        else if(pasos >= 3 && pasos < 6)
        {
            setI(3);
            pasos++;
        }
        else if(pasos == 6)
        {
            setI(2);
            pasos = 0;
        }
        fondo->paste(pantalla->getPtr());

        this->paste(pantalla->getPtr());

    }
    break;
    case ATACA_C:
    {
        for(int v=0; v<4; v++)
        {
            this->setI(4);
            this->setX(this->getX());
            this->setY(this->getY());
            fondo->paste(pantalla->getPtr());
            this->paste(pantalla->getPtr());

        }
        this->setI(0);
        this->setX(this->getX());
        this->setY(this->getY());
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());

    }
    break;
    case ATACA_L:
    {
        for(int v=0; v<4; v++)
        {
            this->setI(5);
            this->setX(this->getX());
            this->setY(this->getY());
            fondo->paste(pantalla->getPtr());
            this->paste(pantalla->getPtr());

        }
        this->setI(0);
        this->setX(this->getX());
        this->setY(this->getY());
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());

    }
    break;
    case DEFIENDE:
    {
        this->setI(8);
        this->setX(this->getX());
        this->setY(this->getY());
        fondo->paste(pantalla->getPtr());
        this->paste(pantalla->getPtr());

        if(evento->wasEvent())
        {
            this->setI(8);
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

//Setter y Getter Vida
void clsPersonaje::setVida(int vida)
{
    this->vida = vida;
}
int clsPersonaje::getVida()
{
    return vida;
}
//Setter y Getter Daño
void clsPersonaje::setDanio(int danio)
{
    this->danio = danio;
}
int clsPersonaje::getDanio()
{
    return danio;
}
//Setter y Getter Activo
void clsPersonaje::setActivo(bool activo)
{
    this->activo = activo;
}
bool clsPersonaje::getActivo()
{
    return activo;
}

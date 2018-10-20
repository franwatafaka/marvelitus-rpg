#include "clsPersonajes.h"

//Metodo para iniciar Personajes
int clsPersonajes::iniciar(char const *ruta[10], int sprites)
{
    error.set(0);

    setItems(sprites);
    //Sprite personaje
    setI(0);
    error.set(load(ruta[0]));
    setX(0);
    setY(0);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(1);
    error.set(load(ruta[1]));
    setX(10);
    setY(10);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(2);
    error.set(load(ruta[2]));
    setX(20);
    setY(20);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(3);
    error.set(load(ruta[3]));
    setX(30);
    setY(30);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(4);
    error.set(load(ruta[4]));
    setX(40);
    setY(40);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(5);
    error.set(load(ruta[5]));
    setX(50);
    setY(50);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(6);
    error.set(load(ruta[6]));
    setX(60);
    setY(60);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(7);
    error.set(load(ruta[7]));
    setX(70);
    setY(70);
    if(error.get())
    {
        return error.get();
    }
    //
    setI(8);
    setX(1280);
    setY(500);
    error.set(load(ruta[8]));
    if(error.get())
    {
        return error.get();
    }
    //
    setI(9);
    error.set(load(ruta[9]));
    setX(90);
    setY(90);
    if(error.get())
    {
        return error.get();
    }

    return error.get();
}
//Setter y Getter Vida
void clsPersonajes::setVida(int vida)
{
    this->vida = vida;
}
int clsPersonajes::getVida()
{
    return vida;
}
//Setter y Getter Daño
void clsPersonajes::setDanio(int danio)
{
    this->danio = danio;
}
int clsPersonajes::getDanio()
{
    return danio;
}
//Setter y Getter Activo
void clsPersonajes::setActivo(bool activo)
{
    this->activo = activo;
}
bool clsPersonajes::getActivo()
{
    return activo;
}
//Constructor Personajes
clsPersonajes::clsPersonajes()
{

}

//
clsPersonajes::~clsPersonajes()
{

}

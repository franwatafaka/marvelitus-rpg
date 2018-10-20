#include "clsPersonajes.h"

//Metodo para iniciar Personajes
int clsPersonajes::iniciar(char* ruta, int sprites)
{
    error.set(0);
    setItems(sprites);
    //Sprite personaje
    setI(0);
    error.set(load(&ruta[0]));
    if(error.get())
    {
        return error.get();
    }
    setX(0);
    setY(0);
    return error.get();
    //
    setI(1);
    error.set(load(&ruta[1]));
    if(error.get())
    {
        return error.get();
    }
    setX(10);
    setY(10);
    return error.get();
    //
    setI(2);
    error.set(load(&ruta[2]));
    if(error.get())
    {
        return error.get();
    }
    setX(20);
    setY(20);
    return error.get();
    //
    setI(3);
    error.set(load(&ruta[3]));
    if(error.get())
    {
        return error.get();
    }
    setX(30);
    setY(30);
    return error.get();
    //
    setI(4);
    error.set(load(&ruta[4]));
    if(error.get())
    {
        return error.get();
    }
    setX(40);
    setY(40);
    return error.get();
    //
    setI(5);
    error.set(load(&ruta[5]));
    if(error.get())
    {
        return error.get();
    }
    setX(50);
    setY(50);
    return error.get();
    //
    setI(6);
    error.set(load(&ruta[6]));
    if(error.get())
    {
        return error.get();
    }
    setX(60);
    setY(60);
    return error.get();
    //
    setI(7);
    error.set(load(&ruta[7]));
    if(error.get())
    {
        return error.get();
    }
    setX(70);
    setY(70);
    return error.get();
    //
    setI(8);
    error.set(load(&ruta[8]));
    if(error.get())
    {
        return error.get();
    }
    setX(80);
    setY(80);
    return error.get();
    //
    setI(9);
    error.set(load(&ruta[9]));
    if(error.get())
    {
        return error.get();
    }
    setX(90);
    setY(90);
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

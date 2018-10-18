#include "clsPersonajes.h"

//Metodo para iniciar Personajes
int clsPersonajes::iniciar(char *ruta, int sprites)
{
    error.set(0);
    setItems(sprites);
    //Sprite personaje
    setI(0);
    error.set(load(ruta));
    if(error.get())
    {
        return error.get();
    }
    setX(0);
    setY(0);
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

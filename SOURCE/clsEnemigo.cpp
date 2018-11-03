#include "clsEnemigo.h"

int clsEnemigo::init(clsScreen *s)
{
    pantalla =  s;
    setItems(10);
    setI(0);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_0.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(1);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_1.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(2);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_3.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(3);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_4.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(4);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_A1.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(5);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_A2.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(6);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_A3.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(7);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_A4.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(8);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_D.png"));
    if(error.get()) {error.show(true); return error.get();}
    setI(9);
    error.set(load("RESOURCES/IMAGES/SPRITES/CHARACTERS/DARE_DEVIL/Dare_Devil_D2.png"));
    if(error.get()) {error.show(true); return error.get();}


    return error.get();

}

void clsEnemigo::animar()
{
    setX(getX()+posX);
    setY(getX()+posX);
    paste(pantalla->getPtr());
}

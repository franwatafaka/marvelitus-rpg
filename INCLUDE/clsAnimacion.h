#ifndef CLSANIMACION_H
#define CLSANIMACION_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsTimer.h>


class clsAnimacion : public clsSprite
{
public:
    void inherit() {};
    //
    int iniciarCapi();
    //
    int iniciarDare();
    //
    int iniciarIron();
    //
    int iniciarSpider();
    //
    int iniciarStar();
    //
    int iniciarThor();
    //
    int play(clsScreen *);
private:
    clsScreen *pantalla;
    int contador = 0;

};

#endif // CLSANIMACION_H

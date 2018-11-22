#ifndef CLSENEMIGO_H
#define CLSENEMIGO_H
#include <clsTimer.h>
#include <clsSprite.h>
#include <clsScreen.h>
#include <clsFondo.h>
#include <clsEvent.h>
class clsEnemigo : public clsSprite
{
public:
    void inherit() {};
    int init( clsScreen *s);
    int vida = 0;
    int animar(clsScreen *pantalla, tDireccion, clsFondo *fondo );
    clsScreen *pantalla;
    clsFondo *fondo;
    tDireccion *direction;

protected:

private:
    clsEvent *evento;
    int danio;
    bool activo;
    clsFondo *fondoActual;
    int pasos = 0;
    int posX;
    int posY;
};

#endif // CLSENEMIGO_H

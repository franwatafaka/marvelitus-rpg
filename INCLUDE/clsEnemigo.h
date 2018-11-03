#ifndef CLSENEMIGO_H
#define CLSENEMIGO_H

#include <clsSprite.h>


class clsEnemigo : public clsSprite
{
    public:
        void inherit(){};
       int init(clsScreen *s);
       int vida = 0;
       void animar();
    protected:

    private:
    clsScreen *pantalla;
    int posX;
    int posY;
};

#endif // CLSENEMIGO_H

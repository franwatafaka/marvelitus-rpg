#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>
#include <clsScreen.h>


class clsFondo : public clsSprite
{
public:
    void inherit() {};
    //
    int iniciar(clsScreen *);

private:
    clsScreen *pantalla;
};

#endif // CLSFONDO_H

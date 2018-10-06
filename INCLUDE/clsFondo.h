#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>


class clsFondo : public clsSprite
{
    public:
        //Metodo para Iniciar Motor
        int iniciar();
        void setBienvenida();
        void setDespedida();
        void setJuego();
    protected:
        void inherit(){};

};

#endif // CLSFONDO_H

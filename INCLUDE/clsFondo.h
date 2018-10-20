#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>


class clsFondo : public clsSprite
{
public:
    //Metodo para Iniciar Fondo
    int iniciar();
    //Metodo para Iniciar Fondo de Bienvenida
    void setBienvenida();
    //Metodo para Iniciar Fondo de Despedida
    void setDespedida();
    //Metodo para Iniciar Fondo de Menu Principal
    void setMenu();
protected:
    void inherit() {};
};

#endif // CLSFONDO_H

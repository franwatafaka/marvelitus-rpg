#ifndef CLSIMAGENES_H
#define CLSIMAGENES_H

#include <clsSprite.h>


class clsImagenes : public clsSprite
{
public:
    //Metodo para Iniciar Imagenes
    int iniciar();
    //Metodo para iniciar Imagen Flecha Derecha
    void setMenuPrincipal();

protected:
    void inherit() {};
};

#endif // CLSIMAGENES_H

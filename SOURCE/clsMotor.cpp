#include "clsMotor.h"

//Metodo para Iniciar Motor
int clsMotor::iniciar()
{
    //Modo Grafico
    error.set(modoGrafico.init(1280,720,32));
    if(error.get())
    {
        return error.get();
    }
    //Pantalla
    error.set(pantalla.init(modoGrafico.getScrWidth(),
    modoGrafico.getScrHeight(),modoGrafico.getScrDepth(),DISABLED,FULLSCREEN));
    if(error.get())
    {
        return error.get();
    }
    error.set(bienvenida.iniciar(&pantalla,&evento));
    if(error.get())
    {
        return error.get();
    }
    error.set(despedida.iniciar(&pantalla,&evento));
    if(error.get())
    {
        return error.get();
    }
    return error.get();
}
//Metodo para Correr Motor
int clsMotor::correr()
{
    error.set(0);
    error.set(bienvenida.correr());
    if(error.get())
    {
        return error.get();
    }
    cout << "Corre bienvenida OK" << endl;

    //Menu Juego <<<------------------------------------------------------------

    error.set(despedida.correr());
    if(error.get())
    {
        return error.get();
    }
    cout << "Corre despedida OK" << endl;
    return error.get();
}

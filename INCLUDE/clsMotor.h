#ifndef CLSMOTOR_H
#define CLSMOTOR_H
//------------------------------------------------------------------------------
#include <adnConsts.h>      // Tipos de datos del sistema adn-X.
#include <clsError.h>
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <clsAudio.h>
#include <clsMusic.h>
#include <clsSoundEffect.h>
#include <clsText.h>
#include <clsTimer.h>
#include <clsRandom.h>

//------------------------------------------------------------------------------
#include "clsFondo.h"
#include "clsAnimacion.h"
#include "clsPersonaje.h"
#include "clsEnemigo.h"
//------------------------------------------------------------------------------
class clsMotor
{
public:
    //Metdodo para Iniciar el Motor del programa
    int iniciar();
    //Metdodo para Correr la bienvenida del programa
    int bienvenida();
    //Metdodo para Correr el menu del programa
    int menu();
    //Metdodo para Correr la seleccion de personajes
    int eleccionPersonaje();
    //Metdodo para Correr la historia del programa
    int historia();
    //Metdodo para Correr la historia del Capitan America
    int introCapi(bool *);
    //Metdodo para Correr la historia del Capitan America
    int introDare(bool *);
    //Metdodo para Correr la historia del Capitan America
    int introIron(bool *);
    //Metdodo para Correr la historia del Capitan America
    int introSpider(bool *);
    //Metdodo para Correr la historia del Capitan America
    int introStar(bool *);
    //Metdodo para Correr la historia del Capitan America
    int introThor(bool *);
    //Metodo para correr el juego del programa
    int juego(int);
    //Metodo para correr el nivel_1 del programa
    int nivel_1(clsPersonaje);
    //Metodo para correr el nivel_2 del programa
    int nivel_2(clsPersonaje);
    //Metodo para correr el nivel_3 del programa
    int nivel_3(clsPersonaje);
    //Metodo para correr la escena final del programa si gana
    int escenaGana();
    //Metodo para correr la escena final del programa si pierde
    int escenaPierde();
    //Metdodo para Correr la bienvenida del programa
    int despedida();
    //Metdodo para Iniciar evento de tecla presionada
    int teclaPresionada();
    //Metdodo para Iniciar evento de tecla liberada
    int teclaLiberada();
    //Metdodo para Iniciar evento de tecla liberada
    int mousePresionado();
    //Metdodo para Iniciar evento de tecla liberada
    int mouseLiberado();
    //Metdodo para Iniciar evento de tecla liberada
    int mouseMovimiento();

private:
    //Atributo para el modo grafico
    clsMode modoGrafico;
    //Atributo para la pantalla
    clsScreen pantalla;
    //Atributo para el audio
    clsAudio audio;
    //Atributo para manejar el reloj
    clsTimer reloj;
    //Atributo para manejar musica
    clsMusic musica[18];
    //Atributo para manejar efecto de sonido
    clsSoundEffect sonido;
    //Atributo para el texto
    clsText texto;
    //Atributo para manejar los eventos
    clsEvent evento;
    //Atributo para manejar errores
    clsError error;
    //Atributo para manejar los fondos
    clsFondo fondo;
    //Atributo para manejar las animaciones de personajes
    clsAnimacion animaciones[6];
    //Atributo para manejar los personajes
    clsPersonaje seleccionado,ronan,elf[10],ultron[10],chitauri[10];
    //Enum para manejar las direcciones
    tDireccion direccion;
    //Atriuto para salir del programa
    bool salirBienvenida;
    //Atriuto para salir del programa
    bool salirMenu;
    //Atriuto para salir del programa
    bool salirSeleccion;
    //Atriuto para salir del programa
    bool salirHistoria;
    //Atriuto para salir del programa
    bool salirIntroCapi;
    //Atriuto para salir del programa
    bool salirIntroDare;
    //Atriuto para salir del programa
    bool salirIntroIron;
    //Atriuto para salir del programa
    bool salirIntroSpider;
    //Atriuto para salir del programa
    bool salirIntroStar;
    //Atriuto para salir del programa
    bool salirIntroThor;
    //Atriuto para salir del programa
    bool eligioPersonaje;
    //Atriuto para salir del programa
    bool ingresoJuego;
    //Atriuto para salir del programa
    bool salirJuego;
    //Atriuto para salir del programa
    bool salirNivel_1;
    //Atriuto para salir del programa
    bool salirNivel_2;
    //Atriuto para salir del programa
    bool salirNivel_3;
    //Atriuto para salir del programa
    bool salirEscenaGana;
    //Atriuto para salir del programa
    bool salirEscenaPierde;
    //Atriuto para salir del programa
    bool salirDespedida;
    //
    bool movimiento;

    clsEnemigo enemigo;


    clsRandom aleatorio;
};

#endif // CLSMOTOR_H

#include "clsMotor.h"
#include "../INCLUDE/rutasRecursos.h"
#include "../INCLUDE/consTextos.h"

//Metdodo para Iniciar el Motor del programa
int clsMotor::iniciar()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Inicializar modo Grafico
    error.set(modoGrafico.init(1280,720,32));
    if(error.get())
    {
        modoGrafico.crashPrevent();
        error.show(true);
        return error.get();
    }

    //Inicializar la pantalla
    error.set(pantalla.init(1280,720,32,DISABLED,FULLSCREEN));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Inicializar el audio
    error.set(audio.init());
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Inicializar el texto y la fuente
    error.set(texto.init());
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //Fuente del texto
    error.set(texto.loadFont(comic,20));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //Color del Texto
    texto.setFontColor(YELLOW);

    //Inicializar Fondos
    error.set(fondo.iniciar(&pantalla));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //Iniciar Musica Bienvenida
    error.set(musica[0].loadMusic(musicaDeBienvenida));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //Iniciar Musica menu
    error.set(musica[1].loadMusic(musicaDeMenu));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //Iniciar Musica historia
    error.set(musica[2].loadMusic(musicaDeHistoria));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    //Iniciar Musica intro capitan america
    error.set(musica[3].loadMusic(musicaDeCapitanAmerica));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    animaciones[0].iniciarCapi();
    //Iniciar Musica intro dare devil
    error.set(musica[4].loadMusic(musicaDeDareDevil));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    animaciones[1].iniciarDare();
    //Iniciar Musica intro iron man
    error.set(musica[5].loadMusic(musicaDeIronMan));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    animaciones[2].iniciarIron();
    //Iniciar Musica intro spider man
    error.set(musica[6].loadMusic(musicaDeSpiderMan));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    animaciones[3].iniciarSpider();
    //Iniciar Musica intro star lord
    error.set(musica[7].loadMusic(musicaDeStarLord));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    animaciones[4].iniciarStar();
    //Iniciar Musica intro thor
    error.set(musica[8].loadMusic(musicaDeThor));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    animaciones[5].iniciarThor();

    //Iniciar Musica Nivel_1
    error.set(musica[9].loadMusic(musicaDeNivel_1));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Iniciar Musica Nivel_2
    error.set(musica[10].loadMusic(musicaDeNivel_2));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Iniciar Musica Introduccion JEFE
    error.set(musica[11].loadMusic(musicaDeJefe));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Iniciar Musica Nivel_3 (JEFE)
    error.set(musica[12].loadMusic(musicaDeNivel_3));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Iniciar Musica Dance_Off (JEFE atacado por Guardianes)
    error.set(musica[13].loadMusic(musicaDanceOff));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Iniciar Musica Escena Final (Ganador)
    error.set(musica[14].loadMusic(musicaDeEscenaFinalGana));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Iniciar Musica Despedida
    error.set(musica[15].loadMusic(musicaDeDespedida));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }


    //Iniciar Musica Seleccion Personaje
    error.set(musica[16].loadMusic(musicaDeSeleccion));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //Iniciar Musica Despedida pierde
    error.set(musica[17].loadMusic(musicaDeEscenaFinalPierde));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la bienvenida del programa
int clsMotor::bienvenida()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(0);
    fondo.paste(pantalla.getPtr());
    pantalla.refresh();
    musica[0].playMusic(1);
    reloj.start();

    salirBienvenida=false;
    //Loop del Motor
    while(!salirBienvenida)
    {
        //Revisar relo jen cada vuelta
        reloj.update();
        if(reloj.getState() == 23000)
        {
            salirBienvenida = true;
        }
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ENTER)
                {
                    salirBienvenida = true;
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    musica[0].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr el menu del programa
int clsMotor::menu()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(1);
    fondo.paste(pantalla.getPtr());
    pantalla.refresh();
    musica[1].playMusic(-1);
    reloj.start();

    salirMenu=false;
    //Loop del Motor
    while(!salirMenu)
    {
        //Revisar reloj jen cada vuelta
        reloj.update();
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ENTER)
                {
                    musica[1].stopMusic();
                    error.set(historia());
                }
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirMenu = true;
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    musica[1].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia del programa
int clsMotor::historia()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(2);
    fondo.paste(pantalla.getPtr());
    pantalla.refresh();
    musica[2].playMusic(1);
    reloj.start();

    salirHistoria=false;
    //Loop del Motor
    while(!salirHistoria)
    {
        //Revisar relo jen cada vuelta
        reloj.update();
        if(reloj.getState() == 50000)
        {
            salirHistoria = true;
        }
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ENTER)
                {
                    salirHistoria = true;
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    musica[2].stopMusic();
    error.set(eleccionPersonaje());
    error.set(menu());
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la seleccion de personajes
int clsMotor::eleccionPersonaje()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //
    texto.loadFont(comic,20);
    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(14);
    fondo.paste(pantalla.getPtr());
    pantalla.refresh();
    musica[16].playMusic(-1);
    reloj.start();

    salirSeleccion=false;
    eligioPersonaje=false;
    //Loop del Motor
    while(!salirSeleccion)
    {
        //Revisar reloj jen cada vuelta
        reloj.update();
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                switch(evento.getKey())
                {
                case KEY_1:
                    musica[16].stopMusic();
                    error.set(introCapi(&eligioPersonaje));
                    if(eligioPersonaje == false)
                    {
                        eleccionPersonaje();
                    }
                    break;
                case KEY_2:
                    musica[16].stopMusic();
                    error.set(introDare(&eligioPersonaje));
                    if(eligioPersonaje == false)
                    {
                        eleccionPersonaje();
                    }
                    break;
                case KEY_3:
                    musica[16].stopMusic();
                    error.set(introIron(&eligioPersonaje));
                    if(eligioPersonaje == false)
                    {
                        eleccionPersonaje();
                    }
                    break;
                case KEY_4:
                    musica[16].stopMusic();
                    error.set(introSpider(&eligioPersonaje));
                    if(eligioPersonaje == false)
                    {
                        eleccionPersonaje();
                    }
                    break;
                case KEY_5:
                    musica[16].stopMusic();
                    error.set(introStar(&eligioPersonaje));
                    if(eligioPersonaje == false)
                    {
                        eleccionPersonaje();
                    }
                    break;
                case KEY_6:
                    musica[16].stopMusic();
                    error.set(introThor(&eligioPersonaje));
                    if(eligioPersonaje == false)
                    {
                        eleccionPersonaje();
                    }
                    break;
                case KEY_ESCAPE:
                    salirSeleccion = true;
                    break;
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    musica[16].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia del capitan america
int clsMotor::introCapi(bool * elegido)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(3);
    fondo.paste(pantalla.getPtr());
    texto.setFontColor(AZUL_CAPI);
    texto.centredWrite(textoCapi[0],0,pantalla.getPtr());
    texto.centredWrite(textoCapi[1],40,pantalla.getPtr());
    texto.centredWrite(textoCapi[2],60,pantalla.getPtr());
    texto.centredWrite(textoCapi[3],80,pantalla.getPtr());
    texto.centredWrite(textoCapi[4],120,pantalla.getPtr());
    musica[3].playMusic(-1);
    reloj.start();
    salirIntroCapi=false;
    ingresoJuego=false;
    //Loop del Motor
    while(!salirIntroCapi)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirIntroCapi = true;
                }
                if(evento.getKey() == KEY_ENTER)
                {
                    *elegido = true;
                    ingresoJuego = true;
                    juego(1);
                }
            }
            break;
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
            }
        }
        if(ingresoJuego != true)
        {
            //Refresca Pantalla
            pantalla.refresh();
            pantalla.clean(BLACK);
            fondo.setI(3);
            fondo.paste(pantalla.getPtr());
            texto.centredWrite(textoCapi[0],0,pantalla.getPtr());
            texto.centredWrite(textoCapi[1],40,pantalla.getPtr());
            texto.centredWrite(textoCapi[2],60,pantalla.getPtr());
            texto.centredWrite(textoCapi[3],80,pantalla.getPtr());
            texto.centredWrite(textoCapi[4],120,pantalla.getPtr());
            animaciones[0].play(&pantalla);
        }
        else
        {
            pantalla.clean(BLACK);
            pantalla.refresh();
            salirIntroCapi=true;
            salirSeleccion=true;
        }
    }
    musica[3].stopMusic();

    //--------------------------------------------------------------------------
    return error.get();
}


//Metdodo para Correr la historia de Dare Devil
int clsMotor::introDare(bool * elegido)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(4);
    fondo.paste(pantalla.getPtr());
    texto.setFontColor(ROJO_DARE);
    texto.centredWrite(textoDare[0],0,pantalla.getPtr());
    texto.centredWrite(textoDare[1],40,pantalla.getPtr());
    texto.centredWrite(textoDare[2],60,pantalla.getPtr());
    texto.centredWrite(textoDare[3],80,pantalla.getPtr());
    texto.centredWrite(textoDare[4],120,pantalla.getPtr());
    musica[4].playMusic(-1);
    reloj.start();

    salirIntroDare=false;
    ingresoJuego=false;
    //Loop del Motor
    while(!salirIntroDare)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirIntroDare = true;
                }
                if(evento.getKey() == KEY_ENTER)
                {
                    *elegido = true;
                    ingresoJuego = true;
                    juego(2);
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
        if(ingresoJuego != true)
        {
            //Refresca Pantalla
            pantalla.refresh();
            pantalla.clean(BLACK);
            fondo.setI(4);
            fondo.paste(pantalla.getPtr());
            texto.centredWrite(textoDare[0],0,pantalla.getPtr());
            texto.centredWrite(textoDare[1],40,pantalla.getPtr());
            texto.centredWrite(textoDare[2],60,pantalla.getPtr());
            texto.centredWrite(textoDare[3],80,pantalla.getPtr());
            texto.centredWrite(textoDare[4],120,pantalla.getPtr());
            animaciones[1].play(&pantalla);
        }
        else
        {
            pantalla.clean(BLACK);
            pantalla.refresh();
            salirIntroDare=true;
            salirSeleccion=true;
        }
    }
    musica[4].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia de Iron Man
int clsMotor::introIron(bool * elegido)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(5);
    fondo.paste(pantalla.getPtr());
    texto.setFontColor(AMARILLO_IRON);
    texto.centredWrite(textoIron[0],0,pantalla.getPtr());
    texto.centredWrite(textoIron[1],40,pantalla.getPtr());
    texto.centredWrite(textoIron[2],60,pantalla.getPtr());
    texto.centredWrite(textoIron[3],80,pantalla.getPtr());
    texto.centredWrite(textoIron[4],120,pantalla.getPtr());
    musica[5].playMusic(-1);
    reloj.start();

    salirIntroIron=false;
    ingresoJuego = false;
    //Loop del Motor
    while(!salirIntroIron)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirIntroIron = true;
                }
                if(evento.getKey() == KEY_ENTER)
                {
                    *elegido = true;
                    ingresoJuego = true;
                    juego(3);
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
        if(ingresoJuego != true)
        {
            //Refresca Pantalla
            pantalla.refresh();
            pantalla.clean(BLACK);
            fondo.setI(5);
            fondo.paste(pantalla.getPtr());
            texto.centredWrite(textoIron[0],0,pantalla.getPtr());
            texto.centredWrite(textoIron[1],40,pantalla.getPtr());
            texto.centredWrite(textoIron[2],60,pantalla.getPtr());
            texto.centredWrite(textoIron[3],80,pantalla.getPtr());
            texto.centredWrite(textoIron[4],120,pantalla.getPtr());
            animaciones[2].play(&pantalla);
        }
        else
        {
            pantalla.clean(BLACK);
            pantalla.refresh();
            salirIntroIron=true;
            salirSeleccion=true;
        }
    }
    musica[5].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia de Spider Man
int clsMotor::introSpider(bool * elegido)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(6);
    fondo.paste(pantalla.getPtr());
    texto.setFontColor(ROJO_SPIDER);
    texto.centredWrite(textoSpider[0],0,pantalla.getPtr());
    texto.centredWrite(textoSpider[1],40,pantalla.getPtr());
    texto.centredWrite(textoSpider[2],60,pantalla.getPtr());
    texto.centredWrite(textoSpider[3],80,pantalla.getPtr());
    texto.centredWrite(textoSpider[4],120,pantalla.getPtr());
    musica[6].playMusic(-1);
    reloj.start();

    salirIntroSpider=false;
    ingresoJuego = false;
    //Loop del Motor
    while(!salirIntroSpider)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirIntroSpider = true;
                }
                if(evento.getKey() == KEY_ENTER)
                {
                    *elegido = true;
                    ingresoJuego = true;
                    juego(4);
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
        if(ingresoJuego != true)
        {
            //Refresca Pantalla
            pantalla.refresh();
            pantalla.clean(BLACK);
            fondo.setI(6);
            fondo.paste(pantalla.getPtr());
            texto.centredWrite(textoSpider[0],0,pantalla.getPtr());
            texto.centredWrite(textoSpider[1],40,pantalla.getPtr());
            texto.centredWrite(textoSpider[2],60,pantalla.getPtr());
            texto.centredWrite(textoSpider[3],80,pantalla.getPtr());
            texto.centredWrite(textoSpider[4],120,pantalla.getPtr());
            animaciones[3].play(&pantalla);
        }
        else
        {
            pantalla.clean(BLACK);
            pantalla.refresh();
            salirIntroSpider=true;
            salirSeleccion=true;
        }
    }
    musica[6].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia de Star Lord
int clsMotor::introStar(bool * elegido)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(7);
    fondo.paste(pantalla.getPtr());
    texto.setFontColor(VIOLETA_STAR);
    texto.centredWrite(textoStar[0],0,pantalla.getPtr());
    texto.centredWrite(textoStar[1],40,pantalla.getPtr());
    texto.centredWrite(textoStar[2],60,pantalla.getPtr());
    texto.centredWrite(textoStar[3],80,pantalla.getPtr());
    texto.centredWrite(textoStar[4],120,pantalla.getPtr());
    musica[7].playMusic(-1);
    reloj.start();

    salirIntroStar=false;
    ingresoJuego = false;
    //Loop del Motor
    while(!salirIntroStar)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirIntroStar = true;
                }
                if(evento.getKey() == KEY_ENTER)
                {
                    *elegido = true;
                    ingresoJuego = true;
                    juego(5);
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
        if(ingresoJuego != true)
        {
            //Refresca Pantalla
            pantalla.refresh();
            pantalla.clean(BLACK);
            fondo.setI(7);
            fondo.paste(pantalla.getPtr());
            texto.centredWrite(textoStar[0],0,pantalla.getPtr());
            texto.centredWrite(textoStar[1],40,pantalla.getPtr());
            texto.centredWrite(textoStar[2],60,pantalla.getPtr());
            texto.centredWrite(textoStar[3],80,pantalla.getPtr());
            texto.centredWrite(textoStar[4],120,pantalla.getPtr());
            animaciones[4].play(&pantalla);
        }
        else
        {
            pantalla.clean(BLACK);
            pantalla.refresh();
            salirIntroStar=true;
            salirSeleccion=true;
        }
    }
    musica[7].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia de Thor
int clsMotor::introThor(bool * elegido)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(8);
    fondo.paste(pantalla.getPtr());
    texto.setFontColor(CELESTE_THOR);
    texto.centredWrite(textoThor[0],0,pantalla.getPtr());
    texto.centredWrite(textoThor[1],40,pantalla.getPtr());
    texto.centredWrite(textoThor[2],60,pantalla.getPtr());
    texto.centredWrite(textoThor[3],80,pantalla.getPtr());
    texto.centredWrite(textoThor[4],120,pantalla.getPtr());
    musica[8].playMusic(-1);
    reloj.start();

    salirIntroThor=false;
    ingresoJuego = false;
    //Loop del Motor
    while(!salirIntroThor)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirIntroThor = true;
                }
                if(evento.getKey() == KEY_ENTER)
                {
                    *elegido = true;
                    ingresoJuego = true;
                    juego(6);
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
        if(ingresoJuego != true)
        {
            //Refresca Pantalla
            pantalla.refresh();
            pantalla.clean(BLACK);
            fondo.setI(8);
            fondo.paste(pantalla.getPtr());
            texto.centredWrite(textoThor[0],0,pantalla.getPtr());
            texto.centredWrite(textoThor[1],40,pantalla.getPtr());
            texto.centredWrite(textoThor[2],60,pantalla.getPtr());
            texto.centredWrite(textoThor[3],80,pantalla.getPtr());
            texto.centredWrite(textoThor[4],120,pantalla.getPtr());
            animaciones[5].play(&pantalla);
        }
        else
        {
            pantalla.clean(BLACK);
            pantalla.refresh();
            salirIntroThor=true;
            salirSeleccion=true;
        }
    }
    musica[8].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

int clsMotor::juego(int personaje)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    pantalla.refresh();
    salirJuego=false;
    switch(personaje)
    {
    case 1:
        {
            seleccionado.iniciar(spritesJuegoCapitan,10);
        }
    break;
    case 2:
        {
            seleccionado.iniciar(spritesJuegoDare,10);
        }
    break;
    case 3:
        {
            seleccionado.iniciar(spritesJuegoIron,10);
        }
    break;
    case 4:
        {
            seleccionado.iniciar(spritesJuegoSpider,10);
        }
    break;
    case 5:
        {
            seleccionado.iniciar(spritesJuegoStar,10);
        }
    break;
    case 6:
        {
            seleccionado.iniciar(spritesJuegoThor,10);
        }
    break;
    }
    //Loop del Motor
    while(!salirJuego)
    {
        //Secuencia de Niveles OK
        nivel_1(seleccionado);
        nivel_2(seleccionado);
        nivel_3(seleccionado);
        escenaGana();
        escenaPierde();
        salirJuego = true;
    }
    //--------------------------------------------------------------------------
    return error.get();
}

int clsMotor::nivel_1(clsPersonaje seleccionado)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    this->seleccionado = seleccionado;
    pantalla.clean(BLACK);
    fondo.setI(9);
    fondo.paste(pantalla.getPtr());
    seleccionado.animar(&pantalla,QUIETO,&fondo);
    movimiento = false;
    pantalla.refresh();
    musica[9].playMusic(-1);

    salirNivel_1=false;
    //Loop del Motor
    while(!salirNivel_1)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                while(evento.getEventType() == KEY_PRESSED)
                {
                    if(evento.wasEvent() && evento.getEventType() == KEY_FREE)
                    {
                        break;
                        seleccionado.animar(&pantalla,QUIETO,&fondo);
                    }
                    else
                    {
                        error.set(teclaPresionada());
                    }
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    musica[9].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

int clsMotor::nivel_2(clsPersonaje seleccionado)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    this->seleccionado = seleccionado;
    pantalla.clean(BLACK);
    fondo.setI(10);
    fondo.paste(pantalla.getPtr());
    seleccionado.animar(&pantalla,QUIETO,&fondo);
    pantalla.refresh();
    musica[10].playMusic(-1);
    reloj.start();

    salirNivel_2=false;
    //Loop del Motor
    while(!salirNivel_2)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                while(evento.getEventType() == KEY_PRESSED)
                {
                    if(evento.wasEvent() && evento.getEventType() == KEY_FREE)
                    {
                        break;
                        seleccionado.animar(&pantalla,QUIETO,&fondo);
                    }
                    else
                    {
                        error.set(teclaPresionada());
                    }
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    musica[10].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

int clsMotor::nivel_3(clsPersonaje seleccionado)
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    this->seleccionado = seleccionado;
    pantalla.clean(BLACK);
    fondo.setI(11);
    fondo.paste(pantalla.getPtr());
    seleccionado.animar(&pantalla,QUIETO,&fondo);
    pantalla.refresh();
    musica[11].playMusic(-1);
    reloj.start();

    salirNivel_3=false;
    //Loop del Motor
    while(!salirNivel_3)
    {
        //Revision de reloj
        if(reloj.getState() == 16500)
        {
            musica[11].stopMusic();
            musica[12].playMusic(-1);
        }
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                while(evento.getEventType() == KEY_PRESSED)
                {
                    if(evento.wasEvent() && evento.getEventType() == KEY_FREE)
                    {
                        break;
                        seleccionado.animar(&pantalla,QUIETO,&fondo);
                    }
                    else
                    {
                        error.set(teclaPresionada());
                    }
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
    }
    musica[12].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia del programa
int clsMotor::escenaGana()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(12);
    fondo.paste(pantalla.getPtr());
    pantalla.refresh();
    musica[14].playMusic(-1);
    reloj.start();

    salirEscenaGana=false;
    //Loop del Motor
    while(!salirEscenaGana)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ENTER)
                {
                    salirEscenaGana = true;
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
        }
        texto.loadFont(comic,40);
        texto.setFontColor(GREEN);
        texto.centredWrite("Has Derrotado a Ronan y has salvado la Galaxia!",40,pantalla.getPtr());
        texto.centredWrite("Tus hazañas quedarán grabadas en la historia.",85,pantalla.getPtr());
        pantalla.refresh();
    }
    musica[14].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Correr la historia del programa
int clsMotor::escenaPierde()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(15);
    fondo.paste(pantalla.getPtr());
    pantalla.refresh();
    musica[17].playMusic(-1);
    reloj.start();

    salirEscenaPierde=false;
    //Loop del Motor
    while(!salirEscenaPierde)
    {
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ENTER)
                {
                    salirEscenaPierde = true;
                }
            }
            break;
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
            texto.loadFont(comic,40);
            texto.setFontColor(RED);
            texto.centredWrite("Derrota!! Ronan, regirá la galaxia...",340,pantalla.getPtr());
            texto.centredWrite("Tu miserable intento quedará manchado de verguenza!!!",390,pantalla.getPtr());
            texto.centredWrite("Serás recordado como inutil...por toda la eternidad.",460,pantalla.getPtr());
            pantalla.refresh();
        }
    }
    musica[17].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}


//Metdodo para Correr la bienvenida del programa
int clsMotor::despedida()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //Pego fondo en pantalla y refresco
    pantalla.clean(BLACK);
    fondo.setI(13);
    fondo.paste(pantalla.getPtr());
    pantalla.refresh();
    musica[15].playMusic(1);
    reloj.start();

    salirDespedida=false;
    //Loop del Motor
    while(!salirDespedida)
    {
        //Revisar relo jen cada vuelta
        reloj.update();
        if(reloj.getState() == 47000)
        {
            salirDespedida = true;
        }
        //Si hubo un evento
        if(evento.wasEvent())
        {
            //Switch de eventos
            switch(evento.getEventType())
            {
            //Presion de una tecla
            case KEY_PRESSED:
            {
                if(evento.getKey() == KEY_ESCAPE)
                {
                    salirDespedida = true;
                }
            }
            }
            if(error.get())
            {
                error.show(true);
                return error.get();
            }
            //Refresca Pantalla
            pantalla.refresh();
            pantalla.clean(BLACK);
            fondo.setI(13);
            fondo.paste(pantalla.getPtr());
        }
    }
    musica[15].stopMusic();
    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Iniciar evento de tecla presionada
int clsMotor::teclaPresionada()
{
    error.set(0);
    //--------------------------------------------------------------------------

    switch(evento.getKey())
    {
    //---------------------

    case KEY_ESCAPE:
    {
        salirNivel_1 = true;
        salirNivel_2 = true;
        salirNivel_3 = true;
    }
    break;
    case KEY_0:
    {

    }
    break;
    case KEY_1:
    {

    }
    break;
    case KEY_2:
    {

    }
    break;
    case KEY_3:
    {

    }
    break;
    case KEY_4:
    {

    }
    break;
    case KEY_5:
    {

    }
    break;
    case KEY_6:
    {

    }
    break;
    case KEY_7:
    {

    }
    break;
    case KEY_8:
    {

    }
    break;
    case KEY_9:
    {

    }
    break;
    case KEY_A:
    case KEY_a:
    {
        seleccionado.animar(&pantalla,IZQUIERDA,&fondo);
    }
    break;
    case KEY_B:
    case KEY_b:
    {

    }
    break;
    case KEY_C:
    case KEY_c:
    {
        seleccionado.animar(&pantalla,DI_DER,&fondo);
    }
    break;
    case KEY_D:
    case KEY_d:
    {
        seleccionado.animar(&pantalla,DERECHA,&fondo);
    }
    break;
    case KEY_E:
    case KEY_e:
    {
        seleccionado.animar(&pantalla,DS_DER,&fondo);
    }
    break;
    case KEY_F:
    case KEY_f:
    {

    }
    break;
    case KEY_G:
    case KEY_g:
    {

    }
    break;
    case KEY_H:
    case KEY_h:
    {

    }
    break;
    case KEY_I:
    case KEY_i:
    {

    }
    break;
    case KEY_J:
    case KEY_j:
    {

    }
    break;
    case KEY_K:
    case KEY_k:
    {

    }
    break;
    case KEY_L:
    case KEY_l:
    {

    }
    break;
    case KEY_M:
    case KEY_m:
    {

    }
    break;
    case KEY_N:
    case KEY_n:
    {

    }
    break;
    case KEY_O:
    case KEY_o:
    {

    }
    break;
    case KEY_P:
    case KEY_p:
    {

    }
    break;
    case KEY_Q:
    case KEY_q:
    {
        seleccionado.animar(&pantalla,DS_IZQ,&fondo);
    }
    break;
    case KEY_R:
    case KEY_r:
    {

    }
    break;
    case KEY_S:
    case KEY_s:
    {
        seleccionado.animar(&pantalla,ABAJO,&fondo);
    }
    break;
    case KEY_T:
    case KEY_t:
    {

    }
    break;
    case KEY_U:
    case KEY_u:
    {

    }
    break;
    case KEY_V:
    case KEY_v:
    {

    }
    break;
    case KEY_W:
    case KEY_w:
    {
        seleccionado.animar(&pantalla,ARRIBA,&fondo);
    }
    break;
    case KEY_X:
    case KEY_x:
    {

    }
    break;
    case KEY_Y:
    case KEY_y:
    {

    }
    break;
    case KEY_Z:
    case KEY_z:
    {
        seleccionado.animar(&pantalla,DI_IZQ,&fondo);
    }
    break;
    case KEY_ENTER:
    {

    }
    break;
    case KEY_SPACE:
    {

    }
    break;
    case KEY_BACKSPACE:
    {

    }
    break;
    case KEY_TAB:
    {

    }
    break;
    case KEY_UP:
    {

    }
    break;
    case KEY_DOWN:
    {

    }
    break;
    case KEY_LEFT:
    {

    }
    break;
    case KEY_RIGHT:
    {

        pantalla.refresh();
    }
    break;
    case KEY_COMMA:
    {
        seleccionado.animar(&pantalla,ATACA_C,&fondo);
    }
    break;
    case KEY_PERIOD:
    {
        seleccionado.animar(&pantalla,ATACA_L,&fondo);
    }
    break;
    case KEY_RIGHT_SLASH:
    {
        seleccionado.animar(&pantalla,DEFIENDE,&fondo);
    }
    break;

        //---------------------
    }

    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Iniciar evento de tecla liberada
int clsMotor::teclaLiberada()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Iniciar evento de mouse izquierdo presionado
int clsMotor::mouseMovimiento()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //texto.centredWrite("Mouse en Movimiento",360,pantalla.getPtr());

    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Iniciar evento de mouse derecho presionado
int clsMotor::mousePresionado()
{
    error.set(0);
    //--------------------------------------------------------------------------

    switch(evento.getMouseButton())
    {
    case MOUSE_LEFT_BUTTON:
    {

    }
    break;
    case MOUSE_RIGHT_BUTTON:
    {

    }
    break;
    case MOUSE_MIDDLE_BUTTON:
    {

    }
    break;
    }

    //--------------------------------------------------------------------------
    return error.get();
}

//Metdodo para Iniciar evento de mouse del medio presionado
int clsMotor::mouseLiberado()
{
    error.set(0);
    //--------------------------------------------------------------------------

    //--------------------------------------------------------------------------
    return error.get();
}

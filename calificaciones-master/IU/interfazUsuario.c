#include<stdlib.h>
#include <stdio.h>
#include "../IU/interfazGrafica.h"
#include <windows.h>
#include <locale.h>
#include "../SYS/alumnosSYS.h"
#include "../IU/alumnoIU.h"
#include "../IU/interfazUsuario.h"
void inicInterfazUsuario() //funcion de interfaz de la tabla
{

    rectangulo(0,0,118,1);
    gotoxy(50,1);
    printf("GESTOR DE CALIFICACIONES");
    system("color 3F");
    rectangulo(0,3,55,1);

    rectangulo(0,6,55,20);
    gotoxy(20,4);
    printf("GESTION DE ALUMNOS");
    rectangulo(0,28,18,1);
    gotoxy(2,29);
    printf("ENTRADA DE DATOS");
    rectangulo(20,28,98,1);
    rectangulo(0,31,18,1);
    rectangulo(20,31,98,1);
    gotoxy(4,32);
    printf("MENSAJES");
    gotoxy(21,29);
}

                            //aqui he decidido dividir la interfaz en varias funciones de interfaz para que vayan apareciendo a medida que sea necesario, y así sea más fácil tanto de entender como de preogramar.

void inicInterfazUsuario2() //funcion de interfaz de la tabla
{
    setlocale(LC_CTYPE, "C");
    SetConsoleCP(850);
    SetConsoleOutputCP(850);

    borraVentana(1,7,54,20);

    gotoxy(2,4);
    printf("\t\tINSCRIPCION DE UN DE ALUMNO");



}


void inicInterfazUsuario3() //funcion de interfaz de la tabla
{


    setlocale(LC_CTYPE, "C");
    SetConsoleCP(850);
    SetConsoleOutputCP(850);
    rectangulo(57,3,61,1);
    rectangulo(57,6,61,20);
    gotoxy(59,4);
    printf("NIA  SEXO  NOTA 1 NOTA 2\tNOMBRE");


}

void inicInterfazUsuario4() //funcion de interfaz de la tabla
{


    setlocale(LC_CTYPE, "C");
    SetConsoleCP(850);
    SetConsoleOutputCP(850);
    rectangulo(57,3,61,1);
    rectangulo(57,6,61,20);
    gotoxy(2,4);
    printf("\tLISTADO DE APROBADOS");
    gotoxy(59,4);
    printf("NIA  NOMBRE\t\t\t       NOTA");


}

void gestionMenuPrincipal()//funcion principal del menu
{

    //Declaracion de variables
    int opcionelegida;

    setlocale(LC_CTYPE, "Spanish");//deberia permitir poner ñ y acentos
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    opcionelegida=menuPrincipal();//recogemos la opcion elegida de la funcion menuPrincipal en una variable


    while(opcionelegida!=0)//bucle con las opciones del menu del que se saldrá cuando se elija la opcion "0"

    {

        switch(opcionelegida) //sentencia de control selectiva con las diferentes opciones del menu
        {

        case 1:
            gestionMenuAlumnos();//llamada a la funcion que muestra el menu de Alumnos
            break;

        case 2:
            gestionMenuDatos();// llamada a la funcion que muestra el menu de Datos
            break;


        default://se muestra opcion incorrecta en caso de que no se opte por ninguna de las opciones anteriores
            gotoxy(2,20);
            printf("Opción incorrecta seleccionada\n\t<Presione a Intro>");


        }
        fflush(stdin);

        borraVentana(1,7,55,20);//borra donde se meten los numeros
        borraVentana(60, 7, 54, 20);
        borraVentana(21,29,70,1);
        borraVentana(1,34,30,1);
        borraVentana(2,4,53,1);
        gotoxy(20,4);
        printf("GESTION PRINCIPAL");//se vuelve a poner la cabecera despues de borrar los mensajes que pudiera haber
        borraVentana(57,3,63,25);
        fflush(stdin);
        opcionelegida=menuPrincipal();
    }


    return;
}

int menuPrincipal()//funcion que muestra la lista de opciones, recoge la opcion elegida y se la manda a gestionmenuPrincipal.
{
    borraVentana(1,7,55,20);
    borraVentana(1,7,55,20);//borra donde se meten los numeros
    borraVentana(60, 7, 54, 20);
    borraVentana(21,29,70,1);
    borraVentana(1,34,30,1);
    borraVentana(2,4,53,1);
    int opcion;//declaracion de variables
    gotoxy(1,9);
    printf("\t1. Menu de Alumnos\n");
    printf("\t2. Menu de Datos\n");
    printf("\t0. Fin del Programa");

    printf("\n\n\tSelecciona una opción: ");
    scanf("%d",&opcion);


    return opcion;





}



void gestionMenuDatos()//funcion de datos del menu
{

    //Declaracion de variables
    int opcionelegida2;

    setlocale(LC_CTYPE, "Spanish");//deberia permitir poner ñ y acentos
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    opcionelegida2=menuDatos();//recogemos la opcion elegida de la funcion menuDatos en una variable


    while(opcionelegida2!=0)//bucle con las opciones del menu del que se saldrá cuando se elija la opcion "0"

    {

        switch(opcionelegida2) //sentencia de control selectiva con las diferentes opciones del menu
        {

        case 1:
            convertirTxt2Bin();//llamada a la funcion que convierte el archivo de texto en un archivo binario
            break;

        case 2:
            convertirBin2Txt();// llamada a la funcion que convierte el archivo binario en un archivo de texto
            break;


        default://se muestra opcion incorrecta en caso de que no se opte por ninguna de las opciones anteriores
            gotoxy(2,20);
            printf("Opción incorrecta seleccionada\n\t<Presione a Intro>");


        }
        fflush(stdin);
        getchar();
        borraVentana(1,7,55,20);//borra donde se meten los numeros
        borraVentana(60, 7, 54, 20);
        borraVentana(21,29,70,1);
        borraVentana(1,34,30,1);
        borraVentana(2,4,53,1);
        borraVentana(22,32,90,1);
        gotoxy(20,4);
        printf("GESTION DATOS");//se vuelve a poner la cabecera despues de borrar los mensajes que pudiera haber
        borraVentana(57,3,63,25);
        fflush(stdin);
        opcionelegida2=menuDatos();
    }


    return;
}

int menuDatos()//funcion que muestra la lista de opciones, recoge la opcion elegida y se la manda a gestionmenuDatos.
{
    borraVentana(1,7,55,20);
    borraVentana(1,7,55,20);//borra donde se meten los numeros
    borraVentana(60, 7, 54, 20);
    borraVentana(21,29,70,1);
    borraVentana(1,34,30,1);
    borraVentana(2,4,53,1);
    int opcion2;//declaracion de variables
    gotoxy(1,9);
    printf("\t1. Convertir texto a binario\n");
    printf("\t2. Convertir binario a texto\n");
    printf("\t0. Volver al menu principal");

    printf("\n\n\tSelecciona una opción: ");
    scanf("%d",&opcion2);


    return opcion2;

}

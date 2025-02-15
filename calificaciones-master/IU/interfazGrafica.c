/*! \file interfazGrafica.c
 *
 * \brief Contiene la definici�n de las funciones declaradas
          en interfazGrafica.h.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include "interfazGrafica.h"

/*! Dibuja un rect�ngulo en la consola.
 * \param [in] x Columna de la esquina superior izquierda del rect�ngulo.
 * \param [in] y Fila de la esquina superior izquierda del rect�ngulo.
 * \param [in] ancho Anchura del rect�ngulo (en columnas).
 * \param [in] alto Altura del rect�ngulo (en filas).

 */
void rectangulo(int x, int y, int ancho, int alto)
{
    int i;

    setlocale(LC_CTYPE, "C"); /* Activo caracteres est�ndar */
    /* Dibuja lado superior del rect�ngulo */
    gotoxy(x, y);
    printf("%c", ESIZQ);
    for(i=x+1; i<x+ancho+1; i++)
        printf("%c", 196);
    printf("%c", ESDER);
    /* Dibuja lados verticales del rect�ngulo. */
    for(i=y+1; i<y+alto+1; i++)
    {
        gotoxy(x,i);
        printf("%c", 179);
        gotoxy(x+ancho+1,i);
        printf("%c", 179);
    }
    /* Dibuja lado inferior del rect�ngulo */
    gotoxy(x, y+alto+1);
    printf("%c", EIIZQ);
    for(i=x+1; i<x+ancho+1; i++)
        printf("%c", 196);
    printf("%c", EIDER);

    return;
}

/*! Borra una ventana (escribiendo el caracter en blanco ' ')
    que comienza en la columna \c x, fila \c y, y que tiene una
    anchura de \c ancho columnas, y una altura de \c alto filas.

 * \param [in] x Columna de la esquina superior izquierda de la ventana.
 * \param [in] y Fila de la esquina superior izquierda de la ventana.
 * \param [in] ancho Anchura de la ventana (en columnas).
 * \param [in] alto Altura de la ventana (en filas).
 */
void borraVentana(int x, int y, int ancho, int alto)
{
    int i;
    char formato[10];
    sprintf(formato, "%%%ds", ancho);
    for(i=0; i<alto; i++)
    {
        gotoxy(x, y + i);
        printf(formato, " ");
    }
    return;
}



/*! Determina los colores de tinta y fondo para el texto
 * \param [in] colores Combinaci�n de colores seleccionada.
 */
void SetColorTexto(int colores)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colores);
}

/*! Coloca el cursor en la columna x, fila y de la consola.

    \param [in] x N�mero de columna
    \param [in] y N�mero de fila

*/
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    if(SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)==0)
    {
        printf("error en gotoxy(%d,%d).\n", x, y);
        system("pause");
    }
    return;
}


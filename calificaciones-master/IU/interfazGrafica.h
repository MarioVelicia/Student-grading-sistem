/* Archivo de cabecera de la biblioteca libinterfazGrafica.a */
#include <windows.h>

enum graficos1
{
    ESIZQ=218, ESDER=191, LHOR=196, EIIZQ= 192,
    EIDER= 217, TDER = 195, TIZQ = 180
};

void rectangulo(int x, int y, int ancho, int alto);
void borraVentana(int x, int y, int cols, int filas);
void SetColorTexto(int colors);
void setConsola(int cols, int lines, int pincel, int lienzo);
void gotoxy(int x, int y);

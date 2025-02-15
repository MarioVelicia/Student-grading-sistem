#include <stdio.h>
#include "IU/interfazGrafica.h"
#include<stdlib.h>
#include "IU/interfazUsuario.h"
#include "IU/alumnoIU.h"
#include "AD/alumnoAD.h"
#include "SYS/alumnosSYS.h"
#include <windows.h>
#include <locale.h>


int main()
{

    inicInterfazUsuario();//funcion de interfaz de la consola


    gestionMenuPrincipal();//funcion de menu


    gotoxy(1,15);




    return 0;

}


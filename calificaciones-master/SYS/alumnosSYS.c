#include <stdio.h>
#include "../SYS/alumnosSYS.h"
#include "../AD/alumnoAD.h"
#include <stdbool.h>
#define NUM_ALUM 100
#include "../Entidades/alumnos.h"
#include "../IU/alumnoIU.h"
#include "../IU/interfazUsuario.h"
#include "../IU/interfazGrafica.h"

bool altaAlumnoSYS(struct sAlumno alumnos)
{
    int codigoerror;
    codigoerror=altaAlumnoAD(alumnos);

    if(codigoerror==-1)
        return false;
    else
    {
        return true;
    }




}


int cargaListaAlumnosSYS(struct sAlumno vAlumnos[])
{
    //Esta función reenvía los datos que recibe como parámetros a la función cargaListaAlumnosAD() para cargar los datos de los alumnos.
    int num;

    num =cargaListaAlumnosAD(vAlumnos);
    return num;

    //recoge el numero de alumnos en la variable num y se lo devuelve a la funcion inicial







}


int buscaAlumno(int niaseleccionado,struct sListaAlumnos lAlumnos)
{

    int i=0;//declaración de variables
    int valor=-1;
    while(i<lAlumnos.num)//bucle while que recorre todo los los alumnos registrados
    {
        if(lAlumnos.vAlumnos[i].nia==niaseleccionado)
        {
            //si el nia de uno de los alumno coincide con el valor de niaseleccionado(nia del alumno que queremos eliminar), se da el valor de la posicion del vector numerosNIA a la variable valor
            valor=i;
            i++;
        }
        else
            i++;


    }

    return valor;//devolvemos valor que sera:   -la posicion del vector numerosNIA del alumno a eliminar, si alguno de los nias de los alumnos coincide con el nia introducido.
    //  - el valor -1 si no coincide con ninguno


}



bool guardaListaAlumnosSYS ( int NUM_AL, struct sAlumno alumnos[])//reenvia la lista de alumnos a guardaListAlumnosAD
{
    int valor_retorno;

    valor_retorno=guardaListaAlumnosAD(NUM_AL, alumnos);
    if(valor_retorno==0)
    {
        //todo ha ido bien
        return true;
    }

    else
    {
        return false;


    }





}

bool cargaListaAlumnosSYS_bin(struct sListaAlumnos *plAlumnos)//reenvia la direccion de la lista de alumnos que recibe a cargaListaAlumnosAD
{
    int valor_retorno;

    valor_retorno=cargaListaAlumnosAD_bin(plAlumnos);
    if(valor_retorno==0)
    {
        //todo ha ido bien
        return true;
    }

    else
    {
        return false;


    }





}


void convertirTxt2Bin()//funcion para convertir un archivo de texto en un archivo binario
{

    struct sListaAlumnos lAlumnos= {0};//se declara e inicializa la lista

    lAlumnos.vAlumnos = (struct sAlumno*)calloc(sizeof(struct sAlumno), 80);//reservamos memoria con un valor generico de alumnos, por ejemplo 80.
     if(lAlumnos.vAlumnos == NULL)
    {
    printf("No hay memoria suficiente.");
    exit(0);
    }

    lAlumnos.num=cargaListaAlumnosSYS(lAlumnos.vAlumnos);//la funcion cargalistaAlumnosSYS devuelve el numero de alumnos que se almacena en el registro num de la lista

    lAlumnos.vAlumnos = realloc(lAlumnos.vAlumnos,(lAlumnos.num) * sizeof(struct sAlumno));//ahora se actualiza la memoria reservada con el numero real de alumnos.

    guardaListaAlumnosSYS_bin(lAlumnos);//se envian los datos a la funcion guardalistaAlumnos que creara un nuevo archivo binario con los datos de los alumnos almacenados.




    if(lAlumnos.vAlumnos == NULL)
    {
        printf("No hay memoria suficiente.");
        exit(0);
    }
    else
    {
        gotoxy(22,32);
        printf("Se ha generado correctamente alumnos.dat    <Pulsa intro para seleccionar otra opción>");

    }

    free(lAlumnos.vAlumnos);//se libera la memoria

}

bool guardaListaAlumnosSYS_bin(struct sListaAlumnos lAlumnos)
{
    int valor_retorno;
    valor_retorno=guardaListaAlumnosAD_bin(lAlumnos);

    if(valor_retorno==0)
    {
        //todo ha ido bien
        return true;
    }

    else
    {
        return false;


    }




}



void convertirBin2Txt()//funcion que convierte los datos de un archivo binario a uno de texto
{

    //declaracion de variables
    struct sListaAlumnos lAlumnos;
    bool exito;


    cargaListaAlumnosSYS_bin(&lAlumnos);

    exito=guardaListaAlumnosSYS(lAlumnos.num, lAlumnos.vAlumnos);

    if(exito==false)
    {
        gotoxy(22,32);
        printf("Ha habido un error y no se ha generado correctamente el archivo");

    }
    else
    {

        gotoxy(22,32);
        printf("Se ha generado correctamente alumnos.txt    <Pulsa intro para seleccionar otra opción>");


    }



    free(lAlumnos.vAlumnos);


}

//he creado dos funciones auxiliares iguales a la buscaAlumno inicial para cada una de las listas
int buscaAlumno1(int niaseleccionado,struct sListaAlumnos lAlumnos1)
{

    int i=0;//declaración de variables
    int valor=-1;
    while(i<lAlumnos1.num)//bucle while que recorre todo los los alumnos registrados
    {
        if(lAlumnos1.vAlumnos[i].nia==niaseleccionado)
        {
            //si el nia de uno de los alumno coincide con el valor de niaseleccionado(nia del alumno que queremos eliminar), se da el valor de la posicion del vector numerosNIA a la variable valor
            valor=i;
            i++;
        }
        else
            i++;


    }

    return valor;//devolvemos valor que sera: -la posicion del vector cuyo registro de nia coincide con el elegido o bien,
    //                                          - el valor -1 si no coincide con ninguno


}

int buscaAlumno2(int niaseleccionado,struct sListaAlumnos lAlumnos2)
{

    int i=0;//declaración de variables
    int valor=-1;
    while(i<lAlumnos2.num)//bucle while que recorre todo los los alumnos registrados
    {
        if(lAlumnos2.vAlumnos[i].nia==niaseleccionado)
        {
            //si el nia de uno de los alumno coincide con el valor de niaseleccionado(nia del alumno que queremos eliminar), se da el valor de la posicion del vector numerosNIA a la variable valor
            valor=i;
            i++;
        }
        else
            i++;


    }

    return valor;//devolvemos valor que sera:   -la posicion del vector cuyo registro de nia coincide con el elegido o bien,
    //                                          - el valor -1 si no coincide con ninguno


}




float calculaPromedioNotas(struct sListaAlumnos lAlumnos, float notasmedias[])
{
    float notamax=0;
    int i;
    for(i=0; i<lAlumnos.num; i++)
    {
        notasmedias[i]=(lAlumnos.vAlumnos[i].nota1+lAlumnos.vAlumnos[i].nota2)/2;

        if(notasmedias[i]>notamax)
        {
            notamax=notasmedias[i];
        }



    }

    return notamax;


}

bool escribeListaAprobadosSYS(struct sListaAlumnos lAlumnos, float notasmedias[])
{

    int valor_retorno;

    valor_retorno=escribeListaAprobadosAD(lAlumnos, notasmedias);
    if(valor_retorno==0)
    {
        //todo ha ido bien
        return true;
    }

    else
    {
        return false;


    }






}

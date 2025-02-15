#include <stdio.h>
#include "../AD/alumnoAD.h"
#include "../IU/alumnoIU.h"
#include "../IU/interfazGrafica.h"
#include "../IU/interfazUsuario.h"
#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "../Entidades/alumnos.h"

int altaAlumnoAD(struct sAlumno alumnos)//recibe los datos de alumnosSYS y los muestra en alumnos.txt mediante un fprintf
{
    setlocale(LC_CTYPE, "Spanish");//deberia permitir poner ñ y acentos
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    FILE*archivo;
    int codigo_error;

    archivo=fopen("BaseDatos/alumnos.dat","ab");//comprueba que se puede abrir el archivo correctamente
    if (archivo == NULL)//no se ha abierto correctamente
    {
        codigo_error=-1;
        return codigo_error;
    }
    else//se ha abierto correctamente
    {
        codigo_error=0;
        fwrite(&alumnos, sizeof(struct sAlumno), 1, archivo);
        fclose(archivo);
        return codigo_error;

    }





}


int cargaListaAlumnosAD(struct sAlumno vAlumnos[])
{

    FILE*archivo;
    int i=0;


    archivo=fopen("BaseDatos/alumnos.txt", "rt");//abrimos el archivo en modo lectura
    if (archivo == NULL)//no se ha abierto correctamente
    {

        return -1;
    }
    else//se ha abierto correctamente
    {

        while(fscanf(archivo, "%d %c %f %f ", &vAlumnos[i].nia, &vAlumnos[i].sexo, &vAlumnos[i].nota1, &vAlumnos[i].nota2)==4)//lee todos los datos del archivo archivo y almacena los datos en los vectores paralelos
        {

            fgets(vAlumnos[i].nombre, 40, archivo);


            vAlumnos[i].nombre[strlen(vAlumnos[i].nombre)-1]='\0';//quitamos el espacio adicional que se genera en la memoria, para ello asignamos el valor del vector nombre en una variable tipo char
                                            //y le quitamos el espacio



            i++;


        }
        fclose(archivo);
        return i;//devuelve i que es el numero total de alumnos
    }





}


int guardaListaAlumnosAD(int NUM_AL, struct sAlumno alumnos[])
{

    FILE*archivo;
    archivo=fopen("BaseDatos/alumnos.txt","wt");//abrimos el archivo alumnos.txt en modo escritura


    if (archivo == NULL)//no se ha abierto correctamente
    {

        return -1;
    }
    else//se ha abierto correctamente
    {
        int i;



        for(i=0; i<NUM_AL; i++) //bucle for para recorrer la lista de alumnos y escribe los datos de cada jugador en el archivo, si y solo si el nia del alumno es distinto de 0.
        {
            if(alumnos[i].nia!=0)
            {
                fflush(stdin);


                fprintf(archivo,"%d %c %.1f %.1f %s\n", alumnos[i].nia, alumnos[i].sexo, alumnos[i].nota1, alumnos[i].nota2, alumnos[i].nombre);
            }




        }
        fclose(archivo);//cerramos el archivo
        return 0;


    }













}

int guardaListaAlumnosAD_bin(struct sListaAlumnos lAlumnos)
{

    FILE*archiv;

    archiv=fopen("BaseDatos/alumnos.dat","wb");

    if (archiv == NULL)//no se ha abierto correctamente
    {
        return -1;
    }
    else//se ha abierto correctamente
    {
        int i;


        for(i=0; i<lAlumnos.num; i++) //bucle for para recorrer la lista de alumnos y escribe los datos de cada jugador en el archivo, si y solo si el nia del alumno es distinto de 0.
        {
            if(lAlumnos.vAlumnos[i].nia!=0)
            {
                fflush(stdin);

                fwrite(&lAlumnos.vAlumnos[i],sizeof(struct sAlumno),1, archiv);
            }




        }
        fclose(archiv);//cerramos el archivo
        return 0;


    }





}


int cargaListaAlumnosAD_bin(struct sListaAlumnos *plAlumnos)//se cargan los datos de los alumnos desde el archivo binario alumnos.dat
{
    FILE*ptr;

    ptr=fopen("BaseDatos/alumnos.dat","rb");
    fseek(ptr, 0, SEEK_END);//se situa al final del archivo
    ftell(ptr);//cuenta las lineas del archivo y asi se puede determinar el numero de alumnos para reservar la memoria.
    plAlumnos->num = ftell(ptr)/sizeof(struct sAlumno);
    plAlumnos->vAlumnos = (struct sAlumno*)
    calloc(sizeof(struct sAlumno), plAlumnos->num);
    if(plAlumnos->vAlumnos == NULL)
    {
    printf("No hay memoria suficiente.");
    exit(0);
    }
    fseek(ptr, 0, SEEK_SET);


    int i=0;
    if (ptr == NULL)//no se ha abierto correctamente
    {

        return -1;
    }
    else//se ha abierto correctamente
    {
        while(fread(&plAlumnos->vAlumnos[i], sizeof(struct sAlumno), 1, ptr)==1)//lee todos los datos del archivo binario y almacena los datos en los registros correspondientes
        {


            i++;


        }

        fclose(ptr);
        return 0;//
    }






}

int escribeListaAprobadosAD(struct sListaAlumnos lAlumnos, float notasmedias[])
{

    FILE*archivo;
    int i;

    archivo=fopen("BaseDatos/aprobados.txt","wt");

    if (archivo == NULL)//no se ha abierto correctamente
    {
        return -1;
    }
    else//se ha abierto correctamente
    {

    for(i=0; i<lAlumnos.num; i++) //bucle for para recorrer la lista de alumnos y escribe los datos de cada jugador en el archivo, si y solo si el nia del alumno es distinto de 0.
        {
            if(notasmedias[i]>=5)
            {
                fflush(stdin);


                fprintf(archivo,"%d %s %.2f\n", lAlumnos.vAlumnos[i].nia, lAlumnos.vAlumnos[i].nombre, notasmedias[i]);
            }




        }

        fclose(archivo);
        return 0;
    }


}












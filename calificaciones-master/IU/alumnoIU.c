#include <stdio.h>
#include "../IU/alumnoIU.h"
#include "../IU/interfazGrafica.h"
#include "../SYS/alumnosSYS.h"
#include <stdbool.h>
#include "../AD/alumnoAD.h"
#include "../IU/interfazUsuario.h"
#include <windows.h>
#include <locale.h>
#define NUM_ALUM 100
#include <string.h>
#include "../Entidades/alumnos.h"
#include <stdlib.h>


void gestionMenuAlumnos()//funcion de alumnos del menu
{

    //Declaracion de variables
    int opcion_elegida;


    borraVentana(1,7,55,20);//borra donde se meten los numeros
    borraVentana(60, 7, 54, 20);
    borraVentana(21,29,70,1);
    borraVentana(1,34,30,1);
    borraVentana(2,4,53,1);


    opcion_elegida=menuAlumnos();//recogemos la opcion elegida de la funcion menuAlumnos en una variable


    while(opcion_elegida!=0)//bucle con las opciones del menu del que se saldrá cuando se elija la opcion "0"

    {

        switch(opcion_elegida) //sentencia de control selectiva con las diferentes opciones del menu
        {

        case 1:
            listadoAlumnos();//llamada a la funcion que muestra la lista de alumnos
            break;

        case 2:
            altaAlumnoIU();// llamada a la funcion para inscribir a un alumno
            break;

        case 3:
            bajaAlumnoIU();// llamada a la funcion para dar de baja a un alumno
            break;

        case 4:
            alumnosPorAsignaturas();// llamada a la funcion para dar de baja a un alumno
            break;

        case 5:
            generaListaprobados();// llamada a la funcion para dar de baja a un alumno
            break;

        case 6:
            alumnosPorSexo();// llamada a la funcion para dar de baja a un alumno
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
        gotoxy(20,4);
        printf("GESTION DE ALUMNOS");//se vuelve a poner la cabecera despues de borrar los mensajes que pudiera haber
        borraVentana(57,3,63,25);
        fflush(stdin);
        opcion_elegida=menuAlumnos();
    }
    return;


}


int menuAlumnos()//funcion que muestra la lista de opciones, recoge la opcion elegida y se la manda a gestionAlumnos.
{

    int opcion;//declaracion de variables

    setlocale(LC_CTYPE, "Spanish");//deberia permitir poner ñ y acentos
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


    gotoxy(1,9);

    printf("\t1. Listado de Alumnos\n");
    printf("\t2. Tramitar Alta de un alumno\n");
    printf("\t3. Tramitar baja de un alumno\n");
    printf("\t4. Alumnos por asignaturas\n");
    printf("\t5. Genera lista de aprobados\n");
    printf("\t6. Alumnos por sexo\n");
    printf("\t0. Volver al menu principal");

    printf("\n\n\tSelecciona una opción: ");
    scanf("%d",&opcion);


    return opcion;





}

void listadoAlumnos()//funcion que muestra la lista de alumnos
{
    struct sListaAlumnos lAlumnos;//declaracion de una lista de alumnos
    bool error;
    inicInterfazUsuario3();//insertamos la funcion de interfaz necesaria para este apartado

    error=cargaListaAlumnosSYS_bin(&lAlumnos);//llamada a la funcion cargalistaAlumnos_bin(SYS y posteriormente AD) que carga en el correspondiente registro del vector de la lista los datos de los alumnos.
    //devuelve el true si todo ha ido bien o false si ha habido algún error y se recoge en la variable error
    //sentencia de control selectiva con los diferentes casos mencionados previamente
    if (error ==false)
    {
        borraVentana(21,29,65,1);
        borraVentana(57,3,63,25);
        gotoxy(21,29);
        printf("Se ha producido un error");
    }
    else
    {
        muestraListaAlumnos(lAlumnos);
        //llamada a la función muestraListaAlumnos que muestra en pantalla la lista de alumnos con sus datos correspondientes en forma de tabla

    }

    free(lAlumnos.vAlumnos);
}
void bajaAlumnoIU()
{//funcion para dar de baja a un alumno

    //declaracion de vectores
    struct sListaAlumnos lAlumnos;//declaracion de la lista de alumnos
    int niaseleccionado;
    int valor_devuelto;
    bool exitoo;


    cargaListaAlumnosSYS_bin(&lAlumnos);//se invoca a la función cargaListaAlumnosSYS() que carga en el correspondiente registro del vector de la lista los datos de los alumnos del archivo binario alumnos.dat
    //se muestra la lista de alumnos con los datos correspondientes




    inicInterfazUsuario3();//funcion de interfaz para mostrar la lista de alumnos

    muestraListaAlumnos(lAlumnos);//funcion para mostrar la lista de alumonos

    gotoxy(21,29);
    printf("Escriba el numero NIA del alumno que quiere eliminar: ");//pide el numero nia del alumno al cual queremos eliminar
    fflush(stdin);
    scanf("%d",&niaseleccionado);
    fflush(stdin);                  //se recoge y se almacena en la variable niaseleccionado

    valor_devuelto=buscaAlumno(niaseleccionado, lAlumnos);//se invoca a la funcion buscaAlumno que busca el alumno que coincide con el nia del alumno al que queremos eliminar.

    if(valor_devuelto==-1)//el niaseleccionado no ha coincidido con ninguno de los nias de la lista
    {
        borraVentana(21,29,65,1);

        borraVentana(57,3,63,25);
        gotoxy(21,29);
        printf("El alumno no esta registrado");
        fflush(stdin);
    }

    else//ha habido coincidencia
    {
        lAlumnos.vAlumnos[valor_devuelto].nia=0;//asignamos el valor 0 al elemento del vector numernosNIA que queremos eliminar.
        exitoo=guardaListaAlumnosSYS_bin(lAlumnos);//se invoca a la funcion guardaListaALumnos para actualizar la lista sin el alumno eliminado

        if(exitoo == true)//todo ha ido bien
        {
            borraVentana(21,29,65,1);
            borraVentana(57,3,63,25);
            gotoxy(21,29);
            printf("El alumno ha sido eliminado con exito");



        }
        else//se ha producido un error
        {
            borraVentana(21,29,30,1);
            borraVentana(63, 7, 56, 20);
            gotoxy(21,29);
            printf("No ha sido posible eliminar al alumno correctamente");

        }




    }



    free(lAlumnos.vAlumnos);
    borraVentana(63, 7, 54, 20);

}

void altaAlumnoIU()//funcion para dar de alta a un alumno
{
    //declaracion de variables
    struct sAlumno alumnos={0};

    struct sListaAlumnos lAlumnos={0};//declaramos una lista de alumnos inicializando los valores a 0
    struct sListaAlumnos *plAlumnos;//puntero a la lista
    plAlumnos=&lAlumnos;//al meter un nuevo alumno tenemos que actualizar la memoria reservada y por ello hacemos uso de la funcion realloc y actualizamos la memoria para un alumno más
    plAlumnos->vAlumnos = realloc(plAlumnos->vAlumnos,(1+plAlumnos->num) * sizeof(struct sAlumno));
    bool exito;

    inicInterfazUsuario2();//llamada a la funcion que prepara la interfaz para esta funcion altaAlumnoIU
    gotoxy(21,29);

    printf("Introduce numero: ");//Introduccion de datos y muestra de los mismos
    scanf("%d",&alumnos.nia);
    borraVentana(21,29,50,1);
    gotoxy(2,8);
    printf("NIA: %d",alumnos.nia);
    gotoxy(21,29);
    printf("Introduce nombre: ");
    fflush(stdin);
    gets(alumnos.nombre);
    borraVentana(21,29,50,1);
    gotoxy(2,9);
    printf("NOMBRE: %s", alumnos.nombre);
    gotoxy(21,29);
    printf("Introduzca sexo M o F: ");
    fflush(stdin);
    scanf("%c", &alumnos.sexo);
    gotoxy(2,10);
    printf("SEXO: %c", alumnos.sexo);
    gotoxy(21,29);
    printf("Introduzca nota examen 1: ");
    scanf("%f",&alumnos.nota1);
    borraVentana(21,29,30,1);
    gotoxy(2,11);
    printf("NOTA EXAMEN 1: %.2f", alumnos.nota1);
    gotoxy(21,29);
    printf("Introduzca nota examen 2: ");
    scanf("%f", &alumnos.nota2);
    gotoxy(2,12);
    printf("NOTA EXAMEN 2: %.2f", alumnos.nota2);

    exito=altaAlumnoSYS(alumnos);

    if(exito == true)//todo ha ido bien
    {

        gotoxy(21,29);
        if(alumnos.sexo=='M')//se muestra un mensaje en caso de que sea chico y otro en el caso de que sea chica
            printf("El alumno %s ha sido registrado con exito", alumnos.nombre);

        if(alumnos.sexo=='F')
            printf("La alumna %s ha sido registrado con exito", alumnos.nombre);

    }
    else//se ha producido un error
    {
        gotoxy(21,29);
        printf("No ha sido posible registrar al alumno %s correctamente", alumnos.nombre);

    }

    free(lAlumnos.vAlumnos);

}

void muestraAlumno(struct sAlumno alumnos)//funcion que muestra los datos leidos que le envia muestraListaAlumnos
{

    setlocale(LC_CTYPE, "Spanish");//  permite las tildes y los acentos que se muestran en pantalla
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    printf("%d  %c    %.2f   %.2f\t%s", alumnos.nia, alumnos.sexo, alumnos.nota1, alumnos.nota2, alumnos.nombre);



}

void muestraAlumnosinsexo(struct sAlumno alumnos)//funcion que muestra los datos leidos que le envia muestraListaAlumnos
{

    setlocale(LC_CTYPE, "Spanish");//  permite las tildes y los acentos que se muestran en pantalla
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    printf("%d     %.2f   %.2f\t%s", alumnos.nia, alumnos.nota1, alumnos.nota2, alumnos.nombre);



}


void muestraListaAlumnos(struct sListaAlumnos lAlumnos)
{
    int columna=59, fila=6;
    int i;
    for(i=0; i<lAlumnos.num; i++)//bucle for que recorre la lista de alumnos y envía los datos de cada alumno a la función muestraAlumno().
    {
        gotoxy(columna, fila=fila + 1);

        muestraAlumno(lAlumnos.vAlumnos[i]);
        if(fila==26)//cuando llega a la ultima fila que cabe en la tabla se repite el proceso, con un enter entre cada lista de alumnos
        {
            gotoxy(1,26);
            fflush(stdin);
            printf("Pulsa <Intro> para continuar");
            getchar();
            borraVentana(59, 7, 60, 20);
            columna=59;
            fila=6;



        }

    }

}


void alumnosPorAsignaturas()
{
    //declaracion de listas y variables
    struct sListaAlumnos lAlumnos1={0};//la de programacion
    struct sListaAlumnos lAlumnos2={0};//la de calculo
    float nota1;
    float nota2;
    char sexo;
    int nia;
    char prueba[30];
    char name[40];
    int columna=59, fila=6;
    int niaselec;
    int y;
    FILE*archivo;
    int i=0;
    int u=0;
    int z;
    int valor_devuelto1;
    int valor_devuelto2;

    char respuesta[4];
    strcpy(respuesta,"si");

    //1 //reserva memoria para ambos grupos






    //leer
    archivo=fopen("BaseDatos/alumnosPorAsignaturas.txt", "rt");//abrimos el archivo en modo lectura
    if (archivo == NULL)//no se ha abierto correctamente
    {

        return;
    }
    else//se ha abierto correctamente
    {
        while(fscanf(archivo, "%s", prueba)==1)//lee el primer dato del alumno que es la asignatura
        {

            if(strcmp(prueba,"Programacion")==0)//si la asignatura es programacion se guardan los datos en los registros de los alumnos de programacion
            {

                lAlumnos1.num++;
                lAlumnos1.vAlumnos = realloc(lAlumnos1.vAlumnos,(lAlumnos1.num) * sizeof(struct sAlumno));//ahora se actualiza la memoria reservada con el numero real de alumnos.

                fscanf(archivo, "%d %c %f %f ", &lAlumnos1.vAlumnos[i].nia, &lAlumnos1.vAlumnos[i].sexo, &lAlumnos1.vAlumnos[i].nota1, &lAlumnos1.vAlumnos[i].nota2);
                fgets(lAlumnos1.vAlumnos[i].nombre, 40, archivo);

                lAlumnos1.vAlumnos[i].nombre[strlen(lAlumnos1.vAlumnos[i].nombre)-1]='\0';
                i++;


            }
            else if(strcmp(prueba,"Calculo")==0)//si la asignatura es calculo se guardan los datos en los registros de los alumnos de calculo
            {

                lAlumnos2.num++;
                lAlumnos2.vAlumnos = realloc(lAlumnos2.vAlumnos,(lAlumnos2.num) * sizeof(struct sAlumno));//ahora se actualiza la memoria reservada con el numero real de alumnos.

                fscanf(archivo, "%d %c %f %f ", &lAlumnos2.vAlumnos[u].nia, &lAlumnos2.vAlumnos[u].sexo, &lAlumnos2.vAlumnos[u].nota1, &lAlumnos2.vAlumnos[u].nota2);
                fgets(lAlumnos2.vAlumnos[u].nombre, 40, archivo);
                lAlumnos2.vAlumnos[u].nombre[strlen(lAlumnos2.vAlumnos[u].nombre)-1]='\0';

                u++;

            }
            else//para cualquier otra asignatura
            {

                fscanf(archivo, "%d %c %f %f ", &nia, &sexo, &nota1, &nota2);
                fgets(name, 40, archivo);
                name[strlen(name)-1]='\0';
                gotoxy(22,32);
                printf("Los datos de %s sobre %s no se van a cargar en ninguna lista", name, prueba);
                fflush(stdin);
                getchar();
                borraVentana(22,32,90,1);



        }


        }
    }

    fclose(archivo);



    //se actualizan las memorias dinamicas con el numero real de alumnosuu



    //MOSTRAR LISTAS



    inicInterfazUsuario3();
    gotoxy(2,4);
    printf("\t\tLISTADO DE NOTAS PROGRAMACION");


    if(lAlumnos1.num==0)
    {
        gotoxy(24,29);
        printf("no hay notas de alumnos de esta asignatura");

    }else{

    for(y=0; y<lAlumnos1.num; y++)//bucle for que recorre la lista de alumnos y envía los datos de cada alumno a la función muestraAlumno().
    {
        gotoxy(columna, fila=fila + 1);



        muestraAlumno(lAlumnos1.vAlumnos[y]);
        if(fila==26)//cuando llega a la ultima fila que cabe en la tabla se repite el proceso, con un enter entre cada lista de alumnos
        {
            gotoxy(1,26);
            fflush(stdin);
            printf("Pulsa <Intro> para continuar");
            getchar();
            borraVentana(59, 7, 60, 20);
            columna=59;
            fila=6;



        }


    }

    }
    fflush(stdin);
    getchar();
    borraVentana(59, 7, 60, 20);
    borraVentana(2,4,50,1);
    gotoxy(2,4);
    printf("\t\tLISTADO DE NOTAS CALCULO");
    fila=6;

    if(lAlumnos2.num==0)
    {
        gotoxy(24,29);
        printf("no hay notas de alumnos de esta asignatura");

    }else{

    for(z=0; z<lAlumnos2.num; z++)//bucle for que recorre la lista de alumnos y envía los datos de cada alumno a la función muestraAlumno().
    {
        gotoxy(columna, fila=fila + 1);

        muestraAlumno(lAlumnos2.vAlumnos[z]);
        if(fila==26)//cuando llega a la ultima fila que cabe en la tabla se repite el proceso, con un enter entre cada lista de alumnos
        {
            gotoxy(1,26);
            fflush(stdin);
            printf("Pulsa <Intro> para continuar");
            getchar();
            borraVentana(59, 7, 60, 20);
            columna=59;
            fila=6;



        }


    }

    }
    //PIDE NIA
    fflush(stdin);
    getchar();



    while (strcmp(respuesta,"si")==0)
    {
    borraVentana(24,29,50,1);
    borraVentana(59, 7, 60, 20);
    gotoxy(24,29);
    printf("Introduzca el nia de un alumno: ");
    scanf("%d", &niaselec);
    valor_devuelto1=buscaAlumno1(niaselec, lAlumnos1);
    valor_devuelto2=buscaAlumno2(niaselec, lAlumnos2);

    if(valor_devuelto1==-1 && valor_devuelto2==-1)//si el nia seleccionado no esta en ninguno de los registros
    {
        borraVentana(24,29,70,1);
        gotoxy(24,29);
        printf("el alumno no se encuentra en uno o ambos registros");
        fflush(stdin);
        getchar();
    }else if(valor_devuelto2==-1)//si el nia seleccionado esta en el grupo de programacion
    {
    gotoxy(2,4);
    printf("\tLISTADO DE NOTAS DE %s", lAlumnos1.vAlumnos[valor_devuelto1].nombre);
    borraVentana(59,4,50,1);
    gotoxy(59,4);
    printf("\t\tNOTA 1  NOTA 2");
    gotoxy(59,8);
    setlocale(LC_CTYPE, "Spanish");//  permite las tildes y los acentos que se muestran en pantalla
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    printf("PROGRAMACION: ");
    printf("%.2f   %.2f", lAlumnos1.vAlumnos[valor_devuelto1].nota1, lAlumnos1.vAlumnos[valor_devuelto1].nota2);


    }else if(valor_devuelto1==-1)//el nia seleccionado esta en el grupo de calculo
    {
    gotoxy(2,4);
    printf("\tLISTADO DE NOTAS DE %s", lAlumnos2.vAlumnos[valor_devuelto2].nombre);

    borraVentana(59,4,50,1);
    gotoxy(59,4);
    printf("\t\tNOTA 1 NOTA 2");
    gotoxy(59,8);
    setlocale(LC_CTYPE, "Spanish");//  permite las tildes y los acentos que se muestran en pantalla
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);


    printf("CALCULO:\t");
    printf("%.2f   %.2f", lAlumnos2.vAlumnos[valor_devuelto2].nota1, lAlumnos2.vAlumnos[valor_devuelto2].nota2);


    }else
    {//el nia seleccionado esta en ambos grupos
    gotoxy(2,4);
    printf("\tLISTADO DE NOTAS DE %s", lAlumnos2.vAlumnos[valor_devuelto2].nombre);

    borraVentana(59,4,50,1);
    gotoxy(59,4);
    printf("\t\tNOTA 1 NOTA 2");
    setlocale(LC_CTYPE, "Spanish");//  permite las tildes y los acentos que se muestran en pantalla
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    gotoxy(59,8);
    printf("PROGRAMACION: ");
    printf("%.2f   %.2f", lAlumnos1.vAlumnos[valor_devuelto1].nota1, lAlumnos1.vAlumnos[valor_devuelto1].nota2);
    gotoxy(59,9);
    printf("CALCULO:\t");
    printf("%.2f   %.2f", lAlumnos2.vAlumnos[valor_devuelto2].nota1, lAlumnos2.vAlumnos[valor_devuelto2].nota2);




    }





    borraVentana(24,29,70,1);
    gotoxy(24,29);
    printf("¿Desea introducir otro  NIA (si o no)?: ");//si se selecciona si se repite el bucle si no se sale de este
    fflush(stdin);
    gets(respuesta);
    }

    borraVentana(24,29,70,1);
    gotoxy(24,29);
    printf("<Pulse intro para continuar>");
    free(lAlumnos1.vAlumnos);
    free(lAlumnos2.vAlumnos);

    }



void generaListaprobados()
{
    //declaracion de variables y estructuras
    float notamax;
    float *notasmedias;
    struct sListaAlumnos lAlumnos={0};
    bool exito;


    cargaListaAlumnosSYS_bin(&lAlumnos);//carga la lista de alumnos en los registros


    notasmedias=calloc(sizeof(notasmedias), lAlumnos.num);//reserva memoria para el vector dinamico de las notas medias


    notamax=calculaPromedioNotas(lAlumnos, notasmedias);//llama a la funcion y esta devuelve la nota media maxima de todos los alumnos

    borraVentana(24,29,40,1);
    gotoxy(24,29);
    printf("La nota media maxima es: %.1f ", notamax);
    fflush(stdin);
    getchar();
    borraVentana(24,29,40,1);

    muestraListaAprobados(lAlumnos, notasmedias);
    exito=escribeListaAprobadosSYS(lAlumnos, notasmedias);
    if(exito == true)
    {
        gotoxy(24,29);
        printf("El archivo de alumnos aprobados se ha generado correctamente");
    }else
    {
        gotoxy(24,29);
        printf("no se ha generado el archivo correctamente");
    }

    free(lAlumnos.vAlumnos);
    free(notasmedias);


}

void muestraListaAprobados(struct sListaAlumnos lAlumnos, float notasmedias[])
{
    int columna=59;
    int fila=6;
    int i;
    inicInterfazUsuario4();
    for(i=0; i<lAlumnos.num; i++)
    {
        if(notasmedias[i]>=5)
        {
            gotoxy(columna, fila=fila + 1);
            muestraAprobado(lAlumnos.vAlumnos[i].nia, lAlumnos.vAlumnos[i].nombre, notasmedias[i]);
            if(fila==26)//cuando llega a la ultima fila que cabe en la tabla se repite el proceso, con un enter entre cada lista de alumnos
            {
            gotoxy(1,26);
            fflush(stdin);
            printf("Pulsa <Intro> para continuar");
            getchar();
            borraVentana(59, 7, 60, 20);
            columna=59;
            fila=6;

            }



        }




    }
}

void muestraAprobado(int nia, char nombre [], float notamedia)
{


    setlocale(LC_CTYPE, "Spanish");//  permite las tildes y los acentos que se muestran en pantalla
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    printf("%d %-30.30s %.1f", nia, nombre, notamedia);



}




void alumnosPorSexo()
{
    struct sListaAlumnos L1={0};
    struct sListaAlumnos L2={0};
    char ficheroelegido [30];
    int u=0;
    int i=0;
    float sumahombres=0;
    float sumamujeres=0;
    float notamediahombres;
    float notamediamujeres;
    int y;
    int z;
    int t;
    int p;
    int fila=6;
    int j;
    int columna=59;
    FILE*ptr;
    char aux[40];
    char respuesta[5];

    strcpy(respuesta,"s");
    strcpy(aux,"BaseDatos/");
    struct sListaAlumnos lAlumnos={0};
    while (strcmp(respuesta,"s")==0){
    gotoxy(24,29);
    printf("Introduzca un nombre de fichero binario: ");
    fflush(stdin);
    scanf("%s", ficheroelegido);


    strcat(aux,ficheroelegido);
    strncat(aux, ".dat",4);

    ptr=fopen(aux, "rb");//abrimos el archivo en modo lectura


    //cargamos alumns

    if (ptr == NULL)//no se ha abierto correctamente
    {

        return;
    }

    else//se ha abierto correctamente
    {
        while(fread(&lAlumnos.vAlumnos[j], sizeof(struct sAlumno), 1, ptr)==1)//lee el primer dato del alumno que es la asignatura
        {

            if(lAlumnos.vAlumnos[j].sexo=='M')//son
            {

                L1.num++;
                L1.vAlumnos = realloc(L1.vAlumnos,(L1.num) * sizeof(struct sAlumno));//ahora se actualiza la memoria reservada con el numero real de alumnos.

                L1.vAlumnos[i]=lAlumnos.vAlumnos[j];

                L1.vAlumnos[i].nombre[strlen(L1.vAlumnos[i].nombre)-1]='\0';

                i++;


            }
            else if(lAlumnos.vAlumnos[j].sexo=='F')//
            {

                L2.num++;
                L2.vAlumnos = realloc(L2.vAlumnos,(L2.num) * sizeof(struct sAlumno));//ahora se actualiza la memoria reservada con el numero real de alumnos.

                L2.vAlumnos[i]=lAlumnos.vAlumnos[j];

                L2.vAlumnos[u].nombre[strlen(L2.vAlumnos[u].nombre)-1]='\0';


            }
            j++;
        }
    fclose(ptr);


        //nota media hombres

    for(y=0; y<L1.num; y++)
    {
        sumahombres= sumahombres + L1.vAlumnos[y].nota1;



    }

    notamediahombres=sumahombres/L1.num;

    gotoxy(24,29);
    printf("La nota media de teoria de los hombres es %f", notamediahombres);
    fflush(stdin);
    getchar();

     //notamedia mujeres

        for(z=0; z<L2.num; z++)
    {
        sumamujeres= sumamujeres + L2.vAlumnos[z].nota1;



    }

    notamediamujeres=sumamujeres/L2.num;

    gotoxy(24,29);
    printf("La nota media de teoria de las mujeres es %f", notamediamujeres);
    fflush(stdin);

    //
    if(notamediahombres>notamediamujeres)
    {
    inicInterfazUsuario3();
    gotoxy(2,4);
    printf("\t\tLISTADO DE HOMBRES");

    for(t=0; t<L1.num; t++)//bucle for que recorre la lista de alumnos y envía los datos de cada alumno a la función muestraAlumno().
    {
        gotoxy(columna, fila=fila + 1);

        muestraAlumnosinsexo(L1.vAlumnos[t]);//se crea una funcion igual a muestraAlumno pero sin sexo
        if(fila==26)//cuando llega a la ultima fila que cabe en la tabla se repite el proceso, con un enter entre cada lista de alumnos
        {
            gotoxy(1,26);
            fflush(stdin);
            printf("Pulsa <Intro> para continuar");
            getchar();
            borraVentana(59, 7, 60, 20);
            columna=59;
            fila=6;



        }







    }
    }else{


    inicInterfazUsuario3();
    gotoxy(2,4);
    printf("\t\tLISTADO DE MUJERES");

    for(p=0; p<L2.num; p++)//bucle for que recorre la lista de alumnos y envía los datos de cada alumno a la función muestraAlumno().
    {
        gotoxy(columna, fila=fila + 1);

        muestraAlumnosinsexo(L2.vAlumnos[p]);//se crea una funcion igual a muestraAlumno pero sin sexo
        if(fila==26)//cuando llega a la ultima fila que cabe en la tabla se repite el proceso, con un enter entre cada lista de alumnos
        {
            gotoxy(1,26);
            fflush(stdin);
            printf("Pulsa <Intro> para continuar");
            getchar();
            borraVentana(59, 7, 60, 20);
            columna=59;
            fila=6;



        }





    }
    }

    }

    borraVentana(24,29,70,1);
    gotoxy(24,29);
    printf("¿Desea introducir otro  fichero ('s' en caso afirmativo o 'n' en caso negativo)?: ");//si se selecciona si se repite el bucle si no se sale de este
    fflush(stdin);
    gets(respuesta);



    }
}


#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

struct sAlumno
{

    int nia;
    char nombre [40];
    float nota1, nota2;
    char sexo;
    char asignatura [30];


};

struct sListaAlumnos
{
    int num;
    struct sAlumno *vAlumnos;


};

#endif // ALUMNOS_H_INCLUDED

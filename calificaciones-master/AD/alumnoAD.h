#ifndef alumnoADh
#define alumnoADh
#include <windows.h>
#include <locale.h>
#include "../Entidades/alumnos.h"
int altaAlumnoAD(struct sAlumno alumnos);
int cargaListaAlumnosAD(struct sAlumno alumnos[]);
int guardaListaAlumnosAD(int NUM_AL, struct sAlumno alumnos[]);
int cargaListaAlumnosAD_bin(struct sListaAlumnos *plAlumnos);
int guardaListaAlumnosAD_bin(struct sListaAlumnos lAlumnos);
int escribeListaAprobadosAD(struct sListaAlumnos lAlumnos, float notasmedias[]);
#endif // alumnoAD.h

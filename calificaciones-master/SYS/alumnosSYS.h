#ifndef alumnosSYSh
#define alumnosSYSh
#include <stdbool.h>
#include "../Entidades/alumnos.h"
bool altaAlumnoSYS(struct sAlumno alumnos);
int cargaListaAlumnosSYS(struct sAlumno alumnos[]);
int buscaAlumno(int niaseleccionado, struct sListaAlumnos lAlumnos);
int buscaAlumno1(int niaseleccionado, struct sListaAlumnos lAlumnos1);
int buscaAlumno2(int niaseleccionado, struct sListaAlumnos lAlumnos2);
bool guardaListaAlumnosSYS (int NUM_AL, struct sAlumno vAlumnos[]);
bool guardaListaAlumnosSYS_bin(struct sListaAlumnos lAlumnos);
void convertirTxt2Bin();
void convertirBin2Txt();
bool cargaListaAlumnosSYS_bin(struct sListaAlumnos *plALumnos);
float calculaPromedioNotas(struct sListaAlumnos lAlumnos, float notasmedias[]);
bool escribeListaAprobadosSYS(struct sListaAlumnos lAlumnos, float notasmedias[]);
#endif // alumnosSYS.h

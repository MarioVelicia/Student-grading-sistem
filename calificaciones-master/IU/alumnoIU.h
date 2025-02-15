#ifndef alumnoIUh
#define alumnoIUh
#include <windows.h>
#include <locale.h>
#include "../Entidades/alumnos.h"
void altaAlumnoIU();
int menuAlumnos();
void gestionMenuAlumnos();

void bajaAlumnoIU();
void alumnosPorNota();
void muestraAlumno(struct sAlumno alumnos);
void listadoAlumnos();
void alumnosPorAsignaturas();
void muestraListaAlumnos(struct sListaAlumnos lAlumnos);
void muestraListaAprobados(struct sListaAlumnos lAlumnos, float notasmedias[]);
void muestraAprobado(int nia, char nombre [], float notamedia);
void generaListaprobados();
void muestraAlumnosinsexo(struct sAlumno alumnos);
void alumnosPorSexo();

#endif // alumnoIU.h

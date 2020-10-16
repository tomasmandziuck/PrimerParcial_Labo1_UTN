
#ifndef REPARACION_H_
#define REPARACION_H_



#endif /* REPARACION_H_ */
typedef struct
{
    int dia;
    int mes;
    int anio;
} eDate;
typedef struct
{
    int Id;
    int serie;
    int IdServicio;
    eDate fecha;
    int isEmpty;
} eRep;

typedef struct
{
    int Id;
    char descripcion [25];
    float precio;
} eSer;


void initRep (eRep Reparacion[], int cant);
void AltaRep(eRep Reparacion[], int cant);
void mostrarTodosRep(eRep Reparacion[],int cant);
void mostrarUnoRep(eRep Reparacion);
int AllEmptyRep(eRep Reparacion[], int cant);
void mostrarTodosServicios(eSer servicios[],int cant);
void mostrarUnoServicios(eSer servicios);

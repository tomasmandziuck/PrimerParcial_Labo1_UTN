
#ifndef REPARACION_H_
#define REPARACION_H_

#include "electrodomesticos.h"


typedef struct
{
    int Id;
    char nombre [25];
    char apellido [25];
} eCli;
typedef struct
{
    int dia;
    int mes;
    int anio;
} eDate;
typedef struct
{
    int Id;
    int IdElec;
    int IdServicio;
    eCli cliente;
    eDate fecha;
    int isEmpty;
} eRep;

typedef struct
{
    int Id;
    char descripcion [25];
    float precio;
} eSer;

/** \brief A la variable isEmpty de la estructura de eRep le pone un 1
 *
 * \param array eRep
 * \param tamanio del array
 * \return 0
 *
 */
void initRep (eRep Reparacion[], int cant);
/** \brief Busca un espacio vacio en el array eRep y pide datos para cargar
 *
 * \param array eRep
 * \param array eCli
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void AltaRep(eRep Reparacion[],eCli clientes[],eElec elec[], int cant);
/** \brief Recorre todos los indices del array Reparacion y ejecuta la funcion mostrarUnoRep
 *
 * \param array eRep
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosRep(eRep Reparacion[],int cant);
/** \brief Muestra los datos de una Reparacion del indice indicado
 *
 * \param un elementro del array eRep
 * \return 0
 *
 */
void mostrarUnoRep(eRep Reparacion);
/** \brief revisa que todos los indices del array eRep tengan un 1 en isEmpty
 *
 * \param array eRep
 * \param tamanio del array
 * \return flag 1 si estan vacios 0 si no
 *
 */
int AllEmptyRep(eRep Reparacion[], int cant);
/** \brief Recorre todos los indices del array servicios y ejecuta la funcion mostrarUnoServicios
 *
 * \param array eSer
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosServicios(eSer servicios[],int cant);
/** \brief Muestra los datos de un servicio del indice indicado
 *
 * \param un elementro del array eSer
 * \return 0
 *
 */
void mostrarUnoServicios(eSer servicios);

#endif

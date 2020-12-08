

#ifndef INFORMES_H_
#define INFORMES_H_
#include "reparacion.h"





/** \brief Recorre todos los indices del array electrodomesticos y ejecuta la funcion mostrarUno en los que tengan modelo 2020
 *
 * \param array eElec
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosElecMod(eElec elec[],eMarca marca[],ePro procedencia[],int cant);
/** \brief Recorre todos los indices del array electrodomesticos y ejecuta la funcion mostrarUno en los de la marca sony
 *
 * \param array eElec
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosElecMarc(eElec elec[],eMarca marca[],ePro procedencia[],int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de reparaciones mostrando todas las reparaciones del electrodomestico seleccionado
 *
 * \param array eElec
 * \param array eRep
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosRepPorElec (eElec elec[], eRep Reparacion[],int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de reparaciones muestra los electrodomesticos sin reparaciones
 *
 * \param array eElec
 * \param array eRep
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarElecSinRep (eElec elec[],eRep Reparacion[],eMarca marca[],ePro procedencia[],int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de reparaciones mostrando las reparaciones para el electrodomestico indicado
 *
 * \param array eElec
 * \param array eRep
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarRepPorElec(eElec elec[], eRep Reparacion[], int cant);
/** \brief Recorre todos los indices del array reparaciones mostrando el servicio mas usado
 *
 * \param array eRep
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarServicioPopular(eRep Reparacion[], int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de servicios calculando la recaudacion total de los servicios
 *
 * \param array eElec
 * \param array eSer
 * \param tamanio del array
 * \return 0
 *
 */
void mostarRecaudacion(eRep Reparacion[], eSer servicio[], int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de reparaciones mostrando las reparaciones por garantia
 *
 * \param array eElec
 * \param array eRep
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarGarantias(eElec elec[], eRep Reparacion[],eMarca marca[],ePro procedencia[], int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de reparaciones mostrando las reparaciones del modelo 2018
 *
 * \param array eElec
 * \param array eRep
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarRepModelo(eElec elec[], eRep Reparacion[],eMarca marca[],ePro procedencia[], int cant);
/** \brief Recorre todos los indices del array servicios y de reparaciones calculando la recaudacion del servicio mantenimiento
 *
 * \param array eSer
 * \param array eRep
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarRecudacionPorMant(eSer servicio[], eRep Reparacion[], int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de reparaciones mostrando las Marcas con mas refacciones
 *
 * \param array eElec
 * \param array eRep
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarMarcaConRef(eRep Reparacion[],eElec elec[],eMarca marca[], int cant);
/** \brief Recorre todos los indices del array electrodomesticos y de reparaciones mostrando las reparaciones en los electrodomesticos en la fecha indicada
 *
 * \param array eElec
 * \param array eRep
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostarRepElecPorFecha(eRep Reparacion[], eElec elec[],eMarca marca[],ePro procedencia[], int cant);


#endif

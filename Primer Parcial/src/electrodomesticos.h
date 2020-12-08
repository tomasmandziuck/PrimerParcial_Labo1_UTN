
#ifndef ELECTRODOMESTICOS_H_
#define ELECTRODOMESTICOS_H_





typedef struct
{
    int Id;
    int serie;
    int IdMarca;
    float modelo;
    int IdPro;
    int isEmpty;
} eElec;

typedef struct
{
    int Id;
    char Marca [15];
} eMarca;

typedef struct
{
    int Id;
    char Pais [15];
} ePro;


/** \brief Busca un espacio vacio en el array eElec y pide datos para cargar
 *
 * \param array eElec
 * \param array marca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void AltaElec(eElec elec[],eMarca marca[],ePro procedencia[], int cant,int* id);
/** \brief Recorre todos los indices del array electrodomesticos y ejecuta la funcion mostrarUno
 *
 * \param array eElec
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosElec (eElec elec[],eMarca marca[],ePro procedencia[],int cant);
/** \brief Muestra los datos de un electrodomestico del indice indicado
 *
 * \param un elementro del array eElec
 * \param array eMarca
 * \param array procedencia
 * \return 0
 *
 */

void mostrarUnoElec(eElec elec,eMarca marca[],ePro procedencia[]);

/** \brief Ejecuta el ordenamiento de burbuja por modelo y serie de forma ascendiente
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void ordenarMoySe(eElec elec[],int cant);

/** \brief A la variable isEmpty de la estructura de eElec le pone un 1
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void initElec (eElec elec[], int cant);
/** \brief Muestra todos los datos de los electrodomesticos te pide que elijas uno por id y abre un menu para elegir que dato modificar
 *
 * \param array eElec
 * \param array eMarca
 * \param tamanio del array
 * \return 0
 *
 */

void Modificacion (eElec elec[],eMarca marca[], ePro procedencia[],int cant);
/** \brief Da la baja logica al electrodomestico deseado reemplazando el 0 por un 1
 *
 * \param array eElec
 * \param array eMarca
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void Baja (eElec elec[],eMarca marca[], ePro procedencia[],int cant);
/** \brief revisa que todos los indices del array eElec tengan un 1 en isEmpty
 *
 * \param array eElec
 * \param tamanio del array
 * \return flag 1 si estan vacios 0 si no
 *
 */

int AllEmptyElec(eElec elec[], int cant);
/** \brief Recorre todos los indices del array marcas y ejecuta la funcion mostrarUnoMarca
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosMarca(eMarca marca[],int cant);
/** \brief Muestra los datos de una marca del indice indicado
 *
 * \param array eElec
 * \return 0
 *
 */

void mostrarUnoMarca(eMarca marcas);
/** \brief Recorre todos los indices del array procedencia y ejecuta la funcion mostrarUnoPro
 *
 * \param array procedencia
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosPro(ePro procedencia[],int cant);
/** \brief Muestra los datos de una procedencia del indice indicado
 *
 * \param array procedencia
 * \return 0
 *
 */
void mostrarUnoPro(ePro procedencia);

#endif

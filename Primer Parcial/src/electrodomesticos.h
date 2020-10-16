
#ifndef ELECTRODOMESTICOS_H_
#define ELECTRODOMESTICOS_H_



#endif /* ELECTRODOMESTICOS_H_ */

typedef struct
{
    int Id;
    int serie;
    float IdMarca;
    float modelo;
    int isEmpty;
} eElec;

typedef struct
{
    int Id;
    char Marca [15];
} eMarca;

/** \brief A la variable isEmpty de la estructura de eElec le pone un 1
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void AltaElec(eElec emp[],int cant);
/** \brief Recorre todos los indices del array empleado y ejecuta la funcion mostrarUno
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodosElec (eElec emp[],int cant);
/** \brief Muestra los datos de un empleado del indice indicado
 *
 * \param array eElec
 * \return 0
 *
 */

void mostrarUnoElec(eElec emp);

/** \brief Ejecuta el ordenamiento de burbuja por apellido y sector de forma ascendiente
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void ordenarMoySe(eElec emp[],int cant);

/** \brief Busca un espacio vacio en el array eElec y pide datos para cargar
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void initElec (eElec emp[], int cant);
/** \brief Muestra todos los datos de los empleados te pide que elijas uno por id y abre un menu para elegir que dato modificar
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */

void Modificacion (eElec emp[], int cant);
/** \brief Da la baja logica al empleado deseado reemplazando el 0 por un 1
 *
 * \param array eElec
 * \param tamanio del array
 * \return 0
 *
 */
void Baja (eElec emp[], int cant);
/** \brief revisa que todos los indices del array eElec tengan un 1 en isEmpty
 *
 * \param array eElec
 * \param tamanio del array
 * \return flag 1 si estan vacios 0 si no
 *
 */

int AllEmptyElec(eElec emp[], int cant);
/** \brief Calcula el promedio de todos los salarios cargados hasta el momento
 *
 * \param array eElec
 * \param tamanio del array
 * \return promedio
 *
 */

void mostrarTodosMarca(eMarca marca[],int cant);
void mostrarUnoMarca(eMarca marcas);

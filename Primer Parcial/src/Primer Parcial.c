#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "electrodomesticos.h"
#include "utn.h"
#include "servicio.h"
#include "informes.h"
#include "reparacion.h"
#define MAX 5

int main() {
	setbuf(stdout, NULL);
	int opcion = 0, flag1 = 0, flag2 = 0, id = 1;
	char seguir = 's';
	eElec elec[MAX];
	eRep reparacion[MAX];
	eCli clientes[MAX] = { { 0, "Rodrigo", "Bianchi" }, { 0, "Guido",
			"Campostrini" }, { 0, "Agustin", "Funes" }, { 0, "Tomas",
			"Mandziuck" }, { 0, "Federico", "Mandziuck" } };
	eMarca marcas[5] = { { 1000, "Wirpoll" }, { 1001, "Sony" }, { 1002,
			"Liliana" }, { 1003, "Gafa" }, { 1004, "Philips" } };
	eSer servicios[4] = { { 20000, "Garantia", 250 }, { 20001, "Mantenimiento",
			500 }, { 20002, "Repuestos", 400 }, { 20003, "Refaccion", 600 } };
	ePro procedencia[4] = { { 1, "Argentina" }, { 2, "China" }, { 3, "Taiwan" },
			{ 4, "EEUU" } };

	initElec(elec, MAX);
	initRep(reparacion, MAX);

	do {

		printf("1-  Alta Electrodomestico "
				"\n2-  Listar Electrodomesticos"
				"\n3-  Listar marcas"
				"\n4-  Listar servicios"
				"\n5-  Listar Procedencia"
				"\n6-  Baja Electrodomestico"
				"\n7-  Modificar Electrodomestico"
				"\n8-  Alta Reparacion"
				"\n9-  Listar Reparaciones"
				"\n10- Listar Electrodomesticos M2020"
				"\n11- Listar Electrodomesticos Sony"
				"\n12- Listar reparaciones por electrodomestico"
				"\n13- Listar electrodomesticos sin reparacion"
				"\n14- Listar Reparaciones totales por Electrodomestico"
				"\n15- Listar Servicio mas Pedido"
				"\n16- Listar Recaudacion segun fecha"
				"\n17- Listar Reparaciones por garantia"
				"\n18- Listar Reparaciones de Electrodomesticos modelo 2018"
				"\n19- Listar Recaudacion por mantenimiento"
				"\n20- Listar Marcas con mas Refacciones"
				"\n21- Listar Electrodomesticos En reparacion por fecha"
				"\n22- Salir");
		utn_getInt(&opcion, "\n", "opcion no valida", 1, 22, 90);
		switch (opcion) {
		case 1:

			AltaElec(elec, marcas, procedencia, MAX, &id);
			system("cls");
			break;
		case 2:
			flag1 = AllEmptyElec(elec, MAX);
			if (flag1 == 0) {
				system("cls");
				ordenarMoySe(elec, MAX);
				mostrarTodosElec(elec, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 3:
			system("cls");
			mostrarTodosMarca(marcas, MAX);
			break;
		case 4:
			system("cls");
			mostrarTodosServicios(servicios, 4);
			break;
		case 5:
			system("cls");
			mostrarTodosPro(procedencia, 4);
			break;
		case 6:
			flag1 = AllEmptyElec(elec, MAX);
			if (flag1 == 0) {
				system("cls");
				Baja(elec, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 7:
			flag1 = AllEmptyElec(elec, MAX);
			if (flag1 == 0) {
				Modificacion(elec, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 8:

			AltaRep(reparacion, clientes, elec, MAX);
			system("cls");
			break;

		case 9:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostrarTodosRep(reparacion, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 10:
			flag1 = AllEmptyElec(elec, MAX);
			if (flag1 == 0) {
				system("cls");
				mostrarTodosElecMod(elec, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 11:
			flag1 = AllEmptyElec(elec, MAX);
			if (flag1 == 0) {
				system("cls");
				mostrarTodosElecMarc(elec, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 12:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostrarTodosRepPorElec(elec, reparacion, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}

		case 13:
			flag1 = AllEmptyElec(elec, MAX);
			if (flag1 == 0) {
				system("cls");
				mostrarElecSinRep(elec, reparacion, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 14:
			flag1 = AllEmptyElec(elec, MAX);
			if (flag1 == 0) {
				system("cls");
				mostrarRepPorElec(elec, reparacion, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 15:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostrarServicioPopular(reparacion, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 16:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostarRecaudacion(reparacion, servicios, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 17:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostrarGarantias(elec, reparacion, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 18:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostrarRepModelo(elec, reparacion, marcas, procedencia, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 19:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostrarRecudacionPorMant(servicios, reparacion, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 20:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostrarMarcaConRef(reparacion, elec, marcas, MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 21:

			flag2 = AllEmptyRep(reparacion, MAX);
			if (flag2 == 0) {
				system("cls");
				mostarRepElecPorFecha(reparacion, elec, marcas, procedencia,
						MAX);
				break;
			} else {
				printf("\nse debe ingresar un dato primero\n");
				break;
			}
		case 22:
			seguir = 'n';
			break;
		}
	} while (seguir == 's');

	return 0;
}

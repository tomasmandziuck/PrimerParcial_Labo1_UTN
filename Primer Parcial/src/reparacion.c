#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "electrodomesticos.h"
#include "reparacion.h"
#include "utn.h"



void initRep (eRep Reparacion[], int cant)
{

    int i;
    for(i=0; i<cant; i++)
    {
        Reparacion[i].isEmpty=1;
    }

}
void AltaRep(eRep Reparacion[],eCli clientes[],eElec elec[], int cant)
{
    int i;
    int o;
    int auxID;
    int cont=0;


    for(i=0;i<cant;i++){
    	if(elec[i].isEmpty==0){
    		cont++;
    	}
    }
    for(i=0;i<cant; i++){
    	strcpy(Reparacion[i].cliente.nombre,clientes[i].nombre);
    	strcpy(Reparacion[i].cliente.apellido,clientes[i].apellido);

    }
    for(i=0; i<cant; i++)
    {

        if(Reparacion[i].isEmpty==1)
        {

            Reparacion[i].Id = (i+1);
            utn_getInt(&Reparacion[i].IdElec, "\ningresar Id del Electrodomestico:1 a 5:\n", "Id no valido", 1,cont,90);
            printf("\n%s\n%s",Reparacion[i].cliente.nombre,Reparacion[i].cliente.apellido);
            utn_getInt(&auxID, "\ningresar Id para el cliente:1 a 5:\n", "Id no valido", 1,5,90);
            for(o=0;o<cant;o++){
            while(auxID==Reparacion[o].cliente.Id){
            		printf("Este id ya existe");
            		utn_getInt(&auxID, "\ningresar Id para el cliente:1 a 5:\n", "Id no valido", 1,5,90);
            }
            }
            Reparacion[i].cliente.Id=auxID;
            utn_getInt(&Reparacion[i].IdServicio, "\ningresar Servicio a realizar por Id\n20000 Garantia: $250 \n20001 Mantenimiento: $500 \n20002 Repuestos: $400 \n20003 Refaccion: $600\n", "Servicio no valido",20000,20004,90);
            utn_getInt(&Reparacion[i].fecha.dia, "\ningresar dia:", "dia no valido", 1,31,90);
            utn_getInt(&Reparacion[i].fecha.mes, "\ningresar mes:", "mes no valido", 1,12,90);
            utn_getInt(&Reparacion[i].fecha.anio, "\ningresar anio de 2018 a 2020:", "a�o no valido", 2018,2020,90);
            Reparacion[i].isEmpty=0;

            printf("\nId:%d\nId cliente:%d\nnombre:%s\napellido:%s\nId Electrodomestico:%d\nId Servicio:%d\nFecha:%d %d %d\n",Reparacion[i].Id,Reparacion[i].cliente.Id,Reparacion[i].cliente.nombre,Reparacion[i].cliente.apellido, Reparacion[i].IdElec, Reparacion[i].IdServicio,Reparacion[i].fecha.dia,Reparacion[i].fecha.mes,Reparacion[i].fecha.anio);
            system("pause");

            break;
        }

    }


}
void mostrarTodosRep(eRep Reparacion[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {


        if(Reparacion[i].isEmpty==0)
        {
            mostrarUnoRep(Reparacion[i]);
        }
        else
        {
            break;
        }
    }
    system("pause");
}

void mostrarUnoRep(eRep Reparacion)
{
    printf("\nId:%d\nId cliente:%d\nnombre:%s\napellido:%s\nId Electrodomestico:%d\nId Servicio:%d\nFecha:%d %d %d\n",Reparacion.Id,Reparacion.cliente.Id,Reparacion.cliente.nombre,Reparacion.cliente.apellido, Reparacion.IdElec, Reparacion.IdServicio,Reparacion.fecha.dia,Reparacion.fecha.mes,Reparacion.fecha.anio);
}


void mostrarTodosServicios(eSer servicios[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	mostrarUnoServicios(servicios[i]);

    }

}

int AllEmptyRep(eRep Reparacion[], int cant)
{

    int i;
    int flag=1;
    for(i=0; i<cant; i++)
    {
        if(Reparacion[i].isEmpty!=1)
        {
            flag=0;
        }
    }
    return flag;
}

void mostrarUnoServicios(eSer servicios)
{
    printf("\nId:%d\nDescripcion:%s\nPrecio:$%.0f\n",servicios.Id, servicios.descripcion,servicios.precio);
}



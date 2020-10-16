#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
void AltaRep(eRep Reparacion[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {

        if(Reparacion[i].isEmpty==1)
        {

            Reparacion[i].Id = (i+1);
            utn_getInt(&Reparacion[i].serie, "\ningresar Serie:1 a 5:\n", "Serie no valida", 1,5,3);
            utn_getInt(&Reparacion[i].IdServicio, "\ningresar Servicio a realizar por Id\n20000 Garantia: $250 \n20001 Mantenimiento: $500 \n20002 Repuestos: $400 \n20003 Refaccion: $600\n", "Servicio no valido",20000,20004,3);
            utn_getInt(&Reparacion[i].fecha.dia, "\ningresar dia:", "dia no valido", 1,31,3);
            utn_getInt(&Reparacion[i].fecha.mes, "\ningresar mes:", "mes no valido", 1,12,3);
            utn_getInt(&Reparacion[i].fecha.anio, "\ningresar anio:", "año no valido", 2018,2020,3);
            Reparacion[i].isEmpty=0;
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

}

void mostrarUnoRep(eRep Reparacion)
{
    printf("\nId:%d\nSerie:%d\nId Servicio:%d\nFecha:%d %d %d\n",Reparacion.Id, Reparacion.serie, Reparacion.IdServicio,Reparacion.fecha.dia,Reparacion.fecha.mes,Reparacion.fecha.anio);
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



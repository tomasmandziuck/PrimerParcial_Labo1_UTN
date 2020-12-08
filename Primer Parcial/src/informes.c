#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "reparacion.h"
#include "electrodomesticos.h"
#include "informes.h"
#include "utn.h"

#define MAX 5


void mostrarTodosElecMod(eElec elec[],eMarca marca[],ePro procedencia[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	if(elec[i].isEmpty==0 && elec[i].modelo==2020)
    	        {
    	            mostrarUnoElec(elec[i], marca,procedencia);
    	        }

    }
    system("pause");
}

void mostrarTodosElecMarc(eElec elec[],eMarca marca[],ePro procedencia[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	if(elec[i].isEmpty==0 && elec[i].IdMarca==1001)
    	        {
    	            mostrarUnoElec(elec[i],marca,procedencia);
    	        }

    }
    system("pause");
}

void mostrarTodosRepPorElec (eElec elec[],eRep Reparacion[],int cant)
{
    int i,o;
    int auxElec;
    int cont=0;


        for(i=0;i<cant;i++){
        	if(elec[i].isEmpty==0){
        		cont++;
        	}
        }

    utn_getInt(&auxElec, "\ningresar Id del Electrodomestico:\n", "Id no valido", 1,cont,90);

    		for(o=0;o<cant;o++){
			    if(Reparacion[o].IdElec==auxElec && Reparacion[o].isEmpty==0)
				{
			    	mostrarUnoRep(Reparacion[o]);


                }

    		}
    		 system("pause");
	}


void mostrarElecSinRep (eElec elec[],eRep Reparacion[],eMarca marca[],ePro procedencia[],int cant)
{
      int i,j;
      eElec elecAux[cant];

      for(i=0;i<cant; i++)
              {
    	  	  	  elecAux[i]=elec[i];
              }

        for(i=0;i<cant; i++)
        {
            for(j=0;j<cant;j++)
            {

                	if(elec[i].isEmpty==0 && elec[i].Id == Reparacion[j].IdElec)
                	{
                		elecAux[i].isEmpty=1;

                }

            }

    		if(elecAux[i].isEmpty==0){
    			mostrarUnoElec(elecAux[i],marca,procedencia);

    		}
        }
        system("pause");
	}

void mostrarRepPorElec(eElec elec[], eRep Reparacion[], int cant)
{
    int auxElec;
    int repCant = 0;
    int cont=0;
    int i;


            for(i=0;i<cant;i++){
            	if(elec[i].isEmpty==0){
            		cont++;
            	}
            }

    mostrarTodosRep(Reparacion,cant);
    utn_getInt(&auxElec, "\ningresar Id del Electrodomestico:\n", "Id no valido", 1,cont,90);
        for(i=0;i<cant;i++)
        {
          if(Reparacion[i].IdElec == auxElec && Reparacion[i].isEmpty==0)
          {
              repCant++;
          }
        }
        printf("El electrodomestico %d tiene %d reparaciones\n",auxElec,repCant);
        system("pause");

}


void mostrarServicioPopular(eRep Reparacion[], int cant)
{
    int contadorServicios[4] = {0,0,0,0};
    int servicioPopular = 0;
    int i;
    for(i = 0;i<cant;i++)
    {
        if(Reparacion[i].isEmpty == 0)
        {
            contadorServicios[Reparacion[i].IdServicio-19999]++;
        }

    }
    for(i=0;i<4;i++)
        {
            if(contadorServicios[i] > servicioPopular)
            {
            	servicioPopular = contadorServicios[i];

            }
        }

    for(i=0;i<4;i++)
    {
        if(contadorServicios[i] == servicioPopular)
        {
            servicioPopular = 19999 + i ;

        }
    }
    printf("servicio popular %d\n", servicioPopular);
    system("pause");
}

void mostarRecaudacion(eRep Reparacion[], eSer servicio[], int cant)
{
    int dia,mes,anio;
    int recaudacion=0;
    int i;
    int o;
    		mostrarTodosRep(Reparacion, cant);
    		utn_getInt(&dia,"\nIngrese fecha de reparacion\n Dia?\n","\nERROR\n",1,31,90);
    		utn_getInt(&mes,"\n Mes? \n","\nERROR\n",1,12,90);
    		utn_getInt(&anio,"\n Anio? \n","\nERROR\n",1950,2021,90);

                for(i = 0; i<cant;i++)
                {
                    if(Reparacion[i].fecha.dia == dia && Reparacion[i].fecha.mes == mes && Reparacion[i].fecha.anio == anio && Reparacion[i].isEmpty==0)
                    {
                        for(o = 0;o<cant; o++)
                        {

                            if(Reparacion[i].IdServicio == servicio[o].Id)
                            {
                                recaudacion += servicio[o].precio;
                            }
                        }

                    }

                }
                printf("La recaudacion de esa fecha es de %d\n",recaudacion);
                system("pause");


}

void mostrarGarantias(eElec elec[], eRep Reparacion[],eMarca marca[],ePro procedencia[], int cant)
{
	int i;
	int o;
    for(i = 0;i<cant;i++)
    {
        for(o = 0;o<cant;o++)
        {
            if(elec[i].Id == Reparacion[o].IdElec&& elec[i].isEmpty == 0 && Reparacion[o].isEmpty == 0 && Reparacion[o].IdServicio == 20000)
            {

            	mostrarUnoElec(elec[i],marca,procedencia);
                printf("%d/%d/%d\n", Reparacion[o].fecha.dia, Reparacion[o].fecha.mes, Reparacion[o].fecha.anio);
            }
        }
    }
    system("pause");
}

void mostrarRepModelo(eElec elec[], eRep Reparacion[],eMarca marca[],ePro procedencia[], int cant)
{
	int i;
	int o;
    for(i = 0;i<cant;i++)
    {
    	if(elec[i].modelo == 2018 && elec[i].isEmpty==0){
        for(o = 0;o<cant;o++)
        {
            if(elec[i].Id == Reparacion[o].IdElec&& elec[i].isEmpty == 0 && Reparacion[o].isEmpty == 0 )
            {
            	mostrarUnoElec(elec[i],marca, procedencia);
            	mostrarUnoRep(Reparacion[o]);
            }
        }
    }
    }
    system("pause");
}

void mostrarRecudacionPorMant(eSer servicio[], eRep Reparacion[], int cant)
{
	int i;
	int o;
	float recaudacion=0;
    for(i = 0;i<cant;i++)
    {

        for(o = 0;o<cant;o++)
        {
            if(servicio[i].Id == 20001 && servicio[i].Id == Reparacion[o].IdServicio && Reparacion[o].isEmpty == 0)
            {
            	recaudacion += servicio[i].precio;

            }
        }

    }
    printf("Total de Recaundacion %.0f\n",recaudacion);
    system("pause");
}

void mostrarMarcaConRef(eRep Reparacion[],eElec elec[],eMarca marca[], int cant)
{
    int contadorMarcas[5] = {0,0,0,0,0};
    int marcaPopular = 0;
    int i;
    int o;
    for(i = 0;i<cant;i++)
    {
    	for(o=0;o<cant;o++)
    	{
    		if(Reparacion[o].IdServicio == 20003 && elec[i].Id == Reparacion[o].IdElec && Reparacion[o].isEmpty == 0 && elec[i].isEmpty==0)
    		{
    			contadorMarcas[elec[i].IdMarca-999]++;
    		}
    	}

    }

    for(i=0;i<5;i++)
        {
            if(contadorMarcas[i] > marcaPopular)
            {
            	marcaPopular = contadorMarcas[i];

            }
        }

    for(i=0;i<5;i++)
    {
        if(contadorMarcas[i] == marcaPopular)
        {
        	marcaPopular = 999 + i ;

        }
    }
    for(i=0;i<cant;i++){
    	if(marcaPopular==marca[i].Id){
    		printf("Marca con mas refacciones %s\n", marca[i].Marca);
    	}
    }

    system("pause");
}

void mostarRepElecPorFecha(eRep Reparacion[], eElec elec[],eMarca marca[],ePro procedencia[], int cant)
{
    int dia,mes,anio;
    int i;
    int o;
    		mostrarTodosRep(Reparacion, cant);
    		utn_getInt(&dia,"\nIngrese fecha de reparacion\n Dia?\n","\nERROR\n",1,31,90);
    		utn_getInt(&mes,"\n Mes? \n","\nERROR\n",1,12,90);
    		utn_getInt(&anio,"\n Anio? \n","\nERROR\n",1950,2021,90);

                for(i = 0; i<cant;i++)
                {
                    if(Reparacion[i].fecha.dia == dia && Reparacion[i].fecha.mes == mes && Reparacion[i].fecha.anio == anio && Reparacion[i].isEmpty==0)
                    {
                        for(o = 0;o<cant; o++)
                        {

                            if(Reparacion[i].IdElec == elec[o].Id)
                            {
                            	mostrarUnoElec(elec[o],marca,procedencia);
                            }
                        }

                    }

                }
                system("pause");
}

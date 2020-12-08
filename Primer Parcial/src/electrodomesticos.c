#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "electrodomesticos.h"
#include "utn.h"
#define MAX 5

void AltaElec(eElec elec[],eMarca marca[],ePro procedencia[], int cant,int* id)
{
    int i,auxId;
    for(i=0; i<cant; i++)
    {

        if(elec[i].isEmpty==1)
        {
        	auxId=*id;
            elec[i].Id =auxId;
            utn_getInt(&elec[i].serie, "\ningresar Serie:1 a 5", "Serie no valida", 1,5,90);
            utn_getInt(&elec[i].IdMarca, "\ningresar Marca:\n1000 Wirpool\n1001 Sony\n1002 Liliana\n1003 Gafa\n1004 Philips\n", "Marca no valida", 1000,1004,90);
            utn_getFloat(&elec[i].modelo, "\ningresar modelo:1980 a 2020", "modelo no valido", 1980,2020,90);
            utn_getInt(&elec[i].IdPro, "\ningresar Procedencia:\n1 Argentina\n2 China\n3 Taiwan\n4 EEUU\n", "Marca no valida", 1,4,90);
            elec[i].isEmpty=0;
            mostrarUnoElec(elec[i],marca,procedencia);
            (*id)++;
            system("pause");
            break;
        }

    }


}



void mostrarTodosElec(eElec elec[],eMarca marca[],ePro procedencia[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	if(elec[i].isEmpty==0)
    	        {
    	            mostrarUnoElec(elec[i],marca,procedencia);
    	        }

    }
    system("pause");
}

void mostrarUnoElec(eElec elec,eMarca marca[],ePro procedencia[])
{
	int y,o;
	for(y=0;y<5;y++){
		for(o=0;o<4;o++){
	if(elec.IdMarca==marca[y].Id&&elec.IdPro==procedencia[o].Id){

    printf("\nId:%d\nSerie:%d\nMarca:%s\nModelo:%.0f\nProcedencia:%s\n",elec.Id, elec.serie, marca[y].Marca,elec.modelo,procedencia[o].Pais);
	}
	}
	}
}

void mostrarTodosMarca(eMarca marca[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	mostrarUnoMarca(marca[i]);

    }
    system("pause");
}

void mostrarUnoMarca(eMarca marcas)
{
    printf("\nId:%d\nMarca:%s\n",marcas.Id, marcas.Marca);
}
void mostrarTodosPro(ePro procedencia[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {

    	mostrarUnoPro(procedencia[i]);

    }
    system("pause");
}

void mostrarUnoPro(ePro procedencia)
{
    printf("\nId:%d\nPais:%s\n",procedencia.Id, procedencia.Pais);
}

void ordenarMoySe(eElec elec[],int cant)
{
    int i,j;
    eElec auxelec;
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(elec[i].modelo>elec[j].modelo)
            {
                auxelec=elec[i];
                elec[i]=elec[j];
                elec[j]=auxelec;
            }
            else
            {
                if(elec[i].modelo==elec[j].modelo && elec[i].serie==elec[j].serie)
            {
                    auxelec=elec[i];
                    elec[i]=elec[j];
                    elec[j]=auxelec;
                }
            }
        }
        break;
    }

}

void initElec (eElec elec[], int cant)
{

    int i;
    for(i=0; i<cant; i++)
    {
        elec[i].isEmpty=1;
    }

}

 void Baja (eElec elec[],eMarca marca[],ePro procedencia[], int cant)
{
    int auxId;
    int flag=0,i;
    char rta;
    mostrarTodosElec(elec,marca,procedencia, MAX);
    fflush(stdin);
    utn_getInt(&auxId, "que Id desea buscar?", "Id no encontrado", 1, 3, 3);
    for(i=0; i<cant; i++)
    {
        if(auxId==elec[i].Id)
        {
        	mostrarUnoElec(elec[i],marca,procedencia);
            do
            {
                printf("\nDesea borrar este registro s/n");
                fflush(stdin);
                scanf("%c",&rta);
                rta=tolower(rta);
            }
            while( rta != 's' && rta != 'n' );
            if(rta=='s')
            {
                elec[i].isEmpty=1;
            }
            else
            {
                printf("\nno se dio de baja\n");
            }

        }
        flag=1;

    }
    if (flag==0)
    {
        printf("no existe dato\n");
    }

}

void Modificacion (eElec elec[],eMarca marca[],ePro procedencia[], int cant)
{
    int auxId;
    int flag=0,i,OP;
    char seguir='s',rta;
    mostrarTodosElec(elec,marca,procedencia, cant);
    fflush(stdin);
    utn_getInt(&auxId, "Que Id desea buscar?", "Id no encontrado", 1, 3, 3);
    for(i=0; i<cant; i++)
    {
        if(auxId==elec[i].Id)
        {
        	mostrarUnoElec(elec[i],marca,procedencia);
            do
            {
                printf("\ndesea modificar este registro s/n");
                fflush(stdin);
                scanf("%c",&rta);
            }
            while(rta!='s'&&rta!='n');
            if(rta=='s')
            {
                do
                {

                    printf("\nQue desea modificar ?\n1- Serie\n2- Marca\n3- Modelo\n4- Procedencia\n5-salir\n");
                    utn_getInt(&OP, "\ningresar opcion", "opcion no valida", 1,5,3);
                    switch(OP)
                    {


                    case 1:
                    	utn_getInt(&elec[i].serie, "\ningresar modelo:1 a 5", "Serie no valida", 1,5,90);
                        system("cls");
                        break;

                    case 2:
                    	utn_getInt(&elec[i].IdMarca, "\ningresar modelo:\n1000 Wirpool\n1001 Sony\n1002 Liliana\n1003 Gafa\n1004 Philips\n", "modelo no valido", 1000,1004,90);
                        system("cls");
                        break;

                    case 3:
                    	utn_getFloat(&elec[i].modelo, "\ningresar modelo:1980 a 2020", "modelo no valido", 1980,2020,90);
                        system("cls");
                        break;
                    case 4:
                    	utn_getInt(&elec[i].IdPro, "\ningresar Procedencia:\n1 Argentina\n2 China\n3 Taiwan\n4 EEUU\n", "Marca no valida", 1,4,90);
                                            system("cls");
                                            break;
                    case 5:
                        seguir='n';
                        break;
                    }
                }
                while(seguir=='s');
            }
            else
            {
                printf("no se Modifico");
            }
        }
        flag=1;
    }
    if (flag==0)
    {
        printf("no existe dato");
    }
}

int AllEmptyElec(eElec elec[], int cant)
{

    int i;
    int flag=1;
    for(i=0; i<cant; i++)
    {
        if(elec[i].isEmpty!=1)
        {
            flag=0;
        }
    }
    return flag;
}


/*
 * informes.c
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "libreria_modelo_parcial.h"
#include "informes.h"
#include "biblioteca_sergio.h"
#define MENSAJE_OPCION "\ningrese una opcion\n"
#define MENSAJE_OPCION_ERROR "\nERROR re ingrese la opcion\n"
#define MAXIMO_OPCION 3
#define MINIMO_OPCION 0
#define MENSAJE "\ningrese un cuit\n"
#define MENSAJE_ERROR "\nERROR re ingrese el cuit\n"
#define MAXIMO 99999999999
#define MINIMO 1000
#define REINTENTOS 2

void mostrarMenuInformes() {
	printf("\n1)Cliente con mas pedidos PENDIENTES \n");
	printf("2)Cliente con mas pedidos COMPLETOS \n");
	printf("3)Cliente con mas pedidos \n");
	printf("4)Cliente que reciclo MAS kilos \n");
	printf("5)Cliente que reciclo MENOS kilos \n");
	printf("6)Cliente que reciclo mas de 1000 kilos \n");
	printf("7)Cliente que reciclo menos de 100 kilos  \n");
	printf("8)imprimir Pedidos COMPLETADOS mostrando ID de pedido,CUIT de cliente y porcentaje de plastico reciclado \n");
	printf("9)Ingresar localidad e indicar cantidad de pedidos PENDIENTES \n");
	printf("10)Cantidad de kilos de polipropileno reciclado por clientes \n");
	printf("11)Ingresar CUIT de un cliente y uno de los 3 tipos de plastico e informar cantidad de kilos totales \n");
	printf("12) SALIR\n");
}

void seleccionMenuInformes(Pedido *pedido,int sizePedido,Cliente *cliente,int sizeCliente) {
	int opcion;
	char salir;

	do {
		mostrarMenuInformes();
		printf("ingrese una opcion ");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			informe_ClienteMasPedidosPendientes(pedido, sizePedido, cliente,
					sizeCliente);
			break;

		case 2:
			informe_ClienteMasPedidosCompletados(pedido, sizePedido, cliente,
					sizeCliente);
			break;

		case 3:
			informe_ClienteMasPedidos(pedido, sizePedido, cliente,
					sizeCliente);
			break;
		case 4:
			informe_ClienteMenosKilos(pedido,sizePedido,cliente,sizeCliente);
			break;
		case 5:
			informe_ClienteMasKilos(pedido, sizePedido, cliente, sizeCliente);
			break;
		case 6:
			informe_ClienteMayorMilKilos(pedido, sizePedido, cliente,
								sizeCliente);
			break;
		case 7:
			informe_ClienteMenorCienKilos(pedido, sizePedido, cliente,
								sizeCliente);
			break;
		case 8:
			informe_ClienteImprimirCompletados(pedido, sizePedido, cliente,
								sizeCliente);
			break;
		case 9:
			Informes_listarPorLocalidadpedido(pedido, sizePedido, cliente,
				sizeCliente);
			break;
		case 10:
			informe_ClienteImprimirPolipropileno(pedido, sizePedido, cliente,
								sizeCliente);
			break;
		case 11:
			informe_ClienteInformarPlasticosCuit(pedido, sizePedido, cliente,
								sizeCliente);
			break;
		case 12:
			printf("esta seguro que desea salir?");
			scanf("%s", &salir);
			fflush(stdin);
			break;
		default:
			printf("\nOpcion no valida");
			}
			fflush(stdin);
		} while (salir != 's');
}

int informe_ClienteMasPedidosPendientes(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumPendiente=0;
	int pendienteMax;
	int indiceClienteMaximo;
	int flag=0;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{
				acumPendiente=0;
				for(j=0;j<sizePedido;j++){
					if(pedido[j].isEmpty==LLENO && pedido[j].estado==PENDIENTE && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumPendiente++;
					}
				}
				if(acumPendiente>pendienteMax||flag==0)
				{
					flag=1;
					pendienteMax=acumPendiente;
					indiceClienteMaximo=i;
				}
			}
		}
		printf("\ncliente con mas Pendientes es %s con un total de : %d pedidos pendientes \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteMasPedidosCompletados(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumPendiente=0;
	int pendienteMax;
	int indiceClienteMaximo;
	int flag=0;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{
				acumPendiente=0;
				for(j=0;j<sizePedido;j++){
					if(pedido[j].isEmpty==LLENO && pedido[j].estado==COMPLETADO && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumPendiente++;
					}
				}
				if(acumPendiente>pendienteMax||flag==0)
				{
					flag=1;
					pendienteMax=acumPendiente;
					indiceClienteMaximo=i;
				}
			}
		}
		printf("\nel cliente con mas Completos es %s con un total de : %d pedidos completados \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteMasPedidos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumPendiente=0;
	int pendienteMax;
	int indiceClienteMaximo;
	int flag=0;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{
				acumPendiente=0;
				for(j=0;j<sizePedido;j++){
					if(pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumPendiente++;
					}
				}
				if(acumPendiente>pendienteMax||flag==0)
				{
					flag=1;
					pendienteMax=acumPendiente;
					indiceClienteMaximo=i;
				}
			}
		}
		printf("\nel cliente con mas pedidos en general es %s con un total de : %d pedidos \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteMasKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumPeso=0;
	int pendienteMax;
	int indiceClienteMaximo;
	int flag=0;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{
				acumPeso=0;
				for(j=0;j<sizePedido;j++){
					if(pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumPeso=acumPeso+pedido[j].kilos;
					}
				}
				if(acumPeso>pendienteMax||flag==0)
				{
					flag=1;
					pendienteMax=acumPeso;
					indiceClienteMaximo=i;
				}
			}
		}
		printf("\nel cliente con mas kilos reciclados es %s con un total de : %d kg \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteMenosKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumPeso=0;
	int pesoMinimo;
	int indiceClienteMinimo;
	int flag=0;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{
				acumPeso=0;
				for(j=0;j<sizePedido;j++){
					if(pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumPeso=acumPeso+pedido[j].kilos;
					}
				}
				if(acumPeso<pesoMinimo||flag==0)
				{
					flag=1;
					pesoMinimo=acumPeso;
					indiceClienteMinimo=i;
				}
			}
		}
		printf("\nel cliente con Menos kilos reciclados es %s con un total de : %d kg \n",cliente[indiceClienteMinimo].nombre,pesoMinimo);
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteMayorMilKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumPeso=0;
	int ClientePedidos=0;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{
				acumPeso=0;
				for(j=0;j<sizePedido;j++)
				{
					if(pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumPeso=acumPeso+pedido[j].kilos;
					}
				}
				if(acumPeso>1000)
				{
					ClientePedidos++;
				}
			}
		}
		printf("\nla cantidad de clientes que reciclaron MAS de 1000 kilos en total es de : %d\n",ClientePedidos);
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteMenorCienKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumPeso=0;
	int ClientePedidos=0;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{
				acumPeso=0;
				for(j=0;j<sizePedido;j++)
				{
					if(pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumPeso=acumPeso+pedido[j].kilos;
					}
				}
				if(acumPeso<100)
				{
					ClientePedidos++;
				}
			}
		}
		printf("\nla cantidad de clientes que reciclaron MENOS de 100 kilos en total es de : %d\n",ClientePedidos);
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteImprimirCompletados(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	float porcentaje;
	float kilosReciclado;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{

				for(j=0;j<sizePedido;j++){
					kilosReciclado=0;
					if(pedido[j].isEmpty==LLENO && pedido[j].estado==COMPLETADO && pedido[j].idCliente == cliente[i].idCliente)
					{
						kilosReciclado=kilosReciclado+pedido[j].HDPE;
						kilosReciclado=kilosReciclado+pedido[j].LDPE;
						kilosReciclado=kilosReciclado+pedido[j].PP;
						porcentaje=(kilosReciclado*100)/pedido[j].kilos;

						printf("\nid Pedido:%d\nCuit Cliente: %ld\nel porcentaje reciclado es de :%f\n",pedido[j].idPedido,cliente[i].cuit,porcentaje);
					}
				}
			}
		}
		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int Informes_listarPorLocalidadpedido(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	int acumlocalidad = 0;
	char criterio[50];
	int i, j;
	printf("ingrese localidad a buscar\n");
	__fpurge(stdin);
	fgets(criterio, sizeof(criterio), stdin);
	criterio[(strlen(criterio)-1)]= '\0';
	if (pedido != NULL && cliente != NULL && sizePedido > 0
			&& sizeCliente > 0)
	{
		for (i = 0; i < sizeCliente; i++)
		{
			if (cliente[i].isEmpty == LLENO && strcmp(cliente[i].localidad, criterio)==0)
			{
				for (j = 0; j < sizePedido; j++)
				{
					if (pedido[j].estado==PENDIENTE && pedido[j].idCliente == cliente[i].idCliente)
					{
						acumlocalidad++;
					}
				}
			}
		}
		printf("\nla cantidad de pedidos Pendientes en %s es de %d\n", criterio,
				acumlocalidad);
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

int informe_ClienteImprimirPolipropileno(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	float porcentaje;
	int cantidadCliente=1;
	float kilosReciclado;
	int i, j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0 && sizeCliente > 0)
	{
		kilosReciclado=0;
		for (i=0;i<sizeCliente;i++)
		{
			if (cliente[i].isEmpty==LLENO)
			{

				for(j=0;j<sizePedido;j++){

					if(pedido[j].isEmpty==LLENO && pedido[j].estado==COMPLETADO && pedido[j].idCliente == cliente[i].idCliente)
					{
						cantidadCliente++;
						kilosReciclado=kilosReciclado+pedido[j].PP;
					}
				}
			}
		}
		porcentaje=kilosReciclado/cantidadCliente;
		printf("\nel porcentaje reciclado es de :%f\n",porcentaje);

		retorno=RETORNO_EXITOSO;
	}
		return retorno;
}

int informe_ClienteInformarPlasticosCuit(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente) {
	int retorno = ERROR;
	long cuit;
	float kilosReciclado;
	int posicion;
	int plastico;
	int j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0
			&& sizeCliente > 0) {
		if(getLong(&cuit, MAXIMO, MINIMO, REINTENTOS,MENSAJE,MENSAJE_ERROR)==RETORNO_EXITOSO)
		{
			if(Cliente_buscarCuit(cliente,sizeCliente,cuit,&posicion)==RETORNO_EXITOSO)
			{
				{	printf("elija que tipo de plastico desea\n1)HDPE\n2)LDPE\n3)PP\n");
					if (getInt(&plastico, MAXIMO_OPCION, MINIMO_OPCION, REINTENTOS,MENSAJE_OPCION,
							MENSAJE_OPCION_ERROR)==RETORNO_EXITOSO)
					{
						switch (plastico) {
							case 1:
							for (j = 0; j < sizePedido; j++) {
								if (pedido[j].isEmpty==LLENO && pedido[j].estado==COMPLETADO && pedido[j].idCliente == cliente[posicion].idCliente) {
									kilosReciclado = kilosReciclado + pedido[j].HDPE;
								}
							}
							break;
							case 2:
							for (j = 0; j < sizePedido; j++) {
								if (pedido[j].isEmpty==LLENO && pedido[j].estado==COMPLETADO && pedido[j].idCliente == cliente[posicion].idCliente) {
									kilosReciclado = kilosReciclado + pedido[j].LDPE;
								}
							}
							break;
							case 3:
							for (j = 0; j < sizePedido; j++) {
								if (pedido[j].isEmpty==LLENO && pedido[j].estado==COMPLETADO && pedido[j].idCliente == cliente[posicion].idCliente) {
									kilosReciclado = kilosReciclado + pedido[j].PP;
								}

							}
							break;
						}
					}
				}
			}
			retorno = RETORNO_EXITOSO;
		}
		printf("\nla cantidad total de plasticos del cliente %s es de: %f kg\n",
				cliente[posicion].nombre, kilosReciclado);
	}
	return retorno;
}

int Cliente_buscarCuit(Cliente cliente[], int size, long valorBuscado, int *posicion)
{
	int retorno = -1;
	int i;
	if (cliente != NULL && size >= 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cliente[i].isEmpty == LLENO && cliente[i].cuit == valorBuscado)
					{
				retorno = RETORNO_EXITOSO;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}


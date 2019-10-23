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
#define MINIMO 1000
#define REINTENTOS 2

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
		printf("el cliente con mas Pendientes es %s con un total de : %d pedidos pendientes \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
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
		printf("el cliente con mas Completos es %s con un total de : %d pedidos completados \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
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
		printf("el cliente con mas pedidos en general es %s con un total de : %d pedidos \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
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
		printf("el cliente con mas kilos recicaldos es %s con un total de : %d kg \n",cliente[indiceClienteMaximo].nombre,pendienteMax);
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
		printf("el cliente con Menos kilos recicaldos es %s con un total de : %d kg \n",cliente[indiceClienteMinimo].nombre,pesoMinimo);
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
		printf("la cantidad de clientes que reciclaron MAS de 1000 kilos en total es de : %d\n",ClientePedidos);
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
		printf("la cantidad de clientes que reciclaron MENOS de 100 kilos en total es de : %d\n",ClientePedidos);
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
			if (cliente[i].isEmpty == LLENO&& strcmp(cliente[i].localidad, criterio)==0)
			{
				for (j = 0; j < sizePedido; j++)
				{
					if (pedido[j].idCliente == cliente[i].idCliente)
					{
						acumlocalidad++;
					}
				}
			}
		}
		printf("\nla cantidad de pedidos en %s es de %d\n", criterio,
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
	int cantidadCliente=0;
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
		Cliente *cliente, int sizeCliente)
{
	int retorno = ERROR;
	long cuit;
	float kilosReciclado;
	int posicion;
	int plastico;
	int j;
	if (pedido != NULL && cliente != NULL && sizePedido > 0
			&& sizeCliente > 0)
	{
		printf("ingre numero de cuit");
		scanf("%ld",&cuit);
		if(Cliente_buscarCuit(cliente,sizeCliente,cuit,&posicion)==RETORNO_EXITOSO)
		{
			{printf("elija que tipo de plastico desea\n1)HDPE\n2)LDPE\n3)PP\n");
				if (getInt(&plastico, MAXIMO_OPCION, MINIMO_OPCION, REINTENTOS,MENSAJE_OPCION,
						MENSAJE_OPCION_ERROR)==RETORNO_EXITOSO)
				{
					switch (plastico) {
					case 1:
						for (j = 0; j < sizePedido; j++) {
							if (pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[posicion].idCliente) {
								kilosReciclado = kilosReciclado + pedido[j].HDPE;
							}
						}
						break;
					case 2:
						for (j = 0; j < sizePedido; j++) {
							if (pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[posicion].idCliente) {
								kilosReciclado = kilosReciclado + pedido[j].LDPE;
							}
						}
						break;
					case 3:
						for (j = 0; j < sizePedido; j++) {
							if (pedido[j].isEmpty==LLENO && pedido[j].idCliente == cliente[posicion].idCliente) {
								kilosReciclado = kilosReciclado + pedido[j].PP;
							}
						}
						break;
					}
				}
			}
		}
		printf("\nla cantidad total de plasticos del cliente %s es de: %f kg\n",cliente[posicion].nombre,kilosReciclado);
		retorno = RETORNO_EXITOSO;
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
				retorno = 0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}


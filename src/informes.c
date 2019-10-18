/*
 * informes.c
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include "libreria_modelo_parcial.h"
#include "informes.h"

int mayorCantidadPendiente(Pedido pedido[], int size, int *idclienteMaximo) {
	int retorno = ERROR;
	int contador;
	int numMax;
	int numMin;
	Informes indices[QTY_PEDIDOS];
	if (contadorPedidosPendientes(pedido, size, &contador,
			indices)==RETORNO_EXITOSO) {
			numMax = ;
	}
	for (i = 1; i < limite; i++) {
		if (pArray[i] > numMax) {
			numMax = pArray[i];
		}
	}
	return retorno;
}
int contadorPedidosPendientes(Pedido pedido[], int size, int *contador,
		Informes *indices) {
	int retorno = ERROR;
	int i;
	int j = 0;
	int acum = 0;
	if (pedido != NULL && size >= 0 && contador != NULL) {

		for (i = 0; i < size; i++) {
			if (pedido[i].estado == PENDIENTE && pedido[i].isEmpty == LLENO) {
				indices[j].idPedido = i;
				acum++;
				j++;
			}
		}
		*contador = acum;
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

int contadorPedidosCompletados(Pedido pedido[], int size, int *contador,
		Informes *indices) {
	int retorno = ERROR;
	int i;
	int j = 0;
	int acum = 0;
	if (pedido != NULL && size >= 0 && contador != NULL) {
		for (i = 0; i < size; i++) {
			if (pedido[i].estado == COMPLETADO && pedido[i].isEmpty == LLENO) {
				indices[j].idPedido = i;
				acum++;
				j++;
			}
		}
		*contador = acum;
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}
int PedidoBuscarID(Pedido pedido[], int size, int valorBuscado,
		int *posicion) {
	int retorno = ERROR;
	int i;
	if (pedido != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (pedido[i].idCliente == valorBuscado) {
				retorno = RETORNO_EXITOSO;
				*posicion = i;
				break;
			}

		}
	}
	return retorno;
}

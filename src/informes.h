/*
 * informes.h
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */

#ifndef INFORMES_H_
#define INFORMES_H_

typedef struct {
	int id;
	int idPedido;
	int isEmpty;
} Informes;
int contadorPedidosPendientes(Pedido pedido[], int size, int *contador,
		Informes *indices);
int contadorPedidosCompletados(Pedido pedido[], int size, int *contador,
		Informes *indices);

#endif /* INFORMES_H_ */

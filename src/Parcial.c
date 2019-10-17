/*
 ============================================================================
 Name        : Parcial.c
 Author      : Sergio Tirante
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreria_modelo_parcial.h"
#include <string.h>
int main(void) {

	int opcion;
	char salir;
	int contadorIdClientes = 0;
	int contadorIdPedidos = 0;
	int retorno = ERROR;

	Cliente cliente[QTY_CLIENTES];
	Pedido pedido[QTY_PEDIDOS];
	ClientInicializar(cliente, QTY_CLIENTES);
	pedidoInicializar(pedido, QTY_PEDIDOS);
	/*DATOS INICIALIZADOS*/
	Cliente aux0;
	Cliente aux1;
	Cliente aux2;
	Cliente aux3;
	Cliente aux4;
	aux0.idCliente = 1;
	strcpy(aux0.nombre, "pepito");
	strcpy(aux0.localidad, "floresta");
	strcpy(aux0.direccion, "rivadavia 750");
	aux0.cuit = 2042653;
	aux0.isEmpty = LLENO;
	cliente[0] = aux0;
	aux1.idCliente = 2;

	strcpy(aux1.nombre, "naranjas");
	strcpy(aux1.localidad, "caballito");
	strcpy(aux1.direccion, "mitre 750");
	aux1.cuit = 457821;
	aux1.isEmpty = LLENO;
	cliente[1] = aux1;

	aux2.idCliente = 3;
	strcpy(aux2.nombre, "Roberto");
	strcpy(aux2.localidad, "Micro centro");
	strcpy(aux2.direccion, "9 de julio 750");
	aux2.cuit = 147567;
	aux2.isEmpty = LLENO;
	cliente[2] = aux2;

	aux3.idCliente = 4;
	strcpy(aux3.nombre, "Luis");
	strcpy(aux3.localidad, "Barracas");
	strcpy(aux3.direccion, "España 750");
	aux3.cuit = 84142653;
	aux3.isEmpty = LLENO;
	cliente[3] = aux3;

	aux4.idCliente = 5;
	strcpy(aux4.nombre, "Juan");
	strcpy(aux4.localidad, "Ostende");
	strcpy(aux4.direccion, "rivadavia 3421");
	aux4.cuit = 214536;
	aux4.isEmpty = LLENO;
	cliente[4] = aux4;
	/*DATOS INICIALIZADOS*/
	fflush(stdin);
	do {
		mostrarMenu();
		printf("ingrese una opcion ");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {
		case 1: //Alta
			clienteAlta(cliente, QTY_CLIENTES, &contadorIdClientes);
			break;

		case 2:
			modificarPorId(cliente, QTY_CLIENTES);
			break;

		case 3:
			bajaCliente(cliente, contadorIdClientes);

			break;

		case 4:
			listarCliente(cliente, QTY_CLIENTES);
			pedidoAlta(pedido, QTY_PEDIDOS, &contadorIdPedidos,
					&contadorIdClientes);
			break;

		case 5:
			listarPedidosPendiente(pedido, QTY_PEDIDOS);
			ProcesarPedido(pedido, contadorIdPedidos);
			break;

		case 6:
			listarCliente(cliente, QTY_PEDIDOS);
			break;

		case 7:
			listarPedidosPendiente(pedido, QTY_PEDIDOS);

			break;
		case 8:
			listarPedidosCompletos(pedido, QTY_PEDIDOS);

			break;
		case 9:
			printf("esta seguro que desea salir?");
			scanf("%s", &salir);
			fflush(stdin);
			break;
		default:
			printf("\nOpcion no valida");
		}
		fflush(stdin);
	} while (salir != 's');
	return retorno;
}

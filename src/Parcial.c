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
#include <stdio_ext.h>
#include "libreria_modelo_parcial.h"
#include "informes.h"

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
	/*DATOS Hardcodeado*/
	cargaDatos(cliente);
	cargaPedidos(pedido);
	/*DATOS Hardcodeado*/
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
			informe_ClienteMasPedidosPendientes(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteMasPedidosCompletados(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteMasPedidos(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteMasKilos(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteMenosKilos(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteMayorMilKilos(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteMenorCienKilos(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteImprimirCompletados(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			Informes_listarPorLocalidadpedido(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteImprimirPolipropileno(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			informe_ClienteInformarPlasticosCuit(pedido,QTY_PEDIDOS,cliente,QTY_CLIENTES);
			break;
		case 10:
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

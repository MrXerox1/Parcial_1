/*
 * libreria_modelo _parcial.c
 *
 *  Created on: 30 sep. 2019
 *      Author: sergio
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "libreria_modelo_parcial.h"
#include "biblioteca_sergio.h"
#define MENSAJE "ingrese id "
#define MENSAJE_ERROR "error ese id no es valido "
#define MINIMO 0
#define REINTENTOS 2

int mostrarMenu() {
	int retorno = ERROR;
	printf("\n1. Alta cliente\n");
	printf("2. Modificar datos del cliente\n");
	printf("3. Baja del cliente\n");
	printf("4. Nuevo pedido\n");
	printf("5. Procesado de residuos\n");
	printf("6. Listar cliente: que poseen su estado en PENDIENTE \n");
	printf("7. INFORMAR:que poseen su estado en PENDIENTE \n");
	printf("8. INFORMAR:que poseen su estado en COMPLETADO \n");
	printf("9. SALIR\n");
	return retorno;
}

int ClientInicializar(Cliente cliente[], int size) {
	int retorno = -1;
	if (cliente != NULL && size > 0) {
		for (; size > 0; size--) {
			cliente[size - 1].isEmpty = VACIO;
		}
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

int clienteBuscarEmpty(Cliente cliente[], int size, int *posicion) {
	int retorno = ERROR;
	int i;
	if (cliente != NULL && size >= 0 && posicion != NULL) {
		for (i = 0; i < size; i++) {
			if (cliente[i].isEmpty == VACIO) {
				retorno = RETORNO_EXITOSO;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int clienteAlta(Cliente *cliente, int size, int *contadorID) {
	int retorno = ERROR;
	int posicion;
	if (cliente != NULL && size > 0 && contadorID != NULL) {
		if (clienteBuscarEmpty(cliente, size, &posicion) == ERROR) {
			printf("\nNo hay lugares vacios");
		} else {
			(*contadorID)++;
			ingresoCliente(&cliente[posicion]);
			cliente[posicion].idCliente = *contadorID;
			cliente[posicion].isEmpty = LLENO;
			printf("\nDatos Personales");
			printf("\n%s", cliente[posicion].nombre);
			printf("\n%s", cliente[posicion].direccion);
			printf("\n%s", cliente[posicion].localidad);
			printf("\n%d", cliente[posicion].cuit);
			printf("\n%d", cliente[posicion].idCliente);
			retorno = RETORNO_EXITOSO;
		}
	}
	return retorno;
}

int ingresoCliente(Cliente *cliente) {
	int retorno = ERROR;

	Cliente aux;
	__fpurge(stdin);
	printf("Ingrese el Nombre \n");
	__fpurge(stdin);
	fgets(aux.nombre, sizeof(aux.nombre), stdin);
	__fpurge(stdin);
	printf("\nIngrese el localidad \n");
	fgets(aux.localidad, sizeof(aux.localidad), stdin);
	printf("\nIngrese el direccion \n");
	fgets(aux.direccion, sizeof(aux.direccion), stdin);
	__fpurge(stdin);
	printf("\nIngrese numero de cuit \n");
	__fpurge(stdin);
	scanf("%d", &aux.cuit);

	*cliente = aux;

	retorno = RETORNO_EXITOSO;

	return retorno;
}

int clienteBuscarID(Cliente cliente[], int size, int valorBuscado,
		int *posicion) {
	int retorno = ERROR;
	int i;
	if (cliente != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (cliente[i].idCliente == valorBuscado) {
				retorno = RETORNO_EXITOSO;
				*posicion = i;
				break;
			}

		}
	}
	return retorno;
}
int modificarPorId(Cliente cliente[], int contadorId) {
	int retorno = ERROR;
	int id;
	char salir = 'n';
	int indice;
	int opcion;
	__fpurge(stdin);
	;
	if (getInt(&id, contadorId, MINIMO, REINTENTOS, MENSAJE, MENSAJE_ERROR)
			== 0) {
		if (clienteBuscarID(cliente, contadorId, id, &indice) == 0) {

			do {
				printf("\nElegir opcion a modificar");
				printf("\n1)Nombre: %s", cliente[indice].nombre);
				printf("\n2)localidad: %s", cliente[indice].localidad);
				printf("\n3)direccion: %s", cliente[indice].direccion);
				printf("\n4)cuit: %d", cliente[indice].cuit);
				printf("\n5)SALIR\n");
				__fpurge(stdin);
				;
				scanf("%d", &opcion);
				__fpurge(stdin);
				;
				switch (opcion) {
				case 1:
					__fpurge(stdin);
					printf("Ingrese el Nombre \n");
					__fpurge(stdin);
					fgets(cliente[indice].nombre,
							sizeof(cliente[indice].nombre),
							stdin);
					break;
				case 2:
					printf("\nIngrese el localidad \n");
					fgets(cliente[indice].localidad,
							sizeof(cliente[indice].localidad),
							stdin);

					break;
				case 3:
					printf("\nIngrese el direccion \n");
					fgets(cliente[indice].direccion,
							sizeof(cliente[indice].direccion),
							stdin);

					break;
				case 4:
					printf("\nIngrese numero de cuit \n");
					__fpurge(stdin);
					scanf("%d", &cliente[indice].cuit);
					break;

				case 5:
					printf("esta seguro de que quiere salir? s/n");
					scanf("%s", &salir);
					break;
				default:
					printf("\nOpcion no valida");
				}
			} while (salir != 's');
		} else {
			printf("error al modificar");
		}
		retorno=RETORNO_EXITOSO;
	}

	return retorno;
}

int bajaCliente(Cliente cliente[], int contadorId) {
	int retorno = ERROR;
	int id;
	int indice;
	__fpurge(stdin);
	;
	if (getInt(&id, contadorId, MINIMO, REINTENTOS, MENSAJE,
	MENSAJE_ERROR) == RETORNO_EXITOSO) {
		if (clienteBuscarID(cliente, contadorId, id, &indice) == RETORNO_EXITOSO) {
			if (cliente[indice].isEmpty == LLENO) {
				cliente[indice].isEmpty = VACIO;
				printf("el espacio de %d esta ahora vacio \n", id);
			} else {
				printf("[error] este id ya esta vacio");
			}
		}
	}
	return retorno;
}

int listarCliente(Cliente cliente[], int size) {
	int retorno = ERROR;
	int i;
	if (cliente != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			printf(
					"\n Nombre:%s\n Localidad:%s\n Direccion:%s\n Cuit:%d\nidCliente:%d\n",
					cliente[i].nombre, cliente[i].localidad,
					cliente[i].direccion, cliente[i].cuit,
					cliente[i].idCliente);
		}
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

/*--------------de aca para abajo son las funciones de pedido-----------*/

int pedidoAlta(Pedido *pedido, int size, int *contadorIDPedido,
		int *contadorIDCliente) {
	int retorno = ERROR;
	int posicion;
	if (pedido != NULL && size > 0 && contadorIDPedido != NULL) {
		if (pedidoBuscarEmpty(pedido, size, &posicion) == ERROR) {
			printf("\nNo hay lugares vacios");
		} else {
			(*contadorIDPedido)++;
			ingresoPedido(&pedido[posicion], *contadorIDCliente);
			pedido[posicion].idPedido = *contadorIDPedido;
			pedido[posicion].estado = PENDIENTE;
			pedido[posicion].isEmpty = LLENO;
			printf("\nDatos Personales");
			printf("\n%d", pedido[posicion].idCliente);
			if (pedido[posicion].estado == 1) {
				printf("CUMPLIDO");
			} else {
				printf("PENDIENTE");
			}
			printf("\n%d", pedido[posicion].kilos);
			retorno = RETORNO_EXITOSO;
		}
	}
	return retorno;
}

int pedidoInicializar(Pedido pedido[], int size) {
	int retorno = -1;
	if (pedido != NULL && size > 0) {
		for (; size > 0; size--) {
			pedido[size - 1].isEmpty = VACIO;
		}
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

int pedidoBuscarEmpty(Pedido pedido[], int size, int *posicion) {
	int retorno = ERROR;
	int i;
	if (pedido != NULL && size >= 0 && posicion != NULL) {
		for (i = 0; i < size; i++) {
			if (pedido[i].isEmpty == VACIO) {
				retorno = RETORNO_EXITOSO;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int ingresoPedido(Pedido *pedido, int contadorId) {
	int retorno = ERROR;
	int id;
	Pedido aux;
	__fpurge(stdin);
	printf("Ingrese el id del cliente \n");
	if (getInt(&id, contadorId, MINIMO, REINTENTOS, MENSAJE, MENSAJE_ERROR)
			== 0) {
		id = aux.idCliente;
		__fpurge(stdin);
	}
	printf("\nIngrese el peso en kilos de los plasticos \n");
	if (getInt(&id, KILO_MAXIMO, MINIMO, REINTENTOS, MENSAJE, MENSAJE_ERROR)
			== 0) {
		id = aux.kilos;
	}
	__fpurge(stdin);

	*pedido = aux;

	retorno = RETORNO_EXITOSO;

	return retorno;
}

int ProcesarPedido(Pedido *pedido, int contadorId) {
	int retorno = ERROR;
	int id;
	int cantidad;
	int indice;
	int maximo;
	__fpurge(stdin);
	;
	if (getInt(&id, contadorId, MINIMO, REINTENTOS, MENSAJE, MENSAJE_ERROR)
			== 0) {
		if (pedidoBuscarID(pedido, contadorId, id, &indice) == RETORNO_EXITOSO) {
			maximo = pedido[indice].kilos;
			if (getInt(&cantidad, maximo, MINIMO, REINTENTOS, MENSAJE,
			MENSAJE_ERROR) > 0) {
				if (maximo >= 0) {
					pedido[indice].HDPE = cantidad;
					maximo = maximo - cantidad;
				}
			}

			if (getInt(&cantidad, maximo, MINIMO, REINTENTOS, MENSAJE,
			MENSAJE_ERROR) > RETORNO_EXITOSO) {

				if (maximo >= RETORNO_EXITOSO) {
					pedido[indice].LDPE = cantidad;
					maximo = maximo - cantidad;
				}
			}

			if (getInt(&cantidad, maximo, MINIMO, REINTENTOS,
			MENSAJE,
			MENSAJE_ERROR) > RETORNO_EXITOSO) {
				if (maximo >= RETORNO_EXITOSO) {
					pedido[indice].PP = cantidad;
					maximo = maximo - cantidad;
				}

			}

		}
	}
	return retorno;
}

int pedidoBuscarID(Pedido *pedido, int size, int valorBuscado, int *posicion) {
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

int listarPedidosPendientes(Pedido pedido[], int size) {
	int retorno = ERROR;
	int i;
	if (pedido != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (pedido[i].estado == PENDIENTE && pedido[i].idPedido != 0) {
				printf(
						"\n idPedido:%d \n idCliente:%d \n kilos:%d \n HDPE:%d \n LDPE:%d \n  plasticoTres:%d \n",
						pedido[i].idPedido, pedido[i].idCliente,
						pedido[i].kilos, pedido[i].HDPE, pedido[i].LDPE,
						pedido[i].PP);
				printf("\nestado; PENDIENTE");
			}
		}
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}

int listarPedidosCompletos(Pedido pedido[], int size) {
	int retorno = ERROR;
	int i;
	if (pedido != NULL && size >= 0) {
		for (i = 0; i < size; i++) {
			if (pedido[i].estado == COMPLETADO && pedido[i].idPedido != 0) {
				printf(
						"\n idPedido:%d \n idCliente:%d \n kilos:%d \n HDPE:%d \n LDPE:%d \n  plasticoTres:%d \n",
						pedido[i].idPedido, pedido[i].idCliente,
						pedido[i].kilos, pedido[i].HDPE, pedido[i].LDPE,
						pedido[i].PP);
				printf("\nestado; COMPLETADO");
			}
		}
		retorno = RETORNO_EXITOSO;
	}
	return retorno;
}


/*
 * libreria_modelo_parcial.h
 *
 *  Created on: 30 sep. 2019
 *      Author: sergio
 */

#ifndef LIBRERIA_MODELO_PARCIAL_H_
#define LIBRERIA_MODELO_PARCIAL_H_
//cantida de arrays
#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000
//retornos
#define RETORNO_EXITOSO 0
#define ERROR -1
//isEmpty
#define VACIO 0
#define LLENO 1
//estado ambulancia
#define PENDIENTE 0
#define COMPLETADO 1
//kilos maximos
#define KILO_MAXIMO 200

typedef struct {
	int idCliente;
	char nombre[30];
	char direccion[30];
	char localidad[30];
	int cuit;
	int isEmpty;
} Cliente;
typedef struct {
	int idPedido;
	int idCliente;
	int kilos;
	int HDPE;
	int LDPE;
	int PP;
	int estado; //(pendiente/completo)
	int isEmpty;
} Pedido;
int ClientInicializar(Cliente cliente[], int size);
int clienteBuscarID(Cliente array[], int size, int valorBuscado, int *posicion);
int clienteAlta(Cliente cliente[], int size, int *contadorID);
int ingresoCliente(Cliente *cliente);
int mostrarMenu();
int bajaCliente(Cliente cliente[], int contadorId);
int listarCliente(Cliente cliente[], int size);
int clienteBuscarID(Cliente cliente[], int size, int valorBuscado,
		int *posicion);
int modificarPorId(Cliente cliente[], int contadorId);
/*prototipos de pedido*/

int pedidoBuscarEmpty(Pedido pedido[], int size, int *posicion);
int pedidoAlta(Pedido *pedido, int size, int *contadorIDPedido,
		int *contadorIDCliente);
int pedidoInicializar(Pedido pedido[], int size);
int pedidoBuscarID(Pedido *pedido, int size, int valorBuscado, int *posicion);
int ProcesarPedido(Pedido *pedido, int contadorId);
int ingresoPedido(Pedido pedido[], int contadorId);

/*
 int ingresoPedido(Pedido *pedido, int idCliente);
 int listarLLamadas(Pedido pedido[], int size);
 */

#endif /* LIBRERIA_MODELO_PARCIAL_H_ */

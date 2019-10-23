/*
 * informes.h
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int informe_ClienteMasPedidosPendientes(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteMasPedidosCompletados(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteMasPedidos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteMasKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteMenosKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteMayorMilKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteMenorCienKilos(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteImprimirCompletados(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int Informes_listarPorLocalidadpedido(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteImprimirPolipropileno(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int informe_ClienteInformarPlasticosCuit(Pedido *pedido, int sizePedido,
		Cliente *cliente, int sizeCliente);
int Cliente_buscarCuit(Cliente cliente[], int size, long valorBuscado, int *posicion);

#endif /* INFORMES_H_ */

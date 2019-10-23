/*
 * Datos.c
 *
 *  Created on: 17 oct. 2019
 *      Author: alumno
 */
#include "libreria_modelo_parcial.h"
#include <string.h>

void cargaDatos(Cliente *cliente) {
	Cliente aux0;
	Cliente aux1;
	Cliente aux2;
	Cliente aux3;
	Cliente aux4;
	Cliente aux5;
	aux0.idCliente = 1;
	strcpy(aux0.nombre, "Telefonica");
	strcpy(aux0.localidad, "CABA");
	strcpy(aux0.direccion, "LIMA 1234");
	aux0.cuit = 30112233445;
	aux0.isEmpty = LLENO;
	cliente[0] = aux0;
	aux1.idCliente = 2;

	strcpy(aux1.nombre, "DATASOFT");
	strcpy(aux1.localidad, "CABA");
	strcpy(aux1.direccion, "Corrientes 2547");
	aux1.cuit = 30445566776;
	aux1.isEmpty = LLENO;
	cliente[1] = aux1;

	aux2.idCliente = 3;
	strcpy(aux2.nombre, "NESTLE");
	strcpy(aux2.localidad, "LANUS");
	strcpy(aux2.direccion, "cucha cucha 555");
	aux2.cuit = 30889955219;
	aux2.isEmpty = LLENO;
	cliente[2] = aux2;

	aux3.idCliente = 4;
	strcpy(aux3.nombre, "TERRABUSI");
	strcpy(aux3.localidad, "QUILMES");
	strcpy(aux3.direccion, "rocha 784");
	aux3.cuit = 30567814235;
	aux3.isEmpty = LLENO;
	cliente[3] = aux3;

	aux4.idCliente = 5;
	strcpy(aux4.nombre, "DIA");
	strcpy(aux4.localidad, "AVELLANEDA");
	strcpy(aux4.direccion, "mitre 750");
	aux4.cuit = 31545812533;
	aux4.isEmpty = LLENO;
	cliente[4] = aux4;
	aux5.idCliente = 6;
	strcpy(aux5.nombre, "QUILMES");
	strcpy(aux5.localidad, "QUILMES");
	strcpy(aux5.direccion, "rocha 741");
	aux5.cuit = 30545812533 ;
	aux5.isEmpty = LLENO;
	cliente[5] = aux5;
}

void cargaPedidos(Pedido *pedido) {
	Pedido aux0;
	Pedido aux1;
	Pedido aux2;
	Pedido aux3;
	Pedido aux4;
	Pedido aux5;
	Pedido aux6;
	Pedido aux7;
	Pedido aux8;
	//pedido 1
	aux0.idPedido = 1;
	aux0.idCliente = 1;
	aux0.kilos = 1000;
	aux0.HDPE = 200;
	aux0.LDPE = 145;
	aux0.PP = 230;
	aux0.estado=COMPLETADO;
	aux0.isEmpty = LLENO;
	pedido[0] = aux0;
	//pedido 2
	aux1.idPedido = 2;
	aux1.idCliente = 1;
	aux1.kilos = 800;
	aux1.HDPE = 210;
	aux1.LDPE = 45;
	aux1.PP = 30;
	aux1.estado=COMPLETADO;
	aux1.isEmpty = LLENO;
	pedido[1] = aux1;
	//pedido 3
	aux2.idPedido = 3;
	aux2.idCliente = 2;
	aux2.kilos = 100;
	aux2.estado=PENDIENTE;
	aux2.isEmpty = LLENO;
	pedido[2] = aux2;
	//pedido 4
	aux3.idPedido = 4;
	aux3.idCliente = 2;
	aux3.kilos = 300;
	aux3.estado=PENDIENTE;
	aux3.isEmpty = LLENO;
	pedido[3] = aux3;
	//pedido 5
	aux4.idPedido = 5;
	aux4.idCliente = 3;
	aux4.kilos = 1500;
	aux4.HDPE = 500;
	aux4.LDPE = 150;
	aux4.PP = 270;
	aux4.estado=COMPLETADO;
	aux4.isEmpty = LLENO;
	pedido[4] = aux4;
	//pedido 6
	aux5.idPedido = 6;
	aux5.idCliente = 4;
	aux5.kilos = 750;
	aux5.HDPE = 100;
	aux5.LDPE = 50;
	aux5.PP = 70;
	aux5.estado=COMPLETADO;
	aux5.isEmpty = LLENO;
	pedido[5] = aux5;
	//pedido 7
	aux6.idPedido = 7;
	aux6.idCliente = 1;
	aux6.kilos = 200;
	aux6.estado=PENDIENTE;
	aux6.isEmpty = LLENO;
	pedido[6] = aux6;
	//pedido 8
	aux7.idPedido = 8;
	aux7.idCliente = 5;
	aux7.kilos = 30;
	aux7.HDPE = 10;
	aux7.LDPE = 5;
	aux7.PP = 3;
	aux7.estado=COMPLETADO;
	aux7.isEmpty = LLENO;
	pedido[7] = aux7;
	//pedido 9
	aux8.idPedido = 9;
	aux8.idCliente = 6;
	aux8.kilos = 456;
	aux8.estado=PENDIENTE;
	aux8.isEmpty = LLENO;
	pedido[8] = aux8;
}


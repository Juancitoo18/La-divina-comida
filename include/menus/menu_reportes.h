#ifndef MENU_REPORTES_H_INCLUDED
#define MENU_REPORTES_H_INCLUDED

int menuReportes();
int pag2Reportes();
int pag3Reportes();
int reportesSimples();


int pag3Reportes() {
    Item opciones[] = {
        Item{1, "Medio de Pago Mas Utiizado", MododePagoMasUsado},
        Item{2, "Recaudación de clientes argentinos en sucursal California", recaudacionDeClientesArgentosEnCA},
        Item{3, "Clientes sin ventas en ninguna sucursal", imprimirClientesSinCompras},
        Item{4, "Cantidad de bebidas sin azúcar", cantBebidasRegSinAzucar},
        Item{-1, ""},
        Item{98, "Página anterior", pag2Reportes},
        Item{-1, ""},
        Item{0, "Volver al menú principal", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu pagina3("Reportes - Pág. 3", 1, opciones, _opciones);
    pagina3.graph();
    return 0;
}

int pag2Reportes() {
    Item opciones[] = {
        Item{1, "Medio de pago más usado en ventas a partir de los $1.000", medioDePagoMasUtilizadoAPartirDeLosMil},
        Item{2, "Plato más consumido en diciembre", platoMasConsumidoEnDiciembre},
        Item{3, "Ventas con 3 bebidas o más", ventasCon3BebidasOMas},
        Item{4, "Recaudación de clientes Solteros en 2019", recaudacionDeSolterosEn2019},
        Item{-1, ""},
        Item{5, "Cantidad de Clientes de Nacionalidad Peruana", CantidadDeClientesDeNacionalidadPeruana},
        Item{6, "Ventas Realizadas Antes del 2018", ventasRealizadasAntesDe2018},
        Item{7, "Plato con maní más vendido", platoConManiMasVendido},
        Item{8, "Las ventas que superan los $2000",VentasConUnImporteMayorAdosMil},
        Item{-1, ""},
        Item{98,"Página anterior", menuReportes},
        Item{99,"Siguiente página", pag3Reportes},
        Item{-1, ""},
        Item{0, "Volver al menú principal", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu pagina2("Reportes - Pág. 2", 1, opciones, _opciones);
    pagina2.graph();
    return 0;
}


int menuReportes() {
    Item opciones[] = {
        Item{1, "Recaudación en bebidas alcohólicas", recaudacionEnBebidasAlcoholicas},
        Item{2, "Recaudación de impuestos (Todas las sucursales)", recaudacionAFIPTodasSucursales},
        Item{3, "Recaudación de clientes casados", recaudacionCasados},
        Item{4, "Sucursales que recaudaron efectivo por alcohol en la década 2010-2020", sucursalesQueRecaudaronCashPorVentaDeAlcoholEnLaDecada2010},
        Item{-1,""},
        Item{5, "Cantidad de mozos que atendieron a clientes solteros un jueves", cantMozosQueAtendieronAClientesSolterosEnJueves},
        Item{6, "Compras hechas en los cumpleaños de los clientes", comprasEnSuCumple},
        Item{7, "Sucursal que más vendió a clientes mujeres", sucursalQueMasVendioAMujeres},
        Item{8, "Bebida no alcohólica más consumida", bebidaNoAlcoholicaMasConsumida},
        Item{-1,""},
        Item{99, "Siguiente página", pag2Reportes},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu reportes("Reportes", 1, opciones, _opciones);
    reportes.graph();
    return 0;
}

#endif // MENU_REPORTES_H_INCLUDED

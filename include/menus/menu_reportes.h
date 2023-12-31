#ifndef MENU_REPORTES_H_INCLUDED
#define MENU_REPORTES_H_INCLUDED

int menuReportes();
int pag2Reportes();
int pag3Reportes();
int reportesSimples();


int pag3Reportes() {
    Item opciones[] = {
        Item{1, "Medio de Pago Mas Utiizado", MododePagoMasUsado},
        Item{2, "Recaudaci�n de clientes argentinos en sucursal California", recaudacionDeClientesArgentosEnCA},
        Item{3, "Clientes sin ventas en ninguna sucursal", imprimirClientesSinCompras},
        Item{4, "Cantidad de bebidas sin az�car", cantBebidasRegSinAzucar},
        Item{-1, ""},
        Item{98, "P�gina anterior", pag2Reportes},
        Item{-1, ""},
        Item{0, "Volver al men� principal", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu pagina3("Reportes - P�g. 3", 1, opciones, _opciones);
    pagina3.graph();
    return 0;
}

int pag2Reportes() {
    Item opciones[] = {
        Item{1, "Medio de pago m�s usado en ventas a partir de los $1.000", medioDePagoMasUtilizadoAPartirDeLosMil},
        Item{2, "Plato m�s consumido en diciembre", platoMasConsumidoEnDiciembre},
        Item{3, "Ventas con 3 bebidas o m�s", ventasCon3BebidasOMas},
        Item{4, "Recaudaci�n de clientes Solteros en 2019", recaudacionDeSolterosEn2019},
        Item{-1, ""},
        Item{5, "Cantidad de Clientes de Nacionalidad Peruana", CantidadDeClientesDeNacionalidadPeruana},
        Item{6, "Ventas Realizadas Antes del 2018", ventasRealizadasAntesDe2018},
        Item{7, "Plato con man� m�s vendido", platoConManiMasVendido},
        Item{8, "Las ventas que superan los $2000",VentasConUnImporteMayorAdosMil},
        Item{-1, ""},
        Item{98,"P�gina anterior", menuReportes},
        Item{99,"Siguiente p�gina", pag3Reportes},
        Item{-1, ""},
        Item{0, "Volver al men� principal", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu pagina2("Reportes - P�g. 2", 1, opciones, _opciones);
    pagina2.graph();
    return 0;
}


int menuReportes() {
    Item opciones[] = {
        Item{1, "Recaudaci�n en bebidas alcoh�licas", recaudacionEnBebidasAlcoholicas},
        Item{2, "Recaudaci�n de impuestos (Todas las sucursales)", recaudacionAFIPTodasSucursales},
        Item{3, "Recaudaci�n de clientes casados", recaudacionCasados},
        Item{4, "Sucursales que recaudaron efectivo por alcohol en la d�cada 2010-2020", sucursalesQueRecaudaronCashPorVentaDeAlcoholEnLaDecada2010},
        Item{-1,""},
        Item{5, "Cantidad de mozos que atendieron a clientes solteros un jueves", cantMozosQueAtendieronAClientesSolterosEnJueves},
        Item{6, "Compras hechas en los cumplea�os de los clientes", comprasEnSuCumple},
        Item{7, "Sucursal que m�s vendi� a clientes mujeres", sucursalQueMasVendioAMujeres},
        Item{8, "Bebida no alcoh�lica m�s consumida", bebidaNoAlcoholicaMasConsumida},
        Item{-1,""},
        Item{99, "Siguiente p�gina", pag2Reportes},
        Item{-1, ""},
        Item{0, "Volver al men� anterior", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu reportes("Reportes", 1, opciones, _opciones);
    reportes.graph();
    return 0;
}

#endif // MENU_REPORTES_H_INCLUDED

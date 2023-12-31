#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

int recaudacionEnBebidasAlcoholicas();
int recaudacionAFIPTodasSucursales();
int recaudacionCasados();
int sucursalesQueRecaudaronCashPorVentaDeAlcoholEnLaDecada2010();
int cantMozosQueAtendieronAClientesSolterosEnJueves();
int clientesEnSuCumple();
int sucursalQueMasVendioAMujeres();
int bebidaNoAlcoholicaMasConsumida();
int medioDePagoMasUtilizadoAPartirDeLosMil();
int platoMasConsumidoEnDiciembre();
int platoConManiMasVendido();
int recaudacionDeClientesArgentosEnCA();
int recaudacionDeSolterosEn2019();
int CantidadDeClientesDeNacionalidadPeruana();
int ventasRealizadasAntesDe2018();
int VentasConUnImporteMayorAdosMil();
int MododePagoMasUsado();
int ventasCon3BebidasOMas();
int imprimirClientesSinCompras();
int cantBebidasRegSinAzucar();

//
void makeHeaderForReport(const char *);


void makeHeaderForReport(const char * detallesDelReporte) {
    rlutil::locate(0,0);
    setCL(0xE);
    cout<<endl;
    cout<<" Reporte: "<<detallesDelReporte<<endl;
    cout<<endl;
    setCL(INACTIVE[1]);
}

int recaudacionEnBebidasAlcoholicas() {
    makeHeaderForReport("Mostrar la recaudación en bebidas alcohólicas por todas las sucursales. ");
    Detalle obj; int pos = 0; float rec = 0;
    while(obj.leerDeArchivo(pos++)) {
        bool esBebida = obj.getTipoProducto() == 1;
        if(obj.getEstado() && esBebida) {
            Bebida aux;
            getByCodigoBebidas(obj.getCodigoProducto(),aux);
            if(aux.contieneAlcohol()) rec += (obj.getImporte());
        }
    }
    cout<<"La recaudación total en bebidas con alcohol es de $"<<rec<<". "<<endl<<endl;
    return 0;
}
int recaudacionAFIPTodasSucursales() {
    makeHeaderForReport("Mostrar impuestos recaudados en total por todas las sucursales. ");
    Ticket obj; int pos = 0; float rec = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            rec += obj.getImpuestos();
        }
    }
    cout<<"\n Los impuestos recaudados en total por todas las sucursales son: $"<<rec<<". "<<endl<<endl;
    return 0;
}
int recaudacionCasados() {
    makeHeaderForReport("Mostrar recaudación entre todos los clientes casados en todas las sucursales. ");
    Ticket obj; int pos = 0; float rec = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            Cliente aux;
            if(aux.getEstadoCivil() == 1) rec += obj.getTotal();
        }
    }
    cout<<"\n La recaudación entre clientes casados fue de $"<<rec<<". "<<endl<<endl;
    return 0;
}
int sucursalesQueRecaudaronCashPorVentaDeAlcoholEnLaDecada2010() {
    makeHeaderForReport("Mostrar sucursales que recaudaron efectivo por venta de alcohol en la década 2010-2020");
    Ticket obj; int pos = 0, cuentaSucursales = 0;
    while(obj.leerDeArchivo(pos++)) {
        bool esActivo = obj.getEstado()
           , pagoEnEfectivo = (obj.getMedioDePago() == 0)
           , ocurrioEnDecada2010 = (obj.getFechaOperacion()).happensBetween(Date{1, 1, 2010}, Date{31, 12, 2019, 23, 59});
        bool esElegible = esActivo && pagoEnEfectivo && ocurrioEnDecada2010;
        if(esElegible) {
            bool vendioAlcohol = false;
            Detalle dt; int ps = 0, ca = 0;
            while(dt.leerDeArchivo(ps++)) {
                if(dt.getEstado() && dt.getCodigoTicket() == obj.getCodigo() && dt.getTipoProducto() == 1) {
                    Bebida aux;
                    getByCodigoBebidas(dt.getCodigoProducto(),aux);
                    if(aux.contieneAlcohol()) ca++;
                }
            }
            vendioAlcohol = (ca > 0);
            if(vendioAlcohol) {
                Sucursal ob;
                ob = obj.getSucursal();
                ob.Mostrar();
                cuentaSucursales++;
            }
        }
    }
    cout<<"Mostrando "<<cuentaSucursales<<" registros... "<<endl<<endl;
    return 0;
}

int cantMozosQueAtendieronAClientesSolterosEnJueves() {
    makeHeaderForReport("Mostrar cantidad de mozos que atendieron a clientes solteros en los jueves. ");
    int mozosResultado = 0, pos = 0;
    Mozo o;
    int maxlength = getNextIndexMozo();
    bool * mozos;
    mozos = new bool[maxlength];
    if(mozos == NULL) {
        cout<<"Error asignando memoria. "<<endl;
        return 0;
    }
    for(int i = 0; i < maxlength; i++) mozos[i] = false;
    Ticket obj;
    while(obj.leerDeArchivo(pos++)) {
        bool estaActivo = obj.getEstado()
           , ocurrioEnJueves = ((obj.getFechaOperacion()).getDay() == 4)
           , elClienteEsSoltero = ((obj.getCliente()).getEstadoCivil() == 0);

        if(estaActivo && ocurrioEnJueves && elClienteEsSoltero) {
            mozos[obj.getCodigoMozo() - 1] = true;
            // obj.Mostrar(); (obj.getCliente()).Mostrar(); // Para fines de verificación.
        }

    }
    for(int i = 0; i < maxlength; i++) {
        if(mozos[i]) mozosResultado++;
    }
    if(mozosResultado > 0) cout<<"En total, "<<mozosResultado<<" mozos atendieron a clientes solteros un jueves. "<<endl;
    else cout<<"No hay ventas registradas en las que algún mozo haya atendido a un cliente soltero un jueves. "<<endl;
    cout<<endl;
    return 0;
}
int comprasEnSuCumple() {
    makeHeaderForReport("Mostrar ventas que se realizaron en la misma fecha que el cumpleaños que su cliente. ");
    Ticket vnt; Cliente cl; int pos = 0, t = 0;
    while(vnt.leerDeArchivo(pos++)) {
        if(vnt.getEstado()) {
            Cliente cl;
            int diaDeCompra = vnt.getFechaOperacion().getDate()
              , mesDeCompra = vnt.getFechaOperacion().getMonth()
              , diaCumple = cl.getFechaDeNacimiento().getDate()
              , mesCumple = cl.getFechaDeNacimiento().getMonth();
            if(diaDeCompra == diaCumple && mesDeCompra == mesCumple) {
                vnt.Mostrar();
                t++;
            }
        }
    }
    if(t > 0) cout<<"En total, "<<t<<" compras fueron hechas por clientes que cumplían años. "<<endl;
    else cout<<"No se registraron compras en las que coincidan la fecha de compra y la del cumpleaños del cliente. "<<endl;
    cout<<endl;
    return 0;
}

int sucursalQueMasVendioAMujeres() {
    makeHeaderForReport("Mostrar sucursal con más ventas registradas realizadas a muejres. ");
    Sucursal x;
    int sucursales = getNextIndex() - 1;
    int * ventasAMujeresSucursal;
    ventasAMujeresSucursal = new int[sucursales];
    if(ventasAMujeresSucursal == NULL) return -1;
    for(int i = 0; i < sucursales; i++) ventasAMujeresSucursal[i] = 0;

    Ticket vnt; int pos = 0;
    while(vnt.leerDeArchivo(pos++)) {
        if(vnt.getEstado() && (vnt.getCliente().getGenero() == 'F')) {
            ventasAMujeresSucursal[vnt.getCodigoSucursal() - 1]++;
        }
    }

    int codigoSucursalQueMasVendioAMujeres = getMaxIndex(ventasAMujeresSucursal, sucursales) + 1;
    int mujeresTotal = getMax(ventasAMujeresSucursal, sucursales);

    if(mujeresTotal == 0) {
        cout<<"Ninguna sucursal registró ventas a mujeres. "<<endl;
    } else cout<<"La sucursal N.º "<<codigoSucursalQueMasVendioAMujeres<<" fue la que más vendió a mujeres. ("<<mujeresTotal<<"). "<<endl;

    delete ventasAMujeresSucursal;
    cout<<endl;
    return 0;
}
int bebidaNoAlcoholicaMasConsumida() {
    makeHeaderForReport("Mostrar bebida no alcohólica más consumida. ");
    Bebida a;
    int cantBebidas = getNextIndexBebidas() - 1;
    int * comprasBebida = new int[cantBebidas];
    if(comprasBebida == NULL) {
        Error(0).print();
        return -1;
    }
    for(int i = 0; i < cantBebidas; i++) comprasBebida[i] = 0;

    Detalle obj; int pos = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && obj.getTipoProducto() == 1) {
            Bebida aux;
            getByCodigoBebidas(obj.getCodigoProducto(),aux);
            if(!aux.contieneAlcohol()) {
                comprasBebida[obj.getCodigoProducto() - 1] += obj.getCantidad();
            }
        }
    }
    int codigoBebidaMasComprada = getMaxIndex(comprasBebida, cantBebidas) + 1;
    int canBebidaMasComprada = getMax(comprasBebida, cantBebidas);
    if(canBebidaMasComprada > 0) {
        Bebida masComprada;
        getByCodigoBebidas(codigoBebidaMasComprada,masComprada);
        masComprada.Mostrar();
        cout<<endl<<"Se registraron "<<canBebidaMasComprada<<" unidades vendidas de esta bebida. "<<endl;
    } else {
        cout<<"No se registraron ventas de bebidas sin alcohol. "<<endl;
    }

    delete comprasBebida;
    cout<<endl;
    return 0;
}

int medioDePagoMasUtilizadoAPartirDeLosMil() {
    makeHeaderForReport("Mostrar medio de pago más urilizado en compras desde los $1.000. ");
    Ticket obj; int pos = 0;
    int ventasPorMedioDePago[5] = {0};
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && obj.getTotal() >= 1000) ventasPorMedioDePago[obj.getMedioDePago()]++;
    }
    int medioMasUsado = getMaxIndex(ventasPorMedioDePago, 5);
    int cantMedioMasU = getMax(ventasPorMedioDePago, 5);
    char mediosDePago[5][24] = {
            "Efectivo", "Tarjeta", "Transferencia", "Cheque", "Pagaré"
    };
    if(cantMedioMasU > 0) {
        cout<<"El medio de pago más popular en las ventas desde $1.000 es: "<<mediosDePago[medioMasUsado]<<". "<<endl;
        cout<<cantMedioMasU<<" ventas se efectuaron con esta forma de pago. "<<endl;
    } else {
        cout<<"No se registraron ventas que superen los $1.000. "<<endl;
    }
    cout<<endl;
    return 0;
}
int platoMasConsumidoEnDiciembre() {
    makeHeaderForReport("Mostrar el plato más consumido en diciembre. ");
    Plato aux;
    int totalPlatos = getNextIndexComida() - 1;
    int * compradosEnDiciembre = new int[totalPlatos];
    if(compradosEnDiciembre == NULL) {
        Error(0).print();
        return -1;
    }
    for(int i = 0; i < totalPlatos; i++) compradosEnDiciembre[i] = 0;

    Ticket obj; int pos = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && (obj.getFechaOperacion().getMonth() == 12)) {
            Detalle dt; int ps = 0;
            while(dt.leerDeArchivo(ps++)) {
                if(dt.getEstado() && dt.getCodigoTicket() == (obj.getCodigo()) && dt.getTipoProducto() == 0) {
                    compradosEnDiciembre[dt.getCodigoProducto() - 1] += dt.getCantidad();
                }
            }
        }
    }

    int codigoPlatoMasComprado = getMaxIndex(compradosEnDiciembre, totalPlatos) + 1;
    int cantPlatoMasComprado = getMax(compradosEnDiciembre, totalPlatos);

    if(cantPlatoMasComprado != 0) {
        Plato x;
        getByCodigoComida(codigoPlatoMasComprado,x);
        x.Mostrar();

        cout<<"Este plato se vendió "<<cantPlatoMasComprado<<" veces en diciembre. "<<endl;
    } else {
        cout<<"No se registraron ventas de platos en diciembre. "<<endl;
    }
    cout<<endl;
    delete compradosEnDiciembre;
    return 0;
}
int ventasCon3BebidasOMas() {
    makeHeaderForReport("Mostrar ventas que tienen más de tres bebidas. ");
    int pos=0, pos_1=0, vcod, cont=0;
    bool mostro=false;
    Ticket vobj;
    Detalle dobj;

    cout<< "LAS VENTAS CON 3 BEBIDAS O MAS SON: "<<endl;

    while(vobj.leerDeArchivo(pos++))
    {
        cont=0;
        pos_1=0;
        vcod=vobj.getCodigo();
        while(dobj.leerDeArchivo(pos_1++))
        {
            if(dobj.getTipoProducto()==1 && dobj.getCodigoTicket()==vcod && dobj.getEstado())
            {
                cont+=dobj.getCantidad();
            }
        }

        if(cont>=3)
        {
            vobj.Mostrar();
            mostro=true;
        }
    }
    if(mostro==false)
    {
        cout<< "NO SE REGISTRARON VENTAS CON 3 BEBIDAS O MAS"<<endl;
    }
    cout<<endl;
    return 0;
}
int recaudacionDeSolterosEn2019(){
    makeHeaderForReport("Recaudación de clientes solteros en 2019.");
    Ticket obj; int pos = 0; float rec = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            Cliente aux;
            if((aux.getEstadoCivil() == 0) && (obj.getFechaOperacion().getFullYear()==2019)) rec += obj.getTotal();
        }
    }
    cout<<"La recaudación entre clientes Solteros en 2019 fue de $"<<rec<<". "<<endl;
    cout<<endl;
    return 0;
}

int CantidadDeClientesDeNacionalidadPeruana(){
    makeHeaderForReport("Cantidad de clientes de nacionalidad peruana. ");
    Cliente reg;
    int pos=0, cant=0;
    while(reg.leerDeArchivo(pos++)){
        if((reg.getEstado()) && (reg.getNacionalidad() == 9)){
           cant++;
           }
    }
     cout<<"Hay "<<cant<<" Clientes de Nacionalidad Peruana"<<endl;
     cout<<endl;
     return 0;
}
int ventasRealizadasAntesDe2018(){
    makeHeaderForReport("Ventas realizadas antes del 2018. ");
    Ticket Obj;
    int pos=0;
    cout<< "Las Ventas Realizadas antes del 2018 son: "<<endl;
    while(Obj.leerDeArchivo(pos++)){
        if(Obj.getEstado()){
                if(Obj.getFechaOperacion().getFullYear()<2018)
                Obj.Mostrar();
        }
    }
    cout<<endl;
    return 0;
}
int platoConManiMasVendido() {
    makeHeaderForReport("Plato que contiene maní más vendido");
    Plato aux; Detalle dt; int pos = 0, cantidadDePlatoMasVendidoConMani, codigoPlatoMasVendidoConMani;
    int cantidadPlatos = getNextIndexComida() - 1;
    int * platos = new int[cantidadPlatos];
    if(platos == NULL) return -1;
    for(int i = 0; i < cantidadPlatos; i++) platos[i] = 0;
    while(dt.leerDeArchivo(pos++)) {
        if(dt.getEstado() && dt.getTipoProducto() == 0) {
            int codigoPlato = dt.getCodigoProducto();
            int epl = getByCodigoComida(codigoPlato,aux);
            if((epl != -1) && (aux.contieneMani()))
                platos[codigoPlato - 1] += dt.getCantidad();

        }
    }
    codigoPlatoMasVendidoConMani = getMaxIndex(platos, cantidadPlatos) + 1;
    cantidadDePlatoMasVendidoConMani = getMax(platos, cantidadPlatos);
    if(cantidadDePlatoMasVendidoConMani == 0) cout<<"No se registraron ventas de platos que contengan maní en ninguna sucursal. "<<endl;
    else {
        getByCodigoComida(codigoPlatoMasVendidoConMani,aux);
        aux.Mostrar();
        cout<<endl<<"Este plato se vendió "<<cantidadDePlatoMasVendidoConMani<<" veces. "<<endl;
    }
    cout<<endl;
    cout<<endl;
    delete platos;
    return 0;
}
int recaudacionDeClientesArgentosEnCA() {
    makeHeaderForReport("Recaudación de clientes argentinos en la sucursal 'California' / Sucursal N.º 3");
    Ticket ticket; int pos = 0; int nacionalidadArgentina = 1, sucursalCalifornia = 3;
    float recaudacion = 0;
    while(ticket.leerDeArchivo(pos++)) {
        Cliente x;
        bool elClienteEsArgentino = (x.getNacionalidad() == nacionalidadArgentina);
        bool ocurrioEnCA = (ticket.getCodigoSucursal() == sucursalCalifornia);
        if(ticket.getEstado() && elClienteEsArgentino && ocurrioEnCA) {
            recaudacion += ticket.getTotal();
        }
    }
    cout<<"En la sucursal N.º 3 (CALIFORNIA) la recaudación hecha por clientes argentinos fue de $"<<recaudacion<<". "<<endl<<endl;
    return 0;
}
int VentasConUnImporteMayorAdosMil(){
    makeHeaderForReport("Ventas que superan los $2000");
    Ticket reg;
    int pos=0;
    cout<< "Las ventas que superaron los $2000 son: "<<endl;
    while(reg.leerDeArchivo(pos++)){
        if(reg.getEstado()){
            if(reg.getTotal()>2000){
                reg.Mostrar();
            }
        }
    }
    return 0;
}
int MododePagoMasUsado(){
    makeHeaderForReport("Metodo de Pago Mas Utilizado. ");
    Ticket pago;
    int pos=0,max=0,VPago[5]={0};
    while(pago.leerDeArchivo(pos++)){
        if(pago.getEstado()){
            VPago[pago.getMedioDePago()]++;
            max=getMaxIndex(VPago,5);
        }
    }
    char mediosDePago[5][24] = {
            "Efectivo", "Tarjeta", "Transferencia", "Cheque", "Pagaré"
    };
    cout<<"El Metodo De Pago Mas Usado Fue El: "<<mediosDePago[max]<<endl;
    return 0;
}
int imprimirClientesSinCompras()
{
    makeHeaderForReport("Clientes que no registraron compras en ninguna sucursal");
    Cliente cobj;
    Ticket tobj;
    int pos=0, pos_1=0;
    bool compro=false;
    cout<< "LOS CLIENTES QUE NO REALIZARON COMPRAS SON: "<<endl;
    while(cobj.leerDeArchivo(pos++)) {
        pos_1 = 0;
        compro = false;
        while(tobj.leerDeArchivo(pos_1++)) {
            compro = (cobj.getNumeroCliente() == tobj.getNumeroCliente());
        }
        if(!compro) cobj.Mostrar();
    }
    return 0;
}
int cantBebidasRegSinAzucar()
{
    makeHeaderForReport("Cantidad de bebidas sin azúcar");
    Bebida bobj;
    int pos=0, cont=0;;

    while(bobj.leerDeArchivo(pos++))
    {
        if(!bobj.contieneAzucar())
        {
            cont++;
        }
    }

    cout<< "la cantidad de bebidas sin azucar es de "<<cont<< " y son las siguientes"<<endl;
    pos = 0;
    while(bobj.leerDeArchivo(pos++))
    {
        if(!bobj.contieneAzucar())
        {
            bobj.Mostrar();
        }
    }
    return 0;
}

/**/
#endif // REPORTES_H_INCLUDED

#ifndef FUNCIONES_DETALLE_H_INCLUDED
#define FUNCIONES_DETALLE_H_INCLUDED

int getCantidadPlatos(int codTicket) {
    Detalle dt; int pos = 0, ctd = 0;
    while(dt.leerDeArchivo(pos++)) {
        if(dt.getCodigoTicket() == codTicket && dt.getTipoProducto() == 0 && dt.getEstado()) ctd++;
    }
    return ctd;
}

int getCantidadBebidas(int codTicket) {
    Detalle dt; int pos = 0, ctd = 0;
    while(dt.leerDeArchivo(pos++)) {
        if(dt.getCodigoTicket() == codTicket && dt.getTipoProducto() == 1 && dt.getEstado()) ctd++;
    }
    return ctd;
}

void printTotal(float r) {
    setBG(ACTIVE[0]);
    setCL(ACTIVE[0]);
    cout<<"\t.";
    setCL(ACTIVE[1]);
    cout<<"TOTAL: $"<<r<<". ";
    setBG(INACTIVE[0]);
    setCL(INACTIVE[1]);
}

int getCantidadProductosEnLaNada(int codTicket) {
    Detalle dt; int pos = 0, ctd = 0;
    while(dt.leerDeArchivo(pos++)) {
        if(dt.getCodigoTicket() == codTicket && !dt.getEstado()) ctd++;
    }
    return ctd;
}

int limpiarProductos() {
    Detalle dt; int pos = 0, ctd = 0, ctt = 0;
    while(dt.leerDeArchivo(pos++)) {
        if(dt.getEstado() && dt.escribirEnArchivo("datos/detalles.temp")) {
            ctd++;
        }
        ctt++;
    }
    remove("datos/detalles.dat");
    rename("datos/detalles.temp", "datos/detalles.dat");
    return (ctt - ctd);
}

bool activarProductos(int codTicket)  {
    Detalle dt; int pos = 0, ctd = 0;
    while(dt.leerDeArchivo(pos++)) {
        if(!dt.getEstado() && dt.getCodigoTicket() == codTicket) {
            dt.setEstado(true);
            if(dt.modificarDelArchivo(pos)) {
                ctd++;
            }
        }
    }
    return (ctd > 0);
}
#endif // FUNCIONES_DETALLE_H_INCLUDED

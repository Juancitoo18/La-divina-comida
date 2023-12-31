#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

int backupMozos();
int backupClientes();
int backupPlatos();
int backupBebidas();
int backupVentas();
int backupSucursales();

int restoreMozos();
int restoreClientes();
int restorePlatos();
int restoreBebidas();
int restoreVentas();
int restoreSucursales();

int restablecerDatosInicio();

int establecerIva();

int backupMozos() {
    remove("datos/mozos.bkp");
    Mozo obj; int pos = 0, t = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            if(obj.escribirEnArchivo("datos/mozos.bkp")) {
                t++;
            }
        }
    }
    cout<<"Se guardaron "<<t<<" registros. "<<endl;
    return 0;
}
int backupClientes() {
    remove("datos/clientes.bkp");
    Cliente obj; int pos = 0, t = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && obj.escribirEnArchivo("datos/clientes.bkp")) {
            t++;
        }
    }
    cout<<"Se guardaron "<<t<<" registros. "<<endl;
    return 0;
}
int backupPlatos() {
    remove("datos/comidas.bkp");
    Plato obj; int pos = 0, t = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && obj.escribirEnArchivo("datos/comidas.bkp")) {
            t++;
        }
    }
    cout<<"Se guardaron "<<t<<" registros. "<<endl;
    return 0;
}
int backupBebidas() {
    remove("datos/bebidas.bkp");
    Bebida obj; int pos = 0, t = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && obj.escribirEnArchivo("datos/bebidas.bkp")) {
            t++;
        }
    }
    cout<<"Se guardaron "<<t<<" registros. "<<endl;
    return 0;
}
int backupVentas() {
    remove("datos/ventas.bkp");
    Ticket obj; int pos = 0, t = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && obj.escribirEnArchivo("datos/ventas.bkp")) t++;
    }
    remove("datos/detalles.bkp");
    Detalle objd; pos = 0; int td = 0;
    while(objd.leerDeArchivo(pos++)) {
        if(objd.getEstado() && objd.escribirEnArchivo("datos/detalles.bkp")) td++;
    }
    cout<<"Se guardaron "<<t<<" (+"<<td<<" productos ) registros. "<<endl;
    return 0;
}
int backupSucursales() {
    remove("datos/sucursales.bkp");
    Sucursal obj; int pos = 0, t = 0;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado() && obj.escribirEnArchivo("datos/sucursales.bkp")) t++;
    }
    cout<<"Se guardaron "<<t<<" registros. "<<endl;
    return 0;
}

///


int restoreMozos() {
    remove("datos/mozos.dat");
    Mozo obj; int pos = 0, res = 0;
    while(obj.leerDeArchivo(pos++, "datos/mozos.bkp")) {
        if(obj.getEstado() && obj.escribirEnArchivo()) res++;
    }
    cout<<"Se restauraron "<<res<<" registros en el archivo. "<<endl;
    return 0;
}
int restoreClientes() {
    remove("datos/clientes.dat");
    Cliente obj; int pos = 0, res = 0;
    while(obj.leerDeArchivo(pos++, "datos/clientes.bkp")) {
        if(obj.getEstado() && obj.escribirEnArchivo()) res++;
    }
    cout<<"Se restauraron "<<res<<" registros en el archivo. "<<endl;
    return 0;
}
int restorePlatos() {
    remove("datos/comidas.dat");
    Plato obj; int pos = 0, res = 0;
    while(obj.leerDeArchivo(pos++, "datos/comidas.bkp")) {
        if(obj.getEstado() && obj.escribirEnArchivo()) res++;
    }
    cout<<"Se restauraron "<<res<<" registros en el archivo. "<<endl;
    return 0;
}
int restoreBebidas() {
    remove("datos/bebidas.dat");
    Bebida obj; int pos = 0, res = 0;
    while(obj.leerDeArchivo(pos++, "datos/bebidas.bkp")) {
        if(obj.getEstado() && obj.escribirEnArchivo()) res++;
    }
    cout<<"Se restauraron "<<res<<" registros en el archivo. "<<endl;
    return 0;
}
int restoreVentas() {
    remove("datos/ventas.dat");
    Ticket obj; int pos = 0, res = 0;
    while(obj.leerDeArchivo(pos++, "datos/ventas.bkp")) {
        if(obj.getEstado() && obj.escribirEnArchivo()) res++;
    }
    remove("datos/detalles.dat");
    Detalle objd; pos = 0; int resd = 0;
    while(objd.leerDeArchivo(pos++, "datos/detalles.bkp")) {
        if(objd.getEstado() && objd.escribirEnArchivo()) resd++;
    }
    cout<<"Se restauraron "<<res<<" (+"<<resd<<" productos) registros en el archivo. "<<endl;
    return 0;
}
int restoreSucursales() {
    system("del datos/sucursales.dat");
    Sucursal obj; int pos = 0, res = 0;
    while(obj.leerDeArchivo(pos++, "datos/sucursales.bkp")) {
        if(obj.getEstado() && obj.escribirEnArchivo()) res++;
    }
    cout<<"Se restauraron "<<res<<" registros en el archivo. "<<endl;
    return 0;
}
int restablecerDatosInicio() {
    remove("datos/mozos.dat");
    remove("datos/clientes.dat");
    remove("datos/sucursales.dat");
    Mozo m; int pos = 0, res = 0;
    while(m.leerDeArchivo(pos++, "datos/mozos.ini")) {
        if(m.getEstado() && m.escribirEnArchivo()) res++;
    }
    cout<<"Se restablecieron "<<res<<" registros de mozos en el archivo. "<<endl;
    Cliente c; pos = 0; res = 0;
    while(c.leerDeArchivo(pos++, "datos/clientes.ini")) {
        if(c.getEstado() && c.escribirEnArchivo()) res++;
    }
    cout<<"Se restablecieron "<<res<<" registros de clientes en el archivo. "<<endl;
    Sucursal s; pos = 0; res = 0;
    while(s.leerDeArchivo(pos++, "datos/sucursales.ini")) {
        if(s.getEstado() && s.escribirEnArchivo()) res++;
    }
    cout<<"Se restablecieron "<<res<<" registros de sucursales en el archivo. "<<endl;
    return 0;
}

int establecerIva()
{
    Iva cobj;
    float val;
    cout<< "Ingrese el porcentaje del Impuesto al Valor Agregado (IVA): ";
    cin>>val;

    if(val>=0 && val<=100)
    {
        cobj.setIva(val);
        if(cobj.escribirEnArchivo())
        {
            cout<< "Porcentaje de IVA modificado."<<endl;
        }
    }else
    {
        cout<< "Valor de porcentaje invalido."<<endl;
    }
    return 0;
}


#endif // CONFIGURACION_H_INCLUDED

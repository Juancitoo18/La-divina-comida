/*
    En este archivo:
     * Funciones de carga de datos manual
*/
#ifndef CARGAR_H_INCLUDED
#define CARGAR_H_INCLUDED

int cargarMozos();
int cargarComidas();
int cargarBebidas();
int cargarClientes();
int cargarVentas();

int cargarMozos() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Mozo miMozo;
        int n = getNextIndexMozo();
        miMozo.Cargar(n);
        if(miMozo.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}

int cargarSucursales() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Sucursal miSucu;
        int n = getNextIndexSucursal();
        miSucu.Cargar(n);
        if(miSucu.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
int cargarComidas() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Plato miPlato;
        int n = getNextIndexComida();
        miPlato.Cargar(n);
        if(miPlato.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
int cargarBebidas() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Bebida miBebida, aux;
        int n = getNextIndexBebidas();
        miBebida.Cargar(n);
        if(miBebida.escribirEnArchivo())
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        cout<<endl;
    }
    return 0;
}
int cargarClientes() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Cliente miCliente, aux;
        int n = getNextIndexCliente();
        miCliente.Cargar(n);
        if(miCliente.escribirEnArchivo()) {
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
int cargarVentas() {
    int regs = aCargar();
    for(int i = 0; i < regs; i++) {
        Ticket miTicket, aux;
        int id = getNextIndex();
        int f = getCantidadProductosEnLaNada(id);
        if(f != 0) {
            cout<<"(!) Se encontraron "<<f<<" productos de la última venta que no se guardaron. ¿Desea eliminarlos? (S/N): ";
            char dec; cin>>dec;
            if(dec == 'S') {
                int el = limpiarProductos();
                cout<<"(!) Se limpiaron "<<el<<" registros. "<<endl<<endl;
            }
        }

        if(miTicket.Cargar(id) && miTicket.escribirEnArchivo()) {
            miTicket.activarCompra();
            cout<<"Se escribió correctamente en el archivo. "<<endl;
        }
        cout<<endl;
    }
    return 0;
}

#endif // CARGAR_H_INCLUDED

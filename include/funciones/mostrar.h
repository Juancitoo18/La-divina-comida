/*
    En este archivo:
     * Funciones que muestran por pantalla los datos en los archivos.
*/
#ifndef MOSTRAR_H_INCLUDED
#define MOSTRAR_H_INCLUDED

int mostrarMozos();
int mostrarSucursales();
int mostrarPlatos();
int mostrarBebidas();
int mostrarClientes();
int mostrarVentas();


int mostrarMozos() {
    int pos = 0, total = 0;
    Mozo obj;
    cout<<endl;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            obj.Mostrar();
            total++;
        }
    }
    informarCantRegistros(total);
    return 0;
}
int mostrarSucursales() {
    int pos = 0, total = 0;
    Sucursal obj;
    cout<<endl;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            obj.Mostrar();
            total++;
        }
    }
    informarCantRegistros(total);
    return 0;
}
int mostrarPlatos() {
    int pos = 0, total = 0;
    Plato obj;
    cout<<endl;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            obj.Mostrar();
            total++;
        }
    }
    informarCantRegistros(total);
    return 0;
}
int mostrarBebidas() {
    int pos = 0, total = 0;
    Bebida obj;
    cout<<endl;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            obj.Mostrar();
            total++;
        }
    }
    informarCantRegistros(total);
    return 0;
}
int mostrarClientesXLSX() {
    int pos = 0, total = 0;
    Mozo obj;
    cout<<endl;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            cout<<"\t"<<obj.getCodigo()<<"\t"<<obj.getApellido()<<"\t"<<obj.getNombre()<<"\t"<<obj.getCodigoSucursal()<<"\t"<<obj.getDNI()<<"\t"<<obj.getGenero()<<"\t'";
            obj.getFechaDeNacimiento().print(obj.getFechaDeNacimiento().SP_SHORT, false); cout<<"'\t"<<obj.getNacionalidad()<<"\t"<<obj.getNumeroTelefono()<<"\t";
            obj.printEstadoCivil(); cout<<"\n";
            total++;
        }
    }
    informarCantRegistros(total);
    return 0;
}
int mostrarClientes() {
    int pos = 0, total = 0;
    Cliente obj;
    cout<<endl;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            obj.Mostrar();
            total++;
        }
    }
    informarCantRegistros(total);
    return 0;
}
int mostrarVentas() {
    int pos = 0, total = 0;
    Ticket obj;
    cout<<endl;
    while(obj.leerDeArchivo(pos++)) {
        if(obj.getEstado()) {
            obj.Mostrar();
            total++;
        }
    }
    informarCantRegistros(total);
    return 0;
}

#endif // MOSTRAR_H_INCLUDED

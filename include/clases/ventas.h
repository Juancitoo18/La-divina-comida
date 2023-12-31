#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class Detalle {
private:
    int codigoTicket;
    int codigoProducto;
    int tipoProducto; // 0 - Plato, 1 - Bebida
    int cantidad;
    float importe;
    bool estado;
public:
    int getCodigoTicket() { return codigoTicket; }
    int getCodigoProducto() { return codigoProducto; }
    int getTipoProducto() { return tipoProducto; }
    int getCantidad() { return cantidad; }
    void calcImporte() {
        switch(tipoProducto) {
        case 0: {
            Plato aux;
            aux.getByCodigo(codigoProducto);
            importe = aux.getPrecio() * cantidad;
            break;
        }
        case 1: {
            Bebida aux;
            aux.getByCodigo(codigoProducto);
            importe = aux.getPrecio() * cantidad;
            break;
        }
        default:
            importe = 0;
            break;
        }
    }
    float getImporte() {
        calcImporte();
        return importe;
    }
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigoTicket(int cod) {codigoTicket = cod;}
    void setCodigoProducto(int cp) {codigoProducto = cp;}
    void setTipoProducto(int tp) {tipoProducto = tp;}
    void setCantidad(int c) {cantidad = c; calcImporte();}
    void setEstado(bool e) {estado = e;}
    /* Imprimir */
    void Imprimir() {
        if(tipoProducto == 0) {
            Plato aux;
            aux.getByCodigo(codigoProducto);
            cout<<"\t  [$"<<importe<<"] "<<aux.getNombre()<<" x "<<cantidad<<". "<<endl;
        }
        if(tipoProducto == 1) {
            Bebida aux;
            aux.getByCodigo(codigoProducto);
            cout<<"\t  [$"<<importe<<"] "<<aux.getNombre()<<" x "<<cantidad<<". "<<endl;
        }
    }
    void Mostrar() {
        cout<<"Producto del ticket #"<<codigoTicket<<": "<<endl;
        Imprimir();
    }
    /* Constructores y destructores */
    Detalle() {}
    Detalle(int cv, int cp, int tp, int c, bool e = true) {
        setCodigoTicket(cv);
        setCodigoProducto(cp);
        setTipoProducto(tp);
        setCantidad(c);
        setEstado(e);
    }
    ~Detalle() {}
    /* Operaciones con archivos */
    bool leerDeArchivo(int pos, const char * filename = "datos/detalles.dat") {
        FILE * archivo = fopen(filename, "rb");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        fseek(archivo, (sizeof * this) * pos, 0);
        bool res = fread(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool escribirEnArchivo(const char * filename = "datos/detalles.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "datos/detalles.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }



};

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




#endif // VENTAS_H_INCLUDED

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
    /*Gets*/
    int getCodigoTicket() { return codigoTicket; }
    int getCodigoProducto() { return codigoProducto; }
    int getTipoProducto() { return tipoProducto; }
    int getCantidad() { return cantidad; }
    void getCalcImporte() {
        switch(tipoProducto) {
        case 0: {
            Plato plato;
            getByCodigoComida(codigoProducto, plato);
            importe = plato.getPrecio() * cantidad;
            break;
        }
        case 1: {
            Bebida aux;
            getByCodigoBebidas(codigoProducto,aux);
            importe = aux.getPrecio() * cantidad;
            break;
        }
        default:
            importe = 0;
            break;
        }
    }
    float getImporte() {
        getCalcImporte();
        return importe;
    }
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigoTicket(int cod) {codigoTicket = cod;}
    void setCodigoProducto(int cp) {codigoProducto = cp;}
    void setTipoProducto(int tp) {tipoProducto = tp;}
    void setCantidad(int c) {cantidad = c; getCalcImporte();}
    void setEstado(bool e) {estado = e;}
    /* Imprimir */
    void Imprimir() {
        if(tipoProducto == 0) {
            Plato aux;
            getByCodigoComida(codigoProducto,aux);
            cout<<"\t  [$"<<importe<<"] "<<aux.getNombre()<<" x "<<cantidad<<". "<<endl;
        }
        if(tipoProducto == 1) {
            Bebida aux;
            getByCodigoBebidas(codigoProducto,aux);
            cout<<"\t  [$"<<importe<<"] "<<aux.getNombre()<<" x "<<cantidad<<". "<<endl;
        }
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





#endif // VENTAS_H_INCLUDED

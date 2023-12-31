
#ifndef SUCURSALES_H_INCLUDED
#define SUCURSALES_H_INCLUDED

class Sucursal {
private:
    int codigo;
    char nombre[48];
    bool estado;
public:
    /* Gets */
    int getCodigo() {return codigo;}
    const char * getNombre() {return nombre;}
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int c) {codigo = c;}
    void setNombre(const char * n) {strcpy(nombre, n);}
    void setEstado(bool e) {estado = e;}
    /* Cargar y Mostrar */
    void Cargar(int _cod = -1) {
        if(_cod == -1) {
            cout<<"Ingrese código de sucursal: ";
            cin>>codigo;
        } else {
            codigo = _cod;
        }
        cout<<"Ingrese nombre de la sucursal: ";
        cargarCadena(nombre, 47);
        estado = true;
    }
    void Mostrar() {
        if(getEstado()) {
            cout<<"\tDetalles de la sucursal #"<<codigo<<": "<<endl;
            cout<<"\tNombre: "<<nombre<<". "<<endl;
            setCL(0xC);
            cout<<"------------------------------------------------------------"<<endl;
            setCL(0xF);
        }
    }
    /* Constructor */
    Sucursal() {}
    Sucursal(int cod, bool est) {
        codigo = cod;
        estado = est;
    }
    /* Destructor */
    ~Sucursal() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "datos/sucursales.dat") {
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
    bool escribirEnArchivo(const char * filename = "datos/sucursales.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "datos/sucursales.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
};

#endif // SUCURSALES_H_INCLUDED

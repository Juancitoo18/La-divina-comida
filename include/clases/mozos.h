#ifndef MOZOS_H_INCLUDED
#define MOZOS_H_INCLUDED

class Mozo:public Persona {
private:
    int codigo;
    int codigoSucursal;
    bool estado;
public:
    /* Gets */
    int getCodigo() { return codigo;}
    int getCodigoSucursal() {return codigoSucursal;}
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int c) {codigo=c;}
    bool setSucursal(int c) {
        Sucursal aux;
        bool res = getByCodigoSucursal(c,aux);
        if(res) codigoSucursal = c;
        return res;
    }
    void setEstado(bool e) {estado=e;}
    /* Cargar y Mostrar */
    void Cargar(int cod = -1)
    {
        Persona::Cargar();
        if(cod==-1)
        {
            cout<< "Ingrese codigo de Mozo: ";
            cin>>codigo;
        }else
            codigo=cod;
        bool sucursalCargada = false;
        while(!sucursalCargada) {
            cout<<"Ingrese código de sucursal: ";
            int c; cin>>c;
            if(!setSucursal(c)) {
                cout<<"Sucursal incorrecta. \n";
            } else {
                cout<<"Sucursal correcta. \n";
                sucursalCargada = true;
            }
        }
        estado=true;
    }
    void Mostrar()
    {
        if(getEstado())
        {
            cout<<"\tCodigo de Mozo: #";
            cout<<codigo<<endl;
            Persona::Mostrar();
            cout<<"\tCódigo de sucursal donde trabaja: #";
            cout<<codigoSucursal<<endl;
            setCL(0xC);
            cout<<"------------------------------------------------------------"<<endl;
            setCL(0xF);
        }
    }
    /* Constructores */
    Mozo() {}
///    Mozo():Persona() {}
    /* Destructor */
    ~Mozo() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "datos/mozos.dat") {
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
    bool escribirEnArchivo(const char * filename = "datos/mozos.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "datos/mozos.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
};

#endif // MOZOS_H_INCLUDED


#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Cliente:public Persona {
private:
    int numeroCliente;
    bool estado;
public:
    /* Gets */
    int getNumeroCliente() {return numeroCliente;}
    bool getEstado() {return estado;}
    /* Sets */
    void setNumeroCliente(int n) {numeroCliente=n;}
    void setEstado(bool e) {estado=e;}
    /* Cargar y Mostrar */
    void Cargar(int n = -1)
    {
        if(n==-1)
        {
            cout<< "Ingrese numero de Cliente: ";
            cin>> numeroCliente;
        } else {
            cout<<"Número de cliente asignado: "<<n<<". "<<endl;
            numeroCliente = n;
        }
        Persona::Cargar();
        estado=true;
    }
    void Mostrar()
    {
        if(getEstado())
        {
        cout<< "\tNumero de Cliente: #"<<numeroCliente<<endl;
        Persona::Mostrar();
        setCL(0xC);
        cout<<"------------------------------------------------------------"<<endl;
        setCL(0xF);
        }
    }
    /* Constructores */
    Cliente(int n=0)
    {
            numeroCliente = n;
    }
    /* Destructor */
    ~Cliente() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "datos/clientes.dat") {
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
    bool escribirEnArchivo(const char * filename = "datos/clientes.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "datos/clientes.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
};

#endif // CLIENTES_H_INCLUDED

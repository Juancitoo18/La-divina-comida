#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

class Plato {
private:
    int codigo;
    char nombre[72];
    int nacionalidad;
    float precio;
    int tipo; /// 0 => Desayuno, 1 => Almuerzo, 2 => Snacks, 3 => Cena, 4 => Postre
    bool tieneGluten;
    bool tieneCarne;
    bool tieneHuevo;
    bool tieneAzucar;
    bool tieneMani;
    bool tieneChocolate;
    bool estado;
public:
    /* Gets */
    int getCodigo() { return codigo;}
    const char * getNombre() {return nombre;}
    int getNacionalidad() {return nacionalidad;}
    float getPrecio() {return precio;}
    int getTipo() {return tipo;}
    void getprintTipo() {
        const char t[5][24] = {"Desayuno", "Almuerzo", "Snack", "Cena", "Postre"};
        cout<<t[tipo];
    }
    void printNacionalidad(bool e = false) {
        char estados[10][24] = {"Argentina", "Uruguay", "Brasil", "Paraguay", "Chile", "Bolivia", "Mexico", "Colombia", "España", "Perú"};
        cout<<estados[nacionalidad];
    }
    bool contieneGluten() {return tieneGluten;}
    bool contieneCarne() {return tieneCarne;}
    bool contieneHuevo() {return tieneHuevo;}
    bool contieneAzucar() {return tieneAzucar;}
    bool contieneMani() {return tieneMani;}
    bool contieneChocolate() {return tieneChocolate;}
    bool contieneAlgo() {
        return (tieneGluten || tieneCarne || tieneHuevo || tieneAzucar || tieneMani ||tieneChocolate);
    }
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int n) {codigo=n;}
    void setNombre(const char * n) {strcpy(nombre,n);}
    void setNacionalidad(int n) {nacionalidad=n;}
    bool setPrecio(float p) {
        if(p > 0) {
            precio = p;
            return true;
        }
        return false;
    }
    bool setTipo(int t) {
        if(t >= 0 && t <= 4) {
            tipo = t;
            return true;
        }
        return false;
    }
    void setGluten(bool e) {tieneGluten=e;}
    void setCarne(bool e) {tieneCarne=e;}
    void setHuevo(bool e) {tieneHuevo=e;}
    void setAzucar(bool e) {tieneAzucar=e;}
    void setMani(bool e) {tieneMani=e;}
    void setChocolate(bool e) {tieneChocolate=e;}
    void setEstado(bool e) {estado=e;}
    /* Cargar y Mostrar */
    void Cargar(int cod = -1)
    {
        if(cod==-1)
        {
            cout<< "Ingrese codigo de Plato: #";
            cin>>codigo;
        }else
            codigo=cod;
        cout<< "Ingrese el nombre del plato: ";
        cargarCadena(nombre,71);
        cout<< "Ingrese la nacionalidad(0: ARG, 1: URU, 2: BRA, 3: PAR, 4: CHI, 5: BOL, 6: MEX, 7: COL, 8:ESP, 9: PER): ";
        cin>>nacionalidad;
        cout<< "Ingrese el precio: $";
        cin>>precio;
        cout<< "Ingrese el tipo: (0 => Desayuno, 1 => Almuerzo, 2 => Snacks, 3 => Cena, 4 => Postre): ";
        cin>>tipo;
        char glu;
        cout<<"¿Contiene Gluten? (S/N): ";
        cin>>glu;
        tieneGluten = (glu=='S'|| glu=='s');
        char car;
        cout<<"¿Contiene Carne? (S/N): ";
        cin>>car;
        tieneCarne = (car=='S' || car=='s');
        char hue;
        cout<<"¿Contiene Huevo? (S/N): ";
        cin>>hue;
        tieneHuevo = ( hue=='S'|| hue=='s');
        char azu;
        cout<<"¿Contiene Azucar? (S/N): ";
        cin>>azu;
        tieneAzucar = ( azu=='S'|| azu=='s');
        char cho;
        cout<<"¿Contiene Chocolate? (S/N): ";
        cin>>cho;
        tieneChocolate = ( cho=='S'|| cho=='s');
        char man;
        cout<<"¿Contiene Mani? (S/N): ";
        cin>>man;
        tieneMani = ( azu=='S'|| azu=='s');
        estado=true;
    }
    void Mostrar()
    {
        if(getEstado())
        {
            cout<<"\tCodigo: #";
            cout<<codigo<<endl;
            cout<<"\t"<<nombre<<endl;
            cout<<"\tNacionalidad: ";
            printNacionalidad();
            cout<<endl;
            cout<<"\t$"<<precio<<endl;
            cout<< "\tTipo: ";
            getprintTipo(); cout<<endl;
            if(contieneAlgo())
                cout<<"\tContiene: "<<(tieneGluten?"Gluten; ":"")<<(tieneCarne?"Carne; ":"")<<(tieneHuevo?"Huevo; ":"")<<(tieneAzucar?"Azúcar; ":"")<<(tieneMani?"Maní; ":"")<<(tieneChocolate?"Chocolate; ":"")<<endl;
            setCL(0xC);
            cout<<"------------------------------------------------------------"<<endl;
            setCL(0xF);
        }
    }
    /* Constructores */
    Plato() {}
    /* Destructor */
    ~Plato() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "datos/comidas.dat") {
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
    bool escribirEnArchivo(const char * filename = "datos/comidas.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "datos/comidas.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
    /* Sobrecarga de operaciones */
    void operator=(Plato aux) {
        codigo = aux.codigo;
        strcpy(nombre, aux.nombre);
        nacionalidad = aux.nacionalidad;
        precio = aux.precio;
        tipo = aux.tipo;
        tieneGluten = aux.tieneGluten;
        tieneCarne = aux.tieneCarne;
        tieneHuevo = aux.tieneHuevo;
        tieneAzucar = aux.tieneAzucar;
        tieneMani = aux.tieneMani;
        tieneChocolate = aux.tieneChocolate;
        estado = aux.estado;
    }
};

#endif // COMIDAS_H_INCLUDED

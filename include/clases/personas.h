#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

class Persona {
private:
    char nombre[48];
    char apellido[48];
    int DNI;
    char genero; // 'M', 'F', 'O'
    Date fechaDeNacimiento;
    int nacionalidad; // 1-10
    char numeroTelefono[24]; // Se usa chars porque puede darse el caso que el teléfono comience con ceros.
    int estadoCivil; // 0: Soltero, 1: Casado, 2: Relación
public:
    /* Gets */
    const char * getNombre() {return nombre;}
    const char * getApellido() {return apellido;}
    char getGenero() {return genero;}
    int getDNI() {return DNI;}
    Date getFechaDeNacimiento() {return fechaDeNacimiento;}
    int getNacionalidad() {return nacionalidad;}
    void printNacionalidad(bool e = false) {
        char estados[10][24] = {"Argentina", "Uruguay", "Brasil", "Paraguay", "Chile", "Bolivia", "Mexico", "Colombia", "España", "Perú"};
        cout<<estados[nacionalidad];
    }
    const char * getNumeroTelefono() {return numeroTelefono;}
    int getEstadoCivil() {return estadoCivil;}
    void printEstadoCivil(bool e = false) {
        char estados[3][24] = {"Soltero", "Casado", "Relación"};
        cout<<estados[estadoCivil];
    }
    /* Sets */
    void setNombre(const char * n) {strcpy(nombre, n);}
    void setApellido(const char * n) {strcpy(apellido, n);}
    bool setGenero(char n) {
        if(n == 'M' || n == 'm' || n == 'F' || n == 'f' || n == 'O' || n == 'o') {
            genero = n;
            return true;
        } return false;
    }
    void setDNI(int n) {DNI = n;}
    void setFechaDeNacimiento(Date n) {fechaDeNacimiento.copyFrom(n);}
    bool setNacionalidad(int n) {
        if(n <= 10 && n >= 0) {
            nacionalidad = n;
            return true;
        } return false;
    }
    void setNumeroTelefono(const char * n) {strcpy(numeroTelefono, n);}
    bool setEstadoCivil(int n) {
        if(n >= 0 && n <= 2) {
            estadoCivil = n;
            return true;
        } return false;
    }
    /* Cargar y Mostrar */
    void Cargar() {
        cout<<"Ingrese nombre: "; cargarCadena(nombre, 47);
        cout<<"Ingrese apellido: "; cargarCadena(apellido, 47);
        char gen = 'N';
        while(!setGenero(gen)) {
            cout<<"Ingrese género (M/F/O): "; cin>>gen;
        }
        cout<<"Ingrese N.º de DNI: "; cin>>DNI;
        cout<<"Ingrese fecha de nacimiento: "; fechaDeNacimiento.load(false);

        int ntemp = -1;
        while(!setNacionalidad(ntemp)) {
            cout<< "Ingrese la nacionalidad(0: ARG, 1: URU, 2: BRA, 3: PAR, 4: CHI, 5: BOL, 6: MEX, 7: COL, 8:ESP, 9: PER): ";
            cin>>ntemp;
        }
        cout<<"Ingrese número de teléfono: "; cargarCadena(numeroTelefono, 23);

        int ntempes = -1;
        while(!setEstadoCivil(ntempes)) {
            cout<<"Ingrese estado civil. 0 => Soltero, 1 => Casado, 2 => Relación.: ";
            cin>>ntempes;
        }
    }
    void Mostrar() {
        cout<<"\t"<<apellido<<", "<<nombre<<endl;
        cout<<"\tGénero: "<<genero<<". "<<endl;
        cout<<"\tN.º de DNI: "<<DNI<<". "<<endl;
        cout<<"\tFecha de nacimiento: "; fechaDeNacimiento.print(fechaDeNacimiento.SP_FULL, false, false); cout<<endl;
        cout<<"\tNacionalidad: "; printNacionalidad(); cout<<endl;
        cout<<"\tNúmero de teléfono: "<<numeroTelefono<<endl;
        cout<<"\tEstado civil: "; printEstadoCivil(); cout<<endl;
    }
    /* Constructores */
    Persona() {}
    Persona(const char * a, const char * n, char gen, int p, Date fn, int pe, const char * t, int e) {
        strcpy(apellido, a);
        strcpy(nombre, n);
        setGenero(gen);
        DNI = p;
        fechaDeNacimiento.copyFrom(fn);
        setNacionalidad(pe);
        strcpy(numeroTelefono, t);
        setEstadoCivil(e);
    }
    /* Destructores */
    ~Persona() {}
    /*
       Atención:
       Se omitieron los métodos .leerDeArchivo(int[, const char *]) y .escribirEnArchivo([const char *]) porque no son necesarios.
    */
};

#endif // PERSONAS_H_INCLUDED

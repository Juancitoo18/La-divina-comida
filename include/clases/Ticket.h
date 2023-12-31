#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

class Ticket {
private:
    int codigo;
    int codCliente;
    int codSucursal;
    int codMozo;
    float neto = 0;
    float impuestos = 0;
    int medioDePago; // 0 => Efectivo, 1 => Tarjeta de crédito/débito, 2 => Transferencia bancaria, 3 => Cheque, 4 => Pagaré
    Date fechaDeLaOperacion;
    bool estado;
public:
     /* Gets */
    void calcularNeto() {
        Detalle dt; int pos = 0;
        while(dt.leerDeArchivo(pos++)) {
            if(dt.getEstado() && dt.getCodigoTicket() == codigo) {
                neto += dt.getImporte();
            }
        }
    }
    void aplicarImpuesto(float porcentaje) {
        impuestos = (neto * (porcentaje / 100));
    }
    float calcularTotal() {
        return neto + impuestos;
    }
    int getCodigo() {return codigo;}
    int getNumeroCliente() {return codCliente;}
    int getCodigoSucursal() {return codSucursal;}
    int getCodigoMozo() {return codMozo;}
    Cliente getCliente() {
        Cliente aux;
        getByNumeroCliente(codCliente,aux);
        return aux;
    }
    Sucursal getSucursal() {
        Sucursal aux;
        getByCodigoSucursal(codSucursal, aux);
        return aux;
    }
    Mozo getMozo() {
        Mozo aux;
        getByCodigoMozo(codMozo, aux);
        return aux;
    }
    float getNeto() {return neto;}
    float getImpuestos() {return impuestos;}
    float getTotal() {return neto + impuestos;}
    int getMedioDePago() {return medioDePago;}
    void printMedioDePago() {
        char mediosDePago[5][24] = {
            "Efectivo", "Tarjeta", "Transferencia", "Cheque", "Pagaré"
        };
        cout<<mediosDePago[medioDePago];
    }
    bool activarCompra() {
        return activarProductos(codigo);
    }
    Date getFechaOperacion() {return fechaDeLaOperacion;}
    bool getEstado() {return estado;}
    /* Sets */
    void setCodigo(int n) {codigo = n;}
    bool setCliente(int c) {
        Cliente aux;
        int y = getByNumeroCliente(c,aux);
        if(y != -1) {
            codCliente = c;
            return true;
        } else return false;
    }
    bool setSucursal(int c) {
        Sucursal aux;
        int y = getByCodigoSucursal(c, aux);
        if(y != -1 && aux.getEstado()) {
            codSucursal = c;
            return true;
        } else return false;
    }
    bool setMozo(int c) {
        Mozo aux;
        int y = getByCodigoMozo(c, aux);
        if(y != -1) {
            codMozo = c;
            return true;
        } else return false;
    }
    void setNeto(float n) {neto = n;}
    void setImpuestos(float n) {impuestos = n;}
    void setMedioDePago(int t) {medioDePago = t % 5;}
    void setFechaOperacion(Date n) {
        fechaDeLaOperacion.copyFrom(n);
    }
    void setEstado(bool n) {estado = n;}


    /* Cargar y Mostrar */
    bool Cargar(int n = -1) {
        // Ingreso código de Ticket
        if(n == -1) {
            cout<<"Ingrese código de Ticket: "; cin>>codigo;
        } else {
            codigo = n;
            cout<<"(Código de Ticket: "<<n<<"). "<<endl;
        }

        int cantidadProductosEnLaNada = getCantidadProductosEnLaNada(codigo);
        int cantidadPlatos = 0;
        // Ingreso de los platos
        int c; Plato aux;
        cout<<endl<<"[PLATOS]"<<endl;
        cout<<"Ingrese código de comida (0 para finalizar carga de comidas): "; cin>>c;
        while(c > 0) {
            int p = getByCodigoComida(c,aux);
            if(p != -1 && aux.getEstado()) { // Si el código es válido...
                cout<<"\t("<<aux.getNombre()<<")";
                cout<<" Ingrese cantidad: "; int codigop; cin>>codigop;
                Detalle dt(codigo, c, 0, codigop, false);
                if(codigop>0){
                 if(dt.escribirEnArchivo()) {
                    neto += dt.getImporte();
                    cantidadPlatos += dt.getCantidad();
                    cout<<"\t\tGuardado."<<endl;
                    }
                }
            }
            cout<<"Ingrese código de comida (0 para finalizar carga de comidas): "; cin>>c;
        }

        // Ingreso de las bebidas
        int bb; Bebida x; int cantidadBebidas = 0;
        cout<<endl<<"[BEBIDAS]"<<endl;
        cout<<"Ingrese código de bebida (0 para finalizar carga de bebidas): "; cin>>bb;
        while(bb > 0) {
            int p = getByCodigoBebidas(bb,x);
            if(p != -1 && x.getEstado()) { // Si el código es válido...
                cout<<"\t("<<x.getNombre()<<")";
                cout<<" Ingrese cantidad: "; int codigobb; cin>>codigobb;
                Detalle dy(codigo, bb, 1, codigobb, false);
                if(codigobb>0){
                    if(dy.escribirEnArchivo()) {
                        neto += dy.getImporte();
                        cantidadBebidas += dy.getCantidad();
                        cout<<"\t\tGuardado."<<endl;
                    }
                }
            }
            cout<<"Ingrese código de bebida (0 para finalizar carga de bebidas): "; cin>>bb;
        }
        bool alMenosUnProductoEnLaLista = (cantidadProductosEnLaNada > 0 || cantidadPlatos > 0 || cantidadBebidas > 0);
        if(!alMenosUnProductoEnLaLista) {
            cout<<"\tSe canceló la carga de la venta debido a que hay cero productos. "<<endl;
            return false;
        }

        // Ingreso del cliente que realizó la compra
        bool clienteIncorrecto = true;
        int codi;
        while(clienteIncorrecto) {
            cout<<"Ingrese número de cliente: ";
            cin>>codi;
            Cliente aux;
            if(getByNumeroCliente(codi,aux) == -1 || !aux.getEstado()) {
                cout<<"El código ingresado no corresponde con ningún registro. Intente de nuevo. "<<endl;
            } else {
                cout<<endl<<"El código corresponde al cliente "<<aux.getApellido()<<", "<<aux.getNombre()<<". "<<endl;
                codCliente = codi;
                clienteIncorrecto = false;
            }
        }

        // Ingreso de la sucursal dónde se realizó la compra e informar quiénes son los mozos que trabajan allí.
        bool sucursalIncorrecta = true;
        while(sucursalIncorrecta) {
            cout<<"Ingrese número de sucursal: "; int sc; cin>>sc;
            if(setSucursal(sc)) {
                sucursalIncorrecta = false;
                Sucursal ex;
                getByCodigoSucursal(sc, ex);
                cout<<ex.getNombre()<<". Mozos: ";
                int pd = 0; Mozo au;
                while(au.leerDeArchivo(pd++)) {
                    if(au.getEstado() && au.getCodigoSucursal() == sc) cout<<"#"<<au.getCodigo()<<"; ";
                }
                cout<<endl;
            } else {
                cout<<"La sucursal ingresada no existe en los registros. "<<endl;
            }
        }

        // Ingreso del mozo que atendió al cliente
        bool mozoIncorrecto = true;
        while(mozoIncorrecto) {
            cout<<"Ingrese código del mozo que atendió: "; int c; cin>>c;
            Mozo aux;
            if(getByCodigoMozo(c, aux) == -1 || !aux.getEstado())
                cout<<"El código ingresado no corresponde con ningún registro. Intente de nuevo. "<<endl;
            else {
                if(aux.getCodigoSucursal() == codSucursal && aux.getEstado()) {
                    cout<<endl<<"El código corresponde al mozo "<<aux.getApellido()<<", "<<aux.getNombre()<<". "<<endl;
                    mozoIncorrecto = false;
                    codMozo = c;
                } else {
                    cout<<"El mozo ingresado no existe o no trabaja en la sucursal. "<<endl;
                }
            }
        }
        // Se calcula el valor neto
        cout<<endl<<"(El neto es de $"<<neto<<".)"<<endl;

        // Ingreso del % de impuestos a aplicar
        //float prc;
        //cout<<"Ingrese el % de impuestos a aplicar: "; cin>>prc;
        Iva cobj;
        cobj.leerDeArchivo();
        cout<< "Se aplicará un "<<cobj.getIva()<<"% de impuestos. (Se puede modificar desde Configuración). "<<endl;


        aplicarImpuesto(cobj.getIva());
        //aplicarImpuesto(prc);

        // Se calcula el total
        cout<<"(Total: $"<<getTotal()<<".)"<<endl;

        // Ingreso del medio de pago utilizado.
        cout<<"Ingrese el medio de pago utilizado: (0 = Efectivo, 1 = Tarjeta, 2 = Transferencia, 3 = Cheque, 4 = Pagaré): ";
        cin>>medioDePago;
        medioDePago %= 5;

        // Ingreso de la fecha de la operación.
        cout<<"Ingrese la fecha de la operación: "<<endl;
        Date af, today;
        bool noPase = true;
        while(noPase) {
            today.now();
            af.load(true);
            if(af.happensBefore(today)) {
                noPase = false;
                fechaDeLaOperacion.copyFrom(af);
            } else Error(9).print();
        }

       // if(activarProductos(codigo)) cout<<"Se guardó la información de la venta correctamente. "<<endl;

        estado = true;
        return true;
    }
    void Mostrar() {
        if(getEstado()) {
            cout<<endl;
            cout<<"\tLA DIVINA COMIDA"<<endl;
            Sucursal sc = getSucursal();
            cout<<"\t"<<sc.getNombre()<<" (#"<<sc.getCodigo()<<"). ";
            cout<<"\n\tTicket #"<<codigo<<". "<<endl<<endl;
            cout<<"\t"; fechaDeLaOperacion.print(fechaDeLaOperacion.SP_FULL, true, false); cout<<endl;

            cout<<endl;
            if(getCantidadPlatos(codigo) > 0) {
                cout<<"\tPlatos: "<<endl;
                Plato pt; Detalle dt; int ps = 0;
                while(dt.leerDeArchivo(ps++)) {
                    if(dt.getEstado() && dt.getCodigoTicket() == codigo && dt.getTipoProducto() == 0) {
                        int y = getByCodigoComida(dt.getCodigoProducto(),pt);
                        if(y > 0)
                            dt.Imprimir();
                    }
                }
            }
            if(getCantidadBebidas(codigo) > 0) {
                cout<<endl<<"\tBebidas: "<<endl;
                Bebida bd; int ps = 0; Detalle dt;
                while(dt.leerDeArchivo(ps++)) {
                    if(dt.getEstado() && dt.getCodigoTicket() == codigo && dt.getTipoProducto() == 1) {
                        int y = getByCodigoBebidas(dt.getCodigoProducto(),bd);
                        if(y > 0) {
                            dt.Imprimir();
                        }
                    }
                }
            }

            Cliente cl = getCliente();
            if(cl.getEstado()) {
                cout<<endl<<"\tCliente: "<<cl.getApellido()<<", "<<cl.getNombre()<<". Forma de pago: "; printMedioDePago(); cout<<". "<<endl;
            }
            Mozo mz = getMozo();
            cout<<"\tMozo: "<<mz.getApellido()<<", "<<mz.getNombre()<<". (#"<<codMozo<<"). "<<endl;
            cout<<endl<<"\tNeto: $"<<neto<<". "<<endl;
            cout<<"\tImpuestos: $"<<impuestos<<". "<<endl;
            printTotal(getTotal()); cout<<endl<<endl;
            setCL(0xC);
            cout<<endl<<"----------------------------------------------------------------------"<<endl;
            setCL(0xF);
        }
    }
    /* Constructores */
    Ticket() {}
    Ticket(int cod, int cc, int sc, int cmz, float porcentaje_impuestos, Date fechaOperacion) {
        codigo = cod;
        setCliente(cc);
        setSucursal(sc);
        setMozo(cmz);
        calcularNeto();
        aplicarImpuesto(porcentaje_impuestos);
        fechaDeLaOperacion.copyFrom(fechaOperacion);
        estado = true;
    }
    /* Destructor */
    ~Ticket() {}
    /* Lectura y escritura de archivos */
    bool leerDeArchivo(int pos, const char * filename = "datos/ventas.dat") {
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
    bool escribirEnArchivo(const char * filename = "datos/ventas.dat") {
        FILE * archivo = fopen(filename, "ab");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos, const char * filename = "datos/ventas.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }

};

#endif // TICKET_H_INCLUDED

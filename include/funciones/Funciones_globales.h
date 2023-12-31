#ifndef FUNCIONES_GLOBALES_H_INCLUDED
#define FUNCIONES_GLOBALES_H_INCLUDED
///Sucursales

int getByCodigoSucursal(int codigoABuscar, Sucursal &suc, const char * filename = "datos/sucursales.dat")
{
    int pos = 0;
    while(suc.leerDeArchivo(pos++, filename))
    {
        if(suc.getEstado() && suc.getCodigo() == codigoABuscar) return pos;
    }
    return -1;
}
int getNextIndexSucursal(const char * filename = "datos/sucursales.dat")
{
    Sucursal sucur;
    int pos = 0, i = 1;
    while(sucur.leerDeArchivo(pos++, filename)) i++;
    return i;
}
void ManageSucursal(int posicion,Sucursal &sucur)
{
    char nombre[48];
    sucur.Mostrar();
    cout<<"\t Menu Sucursal: "<<endl<<endl;
    cout<<"\t 1. Modificar nombre de sucursal"<<endl;
    cout<<"\t 2. Eliminar"<<endl;
    cout<<"\t 0. Salir."<<endl;
    int opc = UserChoose(false);
    switch(opc)
    {
    case 1:
        cout<<"Ingrese nuevo nombre de sucursal: ";
        cargarCadena(nombre, 47);
        sucur.setNombre(nombre);
        if(sucur.modificarDelArchivo(posicion)) cout<<"\n Se modificó correctamente. "<<endl;
        break;
    case 2:
        cout<<"Para confirmar el borrado, vuelva a ingresar el código del Sucursal: ";
        int g;
        cin>>g;
        if(g == sucur.getCodigo())
        {
            sucur.setEstado(false);
            bool b = (sucur.modificarDelArchivo(posicion));
            if(b) cout<<"\n Se ha borrado correctamente el registro. "<<endl;
        }
        break;
    default:
        break;
    }
}
///Comidas

int getByCodigoComida(int codigoABuscar, Plato &plato, const char * filename = "datos/comidas.dat")
{
    int pos = 0;
    while(plato.leerDeArchivo(pos++, filename))
    {
        if(plato.getEstado() && plato.getCodigo() == codigoABuscar) return pos;
    }
    return -1;
}
int getByNameComida(const char * name, Plato &plato, const char * filename = "datos/comidas.dat")
{
    int pos = 0;
    while(plato.leerDeArchivo(pos++, filename))
    {
        if(plato.getEstado() && strcmp(plato.getNombre(), name) == 0) return pos;
    }
    return -1;
}
int getNextIndexComida(const char * filename = "datos/comidas.dat")
{
    Plato plato;
    int pos = 0, e = 1;
    while(plato.leerDeArchivo(pos++, filename))
        e++;
    return e;
}
void ManageComida(int posicion, Plato &plato)
{
    char nombre[72];
    plato.Mostrar();
    cout<<"\tMenu Comidas: "<<endl;
    cout<<"\n\t1. Cambiar nombre";
    cout<<"\n\t2. Cambiar nacionalidad";
    cout<<"\n\t3. Cambiar precio";
    cout<<"\n\t4. Cambiar tipo de plato";
    cout<<"\n\t5. Alternar Gluten ["<<(plato.contieneGluten()?"ON":"OFF")<<"]";
    cout<<"\n\t6. Alternar Carne ["<<(plato.contieneCarne()?"ON":"OFF")<<"]";
    cout<<"\n\t7. Alternar Huevo ["<<(plato.contieneHuevo()?"ON":"OFF")<<"]";
    cout<<"\n\t8. Alternar Azúcar ["<<(plato.contieneAzucar()?"ON":"OFF")<<"]";
    cout<<"\n\t9. Alternar Maní ["<<(plato.contieneMani()?"ON":"OFF")<<"]";
    cout<<"\n\t10. Alternar Chocolate ["<<(plato.contieneChocolate()?"ON":"OFF")<<"]";
    cout<<"\n\t11. Eliminar de los registros";
    cout<<"\n\t0. Salir.";
    cout<<endl;
    int opc = UserChoose(false);
    cout<<endl;
    bool esNecesarioModificarElArchivo = false;
    switch(opc)
    {
    case 1:
    {
        cout<<"Ingrese nombre: ";
        cargarCadena(nombre, 71);
        plato.setNombre(nombre);
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 2:
    {
        cout<<"Ingrese nueva nacionalidad: ";
        int n;
        cin>>n;
        plato.setNacionalidad(n);
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 3:
    {
        cout<<"Ingrese nuevo precio: $";
        float p;
        cin>>p;
        if(plato.setPrecio(p))
        {
            esNecesarioModificarElArchivo = true;
        }
        else
        {
            cout<<"El precio ingresado es inadmisible. "<<endl;
        }
        break;
    }
    case 4:
    {
        cout<<"Ingrese tipo de plato: ";
        int y;
        cin>>y;
        if(plato.setTipo(y)) esNecesarioModificarElArchivo = true;
        else Error(0).print();
        break;
    }
    case 5:
    {
        if(plato.contieneGluten())
        {
            plato.setGluten(false);
        }
        else
        {
            plato.setGluten(true);
        }
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 6:
    {
        if(plato.contieneCarne())
        {
            plato.setCarne(false);
        }
        else
        {
            plato.setCarne(true);
        }
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 7:
    {
        if(plato.contieneHuevo())
        {
            plato.setHuevo(false);
        }
        else
        {
            plato.setHuevo(true);
        }
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 8:
    {
        if(plato.contieneAzucar())
        {
            plato.setAzucar(false);
        }
        else
        {
            plato.setAzucar(true);
        }
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 9:
    {
        if(plato.contieneMani())
        {
            plato.setMani(false);
        }
        else
        {
            plato.setMani(true);
        }
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 10:
    {
        if(plato.contieneChocolate())
        {
            plato.setChocolate(false);
        }
        else
        {
            plato.setChocolate(true);
        }
        esNecesarioModificarElArchivo = true;
        break;
    }
    case 11:
    {
        cout<<"Para confirmar ingrese el código del plato: ";
        int e;
        cin>>e;
        if(e == plato.getCodigo())
        {
            plato.setEstado(false);
            esNecesarioModificarElArchivo = true;
        }
        break;
    }
    default:
    {
        break;
    }
    }
    if(esNecesarioModificarElArchivo)
    {
        if(plato.modificarDelArchivo(posicion))
        {
            cout<<"Los cambios se modificaron exitosamente en el archivo. "<<endl;
        }
        else Error(0).print();
    }
}
/// bebidas

int getByCodigoBebidas(int codigoABuscar, Bebida &bebi, const char * filename = "datos/bebidas.dat")
{
    int pos = 0;
    while(bebi.leerDeArchivo(pos++, filename))
    {
        if(bebi.getEstado() && bebi.getCodigo() == codigoABuscar) return pos;
    }
    return -1;
}
int getByNameBebidas(const char * name, Bebida &bebi, const char * filename = "datos/bebidas.dat")
{
    int pos = 0;
    while(bebi.leerDeArchivo(pos++, filename))
    {
        if(bebi.getEstado() && strcmp(bebi.getNombre(), name) == 0) return pos;
    }
    return -1;
}
int getNextIndexBebidas(const char * filename = "datos/bebidas.dat")
{
    Bebida bebi;
    int pos = 0, i = 1;
    while(bebi.leerDeArchivo(pos++, filename)) i++;
    return i;
}
void ManageBebidas(int posicion, Bebida &bebi)
{
    char nombre[40];
    bebi.Mostrar();
    cout<<"\tMenu Bebidas: "<<endl;
    cout<<"\n\t1. Cambiar nombre de la bebida.";
    cout<<"\n\t2. Cambiar precio. ";
    cout<<"\n\t3. Alternar 'Tiene Alcohol' ["<<(bebi.contieneAlcohol()?"ON":"OFF")<<"]";
    cout<<"\n\t4. Alternar 'Tiene azúcar' ["<<(bebi.contieneAzucar()?"ON":"OFF")<<"]";
    cout<<"\n\t5. Eliminar.";
    cout<<"\n\t0. Salir.";
    cout<<endl;
    int opc = UserChoose(false);
    cout<<endl;
    switch(opc)
    {
    case 1:
    {
        cout<<"Ingrese nuevo nombre de bebida: ";
        cargarCadena(nombre, 39);
        bebi.setNombre(nombre);
        if(bebi.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 2:
    {
        cout<<"Ingrese el nuevo precio: $";
        float tmp;
        cin>>tmp;
        if(bebi.setPrecio(tmp) && bebi.modificarDelArchivo(posicion)) cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"Hubo un problema. Quizá se recibió un precio menor o igual a $0 o hubo un error al intentar guardar los cambios. "<<endl;
        break;
    }
    case 3:
    {
        if(bebi.contieneAlcohol())
        {
            bebi.setAlcohol(false);
        }
        else
        {
            bebi.setAlcohol(true);
        }
        if(bebi.modificarDelArchivo(posicion)) cout<<"Se han guardado los cambios. "<<endl;
        else Error(4).print();
        break;
    }
    case 4:
    {
        if(bebi.contieneAzucar())
        {
            bebi.setAzucar(false);
        }
        else
        {
            bebi.setAzucar(true);
        }
        if(bebi.modificarDelArchivo(posicion)) cout<<"Se han guardado los cambios. "<<endl;
        else Error(4).print();
        break;
    }
    case 5:
    {
        cout<<"Para confirmar el borrado, vuelva a ingresar el código de la Bebida: ";
        int g;
        cin>>g;
        if(g == bebi.getCodigo())
        {
            bebi.setEstado(false);
            bool b = (bebi.modificarDelArchivo(posicion));
            if(b) cout<<"\n Se ha borrado correctamente el registro. "<<endl;
        }
        break;
    }
    default:
        break;
    }
}
///Clientes

int getByNumeroCliente(int codigoABuscar, Cliente &cli, const char * filename = "datos/clientes.dat")
{
    int pos = 0;
    while(cli.leerDeArchivo(pos++, filename))
    {
        if(cli.getEstado() && cli.getNumeroCliente() == codigoABuscar) return pos;
    }
    return -1;
}
int getByDNICliente(int numeroDNIABuscar, Cliente &cli, const char * filename = "datos/clientes.dat")
{
    int pos = 0;
    while(cli.leerDeArchivo(pos++, filename))
    {
        if(cli.getEstado() && cli.getDNI() == numeroDNIABuscar) return pos;
    }
    return -1;
}
int getByNumeroTelefonoCliente(const char * telefon, Cliente &cli, const char * filename = "datos/clientes.dat")
{
    int pos = 0;
    while(cli.leerDeArchivo(pos++, filename))
    {
        if(cli.getEstado() && strcmp(telefon, cli.getNumeroTelefono()) == 0) return pos;
    }
    return -1;
}
int getNextIndexCliente(const char * filename = "datos/clientes.dat")
{
    Cliente cli;
    int pos = 0, e = 1;
    while(cli.leerDeArchivo(pos++, filename)) e++;
    return e;
}
void ManageCliente(int posicion, Cliente &cli)
{
    char nombre[48];
    char apellido[48];
    char tele[24];
    char gen;
    int DNI,Nacionalidad,estadocivil;
    cli.Mostrar();
    cout<<"\tMenu Clientes: "<<endl;
    cout<<"\n\t1. Cambiar Nombre ";
    cout<<"\n\t2. Cambiar Apellido ";
    cout<<"\n\t3. Cambiar Genero ";
    cout<<"\n\t4. Cambiar DNI ";
    cout<<"\n\t5. Cambiar Fecha de Nacimiento ";
    cout<<"\n\t6. Cambiar Nacionalidad ";
    cout<<"\n\t7. Cambiar Telefono ";
    cout<<"\n\t8. Cambiar Estado Civil ";
    cout<<"\n\t9. Eliminar ";
    cout<<"\n\t0. Salir ";
    cout<<endl;
    int opc = UserChoose();
    cout<<endl;
    switch(opc)
    {
    case 1:
    {
        cout<<"Ingrese nuevo nombre del cliente: ";
        cargarCadena(nombre, 47);
        cli.setNombre(nombre);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 2:
    {
        cout<<"Ingrese nuevo apellido del cliente: ";
        cargarCadena(apellido, 47);
        cli.setApellido(apellido);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 3:
    {
        cout<<"Ingrese género (M/F/O): ";
        cin>>gen;
        cli.setGenero(gen);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 4:
    {
        cout<<"Ingrese Nuevo DNI: ";
        cin>>DNI;
        cli.setDNI(DNI);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 5:
    {
        Date FechaM;
        cout<<"Ingrese Nueva Fecha de Nacimiento: "<<endl;
        FechaM.load(false);
        cli.setFechaDeNacimiento(FechaM);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 6:
    {
        cout<<"Ingrese Nueva Nacionalidad: ";
        cin>>Nacionalidad;
        cli.setNacionalidad(Nacionalidad);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 7:
    {
        cout<<"Ingrese Nuevo Numero Telefonico: ";
        cargarCadena(tele,23);
        cli.setNumeroTelefono(tele);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 8:
    {
        cout<<"Ingrese Nuevo estado civil. 0 => Soltero, 1 => Casado, 2 => Relación.: ";
        cin>>estadocivil;
        cli.setEstadoCivil(estadocivil);
        if(cli.modificarDelArchivo(posicion))
            cout<<"Los cambios se guardaron exitosamente. "<<endl;
        else cout<<"No se guardaron los cambios. "<<endl;
        break;
    }
    case 9:
    {
        cout<<"Para confirmar ingrese de nuevo el número de cliente: ";
        int y;
        cin>>y;
        if(y == cli.getNumeroCliente())
        {
            cli.setEstado(false);
            if(cli.modificarDelArchivo(posicion)) cout<<"Se eliminó correctamente del archivo. "<<endl;
            else Error(5).print();
        }
        break;
    }
    default:
    {
        break;
    }
    }
}
#endif // FUNCIONES_GLOBALES_H_INCLUDED

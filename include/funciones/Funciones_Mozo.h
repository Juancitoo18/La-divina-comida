#ifndef FUNCIONES_MOZO_H_INCLUDED
#define FUNCIONES_MOZO_H_INCLUDED

int getByCodigoMozo(int codigoABuscar, Mozo &mozo, const char * filename = "datos/mozos.dat")
{
    int pos = 0;
    while(mozo.leerDeArchivo(pos++, filename))
    {
        if(mozo.getEstado() && mozo.getCodigo() == codigoABuscar) return pos;
    }
    return -1;
}
int getByDNIMozo(int DNIABuscar, Mozo &mozo, const char * filename = "datos/mozos.dat")
{
    int pos = 0;
    while(mozo.leerDeArchivo(pos++, filename))
    {
        if(mozo.getEstado() && mozo.getDNI() == DNIABuscar) return pos;
    }
    return -1;
}
int getByNumeroTelefonoMozo(const char * telefon, Mozo &mozo, const char * filename = "datos/mozos.dat")
{
    int pos = 0;
    while(mozo.leerDeArchivo(pos++, filename))
    {
        if(mozo.getEstado() && strcmp(telefon, mozo.getNumeroTelefono()) == 0) return pos;
    }
    return -1;
}
int getNextIndexMozo(const char * filename = "datos/mozos.dat")
{
    Mozo mozo;
    int pos = 0, p = 1;
    while(mozo.leerDeArchivo(pos++, filename)) p++;
    return p;
}
void ManageMozo(int posicion, Mozo &mozo)
{
    char nombre[48];
    char apellido[48];
    char tele[24];
    char gen;
    int DNI,Nacionalidad,estadocivil;
        mozo.Mostrar();
        cout<<"\tMenu Mozos: "<<endl;
        cout<<"\n\t1. Cambiar Nombre ";
        cout<<"\n\t2. Cambiar Apellido ";
        cout<<"\n\t3. Cambiar Genero ";
        cout<<"\n\t4. Cambiar DNI ";
        cout<<"\n\t5. Cambiar Fecha de Nacimiento ";
        cout<<"\n\t6. Cambiar Nacionalidad ";
        cout<<"\n\t7. Cambiar Telefono ";
        cout<<"\n\t8. Cambiar Estado Civil ";
        cout<<"\n\t9. Cambiar código de sucursal dónde trabaja.";
        cout<<"\n\t10. Despedir (Borrar de los registros de mozo).";
        cout<<"\n\t0. Salir."<<endl;
        int opc = UserChoose(false);
        switch(opc)
        {
        case 1:
        {
            cout<<"Ingrese nuevo nombre del cliente: ";
            cargarCadena(nombre, 47);
            mozo.setNombre(nombre);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 2:
        {
            cout<<"Ingrese nuevo apellido del cliente: ";
            cargarCadena(apellido, 47);
            mozo.setApellido(apellido);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 3:
        {
            cout<<"Ingrese género (M/F/O): ";
            cin>>gen;
            mozo.setGenero(gen);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 4:
        {
            cout<<"Ingrese Nuevo DNI: ";
            cin>>DNI;
            mozo.setDNI(DNI);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 5:
        {
            Date FechaM;
            cout<<"Ingrese Nueva Fecha de Nacimiento: "<<endl;
            FechaM.load(false);
            mozo.setFechaDeNacimiento(FechaM);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 6:
        {
            cout<<"Ingrese Nueva Nacionalidad: ";
            cin>>Nacionalidad;
            mozo.setNacionalidad(Nacionalidad);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 7:
        {
            cout<<"Ingrese Nuevo Numero Telefonico: ";
            cargarCadena(tele,23);
            mozo.setNumeroTelefono(tele);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 8:
        {
            cout<<"Ingrese Nuevo estado civil. 0 => Soltero, 1 => Casado, 2 => Relación.: ";
            cin>>estadocivil;
            mozo.setEstadoCivil(estadocivil);
            if(mozo.modificarDelArchivo(posicion))
                cout<<"Los cambios se guardaron exitosamente. "<<endl;
            else cout<<"No se guardaron los cambios. "<<endl;
            break;
        }
        case 9:
        {
            bool sucursalCargada = false;
            while(!sucursalCargada)
            {
                cout<<"Ingrese código de sucursal: ";
                int c;
                cin>>c;
                if(!mozo.setSucursal(c)) cout<<"Sucursal incorrecta. \n";
                else
                {
                    bool y = mozo.modificarDelArchivo(posicion);
                    if(y) cout<<"Se modificó exitosamente el registro. \n";
                    sucursalCargada = true;
                }
            }
            break;
        }
        case 10:
        {
            cout<<"Para confirmar el borrado, vuelva a ingresar el código del Mozo: ";
            int g;
            cin>>g;
            if(g == mozo.getCodigo())
            {
                mozo.setEstado(false);
                bool b = (mozo.modificarDelArchivo(posicion));
                if(b) cout<<"\n Se ha borrado correctamente el registro. "<<endl;
            }
            break;
        }
        case 0: return;
        default:
            break;
        }
}

#endif // FUNCIONES_MOZO_H_INCLUDED

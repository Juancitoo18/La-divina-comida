#ifndef FUNCIONES_VENTAS_H_INCLUDED
#define FUNCIONES_VENTAS_H_INCLUDED
/// Clase ticket
/* Gets especiales */
Ticket tick;
int getByCodigo(int codigoABuscar, const char * filename = "datos/ventas.dat")
{
    int pos = 0;
    while(tick.leerDeArchivo(pos++, filename))
    {
        if(tick.getEstado() && tick.getCodigo() == codigoABuscar) return pos;
    }
    return -1;
}
int getNextIndex(const char * filename = "datos/ventas.dat")
{
    int pos = 0, e = 1;
    while(tick.leerDeArchivo(pos++, filename))
        e++;
    return e;
}
void Manage(int posicion)
{
    int c = tick.getCodigo();
    tick.Mostrar();
    cout<<endl<<"\t1. Eliminar Ticket de los registros";
    cout<<endl<<"\t0. Volver al menú anterior";
    int opc = UserChoose();
    switch(opc)
    {
    case 1:
    {
        cout<<"Para confirmar el borrado, reingrese el código de Ticket: #";
        int cy = 0;
        cin>>cy;
        if(cy == c)
        {
            tick.setEstado(false);
            if(tick.modificarDelArchivo(posicion))
            {
                cout<<"Se eliminó correctamente. "<<endl;
            }
            else Error(5).print();
        }
        break;
    }
    case 0:
        return;
    default:
        break;
    }
}



#endif // FUNCIONES_VENTAS_H_INCLUDED

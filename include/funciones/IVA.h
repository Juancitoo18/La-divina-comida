#ifndef RECUPERAR_H_INCLUDED
#define RECUPERAR_H_INCLUDED

class Configuracion
{
private:
    float iva;
public:
    void setIva(float i)
    {
        iva=i;
    }
    float getIva()
    {
        return iva;
    }
    void Mostrar()
    {
        cout<< "PRECIO IVA: "<<iva<<endl;
    }
    bool leerDeArchivo(const char * filename = "datos/configuracion.dat") {
        FILE * archivo = fopen(filename, "rb");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        //fseek(archivo, (sizeof * this), 0);
        bool res = fread(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return res;
    }
    bool escribirEnArchivo(const char * filename = "datos/configuracion.dat") {
        FILE * archivo = fopen(filename, "wb");
        if(archivo == NULL) {
            Error(2).print();
            return false;
        }
        bool res = fwrite(this, sizeof (Configuracion), 1, archivo);
        fclose(archivo);
        return res;
    }
    bool modificarDelArchivo(int pos=0,const char * filename = "datos/configuracion.dat") {
        FILE * archivo;
        archivo = fopen(filename, "rb+");
        if(archivo == NULL) return false;
        fseek(archivo, (sizeof * this) * --pos, 0);
        bool escribio = fwrite(this, sizeof * this, 1, archivo);
        fclose(archivo);
        return escribio;
    }
};

#endif // RECUPERAR_H_INCLUDED

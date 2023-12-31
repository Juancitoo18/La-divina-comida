#ifndef ERRORES_H_INCLUDED
#define ERRORES_H_INCLUDED

const char * ERR_DESCRIPTION[128] = {
    "Error no especificado. ",
    "La opción seleccionada no tiene asignada una función. ",
    "Hubo un problema al intentar acceder al archivo en cuestión. ", // 2
    "Hubo un problema al intentar cerrar el archivo en cuestión. ", // 3
    "Hubo un error al intentar escribir en el archivo en cuestión. " // 4
  , "Hubo un error al intentar eliminar de forma lógica un registro en el archivo en cuestión. " //5
  , "No se ha encontrado un registro con los valores ingresados. " // 6
  , "Valor inválido. " // 7
  , "El intérprete no existe en el archivo de intérpretes. " // 8
  , "La fecha y hora ingresadas son posteriores a la fecha y hora actuales" // 9
};

class Error {
private:
    int code = 0;
public:
    void print() {
        cout<<"Err. "<<code<<": "<<ERR_DESCRIPTION[code]<<" "<<endl;
    }
    int getCode() {return code;}
    Error(int c) {
        code = c;
    }
};

#endif // ERRORES_H_INCLUDED

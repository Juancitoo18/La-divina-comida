/*
 * Máximo Canedo
 * Legajo: 25839
 * UTN FRGP
 *
 * Funciones básicas.
 *
 */
#ifndef BASICS_H_INCLUDED
#define BASICS_H_INCLUDED

int showVector(int *, int);
int getMax(int *, int);                     // Devuelve el valor máximo de un vector de enteros.
int getMaxIndex(int *, int);                // Devuelve el índice del valor máximo de un vector de enteros.
int getMin(int *, int, bool);               // Devuelve el valor mínimo (Y si el tercer parámetro es true, distinto de cero) de un vector de enteros.
int getMinIndex(int *, int, bool);          // Devuelve el índice del valor mínimo (Y si el tercer parámetro es true, distinto de cero) de un vector de enteros.
int countValues(int *, int, int);           // Cuenta las apariciones del tercer parámetro en el vector y lo devuelve.
int getIndexOf(int *, int, int);            // Devuelve la posición en el vector de un valor determinado, o -1 si no lo encontró.
float getAverage(int *, int);               // Devuelve el promedio de un vector de enteros...
float getAverage(float *, int);             // ... O de floats
int aCargar();                              // Le pide al usuario la cantidad de registros a cargar y lo devuelve como entero.
void informarCantRegistros(int, int);       // Muestra por pantalla el mensaje: "Mostrando x registros de y..."

void cargarCadena(char *, int);             // (Función dada en clase) Carga una cadena de texto.


int showVector(int * v, int s) {
    cout<<endl;
    for(int i = 0; i < s; i++) {
        cout<<"\t["<<i<<"] "<<v[i]<<". "<<endl;
    }
    cout<<endl;
    return 0;
}
int getMax(int * v, int s) {
    int max = v[0];
    for(int i = 1; i < s; i++) {
        if(v[i] > max) {
            max = v[i];
        }
    }
    return max;
}
int getMaxIndex(int * v, int s) {
    int max = v[0], index = 0;
    for(int i = 1; i < s; i++) {
        if(v[i] > max) {
            max = v[i];
            index = i;
        }
    }
    return index;
}
int getMin(int * v, int s, bool dc = false) {
    int min = v[0];
    for(int i = 1; i < s; i++) {
        if(v[i] < min) {
            min = v[i];
        }
    }
    return min;
}
int getMinIndex(int * v, int s, bool dc = false) {
    int min = v[0], index = 0;
    for(int i = 1; i < s; i++) {
        bool afirmacion = dc ? v[i] != 0 && v[i] < min : v[i] < min;
        if(afirmacion) {
            min = v[i];
            index = i;
        }
    }
    return index;
}
int countValues(int * v, int s, int val) {
    int contador = 0;
    for(int i = 0; i < s; i++)
        if(v[i] == val) contador++;
    return contador;
}
int getIndexOf(int * v, int s, int val) {
    int pos = -1;
    for(int i = 0; i < s; i++) {
        if(v[i] == val) return i;
    }
    return pos;
}
float getAverage(int * v, int s) {
    float suma = 0;
    for(int i = 0; i < s; i++) {
        suma += (float) v[i];
    }
    float mean = suma / s;
    return mean;
}
float getAverage(float * v, int s) {
    float suma = 0;
    for(int i = 0; i < s; i++) {
        suma += (float) v[i];
    }
    float mean = suma / s;
    return mean;
}
void cargarCadena(char *pal, int tam) {
    int i;
    fflush(stdin);
    for(i = 0; i < tam; i++){
        pal[i] = cin.get();
        if(pal[i] == '\n') break;
    }
    pal[i] = '\0';
    fflush(stdin);

}
int aCargar() {
    cout<<"Ingrese la cantidad de registros a cargar: ";
    int y; cin>>y;
    return y;
}

void informarCantRegistros(int fltrd, int total = -15) {
    if(total >= 0)
        cout<<endl<<"  Mostrando "<<fltrd<<" registro"<<(fltrd==1?"":"s")<<" de un total de "<<total<<". "<<endl<<endl;
    else
        cout<<endl<<"  Mostrando "<<fltrd<<" registro"<<(fltrd==1?"":"s")<<". "<<endl<<endl;
}


#endif // BASICS_H_INCLUDED

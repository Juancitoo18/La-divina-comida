/*
 * Máximo Canedo
 * Legajo N.º 25839
 *
 * Clases Menu, Item
 *
 * https://github.com/maximocanedo/Date
 *
 *
 */
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "rlutil.h"


int s() {
    Error(1).print();
    return 1;
}

class Item {
protected:
    char label[128];
    int opc;
    bool esOpcion = (opc >= 0);
    int (*callback)();
    int h = 0;
public:
    Item(int nro = -1, const char * l = "Opción no válida", int (*op)() = s, int h = 0) : opc(nro), callback(op) {
    strcpy(label, l);
    esOpcion = (opc >= 0);
    }

    const char * getLabel() {return label;}
    bool esOpc() {return esOpcion;}
    int getID() {return opc;}
    void Mostrar(int h = 0) {
        if(esOpcion) cout<<opc<<". "<<label<<" ";
        else {
            for(int i = 0; i < h; i++) cout<<"   ";
            cout<<" "<<label<<" ";
        }
    }
    int exec() {
        return callback();
    }
};

void setBG(int b) {
    rlutil::setBackgroundColor(b);
}
void setCL(int b) {
    rlutil::setColor(b);
}
char highlight(string e) {
    setBG(ACTIVE[0]);
    cout<<e;
    setBG(INACTIVE[0]);
    return ' ';
}

void drawOptionInScreen(Item option, int x, int y, bool onHover) {
    int inactiveBG    = INACTIVE[0];
    int inactiveColor = INACTIVE[1];

    int activeBG      = ACTIVE[0];
    int activeColor   = ACTIVE[1];
    bool esOpcion = option.esOpc();
    if(onHover && esOpcion) { // Si el elemento en cuestión está seleccionado..
        setBG(activeBG); // Se pinta el fondo de amarillo,
        setCL(activeColor); // Y se escribe en blanco.
    } else  { // Si el elemento en cuestión no está seleccionado...
        setBG(inactiveBG); // Pintamos el fondo de rojo,
        setCL(inactiveColor); // Y escribimos en blanco.
    }
    rlutil::locate(x,y); // Nos ubicamos en la posición correspondiente...
    cout<<" "<<option.getLabel()<<" "<<endl; // Y escribimos finalmente el texto de la opción.
    setBG(inactiveBG); // Pintamos el fondo de negro,
    setCL(inactiveColor); // Y escribimos en blanco.
}

class Menu {
protected:
    Item * opciones;
    int _opciones;
    char titulo[72];
    int level = 0;
    char l[16] = "";
public:

    Item * getOptionList() {return opciones;}
    int getOptionsLength() {return _opciones;}
    const char * getTitle() {return titulo;}
    int getLevel() {return level;}
 /// Menu principal("Menú principal", 1, opciones, _cantidad);

    Menu(const char * tt, int lt, Item o[], int cantidadDeOpciones) {
        opciones = new Item[cantidadDeOpciones];
        if(opciones == NULL) return;
        for(int i = 0; i < cantidadDeOpciones; i++) opciones[i] = o[i];
        _opciones = cantidadDeOpciones;
        strcpy(titulo, tt);
        level = lt;
    }
    ~Menu() {
        delete[] opciones;
    }
    void write() {
        for(int j = 0; j < level; j++) cout<<"---";
            cout<<titulo<<endl;
        for(int i = 0; i < _opciones; i++) {
            for(int j = 0; j < level; j++) cout<<"   ";
            opciones[i].Mostrar(level);
            cout<<endl;
        }

    }

    int exec(int opt) {
        for(int i = 0; i < _opciones; i++) {
            if(opciones[i].getID() == opt) {
                opciones[i].exec();
                return 1;
            }
        }
        cout<<"Opción inválida. "<<endl;
        return 0;
    }

    void graph() {
        int optionsLength = getOptionsLength();
        int tabs = getLevel() + 5;
        Item * options = getOptionList();
        rlutil::cls();
        rlutil::hidecursor();
        int activeOption = 0;
        int ultimaOpcionSeleccionada = -1;

        while(true) {
            //rlutil::cls();
            rlutil::locate(tabs, 2);
            cout<<getTitle()<<endl;
            rlutil::locate(tabs, 4);
            cout<<"Elegí una opción: "<<endl;
            if(ultimaOpcionSeleccionada == -1) {
                for(int i = 0; i < optionsLength; i++)
                    drawOptionInScreen(options[i], tabs - 1, 6 + i, (activeOption == i));
                ultimaOpcionSeleccionada = 0;
            } else {
                drawOptionInScreen(options[ultimaOpcionSeleccionada], tabs -1, 6 + ultimaOpcionSeleccionada, false);
                drawOptionInScreen(options[activeOption], tabs - 1, 6 + activeOption, true);
            }

            rlutil::locate(tabs - 3, 6 + activeOption);
            ultimaOpcionSeleccionada = activeOption;
            int pressedKey = rlutil::getkey();
            switch(pressedKey) {
            case 14: {
                bool noHayaOpcion = true;
                while(noHayaOpcion) {
                    if(activeOption == 0) activeOption = optionsLength;
                    if(activeOption > 0) activeOption--;
                    noHayaOpcion = !options[activeOption].esOpc();
                }
                rlutil::locate(tabs - 3, 6 + activeOption);
                cout<<" "<<endl;
                break;
            }
            case 15: {
                bool noHayaOpcion = true;
                while(noHayaOpcion) {
                    if(activeOption == optionsLength - 1) activeOption = -1;
                    if(activeOption < optionsLength - 1) activeOption++;
                    noHayaOpcion = !options[activeOption].esOpc();
                }
                rlutil::locate(tabs - 3, 6 + activeOption);
                cout<<" "<<endl;
                break;
            }
            case 1:
                int numeroOpcion = options[activeOption].getID();
                rlutil::cls();
                rlutil::locate(0,0);
                exec(numeroOpcion);
                ultimaOpcionSeleccionada = -1;
                system("pause && cls");
                break;
            }
        }

    }

};

int UserChoose(bool clsAfter = true) {
    cout<<endl<<"Ingrese opción: ";
    int y; cin>>y;
    if(clsAfter) system("cls");
    return y;
}


#endif // MENU_H_INCLUDED

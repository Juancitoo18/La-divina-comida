#ifndef MENU_PRINCIPAL_H_INCLUDED
#define MENU_PRINCIPAL_H_INCLUDED

int exitProgram(); // Sale del programa

int exitProgram() {
    rlutil::locate(40,5);cout<< "GRACIAS POR USAR NUESTRO PROGRAMA <3"<<endl<<endl<<endl<<endl;
    exit(0);
    return 0;
}
int menuPrincipal() {
    Item opciones[] = {
        Item{1, "Administrar archivos y registros", menuArchivos},
        Item{2, "Reportes", menuReportes},
        Item{3, "Configuración", menuRecuperacion},
        Item{-1, ""},
        Item{0, "Salir del programa", exitProgram}
    };
    const int cantidadOpciones = sizeof opciones / sizeof(Item);
    Menu principal("Restaurante 'La Divina Comida'", 1, opciones, cantidadOpciones);
    principal.graph();
    return 0;
}

#endif // MENU_PRINCIPAL_H_INCLUDED

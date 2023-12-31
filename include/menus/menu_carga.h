#ifndef MENU_CARGA_H_INCLUDED
#define MENU_CARGA_H_INCLUDED

int menuArchivos();
int menuSucursales();
int menuMozos();
int menuPlatos();
int menuBebidas();
int menuClientes();
int menuVentas();


int menuSucursales() {
    Item opciones[] = {
        Item{1, "Cargar sucursales", cargarSucursales},
        Item{2, "Mostrar sucursales", mostrarSucursales},
        Item{3, "Administrar un registro particular", msuc},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuArchivos}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu sucursales("Sucursales", 1, opciones, _opciones);
    sucursales.graph();
    return 0;
}
int menuMozos() {
    Item opciones[] = {
        Item{1, "Cargar mozos", cargarMozos},
        Item{2, "Mostrar mozos", mostrarMozos},
        Item{3, "Administrar un registro particular", mmoz},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuArchivos}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu mozos("Mozo", 1, opciones, _opciones);
    mozos.graph();
    return 0;
}
int menuPlatos() {
    Item opciones[] = {
        Item{1, "Cargar platos", cargarComidas},
        Item{2, "Mostrar platos", mostrarPlatos},
        Item{3, "Administrar un registro particular", mpla},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuArchivos}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu platos("Platos", 1, opciones, _opciones);
    platos.graph();
    return 0;
}
int menuClientes() {
    Item opciones[] = {
        Item{1, "Cargar clientes", cargarClientes},
        Item{2, "Mostrar clientes", mostrarClientes},
        Item{3, "Administrar un registro particular", mcli},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuArchivos}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu clientes("Clientes", 1, opciones, _opciones);
    clientes.graph();
    return 0;
}
int menuBebidas() {
    Item opciones[] = {
        Item{1, "Cargar bebidas", cargarBebidas},
        Item{2, "Mostrar bebidas", mostrarBebidas},
        Item{3, "Administrar un registro particular", mbeb},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuArchivos}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu bebidas("Bebidas", 1, opciones, _opciones);
    bebidas.graph();
    return 0;
}
int menuVentas() {
    Item opciones[] = {
        Item{1, "Registrar ventas", cargarVentas},
        Item{2, "Mostrar ventas", mostrarVentas},
        Item{3, "Administrar un registro particular", mven},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuArchivos}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu ventas("Ventas", 1, opciones, _opciones);
    ventas.graph();
    return 0;
}
int menuArchivos() {
    Item opciones[] = {
        Item{100, "Sucursales", menuSucursales},
        Item{101, "Mozos", menuMozos},
        Item{102, "Platos", menuPlatos},
        Item{103, "Bebidas", menuBebidas},
        Item{104, "Clientes", menuClientes},
        Item{105, "Ventas", menuVentas},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu cargas("Seleccione el tipo de registro: ", 1, opciones, _opciones);
    cargas.graph();
    return 0;
}

#endif // MENU_CARGA_H_INCLUDED

#ifndef MENU_RECUPERACION_H_INCLUDED
#define MENU_RECUPERACION_H_INCLUDED

int menuRecuperacion() {
    Item opciones[] = {
        Item{1, "Realizar copia de seguridad de mozos", backupMozos},
        Item{2, "Realizar copia de seguridad de clientes", backupClientes},
        Item{3, "Realizar copia de seguridad de platos", backupPlatos},
        Item{4, "Realizar copia de seguridad de bebidas", backupBebidas},
        Item{5, "Realizar copia de seguridad de ventas", backupVentas},
        Item{6, "Realizar copia de seguridad de sucursales", backupSucursales},
        Item{-1, ""},
        Item{7, "Restaurar datos de mozos", restoreMozos},
        Item{8, "Restaurar datos de clientes", restoreClientes},
        Item{9, "Restaurar datos de platos", restorePlatos},
        Item{10, "Restaurar datos de bebidas", restoreBebidas},
        Item{11, "Restaurar datos de ventas", restoreVentas},
        Item{12, "Restaurar datos de sucursales", restoreSucursales},
        Item{-1, ""},
        Item{13, "Restablecer datos de inicio", restablecerDatosInicio},
        Item{14, "Establecer porcentaje de IVA", establecerIva},
        Item{-1, ""},
        Item{0, "Volver al menú anterior", menuPrincipal}
    };
    int _opciones = sizeof opciones / sizeof(Item);
    Menu recuperacion("Configuración", 1, opciones, _opciones);
    recuperacion.graph();
    return 0;
}


#endif // MENU_RECUPERACION_H_INCLUDED

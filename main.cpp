#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <locale.h>

using namespace std;

int menuPrincipal();

const int INACTIVE[] = {0x3, 0xF};
const int ACTIVE[] = {0xD, 0xF};

#include "include/librerias/Basics.h"
#include "include/librerias/errores.h"
#include "include/librerias/Iva.h"
#include "include/librerias/Fecha.h"
#include "include/librerias/Menu.h"

#include "include/clases/personas.h"
#include "include/clases/sucursales.h"
#include "include/clases/comidas.h"
#include "include/clases/bebidas.h"
#include "include/clases/clientes.h"
#include "include/funciones/Funciones_globales.h"
#include "include/clases/mozos.h"
#include "include/funciones/Funciones_Mozo.h"
#include "include/clases/Detalle.h"
#include "include/funciones/Funciones_Detalle.h"
#include "include/clases/Ticket.h"
#include "include/funciones/Funciones_ticket.h"
#include "include/clases/configuracion.h"

#include "include/funciones/cargar.h"
#include "include/funciones/mostrar.h"
#include "include/funciones/reportes.h"

#include "include/menus/menu_registros.h"
#include "include/menus/menu_carga.h"
#include "include/menus/menu_reportes.h"
#include "include/menus/menu_recuperacion.h"
#include "include/menus/menu_principal.h"

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");
    system("color 3E");
    menuPrincipal();
    system("pause");
    return 0;
}

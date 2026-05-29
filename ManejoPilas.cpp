#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

// Definición de la estructura de un nodo
struct Nodo
{
    int dato;
    Nodo *siguiente;
};

// puntero a la cima de la pila
Nodo *tope = NULL;

// contador de elementos
int cantidadElementos = 0;

// ============================================================================
// COLORES Y ESTILOS RETRO PARA CONSOLA
// ============================================================================
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AMARILLO "\033[33m"
#define AZUL "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BLANCO "\033[37m"
#define RESET "\033[0m"
#define NEGRITA "\033[1m"
#define ATENUADO "\033[2m"

// ============================================================================
// DECORACIONES ASCII RETRO
// ============================================================================
#define BORDE_SUPERIOR "╔════════════════════════════════════════════════════════════╗"
#define BORDE_INFERIOR "╚════════════════════════════════════════════════════════════╝"
#define BORDE_LATERAL "║"
#define DOBLE_LINEA "═════════════════════════════════════════════════════════════"
#define LINEA_SIMPLE "─────────────────────────────────────────────────────────────"
#define ESQUINA_SUP_IZQ "╔"
#define ESQUINA_SUP_DER "╗"
#define ESQUINA_INF_IZQ "╚"
#define ESQUINA_INF_DER "╝"
#define LINEA_VERTICAL "║"
#define LINEA_HORIZONTAL "═"

// ============================================================================
// FUNCIONES DE EFECTOS VISUALES RETRO
// ============================================================================

// Escribir texto con efecto de máquina de escribir
void escribirConEfecto(const string &texto, int velocidad = 20)
{
    for (char c : texto)
    {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(velocidad));
    }
}

// Limpiar pantalla de forma retro
void limpiarPantalla()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Imprimir línea de separación decorativa
void imprimirSeparador(char relleno = '=', int ancho = 59)
{
    cout << CYAN;
    for (int i = 0; i < ancho; i++)
    {
        cout << relleno;
    }
    cout << RESET << endl;
}

// Imprimir texto centrado en estilo retro
void imprimirCentrado(const string &texto, int ancho = 57)
{
    int espacios = (ancho - texto.length()) / 2;
    for (int i = 0; i < espacios; i++)
        cout << " ";
    cout << texto << endl;
}

// Imprimir panel retro
void imprimirPanel(const string &titulo, const string &contenido)
{
    cout << CYAN << BORDE_SUPERIOR << RESET << endl;
    cout << CYAN << BORDE_LATERAL << RESET;
    imprimirCentrado(titulo, 57);
    cout << CYAN << BORDE_LATERAL << RESET << endl;
    cout << CYAN << BORDE_LATERAL << RESET;
    imprimirCentrado(contenido, 57);
    cout << CYAN << BORDE_LATERAL << RESET << endl;
    cout << CYAN << BORDE_INFERIOR << RESET << endl;
}

// Mostrar encabezado retro (ASCII Art)
void mostrarEncabezado()
{
    limpiarPantalla();
    cout << MAGENTA << NEGRITA;
    cout << "\n";
    cout << "   ╔═══════════════════════════════════════════════════╗\n";
    cout << "   ║                                                   ║\n";
    cout << "   ║        ▀█████▄   ▀█████▄     ██▄█      ██        ║\n";
    cout << "   ║          █▀  ▄   ▀█     ▀█   ██ ▀█     ██        ║\n";
    cout << "   ║          █        ▄█      ▄  ██  █     ██        ║\n";
    cout << "   ║          ▀▀████▀  ▀██████▀   ▀▀  ▀     ██▀       ║\n";
    cout << "   ║                                                   ║\n";
    cout << "   ║         👾 MANEJADOR DE PILAS RETRO 👾           ║\n";
    cout << "   ║                                                   ║\n";
    cout << "   ╚═══════════════════════════════════════════════════╝\n";
    cout << RESET << endl;
}

// Animación de carga retro
void animacionCarga()
{
    cout << VERDE << "\n   ⏳ INICIALIZANDO SISTEMA";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << " ✓ LISTO\n" << RESET << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
}

// Mostrar información de un nodo insertado
void mostrarNotificacionInsert(Nodo *nuevoNodo, int valor)
{
    cout << VERDE << "\n   ▶ ELEMENTO INSERTADO CON ÉXITO" << RESET << endl;
    cout << VERDE << "   Valor: " << NEGRITA << valor << RESET << VERDE << " | Mem: " << CYAN << nuevoNodo << RESET << endl;
}

// Mostrar notificación general
void mostrarNotificacion(const string &mensaje, const string &color = VERDE)
{
    cout << "\n" << color << "   ▶ " << mensaje << RESET << endl;
}

// ============================================================================
// FUNCIONES ORIGINALES (SIN CAMBIOS EN LA LÓGICA)
// ============================================================================

// Validar entrada de datos
int validarNumero()
{
    int numero;
    while (!(cin >> numero))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << ROJO << "   ✗ Entrada inválida. Ingrese un número entero: " << RESET;
    }
    return numero;
}

// insertar dato (PUSH)
void insertar(int valor)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    // ENLAZAR NODO
    nuevoNodo->siguiente = tope;

    // NUEVO TOPE
    tope = nuevoNodo;
    cantidadElementos++;
    
    // MEJORADO: Visualización elegante
    mostrarNotificacionInsert(nuevoNodo, valor);
}

// MOSTRAR PILA
void mostrarPila()
{
    cout << "\n";
    if (tope == NULL)
    {
        cout << AMARILLO << "   ⚠ LA PILA ESTÁ VACÍA" << RESET << endl;
        return;
    }
    
    // MEJORADO: Panel retro elegante
    cout << CYAN << "   ╔" << DOBLE_LINEA << "╗" << RESET << endl;
    cout << CYAN << "   ║" << RESET;
    cout << MAGENTA << NEGRITA;
    imprimirCentrado("📦 CONTENIDO DE LA PILA", 57);
    cout << CYAN << "║" << RESET << endl;
    cout << CYAN << "   ╠" << DOBLE_LINEA << "╣" << RESET << endl;
    
    int indice = 1;
    Nodo *actual = tope;
    
    while (actual != NULL)
    {
        cout << CYAN << "   ║ " << RESET;
        cout << MAGENTA << "[" << indice << "]" << RESET;
        cout << AMARILLO << " Valor: " << NEGRITA << actual->dato;
        cout << ATENUADO << " @ " << actual;
        cout << RESET << endl;
        actual = actual->siguiente;
        indice++;
    }
    
    cout << CYAN << "   ╠" << DOBLE_LINEA << "╣" << RESET << endl;
    cout << CYAN << "   ║ " << RESET;
    cout << AZUL << "Total de elementos: " << NEGRITA << cantidadElementos;
    cout << RESET << endl;
    cout << CYAN << "   ╚" << DOBLE_LINEA << "╝" << RESET << endl;
}

// MODIFICAR DATO
void modificar(int valorViejo, int valorNuevo)
{
    if (tope == NULL)
    {
        cout << "\n" << AMARILLO << "   ⚠ LA PILA ESTÁ VACÍA" << RESET << endl;
        return;
    }
    
    int buscar, nuevoValor;
    cout << "\n" << AZUL << "   ► Ingrese el valor a modificar: " << RESET;
    buscar = validarNumero();
    cout << AZUL << "   ► Ingrese el nuevo valor: " << RESET;
    nuevoValor = validarNumero();
    
    Nodo *actual = tope;
    bool encontrado = false;
    
    while (actual != NULL)
    {
        if (actual->dato == buscar)
        {
            cout << VERDE << "\n   ✓ DATO ENCONTRADO Y MODIFICADO" << RESET << endl;
            cout << AMARILLO << "   Valor anterior: " << NEGRITA << buscar << RESET << endl;
            actual->dato = nuevoValor;
            cout << VERDE << "   Valor nuevo: " << NEGRITA << nuevoValor << RESET << endl;
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }
    
    if (!encontrado)
    {
        cout << ROJO << "\n   ✗ VALOR NO ENCONTRADO EN LA PILA" << RESET << endl;
    }
}

// ELIMINAR DATO (POP)
void eliminarDato()
{
    if (tope == NULL)
    {
        cout << "\n" << ROJO << "   ✗ LA PILA ESTÁ VACÍA. NO HAY NADA QUE ELIMINAR" << RESET << endl;
        return;
    }

    Nodo *auxiliar = tope;
    cout << "\n" << AMARILLO << "   ⏳ ELIMINANDO NODO..." << RESET << endl;
    cout << AMARILLO << "   Valor eliminado: " << NEGRITA << auxiliar->dato;
    cout << ATENUADO << " @ " << auxiliar << RESET << endl;
    
    // mover al tope
    tope = tope->siguiente;
    // Liberamos la memoria del nodo eliminado
    delete auxiliar;
    cantidadElementos--;
    cout << VERDE << "   ✓ NODO ELIMINADO EXITOSAMENTE" << RESET << endl;
}

// vaciar toda la pila
void vaciarPila()
{
    if (tope == NULL)
    {
        cout << "\n" << ROJO << "   ✗ LA PILA YA ESTÁ VACÍA" << RESET << endl;
        return;
    }
    
    cout << "\n" << AMARILLO << "   ⏳ VACIANDO PILA..." << RESET << endl;
    Nodo *auxiliar;
    int contador = 0;
    
    while (tope != NULL)
    {
        auxiliar = tope;
        cout << AMARILLO << "   Eliminado [" << contador + 1 << "]: "
             << NEGRITA << auxiliar->dato
             << ATENUADO << " @ " << auxiliar << RESET << endl;

        tope = tope->siguiente;
        delete auxiliar;
        cantidadElementos--;
        contador++;
    }
    
    cout << VERDE << "\n   ✓ PILA VACIADA EXITOSAMENTE" << RESET << endl;
}

// Menu principal MEJORADO
void menu()
{
    cout << "\n";
    cout << CYAN << "   ╔" << DOBLE_LINEA << "╗" << RESET << endl;
    cout << CYAN << "   ║" << RESET;
    imprimirCentrado("⚙️  MENÚ PRINCIPAL - SISTEMA DE PILAS", 57);
    cout << CYAN << "║" << RESET << endl;
    cout << CYAN << "   ╠" << DOBLE_LINEA << "╣" << RESET << endl;
    
    cout << CYAN << "   ║" << RESET << endl;
    cout << CYAN << "   ║ " << RESET << MAGENTA << " [1] " << RESET << BLANCO << "➤ Insertar datos (PUSH)" << RESET << endl;
    cout << CYAN << "   ║ " << RESET << MAGENTA << " [2] " << RESET << BLANCO << "➤ Modificar dato" << RESET << endl;
    cout << CYAN << "   ║ " << RESET << MAGENTA << " [3] " << RESET << BLANCO << "➤ Eliminar dato (POP)" << RESET << endl;
    cout << CYAN << "   ║ " << RESET << MAGENTA << " [4] " << RESET << BLANCO << "➤ Mostrar pila" << RESET << endl;
    cout << CYAN << "   ║ " << RESET << MAGENTA << " [5] " << RESET << BLANCO << "➤ Vaciar pila" << RESET << endl;
    cout << CYAN << "   ║ " << RESET << MAGENTA << " [6] " << RESET << BLANCO << "➤ Salir del programa" << RESET << endl;
    
    cout << CYAN << "   ║" << RESET << endl;
    cout << CYAN << "   ╠" << DOBLE_LINEA << "╣" << RESET << endl;
    cout << CYAN << "   ║ " << RESET << AZUL << "Seleccione una opción: " << RESET;
}

// ============================================================================
// FUNCIÓN PRINCIPAL (SIN CAMBIOS EN LA LÓGICA)
// ============================================================================

int main()
{
    int opcion, valor;

    // MEJORADO: Encabezado retro elegante
    mostrarEncabezado();
    animacionCarga();

    // verificacion principal
    if (tope == NULL)
    {
        cout << AMARILLO << "   ⚠ PILA INICIALIZADA VACÍA" << RESET << endl;
    }
    
    do
    {
        menu();
        opcion = validarNumero();
        
        switch (opcion)
        {
        case 1:
            cout << RESET << endl;
            cout << AMARILLO << "\n   ► Ingrese 5 datos para la pila:" << RESET << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << AZUL << "   Dato [" << i + 1 << "]: " << RESET;
                valor = validarNumero();
                insertar(valor);
            }
            mostrarPila();
            break;

        // Modificar dato
        case 2:
            modificar(valor, valor);
            mostrarPila();
            break;

        // Eliminar dato
        case 3:
            eliminarDato();
            mostrarPila();
            break;

        // Mostrar pila
        case 4:
            mostrarPila();
            break;
            
        // Vaciar pila
        case 5:
            vaciarPila();
            mostrarPila();
            break;
            
        // Salir del programa
        case 6:
            cout << RESET << endl;
            cout << VERDE << "\n   ╔" << DOBLE_LINEA << "╗" << RESET << endl;
            cout << VERDE << "   ║" << RESET;
            imprimirCentrado("👋 ¡HASTA LUEGO, RETROGAMER!", 57);
            cout << VERDE << "║" << RESET << endl;
            cout << VERDE << "   ╚" << DOBLE_LINEA << "╝" << RESET << endl;
            cout << endl;
            break;
            
        default:
            cout << ROJO << "\n   ✗ OPCIÓN INVÁLIDA. SELECCIONE UNA OPCIÓN DEL MENÚ" << RESET << endl;
        }
    } while (opcion != 6);
    
    return 0;
}

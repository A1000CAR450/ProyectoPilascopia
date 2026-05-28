#include <iostream>
#include <cstdlib>

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

// colores para la consola
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AMARILLO "\033[33m"
#define AZUL "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// Validar entra da de datos
int validarNumero()
{
    int numero;
    while (!(cin >> numero))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << ROJO << "Entrada inválida. Por favor, ingrese un número entero: " << RESET;
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
    cout << VERDE << "Elemento " << valor << " insertado en la pila." << RESET << endl;
    cout << AZUL << "Direccion de memoria del node:" << nuevoNodo << RESET << endl;
}

// MOSTRAR PILA
void mostrarPila()
{
    if (tope == NULL)
    {
        cout << AMARILLO
             << "La pila está vacía." << RESET << endl;
        return;
    }
    Nodo *actual = tope;
    cout << CYAN
         << "============== PILA =============" << RESET << endl;
    while (actual != NULL)
    {
        cout << MAGENTA << "Valor: " << actual->dato << " | Direccion de memoria: " << actual << RESET << endl;
        actual = actual->siguiente;
    }
    cout << CYAN
         << "================================" << RESET << endl;
    cout << AZUL << "Cantidad de elementos en la pila: " << cantidadElementos << RESET << endl;
}

// MODFICAR DATO
void modificar(int valorViejo, int valorNuevo)
{
    if (tope == NULL)
    {
        cout << AMARILLO
             << "La pila está vacía." << RESET << endl;
        return;
    }
    int buscar, nuevoValor;
    cout << "Ingrese el valor a modificar: ";
    buscar = validarNumero();
    cout << "Ingrese el nuevo valor: ";
    nuevoValor = validarNumero();
    Nodo *actual = tope;
    bool encontrado = false;
    while (actual != NULL)
    {
        if (actual->dato == buscar)
        {
            cout << VERDE
                 << "dato encontrado y modoficado"
                 << RESET << endl;
            cout << "Valor anterior: "
                 << buscar
                 << endl;
            actual->dato = nuevoValor;
            cout << "Valor nuevo: "
                 << nuevoValor
                 << endl;
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }
    if (!encontrado)
    {
        cout << ROJO
             << "Valor no encontrado en la pila." << RESET << endl;
    }
}

// ELIMINAR DATO (POP)
void eliminarDato()
{
    if (tope == NULL)
    {
        cout << ROJO << "La pila está vacía. No se puede eliminar ningún elemento." << RESET << endl;
        return;
    }

    Nodo *auxiliar = tope; // Guardamos el nodo a eliminar
    cout << AMARILLO
         << "Eliminando nodo..." << RESET << endl;
    cout << "Valor del nodo a eliminar: " << auxiliar->dato << endl;
    cout << "Direccion liberada: " << auxiliar << RESET << endl;
    // mover al tope
    tope = tope->siguiente;
    // Liberamos la memoria del nodo eliminado
    delete auxiliar;
    cantidadElementos--;
    cout << VERDE << "Nodo eliminado exitosamente." << RESET << endl;
}
// vaciar toda la pila
void vaciarPila()
{
    if (tope == NULL)
    {
        cout << ROJO << "La pila ya está vacía." << RESET << endl;
        return;
    }
    Nodo *auxiliar;
    while (tope != NULL)
    {
        auxiliar = tope;
        cout << "Eliminando dato: "
             << auxiliar->dato
             << " | Direccion liberada: "
             << auxiliar
             << endl;

        tope = tope->siguiente; // Mover al siguiente nodo
        delete auxiliar;        // Liberar memoria del nodo actual
        cantidadElementos--;
    }
    cout << VERDE << "Pila vaciada exitosamente." << RESET << endl;
}
// Menu principal
void menu()
{
    cout << AZUL
         << "=================Menu Pila=================" << RESET << endl;
    cout << "1. Insertar dato (PUSH)" << endl;
    cout << "2. Modificar dato" << endl;
    cout << "3. Eliminar dato (POP)" << endl;
    cout << "4. Mostrar pila" << endl;
    cout << "5. Vaciar pila" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion.: ";
}

// Funcion Principal

int main()
{
    int opcion, valor;
    // verificacion principal

    if (tope == NULL)
    {
        cout << AMARILLO
             << "La pila está vacía." << RESET << endl;
    }
    do
    {
        menu();
        opcion = validarNumero();
        switch (opcion)
        {
        case 1:
            cout << AMARILLO
                 << "Ingrese 5 datos: " << RESET << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << "Dato "
                     << i + 1
                     << ": ";
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
            cout << VERDE
                 << "Saliendo del programa..." << RESET << endl;
            break;
        default:
            cout << ROJO
                 << "Opcion invalida. Por favor, seleccione una opcion del menu." << RESET << endl;
        }
    } while (opcion != 6);
    return 0;
}
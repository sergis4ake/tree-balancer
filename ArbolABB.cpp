#include "ArbolABB.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

// Poda: borrar todos los nodos a partir de uno, incluido
void ArbolABB::Podar(Nodo* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el árbol ABB
void ArbolABB::Insertar(const int dat, const int cont, bool drcha)
{
    Nodo *padre = NULL;
    // Si no existe raiz, el arbol esta vacio, y creamos la raiz con peso 0.
    if (Vacio(raiz)) raiz = new Nodo(0);
    actual = raiz;
    padre = actual;

    // Dos primeras inserciones en el arbol que no siguen las reglas de un arbol binario
    // por lo tanto las introducimos a la fuerza, por el hecho de que la raiz es 0.
    if (cont==1) actual->izquierdo = new Nodo(dat);
    else if (cont==2) padre->derecho = new Nodo(dat);
    else
    {
        // Balanceo segun peso total de las ramas
        // Insertamos en la rama derecha o izquierda según nos convenga
        // Se podría interpretar como 2 raíces de dos árboles, derecho e izq
        if ((drcha==true) && (!Vacio(actual)) && (!Vacio(actual->derecho)))
        {
            padre = actual;
            actual = actual->derecho;
        }
        else if((drcha==false) && (!Vacio(actual)) && (!Vacio(actual->izquierdo)))
        {
            padre = actual;
            actual = actual->izquierdo;
        }

        // Buscamos el nodo correcto para insertarle un nodo hijo.
        while(!Vacio(actual)) {
            padre = actual;
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat <= actual->dato) actual = actual->izquierdo;
        }
        // Si el int es menor que el que contiene el nodo padre, lo insertamos
        // en la rama izquierda
        if(dat <= padre->dato) padre->izquierdo = new Nodo(dat);
        // Si el int es mayor que el que contiene el nodo padre, lo insertamos
        // en la rama derecha
        else if(dat > padre->dato) padre->derecho = new Nodo(dat);
    }


}

// Eliminar un elemento de un árbol ABB
void ArbolABB::Borrar(const int dat, char rama)
{
    Nodo *padre = NULL;
    Nodo *nodo;
    int aux;

    // Tomar como raiz el hijo izquierdo o derecho de la raíz principal. Ya que la raiz principal tiene peso 0.
    if (rama == 'd') actual = raiz->derecho;
    else if(rama == 'i') actual = raiz->izquierdo;

    // Mientras sea posible que el valor esté en el árbol
    while(!Vacio(actual)) {
        if(dat == actual->dato) { // Si el valor está en el nodo actual
            if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
                //if(padre) // Si tiene padre (no es el nodo raiz)
                // Anulamos el puntero que le hace referencia
                if(padre->derecho == actual) padre->derecho = NULL;
                else if(padre->izquierdo == actual) padre->izquierdo = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                return;
            }
            else { // Si el valor está en el nodo actual, pero no es hoja
                // Buscar nodo
                padre = actual;
                // Buscar nodo más izquierdo de rama derecha
                if(actual->derecho) {
                    nodo = actual->derecho;
                    while(nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                // O buscar nodo más derecho de rama izquierda
                else {
                    nodo = actual->izquierdo;
                    while(nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                // Intercambiar valores de no a borrar u nodo encontrado
                // y continuar, cerrando el bucle. El nodo encontrado no tiene
                // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
                // de que sólo se eliminan nodos hoja.
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
            }
        }
        else { // Todavía no hemos encontrado el valor, seguir buscándolo
            padre = actual;
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }
    }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
    if(r) nodo = raiz;
    if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->dato);
    if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r)
{
    if(r) nodo = raiz;
    func(nodo->dato);
    if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r)
{
    if(r) nodo = raiz;
    if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if(nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->dato);
}

// Buscar un valor en el árbol
bool ArbolABB::Buscar(const int dat, char rama)
{
    // Tomar como raiz el hijo izquierdo o derecho de la raíz principal.
    if (rama == 'd') actual = raiz->derecho;
    else if(rama == 'i') actual = raiz->izquierdo;


// Todavía puede aparecer, ya que quedan nodos por mirar
    while(!Vacio(actual)) {
        if(dat == actual->dato) return true; // int encontrado
        else if(dat > actual->dato) actual = actual->derecho; // Seguir
        else if(dat < actual->dato) actual = actual->izquierdo;
    }
    return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const int dat)
{
    int altura = 0;
    actual = raiz;

    // Todavía puede aparecer, ya que quedan nodos por mirar
    while(!Vacio(actual)) {
        if(dat == actual->dato) return altura; // int encontrado
        else {
            altura++; // Incrementamos la altura, seguimos buscando
            if(dat > actual->dato) actual = actual->derecho;
            else if(dat < actual->dato) actual = actual->izquierdo;
        }
    }
    return -1; // No está en árbol
}

// Contar el número de nodos
const int ArbolABB::NumeroNodos(bool rama_dcha)
{
    contador = 0;
    if (rama_dcha) auxContador(raiz->derecho);
    else if (!rama_dcha) auxContador(raiz->izquierdo);
    return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(Nodo *nodo)
{
    contador++;  // Otro nodo
    // Continuar recorrido
    if(nodo->izquierdo) auxContador(nodo->izquierdo);
    if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
    altura = 0;

    auxAltura(raiz, 0); // Función auxiliar
    return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ArbolABB::auxAltura(Nodo *nodo, int a)
{
    // Recorrido postorden
    if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
    if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
    // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
    // árbol, actualizamos la altura actual del árbol
    if(EsHoja(nodo) && a > altura) altura = a;
}
int ArbolABB::Suma_nodos(Nodo *raiz)
{
    int total = 0;
    // cout<< raiz->dato<<endl;
    if(raiz==NULL)
        return 0;
    //raiz->dato +
    total = total + raiz->dato;
    if(raiz->derecho!=NULL)
    {
        total = total + Suma_nodos(raiz->derecho);
    }
    if(raiz->izquierdo != NULL)
    {
        total = total + Suma_nodos(raiz->izquierdo);
    }
    return total;

}



#include <stddef.h>

class ArbolABB {
  private:
   //// Clase local de Lista para Nodo de ArbolBinario:
   class Nodo {
     public:
      // Constructor:
      Nodo(const int dat, Nodo *izq=NULL, Nodo *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
      // Miembros:
      int dato;
      Nodo *izquierdo;
      Nodo *derecho;
   };

   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *actual;
   int contador;
   int altura;

  public:
   Nodo *raiz;

   // Constructor y destructor básicos:
   ArbolABB() : actual(NULL), raiz(NULL) {}
   ~ArbolABB() { Podar(raiz); }
   // Insertar en árbol ordenado:
   void Insertar(const int dat, const int cont, bool drcha);
   // Borrar un elemento del árbol:
   void Borrar(const int dat, char rama);
   // Función de búsqueda:
   bool Buscar(const int dat, char rama);
   // Comprobar si el árbol está vacío:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   // Contar número de nodos:
   const int NumeroNodos(bool rama_dcha);
   const int AlturaArbol();
   // Calcular altura de un int:
   int Altura(const int dat);
   // Devolver referencia al int del nodo actual:
   int &ValorActual() { return actual->dato; }
   //Suma del arbol
   //int Suma_nodos(Nodo);
   int Suma_nodos(Nodo *raiz);
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
  private:
   // Funciones auxiliares
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, int);

};

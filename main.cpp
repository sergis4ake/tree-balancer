#include <iostream>
#include <stdlib.h>
#include "ArbolABB.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Mostrar el contenido de un arbol.
void Mostrar(int &d)
{
   cout << d << ",";
}

// Funcion pausa del menu de opciones.
void pausa()
{
    cout << "Pulsa una tecla para volver..." <<endl;
    getwchar();
    getwchar();
}
/***************************************/
/************ 1. AUTOMATICO ************/
/***************************************/
int equilibrar_auto()
{
    ArbolABB ArbolInt; // Un árbol de enteros
    int cont = 0;
    int izq = 0, der = 0;
    int resultado = 0;
    float resultado2 = 0;
    int total = 0;
    int array_num[7] = {1, 2, 3, 5, 7, 10};
    int n_rnd = 0;
    bool drcha;
    srand(time(NULL));

    // Bucle para rellenar las ramas del arbol y equilibrarlas automaticamente.
    do
    {
        cont++;

        // Inserción del peso aleatorio.
        n_rnd = rand()%6;
        ArbolInt.Insertar(array_num[n_rnd], cont, drcha);

        // Suma de las ramas izq y dcha.
        izq = ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo);
        der = ArbolInt.Suma_nodos(ArbolInt.raiz->derecho);

        // Condicion para pasar por argumento al método insertar,
        // para insertar el siguiente peso en la rama que menor peso tenga.
        if (izq <= der) drcha = false;
        else if (der < izq) drcha = true;

        // Control del 2% del peso que pide el enunciado.
        total= ArbolInt.Suma_nodos(ArbolInt.raiz);
        resultado = (izq - der);
        if(resultado < 0) resultado = resultado*-1;
        resultado2 = (0.02 * total);


        // Mostrar los detalles de la insercion de pesos en el arbol.
        cout << "------------"<< cont <<"-------------" << endl;
        cout << "Peso: " << array_num[n_rnd] << endl;
        cout << "Peso rama izq: " << izq << endl;
        cout << "Peso rama dcha: " << der << endl;
        cout << "Peso total: " << total << endl;
        cout << "Diferencia de pesos: " << resultado << endl;
        cout << "2% del peso total: " << resultado2 << endl;
        cout << "---------------------------\n" << endl;

    }while(resultado2<resultado);

    cout << "---------ARBOL---------" << endl;
   // Mostrar el árbol en tres ordenes distintos:
    cout << "InOrden: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    cout << "PreOrden: ";
    ArbolInt.PreOrden(Mostrar);
    cout << endl;
    cout << "PostOrden: ";
    ArbolInt.PostOrden(Mostrar);
    cout << "\n" << endl;

    cout << "Hojas rama izq: " << ArbolInt.NumeroNodos(false) << endl;
    cout << "Hojas rama dcha: " << ArbolInt.NumeroNodos(true) << endl;
    cout << "Altura de arbol: " << ArbolInt.AlturaArbol() << endl;
    cout << "Peso rama izq: " << ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo)<< endl;
    cout << "Peso rama dcha: " << ArbolInt.Suma_nodos(ArbolInt.raiz->derecho)<< endl;
    cout << "Peso total: " << ArbolInt.Suma_nodos(ArbolInt.raiz)<< endl;
    cout << "Diferencia de pesos: " << resultado << endl;
    cout << "2% del peso total: " << resultado2 << endl;

    cout << "----------------------" << endl;
    return 0;
}
/***************************************/
/************** 2. MANUAL **************/
/***************************************/
int equilibrar_manual()
{
    // Un árbol de enteros
    ArbolABB ArbolInt;
    int cont = 0, cont2 = 0;
    int izq = 0;
    int der = 0;
    int resultado = 0;
    float resultado2 = 0;
    int total = 0;
    int array_num[7] = {1, 2, 3, 5, 7, 10};
    int n_rnd = 0;
    bool drcha = NULL;
    int tecla_peso = 0;
    char tecla_rama;
    srand(time(NULL));

    // CREAR UN ARBOL INCOMPLETO, PARA DESPUES PODER EQUILIBRAR MANUALMENTE.
    cout << "CREANDO ARBOL INCOMPLETO...\n" << endl;
    do
    {
        cont++;
        n_rnd = rand()%6;
        cout << "Cargando peso: " << array_num[n_rnd] << endl;
        ArbolInt.Insertar(array_num[n_rnd], cont, drcha);

        izq = ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo);
        der = ArbolInt.Suma_nodos(ArbolInt.raiz->derecho);

        if (izq <= der) drcha = false;
        else if (der < izq) drcha = true;

        total = ArbolInt.Suma_nodos(ArbolInt.raiz);
        resultado = (izq - der);
        if(resultado < 0) resultado = resultado*-1;
        resultado2 = (0.02 * total);

    }while((resultado2>=resultado) || (cont<5));

    // MOSTRAR EL NUEVO ARBOL INCOMPLETO
    cout << endl;
    cout << "Peso rama izq: " << izq << endl;
    cout << "Peso rama dcha: " << der << endl;
    cout << "Peso total: " << total << endl;
    cout << "Diferencia de pesos: " << resultado << endl;
    cout << "2% del peso total: " << resultado2 << endl;
    cout << "---------------------------\n" << endl;

    // EQUILIBRAR EL ARBOL INCOMPLETO MANUALMENTE.
    cout << "Ahora se desea equilibrar el arbol manualmente." << endl;
    do
    {
        cin.clear();
        cont++;
        cont2++; // Para mostrar las veces que se añade peso al equilibrar el arbol.

        // Insercion del peso manual.
        cout << "Que peso desea introducir?" << endl;
        cin >> tecla_peso;
        //do{
            cout << "Rama izquierda(i) o derecha(d)?" << endl;
            cin >> tecla_rama;
        //}while((tecla_rama != 'd') || (tecla_rama != 'i'));
        if (tecla_rama == 'd') drcha = true;
        else if (tecla_rama == 'i') drcha = false;
        ArbolInt.Insertar(tecla_peso, cont, drcha);

        // Suma de las ramas izq y dcha.
        izq = ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo);
        der = ArbolInt.Suma_nodos(ArbolInt.raiz->derecho);

        // Control del 2% del peso que pide el enunciado.
        total = ArbolInt.Suma_nodos(ArbolInt.raiz);
        resultado = (izq - der);
        if(resultado < 0) resultado = resultado*-1;
        resultado2 = (0.02 * total);

        // Mostrar el INTENTO.
        cout << endl;
        cout << "----------Intento " << cont2 << "----------" << endl;
        cout << "Peso: " << tecla_peso << endl;
        cout << "Peso rama izq: " << izq << endl;
        cout << "Peso rama dcha: " << der << endl;
        cout << "Peso total: " << total << endl;
        cout << "Diferencia de pesos: " << resultado << endl;
        cout << "2% del peso total: " << resultado2 << endl;
        cout << "---------------------------\n" << endl;

    }while(resultado2<resultado);

    cout << "ENHORABUENA! Has conseguido equilibrar el arbol!" << endl;
    cout << "---------ARBOL---------" << endl;

   // Mostrar el árbol conseguido en tres ordenes distintos:
    cout << "InOrden: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    cout << "PreOrden: ";
    ArbolInt.PreOrden(Mostrar);
    cout << endl;
    cout << "PostOrden: ";
    ArbolInt.PostOrden(Mostrar);
    cout << "\n" << endl;

    cout << "----------------------" << endl;
    return 0;
}

/***************************************/
/************* 3. BORRAR ***************/
/***************************************/
// La primera parte de esta opcion es igual que la 1, ya que
// creamos un arbol que se equilibra automaticamente.

int equilibrar_borrar()
{
    ArbolABB ArbolInt; // Un árbol de enteros
    int cont = 0, cont2 = 0;
    int izq = 0, der = 0;
    int resultado = 0;
    float resultado2 = 0;
    int total = 0;
    int array_num[7] = {1, 2, 3, 5, 7, 10};
    int n_rnd = 0;
    bool drcha;
    srand(time(NULL));

    // Bucle para rellenar las ramas del arbol y equilibrarlas automaticamente.
    do
    {
        cont++;
        //cont2++;

        // Inserción del peso aleatorio.
        n_rnd = rand()%6;
        ArbolInt.Insertar(array_num[n_rnd], cont, drcha);

        // Suma de las ramas izq y dcha.
        izq = ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo);
        der = ArbolInt.Suma_nodos(ArbolInt.raiz->derecho);

        // Condicion para pasar por argumento al método insertar,
        // para insertar el siguiente peso en la rama que menor peso tenga.
        if (izq <= der) drcha = false;
        else if (der < izq) drcha = true;

        // Control del 2% del peso que pide el enunciado.
        total= ArbolInt.Suma_nodos(ArbolInt.raiz);
        resultado = (izq - der);
        if(resultado < 0) resultado = resultado*-1;
        resultado2 = (0.02 * total);


        // Mostrar los detalles de la insercion de pesos en el arbol.
      /*  cout << "------------"<< cont2 <<"-------------" << endl;
        if (cont==1) cout << "Peso: " << array_num[menor] << endl;
        else if (cont==2) cout << "Peso: " << array_num[mayor] << endl;
        else cout << "Peso: " << array_num[n_rnd] << endl;
        cout << "Peso rama izq: " << izq << endl;
        cout << "Peso rama dcha: " << der << endl;
        cout << "Peso total: " << total << endl;
        cout << "Diferencia de pesos: " << resultado << endl;
        cout << "2% del peso total: " << resultado2 << endl;
        cout << "---------------------------\n" << endl;*/

    }while((cont<5) || (resultado2<resultado));

    cout << "---------ARBOL---------" << endl;
   // Mostrar el árbol en tres ordenes distintos:
    cout << "InOrden: ";
    ArbolInt.InOrden(Mostrar);
    cout << endl;
    cout << "PreOrden: ";
    ArbolInt.PreOrden(Mostrar);
    cout << endl;
    cout << "PostOrden: ";
    ArbolInt.PostOrden(Mostrar);
    cout << "\n" << endl;

    cout << "Hojas rama izq: " << ArbolInt.NumeroNodos(false) << endl;
    cout << "Hojas rama dcha: " << ArbolInt.NumeroNodos(true) << endl;
    cout << "Altura de arbol: " << ArbolInt.AlturaArbol() << endl;
    cout << "Peso rama izq: " << ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo)<< endl;
    cout << "Peso rama dcha: " << ArbolInt.Suma_nodos(ArbolInt.raiz->derecho)<< endl;
    cout << "Peso total: " << ArbolInt.Suma_nodos(ArbolInt.raiz)<< endl;
    cout << "Diferencia de pesos: " << resultado << endl;
    cout << "2% del peso total: " << resultado2 << endl;

    cout << "----------------------" << endl;

/************************************************************/
/*************** Eliminar pesos del arbol *******************/
/************************************************************/
    char respuesta, rama;
    int peso;
    bool encuentra, semaforo = false;

    do{
        cin.clear();
        cout << "Quieres eliminar algun peso del arbol? S/N" << endl;
        cin >> respuesta;
        if (respuesta == 'N' || respuesta == 'n') return 0;
        if(!(respuesta=='S' || respuesta=='s')) cout << "Tecla incorrecta. ";
    }while (!(respuesta=='S' || respuesta=='s'));


    while(respuesta=='S' || respuesta=='s')
    {
        semaforo = true; // Comprobar si nos tenemos que meter en el bucle while que equilibra el arbol.
        do
        {
            cin.clear();
            cout << "Que peso quieres eliminar?" << endl;
            cin >> peso;
            cin.clear();
            cout << "De que rama? izquierda(i)/derecha(d)" << endl;
            cin >> rama;
            encuentra = ArbolInt.Buscar(peso, rama);
            if (!(encuentra)) cout << "No existe! ";
        }while (!(encuentra));

        ArbolInt.Borrar(peso, rama);
        cout << "Peso rama izq: " << ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo)<< endl;
        cout << "Peso rama dcha: " << ArbolInt.Suma_nodos(ArbolInt.raiz->derecho)<< endl;
        cout << "Peso total: " << ArbolInt.Suma_nodos(ArbolInt.raiz)<< endl;
        cout << "Diferencia de pesos: " << resultado << endl;
        cout << "2% del peso total: " << resultado2 << endl;

        cout << "\nInOrden: " << endl;
        ArbolInt.InOrden(Mostrar);

        do
        {
            cin.clear();
            cout << "\nQuieres eliminar otro peso del arbol? S/N" << endl;
            cin >> respuesta;
            if(!(respuesta=='S' || respuesta=='s' || respuesta=='N' || respuesta=='n')) cout << "Tecla incorrecta. ";
        }while (!(respuesta=='S' || respuesta=='s' || respuesta=='N' || respuesta=='n'));
    }
    if (semaforo)
    {
        cont2 = 0;
        do
        {
            cont++;
            cont2++;

            n_rnd = rand()%6;
            cout << "Cargando peso: " << array_num[n_rnd] << endl;
            if (cont<3) ArbolInt.Insertar(array_num[n_rnd], cont, drcha);
            else ArbolInt.Insertar(array_num[n_rnd], cont, drcha);

            izq = ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo);
            der = ArbolInt.Suma_nodos(ArbolInt.raiz->derecho);

            if (izq <= der) drcha = false;
            else if (der < izq) drcha = true;

            total = ArbolInt.Suma_nodos(ArbolInt.raiz);
            resultado = (izq - der);
            if(resultado < 0) resultado = resultado*-1;
            resultado2 = (0.02 * total);


            // Mostrar los detalles de la insercion de pesos en el arbol.
            cout << "------------"<< cont2 <<"-------------" << endl;
            cout << "Peso: " << array_num[n_rnd] << endl;
            cout << "Peso rama izq: " << izq << endl;
            cout << "Peso rama dcha: " << der << endl;
            cout << "Peso total: " << total << endl;
            cout << "Diferencia de pesos: " << resultado << endl;
            cout << "2% del peso total: " << resultado2 << endl;
            cout << "---------------------------\n" << endl;

        }while(resultado2<resultado);

        cout << "---------ARBOL---------" << endl;
        // Mostrar el árbol en tres ordenes distintos:
        cout << "InOrden: ";
        ArbolInt.InOrden(Mostrar);
        cout << endl;
        cout << "PreOrden: ";
        ArbolInt.PreOrden(Mostrar);
        cout << endl;
        cout << "PostOrden: ";
        ArbolInt.PostOrden(Mostrar);
        cout << "\n" << endl;

        cout << "Hojas rama izq: " << ArbolInt.NumeroNodos(false) << endl;
        cout << "Hojas rama dcha: " << ArbolInt.NumeroNodos(true) << endl;
        cout << "Altura de arbol: " << ArbolInt.AlturaArbol() << endl;
        cout << "Peso rama izq: " << ArbolInt.Suma_nodos(ArbolInt.raiz->izquierdo)<< endl;
        cout << "Peso rama dcha: " << ArbolInt.Suma_nodos(ArbolInt.raiz->derecho)<< endl;
        cout << "Peso total: " << ArbolInt.Suma_nodos(ArbolInt.raiz)<< endl;
        cout << "Diferencia de pesos: " << resultado << endl;
        cout << "2% del peso total: " << resultado2 << endl;

        cout << "----------------------" << endl;

    }
    return 0;
}

/************* MENU DEL PROGRAMA ***************/
int main()
{
    bool semaforo=false;
    char a;

    do
    {
        // Borra lo que haya anteriormente en pantalla y la captura por teclado.
        system("cls");
        cin.clear();

        cout << "\t* * * * * * Practica3 * * * * * *" << endl;
        cout << "\t*                               *" << endl;
        cout << "\t*    1. Automatico              *" << endl;
        cout << "\t*    2. Manual                  *" << endl;
        cout << "\t*    3. Borrar                  *" << endl;
        cout << "\t*    4. Salir                   *" << endl;
        cout << "\t*                               *" << endl;
        cout << "\t* * * * * * * * * * * * * * * * *" << endl;

        // Captura por teclado.
        cout << "Elije una opcion: " <<endl;
        cin >> a;

        // 4 casos distintos para el menu.
		switch(a)
		{
			case '1':
				system("cls");
				cout << "Has elejido: Automatico.\n" << endl;
				equilibrar_auto();
				pausa();
				break;

			case '2':
				system("cls");
				cout << "Has elejido: Manual.\n" << endl;
				equilibrar_manual();
				pausa();
				break;

			case '3':
				system("cls");
				cout << "Has elejido: Borrar." << endl;
                equilibrar_borrar();
				pausa();
				break;

			case '4':
				semaforo=true;
				cout << "\nHasta pronto!" << endl;
				break;

			default:
				system("cls");
				cout << "\aOpcion no valida, selecciona otra opcion." << endl;
				pausa();
				break;
		}
    }while(semaforo!=true);

    return 0;
}




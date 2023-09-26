#include <iostream>
#include <string>
#include "UListaP.h"
#include "UListaS.h"
#include "CSMemoria.h"
using namespace std;
 
void menuS();
int main(){
   //	ListaP* list;
  /*	list=new ListaP();
	list->inserta_primero(1);
	for (int i = 2; i < 6; i++) {
		list->inserta_ultimo(i);
	}
	cout<<list->to_str()<<endl;      */

	 //list->eliminarPenultimoNodo();
	// list->suprime(list->anterior(list->fin()));
	// cout<<list->to_str()<<endl;


	//list->inserta(list->siguiente(list->primero()),23);
	//list->insertarSiguienteDirPrimero(23);
	  // cout<<list->to_str()<<endl;
	//ListaS* l1;
   menuS();
 /*	 ListaS* list;
	CSMemoria* mem;
		mem = new CSMemoria();
		list = new ListaS(mem);
			list->inserta_primero(1);
	for (int i = 2; i < 6; i++) {
		list->inserta_ultimo(i);
	}
	cout<<list->to_str()<<endl;
	//list->suprime(list->anterior(list->fin()));
	   //	list->inserta(list->siguiente(list->primero()),23);
		list->suprime(list->siguiente(list->primero()));
			cout<<list->to_str()<<endl;    */

system("pause");
return 0;
}

void menuS(){
   ListaS* list;
	CSMemoria* mem;
	int opcion;
	do {
		cout << "1.Crear Memoria\n";
		cout << "2.Pedir espacio\n";
		cout << "3.Crear Lista\n";
		cout << "4.Mostrar memoria\n";
		cout << "5.Mostrar lista\n";
		cout << "6.INSERTAR DIR PRIMERO \n L.INSERTAR(L->PRIMERO,DATO)\n";
		cout << "7.INSERTAR DIR FIN\n";
		cout << "8.INSERTAR SIGUIENTE PRIMERO\n L.INSERTAR(L,SIGUIENTE,DATO)\n";
		cout << "9.ELIMINAR ANTERIOR FIN\n";
		cout << "10.SUPRIMIR SIGUIENTE PRIMERO\n";
		cout << "11.Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
				mem = new CSMemoria();
				cout<<"Memoria Creada"<<endl;
			} break;
		case 2: {
				string ids;
				cin.ignore();
				cout << "IDS a guardar: ";
				getline(cin, ids);
				mem->new_espacio(ids);
			} break;
		case 3: {

				list = new ListaS(mem);
				cout<<"Lista Creada"<<endl;
			} break;
		case 4: {
				cout<<"La Memoria\n"<<endl;
				mem->mostrar_memoria();
			} break;
		case 5: {

				cout<<"La Lista\n"<<endl;

				cout << list->to_str() << endl;
			} break;
		case 6: {

				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_primero(e);
				cout << list->to_str() << endl;

			} break;
		case 7: {
				int e;
				cout << "Dato: ";
				cin >> e;
				list->inserta_ultimo(e);
				cout << list->to_str() << endl;

			} break;
		case 8: {
				int e;
				cout << "Dato: ";
				cin >> e;
				//insertar(direccion,elemento);
				list->inserta(list->siguiente(list->primero()),e);
				cout << list->to_str() << endl;
			} break;
		case 9: {
				list->suprime(list->anterior(list->fin()));
			} break;

		case 10: {
				list->suprime(list->siguiente(list->primero()));
			} break;
		}
		system("pause");
		system("cls");
	}
	while (opcion != 11);

}



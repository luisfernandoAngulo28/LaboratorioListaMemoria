﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ListaS::ListaS(){
  PtrElementos=NULO;
  longit=0;
   mem=new CSMemoria();
}
ListaS::ListaS(CSMemoria* m){
  PtrElementos=NULO;
  longit=0;
   mem=m;
  // mem->mostrar_memoria();
}

int ListaS::fin(){
 if(vacia()){
	cout<<"ERROR/FIN():Lista Vacia";
 }else{

 int x = PtrElementos;
 int ptrfin;
	while(x!=NULO){
		ptrfin= x;
	   //	x = x->sig; // con simulador m.obtener_dato(x,’->sig’)
		x=mem->obtener_dato(x,sigNL);
	}
	return ptrfin;

 }


}
int ListaS::primero(){
  if(!vacia()){
	return PtrElementos;
  }else{
	cout<<"ERROR/Primero():Lista Vacia";
  }
}





int ListaS::siguiente(int d){
	if(vacia()){
		cout<<"ERROR/Siguiente():Lista Vacia";
	}else{
		if(d==fin()){
		   cout<<"ERROR/ Dirrecion Erronea";
		}
		return mem->obtener_dato(d,sigNL);//d->sig;
	}

}












int ListaS::anterior( int d){
  if(vacia()){
	 cout<<"ERROR/Anterior:Lista Vacia";
  }else{
	int x= PtrElementos;
	int ant=NULO;
	while(x!=NULO){
		 if(x==d){
		  return ant;
		 }
		 ant=x;
		 x=mem->obtener_dato(x,sigNL);//x=x->sig;
	}
	 return NULO;
  }
}














bool ListaS::vacia(){
return longit==0;
}

int ListaS::recupera(int d){
  if(vacia()){
	 cout<<"ERROR/recuperar:Lista Vacia";
  }else{
  //int elemento=mem->obtener_dato(aux,elemNL);
	  return mem->obtener_dato(d,elemNL);//d->elemento;
  }
}
int ListaS::longitud(){
	return longit;
}





void ListaS::inserta(int d, int elem){
 int x=mem->new_espacio(datoNL);
 //mem->mostrar_memoria();
  if(x!=NULO){
	mem->poner_dato(x,elemNL,elem);//x->elemento=elem;

	mem->poner_dato(x,sigNL,NULO);
	//x->sig=NULO;
	if(vacia()){ //caso1 lista vacia
		PtrElementos=x;
		longit=1;
	}else{
	   if( d==primero()){ //caso 2 inserta de primero
		  //x->sig=d;
		  mem->poner_dato(x,sigNL,d);
		  PtrElementos=x;
	   }else{    //caso 3 a la izq de la direccion
		 int ant=anterior(d);
		 mem->poner_dato(ant,sigNL,x); //ant->sig=x;
		 mem->poner_dato(x,sigNL,d);	//x->sig=d;
	   }

    }
  }

}



void ListaS::inserta_primero(int elem){
  int x=mem->new_espacio(datoNL);				// NodoL* x=new NodoL;
  if(x!=NULO){
   mem->poner_dato(x,elemNL,elem);//x->elemento=elem;
   mem->poner_dato(x,sigNL,PtrElementos);//x->sig=PtrElementos;
   PtrElementos=x;
   longit++;

  }

}

void ListaS::inserta_ultimo(int elem){
  int x=mem->new_espacio(datoNL);
	if (x != NULO) {
		 mem->poner_dato(x,elemNL,elem);//x->elemento = elem;
		mem->poner_dato(x,sigNL,NULO);//x->sig = NULO;
		if (vacia())
			PtrElementos = x;
		else
			mem->poner_dato(fin(),sigNL,x);//fin()->sig = x;
		longit++;

  } else{
	  cout<<"ERROR:No existe espacio en la memoria\n";
  }

}




void ListaS::suprime( int d){
   if(longit==0){
	cout<<"ERROR:LISTA VACIA";
	return;
   }else{
	  if(d==PtrElementos){ //si es el primer elemento
		int x=PtrElementos;
		PtrElementos=mem->obtener_dato(PtrElementos,sigNL);//PtrElementos=PtrElementos->sig;
	   mem->delete_espacio(x); //	delete(d);
	  }else{
		  int ant=anterior(d);
		 mem->poner_dato(ant,sigNL,mem->obtener_dato(d,sigNL));//ant->sig=siguiente(d);
		 mem->delete_espacio(d);//delete(d);
	  }
   }
   longit--;

}
void ListaS::modifica( int d, int elem){
if(vacia){
   cout<<"ERROR LISTA VACIA\n";
 }else{
	 mem->poner_dato(d,elemNL,elem); //d->elemento=elem;
 }
}


string ListaS::to_str(){
string s="<";
int aux=PtrElementos;
	while(aux!=NULO){
		int elemento=mem->obtener_dato(aux,elemNL);//int elemento=aux->elemento;
		s=s+to_string(elemento);
		aux=mem->obtener_dato(aux,sigNL);//aux=aux->sig;
		if(aux!=NULO){
		s=s+",";
	}

}
return s+">";

}

//---------------------------------------------------------------------------

#pragma hdrstop

#include "pila_ptr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 pila_ptr::pila_ptr(){
   tope=NULL;
 }
 bool pila_ptr::vacio(){
   return tope==NULL;
 }
 void pila_ptr::meter(int e){
   nodo_pila* aux=new nodo_pila();
   if (aux !=NULL) {
	   aux->elemento=e;
	   aux->sig=tope;
	   tope=aux;
   }
 }
 void pila_ptr::sacar(int &e){
   if (!vacio()){
	   e=tope->elemento;
	   nodo_pila* sup=new nodo_pila();
	   tope=tope->sig;
	   delete(sup);
   }
 }
 int pila_ptr::cima(){
   if (!vacio()) {
	  return tope->elemento;
   }
 }
 int pila_ptr::sacar(){
   if (!vacio()){
	   int e=tope->elemento;
	   nodo_pila* sup=new nodo_pila();  //crea un nodo
	   tope=tope->sig;
	   delete(sup); //eliminamos el nodo
	   return e;
   }
 }
 void pila_ptr::mostrar(){
  pila_ptr* aux = new pila_ptr;   //crea una pila
   while(!vacio()){    //mete a una pila
	  int e;
	  sacar(e);
	  aux->meter(e);
	  cout<< e <<endl;  //muestra los valores consola
   }
   while(!aux->vacio()){     //devuelve a pila original
	  int e;
	  aux->sacar(e);
	  meter(e);
   }
}
string pila_ptr::to_str(){
	string r = "";
	pila_ptr* aux = new pila_ptr();
	while(!vacio()){
		int e;
		sacar(e);
		r+= "| "+to_string(e)+" |\n";
		aux->meter(e);
	}
	while(!aux->vacio()){
		int e;
		aux->sacar(e);
		meter(e);
	}
	r += "+---+\n";
	return r;
}


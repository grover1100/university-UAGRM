//---------------------------------------------------------------------------

#ifndef pila_ptrH
#define pila_ptrH
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
struct nodo_pila{
	 int elemento;
	 nodo_pila *sig;
};
class pila_ptr{
	private:
		nodo_pila* tope;
	public:
		pila_ptr();
		bool vacio();
		void meter(int);
		void sacar(int &);
		int cima();
		int sacar();
		void mostrar();
        string to_str();
};
#endif

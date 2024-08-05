//---------------------------------------------------------------------------

#ifndef CtexH
#define CtexH
#include <Vcl.h>
//---------------------------------------------------------------------------
class Ctex{
	private:
		int HanArc;//identificar el archivo
		int TamArc;//tamaño del archivo
		int BytArc;//cant de bytes de archivo
		PAnsiChar MemBuf; // pansichar :puntero a candena ascci y membuf accede ala memoria
		String Nombre;

	public:
		//Constructor

		Ctex();
		Ctex(String nom,int modo);
		Ctex(Ctex &copia);// copia del constructor

		//Getters

		String GetNom();
		bool GetValido();
		int GetTamano();
		int GetNroByte();
		PAnsiChar GetBuf();

		//Setters

		void SetNom(String nom);

		//Others

		bool AbrirLectura();
		void Escribe(String nom,UTF8String cad);

		//Destructor

		~Ctex();

};
#endif

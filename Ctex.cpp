//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "Ctex.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//Constructor

Ctex::Ctex(){
	Nombre="Default.txt"; //Crear la carpeta tmp si no existe
	if(FileExists(Nombre)){
		DeleteFile(Nombre);
	}
	HanArc = FileCreate(Nombre);
	if(HanArc>0) TamArc=0;
};

Ctex::Ctex(String nom,int modo){
	if (modo==0)
		HanArc=FileOpen(nom,fmOpenRead);//fmOpenRead
	else{
		if (modo==1)
			HanArc=FileOpen(nom,fmOpenWrite);//fmOpenWrite
		else
			HanArc=FileOpen(nom,fmOpenReadWrite);//fmOpenRead | fmOpenWrite
	}
	if (HanArc>0) {
			TamArc=FileSeek(HanArc,0,2);//Obtener el tamaño de archivo
			FileSeek(HanArc,0,0);//Vueleve al inicio del fichero
			MemBuf=new AnsiChar[TamArc+1]; //creando arreglo dinamico
			BytArc=FileRead(HanArc,MemBuf,TamArc); // cant bytes del archivo
			FileClose(HanArc);//cerrar el archivo
	}
};

//Getters

bool Ctex::GetValido(){   //que hay archivo creado
	return HanArc>0;
};

int Ctex::GetTamano(){    //me devuelve tamaño del archivo
	return TamArc;
};

int Ctex::GetNroByte(){    //cant de bytes de archivo
	return BytArc;
};

PAnsiChar Ctex::GetBuf(){  //me devuele el puntero tipo string y acceso ala memoria
	return MemBuf;
};

String Ctex::GetNom(){
	return Nombre;
};

/*
Ctex::Ctex(Ctex &copia){
	Nombre=copia.Nombre;
};
*/

//Setters

void Ctex::Escribe(String nom,UTF8String cad){
	Nombre=nom;
	HanArc=FileOpen(Nombre,fmOpenWrite);//fmOpenWrite
	if (HanArc>0) {
		TamArc=FileSeek(HanArc,0,2);//Se posiciona al final
		if (cad.Length()>0) FileWrite(HanArc,"\n",2);
		ShowMessage(cad.c_str());
		ShowMessage(cad.Length());
		if (cad.Length()>0) FileWrite(HanArc,cad.c_str(),cad.Length()+1);
		FileClose(HanArc);
	}
};

/*void Ctex::SetNom(String nom){
	Nombre=nom;
};
*/

//Destructor

Ctex::~Ctex(){
	delete[]MemBuf;
};

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::Pintado(int posX, int posY, String cad, TColor color){


	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Form1->Canvas->Brush->Color = color;
	Form1->Canvas->FillRect(rect);

	Form1->Canvas->TextOutW(100,posY+20,"Direccion del Archivo");
	//Form1->Canvas->TextOutW(posX+3,posY+3,cad);


}
void TForm1::CarArcLin(AnsiChar *MemBuf,int BytArc,String cad,int pos,int lin)
{
   //	if(pos==BytArc){
	  if (BytArc==pos) {
	  }
	else
	{
	   //	int val=StrToInt((int)MemBuf[pos]);
		int val = static_cast<int>(MemBuf[pos]);
		//13 es Enter y 10 es salto de linea
		if(val!=13 && val!=10)
			cad=cad+MemBuf[pos];
		else{
			pos++;
			cad="";
		}
		CarArcLin(MemBuf,BytArc,cad,pos+1,lin);
	}
}
void TForm1::leer_archivo(AnsiChar* MemBuf, int BytArc){
	//este codigo lee la primera fila del archivo
	if (BytArc == 0) {
	}
	else{
		String numero;
		p = new pila_ptr();
		int num;
		for (int i = 0; i < BytArc; i++) {
			if (MemBuf[i+1]==32 || MemBuf[i+1]==13 ) {
				   num = StrToInt(numero);
					   if (numero[0]=='-') {
						   num*=-1;
					   }
					   p->meter(num);
					   numero="";
			}
			numero+=MemBuf[i];
		}
	}
	/* //invertir pila
	p1 = new pila_ptr();
	int e;
	while(!p->vacio()){
		p->sacar(e);
		p1->meter(e);
	}
	ShowMessage(p1->to_str().c_str());  */
	ShowMessage(p->to_str().c_str());
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
try{
		if (OpenDialog1->Execute()) {
			Edit1->Text=OpenDialog1->FileName;
			Ctex a(Edit1->Text,0);
			if(a.GetValido()){
				String cad="";
				CarArcLin(a.GetBuf(),a.GetNroByte(),cad,0,0);
				UTF8String cad1=InputBox("AddFile","IntroTexto:","");
				a.Escribe(Edit1->Text,cad1);
			}
		}
	} 	catch(...){
		Application->MessageBoxW(L"Revisar Errores",L"ERROR !!",IDOK);
		ShowMessage("Error");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	  UTF8String nombre=InputBox("Crear Archivo","Nombre Archivo:","");
	  nombre+=".txt";
	  int HanArc = FileCreate(nombre);
	  if (HanArc > 0) {
		ShowMessage("Archivo creado exitosamente.");
		FileClose(HanArc);
	  } else {
        ShowMessage("Error al crear el archivo.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  if (OpenDialog1->Execute())
	{
        // Obtener el nombre del archivo seleccionado
		String fileName = OpenDialog1->FileName;
		// Convertir el nombre del archivo a un formato compatible con la función remove
		AnsiString ansiFileName = fileName;
        // Eliminar el archivo
        if (remove(ansiFileName.c_str()) != 0)
        {
			ShowMessage("No se pudo eliminar archivo!");
		}
		else
		{
			ShowMessage("Se borro Archivo exitosamente!");
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  exit(1);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	a = new Ctex("pila y archivo.txt",0);
	if (a->GetValido()){
			leer_archivo(a->GetBuf(), a->GetNroByte());
	}

}
//---------------------------------------------------------------------------



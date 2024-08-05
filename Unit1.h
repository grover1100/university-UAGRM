//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include "Ctex.h"
#include "pila_ptr.h"
//---------------------------------------------------------------------------
using namespace std;

const int TamanoCelda = 35;
const int TamanoCeldaX = 80;
const int TamanoCeldaY = 35;
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TOpenDialog *OpenDialog1;
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
		  pila_ptr* p;
          pila_ptr* p1;
		  Ctex* a;
		  void CarArcLin(AnsiChar *MemBuf,int BytArc,String cad,int pos,int lin);
		  void Pintado(int posX, int posY, String cad, TColor color);
		  void leer_archivo(AnsiChar* MemBuf, int BytArc);
		  int posX;
		  int posY;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

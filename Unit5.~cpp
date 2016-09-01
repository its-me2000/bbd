//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
        portas=0;
        reiksme=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit1Change(TObject *Sender)
{
        if(Edit1->Text!=""){

                if(StrToIntDef("0x"+Edit1->Text,-1)>=0){
                        portas=StrToInt("0x"+Edit1->Text);
                }else{
                        Edit1->Text=IntToHex((int)portas,4);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit2Change(TObject *Sender)
{
        if(Edit2->Text!=""){
                if(StrToIntDef("0x"+Edit2->Text,-1)>=0){
                        reiksme=StrToInt("0x"+Edit2->Text);
                }else{
                        Edit2->Text=IntToHex((int)reiksme,4);
                }
        }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
        Form5->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
        Edit1->Text=IntToHex((int)portas,4);
        Edit2->Text=IntToHex((int)reiksme,4);
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit2KeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_RETURN)
                Button2->Click();        
}
//---------------------------------------------------------------------------


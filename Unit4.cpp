//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm4::RadioButton1Click(TObject *Sender)
{
        Edit3->Enabled=false;
        Edit3->Text=Edit2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton2Click(TObject *Sender)
{
        Edit3->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit1Change(TObject *Sender)
{
        if(Edit1->Text!=""){
                if(StrToIntDef("0x"+Edit1->Text,-1)>=0){
                        segmentas=StrToInt("0x"+Edit1->Text);
                }else{
                        Edit1->Text=IntToHex((int)segmentas,4);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit2Change(TObject *Sender)
{
        if(Edit2->Text!=""){
                if(StrToIntDef("0x"+Edit2->Text,-1)>=0){
                        pradzia=StrToInt("0x"+Edit2->Text);
                        if(RadioButton1->Checked==true){
                                Edit3->Text=Edit2->Text;
                        }
                }else{
                        Edit2->Text=IntToHex((int)pradzia,4);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit3Change(TObject *Sender)
{
        if(Edit3->Text!=""){
                 if(StrToIntDef("0x"+Edit3->Text,-1)>=0){
                        pabaiga=StrToInt("0x"+Edit3->Text);
                }else{
                        Edit3->Text=IntToHex((int)pabaiga,4);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit4Change(TObject *Sender)
{
        if(Edit4->Text!=""){
                if(StrToIntDef("0x"+Edit4->Text,-1)>=0){
                        reiksme=StrToInt("0x"+Edit4->Text);
                }else{
                        Edit4->Text=IntToHex((int)reiksme,2);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
        Form4->Close();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

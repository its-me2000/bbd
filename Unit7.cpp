//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm7::Button1Click(TObject *Sender)
{
        Form7->Close();        
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm7::LabeledEdit1Change(TObject *Sender)
{
        if(LabeledEdit1->Text!=""){
                if(StrToIntDef("0x"+LabeledEdit1->Text,-1)>=0){
                        ekrAdresas=StrToInt("0x"+LabeledEdit1->Text);
                }else{
                        LabeledEdit1->Text=IntToHex((int)ekrAdresas,5);
                }
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm7::LabeledEdit3Change(TObject *Sender)
{
if(LabeledEdit3->Text!=""){
                if(StrToIntDef("0x"+LabeledEdit3->Text,-1)>=0){
                        kbPortas=StrToInt("0x"+LabeledEdit3->Text);
                }else{
                        LabeledEdit3->Text=IntToHex((int)kbPortas,4);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::LabeledEdit2Change(TObject *Sender)
{
if(LabeledEdit2->Text!=""){
                if(StrToIntDef("0x"+LabeledEdit2->Text,-1)>=0){
                        kbPertraukimas=StrToInt("0x"+LabeledEdit2->Text);
                }else{
                        LabeledEdit2->Text=IntToHex((int)kbPertraukimas,2);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormShow(TObject *Sender)
{
        if(ekrGrafinis){
                RadioButton1->Checked=false;
                RadioButton2->Checked=true;
        }else{
                RadioButton2->Checked=false;
                RadioButton1->Checked=true;
        }
        LabeledEdit1->Text=IntToHex((int)ekrAdresas,5);
        LabeledEdit2->Text=IntToHex((int)kbPertraukimas,2);
        LabeledEdit3->Text=IntToHex((int)kbPortas,4);
}
//---------------------------------------------------------------------------
void __fastcall TForm7::TrackBar1Change(TObject *Sender)
{
        greitis=TrackBar1->Position;        
}
//---------------------------------------------------------------------------
void __fastcall TForm7::RadioButton1Click(TObject *Sender)
{
        if(ekrGrafinis){
                RadioButton2->Checked=false;
                RadioButton1->Checked=true;
                ekrGrafinis=false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::RadioButton2Click(TObject *Sender)
{
        if(!ekrGrafinis){
                RadioButton2->Checked=true;
                RadioButton1->Checked=false;
                ekrGrafinis=true;
        }
}
//---------------------------------------------------------------------------

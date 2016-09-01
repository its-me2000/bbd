//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
        adresas=0;
        LabeledEdit1->Text="00000";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::LabeledEdit1Change(TObject *Sender)
{
        if(LabeledEdit1->Text!=""){
                if(StrToIntDef("0x"+LabeledEdit1->Text,-1)>=0){
                        adresas=StrToInt("0x"+LabeledEdit1->Text);
                }else{
                        LabeledEdit1->Text=IntToHex((int)adresas,5);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button1Click(TObject *Sender)
{
        Form6->Close();        
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm6::FormShow(TObject *Sender)
{
        LabeledEdit1->Focused();
        LabeledEdit1->SelectAll();        
}
//---------------------------------------------------------------------------


void __fastcall TForm6::LabeledEdit1KeyPress(TObject *Sender, char &Key)
{
        if(Key==VK_RETURN)
                Button2->Click();

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm3::FormShow(TObject *Sender)
{
        Form3->Caption="Keisti "+registras+" registro reikðmæ";
        showReiksme();
}
//---------------------------------------------------------------------------
void TForm3::showReiksme(){
        //dec
        StaticText5->Caption=IntToStr((int)reiksme/10000);
        StaticText6->Caption=IntToStr(((int)reiksme%10000)/1000);
        StaticText7->Caption=IntToStr(((int)reiksme%1000)/100);
        StaticText24->Caption=IntToStr(((int)reiksme%100)/10);
        StaticText25->Caption=IntToStr((int)reiksme%10);
        //hex
        StaticText1->Caption=IntToHex((((int)reiksme&0x0000F000)>>12),1);
        StaticText2->Caption=IntToHex((((int)reiksme&0x00000F00)>>8),1);
        StaticText3->Caption=IntToHex((((int)reiksme&0x000000F0)>>4),1);
        StaticText4->Caption=IntToHex((((int)reiksme&0x0000000F)),1);
        //bin
        StaticText8->Caption=IntToStr((int)(reiksme&0x00008000)>>15);
        StaticText9->Caption=IntToStr((int)(reiksme&0x00004000)>>14);
        StaticText10->Caption=IntToStr((int)(reiksme&0x00002000)>>13);
        StaticText11->Caption=IntToStr((int)(reiksme&0x00001000)>>12);
        StaticText12->Caption=IntToStr((int)(reiksme&0x00000800)>>11);
        StaticText13->Caption=IntToStr((int)(reiksme&0x00000400)>>10);
        StaticText14->Caption=IntToStr((int)(reiksme&0x00000200)>>9);
        StaticText15->Caption=IntToStr((int)(reiksme&0x00000100)>>8);
        StaticText16->Caption=IntToStr((int)(reiksme&0x00000080)>>7);
        StaticText17->Caption=IntToStr((int)(reiksme&0x00000040)>>6);
        StaticText18->Caption=IntToStr((int)(reiksme&0x00000020)>>5);
        StaticText19->Caption=IntToStr((int)(reiksme&0x00000010)>>4);
        StaticText20->Caption=IntToStr((int)(reiksme&0x00000008)>>3);
        StaticText21->Caption=IntToStr((int)(reiksme&0x00000004)>>2);
        StaticText22->Caption=IntToStr((int)(reiksme&0x00000002)>>1);
        StaticText23->Caption=IntToStr((int)(reiksme&0x00000001));
}
void __fastcall TForm3::StaticText5Click(TObject *Sender)
{
        if((reiksme%100000)/10000!=6 && (reiksme+10000)<0x00010000)
                reiksme=(reiksme+10000)&0x0000FFFF;
        else
                reiksme=(reiksme-((reiksme%100000)/10000)*10000)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText6Click(TObject *Sender)
{
        if((reiksme%10000)/1000!=9 && (reiksme+1000)<0x00010000)
                reiksme=(reiksme+1000)&0x0000FFFF;
        else
                reiksme=(reiksme-((reiksme%10000)/1000)*1000)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::StaticText25Click(TObject *Sender)
{
        if((reiksme%10)!=9 && (reiksme+1)<0x00010000)
                reiksme=(reiksme+1)&0x0000FFFF;
        else
                reiksme=(reiksme-(reiksme%10))&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText7Click(TObject *Sender)
{
        if((reiksme%1000)/100!=9 && (reiksme+100)<0x00010000)
                reiksme=(reiksme+100)&0x0000FFFF;
        else
                reiksme=(reiksme-((reiksme%1000)/100)*100)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText24Click(TObject *Sender)
{
        if((reiksme%100)/10!=9 && (reiksme+10)<0x00010000)
                reiksme=(reiksme+10)&0x0000FFFF;
        else
                reiksme=(reiksme-((reiksme%100)/10)*10)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText1Click(TObject *Sender)
{
        if((reiksme&0x0000F000)!=0x0000F000)
                reiksme=(reiksme+0x00001000)&0x0000FFFF;
        else
                reiksme=(reiksme-0x0000F000)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText2Click(TObject *Sender)
{
        if((reiksme&0x00000F00)!=0x00000F00)
                reiksme=(reiksme+0x00000100)&0x0000FFFF;
        else
                reiksme=(reiksme-0x00000F00)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText3Click(TObject *Sender)
{
        if((reiksme&0x000000F0)!=0x000000F0)
                reiksme=(reiksme+0x00000010)&0x0000FFFF;
        else
                reiksme=(reiksme-0x000000F0)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText4Click(TObject *Sender)
{
        if((reiksme&0x0000000F)!=0x0000000F)
                reiksme=(reiksme+0x00000001)&0x0000FFFF;
        else
                reiksme=(reiksme-0x0000000F)&0x0000FFFF;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText8Click(TObject *Sender)
{
        reiksme=reiksme^0x00008000;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText9Click(TObject *Sender)
{
        reiksme=reiksme^0x00004000;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText10Click(TObject *Sender)
{
        reiksme=reiksme^0x00002000;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText11Click(TObject *Sender)
{
        reiksme=reiksme^0x00001000;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText12Click(TObject *Sender)
{
        reiksme=reiksme^0x00000800;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText13Click(TObject *Sender)
{
        reiksme=reiksme^0x00000400;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText14Click(TObject *Sender)
{
        reiksme=reiksme^0x00000200;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText15Click(TObject *Sender)
{
        reiksme=reiksme^0x00000100;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText16Click(TObject *Sender)
{
        reiksme=reiksme^0x00000080;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText17Click(TObject *Sender)
{
        reiksme=reiksme^0x00000040;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText18Click(TObject *Sender)
{
        reiksme=reiksme^0x00000020;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText19Click(TObject *Sender)
{
        reiksme=reiksme^0x00000010;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText20Click(TObject *Sender)
{
        reiksme=reiksme^0x00000008;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText21Click(TObject *Sender)
{
        reiksme=reiksme^0x00000004;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText22Click(TObject *Sender)
{
        reiksme=reiksme^0x00000002;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText23Click(TObject *Sender)
{
        reiksme=reiksme^0x00000001;
        showReiksme();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
        Form3->Close();        
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#pragma hdrstop

#include "Unit2.h"
//#include "komp.h"
#include "comp.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
bool issaugotas = true;
bool naujas = true;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Naujas1Click(TObject *Sender)
{
        if(!issaugotas){

                switch(MessageDlg("Ar issaugoti pakeitimus?",
                mtConfirmation	, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0)){
                case mrYes:
                      Issaugoti1Click(Sender);
                      RichEdit1->Clear();
                      naujas=true;
                break;
                case mrNo:
                      RichEdit1->Clear();
                      naujas=true;
                break;
                case mrCancel:
                      //ShowMessage("cancel");
                break;
                }
        }else{
                RichEdit1->Clear();
                issaugotas=false;
                naujas=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Issaugoti1Click(TObject *Sender)
{
        if(naujas){
                Issaugotikaip1Click(Sender);
        }else{
                char szFileName[MAXFILE+4];
                if (FileExists(failoVardas)){
                        fnsplit(failoVardas.c_str(), 0, 0, szFileName, 0);
                        strcat(szFileName, ".BAK");
                        RenameFile(failoVardas, szFileName);
                }
                RichEdit1->Lines->SaveToFile(failoVardas);
                issaugotas=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Issaugotikaip1Click(TObject *Sender)
{
        SaveDialog1->Filter = "Programos failai (*.asm)|*.asm|Visi failai (*.*)|*.*";
        SaveDialog1->DefaultExt="asm";
        if(SaveDialog1->Execute()){
                failoVardas=SaveDialog1->FileName;
                char szFileName[MAXFILE+4];
                if (FileExists(failoVardas)){
                        fnsplit(failoVardas.c_str(), 0, 0, szFileName, 0);
                        strcat(szFileName, ".BAK");
                        RenameFile(failoVardas, szFileName);
                }
                RichEdit1->Lines->SaveToFile(failoVardas);
                naujas=false;
                issaugotas=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(!issaugotas){

                switch(MessageDlg("Ar issaugoti pakeitimus?",
                mtConfirmation	, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0)){
                case mrYes:
                        Issaugoti1Click(Sender);
                        RichEdit1->Clear();
                        Action=caHide;
                break;
                case mrNo:
                        RichEdit1->Clear();
                        Action=caHide;
                break;
                case mrCancel:
                        Action=caNone;
                break;
                }
        }else{
                Action=caHide;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RichEdit1Change(TObject *Sender)
{
        if(issaugotas)
                issaugotas=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Atidaryti1Click(TObject *Sender)
{
        if(!issaugotas){

                switch(MessageDlg("Ar issaugoti pakeitimus?",
                mtConfirmation	, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0)){
                case mrYes:
                        Issaugoti1Click(Sender);
                        OpenDialog1->Filter = "Programos failai (*.asm)|*.asm|Visi failai (*.*)|*.*";
                        if(OpenDialog1->Execute()){
                                failoVardas=OpenDialog1->FileName;
                                RichEdit1->Lines->LoadFromFile(failoVardas);
                                naujas=false;
                                issaugotas=true;
                        }
                break;
                case mrNo:
                        OpenDialog1->Filter = "Programos failai (*.asm)|*.asm|Visi failai (*.*)|*.*";
                        if(OpenDialog1->Execute()){
                                failoVardas=OpenDialog1->FileName;
                                RichEdit1->Lines->LoadFromFile(failoVardas);
                                naujas=false;
                                issaugotas=true;
                        }
                break;
                case mrCancel:
                break;
                }
        }else{
                OpenDialog1->Filter = "Programos failai (*.asm)|*.asm|Visi failai (*.*)|*.*";
                if(OpenDialog1->Execute()){
                        failoVardas=OpenDialog1->FileName;
                        RichEdit1->Lines->LoadFromFile(failoVardas);
                        naujas=false;
                        issaugotas=true;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Kompiliuoti1Click(TObject *Sender)
{
        int pc=0;
        int code=0;
        int stack=0;
        int data=0;
        int datacount=0;
        int extra=0;
        AnsiString Data="";
        AnsiString ErrCode="";

        TList *Zymes=new TList;
        TList *Jumps=new TList;
        TStringList *MasKodas=new TStringList;
        int i;
        for (i=0;i<RichEdit1->Lines->Count;i++){
             AnsiString E="";
             AnsiString Temp="";
             E=RichEdit1->Lines->Strings[i];
             Temp=E;
             if(Temp.Trim()!=""){
                     if(E.Pos(";")!=0){
                             E=E.SubString(0,E.Pos(";")-1);
                     }
                     E=E+" ";
                     Temp=E;
                     if(Temp.Trim()!=""){
                             E=E.TrimLeft();
                             if(E.SubString(0,4)==".org"){
                                     E=E.SubString(5,E.Length()-4).TrimLeft();
                                     try{
                                             if(E.SubString(0,6).Pos("h")==6){
                                                     pc=StrToInt("0x"+E.SubString(0,5));
                                             }
                                     }
                                     catch(...){
                                     }
                             }
                             else if(E.SubString(0,5)==".code"){
                                     E=E.SubString(6,E.Length()-5).TrimLeft();
                                     try{
                                             if(E.SubString(0,5).Pos("h")==5){
                                                     code=StrToInt("0x"+E.SubString(0,4));
                                             }
                                     }
                                     catch(...){
                                     }
                             }
                             else if(E.SubString(0,5)==".data"){
                                     E=E.SubString(6,E.Length()-5).TrimLeft();
                                     try{
                                             if(E.SubString(0,5).Pos("h")==5){
                                                     data=StrToInt("0x"+E.SubString(0,4));
                                             }
                                     }
                                     catch(...){
                                     }
                             }
                             else if(E.SubString(0,6)==".stack"){
                                     E=E.SubString(7,E.Length()-6).TrimLeft();
                                     try{
                                             if(E.SubString(0,5).Pos("h")==5){
                                                     stack=StrToInt("0x"+E.SubString(0,4));
                                             }
                                     }
                                     catch(...){
                                     }
                             }
                             else if(E.SubString(0,6)==".extra"){
                                     E=E.SubString(7,E.Length()-6).TrimLeft();
                                     try{
                                             if(E.SubString(0,5).Pos("h")==5){
                                                     extra=StrToInt("0x"+E.SubString(0,4));
                                             }
                                     }
                                     catch(...){
                                     }
                             }
                             else if(E.SubString(0,2)=="db"){
                                     E=E.SubString(3,E.Length()-2).TrimLeft();

                                     try{
                                        if(E.SubString(0,6).Pos("h")==6){
                                                StrToInt("0x"+E.SubString(0,5));
                                                Data=Data+"$"+E.SubString(0,5);
                                                E=E.SubString(7,E.Length()-6).TrimLeft();
                                             while(E!=""){
                                                if(E.SubString(0,3).Pos("h")==3){
                                                      StrToInt("0x"+E.SubString(0,2));
                                                      Data=Data+" "+E.SubString(0,2);
                                                      datacount++;
                                                      E=E.SubString(4,E.Length()-3).TrimLeft();
                                                }
                                                else
                                                      break;
                                             }
                                             Data=Data+"$";
                                        }
                                     }
                                     catch(...){
                                     }
                             }
                             //
                             else{
                             E=E.TrimLeft();
                             if(E.Pos(":")!=0){
                                     TZyme *Zyme=new TZyme;
                                     E=E.TrimLeft();
                                     Zyme->zyme=E.SubString(0,E.Pos(":")-1);
                                     Zyme->adresas=pc;
                                     Zymes->Add(Zyme);
                                    // RichEdit3->Lines->Add(Zyme->zyme+":"+IntToStr(Zyme->adresas));
                                     E=E.SubString(E.Pos(":")+1,E.Length());
                                    // delete Zyme;
                             }
                             E=E.TrimLeft();
                             Temp=E;
                             if(Temp.Trim()!=""){
                                     //TKomanda *Komanda=new TKomanda;
                                     AnsiString OpCode;
                                     AnsiString op1;
                                     AnsiString op2;
                                     OpCode=E.SubString(0,E.Pos(" ")-1);
                                     E=E.SubString(E.Pos(" "),E.Length());
                                     Temp=E;
                                     if(Temp.Trim()!=""){
                                             if(E.Pos(",")!=0){
                                                     op1=E.SubString(0,E.Pos(",")-1).Trim();
                                                     E=E.TrimLeft();
                                                     op2=E.SubString(E.Pos(",")+1,E.Length()).Trim();
                                             }
                                             else{
                                                     op1=E.Trim();
                                                     op2="";
                                             }
                                     }
                                    // RichEdit2->Lines->Add(Komanda->OpCode+"-"+Komanda->op1+"-"+Komanda->op2);
                                     //-----

                                     AnsiString Kodas;
                                     //komp->Kompiliuoti(Komanda, Kodas);
                                     Kodas=Kompiliuoti(OpCode,op1,op2);
                                     AnsiString Temp="";
                                     if(Kodas==""){
                                        ErrCode="Klaida eiluteje "+IntToStr(i+1)+"!";
                                        break;
                                     }else{
                                        if(Kodas==(IntToHex(0xE9,2)+" -- --") || Kodas==(IntToHex(0xE8,2)+" -- --")){
                                                TZyme *Jump=new TZyme;
                                                Jump->zyme="l"+op1.Trim();
                                                Jump->adresas=pc;
                                                Jumps->Add(Jump);
                                        }else if(Kodas==(IntToHex(0xEB,2)+" --")){
                                                TZyme *Jump=new TZyme;
                                                Jump->zyme="s"+op1.Trim();
                                                Jump->adresas=pc;
                                                Jumps->Add(Jump);
                                        }
                                        for(int j=0x70;j<=0x7F;j++){
                                                if(Kodas==(IntToHex(j,2)+" --")){
                                                        TZyme *Jump=new TZyme;
                                                        Jump->zyme="s"+op1.Trim();
                                                        Jump->adresas=pc;
                                                        Jumps->Add(Jump);
                                                }
                                        }
                                        for(int j=0xE0;j<=0xE3;j++){
                                                if(Kodas==(IntToHex(j,2)+" --")){
                                                        TZyme *Jump=new TZyme;
                                                        Jump->zyme="s"+op1.Trim();
                                                        Jump->adresas=pc;
                                                        Jumps->Add(Jump);
                                                }
                                        }

                                        Temp="["+IntToHex(pc,5)+"-"+IntToHex(pc+(Kodas.Length()+1)/3-1,5)+"] ";
                                        Temp=Temp+Kodas+"; "+OpCode;
                                        if(op1!=""){
                                                Temp=Temp+" "+op1;
                                                if(op2!=""){
                                                        Temp=Temp+","+op2;
                                                }
                                        }
                                        pc=pc+(Kodas.Length()+1)/3;
                                     }

                                     //RichEdit4->Lines->Add(Temp);
                                     MasKodas->Add(Temp);
                                    // RichEdit4->Text=MasKodas->Text;
                                     //ShowMessage(IntToStr(Kodas.Length()));

                                        //-----
                             }
                           }
                        }
                }
        }
        if(i==RichEdit1->Lines->Count){
                MasKodas=Kompiliuoti2(MasKodas,Zymes,Jumps);
                if(datacount>0){
                        //MasKodas->Insert(0,"["+IntToHex(data*16,5)+"-"+IntToHex(data*16+datacount-1,5)+"]"+Data);
                        AnsiString E;
                        while(Data.SubString(0,1)=="$"){
                                E=Data.SubString(2,Data.SubString(2,Data.Length()-1).Pos("$"));
                                MasKodas->Insert(0,"["+E.SubString(0,5)+"-"+IntToHex( StrToInt("0x"+E.SubString(0,5))+((E.Length()-5)/3)-1,5)+"]"+E.SubString(6,E.Length()-6));
                                Data=Data.SubString( E.Length()+2,Data.Length()-E.Length() );
                }       }
                if(code>0 && !dt)
                        MasKodas->Insert(0,"[CODE -"+IntToHex(code,4)+" ]");
                if(data>0 && !dt)
                        MasKodas->Insert(0,"[DATA -"+IntToHex(data,4)+" ]");
                if(stack>0 && !dt)
                        MasKodas->Insert(0,"[STACK-"+IntToHex(stack,4)+" ]");
                if(extra>0 && !dt)
                        MasKodas->Insert(0,"[EXTRA-"+IntToHex(extra,4)+" ]");
                if(kFailoVardas!=""){
                        if(dt)
                                MasKodas->Insert(0,"[!8086SIMULATORDATAFILE!]");
                        else
                                MasKodas->Insert(0,"[!8086SIMULATORCOMPILEDFILE!]");
                        MasKodas->SaveToFile(kFailoVardas);
                }else{
                        if(dt){
                                SaveDialog1->Filter = "Duomenu failai (*.dt)|*.dt|Visi failai (*.*)|*.*";
                                SaveDialog1->DefaultExt="dt";
                                if(SaveDialog1->Execute()){
                                        kFailoVardas=SaveDialog1->FileName;
                                        MasKodas->Insert(0,"[!8086SIMULATORDATAFILE!]");
                                        MasKodas->SaveToFile(kFailoVardas);
                                }
                        }else{
                                SaveDialog1->Filter = "Sukompiliuoti failai (*.co)|*.co|Visi failai (*.*)|*.*";
                                SaveDialog1->DefaultExt="co";
                                if(SaveDialog1->Execute()){
                                        kFailoVardas=SaveDialog1->FileName;
                                        MasKodas->Insert(0,"[!8086SIMULATORCOMPILEDFILE!]");
                                        MasKodas->SaveToFile(kFailoVardas);
                                }
                        }
                }
                //RichEdit3->Text=MasKodas->Text;
                //if (SaveDialog1->Execute())
                //       MasKodas->SaveToFile(SaveDialog1->FileName);
        }
        else{
                ShowMessage("Klaidos programoje, negalima kompiliuoti\n"+ErrCode);
        }
}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm2::Spausdinti2Click(TObject *Sender)
{
        if(PrintDialog1->Execute()){
                RichEdit1->Print("");
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Ieskoti1Click(TObject *Sender)
{
        FindDialog1->Position = Point(RichEdit1->Left + RichEdit1->Width, RichEdit1->Top);
        FindDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FindDialog1Find(TObject *Sender)
{
  int FoundAt, StartPos, ToEnd;
  // begin the search after the current selection 
  // if there is one 
  // otherwise, begin at the start of the text 
  if (RichEdit1->SelLength)
    StartPos = RichEdit1->SelStart + RichEdit1->SelLength;
  else

    StartPos = 0;

  // ToEnd is the length from StartPos 
  // to the end of the text in the rich edit control

  ToEnd = RichEdit1->Text.Length() - StartPos;

  FoundAt = RichEdit1->FindText(FindDialog1->FindText, StartPos, ToEnd, TSearchTypes()<< stMatchCase);
  if (FoundAt != -1)
  {
    RichEdit1->SetFocus();
    RichEdit1->SelStart = FoundAt;
    RichEdit1->SelLength = FindDialog1->FindText.Length();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::FindDialog1Show(TObject *Sender)
{
        FindDialog1->Left=Form2->Left+100;
        FindDialog1->Top=Form2->Top+100;        
}
//---------------------------------------------------------------------------





void __fastcall TForm2::Uzdaryti1Click(TObject *Sender)
{
        Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Kompiliuotiiri1Click(TObject *Sender)
{
        dt=true;
        Kompiliuoti1Click(Sender);
        dt=false;
                
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Pagalba1Click(TObject *Sender)
{
ShellExecute(0, NULL, "8086help.chm", NULL, NULL, SW_SHOW);        
}
//---------------------------------------------------------------------------


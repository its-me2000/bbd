//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Unit1.h"
//#include "HTMLHelpViewer.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "HTMLHelpViewer"
#pragma resource "*.dfm"





const unsigned int AX=0x00000000;
const unsigned int CX=0x00000001;
const unsigned int DX=0x00000002;
const unsigned int BX=0x00000003;
const unsigned int SP=0x00000004;
const unsigned int BP=0x00000005;
const unsigned int SI=0x00000006;
const unsigned int DI=0x00000007;
const unsigned int ES=0x00000008;
const unsigned int CS=0x00000009;
const unsigned int SS=0x0000000A;
const unsigned int DS=0x0000000B;

const unsigned int AL=0x00000000;
const unsigned int CL=0x00000001;
const unsigned int DL=0x00000002;
const unsigned int BL=0x00000003;
const unsigned int AH=0x00000004;
const unsigned int CH=0x00000005;
const unsigned int DH=0x00000006;
const unsigned int BH=0x00000007;
const unsigned int CF=0x00000001;
const unsigned int PF=0x00000004;
const unsigned int AF=0x00000010;
const unsigned int ZF=0x00000040;
const unsigned int SF=0x00000080;
const unsigned int TF=0x00000100;
const unsigned int IF=0x00000200;
const unsigned int DF=0x00000400;
const unsigned int OF=0x00000800;

TForm1 *Form1;
TStaticText *kAdresas[14];
TStaticText *kBaitKodas[14];
TStaticText *kKomanda[14];
TStaticText *aAdresas[16];
TStaticText *aReiksme[16][16];
TStaticText *pAdresas[16];
TStaticText *pReiksmeIN[16];
TStaticText *pReiksmeOUT[16];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Application->HelpFile = ExtractFilePath(Application->ExeName) + "8086help.chm";
   kbPort=0x00000060;
   kbIrq=9;
   kodKodas=new TStringList;
   kodKodas->Capacity=0x0000FFFF;
   for(int i=0;i<0x00010000;i++){
        kodKodas->Add("");
   }
   for(int i=0;i<0x0000FFFF;i++){
        bP[i]=false;
   }
   for(int i=0;i<14;i++){
        kAdresas[i]=new TStaticText(this);
        kAdresas[i]->AutoSize=false;
        kAdresas[i]->BorderStyle=sbsSunken;
        kAdresas[i]->Alignment=taCenter;
        kAdresas[i]->Height=17;
        kAdresas[i]->Width=41;
        kAdresas[i]->Caption="";
        kAdresas[i]->Top=40+i*16;
        kAdresas[i]->Left=kAddr->Left;
        kAdresas[i]->Tag=i;
        //kAdresas[i]->OnMouseDown=kAdresasMouseDown;
        Kodas->InsertControl(kAdresas[i]);
        
   }
      for(int i=0;i<14;i++){
        kBaitKodas[i]=new TStaticText(this);
        kBaitKodas[i]->AutoSize=false;
        kBaitKodas[i]->BorderStyle=sbsSunken;
        kBaitKodas[i]->Alignment=taCenter;
        kBaitKodas[i]->Height=kByteCode->Height;
        kBaitKodas[i]->Width=kByteCode->Width;
        kBaitKodas[i]->Caption="";
        kBaitKodas[i]->Top=40+i*16;
        kBaitKodas[i]->Left=kByteCode->Left;
        Kodas->InsertControl(kBaitKodas[i]);
   }
   for(int i=0;i<14;i++){
        kKomanda[i]=new TStaticText(this);
        kKomanda[i]->AutoSize=false;
        kKomanda[i]->BorderStyle=sbsSunken;
        kKomanda[i]->Alignment=taCenter;
        kKomanda[i]->Height=kCommand->Height;
        kKomanda[i]->Width=kCommand->Width;
        kKomanda[i]->Caption="";
        kKomanda[i]->Top=40+i*16;
        kKomanda[i]->Left=kCommand->Left;
        Kodas->InsertControl(kKomanda[i]);
   }

   for(int i=0;i<14; i++){
        Br->Canvas->Pen->Color=clBlack;
        Br->Canvas->Brush->Color=clBlack;
        Br->Canvas->Ellipse(i,i,i+13,i+13);
   }
   Br->Canvas->Lock();
   for(int i=0;i<16;i++){
        aAdresas[i]=new TStaticText(this);
        aAdresas[i]->AutoSize=false;
        aAdresas[i]->BorderStyle=sbsSunken;
        aAdresas[i]->Alignment=taCenter;
        aAdresas[i]->Height=17;
        aAdresas[i]->Width=33;
        aAdresas[i]->Caption=IntToHex(i,4);
        aAdresas[i]->Top=40+i*16;
        aAdresas[i]->Left=8;
        Atmintis->InsertControl(aAdresas[i]);
   }
   for(int i=0;i<16;i++){
      for(int j=0;j<16;j++){
        aReiksme[i][j]=new TStaticText(this);
        aReiksme[i][j]->AutoSize=false;
        aReiksme[i][j]->BorderStyle=sbsSunken;
        aReiksme[i][j]->Alignment=taCenter;
        aReiksme[i][j]->Height=17;
        aReiksme[i][j]->Width=17;
        aReiksme[i][j]->Caption=IntToHex(i*16+j,2);
        aReiksme[i][j]->Top=40+i*16;
        aReiksme[i][j]->Left=48+j*16;
        Atmintis->InsertControl(aReiksme[i][j]);
        aReiksme[i][j]->OnClick=memChangeClick;
      }
   }
   for(int i=0;i<16;i++){
        pAdresas[i]=new TStaticText(this);
        pAdresas[i]->AutoSize=false;
        pAdresas[i]->BorderStyle=sbsSunken;
        pAdresas[i]->Alignment=taCenter;
        pAdresas[i]->Height=17;
        pAdresas[i]->Width=33;
        pAdresas[i]->Caption=IntToHex(i,4);
        pAdresas[i]->Top=40+i*16;
        pAdresas[i]->Left=8;
        Portai->InsertControl(pAdresas[i]);
   }
   for(int i=0;i<16;i++){
        pReiksmeIN[i]=new TStaticText(this);
        pReiksmeIN[i]->AutoSize=false;
        pReiksmeIN[i]->BorderStyle=sbsSunken;
        pReiksmeIN[i]->Alignment=taCenter;
        pReiksmeIN[i]->Height=17;
        pReiksmeIN[i]->Width=31;
        pReiksmeIN[i]->Caption=IntToHex(0,4);
        pReiksmeIN[i]->Top=40+i*16;
        pReiksmeIN[i]->Left=40;
        Portai->InsertControl(pReiksmeIN[i]);
        pReiksmeIN[i]->OnClick=PortChangeClick;

        pReiksmeOUT[i]=new TStaticText(this);
        pReiksmeOUT[i]->AutoSize=false;
        pReiksmeOUT[i]->BorderStyle=sbsSunken;
        pReiksmeOUT[i]->Alignment=taCenter;
        pReiksmeOUT[i]->Height=17;
        pReiksmeOUT[i]->Width=31;
        pReiksmeOUT[i]->Caption=IntToHex(0,4);
        pReiksmeOUT[i]->Top=40+i*16;
        pReiksmeOUT[i]->Left=70;
        Portai->InsertControl(pReiksmeOUT[i]);
        pReiksmeOUT[i]->OnClick=PortChangeClick;

   }
   StaticText4->Caption=IntToHex((int)kbPort,4);
   aScroll->Position=0;
   aScrollChange(this);
   irq=256;
   interrupt=false;
   vidAddress=0x00010000;
   vidMode=true;
   simReset();
}
//---------------------------------------------------------------------------
void TForm1::memIn8(unsigned int address,unsigned int data){
        if(address<0x100000){
                memory[address]=data;
        }
        if((address>=(((unsigned int)aScroll->Position&0x0FFFFF)*16)) && (address<=(((unsigned int)aScroll->Position&0x0FFFFF)*16)+256))
                memShow();
}

void TForm1::memIn16(unsigned int address, unsigned int data){
        if(address<0xFFFFF){
             memory[address]=data&0x000000FF;
             memory[address+1]=(data&0x0000FF00)>>8;
        }
        if((address-1>=(((unsigned int)aScroll->Position&0x0FFFFF)*16)) && (address<=(((unsigned int)aScroll->Position&0x0FFFFF)*16)+256))
                memShow();
}

unsigned int TForm1::memOut8(unsigned int address){
        if(address<0x100000)
               return memory[address];
        return 0;
}

unsigned int TForm1::memOut16(unsigned int address){
        if(address<0xFFFFF){
                return memory[address]+(memory[address+1]<<8);
        }
        return 0;
}

void TForm1::memReset(){
        for(int i=0;i<0x100000;i++){
                memory[i]=0x00000000;
                //memIn8(i,0x00000000);
        }
}

void TForm1::memShow(){
        int pos=aScroll->Position;
        for(int i=0;i<16;i++){
                aAdresas[i]->Caption=IntToHex(pos+i,4);
        }
        for(int i=0;i<16;i++){
                for(int j=0;j<16;j++){
                        aReiksme[i][j]->Caption=IntToHex((int)memOut8(((pos+i)<<4)+j),2);
                }
        }
}
void TForm1::memIn(unsigned int address,unsigned int w,unsigned int data){
        w?memIn16(address,data):memIn8(address,data);
        if(address>=(regSegOut(CS)<<4) && address<=((regSegOut(CS)<<4)+0x0000FFFF)){
                memchg=true;
        }
        if(address>=vidAddress && address<=(vidMode?(vidAddress+1000):(vidAddress+64000)))
                vidRefresh();
}
unsigned int TForm1::memOut(unsigned int address,unsigned int w){
        return w?memOut16(address):memOut8(address);
}
void TForm1::memFromFile(AnsiString failoVardas){
        TStringList *Failas;
        Failas = new TStringList;
        Failas->LoadFromFile(failoVardas);
        bool error=false;
        if(Failas->Strings[0]=="[!8086SIMULATORDATAFILE!]"){
                int start,end,count;
                for(int i=1;i<Failas->Count;i++){
                        if(StrToIntDef("0x"+Failas->Strings[i].SubString(2,5),-1)>=0 &&
                        StrToIntDef("0x"+Failas->Strings[i].SubString(8,5),-1)>=0){
                                start=StrToInt("0x"+Failas->Strings[i].SubString(2,5));
                                end=StrToInt("0x"+Failas->Strings[i].SubString(8,5));
                                count=end-start+1;
                                for(int j=0;j<count;j++){
                                        if(StrToIntDef("0x"+Failas->Strings[i].SubString(15+(j*3),2),-1)>=0)
                                                memory[start+j]=(unsigned char)StrToInt("0x"+Failas->Strings[i].SubString(15+(j*3),2));
                                        else
                                                error=true;
                                }
                        }
                }
        }else
                error=true;
        if(error)
                ShowMessage("blogas failo formatas");
        else{
                memShow();
                kodDecompile();
                kodShow();
                vidRefresh();
        }
}
//---------------------------------------------------------------------------
void TForm1::portInOUT(unsigned int port, unsigned int w, unsigned int data){
        portsOUT[port]=data;
        if(port>=pScroll->Position && port<=pScroll->Position+16)
                portShow();
}
void TForm1::portInIN(unsigned int port, unsigned int w, unsigned int data){
        portsIN[port]=data;
        portShow();
}


unsigned int TForm1::portOutIN(unsigned int port,unsigned int w){
        return w?portsIN[port]&0x0000FFFF:portsIN[port]&0x000000FF;
}
unsigned int TForm1::portOutOUT(unsigned int port,unsigned int w){
        return w?portsOUT[port]&0x0000FFFF:portsOUT[port]&0x000000FF;
}

void TForm1::portShow(){
        int pos=pScroll->Position;
        for(int i=0;i<16;i++){
                pAdresas[i]->Caption=IntToHex(pos+i,4);
        }
        for(int i=0;i<16;i++){
                pReiksmeIN[i]->Caption=IntToHex((int)portOutIN(pos+i,1),4);
                pReiksmeOUT[i]->Caption=IntToHex((int)portOutOUT(pos+i,1),4);
        }

}
//---------------------------------------------------------------------------
void TForm1::regIn(unsigned int reg, unsigned int w, unsigned int data){
        if(w==1){
                registras[reg]=data;
        }else{
                switch(reg){
                        case 0:
                                registras[0]=(registras[0]&0xFFFFFF00)+(data&0x000000FF);
                        break;
                        case 1:
                                registras[1]=(registras[1]&0xFFFFFF00)+(data&0x000000FF);
                        break;
                        case 2:
                                registras[2]=(registras[2]&0xFFFFFF00)+(data&0x000000FF);
                        break;
                        case 3:
                                registras[3]=(registras[3]&0xFFFFFF00)+((data&0x000000FF));
                        break;
                        case 4:
                                registras[0]=(registras[0]&0x000000FF)+((data&0x000000FF)<<8);
                        break;
                        case 5:
                                registras[1]=(registras[1]&0x000000FF)+((data&0x000000FF)<<8);
                        break;
                        case 6:
                                registras[2]=(registras[2]&0x000000FF)+((data&0x000000FF)<<8);
                        break;
                        case 7:
                                registras[3]=(registras[3]&0x000000FF)+((data&0x000000FF)<<8);
                        break;
                }
        }
        regShow();
}
void TForm1::regInF(unsigned int reg, unsigned int w, unsigned int data){
        if(w==1){
                registras[reg]=data;
        }else{
                switch(reg){
                        case 0:
                                registras[0]=(registras[0]&0xFFFFFF00)+(data&0x000000FF);
                        break;
                        case 1:
                                registras[1]=(registras[1]&0xFFFFFF00)+(data&0x000000FF);
                        break;
                        case 2:
                                registras[2]=(registras[2]&0xFFFFFF00)+(data&0x000000FF);
                        break;
                        case 3:
                                registras[3]=(registras[3]&0xFFFFFF00)+((data&0x000000FF));
                        break;
                        case 4:
                                registras[0]=(registras[0]&0x000000FF)+((data<<8)&0x0000FF00);
                        break;
                        case 5:
                                registras[1]=(registras[1]&0x000000FF)+((data<<8)&0x0000FF00);
                        break;
                        case 6:
                                registras[2]=(registras[2]&0x000000FF)+((data<<8)&0x0000FF00);
                        break;
                        case 7:
                                registras[3]=(registras[3]&0x000000FF)+((data<<8)&0x0000FF00);
                        break;
                }
        }
}
unsigned int TForm1::regOut(unsigned int reg,unsigned int w){
        if(w==1){
                return registras[reg];
        }else{
                switch(reg){
                case 0:
                        return registras[0]&0x000000FF;
                break;
                case 1:
                        return registras[1]&0x000000FF;
                break;
                case 2:
                        return registras[2]&0x000000FF;
                break;
                case 3:
                        return registras[3]&0x000000FF;
                break;
                case 4:
                        return (registras[0]&0x0000FF00)>>8;
                break;
                case 5:
                        return (registras[1]&0x0000FF00)>>8;
                break;
                case 6:
                        return (registras[2]&0x0000FF00)>>8;
                break;
                case 7:
                        return (registras[3]&0x0000FF00)>>8;
                break;
                }
        }
        return 0;
}
void TForm1::regSegIn(unsigned int reg, unsigned int data){
        registras[reg]=data;
        regShow();
}
unsigned int TForm1::regSegOut(unsigned int reg){
        return registras[reg];
}
void TForm1::regShow(){
        rAX->Caption=IntToHex(((int)regOut(AX,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(AX,1)&0x000000FF),2);
        rCX->Caption=IntToHex(((int)regOut(CX,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(CX,1)&0x000000FF),2);
        rDX->Caption=IntToHex(((int)regOut(DX,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(DX,1)&0x000000FF),2);
        rBX->Caption=IntToHex(((int)regOut(BX,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(BX,1)&0x000000FF),2);
        rSP->Caption=IntToHex(((int)regOut(SP,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(SP,1)&0x000000FF),2);
        rBP->Caption=IntToHex(((int)regOut(BP,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(BP,1)&0x000000FF),2);
        rSI->Caption=IntToHex(((int)regOut(SI,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(SI,1)&0x000000FF),2);
        rDI->Caption=IntToHex(((int)regOut(DI,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(DI,1)&0x000000FF),2);
        rES->Caption=IntToHex(((int)regOut(ES,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(ES,1)&0x000000FF),2);
        rCS->Caption=IntToHex(((int)regOut(CS,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(CS,1)&0x000000FF),2);
        rSS->Caption=IntToHex(((int)regOut(SS,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(SS,1)&0x000000FF),2);
        rDS->Caption=IntToHex(((int)regOut(DS,1)&0x0000FF00)>>8,2)+" "+IntToHex(((int)regOut(DS,1)&0x000000FF),2);
        rPC->Caption=IntToHex(((int)regPC&0x0000FF00)>>8,2)+" "+IntToHex((int)regPC&0x000000FF,2);
        rFL->Caption=IntToHex(((int)regFL&0x0000FF00)>>8,2)+" "+IntToHex((int)regFL&0x000000FF,2);
        if((regFL&0x00000001)==1)
                fCF->Checked=true;
        else
                fCF->Checked=false;
        if((regFL&0x00000004)==0x00000004)
                fPF->Checked=true;
        else
                fPF->Checked=false;
        if((regFL&0x00000010)==0x00000010)
                fAF->Checked=true;
        else
                fAF->Checked=false;
        if((regFL&0x00000040)==0x00000040)
                fZF->Checked=true;
        else
                fZF->Checked=false;
        if((regFL&0x00000080)==0x00000080)
                fSF->Checked=true;
        else
                fSF->Checked=false;
        if((regFL&0x00000100)==0x00000100)
                fTF->Checked=true;
        else
                fTF->Checked=false;
        if((regFL&0x00000200)==0x00000200)
                fIF->Checked=true;
        else
                fIF->Checked=false;
        if((regFL&0x00000400)==0x00000400)
                fDF->Checked=true;
        else
                fDF->Checked=false;
        if((regFL&0x00000800)==0x00000800)
                fOF->Checked=true;
        else
                fOF->Checked=false;

}

void TForm1::regFlSet(unsigned int flag){
        regFL=(regFL|flag);
}

void TForm1::regFlReset(unsigned int flag){
        regFL=(regFL&(~flag));
}

unsigned int TForm1::regFlRead(unsigned int flag){
        if((regFL&flag)==flag)
                return true;
        else
                return false;
}

//---------------------------------------------------------------------------

void TForm1::vidGrfDrawPixel(unsigned int x, unsigned int y, unsigned int color){
        int spalva;
        spalva=((color&0x0000FF)<<16)+((color&0x0000FF)<<8)+(color&0x0000FF);
        Display->Canvas->Pen->Color=spalva;
        //Display->Canvas->Brush->Color=spalva;
        Display->Canvas->MoveTo(x+1,y+1);
        Display->Canvas->LineTo(x,y);

}

void TForm1::vidTxtDrawSimbol(unsigned int x, unsigned int y, unsigned int simbol){
        AnsiString E=" ";
        E.c_str()[0]=(char)simbol;
        Display->Canvas->Font->Height=8;
        Display->Canvas->Font->Color=clWhite;
        Display->Canvas->Font->Name="Courier New";
        Display->Canvas->TextOutA(x*8+2,y*8+1,E);
}

void TForm1::vidGrfRefresh(unsigned int address){ //320*200*256
        for(int i=0;i<200;i++){
                for(int j=0;j<320;j++)
                        vidGrfDrawPixel(j,i,memory[address++]);
        }
}

void TForm1::vidTxtRefresh(unsigned int address){ //40*25
       for(int i=0;i<25;i++){
                for(int j=0;j<40;j++)
                        vidTxtDrawSimbol(j,i,memory[address++]);
       }
}

void TForm1::vidRefresh(){
        vidMode?vidTxtRefresh(vidAddress):vidGrfRefresh(vidAddress);
}
//---------------------------------------------------------------------------
void TForm1::simReset(){
        regFL=0x00000000;
        regPC=0x00000000;
        for(int i=0;i<12;i++)
                registras[i]=0x00000000;
        registras[4]=0x0000FFFF;
        memReset();
        irq=256;
        aScroll->Position=0;
        kScroll->Position=0;
        pScroll->Position=0;
        kodDecompile();
        kodShow();
        regShow();
        vidRefresh();
}

void TForm1::simReadCommand(unsigned int address){
        for(int i=0;i<6;i++){
                bytecode[i]=memOut8(address+i);
        }
}

void TForm1::simGetMnemonic(AnsiString nemonic, unsigned int mnemoni){
        //Mnemonic=nemonic;
        mnemonic=mnemoni;
//

AnsiString op="";
AnsiString opDisp="";
AnsiString opFromMem="";
AnsiString opToMem="";
AnsiString opToReg="";
AnsiString opFromReg="";
AnsiString opData="";
AnsiString opAddr="";
AnsiString opOffset="";
AnsiString opToSeg="";
AnsiString opFromSeg="";
AnsiString opToRM="";
AnsiString opFromRM="";
AnsiString opSegment="";
AnsiString reg8[]={"al","cl","dl","bl","ah","ch","dh","bh"};
AnsiString reg16[]={"ax","cx","dx","bx","sp","bp","si","di","es","cs","ss","ds"};
AnsiString modRm[]={"bx+si","bx+di","bp+si","bp+di","si","di","bp","bx"};
unsigned int disp=0;


if ((state&0x00000003)==0x00000002){
		if((disp8&0x0000000F)==0x0000000F){
				disp=((!disp8)+1)&0x000000FF;
				opDisp="-"+IntToHex((int)disp,4)+"h]";
		}else{
				disp=disp8;
				opDisp="+"+IntToHex((int)disp,4)+"h]";
		}
}else if((state&0x00000003)==0x00000003){
		disp=(disp16<<8)+disp8;
		opDisp=IntToHex((int)disp,4)+"h]";
}else{
		opDisp="]";
}

if(mod==0 && fromMem==6)
		opFromMem="[";
else
		opFromMem="["+modRm[fromMem];

if(mod==0 && toMem==6)
		opToMem="[";
else
		opToMem="["+modRm[toMem];

opToReg=w?reg16[toReg]:reg8[toReg];
opFromReg=w?reg16[fromReg]:reg8[fromReg];
opToSeg=reg16[toReg];
opFromSeg=reg16[fromReg];
opData=IntToHex((int)(((state&0x0000000C)==0x0000000C?(data16<<8):0)+data8),4)+"h";
//((state&0x0000000C)==0x0000000C?(data16<<8):0)
//opData=IntToHex((int)((data16<<8)+data8),4)+"h";
if(mod==0x00000003){
	opToRM=opToReg;
	opFromRM=opFromReg;
}else{
	opToRM=opToMem+opDisp;
	opFromRM=opFromMem+opDisp;
}
opOffset="["+IntToHex((int)(disp16<<8)+(int)disp8,4)+"h]";
opSegment="["+IntToHex((int)(data16<<8)+(int)data8,4)+"h]";
AnsiString si=((disp>>7)&0x00000001)?"-":"";
opAddr="["+si+IntToHex((int)disp,2)+"h]";
        switch(mnemonic){
                        //mov
                case 0:
                        switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                break;
                case 1:
					op=opFromRM+", "+opData;
                break;
                case 2:
					op=opToReg+", "+opData;
                break;
                case 3:
					op=opToReg+", "+opOffset;
                break;
                case 4:
					op=opOffset+", "+opFromReg;
                break;
                case 5:
					op=opToSeg+", "+opFromRM;
                break;
                case 6:
					op=opToRM+", "+opFromSeg;
                break;
                // push
                case 7:
					op=opFromRM;
                break;
                case 8:
                    op=reg16[fromReg];
                break;
                case 9:
                    op=opFromSeg;
                break;
                        //pop
                case 10:
					op=opFromRM;
                break;
                case 11:
					op=reg16[toReg];
                break;
                case 12:
                    op=opToSeg;
                break;
                case 13:  //xchg
                        /*opToReg=reg16[toReg];
                        opFromReg=reg16[fromReg];
                        if(mod==0x00000003){
                        	opToRM=opToReg;
	                        opFromRM=opFromReg;
                        }else{
	                        opToRM=opToMem+opDisp;
	                        opFromRM=opFromMem+opDisp;
                        } */
                        if(mod==0x00000003)
                                op=opToRM+", "+opFromReg;
                        else
                                op=opFromReg+", "+opToRM;
                break;
                case 14:
                    op=opToReg+", "+opFromReg;
                break;
                case 15:
                    op=IntToHex((int)disp,2)+"h";
                break;

                case 17:
                    op=IntToHex((int)disp,2)+"h";
                break;

                case 20:
                    op=opFromReg+", "+opToRM;
                break;
                case 21:
                       //lds
                    op=opFromReg+", "+opToRM;   
                break;
                case 22:
                        //lds
                    op=opFromReg+", "+opToRM; 
                break;

                case 27:
                        //  add
                        
						switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                        
                        //
                break;
                case 28:
                    op=opFromRM+", "+opData;
                break;
                case 29:
                    op=opFromReg+", "+opData;
                break;
                //case 30:

                //break;
                case 30:
                        //adc
                        switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                break;
                case 31:
                    op=opToRM+", "+opData;
                break;
                case 32:
                    op=opToReg+", "+opData; 
                break;
                case 33:      //inc
					op=opFromRM;
                break;
                case 34:
                    op=opToReg;
                break;

                case 37:       //sub
                        switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                        //
                break;
                case 38:
                    op=opFromRM+", "+opData;
                break;
                case 39:
                    op=opToReg+", "+opData; 
                break;
                case 40: //sbb
					switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                break;
                case 41:
					op=opFromRM+", "+opData;
                break;
                case 42:
                    op=opToReg+", "+opData; 
                break;
                case 43: //dec
                    op=opFromRM;
                break;
                case 44:
                    op=opToReg;
                break;
                case 45: //neg
                    op=opFromRM;
                break;
                case 46: //cmp
                    switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                        //
                break;
                case 47:
                    op=opToRM+", "+opData;
                break;
                case 48:
                    op=opToReg+", "+opData; 
                break;

                case 51:    //mul
                    op=opFromRM;
                break;
                case 52: //imul
                    op=opFromRM;
                break;
                case 53:  //aam
                    op="";
                break;
                case 54: //div
                    op=opFromRM;
                break;
                case 55: //idiv
                    op=opFromRM;
                break;

                case 59:  //not
                    op=opFromRM;
                break;
                case 60:  //sal
                    op=opFromRM+(dsv?",cl":",01h");
                break;
                case 61:        //shr
                    op=opFromRM+(dsv?",cl":",01h");
                break;
                case 62:  //sar
                    op=opFromRM+(dsv?",cl":",01h");
                break;
                case 63:   //rol
                    op=opFromRM+(dsv?",cl":",01h");
                break;
                case 64:  //ror
                    op=opFromRM+(dsv?",cl":",01h");
                break;
                case 65:    //rcl
                    op=opFromRM+(dsv?",cl":",01h");
                break;
                case 66:  //rcr
                    op=opFromRM+(dsv?",cl":",01h");
                break;
                case 67:
                    switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                break;
                case 68:
					op=opFromRM+", "+opData;
				break;
                case 69:
                    op=opToReg+", "+opData;
                break;
                case 70:
                    switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                break;
                case 71:
                    op=opToRM+", "+opData;
                break;
                case 72:
					op=opToReg+", "+opData;
                break;
                case 73:
                    switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                break;
                case 74:
                    op=opFromRM+", "+opData;
                break;
                case 75:
                    op=opToReg+", "+opData;
                break;
                case 76:
                    switch(state&0x000000F0){
                        case 0x000000C0:
							op=opToReg+","+opFromReg;
                        break;
                        case 0x00000060:
							op=opToReg+","+opFromRM;
                        break;
                        case 0x00000090:
							op=opToRM+", "+opFromReg;
						break;}
                break;
                case 77:
                    op=opToRM+", "+opData;
                break;
                case 78:
                    op=opToReg+", "+opData;
                break;
                case 79:  //rep's
                    switch(mod){
					case 1:
                        op="movs";
					break;
					case 2:
                        op="cmps";
					break;
					case 3:
                        op="scas";
					break;
					}
                break;

                case 85: //call
                    op=opOffset;
                break;
                case 86:
                    op=opToRM;
                break;
                case 87:
                    op=opSegment+":"+opOffset;
                break;
                case 88:
                    opToRM; 
                break;
                case 89: //jmp
                    op=opOffset;
                break;
                case 90:
                    op=opAddr;
                break;
                case 91:
                    op=opToRM;
                break;
                case 92:
                    op=opSegment+":"+opOffset;
                break;
                case 93:
                    op=opToRM;
                break;

                case 95:
                    op=opData;
                break;

                case 97:
                    op=opData;
                break;
                case 98:  //jz
                    op=opAddr;
                break;
                case 99:  //jl
                    op=opAddr;
                break;
                case 100:  //jle
                    op=opAddr;
                break;
                case 101:  //jb
                    op=opAddr;
                break;
                case 102:  //jbe
                    op=opAddr;
                break;
                case 103:  //jp
                    op=opAddr;
                break;
                case 104:  //jo
                     op=opAddr;
                break;
                case 105:  //js
					op=opAddr;
                break;
                case 106:   //jne
                      op=opAddr;
                break;
                case 107:  //jnl
                    op=opAddr;
                break;
                case 108: //jnle
                    op=opAddr;
                break;
                case 109:  //jnb
                    op=opAddr;
                break;
                case 110: //jnbe
                    op=opAddr;
                break;
                case 111: //jnp
                    op=opAddr;
                break;
                case 112: //jno
                    op=opAddr;
                break;
                case 113: //jns
                    op=opAddr;
                break;
                case 114: //loop
                    op=opAddr;
                break;
                case 115: //loopz
                    op=opAddr;
                break;
                case 116: //loopnz
                    op=opAddr;
                break;
                case 117: //jcxz
                    op=opAddr;
                break;
                case 118: //int
                    op=opAddr;
                break;


        }
Mnemonic=nemonic+" "+op;
//
}

void TForm1::simGetDSV(){
        dsv=(((bytecode[0]&0x00000002)>>1)==0x00000001?true:false);
}

void TForm1::simGetW(){
        w=((bytecode[0]&0x00000001)==0x00000001)?true:false;
}

void TForm1::simGetModRM(){
        mod=(bytecode[1]&0x000000C0)>>6;
        rm=bytecode[1]&0x00000007;
      //  toReg=(bytecode[1]&0x00000038)>>3;
                switch(bytecode[1]&0x000000C0){
                        case 0x000000C0:
                                fromReg=bytecode[1]&0x00000007;
                                state=state|0x00000080;
                                length=2;
                        break;
                        case 0x00000040:
                                fromMem=bytecode[1]&0x00000007;
                                disp8=bytecode[2]&0x000000FF;
                                //disp16=bytecode[2]&0x00000080==0x00000080?0x000000FF:0x00000000;
                                state=state|0x00000022;
                                length=3;
                        break;
                        case 0x00000080:
                                fromMem=bytecode[1]&0x00000007;
                                disp8=bytecode[2]&0x000000FF;
                                disp16=bytecode[3]&0x000000FF;
                                state=state|0x00000023;
                                length=4;
                        break;
                        case 0x00000000:
                                if((bytecode[1]&0x00000007)==0x00000006){
                                        fromMem=bytecode[1]&0x00000007;
                                        disp8=bytecode[2]&0x000000FF;
                                        disp16=bytecode[3]&0x000000FF;
                                        state=state|0x00000023;
                                        length=4;
                                }else{
                                        fromMem=bytecode[1]&0x00000007;
                                        state=state|0x00000020;
                                        length=2;
                                }
                        break;
                }
}

void TForm1::simGetModRegRM(){
        mod=(bytecode[1]&0x000000C0)>>6;
        reg=(bytecode[1]&0x00000038)>>3;
        rm=bytecode[1]&0x00000007;
        if(dsv){
                toReg=(bytecode[1]&0x00000038)>>3;
                state=state|0x00000040;
                switch(bytecode[1]&0x000000C0){
                        case 0x000000C0:
                                fromReg=bytecode[1]&0x00000007;
                                state=state|0x00000080;
                                length=2;
                        break;
                        case 0x00000040:
                                fromMem=bytecode[1]&0x00000007;
                                disp8=bytecode[2]&0x000000FF;
                                //disp16=bytecode[2]&0x00000080==0x00000080?0x000000FF:0x00000000;
                                state=state|0x00000022;
                                length=3;
                        break;
                        case 0x00000080:
                                fromMem=bytecode[1]&0x00000007;
                                disp8=bytecode[2]&0x000000FF;
                                disp16=bytecode[3]&0x000000FF;
                                state=state|0x00000023;
                                length=4;
                        break;
                        case 0x00000000:
                                if((bytecode[1]&0x00000007)==0x00000006){
                                        disp8=bytecode[2]&0x000000FF;
                                        disp16=bytecode[3]&0x000000FF;
                                        fromMem=bytecode[1]&0x00000007;
                                        state=state|0x00000023;
                                        length=4;
                                }else{
                                        fromMem=bytecode[1]&0x00000007;
                                        state=state|0x00000020;
                                        length=2;
                                }
                        break;
                }
        }else{
                fromReg=(bytecode[1]&0x00000038)>>3;
                state=state|0x00000080;
                switch(bytecode[1]&0x000000C0){
                        case 0x000000C0:
                                toReg=bytecode[1]&0x00000007;
                                state=state|0x00000040;
                                length=2;
                        break;
                        case 0x00000040:
                                toMem=bytecode[1]&0x00000007;
                                disp8=bytecode[2]&0x000000FF;
                                disp16=bytecode[2]&0x00000080==0x00000080?0x000000FF:0x00000000;
                                state=state|0x00000013;
                                length=3;
                        break;
                        case 0x00000080:
                                toMem=bytecode[1]&0x00000007;
                                disp8=bytecode[2]&0x000000FF;
                                disp16=bytecode[3]&0x000000FF;
                                state=state|0x00000013;
                                length=4;
                        break;
                        case 0x00000000:
                                if((bytecode[1]&0x00000007)==0x00000006){
                                        disp8=bytecode[2]&0x000000FF;
                                        disp16=bytecode[3]&0x000000FF;
                                        toMem=bytecode[1]&0x00000007;
                                        state=state|0x00000013;
                                        length=4;
                                }else{
                                        toMem=bytecode[1]&0x00000007;
                                        state=state|0x00000010;
                                        length=2;
                                }
                        break;
                }

        }
}

void TForm1::simGetData(){
        if(length==1){
                if(w<=0){
                        data8=bytecode[1]&0x000000FF;
                        //data16=bytecode[2]&0x000000FF;
                        state=state|0x00000008;
                        length=length+1;
                }else
                {
                        data8=bytecode[1]&0x000000FF;
                        data16=w?bytecode[2]&0x000000FF:-1;
                        state=w?(state|0x0000000C):(state|0x00000008);
                        length=w?(length+2):(length+1);
                }
        }else{
                        if(dsv==1){
                                data8=bytecode[length]&0x000000FF;
                                data16=((bytecode[length]&0x00000080)==0x00000080)?0x000000FF:0x00000000;
                                state=state|0x0000000C;
                                length++;

                        }else{
                                data8=bytecode[length]&0x000000FF;
                                data16=(w)?bytecode[length+1]&0x000000FF:-1;
                                state=w?(state|0x0000000C):(state|0x00000008);
                                length=(w?length+2:length+1);
                        }
        }
}

void TForm1::simGetDisp8(){
        disp8=bytecode[1]&0x000000FF;
        state=state|0x00000002;
        length=length+1;
}

void TForm1::simGetDisp16(){
        disp8=bytecode[1]&0x000000FF;
        disp16=bytecode[2]&0x000000FF;
        state=state|0x00000003;
        length=length+2;
}

void TForm1::simGetIntersegment(){
        disp8=bytecode[1]&0x000000FF;
        disp16=bytecode[2]&0x000000FF;
        data8=bytecode[3]&0x000000FF;
        data16=bytecode[4]&0x000000FF;
        state=state|0x0000000F;
        length=length+4;
}

void TForm1::simDecode(){
        simClear();
        length=1;
        if((bytecode[0]&0x000000FC)==0x00000088){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("mov", 0);
        }else if((bytecode[0]&0x000000FE)==0x000000C6 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetModRM();
                simGetData();
                simGetMnemonic("mov",1);
        }else if((bytecode[0]&0x000000F0)==0x000000B0){
                w=((bytecode[0]&0x00000008)==0x00000008)?true:false;
                toReg=bytecode[0]&0x00000007;
                state=state|0x00000040;
                simGetData();
                simGetMnemonic("mov",2);
        }else if((bytecode[0]&0x000000FE)==0x000000A0){
                simGetW();
                simGetDisp16();
                simGetMnemonic("mov",3);
        }else if((bytecode[0]&0x000000FE)==0x000000A2){
                simGetW();
                simGetDisp16();
                simGetMnemonic("mov",4);
        }else if((bytecode[0]&0x000000FF)==0x0000008E && (bytecode[1]&0x00000020)==0x00000000){
                dsv=1;
                w=1;
                simGetModRegRM();
                toReg=toReg+8;
                simGetMnemonic("mov",5);
        }else if((bytecode[0]&0x000000FF)==0x0000008C && (bytecode[1]&0x00000020)==0x00000000){
                w=1;
                simGetModRegRM();
                fromReg=fromReg+8;
                simGetMnemonic("mov",6);
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000030){
                w=1;
                simGetModRM();
                simGetMnemonic("push", 7);
        }else if((bytecode[0]&0x000000F8)==0x00000050){
                w=1;
                fromReg=bytecode[0]&0x00000007;
                simGetMnemonic("push",8);
        }else if((bytecode[0]&0x000000E7)==0x00000006){
                w=1;
                fromReg=((bytecode[0]&0x00000018)>>3)+8;
                simGetMnemonic("push",9);
        }else if((bytecode[0]&0x000000FF)==0x0000008F && (bytecode[1]&0x00000038)==0x00000000){
                w=1;
                simGetModRM();
                simGetMnemonic("pop",10);
        }else if((bytecode[0]&0x000000F8)==0x00000058){
                w=1;
                toReg=bytecode[0]&0x00000007;
                simGetMnemonic("pop",11);
        }else if((bytecode[0]&0x000000E7)==0x00000007){
                w=1;
                toReg=((bytecode[0]&0x00000018)>>3)+8;
                simGetMnemonic("pop",12);
        }else if((bytecode[0]&0x000000FE)==0x00000086){
                simGetW();
                simGetModRegRM();
                simGetMnemonic("xchg", 13);
        }else if((bytecode[0]&0x000000F8)==0x00000090){
                fromReg=bytecode[0]&0x00000007;
                w=1;
                simGetMnemonic("xchg",14);
        }else if((bytecode[0]&0x000000FE)==0x000000E4){
                simGetW();
                simGetDisp8();
                simGetMnemonic(w?"inw":"inb",15);
        }else if((bytecode[0]&0x000000FE)==0x000000EC){
                simGetW();
                simGetMnemonic(w?"inw":"inb",16);
        }else if((bytecode[0]&0x000000FE)==0x000000E6){
                simGetW();
                simGetDisp8();
                simGetMnemonic(w?"outw":"outb",17);
        }else if((bytecode[0]&0x000000FE)==0x000000EE){
                simGetW();
                simGetMnemonic(w?"outw":"outb",18);
        }else if((bytecode[0]&0x000000FF)==0x000000D7){
                simGetMnemonic("xlat",19);
        }else if((bytecode[0]&0x000000FF)==0x0000008D){
                w=1;
                simGetModRegRM();
                simGetMnemonic("lea",20);
        }else if((bytecode[0]&0x000000FF)==0x000000C5){
                w=1;
                simGetModRegRM();
                simGetMnemonic("lds",21);
        }else if((bytecode[0]&0x000000FF)==0x000000C4){
                w=1;
                simGetModRegRM();
                simGetMnemonic("les",22);
        }else if((bytecode[0]&0x000000FF)==0x0000009F){
                simGetMnemonic("lahf",23);
        }else if((bytecode[0]&0x000000FF)==0x0000009E){
                simGetMnemonic("sahf",24);
        }else if((bytecode[0]&0x000000FF)==0x0000009C){
                simGetMnemonic("pushf",25);
        }else if((bytecode[0]&0x000000FF)==0x0000009D){
                simGetMnemonic("popf",26);
        }else if((bytecode[0]&0x000000FC)==0x00000000){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("add", 27);
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                simGetMnemonic("add",28);
        }else if((bytecode[0]&0x000000FE)==0x00000004){
                simGetW();
                simGetData();
                simGetMnemonic("add",29);
        }else if((bytecode[0]&0x000000FC)==0x00000010){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("adc", 30);
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000010){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                simGetMnemonic("adc",31);
        }else if((bytecode[0]&0x000000FE)==0x00000014){
                simGetW();
                simGetData();
                simGetMnemonic("adc",32);
        }else if((bytecode[0]&0x000000FE)==0x000000FE && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetModRM();
                simGetMnemonic("inc",33);
        }else if((bytecode[0]&0x000000F8)==0x00000040){
                w=1;
                toReg=bytecode[0]&0x00000007;
                simGetMnemonic("inc",34);
        }else if((bytecode[0]&0x000000FF)==0x00000037){
                simGetMnemonic("aaa",35);
        }else if((bytecode[0]&0x000000FF)==0x00000027){
                simGetMnemonic("daa",36);
        }else if((bytecode[0]&0x000000FC)==0x00000028){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("sub", 37);
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000028){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                simGetMnemonic("sub",38);
        }else if((bytecode[0]&0x000000FE)==0x0000002C){
                simGetW();
                simGetData();
                simGetMnemonic("sub",39);
        }else if((bytecode[0]&0x000000FC)==0x00000018){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("sbb", 40);
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000018){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                simGetMnemonic("sbb",41);
        }else if((bytecode[0]&0x000000FE)==0x0000001C){
                simGetW();
                simGetData();
                simGetMnemonic("sbb",42);
        }else if((bytecode[0]&0x000000FE)==0x000000FE && (bytecode[1]&0x00000038)==0x00000008){
                simGetW();
                simGetModRM();
                simGetMnemonic("dec",43);
        }else if((bytecode[0]&0x000000F8)==0x00000048){
                w=1;
                toReg=bytecode[0]&0x00000007;
                simGetMnemonic("dec",44);
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000018){
                simGetW();
                simGetModRM();
                simGetMnemonic("neg",45);
        }else if((bytecode[0]&0x000000FC)==0x00000038){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("cmp", 46);
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000038){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                simGetMnemonic("cmp",47);
        }else if((bytecode[0]&0x000000FE)==0x0000003C){
                simGetW();
                simGetData();
                simGetMnemonic("cmp",48);
        }else if((bytecode[0]&0x000000FF)==0x0000003F){
                simGetMnemonic("aas",49);
        }else if((bytecode[0]&0x000000FF)==0x0000002F){
                simGetMnemonic("das",50);
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000020){
                simGetW();
                simGetModRM();
                simGetMnemonic("mul",51);
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000028){
                simGetW();
                simGetModRM();
                simGetMnemonic("imul",52);
        }else if((bytecode[0]&0x000000FF)==0x000000D4 && (bytecode[1]&0x000000FF)==0x0000000A){
                length=2;
                simGetMnemonic("aam",53);
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000030){
                simGetW();
                simGetModRM();
                simGetMnemonic("div",54);
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000038){
                simGetW();
                simGetModRM();
                simGetMnemonic("idiv",55);
        }else if((bytecode[0]&0x000000FF)==0x000000D5 && (bytecode[1]&0x000000FF)==0x0000000A){
                length=2;
                simGetMnemonic("aad",56);
        }else if((bytecode[0]&0x000000FF)==0x00000098){
                simGetMnemonic("cbw",57);
        }else if((bytecode[0]&0x000000FF)==0x00000099){
                simGetMnemonic("cwd",58);
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000010){
                simGetW();
                simGetModRM();
                simGetMnemonic("not",59);
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000020){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetMnemonic("shl",60);
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000028){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetMnemonic("shr",61);
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000038){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetMnemonic("sar",62);
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetMnemonic("rol",63);
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000008){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetMnemonic("ror",64);
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000010){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetMnemonic("rcl",65);
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000018){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetMnemonic("rcr",66);
        }else if((bytecode[0]&0x000000FC)==0x00000020){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("and", 67);
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000020){
                simGetW();
                //simGetDSV();
                simGetModRM();
                simGetData();
                simGetMnemonic("and",68);
        }else if((bytecode[0]&0x000000FE)==0x00000024){
                simGetW();
                simGetData();
                simGetMnemonic("and",69);
        }else if((bytecode[0]&0x000000FE)==0x00000084){
                simGetW();
                simGetModRegRM();
                simGetMnemonic("test", 70);
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetModRM();
                simGetData();
                simGetMnemonic("test",71);
        }else if((bytecode[0]&0x000000FE)==0x000000A8){
                simGetW();
                simGetData();
                simGetMnemonic("test",72);
        }else if((bytecode[0]&0x000000FC)==0x00000008){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("or", 73);
        }else if((bytecode[0]&0x000000FE)==0x00000080 && (bytecode[1]&0x00000038)==0x00000008){
                simGetW();
                simGetModRM();
                simGetData();
                simGetMnemonic("or",74);
        }else if((bytecode[0]&0x000000FE)==0x0000000C){
                simGetW();
                simGetData();
                simGetMnemonic("or",75);
        }else if((bytecode[0]&0x000000FC)==0x00000030){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                simGetMnemonic("xor", 76);
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000030){
                simGetW();
                simGetModRM();
                simGetData();
                simGetMnemonic("xor",77);
        }else if((bytecode[0]&0x000000FE)==0x00000034){
                simGetW();
                simGetData();
                simGetMnemonic("xor",78);
        }else if((bytecode[0]&0x000000FE)==0x000000F2){
                //simGetW();
                switch(bytecode[1]&0x000000FA){
                case 0x000000A4:
                        mod=0x00000001;
                break;
                case 0x000000A6:
                        mod=0x00000002;
                break;
                case 0x000000AE:
                        mod=0x00000003;
                break;
                }
                w=bytecode[1]&0x00000001;
                dsv=bytecode[0]&0x00000001;
                length=2;
                simGetMnemonic("rep",79);
        }else if((bytecode[0]&0x000000FE)==0x000000A4){
                simGetW();
                simGetMnemonic("movs",80);
        }else if((bytecode[0]&0x000000FE)==0x000000A6){
                simGetW();
                simGetMnemonic("cmps",81);
        }else if((bytecode[0]&0x000000FE)==0x000000AE){
                simGetW();
                simGetMnemonic("scas",82);
        }else if((bytecode[0]&0x000000FE)==0x000000AC){
                simGetW();
                simGetMnemonic("lods",83);
        }else if((bytecode[0]&0x000000FE)==0x000000AA){
                simGetW();
                simGetMnemonic("stos",84);
        }else if((bytecode[0]&0x000000FF)==0x000000E8){
                simGetDisp16();
                simGetMnemonic("call",85);
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000010){
                simGetModRM();
                simGetMnemonic("call",86);
        }else if((bytecode[0]&0x000000FF)==0x0000009A){
                simGetIntersegment();
                simGetMnemonic("call",87);
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000018){
                simGetModRM();
                simGetMnemonic("call",88);
        }else if((bytecode[0]&0x000000FF)==0x000000E9){
                simGetDisp16();
                simGetMnemonic("jmp",89);
        }else if((bytecode[0]&0x000000FF)==0x000000EB){
                simGetDisp8();
                simGetMnemonic("jmp",90);
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000020){
               // w=1;
                simGetModRM();
                simGetMnemonic("jmp",91);
        }else if((bytecode[0]&0x000000FF)==0x000000EA){
                simGetIntersegment();
                simGetMnemonic("jmp",92);
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000028){
                w=1;
                simGetModRM();
                simGetMnemonic("jmp",93);
        }else if((bytecode[0]&0x000000FF)==0x000000C3){
                simGetMnemonic("ret",94);
        }else if((bytecode[0]&0x000000FF)==0x000000C2){
                simGetData();
                simGetMnemonic("ret",95);
        }else if((bytecode[0]&0x000000FF)==0x000000CB){
                simGetMnemonic("ret",96);
        }else if((bytecode[0]&0x000000FF)==0x000000CA){
                simGetData();
                simGetMnemonic("ret",97);
        }else if((bytecode[0]&0x000000FF)==0x00000074){
                simGetDisp8();
                simGetMnemonic("jz",98);
        }else if((bytecode[0]&0x000000FF)==0x0000007c){
                simGetDisp8();
                simGetMnemonic("jl",99);
        }else if((bytecode[0]&0x000000FF)==0x0000007e){
                simGetDisp8();
                simGetMnemonic("jng",100);
        }else if((bytecode[0]&0x000000FF)==0x00000072){
                simGetDisp8();
                simGetMnemonic("jb",101);
        }else if((bytecode[0]&0x000000FF)==0x00000076){
                simGetDisp8();
                simGetMnemonic("jna",102);
        }else if((bytecode[0]&0x000000FF)==0x0000007A){
                simGetDisp8();
                simGetMnemonic("jp",103);
        }else if((bytecode[0]&0x000000FF)==0x00000070){
                simGetDisp8();
                simGetMnemonic("jo",104);
        }else if((bytecode[0]&0x000000FF)==0x00000078){
                simGetDisp8();
                simGetMnemonic("js",105);
        }else if((bytecode[0]&0x000000FF)==0x00000075){
                simGetDisp8();
                simGetMnemonic("jnz",106);
        }else if((bytecode[0]&0x000000FF)==0x0000007D){
                simGetDisp8();
                simGetMnemonic("jnl",107);
        }else if((bytecode[0]&0x000000FF)==0x0000007F){
                simGetDisp8();
                simGetMnemonic("jg",108);
        }else if((bytecode[0]&0x000000FF)==0x00000073){
                simGetDisp8();
                simGetMnemonic("jnb",109);
        }else if((bytecode[0]&0x000000FF)==0x00000077){
                simGetDisp8();
                simGetMnemonic("ja",110);
        }else if((bytecode[0]&0x000000FF)==0x0000007B){
                simGetDisp8();
                simGetMnemonic("jnp",111);
        }else if((bytecode[0]&0x000000FF)==0x00000071){
                simGetDisp8();
                simGetMnemonic("jno",112);
        }else if((bytecode[0]&0x000000FF)==0x00000079){
                simGetDisp8();
                simGetMnemonic("jns",113);
        }else if((bytecode[0]&0x000000FF)==0x000000E2){
                simGetDisp8();
                simGetMnemonic("loop",114);
        }else if((bytecode[0]&0x000000FF)==0x000000E1){
                simGetDisp8();
                simGetMnemonic("loopz",115);
        }else if((bytecode[0]&0x000000FF)==0x000000E0){
                simGetDisp8();
                simGetMnemonic("loopnz",116);
        }else if((bytecode[0]&0x000000FF)==0x000000E3){
                simGetDisp8();
                simGetMnemonic("jcxz",117);
        }else if((bytecode[0]&0x000000FF)==0x000000CD){
                simGetDisp8();
                simGetMnemonic("int",118);
        }else if((bytecode[0]&0x000000FF)==0x000000CC){
                simGetMnemonic("int",119);
        }else if((bytecode[0]&0x000000FF)==0x000000CE){
                simGetMnemonic("into",120);
        }else if((bytecode[0]&0x000000FF)==0x000000CF){
                simGetMnemonic("iret",121);
        }else if((bytecode[0]&0x000000FF)==0x000000F8){
                simGetMnemonic("clc",122);
        }else if((bytecode[0]&0x000000FF)==0x000000F5){
                simGetMnemonic("cmc",123);
        }else if((bytecode[0]&0x000000FF)==0x000000F9){
                simGetMnemonic("stc",124);
        }else if((bytecode[0]&0x000000FF)==0x000000FC){
                simGetMnemonic("cld",125);
        }else if((bytecode[0]&0x000000FF)==0x000000FD){
                simGetMnemonic("std",126);
        }else if((bytecode[0]&0x000000FF)==0x000000FA){
                simGetMnemonic("cli",127);
        }else if((bytecode[0]&0x000000FF)==0x000000FB){
                simGetMnemonic("sti",128);
        }else if((bytecode[0]&0x000000FF)==0x000000F4){
                simGetMnemonic("hlt",129);
        }else if((bytecode[0]&0x000000FF)==0x0000009B){
                simGetMnemonic("wait",130);
        }else if((bytecode[0]&0x000000F8)==0x000000D8){
                simGetModRM();
                simGetMnemonic("esc",131);
        }else if((bytecode[0]&0x000000FF)==0x000000F0){
                simGetMnemonic("lock",132);
        }
}

void TForm1::simDecodeF(){
        simClear();
        length=1;
        if((bytecode[0]&0x000000FC)==0x00000088){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=0;
        }else if((bytecode[0]&0x000000FE)==0x000000C6 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetModRM();
                simGetData();
                mnemonic=1;
        }else if((bytecode[0]&0x000000F0)==0x000000B0){
                w=((bytecode[0]&0x00000008)==0x00000008)?true:false;
                toReg=bytecode[0]&0x00000007;
                state=state|0x00000040;
                simGetData();
                mnemonic=2;
        }else if((bytecode[0]&0x000000FE)==0x000000A0){
                simGetW();
                simGetDisp16();
                mnemonic=3;
        }else if((bytecode[0]&0x000000FE)==0x000000A2){
                simGetW();
                simGetDisp16();
                mnemonic=4;
        }else if((bytecode[0]&0x000000FF)==0x0000008E && (bytecode[1]&0x00000020)==0x00000000){
                dsv=1;
                w=1;
                simGetModRegRM();
                toReg=toReg+8;
                mnemonic=5;
        }else if((bytecode[0]&0x000000FF)==0x0000008C && (bytecode[1]&0x00000020)==0x00000000){
                w=1;
                simGetModRegRM();
                fromReg=fromReg+8;
                mnemonic=6;
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000030){
                w=1;
                simGetModRM();
                mnemonic=7;
        }else if((bytecode[0]&0x000000F8)==0x00000050){
                w=1;
                fromReg=bytecode[0]&0x00000007;
                mnemonic=8;
        }else if((bytecode[0]&0x000000E7)==0x00000006){
                w=1;
                fromReg=((bytecode[0]&0x00000018)>>3)+8;
                mnemonic=9;
        }else if((bytecode[0]&0x000000FF)==0x0000008F && (bytecode[1]&0x00000038)==0x00000000){
                w=1;
                simGetModRM();
                mnemonic=10;
        }else if((bytecode[0]&0x000000F8)==0x00000058){
                w=1;
                toReg=bytecode[0]&0x00000007;
                mnemonic=11;
        }else if((bytecode[0]&0x000000E7)==0x00000007){
                w=1;
                toReg=((bytecode[0]&0x00000018)>>3)+8;
                mnemonic=12;
        }else if((bytecode[0]&0x000000FE)==0x00000086){
                simGetW();
                simGetModRegRM();
                mnemonic=13;
        }else if((bytecode[0]&0x000000F8)==0x00000090){
                fromReg=bytecode[0]&0x00000007;
                w=1;
                mnemonic=14;
        }else if((bytecode[0]&0x000000FE)==0x000000E4){
                simGetW();
                simGetDisp8();
                mnemonic=15;
        }else if((bytecode[0]&0x000000FE)==0x000000EC){
                simGetW();
                simGetMnemonic(w?"inw":"inb",16);
        }else if((bytecode[0]&0x000000FE)==0x000000E6){
                simGetW();
                simGetDisp8();
                mnemonic=17;
        }else if((bytecode[0]&0x000000FE)==0x000000EE){
                simGetW();
                mnemonic=18;
        }else if((bytecode[0]&0x000000FF)==0x000000D7){
                mnemonic=19;
        }else if((bytecode[0]&0x000000FF)==0x0000008D){
                w=1;
                simGetModRegRM();
                mnemonic=20;
        }else if((bytecode[0]&0x000000FF)==0x000000C5){
                w=1;
                simGetModRegRM();
                mnemonic=21;
        }else if((bytecode[0]&0x000000FF)==0x000000C4){
                w=1;
                simGetModRegRM();
                mnemonic=22;
        }else if((bytecode[0]&0x000000FF)==0x0000009F){
                mnemonic=23;
        }else if((bytecode[0]&0x000000FF)==0x0000009E){
                mnemonic=24;
        }else if((bytecode[0]&0x000000FF)==0x0000009C){
                mnemonic=25;
        }else if((bytecode[0]&0x000000FF)==0x0000009D){
                mnemonic=26;
        }else if((bytecode[0]&0x000000FC)==0x00000000){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=27;
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                mnemonic=28;
        }else if((bytecode[0]&0x000000FE)==0x00000004){
                simGetW();
                simGetData();
                mnemonic=29;
        }else if((bytecode[0]&0x000000FC)==0x00000010){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=30;
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000010){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                mnemonic=31;
        }else if((bytecode[0]&0x000000FE)==0x00000014){
                simGetW();
                simGetData();
                mnemonic=32;
        }else if((bytecode[0]&0x000000FE)==0x000000FE && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetModRM();
                mnemonic=33;
        }else if((bytecode[0]&0x000000F8)==0x00000040){
                w=1;
                toReg=bytecode[0]&0x00000007;
                mnemonic=34;
        }else if((bytecode[0]&0x000000FF)==0x00000037){
                mnemonic=35;
        }else if((bytecode[0]&0x000000FF)==0x00000027){
                mnemonic=36;
        }else if((bytecode[0]&0x000000FC)==0x00000028){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=37;
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000028){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                mnemonic=38;
        }else if((bytecode[0]&0x000000FE)==0x0000002C){
                simGetW();
                simGetData();
                mnemonic=39;
        }else if((bytecode[0]&0x000000FC)==0x00000018){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=40;
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000018){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                mnemonic=41;
        }else if((bytecode[0]&0x000000FE)==0x0000001C){
                simGetW();
                simGetData();
                mnemonic=42;
        }else if((bytecode[0]&0x000000FE)==0x000000FE && (bytecode[1]&0x00000038)==0x00000008){
                simGetW();
                simGetModRM();
                 mnemonic=43;
        }else if((bytecode[0]&0x000000F8)==0x00000048){
                w=1;
                toReg=bytecode[0]&0x00000007;
                mnemonic=44;
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000018){
                simGetW();
                simGetModRM();
                mnemonic=45;
        }else if((bytecode[0]&0x000000FC)==0x00000038){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=46;
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000038){
                simGetW();
                simGetDSV();
                simGetModRM();
                simGetData();
                mnemonic=47;
        }else if((bytecode[0]&0x000000FE)==0x0000003C){
                simGetW();
                simGetData();
                mnemonic=48;
        }else if((bytecode[0]&0x000000FF)==0x0000003F){
                mnemonic=49;
        }else if((bytecode[0]&0x000000FF)==0x0000002F){
                mnemonic=50;
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000020){
                simGetW();
                simGetModRM();
                mnemonic=51;
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000028){
                simGetW();
                simGetModRM();
                mnemonic=52;
        }else if((bytecode[0]&0x000000FF)==0x000000D4 && (bytecode[1]&0x000000FF)==0x0000000A){
                length=2;
                mnemonic=53;
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000030){
                simGetW();
                simGetModRM();
                mnemonic=54;
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000038){
                simGetW();
                simGetModRM();
                mnemonic=55;
        }else if((bytecode[0]&0x000000FF)==0x000000D5 && (bytecode[1]&0x000000FF)==0x0000000A){
                mnemonic=56;
        }else if((bytecode[0]&0x000000FF)==0x00000098){
                mnemonic=57;
        }else if((bytecode[0]&0x000000FF)==0x00000099){
                mnemonic=58;
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000010){
                simGetW();
                simGetModRM();
                mnemonic=59;
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000020){
                simGetW();
                simGetDSV();
                simGetModRM();
                mnemonic=60;
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000028){
                simGetW();
                simGetDSV();
                simGetModRM();
                mnemonic=61;
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000038){
                simGetW();
                simGetDSV();
                simGetModRM();
                mnemonic=62;
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetDSV();
                simGetModRM();
                mnemonic=63;
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000008){
                simGetW();
                simGetDSV();
                simGetModRM();
                mnemonic=64;
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000010){
                simGetW();
                simGetDSV();
                simGetModRM();
                mnemonic=65;
        }else if((bytecode[0]&0x000000FC)==0x000000D0 && (bytecode[1]&0x00000038)==0x00000018){
                simGetW();
                simGetDSV();
                simGetModRM();
                mnemonic=66;
        }else if((bytecode[0]&0x000000FC)==0x00000020){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=67;
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000020){
                simGetW();
                //simGetDSV();
                simGetModRM();
                simGetData();
                mnemonic=68;
        }else if((bytecode[0]&0x000000FE)==0x00000024){
                simGetW();
                simGetData();
                mnemonic=69;
        }else if((bytecode[0]&0x000000FE)==0x00000084){
                simGetW();
                simGetModRegRM();
                mnemonic=70;
        }else if((bytecode[0]&0x000000FE)==0x000000F6 && (bytecode[1]&0x00000038)==0x00000000){
                simGetW();
                simGetModRM();
                simGetData();
                mnemonic=71;
        }else if((bytecode[0]&0x000000FE)==0x000000A8){
                simGetW();
                simGetData();
                mnemonic=72;
        }else if((bytecode[0]&0x000000FC)==0x00000008){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=73;
        }else if((bytecode[0]&0x000000FE)==0x00000080 && (bytecode[1]&0x00000038)==0x00000008){
                simGetW();
                simGetModRM();
                simGetData();
                mnemonic=74;
        }else if((bytecode[0]&0x000000FE)==0x0000000C){
                simGetW();
                simGetData();
                mnemonic=75;
        }else if((bytecode[0]&0x000000FC)==0x00000030){
                simGetDSV();
                simGetW();
                simGetModRegRM();
                mnemonic=76;
        }else if((bytecode[0]&0x000000FC)==0x00000080 && (bytecode[1]&0x00000038)==0x00000030){
                simGetW();
                simGetModRM();
                simGetData();
                mnemonic=77;
        }else if((bytecode[0]&0x000000FE)==0x00000034){
                simGetW();
                simGetData();
                mnemonic=78;
        }else if((bytecode[0]&0x000000FE)==0x000000F2){
                //simGetW();
                switch(bytecode[1]&0x000000FA){
                case 0x000000A4:
                        mod=0x00000001;
                break;
                case 0x000000A6:
                        mod=0x00000002;
                break;
                case 0x000000AE:
                        mod=0x00000003;
                break;
                }
                w=bytecode[1]&0x00000001;
                dsv=bytecode[0]&0x00000001;
                length=2;
                mnemonic=79;
        }else if((bytecode[0]&0x000000FE)==0x000000A4){
                simGetW();
                mnemonic=80;
        }else if((bytecode[0]&0x000000FE)==0x000000A6){
                simGetW();
                mnemonic=81;
        }else if((bytecode[0]&0x000000FE)==0x000000AE){
                simGetW();
                mnemonic=82;
        }else if((bytecode[0]&0x000000FE)==0x000000AC){
                simGetW();
                mnemonic=83;
        }else if((bytecode[0]&0x000000FE)==0x000000AA){
                simGetW();
                mnemonic=84;
        }else if((bytecode[0]&0x000000FF)==0x000000E8){
                simGetDisp16();
                mnemonic=85;
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000010){
                simGetModRM();
                mnemonic=86;
        }else if((bytecode[0]&0x000000FF)==0x0000009A){
                simGetIntersegment();
                mnemonic=87;
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000018){
                simGetModRM();
                mnemonic=88;
        }else if((bytecode[0]&0x000000FF)==0x000000E9){
                simGetDisp16();
                mnemonic=89;
        }else if((bytecode[0]&0x000000FF)==0x000000EB){
                simGetDisp8();
                mnemonic=90;
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000020){
                simGetModRM();
                mnemonic=91;
        }else if((bytecode[0]&0x000000FF)==0x000000EA){
                simGetIntersegment();
                mnemonic=92;
        }else if((bytecode[0]&0x000000FF)==0x000000FF && (bytecode[1]&0x00000038)==0x00000028){
                simGetModRM();
                mnemonic=93;
        }else if((bytecode[0]&0x000000FF)==0x000000C3){
                mnemonic=94;
        }else if((bytecode[0]&0x000000FF)==0x000000C2){
                simGetData();
                mnemonic=95;
        }else if((bytecode[0]&0x000000FF)==0x000000CB){
                mnemonic=96;
        }else if((bytecode[0]&0x000000FF)==0x000000CA){
                simGetData();
                mnemonic=97;
        }else if((bytecode[0]&0x000000FF)==0x00000074){
                simGetDisp8();
                mnemonic=98;
        }else if((bytecode[0]&0x000000FF)==0x0000007c){
                simGetDisp8();
                mnemonic=99;
        }else if((bytecode[0]&0x000000FF)==0x0000007e){
                simGetDisp8();
                mnemonic=100;
        }else if((bytecode[0]&0x000000FF)==0x00000072){
                simGetDisp8();
                mnemonic=101;
        }else if((bytecode[0]&0x000000FF)==0x00000076){
                simGetDisp8();
                mnemonic=102;
        }else if((bytecode[0]&0x000000FF)==0x0000007A){
                simGetDisp8();
                mnemonic=103;
        }else if((bytecode[0]&0x000000FF)==0x00000070){
                simGetDisp8();
                mnemonic=104;
        }else if((bytecode[0]&0x000000FF)==0x00000078){
                simGetDisp8();
                mnemonic=105;
        }else if((bytecode[0]&0x000000FF)==0x00000075){
                simGetDisp8();
                mnemonic=106;
        }else if((bytecode[0]&0x000000FF)==0x0000007D){
                simGetDisp8();
                mnemonic=107;
        }else if((bytecode[0]&0x000000FF)==0x0000007F){
                simGetDisp8();
                mnemonic=108;
        }else if((bytecode[0]&0x000000FF)==0x00000073){
                simGetDisp8();
                mnemonic=109;
        }else if((bytecode[0]&0x000000FF)==0x00000077){
                simGetDisp8();
                mnemonic=110;
        }else if((bytecode[0]&0x000000FF)==0x0000007B){
                simGetDisp8();
                mnemonic=111;
        }else if((bytecode[0]&0x000000FF)==0x00000071){
                simGetDisp8();
                mnemonic=112;
        }else if((bytecode[0]&0x000000FF)==0x00000079){
                simGetDisp8();
                mnemonic=113;
        }else if((bytecode[0]&0x000000FF)==0x000000E2){
                simGetDisp8();
                mnemonic=114;
        }else if((bytecode[0]&0x000000FF)==0x000000E1){
                simGetDisp8();
                mnemonic=115;
        }else if((bytecode[0]&0x000000FF)==0x000000E0){
                simGetDisp8();
                mnemonic=116;
        }else if((bytecode[0]&0x000000FF)==0x000000E3){
                simGetDisp8();
                mnemonic=117;
        }else if((bytecode[0]&0x000000FF)==0x000000CD){
                simGetDisp8();
                mnemonic=118;
        }else if((bytecode[0]&0x000000FF)==0x000000CC){
                mnemonic=119;
        }else if((bytecode[0]&0x000000FF)==0x000000CE){
                mnemonic=120;
        }else if((bytecode[0]&0x000000FF)==0x000000CF){
                mnemonic=121;
        }else if((bytecode[0]&0x000000FF)==0x000000F8){
                mnemonic=122;
        }else if((bytecode[0]&0x000000FF)==0x000000F5){
                mnemonic=123;
        }else if((bytecode[0]&0x000000FF)==0x000000F9){
                mnemonic=124;
        }else if((bytecode[0]&0x000000FF)==0x000000FC){
                mnemonic=125;
        }else if((bytecode[0]&0x000000FF)==0x000000FD){
                mnemonic=126;
        }else if((bytecode[0]&0x000000FF)==0x000000FA){
                mnemonic=127;
        }else if((bytecode[0]&0x000000FF)==0x000000FB){
                mnemonic=128;
        }else if((bytecode[0]&0x000000FF)==0x000000F4){
                mnemonic=129;
        }else if((bytecode[0]&0x000000FF)==0x0000009B){
                mnemonic=130;
        }else if((bytecode[0]&0x000000F8)==0x000000D8){
                simGetModRM();
                mnemonic=131;
        }else if((bytecode[0]&0x000000FF)==0x000000F0){
                mnemonic=132;
        }
}

//---------------------------------------------------------------------------

void TForm1::simStep(){
unsigned int disp=0;
unsigned int temp=0;
unsigned int i=0;
unsigned int a1;
unsigned int a2;
        regPC=(regPC+length)&0x0000FFFF;
        switch(mnemonic){
                        //mov
                case 0:
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                regIn(toReg,w,regOut(fromReg,w));
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w));
                                        break;
                                        case 1:
                                                regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w));
                                        break;
                                        case 2:
                                                regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w));
                                        break;
                                        case 3:
                                                regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w));
                                        break;
                                        case 4:
                                                regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w));
                                        break;
                                        case 5:
                                                regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w));
                                        break;
                                        case 7:
                                                regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w));
                                        break;
                                        case 6:
                                                if(mod==0)
                                                        regIn(toReg,w,memOut((regSegOut(DS)<<4)+disp,w));
                                                else
                                                        regIn(toReg,w,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w));
                                        break;
                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,regOut(fromReg,w));
                                        break;
                                        case 1:
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,regOut(fromReg,w));
                                        break;
                                        case 2:
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,regOut(fromReg,w));
                                        break;
                                        case 3:
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,regOut(fromReg,w));
                                        break;
                                        case 4:
                                                memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,regOut(fromReg,w));
                                        break;
                                        case 5:
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,regOut(fromReg,w));
                                        break;
                                        case 7:
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,regOut(fromReg,w));
                                        break;
                                        case 6:
                                                if(mod==0)
                                                        memIn((regSegOut(DS)<<4)+disp,w,regOut(fromReg,w));
                                                else
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,regOut(fromReg,w));
                                        break;
                                }

                        break;

                        }
                break;
                case 1:
                        switch(state&0x000000F0){
                                case 0x00000040:
                                        regIn(fromReg,w,w?((data16<<8)+data8):data8);
                                break;
                                case 0x00000020:
                                        if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                        }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                        }
                                        switch(fromMem){
                                                case 0:
                                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                                case 1:
                                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                                case 2:
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                                case 3:
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                                case 4:
                                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                                case 5:
                                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                                case 7:
                                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                                case 6:
                                                        if(mod==0)
                                                                memIn((regSegOut(DS)<<4)+disp,w,w?((data16<<8)+data8):data8);
                                                        else
                                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,w?((data16<<8)+data8):data8);
                                                break;
                                        }//??? tut proverit'
                                break;
                        }
                break;
                case 2:
                        regIn(toReg,w,(w?data8+(data16<<8):data8));
                break;
                case 3:
                        if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                        }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                        }
                        regIn(AX,w,memOut(regSegOut(DS)+disp,w));
                break;
                case 4:
                if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                        }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                        }
                        memIn(regSegOut(DS)+disp,w,regOut(AX,w));
                break;
                case 5:
                        if(mod==0x00000003){
                                regSegIn(toReg,regOut(fromReg,1));
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,1));
                                break;
                                case 1:
                                        regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,1));
                                break;
                                case 2:
                                        regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,1));
                                break;
                                case 3:
                                        regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,1));
                                break;
                                case 4:
                                        regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,1));
                                break;
                                case 5:
                                        regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,1));
                                break;
                                case 6:
                                      if (mod==0x00000000)
                                               regSegIn(toReg,memOut((regSegOut(DS)<<4)+disp,1));
                                      else
                                                regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,1));
                                break;
                                case 7:
                                        regSegIn(toReg,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,1));
                                break;
                                }
                        }
                break;
                case 6:
                        if(mod==0x00000003){
                                regIn(toReg,1,regSegOut(fromReg));
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                case 0:
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,1,regSegOut(fromReg));
                                break;
                                case 1:
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,1,regSegOut(fromReg));
                                break;
                                case 2:
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,1,regSegOut(fromReg));
                                break;
                                case 3:
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,1,regSegOut(fromReg));
                                break;
                                case 4:
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,1,regSegOut(fromReg));
                                break;
                                case 5:
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,1,regSegOut(fromReg));
                                break;
                                case 6:
                                        if(mod==0x00000000)
                                                memIn((regSegOut(DS)<<4)+disp,1,regSegOut(fromReg));
                                        else
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,1,regSegOut(fromReg));

                                break;
                                case 7:
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,1,regSegOut(fromReg));
                                break;
                                }
                        }
                break;
                // push
                case 7:
                        regIn(SP,1,regOut(SP,1)-2);
                        if (mod==0x00000003){
                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regOut(fromReg,1));
                        }else {
                                if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem) {
                                case 0:
                                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,1));
                                break;
                                case 1:
                                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,1));
                                break;
                                case 2:
                                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,1));
                                break;
                                case 3:
                                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,1));
                                break;
                                case 4:
                                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,1));
                                break;
                                case 5:
                                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,1));
                                break;
                                case 6:
                                        if(mod==0x00000000)
                                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+disp,1));
                                        else
                                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,1));
                                break;
                                case 7:
                                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,1));
                                break;
                                }
                        }
                break;
                case 8:
                        regIn(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regOut(fromReg,1));
                break;
                case 9:
                        regIn(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(fromReg));
                break;
                        //pop
                case 10:
                        if (mod==0x00000003){
                                regIn(toReg,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        }else {
                                if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                }
                                switch (fromMem){
                                 case 0:
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                 case 1:
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                 case 2:
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                 case 3:
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                 case 4:
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                 case 5:
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                 case 6:
                                        if(mod==0x00000000)
                                                memIn((regSegOut(DS)<<4)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                        else
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                 case 7:
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                                 break;
                                }
                        }
                        regIn(SP,1,regOut(SP,1)+2);
                break;
                case 11:
                        regInF(toReg,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        //regIn(toReg,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        regIn(SP,1,regOut(SP,1)+2);
                break;
                case 12:
                        regInF(toReg,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        //regSegIn(toReg,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        regIn(SP,1,regOut(SP,1)+2);
                break;
                case 13:  //xchg
                        if(mod==0x00000003){
                                temp=regOut(fromReg,w);
                                //regIn(fromReg,w,regOut(toReg,w));
                                regInF(fromReg,w,regOut(toReg,w));
                                regIn(toReg,w,temp);
                        }else{
                                temp=regOut(fromReg,w);
                                //
                                if ((state&0x00000003)==0x00000002){
                                                if((disp8&0x00000080)==0x00000080){
                                                        disp=(disp8|0x0000FF00);
                                                }else{
                                                        disp=disp8;
                                                }
                                }else if((state&0x00000003)==0x00000003){
                                                disp=(disp16<<8)+disp8;
                                }
                                //
                                switch(toMem){
                                case 0:
                                        regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w));
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 1:
                                        regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w));
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 2:
                                        regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w));
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w));
                                        //ShowMessage((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w));
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 5:
                                        regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w));
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                regIn(fromReg,w,memOut((regSegOut(DS)<<4)+disp,w));
                                                memIn((regSegOut(DS)<<4)+disp,w,temp);
                                        }else{
                                                regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w));
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                        }
                                break;
                                case 7:
                                        regIn(fromReg,w,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w));
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                break;
                                }

                        }
                break;
                case 14:
                        temp=regOut(AX,1);
                        //regIn(AX,1,regOut(toReg,1));
                        regInF(AX,1,regOut(fromReg,1));
                        regIn(fromReg,1,temp);
                break;
                case 15:
                        regIn(AX,w,portOutIN(disp8,w));
                break;
                case 16:
                        regIn(AX,w,portOutIN(regOut(DX,1),w));
                break;
                case 17:
                        portInOUT(disp8,w,regOut(AX,w));
                break;
                case 18:
                        portInOUT(regOut(DX,1),w,regOut(AX,w));
                break;
                case 19:
                        regIn(AL,0,memOut((regOut(DS,1)<<4)+regOut(BX,1)+regOut(AL,0),0));
                break;
                case 20: //lea
                        if ((state&0x00000003)==0x00000002){
                                if((disp8&0x00000080)==0x00000080){
                                        disp=(disp8|0x0000FF00);
                                }else{
                                        disp=disp8;
                                                }
                        }else if((state&0x00000003)==0x00000003){
                                disp=(disp16<<8)+disp8;
                        }
                        switch(toMem){
                        case 0:
                                regIn(fromReg,1,regOut(BX,1)+regOut(SI,1)+disp);
                        break;
                        case 1:
                                regIn(fromReg,1,regOut(BX,1)+regOut(DI,1)+disp);
                        break;
                        case 2:
                                regIn(fromReg,1,regOut(BP,1)+regOut(SI,1)+disp);
                        break;
                        case 3:
                                regIn(fromReg,1,regOut(BP,1)+regOut(DI,1)+disp);
                        break;
                        case 4:
                                regIn(fromReg,1,regOut(SI,1)+disp);
                        break;
                        case 5:
                                regIn(fromReg,1,regOut(DI,1)+disp);
                        break;
                        case 6:
                                if(mod==0x00000000){
                                        regIn(fromReg,1,disp);
                                }else{
                                        regIn(fromReg,1,regOut(BP,1)+disp);
                                }
                        break;
                        case 7:
                                regIn(fromReg,1,regOut(BX,1)+disp);
                        break;
                        }
                break;
                case 21:
                       //lds
                       if ((state&0x00000003)==0x00000002){
                                if((disp8&0x00000080)==0x00000080){
                                        disp=(disp8|0x0000FF00);
                                }else{
                                        disp=disp8;
                                                }
                        }else if((state&0x00000003)==0x00000003){
                                disp=(disp16<<8)+disp8;
                        }
                        switch(toMem){
                        case 0:
                                //regIn(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,1));
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,1));
                                regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp+2,1));
                        break;
                        case 1:
                                //regIn(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,1));
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,1));
                                regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp+2,1));
                        break;
                        case 2:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,1));
                                regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp+2,1));
                        break;
                        case 3:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,1));
                                regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp+2,1));
                        break;
                        case 4:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,1));
                                regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp+2,1));
                        break;
                        case 5:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,1));
                                regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp+2,1));
                        break;
                        case 6:
                                if(mod==0x00000000){
                                        regInF(fromReg,1,memOut((regSegOut(DS)<<4)+disp,1));
                                        regIn(DS,1,memOut((regSegOut(DS)<<4)+disp+2,1));
                                }else{
                                        regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,1));
                                        regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp+2,1));
                                }
                        break;
                        case 7:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,1));
                                regIn(DS,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp+2,1));
                        break;
                        }
                break;
                case 22:
                        //lds
                       if ((state&0x00000003)==0x00000002){
                                if((disp8&0x00000080)==0x00000080){
                                        disp=(disp8|0x0000FF00);
                                }else{
                                        disp=disp8;
                                                }
                        }else if((state&0x00000003)==0x00000003){
                                disp=(disp16<<8)+disp8;
                        }
                        switch(toMem){
                        case 0:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,1));
                                regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp+2,1));
                        break;
                        case 1:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,1));
                                regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp+2,1));
                        break;
                        case 2:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,1));
                                regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp+2,1));
                        break;
                        case 3:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,1));
                                regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp+2,1));
                        break;
                        case 4:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,1));
                                regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp+2,1));
                        break;
                        case 5:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,1));
                                regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp+2,1));
                        break;
                        case 6:
                                if(mod==0x00000000){
                                        regInF(fromReg,1,memOut((regSegOut(DS)<<4)+disp,1));
                                        regIn(ES,1,memOut((regSegOut(DS)<<4)+disp+2,1));
                                }else{
                                        regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,1));
                                        regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp+2,1));
                                }
                        break;
                        case 7:
                                regInF(fromReg,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,1));
                                regIn(ES,1,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp+2,1));
                        break;
                        }
                break;
                case 23:
                        regIn(AH,0,regFL&0x000000FF);
                break;
                case 24:
                        regFL=regOut(AH,0);
                        regShow();
                break;
                case 25:
                        regIn(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regFL);
                break;
                case 26:
                        regFL=memOut((regSegOut(SS)<<4)+regOut(SP,1),1);
                        regIn(SP,1,regOut(SP,1)+2);
                break;
                case 27:
                        //  add
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                regInF(toReg,w,temp);
                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        regInF(toReg,w,temp);
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        regInF(toReg,w,temp);
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+disp,w,temp);
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                        break;

                                }
                        break;
                        }
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( a1&0x0000000F) + (a2&0x0000000F)  > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();

                        //
                break;
                case 28:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if((state&0x00000080)==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                regInF(fromReg,w,temp);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp);
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                break;
                                }
                        }
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( (a1&0x0000000F) + (a2&0x0000000F) ) > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 29:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                        regInF(AX,w,temp);
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( (a1&0x0000000F) + (a2&0x0000000F) ) > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                //case 30:

                //break;
                case 30:
                        //adc
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                regInF(toReg,w,temp);
                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        regInF(toReg,w,temp);
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        regInF(toReg,w,temp);
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp);
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+disp,w,temp);
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                        break;

                                }
                        break;
                        }
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( (a1&0x0000000F) + (a2&0x0000000F) + 0x00000001 ) > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                        //
                break;
                case 31:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if(state&0x00000080==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                regInF(toReg,w,temp);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp);
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                break;
                                }
                        }
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080)==0x00000000)){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( (a1&0x0000000F) + (a2&0x0000000F) + 0x00000001 ) > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 32:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a1+a2+(regFlRead(CF)?0x00000001:0x00000000))&(w?0x0000FFFF:0x000000FF);
                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                        regInF(AX,w,temp);
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( (a1&0x0000000F) + (a2&0x0000000F) + 0x00000001) > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 33:      //inc
                        a1=0x00000001;
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                regInF(fromReg,w,temp);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp);
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                                i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                break;
                                }
                        }
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                               // regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                        }else if(i==0x00000004 || i==0x00000002){
                               // regFlSet(CF);
                        }else{
                               // regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( (a1&0x0000000F) + (a2&0x0000000F) ) > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 34:
                        a1=0x00000001;
                        a2=regOut(toReg,w);
                        temp=(a1+a2)&(w?0x0000FFFF:0x000000FF);
                        i=((temp>>(w?15:7))&0x00000001)+((a1>>(w?14:6))&0x00000002)+((a2>>(w?13:5))&0x00000004);
                        regInF(toReg,w,temp);
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                               // regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                        }else if(i==0x00000004 || i==0x00000002){
                               // regFlSet(CF);
                        }else{
                               // regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if( ( (a1&0x0000000F) + (a2&0x0000000F) ) > 0x0000000F){
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 35:
                        a1=regOut(AL,0)&0x0000000F;
                        if(a1>0x00000009 || regFlRead(AF)){
                                a1=(a1+0x00000006)&0x0000000F;
                                regInF(AL,0,a1);
                                regInF(AH,0,(regOut(AH,0)+0x00000001)&0x000000FF);
                                regFlSet(AF);
                                regFlSet(CF);
                        }else{
                                regFlReset(AF);
                                regFlReset(CF);
                        }
                        regShow();
                break;
                case 36:
                        a1=0x00000000;
                        a2=regOut(AL,0);
                        if((regOut(AL,0)&0x0000000F)>0x00000009 || regFlRead(AF)){
                                regInF(AL,0,(regOut(AL,0)+0x00000006)&0x000000FF);
                                regFlSet(AF);
                                a1=a1+0x00000006;
                        }else
                                regFlReset(AF);
                        if( (regOut(AL,0)&0x000000F0)>0x00000090 || regFlRead(CF)){
                                regInF(AL,0,(regOut(AL,0)+0x00000060)&0x000000FF);
                                regFlSet(CF);
                                a1=a1+0x00000060;
                        }else
                                regFlReset(CF);
                        temp=(a1+a2)&0x000000FF;
                        i=((temp>>7)&0x00000001)+((a1>>6)&0x00000002)+((a2>>5)&0x00000004);
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                               // regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                        }else if(i==0x00000004 || i==0x00000002){
                               // regFlSet(CF);
                        }else{
                               // regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 37:       //sub
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=a1-a2;
                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                //temp=(a1-a2)&(w?0x0000FFFF:0x000000FF);
                                //regInF(toReg,w,temp);
                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=a1-a2;
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                //regInF(toReg,w,temp);
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=a1-a2;
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                //regInF(toReg,w,temp);
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=a1-a2;
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                //regInF(toReg,w,temp);
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=a1-a2;
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                //regInF(toReg,w,temp);
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=a1-a2;
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                //regInF(toReg,w,temp);
                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=a1-a2;
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                //regInF(toReg,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=a1-a2;
                                                        regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                        //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        //regInF(toReg,w,temp);
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=a1-a2;
                                                        regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                        //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        //regInF(toReg,w,temp);
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=a1-a2;
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                //regInF(toReg,w,temp);
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=a1-a2;
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=a1-a2;
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=a1-a2;
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=a1-a2;
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=a1-a2;
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=a1-a2;
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=a1-a2;
                                                        //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=a1-a2;
                                                        //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=a1-a2;
                                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;

                                }
                        break;
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        */
                        
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a1&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a1&0x0000000F) < (a2&0x0000000F) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                        //
                break;
                case 38:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if((state&0x00000080)==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=a2-a1;
                                //temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                regInF(fromReg,w,temp&(w?0x0000FFFF:0x000000FF));
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a2-a1);//&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                }
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a2&0x0000000F) < (a1&0x0000000F) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 39:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a2-a1);
                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        regInF(AX,w,temp&(w?0x0000FFFF:0x000000FF));
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a2&0x0000000F) < (a1&0x0000000F) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 40: //sbb
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a2-a1-regFlRead(CF)?0x00000001:0x00000000)&(w?0x0000FFFF:0x000000FF);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        break;

                                }
                        break;
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a1&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a1&0x0000000F) < ((a2&0x0000000F)+(regFlRead(CF)?0x00000001:0x00000000)) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                        //
                break;
                case 41:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if((state&0x00000080)==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                regInF(fromReg,w,temp&(w?0x0000FFFF:0x000000FF));
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                }
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a2&0x0000000F) < ((a1&0x0000000F)+(regFlRead(CF)?0x00000001:0x00000000)) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 42:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a2-a1-(regFlRead(CF)?0x00000001:0x00000000));
                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        regInF(AX,w,temp&(w?0x0000FFFF:0x000000FF));
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a2&0x0000000F) < ((a1&0x0000000F)+(regFlRead(CF)?0x00000001:0x00000000)) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 43: //dec
                        a1=0x00000001;
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a2-a1);
                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                regInF(fromReg,w,temp&(w?0x0000FFFF:0x000000FF));
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a2-a1);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a2-a1);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                }
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                //regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                //regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                //regFlReset(CF);
                        }else{
                                //regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                //regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        //regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        //regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a2&0x0000000F) < (a1&0x0000000F) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 44:
                        a1=0x00000001;
                        a2=regOut(toReg,w);
                        temp=(a2-a1);
                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        regInF(toReg,w,temp&(w?0x0000FFFF:0x000000FF));
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                //regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                //regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                //regFlReset(CF);
                        }else{
                                //regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                //regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        //regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        //regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( (a2&0x0000000F) < (a1&0x0000000F) ) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 45: //neg
                        a1=0x00000000;
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);
                                //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                temp=(a1-a2);
                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                regInF(fromReg,w,temp&(w?0x0000FFFF:0x000000FF));
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        (a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                        //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        //temp=(a2+a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1-a2);
                                        //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                        //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        //temp=(a2+a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1-a2);
                                        //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                        //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        //temp=(a2+a1)&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1-a2);
                                        //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                        //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        //temp=(a2+a1)&(w?0x0000FFFF:0x000000FF);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1-a2);
                                        //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                        //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        //temp=(a2+a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1-a2);
                                        //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                        //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        //temp=(a2+a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1-a2);
                                                //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                                //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                                //temp=(a2+a1);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1-a2);
                                                //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                                //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                                //temp=(a2+a1);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1-a2);
                                        //(a2!=0x00000000)?(temp=(~a2)):(temp=0x00000000);
                                        //a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        //temp=(a2+a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp&(w?0x0000FFFF:0x000000FF));
                                break;
                                }
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                //regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                //regFlSet(CF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                //regFlReset(CF);
                        }else{
                                //regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                //regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                if((a1&(w?0x00008000:0x00000080))==0x00000000){
                                        //regFlSet(CF);
                                        regFlSet(OF);
                                }else{
                                        //regFlSet(CF);
                                        regFlReset(OF);
                                }
                        }
                        if((a2?0x0000FFFF:0x000000FF)==(unsigned int)(w?0x0000FFFF:0x000000FF)){
                                regFlSet(CF);
                        }else{
                                regFlReset(CF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000  && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if ( ( (a2&0x0000000F) + (a1&0x0000000F) ) > 0x0000000F) {
                                regFlSet(AF);
                        }else{
                                regFlReset(AF);
                        }
                        regShow();
                break;
                case 46: //cmp
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1-a2);

                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1-a2);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1-a2);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1-a2);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1-a2);
                                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1-a2);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        break;

                                }
                        break;
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                                regFlSet(AF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                                regFlReset(AF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else{
                                if((a1&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(AF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlSet(AF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                        //
                break;
                case 47:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if((state&0x00000080)==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a2-a1);
                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a2-a1);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a2-a1);
                                                //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a2-a1);
                                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                                break;
                                }
                        }
                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                                regFlSet(AF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                                regFlReset(AF);
                        }else{
                                regFlSet(CF);
                                regFlSet(AF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(AF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlSet(AF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 && (temp&0x000000FF)!=0 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 48:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a2-a1);
                        //i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);

                        /*if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                                regFlSet(AF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                                regFlReset(AF);
                        }else{
                                regFlSet(CF);
                                regFlSet(AF);
                                regFlSet(OF);
                        }*/
                        if((temp&(w?0x00010000:0x00000100))==0x00000000){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else{
                                if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                        regFlSet(CF);
                                        regFlSet(AF);
                                        regFlSet(OF);
                                }else{
                                        regFlSet(CF);
                                        regFlSet(AF);
                                        regFlReset(OF);
                                }
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 49: //aas
                        a1=regOut(AL,0)&0x0000000F;
                        if(a1>0x00000009 || regFlRead(AF)){
                                a1=(a1-0x00000006)&0x0000000F;
                                regInF(AL,0,a1);
                                regInF(AH,0,(regOut(AH,0)-0x00000001)&0x000000FF);
                                regFlSet(AF);
                                regFlSet(CF);
                        }else if(a1<=9 && !regFlRead(AF)){
                                regInF(AL,0,a1);
                        }
                        regFlRead(AF)?regFlSet(CF):regFlReset(CF);


                        //if(a1>9 && regFlRead(AF)
                        regShow();
                break;
                case 50:  //das
                        a1=0x00000000;
                        a2=regOut(AL,0);
                        if((regOut(AL,0)&0x0000000F)>0x00000009 || regFlRead(AF)){
                                regInF(AL,0,(regOut(AL,0)-0x00000006)&0x000000FF);
                                regFlSet(AF);
                                a1=a1+0x00000006;
                        }else
                                regFlReset(AF);
                        if( (regOut(AL,0)&0x000000F0)>0x00000090 || regFlRead(CF)){
                                regInF(AL,0,(regOut(AL,0)-0x00000060)&0x000000FF);
                                regFlSet(CF);
                                a1=a1+0x00000060;
                        }else
                                regFlReset(CF);
                        temp=(a2-a1)&0x000000FF;
                        i=((temp>>7)&0x00000001)+((a2>>6)&0x00000002)+((a1>>5)&0x00000004);
                        if(i==0x00000000 || i==0x00000005 || i==0x00000003){
                               // regFlReset(CF);
                                regFlReset(OF);
                        }else if(i==0x00000001){
                                regFlSet(OF);
                        }else if(i==0x00000004 || i==0x00000002){
                               // regFlSet(CF);
                        }else{
                               // regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 51:    //mul
                        a1=regOut(AX,w);
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);

                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);

                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);

                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);

                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);

                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);

                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);

                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);

                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);

                                break;
                                }
                        }
                        temp=0;
                        for(i=0;i<(unsigned int)(w?16:8);i++){
                                if((a1&(0x00000001<<i))==(unsigned int)(0x00000001<<i)){
                                        temp=temp+((a2<<i)&((w?0x0000FFFF:0x000000FF)<<i));
                                }
                        }
                        if(w){
                                regIn(DX,1,(temp&0xFFFF0000)>>16);
                                regIn(AX,1,temp&0x0000FFFF);
                        }else{
                                regIn(AX,1,temp&0x0000FFFF);
                        }
                        if( (w?(regOut(DX,1)&0x0000FFFF):(regOut(AH,0)&0x000000FF))==0x00000000){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        regShow();

                break;
                case 52: //imul
                        a1=regOut(AX,w);
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);

                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);

                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);

                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);

                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);

                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);

                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);

                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);

                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);

                                break;
                                }
                        }
                        disp=0;
                        if((a1&(w?0x00008000:0x00000080))!=0){
                                a1=(~a1)&(w?0x0000FFFF:0x00000000FF);
                                disp=disp+1;
                        }
                        if((a2&(w?0x00008000:0x00000080))!=0){
                                a2=(~a2)&(w?0x0000FFFF:0x00000000FF);
                                disp=disp+2;
                        }

                        temp=0;
                        for(i=0;i<(unsigned int)(w?16:8);i++){
                                if((a1&(0x00000001<<i))==(unsigned int)(0x00000001<<i)){
                                        temp=temp+((a2<<i)&((w?0x0000FFFF:0x000000FF)<<i));
                                }
                        }
                        if(disp==1 || disp==2){
                                temp=(~temp)&(w?0xFFFFFFFF:0x0000FFFF);
                        }
                        if(w){
                                regIn(DX,1,(temp&0xFFFF0000)>>16);
                                regIn(AX,1,temp&0x0000FFFF);
                        }else{
                                regIn(AX,1,temp&0x0000FFFF);
                        }
                        if( (w?(regOut(DX,1)&0x0000FFFF):(regOut(AH,0)&0x000000FF))==0x00000000
                        || (w?(regOut(DX,1)&0x0000FFFF):(regOut(AH,0)&0x000000FF))==(w?0x0000FFFF:0x000000FF)){
                                regFlReset(CF);
                                regFlReset(OF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        regShow();
                break;
                case 53:  //aam
                        temp=regOut(AL,0);
                        a1=temp/10;
                        a2=temp%10;
                        regInF(AH,0,a1&0x000000FF);
                        regInF(AL,0,a2&0x000000FF);
                        if((a2&0x00000080)==0x00000080)
                                regFlSet(SF);
                        else
                                regFlReset(SF);
                        if(a2==0x00000000)
                                regFlSet(ZF);
                        else
                                regFlReset(ZF);
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 54: //div
                        a1=(w?(((regOut(DX,w)<<16)&0xFFFF0000)+(regOut(AX,w))):regOut(AX,1));
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);

                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);

                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);

                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);

                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);

                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);

                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);

                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);

                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);

                                break;
                                }
                        }
                        //temp=a1/a2;

                        if(a2!=0){
                                temp=a1/a2;
                                if(temp>(unsigned int)(w?0x0000FFFF:0x000000FF)){
                                        irq=0;
                                        regFlSet(IF);
                                }else{
                                        if(w){
                                                regInF(DX,1,(a1%a2)&0x0000FFFF);
                                                regInF(AX,1,(a1/a2)&0x0000FFFF);
                                        }else{
                                                regInF(AH,0,(a1%a2)&0x000000FF);
                                                regInF(AL,0,(a1/a2)&0x000000FF);
                                        }
                                        regShow();
                                }
                        }
                        else{
                                irq=0;
                                regFlSet(IF);
                        }

                      /*  if(temp>(unsigned int)(w?0x0000FFFF:0x000000FF) || a2==0){
                                //pertraukimas 0
                                irq=0;

                                 //---------------------
                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regFL);
                                regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                                regFlReset(IF);
                                regFlReset(TF);
                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                                regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                                regInF(CS,1,memOut(0x00000000,1));
                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                                regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                                regPC=(memOut(0x00000000,1))&0x0000FFFF;
                                regShow();
                                 //---------------------
                                regFlSet(IF);

                        }else{
                                if(w){
                                        regInF(DX,1,(a1%a2)&0x0000FFFF);
                                        regInF(AX,1,(a1/a2)&0x0000FFFF);
                                }else{
                                        regInF(AH,0,(a1%a2)&0x000000FF);
                                        regInF(AL,0,(a1/a2)&0x000000FF);
                                }
                                regShow();
                        }   */
                break;
                case 55: //idiv
                        a1=(w?(((regOut(DX,w)<<16)&0xFFFF0000)+(regOut(AX,w))):regOut(AX,1));
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);

                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);

                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);

                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);

                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);

                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);

                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);

                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);

                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);

                                break;
                                }
                        }
                        disp=0;
                        if((a1&(w?0x80000000:0x00008000))!=0){
                                a1=(~a1)&(w?0xFFFFFFFF:0x000000FFFF);
                                disp=disp+1;
                        }
                        if((a2&(w?0x00008000:0x00000080))!=0){
                                a2=(~a2)&(w?0x0000FFFF:0x00000000FF);
                                disp=disp+2;
                        }
                        if(a2!=0){
                                temp=a1/a2;
                                if(temp>(unsigned)(w?0x00007FFF:0x0000007F)){
                                        irq=0;
                                        regFlSet(IF);
                                }else{
                                        if(w){
                                                regInF(DX,1,(disp==1 || disp==2)?(~(a1%a2))&0x0000FFFF:(a1%a2)&0x0000FFFF);
                                                regInF(AX,1,(disp==1 || disp==3)?(~(a1/a2))&0x0000FFFF:(a1/a2)&0x0000FFFF);
                                        }else{
                                                regInF(AH,0,(disp==1 || disp==2)?(~(a1%a2))&0x000000FF:(a1%a2)&0x000000FF);
                                                regInF(AL,0,(disp==1 || disp==3)?(~(a1/a2))&0x000000FF:(a1/a2)&0x000000FF);
                                        }
                                        regShow();
                                }
                        }
                        else{
                                irq=0;
                                regFlSet(IF);
                        }
                        /*temp=a1/a2;
                        if(temp>(unsigned)(w?0x00007FFF:0x0000007F) || a2==0){
                                //pertraukimas 0
                                irq=0;
                                //regFlSet(IF);
                        }else{
                                if(w){
                                        regInF(DX,1,(disp==1 || disp==2)?(~(a1%a2))&0x0000FFFF:(a1%a2)&0x0000FFFF);
                                        regInF(AX,1,(disp==1 || disp==3)?(~(a1/a2))&0x0000FFFF:(a1/a2)&0x0000FFFF);
                                }else{
                                        regInF(AH,0,(disp==1 || disp==2)?(~(a1%a2))&0x000000FF:(a1%a2)&0x000000FF);
                                        regInF(AL,0,(disp==1 || disp==3)?(~(a1/a2))&0x000000FF:(a1/a2)&0x000000FF);
                                }
                                regShow();
                        } */
                break;
                case 56: //aad
                        a1=regOut(AL,0);
                        a2=regOut(AH,0);
                        temp=a2*10;
                        a1=a1+temp;
                        regInF(AH,0,0x00000000);
                        regInF(AL,0,a1&0x000000FF);
                        if((a1&0x00000080)==0x00000080)
                                regFlSet(SF);
                        else
                                regFlReset(SF);
                        if(a1==0x00000000)
                                regFlSet(ZF);
                        else
                                regFlReset(ZF);
                        if( (((a1&0x00000001)+((a1&0x00000002)>>1)+((a1&0x00000004)>>2)+((a1&0x00000008)>>3)+
                                ((a1&0x00000010)>>4)+((a1&0x00000020)>>5)+((a1&0x00000040)>>6)+((a1&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 57: //cbw
                        temp=regOut(AL,0);
                        if((temp&0x00000080)!=0)
                                regIn(AH,0,0x000000FF);
                        else
                                regIn(AH,0,0x00000000);
                break;
                case 58: //cwd
                        temp=regOut(AX,1);
                        if((temp&0x00008000)!=0)
                                regIn(DX,1,0x0000FFFF);
                        else
                                regIn(DX,1,0x00000000);
                break;
                case 59:  //not
                        if(state&0x00000080){
                                a2=regOut(fromReg,w);
                                a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                regIn(fromReg,w,a2);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=(~a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                break;
                case 60:  //sal
                        if(state&0x00000080){
                                a1=regOut(fromReg,w);
                                a2=a1;
                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                        a1=a1<<1;
                                        ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                        ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                }

                                /*a2=a1<<(dsv?regOut(CL,0):1);
                                ((a2&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                */

                                regInF(fromReg,w,a2);


                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                a1=a1<<1;
                                                ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                a1=a1<<1;
                                                ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                a1=a1<<1;
                                                ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                a1=a1<<1;
                                                ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                a1=a1<<1;
                                                ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                a1=a1<<1;
                                                ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        a1=a1<<1;
                                                        ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                        ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }

                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        a1=a1<<1;
                                                        ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                        ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                a1=a1<<1;
                                                ((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                        if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(a2==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if(regFlRead(CF)==(w?((a2&0x00008000)>>15):((a2&0x00000080)>>7)))
                                regFlReset(OF);
                        else
                                regFlSet(OF);
                        regShow();
                break;
                case 61:        //shr
                        if(state&0x00000080){
                                a1=regOut(fromReg,w);
                                a2=a1;
                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                        a1=a1>>1;
                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                }

                                /*a2=a1<<(dsv?regOut(CL,0):1);
                                ((a2&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                */

                                regInF(fromReg,w,a2);


                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=a1>>1;
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=a1>>1;
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=a1>>1;
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=a1>>1;
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=a1>>1;
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=a1>>1;
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        a1=a1>>1;
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }

                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        a1=a1<<1;
                                                        //((a1&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x00008000:0x00000080);
                                                }
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=a1>>1;
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                        if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(a2==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if(regFlRead(CF)==(w?((a2&0x00008000)>>15):((a2&0x00000080)>>7)))
                                regFlReset(OF);
                        else
                                regFlSet(OF);
                        regShow();
                break;
                case 62:  //sar
                        if(state&0x00000080){
                                a1=regOut(fromReg,w);
                                a2=a1;
                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                        temp=a1&(w?0x00008000:0x00000080);
                                        a1=a1>>1;
                                        a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                }

                                /*a2=a1<<(dsv?regOut(CL,0):1);
                                ((a2&(w?0x00010000:0x00000100))>>(w?16:8))?regFlSet(CF):regFlReset(CF);
                                ((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                */

                                regInF(fromReg,w,a2);


                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=a1&(w?0x00008000:0x00000080);
                                                a1=a1>>1;
                                                a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=a1&(w?0x00008000:0x00000080);
                                                a1=a1>>1;
                                                a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=a1&(w?0x00008000:0x00000080);
                                                a1=a1>>1;
                                                a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=a1&(w?0x00008000:0x00000080);
                                                a1=a1>>1;
                                                a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=a1&(w?0x00008000:0x00000080);
                                                a1=a1>>1;
                                                a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=a1&(w?0x00008000:0x00000080);
                                                a1=a1>>1;
                                                a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        temp=a1&(w?0x00008000:0x00000080);
                                                        a1=a1>>1;
                                                        a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }

                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        temp=a1&(w?0x00008000:0x00000080);
                                                        a1=a1>>1;
                                                        a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=a1&(w?0x00008000:0x00000080);
                                                a1=a1>>1;
                                                a1=(a1&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                        if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(a2==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if(regFlRead(CF)==(w?((a2&0x00008000)>>15):((a2&0x00000080)>>7)))
                                regFlReset(OF);
                        else
                                regFlSet(OF);
                        regShow();
                break;
                case 63:   //rol
                        if(state&0x00000080){
                                a1=regOut(fromReg,w);
                                a2=a1;
                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                        ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                        temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                        a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                }
                                regIn(fromReg,w,a2);


                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                        a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }

                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                        a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=(a1&(w?0x00008000:0x00000080))>>(w?15:7);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                        if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(a2==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if(regFlRead(CF)==(w?((a2&0x00008000)>>15):((a2&0x00000080)>>7)))
                                regFlReset(OF);
                        else
                                regFlSet(OF);
                        regShow();


                break;
                case 64:  //ror
                        if(state&0x00000080){
                                a1=regOut(fromReg,w);
                                a2=a1;
                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                        temp=((a1&0x00000001)<<(w?15:7));
                                        a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                }
                                regIn(fromReg,w,a2);


                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=((a1&0x00000001)<<(w?15:7));
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                         for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=((a1&0x00000001)<<(w?15:7));
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                         for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=((a1&0x00000001)<<(w?15:7));
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=((a1&0x00000001)<<(w?15:7));
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=((a1&0x00000001)<<(w?15:7));
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=((a1&0x00000001)<<(w?15:7));
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        temp=((a1&0x00000001)<<(w?15:7));
                                                        a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }

                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        temp=((a1&0x00000001)<<(w?15:7));
                                                        a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                (a1&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                temp=((a1&0x00000001)<<(w?15:7));
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                        if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(a2==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if(regFlRead(CF)==(w?((a2&0x00008000)>>15):((a2&0x00000080)>>7)))
                                regFlReset(OF);
                        else
                                regFlSet(OF);
                        regShow();
                break;
                case 65:    //rcl
                        if(state&0x00000080){
                                a1=regOut(fromReg,w);
                                a2=a1;
                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                        temp=regFlRead(CF);
                                        ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                        a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                }
                                regIn(fromReg,w,a2);


                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=regFlRead(CF);
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=regFlRead(CF);
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=regFlRead(CF);
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=regFlRead(CF);
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=regFlRead(CF);
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=regFlRead(CF);
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        temp=regFlRead(CF);
                                                        ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }

                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        temp=regFlRead(CF);
                                                        ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                        a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=regFlRead(CF);
                                                ((a1>>(w?15:7))&0x00000001)?regFlSet(CF):regFlReset(CF);
                                                a1=((a1<<1)&(w?0x0000FFFE:0x000000FE))+(temp&0x00000001);
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                        if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(a2==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if(regFlRead(CF)==(w?((a2&0x00008000)>>15):((a2&0x00000080)>>7)))
                                regFlReset(OF);
                        else
                                regFlSet(OF);
                        regShow();
                break;
                case 66:  //rcr
                        if(state&0x00000080){
                                a1=regOut(fromReg,w);
                                a2=a1;
                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                        temp=(regFlRead(CF))<<(w?15:7);
                                        ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                        a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                }
                                regIn(fromReg,w,a2);


                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=(regFlRead(CF))<<(w?15:7);
                                                ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=(regFlRead(CF))<<(w?15:7);
                                                ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                         for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=(regFlRead(CF))<<(w?15:7);
                                                ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=(regFlRead(CF))<<(w?15:7);
                                                ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=(regFlRead(CF))<<(w?15:7);
                                                ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,a2);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=(regFlRead(CF))<<(w?15:7);
                                                ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,a2);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);

                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        temp=(regFlRead(CF))<<(w?15:7);
                                                        ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                        a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }

                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                a2=a1;
                                                for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                        temp=(regFlRead(CF))<<(w?15:7);
                                                        ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                        a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                        //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                        a2=a1&(w?0x0000FFFF:0x000000FF);
                                                }
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,a2);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        a2=a1;
                                        for(i=0;i<(dsv?regOut(CL,0):1);i++){
                                                temp=(regFlRead(CF))<<(w?15:7);
                                                ((a1&(w?0x00008000:0x00000080))>>(w?15:7))?regFlSet(CF):regFlReset(CF);
                                                a1=((a1>>1)&(w?0x00007FFF:0x0000007F))+(temp&(w?0x00008000:0x00000080));
                                                //((a1&(w?0x00008000:0x00000080))==(a2&(w?0x00008000:0x00000080)))?regFlSet(OF):regFlReset(OF);
                                                a2=a1&(w?0x0000FFFF:0x000000FF);
                                        }
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,a2);

                                break;
                                }
                        }
                        if((a2&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(a2==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((a2&0x00000001)+((a2&0x00000002)>>1)+((a2&0x00000004)>>2)+((a2&0x00000008)>>3)+
                                ((a2&0x00000010)>>4)+((a2&0x00000020)>>5)+((a2&0x00000040)>>6)+((a2&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        if(regFlRead(CF)==(w?((a2&0x00008000)>>15):((a2&0x00000080)>>7)))
                                regFlReset(OF);
                        else
                                regFlSet(OF);
                        regShow();
                break;
                case 67:
                        //  and
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                regInF(toReg,w,temp);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                        regInF(toReg,w,temp);
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                        regInF(toReg,w,temp);
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                        memIn((regSegOut(DS)<<4)+disp,w,temp);
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                        break;

                                }
                        break;
                        }
                                regFlReset(CF);
                                regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                        //
                break;
                case 68:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if((state&0x00000080)==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                regInF(fromReg,w,temp);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp);
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                break;
                                }
                        }
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 69:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                        regInF(AX,w,temp);
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 70:
                        //  test
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        break;

                                }
                        break;
                        }
                                regFlReset(CF);
                                regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                        //
                break;
                case 71:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if(state&0x00000080==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                                break;
                                }
                        }
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 72:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a1&a2)&(w?0x0000FFFF:0x000000FF);
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 73:
                        //  or
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                regInF(toReg,w,temp);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                        regInF(toReg,w,temp);
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                        regInF(toReg,w,temp);
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                        memIn((regSegOut(DS)<<4)+disp,w,temp);
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                        break;

                                }
                        break;
                        }
                                regFlReset(CF);
                                regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                        //
                break;
                case 74:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if(state&0x00000080==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                regInF(toReg,w,temp);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp);
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                break;
                                }
                        }
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 75:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a1|a2)&(w?0x0000FFFF:0x000000FF);
                        regInF(AX,w,temp);
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 76:
                        //  xor
                        switch(state&0x000000F0){

                        case 0x000000C0:
                                a1=regOut(toReg,w);
                                a2=regOut(fromReg,w);
                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                regInF(toReg,w,temp);
                        break;
                        case 0x00000060:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                        case 0:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 1:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 2:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 3:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 4:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 5:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                        regInF(toReg,w,temp);
                                                }else{
                                                        a1=regOut(toReg,w);
                                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                        regInF(toReg,w,temp);
                                                }
                                        break;
                                        case 7:
                                                a1=regOut(toReg,w);
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                regInF(toReg,w,temp);
                                        break;

                                }
                        break;
                        case 0x00000090:
                                //int disp=0;
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(toMem){
                                        case 0:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 1:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 2:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 3:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 4:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                        break;
                                        case 5:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                        break;
                                        case 6:
                                                if(mod==0x00000000){
                                                        a1=memOut((regSegOut(DS)<<4)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                        memIn((regSegOut(DS)<<4)+disp,w,temp);
                                                }else{
                                                        a1=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                        a2=regOut(fromReg,w);
                                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                                }

                                        break;
                                        case 7:
                                                a1=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                                a2=regOut(fromReg,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                        break;

                                }
                        break;
                        }
                                regFlReset(CF);
                                regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                        //
                break;
                case 77:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        if(state&0x00000080==0x00000080){
                                a2=regOut(fromReg,w);
                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                regInF(toReg,w,temp);
                        }else{
                                if ((state&0x00000003)==0x00000002){
                                        if((disp8&0x00000080)==0x00000080){
                                                disp=(disp8|0x0000FF00);
                                        }else{
                                                disp=disp8;
                                        }
                                }else if((state&0x00000003)==0x00000003){
                                        disp=(disp16<<8)+disp8;
                                }
                                switch(fromMem){
                                case 0:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 1:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 2:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 3:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 4:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(SI,1)+disp,w,temp);
                                break;
                                case 5:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(DI,1)+disp,w,temp);
                                break;
                                case 6:
                                        if(mod==0x00000000){
                                                a2=memOut((regSegOut(DS)<<4)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+disp,w,temp);
                                        }else{
                                                a2=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                                temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                                memIn((regSegOut(DS)<<4)+regOut(BP,1)+disp,w,temp);
                                        }
                                break;
                                case 7:
                                        a2=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                                        memIn((regSegOut(DS)<<4)+regOut(BX,1)+disp,w,temp);
                                break;
                                }
                        }
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 78:
                        a1=w?(((data16<<8)&0x0000FF00)+(data8&0x000000FF)):(data8&0x000000FF);
                        a2=regOut(AX,w);
                        temp=(a1^a2)&(w?0x0000FFFF:0x000000FF);
                        regInF(AX,w,temp);
                        regFlReset(CF);
                        regFlReset(OF);
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regShow();
                break;
                case 79:  //rep's
                        switch(mod){
                        case 1:
                                for(i=regOut(CX,1);i>0;i--){
                                        memIn((regOut(ES,1)<<4)+regOut(DI,1),w,memOut((regOut(DS,1)<<4)+regOut(SI,1),w));
                                        regInF(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                                        regInF(SI,1,(regFlRead(DF)?(regOut(SI,1)-(w?1:2)):(regOut(SI,1)+(w?1:2))));
                                        regIn(CX,1,i);
                                }
                        break;
                        case 2:
                                for(disp=regOut(CX,1);(disp>0 && (dsv?regFlRead(ZF):!regFlRead(ZF)) );disp--){
                                        a1=memOut((regOut(DS,1)<<4)+regOut(SI,1),w);
                                        a2=memOut((regOut(ES,1)<<4)+regOut(DI,1),w);
                                        temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                                regFlReset(CF);
                                                regFlReset(AF);
                                                regFlReset(OF);
                                        }else if(i==0x00000005){
                                                regFlSet(OF);
                                                regFlSet(CF);
                                                regFlSet(AF);
                                        }else if(i==0x00000004 || i==0x00000002){
                                                regFlSet(OF);
                                                regFlReset(CF);
                                                regFlReset(AF);
                                        }else{
                                                regFlSet(CF);
                                                regFlSet(OF);
                                        }
                                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                                regFlReset(SF);
                                        }else{
                                                regFlSet(SF);
                                        }
                                        if(temp==0){
                                                regFlSet(ZF);
                                        }else{
                                                regFlReset(ZF);
                                        }
                                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                                regFlSet(PF);
                                        }else{
                                                regFlReset(PF);
                                        }
                                        regInF(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                                        regInF(SI,1,(regFlRead(DF)?(regOut(SI,1)-(w?1:2)):(regOut(SI,1)+(w?1:2))));
                                        regIn(CX,1,disp);
                                }
                        break;
                        case 3:
                                a1=regOut(AX,w);
                                for(disp=regOut(CX,1);(disp>0 && (dsv?regFlRead(ZF):!regFlRead(ZF)) );disp--){
                                        a2=memOut((regOut(ES,1)<<4)+regOut(DI,1),w);
                                        temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                                        i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                                        if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                                regFlReset(CF);
                                                regFlReset(AF);
                                                regFlReset(OF);
                                        }else if(i==0x00000005){
                                                regFlSet(OF);
                                                regFlSet(CF);
                                                regFlSet(AF);
                                        }else if(i==0x00000004 || i==0x00000002){
                                                regFlSet(OF);
                                                regFlReset(CF);
                                                regFlReset(AF);
                                        }else{
                                                regFlSet(CF);
                                                regFlSet(OF);
                                        }
                                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                                regFlReset(SF);
                                        }else{
                                                regFlSet(SF);
                                        }
                                        if(temp==0){
                                                regFlSet(ZF);
                                        }else{
                                                regFlReset(ZF);
                                        }
                                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                                regFlSet(PF);
                                        }else{
                                                regFlReset(PF);
                                        }
                                        regInF(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                                        regInF(SI,1,(regFlRead(DF)?(regOut(SI,1)-(w?1:2)):(regOut(SI,1)+(w?1:2))));
                                        regIn(CX,1,disp);
                                }
                        break;
                        case 4:
                                a1=regOut(AX,w);
                                for(i=regOut(CX,1);i>0;i--){
                                        memIn((regOut(ES,1)<<4)+regOut(DI,1),w,a1);
                                        regInF(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                                        regIn(CX,1,i);
                                }
                        break;
                        }
                break;
                case 80: //movs
                        memIn((regOut(ES,1)<<4)+regOut(DI,1),w,memOut((regOut(DS,1)<<4)+regOut(SI,1),w));
                        regInF(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                        regIn(SI,1,(regFlRead(DF)?(regOut(SI,1)-(w?1:2)):(regOut(SI,1)+(w?1:2))));
                break;
                case 81: //cmps
                        a1=memOut((regOut(DS,1)<<4)+regOut(SI,1),w);
                        a2=memOut((regOut(ES,1)<<4)+regOut(DI,1),w);
                        temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                        i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                                regFlSet(AF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                                regFlReset(AF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regInF(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                        regIn(SI,1,(regFlRead(DF)?(regOut(SI,1)-(w?1:2)):(regOut(SI,1)+(w?1:2))));
                break;
                case 82:  //scas
                        a1=regOut(AX,w);
                        a2=memOut((regOut(ES,1)<<4)+regOut(DI,1),w);
                        temp=(a2-a1)&(w?0x0000FFFF:0x000000FF);
                        i=((temp>>(w?15:7))&0x00000001)+((a2>>(w?14:6))&0x00000002)+((a1>>(w?13:5))&0x00000004);
                        if(i==0x00000000 || i==0x00000006 || i==0x00000001){
                                regFlReset(CF);
                                regFlReset(AF);
                                regFlReset(OF);
                        }else if(i==0x00000005){
                                regFlSet(OF);
                                regFlSet(CF);
                                regFlSet(AF);
                        }else if(i==0x00000004 || i==0x00000002){
                                regFlSet(OF);
                                regFlReset(CF);
                                regFlReset(AF);
                        }else{
                                regFlSet(CF);
                                regFlSet(OF);
                        }
                        if((temp&(w?0x00008000:0x00000080))==0x00000000){
                                regFlReset(SF);
                        }else{
                                regFlSet(SF);
                        }
                        if(temp==0){
                                regFlSet(ZF);
                        }else{
                                regFlReset(ZF);
                        }
                        if( (((temp&0x00000001)+((temp&0x00000002)>>1)+((temp&0x00000004)>>2)+((temp&0x00000008)>>3)+
                                ((temp&0x00000010)>>4)+((temp&0x00000020)>>5)+((temp&0x00000040)>>6)+((temp&0x00000080)>>7))&0x00000001)==0x00000000 ){
                                regFlSet(PF);
                        }else{
                                regFlReset(PF);
                        }
                        regInF(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                        regIn(SI,1,(regFlRead(DF)?(regOut(SI,1)-(w?1:2)):(regOut(SI,1)+(w?1:2))));
                break;
                case 83: //lods
                        regInF(AX,w,memOut((regOut(DS,1)<<4)+regOut(SI,1),w));
                        regIn(SI,1,(regFlRead(DF)?(regOut(SI,1)-(w?1:2)):(regOut(SI,1)+(w?1:2))));
                break;
                case 84: //stos
                        memIn((regOut(ES,1)<<4)+regOut(DI,1),w,regOut(AX,w));
                        regIn(DI,1,(regFlRead(DF)?(regOut(DI,1)-(w?1:2)):(regOut(DI,1)+(w?1:2))));
                break;
                case 85: //call
                        regInF(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                        regPC=((regPC-length)+(disp16<<8+disp8))&0x0000FFFF;
                        regShow();
                break;
                case 86:
                        regInF(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);

                        if ((state&0x00000003)==0x00000002){
                                if((disp8&0x00000080)==0x00000080){
                                        disp=(disp8|0x0000FF00);
                                }else{
                                        disp=disp8;
                                }
                        }else if((state&0x00000003)==0x00000003){
                                disp=(disp16<<8)+disp8;
                        }
                        switch(fromMem){
                        case 0:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 1:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 2:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 3:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 4:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 5:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 6:
                                if(mod==0x00000000){
                                        regPC=(memOut((regSegOut(DS)<<4)+disp,w))&0x0000FFFF;
                                }else{
                                        regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w))&0x0000FFFF;
                                }
                        break;
                        case 7:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w))&0x0000FFFF;
                        break;
                        }
                        regShow();
                break;
                case 87:
                        regInF(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                        regInF(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                        regPC=(disp16<<8+disp8);
                        regSegIn(CS,(data16<<8+data8));
                break;
                case 88:
                        regInF(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                        regInF(SP,1,regOut(SP,1)-2);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                        if ((state&0x00000003)==0x00000002){
                                if((disp8&0x00000080)==0x00000080){
                                        disp=(disp8|0x0000FF00);
                                }else{
                                        disp=disp8;
                                }
                        }else if((state&0x00000003)==0x00000003){
                                disp=(disp16<<8)+disp8;
                        }
                        switch(fromMem){
                        case 0:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w))&0x0000FFFF;
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp+2,w));
                        break;
                        case 1:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w))&0x0000FFFF;
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp+2,w));
                        break;
                        case 2:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w))&0x0000FFFF;
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp+2,w));
                        break;
                        case 3:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w))&0x0000FFFF;
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp+2,w));
                        break;
                        case 4:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w))&0x0000FFFF;
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp+2,w));
                        break;
                        case 5:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w))&0x0000FFFF;
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp+2,w));
                        break;
                        case 6:
                                if(mod==0x00000000){
                                        regPC=(memOut((regSegOut(DS)<<4)+disp,w))&0x0000FFFF;
                                        regSegIn(CS,memOut((regSegOut(DS)<<4)+disp+2,w));
                                }else{
                                        regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w))&0x0000FFFF;
                                        regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp+2,w));
                                }
                        break;
                        case 7:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w))&0x0000FFFF;
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp+2,w));
                        break;
                        }
                break;
                //jmp
                case 89:  regPC=(((regPC-length)+((disp16<<8)+disp8))&0x0000FFFF);
                        regShow();

                break;
                case 90:
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        regPC=(((regPC-length)+disp)&0x0000FFFF);
                        regShow();
                break;
                case 91:
                        if ((state&0x00000003)==0x00000002){
                                if((disp8&0x00000080)==0x00000080){
                                        disp=(disp8|0x0000FF00);
                                }else{
                                        disp=disp8;
                                }
                        }else if((state&0x00000003)==0x00000003){
                                disp=(disp16<<8)+disp8;
                        }
                        switch(fromMem){
                        case 0:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 1:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 2:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 3:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 4:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 5:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w))&0x0000FFFF;
                        break;
                        case 6:
                                if(mod==0x00000000){
                                        regPC=(memOut((regSegOut(DS)<<4)+disp,w))&0x0000FFFF;
                                }else{
                                        regPC=(memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w))&0x0000FFFF;
                                }
                        break;
                        case 7:
                                regPC=(memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w))&0x0000FFFF;
                        break;
                        }
                        regShow();
                break;
                case 92:
                        //regIn(SP,1,regOut(SP,1)-2);
                        //memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                        //regIn(SP,1,regOut(SP,1)-2);
                        //memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                        regPC=(disp16<<8+disp8);
                        regSegIn(CS,(data16<<8+data8));
                break;
                case 93:
                        //regIn(SP,1,regOut(SP,1)-2);
                        //memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                        //regIn(SP,1,regOut(SP,1)-2);
                        //memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                        if ((state&0x00000003)==0x00000002){
                                if((disp8&0x00000080)==0x00000080){
                                        disp=(disp8|0x0000FF00);
                                }else{
                                        disp=disp8;
                                }
                        }else if((state&0x00000003)==0x00000003){
                                disp=(disp16<<8)+disp8;
                        }
                        switch(fromMem){
                        case 0:
                                regPC=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp,w);
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(SI,1)+disp+2,w));
                        break;
                        case 1:
                                regPC=memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp,w);
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BX,1)+regOut(DI,1)+disp+2,w));
                        break;
                        case 2:
                                regPC=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp,w);
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(SI,1)+disp+2,w));
                        break;
                        case 3:
                                regPC=memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp,w);
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BP,1)+regOut(DI,1)+disp+2,w));
                        break;
                        case 4:
                                regPC=memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp,w);
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(SI,1)+disp+2,w));
                        break;
                        case 5:
                                regPC=memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp,w);
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(DI,1)+disp+2,w));
                        break;
                        case 6:
                                if(mod==0x00000000){
                                        regPC=memOut((regSegOut(DS)<<4)+disp,w);
                                        regSegIn(CS,memOut((regSegOut(DS)<<4)+disp+2,w));
                                }else{
                                        regPC=memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp,w);
                                        regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BP,1)+disp+2,w));
                                }
                        break;
                        case 7:
                                regPC=memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp,w);
                                regSegIn(CS,memOut((regSegOut(DS)<<4)+regOut(BX,1)+disp+2,w));
                        break;
                        }
                break;
                case 94:
                        regPC=(memOut((regSegOut(CS)<<4)+regOut(SP,1),w))&0x0000FFFF;
                        regIn(SP,w,(regOut(SP,w)+2)&0x0000FFFF);
                break;
                case 95:
                        regPC=(memOut((regSegOut(CS)<<4)+regOut(SP,1),w))&0x0000FFFF;
                        regIn(SP,w,(regOut(SP,w)+2+(data16<<8)+data8)&0x0000FFFF);
                break;
                case 96:
                        regPC=(memOut((regSegOut(CS)<<4)+regOut(SP,1),w))&0x0000FFFF;
                        regInF(SP,w,(regOut(SP,w)+2)&0x0000FFFF);
                        regInF(CS,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        regIn(SP,w,(regOut(SP,w)+2)&0x0000FFFF);
                break;
                case 97:
                        regPC=(memOut((regSegOut(CS)<<4)+regOut(SP,1),w))&0x0000FFFF;
                        regInF(SP,w,(regOut(SP,w)+2)&0x0000FFFF);
                        regInF(CS,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        regIn(SP,w,(regOut(SP,w)+2+(data16<<8)+data8)&0x0000FFFF);
                break;
                case 98:  //jz
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        regFlRead(ZF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 99:  //jl
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        ((!regFlRead(OF) && regFlRead(SF)) || (regFlRead(OF) && !regFlRead(SF)))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 100:  //jle
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        ((regFlRead(OF) && regFlRead(ZF) && !regFlRead(SF)) || (regFlRead(OF) && !regFlRead(ZF) && regFlRead(SF)))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 101:  //jb
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        regFlRead(CF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 102:  //jbe
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        (regFlRead(ZF) || regFlRead(ZF))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 103:  //jp
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        regFlRead(PF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 104:  //jo
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        regFlRead(OF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 105:  //js
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        regFlRead(SF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 106:   //jne
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        !regFlRead(ZF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 107:  //jnl
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        ((regFlRead(OF) && regFlRead(SF)) || (!regFlRead(OF) && !regFlRead(SF)))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 108: //jnle
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        ((!regFlRead(OF) && !regFlRead(ZF) && !regFlRead(SF)) || (!regFlRead(OF) && regFlRead(ZF) && !regFlRead(SF)))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 109:  //jnb
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                         !regFlRead(CF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                         regShow();
                break;
                case 110: //jnbe
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        (!regFlRead(CF) && !regFlRead(ZF))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 111: //jnp
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        !regFlRead(PF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 112: //jno
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        !regFlRead(OF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 113: //jns
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        !regFlRead(SF)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 114: //loop
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0xFFFFFF00);
                        }else{
                                disp=disp8;
                        }
                        a1=regOut(CX,w);
                        regInF(CX,w, (a1-1)&0x0000FFFF);
                        (a1!=0)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 115: //loopz
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        a1=regOut(CX,w);
                        regInF(CX,w, (a1-1)&0x0000FFFF);
                        ((a1!=0) && regFlRead(ZF))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 116: //loopnz
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        a1=regOut(CX,w);
                        regInF(CX,w, (a1-1)&0x0000FFFF);
                        ((a1!=0) && !regFlRead(ZF))?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 117: //jcxz
                        if((disp8&0x00000080)==0x00000080){
                                disp=(disp8|0x0000FF00);
                        }else{
                                disp=disp8;
                        }
                        a1=regOut(CX,w);
                        (a1==0)?(regPC=(((regPC-length)+disp)&0x0000FFFF)):true;
                        regShow();
                break;
                case 118: //int
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regFL);
                        regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                        regFlReset(IF);
                        regFlReset(TF);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                        regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                        regInF(CS,1,memOut((disp<<2)+2,1));
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                        regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                        regPC=(memOut((disp<<2),1))&0x0000FFFF;
                        regShow();
                break;
                case 119:   //int 3
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regFL);
                        regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                        regFlReset(IF);
                        regFlReset(TF);
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                        regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                        regInF(CS,1,memOut((3<<2)+2,1));
                        memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                        regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                        regPC=(memOut((3<<2),1))&0x0000FFFF;
                        regShow();
                break;
                case 120: //into
                        if(regFlRead(OF)){
                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regFL);
                                regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                                regFlReset(IF);
                                regFlReset(TF);
                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                                regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                                regInF(CS,1,memOut((4<<2)+2,1));
                                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                                regInF(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                                regPC=(memOut((4<<2),1))&0x0000FFFF;
                                regShow();
                        }
                break;
                case 121: //iret

                        //regPC=memory[(regSegOut(SS)<<4)+regOut(SP,1)+1]+(memory[(regSegOut(SS)<<4)+regOut(SP,1)]<<8);
                        regPC=memOut((regSegOut(SS)<<4)+regOut(SP,1),1);
                        regInF(SP,1,(regOut(SP,1)+2)&0x0000FFFF);
                        regInF(CS,1,memOut((regSegOut(SS)<<4)+regOut(SP,1),1));
                        //regInF(CS,1,memory[(regSegOut(SS)<<4)+regOut(SP,1)+1]+(memory[(regSegOut(SS)<<4)+regOut(SP,1)]<<8));
                        regInF(SP,1,(regOut(SP,1)+2)&0x0000FFFF);
                        regFL=memOut((regSegOut(SS)<<4)+regOut(SP,1),1);
                        //regFL=memory[(regSegOut(SS)<<4)+regOut(SP,1)+1]+(memory[(regSegOut(SS)<<4)+regOut(SP,1)]<<8);
                        regIn(SP,1,(regOut(SP,1)+2)&0x0000FFFF);

                        kodDecompile();
                        kodShow();
                        regShow();
                break;
                case 122: //clc
                        regFlReset(CF);
                        regShow();
                break;
                case 123: //cmc
                        regFlRead(CF)?regFlReset(CF):regFlSet(CF);
                        regShow();
                break;
                case 124: //stc
                        regFlSet(CF);
                        regShow();
                break;
                case 125: //cld
                        regFlReset(DF);
                        regShow();
                break;
                case 126: //std
                        regFlSet(DF);
                        regShow();
                break;
                case 127: //cli
                        regFlReset(IF);
                        regShow();
                break;
                case 128: //sti
                        regFlSet(IF);
                        regShow();
                break;
                case 129: //hlt
                        Timer1->Enabled=false;
                break;
                case 130: //wait

                break;
                case 131: //esc

                break;
                case 132: //lock

                break;
        }
        if(memchg){
                kodDecompile();
                kodShow();
                memchg=false;
        }
}

//---------------------------------------------------------------------------

void TForm1::simClear(){
        fromReg=0;
        toReg=0;
        fromMem=0;
        toMem=0;
        mnemonic=0;
        mod=0;
        rm=0;
        reg=0;
        data8=0;
        data16=0;
        disp8=0;
        disp16=0;
        state=0;
        length=0;
        dsv=0;
        w=0;

        Mnemonic="";
}

//---------------------------------------------------------------------------

void TForm1::ikrauti(AnsiString FailoVardas){
        simReset();
        TStringList *Failas;
        Failas = new TStringList;
        Failas->LoadFromFile(FailoVardas);
        bool error=false;
        if(Failas->Strings[0]=="[!8086SIMULATORCOMPILEDFILE!]"){
                for(int i=1;i<Failas->Count;i++){
                        if(Failas->Strings[i].SubString(0,7)=="[CODE -"){
                                //Form3->IrasytiCS((unsigned int)StrToInt("0x"+Failas->Strings[i].SubString(8,4)));
                                if(StrToIntDef("0x"+Failas->Strings[i].SubString(8,4),-1)>=0)
                                        regSegIn(CS, (unsigned int)StrToInt("0x"+Failas->Strings[i].SubString(8,4)) );
                                else
                                        error=true;
                        }
                        else if(Failas->Strings[i].SubString(0,7)=="[DATA -"){
                                //Form3->IrasytiDS(StrToInt("0x"+Failas->Strings[i].SubString(8,4)));
                                if(StrToIntDef("0x"+Failas->Strings[i].SubString(8,4),-1)>=0)
                                        regSegIn(DS, (unsigned int)StrToInt("0x"+Failas->Strings[i].SubString(8,4)) );
                                else
                                        error=true;
                        }
                        else if(Failas->Strings[i].SubString(0,7)=="[STACK-"){
                                //Form3->IrasytiSS(StrToInt("0x"+Failas->Strings[i].SubString(8,4)));
                                if(StrToIntDef("0x"+Failas->Strings[i].SubString(8,4),-1)>=0)
                                        regSegIn(SS, (unsigned int)StrToInt("0x"+Failas->Strings[i].SubString(8,4)) );
                                else
                                        error=true;
                        }
                        else if(Failas->Strings[i].SubString(0,7)=="[EXTRA-"){
                                //Form3->IrasytiES(StrToInt("0x"+Failas->Strings[i].SubString(8,4)));
                                if(StrToIntDef("0x"+Failas->Strings[i].SubString(8,4),-1)>=0)
                                        regSegIn(ES, (unsigned int)StrToInt("0x"+Failas->Strings[i].SubString(8,4)) );
                                else
                                        error=true;
                        }
                        else{
                                int start,end,count;
                                if(StrToIntDef("0x"+Failas->Strings[i].SubString(2,5),-1)>=0 &&
                                StrToIntDef("0x"+Failas->Strings[i].SubString(8,5),-1)>=0){
                                        start=StrToInt("0x"+Failas->Strings[i].SubString(2,5));
                                        end=StrToInt("0x"+Failas->Strings[i].SubString(8,5));
                                        count=end-start+1;
                                //Form4->PridetiEilute(Failas->Strings[i],start,count);
                                        for(int j=0;j<count;j++){
                                        //Form2->IrasytiBaita(start+j,(unsigned char)StrToInt("0x"+Failas->Strings[i].SubString(15+(j*3),2)));
                                        //memIn(start+j,0, (unsigned char)StrToInt("0x"+Failas->Strings[i].SubString(15+(j*3),2)) );
                                                if(StrToIntDef("0x"+Failas->Strings[i].SubString(15+(j*3),2),-1)>=0)
                                                        memory[start+j]=(unsigned char)StrToInt("0x"+Failas->Strings[i].SubString(15+(j*3),2));
                                                else
                                                        error=true;
                                        }
                                }
                        }
                }

                //regIn(SP,1,0x0000FFFF);
                //kodShow();
        }
        else
                error=true;
        if(error==false){
                regIn(SP,1,0x0000FFFF);
                kodDecompile();
                kodShow();
                memShow();
                kodBPReset();
                kodBPRefresh();
        }else
                ShowMessage("klaida atidarant faila");
        
}

void __fastcall TForm1::aScrollChange(TObject *Sender)
{
        memShow();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button84Click(TObject *Sender)
{

     /*
        //regIn(AL,0,12);
        //memIn8(0,0x0000008A);
        //memIn8(1,0x0000008A);
        memIn8(2,0x00000004);
        memIn8(3,0x00000000);
        memIn8(4,0x00000005);
        simReadCommand(0);
        Edit1->Text=IntToStr(bytecode[0]);
        simDecode();
        simStep();

     */
        //Edit1->Text=IntToStr(0x00000088&0x000000FC);


        /*for(int i=0x010000;i<0x01FA00;i++){
                memIn8(i,i&0x0000FF);
        }
       */
        vidRefresh();

        /*for(int i=1;i<320;i++){
                for(int j=1;j<200;j++)
                vidGrfDrawPixel(i,j,255);//StrToInt(Edit1->Text));
        }
          */
    /*  for(int i=0;i<40;i++)
        for(int j=0;j<25;j++)
                vidTxtDrawSimbol(i,j,IntToStr(i%10).c_str()[0]);
      */
}
//---------------------------------------------------------------------------


void __fastcall TForm1::pScrollChange(TObject *Sender)
{
        portShow();
}

//---------------------------------------------------------------------------
void TForm1::kodShow(){
        unsigned int i=0;
        unsigned int temp;
        temp=kScroll->Position;
        for(i=0;i<14;i++){
                if((temp+i)==regPC){
                        //if(bP[temp+i])
                        //        kAdresas[i]->Color=clRed;
                        //else
                                kAdresas[i]->Color=clLime;
                        kBaitKodas[i]->Color=clLime;
                        kKomanda[i]->Color=clLime;
                }else{
                        //if(bP[temp+i])
                        //        kAdresas[i]->Color=clRed;
                        //else
                                kAdresas[i]->Color=clBtnFace;
                        kBaitKodas[i]->Color=clBtnFace;
                        kKomanda[i]->Color=clBtnFace;
                }
                kAdresas[i]->Caption=IntToHex((int)(((regSegOut(CS)<<4)+temp+i)&0x000FFFFF),5);
                kBaitKodas[i]->Caption=IntToHex( (int)memOut((regSegOut(CS)<<4)+temp+i,0),2);
                kKomanda[i]->Caption=kodKodas->Strings[temp+i];

        }
        kodBPRefresh();
}

void TForm1::kodDecompile(){
        unsigned int i=0;
        for(i=0;i<=0x0000FFFF;){
                simReadCommand((regSegOut(CS)<<4)+i);
                if(i==0){
                //Edit1->Text=IntToHex((int)bytecode[0],4);
                }
                simDecode();

                kodKodas->Strings[i]=Mnemonic;
                if(length>1){
                        for(int j=1;j<length;j++){
                                if(i+j<=0x0000FFFF)
                                kodKodas->Strings[i+j]="";
                        }
                }
                i=i+length;
        }

}

void TForm1::kodAddBP(unsigned int point){
        unsigned int i;
        i=kScroll->Position+point;
        if(bP[i])
                bP[i]=false;
        else
                bP[i]=true;
        kodShow();
}
void TForm1::kodBPRefresh(){
for(int i=0;i<14;i++){
                if(bP[kScroll->Position+i]){
                        Br->Canvas->Pen->Color=clBlack;
                        Br->Canvas->Brush->Color=clRed;
                        Br->Canvas->Ellipse(0,i*16,16,i*16+16);
                }else{
                        Br->Canvas->Pen->Color=clBlack;
                        Br->Canvas->Brush->Color=clBtnFace;
                        Br->Canvas->Ellipse(0,i*16,16,i*16+16);
                }
        }
}
void TForm1::kodBPReset(){
        for(int i=0;i<0x0000FFFF;i++){
                bP[i]=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button85Click(TObject *Sender)
{
        memReset();
        regShow();
        ikrauti("test.o.emt");
        kodDecompile();
        kodShow();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::kScrollChange(TObject *Sender)
{
        kodShow();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
        StaticText5->Color=clGreen;
        StaticText5->Caption="[ VYKDYMAS ]";
        if(bP[regPC&0x0000FFFF])
                Timer1->Enabled=false;
        else if(!regFlRead(IF) || (regFlRead(IF) && !interrupt)){
                simReadCommand(((regSegOut(CS)<<4)+regPC)&0x000FFFFF);
                //Edit1->Text=IntToHex((int)bytecode[0],2)+" "+IntToHex((int)bytecode[1],2)+" "+IntToHex((int)bytecode[2],2)+" "+IntToHex((int)bytecode[3],2)+" "+IntToHex((int)bytecode[4],2)+" "+IntToHex((int)bytecode[5],2);
                simDecodeF();
                simStep();
        }else if(!regFlRead(IF) && interrupt)
                interrupt=false;
        else{
                /*
                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regFL);
                regIn(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                regFlReset(IF);
                regFlReset(TF);
                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regSegOut(CS));
                regIn(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                regSegIn(CS,memOut((irq<<2)+2,1));
                memIn((regSegOut(SS)<<4)+regOut(SP,1),1,regPC);
                regIn(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                regPC=(memOut((irq<<2),1))&0x0000FFFF;
                */
                memory[((registras[SS]<<4)+registras[SP]-1)&0x000FFFFF]=((regFL&0x0000FF00)>>8);
                memory[((registras[SS]<<4)+registras[SP]-2)&0x000FFFFF]=((regFL&0x000000FF));

                registras[SP]=(registras[SP]-2)&0x0000FFFF;

                regFlReset(IF);
                regFlReset(TF);
                interrupt=false;

                memory[((registras[SS]<<4)+registras[SP]-1)&0x000FFFFF]=((registras[CS]&0x0000FF00)>>8);
                memory[((registras[SS]<<4)+registras[SP]-2)&0x000FFFFF]=((registras[CS]&0x000000FF));

                registras[SP]=(registras[SP]-2)&0x0000FFFF;

                registras[CS]=memory[((irq<<2)+2)&0x000FFFFF]+(memory[((irq<<2)+3)&0x000FFFFF]<<8);

                memory[((registras[SS]<<4)+registras[SP]-1)&0x000FFFFF]=((regPC&0x0000FF00)>>8);
                memory[((registras[SS]<<4)+registras[SP]-2)&0x000FFFFF]=((regPC&0x000000FF));

                registras[SP]=(registras[SP]-2)&0x0000FFFF;

                regPC=memory[((irq<<2))&0x000FFFFF]+(memory[((irq<<2)+1)&0x000FFFFF]<<8);

                regShow();
                memShow();
                kodDecompile();
                kodShow();
        }

        if( (regPC&0x0000FFFF)<0x00000007 )
                kScroll->Position=0;
        else if ( (regPC&0x0000FFFF)>65522 )
                kScroll->Position=65522;
        else
                kScroll->Position=(regPC&0x0000FFFF)-6;
        regShow();
        kodShow();
        if(!Timer1->Enabled){
                StaticText5->Caption="[   PAUZË  ]";
                StaticText5->Color=clYellow;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
        int timer=Timer1->Interval;
        Timer1->Interval=0;
        Timer1->Enabled=true;
        SpeedButton1Click(Sender);
        Timer1->Interval=timer;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
        Timer1->Enabled=false;
        StaticText5->Caption="[   PAUZE  ]";
        StaticText5->Color=clYellow;

}
//---------------------------------------------------------------------------





void __fastcall TForm1::BrMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
         kodAddBP(Y/16);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BrPaint(TObject *Sender)
{
        kodBPRefresh();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::rAXClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(AX,1);
                Form3->reg=AX;
                Form3->registras="AX";
                Form3->ShowModal();
        }
/*
 GroupBox1->Visible=true;
 GroupBox1->Top=rAX->Top+5;
 GroupBox1->Left=340;
 GroupBox1->Caption="Registras AX";
 GroupBox1->Tag=0;
 Edit2->Text=IntToHex((int)regOut(AX,1),4);
 Edit2->SetFocus();
 Edit2->SelectAll();
 */
 
}
//---------------------------------------------------------------------------



void __fastcall TForm1::rCXClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(CX,1);
                Form3->reg=CX;
                Form3->registras="CX";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
        if(registras!="PC" && registras!="FL"){
                Form1->regIn(Form3->reg,1,Form3->reiksme);
        }else if(registras=="PC"){
                Form1->regPC=Form3->reiksme;
                Form1->regShow();
        }else if(registras=="FL"){
                Form1->regFL=Form3->reiksme;
                Form1->regShow();
        }
        Form3->Close();
}



void __fastcall TForm1::rDXClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(DX,1);
                Form3->reg=DX;
                Form3->registras="DX";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rBXClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(BX,1);
                Form3->reg=BX;
                Form3->registras="BX";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rSPClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(SP,1);
                Form3->reg=SP;
                Form3->registras="SP";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rBPClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(BP,1);
                Form3->reg=BP;
                Form3->registras="BP";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rSIClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(SI,1);
                Form3->reg=SI;
                Form3->registras="SI";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rDIClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(DI,1);
                Form3->reg=DI;
                Form3->registras="DI";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rESClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(ES,1);
                Form3->reg=ES;
                Form3->registras="ES";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rCSClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(CS,1);
                Form3->reg=CS;
                Form3->registras="CS";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rSSClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(SS,1);
                Form3->reg=SS;
                Form3->registras="SS";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rDSClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regOut(DS,1);
                Form3->reg=DS;
                Form3->registras="DS";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rPCClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regPC;
                Form3->registras="PC";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rFLClick(TObject *Sender)
{
        if(Timer1->Enabled==false){
                Form3->reiksme=regFL;
                Form3->registras="FL";
                Form3->ShowModal();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::memChangeClick(TObject *Sender){
        if(!Timer1->Enabled)
                Form4->ShowModal();

}

void __fastcall TForm1::PortChangeClick(TObject *Sender){
        if(!Timer1->Enabled)
                Form5->ShowModal();

}

void __fastcall TForm4::Button2Click(TObject *Sender)
{
        for(int i=Form4->pradzia;i<=Form4->pabaiga;i++){
                Form1->memIn8( ((Form4->segmentas<<4)+i)&0x000FFFFF,Form4->reiksme );
        }
        Form4->Close();
        if(((Form4->segmentas<<4)+Form4->pradzia)>=(Form1->regSegOut(CS)<<4) && ((Form4->segmentas<<4)+Form4->pabaiga)<=((Form1->regSegOut(CS)<<4)+0x0000FFFF)){
                Form1->kodDecompile();
                Form1->kodShow();
        }
        if((((Form4->segmentas<<4)+Form4->pradzia)>=Form1->vidAddress
        && ((Form4->segmentas<<4)+Form4->pradzia)<=(Form1->vidMode?(Form1->vidAddress+1000):(Form1->vidAddress+6400)))
        || (((Form4->segmentas<<4)+Form4->pabaiga)>=Form1->vidAddress
        && ((Form4->segmentas<<4)+Form4->pabaiga)<=(Form1->vidMode?(Form1->vidAddress+1000):(Form1->vidAddress+6400))) )
                Form1->vidRefresh();
}

void __fastcall TForm5::Button2Click(TObject *Sender)
{
        if(Form5->RadioButton1->Checked){
                Form1->portInIN(Form5->portas,1,Form5->reiksme);
        }else{
                Form1->portInOUT(Form5->portas,1,Form5->reiksme);
        }
        Form5->Close();
}
void __fastcall TForm1::DisplayPaint(TObject *Sender)
{
vidRefresh();        
}
//---------------------------------------------------------------------------
/*void TForm1::simInt(unsigned int intVector){
        if(intVector<0x00000100){
                memIn(((regSegOut(SS)<<4)+regOut(SP,1))&0x000FFFFF,1,regFL);
                regIn(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                regFlReset(IF);
                regFlReset(TF);
                memIn(((regSegOut(SS)<<4)+regOut(SP,1))&0x000FFFFF,1,regSegOut(CS));
                regIn(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                regSegIn(CS,memOut(((intVector<<2)+2)&0x000FFFFF,1));
                memIn(((regSegOut(SS)<<4)+regOut(SP,1))&0x000FFFFF,1,regPC);
                regIn(SP,w,(regOut(SP,w)-2)&0x0000FFFF);
                regPC=(memOut(((intVector<<2))&0x000FFFFF,1))&0x0000FFFF;

                memory[((registras[SS]<<4)+registras[SP])&0x000FFFFF]=((regFL&0x0000FF00)>>8);
                memory[((registras[SS]<<4)+registras[SP]-1)&0x000FFFFF]=((regFL&0x0000FF00)>>8);

                registras[SP]=(registras[SP]-2)&0x0000FFFF;

                regFlReset(IF);
                regFlReset(TF);

                memory[((registras[SS]<<4)+registras[SP])&0x000FFFFF]=((registras[CS]&0x0000FF00)>>8);
                memory[((registras[SS]<<4)+registras[SP]-1)&0x000FFFFF]=((registras[CS]&0x0000FF00)>>8);

                registras[SP]=(registras[SP]-2)&0x0000FFFF;

                registras[CS]=memory[((irq<<1)+2)&0x000FFFFF]+(memory[((irq<<1)+3)&0x000FFFFF]<<8);

                memory[((registras[SS]<<4)+registras[SP])&0x000FFFFF]=((regPC&0x0000FF00)>>8);
                memory[((registras[SS]<<4)+registras[SP]-1)&0x000FFFFF]=((regPC&0x0000FF00)>>8);

                registras[SP]=(registras[SP]-2)&0x0000FFFF;

                regPC=memory[((irq<<1))&0x000FFFFF]+(memory[((irq<<1)+1)&0x000FFFFF]<<8);

        }
}
*/

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000001);

        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="01";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000002);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="02";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000003);
        irq=kbIrq;
        regFlSet(IF);
        StaticText413->Caption="03";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000004);
        irq=kbIrq;
        regFlSet(IF);
        StaticText413->Caption="04";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000005);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="05";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000006);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="06";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000007);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="07";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000008);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="08";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000009);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="09";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000000A);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="0A";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000000B);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="0B";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000000C);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="0C";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000000D);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="0D";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000000E);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="0E";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button38Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000000F);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="0F";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000010);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="10";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000011);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="11";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000012);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="12";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000013);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="13";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000014);
       irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="14";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000015);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="15";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000016);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="16";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000017);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="17";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000018);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="18";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000019);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="19";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000001A);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="1A";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button54Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000001B);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="1B";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button52Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000001C);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="1C";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button51Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000001D);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="1D";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000001E);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="1E";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000001F);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="1F";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000020);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="20";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000021);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="21";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000022);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="22";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000023);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="23";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000024);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="24";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000025);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="25";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button34Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000026);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="26";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button35Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000027);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="27";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button36Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000028);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="28";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button37Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000029);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="29";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button55Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000002A);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="2A";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button39Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000002B);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="2B";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button40Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000002C);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="2C";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button41Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000002D);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="2D";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button42Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000002E);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="2E";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button43Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000002F);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="2F";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button44Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000030);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="30";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button45Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000031);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="31";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button46Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000032);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="32";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button47Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000033);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="33";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button48Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000034);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="34";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button49Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000035);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="35";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button50Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000036);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="36";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button53Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000037);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="37";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button57Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000038);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="38";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button56Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000039);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="39";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button58Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000003A);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="3A";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button67Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000003B);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="3B";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button68Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000003C);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="3C";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button64Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000003D);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="3D";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button65Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000003E);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="3E";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button60Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000003F);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="3F";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button62Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000040);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="40";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button76Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000041);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="41";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button77Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000042);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="42";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button74Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000043);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="43";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button75Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000044);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="44";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button72Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000045);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="45";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button73Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000046);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="46";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button82Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000047);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="47";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button83Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000048);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="48";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button69Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000049);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="49";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button71Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000004A);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="4A";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button80Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000004B);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="4B";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button81Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000004C);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="4C";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button66Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000004D);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="4D";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button70Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000004E);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="4E";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button78Click(TObject *Sender)
{
        portInIN(kbPort,0,0x0000004F);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="4F";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button79Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000050);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="50";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button63Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000051);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="51";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button59Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000052);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="52";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button61Click(TObject *Sender)
{
        portInIN(kbPort,0,0x00000053);
        irq=kbIrq;
        interrupt=true;
        //regFlSet(IF);
        StaticText413->Caption="53";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
        Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Kompiliuotiirikrauti1Click(TObject *Sender)
{
        Form2->Kompiliuoti1Click(Sender);
        if(Form2->kFailoVardas!="")
                Form1->ikrauti(kFailoVardas);
}

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
        OpenDialog1->Filter = "Sukompiliuoti failai (*.co)|*.co|Visi failai (*.*)|*.*";
        if(OpenDialog1->Execute()){
                ikrauti(OpenDialog1->FileName);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
        OpenDialog1->Filter = "Duomenu failai (*.dt)|*.dt|Visi failai (*.*)|*.*";
        if(OpenDialog1->Execute()){
                memFromFile(OpenDialog1->FileName);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
        OpenDialog1->Filter = "Atmities failai (*.dm)|*.dm|Visi failai (*.*)|*.*";
                int iFileHandle;
                int iFileLength;
                int iBytesRead;
                char pszBuffer;
                if (OpenDialog1->Execute()){
                        iFileHandle = FileOpen(OpenDialog1->FileName, fmOpenRead);
                        iFileLength = FileSeek(iFileHandle,0,2);
                        if(iFileLength==0x000FFFFF){

                        FileSeek(iFileHandle,0,0);
                        //pszBuffer = newchar[iFileLength+1];
                        //iBytesRead = FileRead(iFileHandle, pszBuffer, iFileLength);
                        //FileClose(iFileHandle);

                        for (int i=0;i<0x000FFFFF;i++){
                                FileRead(iFileHandle,&pszBuffer,1);
                                memory[i]=((int)pszBuffer)&0x000000FF;
                        }
                        //delete [] pszBuffer;
                        }
                        FileClose(iFileHandle);
                        kodDecompile();
                        kodShow();
                        memShow();
                }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{

SaveDialog1->Filter = "Atminties failai (*.dm)|*.dm|Visi failai (*.*)|*.*";
SaveDialog1->DefaultExt="dm";
  char szFileName[MAXFILE+4];
  int iFileHandle;
  int iLength;
  if (SaveDialog1->Execute())
  {
    if (FileExists(SaveDialog1->FileName)){
      if(MessageDlg("Toks failas jau yra.\nAr norite irasyti faila tuo paciu pavadinimu?",mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes){
        fnsplit(SaveDialog1->FileName.c_str(), 0, 0, szFileName, 0);
        strcat(szFileName, ".BAK");
        RenameFile(SaveDialog1->FileName, szFileName);
        iFileHandle = FileCreate(SaveDialog1->FileName);
        for(int i=0;i<0x000FFFFF;i++){
                FileWrite(iFileHandle,&((char*)memory[i]),1);
        }
        FileClose(iFileHandle);
      }
    }
    else{
        iFileHandle = FileCreate(SaveDialog1->FileName);
        for(int i=0;i<0x000FFFFF;i++){
                FileWrite(iFileHandle,&((char*)memory[i]),1);
        }
        FileClose(iFileHandle);
    }
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
                OpenDialog1->Filter = "Busenos failai (*.st)|*.st|Visi failai (*.*)|*.*";                int iFileHandle;
                int iFileLength;
                int iBytesRead;
                char pszBuffer;
                char pszBuffReg[2];
                if (OpenDialog1->Execute()){
                        iFileHandle = FileOpen(OpenDialog1->FileName, fmOpenRead);
                        iFileLength = FileSeek(iFileHandle,0,2);
                        if(iFileLength==0x0010001B){

                        FileSeek(iFileHandle,0,0);

                        for(int i=0;i<12;i++){
                                FileRead(iFileHandle,&pszBuffReg,2);
                                registras[i]=(unsigned int)(pszBuffReg[0])+((unsigned int)(pszBuffReg[1])<<8);
                        }
                        FileRead(iFileHandle,&pszBuffReg,2);
                        regPC=(unsigned int)(pszBuffReg[0])+((unsigned int)(pszBuffReg[1])<<8);
                        FileRead(iFileHandle,&pszBuffReg,2);
                        regFL=(unsigned int)(pszBuffReg[0])+((unsigned int)(pszBuffReg[1])<<8);

                        //pszBuffer = newchar[iFileLength+1];
                        //iBytesRead = FileRead(iFileHandle, pszBuffer, iFileLength);
                        //FileClose(iFileHandle);

                        for (int i=0;i<0x000FFFFF;i++){
                                FileRead(iFileHandle,&pszBuffer,1);
                                memory[i]=((int)pszBuffer)&0x000000FF;
                        }
                        //delete [] pszBuffer;
                        }
                        FileClose(iFileHandle);
                        regShow();
                        kodDecompile();
                        kodShow();
                        memShow();
                }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton10Click(TObject *Sender)
{
SaveDialog1->Filter = "Busenos failai (*.st)|*.st|Visi failai (*.*)|*.*";
SaveDialog1->DefaultExt="st";
  char szFileName[MAXFILE+4];
  int iFileHandle;
  int iLength;
  char pszBuffReg[2];
  if (SaveDialog1->Execute())
  {
    if (FileExists(SaveDialog1->FileName)){
      if(MessageDlg("Toks failas jau yra.\nAr norite irasyti faila tuo paciu pavadinimu?",mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes){
        fnsplit(SaveDialog1->FileName.c_str(), 0, 0, szFileName, 0);
        strcat(szFileName, ".BAK");
        RenameFile(SaveDialog1->FileName, szFileName);
        iFileHandle = FileCreate(SaveDialog1->FileName);
        for(int i=0;i<12;i++){
                FileWrite(iFileHandle,&((char*)registras[i]),2);
        }
        FileWrite(iFileHandle,&((char*)regPC),2);
        FileWrite(iFileHandle,&((char*)regFL),2);
        for(int i=0;i<0x000FFFFF;i++){
                FileWrite(iFileHandle,&((char*)memory[i]),1);
        }
        FileClose(iFileHandle);
      }
    }
    else{
        iFileHandle = FileCreate(SaveDialog1->FileName);
        for(int i=0;i<0x000FFFFF;i++){
                FileWrite(iFileHandle,&((char*)memory[i]),1);
        }
        FileClose(iFileHandle);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
        if((Form6->adresas>>4)<=0x0000FFF0)
                Form1->aScroll->Position=(Form6->adresas>>4);
        else
                Form1->aScroll->Position=0x0000FFF0;

        Form6->Close();
}
void __fastcall TForm1::Pereitiprieadreso1Click(TObject *Sender)
{
        Form6->ShowModal();
}
void __fastcall TForm7::Button2Click(TObject *Sender)
{
        Form1->vidMode=!Form7->ekrGrafinis;
        Form1->Ekranas->Caption=!Form7->ekrGrafinis?"Tekstinis ekranas":"Grafinis ekranas";
        Form1->vidAddress=Form7->ekrAdresas;
        Form1->kbIrq=Form7->kbPertraukimas;
        Form1->kbPort=Form7->kbPortas;
        switch(Form7->TrackBar1->Position){
        case 0:
                Form1->Timer1->Interval=1;
        break;
        case 1:
                Form1->Timer1->Interval=10;
        break;
        case 2:
                Form1->Timer1->Interval=20;
        break;
        case 3:
                Form1->Timer1->Interval=50;
        break;
        case 4:
                Form1->Timer1->Interval=100;
        break;
        case 5:
                Form1->Timer1->Interval=150;
        break;
        case 6:
                Form1->Timer1->Interval=300;
        break;
        case 7:
                Form1->Timer1->Interval=500;
        break;
        case 8:
                Form1->Timer1->Interval=1000;
        break;
        case 9:
                Form1->Timer1->Interval=1500;
        break;
        case 10:
                Form1->Timer1->Interval=2000;
        break;
        }
        Form1->vidRefresh();
        Form1->StaticText4->Caption=IntToHex((int)Form1->kbPort,4);
        Form7->Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Parametrai3Click(TObject *Sender)
{
        Form7->ekrGrafinis=!vidMode;
        Form7->ekrAdresas=vidAddress;
        Form7->kbPertraukimas=kbIrq;
        Form7->kbPortas=kbPort;
        switch(Timer1->Interval){
        case 1:
                Form7->TrackBar1->Position=0;
        break;
        case 10:
                Form7->TrackBar1->Position=1;
        break;
        case 20:
                Form7->TrackBar1->Position=2;
        break;
        case 50:
                Form7->TrackBar1->Position=3;
        break;
        case 100:
                Form7->TrackBar1->Position=4;
        break;
        case 150:
                Form7->TrackBar1->Position=5;
        break;
        case 300:
                Form7->TrackBar1->Position=6;
        break;
        case 500:
                Form7->TrackBar1->Position=7;
        break;
        case 1000:
                Form7->TrackBar1->Position=8;
        break;
        case 1500:
                Form7->TrackBar1->Position=9;
        break;
        case 2000:
                Form7->TrackBar1->Position=10;
        break;
        }
        Form7->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Naujas1Click(TObject *Sender)
{
        SpeedButton4Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Atverti1Click(TObject *Sender)
{
        SpeedButton5Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ikeltiduomenis1Click(TObject *Sender)
{
        SpeedButton6Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ikeltiatminti1Click(TObject *Sender)
{
        SpeedButton9Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ikeltibusena1Click(TObject *Sender)
{
        SpeedButton8Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Issaugotiatminti1Click(TObject *Sender)
{
        SpeedButton7Click(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Zingsnis1Click(TObject *Sender)
{
        SpeedButton1Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Vykdyti1Click(TObject *Sender)
{
        SpeedButton2Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pauze1Click(TObject *Sender)
{
        SpeedButton3Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pabaiga1Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button86Click(TObject *Sender)
{
        for(int i=0;i<0x00010000;i++){
                portsIN[i]=0;
                portsOUT[i]=0;
        }
        portShow();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Parametrai1Click(TObject *Sender)
{
ShellExecute(0, NULL, "8086help.chm", NULL, NULL, SW_SHOW);
}
//---------------------------------------------------------------------------



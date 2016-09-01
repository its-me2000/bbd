//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Unit2.cpp"
#include "Unit3.cpp"
#include "Unit4.cpp"
#include "Unit5.cpp"
#include "Unit6.cpp"
#include "Unit7.cpp"
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *Registrai;
        TStaticText *lAX;
        TStaticText *rAX;
        TStaticText *lCX;
        TStaticText *lDX;
        TStaticText *lBX;
        TStaticText *lSP;
        TStaticText *lBP;
        TStaticText *lSI;
        TStaticText *lDI;
        TStaticText *lES;
        TStaticText *lCS;
        TStaticText *lSS;
        TStaticText *lDS;
        TStaticText *lPC;
        TStaticText *lFL;
        TGroupBox *Atmintis;
        TStaticText *aCol0;
        TStaticText *aCol1;
        TStaticText *aCol2;
        TStaticText *aCol3;
        TStaticText *aCol4;
        TStaticText *aCol5;
        TStaticText *aCol6;
        TStaticText *aCol7;
        TStaticText *aCol8;
        TStaticText *aCol9;
        TStaticText *aColA;
        TStaticText *aColB;
        TStaticText *aColC;
        TStaticText *aColD;
        TStaticText *aColE;
        TStaticText *aColF;
        TGroupBox *Portai;
        TScrollBar *aScroll;
        TStaticText *pIN;
        TStaticText *pOUT;
        TScrollBar *pScroll;
        TStaticText *rCX;
        TStaticText *rDX;
        TStaticText *rBX;
        TStaticText *rSP;
        TStaticText *rBP;
        TStaticText *rSI;
        TStaticText *rDI;
        TStaticText *rES;
        TStaticText *rCS;
        TStaticText *rSS;
        TStaticText *rDS;
        TStaticText *rPC;
        TStaticText *rFL;
        TCheckBox *fCF;
        TCheckBox *fPF;
        TCheckBox *fAF;
        TCheckBox *fZF;
        TCheckBox *fSF;
        TCheckBox *fTF;
        TCheckBox *fIF;
        TCheckBox *fDF;
        TCheckBox *fOF;
        TGroupBox *Kodas;
        TStaticText *kAddr;
        TStaticText *kByteCode;
        TStaticText *kCommand;
        TScrollBar *kScroll;
        TGroupBox *Ekranas;
        TGroupBox *GroupBox6;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TButton *Button14;
        TButton *Button15;
        TButton *Button16;
        TButton *Button17;
        TButton *Button18;
        TButton *Button19;
        TButton *Button20;
        TButton *Button21;
        TButton *Button22;
        TButton *Button23;
        TButton *Button24;
        TButton *Button25;
        TButton *Button26;
        TButton *Button27;
        TButton *Button28;
        TButton *Button29;
        TButton *Button30;
        TButton *Button31;
        TButton *Button32;
        TButton *Button33;
        TButton *Button34;
        TButton *Button35;
        TButton *Button36;
        TButton *Button37;
        TButton *Button38;
        TButton *Button39;
        TButton *Button40;
        TButton *Button41;
        TButton *Button42;
        TButton *Button43;
        TButton *Button44;
        TButton *Button45;
        TButton *Button46;
        TButton *Button47;
        TButton *Button48;
        TButton *Button49;
        TButton *Button50;
        TButton *Button51;
        TButton *Button52;
        TButton *Button53;
        TButton *Button54;
        TButton *Button55;
        TButton *Button56;
        TButton *Button57;
        TButton *Button58;
        TButton *Button59;
        TButton *Button60;
        TButton *Button61;
        TButton *Button62;
        TButton *Button63;
        TButton *Button64;
        TButton *Button65;
        TButton *Button66;
        TButton *Button67;
        TButton *Button68;
        TButton *Button69;
        TButton *Button70;
        TButton *Button71;
        TButton *Button72;
        TButton *Button73;
        TButton *Button74;
        TButton *Button75;
        TButton *Button76;
        TButton *Button77;
        TButton *Button78;
        TButton *Button79;
        TButton *Button80;
        TButton *Button81;
        TButton *Button82;
        TButton *Button83;
        TStaticText *StaticText412;
        TStaticText *StaticText413;
        TPaintBox *Display;
        TPanel *Panel1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TTimer *Timer1;
        TSpeedButton *SpeedButton3;
        TStaticText *StaticText1;
        TPaintBox *Br;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TSpeedButton *SpeedButton9;
        TMainMenu *MainMenu1;
        TMenuItem *failas1;
        TMenuItem *Atverti1;
        TMenuItem *Ikeltiduomenis1;
        TMenuItem *Ikeltiatminti1;
        TMenuItem *Issaugotiatminti1;
        TMenuItem *Naujas1;
        TMenuItem *N1;
        TMenuItem *Pabaiga1;
        TMenuItem *Redagavimas1;
        TMenuItem *Valdymas1;
        TMenuItem *Parametrai1;
        TMenuItem *Parametrai2;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TMemo *Memo1;
        TMenuItem *Parametrai3;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton10;
        TMenuItem *Zingsnis1;
        TMenuItem *Vykdyti1;
        TMenuItem *Pauze1;
        TMenuItem *Pereitiprieadreso1;
        TStaticText *StaticText5;
        TMenuItem *Ikeltibusena1;
        TMenuItem *Issaugotibusena1;
        TButton *Button86;
        void __fastcall aScrollChange(TObject *Sender);
        void __fastcall Button84Click(TObject *Sender);
        void __fastcall pScrollChange(TObject *Sender);
        void __fastcall Button85Click(TObject *Sender);
        void __fastcall kScrollChange(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall BrMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall BrPaint(TObject *Sender);
        void __fastcall rAXClick(TObject *Sender);
        void __fastcall rCXClick(TObject *Sender);
        void __fastcall rDXClick(TObject *Sender);
        void __fastcall rBXClick(TObject *Sender);
        void __fastcall rSPClick(TObject *Sender);
        void __fastcall rBPClick(TObject *Sender);
        void __fastcall rSIClick(TObject *Sender);
        void __fastcall rDIClick(TObject *Sender);
        void __fastcall rESClick(TObject *Sender);
        void __fastcall rCSClick(TObject *Sender);
        void __fastcall rSSClick(TObject *Sender);
        void __fastcall rDSClick(TObject *Sender);
        void __fastcall rPCClick(TObject *Sender);
        void __fastcall rFLClick(TObject *Sender);
        void __fastcall DisplayPaint(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button38Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall Button20Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button24Click(TObject *Sender);
        void __fastcall Button25Click(TObject *Sender);
        void __fastcall Button54Click(TObject *Sender);
        void __fastcall Button52Click(TObject *Sender);
        void __fastcall Button51Click(TObject *Sender);
        void __fastcall Button26Click(TObject *Sender);
        void __fastcall Button27Click(TObject *Sender);
        void __fastcall Button28Click(TObject *Sender);
        void __fastcall Button29Click(TObject *Sender);
        void __fastcall Button30Click(TObject *Sender);
        void __fastcall Button31Click(TObject *Sender);
        void __fastcall Button32Click(TObject *Sender);
        void __fastcall Button33Click(TObject *Sender);
        void __fastcall Button34Click(TObject *Sender);
        void __fastcall Button35Click(TObject *Sender);
        void __fastcall Button36Click(TObject *Sender);
        void __fastcall Button37Click(TObject *Sender);
        void __fastcall Button55Click(TObject *Sender);
        void __fastcall Button39Click(TObject *Sender);
        void __fastcall Button40Click(TObject *Sender);
        void __fastcall Button41Click(TObject *Sender);
        void __fastcall Button42Click(TObject *Sender);
        void __fastcall Button43Click(TObject *Sender);
        void __fastcall Button44Click(TObject *Sender);
        void __fastcall Button45Click(TObject *Sender);
        void __fastcall Button46Click(TObject *Sender);
        void __fastcall Button47Click(TObject *Sender);
        void __fastcall Button48Click(TObject *Sender);
        void __fastcall Button49Click(TObject *Sender);
        void __fastcall Button50Click(TObject *Sender);
        void __fastcall Button53Click(TObject *Sender);
        void __fastcall Button57Click(TObject *Sender);
        void __fastcall Button56Click(TObject *Sender);
        void __fastcall Button58Click(TObject *Sender);
        void __fastcall Button67Click(TObject *Sender);
        void __fastcall Button68Click(TObject *Sender);
        void __fastcall Button64Click(TObject *Sender);
        void __fastcall Button65Click(TObject *Sender);
        void __fastcall Button60Click(TObject *Sender);
        void __fastcall Button62Click(TObject *Sender);
        void __fastcall Button76Click(TObject *Sender);
        void __fastcall Button77Click(TObject *Sender);
        void __fastcall Button74Click(TObject *Sender);
        void __fastcall Button75Click(TObject *Sender);
        void __fastcall Button72Click(TObject *Sender);
        void __fastcall Button73Click(TObject *Sender);
        void __fastcall Button82Click(TObject *Sender);
        void __fastcall Button83Click(TObject *Sender);
        void __fastcall Button69Click(TObject *Sender);
        void __fastcall Button71Click(TObject *Sender);
        void __fastcall Button80Click(TObject *Sender);
        void __fastcall Button81Click(TObject *Sender);
        void __fastcall Button66Click(TObject *Sender);
        void __fastcall Button70Click(TObject *Sender);
        void __fastcall Button78Click(TObject *Sender);
        void __fastcall Button79Click(TObject *Sender);
        void __fastcall Button63Click(TObject *Sender);
        void __fastcall Button59Click(TObject *Sender);
        void __fastcall Button61Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        void __fastcall Pereitiprieadreso1Click(TObject *Sender);
        void __fastcall Parametrai3Click(TObject *Sender);
        void __fastcall Naujas1Click(TObject *Sender);
        void __fastcall Atverti1Click(TObject *Sender);
        void __fastcall Ikeltiduomenis1Click(TObject *Sender);
        void __fastcall Ikeltiatminti1Click(TObject *Sender);
        void __fastcall Ikeltibusena1Click(TObject *Sender);
        void __fastcall Issaugotiatminti1Click(TObject *Sender);
        void __fastcall Zingsnis1Click(TObject *Sender);
        void __fastcall Vykdyti1Click(TObject *Sender);
        void __fastcall Pauze1Click(TObject *Sender);
        void __fastcall Pabaiga1Click(TObject *Sender);
        void __fastcall Button86Click(TObject *Sender);
        void __fastcall Parametrai1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        void __fastcall memChangeClick(TObject *Sender);
        void __fastcall PortChangeClick(TObject *Sender);
        void ikrauti(AnsiString FailoVardas);
        unsigned int memory[0x00100000];
        unsigned int registras[12];
        unsigned int portsIN[0x00010000];
        unsigned int portsOUT[0x00010000];
        unsigned int regPC, regFL;
        unsigned int irq;
        bool interrupt;
        unsigned int kbPort;
        unsigned int kbIrq;
        bool run;
        bool bP[0x00010000];
        TStringList *kodKodas;

//----------------------------------------------
        unsigned int bytecode[6];
        unsigned int length;
        bool dsv,w,memchg;
        unsigned int mod, rm, reg;
        unsigned int fromReg,toReg,fromMem,toMem,mnemonic;
        unsigned int data8,data16,disp8,disp16;
        AnsiString Mnemonic;
        unsigned int state;

//----------------------------------------------

        __fastcall TForm1(TComponent* Owner);
//----------------------------------------------
        void memIn8(unsigned int address,unsigned int data);
        void memIn16(unsigned int address, unsigned int data);
        unsigned int memOut8(unsigned int address);
        unsigned int memOut16(unsigned int address);
        void memIn(unsigned int address,unsigned int w,unsigned int data);
        unsigned int memOut(unsigned int address,unsigned int w);
        void memReset();
        void memShow();
        void memFromFile(AnsiString failoVardas);
//----------------------------------------------
        void regInF(unsigned int reg, unsigned int w, unsigned int data);
        void regIn(unsigned int reg, unsigned int w, unsigned int data);
        unsigned int regOut(unsigned int reg,unsigned int w);
        void regSegIn(unsigned int reg, unsigned int data);
        unsigned int regSegOut(unsigned int reg);
        void regShow();
        void regFlSet(unsigned int flag);
        void regFlReset(unsigned int flag);
        unsigned int regFlRead(unsigned int flag);
//----------------------------------------------
        void portInOUT(unsigned int port, unsigned int w, unsigned int data);
        void portInIN(unsigned int port, unsigned int w, unsigned int data);
        unsigned int portOutIN(unsigned int port,unsigned int w);
        unsigned int portOutOUT(unsigned int port,unsigned int w);
        void portShow();
//----------------------------------------------
        void vidGrfRefresh(unsigned int address); //320*200*256
        void vidTxtRefresh(unsigned int address); //40*25
        void vidGrfDrawPixel(unsigned int x, unsigned int y, unsigned int color);
        void vidTxtDrawSimbol(unsigned int x, unsigned int y, unsigned int simbol);
        bool vidMode;
        unsigned int vidAddress;
        void vidRefresh();
//-----------------------------------------------
        void kodShow();
        void kodDecompile();
        void kodAddBP(unsigned int point);
        void kodBPRefresh();
        void kodBPReset();
//-----------------------------------------------

        void simStep();
        void simReadCommand(unsigned int address);
        void simDecode();
        void simDecodeF();
        void simClear();
        void simGetMnemonic(AnsiString nemonic, unsigned int mnemoni);
        void simGetDSV();
        void simGetW();
        void simGetModRM();
        void simGetModRegRM();
        void simGetData();
        void simGetDisp8();
        void simGetDisp16();
        void simGetIntersegment();
        void simReset();
        void simInt(unsigned int intVector);


//-----------------------------------------------
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

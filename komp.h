//---------------------------------------------------------------------------

#ifndef kompH
#define kompH
//---------------------------------------------------------------------------
#endif
#include "Unit2.h"

class TKomanda{
        public:
        AnsiString OpCode;
        AnsiString op1;
        AnsiString op2;
};

class TZyme{
        public:
        AnsiString zyme;
        int adresas;
};

class TKompiliavimas{
        public:
        bool Kompiliuoti(TKomanda *Komanda, AnsiString &Kodas);
        TStringList* Kompiliuoti(TStringList *MasKodas, TList *Zymes, TList *Jumps);
        
        private:
        int OperandoTipas(AnsiString op);
        AnsiString AsmMov(int op1, int op2);
        AnsiString AsmPush(int op1, int op2);
        AnsiString AsmPop(int op1, int op2);
        AnsiString AsmXchg(int op1, int op2);
        AnsiString AsmIn(int op1, int op2);
        AnsiString AsmOut(int op1, int op2);
        AnsiString AsmXlat(int op1, int op2);
        AnsiString AsmLea(int op1, int op2);
        AnsiString AsmLds(int op1, int op2);
        AnsiString AsmLes(int op1, int op2);
        AnsiString AsmLahf(int op1, int op2);
        AnsiString AsmSahf(int op1, int op2);
        AnsiString AsmPushf(int op1, int op2);
        AnsiString AsmPopf(int op1, int op2);
        AnsiString AsmAdd(int op1, int op2);
        AnsiString AsmAdc(int op1, int op2);
        AnsiString AsmInc(int op1, int op2);
        AnsiString AsmAaa(int op1, int op2);
        AnsiString AsmBaa(int op1, int op2);
        AnsiString AsmSub(int op1, int op2);
        AnsiString AsmSsb(int op1, int op2);
        AnsiString AsmDec(int op1, int op2);
        AnsiString AsmNeg(int op1, int op2);
        AnsiString AsmCmp(int op1, int op2);
        AnsiString AsmAas(int op1, int op2);
        AnsiString AsmDas(int op1, int op2);
        AnsiString AsmMulDiv(int op1, int op2, int type);
        //MulDiv - daugybai ir dalybai
        AnsiString AsmMul(int op1, int op2);
        AnsiString AsmImul(int op1, int op2);
        AnsiString AsmAam(int op1, int op2);
        AnsiString AsmDiv(int op1, int op2);
        AnsiString AsmIdiv(int op1, int op2);
        AnsiString AsmAad(int op1, int op2);
        AnsiString AsmCbw(int op1, int op2);
        AnsiString AsmCwd(int op1, int op2);
        AnsiString AsmNot(int op1, int op2);
        AnsiString AsmShift(int op1, int op2, int type);
        //AsmShift - poslinkio komandoms
        AnsiString AsmShlSal(int op1, int op2);
        AnsiString AsmShr(int op1, int op2);
        AnsiString AsmSar(int op1, int op2);
        AnsiString AsmRol(int op1, int op2);
        AnsiString AsmRor(int op1, int op2);
        AnsiString AsmRcl(int op1, int op2);
        AnsiString AsmRcr(int op1, int op2);
        AnsiString AsmRegMemToReg(int op1, int op2, int type);
        //AsmRegMemToReg 000000dw ModRegR/m
        AnsiString AsmImToRegMemS(int op1, int op2, int type);
        //AsmImToRegMem 100000sw mod 000 r/m data [data w=1]
        AnsiString AsmImToRegMem(int op1, int op2, int type);
        //AsmImToRegMem 1000000w mod 000 r/m data [data w=1]
        AnsiString AsmAnd(int op1, int op2);
        AnsiString AsmTest(int op1, int op2);
        AnsiString AsmOr(int op1, int op2);
        AnsiString AsmXor(int op1, int op2);
        AnsiString AsmRep(int op1, int op2);
        AnsiString AsmMovs(int op1, int op2);
        AnsiString AsmCmps(int op1, int op2);
        AnsiString AsmScas(int op1, int op2);
        AnsiString AsmLods(int op1, int op2);
        AnsiString AsmStos(int op1, int op2);
        AnsiString AsmCall(int op1, int op2);
        AnsiString AsmJmp(int op1, int op2);
        AnsiString AsmJmp(AnsiString op1);

};
 
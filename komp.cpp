//---------------------------------------------------------------------------


#pragma hdrstop

#include "komp.h"
//#include "Unit2.h"
#include "string.h"
#include "stdio.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)



bool TKompiliavimas::Kompiliuoti(TKomanda *Komanda, AnsiString &Kodas){

        int op1=OperandoTipas(Komanda->op1);
        int op2=OperandoTipas(Komanda->op2);
        if(Komanda->OpCode=="mov"){
                Kodas=AsmMov(op1,op2);
        }
        else if(Komanda->OpCode=="push"){
                Kodas=AsmPush(op1,op2);
        }
        else if(Komanda->OpCode=="pop"){
                Kodas=AsmPop(op1,op2);
        }
        else if(Komanda->OpCode=="xchg"){
                Kodas=AsmXchg(op1,op2);
        }
        else if(Komanda->OpCode=="xlat"){
                Kodas=AsmXlat(op1,op2);
        }
        else if(Komanda->OpCode=="lea"){
                Kodas=AsmLea(op1,op2);
        }
        else if(Komanda->OpCode=="lahf"){
                Kodas=AsmLahf(op1,op2);
        }
        else if(Komanda->OpCode=="sahf"){
                Kodas=AsmSahf(op1,op2);
        }
        else if(Komanda->OpCode=="pushf"){
                Kodas=AsmPushf(op1,op2);
        }
        else if(Komanda->OpCode=="popf"){
                Kodas=AsmPopf(op1,op2);
        }
        else if(Komanda->OpCode=="add"){
                Kodas=AsmAdd(op1,op2);
        }
        else if(Komanda->OpCode=="adc"){
                Kodas=AsmAdc(op1,op2);
        }
        else if(Komanda->OpCode=="inc"){
                Kodas=AsmInc(op1,op2);
        }
        else if(Komanda->OpCode=="aaa"){
                Kodas=AsmAaa(op1,op2);
        }
        else if(Komanda->OpCode=="baa"){
                Kodas=AsmBaa(op1,op2);
        }
        else if(Komanda->OpCode=="sub"){
                Kodas=AsmSub(op1,op2);
        }
        else if(Komanda->OpCode=="ssb"){
                Kodas=AsmSsb(op1,op2);
        }
        else if(Komanda->OpCode=="dec"){
                Kodas=AsmDec(op1,op2);
        }
        else if(Komanda->OpCode=="neg"){
                Kodas=AsmNeg(op1,op2);
        }
        else if(Komanda->OpCode=="cmp"){
                Kodas=AsmCmp(op1,op2);
        }
        else if(Komanda->OpCode=="aas"){
                Kodas=AsmAas(op1,op2);
        }
        else if(Komanda->OpCode=="das"){
                Kodas=AsmDas(op1,op2);
        }
        else if(Komanda->OpCode=="mul"){
                Kodas=AsmMul(op1,op2);
        }
        else if(Komanda->OpCode=="imul"){
                Kodas=AsmImul(op1,op2);
        }
        else if(Komanda->OpCode=="aam"){
                Kodas=AsmAam(op1,op2);
        }
        else if(Komanda->OpCode=="div"){
                Kodas=AsmDiv(op1,op2);
        }
        else if(Komanda->OpCode=="idiv"){
                Kodas=AsmIdiv(op1,op2);
        }
        else if(Komanda->OpCode=="aad"){
                Kodas=AsmAad(op1,op2);
        }
        else if(Komanda->OpCode=="cbw"){
                Kodas=AsmCbw(op1,op2);
        }
        else if(Komanda->OpCode=="cwd"){
                Kodas=AsmCwd(op1,op2);
        }
        else if(Komanda->OpCode=="not"){
                Kodas=AsmNot(op1,op2);
        }
        else if(Komanda->OpCode=="shl" || Komanda->OpCode=="sal"){
                Kodas=AsmShlSal(op1,op2);
        }
        else if(Komanda->OpCode=="shr"){
                Kodas=AsmShr(op1,op2);
        }
        else if(Komanda->OpCode=="sar"){
                Kodas=AsmSar(op1,op2);
        }
        else if(Komanda->OpCode=="rol"){
                Kodas=AsmRol(op1,op2);
        }
        else if(Komanda->OpCode=="ror"){
                Kodas=AsmRor(op1,op2);
        }
        else if(Komanda->OpCode=="rcl"){
                Kodas=AsmRcl(op1,op2);
        }
        else if(Komanda->OpCode=="rcr"){
                Kodas=AsmRcr(op1,op2);
        }
        else if(Komanda->OpCode=="and"){
                Kodas=AsmAnd(op1,op2);
        }
        else if(Komanda->OpCode=="or"){
                Kodas=AsmOr(op1,op2);
        }
        else if(Komanda->OpCode=="xor"){
                Kodas=AsmXor(op1,op2);
        }
        else if(Komanda->OpCode=="jmp"){
                if(op1!=-1)
                Kodas=AsmJmp(op1,op2);
                else
                Kodas=AsmJmp(Komanda->op1);
        }

        return true;

}

TStringList* TKompiliavimas::Kompiliuoti(TStringList *MasKodas, TList *Zymes, TList *Jumps){
        for(int i=0;i<Jumps->Count;i++){
                TZyme *Jump=new TZyme;
                Jump=(TZyme*)Jumps->Items[i];
                for(int j=0;j<Zymes->Count;j++){
                        TZyme *Zyme=new TZyme;
                        Zyme=(TZyme*)Zymes->Items[j];
                        if(Jump->zyme=="l"+Zyme->zyme){
                                for(int k=0;k<MasKodas->Count;k++){
                                        if(StrToInt("0x"+MasKodas->Strings[k].SubString(2,5))==Jump->adresas){
                                                AnsiString E,E1,E2;
                                                E=MasKodas->Strings[k].SubString(1,17);
                                                E2=MasKodas->Strings[k].SubString(23,MasKodas->Strings[k].Length()-22);
                                                int disp;
                                                disp=(Zyme->adresas - Jump->adresas)/0x8000;
                                                E1=(disp>=0)?IntToHex(disp%256,2)+" "+IntToHex(disp/256,2):IntToHex(abs(disp)%256,2)+" "+IntToHex(0x80+abs(disp)/256,2);
                                                MasKodas->Strings[k]=E+E1+E2;
                                                break;
                                        }
                                }
                                break;
                        }
                        if(Jump->zyme=="s"+Zyme->zyme){
                                for(int k=0;k<MasKodas->Count;k++){
                                        if(StrToInt("0x"+MasKodas->Strings[k].SubString(2,5))==Jump->adresas){
                                                AnsiString E,E1,E2;
                                                E=MasKodas->Strings[k].SubString(1,17);
                                                E2=MasKodas->Strings[k].SubString(20,MasKodas->Strings[k].Length()-19);
                                                int disp;
                                                disp=(Zyme->adresas - Jump->adresas)%0x80;
                                                E1=(disp>=0)?IntToHex(disp%256,2):(IntToHex(0x80+abs(disp)%256,2));
                                                MasKodas->Strings[k]=E+E1+E2;
                                                break;
                                        }
                                }
                                break;
                        }
                }
        }
        return MasKodas;
}

int TKompiliavimas::OperandoTipas(AnsiString op){
        AnsiString reg16[]={"ax","cx","dx","bx","sp","bp","si","di"};
        AnsiString reg8[]={"al","cl","dl","bl","ah","ch","dh","bh"};
        AnsiString segr[]={"es","cs","ss","ds"};
        AnsiString mem[]={"(bx)+(si)","(bx)+(di)","(bp)+(si)","(bp)+(di)","(si)","(di)","(bp)","(bx)"};

       // int optype;

        if(op!=""){
                for(int i=0;i<8;i++){
                        if(op==reg16[i]){
                                return 1000000+i;
                        }
                }
                for(int i=0;i<8;i++){
                        if(op==reg8[i]){
                                return 2000000+i;
                        }
                }
                for(int i=0;i<4;i++){
                        if(op==segr[i]){
                                return 3000000+i;
                        }
                }
                try{
                         int disp;
                         int i;
                         switch(op.Length()){
                                 case 17:
                                         disp=StrToInt("0x"+op.SubString(11,4));
                                         for(i=0;i<4;i++){
                                                 if(op.SubString(1,9)==mem[i] && op.SubString(10,1)=="+"){
                                                         return 4000000+i*100000+disp;
                                                 }
                                         }
                                 break;
                                 case 15:
                                         disp=StrToInt("0x"+op.SubString(11,2));
                                         for(i=0;i<4;i++){
                                                 if(op.SubString(1,9)==mem[i] && op.SubString(10,1)=="+"){
                                                         return 5000000+i*100000+disp;
                                                 }
                                         }
                                 break;
                                 case 11:
                                         for(i=0;i<4;i++){
                                                 if(op.SubString(1,op.Length()-1)==mem[i]){
                                                         return 6000000+i*100000+disp;
                                                 }
                                         }
                                 break;
                                 case 12:
                                         disp=StrToInt("0x"+op.SubString(6,4));
                                         for(i=4;i<8;i++){
                                                  if(op.SubString(1,4)==mem[i] && op.SubString(5,1)=="+"){
                                                         return 7000000+i*100000+disp;
                                                 }
                                         }
                                 break;
                                 case 10:
                                         disp=StrToInt("0x"+op.SubString(6,2));
                                         for(i=4;i<8;i++){
                                                 if(op.SubString(1,4)==mem[i] && op.SubString(5,1)=="+"){
                                                         return 8000000+i*100000+disp;
                                                 }
                                         }
                                 break;
                                 case 6:
                                         for(i=4;i<8;i++){
                                                if(i!=6){
                                                 if(op.SubString(1,4)==mem[i]){
                                                         return 9000000+i*100000;
                                                 }
                                                }
                                         }
                                 break;
                         }
                         if(op.Length()==7 || op.Length()==5){
                                 disp=StrToInt("0x"+op.SubString(2,op.Length()-3));
                                 return 10000000+disp;
                         }
                         else if(op.Length()==6 || op.Length()==4){
                                 disp=StrToInt(op);
                                 return disp;
                         }
                }
                catch(...){

                }


        }
        return -1;

}

AnsiString TKompiliavimas::AsmMov(int op1, int op2){
        char e[6];
        AnsiString E="";
//ax to mem
        if(op2==1000000 && op1>=10000000){
                E=IntToHex(0xa3,2)+" "+IntToHex((op1%10000000)%256,2)+" "+IntToHex((op1%10000000)/256,2)+" ";
        }
//al to mem
        else if(op2==2000000 && op1>=10000000){
                E=IntToHex(0xa2,2)+" "+IntToHex((op1%10000000)%256,2)+" "+IntToHex((op1%10000000)/256,2)+" ";
        }
//mem to ax
        else if(op1==1000000 && op2>=10000000){
                E=IntToHex(0xa1,2)+" "+IntToHex((op2%10000000)%256,2)+" "+IntToHex((op2%10000000)/256,2)+" ";
        }
//mem to ah
        else if(op1==2000000 && op2>=10000000){
                E=IntToHex(0xa0,2)+" "+IntToHex((op2%10000000)%256,2)+" "+IntToHex((op2%10000000)/256,2)+" ";
        }
//reg16 to reg16
        else if((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)){
                E=IntToHex(0x8B,2)+" "+IntToHex(0xc0+((op1%1000000)<<3)+(op2%1000000),2)+" ";
        }
//reg8 to reg8
        else if((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)){
                E=IntToHex(0x8A,2)+" "+IntToHex(0xc0+((op1%1000000)<<3)+(op2%1000000),2)+" ";
        }
//mem to reg16
        else if((op1>=1000000 && op1<2000000) && (op2>=4000000)){
                int mod;
                mod=op2/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x8B,2)+" "+IntToHex(0x80+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x8B,2)+" "+IntToHex(0x40+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x8B,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x8B,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+6,2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
        }
//mem to reg8
        else if((op1>=2000000 && op1<3000000) && (op2>=4000000)){
                int mod;
                mod=op2/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x8A,2)+" "+IntToHex(0x80+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x8A,2)+" "+IntToHex(0x40+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x8A,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x8A,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+6,2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
        }
//reg16 to mem
        else if((op2>=1000000 && op2<2000000) && (op1>=4000000)){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x89,2)+" "+IntToHex(0x80+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x89,2)+" "+IntToHex(0x40+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x89,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x89,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }
//reg8 to mem
        else if((op2>=2000000 && op2<3000000) && (op1>=4000000)){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x88,2)+" "+IntToHex(0x80+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x88,2)+" "+IntToHex(0x40+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x88,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x88,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }
//im to reg16
        else if(op1>=1000000 && op1<2000000 && op2<1000000 && op2>=0){
             //   E=IntToHex(0xB8+op1%1000000,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
             E=IntToHex(0xB8+op1%1000000,2)+" "+IntToHex(op2&0x000000FF,2)+" "+IntToHex(op2&0x0000FF00,2)+" ";
        }
//im to reg8
        else if(op1>=2000000 && op1<3000000 && op2<1000000 && op2>=0){
                E=IntToHex(0xB0+op1%1000000,2)+" "+IntToHex(op2%256,2)+" ";
        }

//im16 to mem
        else if(op2<1000000 && op2>=0 && op2>=256 && op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xc7,2)+" "+IntToHex(0x80+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xc7,2)+" "+IntToHex(0x40+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xc7,2)+" "+IntToHex(0x00+((op1%1000000)/100000),2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xc7,2)+" "+IntToHex(0x00+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
        }
//im8 to mem
        else if(op2<1000000 && op2>=0 && op2<256 && op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xc6,2)+" "+IntToHex(0x80+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xc6,2)+" "+IntToHex(0x40+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xc6,2)+" "+IntToHex(0x00+((op1%1000000)/100000),2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xc6,2)+" "+IntToHex(0x00+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" ";
                }
        }

//reg to segr
        else if(op1>=3000000 && op1<4000000 && op2>=1000000 && op2<2000000){
                E=IntToHex(0x8E,2)+" "+IntToHex(0xC0+((op1%1000000)<<3)+(op2%1000000),2)+" ";
        }
//mem to segr
        else if(op1>=3000000 && op1<4000000 && op2>=4000000){
                int mod;
                mod=op2/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x8E,2)+" "+IntToHex(0x80+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x8E,2)+" "+IntToHex(0x40+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x8E,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x8E,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+6,2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
        }
//segr to reg
        else if(op2>=3000000 && op2<4000000 && op1>=1000000 && op1<2000000){
                E=IntToHex(0x8C,2)+" "+IntToHex(0xC0+((op1%1000000)<<3)+(op2%1000000),2)+" ";
        }
//segr to mem
        else if((op2>=3000000 && op2<4000000) && (op1>=4000000)){
                int mod;
                mod=op2/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x8C,2)+" "+IntToHex(0x80+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x8C,2)+" "+IntToHex(0x40+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x8C,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x8C,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";;
                }
        }
        return E;
}

AnsiString TKompiliavimas::AsmPush(int op1, int op2){

        AnsiString E="";
//puch reg
        if(op1>=1000000 && op1<2000000){
                E=IntToHex(0x50+op1/1000000,2)+" ";
        }
//push segr
        else if(op1>=3000000 && op1<4000000){
                E=IntToHex(0x06+((op1/1000000)<<3),2);
        }
//push mem
        else if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0xB0+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0x70+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0x30+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0x30+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }

        return E;
}

AnsiString TKompiliavimas::AsmPop(int op1, int op2){
        AnsiString E="";
//pop reg
        if(op1>=1000000 && op1<2000000){
                E=IntToHex(0x58+op1/1000000,2)+" ";
        }
//pop segr
        else if(op1>=3000000 && op1<4000000){
                E=IntToHex(0x07+((op1/1000000)<<3),2);
        }
//pop mem
        else if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x8F,2)+" "+IntToHex(0x80+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x8F,2)+" "+IntToHex(0x40+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x8F,2)+" "+IntToHex(0x00+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x8F,2)+" "+IntToHex(0x00+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }

        return E;
}

AnsiString TKompiliavimas::AsmXchg(int op1, int op2){

        AnsiString E;
// reg & ax
        if((op1==1000000 && op2>1000000 && op2<2000000) || (op2==1000000 && op1>1000000 && op1<2000000)){
                E=IntToHex(0x90+((op1==1000000)?(op2%1000000):(op1%1000000)),2);
        }
//reg16 & reg16
        else if((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)){
                E=IntToHex(0x87,2)+" "+IntToHex(0xc0+((op1/1000000)<<3)+(op2%1000000),2)+" ";
        }
//reg8 & reg8
        else if((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)){
                E=IntToHex(0x86,2)+" "+IntToHex(0xc0+((op1/1000000)<<3)+(op2%1000000),2)+" ";
        }
//reg16 & mem
        else if((op2>=1000000 && op2<2000000) && (op1>=4000000) || (op1>=1000000 && op1<2000000) && (op2>=4000000)){
                int mod;
                if(op2>=4000000){
                        mod=op2;
                        op2=op1;
                        op1=mod;
                }
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x87,2)+" "+IntToHex(0x80+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x87,2)+" "+IntToHex(0x40+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x87,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x87,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }
//reg8 & mem
        else if((op2>=2000000 && op2<3000000) && (op1>=4000000) || (op1>=2000000 && op1<3000000) && (op2>=4000000)){
                int mod;
                if(op2>=4000000){
                        mod=op2;
                        op2=op1;
                        op1=mod;
                }
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x86,2)+" "+IntToHex(0x80+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x86,2)+" "+IntToHex(0x40+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x86,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x86,2)+" "+IntToHex(0x00+((op2%1000000)<<3)+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }
        return E;
}

AnsiString TKompiliavimas::AsmXlat(int op1, int op2){

        AnsiString E;
        E=IntToHex(0xd7,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmLea(int op1, int op2){

        AnsiString E;
        //mem to reg16
        if((op1>=1000000 && op1<2000000) && (op2>=4000000)){
                int mod;
                mod=op2/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x8d,2)+" "+IntToHex(0x80+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x8d,2)+" "+IntToHex(0x40+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x8d,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x8d,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+6,2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
        }
        return E;
}

AnsiString TKompiliavimas::AsmLahf(int op1, int op2){

        AnsiString E;
        E=IntToHex(0x9f,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmSahf(int op1, int op2){

        AnsiString E;
        E=IntToHex(0x9e,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmPushf(int op1, int op2){

        AnsiString E;
        E=IntToHex(0x9c,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmPopf(int op1, int op2){

        AnsiString E;
        E=IntToHex(0x9d,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmAdd(int op1, int op2){

        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x00);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x05,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x04,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMemS(op1,op2,0x00);
        }
        return E;
}

AnsiString TKompiliavimas::AsmAdc(int op1, int op2){

        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x10);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x15,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x14,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMemS(op1,op2,0x10);
        }
        return E;
}

AnsiString TKompiliavimas::AsmInc(int op1, int op2){

        AnsiString E="";
//inc reg16
        if(op1>=1000000 && op1<2000000){
                E=IntToHex(0x40+op1/1000000,2)+" ";
        }
//inc reg8
        if(op1>=2000000 && op1<3000000){
                E=IntToHex(0xfe,2)+" "+IntToHex(0xc0+op1/1000000,2)+" ";
        }
//inc mem
        else if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x80+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x40+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x00+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x00+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }

        return E;
}

AnsiString TKompiliavimas::AsmAaa(int op1, int op2){
        AnsiString E;
        E=IntToHex(0x37,2);
        return E;
}

AnsiString TKompiliavimas::AsmBaa(int op1, int op2){
        AnsiString E;
        E=IntToHex(0x27,2);
        return E;
}

AnsiString TKompiliavimas::AsmSub(int op1, int op2){

        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x28);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x2D,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x2C,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMemS(op1,op2,0x28);
        }
        return E;
}

AnsiString TKompiliavimas::AsmSsb(int op1, int op2){

        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x18);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x1D,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x1C,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMemS(op1,op2,0x18);
        }
        return E;
}

AnsiString TKompiliavimas::AsmDec(int op1, int op2){

        AnsiString E="";
//dec reg16
        if(op1>=1000000 && op1<2000000){
                E=IntToHex(0x41+op1/1000000,2)+" ";
        }
//dec reg8
        if(op1>=2000000 && op1<3000000){
                E=IntToHex(0xfe,2)+" "+IntToHex(0xc8+op1/1000000,2)+" ";
        }
//dec mem
        else if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x88+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x48+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x08+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xFE,2)+" "+IntToHex(0x08+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }

        return E;
}

AnsiString TKompiliavimas::AsmNeg(int op1, int op2){
        return AsmMulDiv(op1, op2,0x18);
}

AnsiString TKompiliavimas::AsmCmp(int op1, int op2){

        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x38);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x3D,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x3C,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMemS(op1,op2,0x38);
        }
        return E;
}

AnsiString TKompiliavimas::AsmAas(int op1, int op2){
        AnsiString E;
        E=IntToHex(0x3F,2);
        return E;
}

AnsiString TKompiliavimas::AsmDas(int op1, int op2){
        AnsiString E;
        E=IntToHex(0x2F,2);
        return E;
}

AnsiString TKompiliavimas::AsmMul(int op1, int op2){
        return AsmMulDiv(op1, op2,0x20);
}

AnsiString TKompiliavimas::AsmImul(int op1, int op2){
        return AsmMulDiv(op1, op2,0x28);
}

AnsiString TKompiliavimas::AsmAam(int op1, int op2){
        AnsiString E;
        E=IntToHex(0xD4,2)+" "+IntToHex(0x0A,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmDiv(int op1, int op2){
        return AsmMulDiv(op1, op2,0x30);
}

AnsiString TKompiliavimas::AsmIdiv(int op1, int op2){
        return AsmMulDiv(op1, op2,0x38);
}

AnsiString TKompiliavimas::AsmMulDiv(int op1, int op2, int type){
        AnsiString E;
//reg16
        if(op1>=1000000 && op1<2000000){
                E=IntToHex(0xF7,2)+" "+IntToHex(0xC0+type+(op1/1000000),2)+" ";
        }
//reg8
        else if(op1>=2000000 && op1<3000000){
                E=IntToHex(0xF6,2)+" "+IntToHex(0xC0+type+(op1/1000000),2)+" ";
        }
//mem8
        else if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x80+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x40+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x00+type+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x00+type+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }

        return E;
}

AnsiString TKompiliavimas::AsmAad(int op1, int op2){
        AnsiString E;
        E=IntToHex(0xD5,2)+" "+IntToHex(0x0A,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmCbw(int op1, int op2){
        AnsiString E;
        E=IntToHex(0x98,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmCwd(int op1, int op2){
        AnsiString E;
        E=IntToHex(0x99,2)+" ";
        return E;
}

AnsiString TKompiliavimas::AsmNot(int op1, int op2){
        AnsiString E;
//reg16
        if(op1>=1000000 && op1<2000000){
                E=IntToHex(0xF7,2)+" "+IntToHex(0xD0+(op1/1000000),2)+" ";
        }
//reg8
        else if(op1>=2000000 && op1<3000000){
                E=IntToHex(0xF6,2)+" "+IntToHex(0xD0+(op1/1000000),2)+" ";
        }
//mem8
        else if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x90+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x50+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x10+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x18+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }

        return E;
}

AnsiString TKompiliavimas::AsmShift(int op1, int op2, int type){
        AnsiString E;
        int temp;
        if(op2==2000001){
                temp=0xD2;
        }
        else{
                temp=0xD0;
        }
//reg16
        if(op1>=1000000 && op1<2000000){
                E=IntToHex(temp+1,2)+" "+IntToHex(0xC0+type+(op1/1000000),2)+" ";
        }
//reg8
        else if(op1>=2000000 && op1<3000000){
                E=IntToHex(temp,2)+" "+IntToHex(0xC0+type+(op1/1000000),2)+" ";
        }
//mem8
        else if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(temp,2)+" "+IntToHex(0x80+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(temp,2)+" "+IntToHex(0x40+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x00+type+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xF6,2)+" "+IntToHex(0x00+type+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }

        return E;
}

AnsiString TKompiliavimas::AsmShlSal(int op1, int op2){
        return AsmShift(op1,op2,0x20);
}

AnsiString TKompiliavimas::AsmShr(int op1, int op2){
        return AsmShift(op1,op2,0x28);
}

AnsiString TKompiliavimas::AsmSar(int op1, int op2){
        return AsmShift(op1,op2,0x38);
}

AnsiString TKompiliavimas::AsmRol(int op1, int op2){
        return AsmShift(op1,op2,0x00);
}

AnsiString TKompiliavimas::AsmRor(int op1, int op2){
        return AsmShift(op1,op2,0x08);
}

AnsiString TKompiliavimas::AsmRcl(int op1, int op2){
        return AsmShift(op1,op2,0x10);
}

AnsiString TKompiliavimas::AsmRcr(int op1, int op2){
        return AsmShift(op1,op2,0x18);
}

AnsiString TKompiliavimas::AsmRegMemToReg(int op1, int op2, int type){
        AnsiString E;
//reg16 to reg16
        if((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)){
                E=IntToHex(type+0x03,2)+" "+IntToHex(0xc0+((op1/1000000)<<3)+(op2%1000000),2)+" ";
        }
//reg8 to reg8
        else if((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)){
                E=IntToHex(type+0x02,2)+" "+IntToHex(0xc0+((op1/1000000)<<3)+(op2%1000000),2)+" ";
        }
//mem to reg16
        else if((op1>=1000000 && op1<2000000) && (op2>=4000000)){
                int mod;
                mod=op2/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(type+0x03,2)+" "+IntToHex(0x80+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(type+0x03,2)+" "+IntToHex(0x40+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(type+0x03,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(type+0x03,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+6,2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
        }
//mem to reg8
        else if((op1>=2000000 && op1<3000000) && (op2>=4000000)){
                int mod;
                mod=op2/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(type+0x02,2)+" "+IntToHex(0x80+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(type+0x02,2)+" "+IntToHex(0x40+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" "+IntToHex((op2%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(type+0x02,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+((op2%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(type+0x02,2)+" "+IntToHex(0x00+((op1%1000000)<<3)+6,2)+" "+IntToHex((op2%100000)%256,2)+" "+IntToHex((op2%100000)/256,2)+" ";
                }
        }
        return E;
}

AnsiString TKompiliavimas::AsmImToRegMemS(int op1, int op2, int type){
        AnsiString E;
//im16 to reg16
        if((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)){
                E=IntToHex(type+0x83,2)+" "+IntToHex(0xc0+type+op1%1000000,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to reg8
        else if((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)){
                E=IntToHex(0x80,2)+" "+IntToHex(0xc0+type+op1%1000000,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to mem
        else if(op2<1000000 && op2>=0 && op2>=256 && op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x83,2)+" "+IntToHex(0x80+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x83,2)+" "+IntToHex(0x40+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x83,2)+" "+IntToHex(0x00+type+((op1%1000000)/100000),2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x83,2)+" "+IntToHex(0x00+type+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
        }
//im8 to mem
        else if(op2<1000000 && op2>=0 && op2<256 && op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x82,2)+" "+IntToHex(0x80+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x82,2)+" "+IntToHex(0x40+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x82,2)+" "+IntToHex(0x00+type+((op1%1000000)/100000),2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x82,2)+" "+IntToHex(0x00+type+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" ";
                }
        }
        return E;
}

AnsiString TKompiliavimas::AsmImToRegMem(int op1, int op2, int type){
        AnsiString E;
//im16 to reg16
        if((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)){
                E=IntToHex(type+0x81,2)+" "+IntToHex(0xc0+type+op1%1000000,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to reg8
        else if((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)){
                E=IntToHex(0x80,2)+" "+IntToHex(0xc0+type+op1%1000000,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to mem
        else if(op2<1000000 && op2>=0 && op2>=256 && op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x81,2)+" "+IntToHex(0x80+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x81,2)+" "+IntToHex(0x40+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x81,2)+" "+IntToHex(0x00+type+((op1%1000000)/100000),2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x81,2)+" "+IntToHex(0x00+type+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
                }
        }
//im8 to mem
        else if(op2<1000000 && op2>=0 && op2<256 && op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0x80,2)+" "+IntToHex(0x80+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0x80,2)+" "+IntToHex(0x40+type+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0x80,2)+" "+IntToHex(0x00+type+((op1%1000000)/100000),2)+" "+IntToHex(op2%256,2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0x80,2)+" "+IntToHex(0x00+type+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" "+IntToHex(op2%256,2)+" ";
                }
        }
        return E;
}

AnsiString TKompiliavimas::AsmAnd(int op1, int op2){
        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x20);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x05,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x04,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMem(op1,op2,0x20);
        }
        return E;
}

AnsiString TKompiliavimas::AsmOr(int op1, int op2){
        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x08);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x05,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x04,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMem(op1,op2,0xC0);
        }
        return E;
}

AnsiString TKompiliavimas::AsmXor(int op1, int op2){
        AnsiString E;
//reg16 to reg16, reg8 to reg8, mem to reg16, mem to reg8
        if(((op2>=1000000 && op2<2000000) && (op1>=1000000 && op1<2000000)) ||
        ((op2>=2000000 && op2<3000000) && (op1>=2000000 && op1<3000000)) ||
        ((op1>=1000000 && op1<2000000) && (op2>=4000000)) ||
        ((op1>=2000000 && op1<3000000) && (op2>=4000000))){
                E=AsmRegMemToReg(op1, op2, 0x30);
        }
//im16 to ax
        else if(op1==1000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x05,2)+" "+IntToHex(op2%256,2)+" "+IntToHex(op2/256,2)+" ";
        }
//im8 to al
        else if(op1==2000000 && op2<1000000 && op2>=0){
                E=IntToHex(0x04,2)+" "+IntToHex(op2%256,2)+" ";
        }
//im16 to reg16, im8 to reg8, im16 to mem, im8 to mem
        else if(((op1>1000000 && op1<2000000) && (op2<1000000 && op2>=0)) ||
        ((op1>2000000 && op1<3000000) && (op2<1000000 && op2>=0)) ||
        (op2<1000000 && op2>=0 && op2>=256 && op1>=4000000) ||
        (op2<1000000 && op2>=0 && op2<256 && op1>=4000000)){
                E=AsmImToRegMem(op1,op2,0x34);
        }
        return E;
}

AnsiString TKompiliavimas::AsmJmp(int op1, int op2){
        AnsiString E="";
//jump indirect within segment
        if(op1>=4000000){
                int mod;
                mod=op1/1000000;
                if(mod==4 || mod==7){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0xA0+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
                else if(mod==5 || mod==8){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0x60+((op1%1000000)/100000),2)+" "+IntToHex((op1%100000)%256,2)+" ";
                }
                else if(mod==6 || mod==9){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0x20+((op1%1000000)/100000),2)+" ";
                }
                else if(mod==10){
                        E=IntToHex(0xFF,2)+" "+IntToHex(0x20+6,2)+" "+IntToHex((op1%100000)%256,2)+" "+IntToHex((op1%100000)/256,2)+" ";
                }
        }
        else if(op1<1000000 && op1<256){
                E=IntToHex(0xEB,2)+" "+IntToHex(op1,2)+" ";
        }
        else if(op1<1000000 && op1>=256){
                E=IntToHex(0xE9,2)+" "+IntToHex(op1%256,2)+" "+IntToHex(op1/256,2)+" ";
        }
        return E;
}

AnsiString TKompiliavimas::AsmJmp(AnsiString op1){
        AnsiString E="";
                if(op1!=""){
                        E=IntToHex(0xEB,2)+" -- -- ";
                }
        return E;
}



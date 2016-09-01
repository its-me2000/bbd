#include <vcl.h>
//---------------------------------------------------------------------------
class TZyme{
        public:
        AnsiString zyme;
        int adresas;
};



class TOperandas{
        private:
        unsigned int operandas;
        public:
        TOperandas(AnsiString op);
        void irasytiOp(AnsiString op);
        void setReg(unsigned int reg, bool w);
        void setSeg(unsigned int seg);
        void setMem(unsigned int mem, unsigned int disp8, unsigned int disp16);
        void setMem(unsigned int mem, unsigned int disp8);
        void setMem(unsigned int mem);
        void setDisp(unsigned int disp8);
        void setDisp(unsigned int disp8, unsigned int disp16);
        void setData(unsigned int data8, unsigned int data16);
        void setData(unsigned int data8);
        unsigned int getReg();
        unsigned int getRM();
        AnsiString getRM(unsigned int reg);
        AnsiString getDisp(bool w);
        AnsiString getData(bool w);
        bool is();
        bool isReg();
        bool isMem();
        bool isSeg();
        bool is8b();
        bool isDisp();
        bool isDisp16();
        bool isData();
        bool isData16();
};
TOperandas::TOperandas(AnsiString op){
        irasytiOp(op);
}
unsigned int TOperandas::getReg(){
        unsigned int temp;
        temp=(operandas>>16)&0x000000FF;
        return temp;
}
unsigned int TOperandas::getRM(){
        unsigned int temp;
        temp=(operandas>>16)&0x000000FF;
        if(isReg())
                temp=temp|0x000000C0;
        else if(isDisp()){
                if(isDisp16())
                        temp=temp|0x00000080;
                else
                        temp=temp|0x00000040;
        }
        return temp;
}
AnsiString TOperandas::getRM(unsigned int reg){
        AnsiString E="";
        unsigned int temp;
        if(isMem()){
                temp=getRM()|(reg<<3);
                E=IntToHex((int)temp,2);
        }else if(isDisp16() || isReg()){
                if(isDisp16())
                        temp=0x00000006|(reg<<3);
                else
                        temp=(0x000000C0|getReg())|(reg<<3);
                E=IntToHex((int)temp,2);
        }
        if(isDisp()){
                if(isDisp16())
                        E=E+" "+IntToHex((int)((operandas>>8)&0x000000FF),2)+" "+IntToHex((int)(operandas&0x000000FF),2);
                else if(isMem())
                        E=E+" "+IntToHex((int)((operandas>>8)&0x000000FF),2);
        }
        return E;
}
AnsiString TOperandas::getData(bool w){
        AnsiString E;
        E=IntToHex((int) ((operandas>>8)&0x000000FF),2 );
        if(isData16() && w)
                E=E+" "+IntToHex((int)(operandas&0x000000FF),2);
        else if(!isData16() && w)
                E=E+" 00";
        return E;
}
AnsiString TOperandas::getDisp(bool w){
        AnsiString E;
        E=IntToHex((int) ((operandas>>8)&0x000000FF),2 );
        if(isDisp16() && w)
                E=E+" "+IntToHex((int)(operandas&0x000000FF),2);
        return E;
}
bool TOperandas::is(){
        if(operandas==0x00000000)
                return false;
        else
                return true;
}
bool TOperandas::isReg(){
        if((operandas&0xC0000000)!=0)
                return true;
        else
                return false;
}
bool TOperandas::isMem(){
        if((operandas&0x10000000)!=0)
                return true;
        else
                return false;
}
bool TOperandas::isSeg(){
        if((operandas&0x20000000)!=0)
                return true;
        else
                return false;
}
bool TOperandas::is8b(){
        if((operandas&0x40000000)!=0)
                return true;
        else
                return false;
}
bool TOperandas::isDisp(){
        if((operandas&0x04000000)!=0)
                return true;
        else
                return false;
}
bool TOperandas::isDisp16(){
        if((operandas&0x08000000)!=0)
                return true;
        else
                return false;
}
bool TOperandas::isData(){
        if((operandas&0x01000000)!=0)
                return true;
        else
                return false;
}
bool TOperandas::isData16(){
        if((operandas&0x02000000)!=0)
                return true;
        else
                return false;
}

void TOperandas::setReg(unsigned int reg, bool w){
        operandas=operandas|(w?0x80000000:0x40000000);
        operandas=operandas|((reg<<16)&0x00FF0000);
}
void TOperandas::setSeg(unsigned int seg){
        operandas=operandas|0x20000000;
        operandas=operandas|((seg<<16)&0x00FF0000);
}
void TOperandas::setMem(unsigned int mem){
        operandas=operandas|0x10000000;
        operandas=operandas|((mem<<16)&0x00FF0000);
}
void TOperandas::setMem(unsigned int mem, unsigned int disp8){
        setMem(mem);
        setDisp(disp8);
}
void TOperandas::setMem(unsigned int mem, unsigned int disp8, unsigned int disp16){
        setMem(mem);
        setDisp(disp8, disp16);
}
void TOperandas::setDisp(unsigned int disp8){
        operandas=operandas|0x04000000;
        operandas=operandas|((disp8<<8)&0x0000FF00);
}
void TOperandas::setDisp(unsigned int disp8, unsigned int disp16){
        setDisp(disp8);
        operandas=operandas|0x08000000;
        operandas=operandas|(disp16&0x000000FF);
}
void TOperandas::setData(unsigned int data8){
        operandas=operandas|0x01000000;
        operandas=operandas|((data8<<8)&0x0000FF00);
}
void TOperandas::setData(unsigned int data8, unsigned int data16){
        setData(data8);
        operandas=operandas|0x02000000;
        operandas=operandas|(data16&0x000000FF);
}

void TOperandas::irasytiOp(AnsiString op){
        operandas=0x00000000;
        if(op=="ax"){
                setReg(0x00000000,1);
        }else if(op=="cx"){
                setReg(0x00000001,1);
        }else if(op=="dx"){
                setReg(0x00000002,1);
        }else if(op=="bx"){
                setReg(0x00000003,1);
        }else if(op=="sp"){
                setReg(0x00000004,1);
        }else if(op=="bp"){
                setReg(0x00000005,1);
        }else if(op=="si"){
                setReg(0x00000006,1);
        }else if(op=="di"){
                setReg(0x00000007,1);
        }else if(op=="al"){
                setReg(0x00000000,0);
        }else if(op=="cl"){
                setReg(0x00000001,0);
        }else if(op=="dl"){
                setReg(0x00000002,0);
        }else if(op=="bl"){
                setReg(0x00000003,0);
        }else if(op=="ah"){
                setReg(0x00000004,0);
        }else if(op=="ch"){
                setReg(0x00000005,0);
        }else if(op=="dh"){
                setReg(0x00000006,0);
        }else if(op=="bh"){
                setReg(0x00000007,0);
        }else if(op=="es"){
                setSeg(0x00000000);
        }else if(op=="cs"){
                setSeg(0x00000001);
        }else if(op=="ss"){
                setSeg(0x00000002);
        }else if(op=="ds"){
                setSeg(0x00000003);
        }else if(op.Length()==3 && ("0x"+op.SubString(1,2)).ToIntDef(-1)>=0 && op.SubString(3,1)=="h"){
                setData((unsigned int)("0x"+op.SubString(1,2)).ToInt());
        }else if(op=="[bx+si]"){
                setMem(0x00000000);
        }else if(op=="[bx+di]"){
                setMem(0x00000001);
        }else if(op=="[bp+si]"){
                setMem(0x00000002);
        }else if(op=="[bp+di]"){
                setMem(0x00000003);
        }else if(op=="[si]"){
                setMem(0x00000004);
        }else if(op=="[di]"){
                setMem(0x00000005);
        }else if(op=="[bp]"){
                setMem(0x00000006);
        }else if(op=="[bx]"){
                setMem(0x00000007);
        }else if(op.Length()==5 && op.SubString(1,1)=="["
        && op.SubString(5,1)=="]" && (("0x"+op.SubString(2,2)).ToIntDef(-1)>=0)){
                setDisp((unsigned int)("0x"+op.SubString(2,2)).ToInt()&0x000000FF );
        }else if(op.Length()==5 && (("0x"+op.SubString(1,4)).ToIntDef(-1)>=0)){
                setData((unsigned int)(("0x"+op.SubString(3,2)).ToInt())&0x000000FF,(("0x"+op.SubString(1,2)).ToInt())&0x000000FF );
        }else if(op.Length()==7 && op.SubString(1,1)=="[" && op.SubString(6,2)=="h]" && ("0x"+op.SubString(2,4)).ToIntDef(-1)>=0 ){
                setDisp((unsigned int)(("0x"+op.SubString(4,2)).ToInt())&0x000000FF,(("0x"+op.SubString(2,2)).ToInt())&0x000000FF );
        }else if(op.Length()==8){
                if(("0x"+op.SubString(5,2)).ToIntDef(-1)>=0){
                        if(op.SubString(1,4)=="[si+" && op.SubString(7,2)=="h]"){
                                setMem(0x00000004,(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }else if(op.SubString(1,4)=="[di+" && op.SubString(7,2)=="h]"){
                                setMem(0x00000005,(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }else if(op.SubString(1,4)=="[bp+" && op.SubString(7,2)=="h]"){
                                setMem(0x00000006,(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }else if(op.SubString(1,4)=="[bx+" && op.SubString(7,2)=="h]"){
                                setMem(0x00000007,(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }
                }
        }else if(op.Length()==10){
                if(("0x"+op.SubString(5,4)).ToIntDef(-1)>=0){
                        if(op.SubString(1,4)=="[si+" && op.SubString(9,2)=="h]"){
                                setMem(0x00000004,(unsigned int)("0x"+op.SubString(7,2)).ToInt(),(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }else if(op.SubString(1,4)=="[di+" && op.SubString(9,2)=="h]"){
                                setMem(0x00000005,(unsigned int)("0x"+op.SubString(7,2)).ToInt(),(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }else if(op.SubString(1,4)=="[bp+" && op.SubString(9,2)=="h]"){
                                setMem(0x00000006,(unsigned int)("0x"+op.SubString(7,2)).ToInt(),(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }else if(op.SubString(1,4)=="[bx+" && op.SubString(9,2)=="h]"){
                                setMem(0x00000007,(unsigned int)("0x"+op.SubString(7,2)).ToInt(),(unsigned int)("0x"+op.SubString(5,2)).ToInt());
                        }
                }
        }else if(op.Length()==11){
                if(("0x"+op.SubString(8,2)).ToIntDef(-1)>=0){
                        if(op.SubString(1,7)=="[bx+si+" && op.SubString(10,2)=="h]"){
                                setMem(0x00000000,(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }else if(op.SubString(1,7)=="[bx+di+" && op.SubString(10,2)=="h]"){
                                setMem(0x00000001,(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }else if(op.SubString(1,7)=="[bp+si+" && op.SubString(10,2)=="h]"){
                                setMem(0x00000002,(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }else if(op.SubString(1,7)=="[bp+di+" && op.SubString(10,2)=="h]"){
                                setMem(0x00000003,(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }
                }
        }else if(op.Length()==13){
                if(("0x"+op.SubString(8,4)).ToIntDef(-1)>=0){
                        if(op.SubString(1,7)=="[bx+si+" && op.SubString(12,2)=="h]"){
                                setMem(0x00000000,(unsigned int)("0x"+op.SubString(10,2)).ToInt(),(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }else if(op.SubString(1,7)=="[bx+di+" && op.SubString(12,2)=="h]"){
                                setMem(0x00000001,(unsigned int)("0x"+op.SubString(10,2)).ToInt(),(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }else if(op.SubString(1,7)=="[bp+si+" && op.SubString(12,2)=="h]"){
                                setMem(0x00000002,(unsigned int)("0x"+op.SubString(10,2)).ToInt(),(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }else if(op.SubString(1,7)=="[bp+di+" && op.SubString(12,2)=="h]"){
                                setMem(0x00000003,(unsigned int)("0x"+op.SubString(10,2)).ToInt(),(unsigned int)("0x"+op.SubString(8,2)).ToInt());
                        }
                }
        }
}
AnsiString Kompiliuoti(AnsiString komanda, AnsiString op1, AnsiString op2);
TStringList* Kompiliuoti2(TStringList *MasKodas, TList *Zymes, TList *Jumps);

//------------------------------
 TStringList* Kompiliuoti2(TStringList *MasKodas, TList *Zymes, TList *Jumps){
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
                                                disp=(Zyme->adresas - Jump->adresas)&0x0000FFFF;
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
                                                disp=(Zyme->adresas - Jump->adresas)&0x000000FF;
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
//----------------------------------------------

//---------------------------------------------------------------------------
AnsiString Kompiliuoti(AnsiString komanda, AnsiString op1, AnsiString op2){
        TOperandas *operandas1;
        TOperandas *operandas2;
        operandas1 = new TOperandas(op1);
        operandas2 = new TOperandas(op2);

        AnsiString ByteCode="";

        if(komanda=="mov"){
                if(operandas1->isReg() && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000088|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && operandas2->isMem()){
                        ByteCode=IntToHex(0x0000008A|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if(operandas1->isMem() && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000088|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && operandas2->isData()){
                        ByteCode=IntToHex((int)((0x000000B0|(operandas1->is8b()?0x00000000:0x00000008))|(operandas1->getReg())),2)+" "+operandas2->getData(!operandas1->is8b());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex(0x000000C6|(operandas2->isData16()?0x00000001:0x00000000),2)+" "+
                        operandas1->getRM(0x00000000)+" "+operandas2->getData(operandas2->isData16());
                }else if(operandas1->isReg() && operandas2->isDisp16()){
                        if(operandas1->getReg()==0x00000000)
                                ByteCode=IntToHex(0x000000A0|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+operandas2->getDisp(1);
                        else
                                ByteCode=IntToHex(0x0000008A|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+operandas2->getRM(operandas1->getReg());
                }else if(operandas1->isDisp16() && operandas2->isReg()){
                        if(operandas2->getReg()==0x00000000)
                                ByteCode=IntToHex(0x000000A2|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+operandas1->getDisp(1);
                        else
                                ByteCode=IntToHex(0x00000088|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isSeg() && (operandas2->isReg() || operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x0000008E,2)+" "+operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isReg() || operandas1->isMem()) && operandas2->isSeg()){
                        ByteCode=IntToHex(0x0000008C,2)+" "+operandas1->getRM(operandas2->getReg());
                }
        }else if(komanda=="push" && !operandas2->is()){
                if(operandas1->isReg() && !operandas1->is8b()){
                        ByteCode=IntToHex((int)(0x00000050|operandas1->getReg()),2);
                }else if(operandas1->isMem() || operandas1->isDisp16()){
                        ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000006);
                }else if(operandas1->isSeg()){
                        ByteCode=IntToHex((int)(0x00000006|(operandas1->getReg())<<3),2);
                }
        }else if(komanda=="pop" && !operandas2->is()){
                if(operandas1->isReg() && !operandas1->is8b()){
                        ByteCode=IntToHex((int)(0x00000058|operandas1->getReg()),2);
                }else if(operandas1->isMem() || operandas1->isDisp16()){
                        ByteCode=IntToHex(0x0000008F,2)+" "+operandas1->getRM(0x00000000);
                }else if(operandas1->isSeg()){
                        ByteCode=IntToHex((int)(0x00000007|(operandas1->getReg())<<3),2);
                }
        }else if(komanda=="xchg"){
                if(operandas1->isReg() && operandas2->isReg()){
                        if(operandas1->getReg()==0x00000000 && !operandas1->is8b() && !operandas2->is8b()){
                                ByteCode=IntToHex((int)(0x00000090|(operandas2->getReg())),2);
                        }else if(operandas2->getReg()==0x00000000 && !operandas1->is8b() && !operandas2->is8b()){
                                ByteCode=IntToHex((int)(0x00000090|(operandas1->getReg())),2);
                        }else{
                                ByteCode=IntToHex((int)(0x00000086|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(operandas2->getReg());
                        }
                }else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex((int)(0x00000086|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex((int)(0x00000086|(operandas2->is8b()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(operandas2->getReg());
                }
        }else if(komanda=="inb"){
                if(operandas1->isData() && !operandas2->is())
                        ByteCode=IntToHex(0x000000E4,2)+" "+operandas1->getData(0);
                else if(!operandas1->is() && !operandas2->is())
                        ByteCode=IntToHex(0x000000EC,2);
        }else if(komanda=="inw"){
                if(operandas1->isData() && !operandas2->is())
                        ByteCode=IntToHex(0x000000E5,2)+" "+operandas1->getData(1);
                else if(!operandas1->is() && !operandas2->is())
                        ByteCode=IntToHex(0x000000ED,2);
        }else if(komanda=="outb"){
                if(operandas1->isData() && !operandas2->is())
                        ByteCode=IntToHex(0x000000E6,2)+" "+operandas1->getData(0);
                else if(!operandas1->is() && !operandas2->is())
                        ByteCode=IntToHex(0x000000EE,2);
        }else if(komanda=="outw"){
                if(operandas1->isData() && !operandas2->is())
                        ByteCode=IntToHex(0x000000E7,2)+" "+operandas1->getData(1);
                else if(!operandas1->is() && !operandas2->is())
                        ByteCode=IntToHex(0x000000EF,2);
        }else if(komanda=="xlat"){
                ByteCode=IntToHex(0x000000D7,2);
        }else if(komanda=="lea" && operandas1->isReg() && !operandas1->is8b() && (operandas2->isMem() || operandas2->isDisp16())){
                ByteCode=IntToHex(0x0000008D,2)+" "+operandas2->getRM(operandas1->getReg());
        }else if(komanda=="lds" && operandas1->isReg() && !operandas1->is8b() && (operandas2->isMem() || operandas2->isDisp16())){
                ByteCode=IntToHex(0x000000C5,2)+" "+operandas2->getRM(operandas1->getReg());
        }else if(komanda=="les"  && operandas1->isReg() && !operandas1->is8b() && (operandas2->isMem() || operandas2->isDisp16())){
                ByteCode=IntToHex(0x000000C4,2)+" "+operandas2->getRM(operandas1->getReg());
        }else if(komanda=="lahf"){
                ByteCode=IntToHex(0x0000009F,2);
        }else if(komanda=="sahf"){
                ByteCode=IntToHex(0x0000009E,2);
        }else if(komanda=="pushf"){
                ByteCode=IntToHex(0x0000009C,2);
        }else if(komanda=="popf"){
                ByteCode=IntToHex(0x0000009D,2);
        }else if(komanda=="add"){
                if(operandas1->isReg() && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000000|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000000|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000000|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex(0x00000080+(operandas2->isData16()?0x00000001:0x00000000),2)+" "+operandas1->getRM(0)+" "+operandas2->getData(operandas2->isData16()?0x00000001:0x00000000);
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000)
                                ByteCode=IntToHex((int)(0x00000004|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+
                                operandas2->getData(!operandas1->is8b());
                        else if(!operandas1->is8b() && operandas2->isData16())
                                ByteCode=IntToHex(0x00000081,2)+" "+operandas1->getRM(0x00000000)+" "+operandas2->getData(1);
                        else if(!operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000083,2)+" "+operandas1->getRM(0x00000000)+" "+operandas2->getData(0);
                        else if(operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000080,2)+" "+operandas1->getRM(0x00000000)+" "+operandas2->getData(0);
                }
        }else if(komanda=="adc"){
                if(operandas1->isReg() && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000010|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000010|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000010|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex(0x00000080+(operandas2->isData16()?0x00000001:0x00000000),2)+" "+operandas1->getRM(2)+" "+operandas2->getData(operandas2->isData16()?0x00000001:0x00000000);
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000)
                                ByteCode=IntToHex((int)(0x00000014|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+
                                operandas2->getData(!operandas1->is8b());
                        else if(!operandas1->is8b() && operandas2->isData16())
                                ByteCode=IntToHex(0x00000081,2)+" "+operandas1->getRM(0x00000002)+" "+operandas2->getData(1);
                        else if(!operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000083,2)+" "+operandas1->getRM(0x00000002)+" "+operandas2->getData(0);
                        else if(operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000080,2)+" "+operandas1->getRM(0x00000002)+" "+operandas2->getData(0);
                }
        }else if(komanda=="incb" && (operandas1->is8b() || operandas1->isMem()  || operandas1->isDisp16()) && !operandas2->is()){
                ByteCode=IntToHex(0x000000FE,2)+" "+operandas1->getRM(0x00000000);
        }else if(komanda=="incw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16())){
                //ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000000);
                if(operandas1->isMem() || operandas1->isDisp16())
                        ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000000);
                else if(operandas1->isReg() && !operandas1->is8b())
                        ByteCode=IntToHex((int)(0x00000040|operandas1->getReg()),2);
        }else if(komanda=="aaa"){
                ByteCode=IntToHex(0x00000037,2);
        }else if(komanda=="daa"){
                ByteCode=IntToHex(0x00000027,2);
        }else if(komanda=="sub"){
                if(operandas1->isReg() && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000028|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000028|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000028|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex(0x00000080+(operandas2->isData16()?0x00000001:0x00000000),2)+" "+operandas1->getRM(5)+" "+operandas2->getData(operandas2->isData16()?0x00000001:0x00000000);
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000)
                                ByteCode=IntToHex((int)(0x0000002C|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+
                                operandas2->getData(!operandas1->is8b());
                        else if(!operandas1->is8b() && operandas2->isData16())
                                ByteCode=IntToHex(0x00000081,2)+" "+operandas1->getRM(0x00000005)+" "+operandas2->getData(1);
                        else if(!operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000083,2)+" "+operandas1->getRM(0x00000005)+" "+operandas2->getData(0);
                        else if(operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000080,2)+" "+operandas1->getRM(0x00000005)+" "+operandas2->getData(0);
                }
        }else if(komanda=="sbb"){
                if(operandas1->isReg() && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000018|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000018|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000018|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex(0x00000080+(operandas2->isData16()?0x00000001:0x00000000),2)+" "+operandas1->getRM(3)+" "+operandas2->getData(operandas2->isData16()?0x00000001:0x00000000);
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000)
                                ByteCode=IntToHex((int)(0x0000001C|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+
                                operandas2->getData(!operandas1->is8b());
                        else if(!operandas1->is8b() && operandas2->isData16())
                                ByteCode=IntToHex(0x00000081,2)+" "+operandas1->getRM(0x00000003)+" "+operandas2->getData(1);
                        else if(!operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000083,2)+" "+operandas1->getRM(0x00000003)+" "+operandas2->getData(0);
                        else if(operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000080,2)+" "+operandas1->getRM(0x00000003)+" "+operandas2->getData(0);
                }
        }else if(komanda=="decb" && (operandas1->is8b() || operandas1->isMem() || operandas1->isDisp16()) && !operandas2->is()){
                ByteCode=IntToHex(0x000000FE,2)+" "+operandas1->getRM(0x00000001);
        }else if(komanda=="decw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16())){
                if(operandas1->isMem() || operandas1->isDisp16())
                        ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000001);
                else if(operandas1->isReg() && !operandas1->is8b())
                        ByteCode=IntToHex((int)(0x00000048|operandas1->getReg()),2);
        }else if(komanda=="negb" &&((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) && !operandas2->is()){
                ByteCode=IntToHex(0x000000F6,2)+" "+operandas1->getRM(0x00000003);
        }else if(komanda=="negw" &&((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) && !operandas2->is()){
                ByteCode=IntToHex(0x000000F7,2)+" "+operandas1->getRM(0x00000003);
        }else if(komanda=="cmp"){
                if(operandas1->isReg() && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000038|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000038|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000038|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex(0x00000080+(operandas2->isData16()?0x00000001:0x00000000),2)+" "+operandas1->getRM(7)+" "+operandas2->getData(operandas2->isData16()?0x00000001:0x00000000);
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000)
                                ByteCode=IntToHex((int)(0x0000003C|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+
                                operandas2->getData(!operandas1->is8b());
                        else if(!operandas1->is8b() && operandas2->isData16())
                                ByteCode=IntToHex(0x00000081,2)+" "+operandas1->getRM(0x00000007)+" "+operandas2->getData(1);
                        else if(!operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000083,2)+" "+operandas1->getRM(0x00000007)+" "+operandas2->getData(0);
                        else if(operandas1->is8b() && !operandas2->isData16())
                                ByteCode=IntToHex(0x00000080,2)+" "+operandas1->getRM(0x00000007)+" "+operandas2->getData(0);
                }
        }else if(komanda=="aas"){
                ByteCode=IntToHex(0x0000003F,2);
        }else if(komanda=="das"){
                ByteCode=IntToHex(0x0000002F,2);
        }else if(komanda=="mulb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F6,2)+" "+operandas1->getRM(0x00000004);
        }else if(komanda=="mulw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F7,2)+" "+operandas1->getRM(0x00000004);
        }else if(komanda=="imulb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F6,2)+" "+operandas1->getRM(0x00000005);
        }else if(komanda=="imulw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F7,2)+" "+operandas1->getRM(0x00000005);
        }else if(komanda=="aam"){
                ByteCode=IntToHex(0x000000D4,2)+" "+IntToHex(0x0000000A,2);
        }else if(komanda=="divb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F6,2)+" "+operandas1->getRM(0x00000006);
        }else if(komanda=="divw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F7,2)+" "+operandas1->getRM(0x00000006);
        }else if(komanda=="idivb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F6,2)+" "+operandas1->getRM(0x00000007);
        }else if(komanda=="idivw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F7,2)+" "+operandas1->getRM(0x00000007);
        }else if(komanda=="aad"){
                ByteCode=IntToHex(0x000000D5,2)+" "+IntToHex(0x0000000A,2);
        }else if(komanda=="cbw"){
                ByteCode=IntToHex(0x00000098,2);
        }else if(komanda=="cwd"){
                ByteCode=IntToHex(0x00000099,2);
        }else if(komanda=="notb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F6,2)+" "+operandas1->getRM(0x00000002);
        }else if(komanda=="notw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                ByteCode=IntToHex(0x000000F7,2)+" "+operandas1->getRM(0x00000002);
        }else if((komanda=="shlb" || komanda=="salb") && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D0,2)+" "+operandas1->getRM(0x00000004);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D2,2)+" "+operandas1->getRM(0x00000004);
        }else if((komanda=="shlw" || komanda=="salw") && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D1,2)+" "+operandas1->getRM(0x00000004);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D3,2)+" "+operandas1->getRM(0x00000004);
        }else if(komanda=="shrb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D0,2)+" "+operandas1->getRM(0x00000005);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D2,2)+" "+operandas1->getRM(0x00000005);
        }else if(komanda=="shrw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D1,2)+" "+operandas1->getRM(0x00000005);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D3,2)+" "+operandas1->getRM(0x00000005);
        }else if(komanda=="sarb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D0,2)+" "+operandas1->getRM(0x00000007);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D2,2)+" "+operandas1->getRM(0x00000007);
        }else if(komanda=="sarw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D1,2)+" "+operandas1->getRM(0x00000007);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D3,2)+" "+operandas1->getRM(0x00000007);
        }else if(komanda=="rolb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D0,2)+" "+operandas1->getRM(0x00000000);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D2,2)+" "+operandas1->getRM(0x00000000);
        }else if(komanda=="rolw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D1,2)+" "+operandas1->getRM(0x00000000);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D3,2)+" "+operandas1->getRM(0x00000000);
        }else if(komanda=="rorb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D0,2)+" "+operandas1->getRM(0x00000001);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D2,2)+" "+operandas1->getRM(0x00000001);
        }else if(komanda=="rorw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D1,2)+" "+operandas1->getRM(0x00000001);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D3,2)+" "+operandas1->getRM(0x00000001);
        }else if(komanda=="rclb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D0,2)+" "+operandas1->getRM(0x00000002);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D2,2)+" "+operandas1->getRM(0x00000002);
        }else if(komanda=="rclw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D1,2)+" "+operandas1->getRM(0x00000002);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D3,2)+" "+operandas1->getRM(0x00000002);
        }else if(komanda=="rcrb" && ((operandas1->isReg() && operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D0,2)+" "+operandas1->getRM(0x00000003);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D2,2)+" "+operandas1->getRM(0x00000003);
        }else if(komanda=="rcrw" && ((operandas1->isReg() && !operandas1->is8b()) || operandas1->isMem() || operandas1->isDisp16()) ){
                if(operandas2->isData() && (operandas2->getData(0)=="01" || operandas2->getData(1)=="00 01"))
                        ByteCode=IntToHex(0x000000D1,2)+" "+operandas1->getRM(0x00000003);
                else if(operandas2->isReg() && operandas2->is8b() && operandas2->getReg()==0x00000001)
                        ByteCode=IntToHex(0x000000D3,2)+" "+operandas1->getRM(0x00000003);
        }else if(komanda=="and"){
                if(operandas1->isReg() && operandas2->isReg())
                        ByteCode=IntToHex(0x00000020|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000022|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000020|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000 && (operandas1->is8b()==!operandas2->isData16()))
                                ByteCode=IntToHex((int)(0x00000024|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas2->getData(!operandas1->is8b());
                        else
                                ByteCode=IntToHex((int)(0x00000080|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(0x00000004)+" "+operandas2->getData(!operandas1->is8b());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex((int)(0x00000080|(operandas2->isData16()?0x00000001:0x00000000)),2)+" "+operandas1->getRM(0x00000004)+" "+operandas2->getData(operandas2->isData16());
                }
        }else if(komanda=="test"){
                if(operandas1->isReg() && operandas2->isReg())
                        ByteCode=IntToHex(0x00000084|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000084|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000084|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000 && (operandas1->is8b()==!operandas2->isData16()))
                                ByteCode=IntToHex((int)(0x000000A8|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas2->getData(!operandas1->is8b());
                        else
                                ByteCode=IntToHex((int)(0x000000F6|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(0x00000000)+" "+operandas2->getData(!operandas1->is8b());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex((int)(0x000000F6|(!operandas2->isData16()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(0x00000000)+" "+operandas2->getData(operandas2->isData16());
                }
        }else if(komanda=="or"){
                if(operandas1->isReg() && operandas2->isReg())
                        ByteCode=IntToHex(0x0000008|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x0000000A|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000008|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000 && (operandas1->is8b()==!operandas2->isData16()))
                                ByteCode=IntToHex((int)(0x0000000C|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas2->getData(!operandas1->is8b());
                        else
                                ByteCode=IntToHex((int)(0x00000080|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(0x00000001)+" "+operandas2->getData(!operandas1->is8b());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex((int)(0x00000080|(!operandas2->isData16()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(0x00000001)+" "+operandas2->getData(operandas2->isData16());
                }
        }else if(komanda=="xor"){
                if(operandas1->isReg() && operandas2->isReg())
                        ByteCode=IntToHex(0x0000032|(operandas1->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                else if(operandas1->isReg() && (operandas2->isMem() || operandas2->isDisp16())){
                        ByteCode=IntToHex(0x00000032|(operandas1->is8b()?0x00000002:0x00000003),2)+" "+
                        operandas2->getRM(operandas1->getReg());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isReg()){
                        ByteCode=IntToHex(0x00000030|(operandas2->is8b()?0x00000000:0x00000001),2)+" "+
                        operandas1->getRM(operandas2->getReg());
                }else if(operandas1->isReg() && operandas2->isData()){
                        if(operandas1->getReg()==0x00000000 && (operandas1->is8b()==!operandas2->isData16()))
                                ByteCode=IntToHex((int)(0x00000034|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas2->getData(!operandas1->is8b());
                        else
                                ByteCode=IntToHex((int)(0x00000080|(operandas1->is8b()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(0x00000006)+" "+operandas2->getData(!operandas1->is8b());
                }else if((operandas1->isMem() || operandas1->isDisp16()) && operandas2->isData()){
                        ByteCode=IntToHex((int)(0x00000080|(!operandas2->isData16()?0x00000000:0x00000001)),2)+" "+operandas1->getRM(0x00000006)+" "+operandas2->getData(operandas2->isData16());
                }
        }else if(komanda=="repz"){
                ByteCode=IntToHex(0x000000F3,2);
        }else if(komanda=="repnz"){
                ByteCode=IntToHex(0x000000F2,2);
        }else if(komanda=="movsb"){
                ByteCode=IntToHex(0x000000A4,2);
        }else if(komanda=="movsw"){
                ByteCode=IntToHex(0x000000A5,2);
        }else if(komanda=="cmpsb"){
                ByteCode=IntToHex(0x000000A6,2);
        }else if(komanda=="cmpsw"){
                ByteCode=IntToHex(0x000000A7,2);
        }else if(komanda=="scasb"){
                ByteCode=IntToHex(0x000000AE,2);
        }else if(komanda=="scasw"){
                ByteCode=IntToHex(0x000000AF,2);
        }else if(komanda=="lodsb"){
                ByteCode=IntToHex(0x000000AC,2);
        }else if(komanda=="lodsw"){
                ByteCode=IntToHex(0x000000AD,2);
        }else if(komanda=="stosb"){
                ByteCode=IntToHex(0x000000AA,2);
        }else if(komanda=="stosw"){
                ByteCode=IntToHex(0x000000AB,2);
        }else if (komanda=="call_near" && !operandas2->is()){
                if(!operandas1->isMem() && operandas1->isDisp16()){
                        ByteCode=IntToHex(0x000000E8,2)+" "+operandas1->getDisp(1);
                }else if(operandas1->isMem() || (operandas1->isReg() && !operandas1->is8b())){
                        ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000002);
                }
        }else if(komanda=="call_far"){
                if(!operandas1->isMem() && operandas1->isDisp16() && !operandas2->isMem() && operandas2->isDisp16()){
                        ByteCode=IntToHex(0x0000009A,2)+" "+operandas2->getDisp(1)+" "+operandas1->getDisp(1);
                }else if((operandas1->isMem() || operandas1->isDisp16()) && !operandas2->is()){
                        ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000003);
                }
        }else if(komanda=="call" && !operandas1->is() && !operandas2->is()){
                ByteCode=IntToHex(0x000000E9,2)+" -- --";
        }else if (komanda=="jmp_near" && !operandas2->is()){
                if(!operandas1->isMem() && operandas1->isDisp16()){
                        ByteCode=IntToHex(0x000000E9,2)+" "+operandas1->getDisp(1);
                }else if(operandas1->isMem() || (operandas1->isReg() && !operandas1->is8b())){
                        ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000004);
                }
        }else if(komanda=="jmp_short" && !operandas2->is() && !operandas1->isMem() && operandas1->isDisp() && !operandas1->isDisp16()){
                ByteCode=IntToHex(0x000000EB,2)+" "+operandas1->getDisp(0);
        }else if(komanda=="jmp_far"){
                if(!operandas1->isMem() && operandas1->isDisp16() && !operandas2->isMem() && operandas2->isDisp16()){
                        ByteCode=IntToHex(0x0000009A,2)+" "+operandas2->getDisp(1)+" "+operandas1->getDisp(1);
                }else if((operandas1->isMem() || operandas1->isDisp16()) && !operandas2->is()){
                        ByteCode=IntToHex(0x000000FF,2)+" "+operandas1->getRM(0x00000005);
                }
        }else if(komanda=="jmp" && !operandas1->is() && !operandas2->is()){
                ByteCode=IntToHex(0x000000E9,2)+" -- --";
        }else if(komanda=="ret_near"){
                if(!operandas1->is() && !operandas2->is()){
                        ByteCode=IntToHex(0x000000C3,2);
                }else if(operandas1->isData16()){
                        ByteCode=IntToHex(0x000000C2,2)+" "+operandas1->getData(1);
                }
        }else if(komanda=="ret_far"){
                if(!operandas1->is() && !operandas2->is()){
                        ByteCode=IntToHex(0x000000CB,2);
                }else if(operandas1->isData16()){
                        ByteCode=IntToHex(0x000000CA,2)+" "+operandas1->getData(1);
                }
        }else if(komanda=="je" || komanda=="jz"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000074,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000074,2)+" --";
                }
        }else if(komanda=="jl" || komanda=="jnge"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x0000007C,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x0000007C,2)+" --";
                }
        }else if(komanda=="jle" || komanda=="jng"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x0000007E,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x0000007E,2)+" --";
                }
        }else if(komanda=="jb" || komanda=="jnae"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000072,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000072,2)+" --";
                }
        }else if(komanda=="jbe" || komanda=="jna"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000076,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000076,2)+" --";
                }
        }else if(komanda=="jp" || komanda=="jpe"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x0000007A,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x0000007A,2)+" --";
                }
        }else if(komanda=="jo"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000070,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000070,2)+" --";
                }
        }else if(komanda=="js"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000078,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000078,2)+" --";
                }
        }else if(komanda=="jne" || komanda=="jnz"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000075,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000075,2)+" --";
                }
        }else if(komanda=="jnl" || komanda=="jge"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x0000007D,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x0000007D,2)+" --";
                }
        }else if(komanda=="jnle" || komanda=="jg"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x0000007F,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x0000007F,2)+" --";
                }
        }else if(komanda=="jnb" || komanda=="jae"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000073,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000073,2)+" --";
                }
        }else if(komanda=="jnbe" || komanda=="ja"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000077,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000077,2)+" --";
                }
        }else if(komanda=="jnp" || komanda=="jpo"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x0000007B,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x0000007B,2)+" --";
                }
        }else if(komanda=="jno"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000071,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000071,2)+" --";
                }
        }else if(komanda=="jns"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x00000079,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x00000079,2)+" --";
                }
        }else if(komanda=="loop"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x000000E2,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x000000E2,2)+" --";
                }
        }else if(komanda=="loope" || komanda=="loopz"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x000000E1,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x000000E1,2)+" --";
                }
        }else if(komanda=="loopne" || komanda=="loopnz"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x000000E0,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x000000E0,2)+" --";
                }
        }else if(komanda=="jcxz"){
                if(operandas1->isDisp() && !operandas1->isDisp16() && !operandas1->isMem()){
                        ByteCode=IntToHex(0x000000E3,2)+" "+operandas1->getDisp(0);
                }else if(!operandas1->is()){
                        ByteCode=IntToHex(0x000000E3,2)+" --";
                }
        }else if(komanda=="int"){
                if(operandas1->isData() && !operandas1->isData16() && operandas1->getData(0)=="03"){
                        ByteCode=IntToHex(0x000000CC,2);
                }else if(operandas1->isData() && !operandas1->isData16()){
                        ByteCode=IntToHex(0x000000CD,2)+" "+operandas1->getData(0);
                }
        }else if(komanda=="into"){
                ByteCode=IntToHex(0x000000CE,2);
        }else if(komanda=="iret"){
                ByteCode=IntToHex(0x000000CF,2);
        }else if(komanda=="clc"){
                ByteCode=IntToHex(0x000000F8,2);
        }else if(komanda=="cmc"){
                ByteCode=IntToHex(0x000000F5,2);
        }else if(komanda=="stc"){
                ByteCode=IntToHex(0x000000F9,2);
        }else if(komanda=="cld"){
                ByteCode=IntToHex(0x000000FC,2);
        }else if(komanda=="std"){
                ByteCode=IntToHex(0x000000FD,2);
        }else if(komanda=="cli"){
                ByteCode=IntToHex(0x000000FA,2);
        }else if(komanda=="sti"){
                ByteCode=IntToHex(0x000000FB,2);
        }else if(komanda=="hlt"){
                ByteCode=IntToHex(0x000000F4,2);
        }else if(komanda=="wait"){
                ByteCode=IntToHex(0x0000009B,2);
        }else if(komanda=="esc" && (operandas1->isMem() || operandas1->isDisp16() || (operandas1->isReg() && !operandas1->is8b()))){
                ByteCode=IntToHex(0x0000D8C0,2);
        }else if(komanda=="lock"){
                ByteCode=IntToHex(0x000000F0,2);
        }
		delete operandas1;
		delete operandas2;
        return ByteCode;
}
//---------------------------------------------------------------------------



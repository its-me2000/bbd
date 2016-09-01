//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TGroupBox *GroupBox2;
        TLabeledEdit *LabeledEdit1;
        TLabeledEdit *LabeledEdit2;
        TLabeledEdit *LabeledEdit3;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TGroupBox *GroupBox3;
        TTrackBar *TrackBar1;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall LabeledEdit1Change(TObject *Sender);
        void __fastcall LabeledEdit3Change(TObject *Sender);
        void __fastcall LabeledEdit2Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm7(TComponent* Owner);
        unsigned int ekrAdresas;
        bool ekrGrafinis;
        unsigned int kbPertraukimas;
        unsigned int kbPortas;
        unsigned int greitis;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TitleFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmTitle *FrmTitle;
//---------------------------------------------------------------------------
__fastcall TFrmTitle::TFrmTitle(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmTitle::Button1Click(TObject *Sender)
{
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TFrmTitle::Button2Click(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

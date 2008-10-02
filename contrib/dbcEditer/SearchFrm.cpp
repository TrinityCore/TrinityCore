//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmSearch *FrmSearch;
//---------------------------------------------------------------------------
__fastcall TFrmSearch::TFrmSearch(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmSearch::btOkClick(TObject *Sender)
{
     ModalResult = mrOk;        
}
//---------------------------------------------------------------------------
void __fastcall TFrmSearch::btCancelClick(TObject *Sender)
{
     ModalResult = mrCancel;        
}
//---------------------------------------------------------------------------

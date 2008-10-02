//---------------------------------------------------------------------------

#ifndef dbceditH
#define dbceditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include "thOpenSource.h"

union TypePtr
{
	long*			l;
	DWORD*			dw;
	WORD*			w;
	char*			c;
	void*			p;
	float*			f;

	TypePtr(void* in) :p(in)
	{
	}
};

#define TAG(x) (DWORD)(  (((DWORD)x&0x0000ff00)<<8)+(((DWORD)x&0x000000ff)<<24)+(((DWORD)x&0x00ff0000)>>8)+(((DWORD)x&0xff000000)>>24) )


//---------------------------------------------------------------------------
class TFrmMain : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TCoolBar *CoolBar1;
        TToolBar *ToolBar1;
        TToolButton *btOpen;
        TToolButton *btSave;
        TStringGrid *sgEdit;
        TOpenDialog *OpenDialog1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *btIntType;
        TMenuItem *btFloatType;
        TMenuItem *btTxtType;
        TImageList *ImageList1;
        TPanel *pnFileName;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TTimer *Timer1;
        TLabel *lbOpState;
        TMenuItem *N4;
        TToolButton *ToolButton3;
        TMenuItem *btRowSave;
        TMenuItem *btColSave;
        TMenuItem *btRowClear;
        TMenuItem *btColClear;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        void __fastcall btOpenClick(TObject *Sender);
        void __fastcall btSaveClick(TObject *Sender);
        void __fastcall btIntTypeClick(TObject *Sender);
        void __fastcall btFloatTypeClick(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall sgEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall sgEditSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall btTxtTypeClick(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall btRowSaveClick(TObject *Sender);
        void __fastcall btColSaveClick(TObject *Sender);
        void __fastcall btRowClearClick(TObject *Sender);
        void __fastcall btColClearClick(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
private:	// User declarations


        thOpenFile  *thOpen;
        bool Term; 

public:		// User declarations
        bool       OpenOk;
       
        AnsiString CurrentOpenFile;
        __fastcall TFrmMain(TComponent* Owner);
        void SaveToFile(const char * pszFileName);
        void __fastcall OpenFileCol(AnsiString FileName,int ColIndex,int ColType);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif

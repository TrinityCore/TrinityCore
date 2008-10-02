//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "thOpenSource.h"
#include "dbcedit.h"
#include "stdio.h"
#include <dir.h>
#include <inifiles.hpp>
#include <process.h>
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall thOpenFile::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall thOpenFile::thOpenFile(bool CreateSuspended)
        : TThread(CreateSuspended)
{
     
}
//---------------------------------------------------------------------------
void __fastcall thOpenFile::Execute()
{
        //---- Place thread code here ----
        //if(!Terminated){
        //  FrmMain->LoadAndModify(FrmMain->OpenDialog1->FileName.c_str());
        //  FrmMain->OpenOk=true;
        //}
        thEnd=false;
        RunOpen();
        FrmMain->OpenOk=true;
        thEnd=true;

}
//---------------------------------------------------------------------------
void __fastcall thOpenFile::RunOpen()
{
        LoadAndModify(FrmMain->OpenDialog1->FileName.c_str());
        //OpenOk=true;
}

void thOpenFile::ReadAndModifyFromBuff(char *pBuff, DWORD dwSize, const char* pszFileName)
{
	char szErrorMsg[MAX_PATH];
	char szNewFileName[MAX_PATH];
	DWORD w;
        TIniFile *ini;
        

	TypePtr p(pBuff);
	if('WDBC' != TAG(*p.dw))
	{
		_snprintf(szErrorMsg, 512, "[%s]Not Wow's dbc file!", pszFileName);
		ShowMessage(szErrorMsg);
		return;
	}
	p.dw++;

	DWORD dwRows, dwCols, dwRowLen, dwTextLen;
	dwRows = *p.dw++;
	dwCols = *p.dw++;
	dwRowLen = *p.dw++;
	dwTextLen = *p.dw++;

        FrmMain->sgEdit->RowCount = dwRows+1;
        FrmMain->sgEdit->ColCount = dwCols+1;

        for(int i=0; i<FrmMain->sgEdit->RowCount; i++){
            FrmMain->sgEdit->Cells[0][i]=IntToStr(i);
            if(Terminated) return;
        }
        //设定列标题
        AnsiString  iniSetFile=ExtractFilePath(Application->ExeName)+"BcdEditer.ini";
        AnsiString SectionName=ExtractFileName(FrmMain->CurrentOpenFile);

        ini = new TIniFile( iniSetFile );
        for(int j=0; j<FrmMain->sgEdit->ColCount; j++){
            FrmMain->sgEdit->Cells[j][0]= ini->ReadString(SectionName,"ColTitle"+IntToStr(j),IntToStr(j));
            //sgEdit->Cells[j][0]=IntToStr(j);
            ColType[j]=ini->ReadInteger(SectionName,"ColType"+IntToStr(j),0);
            if(Terminated) return;
        }
        delete ini;

        //int   *ColType = new int[dwCols];
        
	DWORD dwTextStartPos = dwRows*dwRowLen+20;
	char* pTextPtr = pBuff + dwTextStartPos;
	char pszTemp[MAX_PATH];
	float fTemp;
	long lTemp;
	DWORD i, j;
	BOOL* pbString = new BOOL[dwRows*dwCols];
        float newTmp;
        //int   ColType;

        ini = new TIniFile( iniSetFile );

	for(i=0; i<dwRows; i++)
	{
		for(j=0; j<dwCols; j++)
		{
                    //SleepEx(0,0);
                    if(Terminated) return;
                    lTemp = *p.l;
                    newTmp = *p.f;
                    memcpy(&fTemp, &newTmp, 4);

                    if(j==0)    //ID
                        FrmMain->sgEdit->Cells[j+1][i+1]=IntToStr(lTemp);
                    else{

                        //ColType= ini->ReadInteger(SectionName,"ColType"+IntToStr(j),0);

                        switch (ColType[j+1])
                        {
                          case 0: //整型
                             FrmMain->sgEdit->Cells[j+1][i+1]=IntToStr(lTemp);
                          break;
                          case 1: //浮点
                             FrmMain->sgEdit->Cells[j+1][i+1]=FloatToStr(fTemp);
                          break;
                          case 2: //文本  文本类型只能看，不能编辑
                             if(dwTextStartPos + lTemp < dwSize){
                                 pTextPtr = pBuff + dwTextStartPos + lTemp;
                                 FrmMain->sgEdit->Cells[j+1][i+1]=pTextPtr;
                             }else{
                                 FrmMain->sgEdit->Cells[j+1][i+1]="该列不是文本";
                             }
                          break;
                          default: //整型
                             FrmMain->sgEdit->Cells[j+1][i+1]=IntToStr(lTemp);
                        }
                    }
                    p.c += 4;
                }
        }

	delete [] pbString;
        //delete []  ColType;
        delete ini;

}

void thOpenFile::LoadAndModify(const char * pszFileName)
{
	HANDLE hFile = NULL;
	hFile = CreateFile(pszFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if(hFile == INVALID_HANDLE_VALUE)return;

	DWORD r = 0, nFileSize = 0;
	nFileSize = GetFileSize(hFile, NULL);
	char* pTmpBuf = new char[nFileSize];
	if(pTmpBuf==NULL)
	{
		CloseHandle(hFile);
		return;
	}
	ReadFile(hFile, pTmpBuf, nFileSize, &r, NULL);

	FrmMain->CurrentOpenFile=pszFileName;
        FrmMain->btSave->Enabled=true;

	ReadAndModifyFromBuff(pTmpBuf, nFileSize, pszFileName);

	//SAFE_DELETE_ARRAY(pTmpBuf);
        delete [] pTmpBuf;
        CloseHandle(hFile);

}

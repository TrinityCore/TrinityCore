/*****************************************************************************/
/* StormLibTest.cpp                       Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* This module uses very brutal test methods for StormLib. It extracts all   */
/* files from the archive with Storm.dll and with stormlib and compares them,*/
/* then tries to build a copy of the entire archive, then removes a few files*/
/* from the archive and adds them back, then compares the two archives, ...  */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 25.03.03  1.00  Lad  The first version of StormLibTest.cpp                */
/*****************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#include <io.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <vector>
#include <list>


#define __STORMLIB_SELF__               // Don't use StormLib.lib
#include "StormLib.h"

#pragma warning(disable : 4505)
#pragma comment(lib, "Winmm.lib")

//From Extractor
#include "adtfile.h"
#include "wdtfile.h"
#include "dbcfile.h"
#include "mpq.h"
#include "wmo.h"

//------------------------------------------------------------------------------
// Defines

#define MPQ_BLOCK_SIZE 0x1000

//-----------------------------------------------------------------------------
// from extractor
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef struct{
    char name[64];
    unsigned int id;
}map_id;

map_id * map_ids;
uint16 * areas;
uint16 *areamax;
uint32 map_count;
char output_path[128]=".";
char input_path[1024]=".";
bool hasInputPathParam = false;
char tmp[512];
bool preciseVectorData = false;
//char gamepath[1024];

//Convert function
//bool ConvertADT(char*,char*);

// Constants

//static const char * szWorkDirMaps = ".\\Maps";
static const char * szWorkDirWmo = ".\\buildings";

//static LPBYTE pbBuffer1 = NULL;
//static LPBYTE pbBuffer2 = NULL;

// Local testing functions

static void clreol()
{
    printf("\r                                                                              \r");
}

static const char * GetPlainName(const char * szFileName)
{
    const char * szTemp;

    if((szTemp = strrchr(szFileName, '\\')) != NULL)
        szFileName = szTemp + 1;
    return szFileName;
}
//------------------------------------------------------------------------------
static void ShowProcessedFile(const char * szFileName)
{
    char szLine[80];
    size_t nLength = strlen(szFileName);

    memset(szLine, 0x20, sizeof(szLine));
    szLine[sizeof(szLine)-1] = 0;

    if(nLength > sizeof(szLine)-1)
        nLength = sizeof(szLine)-1;
    memcpy(szLine, szFileName, nLength);
    printf("\r%s\n", szLine);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int ExtractWmo(const std::vector<std::string>& pArchiveNames)
{

    char* szListFile = "";
    char   szLocalFile[MAX_PATH] = "";
    HANDLE hMpq = "";
    BOOL bResult = FALSE;

    //const char* ParsArchiveNames[] = {"patch-2.MPQ", "patch.MPQ", "common.MPQ", "expansion.MPQ"};

    int nError = ERROR_SUCCESS;
    if(szListFile == NULL || *szListFile == 0)
        szListFile = NULL;
    //char tmp[1024];
    //for (size_t i=0; i<4; i++)
    for (size_t i=0; i<pArchiveNames.size(); i++)
    {

        //sprintf(tmp,"%s\\%s", input_path, ParsArchiveNames[i]);
        //if(!SFileOpenArchive(tmp, 0, 0, &hMpq))
        if(!SFileOpenArchive(pArchiveNames[i].c_str(), 0, 0, &hMpq))
            printf("NOT open!!! %s\n",pArchiveNames[i].c_str());

        // Copy files from archive
        if(nError == ERROR_SUCCESS)
        {
            SFILE_FIND_DATA wf;
            HANDLE hFind = SFileFindFirstFile(hMpq,"*.wmo*", &wf, szListFile);
            bResult = TRUE;

            while(hFind != NULL && bResult == TRUE)
            {
                ShowProcessedFile(wf.cFileName);
                SFileSetLocale(wf.lcLocale);
                sprintf(szLocalFile, "%s\\%s", szWorkDirWmo, GetPlainName(wf.cFileName));
                fixnamen(szLocalFile,strlen(szLocalFile));
                FILE * n;
                if ((n = fopen(szLocalFile, "rb"))== NULL)
                {
                    int p = 0;
                    //Select root wmo files
                    const char * rchr = strrchr(GetPlainName(wf.cFileName),0x5f);
                    if(rchr != NULL)
                    {
                        char cpy[4];
                        strncpy((char*)cpy,rchr,4);
                        for (int i=0;i<4;i++)
                        {
                            int m = cpy[i];
                            if(isdigit(m))
                                p++;
                        }
                    }
                    if(p != 3)
                    {
                        //printf("RootWmo!\n");
                        string s = wf.cFileName;
                        WMORoot * froot = new WMORoot(s);
                        if(!froot->open())
                        {
                            printf("Not open RootWmo!!!\n");
                            bResult = SFileFindNextFile(hFind, &wf);
                            continue;
                        }
                         FILE *output=fopen(szLocalFile,"wb");
                        froot->ConvertToVMAPRootWmo(output);
                        int Wmo_nVertices = 0;
                        if(froot->nGroups !=0)
                        {
                            for (int i=0; i<froot->nGroups; i++)
                            {
                                char temp[512];
                                strcpy(temp, wf.cFileName);
                                temp[strlen(wf.cFileName)-4] = 0;
                                char groupFileName[512];
                                sprintf(groupFileName,"%s_%03d.wmo",temp, i);
                                printf("%s\n",groupFileName);
                                //printf("GroupWmo!\n");
                                string s = groupFileName;
                                WMOGroup * fgroup = new WMOGroup(s);
                                if(!fgroup->open())
                                {
                                    printf("Not all open Group file for: %s\n",GetPlainName(wf.cFileName));
                                    bResult = SFileFindNextFile(hFind, &wf);
                                    break;
                                }
                                Wmo_nVertices += fgroup->ConvertToVMAPGroupWmo(output, preciseVectorData);
                            }
                        }
                        fseek(output, 8, SEEK_SET); // store the correct no of vertices
                        fwrite(&Wmo_nVertices,sizeof(int),1,output);
                        fclose(output);
                    }
                } else {
                    fclose(n);
                }
                wf.dwFileFlags &= ~MPQ_FILE_HAS_EXTRA;
                wf.dwFileFlags &= ~MPQ_FILE_EXISTS;
                // Find the next file
                bResult = SFileFindNextFile(hFind, &wf);
            }
            // Delete the extracted file in the case of an error
            if(nError != ERROR_SUCCESS)
                DeleteFile(szLocalFile);
            // Close the search handle
            if(hFind != NULL)
                SFileFindClose(hFind);

        }
    }
    // Close both archives
    if(hMpq != NULL)
        //SFileCloseArchive(hMpq);
        if(nError == ERROR_SUCCESS)
            printf("\nExtract wmo complete (No errors)\n");

    return nError;

}

void ExtractMapsFromMpq()
{

}
//-----------------------------------------------------------------------------
void ParsMapFiles()
{
    char fn[512];
    char id_filename[64];
    char id[10];
    for (unsigned int i=0; i<map_count; i++)
    {
        sprintf(id,"%03u",map_ids[i].id);
        sprintf(fn,"World\\Maps\\%s\\%s.wdt", map_ids[i].name, map_ids[i].name);
        WDTFile WDT(fn,map_ids[i].name);
        if(WDT.init(id))
        {
            for (int x=0; x<64; x++)
            {
                for (int y=0; y<64; y++)
                {
                    if (ADTFile*ADT = WDT.GetMap(x,y))
                    {
                        sprintf(id_filename,"%02u %02u %03u",x,y,map_ids[i].id);//!!!!!!!!!
                        ADT->init(id_filename);
                        delete ADT;
                    }

                }
            }
        }
    }
}
#if 0
void ParsMapFiles()
{

    char fn[512];
    for (unsigned int i=0; i<map_count; i++)
    {
        sprintf(fn,"World\\Maps\\%s\\%s.wdt", map_ids[i].name, map_ids[i].name);
        WDTFile WDT(fn,map_ids[i].name);
        if(WDT.init())
        {
            for (int x=0; x<64; x++)
            {
                for (int y=0; y<64; y++)
                {
                    if (ADTFile*ADT = WDT.GetMap(x,y))
                    {
                        ADT->init();
                        delete ADT;
                    }

                }
            }
        }
    }
}
#endif
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void getGamePath()
{
#ifdef _WIN32
    HKEY key;
    DWORD t,s;
    LONG l;
    s = sizeof(input_path);
    memset(input_path,0,s);
    l = RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Blizzard Entertainment\\World of Warcraft",0,KEY_QUERY_VALUE,&key);
    //l = RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Blizzard Entertainment\\Burning Crusade Closed Beta",0,KEY_QUERY_VALUE,&key);
    l = RegQueryValueEx(key,"InstallPath",0,&t,(LPBYTE)input_path,&s);
    RegCloseKey(key);
    if (strlen(input_path) > 0)
    {
        if (input_path[strlen(input_path) - 1] != '\\') strcat(input_path, "\\");
    }
    strcat(input_path,"Data\\");
#else
    strcpy(input_path,"data/");
#endif
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

bool scan_patches(char* scanmatch, std::vector<std::string>& pArchiveNames)
{
    int i;
    char path[512];
    std::list<std::string> matches;

    WIN32_FIND_DATA ffData;
    HANDLE hFind;

    for (i = 1; i <= 99; i++)
    {
        if (i != 1)
        {
            sprintf(path, "%s-%d.mpq", scanmatch, i);
        }
        else
        {
            sprintf(path, "%s.mpq", scanmatch);
        }

        hFind = INVALID_HANDLE_VALUE;
        hFind = FindFirstFile(path, &ffData);
        if (hFind == INVALID_HANDLE_VALUE) break;
        FindClose(hFind);

        matches.push_back(path);
    }

    matches.reverse();
    for (std::list<std::string>::iterator i = matches.begin(); i != matches.end(); i++)
    {
        pArchiveNames.push_back(i->c_str());
    }

    printf("\n");

    return(true);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

bool fillArchiveNameVector(std::vector<std::string>& pArchiveNames) {
    //srand((unsigned int)time(0));

    if(!hasInputPathParam)
        getGamePath();

    printf("\nGame path: %s\n", input_path);

    char path[512];
    std::vector<std::string> locales;

    // scan game directories
    WIN32_FIND_DATA ffData;
    HANDLE hFind;
    DWORD dwError;

    // first, scan for locales (4-letter directories)
    printf("Scanning for locales.\n");
    sprintf(path, "%s*.*", input_path);
    hFind = INVALID_HANDLE_VALUE;
    hFind = FindFirstFile(path, &ffData);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        printf("\nCould not open data directory for reading. Aborting.\n");
        return(false);
    }
    do
    {
        if (ffData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if (ffData.cFileName[0] != '.')
            {
                if (strlen(ffData.cFileName) == 4)
                {
                    printf("Found locale: %s\n", ffData.cFileName);
                    locales.push_back(ffData.cFileName);
                }
            }
        }
    } while (FindNextFile(hFind, &ffData) != 0);
    dwError = GetLastError();
    FindClose(hFind);
    if (dwError != ERROR_NO_MORE_FILES)
    {
        printf("\nError reading data directory while scanning locales. Aborting.\n");
        return(false);
    }
    printf("\n");

    if (locales.size() == 0)
    {
        printf("Sorry, no locales found. Aborting.\n");
        return(false);
    }

    // now, scan for the patch levels in the core dir
    printf("Loading patch levels from data directory.\n");
    sprintf(path, "%spatch", input_path);
    if (!scan_patches(path, pArchiveNames)) return(false);

    // now, scan for the patch levels in locale dirs
    printf("Loading patch levels from locale directories.\n");
    for (std::vector<std::string>::iterator i = locales.begin(); i != locales.end(); i++)
    {
        printf("Locale: %s\n", i->c_str());
        sprintf(path, "%s%s\\patch-%s", input_path, i->c_str(), i->c_str());
        if (!scan_patches(path, pArchiveNames)) return(false);
    }

    // open expansion and common files
    printf("Opening data files from data directory.\n");
    sprintf(path, "%sexpansion.mpq", input_path);
    pArchiveNames.push_back(path);
    sprintf(path, "%scommon.mpq", input_path);
    pArchiveNames.push_back(path);
    printf("\n");

    // open locale expansion and common files
    printf("Opening data files from locale directories.\n");
    for (std::vector<std::string>::iterator i = locales.begin(); i != locales.end(); i++)
    {
        printf("Locale: %s\n", i->c_str());
        sprintf(path, "%s%s\\expansion-locale-%s.mpq", input_path, i->c_str(), i->c_str());
        pArchiveNames.push_back(path);
        sprintf(path, "%s%s\\locale-%s.mpq", input_path, i->c_str(), i->c_str());
        pArchiveNames.push_back(path);
        printf("\n");
    }
    return true;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// return false it normal processing can not proceed

bool processArgv(int argc, char ** argv, char*versionString)
{
    bool result = true;
    hasInputPathParam = false;
    bool preciseVectorData = false;

    for(int i=1; i< argc; ++i) {
        if(strcmp("-s",argv[i]) == 0) {
            preciseVectorData = false;
        } else if(strcmp("-d",argv[i]) == 0) {
            if((i+1)<argc) {
                hasInputPathParam = true;
                strcpy(input_path, argv[i+1]);
                if (input_path[strlen(input_path) - 1] != '\\' || input_path[strlen(input_path) - 1] != '/')
                    strcat(input_path, "\\");
                ++i;
            } else {
                result = false;
            }
        } else if(strcmp("-?",argv[1]) == 0) {
            result = false;
        } else if(strcmp("-l",argv[i]) == 0) {
            preciseVectorData = true;
        } else {
            result = false;
            break;
        }
    }
    if(!result)     {
        printf("Extract %s.\n",versionString);
        printf("%s [-?][-s][-l][-d <path>]\n", argv[0]);
        printf("   -s : (default) small size (data size optimization), ~500MB less vmap data.\n");
        printf("   -l : large size, ~500MB more vmap data. (might contain more details)\n");
        printf("   -d <path>: Path to the vector data source folder.\n");
        printf("   -? : This message.\n");
    }
    return result;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// Main
//
// The program must be run with two command line arguments
//
// Arg1 - The source MPQ name (for testing reading and file find)
// Arg2 - Listfile name
//

int main(int argc, char ** argv)
{
    //char tmp[512];
//    FILE* pDatei;
//    char tmp[512];
//    char tmp1[512];
    //char tmp2[512];
//    char tmp3[512];
//    char tmp4[512];
//    char szMpqName[MAX_PATH] = "";
//    char szListFile[MAX_PATH] = "";
    int nError = ERROR_SUCCESS;
    char *versionString = "V2.4 2007_07_12";

    // Use command line arguments, when some
    if(!processArgv(argc, argv, versionString))
        return 1;

    printf("Extract %s. Beginning work ....\n",versionString);
    // Set the lowest priority to allow running in the background
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Create the working directory
    if(nError == ERROR_SUCCESS)
    {
        //if(!CreateDirectory(szWorkDirMaps, NULL))
        // nError = GetLastError();
        if(!CreateDirectory(szWorkDirWmo, NULL))
            nError = GetLastError();
        if(nError == ERROR_ALREADY_EXISTS)
            nError = ERROR_SUCCESS;
    }
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // patch goes first -> fake priority handling
    std::vector<MPQArchive*> archives;

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    std::vector<std::string> archiveNames;

    fillArchiveNameVector(archiveNames);
    for (size_t i=0; i<archiveNames.size(); i++) {
        archives.push_back(new MPQArchive(archiveNames[i].c_str()));
    }
    ExtractWmo(archiveNames);

     //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //map.dbc
    if(nError == ERROR_SUCCESS)
    {
        DBCFile * dbc = new DBCFile("DBFilesClient\\Map.dbc");
        dbc->open();
        map_count=dbc->getRecordCount ();
        map_ids=new map_id[map_count];
        for(unsigned int x=0;x<map_count;x++)
        {
            map_ids[x].id=dbc->getRecord (x).getUInt(0);
            strcpy(map_ids[x].name,dbc->getRecord(x).getString(1));
            printf("Map - %s\n",map_ids[x].name);
        }

        delete dbc;
        ParsMapFiles();
        delete [] map_ids;
        nError = ERROR_SUCCESS;
    }

    clreol();
    if(nError != ERROR_SUCCESS) {
        printf("ERROR: Extract %s. Work NOT complete.\n   Precise vector data=%d.\nPress any key.\n",versionString, preciseVectorData);
        _getch();
    }
    printf("Extract %s. Work complete. No errors.",versionString);
}


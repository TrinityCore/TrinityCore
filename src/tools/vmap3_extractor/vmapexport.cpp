#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <errno.h>

#ifdef _WIN32
    #include <Windows.h>
    #include <sys/stat.h>
    #include <direct.h>
    #define mkdir _mkdir
#else
    #include <sys/stat.h>
#endif

#undef min
#undef max

//#pragma warning(disable : 4505)
//#pragma comment(lib, "Winmm.lib")

#include <map>

//From Extractor
#include "adtfile.h"
#include "wdtfile.h"
#include "dbcfile.h"
#include "wmo.h"
#include "mpq_libmpq04.h"

//------------------------------------------------------------------------------
// Defines

#define MPQ_BLOCK_SIZE 0x1000

//-----------------------------------------------------------------------------

extern ArchiveSet gOpenArchives;

typedef struct
{
    char name[64];
    unsigned int id;
}map_id;

map_id * map_ids;
uint16 *LiqType = 0;
uint32 map_count;
char output_path[128]=".";
char input_path[1024]=".";
bool hasInputPathParam = false;
bool preciseVectorData = false;

// Constants

//static const char * szWorkDirMaps = ".\\Maps";
const char * szWorkDirWmo = "./Buildings";

// Local testing functions

static void clreol()
{
    printf("\r                                                                              \r");
}

void strToLower(char* str)
{
    while(*str)
    {
        *str=tolower(*str);
        ++str;
    }
}

static const char * GetPlainName(const char * szFileName)
{
    const char * szTemp;

    if((szTemp = strrchr(szFileName, '\\')) != NULL)
        szFileName = szTemp + 1;
    return szFileName;
}

// copied from contrib/extractor/System.cpp
void ReadLiquidTypeTableDBC()
{
    printf("Read LiquidType.dbc file...");
    DBCFile dbc("DBFilesClient\\LiquidType.dbc");
    if(!dbc.open())
    {
        printf("Fatal error: Invalid LiquidType.dbc file format!\n");
        exit(1);
    }

    size_t LiqType_count = dbc.getRecordCount();
    size_t LiqType_maxid = dbc.getRecord(LiqType_count - 1).getUInt(0);
    LiqType = new uint16[LiqType_maxid + 1];
    memset(LiqType, 0xff, (LiqType_maxid + 1) * sizeof(uint16));

    for(uint32 x = 0; x < LiqType_count; ++x)
        LiqType[dbc.getRecord(x).getUInt(0)] = dbc.getRecord(x).getUInt(3);

    printf("Done! (%u LiqTypes loaded)\n", (unsigned int)LiqType_count);
}

int ExtractWmo()
{
    char   szLocalFile[1024] = "";
    bool success=true;

    //const char* ParsArchiveNames[] = {"patch-2.MPQ", "patch.MPQ", "common.MPQ", "expansion.MPQ"};

    for (ArchiveSet::const_iterator ar_itr = gOpenArchives.begin(); ar_itr != gOpenArchives.end() && success; ++ar_itr)
    {
        vector<string> filelist;

        (*ar_itr)->GetFileListTo(filelist);
        for (vector<string>::iterator fname=filelist.begin(); fname != filelist.end() && success; ++fname)
        {
            bool file_ok=true;
            if (fname->find(".wmo") != string::npos)
            {
                // Copy files from archive
                //std::cout << "found *.wmo file " << *fname << std::endl;
                sprintf(szLocalFile, "%s/%s", szWorkDirWmo, GetPlainName(fname->c_str()));
                fixnamen(szLocalFile,strlen(szLocalFile));
                FILE * n;
                if ((n = fopen(szLocalFile, "rb"))== NULL)
                {
                    int p = 0;
                    //Select root wmo files
                    const char * rchr = strrchr(GetPlainName(fname->c_str()),0x5f);
                    if(rchr != NULL)
                    {
                        char cpy[4];
                        strncpy((char*)cpy,rchr,4);
                        for (int i=0;i<4; ++i)
                        {
                            int m = cpy[i];
                            if(isdigit(m))
                                p++;
                        }
                    }
                    if(p != 3)
                    {
                        std::cout << "Extracting " << *fname << std::endl;
                        WMORoot * froot = new WMORoot(*fname);
                        if(!froot->open())
                        {
                            printf("Couldn't open RootWmo!!!\n");
                            delete froot;
                            continue;
                        }
                        FILE *output=fopen(szLocalFile,"wb");
                        if(!output)
                        {
                            printf("couldn't open %s for writing!\n", szLocalFile);
                            success=false;
                        }
                        froot->ConvertToVMAPRootWmo(output);
                        int Wmo_nVertices = 0;
                        //printf("root has %d groups\n", froot->nGroups);
                        if(froot->nGroups !=0)
                        {
                            for (uint32 i=0; i<froot->nGroups; ++i)
                            {
                                char temp[1024];
                                strcpy(temp, fname->c_str());
                                temp[fname->length()-4] = 0;
                                char groupFileName[1024];
                                sprintf(groupFileName,"%s_%03d.wmo",temp, i);
                                //printf("Trying to open groupfile %s\n",groupFileName);
                                string s = groupFileName;
                                WMOGroup * fgroup = new WMOGroup(s);
                                if(!fgroup->open())
                                {
                                    printf("Could not open all Group file for: %s\n",GetPlainName(fname->c_str()));
                                    file_ok=false;
                                    break;
                                }

                                Wmo_nVertices += fgroup->ConvertToVMAPGroupWmo(output, froot, preciseVectorData);
                                delete fgroup;
                            }
                        }
                        fseek(output, 8, SEEK_SET); // store the correct no of vertices
                        fwrite(&Wmo_nVertices,sizeof(int),1,output);
                        fclose(output);
                        delete froot;
                    }
                }
                else
                {
                    fclose(n);
                }
            }
            // Delete the extracted file in the case of an error
            if(!file_ok)
                remove(szLocalFile);
        }
    }

    if(success)
        printf("\nExtract wmo complete (No (fatal) errors)\n");

    return success;
}

void ExtractMapsFromMpq()
{
}

void ParsMapFiles()
{
    char fn[512];
    //char id_filename[64];
    char id[10];
    for (unsigned int i=0; i<map_count; ++i)
    {
        sprintf(id,"%03u",map_ids[i].id);
        sprintf(fn,"World\\Maps\\%s\\%s.wdt", map_ids[i].name, map_ids[i].name);
        WDTFile WDT(fn,map_ids[i].name);
        if(WDT.init(id, map_ids[i].id))
        {
            printf("Processing Map %u\n[", map_ids[i].id);
            for (int x=0; x<64; ++x)
            {
                for (int y=0; y<64; ++y)
                {
                    if (ADTFile *ADT = WDT.GetMap(x,y))
                    {
                        //sprintf(id_filename,"%02u %02u %03u",x,y,map_ids[i].id);//!!!!!!!!!
                        ADT->init(map_ids[i].id, x, y);
                        delete ADT;
                    }
                }
                printf("#");
                fflush(stdout);
            }
            printf("]\n");
        }
    }
}

void getGamePath()
{
#ifdef _WIN32
    HKEY key;
    DWORD t,s;
    LONG l;
    s = sizeof(input_path);
    memset(input_path,0,s);
    l = RegOpenKeyExA(HKEY_LOCAL_MACHINE,"SOFTWARE\\Blizzard Entertainment\\World of Warcraft",0,KEY_QUERY_VALUE,&key);
    l = RegQueryValueExA(key,"InstallPath",0,&t,(LPBYTE)input_path,&s);
    RegCloseKey(key);
    if (strlen(input_path) > 0)
    {
        if (input_path[strlen(input_path) - 1] != '\\') strcat(input_path, "\\");
    }
    strcat(input_path,"Data\\");
#else
    strcpy(input_path,"Data/");
#endif
}

bool scan_patches(char* scanmatch, std::vector<std::string>& pArchiveNames)
{
    int i;
    char path[512];

    for (i = 1; i <= 99; i++)
    {
        if (i != 1)
        {
            sprintf(path, "%s-%d.MPQ", scanmatch, i);
        }
        else
        {
            sprintf(path, "%s.MPQ", scanmatch);
        }
#ifdef __linux__
        if(FILE* h = fopen64(path, "rb"))
#else
        if(FILE* h = fopen(path, "rb"))
#endif
        {
            fclose(h);
            //matches.push_back(path);
            pArchiveNames.push_back(path);
        }
    }

    return(true);
}

bool fillArchiveNameVector(std::vector<std::string>& pArchiveNames)
{
    if(!hasInputPathParam)
        getGamePath();

    printf("\nGame path: %s\n", input_path);

    char path[512];
    string in_path(input_path);
    std::vector<std::string> locales, searchLocales;

    searchLocales.push_back("enGB");
    searchLocales.push_back("enUS");
    searchLocales.push_back("deDE");
    searchLocales.push_back("esES");
    searchLocales.push_back("frFR");
    searchLocales.push_back("koKR");
    searchLocales.push_back("zhCN");
    searchLocales.push_back("zhTW");
    searchLocales.push_back("enCN");
    searchLocales.push_back("enTW");
    searchLocales.push_back("esMX");
    searchLocales.push_back("ruRU");

    for (std::vector<std::string>::iterator i = searchLocales.begin(); i != searchLocales.end(); ++i)
    {
        std::string localePath = in_path + *i;
        // check if locale exists:
        struct stat status;
        if (stat(localePath.c_str(), &status))
            continue;
        if ((status.st_mode & S_IFDIR) == 0)
            continue;
        printf("Found locale '%s'\n", i->c_str());
        locales.push_back(*i);
    }
    printf("\n");

    // open locale expansion and common files
    printf("Adding data files from locale directories.\n");
    for (std::vector<std::string>::iterator i = locales.begin(); i != locales.end(); ++i)
    {
        pArchiveNames.push_back(in_path + *i + "/locale-" + *i + ".MPQ");
        pArchiveNames.push_back(in_path + *i + "/expansion-locale-" + *i + ".MPQ");
        pArchiveNames.push_back(in_path + *i + "/lichking-locale-" + *i + ".MPQ");
    }

    // open expansion and common files
    pArchiveNames.push_back(input_path + string("common.MPQ"));
    pArchiveNames.push_back(input_path + string("common-2.MPQ"));
    pArchiveNames.push_back(input_path + string("expansion.MPQ"));
    pArchiveNames.push_back(input_path + string("lichking.MPQ"));

    // now, scan for the patch levels in the core dir
    printf("Scanning patch levels from data directory.\n");
    sprintf(path, "%spatch", input_path);
    if (!scan_patches(path, pArchiveNames))
        return(false);

    // now, scan for the patch levels in locale dirs
    printf("Scanning patch levels from locale directories.\n");
    bool foundOne = false;
    for (std::vector<std::string>::iterator i = locales.begin(); i != locales.end(); ++i)
    {
        printf("Locale: %s\n", i->c_str());
        sprintf(path, "%s%s/patch-%s", input_path, i->c_str(), i->c_str());
        if(scan_patches(path, pArchiveNames))
            foundOne = true;
    }

    printf("\n");

    if(!foundOne)
    {
        printf("no locale found\n");
        return false;
    }

    return true;
}

bool processArgv(int argc, char ** argv, const char *versionString)
{
    bool result = true;
    hasInputPathParam = false;
    bool preciseVectorData = false;

    for(int i=1; i< argc; ++i)
    {
        if(strcmp("-s",argv[i]) == 0)
        {
            preciseVectorData = false;
        }
        else if(strcmp("-d",argv[i]) == 0)
        {
            if((i+1)<argc)
            {
                hasInputPathParam = true;
                strcpy(input_path, argv[i+1]);
                if (input_path[strlen(input_path) - 1] != '\\' || input_path[strlen(input_path) - 1] != '/')
                    strcat(input_path, "/");
                ++i;
            }
            else
            {
                result = false;
            }
        }
        else if(strcmp("-?",argv[1]) == 0)
        {
            result = false;
        }
        else if(strcmp("-l",argv[i]) == 0)
        {
            preciseVectorData = true;
        }
        else
        {
            result = false;
            break;
        }
    }
    if(!result)
    {
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
    bool success=true;
    const char *versionString = "V3.00 2010_07";

    // Use command line arguments, when some
    if(!processArgv(argc, argv, versionString))
        return 1;

    // some simple check if working dir is dirty
    else
    {
        std::string sdir = std::string(szWorkDirWmo) + "/dir";
        std::string sdir_bin = std::string(szWorkDirWmo) + "/dir_bin";
        struct stat status;
        if (!stat(sdir.c_str(), &status) || !stat(sdir_bin.c_str(), &status))
        {
            printf("Your output directory seems to be polluted, please use an empty directory!\n");
            printf("<press return to exit>");
            char garbage[2];
            scanf("%c", garbage);
            return 1;
        }
    }

    printf("Extract %s. Beginning work ....\n",versionString);
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Create the working directory
    if(mkdir(szWorkDirWmo
#ifdef _XOPEN_UNIX
                    , 0711
#endif
                    ))
            success = (errno == EEXIST);

    // prepare archive name list
    std::vector<std::string> archiveNames;
    fillArchiveNameVector(archiveNames);
    for (size_t i=0; i < archiveNames.size(); ++i)
    {
        MPQArchive *archive = new MPQArchive(archiveNames[i].c_str());
        if(!gOpenArchives.size() || gOpenArchives.front() != archive)
            delete archive;
    }

    if(gOpenArchives.empty())
    {
        printf("FATAL ERROR: None MPQ archive found by path '%s'. Use -d option with proper path.\n",input_path);
        return 1;
    }
    ReadLiquidTypeTableDBC();

    // extract data
    if(success)
        success = ExtractWmo();

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //map.dbc
    if(success)
    {
        DBCFile * dbc = new DBCFile("DBFilesClient\\Map.dbc");
        if(!dbc->open())
        {
            delete dbc;
            printf("FATAL ERROR: Map.dbc not found in data file.\n");
            return 1;
        }
        map_count=dbc->getRecordCount ();
        map_ids=new map_id[map_count];
        for(unsigned int x=0;x<map_count;++x)
        {
            map_ids[x].id=dbc->getRecord (x).getUInt(0);
            strcpy(map_ids[x].name,dbc->getRecord(x).getString(1));
            printf("Map - %s\n",map_ids[x].name);
        }


        delete dbc;
        ParsMapFiles();
        delete [] map_ids;
        //nError = ERROR_SUCCESS;
    }

    clreol();
    if(!success)
    {
        printf("ERROR: Extract %s. Work NOT complete.\n   Precise vector data=%d.\nPress any key.\n",versionString, preciseVectorData);
        getchar();
    }

    printf("Extract %s. Work complete. No errors.\n",versionString);
    delete [] LiqType;
    return 0;
}

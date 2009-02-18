#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <deque>
#include <set>

#ifdef WIN32
#include "direct.h"
#else
#include <sys/stat.h>
#endif

#include "dbcfile.h"
#include "mpq_libmpq.h"

extern unsigned int iRes;
extern ArchiveSet gOpenArchives;

bool ConvertADT(char*,char*);

typedef struct{
    char name[64];
    unsigned int id;
}map_id;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

map_id * map_ids;
uint16 * areas;
char output_path[128]=".";
char input_path[128]=".";

enum Extract
{
    EXTRACT_MAP = 1,
    EXTRACT_DBC = 2
};
int extract = EXTRACT_MAP | EXTRACT_DBC;

static char* const langs[] = {"enGB", "enUS", "deDE", "esES", "frFR", "koKR", "zhCN", "zhTW", "enCN", "enTW", "esMX", "ruRU" };
#define LANG_COUNT 12

#define ADT_RES 64

void CreateDir( const std::string& Path )
{
    #ifdef WIN32
    _mkdir( Path.c_str());
    #else
    mkdir( Path.c_str(), 0777 );
    #endif
}

bool FileExists( const char* FileName )
{
    if(FILE* fp = fopen( FileName, "rb" ))
    {
        fclose(fp);
        return true;
    }

    return false;
}

void Usage(char* prg)
{
    printf("Usage:\n%s -[var] [value]\n-i set input path\n-o set output path\n-r set resolution\n-e extract only MAP(1)/DBC(2) - standard: both(3)\nExample: %s -r 256 -i \"c:\\games\\game\"",
    prg,prg);
    exit(1);
}

void HandleArgs(int argc, char * arg[])
{
    for(int c=1;c<argc;c++)
    {
        //i - input path
        //o - output path
        //r - resolution, array of (r * r) heights will be created
        //e - extract only MAP(1)/DBC(2) - standard both(3)
        if(arg[c][0] != '-')
            Usage(arg[0]);

        switch(arg[c][1])
        {
            case 'i':
                if(c+1<argc)//all ok
                    strcpy(input_path,arg[(c++) +1]);
                else
                    Usage(arg[0]);
                break;
            case 'o':
                if(c+1<argc)//all ok
                    strcpy(output_path,arg[(c++) +1]);
                else
                    Usage(arg[0]);
                break;
            case 'r':
                if(c+1<argc)//all ok
                    iRes=atoi(arg[(c++) +1]);
                else
                    Usage(arg[0]);
                break;
            case 'e':
                if(c+1<argc)//all ok
                {
                    extract=atoi(arg[(c++) +1]);
                    if(!(extract > 0 && extract < 4))
                        Usage(arg[0]);
                }
                else
                    Usage(arg[0]);
                break;
        }
    }
}

uint32 ReadMapDBC()
{
    printf("Read Map.dbc file... ");
    DBCFile dbc("DBFilesClient\\Map.dbc");
    dbc.open();

    uint32 map_count=dbc.getRecordCount();
    map_ids=new map_id[map_count];
    for(unsigned int x=0;x<map_count;x++)
    {
        map_ids[x].id=dbc.getRecord(x).getUInt(0);
        strcpy(map_ids[x].name,dbc.getRecord(x).getString(1));
    }
    printf("Done! (%u maps loaded)\n", map_count);
    return map_count;
}

void ReadAreaTableDBC()
{
    printf("Read AreaTable.dbc file... ");
    DBCFile dbc("DBFilesClient\\AreaTable.dbc");
    dbc.open();

    unsigned int area_count=dbc.getRecordCount();
    uint32 maxid = dbc.getMaxId();
    areas=new uint16[maxid + 1];
    memset(areas, 0xff, sizeof(areas));
    for(unsigned int x=0; x<area_count;++x)
        areas[dbc.getRecord(x).getUInt(0)] = dbc.getRecord(x).getUInt(3);

    printf("Done! (%u areas loaded)\n", area_count);
}

void ExtractMapsFromMpq()
{
    char mpq_filename[1024];
    char output_filename[1024];

    printf("Extracting maps...\n");

    uint32 map_count = ReadMapDBC();

    ReadAreaTableDBC();

    unsigned int total=map_count*ADT_RES*ADT_RES;
    unsigned int done=0;

    std::string path = output_path;
    path += "/maps/";
    CreateDir(path);

    for(unsigned int x = 0; x < ADT_RES; ++x)
    {
        for(unsigned int y = 0; y < ADT_RES; ++y)
        {
            for(unsigned int z = 0; z < map_count; ++z)
            {
                sprintf(mpq_filename,"World\\Maps\\%s\\%s_%u_%u.adt",map_ids[z].name,map_ids[z].name,x,y);
                sprintf(output_filename,"%s/maps/%03u%02u%02u.map",output_path,map_ids[z].id,y,x);
                ConvertADT(mpq_filename,output_filename);
                done++;
            }
            //draw progess bar
            printf("Processing........................%d%%\r",(100*done)/total);
        }
    }

    delete [] areas;
    delete [] map_ids;
}

//bool WMO(char* filename);

void ExtractDBCFiles(int locale, bool basicLocale)
{
    printf("Extracting dbc files...\n");

    set<string> dbcfiles;

    // get DBC file list
    for(ArchiveSet::iterator i = gOpenArchives.begin(); i != gOpenArchives.end();++i)
    {
        vector<string> files;
        (*i)->GetFileListTo(files);
        for (vector<string>::iterator iter = files.begin(); iter != files.end(); ++iter)
            if (iter->rfind(".dbc") == iter->length() - strlen(".dbc"))
                    dbcfiles.insert(*iter);
    }

    string path = output_path;
    path += "/dbc/";
    CreateDir(path);
    if(!basicLocale)
    {
        path += langs[locale];
        path += "/";
        CreateDir(path);
    }

    // extract DBCs
    int count = 0;
    for (set<string>::iterator iter = dbcfiles.begin(); iter != dbcfiles.end(); ++iter)
    {
        string filename = path;
        filename += (iter->c_str() + strlen("DBFilesClient\\"));

        FILE *output=fopen(filename.c_str(), "wb");
        if(!output)
        {
            printf("Can't create the output file '%s'\n", filename.c_str());
            continue;
        }
        MPQFile m(iter->c_str());
        if(!m.isEof())
            fwrite(m.getPointer(), 1, m.getSize(), output);

        fclose(output);
        ++count;
    }
    printf("Extracted %u DBC files\n\n", count);
}

void LoadLocaleMPQFiles(int const locale)
{
    char filename[512];

    sprintf(filename,"%s/Data/%s/locale-%s.MPQ", input_path, langs[locale], langs[locale]);
    new MPQArchive(filename);

    for(int i = 1; i < 5; ++i)
    {
        char ext[3] = "";
        if(i > 1)
            sprintf(ext, "-%i", i);

        sprintf(filename,"%s/Data/%s/patch-%s%s.MPQ", input_path, langs[locale], langs[locale], ext);
        if(FileExists(filename))
            new MPQArchive(filename);
    }
}

void LoadCommonMPQFiles()
{
    char filename[512];

    sprintf(filename,"%s/Data/common.MPQ", input_path);
    new MPQArchive(filename);
    sprintf(filename,"%s/Data/expansion.MPQ", input_path);
    new MPQArchive(filename);
    for(int i = 1; i < 5; ++i)
    {
        char ext[3] = "";
        if(i > 1)
            sprintf(ext, "-%i", i);

        sprintf(filename,"%s/Data/patch%s.MPQ", input_path, ext);
        if(FileExists(filename))
            new MPQArchive(filename);
    }
}

inline void CloseMPQFiles()
{
    for(ArchiveSet::iterator j = gOpenArchives.begin(); j != gOpenArchives.end();++j) (*j)->close();
        gOpenArchives.clear();
}

int main(int argc, char * arg[])
{
    printf("Map & DBC Extractor\n");
    printf("===================\n\n");

    HandleArgs(argc, arg);

    int FirstLocale = -1;

    for (int i = 0; i < LANG_COUNT; i++)
    {
        char tmp1[512];
        sprintf(tmp1, "%s/Data/%s/locale-%s.MPQ", input_path, langs[i], langs[i]);
        if (FileExists(tmp1))
        {
            printf("Detected locale: %s\n", langs[i]);

            //Open MPQs
            LoadLocaleMPQFiles(i);

            if((extract & EXTRACT_DBC) == 0)
            {
                FirstLocale = i;
                break;
            }

            //Extract DBC files
            if(FirstLocale < 0)
            {
                ExtractDBCFiles(i, true);
                FirstLocale = i;
            }
            else
                ExtractDBCFiles(i, false);

            //Close MPQs
            CloseMPQFiles();
        }
    }

    if(FirstLocale < 0)
    {
        printf("No locales detected\n");
        return 0;
    }

    if (extract & EXTRACT_MAP)
    {
        printf("Using locale: %s\n", langs[FirstLocale]);

        // Open MPQs
        LoadLocaleMPQFiles(FirstLocale);
        LoadCommonMPQFiles();

        // Extract maps
        ExtractMapsFromMpq();

        // Close MPQs
        CloseMPQFiles();
    }

    return 0;
}


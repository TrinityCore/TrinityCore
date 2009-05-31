#include "adtfile.h"

#include <algorithm>

char * GetPlainName(char * FileName)
{
    char * szTemp;

    if((szTemp = strrchr(FileName, '\\')) != NULL)
        FileName = szTemp + 1;
    return FileName;
}

void fixnamen(char *name, size_t len)
{
    for (size_t i=0; i<len-3; i++)
    {
        if (i>0 && name[i]>='A' && name[i]<='Z' && isalpha(name[i-1]))
        {
            name[i] |= 0x20;
        } else if ((i==0 || !isalpha(name[i-1])) && name[i]>='a' && name[i]<='z')
        {
            name[i] &= ~0x20;
        }
    }
}

void fixname2(char *name, size_t len)
{
    for (size_t i=0; i<len-3; i++)
    {
        if(name[i] == ' ')
        name[i] = '_';
    }
}

ADTFile::ADTFile(char* filename): ADT(filename)
{
    Adtfilename.append(filename);
}

bool ADTFile::init(char *map_id)
{
    if(ADT.isEof ())
        return false;

    size_t size;

    string xMap;
    string yMap;

    Adtfilename.erase(Adtfilename.find(".adt"),4);
    string TempMapNumber;
    TempMapNumber = Adtfilename.substr(Adtfilename.length()-6,6);
    xMap = TempMapNumber.substr(TempMapNumber.find("_")+1,(TempMapNumber.find_last_of("_")-1) - (TempMapNumber.find("_")));
    yMap = TempMapNumber.substr(TempMapNumber.find_last_of("_")+1,(TempMapNumber.length()) - (TempMapNumber.find_last_of("_")));
    Adtfilename.erase((Adtfilename.length()-xMap.length()-yMap.length()-2), (xMap.length()+yMap.length()+2));
    string AdtMapNumber = xMap + ' ' + yMap + ' ' + GetPlainName((char*)Adtfilename.c_str());
    printf("Processing map %s...\n", AdtMapNumber.c_str());
    //printf("MapNumber = %s\n", TempMapNumber.c_str());
    //printf("xMap = %s\n", xMap.c_str());
    //printf("yMap = %s\n", yMap.c_str());

    const char dirname[] = "buildings\\dir";
    FILE *dirfile;
    dirfile = fopen(dirname, "ab");
    if(!dirfile)
    {
        printf("Can't open dirfile!'%s'\n");
        return false;
    }

    while (!ADT.isEof())
    {
        char fourcc[5];
        ADT.read(&fourcc,4);
        ADT.read(&size, 4);
        flipcc(fourcc);
        fourcc[4] = 0;

        size_t nextpos = ADT.getPos() + size;

        if (!strcmp(fourcc,"MCIN"))
        {
        }
        else if (!strcmp(fourcc,"MTEX"))
        {
        }
        else if (!strcmp(fourcc,"MMDX"))
        {
            if (size)
            {
                char *buf = new char[size];
                ADT.read(buf, size);
                char *p=buf;
                int t=0;
                ModelInstansName = new string[size];
                while (p<buf+size)
                {
                    fixnamen(p,strlen(p));
                    string path(p);
                    char* s=GetPlainName(p);
                    fixname2(s,strlen(s));
                    p=p+strlen(p)+1;
                    ModelInstansName[t++] = s;

                    // < 3.1.0 ADT MMDX section store filename.mdx filenames for corresponded .m2 file
                    std::string ext3 = path.size() >= 4 ? path.substr(path.size()-4,4) : "";
                    std::transform( ext3.begin(), ext3.end(), ext3.begin(), ::tolower );
                    if(ext3 == ".mdx")
                    {
                        // replace .mdx -> .m2
                        path.erase(path.length()-2,2);
                        path.append("2");
                    }
                    // >= 3.1.0 ADT MMDX section store filename.m2 filenames for corresponded .m2 file
                    // nothing do

                    char szLocalFile[MAX_PATH];
                    sprintf(szLocalFile, ".\\buildings\\%s", s);
                    FILE * output = fopen(szLocalFile,"rb");
                    if(!output)
                    {
                        Model * m2 = new Model(path);
                        if(m2->open())
                            m2->ConvertToVMAPModel(szLocalFile);
                        delete m2;
                    }
                    else
                        fclose(output);
                }
                delete[] buf;
            }
        }
        else if (!strcmp(fourcc,"MWMO"))
        {
            if (size)
            {
                char *buf = new char[size];
                ADT.read(buf, size);
                char *p=buf;
                int q = 0;
                WmoInstansName = new string[size];
                while (p<buf+size)
                {
                    string path(p);
                    char* s=GetPlainName(p);
                    fixnamen(s,strlen(s));
                    fixname2(s,strlen(s));
                    p=p+strlen(p)+1;
                    WmoInstansName[q++] = s;
                }
                delete[] buf;
            }
        }
        //======================
        else if (!strcmp(fourcc,"MDDF"))
        {
            if (size)
            {
                nMDX = (int)size / 36;
                for (int i=0; i<nMDX; ++i)
                {
                    int id;
                    ADT.read(&id, 4);
                    ModelInstance inst(ADT,ModelInstansName[id].c_str(),map_id, dirfile);//!!!!!!!!!!!
                }
                delete[] ModelInstansName;
            }
        }
        else if (!strcmp(fourcc,"MODF"))
        {
            if (size)
            {
                nWMO = (int)size / 64;
                for (int i=0; i<nWMO; ++i)
                {
                    int id;
                    ADT.read(&id, 4);
                    WMOInstance inst(ADT,WmoInstansName[id].c_str(),map_id, dirfile);//!!!!!!!!!!!!!
                }
                delete[] WmoInstansName;
            }
        }
        //======================
#if 0
        else if (!strcmp(fourcc,"MDDF"))
        {
            if (size)
            {
                nMDX = (int)size / 36;
                for (int i=0; i<nMDX; ++i)
                {
                    int id;
                    ADT.read(&id, 4);
                    ModelInstance inst(ADT,ModelInstansName[id].c_str(),AdtMapNumber.c_str(), dirfile);
                }
                delete[] ModelInstansName;
            }
        }
        else if (!strcmp(fourcc,"MODF"))
        {
            if (size)
            {
                nWMO = (int)size / 64;
                for (int i=0; i<nWMO; ++i)
                {
                    int id;
                    ADT.read(&id, 4);
                    WMOInstance inst(ADT,WmoInstansName[id].c_str(),AdtMapNumber.c_str(), dirfile);
                }
                delete[] WmoInstansName;
            }
        }
#endif
        ADT.seek(nextpos);
    }
    ADT.close();
    fclose(dirfile);
    return true;
}

ADTFile::~ADTFile()
{
    ADT.close();
}

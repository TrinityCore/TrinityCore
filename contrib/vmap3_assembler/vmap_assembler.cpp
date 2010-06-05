#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "TileAssembler.h"

//=======================================================
// remove last return or LF and tailing SPACE
// remove all char after a #

void chompAndTrim(std::string& str)
{
    for(unsigned int i=0;i<str.length(); ++i) {
        char lc = str[i];
        if(lc == '#') {
            str = str.substr(0,i);
            break;
        }
    }

    while(str.length() >0) {
        char lc = str[str.length()-1];
        if(lc == '\r' || lc == '\n' || lc == ' ') {
            str = str.substr(0,str.length()-1);
        } else {
            break;
        }
    }
}

//=======================================================
/**
This callback method is called for each model found in the dir file.
return true if it should be included in the vmap
*/
bool modelNameFilter(char *pName)
{
#if 0
    bool result;
    result = !Wildcard::wildcardfit("*bush[0-9]*", pName);
    if(result) result = !Wildcard::wildcardfit("*shrub[0-9]*", pName);
    if(result) result = !Wildcard::wildcardfit("*_Bushes_*", pName);
    if(result) result = !Wildcard::wildcardfit("*_Bush_*", pName);
    if(!result) {
        printf("%s",pName);
    }
#endif
    return true;
}

//=======================================================
/**
File contains map names that should be split into tiles
A '#' at the beginning of a line defines a comment
*/

/* bool readConfigFile(char *pConffile, VMAP::TileAssembler* pTa)
{
    bool result = false;
    char buffer[501];
    FILE *cf = fopen(pConffile, "rb");
    if(cf) {
        while(fgets(buffer, 500, cf)) {
            std::string name = std::string(buffer);
            size_t pos = name.find_first_not_of(' ');
            name = name.substr(pos);
            chompAndTrim(name); // just to be sure
            if(name[0] != '#' && name.size() >0) { // comment?
                unsigned int mapId = atoi(name.c_str());
                pTa->addWorldAreaMapId(mapId);
            }
        }
        fclose(cf);
        result = true;
    }
    return(result);
} */
//=======================================================
int main(int argc, char* argv[])
{
    if(argc != 3 && argc != 4)
    {
        printf("\nusage: %s <raw data dir> <vmap dest dir> [config file name]\n", argv[0]);
        return 1;
    }

    char *src = argv[1];
    char *dest = argv[2];
    char *conffile = NULL;
    if(argc >= 4)
        conffile = argv[3];

    VMAP::TileAssembler* ta = new VMAP::TileAssembler(std::string(src), std::string(dest));
    ta->setModelNameFilterMethod(modelNameFilter);

    /*
    All the names in the list are considered to be world maps or huge instances.
    These maps will be spilt into tiles in the vmap assemble process
    */
    /* if(conffile != NULL)
    {
        if(!readConfigFile(conffile, ta))
        {
            printf("Can not open file config file: %s\n", conffile);
            delete ta;
            return 1;
        }
    } */

    if(!ta->convertWorld2())
    {
        printf("exit with errors\n");
        delete ta;
        return 1;
    }

    delete ta;
    printf("Ok, all done\n");
    return 0;
}

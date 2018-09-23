#include "Globals.h"
#include "Config.h"

std::string dbcdir()
{
    std::string dir = sConfigMgr->GetStringDefault("DataDir", "./");
    if (dir.empty() || (dir.back() != '/' && dir.back() != '\\'))
        dir.push_back('/');
    dir += "dbc/";
    return dir;
}

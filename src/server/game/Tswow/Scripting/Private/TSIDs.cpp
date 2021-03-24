/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2021 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "TSString.h"
#include "TSIDs.h"
#include "Config.h"

#include <boost/filesystem.hpp>

#include <sstream>
#include <fstream>
#include <map>

static std::map<TSString, IDRange> tables;
IDRange GetIDRange(TSString table, TSString mod, TSString name)
{
    auto fn = table+JSTR(":")+mod+JSTR(":")+name;
    std::map<TSString, IDRange>::iterator it = tables.find(fn);
    if(it != tables.end())
    {
        return it->second;
    }
    return IDRange(0,0);
}

uint32 GetID(TSString table, TSString mod, TSString name)
{
    return GetIDRange(table,mod,name).low;
}

void LoadIDs()
{
    tables.clear();

    int stage = 0;
    char curstr[128];
    int strlen = 0;
    int namepos = 0;
    int lowpos = 0;
    int hipos = 0;

    auto data_str = sConfigMgr
        ->GetStringDefault("DataDir","../../datasets/default");
    auto data_dir =
          boost::filesystem::path(data_str)
        / boost::filesystem::path("ids.txt");

    std::ifstream t(data_dir.string().c_str());
    if (!t.good()) return;

    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string str = buffer.str();
    t.close();
    buffer.clear();

    for (int i = 0; i < str.size(); ++i) {
        char& chr = str[i];
        if (chr != '|') {
            curstr[strlen++] = chr;
            continue;
        }

        switch (stage) {
        case 0:
            curstr[strlen++] = 0;
            namepos = strlen;
            break;
        case 1:
            curstr[strlen++] = 0;
            lowpos = strlen;
            break;
        case 2:
            curstr[strlen++] = 0;
            hipos = strlen;
            break;
        case 3:
            ++i;
            curstr[strlen] = 0;
            TSString table = TSString(std::string(curstr));
            TSString name = TSString(table + JSTR(":") + JSTR(curstr + namepos));
            strlen = 0;
            int low = atoi(curstr + lowpos);
            int high = atoi(curstr + hipos);
            stage = -1;
            tables[name] = IDRange(low, high);
            stage = -1;
            break;
        }
        ++stage;
    }
}

/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "ConfigEnv.h"
#include "Policies/SingletonImp.h"
INSTANTIATE_SINGLETON_1(Config);
Config::Config() : mIgnoreCase(true), mConf(NULL)
{
}

Config::~Config()
{
    delete mConf;
}

bool Config::SetSource(const char *file, bool ignorecase)
{
    mIgnoreCase = ignorecase;
    mFilename = file;
    return Reload();
}
bool Config::Reload()
{
    delete mConf;
    mConf = new DOTCONFDocument(mIgnoreCase ?
        DOTCONFDocument::CASEINSENSETIVE :
    DOTCONFDocument::CASESENSETIVE);
    if (mConf->setContent(mFilename.c_str()) == -1)
    {
        delete mConf;
        mConf = NULL;
        return false;
    }
    return true;
}
std::string Config::GetStringDefault(const char * name, std::string def)
{
    if(!mConf)
        return std::string(def);
    const DOTCONFDocumentNode * node = mConf->findNode(name);
    if(!node || !node->getValue())
        return std::string(def);
    return std::string(node->getValue());
};
bool Config::GetBoolDefault(const char * name, const bool def)
{
    if(!mConf)
        return false;
    const DOTCONFDocumentNode * node = mConf->findNode(name);
    if(!node || !node->getValue())
        return def;
    const char * str = node->getValue();
    if(strcmp(str, "true") == 0 || strcmp(str, "TRUE") == 0 ||
        strcmp(str, "yes") == 0 || strcmp(str, "YES") == 0 ||
        strcmp(str, "1") == 0)
        return true;
    else
        return false;
};
int32 Config::GetIntDefault(const char * name, const int32 def)
{
    if(!mConf)
        return def;
    const DOTCONFDocumentNode * node = mConf->findNode(name);
    if(!node || !node->getValue())
        return def;
    return atoi(node->getValue());
};
float Config::GetFloatDefault(const char * name, const float def)
{
    if(!mConf)
        return def;
    const DOTCONFDocumentNode * node = mConf->findNode(name);
    if(!node || !node->getValue())
        return def;
    return atof(node->getValue());
};

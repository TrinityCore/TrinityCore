/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

bool Config::GetString(const char* name, std::string *value)
{
    if(!mConf)
        return false;

    DOTCONFDocumentNode const *node = mConf->findNode(name);
    if(!node || !node->getValue())
        return false;

    *value = node->getValue();

    return true;
}

bool Config::GetString(const char* name, char const **value)
{
    if(!mConf)
        return false;

    DOTCONFDocumentNode const *node = mConf->findNode(name);
    if(!node || !node->getValue())
        return false;

    *value = node->getValue();

    return true;
}


std::string Config::GetStringDefault(const char* name, const char* def)
{
    if(!mConf)
        return std::string(def);

    DOTCONFDocumentNode const *node = mConf->findNode(name);
    if(!node || !node->getValue())
        return std::string(def);

    return std::string(node->getValue());
}


bool Config::GetBool(const char* name, bool *value)
{
    if(!mConf)
        return false;

    DOTCONFDocumentNode const *node = mConf->findNode(name);
    if(!node || !node->getValue())
        return false;

    const char* str = node->getValue();
    if(strcmp(str, "true") == 0 || strcmp(str, "TRUE") == 0 ||
        strcmp(str, "yes") == 0 || strcmp(str, "YES") == 0 ||
        strcmp(str, "1") == 0)
    {
        *value = true;
    }
    else
        *value = false;

    return true;
}


bool Config::GetBoolDefault(const char* name, const bool def)
{
    bool val;
    return GetBool(name, &val) ? val : def;
}


bool Config::GetInt(const char* name, int *value)
{
    if(!mConf)
        return false;

    DOTCONFDocumentNode const *node = mConf->findNode(name);
    if(!node || !node->getValue())
        return false;

    *value = atoi(node->getValue());

    return true;
}


bool Config::GetFloat(const char* name, float *value)
{
    if(!mConf)
        return false;

    DOTCONFDocumentNode const *node = mConf->findNode(name);
    if(!node || !node->getValue())
        return false;

    *value = atof(node->getValue());

    return true;
}


int Config::GetIntDefault(const char* name, const int def)
{
    int val;
    return GetInt(name, &val) ? val : def;
}


float Config::GetFloatDefault(const char* name, const float def)
{
    float val;
    return (GetFloat(name, &val) ? val : def);
}


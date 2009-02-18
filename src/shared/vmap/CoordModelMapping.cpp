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

#include "CoordModelMapping.h"

#include <string.h>

using namespace G3D;

namespace VMAP
{

    //============================================================
    //============================================================

    void CMappingEntry::addFilename(char *pName)
    {
        std::string name = std::string(pName);
        if(!iFilenames.contains(name))
            iFilenames.append(std::string(pName));
    }

    //============================================================

    const std::string CMappingEntry::getKeyString() const
    {
        return(CMappingEntry::getKeyString(iMapId,xPos, yPos));
    }

    //============================================================
    //============================================================
    //============================================================

    CoordModelMapping::~CoordModelMapping()
    {
        Array<std::string> keys = iMapObjectFiles.getKeys();
        for (int k = 0; k < keys.length(); k++)
        {
            CMappingEntry *value = getCMappingEntry(keys[k]);
            if(value != 0)
            {
                iMapObjectFiles.remove(keys[k]);
                delete value;
            }
        }
    }

    //============================================================

    int findPosChar(const char *namebuffer, char pSearch, int pCount)
    {
        int result = -1;
        int pos=0;
        while(namebuffer[pos] != 0)
        {
            if(namebuffer[pos] == pSearch)
            {
                --pCount;
            }
            if(pCount == 0)
            {
                result = pos;
                break;
            }
            ++pos;
        }
        return result;
    }
    //============================================================
    bool CoordModelMapping::readCoordinateMapping(const std::string& pDirectoryFileName)
    {
        FILE *f = fopen(pDirectoryFileName.c_str(), "rb");
        bool result = false;
        char buffer[500+1];

        if(f)
        {
            result = true;
            CMappingEntry* cMappingEntry;
            while(fgets(buffer, 500, f))
            {
                //char namebuffer[500];
                char positionbuffer[500];
                int xpos, ypos, noVec;
                float scale;
                xpos = ypos = noVec = 0;

                //sscanf(buffer, "%d %d %s %s %f %d", &xpos, &ypos, namebuffer,positionbuffer, &scale, &noVec);

                // this is ugly, but the format has no read delimiter and a space could be in the first part of the name
                int nameStart = findPosChar(buffer, ' ', 2);// find the 2. space
                if(nameStart > -1 && (iFilterMethod == NULL || (*iFilterMethod)(buffer)))
                {
                    ++nameStart;
                                                            // find the 1. / (now a space only can be found at the end of the name)
                    int nameEnd = nameStart + findPosChar(&buffer[nameStart], '/', 1);
                                                            // find the 1. space (after the name)
                    nameEnd += findPosChar(&buffer[nameEnd], ' ', 1);
                    buffer[nameEnd] = 0;                    // terminate the name

                    sscanf(buffer, "%d %d", &xpos, &ypos);
                    sscanf(&buffer[nameEnd+1], "%s %f %d", positionbuffer, &scale, &noVec);
                    unsigned int mapId = getMapIdFromFilename(std::string(&buffer[nameStart]));
                    if(!iMapIds.contains(mapId))
                    {
                        iMapIds.append(mapId);
                    }
                    if(!isWorldAreaMap(mapId))
                    {
                        xpos = 0;                           // store all files under the groupKey
                        ypos = 0;
                    }

                    std::string key = CMappingEntry::getKeyString(mapId, xpos, ypos);
                    cMappingEntry = getCMappingEntry(key);
                    if(cMappingEntry == 0)
                    {
                        cMappingEntry = new CMappingEntry(mapId, xpos, ypos);
                        addCMappingEntry(cMappingEntry);
                    }
                    char namebuffer2[500];
                    sprintf(namebuffer2, "%d %s#%s_%f", noVec, &buffer[nameStart], positionbuffer, scale);
                    cMappingEntry->addFilename(namebuffer2);
                    //break;
                }
            }
            fclose(f);
        }
        return result;
    }

    //============================================================

    const NameCollection CoordModelMapping::getFilenamesForCoordinate(unsigned int pMapId, int xPos, int yPos)
    {
        NameCollection result;
        Array<std::string> rawNames;

        CMappingEntry *entry = getCMappingEntry(CMappingEntry::getKeyString(pMapId, xPos, yPos));
        if(entry != 0)
        {
            rawNames = entry->getFilenames();

            int pos = 0;
            while(pos < rawNames.size())
            {
                char namebuffer[500];
                int noVerc;
                int startName = findPosChar(rawNames[pos].c_str(), ' ', 1) + 1;
                int endName = (int) rawNames[pos].length();
                sscanf(rawNames[pos].c_str(), "%d", &noVerc);
                memcpy(namebuffer, &rawNames[pos].c_str()[startName], endName-startName);
                namebuffer[endName-startName]  = 0;
                sscanf(rawNames[pos].c_str(), "%d", &noVerc);
                std::string modelPosFileName = std::string(namebuffer);
                if(noVerc > MIN_VERTICES_FOR_OWN_CONTAINER_FILE)
                {
                    result.appendToSingle(modelPosFileName);
                }
                else
                {
                    result.appendToMain(modelPosFileName);
                }
                ++pos;
            }
        }
        return result;
    }

    //=================================================================

}


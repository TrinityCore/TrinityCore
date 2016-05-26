/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define _CRT_SECURE_NO_DEPRECATE

#include "adt.h"

// Helper
int holetab_h[4] = { 0x1111, 0x2222, 0x4444, 0x8888 };
int holetab_v[4] = { 0x000F, 0x00F0, 0x0F00, 0xF000 };

u_map_fcc MHDRMagic = { { 'R','D','H','M' } };
u_map_fcc MCINMagic = { { 'N','I','C','M' } };
u_map_fcc MH2OMagic = { { 'O','2','H','M' } };
u_map_fcc MCNKMagic = { { 'K','N','C','M' } };
u_map_fcc MCVTMagic = { { 'T','V','C','M' } };
u_map_fcc MCLQMagic = { { 'Q','L','C','M' } };
u_map_fcc MFBOMagic = { { 'O','B','F','M' } };

bool isHole(int holes, int i, int j)
{
    int testi = i / 2;
    int testj = j / 4;
    if(testi > 3) testi = 3;
    if(testj > 3) testj = 3;
    return (holes & holetab_h[testi] & holetab_v[testj]) != 0;
}

//
// Adt file loader class
//
ADT_file::ADT_file()
{
    a_grid = 0;
}

ADT_file::~ADT_file()
{
    free();
}

void ADT_file::free()
{
    a_grid = 0;
    FileLoader::free();
}

//
// Adt file check function
//
bool ADT_file::prepareLoadedData()
{
    // Check parent
    if (!FileLoader::prepareLoadedData())
        return false;

    // Check and prepare MHDR
    a_grid = (adt_MHDR *)(GetData()+8+version->size);
    if (!a_grid->prepareLoadedData())
        return false;

    return true;
}

bool adt_MHDR::prepareLoadedData()
{
    if (fcc != MHDRMagic.fcc)
        return false;

    if (size != sizeof(adt_MHDR) - 8)
        return false;

    // Check and prepare MCIN
    if (offsMCIN && !getMCIN()->prepareLoadedData())
        return false;

    // Check and prepare MH2O
    if (offsMH2O && !getMH2O()->prepareLoadedData())
        return false;

    if (offsMFBO && flags & 1 && !getMFBO()->prepareLoadedData())
        return false;

    return true;
}

bool adt_MCIN::prepareLoadedData()
{
    if (fcc != MCINMagic.fcc)
        return false;

    // Check cells data
    for (int i=0; i<ADT_CELLS_PER_GRID;i++)
        for (int j=0; j<ADT_CELLS_PER_GRID;j++)
            if (cells[i][j].offsMCNK && !getMCNK(i,j)->prepareLoadedData())
                return false;

    return true;
}

bool adt_MH2O::prepareLoadedData()
{
    if (fcc != MH2OMagic.fcc)
        return false;

    // Check liquid data
//    for (int i=0; i<ADT_CELLS_PER_GRID;i++)
//        for (int j=0; j<ADT_CELLS_PER_GRID;j++)

    return true;
}

bool adt_MCNK::prepareLoadedData()
{
    if (fcc != MCNKMagic.fcc)
        return false;

    // Check height map
    if (offsMCVT && !getMCVT()->prepareLoadedData())
        return false;
    // Check liquid data
    if (offsMCLQ && !getMCLQ()->prepareLoadedData())
        return false;

    return true;
}

bool adt_MCVT::prepareLoadedData()
{
    if (fcc != MCVTMagic.fcc)
        return false;

    if (size != sizeof(adt_MCVT)-8)
        return false;

    return true;
}

bool adt_MCLQ::prepareLoadedData()
{
    if (fcc != MCLQMagic.fcc)
        return false;

    return true;
}

bool adt_MFBO::prepareLoadedData()
{
    return fcc == MFBOMagic.fcc;
}

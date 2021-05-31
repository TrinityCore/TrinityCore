/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef VMAPEXPORT_H
#define VMAPEXPORT_H

#include "Define.h"
#include <string>
#include <unordered_map>
// @tswow-begin
#include <set>
// @tswow-end

enum ModelFlags
{
    MOD_M2 = 1,
    MOD_WORLDSPAWN = 1<<1,
    MOD_HAS_BOUND = 1<<2
};

struct WMODoodadData;

// @tswow-begin
extern std::string szWorkDirWmo;
// @tswow-end
extern std::unordered_map<std::string, WMODoodadData> WmoDoodads;
// @tswow-begin
bool HasDoneFile(char const* file);
void FinishFile(char const* file);
extern std::set<int> assembled_maps;
extern std::set<std::string> assembled_models;
extern std::set<std::pair<int, int>> assembled_tiles;
extern std::set<std::string> done_files;
extern int bindir_counter;
// @tswow-end

uint32 GenerateUniqueObjectId(uint32 clientId, uint16 clientDoodadId);

bool FileExists(const char * file);
void strToLower(char* str);

bool ExtractSingleWmo(std::string& fname);
bool ExtractSingleModel(std::string& fname);

void ExtractGameobjectModels();

#endif

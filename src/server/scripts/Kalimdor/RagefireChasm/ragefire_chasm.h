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

#ifndef RAGEFIRE_CHASM_H_
#define RAGEFIRE_CHASM_H_

#include "Define.h"

#define RCScriptName "instance_ragefire_chasm"
#define DataHeader   "RC"

uint32 const EncounterCount = 4;

enum RCDataTypes
{
    // Bosses
    DATA_OGGLEFLINT             = 0,
    DATA_JERGOSH_THE_INVOKER    = 1,
    DATA_BAZZALAN               = 2,
    DATA_TARAGAMAN_THE_HUNGERER = 3
};

#endif // RAGEFIRE_CHASM_H_


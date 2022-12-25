/*
 * Copyright 2023 AzgathCore
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

#include "ScriptMgr.h"
#include "Player.h"
#include "SpellMgr.h"
#include "Conversation.h"
#include "Chat.h"
#include "Log.h"
#include "LFGMgr.h"
#include "ScenarioMgr.h"
#include "Scenario.h"

enum
{
    MAP_INVASION_POINT = 1779,
    MAP_AGS = 1669,
    AREA_BOZI = 9025,
    AREA_AURINOR = 9100,
    AREA_SANGUA = 9128,
    AREA_REKINDLING = 9126,
    AREA_CEN_GAR = 9126,
    AREA_VAL = 9127,
    AREA_BONICH = 9180,
    AREA_NAIGTAL = 9102,

    AREA_MATRON_FOLNUNA = 9295,
    AREA_SOTANATHOR = 9299,
    AREA_OCCULARUS = 9298,
    AREA_INQUISITOR_METO = 9297,
    AREA_PIT_LORD_VILEMUS = 9296,
    AREA_MISTRESS_ALLURADEL = 9300,

    NPC_FELFRENZY_BERSERKER = 125785,
    NPC_FELFLAME_INVADER = 125755,
    NPC_SHADOWSWORN_BETRAYER = 125758,
    NPC_BLADESWORN_DISCIPLE = 125788,
    NPC_CONQUERING_RIFTSTALKER = 125199,
    NPC_FELFLAME_SUBJUGATOR = 125197,
    NPC_DREAD_KNIGHT_ZAKGAL = 125252,

    NPC_TEMPORAL_ANOMALY = 125856,
    NPC_DURAEL = 125525,
    NPC_INVASION_POINT = 124884,
    NPC_DEMON_HUNTER = 127108,

    ENTRY_AURINOR = 125849,
    ENTRY_SANGUA = 125863,
    ENTRY_CEN_GAR = 126120,
    ENTRY_VAL = 126499,
    ENTRY_BONICH = 126547,
    ENTRY_NAIGTAL = 126593,

    ENTRY_MATRON_FOLNUNA = 127528,
    ENTRY_SOTANATHOR = 127532,
    ENTRY_OCCULARUS = 127533,
    ENTRY_INQUISITOR_METO = 127535,
    ENTRY_PIT_LORD_VILEMUS = 127531,
    ENTRY_MISTRESS_ALLURADEL = 127536,

    LFG_DUNGEON_CEN_GAR = 1617,
    LFG_DUNGEON_NAIGTAL = 1618,
    LFG_DUNGEON_SANGUA = 1619,
    LFG_DUNGEON_AURINOR = 1620,
    LFG_DUNGEON_VAL = 1621,
    LFG_DUNGEON_BONICH = 1622,
    LFG_DUNGEON_MATRON_FOLNUNA = 1628,
    LFG_DUNGEON_PIT_LORD_VILEMUS = 1629,
    LFG_DUNGEON_SOTANATHOR = 1630,
    LFG_DUNGEON_OCCULARUS = 1631,
    LFG_DUNGEON_INQUISITOR_METO = 1632,
    LFG_DUNGEON_MISTRESS_ALLURADEL = 1633,
};


enum
{
    DATA_AKC = 0,
    DATA_STAGE_1,
    DATA_STAGE_2,
    DATA_STAGE_3,
    DATA_STAGE_4,
    DATA_STAGE_5,
    DATA_STAGE_6,
    DATA_STAGE_7,

    DATA_MAX_ENCOUNTERS,
};

struct InvasionPointData
{
    uint32 areaid, conversationid, scenarioid, scenariostep;
};
InvasionPointData const invasionpointData[] =
{
    { AREA_BOZI,                   0, 1379, 3410 },
    { AREA_AURINOR,             5440, 1391, 3443 },
    { AREA_SANGUA,              5788, 1394, 3452 },
    { AREA_CEN_GAR,             5788, 1404, 3471 },
    { AREA_VAL,                 5788, 1406, 3477 },
    { AREA_BONICH,              5786, 1409, 3487 },
    { AREA_NAIGTAL,             5923, 1411, 3492 },
    { AREA_MATRON_FOLNUNA,      5231, 1412, 3502 },
    { AREA_SOTANATHOR,          5486, 1418, 3509 },
    { AREA_OCCULARUS,           5893, 1419, 3511 },
    { AREA_INQUISITOR_METO,     5797, 1420, 3513 },
    { AREA_PIT_LORD_VILEMUS,       0, 1421, 3515 },
    { AREA_MISTRESS_ALLURADEL,     0, 1422, 3517 },
};

enum CriteriaTrees
{
    CRITERIA_TREE_AURINOR_DISRUPT_THE_LEGION_S_FORCES = 60429,
    CRITERIA_TREE_AURINOR_DESTROY_THE_TEMPORAL_ANOMALIES = 60431,
    CRITERIA_TREE_AURINOR_KILL_THE_LEGION_S_COMMANDER = 60433,
};

enum ScenarioEvents
{
    SCENARIO_EVENT_AURINOR_DISRUPT_THE_LEGION_S_FORCES = 59201,
    SCENARIO_EVENT_AURINOR_DESTROY_THE_TEMPORAL_ANOMALIES = 59346,
    SCENARIO_EVENT_AURINOR_KILL_THE_LEGION_S_COMMANDER = 59372,
};

void AddSC_instance_invasion_point()
{
    
}

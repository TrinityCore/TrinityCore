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

#include "Log.h"
#include "Scenario.h"
#include "InstanceScenario.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"
#include "CombatAI.h"
#include "TemporarySummon.h"
#include "Unit.h"

enum DataTypes
{
    SCENARIO_ID_DH = 961, // The Aldrachi Warblades
    SCENARIO_ID_PALADIN = 775, // The Legend of The Ashbringer
    DATA_DH_STEP_1 = 1939, // Free Allari from her chains.(Picking Up the Pieces)
    DATA_DH_STEP_2 = 1940, // Cut through the demon hordes and destroy their portals. (Their Blood Will Flow)
    DATA_DH_STEP_3 = 2299, // Two of Caria's lieutenants are performing a dark ritual. They must be stopped. (A River of Souls)
    DATA_DH_STEP_4 = 1948, // Gorgonnash has risen to stop your assault. (In the Darkness of the Pit)
    DATA_DH_STEP_5 = 1941, // Use your demonic senses to pickup Caria's trail. (Nowhere to Hide)
    DATA_DH_STEP_6 = 1942, // Caria Felsoul's time has come. (Vengeance for the Illidari)
    DATA_DH_STEP_7 = 2302, // Claim the Aldrachi Warblades as your own. (Right by Ascension)
    DATA_PALADIN_STEP_1 = 1488, // Lead the paladins of the Argent Crusade into battle. (Sounding the Charge)
    DATA_PALADIN_STEP_2 = 1485, // Destroy the demon army. (Crusaders' March)
    DATA_PALADIN_STEP_3 = 1486, // Destroy Jailer Zerus and save Highlord Tirion Fordring. (Holy Vengeance)
    DATA_PALADIN_STEP_4 = 1487, // Find the Ashbringer within the Lost Temple. (The Ashbringer)
    DATA_PALADIN_STEP_5 = 2632, // Call upon the power of the Ashbringer to break free from Balnazzar's control. (One Final Blessing)
    DATA_PALADIN_STEP_6 = 1853, // Defeat Balnazzar. (Balnazzar the Risen)
    DATA_PALADIN_STEP_7 = 1854, // Return to Tirion Fordring. (The Fate of the Highlord)
    DATA_MAX_ENCOUNTERS_DH = 7,
    DATA_MAX_ENCOUNTERS_PALADIN = 7,
    PHASE_DH = 5875,
    PHASE_PALADIN = 5171,
    NPC_ALLARI_SOULEATER = 98882,
    NPC_DOOMHERALD_AKVESH = 98975,
    NPC_GORGONNASH = 99046,
    NPC_DOOMHERALD_SAERA = 105095,
    NPC_DOOMHERALD_TARAAR = 105094,
    NPC_ALDRACHI_REVENANT = 105151,
    NPC_CARIA_FELSOUL = 99184,
    NPC_ALDRACHI_WARBLADES = 105155,
    GO_ALDRACHI_WARBLADES = 248785,
    GO_FELSOUL_PORTAL_1 = 248573,
    GO_FELSOUL_PORTAL_2 = 248517,
    GO_FELSOUL_CAGE = 266029,
    GO_STONE_WALL = 245119,
    NORMAL_PHASE = 169,
    DATA_BROKENSHORE = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DH_VENGEANCE_ARTIFACT_ACQUISTION_LOOTED_SCENE = 1601,
    QUEST_VENGEANCE_WILL_BE_OURS_1 = 40249,
    QUEST_VENGEANCE_WILL_BE_OURS_2 = 41863,
};

void AddSC_scenario_artifact_brokenshore()
{
    
}

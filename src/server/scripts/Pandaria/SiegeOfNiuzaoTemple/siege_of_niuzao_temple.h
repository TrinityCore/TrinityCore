/*
 * Trinity Core and update by MoPCore Forums
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
 *
 * Dungeon: Siege of Niuzao Temple.
 * Description: Header Script.
 */

#ifndef DEF_SIEGE_OF_NIUZAO_TEMPLE_H_
#define DEF_SIEGE_OF_NIUZAO_TEMPLE_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define MAX_ENCOUNTERS 4

enum DataTypes // Events / Encounters.
{
	DATA_VIZIER_JINBAK_EVENT       = 0,
    DATA_COMMANDER_VOJAK_EVENT     = 1,
    DATA_GENERAL_PAVALAK_EVENT     = 2,    
	DATA_WING_LEADER_NERONOK_EVENT = 3
};

enum Data     // GUID handling.
{
	DATA_VIZIER_JINBAK             = 0,
    DATA_COMMANDER_VOJAK           = 1,
    DATA_GENERAL_PAVALAK           = 2,    
	DATA_WING_LEADER_NERONOK       = 3
};

enum CreaturesIds
{
    // Bosses
    BOSS_VIZIER_JINBAK             = 61567,
    BOSS_COMMANDER_VOJAK           = 61634,
    BOSS_GENERAL_PAVALAK           = 61485,
    BOSS_WING_LEADER_NERONOK       = 62205,

    // NPCs
    NPC_SAP_PUDDLE                 = 61613,
    NPC_SAP_GLOBULE                = 61623,

    NPC_MANTID_TAR_KEG             = 61817, // Vehicle. Interaction for throwing keg.
    NPC_SIKTHIK_SWARMER            = 63106,
    NPC_SIKTHIK_AMBERWING          = 61699,
    NPC_SIKTHIK_DEMOLISHER         = 61670,
    NPC_SIKTHIK_WARRIOR            = 61701,

    NPC_LI_CHU                     = 61812,
    NPC_LO_CHU                     = 62794,
    NPC_YANG_IRONCLAW              = 61620,
    NPC_MAKESHIFT_CHARGE           = 65168,
    NPC_SIKTHIK_WARDEN             = 62795,
    NPC_TAR_PUDDLE_VOJAK           = 61579,

    NPC_DASHING_STRIKE             = 60107,
    NPC_BLADE_RUSH                 = 63720,
    NPC_SIKTHIK_SOLDIER            = 62348,
    NPC_SIKTHIK_AMBER_SAPPER       = 61484,
    NPC_SIEGE_EXPLOSIVES           = 61452  // Interaction for throwing explosive back.
};

enum GameObjectIds
{
    GO_VOJAK_PATH_WALL             = 210097, // Two on the path to prevent players from going down.
    GO_VOJAK_DOOR                  = 212921  // Gate after Vo'jak.
};

#endif // DEF_SIEGE_OF_NIUZAO_TEMPLE_H_

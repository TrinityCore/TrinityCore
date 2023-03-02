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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CombatAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "the_everbloom.h"
#include "G3D/Vector3.h"

enum XeritacSpells
{
    GO_TOXIC_EGGS                = 234113,

    NPC_XERITAC_VEHICLE          = 84666,
    NPC_TOXIC_SPIDERLING         = 84552,
    NPC_VENOM_SPRAYER            = 86547,
    NPC_GORGED_BURSTER           = 86552,
    NPC_VENOM_CRAZED             = 84554,

    SPELL_EJECT_ALL_PASSENGERS   = 50630,

    SPELL_WEB_CRAWL_1            = 169271,
    SPELL_DESCEND_1              = 169272,
    SPELL_DESCEND_2              = 169275,
    SPELL_DESCEND_3              = 172643,
    SPELL_WEB_CRAWL_2            = 169293,
    SPELL_TOXIC_GAS_XERITAC      = 169224,
    SPELL_TOXIC_GAS_MISSILE      = 169270,
    SPELL_TOXIC_BOLT             = 169375,
    SPELL_VENOMOUS_STING         = 169376,
    SPELL_GASEOUS_VOLLEY         = 169382,
    SPELL_GASEOUS_VOLLEY_MISSILE = 169383,
    SPELL_CONSUME_VEHICLE        = 169249,
    SPELL_CONSUME                = 169248,
    SPELL_DESPAWN_AREA_TRIGGERS  = 138175,
};

void AddSC_boss_xeritac()
{
    
}

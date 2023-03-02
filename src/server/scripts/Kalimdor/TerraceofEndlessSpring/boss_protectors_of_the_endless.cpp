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
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "terrace_of_endless_spring.h"

#define ENTRANCE_ORIENTATION 4.723f

enum eLootModes
{
    LOOT_PATTERNS = 0x2,
    LOOT_NORMAL = 0x4,
    LOOT_ELITE = 0x8
};

enum eProtectorsSpells
{
    // Shared
    SPELL_SHA_CORRUPTION = 117052,
    SPELL_SHA_MASK = 118221,

    // Protector Kaolan
    SPELL_TOUCH_OF_SHA = 117519,
    SPELL_DEFILED_GROUND_SUMMON = 117986,
    SPELL_DEFILED_GROUND_VISUAL = 117989,
    SPELL_DEFILED_GROUND_STACKS = 118091,
    SPELL_EXPEL_CORRUPTION_SUMMON = 117975,
    SPELL_EXPEL_CORRUPTION_VISUAL = 117943,

    // Ancient Regail
    SPELL_LIGHTNING_BOLT = 117187,
    SPELL_LIGHTNING_PRISON = 111850,
    SPELL_LIGHTNING_PRISON_STUN = 117436,
    SPELL_LIGHTNING_STORM = 118077,
    SPELL_LIGHTNING_STORM_FIRST = 118064,
    SPELL_LIGHTNING_STORM_SECOND = 118040,
    SPELL_LIGHTNING_STORM_THIRD = 118053,
    SPELL_LIGHTNING_STORM_FOURTH = 118054,
    SPELL_LIGHTNING_STORM_FIFTH = 118055,
    SPELL_LIGHTNING_STORM_FIRST_DMG = 118003,
    SPELL_LIGHTNING_STORM_SECOND_DMG = 118004,
    SPELL_LIGHTNING_STORM_THIRD_DMG = 118005,
    SPELL_LIGHTNING_STORM_FOURTH_DMG = 118007,
    SPELL_LIGHTNING_STORM_FIFTH_DMG = 118008,
    SPELL_OVERWHELMING_CORRUPTION = 117351,
    SPELL_OVERWHELMING_CORRUPTION_STACK = 117353,

    // Ancient Asani
    SPELL_WATER_BOLT = 118312,
    SPELL_CLEANSING_WATERS_SUMMON = 117309,
    SPELL_CLEANSING_WATERS_VISUAL = 117250,
    SPELL_CLEANSING_WATERS_REGEN = 117283,
    SPELL_CORRUPTING_WATERS_SUMMON = 117227,
    SPELL_CORRUPTING_WATERS_AURA = 117217,
    SPELL_PURIFIED = 117235,

    // Minions of Fear
    SPELL_CORRUPTED_ESSENCE = 118191,
    SPELL_ESSENCE_OF_FEAR = 118198,
    SPELL_SUPERIOR_CORRUPTED_ESSENCE = 117905,
    SPELL_SUPERIOR_ESSENCE_OF_FEAR = 118186,

    SPELL_PROTECTOR_BERSERK = 26662,
    SPELL_PROTECTOR_ACHIEVEMENT_MARKER = 123900,
};

enum eProtectorsActions
{
    // Shared
    ACTION_FIRST_PROTECTOR_DIED = 0,
    ACTION_SECOND_PROTECTOR_DIED = 1,
    ACTION_DESPAWN_SUMMONS = 3,
    ACTION_INIT_MINION_CONTROLLER = 4,
    ACTION_RESET_MINION_CONTROLLER = 5,
    ACTION_EVENT_DONE = 6,
    ACTION_I_WAS_INTERRUPTED = 7,
};

enum eProtectorsEvents
{
    // Protector Kaolan
    EVENT_TOUCH_OF_SHA = 1,
    EVENT_DEFILED_GROUND = 2,
    EVENT_EXPEL_CORRUPTION = 3,

    // Ancient Regail
    EVENT_LIGHTNING_BOLT = 4,
    EVENT_LIGHTNING_PRISON = 5,
    EVENT_LIGHTNING_STORM = 6,
    EVENT_OVERWHELMING_CORRUPTION = 7,

    // Ancient Asani
    EVENT_WATER_BOLT = 8,
    EVENT_CLEANSING_WATERS = 9,
    EVENT_CORRUPTING_WATERS = 10,

    // Adds
    EVENT_REFRESH_CLEANSING_WATERS = 11,
    EVENT_DESPAWN_CLEANSING_WATERS = 12,
    EVENT_SPAWN_MINION_OF_FEAR = 13,

    EVENT_ADD_BERSERK,
    EVENT_CHECK_WIPE,
};

enum eProtectorsSays
{
    TALK_INTRO,
    TALK_ASANI_AGGRO,
    TALK_REGAIL_AGGRO,
    TALK_KAOLAN_DIES_FIRST_ASANI,
    TALK_KAOLAN_DIES_FIRST_REGAIL,
    TALK_ASANI_DIES_FIRST_KAOLAN,
    TALK_ASANI_DIES_FIRST_REGAIL,
    TALK_CORRUPTED_WATERS,
    TALK_LIGHTNING_STORM,
    TALK_EXPEL_CORRUPTION,
    TALK_REGAIL_DIES_SECOND_ASANI,
    TALK_REGAIL_DIES_SECOND_KAOLAN,
    TALK_ASANI_DIES_SECOND_REGAIL,
    TALK_ASANI_DIES_SECOND_KAOLAN,
    TALK_ASANI_SLAY,
    TALK_REGAIL_SLAY,
    TALK_KAOLAN_SLAY,
    TALK_ASANI_DEATH,
    TALK_REGAIL_DEATH,
    TALK_KAOLAN_DEATH
};

enum eProtectorsEquipId
{
    ASANI_MH_ITEM = 79832,
    KAOLAN_MH_ITEM = 81390,
    REGAIL_ITEMS = 81389
};

uint8 ProtectorsAlive(InstanceScript* instance, Creature* me)
{
    uint8 count = 0;
    if (!instance || !me)
        return count;

    Creature* asani = instance->GetCreature(instance->GetData64(NPC_ANCIENT_ASANI));
    if (asani && asani->IsAlive())
        ++count;

    Creature* regail = instance->GetCreature(instance->GetData64(NPC_ANCIENT_REGAIL));
    if (regail && regail->IsAlive())
        ++count;

    Creature* kaolan = instance->GetCreature(instance->GetData64(NPC_PROTECTOR_KAOLAN));
    if (kaolan && kaolan->IsAlive())
        ++count;

    return count;
}

void RespawnProtectors(InstanceScript* instance, Creature* me)
{
    if (!instance || !me)
        return;

    Creature* asani = instance->GetCreature(instance->GetData64(NPC_ANCIENT_ASANI));
    if (asani)
    {
        asani->Respawn();
        asani->GetMotionMaster()->MoveTargetedHome();
    }

    Creature* regail = instance->GetCreature(instance->GetData64(NPC_ANCIENT_REGAIL));
    if (regail)
    {
        regail->Respawn();
        regail->GetMotionMaster()->MoveTargetedHome();
    }

    Creature* kaolan = instance->GetCreature(instance->GetData64(NPC_PROTECTOR_KAOLAN));
    if (kaolan)
    {
        kaolan->Respawn();
        kaolan->GetMotionMaster()->MoveTargetedHome();
    }
}

void AddSC_boss_protectors_of_the_endless()
{
    
}

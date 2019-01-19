/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/*
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_pal_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "CombatAI.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "PetAI.h"
#include "ScriptedCreature.h"

enum GuardianOfAncientKings
{
    SPELL_ANCIENT_GUARDIAN                      = 86657,
    NPC_GUARDIAN_OF_ANCIENT_KINGS_PROTECTION    = 46490
};

struct npc_pet_pal_guardian_of_ancient_kings : public PetAI
{
    npc_pet_pal_guardian_of_ancient_kings(Creature* creature) : PetAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        if (me->GetEntry() == NPC_GUARDIAN_OF_ANCIENT_KINGS_PROTECTION)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            DoCast(summoner, SPELL_ANCIENT_GUARDIAN);
        }
    }
};

void AddSC_paladin_pet_script()
{
    RegisterCreatureAI(npc_pet_pal_guardian_of_ancient_kings);
}

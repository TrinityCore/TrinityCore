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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "necrotic_wake.h"

enum Spells
{
    SPELL_LAND_OF_THE_DEAD_CAST = 321226,
    SPELL_LAND_OF_THE_DEAD_MISSILE = 319874,
    SPELL_LAND_OF_THE_DEAD_MISSILE_SECOND = 319902,
    SPELL_LAND_OF_THE_DEAD_MISSILE_THIRD = 333627,
    SPELL_FINAL_HARVEST = 321247,
    SPELL_FINAL_HARVEST_DAMAGE = 321253,
    SPELL_NECROTIC_BOLT = 320170,
    SPELL_UNHOLY_FRENZY = 320012,
    SPELL_NECROTIC_BREATH_TRIGGER = 337074,
    EVENT_LAND_OF_THE_DEAD = 1,
    EVENT_NECROTIC_BREATH
};

//162692
struct npc_amarth : public ScriptedAI
{
    npc_amarth(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
    }
};

void AddSC_boss_amarth()
{
    RegisterCreatureAI(npc_amarth);
}
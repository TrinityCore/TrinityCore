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

#include "AIGroup.h"
#include "Creature.h"
#include "Player.h"
#include "SpellInfo.h"

AIGroup::AIGroup(Creature* creature) : CreatureAI(creature) { }

void AIGroup::InitializeAI()
{
    GetScript()->OnInitialize(me);
}

void AIGroup::OnActionTriggersChange(uint32 /*triggersId*/)
{
    GetScript()->ReplaceActionTriggers();
}

void AIGroup::UpdateAI(uint32 diff)
{
    GetScript()->OnUpdate(diff);

    if (!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

void AIGroup::MovementInform(uint32 type, uint32 id)
{
    GetScript()->MovementInform(type, id);
}

void AIGroup::JustDied(Unit* killer)
{
    GetScript()->ProcessEventsFor(UnitActionTriggers::OnDeath, killer);
    GetScript()->TerminateActionSets();
}

void AIGroup::SpellHit(WorldObject* caster, SpellInfo const* spellInfo)
{
    if (!spellInfo)
        return;

    GetScript()->ProcessEventsFor(UnitActionTriggers::OnSpell, caster->ToUnit(), spellInfo->Id, 0, caster->ToGameObject());
}

void AIGroup::JustAppeared()
{
    CreatureAI::JustAppeared();

    GetScript()->ProcessEventsFor(UnitActionTriggers::OnSpawn);
}

void AIGroup::ReceiveEmote(Player* player, uint32 textEmote)
{
    GetScript()->ProcessEventsFor(UnitActionTriggers::OnEmote, player, textEmote);
}

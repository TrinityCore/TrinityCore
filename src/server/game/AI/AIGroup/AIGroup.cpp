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
#include "AIGroupEntity.h"
#include "Creature.h"
#include "Map.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellInfo.h"

AIGroupCreature::AIGroupCreature(Creature* creature) : CreatureAI(creature) { }

AIGroup* AIGroupCreature::GetGroup() const
{
    return AIGroup::GetAIGroup(me);
}

AIGroupScript* AIGroupCreature::GetScript()
{
    if (AIGroup* group = GetGroup())
    {
        group->GetScript()->SetActor(me);
        return group->GetScript();
    }

    if (!_scriptInitialized)
    {
        _script.OnInitialize(me);
        _scriptInitialized = true;
    }

    return &_script;
}

void AIGroupCreature::InitializeAI()
{
    if (AIGroup* group = GetGroup())
    {
        group->GetScript()->SetActor(me);
        return;
    }

    GetScript();
}

void AIGroupCreature::OnActionTriggersChange(uint32 /*triggersId*/)
{
    GetScript()->ReplaceActionTriggers();
}

void AIGroupCreature::MovementInform(uint32 type, uint32 id)
{
    GetScript()->MovementInform(type, id);
}

void AIGroupCreature::UpdateAI(uint32 diff)
{
    if (AIGroup* group = GetGroup())
        group->GetScript()->SetActor(me);
    else
        GetScript()->OnUpdate(diff);

    if (!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

void AIGroupCreature::JustEngagedWith(Unit* enemy)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnEnterCombat, enemy);
}

void AIGroupCreature::JustDied(Unit* killer)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnDeath, killer);
    GetScript()->TerminateActionSets();
}

void AIGroupCreature::SpellHit(WorldObject* caster, SpellInfo const* spellInfo)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnSpell, caster, spellInfo->Id);
}

void AIGroupCreature::KilledUnit(Unit* victim)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnKill, victim);
}

void AIGroupCreature::JustAppeared()
{
    CreatureAI::JustAppeared();

    if (!GetGroup())
        GetScript()->ProcessEventsFor(ActionTriggers::OnSpawn);
}

void AIGroupCreature::ReceiveEmote(Player* player, uint32 textEmote)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnEmote, player, textEmote);
}

void AIGroupCreature::OnSpellCast(SpellInfo const* spellInfo)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnSpellCast, nullptr, spellInfo->Id);
}

void AIGroupCreature::JustReachedHome()
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnCombatReturn);
}

void AIGroupCreature::OnDespawn()
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnDespawn);
}

void AIGroupCreature::OnSpellFailed(SpellInfo const* spellInfo)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnSpellFailed, nullptr, spellInfo->Id);
}

void AIGroupCreature::OnSpellStart(SpellInfo const* spellInfo)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnSpellStart, nullptr, spellInfo->Id);
}

void AIGroupCreature::OnAuraApplied(AuraApplication const* aurApp)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnAuraApplied, nullptr, aurApp->GetBase()->GetSpellInfo()->Id);
}

void AIGroupCreature::OnAuraRemoved(AuraApplication const* aurApp)
{
    GetScript()->ProcessEventsFor(ActionTriggers::OnAuraRemoved, nullptr, aurApp->GetBase()->GetSpellInfo()->Id);
}

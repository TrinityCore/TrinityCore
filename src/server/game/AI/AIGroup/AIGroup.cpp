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

/// Creature Section

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
    GetScript()->NotifyTriggers(ActionTriggers::OnEnterCombat, enemy);
}

void AIGroupCreature::EnterEvadeMode(EvadeReason why)
{
    CreatureAI::EnterEvadeMode(why);

    GetScript()->NotifyTriggers(ActionTriggers::OnLeaveCombat);
}

void AIGroupCreature::JustDied(Unit* killer)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnDeath, killer);
    GetScript()->TerminateActionSets();
}

void AIGroupCreature::SpellHit(WorldObject* caster, SpellInfo const* spellInfo)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnSpell, caster, spellInfo->Id);
}

void AIGroupCreature::KilledUnit(Unit* victim)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnKill, victim);
}

void AIGroupCreature::JustAppeared()
{
    CreatureAI::JustAppeared();

    if (!GetGroup())
        GetScript()->NotifyTriggers(ActionTriggers::OnSpawn);
}

void AIGroupCreature::ReceiveEmote(Player* player, uint32 textEmote)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnEmote, player, textEmote);
}

void AIGroupCreature::OnCombatTrigger(Unit* sender, uint32 triggerId)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnCombatTrigger, sender, triggerId);
}

void AIGroupCreature::OnSpellCast(SpellInfo const* spellInfo)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnSpellCast, nullptr, spellInfo->Id);
}

void AIGroupCreature::JustReachedHome()
{
    GetScript()->NotifyTriggers(ActionTriggers::OnCombatReturn);
}

void AIGroupCreature::OnGeneralTrigger(Unit* sender, uint32 triggerId)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnGeneralTrigger, sender, triggerId);
}

void AIGroupCreature::OnDespawn()
{
    GetScript()->NotifyTriggers(ActionTriggers::OnDespawn);
}

void AIGroupCreature::OnSpellFailed(SpellInfo const* spellInfo)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnSpellFailed, nullptr, spellInfo->Id);
}

void AIGroupCreature::OnCharmed(bool isNew)
{
    CreatureAI::OnCharmed(isNew);

    if (!isNew)
        GetScript()->NotifyTriggers(ActionTriggers::OnCharmBreak);
}

void AIGroupCreature::OnSpellStart(SpellInfo const* spellInfo)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnSpellStart, nullptr, spellInfo->Id);
}

void AIGroupCreature::OnAuraApplied(AuraApplication const* aurApp)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnAuraApplied, nullptr, aurApp->GetBase()->GetSpellInfo()->Id);
}

void AIGroupCreature::OnAuraRemoved(AuraApplication const* aurApp)
{
    GetScript()->NotifyTriggers(ActionTriggers::OnAuraRemoved, nullptr, aurApp->GetBase()->GetSpellInfo()->Id);
}

/// GameObject section

AIGroupGameObject::AIGroupGameObject(GameObject* go) : GameObjectAI(go) { }

AIGroupScript* AIGroupGameObject::GetScript()
{
    return &_script;
}

void AIGroupGameObject::InitializeAI()
{
    GetScript()->OnInitialize(me);
}

void AIGroupGameObject::UpdateAI(uint32 diff)
{
    GetScript()->OnUpdate(diff);
}

void AIGroupGameObject::OnActionTriggered(GameObjectActions action, WorldObject* user)
{
    GetScript()->OnActionTriggered(uint32(action), user);
}

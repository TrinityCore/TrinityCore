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

#include "Battleground.h"
#include "BattlegroundScript.h"
#include "Containers.h"
#include "Conversation.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

namespace NokhudonProvingGrounds
{
    namespace Actions
    {
        static constexpr uint32 ReactionTrigger = 1;
        static constexpr uint32 ReactionDead = 2;
    }

    namespace Creatures
    {
        static constexpr uint32 Malicia = 196670;
        static constexpr uint32 NokhudCombatant = 196470;
    }

    namespace GameObjects
    {
        static constexpr uint32 Door01 = 379282;
    }

    namespace MapIds
    {
        static constexpr uint32 NokhudonProvingGrounds = 2563;
    }

    namespace Spells
    {
        static constexpr uint32 ArenaLowHealthCooldownAura = 234031;
        static constexpr uint32 NokhudonProvingGroundsVOCooldownAuraPlayerDeath = 391325;
        static constexpr uint32 NokhudonProvingGroundsVOCooldownAura = 388904;
        static constexpr uint32 NokhudonProvingGroundsReactionTrigger = 388970;
    }

    namespace Texts
    {
        namespace Malicia
        {
            static constexpr uint8 Prepare = 0;
            static constexpr uint8 Start = 1;
            static constexpr uint8 ReactionNonGendered = 2;
        }
    }

    namespace Conversations
    {
        static constexpr std::array<uint32, 2> ReactionKill = { 20101, 20102 };
    }
}

struct arena_nokhudon_proving_grounds : ArenaScript
{
    explicit arena_nokhudon_proving_grounds(BattlegroundMap* map) : ArenaScript(map) {}

    void OnStart() override
    {
        for (ObjectGuid const& guid : _doorGUIDs)
        {
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
            {
                door->UseDoorOrButton();
                door->DespawnOrUnsummon(5s);
            }
        }

        if (Creature const* creature = battlegroundMap->GetCreature(_maliciaGUID))
            creature->AI()->Talk(NokhudonProvingGrounds::Texts::Malicia::Start);
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        switch (actionId)
        {
            case NokhudonProvingGrounds::Actions::ReactionTrigger:
                HandleReactionLowHealth(Object::ToPlayer(source));
                break;
            case NokhudonProvingGrounds::Actions::ReactionDead:
                HandleKill(Object::ToPlayer(target));
                break;
            default:
                break;
        }
    }

    void OnPrepareStage2() override
    {
        if (Creature const* creature = battlegroundMap->GetCreature(_maliciaGUID))
            creature->AI()->Talk(NokhudonProvingGrounds::Texts::Malicia::Prepare);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case NokhudonProvingGrounds::Creatures::Malicia:
                _maliciaGUID = creature->GetGUID();
                break;
            case NokhudonProvingGrounds::Creatures::NokhudCombatant:
                _nokhudCombatantGUIDs.emplace_back(creature->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case NokhudonProvingGrounds::GameObjects::Door01:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnPlayerJoined(Player* player, bool /*inBattleground*/) override
    {
        player->CastSpell(nullptr, NokhudonProvingGrounds::Spells::NokhudonProvingGroundsReactionTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void HandleKill(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_maliciaGUID))
        {
            if (creature->HasAura(NokhudonProvingGrounds::Spells::NokhudonProvingGroundsVOCooldownAuraPlayerDeath))
                return;

            uint32 conversationId = Trinity::Containers::SelectRandomContainerElement(NokhudonProvingGrounds::Conversations::ReactionKill);
            Conversation::CreateConversation(conversationId, creature, creature->GetPosition(), ObjectGuid::Empty);

            creature->CastSpell(nullptr, NokhudonProvingGrounds::Spells::NokhudonProvingGroundsVOCooldownAuraPlayerDeath, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

    void HandleReactionLowHealth(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_maliciaGUID))
        {
            if (creature->HasAura(NokhudonProvingGrounds::Spells::NokhudonProvingGroundsVOCooldownAura))
                return;

            creature->AI()->Talk(NokhudonProvingGrounds::Texts::Malicia::ReactionNonGendered, victim);

            creature->CastSpell(nullptr, NokhudonProvingGrounds::Spells::NokhudonProvingGroundsVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }

        for (ObjectGuid const& guid : _nokhudCombatantGUIDs)
            if (Creature* creature = battlegroundMap->GetCreature(guid))
                creature->AI()->DoAction(NokhudonProvingGrounds::Actions::ReactionTrigger);
    }

private:
    GuidVector _doorGUIDs;
    GuidVector _nokhudCombatantGUIDs;
    ObjectGuid _maliciaGUID;
};

// 196470 - Nokhud Combatant
struct npc_nokhudon_proving_grounds_nokhud_combatant : ScriptedAI
{
    explicit npc_nokhudon_proving_grounds_nokhud_combatant(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
            case NokhudonProvingGrounds::Actions::ReactionTrigger:
                HandleEmoteSequence();
                break;
            default:
                break;
        }
    }

    void HandleEmoteSequence()
    {
        if (me->GetStandState() != UNIT_STAND_STATE_SIT)
            return;

        me->HandleEmoteCommand(EMOTE_ONESHOT_JUMPSTART);
        me->SetStandState(UNIT_STAND_STATE_STAND);

        _scheduler.Schedule(2s, [&](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
            if (context.GetRepeatCounter() < 2)
                context.Repeat(1s);
            else
            {
                context.Schedule(1s, [&](TaskContext)
                {
                    me->SetStandState(UNIT_STAND_STATE_SIT);
                });
            }
        });
    }

private:
    TaskScheduler _scheduler;
};

// 388969 - Nokhudon Proving Grounds Reaction Trigger - Low Health
class spell_nokhudon_proving_grounds_trigger_low_health : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == NokhudonProvingGrounds::MapIds::NokhudonProvingGrounds;
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        if (target->HasAura(NokhudonProvingGrounds::Spells::ArenaLowHealthCooldownAura))
            return;

        target->CastSpell(nullptr, NokhudonProvingGrounds::Spells::ArenaLowHealthCooldownAura, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

        if (ZoneScript* zoneScript = target->FindZoneScript())
            zoneScript->DoAction(NokhudonProvingGrounds::Actions::ReactionTrigger, GetCaster(), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_nokhudon_proving_grounds_trigger_low_health::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 388970 - Nokhudon Proving Grounds Reaction Trigger
class spell_nokhudon_proving_grounds_reaction_trigger : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == NokhudonProvingGrounds::MapIds::NokhudonProvingGrounds;
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        if (ZoneScript* zonescript = GetTarget()->FindZoneScript())
            zonescript->DoAction(NokhudonProvingGrounds::Actions::ReactionDead, eventInfo.GetActor(), eventInfo.GetProcTarget());
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_nokhudon_proving_grounds_reaction_trigger::HandleProc);
    }
};

void AddSC_arena_nokhudon_proving_grounds()
{
    RegisterBattlegroundMapScript(arena_nokhudon_proving_grounds, NokhudonProvingGrounds::MapIds::NokhudonProvingGrounds);
    RegisterCreatureAI(npc_nokhudon_proving_grounds_nokhud_combatant);
    RegisterSpellScript(spell_nokhudon_proving_grounds_trigger_low_health);
    RegisterSpellScript(spell_nokhudon_proving_grounds_reaction_trigger);
}

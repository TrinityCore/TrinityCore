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
#include "ConditionMgr.h"
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

namespace EnigmaCrucible
{
    namespace Actions
    {
        static constexpr uint32 ReactionTrigger = 1;
        static constexpr uint32 ReactionDead = 2;
    }

    namespace Creatures
    {
        static constexpr uint32 ZoSorg = 188479;
    }

    namespace GameObjects
    {
        static constexpr uint32 Door01 = 376876;
        static constexpr uint32 Door02 = 376861;
    }

    namespace MapIds
    {
        static constexpr uint32 EnigmaCrucible = 2547;
    }

    namespace Positions
    {
        static constexpr Position PurpleWarningTeleport = { 327.70486f, 278.69965f, 90.0686f, 3.1415927f };
        static constexpr Position GoldWarningTeleport = { 201.601f, 268.516f, 90.0686f, 0.0f };
    }

    namespace Spells
    {
        static constexpr uint32 ArenaLowHealthCooldownAura = 234031;
        static constexpr uint32 EnigmaArenaVOCooldownAura = 371330;
        static constexpr uint32 EnigmaArenaReactionTrigger = 371601;
        static constexpr uint32 Warning = 370437;
        static constexpr uint32 WarningTeleport = 371319;
        static constexpr uint32 ArenaStartingAreaMarker = 228212;
    }

    namespace Texts
    {
        namespace ZoSorg
        {
            static constexpr uint8 Prepare = 0;
            static constexpr uint8 Prepare2 = 1;
            static constexpr uint8 Start = 2;
            static constexpr uint8 ReactionTrigger = 3;
        }
    }
}

struct arena_enigma_crucible : ArenaScript
{
    explicit arena_enigma_crucible(BattlegroundMap* map) : ArenaScript(map) { }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

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

        if (Creature const* creature = battlegroundMap->GetCreature(_zoSorgGUID))
            creature->AI()->Talk(EnigmaCrucible::Texts::ZoSorg::Start);

        _scheduler.Schedule(10s, [&](TaskContext context)
        {
            battlegroundMap->DoOnPlayers([&](Player* player)
            {
                if (!player->HasAura(EnigmaCrucible::Spells::ArenaStartingAreaMarker))
                    return;

                if (player->HasAura(EnigmaCrucible::Spells::Warning))
                    return;

                player->CastSpell(nullptr, EnigmaCrucible::Spells::Warning, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                });
            });

            context.Repeat();
        });
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        switch (actionId)
        {
            case EnigmaCrucible::Actions::ReactionTrigger:
                HandleReactionLowHealth(Object::ToPlayer(source));
                break;
            case EnigmaCrucible::Actions::ReactionDead:
                HandleKill(Object::ToPlayer(target));
                break;
            default:
                break;
        }
    }

    void OnPrepareStage2() override
    {
        if (Creature const* creature = battlegroundMap->GetCreature(_zoSorgGUID))
            creature->AI()->Talk(EnigmaCrucible::Texts::ZoSorg::Prepare);

        _scheduler.Schedule(10s, [&](TaskContext)
        {
            if (Creature const* creature = battlegroundMap->GetCreature(_zoSorgGUID))
                creature->AI()->Talk(EnigmaCrucible::Texts::ZoSorg::Prepare2);
        });
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case EnigmaCrucible::Creatures::ZoSorg:
                _zoSorgGUID = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case EnigmaCrucible::GameObjects::Door01:
            case EnigmaCrucible::GameObjects::Door02:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnPlayerJoined(Player* player, bool /*inBattleground*/) override
    {
        player->CastSpell(nullptr, EnigmaCrucible::Spells::EnigmaArenaReactionTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void HandleKill(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_zoSorgGUID))
        {
            if (creature->HasAura(EnigmaCrucible::Spells::EnigmaArenaVOCooldownAura))
                return;

            creature->AI()->Talk(EnigmaCrucible::Texts::ZoSorg::ReactionTrigger, victim);

            creature->CastSpell(nullptr, EnigmaCrucible::Spells::EnigmaArenaVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

    void HandleReactionLowHealth(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_zoSorgGUID))
        {
            if (creature->HasAura(EnigmaCrucible::Spells::EnigmaArenaVOCooldownAura))
                return;

            creature->AI()->Talk(EnigmaCrucible::Texts::ZoSorg::ReactionTrigger, victim);

            creature->CastSpell(nullptr, EnigmaCrucible::Spells::EnigmaArenaVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

private:
    GuidVector _doorGUIDs;
    ObjectGuid _zoSorgGUID;

    TaskScheduler _scheduler;
};

// 371602 - Enigma Arena Reaction Trigger - Low Health
class spell_enigma_arena_reaction_trigger_low_health : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == EnigmaCrucible::MapIds::EnigmaCrucible;
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        if (target->HasAura(EnigmaCrucible::Spells::ArenaLowHealthCooldownAura))
            return;

        target->CastSpell(nullptr, EnigmaCrucible::Spells::ArenaLowHealthCooldownAura, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });

        if (ZoneScript* zoneScript = target->FindZoneScript())
            zoneScript->DoAction(EnigmaCrucible::Actions::ReactionTrigger, GetCaster(), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_enigma_arena_reaction_trigger_low_health::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 371601 - Enigma Arena Reaction Trigger
class spell_enigma_arena_reaction_trigger : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == EnigmaCrucible::MapIds::EnigmaCrucible;
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        if (ZoneScript* zonescript = GetTarget()->FindZoneScript())
            zonescript->DoAction(EnigmaCrucible::Actions::ReactionDead, eventInfo.GetActor(), eventInfo.GetProcTarget());
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_enigma_arena_reaction_trigger::HandleProc);
    }
};

// 370437 - Warning (countdown)
class spell_enigma_arena_warning_countdown : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == EnigmaCrucible::MapIds::EnigmaCrucible;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ EnigmaCrucible::Spells::WarningTeleport });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Player* target = GetTarget()->ToPlayer();
        if (!target)
            return;

        if (!target->HasAura(EnigmaCrucible::Spells::ArenaStartingAreaMarker))
            return;

        target->CastSpell(nullptr, EnigmaCrucible::Spells::WarningTeleport, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_enigma_arena_warning_countdown::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 371319 - Warning Teleport
class spell_enigma_arena_warning_teleport : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == EnigmaCrucible::MapIds::EnigmaCrucible;
    }

    void HandleTeleport(SpellEffIndex /*effIndex*/) const
    {
        Player* target = GetHitPlayer();
        if (!target)
            return;

        if (target->GetBGTeam() == ALLIANCE)
            target->NearTeleportTo(EnigmaCrucible::Positions::PurpleWarningTeleport);
        else
            target->NearTeleportTo(EnigmaCrucible::Positions::GoldWarningTeleport);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_enigma_arena_warning_teleport::HandleTeleport, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class condition_enigma_arena_collision_doors : public ConditionScript
{
public:
    condition_enigma_arena_collision_doors() : ConditionScript("condition_enigma_arena_collision_doors") {}

    bool OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& sourceInfo) override
    {
        if (!sourceInfo.mConditionMap)
            return false;

        if (BattlegroundMap const* bgMap = sourceInfo.mConditionMap->ToBattlegroundMap())
            if (Battleground const* bg = bgMap->GetBG())
                if (bg->GetStatus() >= STATUS_IN_PROGRESS)
                    return bg->GetInProgressDuration() >= 15s;

        return false;
    }
};

void AddSC_arena_enigma_crucible()
{
    RegisterBattlegroundMapScript(arena_enigma_crucible, EnigmaCrucible::MapIds::EnigmaCrucible);
    RegisterSpellScript(spell_enigma_arena_reaction_trigger_low_health);
    RegisterSpellScript(spell_enigma_arena_reaction_trigger);
    RegisterSpellScript(spell_enigma_arena_warning_countdown);
    RegisterSpellScript(spell_enigma_arena_warning_teleport);

    new condition_enigma_arena_collision_doors();
}

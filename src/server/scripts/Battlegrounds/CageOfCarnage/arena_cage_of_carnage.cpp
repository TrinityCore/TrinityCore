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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"

namespace CageOfCarnage
{
    namespace Actions
    {
        static constexpr uint32 ReactionTrigger = 1;
        static constexpr uint32 ReactionDead = 2;
    }

    namespace Creatures
    {
        static constexpr uint32 NaminzeBoltfingers = 232750;
    }

    namespace GameObjects
    {
        static constexpr uint32 GoblinArenaTrapDoor01 = 505683;
    }

    namespace MapIds
    {
        static constexpr uint32 CageOfCarnage = 2759;
    }

    namespace Positions
    {
        static constexpr Position PurpleWarningTeleport = { 442.311f, 343.167f, -34.1166f, 1.7453293f };
        static constexpr Position GoldWarningTeleport = { 443.167f, 439.243f, -42.6562f, 4.5902157f };
    }

    namespace Spells
    {
        static constexpr uint32 UndermineArenaVOCooldownAura = 472905;
        static constexpr uint32 UndermineArenaVOCooldownAuraPlayerDeath = 472913;
        static constexpr uint32 UndermineArenaReactionTrigger = 472885;
        static constexpr uint32 ArenaLowHealthCooldownAura = 234031;
        static constexpr uint32 Warning = 1214676;
        static constexpr uint32 WarningTeleport = 371319;
        static constexpr uint32 ArenaStartingAreaMarker = 228212;
    }

    namespace Texts
    {
        namespace Naminze
        {
            static constexpr uint8 Prepare = 0;
            static constexpr uint8 Start = 1;
            static constexpr uint8 ReactionAlmostDead = 2;
            static constexpr uint8 ReactionKill = 3;
        }
    }
}

struct arena_cage_of_carnage : ArenaScript
{
    explicit arena_cage_of_carnage(BattlegroundMap* map) : ArenaScript(map) { }

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

        if (Creature const* creature = battlegroundMap->GetCreature(_naminzeGUID))
            creature->AI()->Talk(CageOfCarnage::Texts::Naminze::Start);

        _scheduler.Schedule(5s, [&](TaskContext context)
        {
            battlegroundMap->DoOnPlayers([&](Player* player)
            {
                if (!player->HasAura(CageOfCarnage::Spells::ArenaStartingAreaMarker))
                    return;

                if (player->HasAura(CageOfCarnage::Spells::Warning))
                    return;

                player->CastSpell(nullptr, CageOfCarnage::Spells::Warning, CastSpellExtraArgsInit{
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
            case CageOfCarnage::Actions::ReactionTrigger:
                HandleReactionLowHealth(Object::ToPlayer(source));
                break;
            case CageOfCarnage::Actions::ReactionDead:
                HandleKill(Object::ToPlayer(target));
                break;
            default:
                break;
        }
    }

    void OnPrepareStage2() override
    {
        if (Creature const* creature = battlegroundMap->GetCreature(_naminzeGUID))
            creature->AI()->Talk(CageOfCarnage::Texts::Naminze::Prepare);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case CageOfCarnage::Creatures::NaminzeBoltfingers:
                _naminzeGUID = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case CageOfCarnage::GameObjects::GoblinArenaTrapDoor01:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnPlayerJoined(Player* player, bool /*inBattleground*/) override
    {
        player->CastSpell(nullptr, CageOfCarnage::Spells::UndermineArenaReactionTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void HandleKill(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_naminzeGUID))
        {
            if (creature->HasAura(CageOfCarnage::Spells::UndermineArenaVOCooldownAuraPlayerDeath))
                return;

            creature->AI()->Talk(CageOfCarnage::Texts::Naminze::ReactionKill, victim);

            creature->CastSpell(nullptr, CageOfCarnage::Spells::UndermineArenaVOCooldownAuraPlayerDeath, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

    void HandleReactionLowHealth(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_naminzeGUID))
        {
            if (creature->HasAura(CageOfCarnage::Spells::UndermineArenaVOCooldownAura))
                return;

            creature->AI()->Talk(CageOfCarnage::Texts::Naminze::ReactionAlmostDead, victim);

            creature->CastSpell(nullptr, CageOfCarnage::Spells::UndermineArenaVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

private:
    GuidVector _doorGUIDs;
    ObjectGuid _naminzeGUID;

    TaskScheduler _scheduler;
};

// 472883 - Undermine Arena Reaction Trigger - Low Health
class spell_undermine_arena_reaction_trigger_low_health : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == CageOfCarnage::MapIds::CageOfCarnage;
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        if (target->HasAura(CageOfCarnage::Spells::ArenaLowHealthCooldownAura))
            return;

        target->CastSpell(nullptr, CageOfCarnage::Spells::ArenaLowHealthCooldownAura, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

        if (ZoneScript* zoneScript = target->FindZoneScript())
            zoneScript->DoAction(CageOfCarnage::Actions::ReactionTrigger, GetCaster(), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_undermine_arena_reaction_trigger_low_health::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 472885 - Undermine Arena Reaction Trigger
class spell_undermine_arena_reaction_trigger : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == CageOfCarnage::MapIds::CageOfCarnage;
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        if (ZoneScript* zonescript = GetTarget()->FindZoneScript())
            zonescript->DoAction(CageOfCarnage::Actions::ReactionDead, eventInfo.GetActor(), eventInfo.GetProcTarget());
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_undermine_arena_reaction_trigger::HandleProc);
    }
};

// 1214676 - Warning (countdown)
class spell_undermine_arena_warning_countdown : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == CageOfCarnage::MapIds::CageOfCarnage;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ CageOfCarnage::Spells::WarningTeleport });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Player* target= GetTarget()->ToPlayer();
        if (!target)
            return;

        if (!target->HasAura(CageOfCarnage::Spells::ArenaStartingAreaMarker))
            return;

        target->CastSpell(nullptr, CageOfCarnage::Spells::WarningTeleport, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_undermine_arena_warning_countdown::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 371319 - Warning Teleport
class spell_undermine_arena_warning_teleport : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == CageOfCarnage::MapIds::CageOfCarnage;
    }

    void HandleTeleport(SpellEffIndex /*effIndex*/) const
    {
        Player* target = GetHitPlayer();
        if (!target)
            return;

        if (target->GetBGTeam() == ALLIANCE)
            target->NearTeleportTo(CageOfCarnage::Positions::PurpleWarningTeleport);
        else
            target->NearTeleportTo(CageOfCarnage::Positions::GoldWarningTeleport);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_undermine_arena_warning_teleport::HandleTeleport, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_arena_cage_of_carnage()
{
    RegisterBattlegroundMapScript(arena_cage_of_carnage, CageOfCarnage::MapIds::CageOfCarnage);
    RegisterSpellScript(spell_undermine_arena_reaction_trigger_low_health);
    RegisterSpellScript(spell_undermine_arena_reaction_trigger);
    RegisterSpellScript(spell_undermine_arena_warning_countdown);
    RegisterSpellScript(spell_undermine_arena_warning_teleport);
}

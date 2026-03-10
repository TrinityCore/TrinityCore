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
#include "Conversation.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"

namespace HookPoint
{
    namespace Actions
    {
        static constexpr uint32 ReactionTrigger = 1;
        static constexpr uint32 ReactionDead = 2;
        static constexpr uint32 ReactionCheer = 3;
        static constexpr uint32 PennyMove = 4;
    }

    namespace BouncerPaths
    {
        static constexpr uint64 Path1 = 14324500;
        static constexpr uint64 Path2 = 14324501;
        static constexpr uint64 Path3 = 14324502;
        static constexpr uint64 Path4 = 14324503;
    }

    namespace Conversations
    {
        static constexpr uint32 Prepare = 9450;
    }

    namespace Creatures
    {
        static constexpr uint32 DanielPoole = 137530;
        static constexpr uint32 Bouncer = 143245;
        static constexpr uint32 Penny = 143121;
    }

    namespace GameObjects
    {
        static constexpr uint32 InvisWall = 296728;
        static constexpr uint32 SlideDoor = 297144;
    }

    namespace MapIds
    {
        static constexpr uint32 HookPoint = 1825;
    }

    namespace Spells
    {
        static constexpr uint32 KulTirasArenaVOCooldownAura = 275002;
        static constexpr uint32 ArenaReactionTrigger = 278776;
        static constexpr uint32 KulTirasArenaCrowdCheers = 278937;
        static constexpr uint32 ArenaLowHealthDyingTrigger = 279047;
        static constexpr uint32 KulTirasArenaCrowdBoos = 278926;
    }

    namespace StringIds
    {
        static constexpr std::string_view Bouncer1 = "hook_point_bouncer_1"sv;
        static constexpr std::string_view Bouncer2 = "hook_point_bouncer_2"sv;
        static constexpr std::string_view Bouncer3 = "hook_point_bouncer_3"sv;
        static constexpr std::string_view Bouncer4 = "hook_point_bouncer_4"sv;
    }

    namespace Texts
    {
        namespace DanielPoole
        {
            static constexpr uint8 Start = 0;
            static constexpr uint8 ReactionLowHealth = 1;
            static constexpr uint8 ReactionKill = 2;
        }
    }
}

struct arena_hook_point : ArenaScript
{
    explicit arena_hook_point(BattlegroundMap* map) : ArenaScript(map) { }

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

        if (Creature const* creature = battlegroundMap->GetCreature(_danielPooleGUID))
            creature->AI()->Talk(HookPoint::Texts::DanielPoole::Start);

        for (ObjectGuid const& guid : _bouncerGUIDs)
        {
            if (Creature* bouncer = battlegroundMap->GetCreature(guid))
            {
                bouncer->SetAIAnimKitId(0);
                if (bouncer->HasStringId(HookPoint::StringIds::Bouncer1))
                    bouncer->GetMotionMaster()->MovePath(HookPoint::BouncerPaths::Path1, false, {}, {}, MovementWalkRunSpeedSelectionMode::Default, {}, {}, {}, true, false);
                else if (bouncer->HasStringId(HookPoint::StringIds::Bouncer2))
                {
                    bouncer->m_Events.AddEventAtOffset([bouncer]()
                    {
                        bouncer->GetMotionMaster()->MovePath(HookPoint::BouncerPaths::Path2, false, {}, {}, MovementWalkRunSpeedSelectionMode::Default, {}, {}, {}, true, false);
                    }, 500ms);
                }
                else if (bouncer->HasStringId(HookPoint::StringIds::Bouncer3))
                    bouncer->GetMotionMaster()->MovePath(HookPoint::BouncerPaths::Path3, false, {}, {}, MovementWalkRunSpeedSelectionMode::Default, {}, {}, {}, true, false);
                else if (bouncer->HasStringId(HookPoint::StringIds::Bouncer4))
                {
                    bouncer->m_Events.AddEventAtOffset([bouncer]()
                    {
                        bouncer->GetMotionMaster()->MovePath(HookPoint::BouncerPaths::Path4, false, {}, {}, MovementWalkRunSpeedSelectionMode::Default, {}, {}, {}, true, false);
                    }, 500ms);
                }
            }
        }

        if (Creature* creature = battlegroundMap->GetCreature(_pennyGUID))
        {
            creature->SetAIAnimKitId(0);
            creature->AI()->DoAction(HookPoint::Actions::PennyMove);
        }
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnPrepareStage1() override
    {
        _scheduler.Schedule(20s, [&](TaskContext)
        {
            if (GameObject* slideDoor = battlegroundMap->GetGameObject(_slideDoorGUID))
                slideDoor->UseDoorOrButton();

            if (Creature* creature = battlegroundMap->GetCreature(_danielPooleGUID))
                Conversation::CreateConversation(HookPoint::Conversations::Prepare, creature, creature->GetPosition(), ObjectGuid::Empty);
        });
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        switch (actionId)
        {
            case HookPoint::Actions::ReactionTrigger:
                HandleReactionLowHealth(Object::ToPlayer(source));
                break;
            case HookPoint::Actions::ReactionCheer:
                HandleReactionCheer(Object::ToPlayer(source));
                break;
            case HookPoint::Actions::ReactionDead:
                HandleKill(Object::ToPlayer(target));
                break;
            default:
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case HookPoint::Creatures::DanielPoole:
                _danielPooleGUID = creature->GetGUID();
                break;
            case HookPoint::Creatures::Bouncer:
                _bouncerGUIDs.emplace_back(creature->GetGUID());
                break;
            case HookPoint::Creatures::Penny:
                _pennyGUID = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case HookPoint::GameObjects::InvisWall:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            case HookPoint::GameObjects::SlideDoor:
                _slideDoorGUID = gameobject->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnPlayerJoined(Player* player, bool /*inBattleground*/) override
    {
        player->CastSpell(nullptr, HookPoint::Spells::ArenaReactionTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void HandleKill(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_danielPooleGUID))
        {
            if (creature->HasAura(HookPoint::Spells::KulTirasArenaVOCooldownAura))
                return;

            creature->AI()->Talk(HookPoint::Texts::DanielPoole::ReactionKill, victim);

            creature->CastSpell(nullptr, HookPoint::Spells::KulTirasArenaVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

    void HandleReactionCheer(Player const* victim) const
    {
        if (!victim)
            return;

        Team const otherTeam = GetOtherTeam(victim->GetBGTeam());

        battlegroundMap->DoOnPlayers([&](Player* player)
        {
            if (player->GetBGTeam() == otherTeam)
            {
                player->CastSpell(nullptr, HookPoint::Spells::KulTirasArenaCrowdCheers, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                });
            }
        });
    }

    void HandleReactionLowHealth(Player const* victim) const
    {
        if (!victim)
            return;

        Team const victimTeam = victim->GetBGTeam();
        battlegroundMap->DoOnPlayers([&](Player* player)
        {
            if (player->GetBGTeam() == victimTeam)
            {
                player->CastSpell(nullptr, HookPoint::Spells::KulTirasArenaCrowdBoos, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                });
            }
        });

        if (Creature* creature = battlegroundMap->GetCreature(_danielPooleGUID))
        {
            if (creature->HasAura(HookPoint::Spells::KulTirasArenaVOCooldownAura))
                return;

            creature->AI()->Talk(HookPoint::Texts::DanielPoole::ReactionLowHealth, victim);

            creature->CastSpell(nullptr, HookPoint::Spells::KulTirasArenaVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

private:
    GuidVector _doorGUIDs;
    GuidVector _bouncerGUIDs;
    ObjectGuid _slideDoorGUID;
    ObjectGuid _danielPooleGUID;
    ObjectGuid _pennyGUID;

    TaskScheduler _scheduler;
};

// 278775 - Arena Reaction Trigger - Low Health
class spell_arena_reaction_trigger_low_health : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == HookPoint::MapIds::HookPoint;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ HookPoint::Spells::ArenaLowHealthDyingTrigger });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        target->CastSpell(nullptr, HookPoint::Spells::ArenaLowHealthDyingTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

        if (ZoneScript* zoneScript = target->FindZoneScript())
            zoneScript->DoAction(HookPoint::Actions::ReactionCheer, GetCaster(), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arena_reaction_trigger_low_health::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 278776 - Arena Reaction Trigger
class spell_arena_reaction_trigger : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == HookPoint::MapIds::HookPoint;
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        if (ZoneScript* zonescript = GetTarget()->FindZoneScript())
            zonescript->DoAction(HookPoint::Actions::ReactionDead, eventInfo.GetActor(), eventInfo.GetProcTarget());
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_arena_reaction_trigger::HandleProc);
    }
};

// 279047 - Arena Low Health Dying Trigger
class spell_arena_low_health_dying_trigger : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == HookPoint::MapIds::HookPoint;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({HookPoint::Spells::ArenaLowHealthDyingTrigger });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();

        if (ZoneScript* zoneScript = target->FindZoneScript())
            zoneScript->DoAction(HookPoint::Actions::ReactionTrigger, GetCaster(), target);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_arena_low_health_dying_trigger::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_arena_hook_point()
{
    RegisterBattlegroundMapScript(arena_hook_point, HookPoint::MapIds::HookPoint);
    RegisterSpellScript(spell_arena_reaction_trigger_low_health);
    RegisterSpellScript(spell_arena_reaction_trigger);
    RegisterSpellScript(spell_arena_low_health_dying_trigger);
}

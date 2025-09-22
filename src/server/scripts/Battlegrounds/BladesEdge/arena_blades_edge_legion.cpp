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
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"

namespace BladesEdge
{
    namespace Actions
    {
        static constexpr uint32 ArenaStart = 1;
        static constexpr uint32 ReactionTrigger = 2;
        static constexpr uint32 MaulgarReactionGenderedM = 3;
        static constexpr uint32 MaulgarReactionGenderedF = 4;
        static constexpr uint32 MaulgarReactionNonGendered = 5;
        static constexpr uint32 MaulgarReactionBored = 6;
    }

    namespace Creatures
    {
        static constexpr uint32 HighKingMaulgar = 115494;
    }

    namespace GameObjects
    {
        static constexpr uint32 Door01 = 265571;
        static constexpr uint32 Door02 = 265569;
    }

    namespace MapIds
    {
        static constexpr uint32 BladesEdge = 1672;
    }

    namespace Spells
    {
        static constexpr uint32 KingVoiceOverCooldownAura = 236744;
        static constexpr uint32 ArenaLowHealthCooldownAura = 234031;
        static constexpr uint32 ArenaReactionTrigger = 234032;
    }

    namespace Texts
    {
        namespace HighKingMaulgar
        {
            static constexpr uint8 Bored = 0;
            static constexpr uint8 ReactionTriggerGenderedM = 1;
            static constexpr uint8 ReactionTriggerGenderedF = 2;
            static constexpr uint8 ReactionTriggerNonGendered = 3;
            static constexpr uint8 ArenaStart = 4;
        }
    }
}

struct arena_blades_edge_legion : ArenaScript
{
    explicit arena_blades_edge_legion(BattlegroundMap* map) : ArenaScript(map), _scheduleBored(true) { }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* /*target*/) override
    {
        switch (actionId)
        {
            case BladesEdge::Actions::ReactionTrigger:
                HandleReactionTriggerLowHealth(Object::ToPlayer(source));
                break;
            default:
                break;
        }
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

        if (Creature const* maulgar = battlegroundMap->GetCreature(_maulgarGUID))
            maulgar->AI()->DoAction(BladesEdge::Actions::ArenaStart);

        _scheduler.Schedule(5s, [&](TaskContext context)
        {
            if (_scheduleBored)
                context.Repeat(1min, 2min);
        });
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case BladesEdge::Creatures::HighKingMaulgar:
                _maulgarGUID = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case BladesEdge::GameObjects::Door01:
            case BladesEdge::GameObjects::Door02:
                _doorGUIDs.push_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnPlayerJoined(Player* player, bool /*inBattleground*/) override
    {
        player->CastSpell(nullptr, BladesEdge::Spells::ArenaReactionTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void HandleReactionTriggerLowHealth(Player const* source)
    {
        if (Creature const* maulgar = battlegroundMap->GetCreature(_maulgarGUID))
        {
            if (urand(0, 1))
                maulgar->AI()->DoAction(BladesEdge::Actions::MaulgarReactionNonGendered);
            else if (source)
            {
                if (source->GetGender() == GENDER_FEMALE)
                    maulgar->AI()->DoAction(BladesEdge::Actions::MaulgarReactionGenderedF);
                else
                    maulgar->AI()->DoAction(BladesEdge::Actions::MaulgarReactionGenderedM);
            }
        }

        _scheduleBored = false;
    }

private:
    TaskScheduler _scheduler;
    GuidVector _doorGUIDs;
    ObjectGuid _maulgarGUID;
    bool _scheduleBored;
};

// 115494 - High King Maulgar
class npc_blades_edge_high_king_maulgar : public ScriptedAI
{
public:
    explicit npc_blades_edge_high_king_maulgar(Creature* creature) : ScriptedAI(creature) {}

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case BladesEdge::Actions::ArenaStart:
                ProcessTalk(BladesEdge::Texts::HighKingMaulgar::ArenaStart);
                break;
            case BladesEdge::Actions::MaulgarReactionNonGendered:
                ProcessTalk(BladesEdge::Texts::HighKingMaulgar::ReactionTriggerNonGendered);
                break;
            case BladesEdge::Actions::MaulgarReactionGenderedM:
                ProcessTalk(BladesEdge::Texts::HighKingMaulgar::ReactionTriggerGenderedM);
                break;
            case BladesEdge::Actions::MaulgarReactionGenderedF:
                ProcessTalk(BladesEdge::Texts::HighKingMaulgar::ReactionTriggerGenderedF);
                break;
            case BladesEdge::Actions::MaulgarReactionBored:
                ProcessTalk(BladesEdge::Texts::HighKingMaulgar::Bored);
                break;
            default:
                break;
        }
    }

    void ProcessTalk(uint8 id)
    {
        Talk(id);
        DoCastAOE(BladesEdge::Spells::KingVoiceOverCooldownAura);
    }
};

// 234033 - Blade's Edge Arena Game Event
class spell_blades_edge_arena_game_event : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == BladesEdge::MapIds::BladesEdge;
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        if (target->HasAura(BladesEdge::Spells::ArenaLowHealthCooldownAura))
            return;

        target->CastSpell(nullptr, BladesEdge::Spells::ArenaLowHealthCooldownAura, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

        if (ZoneScript* zoneScript = target->FindZoneScript())
            zoneScript->DoAction(BladesEdge::Actions::ReactionTrigger, GetCaster(), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_blades_edge_arena_game_event::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_arena_blades_edge_legion()
{
    RegisterBattlegroundMapScript(arena_blades_edge_legion, BladesEdge::MapIds::BladesEdge);
    RegisterSpellScript(spell_blades_edge_arena_game_event);
    RegisterCreatureAI(npc_blades_edge_high_king_maulgar);
}

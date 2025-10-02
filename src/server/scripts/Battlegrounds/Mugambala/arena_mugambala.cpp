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

namespace Mugambala
{
    namespace Actions
    {
        static constexpr uint32 ReactionTrigger = 1;
        static constexpr uint32 ReactionDead = 2;
    }

    namespace Creatures
    {
        static constexpr uint32 JestryTheUntamed = 141962;
    }

    namespace GameObjects
    {
        static constexpr uint32 Door01 = 298780;
        static constexpr uint32 Door02 = 298781;
    }

    namespace MapIds
    {
        static constexpr uint32 Mugambala = 1911;
    }

    namespace Spells
    {
        static constexpr uint32 ArenaLowHealthCooldownAura = 234031;
        static constexpr uint32 ZandalarArenaVOCooldownAura = 278700;
        static constexpr uint32 ZandalarArenaReactionTrigger = 278771;
    }

    namespace Texts
    {
        namespace Jestry
        {
            static constexpr uint8 Prepare = 0;
            static constexpr uint8 Start = 1;
            static constexpr uint8 ReactionNonGendered = 2;
            static constexpr uint8 ReactionGenderF = 3;
            static constexpr uint8 ReactionGenderM = 4;
            static constexpr uint8 ReactionKill = 5;
        }
    }
}

struct arena_mugambala : ArenaScript
{
    explicit arena_mugambala(BattlegroundMap* map) : ArenaScript(map) { }

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

        if (Creature const* creature = battlegroundMap->GetCreature(_jestryGUID))
            creature->AI()->Talk(Mugambala::Texts::Jestry::Start);
    }

    void DoAction(uint32 actionId, WorldObject* source, WorldObject* target) override
    {
        switch (actionId)
        {
            case Mugambala::Actions::ReactionTrigger:
                HandleReactionLowHealth(Object::ToPlayer(source));
                break;
            case Mugambala::Actions::ReactionDead:
                HandleKill(Object::ToPlayer(target));
                break;
            default:
                break;
        }
    }

    void OnPrepareStage2() override
    {
        if (Creature const* creature = battlegroundMap->GetCreature(_jestryGUID))
            creature->AI()->Talk(Mugambala::Texts::Jestry::Prepare);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case Mugambala::Creatures::JestryTheUntamed:
                _jestryGUID = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case Mugambala::GameObjects::Door01:
            case Mugambala::GameObjects::Door02:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnPlayerJoined(Player* player, bool /*inBattleground*/) override
    {
        player->CastSpell(nullptr, Mugambala::Spells::ZandalarArenaReactionTrigger, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void HandleKill(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_jestryGUID))
        {
            if (creature->HasAura(Mugambala::Spells::ZandalarArenaVOCooldownAura))
                return;

            creature->AI()->Talk(Mugambala::Texts::Jestry::ReactionKill, victim);

            creature->CastSpell(nullptr, Mugambala::Spells::ZandalarArenaVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

    void HandleReactionLowHealth(Player const* victim) const
    {
        if (!victim)
            return;

        if (Creature* creature = battlegroundMap->GetCreature(_jestryGUID))
        {
            if (creature->HasAura(Mugambala::Spells::ZandalarArenaVOCooldownAura))
                return;

            if (urand(0, 1))
                creature->AI()->Talk(Mugambala::Texts::Jestry::ReactionNonGendered, victim);
            else if (victim->GetGender() == GENDER_FEMALE)
                creature->AI()->Talk(Mugambala::Texts::Jestry::ReactionGenderF, victim);
            else
                creature->AI()->Talk(Mugambala::Texts::Jestry::ReactionGenderM, victim);

            creature->CastSpell(nullptr, Mugambala::Spells::ZandalarArenaVOCooldownAura, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
        }
    }

private:
    GuidVector _doorGUIDs;
    ObjectGuid _jestryGUID;
};

// 278770 - Zandalar Arena Reaction Trigger - Low Health
class spell_zandalar_arena_reaction_trigger_low_health : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetMapId() == Mugambala::MapIds::Mugambala;
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        if (target->HasAura(Mugambala::Spells::ArenaLowHealthCooldownAura))
            return;

        target->CastSpell(nullptr, Mugambala::Spells::ArenaLowHealthCooldownAura, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });

        if (ZoneScript* zoneScript = target->FindZoneScript())
            zoneScript->DoAction(Mugambala::Actions::ReactionTrigger, GetCaster(), target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_zandalar_arena_reaction_trigger_low_health::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 278771 - Zandalar Arena Reaction Trigger
class spell_zandalar_arena_reaction_trigger : public AuraScript
{
    bool Load() override
    {
        return GetOwner()->GetMapId() == Mugambala::MapIds::Mugambala;
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        if (ZoneScript* zonescript = GetTarget()->FindZoneScript())
            zonescript->DoAction(Mugambala::Actions::ReactionDead, eventInfo.GetActor(), eventInfo.GetProcTarget());
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_zandalar_arena_reaction_trigger::HandleProc);
    }
};

void AddSC_arena_mugambala()
{
    RegisterBattlegroundMapScript(arena_mugambala, Mugambala::MapIds::Mugambala);
    RegisterSpellScript(spell_zandalar_arena_reaction_trigger_low_health);
    RegisterSpellScript(spell_zandalar_arena_reaction_trigger);
}

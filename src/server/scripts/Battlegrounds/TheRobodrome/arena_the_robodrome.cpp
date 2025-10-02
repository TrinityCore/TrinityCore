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

namespace TheRobodrome
{
    namespace MapIds
    {
        static constexpr uint32 TheRobodrome = 2167;
    }

    namespace Creatures
    {
        static constexpr uint32 PowerCoil = 154593;
    }

    namespace GameObjects
    {
        static constexpr uint32 Door01 = 329742;
        static constexpr uint32 Door02 = 329743;
    }

    namespace Spells
    {
        static constexpr uint32 Zap = 300642;
    }
}

struct arena_the_robodrome : ArenaScript
{
    explicit arena_the_robodrome(BattlegroundMap* map) : ArenaScript(map) { }

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

        _scheduler.Schedule(5s, [&](TaskContext context)
        {
            for (ObjectGuid const& guid : _powerCoilGUIDs)
                if (Creature* coil = battlegroundMap->GetCreature(guid))
                    coil->CastSpell(nullptr, TheRobodrome::Spells::Zap);

            context.Repeat();
        });
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case TheRobodrome::GameObjects::Door01:
            case TheRobodrome::GameObjects::Door02:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case TheRobodrome::Creatures::PowerCoil:
                _powerCoilGUIDs.emplace_back(creature->GetGUID());
                break;
            default:
                break;
        }
    }

private:
    GuidVector _doorGUIDs;
    GuidVector _powerCoilGUIDs;

    TaskScheduler _scheduler;
};

// 300642 - Zap (Damage mod)
class spell_the_robodrome_zap_damage : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        uint32 basePct = 16;
        uint32 stackCount = GetHitUnit()->GetAuraCount(TheRobodrome::Spells::Zap);

        SetEffectValue(basePct + basePct * stackCount);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_robodrome_zap_damage::HandleHitTarget, EFFECT_2, SPELL_EFFECT_DAMAGE_FROM_MAX_HEALTH_PCT);
    }
};

void AddSC_arena_the_robodrome()
{
    RegisterBattlegroundMapScript(arena_the_robodrome, TheRobodrome::MapIds::TheRobodrome);
    RegisterSpellScript(spell_the_robodrome_zap_damage);
}

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

#include "ScriptMgr.h"
#include "Creature.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

namespace Scripts::EasternKingdoms::AbyssalDepths
{
namespace Spells
{
    static constexpr uint32 SummonVashjirWhirlpoolVehicleTrigger = 82905;
    static constexpr uint32 RideVehicleHardcoded                 = 46598;
    static constexpr uint32 TeleportUnderWhirlpool               = 82903;
}

namespace Creatures
{
    static constexpr uint32 WorldTrigger = 22515;
}

namespace Paths
{
    static constexpr uint32 PathUnderWhirlpool = 4437300;
}

// 6200 - Abyssal Depths Whirlpool Entrance
class at_abyssal_depths_whirlpool_entrance : public AreaTriggerScript
{
public:
    at_abyssal_depths_whirlpool_entrance() : AreaTriggerScript("at_abyssal_depths_whirlpool_entrance") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        // cast from nearby worldtrigger
        if (Creature* worldTrigger = player->FindNearestCreature(Creatures::WorldTrigger, 100.0f))
            worldTrigger->CastSpell(player, Spells::SummonVashjirWhirlpoolVehicleTrigger);

        return true;
    }
};

// 44373 - Whirlpool Vehicle
struct npc_abyssal_depths_whirlpool_vehicle : public ScriptedAI
{
    explicit npc_abyssal_depths_whirlpool_vehicle(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (Unit* owner = me->GetOwner())
        {
            owner->CastSpell(me, Spells::RideVehicleHardcoded);

            _scheduler.Schedule(3s + 500ms, [this](TaskContext /*task*/)
            {
                me->SetAIAnimKitId(822);
                me->CastSpell(nullptr, Spells::TeleportUnderWhirlpool, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_SET_FACING
                });
                me->GetMotionMaster()->MovePath(Paths::PathUnderWhirlpool, false);
            });
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::TeleportUnderWhirlpool)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

}

void AddSC_abyssal_depths()
{
    using namespace Scripts::EasternKingdoms::AbyssalDepths;

    new at_abyssal_depths_whirlpool_entrance();

    RegisterCreatureAI(npc_abyssal_depths_whirlpool_vehicle);
}

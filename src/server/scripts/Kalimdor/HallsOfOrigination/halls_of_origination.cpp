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
#include "CreatureGroups.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "halls_of_origination.h"

// The Maker's Lift
enum ElevatorMisc
{
    GOSSIP_MENU_HOO_LIFT                    = 12646,
    GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION    = 17791,
    GOSSIP_OPTION_FIRST_FLOOR               = 0,
    GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR     = 1,
    GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR      = 2
};

// 207669 - The Maker's Lift Controller
struct go_hoo_the_makers_lift_controller : public GameObjectAI
{
    go_hoo_the_makers_lift_controller(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return false;

        // Build menu.
        // First floor: Option available from start.
        AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_FIRST_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);

        // Second floor: Anraphet must be defeated first.
        if (instance->GetBossState(DATA_ANRAPHET) == DONE || instance->GetBossState(DATA_EARTHRAGER_PTAH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_SECOND_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        // Third floor: Constructs of The Four Seats must be defeated first.
        if (instance->GetBossState(DATA_ISISET) == DONE && instance->GetBossState(DATA_AMMUNAE) == DONE &&
            instance->GetBossState(DATA_SETESH) == DONE && instance->GetBossState(DATA_RAJH) == DONE)
            AddGossipItemFor(player, GOSSIP_MENU_HOO_LIFT, GOSSIP_OPTION_HOO_LIFT_THIRD_FLOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, GOSSIP_NPC_TEXT_CHOOSE_A_DESTINATION, me->GetGUID());
        return true;
    }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        player->PlayerTalkClass->SendCloseGossip();

        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return true;

        // Handle elevator: gossip item index => stopFrame (floor index).
        Transport* elevator = ObjectAccessor::GetTransportOnMap(*me, instance->GetGuidData(DATA_LIFT_OF_THE_MAKERS));
        if (!elevator)
            return true;

        if (action == 0 && elevator->GetGoState() >= GO_STATE_TRANSPORT_ACTIVE + 2)
            elevator->SetTransportState(GO_STATE_TRANSPORT_ACTIVE);
        else
            elevator->SetTransportState(GO_STATE_TRANSPORT_STOPPED, action);

        return true;
    }
};

class spell_hoo_flame_ring_visual : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* target)->bool
            {
                Unit const* unit = target->ToUnit();
                return !unit || unit->GetEntry() != NPC_SUN_TOUCHED_SERVANT;
            });

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_hoo_flame_ring_visual::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget.Register(&spell_hoo_flame_ring_visual::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_halls_of_origination()
{
    RegisterGameObjectAI(go_hoo_the_makers_lift_controller);
    RegisterSpellScript(spell_hoo_flame_ring_visual);
}

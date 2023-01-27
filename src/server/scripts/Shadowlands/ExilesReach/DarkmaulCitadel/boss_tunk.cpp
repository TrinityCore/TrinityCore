/*
 * Copyright 2021 ShadowCore
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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "darkmaul_citadel.h"

//157300
struct boss_tunk : public BossAI
{
    boss_tunk(Creature* creature) : BossAI(creature, DATA_TUNK) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        if (auto* tunkDoor = me->FindNearestGameObject(GO_TUNK_EXIT, 100.0f))
            tunkDoor->SetGoState(GO_STATE_READY);
        if (auto* tunkEntrance = me->FindNearestGameObject(GO_TUNK_ENTRANCE, 100.0f))
            tunkEntrance->SetGoState(GO_STATE_READY);
        events.ScheduleEvent(SPELL_SEISMIC_SLAM, 5s);
        events.ScheduleEvent(SPELL_INTERRUPTING_SHOUT, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_SEISMIC_SLAM:
            DoCastVictim(SPELL_SEISMIC_SLAM, false);
            events.Repeat(20s);
            break;

        case SPELL_INTERRUPTING_SHOUT:
            DoCastAOE(SPELL_INTERRUPTING_SHOUT, false);
            events.Repeat(25s);
            break;
        }
    }

    void JustReachedHome() override
    {
        me->RemoveAllAreaTriggers();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        Talk(1);
        me->RemoveAllAreaTriggers();
        if (auto* tunkToor = me->FindNearestGameObject(GO_TUNK_EXIT, 100.0f))
            tunkToor->SetGoState(GO_STATE_ACTIVE);
        if (auto* tunkEntrance = me->FindNearestGameObject(GO_TUNK_ENTRANCE, 100.0f))
            tunkEntrance->SetGoState(GO_STATE_ACTIVE);
        std::list<Player*> playerList;
        me->GetPlayerListInGrid(playerList, 100.0f);
        for (auto& players : playerList)
        {
           // me->SetLootRecipient(players);
        }
    }
};

//22171
struct at_seismic_slam : public AreaTriggerAI
{
    at_seismic_slam(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        at->GetCaster()->CastSpell(unit->GetPosition(), SPELL_SEISMIC_SLAM_DAMAGE_KNOCK, true);
    }
};

void AddSC_boss_tunk()
{
    RegisterCreatureAI(boss_tunk);
    RegisterAreaTriggerAI(at_seismic_slam);
}

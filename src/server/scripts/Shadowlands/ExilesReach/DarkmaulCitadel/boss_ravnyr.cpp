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

//156501
struct boss_ravnyr : public BossAI
{
    boss_ravnyr(Creature* creature) : BossAI(creature, DATA_RAVNYR) { }

    void Reset() override
    {
        BossAI::Reset();
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        me->AddUnitFlag2(UnitFlags2(UNIT_FLAG2_FEIGN_DEATH | UNIT_FLAG_NOT_SELECTABLE));
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 100);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        events.ScheduleEvent(SPELL_NECROTIC_BREATH, 3s);
        events.ScheduleEvent(SPELL_WING_BUFFET, 8s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_AWAKEN:
            AddTimedDelayedOperation(6000, [this]() -> void
            {
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                me->RemoveUnitFlag2(UnitFlags2(UNIT_FLAG2_FEIGN_DEATH | UNIT_FLAG_NOT_SELECTABLE));
                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            });
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_NECROTIC_BREATH:
            DoCastVictim(SPELL_NECROTIC_BREATH, false);
            events.Repeat(25s);
            break;

        case SPELL_WING_BUFFET:
            DoCastAOE(SPELL_WING_BUFFET, false);
            events.Repeat(20s);
            break;
        }
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        if (auto* tunkToor = me->FindNearestGameObject(GO_RAVNYR_EXIT, 100.0f))
            tunkToor->SetGoState(GO_STATE_ACTIVE);

        std::list<Player*> playerList;
        me->GetPlayerListInGrid(playerList, 100.0f);
        for (auto& players : playerList)
        {
            players->ForceCompleteQuest(55992);
            //me->SetLootRecipient(players);
        }
    }
};

void AddSC_boss_ravnyr()
{
    RegisterCreatureAI(boss_ravnyr);
}

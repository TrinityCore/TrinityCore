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

//156814
struct boss_gorgroth : public BossAI
{
    boss_gorgroth(Creature* creature) : BossAI(creature, DATA_GORGROTH) 
    {         
        me->SetPowerType(POWER_MANA);
        me->SetMaxPower(POWER_MANA, 191);
        me->SetPower(POWER_MANA, 191);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        me->SetReactState(REACT_PASSIVE);
        std::list<Creature*> decayCorpseList;
        me->GetCreatureListWithEntryInGrid(decayCorpseList, NPC_DECAYING_CORPSE, 25.0f);
        for (uint8 i = 0; i < 5; i++)
        {
            me->SummonCreature(NPC_DECAYING_CORPSE, me->GetRandomNearPosition(10.0f), TEMPSUMMON_MANUAL_DESPAWN);
        }
        this->decayingCorpse = 0;
        sacrifice = false;
       // me->setRegeneratingHealth(false); // This is not supposed to be there
        //There is a bug when npc A is trying to get in combat with npc B, but instead of it, they will both reset until they're in small range
    }

private:
    uint8 decayingCorpse;
    bool sacrifice;

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        if (auto* tunkToor = me->FindNearestGameObject(GO_RAVNYR_EXIT, 100.0f))
            tunkToor->SetGoState(GO_STATE_READY);

        //events.ScheduleEvent(SPELL_SHADOWBOLT, 3s);
        events.ScheduleEvent(SPELL_UNSTABLE_SHADOWS_MISSILE, 10s);
        me->SetInCombatWithZone();
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_DECAYING_CORPSE)
            decayingCorpse++;

        if (this->decayingCorpse = 5)
        {
            me->RemoveAura(306097);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE));           
            me->SetReactState(REACT_DEFENSIVE);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            /*case SPELL_SHADOWBOLT:
                events.Repeat(3s, 4s);
                break;*/

            case SPELL_UNSTABLE_SHADOWS_MISSILE:
                for (uint8 i = 0; i < 3; i++)
                {
                    me->CastSpell(me->GetRandomNearPosition(35.0f), SPELL_UNSTABLE_SHADOWS_MISSILE, true);
                }
                events.Repeat(20s);
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPct(50) && !sacrifice)
        {
            sacrifice = true;
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MovePoint(1, 837.639f, -1785.040f, 248.593f);
            me->GetScheduler().Schedule(3s, [this](TaskContext context)
            {
                me->KillSelf();
                if (auto* ravanyr = me->FindNearestCreature(NPC_RAVNYR, 100.0f, true))
                {
                    ravanyr->CastSpell(nullptr, SPELL_AWAKEN, true);
                    ravanyr->AI()->DoAction(ACTION_AWAKEN);
                }
            });
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
            Talk(1);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        BossAI::Reset();
        this->decayingCorpse = 0;
        if (auto* ravnyrExit = me->FindNearestGameObject(GO_RAVNYR_EXIT, 100.0f))
            ravnyrExit->SetGoState(GO_STATE_ACTIVE);
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        me->GetScheduler().Schedule(3s, [this](TaskContext context)
        {
            if (auto* ravanyr = me->FindNearestCreature(NPC_RAVNYR, 100.0f, true))
            {
                ravanyr->CastSpell(nullptr, SPELL_AWAKEN, true);
                ravanyr->AI()->DoAction(ACTION_AWAKEN);
            }
        });
    }
};

void AddSC_boss_gorgroth()
{
    RegisterCreatureAI(boss_gorgroth);
}

/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "darkheart_thicket.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Spells
{
    //Breath of Corruption
    SPELL_BOC_TARGET        = 191325, //Targets a tank
    SPELL_BOC_DAMAGE        = 191326, //Ticks every second for 3 seconds

    //Down Draft
    SPELL_DD_TARGET         = 199345,
    SPELL_DD_AT             = 199348,
    SPELL_DD_DOT            = 220855,
    SPELL_DD_CHARGE         = 199351,

    //Earthshaking Roar
    //                        199385 ?
    SPELL_ER_TARGET         = 199389,
    SPELL_ER_DAMAGE         = 218587,

    //Falling Rocks
    SPELL_FR_TRIGGERMISSILE = 141461,
    SPELL_FR_MISSILE        = 141463,
    SPELL_FR_AT             = 163897,
    SPELL_FR_DOT            = 163900,
    SPELL_FR_AT_1           = 199458,

    SPELL_DISTURB_EGG       = 199313
};

enum Events
{
    EVENT_BOC = 1,
    EVENT_DD  = 2,
    EVENT_ER  = 3
};

enum
{
    CREATURE_GROUP_EGGS = 0
};

struct boss_dresaron : public BossAI
{
    boss_dresaron(Creature* creature) : BossAI(creature, DATA_DRESARON) { }

    void Reset() override
    {
        _Reset();
        events.ScheduleEvent(EVENT_BOC, urand(15000, 20000));
        events.ScheduleEvent(EVENT_ER, 21000);
        events.ScheduleEvent(EVENT_DD, urand(38000, 42000));

        // Respawn eggs
        me->SummonCreatureGroup(CREATURE_GROUP_EGGS);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        instance->SetBossState(DATA_DRESARON, FAIL);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->setActive(true);
        DoZoneInCombat();
        events.Reset();
        events.ScheduleEvent(EVENT_BOC, urand(15000, 20000));
        events.ScheduleEvent(EVENT_ER, 21000);
        events.ScheduleEvent(EVENT_DD, urand(38000, 42000));
        instance->SetBossState(DATA_DRESARON, IN_PROGRESS);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SetBossState(DATA_DRESARON, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BOC:
                {
                    events.ScheduleEvent(EVENT_BOC, urand(15000, 20000));
                    DoCastVictim(SPELL_BOC_TARGET);
                    break;
                }
                case EVENT_ER:
                {
                    events.ScheduleEvent(EVENT_ER, 21000);
                    DoCastAOE(SPELL_ER_TARGET);
                    break;
                }
                case EVENT_DD:
                {
                    events.ScheduleEvent(EVENT_DD, urand(38000, 42000));
                    me->CastSpell(me, SPELL_DD_TARGET, false);
                }
            }
        }

        DoMeleeAttackIfReady();
    }
};

//AT ; 6084
//Spell : 199345 - Effect 1
struct at_dresaron_down_draft : AreaTriggerAI
{
    at_dresaron_down_draft(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() && at->GetCaster())
        {
            unit->CastSpell(unit, SPELL_DD_DOT, true);
            unit->ToPlayer()->ApplyMovementForce(at->GetGUID(), -8.0f, at->GetPosition());
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->HasAura(SPELL_DD_DOT))
            unit->RemoveAura(SPELL_DD_DOT);

        if (unit->IsPlayer())
            unit->ToPlayer()->RemoveMovementForce(at->GetGUID());
    }
};

// 101072
class npc_dresaron_corrupted_dragon_egg : public ScriptedAI
{
public:
    npc_dresaron_corrupted_dragon_egg(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
        SetCanSeeEvenInPassiveMode(true);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->GetDistance(who) <= 1.0f)
        {
            me->CastSpell(who, SPELL_DISTURB_EGG, true);
            me->KillSelf();
        }
    }
};

void AddSC_boss_dresaron()
{
    RegisterCreatureAI(boss_dresaron);
    RegisterCreatureAI(npc_dresaron_corrupted_dragon_egg);

    RegisterAreaTriggerAI(at_dresaron_down_draft);
}

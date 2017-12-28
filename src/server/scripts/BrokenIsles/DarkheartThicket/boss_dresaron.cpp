/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
};

enum Events
{
    EVENT_BOC = 1,
    EVENT_DD  = 2,
    EVENT_ER  = 3
};

class boss_dresaron : public CreatureScript
{
public:
    boss_dresaron() : CreatureScript("boss_dresaron") { }

    struct boss_dresaronAI : public BossAI
    {
        boss_dresaronAI(Creature* creature) : BossAI(creature, DATA_DRESARON) { }

        void Reset() override
        {
            _Reset();
            events.ScheduleEvent(EVENT_BOC, urand(15000, 20000));
            events.ScheduleEvent(EVENT_ER, 21000);
            events.ScheduleEvent(EVENT_DD, urand(38000, 42000));
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_dresaronAI(creature);
    }
};

//AT ; 6084
//Spell : 199345 - Effect 1
class at_dresaron_down_draft : public AreaTriggerEntityScript
{
public:
    at_dresaron_down_draft() : AreaTriggerEntityScript("at_dresaron_down_draft") { }

    struct at_dresaron_down_draftAI : AreaTriggerAI
    {
        at_dresaron_down_draftAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                        unit->CastSpell(unit, SPELL_DD_DOT, true);
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit->GetTypeId() == TYPEID_PLAYER)
                unit->CastSpell(unit, SPELL_DD_DOT, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->HasAura(SPELL_DD_DOT))
                unit->RemoveAura(SPELL_DD_DOT);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->HasAura(SPELL_DD_DOT))
                        unit->RemoveAura(SPELL_DD_DOT);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_dresaron_down_draftAI(areatrigger);
    }
};


void AddSC_boss_dresaron()
{
    new at_dresaron_down_draft();

    new boss_dresaron();
}

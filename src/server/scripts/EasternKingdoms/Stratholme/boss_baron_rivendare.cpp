/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Baron_Rivendare
SD%Complete: 70
SDComment: aura applied/defined in database
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Says
{
    SAY_BARON_RUN_START         = 0,
    SAY_BARON_RUN_BOSS_KILL     = 1,
    SAY_BARON_RUN_FAIL          = 2,
    SAY_EVENT_RAMSTEIN          = 3,
    SAY_EVENT_BARON             = 4
};

enum Spells
{
    SPELL_SHADOWBOLT            = 17393,
    SPELL_CLEAVE                = 15284,
    SPELL_MORTALSTRIKE          = 15708,

    SPELL_UNHOLY_AURA           = 15284,
    SPELL_RAISEDEAD             = 15708,  //triggers death pact (17471)

    SPELL_RAISE_DEAD1           = 17475,
    SPELL_RAISE_DEAD2           = 17476,
    SPELL_RAISE_DEAD3           = 17477,
    SPELL_RAISE_DEAD4           = 17478,
    SPELL_RAISE_DEAD5           = 17479,
    SPELL_RAISE_DEAD6           = 17480,
};

enum RivendareMisc
{
    EVENT_SHADOW_BOLT           = 0,
    EVENT_CLEAVE                = 1,
    EVENT_MORTAL_STRIKE         = 2,
    EVENT_SUMMON_SKELETON       = 3,
    EVENT_RAISE_DEAD            = 4,
};

enum RivendareCreatures
{
    NPC_SKELETON                = 11197
};

class boss_baron_rivendare : public CreatureScript
{
public:
    boss_baron_rivendare() : CreatureScript("boss_baron_rivendare") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_baron_rivendareAI>(creature);
    }

    struct boss_baron_rivendareAI : public ScriptedAI
    {
        boss_baron_rivendareAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        void Reset() override
        {
            _events.Reset();
            if (instance->GetData(TYPE_RAMSTEIN) == DONE)
                instance->SetData(TYPE_BARON, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_SHADOW_BOLT, 5 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_CLEAVE, 8 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_MORTAL_STRIKE, 12 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_SUMMON_SKELETON, 34 * IN_MILLISECONDS);
            //_events.ScheduleEvent(EVENT_RAISE_DEAD, 30 * IN_MILLISECONDS);
        }

        void AttackStart(Unit* who) override
        {
            //can't use entercombat(), boss' dmg aura sets near players in combat, before entering the room's door
            if (instance->GetData(TYPE_BARON) == NOT_STARTED)
                instance->SetData(TYPE_BARON, IN_PROGRESS);
            ScriptedAI::AttackStart(who);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(target);
        }

        void DoSpawnSkeleton()
        {
            DoCast(me, SPELL_RAISE_DEAD1);
            DoCast(me, SPELL_RAISE_DEAD2);
            DoCast(me, SPELL_RAISE_DEAD3);
            DoCast(me, SPELL_RAISE_DEAD4);
            DoCast(me, SPELL_RAISE_DEAD5);
            DoCast(me, SPELL_RAISE_DEAD6);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(TYPE_BARON, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_BOLT:
                        if (SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCastVictim(SPELL_SHADOWBOLT);
                        _events.ScheduleEvent(EVENT_SHADOW_BOLT, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        _events.ScheduleEvent(EVENT_CLEAVE, urand(7, 17) * IN_MILLISECONDS);
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTALSTRIKE);
                        _events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(10, 25) * IN_MILLISECONDS);
                        break;
                        /*case EVENT_RAISE_DEAD:
                        DoCast(me, SPELL_RAISEDEAD);
                        _events.ScheduleEvent(EVENT_RAISE_DEAD, 45*IN_MILLISECONDS);
                        break;*/
                    case EVENT_SUMMON_SKELETON:
                        DoSpawnSkeleton();
                        _events.ScheduleEvent(EVENT_SUMMON_SKELETON, 40 * IN_MILLISECONDS); //34 seconds until we should cast this again
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* instance;
        EventMap _events;
    };

};

void AddSC_boss_baron_rivendare()
{
    new boss_baron_rivendare();
}

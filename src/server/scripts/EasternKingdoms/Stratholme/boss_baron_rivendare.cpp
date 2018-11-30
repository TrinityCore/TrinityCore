/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "InstanceScript.h"
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

// Define Add positions
Position const ADD_POS_1 = {4017.403809f, -3339.703369f, 115.057655f, 5.487860f};
Position const ADD_POS_2 = {4013.189209f, -3351.808350f, 115.052254f, 0.134280f};
Position const ADD_POS_3 = {4017.738037f, -3363.478016f, 115.057274f, 0.723313f};
Position const ADD_POS_4 = {4048.877197f, -3363.223633f, 115.054253f, 3.627735f};
Position const ADD_POS_5 = {4051.777588f, -3350.893311f, 115.055351f, 3.066176f};
Position const ADD_POS_6 = {4048.375977f, -3339.966309f, 115.055222f, 2.457497f};

class boss_baron_rivendare : public CreatureScript
{
public:
    boss_baron_rivendare() : CreatureScript("boss_baron_rivendare") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStratholmeAI<boss_baron_rivendareAI>(creature);
    }

    struct boss_baron_rivendareAI : public ScriptedAI
    {
        boss_baron_rivendareAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = me->GetInstanceScript();
        }

        void Initialize()
        {
            ShadowBolt_Timer = 5000;
            Cleave_Timer = 8000;
            MortalStrike_Timer = 12000;
            //        RaiseDead_Timer = 30000;
            SummonSkeletons_Timer = 34000;
        }

        InstanceScript* instance;

        uint32 ShadowBolt_Timer;
        uint32 Cleave_Timer;
        uint32 MortalStrike_Timer;
        //    uint32 RaiseDead_Timer;
        uint32 SummonSkeletons_Timer;

        void Reset() override
        {
            Initialize();
            if (instance->GetData(TYPE_RAMSTEIN) == DONE)
                instance->SetData(TYPE_BARON, NOT_STARTED);
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

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(TYPE_BARON, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            //ShadowBolt
            if (ShadowBolt_Timer <= diff)
            {
                if (SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCastVictim(SPELL_SHADOWBOLT);

                ShadowBolt_Timer = 10000;
            } else ShadowBolt_Timer -= diff;

            //Cleave
            if (Cleave_Timer <= diff)
            {
                DoCastVictim(SPELL_CLEAVE);
                //13 seconds until we should cast this again
                Cleave_Timer = 7000 + (rand32() % 10000);
            } else Cleave_Timer -= diff;

            //MortalStrike
            if (MortalStrike_Timer <= diff)
            {
                DoCastVictim(SPELL_MORTALSTRIKE);
                MortalStrike_Timer = 10000 + (rand32() % 15000);
            } else MortalStrike_Timer -= diff;

            //RaiseDead
            //            if (RaiseDead_Timer <= diff)
            //          {
            //      DoCast(me, SPELL_RAISEDEAD);
            //                RaiseDead_Timer = 45000;
            //            } else RaiseDead_Timer -= diff;

            //SummonSkeletons
            if (SummonSkeletons_Timer <= diff)
            {
                me->SummonCreature(11197, ADD_POS_1, TEMPSUMMON_TIMED_DESPAWN, 29000);
                me->SummonCreature(11197, ADD_POS_2, TEMPSUMMON_TIMED_DESPAWN, 29000);
                me->SummonCreature(11197, ADD_POS_3, TEMPSUMMON_TIMED_DESPAWN, 29000);
                me->SummonCreature(11197, ADD_POS_4, TEMPSUMMON_TIMED_DESPAWN, 29000);
                me->SummonCreature(11197, ADD_POS_5, TEMPSUMMON_TIMED_DESPAWN, 29000);
                me->SummonCreature(11197, ADD_POS_6, TEMPSUMMON_TIMED_DESPAWN, 29000);

                //34 seconds until we should cast this again
                SummonSkeletons_Timer = 40000;
            } else SummonSkeletons_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_baron_rivendare()
{
    new boss_baron_rivendare();
}

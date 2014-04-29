/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Maiden_of_Virtue
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum MaidenOfVirtue
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_REPENTANCE          = 2,
    SAY_DEATH               = 3,

    SPELL_REPENTANCE        = 29511,
    SPELL_HOLYFIRE          = 29522,
    SPELL_HOLYWRATH         = 32445,
    SPELL_HOLYGROUND        = 29512,
    SPELL_BERSERK           = 26662,
};

class boss_maiden_of_virtue : public CreatureScript
{
public:
    boss_maiden_of_virtue() : CreatureScript("boss_maiden_of_virtue") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_maiden_of_virtueAI(creature);
    }

    struct boss_maiden_of_virtueAI : public ScriptedAI
    {
        boss_maiden_of_virtueAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 Repentance_Timer;
        uint32 Holyfire_Timer;
        uint32 Holywrath_Timer;
        uint32 Holyground_Timer;
        uint32 Enrage_Timer;

        bool Enraged;

        void Reset() override
        {
            Repentance_Timer    = 25000+(rand()%15000);
            Holyfire_Timer      = 8000+(rand()%17000);
            Holywrath_Timer     = 15000+(rand()%10000);
            Holyground_Timer    = 3000;
            Enrage_Timer        = 600000;

            Enraged = false;
        }

        void KilledUnit(Unit* /*Victim*/) override
        {
            if (urand(0, 1) == 0)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Enrage_Timer < diff && !Enraged)
            {
                DoCast(me, SPELL_BERSERK, true);
                Enraged = true;
            } else Enrage_Timer -= diff;

            if (Holyground_Timer <= diff)
            {
                DoCast(me, SPELL_HOLYGROUND, true);   //Triggered so it doesn't interrupt her at all
                Holyground_Timer = 3000;
            } else Holyground_Timer -= diff;

            if (Repentance_Timer <= diff)
            {
                DoCastVictim(SPELL_REPENTANCE);
                Talk(SAY_REPENTANCE);

                Repentance_Timer = urand(25000, 35000);        //A little randomness on that spell
            } else Repentance_Timer -= diff;

            if (Holyfire_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_HOLYFIRE);

                    Holyfire_Timer = urand(8000, 23000);      //Anywhere from 8 to 23 seconds, good luck having several of those in a row!
            } else Holyfire_Timer -= diff;

            if (Holywrath_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_HOLYWRATH);

                Holywrath_Timer = urand(20000, 25000);        //20-30 secs sounds nice
            } else Holywrath_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_maiden_of_virtue()
{
    new boss_maiden_of_virtue();
}

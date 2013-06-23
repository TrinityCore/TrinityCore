/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Amnennar_the_coldbringer
SD%Complete: 100
SDComment:
SDCategory: Razorfen Downs
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum AmnennarTheColdbringer
{
    SAY_AGGRO               = 0,
    SAY_SUMMON60            = 1,
    SAY_SUMMON30            = 2,
    SAY_HP                  = 3,
    SAY_KILL                = 4,

    SPELL_AMNENNARSWRATH    = 13009,
    SPELL_FROSTBOLT         = 15530,
    SPELL_FROST_NOVA        = 15531,
    SPELL_FROST_SPECTRES    = 12642
};

class boss_amnennar_the_coldbringer : public CreatureScript
{
public:
    boss_amnennar_the_coldbringer() : CreatureScript("boss_amnennar_the_coldbringer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_amnennar_the_coldbringerAI (creature);
    }

    struct boss_amnennar_the_coldbringerAI : public ScriptedAI
    {
        boss_amnennar_the_coldbringerAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 AmnenarsWrath_Timer;
        uint32 FrostBolt_Timer;
        uint32 FrostNova_Timer;
        bool Spectrals60;
        bool Spectrals30;
        bool Hp;

        void Reset()
        {
            AmnenarsWrath_Timer = 8000;
            FrostBolt_Timer = 1000;
            FrostNova_Timer = urand(10000, 15000);
            Spectrals30 = false;
            Spectrals60 = false;
            Hp = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //AmnenarsWrath_Timer
            if (AmnenarsWrath_Timer <= diff)
            {
                DoCastVictim(SPELL_AMNENNARSWRATH);
                AmnenarsWrath_Timer = 12000;
            } else AmnenarsWrath_Timer -= diff;

            //FrostBolt_Timer
            if (FrostBolt_Timer <= diff)
            {
                DoCastVictim(SPELL_FROSTBOLT);
                FrostBolt_Timer = 8000;
            } else FrostBolt_Timer -= diff;

            if (FrostNova_Timer <= diff)
            {
                DoCast(me, SPELL_FROST_NOVA);
                FrostNova_Timer = 15000;
            } else FrostNova_Timer -= diff;

            if (!Spectrals60 && HealthBelowPct(60))
            {
                Talk(SAY_SUMMON60);
                DoCastVictim(SPELL_FROST_SPECTRES);
                Spectrals60 = true;
            }

            if (!Hp && HealthBelowPct(50))
            {
                Talk(SAY_HP);
                Hp = true;
            }

            if (!Spectrals30 && HealthBelowPct(30))
            {
                Talk(SAY_SUMMON30);
                DoCastVictim(SPELL_FROST_SPECTRES);
                Spectrals30 = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_amnennar_the_coldbringer()
{
    new boss_amnennar_the_coldbringer();
}

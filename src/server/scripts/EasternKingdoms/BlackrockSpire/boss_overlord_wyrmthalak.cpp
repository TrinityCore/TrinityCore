/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Overlord_Wyrmthalak
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_BLASTWAVE         11130
#define SPELL_SHOUT             23511
#define SPELL_CLEAVE            20691
#define SPELL_KNOCKAWAY         20686

#define ADD_1X -39.355381
#define ADD_1Y -513.456482
#define ADD_1Z 88.472046
#define ADD_1O 4.679872

#define ADD_2X -49.875881
#define ADD_2Y -511.896942
#define ADD_2Z 88.195160
#define ADD_2O 4.613114
class boss_overlord_wyrmthalak : public CreatureScript
{
public:
    boss_overlord_wyrmthalak() : CreatureScript("boss_overlord_wyrmthalak") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_overlordwyrmthalakAI (pCreature);
    }

    struct boss_overlordwyrmthalakAI : public ScriptedAI
    {
        boss_overlordwyrmthalakAI(Creature *c) : ScriptedAI(c) {}

        uint32 BlastWave_Timer;
        uint32 Shout_Timer;
        uint32 Cleave_Timer;
        uint32 Knockaway_Timer;
        bool Summoned;

        void Reset()
        {
            BlastWave_Timer = 20000;
            Shout_Timer = 2000;
            Cleave_Timer = 6000;
            Knockaway_Timer = 12000;
            Summoned = false;
        }

        void EnterCombat(Unit * /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //BlastWave_Timer
            if (BlastWave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_BLASTWAVE);
                BlastWave_Timer = 20000;
            } else BlastWave_Timer -= diff;

            //Shout_Timer
            if (Shout_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHOUT);
                Shout_Timer = 10000;
            } else Shout_Timer -= diff;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 7000;
            } else Cleave_Timer -= diff;

            //Knockaway_Timer
            if (Knockaway_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KNOCKAWAY);
                Knockaway_Timer = 14000;
            } else Knockaway_Timer -= diff;

            //Summon two Beserks
            if (!Summoned && me->GetHealth()*100 / me->GetMaxHealth() < 51)
            {
                Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0, 100, true);

                if (Creature *SummonedCreature = me->SummonCreature(9216,ADD_1X,ADD_1Y,ADD_1Z,ADD_1O,TEMPSUMMON_TIMED_DESPAWN,300000))
                    SummonedCreature->AI()->AttackStart(pTarget);
                if (Creature *SummonedCreature = me->SummonCreature(9268,ADD_2X,ADD_2Y,ADD_2Z,ADD_2O,TEMPSUMMON_TIMED_DESPAWN,300000))
                    SummonedCreature->AI()->AttackStart(pTarget);
                Summoned = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_overlordwyrmthalak()
{
    new boss_overlord_wyrmthalak();
}

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
SDName: Boss_Broodlord_Lashlayer
SD%Complete: 100
SDComment:
SDCategory: Blackwing Lair
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Say
{
    SAY_AGGRO               = 0,
    SAY_LEASH               = 1,
};

enum Spells
{
    SPELL_CLEAVE            = 26350,
    SPELL_BLASTWAVE         = 23331,
    SPELL_MORTALSTRIKE      = 24573,
    SPELL_KNOCKBACK         = 25778
};

class boss_broodlord : public CreatureScript
{
public:
    boss_broodlord() : CreatureScript("boss_broodlord") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_broodlordAI (creature);
    }

    struct boss_broodlordAI : public ScriptedAI
    {
        boss_broodlordAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 Cleave_Timer;
        uint32 BlastWave_Timer;
        uint32 MortalStrike_Timer;
        uint32 KnockBack_Timer;

        void Reset()
        {
            Cleave_Timer = 8000;                                // These times are probably wrong
            BlastWave_Timer = 12000;
            MortalStrike_Timer = 20000;
            KnockBack_Timer = 30000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 7000;
            } else Cleave_Timer -= diff;

            // BlastWave
            if (BlastWave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_BLASTWAVE);
                BlastWave_Timer = urand(8000, 16000);
            } else BlastWave_Timer -= diff;

            //MortalStrike_Timer
            if (MortalStrike_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MORTALSTRIKE);
                MortalStrike_Timer = urand(25000, 35000);
            } else MortalStrike_Timer -= diff;

            if (KnockBack_Timer <= diff)
            {
                if (Unit* target = me->getVictim())
                {
                    DoCast(target, SPELL_KNOCKBACK);
                    // Drop 50% aggro
                    if (DoGetThreat(target))
                        DoModifyThreatPercent(target, -50);
                }

                KnockBack_Timer = urand(15000, 30000);
            } else KnockBack_Timer -= diff;

            if (EnterEvadeIfOutOfCombatArea(diff))
                Talk(SAY_LEASH);

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_broodlord()
{
    new boss_broodlord();
}

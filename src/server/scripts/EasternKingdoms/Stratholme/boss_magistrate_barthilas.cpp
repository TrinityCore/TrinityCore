/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Magistrate_Barthilas
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptPCH.h"
#include "stratholme.h"

#define SPELL_DRAININGBLOW    16793
#define SPELL_CROWDPUMMEL    10887
#define SPELL_MIGHTYBLOW    14099
#define SPELL_FURIOUS_ANGER     16791

#define MODEL_NORMAL            10433
#define MODEL_HUMAN             3637

class boss_magistrate_barthilas : public CreatureScript
{
public:
    boss_magistrate_barthilas() : CreatureScript("boss_magistrate_barthilas") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_magistrate_barthilasAI (pCreature);
    }

    struct boss_magistrate_barthilasAI : public ScriptedAI
    {
        boss_magistrate_barthilasAI(Creature *c) : ScriptedAI(c) {}

        uint32 DrainingBlow_Timer;
        uint32 CrowdPummel_Timer;
        uint32 MightyBlow_Timer;
        uint32 FuriousAnger_Timer;
        uint32 AngerCount;

        void Reset()
        {
            DrainingBlow_Timer = 20000;
            CrowdPummel_Timer = 15000;
            MightyBlow_Timer = 10000;
            FuriousAnger_Timer = 5000;
            AngerCount = 0;

            if (me->isAlive())
                me->SetDisplayId(MODEL_NORMAL);
            else
                me->SetDisplayId(MODEL_HUMAN);
        }

        void MoveInLineOfSight(Unit *who)
        {
            //nothing to see here yet

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*Killer*/)
        {
            me->SetDisplayId(MODEL_HUMAN);
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (FuriousAnger_Timer <= diff)
            {
                FuriousAnger_Timer = 4000;
                if (AngerCount > 25)
                    return;

                ++AngerCount;
                DoCast(me, SPELL_FURIOUS_ANGER, false);
            } else FuriousAnger_Timer -= diff;

            //DrainingBlow
            if (DrainingBlow_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DRAININGBLOW);
                DrainingBlow_Timer = 15000;
            } else DrainingBlow_Timer -= diff;

            //CrowdPummel
            if (CrowdPummel_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CROWDPUMMEL);
                CrowdPummel_Timer = 15000;
            } else CrowdPummel_Timer -= diff;

            //MightyBlow
            if (MightyBlow_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MIGHTYBLOW);
                MightyBlow_Timer = 20000;
            } else MightyBlow_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_magistrate_barthilas()
{
    new boss_magistrate_barthilas();
}

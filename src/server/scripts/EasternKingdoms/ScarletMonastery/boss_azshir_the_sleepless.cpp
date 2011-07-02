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
SDName: Boss_Azshir_the_Sleepless
SD%Complete: 80
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_CALLOFTHEGRAVE            17831
#define SPELL_TERRIFY                   7399
#define SPELL_SOULSIPHON                7290

class boss_azshir_the_sleepless : public CreatureScript
{
public:
    boss_azshir_the_sleepless() : CreatureScript("boss_azshir_the_sleepless") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_azshir_the_sleeplessAI (creature);
    }

    struct boss_azshir_the_sleeplessAI : public ScriptedAI
    {
        boss_azshir_the_sleeplessAI(Creature* c) : ScriptedAI(c) {}

        uint32 SoulSiphon_Timer;
        uint32 CallOftheGrave_Timer;
        uint32 Terrify_Timer;

        void Reset()
        {
            SoulSiphon_Timer = 1;
            CallOftheGrave_Timer = 30000;
            Terrify_Timer = 20000;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //If we are <50% hp cast Soul Siphon rank 1
            if (!HealthAbovePct(50) && !me->IsNonMeleeSpellCasted(false))
            {
                //SoulSiphon_Timer
                if (SoulSiphon_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_SOULSIPHON);
                    return;

                    //SoulSiphon_Timer = 20000;
                } else SoulSiphon_Timer -= diff;
            }

            //CallOfTheGrave_Timer
            if (CallOftheGrave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CALLOFTHEGRAVE);
                CallOftheGrave_Timer = 30000;
            } else CallOftheGrave_Timer -= diff;

            //Terrify_Timer
            if (Terrify_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_TERRIFY);
                Terrify_Timer = 20000;
            } else Terrify_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_azshir_the_sleepless()
{
    new boss_azshir_the_sleepless();
}

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
SDName: Boss_Ebonroc
SD%Complete: 50
SDComment: Shadow of Ebonroc needs core support
SDCategory: Blackwing Lair
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_SHADOWFLAME           22539
#define SPELL_WINGBUFFET            18500
#define SPELL_SHADOWOFEBONROC       23340
#define SPELL_HEAL                  41386                   //Thea Heal spell of his Shadow

class boss_ebonroc : public CreatureScript
{
public:
    boss_ebonroc() : CreatureScript("boss_ebonroc") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ebonrocAI (pCreature);
    }

    struct boss_ebonrocAI : public ScriptedAI
    {
        boss_ebonrocAI(Creature *c) : ScriptedAI(c) {}

        uint32 ShadowFlame_Timer;
        uint32 WingBuffet_Timer;
        uint32 ShadowOfEbonroc_Timer;
        uint32 Heal_Timer;

        void Reset()
        {
            ShadowFlame_Timer = 15000;                          //These times are probably wrong
            WingBuffet_Timer = 30000;
            ShadowOfEbonroc_Timer = 45000;
            Heal_Timer = 1000;
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //Shadowflame Timer
            if (ShadowFlame_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHADOWFLAME);
                ShadowFlame_Timer = urand(12000,15000);
            } else ShadowFlame_Timer -= diff;

            //Wing Buffet Timer
            if (WingBuffet_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WINGBUFFET);
                WingBuffet_Timer = 25000;
            } else WingBuffet_Timer -= diff;

            //Shadow of Ebonroc Timer
            if (ShadowOfEbonroc_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SHADOWOFEBONROC);
                ShadowOfEbonroc_Timer = urand(25000,350000);
            } else ShadowOfEbonroc_Timer -= diff;

            if (me->getVictim()->HasAura(SPELL_SHADOWOFEBONROC))
            {
                if (Heal_Timer <= diff)
                {
                    DoCast(me, SPELL_HEAL);
                    Heal_Timer = urand(1000,3000);
                } else Heal_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_ebonroc()
{
    new boss_ebonroc();
}

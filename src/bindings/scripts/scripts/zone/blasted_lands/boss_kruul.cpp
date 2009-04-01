/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Kruul
SD%Complete: 100
SDComment: Highlord Kruul are presumably no longer in-game on regular bases, however future events could bring him back.
SDCategory: Bosses
EndScriptData */

#include "precompiled.h"

#define SPELL_SHADOWVOLLEY          21341
#define SPELL_CLEAVE                20677
#define SPELL_THUNDERCLAP           23931
#define SPELL_TWISTEDREFLECTION     21063
#define SPELL_VOIDBOLT              21066
#define SPELL_RAGE                  21340
#define SPELL_CAPTURESOUL           21054

struct TRINITY_DLL_DECL boss_kruulAI : public ScriptedAI
{
    boss_kruulAI(Creature *c) : ScriptedAI(c) {}

    uint32 ShadowVolley_Timer;
    uint32 Cleave_Timer;
    uint32 ThunderClap_Timer;
    uint32 TwistedReflection_Timer;
    uint32 VoidBolt_Timer;
    uint32 Rage_Timer;
    uint32 Hound_Timer;
    int Rand;
    int RandX;
    int RandY;
    Creature* Summoned;

    void Reset()
    {
        ShadowVolley_Timer = 10000;
        Cleave_Timer = 14000;
        ThunderClap_Timer = 20000;
        TwistedReflection_Timer = 25000;
        VoidBolt_Timer = 30000;
        Rage_Timer = 60000;                                 //Cast rage after 1 minute
        Hound_Timer = 8000;
    }

    void Aggro(Unit *who)
    {
    }

    void KilledUnit()
    {
        // When a player, pet or totem gets killed, Lord Kazzak casts this spell to instantly regenerate 70,000 health.
        DoCast(m_creature,SPELL_CAPTURESOUL);

    }

    void SummonHounds(Unit* victim)
    {
        Rand = rand()%10;
        switch (rand()%2)
        {
            case 0: RandX = 0 - Rand; break;
            case 1: RandX = 0 + Rand; break;
        }
        Rand = 0;
        Rand = rand()%10;
        switch (rand()%2)
        {
            case 0: RandY = 0 - Rand; break;
            case 1: RandY = 0 + Rand; break;
        }
        Rand = 0;
        Summoned = DoSpawnCreature(19207, RandX, RandY, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
        if(Summoned)
            ((CreatureAI*)Summoned->AI())->AttackStart(victim);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim() )
            return;

        //ShadowVolley_Timer
        if (ShadowVolley_Timer < diff)
        {
            if (rand()%100 < 46)
            {
                DoCast(m_creature->getVictim(),SPELL_SHADOWVOLLEY);
            }

            ShadowVolley_Timer = 5000;
        }else ShadowVolley_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            if (rand()%100 < 50)
            {
                DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            }

            Cleave_Timer = 10000;
        }else Cleave_Timer -= diff;

        //ThunderClap_Timer
        if (ThunderClap_Timer < diff)
        {
            if (rand()%100 < 20)
            {
                DoCast(m_creature->getVictim(),SPELL_THUNDERCLAP);
            }

            ThunderClap_Timer = 12000;
        }else ThunderClap_Timer -= diff;

        //TwistedReflection_Timer
        if (TwistedReflection_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_TWISTEDREFLECTION);
            TwistedReflection_Timer = 30000;
        }else TwistedReflection_Timer -= diff;

        //VoidBolt_Timer
        if (VoidBolt_Timer < diff)
        {
            if (rand()%100 < 40)
            {
                DoCast(m_creature->getVictim(),SPELL_VOIDBOLT);
            }

            VoidBolt_Timer = 18000;
        }else VoidBolt_Timer -= diff;

        //Rage_Timer
        if (Rage_Timer < diff)
        {
            DoCast(m_creature,SPELL_RAGE);
            Rage_Timer = 70000;
        }else Rage_Timer -= diff;

        //Hound_Timer
        if (Hound_Timer < diff)
        {
            SummonHounds(m_creature->getVictim());
            SummonHounds(m_creature->getVictim());
            SummonHounds(m_creature->getVictim());

            Hound_Timer = 45000;
        }else Hound_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_kruul(Creature *_Creature)
{
    return new boss_kruulAI (_Creature);
}

void AddSC_boss_kruul()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_kruul";
    newscript->GetAI = &GetAI_boss_kruul;
    newscript->RegisterSelf();
}


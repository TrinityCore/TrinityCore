/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Ambassador_Flamelash
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_FIREBLAST            15573

struct TRINITY_DLL_DECL boss_ambassador_flamelashAI : public ScriptedAI
{
    boss_ambassador_flamelashAI(Creature *c) : ScriptedAI(c) {}

    uint32 FireBlast_Timer;
    uint32 Spirit_Timer;
    int Rand;
    int RandX;
    int RandY;
    Creature* Summoned;

    void Reset()
    {
        FireBlast_Timer = 2000;
        Spirit_Timer = 24000;
    }

    void EnterCombat(Unit *who) {}

    void SummonSpirits(Unit* victim)
    {
        Rand = rand()%10;
        switch (rand()%2)
        {
            case 0: RandX -= Rand; break;
            case 1: RandX += Rand; break;
        }
        Rand = 0;
        Rand = rand()%10;
        switch (rand()%2)
        {
            case 0: RandY -= Rand; break;
            case 1: RandY += Rand; break;
        }
        Summoned = DoSpawnCreature(9178, RandX, RandY, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
        if (Summoned)
            (Summoned->AI())->AttackStart(victim);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //FireBlast_Timer
        if (FireBlast_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FIREBLAST);
            FireBlast_Timer = 7000;
        }else FireBlast_Timer -= diff;

        //Spirit_Timer
        if (Spirit_Timer < diff)
        {
            SummonSpirits(m_creature->getVictim());
            SummonSpirits(m_creature->getVictim());
            SummonSpirits(m_creature->getVictim());
            SummonSpirits(m_creature->getVictim());

            Spirit_Timer = 30000;
        }else Spirit_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_ambassador_flamelash(Creature* pCreature)
{
    return new boss_ambassador_flamelashAI (pCreature);
}

void AddSC_boss_ambassador_flamelash()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_ambassador_flamelash";
    newscript->GetAI = &GetAI_boss_ambassador_flamelash;
    newscript->RegisterSelf();
}


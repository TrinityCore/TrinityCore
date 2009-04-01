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
SDName: Boss_Broodlord_Lashlayer
SD%Complete: 100
SDComment:
SDCategory: Blackwing Lair
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO               -1469000
#define SAY_LEASH               -1469001

#define SPELL_CLEAVE            26350
#define SPELL_BLASTWAVE         23331
#define SPELL_MORTALSTRIKE      24573
#define SPELL_KNOCKBACK         25778

struct TRINITY_DLL_DECL boss_broodlordAI : public ScriptedAI
{
    boss_broodlordAI(Creature *c) : ScriptedAI(c) {}

    uint32 Cleave_Timer;
    uint32 BlastWave_Timer;
    uint32 MortalStrike_Timer;
    uint32 KnockBack_Timer;
    uint32 LeashCheck_Timer;

    void Reset()
    {
        Cleave_Timer = 8000;                                //These times are probably wrong
        BlastWave_Timer = 12000;
        MortalStrike_Timer = 20000;
        KnockBack_Timer = 30000;
        LeashCheck_Timer = 2000;

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(1, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
    }

    void Aggro(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoZoneInCombat();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //LeashCheck_Timer
        if (LeashCheck_Timer < diff)
        {
            float rx,ry,rz;
            m_creature->GetRespawnCoord(rx, ry, rz);
            float spawndist = m_creature->GetDistance(rx,ry,rz);
            if ( spawndist > 250 )
            {
                DoScriptText(SAY_LEASH, m_creature);
                EnterEvadeMode();
                return;
            }
            LeashCheck_Timer = 2000;
        }else LeashCheck_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 7000;
        }else Cleave_Timer -= diff;

        // BlastWave
        if (BlastWave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_BLASTWAVE);
            BlastWave_Timer = 8000 + rand()%8000;
        }else BlastWave_Timer -= diff;

        //MortalStrike_Timer
        if (MortalStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MORTALSTRIKE);
            MortalStrike_Timer = 25000 + rand()%10000;
        }else MortalStrike_Timer -= diff;

        if (KnockBack_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_KNOCKBACK);
            //Drop 50% aggro
            if (DoGetThreat(m_creature->getVictim()))
                DoModifyThreatPercent(m_creature->getVictim(),-50);

            KnockBack_Timer = 15000 + rand()%15000;
        }else KnockBack_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_broodlord(Creature *_Creature)
{
    return new boss_broodlordAI (_Creature);
}

void AddSC_boss_broodlord()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_broodlord";
    newscript->GetAI = &GetAI_boss_broodlord;
    newscript->RegisterSelf();
}


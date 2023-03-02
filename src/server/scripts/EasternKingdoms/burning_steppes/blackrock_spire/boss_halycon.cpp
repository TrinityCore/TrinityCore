/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Halycon
SD%Complete: 100
SDComment:
SDCategory: Blackrock Spire
EndScriptData */

#include "scriptPCH.h"

#define SPELL_CROWDPUMMEL       10887
#define SPELL_MIGHTYBLOW        14099

struct boss_halyconAI : public ScriptedAI
{
    boss_halyconAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Summoned = false;
        Reset();
    }

    uint32 CrowdPummel_Timer;
    uint32 MightyBlow_Timer;
    bool Summoned;

    void Reset() override
    {
        CrowdPummel_Timer = 8000;
        MightyBlow_Timer = 14000;
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //CrowdPummel_Timer
        if (CrowdPummel_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CROWDPUMMEL);
            CrowdPummel_Timer = 14000;
        }
        else CrowdPummel_Timer -= diff;

        //MightyBlow_Timer
        if (MightyBlow_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MIGHTYBLOW);
            MightyBlow_Timer = 10000;
        }
        else MightyBlow_Timer -= diff;

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* pKiller) override
    {
        //Summon Gizrul
        if (!Summoned)
        {
            m_creature->MonsterTextEmote("Halycon lets loose a gutteral growl as her body collapses. A horrifying howl can be heard echoing through the halls of Blackrock Spire. Something is very, very angry.");
            if (Creature* pGizrul = m_creature->SummonCreature(10268, -167.58f, -382.41f, 64.401f, 1.563f, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                pGizrul->SetHomePosition(-172.633f, -324.253f, 64.401f, 4.74f);
                pGizrul->SetInCombatWithZone();
            }
            Summoned = true;
        }
    }
};
CreatureAI* GetAI_boss_halycon(Creature* pCreature)
{
    return new boss_halyconAI(pCreature);
}

void AddSC_boss_halycon()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_halycon";
    newscript->GetAI = &GetAI_boss_halycon;
    newscript->RegisterSelf();
}

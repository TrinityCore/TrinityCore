/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Anubshiah
SD%Complete: 100
SDComment:
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"

#define SPELL_SHADOWBOLT            15472
#define SPELL_CURSEOFTONGUES        15470
#define SPELL_CURSEOFWEAKNESS       12493
#define SPELL_DEMONARMOR            13787
#define SPELL_ENVELOPINGWEB         15471

struct boss_anubshiahAI : public ScriptedAI
{
    boss_anubshiahAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 ShadowBolt_Timer;
    uint32 CurseOfTongues_Timer;
    uint32 CurseOfWeakness_Timer;
    uint32 DemonArmor_Timer;
    uint32 EnvelopingWeb_Timer;

    void Reset() override
    {
        ShadowBolt_Timer = 7000;
        CurseOfTongues_Timer = 24000;
        CurseOfWeakness_Timer = 12000;
        DemonArmor_Timer = 3000;
        EnvelopingWeb_Timer = 16000;
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //ShadowBolt_Timer
        if (ShadowBolt_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWBOLT);
            ShadowBolt_Timer = 7000;
        }
        else ShadowBolt_Timer -= diff;

        //CurseOfTongues_Timer
        if (CurseOfTongues_Timer < diff)
        {
            Unit* target = nullptr;
            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target) DoCastSpellIfCan(target, SPELL_CURSEOFTONGUES);
            CurseOfTongues_Timer = 18000;
        }
        else CurseOfTongues_Timer -= diff;

        //CurseOfWeakness_Timer
        if (CurseOfWeakness_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSEOFWEAKNESS);
            CurseOfWeakness_Timer = 45000;
        }
        else CurseOfWeakness_Timer -= diff;

        //DemonArmor_Timer
        if (DemonArmor_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_DEMONARMOR);
            DemonArmor_Timer = 300000;
        }
        else DemonArmor_Timer -= diff;

        //EnvelopingWeb_Timer
        if (EnvelopingWeb_Timer < diff)
        {
            Unit* target = nullptr;
            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (target) DoCastSpellIfCan(target, SPELL_ENVELOPINGWEB);
            EnvelopingWeb_Timer = 12000;
        }
        else EnvelopingWeb_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_anubshiah(Creature* pCreature)
{
    return new boss_anubshiahAI(pCreature);
}

void AddSC_boss_anubshiah()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_anubshiah";
    newscript->GetAI = &GetAI_boss_anubshiah;
    newscript->RegisterSelf();
}

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
SDName: Boss_Emperor_Dagran_Thaurissan
SD%Complete: 90
SDComment: With script for Moria
SDCategory: Blackrock Depths
EndScriptData */

#include "scriptPCH.h"
#include "blackrock_depths.h"

enum eEmperor
{
    FACTION_FRIENDLY            = 35,
    SAY_AGGRO                   = -1230001,
    SAY_SLAY                    = -1230002,

    SPELL_HANDOFTHAURISSAN      = 17492,
    SPELL_AVATAROFFLAME         = 15636,
    SPELL_IRONFOE               = 15642
};

struct boss_emperor_dagran_thaurissanAI : public ScriptedAI
{
    boss_emperor_dagran_thaurissanAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiHandOfThaurissan_Timer;
    uint32 m_uiAvatarOfFlame_Timer;
    uint32 m_uiIronfoeTimer;
    uint32 m_uiCallForHelp_Timer;

    void Reset() override
    {
        m_uiHandOfThaurissan_Timer        = urand(5000, 7500);
        m_uiAvatarOfFlame_Timer           = 18000;
        m_uiIronfoeTimer                  = 9000;
        m_uiCallForHelp_Timer             = 8000;
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->CallForHelp(VISIBLE_RANGE);
    }

    void JustDied(Unit* pVictim) override
    {
        if (!m_pInstance)
            return;

        if (Creature* pPrincess = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_PRINCESS)))
        {
            if (pPrincess->IsAlive())
            {
                pPrincess->SetFactionTemplateId(FACTION_FRIENDLY);
                pPrincess->AI()->EnterEvadeMode();
            }
        }
    }

    void KilledUnit(Unit* pVictim) override
    {
        DoScriptText(SAY_SLAY, m_creature);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiHandOfThaurissan_Timer < uiDiff)
        {
            if (m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1, nullptr, SELECT_FLAG_PLAYER))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_HANDOFTHAURISSAN) == CAST_OK)
                    m_uiHandOfThaurissan_Timer = urand(10000, 15000);
            }
        }
        else
            m_uiHandOfThaurissan_Timer -= uiDiff;

        if (m_uiAvatarOfFlame_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_AVATAROFFLAME);
            m_uiAvatarOfFlame_Timer = 18000;
        }
        else
            m_uiAvatarOfFlame_Timer -= uiDiff;

        if (m_uiCallForHelp_Timer < uiDiff)
        {
            m_creature->CallForHelp(VISIBLE_RANGE);
            m_uiCallForHelp_Timer = 20000;
        }
        else
            m_uiCallForHelp_Timer -= uiDiff;

        /*
        if (m_uiIronfoeTimer < uiDiff)
        {
            if (m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
                if (DoCastSpellIfCan(m_creature, SPELL_IRONFOE) == CAST_OK)
                    m_uiIronfoeTimer = urand(20000, 25000);
        }
        else 
            m_uiIronfoeTimer -= uiDiff;
        */

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_emperor_dagran_thaurissan(Creature* pCreature)
{
    return new boss_emperor_dagran_thaurissanAI(pCreature);
}

/*######
## boss_moira_bronzebeard
######*/

enum ePrincess
{
    SPELL_HEAL                  = 15586,
    SPELL_RENEW                 = 10929,
    SPELL_SHIELD                = 10901,
    SPELL_MINDBLAST             = 15587,
    SPELL_SHADOWWORDPAIN        = 15654,
    SPELL_SMITE                 = 10934,
    SPELL_SHADOW_BOLT           = 15537,
    SPELL_OPEN_PORTAL           = 13912
};

struct boss_moira_bronzebeardAI : public ScriptedAI
{
    boss_moira_bronzebeardAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiHeal_Timer;
    uint32 m_uiMindBlast_Timer;
    uint32 m_uiShadowWordPain_Timer;
    uint32 m_uiSmite_Timer;

    void Reset() override
    {
        m_uiHeal_Timer = 12000;                                 //These times are probably wrong
        m_uiMindBlast_Timer = 16000;
        m_uiShadowWordPain_Timer = 2000;
        m_uiSmite_Timer = 8000;
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
        {
            if (Creature* pEmperor = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_EMPEROR)))
            {
                // if evade, then check if he is alive. If not, start make portal
                if (!pEmperor->IsAlive())
                    m_creature->CastSpell(m_creature, SPELL_OPEN_PORTAL, false);
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //MindBlast_Timer
        if (m_uiMindBlast_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MINDBLAST);
            m_uiMindBlast_Timer = 14000;
        }
        else
            m_uiMindBlast_Timer -= uiDiff;

        //ShadowWordPain_Timer
        if (m_uiShadowWordPain_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWWORDPAIN);
            m_uiShadowWordPain_Timer = 18000;
        }
        else
            m_uiShadowWordPain_Timer -= uiDiff;

        //Smite_Timer
        if (m_uiSmite_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SMITE);
            m_uiSmite_Timer = 10000;
        }
        else
            m_uiSmite_Timer -= uiDiff;

        //healTimer
        if (m_uiHeal_Timer < uiDiff)
        {
            if (Creature* pEmperor = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_EMPEROR)))
            {
                if (pEmperor->IsAlive() && pEmperor->GetHealthPercent() != 100.0f)
                    DoCastSpellIfCan(pEmperor, SPELL_HEAL);
            }

            m_uiHeal_Timer = 10000;
        }
        else
            m_uiHeal_Timer -= uiDiff;

        DoMeleeAttackIfReady(); //Sredna found proof.
    }
};

CreatureAI* GetAI_boss_moira_bronzebeard(Creature* pCreature)
{
    return new boss_moira_bronzebeardAI(pCreature);
}

void AddSC_boss_draganthaurissan()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_emperor_dagran_thaurissan";
    newscript->GetAI = &GetAI_boss_emperor_dagran_thaurissan;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_moira_bronzebeard";
    newscript->GetAI = &GetAI_boss_moira_bronzebeard;
    newscript->RegisterSelf();
}

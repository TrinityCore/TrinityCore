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
SDName: Boss_Moam
SD%Complete: 100
SDComment: fix summon mana fiend in core, find out if there is a mana drain
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"
#include "ruins_of_ahnqiraj.h"

enum
{
    EMOTE_AGGRO             =  -1509000,
    EMOTE_MANA_FULL         =  -1509001,
    EMOTE_DRAIN             =  -1509028,

    SPELL_TRAMPLE           =  15550,
    SPELL_ARCANEERUPTION    =  25672,
    SPELL_SUMMON_MANA_FIEND =  25681,                      //25682,25683
    SPELL_ENERGIZE          =  25685,
    SPELL_DRAINMANA         =  25676,

    // mana fiend
    NPC_MANA_FIEND          =  15527,
};

struct boss_moamAI : public ScriptedAI
{
    boss_moamAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiTrample_Timer;
    uint32 m_uiSummonManaFiend_Timer;
    uint32 m_uiTurnBackFromStone_Timer;
    uint32 m_uiArmorValue;
    uint32 m_uiDrainMana_Timer;
    ObjectGuid m_OGvictim;          // Memorize last target before turning into stone, then take it back.
    bool m_bIsInCombat;

    void Reset() override
    {
        m_uiTrample_Timer = 6000;
        m_uiSummonManaFiend_Timer = 90000;
        m_uiTurnBackFromStone_Timer = 90000;
        m_uiDrainMana_Timer = 5000;

        m_bIsInCombat = false;
        m_uiArmorValue = m_creature->GetCreatureInfo()->armor;

        m_OGvictim.Clear();

        if (m_pInstance)
            m_pInstance->SetData(TYPE_MOAM, NOT_STARTED);
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
        DoScriptText(EMOTE_AGGRO, m_creature);
        if (!m_bIsInCombat)
        {
            m_creature->SetPower(POWER_MANA, 0);
            m_bIsInCombat = true;
        }

        if (m_pInstance)
            m_pInstance->SetData(TYPE_MOAM, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        if (GameObject *pObsidian = m_creature->SummonGameObject(181069, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, 0, 0, 0, 0, -1, false))
            pObsidian->SetRespawnTime(345600);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_MOAM, DONE);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
        {
            if (pTarget->IsAlive())
            {
                pSummoned->AI()->AttackStart(pTarget);
                if (pSummoned->GetEntry() == NPC_MANA_FIEND)
                {
                    // Create visual animation of the teleportation spell
                    pSummoned->SendSpellGo(pSummoned, 25681);
                    return;
                }
            }
        }
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            pSummoned->AddObjectToRemoveList();
            return;
        }

        pSummoned->AddObjectToRemoveList();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if ((!m_creature->SelectHostileTarget() || !m_creature->GetVictim()) && !m_creature->HasAura(SPELL_ENERGIZE))
            return;

        // Once Moam got 100% mana, take back last target and launch arcane eruption
        if (m_creature->HasAura(SPELL_ENERGIZE))
        {
            m_uiTurnBackFromStone_Timer -= uiDiff;
            //m_creature->SetPower(POWER_MANA,0); /** Help to check stone form by setting mana to 0 */
            if (m_creature->GetPower(POWER_MANA) >= m_creature->GetMaxPower(POWER_MANA) ||
                    m_uiTurnBackFromStone_Timer == 0)
            {
                //Check if a victim was memorize, in case of error, take a random one.
                Unit * victim = m_creature->GetMap()->GetUnit(m_OGvictim);
                if (victim)
                    m_creature->AI()->AttackStart(victim);
                else
                    m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);

                m_creature->RemoveAurasDueToSpell(SPELL_ENERGIZE);
                DoCast(m_creature->GetVictim(), SPELL_ARCANEERUPTION, true);
                DoScriptText(EMOTE_MANA_FULL, m_creature);
                m_creature->SetArmor(m_uiArmorValue);
            }
        }

        if (m_creature->HasAura(SPELL_ENERGIZE))
            return;

        // Cast arcane eruption spell if not in energize mode and if mana is at 100%
        if (m_creature->GetPower(POWER_MANA) == m_creature->GetMaxPower(POWER_MANA))
        {
            DoCast(m_creature->GetVictim(), SPELL_ARCANEERUPTION);
            DoScriptText(EMOTE_MANA_FULL, m_creature);
        }

        // m_uiSummonManaFiend_Timer
        if (m_uiSummonManaFiend_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_ENERGIZE) == CAST_OK)
            {
                // TODO: Not sure if the armor increase is Blizzlike, please investigate.
                m_creature->SetArmor(18000);
                for (uint8 i = 0; i < 3; ++i)
                {
                    // Summon a Mana fiend which will disappear if Moam is reset
                    m_creature->SummonCreature(NPC_MANA_FIEND,
                                               m_creature->GetPositionX() + 2,
                                               m_creature->GetPositionY(),
                                               m_creature->GetPositionZ(),
                                               m_creature->GetOrientation(),
                                               TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                }

                m_uiSummonManaFiend_Timer = 90000;
                m_uiTurnBackFromStone_Timer = 90000;
                m_OGvictim = m_creature->GetVictim()->GetObjectGuid(); /** Memorize actual target to take it back,
                                      once the end of SPELL_ENERGIZE */
                m_creature->AttackStop();
                DoScriptText(EMOTE_DRAIN, m_creature);
            }
        }
        else
            m_uiSummonManaFiend_Timer -= uiDiff;

        //m_uiTrample_Timer
        if (m_uiTrample_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TRAMPLE) == CAST_OK)
                m_uiTrample_Timer = 15000;
        }
        else
            m_uiTrample_Timer -= uiDiff;

        // m_uiDrainMana_Timer
        if (m_uiDrainMana_Timer < uiDiff)
        {
            DoCast(m_creature, SPELL_DRAINMANA);
            m_uiDrainMana_Timer = 7000;
        }
        else
            m_uiDrainMana_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_moam(Creature* pCreature)
{
    return new boss_moamAI(pCreature);
}

void AddSC_boss_moam()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_moam";
    newscript->GetAI = &GetAI_boss_moam;
    newscript->RegisterSelf();
}

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
SDName: Boss_Mograine_And_Whitemane
SD%Complete: 90
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "scriptPCH.h"
#include "scarlet_monastery.h"

enum
{
    //Mograine says
    SAY_MO_AGGRO                 = -1189005,
    SAY_MO_KILL                  = -1189006,
    SAY_MO_RESSURECTED           = -1189007,

    //Whitemane says
    SAY_WH_INTRO                 = -1189008,
    SAY_WH_KILL                  = -1189009,
    SAY_WH_RESSURECT             = -1189010,

    //Mograine Spells
    SPELL_CRUSADERSTRIKE         = 14518,
    SPELL_HAMMEROFJUSTICE        = 5589,
    SPELL_LAYONHANDS             = 9257,
    SPELL_RETRIBUTIONAURA        = 8990,
    SPELL_DIVINESHIELD           = 1020,

    //Whitemanes Spells
    SPELL_DEEPSLEEP              = 9256,
    SPELL_SCARLETRESURRECTION    = 9232,
    SPELL_DOMINATEMIND           = 14515,
    SPELL_HOLYSMITE              = 9481,
    SPELL_HEAL                   = 12039,
    SPELL_POWERWORDSHIELD        = 22187,

    //Mograine's assist entry
    ENTRY_SCARLET_CHAPLAIN       = 4299,
    ENTRY_SCARLET_WIZARD         = 4300,
    ENTRY_SCARLET_CENTURION      = 4301,
    ENTRY_SCARLET_CHAMPION       = 4302,
    ENTRY_SCARLET_ABBOT          = 4303,
    ENTRY_SCARLET_MONK           = 4540
};

struct boss_scarlet_commander_mograineAI : public ScriptedAI
{
    boss_scarlet_commander_mograineAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiCrusaderStrike_Timer;
    uint32 m_uiHammerOfJustice_Timer;

    bool m_bDivineShield;
    bool m_bHasDied;
    bool m_bHeal;
    bool m_bFakeDeath;

    void Reset() override
    {
        m_uiCrusaderStrike_Timer = 10000;
        m_uiHammerOfJustice_Timer = 15000;

        //Incase wipe during phase that mograine fake death
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);

        m_bDivineShield = false;
        m_bHasDied = false;
        m_bHeal = false;
        m_bFakeDeath = false;

        if (!m_pInstance)
            return;

/** Commented to prevent an abuse of infinite respawn of Whitemane for hunter */
//        if (!(m_pInstance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == SPECIAL))
//        {
//            if (Creature* pWhitemane = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_WHITEMANE)))
//            {
//                if (m_creature->IsAlive() && !pWhitemane->IsAlive())
//                    pWhitemane->Respawn();
//            }
//        }
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_MO_AGGRO, m_creature);
        DoCastSpellIfCan(m_creature, SPELL_RETRIBUTIONAURA);

        std::list<Creature*> mograinesAssist;
        GetCreatureListWithEntryInGrid(mograinesAssist, m_creature, ENTRY_SCARLET_CHAPLAIN, 82.0f);
        GetCreatureListWithEntryInGrid(mograinesAssist, m_creature, ENTRY_SCARLET_WIZARD, 82.0f);
        GetCreatureListWithEntryInGrid(mograinesAssist, m_creature, ENTRY_SCARLET_CENTURION, 82.0f);
        GetCreatureListWithEntryInGrid(mograinesAssist, m_creature, ENTRY_SCARLET_CHAMPION, 82.0f);
        GetCreatureListWithEntryInGrid(mograinesAssist, m_creature, ENTRY_SCARLET_ABBOT, 82.0f);
        GetCreatureListWithEntryInGrid(mograinesAssist, m_creature, ENTRY_SCARLET_MONK, 82.0f);

        if (!mograinesAssist.empty())
        {
            for (const auto& itr : mograinesAssist)
            {
                if (itr->IsAlive() && itr->AI())
                    itr->AI()->AttackStart(pWho);
            }
        }
    }

    void KilledUnit(Unit* pVictim) override
    {
        DoScriptText(SAY_MO_KILL, m_creature);
    }

    void FakeDeath()
    {
        m_creature->GetMotionMaster()->MovementExpired();
        m_creature->GetMotionMaster()->MoveIdle();

        m_creature->SetHealth(0);

        if (m_creature->IsNonMeleeSpellCasted(false))
            m_creature->InterruptNonMeleeSpells(false);

        m_creature->ClearComboPointHolders();
        m_creature->RemoveAllAuras();
        m_creature->ClearAllReactives();

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        m_creature->SetStandState(UNIT_STAND_STATE_DEAD);

        m_bDivineShield = false;
        m_bHasDied = true;
        m_bFakeDeath = true;
   }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        if (uiDamage < m_creature->GetHealth())
            return;

        if (!m_pInstance)
            return;

        //On second death, fake death if whitemane is alive for prevent loot abuse.
        if (m_bHasDied)
        {
            if (Creature* pWhitemane = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_WHITEMANE)))
            {
                if (pWhitemane->IsAlive())
                    FakeDeath();
            }

            if (m_bFakeDeath)
                uiDamage = 0;

            return;
        }

        //On first death, fake death and open door, as well as initiate whitemane if exist
        if (Creature* pWhitemane = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_WHITEMANE)))
        {
            if (pWhitemane->IsAlive())
            {
                m_pInstance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, IN_PROGRESS);

                pWhitemane->GetMotionMaster()->MovePoint(1, 1163.113370f, 1398.856812f, 32.527786f);

                FakeDeath();

                uiDamage = 0;
            }
        }
    }

    void SpellHit(Unit* pWho, SpellEntry const* pSpell) override
    {
        //When hit with ressurection stop fake death and say text
        if (pSpell->Id == SPELL_SCARLETRESURRECTION)
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->SetStandState(UNIT_STAND_STATE_STAND);
            m_creature->SetHealth(m_creature->GetMaxHealth());

            DoScriptText(SAY_MO_RESSURECTED, m_creature);
            m_bFakeDeath = false;

            if (m_pInstance)
                m_pInstance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, SPECIAL);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_bHasDied && !m_bHeal && m_pInstance && m_pInstance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == SPECIAL)
        {
            //On ressurection, heal whitemane and resume fight
            if (Creature* pWhitemane = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_WHITEMANE)))
            {
                DoCastSpellIfCan(pWhitemane, SPELL_LAYONHANDS);

                m_uiCrusaderStrike_Timer = 10000;
                m_uiHammerOfJustice_Timer = 15000;

                if (m_creature->GetVictim())
                    m_creature->GetMotionMaster()->MoveChase(m_creature->GetVictim());

                m_bHeal = true;
            }
        }

        //This if-check to make sure mograine does not attack while fake death
        if (m_bFakeDeath)
            return;

        //m_uiCrusaderStrike_Timer
        if (m_uiCrusaderStrike_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CRUSADERSTRIKE);
            m_uiCrusaderStrike_Timer = 10000;
        }
        else
            m_uiCrusaderStrike_Timer -= uiDiff;

        //m_uiHammerOfJustice_Timer
        if (m_uiHammerOfJustice_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_HAMMEROFJUSTICE);
            m_uiHammerOfJustice_Timer = 45000;
        }
        else
            m_uiHammerOfJustice_Timer -= uiDiff;

        if (m_creature->GetHealthPercent() < 25.0f && !m_bDivineShield)
        {
            m_bDivineShield = true;
            DoCastSpellIfCan(m_creature, SPELL_DIVINESHIELD, true);
        }

        DoMeleeAttackIfReady();
    }
};

struct boss_high_inquisitor_whitemaneAI : public ScriptedAI
{
    boss_high_inquisitor_whitemaneAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiHeal_Timer;
    uint32 m_uiPowerWordShield_Timer;
    uint32 m_uiHolySmite_Timer;
    uint32 m_uiWait_Timer;
    uint32 m_uiStopAttack_Timer;

    bool m_bCanResurrectCheck;
    bool m_bCanResurrect;
    bool m_bStopAttack;

    void Reset() override
    {
        m_uiWait_Timer = 7000;
        m_uiHeal_Timer = 10000;
        m_uiPowerWordShield_Timer = 15000;
        m_uiHolySmite_Timer = 6000;
        m_uiStopAttack_Timer = 2000;

        m_bCanResurrectCheck = false;
        m_bCanResurrect = false;
        m_bStopAttack = false;

        if (!m_pInstance)
            return;

        if (Creature* pMograine = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_MOGRAINE)))
        {
            if (m_creature->IsAlive() && !pMograine->IsAlive())
                pMograine->Respawn();
        }
    }


    void JustReachedHome() override
    {
        if (m_pInstance)
        {
            if (!(m_pInstance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == NOT_STARTED) || !(m_pInstance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == FAIL))
                m_pInstance->SetData(TYPE_MOGRAINE_AND_WHITE_EVENT, FAIL);
        }
        ScriptedAI::JustReachedHome();
    }

    void MoveInLineOfSight(Unit*) override
    {
        //This needs to be empty because Whitemane should NOT aggro while fighting Mograine. Mograine will give us a target.
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        if (uiDamage < m_creature->GetHealth())
            return;

        if (!m_bCanResurrectCheck || m_bCanResurrect)
        {
            // prevent killing blow before rezzing commander
            m_creature->SetHealth(uiDamage + 1);
        }
        ScriptedAI::DamageTaken(pDoneBy, uiDamage);
    }

    void AttackStart(Unit* pWho) override
    {
        if (m_pInstance && (m_pInstance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == NOT_STARTED || m_pInstance->GetData(TYPE_MOGRAINE_AND_WHITE_EVENT) == FAIL))
            return;

        if (m_bStopAttack)
            return;

        ScriptedAI::AttackStart(pWho);
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_WH_INTRO, m_creature);
    }

    void KilledUnit(Unit* pVictim) override
    {
        DoScriptText(SAY_WH_KILL, m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
        {
            if (Creature* pMograine = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_MOGRAINE)))
            {
                if (pMograine->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    pKiller->DealDamage(pMograine, 1, nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if ((!m_creature->SelectHostileTarget() || !m_creature->GetVictim()) && !m_bStopAttack)
            return;

        if (m_bCanResurrect)
        {
            //When casting resuruction make sure to delay so on rez when reinstate battle deepsleep runs out
            if (m_pInstance && m_uiWait_Timer < uiDiff)
            {
                if (Creature* pMograine = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_MOGRAINE)))
                {
                    DoCastSpellIfCan(pMograine, SPELL_SCARLETRESURRECTION);
                    DoScriptText(SAY_WH_RESSURECT, m_creature);
                    m_bCanResurrect = false;
                }
            }
            else
                m_uiWait_Timer -= uiDiff;
        }

        //Cast Deep sleep when health is less than 50%
        if (!m_bCanResurrectCheck && m_creature->GetHealthPercent() <= 50.0f)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(false);

            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DEEPSLEEP);
            m_bCanResurrectCheck = true;
            m_bCanResurrect = true;
            m_bStopAttack = true;

            if (m_pInstance)
            {
                if (Creature* pMograine = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_MOGRAINE)))
                {
                    m_creature->AttackStop(true);
                    m_creature->GetMotionMaster()->Clear();
                    m_creature->GetMotionMaster()->MovePoint(2, pMograine->GetPositionX() - 2.0f, pMograine->GetPositionY(), pMograine->GetPositionZ());
                }
            }
            return;
        }

        //while in "resurrect-mode", don't do anything
        if (m_bCanResurrect)
            return;

        //m_uiStopAttack_Timer
        if (m_bStopAttack)
        {
            if (m_uiStopAttack_Timer < uiDiff)
                m_bStopAttack = false;
            else
                m_uiStopAttack_Timer -= uiDiff;
        }

        //If we are <75% hp cast healing spells at self or Mograine
        if (m_uiHeal_Timer < uiDiff)
        {
            Creature* pTarget = nullptr;

            if (m_creature->GetHealthPercent() <= 75.0f)
                pTarget = m_creature;

            if (m_pInstance)
            {
                if (Creature* pMograine = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_MOGRAINE)))
                {
                    if (pMograine->IsAlive() && pMograine->GetHealthPercent() <= 75.0f)
                        pTarget = pMograine;
                }
            }

            if (pTarget)
                DoCastSpellIfCan(pTarget, SPELL_HEAL);

            m_uiHeal_Timer = 13000;
        }
        else
            m_uiHeal_Timer -= uiDiff;

        //m_uiPowerWordShield_Timer
        if (m_uiPowerWordShield_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_POWERWORDSHIELD);
            m_uiPowerWordShield_Timer = 15000;
        }
        else
            m_uiPowerWordShield_Timer -= uiDiff;

        //m_uiHolySmite_Timer
        if (m_uiHolySmite_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_HOLYSMITE);
            m_uiHolySmite_Timer = 6000;
        }
        else
            m_uiHolySmite_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void MovementInform(uint32 MovementType, uint32 id) override
    {
        if (MovementType == POINT_MOTION_TYPE && id == 1)
            m_creature->SetInCombatWithZone();
        else
        {
            if (m_pInstance)
            {
                if (Creature* pMograine = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_MOGRAINE)))
                    m_creature->SetFacingToObject(pMograine);
            }
        }
    }
};

CreatureAI* GetAI_boss_scarlet_commander_mograine(Creature* pCreature)
{
    return new boss_scarlet_commander_mograineAI(pCreature);
}

CreatureAI* GetAI_boss_high_inquisitor_whitemane(Creature* pCreature)
{
    return new boss_high_inquisitor_whitemaneAI(pCreature);
}

void AddSC_boss_mograine_and_whitemane()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_scarlet_commander_mograine";
    newscript->GetAI = &GetAI_boss_scarlet_commander_mograine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_high_inquisitor_whitemane";
    newscript->GetAI = &GetAI_boss_high_inquisitor_whitemane;
    newscript->RegisterSelf();
}

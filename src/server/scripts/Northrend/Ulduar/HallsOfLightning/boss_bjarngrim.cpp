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
SDName: Boss General Bjarngrim
SD%Complete: 70%
SDComment: Waypoint needed, we expect boss to always have 2x Stormforged Lieutenant following
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptPCH.h"
#include "halls_of_lightning.h"

enum eEnums
{
    //Yell
    SAY_AGGRO                               = -1602000,
    SAY_SLAY_1                              = -1602001,
    SAY_SLAY_2                              = -1602002,
    SAY_SLAY_3                              = -1602003,
    SAY_DEATH                               = -1602004,
    SAY_BATTLE_STANCE                       = -1602005,
    EMOTE_BATTLE_STANCE                     = -1602006,
    SAY_BERSEKER_STANCE                     = -1602007,
    EMOTE_BERSEKER_STANCE                   = -1602008,
    SAY_DEFENSIVE_STANCE                    = -1602009,
    EMOTE_DEFENSIVE_STANCE                  = -1602010,

    SPELL_DEFENSIVE_STANCE                  = 53790,
    //SPELL_DEFENSIVE_AURA                    = 41105,
    SPELL_SPELL_REFLECTION                  = 36096,
    SPELL_PUMMEL                            = 12555,
    SPELL_KNOCK_AWAY                        = 52029,
    SPELL_IRONFORM                          = 52022,

    SPELL_BERSEKER_STANCE                   = 53791,
    //SPELL_BERSEKER_AURA                     = 41107,
    SPELL_INTERCEPT                         = 58769,
    SPELL_WHIRLWIND                         = 52027,
    SPELL_CLEAVE                            = 15284,

    SPELL_BATTLE_STANCE                     = 53792,
    //SPELL_BATTLE_AURA                       = 41106,
    SPELL_MORTAL_STRIKE                     = 16856,
    SPELL_SLAM                              = 52026,

    //OTHER SPELLS
    //SPELL_CHARGE_UP                         = 52098,      // only used when starting walk from one platform to the other
    //SPELL_TEMPORARY_ELECTRICAL_CHARGE       = 52092,      // triggered part of above

    NPC_STORMFORGED_LIEUTENANT              = 29240,
    SPELL_ARC_WELD                          = 59085,
    SPELL_RENEW_STEEL_N                     = 52774,
    SPELL_RENEW_STEEL_H                     = 59160,

    EQUIP_SWORD                             = 37871,
    EQUIP_SHIELD                            = 35642,
    EQUIP_MACE                              = 43623,

    STANCE_DEFENSIVE                        = 0,
    STANCE_BERSERKER                        = 1,
    STANCE_BATTLE                           = 2
};

/*######
## boss_bjarngrim
######*/

struct boss_bjarngrimAI : public ScriptedAI
{
    boss_bjarngrimAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
        m_uiStance = STANCE_DEFENSIVE;
        memset(&m_auiStormforgedLieutenantGUID, 0, sizeof(m_auiStormforgedLieutenantGUID));
    }

    ScriptedInstance* m_pInstance;

    bool m_bIsChangingStance;

    uint8 m_uiChargingStatus;
    uint8 m_uiStance;

    uint32 m_uiCharge_Timer;
    uint32 m_uiChangeStance_Timer;

    uint32 m_uiReflection_Timer;
    uint32 m_uiKnockAway_Timer;
    uint32 m_uiPummel_Timer;
    uint32 m_uiIronform_Timer;

    uint32 m_uiIntercept_Timer;
    uint32 m_uiWhirlwind_Timer;
    uint32 m_uiCleave_Timer;

    uint32 m_uiMortalStrike_Timer;
    uint32 m_uiSlam_Timer;

    uint64 m_auiStormforgedLieutenantGUID[2];

    void Reset()
    {
        m_bIsChangingStance = false;

        m_uiChargingStatus = 0;
        m_uiCharge_Timer = 1000;

        m_uiChangeStance_Timer = 20000 + rand()%5000;

        m_uiReflection_Timer = 8000;
        m_uiKnockAway_Timer = 20000;
        m_uiPummel_Timer = 10000;
        m_uiIronform_Timer = 25000;

        m_uiIntercept_Timer = 5000;
        m_uiWhirlwind_Timer = 10000;
        m_uiCleave_Timer = 8000;

        m_uiMortalStrike_Timer = 8000;
        m_uiSlam_Timer = 10000;

        for (uint8 i = 0; i < 2; ++i)
        {
            if (Creature* pStormforgedLieutenant = (Unit::GetCreature((*me), m_auiStormforgedLieutenantGUID[i])))
            {
                if (!pStormforgedLieutenant->isAlive())
                    pStormforgedLieutenant->Respawn();
            }
        }

        if (m_uiStance != STANCE_DEFENSIVE)
        {
            DoRemoveStanceAura(m_uiStance);
            DoCast(me, SPELL_DEFENSIVE_STANCE);
            m_uiStance = STANCE_DEFENSIVE;
        }

        SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SHIELD, EQUIP_NO_CHANGE);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_BJARNGRIM, NOT_STARTED);
    }

    void EnterCombat(Unit* /*pWho*/)
    {
        DoScriptText(SAY_AGGRO, me);

        //must get both lieutenants here and make sure they are with him
        me->CallForHelp(30.0f);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_BJARNGRIM, IN_PROGRESS);
    }

    void KilledUnit(Unit* /*pVictim*/)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
    }

    void JustDied(Unit* /*pKiller*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_BJARNGRIM, DONE);
    }

    //TODO: remove when removal is done by the core
    void DoRemoveStanceAura(uint8 uiStance)
    {
        switch(uiStance)
        {
            case STANCE_DEFENSIVE:
                me->RemoveAurasDueToSpell(SPELL_DEFENSIVE_STANCE);
                break;
            case STANCE_BERSERKER:
                me->RemoveAurasDueToSpell(SPELL_BERSEKER_STANCE);
                break;
            case STANCE_BATTLE:
                me->RemoveAurasDueToSpell(SPELL_BATTLE_STANCE);
                break;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
     if (!UpdateVictim())
            return;

        // Change stance
        if (m_uiChangeStance_Timer <= uiDiff)
        {
            //wait for current spell to finish before change stance
            if (me->IsNonMeleeSpellCasted(false))
                return;

            DoRemoveStanceAura(m_uiStance);

            int uiTempStance = rand()%(3-1);

            if (uiTempStance >= m_uiStance)
                ++uiTempStance;

            m_uiStance = uiTempStance;

            switch(m_uiStance)
            {
                case STANCE_DEFENSIVE:
                    DoScriptText(SAY_DEFENSIVE_STANCE, me);
                    DoScriptText(EMOTE_DEFENSIVE_STANCE, me);
                    DoCast(me, SPELL_DEFENSIVE_STANCE);
                    SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SHIELD, EQUIP_NO_CHANGE);
                    break;
                case STANCE_BERSERKER:
                    DoScriptText(SAY_BERSEKER_STANCE, me);
                    DoScriptText(EMOTE_BERSEKER_STANCE, me);
                    DoCast(me, SPELL_BERSEKER_STANCE);
                    SetEquipmentSlots(false, EQUIP_SWORD, EQUIP_SWORD, EQUIP_NO_CHANGE);
                    break;
                case STANCE_BATTLE:
                    DoScriptText(SAY_BATTLE_STANCE, me);
                    DoScriptText(EMOTE_BATTLE_STANCE, me);
                    DoCast(me, SPELL_BATTLE_STANCE);
                    SetEquipmentSlots(false, EQUIP_MACE, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                    break;
            }

            m_uiChangeStance_Timer = 20000 + rand()%5000;
            return;
        }
        else
            m_uiChangeStance_Timer -= uiDiff;

        switch(m_uiStance)
        {
            case STANCE_DEFENSIVE:
            {
                if (m_uiReflection_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_SPELL_REFLECTION);
                    m_uiReflection_Timer = 8000 + rand()%1000;
                }
                else
                    m_uiReflection_Timer -= uiDiff;

                if (m_uiKnockAway_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_KNOCK_AWAY);
                    m_uiKnockAway_Timer = 20000 + rand()%1000;
                }
                else
                    m_uiKnockAway_Timer -= uiDiff;

                if (m_uiPummel_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_PUMMEL);
                    m_uiPummel_Timer = 10000 + rand()%1000;
                }
                else
                    m_uiPummel_Timer -= uiDiff;

                if (m_uiIronform_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_IRONFORM);
                    m_uiIronform_Timer = 25000 + rand()%1000;
                }
                else
                    m_uiIronform_Timer -= uiDiff;

                break;
            }
            case STANCE_BERSERKER:
            {
                if (m_uiIntercept_Timer <= uiDiff)
                {
                    //not much point is this, better random target and more often?
                    DoCast(me->getVictim(), SPELL_INTERCEPT);
                    m_uiIntercept_Timer = 45000 + rand()%1000;
                }
                else
                    m_uiIntercept_Timer -= uiDiff;

                if (m_uiWhirlwind_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_WHIRLWIND);
                    m_uiWhirlwind_Timer = 10000 + rand()%1000;
                }
                else
                    m_uiWhirlwind_Timer -= uiDiff;

                if (m_uiCleave_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_CLEAVE);
                    m_uiCleave_Timer = 8000 + rand()%1000;
                }
                else
                    m_uiCleave_Timer -= uiDiff;

                break;
            }
            case STANCE_BATTLE:
            {
                if (m_uiMortalStrike_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
                    m_uiMortalStrike_Timer = 20000 + rand()%1000;
                }
                else
                    m_uiMortalStrike_Timer -= uiDiff;

                if (m_uiSlam_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_SLAM);
                    m_uiSlam_Timer = 15000 + rand()%1000;
                }
                else
                    m_uiSlam_Timer -= uiDiff;

                break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

/*######
## mob_stormforged_lieutenant
######*/

struct mob_stormforged_lieutenantAI : public ScriptedAI
{
    mob_stormforged_lieutenantAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiArcWeld_Timer;
    uint32 m_uiRenewSteel_Timer;

    void Reset()
    {
        m_uiArcWeld_Timer = 20000 + rand()%1000;
        m_uiRenewSteel_Timer = 10000 + rand()%1000;
    }

    void EnterCombat(Unit* pWho)
    {
        if (m_pInstance)
        {
            if (Creature* pBjarngrim = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_BJARNGRIM)))
            {
                if (pBjarngrim->isAlive() && !pBjarngrim->getVictim())
                    pBjarngrim->AI()->AttackStart(pWho);
            }
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (m_uiArcWeld_Timer <= uiDiff)
        {
            DoCast(me->getVictim(), SPELL_ARC_WELD);
            m_uiArcWeld_Timer = 20000 + rand()%1000;
        }
        else
            m_uiArcWeld_Timer -= uiDiff;

        if (m_uiRenewSteel_Timer <= uiDiff)
        {
            if (m_pInstance)
            {
                if (Creature* pBjarngrim = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_BJARNGRIM)))
                {
                    if (pBjarngrim->isAlive())
                        DoCast(pBjarngrim, SPELL_RENEW_STEEL_N);
                }
            }
            m_uiRenewSteel_Timer = 10000 + rand()%4000;
        }
        else
            m_uiRenewSteel_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_bjarngrim(Creature* pCreature)
{
    return new boss_bjarngrimAI(pCreature);
}

CreatureAI* GetAI_mob_stormforged_lieutenant(Creature* pCreature)
{
    return new mob_stormforged_lieutenantAI(pCreature);
}

void AddSC_boss_bjarngrim()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_bjarngrim";
    newscript->GetAI = &GetAI_boss_bjarngrim;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_stormforged_lieutenant";
    newscript->GetAI = &GetAI_mob_stormforged_lieutenant;
    newscript->RegisterSelf();
}

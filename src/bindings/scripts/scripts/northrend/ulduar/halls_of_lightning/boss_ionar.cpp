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
SDName: Boss Ionar
SD%Complete: 80%
SDComment: Timer check
SDCategory: Halls of Lightning
EndScriptData */

#include "precompiled.h"
#include "def_halls_of_lightning.h"

enum
{
    SAY_AGGRO                               = -1602011,
    SAY_SLAY_1                              = -1602012,
    SAY_SLAY_2                              = -1602013,
    SAY_SLAY_3                              = -1602014,
    SAY_DEATH                               = -1602015,
    SAY_SPLIT_1                             = -1602016,
    SAY_SPLIT_2                             = -1602017,

    SPELL_BALL_LIGHTNING_N                  = 52780,
    SPELL_BALL_LIGHTNING_H                  = 59800,
    SPELL_STATIC_OVERLOAD_N                 = 52658,
    SPELL_STATIC_OVERLOAD_H                 = 59795,

    SPELL_DISPERSE                          = 52770,
    SPELL_SUMMON_SPARK                      = 52746,
    SPELL_SPARK_DESPAWN                     = 52776,

    //Spark of Ionar
    SPELL_SPARK_VISUAL_TRIGGER_N            = 52667,
    SPELL_SPARK_VISUAL_TRIGGER_H            = 59833,

    NPC_SPARK_OF_IONAR                      = 28926,

    MAX_SPARKS                              = 5,
    POINT_CALLBACK                          = 0
};

/*######
## Boss Ionar
######*/

struct TRINITY_DLL_DECL boss_ionarAI : public ScriptedAI
{
    boss_ionarAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
        m_bIsHeroic = pCreature->GetMap()->IsHeroic();
    }

    ScriptedInstance* m_pInstance;

    std::list<uint64> m_lSparkGUIDList;

    bool m_bIsHeroic;

    bool m_bIsSplitPhase;
    uint32 m_uiSplit_Timer;
    uint32 m_uiSparkAtHomeCount;

    uint32 m_uiStaticOverload_Timer;
    uint32 m_uiBallLightning_Timer;

    uint32 m_uiHealthAmountModifier;

    void Reset()
    {
        m_lSparkGUIDList.clear();

        m_bIsSplitPhase = true;
        m_uiSplit_Timer = 25000;
        m_uiSparkAtHomeCount = 0;

        m_uiStaticOverload_Timer = 5000 + rand()%1000;
        m_uiBallLightning_Timer = 10000 + rand()%1000;

        m_uiHealthAmountModifier = 1;

        if (m_creature->GetVisibility() == VISIBILITY_OFF)
            m_creature->SetVisibility(VISIBILITY_ON);
    }

    void AttackedBy(Unit* pAttacker)
    {
        if (m_creature->getVictim())
            return;

        if (m_creature->GetVisibility() == VISIBILITY_OFF)
            return;

        AttackStart(pAttacker);
    }

    void Aggro(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_IONAR, IN_PROGRESS);
    }

    void JustReachedHome()
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_IONAR, NOT_STARTED);
    }

    void AttackStart(Unit* pWho)
    {
        if (m_creature->Attack(pWho, true))
        {
            m_creature->AddThreat(pWho, 0.0f);
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);

            if (m_creature->GetVisibility() != VISIBILITY_OFF)
                m_creature->GetMotionMaster()->MoveChase(pWho);
        }
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        DespawnSpark();

        if (m_pInstance)
            m_pInstance->SetData(TYPE_IONAR, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature); break;
            case 2: DoScriptText(SAY_SLAY_3, m_creature); break;
        }
    }

    void DespawnSpark()
    {
        if (m_lSparkGUIDList.empty())
            return;

        for(std::list<uint64>::iterator itr = m_lSparkGUIDList.begin(); itr != m_lSparkGUIDList.end(); ++itr)
        {
            if (Creature* pTemp = Unit::GetCreature(*m_creature, *itr))
            {
                if (pTemp->isAlive())
                    pTemp->ForcedDespawn();
            }
        }

        m_lSparkGUIDList.clear();
    }

    //make sparks come back
    void CallBackSparks()
    {
        //should never be empty here, but check
        if (m_lSparkGUIDList.empty())
            return;

        for(std::list<uint64>::iterator itr = m_lSparkGUIDList.begin(); itr != m_lSparkGUIDList.end(); ++itr)
        {
            if (Creature* pSpark = Unit::GetCreature(*m_creature, *itr))
            {
                if (pSpark->isAlive())
                {
                    if (pSpark->GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE)
                        pSpark->GetMotionMaster()->MovementExpired();

                    pSpark->SetSpeed(MOVE_RUN, pSpark->GetCreatureInfo()->speed * 2);
                    pSpark->GetMotionMaster()->MovePoint(POINT_CALLBACK, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ());
                }
            }
        }
    }

    void RegisterSparkAtHome()
    {
        ++m_uiSparkAtHomeCount;
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == NPC_SPARK_OF_IONAR)
        {
            pSummoned->CastSpell(pSummoned, m_bIsHeroic ? SPELL_SPARK_VISUAL_TRIGGER_H : SPELL_SPARK_VISUAL_TRIGGER_N, true);

            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);

            if (m_creature->getVictim())
                pSummoned->AI()->AttackStart(pTarget ? pTarget : m_creature->getVictim());

            m_lSparkGUIDList.push_back(pSummoned->GetGUID());
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        // Splitted
        if (m_creature->GetVisibility() == VISIBILITY_OFF)
        {
            if (!m_creature->getVictim())
            {
                Reset();
                return;
            }

            if (m_uiSplit_Timer < uiDiff)
            {
                m_uiSplit_Timer = 2500;

                // Return sparks to where Ionar splitted
                if (m_bIsSplitPhase)
                {
                    CallBackSparks();
                    m_bIsSplitPhase = false;
                }
                // Lightning effect and restore Ionar
                else if (m_uiSparkAtHomeCount == MAX_SPARKS)
                {
                    m_creature->SetVisibility(VISIBILITY_ON);
                    m_creature->CastSpell(m_creature, SPELL_SPARK_DESPAWN, false);

                    DespawnSpark();

                    m_uiSparkAtHomeCount = 0;
                    m_uiSplit_Timer = 25000;
                    m_bIsSplitPhase = true;

                    if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    {
                        if (m_creature->getVictim())
                            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                    }
                }
            }
            else
                m_uiSplit_Timer -= uiDiff;

            return;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (m_uiStaticOverload_Timer < uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, m_bIsHeroic ? SPELL_STATIC_OVERLOAD_H : SPELL_STATIC_OVERLOAD_N);

            m_uiStaticOverload_Timer = 5000 + rand()%1000;
        }
        else
            m_uiStaticOverload_Timer -= uiDiff;

        if (m_uiBallLightning_Timer < uiDiff)
        {
            DoCast(m_creature->getVictim(), m_bIsHeroic ? SPELL_BALL_LIGHTNING_H : SPELL_BALL_LIGHTNING_N);
            m_uiBallLightning_Timer = 10000 + rand()%1000;
        }
        else
            m_uiBallLightning_Timer -= uiDiff;

        // Health check
        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < (100-(20*m_uiHealthAmountModifier)))
        {
            ++m_uiHealthAmountModifier;

            switch(rand()%2)
            {
                case 0: DoScriptText(SAY_SPLIT_1, m_creature); break;
                case 1: DoScriptText(SAY_SPLIT_2, m_creature); break;
            }

            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(false);

            DoCast(m_creature, SPELL_DISPERSE);
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_ionar(Creature* pCreature)
{
    return new boss_ionarAI(pCreature);
}

bool EffectDummyCreature_boss_ionar(Unit* pCaster, uint32 uiSpellId, uint32 uiEffIndex, Creature* pCreatureTarget)
{
    //always check spellid and effectindex
    if (uiSpellId == SPELL_DISPERSE && uiEffIndex == 0)
    {
        if (pCreatureTarget->GetEntry() != NPC_IONAR)
            return true;

        for(uint8 i = 0; i < MAX_SPARKS; ++i)
        {
            pCreatureTarget->CastSpell(pCreatureTarget, SPELL_SUMMON_SPARK, true);

            //TODO: remove this line of hack when summon implemented
            pCreatureTarget->SummonCreature(NPC_SPARK_OF_IONAR, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
        }

        pCreatureTarget->AttackStop();
        pCreatureTarget->SetVisibility(VISIBILITY_OFF);

        if (pCreatureTarget->GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE)
            pCreatureTarget->GetMotionMaster()->MovementExpired();

        //always return true when we are handling this spell and effect
        return true;
    }
    return false;
}

/*######
## mob_spark_of_ionar
######*/

struct TRINITY_DLL_DECL mob_spark_of_ionarAI : public ScriptedAI
{
    mob_spark_of_ionarAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    void Reset() { }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (uiType != POINT_MOTION_TYPE || !m_pInstance)
            return;

        if (uiPointId == POINT_CALLBACK)
        {
            if (Creature* pIonar = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_IONAR)))
            {
                if (!pIonar->isAlive())
                {
                    m_creature->ForcedDespawn();
                    return;
                }

                if (boss_ionarAI* pIonarAI = dynamic_cast<boss_ionarAI*>(pIonar->AI()))
                    pIonarAI->RegisterSparkAtHome();
            }
            else
                m_creature->ForcedDespawn();
        }
    }
};

CreatureAI* GetAI_mob_spark_of_ionar(Creature* pCreature)
{
    return new mob_spark_of_ionarAI(pCreature);
}

void AddSC_boss_ionar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_ionar";
    newscript->GetAI = &GetAI_boss_ionar;
    newscript->pEffectDummyCreature = &EffectDummyCreature_boss_ionar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_spark_of_ionar";
    newscript->GetAI = &GetAI_mob_spark_of_ionar;
    newscript->RegisterSelf();
}

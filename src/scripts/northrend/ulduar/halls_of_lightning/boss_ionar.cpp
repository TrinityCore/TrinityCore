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
SD%Complete: 90%
SDComment: Timer check
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptedPch.h"
#include "halls_of_lightning.h"

enum eEnums
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
    MAX_SPARK_DISTANCE                      = 90,       // Distance to boss - prevent runs through the whole instance
    POINT_CALLBACK                          = 0
};

/*######
## Boss Ionar
######*/

struct boss_ionarAI : public ScriptedAI
{
    boss_ionarAI(Creature *pCreature) : ScriptedAI(pCreature), m_sparkList(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    SummonList m_sparkList;

    bool m_bIsSplitPhase;
    uint32 m_uiSplitTimer;

    uint32 m_uiStaticOverloadTimer;
    uint32 m_uiBallLightningTimer;

    uint32 m_uiHealthAmountModifier;

    void Reset()
    {
        m_sparkList.DespawnAll();

        m_bIsSplitPhase = true;
        m_uiSplitTimer = 25000;

        m_uiStaticOverloadTimer = urand(5000, 6000);
        m_uiBallLightningTimer = urand(10000, 11000);

        m_uiHealthAmountModifier = 1;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_DISABLE_MOVE);

        if (m_creature->GetVisibility() == VISIBILITY_OFF)
            m_creature->SetVisibility(VISIBILITY_ON);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_IONAR, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_IONAR, IN_PROGRESS);
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        m_sparkList.DespawnAll();

        if (m_pInstance)
            m_pInstance->SetData(TYPE_IONAR, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), m_creature);
    }

    //make sparks come back
    void CallBackSparks()
    {
        //should never be empty here, but check
        if (m_sparkList.empty())
            return;

        Position pos;
        m_creature->GetPosition(&pos);

        for (std::list<uint64>::const_iterator itr = m_sparkList.begin(); itr != m_sparkList.end(); ++itr)
        {
            if (Creature* pSpark = Unit::GetCreature(*m_creature, *itr))
            {
                if (pSpark->isAlive())
                {
                    pSpark->SetSpeed(MOVE_RUN, 2.0f);
                    pSpark->GetMotionMaster()->Clear();
                    pSpark->GetMotionMaster()->MovePoint(POINT_CALLBACK, pos);
                }
                else
                    pSpark->ForcedDespawn();
            }
        }
    }

    void DamageTaken(Unit *pDoneBy, uint32 &uiDamage)
    {
        if (m_creature->GetVisibility() == VISIBILITY_OFF)
            uiDamage = 0;
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == NPC_SPARK_OF_IONAR)
        {
            m_sparkList.Summon(pSummoned);

            pSummoned->CastSpell(pSummoned, DUNGEON_MODE(SPELL_SPARK_VISUAL_TRIGGER_N,SPELL_SPARK_VISUAL_TRIGGER_H), true);

            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (pTarget)
            {
                pSummoned->SetInCombatWith(pTarget);
                pSummoned->GetMotionMaster()->Clear();
                pSummoned->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
            }
        }
    }

    void SummonedCreatureDespawn(Creature *pSummoned)
    {
        if (pSummoned->GetEntry() == NPC_SPARK_OF_IONAR)
            m_sparkList.Despawn(pSummoned);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        // Splitted
        if (m_creature->GetVisibility() == VISIBILITY_OFF)
        {
            if (m_uiSplitTimer <= uiDiff)
            {
                m_uiSplitTimer = 2500;

                // Return sparks to where Ionar splitted
                if (m_bIsSplitPhase)
                {
                    CallBackSparks();
                    m_bIsSplitPhase = false;
                }
                // Lightning effect and restore Ionar
                else if (m_sparkList.empty())
                {
                    m_creature->SetVisibility(VISIBILITY_ON);
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_DISABLE_MOVE);

                    DoCast(m_creature, SPELL_SPARK_DESPAWN, false);

                    m_uiSplitTimer = 25000;
                    m_bIsSplitPhase = true;

                    if (m_creature->getVictim())
                        m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                }
            }
            else
                m_uiSplitTimer -= uiDiff;

            return;
        }

        if (m_uiStaticOverloadTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, DUNGEON_MODE(SPELL_STATIC_OVERLOAD_N, SPELL_STATIC_OVERLOAD_H));

            m_uiStaticOverloadTimer = urand(5000, 6000);
        }
        else
            m_uiStaticOverloadTimer -= uiDiff;

        if (m_uiBallLightningTimer <= uiDiff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_BALL_LIGHTNING_N, SPELL_BALL_LIGHTNING_H));
            m_uiBallLightningTimer = urand(10000, 11000);
        }
        else
            m_uiBallLightningTimer -= uiDiff;

        // Health check
        if (HealthBelowPct(100-(20*m_uiHealthAmountModifier)))
        {
            ++m_uiHealthAmountModifier;

            DoScriptText(RAND(SAY_SPLIT_1,SAY_SPLIT_2), m_creature);

            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(false);

            DoCast(m_creature, SPELL_DISPERSE, true);
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

        for (uint8 i = 0; i < MAX_SPARKS; ++i)
            pCreatureTarget->CastSpell(pCreatureTarget, SPELL_SUMMON_SPARK, true);

        pCreatureTarget->AttackStop();
        pCreatureTarget->SetVisibility(VISIBILITY_OFF);
        pCreatureTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_DISABLE_MOVE);

        pCreatureTarget->GetMotionMaster()->Clear();
        pCreatureTarget->GetMotionMaster()->MoveIdle();

        //always return true when we are handling this spell and effect
        return true;
    }
    return false;
}

/*######
## mob_spark_of_ionar
######*/

struct mob_spark_of_ionarAI : public ScriptedAI
{
    mob_spark_of_ionarAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* m_pInstance;

    uint32 uiCheckTimer;

    void Reset()
    {
        uiCheckTimer = 2000;
        m_creature->SetReactState(REACT_PASSIVE);
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (uiType != POINT_MOTION_TYPE || !m_pInstance)
            return;

        if (uiPointId == POINT_CALLBACK)
            m_creature->ForcedDespawn();
    }

    void DamageTaken(Unit *pDoneBy, uint32 &uiDamage)
    {
        uiDamage = 0;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        // Despawn if the encounter is not running
        if (m_pInstance && m_pInstance->GetData(TYPE_IONAR) != IN_PROGRESS)
        {
            m_creature->ForcedDespawn();
            return;
        }

        // Prevent them to follow players through the whole instance
        if (uiCheckTimer <= uiDiff)
        {
            if (m_pInstance)
            {
                Creature* pIonar = m_pInstance->instance->GetCreature(m_pInstance->GetData64(DATA_IONAR));
                if (pIonar && pIonar->isAlive())
                {
                    if (m_creature->GetDistance(pIonar) > MAX_SPARK_DISTANCE)
                    {
                        Position pos;
                        pIonar->GetPosition(&pos);

                        m_creature->SetSpeed(MOVE_RUN, 2.0f);
                        m_creature->GetMotionMaster()->Clear();
                        m_creature->GetMotionMaster()->MovePoint(POINT_CALLBACK, pos);
                    }
                }
                else
                    m_creature->ForcedDespawn();
            }
            uiCheckTimer = 2000;
        }
        else
            uiCheckTimer -= uiDiff;

        // No melee attack at all!
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

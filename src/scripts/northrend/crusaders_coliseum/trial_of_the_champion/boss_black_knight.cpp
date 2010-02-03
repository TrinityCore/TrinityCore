/*
 * Copyright (C) 2010 Trinity <http://www.trinitycore.org/>
 *
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
SDName: Boss Black Knight
SD%Complete: 80%
SDComment: missing yells. not sure about timers.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"
#include "trial_of_the_champion.h"

enum eSpells
{
    //phase 1
    SPELL_PLAGUE_STRIKE     = 67884,
    SPELL_PLAGUE_STRIKE_2   = 67724,
    SPELL_ICY_TOUCH_H       = 67881,
    SPELL_ICY_TOUCH         = 67718,
    SPELL_DEATH_RESPITE     = 67745,
    SPELL_DEATH_RESPITE_2   = 68306,
    SPELL_DEATH_RESPITE_3   = 66798,
    SPELL_OBLITERATE_H      = 67883,
    SPELL_OBLITERATE        = 67725,
    //in this phase should rise herald (the spell is missing)

    //phase 2 - During this phase, the Black Knight will use the same abilities as in phase 1, except for Death's Respite
    SPELL_ARMY_DEAD         = 67761,
    SPELL_DESECRATION       = 67778,
    SPELL_DESECRATION_2     = 67778,
    SPELL_GHOUL_EXPLODE     = 67751,

    //phase 3
    SPELL_DEATH_BITE_H      = 67875,
    SPELL_DEATH_BITE        = 67808,
    SPELL_MARKED_DEATH      = 67882,
    SPELL_MARKED_DEATH_2    = 67823,

    SPELL_BLACK_KNIGHT_RES  = 67693,

    SPELL_LEAP				= 67749,
    SPELL_LEAP_H			= 67880
};

enum eModels
{
     MODEL_SKELETON = 29846,
     MODEL_GHOST    = 21300
};

enum ePhases
{
    PHASE_UNDEAD    = 1,
    PHASE_SKELETON  = 2,
    PHASE_GHOST     = 3
};

struct TRINITY_DLL_DECL boss_black_knightAI : public ScriptedAI
{
    boss_black_knightAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    std::list<uint64> SummonList;

    bool bEventInProgress;
    bool bEvent;
    bool bSummonArmy;
    bool bDeathArmyDone;

    uint8 uiPhase;

    uint32 uiPlagueStrikeTimer;
    uint32 uiIcyTouchTimer;
    uint32 uiDeathRespiteTimer;
    uint32 uiObliterateTimer;
    uint32 uiDesecration;
    uint32 uiResurrectTimer;
    uint32 uiDeathArmyCheckTimer;
    uint32 uiGhoulExplodeTimer;
    uint32 uiDeathBiteTimer;
    uint32 uiMarkedDeathTimer;

    void Reset()
    {
        RemoveSummons();
        m_creature->SetDisplayId(m_creature->GetNativeDisplayId());
        m_creature->clearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);

        bEventInProgress = false;
        bEvent = false;
        bSummonArmy = false;
        bDeathArmyDone = false;

        uiPhase = PHASE_UNDEAD;

        uiIcyTouchTimer = urand(5000,9000);
        uiPlagueStrikeTimer = urand(10000,13000);
        uiDeathRespiteTimer = urand(15000,16000);
        uiObliterateTimer = urand(17000,19000);
        uiDesecration = urand(15000,16000);
        uiDeathArmyCheckTimer = 7000;
        uiResurrectTimer = 4000;
        uiGhoulExplodeTimer = 8000;
        uiDeathBiteTimer = urand (2000,4000);
        uiMarkedDeathTimer = urand (5000,7000);
    }

    void RemoveSummons()
    {
        if (SummonList.empty())
            return;

        for(std::list<uint64>::iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
        {
            if (Creature* pTemp = Unit::GetCreature(*m_creature, *itr))
                if (pTemp)
                    pTemp->DisappearAndDie();
        }
        SummonList.clear();
    }

    void JustSummoned(Creature* pSummon)
    {
        SummonList.push_back(pSummon->GetGUID());
        pSummon->AI()->AttackStart(m_creature->getVictim());
    }

    void UpdateAI(const uint32 uiDiff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (bEventInProgress)
            if (uiResurrectTimer <= uiDiff)
            {
                m_creature->SetHealth(m_creature->GetMaxHealth());
                DoCast(m_creature,SPELL_BLACK_KNIGHT_RES,true);
                uiPhase++;
                uiResurrectTimer = 4000;
                bEventInProgress = false;
                m_creature->clearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
            } else uiResurrectTimer -= uiDiff;

        switch(uiPhase)
        {
            case PHASE_UNDEAD:
            case PHASE_SKELETON:
            {
                if (uiIcyTouchTimer <= uiDiff)
                {
                    DoCastVictim(DUNGEON_MODE(SPELL_ICY_TOUCH,SPELL_ICY_TOUCH_H));
                    uiIcyTouchTimer = urand(5000,7000);
                } else uiIcyTouchTimer -= uiDiff;
                if (uiPlagueStrikeTimer <= uiDiff)
                {
                    DoCastVictim(DUNGEON_MODE(SPELL_ICY_TOUCH,SPELL_ICY_TOUCH_H));
                    uiPlagueStrikeTimer = urand(12000,15000);
                } else uiPlagueStrikeTimer -= uiDiff;
                if (uiObliterateTimer <= uiDiff)
                {
                    DoCastVictim(DUNGEON_MODE(SPELL_OBLITERATE,SPELL_OBLITERATE_H));
                    uiObliterateTimer = urand(17000,19000);
                } else uiObliterateTimer -= uiDiff;
                switch(uiPhase)
                {
                    case PHASE_UNDEAD:
                    {
                        if (uiDeathRespiteTimer <= uiDiff)
                        {
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                if (pTarget && pTarget->isAlive())
                                    DoCast(pTarget,SPELL_DEATH_RESPITE);
                            }
                            uiDeathRespiteTimer = urand(15000,16000);
                        } else uiDeathRespiteTimer -= uiDiff;
                        break;
                    }
                    case PHASE_SKELETON:
                    {
                        if (!bSummonArmy)
                        {
                            bSummonArmy = true;
                            m_creature->addUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                            DoCast(m_creature, SPELL_ARMY_DEAD);
                        }
                        if (!bDeathArmyDone)
                            if (uiDeathArmyCheckTimer <= uiDiff)
                            {
                                m_creature->clearUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
                                uiDeathArmyCheckTimer = 0;
                                bDeathArmyDone = true;
                            } else uiDeathArmyCheckTimer -= uiDiff;
                        if (uiDesecration <= uiDiff)
                        {
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            {
                                if (pTarget && pTarget->isAlive())
                                    DoCast(pTarget,SPELL_DESECRATION);
                            }
                            uiDesecration = urand(15000,16000);
                        } else uiDesecration -= uiDiff;
                        if (uiGhoulExplodeTimer <= uiDiff)
                        {
                            DoCast(m_creature, SPELL_GHOUL_EXPLODE);
                            uiGhoulExplodeTimer = 8000;
                        } else uiGhoulExplodeTimer -= uiDiff;
                        break;
                    }
                    break;
                }
                break;
            }
            case PHASE_GHOST:
            {
                if (uiDeathBiteTimer <= uiDiff)
                {
                    DoCastAOE(DUNGEON_MODE(SPELL_DEATH_BITE,SPELL_DEATH_BITE_H));
                    uiDeathBiteTimer = urand (2000, 4000);
                } else uiDeathBiteTimer -= uiDiff;
                if (uiMarkedDeathTimer <= uiDiff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        if (pTarget && pTarget->isAlive())
                            DoCast(pTarget,SPELL_MARKED_DEATH);
                    }
                    uiMarkedDeathTimer = urand (5000, 7000);
                } else uiMarkedDeathTimer -= uiDiff;
                break;
            }
        }

        if (!m_creature->hasUnitState(UNIT_STAT_ROOT) && !m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 0)
            DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
    {
        if (uiDamage > m_creature->GetHealth() && uiPhase <= PHASE_SKELETON)
        {
            uiDamage = 0;
            m_creature->SetHealth(0);
            m_creature->addUnitState(UNIT_STAT_ROOT | UNIT_STAT_STUNNED);
            RemoveSummons();
            switch(uiPhase)
            {
                case PHASE_UNDEAD:
                    m_creature->SetDisplayId(MODEL_SKELETON);
                    break;
                case PHASE_SKELETON:
                    m_creature->SetDisplayId(MODEL_GHOST);
                    break;
            }
            bEventInProgress = true;
        }
    }

    void JustDied(Unit* pKiller)
    {
        if (pInstance)
            pInstance->SetData(BOSS_BLACK_KNIGHT,DONE);
    }
};

CreatureAI* GetAI_boss_black_knight(Creature *pCreature)
{
    return new boss_black_knightAI (pCreature);
}

struct TRINITY_DLL_DECL npc_risen_ghoulAI : public ScriptedAI
{
    npc_risen_ghoulAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 uiAttackTimer;

    void Reset()
    {
        uiAttackTimer = 3500;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (uiAttackTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
            {
                if (pTarget && pTarget->isAlive())
                DoCast(pTarget, (DUNGEON_MODE(SPELL_LEAP,SPELL_LEAP_H)));
            }
            uiAttackTimer = 3500;
        } else uiAttackTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_risen_ghoul(Creature* pCreature)
{
    return new npc_risen_ghoulAI(pCreature);
}

struct TRINITY_DLL_DECL npc_black_knight_skeletal_gryphonAI : public npc_escortAI
{
    npc_black_knight_skeletal_gryphonAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Start(false,true,0,NULL);
    }

    void WaypointReached(uint32 i)
    {

    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (!UpdateVictim())
            return;
    }

};

CreatureAI* GetAI_npc_black_knight_skeletal_gryphon(Creature* pCreature)
{
    return new npc_black_knight_skeletal_gryphonAI(pCreature);
}

void AddSC_boss_black_knight()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "boss_black_knight";
    NewScript->GetAI = &GetAI_boss_black_knight;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "npc_risen_ghoul";
    NewScript->GetAI = &GetAI_npc_risen_ghoul;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "npc_black_knight_skeletal_gryphon";
    NewScript->GetAI = &GetAI_npc_black_knight_skeletal_gryphon;
    NewScript->RegisterSelf();
}

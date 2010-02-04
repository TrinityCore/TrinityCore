/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
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
SDName: Argent Challenge Encounter.
SD%Complete: 50 %
SDComment: AI for Argent Soldiers are not implemented. AI from bosses need more improvements.
SDCategory: Trial of the Champion
EndScriptData */

#include "ScriptedPch.h"
#include "trial_of_the_champion.h"
#include "ScriptedEscortAI.h"

enum eSpells
{
    //Eadric
    SPELL_EADRIC_ACHIEVEMENT    = 68197,
    SPELL_HAMMER_JUSTICE        = 66863,
    SPELL_HAMMER_RIGHTEOUS      = 66867,
    SPELL_RADIANCE              = 66935,
    SPELL_VENGEANCE             = 66865,

    //Paletress
    SPELL_SMITE                 = 66536,
    SPELL_SMITE_H               = 67674,
    SPELL_HOLY_FIRE             = 66538,
    SPELL_HOLY_FIRE_H           = 67676,
    SPELL_RENEW                 = 66537,
    SPELL_RENEW_H               = 67675,
    SPELL_HOLY_NOVA             = 66546,
    SPELL_SHIELD                = 66515,
    SPELL_CONFESS               = 66680,
    SPELL_SUMMON_MEMORY         = 66545,

    //Memory
    SPELL_OLD_WOUNDS            = 66620,
    SPELL_OLD_WOUNDS_H          = 67679,
    SPELL_SHADOWS_PAST          = 66619,
    SPELL_SHADOWS_PAST_H        = 67678,
    SPELL_WAKING_NIGHTMARE      = 66552,
    SPELL_WAKING_NIGHTMARE_H    = 67677
};

struct boss_eadricAI : public ScriptedAI
{
    boss_eadricAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
        pCreature->SetReactState(REACT_PASSIVE);
        pCreature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
    }

    ScriptedInstance* pInstance;

    uint32 uiVenganceTimer;
    uint32 uiRadianceTimer;
    uint32 uiHammerJusticeTimer;
    uint32 uiResetTimer;

    bool bDone;

    void Reset()
    {
        uiVenganceTimer = 10000;
        uiRadianceTimer = 16000;
        uiHammerJusticeTimer = 25000;
        uiResetTimer = 5000;

        bDone = false;
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (damage >= m_creature->GetHealth())
        {
            damage = 0;
            EnterEvadeMode();
            m_creature->setFaction(35);
            bDone = true;
        }
    }

    void MovementInform(uint32 MovementType, uint32 Data)
    {
        if (MovementType != POINT_MOTION_TYPE)
            return;

        if (pInstance)
            pInstance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);

        m_creature->DisappearAndDie();
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (bDone && uiResetTimer <= uiDiff)
        {
            m_creature->GetMotionMaster()->MovePoint(0,746.87,665.87,411.75);
            bDone = false;
        } else uiResetTimer -= uiDiff;

        if (!UpdateVictim())
            return;

        if (uiHammerJusticeTimer <= uiDiff)
        {
            m_creature->InterruptNonMeleeSpells(true);

            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
            {
                if (pTarget && pTarget->isAlive())
                {
                    DoCast(pTarget, SPELL_HAMMER_JUSTICE);
                    DoCast(pTarget, SPELL_HAMMER_RIGHTEOUS);
                }
            }
            uiHammerJusticeTimer = 25000;
        } else uiHammerJusticeTimer -= uiDiff;

        if (uiVenganceTimer <= uiDiff)
        {
            DoCast(m_creature,SPELL_VENGEANCE);

            uiVenganceTimer = 10000;
        } else uiVenganceTimer -= uiDiff;

        if (uiRadianceTimer <= uiDiff)
        {
            DoCastAOE(SPELL_RADIANCE);

            uiRadianceTimer = 16000;
        } else uiRadianceTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_eadric(Creature* pCreature)
{
    return new boss_eadricAI(pCreature);
}

struct boss_paletressAI : public ScriptedAI
{
    boss_paletressAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();

        pMemory = NULL;
        pCreature->SetReactState(REACT_PASSIVE);
        pCreature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
        pCreature->RestoreFaction();
    }

    ScriptedInstance* pInstance;

    Creature* pMemory;

    bool bHealth;
    bool bDone;

    uint32 uiHolyFireTimer;
    uint32 uiHolySmiteTimer;
    uint32 uiRenewTimer;
    uint32 uiResetTimer;

    void Reset()
    {
        m_creature->RemoveAllAuras();

        uiHolyFireTimer     = urand(9000,12000);
        uiHolySmiteTimer    = urand(5000,7000);
        uiRenewTimer        = urand(2000,5000);

        uiResetTimer        = 7000;

        bHealth = false;
        bDone = false;

        if (pMemory && pMemory->isAlive())
            pMemory->RemoveFromWorld();
    }

    void SetData(uint32 uiId, uint32 uiValue)
    {
        if (uiId == 1)
            m_creature->RemoveAura(SPELL_SHIELD);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (damage >= m_creature->GetHealth())
        {
            damage = 0;
            EnterEvadeMode();
            m_creature->setFaction(35);
            bDone = true;
        }
    }

    void MovementInform(uint32 MovementType, uint32 Data)
    {
        if (MovementType != POINT_MOTION_TYPE)
            return;

        if (pInstance)
            pInstance->SetData(BOSS_ARGENT_CHALLENGE_P, DONE);

        m_creature->DisappearAndDie();
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (bDone && uiResetTimer <= uiDiff)
        {
            m_creature->GetMotionMaster()->MovePoint(0,746.87,665.87,411.75);
            bDone = false;
        } else uiResetTimer -= uiDiff;

        if (!UpdateVictim())
            return;

        if (uiHolyFireTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget,DUNGEON_MODE(SPELL_HOLY_FIRE,SPELL_HOLY_FIRE_H));
            }
             if (m_creature->HasAura(SPELL_SHIELD))
                uiHolyFireTimer = 13000;
            else
                uiHolyFireTimer = urand(9000,12000);
        } else uiHolyFireTimer -= uiDiff;

        if (uiHolySmiteTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 250, true))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget,DUNGEON_MODE(SPELL_SMITE,SPELL_SMITE_H));
            }
            if (m_creature->HasAura(SPELL_SHIELD))
                uiHolySmiteTimer = 9000;
            else
                uiHolySmiteTimer = urand(5000,7000);
        } else uiHolySmiteTimer -= uiDiff;

        if (m_creature->HasAura(SPELL_SHIELD))
            if (uiRenewTimer <= uiDiff)
            {
                m_creature->InterruptNonMeleeSpells(true);
                uint8 uiTarget = urand(0,1);
                switch(uiTarget)
                {
                    case 0:
                        DoCast(m_creature,DUNGEON_MODE(SPELL_RENEW,SPELL_RENEW_H));
                        break;
                    case 1:
                        if (pMemory && pMemory->isAlive())
                            DoCast(pMemory,DUNGEON_MODE(SPELL_RENEW,SPELL_RENEW_H));
                        break;
                }
                uiRenewTimer = urand(15000,17000);
            } else uiRenewTimer -= uiDiff;


        if (!bHealth && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 25)
        {
            m_creature->InterruptNonMeleeSpells(true);
            DoCastAOE(SPELL_HOLY_NOVA,false);
            DoCast(m_creature, SPELL_SHIELD);
            DoCastAOE(SPELL_SUMMON_MEMORY,false);
            DoCastAOE(SPELL_CONFESS,false);

            bHealth = true;
        }

        DoMeleeAttackIfReady();
    }

    void JustSummoned(Creature* pSummon)
    {
        pMemory = pSummon;
    }
};

CreatureAI* GetAI_boss_paletress(Creature* pCreature)
{
    return new boss_paletressAI(pCreature);
}

struct npc_memoryAI : public ScriptedAI
{
    npc_memoryAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 uiOldWoundsTimer;
    uint32 uiShadowPastTimer;
    uint32 uiWakingNightmare;

    void Reset()
    {
        uiOldWoundsTimer = 12000;
        uiShadowPastTimer = 5000;
        uiWakingNightmare = 7000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (uiOldWoundsTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget, DUNGEON_MODE(SPELL_OLD_WOUNDS,SPELL_OLD_WOUNDS_H));
            }
            uiOldWoundsTimer = 12000;
        }else uiOldWoundsTimer -= uiDiff;

        if (uiWakingNightmare <= uiDiff)
        {
            DoCast(m_creature, DUNGEON_MODE(SPELL_WAKING_NIGHTMARE,SPELL_WAKING_NIGHTMARE_H));
            uiWakingNightmare = 7000;
        }else uiWakingNightmare -= uiDiff;

        if (uiShadowPastTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget,DUNGEON_MODE(SPELL_SHADOWS_PAST,SPELL_SHADOWS_PAST_H));
            }
            uiShadowPastTimer = 5000;
        }else uiShadowPastTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (m_creature->isSummon())
        {
            if (Unit* pSummoner = CAST_SUM(m_creature)->GetSummoner())
            {
                if (pSummoner && pSummoner->isAlive())
                    CAST_CRE(pSummoner)->AI()->SetData(1,0);
            }
        }
    }
};

CreatureAI* GetAI_npc_memory(Creature* pCreature)
{
    return new npc_memoryAI(pCreature);
}

// THIS AI NEEDS MORE IMPROVEMENTS
struct npc_argent_soldierAI : public npc_escortAI
{
    npc_argent_soldierAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
        m_creature->SetReactState(REACT_DEFENSIVE);
        SetDespawnAtEnd(false);
        uiWaypoint = 0;
    }

    ScriptedInstance* pInstance;

    uint8 uiWaypoint;

    void WaypointReached(uint32 uiPoint)
    {
        if (uiPoint == 0)
        {
            switch(uiWaypoint)
            {
                case 0:
                    m_creature->SetOrientation(5.81);
                    break;
                case 1:
                    m_creature->SetOrientation(4.60);
                    break;
                case 2:
                    m_creature->SetOrientation(2.79);
                    break;
            }

            m_creature->SendMovementFlagUpdate();
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(m_creature->GetEntry())
        {
            case NPC_ARGENT_LIGHWIELDER:
                switch(uiType)
                {
                    case 0:
                        AddWaypoint(0,712.14,628.42,411.88);
                        break;
                    case 1:
                        AddWaypoint(0,742.44,650.29,411.79);
                        break;
                    case 2:
                        AddWaypoint(0,783.33,615.29,411.84);
                        break;
                }
                break;
            case NPC_ARGENT_MONK:
                switch(uiType)
                {
                    case 0:
                        AddWaypoint(0,713.12,632.97,411.90);
                        break;
                    case 1:
                        AddWaypoint(0,746.73,650.24,411.56);
                        break;
                    case 2:
                        AddWaypoint(0,781.32,610.54,411.82);
                        break;
                }
                break;
            case NPC_PRIESTESS:
                switch(uiType)
                {
                    case 0:
                        AddWaypoint(0,715.06,637.07,411.91);
                        break;
                    case 1:
                        AddWaypoint(0,750.72,650.20,411.77);
                        break;
                    case 2:
                        AddWaypoint(0,779.77,607.03,411.81);
                        break;
                }
                break;
        }

        Start(false,true,0);
        uiWaypoint = uiType;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pInstance)
            pInstance->SetData(DATA_ARGENT_SOLDIER_DEFEATED,pInstance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
    }
};

CreatureAI* GetAI_npc_argent_soldier(Creature* pCreature)
{
    return new npc_argent_soldierAI(pCreature);
}

void AddSC_boss_argent_challenge()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "boss_eadric";
    NewScript->GetAI = &GetAI_boss_eadric;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "boss_paletress";
    NewScript->GetAI = &GetAI_boss_paletress;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "npc_memory";
    NewScript->GetAI = &GetAI_npc_memory;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "npc_argent_soldier";
    NewScript->GetAI = &GetAI_npc_argent_soldier;
    NewScript->RegisterSelf();
}

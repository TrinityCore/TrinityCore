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
SDName: Boss_Onyxia
Editedby LordVanLuther
SD%Complete: 65
SDComment: Phase 3 need additianal code. Phase 2 requires entries in spell_target_position with specific locations. See bottom of file.
SDCategory: Onyxia's Lair
EndScriptData */

#include "precompiled.h"

enum
{
    SAY_AGGRO                   = -1249000,
    SAY_KILL                    = -1249001,
    SAY_PHASE_2_TRANS           = -1249002,
    SAY_PHASE_3_TRANS           = -1249003,
    EMOTE_BREATH                = -1249004,

    SPELL_WINGBUFFET            = 18500,
    SPELL_FLAMEBREATH           = 18435,
    SPELL_CLEAVE                = 19983,
    SPELL_TAILSWEEP             = 15847,
    SPELL_KNOCK_AWAY            = 19633,

    SPELL_ENGULFINGFLAMES       = 20019,
    SPELL_DEEPBREATH            = 23461,
    SPELL_FIREBALL              = 18392,

    //Not much choise about these. We have to make own defintion on the direction/start-end point
    //SPELL_BREATH_NORTH_TO_SOUTH = 17086,                  // 20x in "array"
    //SPELL_BREATH_SOUTH_TO_NORTH = 18351,                  // 11x in "array"

    SPELL_BREATH_EAST_TO_WEST   = 18576,                    // 7x in "array"
    SPELL_BREATH_WEST_TO_EAST   = 18609,                    // 7x in "array"

    SPELL_BREATH_SE_TO_NW       = 18564,                    // 12x in "array"
    SPELL_BREATH_NW_TO_SE       = 18584,                    // 12x in "array"
    SPELL_BREATH_SW_TO_NE       = 18596,                    // 12x in "array"
    SPELL_BREATH_NE_TO_SW       = 18617,                    // 12x in "array"

    //SPELL_BREATH                = 21131,                  // 8x in "array", different initial cast than the other arrays

    SPELL_BELLOWINGROAR         = 18431,
    SPELL_HEATED_GROUND         = 22191,

    SPELL_SUMMONWHELP           = 17646,
    NPC_WHELP                   = 11262,
    MAX_WHELP                   = 16,

    PHASE_START                 = 1,
    PHASE_BREATH                = 2,
    PHASE_END                   = 3
};

struct sOnyxMove
{
    uint32 uiLocId;
    uint32 uiLocIdEnd;
    uint32 uiSpellId;
    float fX, fY, fZ;
};

static sOnyxMove aMoveData[]=
{
    {0, 1, SPELL_BREATH_WEST_TO_EAST,   -33.5561f, -182.682f, -60.9457f},//west
    {1, 0, SPELL_BREATH_EAST_TO_WEST,   -31.4963f, -250.123f, -60.1278f},//east
    {2, 4, SPELL_BREATH_NW_TO_SE,         6.8951f, -180.246f, -60.896f},//north-west
    {3, 5, SPELL_BREATH_NE_TO_SW,        10.2191f, -247.912f, -60.896f},//north-east
    {4, 2, SPELL_BREATH_SE_TO_NW,       -63.5156f, -240.096f, -60.477f},//south-east
    {5, 3, SPELL_BREATH_SW_TO_NE,       -58.2509f, -189.020f, -60.790f},//south-west
    //{6, 7, SPELL_BREATH_SOUTH_TO_NORTH, -65.8444f, -213.809f, -60.2985f},//south
    //{7, 6, SPELL_BREATH_NORTH_TO_SOUTH,  22.8763f, -217.152f, -60.0548f},//north
};

static float afSpawnLocations[2][3]=
{
    {-30.127, -254.463, -89.440},
    {-30.817, -177.106, -89.258}
};

struct TRINITY_DLL_DECL boss_onyxiaAI : public ScriptedAI
{
    boss_onyxiaAI(Creature* pCreature) : ScriptedAI(pCreature) {Reset();}

    uint32 m_uiPhase;

    uint32 m_uiFlameBreathTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiTailSweepTimer;
    uint32 m_uiWingBuffetTimer;

    uint32 m_uiMovePoint;
    uint32 m_uiMovementTimer;
    sOnyxMove* m_pPointData;

    uint32 m_uiEngulfingFlamesTimer;
    uint32 m_uiSummonWhelpsTimer;
    uint32 m_uiBellowingRoarTimer;
    uint32 m_uiWhelpTimer;

    uint8 m_uiSummonCount;
    bool m_bIsSummoningWhelps;

    void Reset()
    {
        if (!IsCombatMovement())
            SetCombatMovement(true);

        m_uiPhase = PHASE_START;

        m_uiFlameBreathTimer = urand(10000, 20000);
        m_uiTailSweepTimer = urand(15000, 20000);
        m_uiCleaveTimer = urand(2000, 5000);
        m_uiWingBuffetTimer = urand(10000, 20000);

        m_uiMovePoint = urand(0, 5);
        m_uiMovementTimer = 20000;
        m_pPointData = GetMoveData();

        m_uiEngulfingFlamesTimer = 15000;
        m_uiSummonWhelpsTimer = 45000;
        m_uiBellowingRoarTimer = 30000;
        m_uiWhelpTimer = 1000;

        m_uiSummonCount = 0;
        m_bIsSummoningWhelps = false;
    }

    void Aggro(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->SetInCombatWithZone();
    }

    void JustSummoned(Creature *pSummoned)
    {
        if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
            pSummoned->AI()->AttackStart(pTarget);

        ++m_uiSummonCount;
    }

    void KilledUnit(Unit* pVictim)
    {
        DoScriptText(SAY_KILL, m_creature);
    }

    void SpellHit(Unit *pCaster, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_BREATH_EAST_TO_WEST ||
            pSpell->Id == SPELL_BREATH_WEST_TO_EAST ||
            pSpell->Id == SPELL_BREATH_SE_TO_NW ||
            pSpell->Id == SPELL_BREATH_NW_TO_SE ||
            pSpell->Id == SPELL_BREATH_SW_TO_NE ||
            pSpell->Id == SPELL_BREATH_NE_TO_SW)
        {
            if (m_pPointData)
            {
                m_creature->GetMap()->CreatureRelocation(m_creature, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ, 0.0f);
                m_creature->GetMotionMaster()->MovePoint(0, -10.6155, -219.357, -87.7344);
                
            }
        }
    }

    sOnyxMove* GetMoveData()
    {
        uint32 uiMaxCount = sizeof(aMoveData)/sizeof(sOnyxMove);

        for (uint32 i = 0; i < uiMaxCount; ++i)
        {
            if (aMoveData[i].uiLocId == m_uiMovePoint)
                return &aMoveData[i];
        }

        return NULL;
    }

    void SetNextRandomPoint()
    {
        uint32 uiMaxCount = sizeof(aMoveData)/sizeof(sOnyxMove);

        int iTemp = rand()%(uiMaxCount-1);

        if (iTemp >= m_uiMovePoint)
            ++iTemp;

        m_uiMovePoint = iTemp;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (m_uiPhase == PHASE_START || m_uiPhase == PHASE_END)
        {
            if (m_uiFlameBreathTimer < uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_FLAMEBREATH);
                m_uiFlameBreathTimer = urand(10000, 20000);
            }
            else
                m_uiFlameBreathTimer -= uiDiff;

            if (m_uiTailSweepTimer < uiDiff)
            {
                DoCast(m_creature, SPELL_TAILSWEEP);
                m_uiTailSweepTimer = urand(15000, 20000);
            }
            else
                m_uiTailSweepTimer -= uiDiff;

            if (m_uiCleaveTimer < uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                m_uiCleaveTimer = urand(2000, 5000);
            }
            else
                m_uiCleaveTimer -= uiDiff;

            if (m_uiWingBuffetTimer < uiDiff)
            {
                DoCast(m_creature->getVictim(), SPELL_WINGBUFFET);
                m_uiWingBuffetTimer = urand(15000, 30000);
            }
            else
                m_uiWingBuffetTimer -= uiDiff;

            if (m_uiPhase == PHASE_END)
            {
                if (m_uiBellowingRoarTimer < uiDiff)
                {
                    DoCast(m_creature->getVictim(), SPELL_BELLOWINGROAR);
                    m_uiBellowingRoarTimer = 30000;
                }
                else
                    m_uiBellowingRoarTimer -= uiDiff;
            }
            else
            {
                if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 60)
                {
                    m_uiPhase = PHASE_BREATH;

                    SetCombatMovement(false);

                    m_creature->GetMotionMaster()->Clear(false);
                    m_creature->GetMotionMaster()->MoveIdle();

                    DoScriptText(SAY_PHASE_2_TRANS, m_creature);

                    if (m_pPointData)
                        m_creature->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ);

                    SetNextRandomPoint();
                    return;
                }
            }

            DoMeleeAttackIfReady();
        }
        else
        {
            if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 40)
            {
                m_uiPhase = PHASE_END;
                DoScriptText(SAY_PHASE_3_TRANS, m_creature);

                SetCombatMovement(true);
                m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());

                return;
            }

            if (m_uiMovementTimer < uiDiff)
            {
                m_pPointData = GetMoveData();

                SetNextRandomPoint();

                m_uiMovementTimer = 25000;

                if (!m_pPointData)
                    return;

                if (m_uiMovePoint == m_pPointData->uiLocIdEnd)
                {
                    if (m_creature->IsNonMeleeSpellCasted(false))
                        m_creature->InterruptNonMeleeSpells(false);

                    DoScriptText(EMOTE_BREATH, m_creature);
                    DoCast(m_creature, m_pPointData->uiSpellId);
                }
                else
                {
                    m_creature->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ);
                }
            }
            else
                m_uiMovementTimer -= uiDiff;

            if (m_uiEngulfingFlamesTimer < uiDiff)
            {
                if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE)
                {
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_FIREBALL);

                    m_uiEngulfingFlamesTimer = 8000;
                }
            }
            else
                m_uiEngulfingFlamesTimer -= uiDiff;           //engulfingflames is supposed to be activated by a fireball but haven't come by

            if (m_bIsSummoningWhelps)
            {
                if (m_uiSummonCount < MAX_WHELP)
                {
                    if (m_uiWhelpTimer < uiDiff)
                    {
                        m_creature->SummonCreature(NPC_WHELP, afSpawnLocations[0][0], afSpawnLocations[0][1], afSpawnLocations[0][2], 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                        m_creature->SummonCreature(NPC_WHELP, afSpawnLocations[1][0], afSpawnLocations[1][1], afSpawnLocations[1][2], 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                        m_uiWhelpTimer = 1000;
                    }
                    else
                        m_uiWhelpTimer -= uiDiff;
                }
                else
                {
                    m_bIsSummoningWhelps = false;
                    m_uiSummonCount = 0;
                    m_uiSummonWhelpsTimer = 30000;
                }
            }
            else
            {
                if (m_uiSummonWhelpsTimer < uiDiff)
                    m_bIsSummoningWhelps = true;
                else
                    m_uiSummonWhelpsTimer -= uiDiff;
            }
        }
    }
};

CreatureAI* GetAI_boss_onyxiaAI(Creature* pCreature)
{
    return new boss_onyxiaAI (pCreature);
}

void AddSC_boss_onyxia()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_onyxia";
    newscript->GetAI = &GetAI_boss_onyxiaAI;
    newscript->RegisterSelf();
}

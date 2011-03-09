/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Onyxia
SD%Complete: 95
SDComment: <Known bugs>
               Ground visual for Deep Breath effect;
               Not summoning whelps on phase 3 (lacks info)
           </Known bugs>
SDCategory: Onyxia's Lair
EndScriptData */

#include "ScriptPCH.h"
#include "onyxias_lair.h"

enum eYells
{
    SAY_AGGRO                   = -1249000,
    SAY_KILL                    = -1249001,
    SAY_PHASE_2_TRANS           = -1249002,
    SAY_PHASE_3_TRANS           = -1249003,
    EMOTE_BREATH                = -1249004,
};

enum eSpells
{
    // Phase 1 spells
    SPELL_WING_BUFFET           = 18500,
    SPELL_FLAME_BREATH          = 18435,
    SPELL_CLEAVE                = 68868,
    SPELL_TAIL_SWEEP            = 68867,

    // Phase 2 spells
    SPELL_DEEP_BREATH           = 23461,
    SPELL_FIREBALL              = 18392,

    //Not much choise about these. We have to make own defintion on the direction/start-end point
    SPELL_BREATH_NORTH_TO_SOUTH = 17086,                    // 20x in "array"
    SPELL_BREATH_SOUTH_TO_NORTH = 18351,                    // 11x in "array"

    SPELL_BREATH_EAST_TO_WEST   = 18576,                    // 7x in "array"
    SPELL_BREATH_WEST_TO_EAST   = 18609,                    // 7x in "array"

    SPELL_BREATH_SE_TO_NW       = 18564,                    // 12x in "array"
    SPELL_BREATH_NW_TO_SE       = 18584,                    // 12x in "array"
    SPELL_BREATH_SW_TO_NE       = 18596,                    // 12x in "array"
    SPELL_BREATH_NE_TO_SW       = 18617,                    // 12x in "array"

    //SPELL_BREATH                = 21131,                  // 8x in "array", different initial cast than the other arrays

    // Phase 3 spells
    SPELL_BELLOWING_ROAR         = 18431,
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
    {0, 1, SPELL_BREATH_WEST_TO_EAST,   -33.5561f, -182.682f, -56.9457f},//west
    {1, 0, SPELL_BREATH_EAST_TO_WEST,   -31.4963f, -250.123f, -55.1278f},//east
    {2, 4, SPELL_BREATH_NW_TO_SE,         6.8951f, -180.246f, -55.896f},//north-west
    {3, 5, SPELL_BREATH_NE_TO_SW,        10.2191f, -247.912f, -55.896f},//north-east
    {4, 2, SPELL_BREATH_SE_TO_NW,       -63.5156f, -240.096f, -55.477f},//south-east
    {5, 3, SPELL_BREATH_SW_TO_NE,       -58.2509f, -189.020f, -55.790f},//south-west
    {6, 7, SPELL_BREATH_SOUTH_TO_NORTH, -65.8444f, -213.809f, -55.2985f},//south
    {7, 6, SPELL_BREATH_NORTH_TO_SOUTH,  22.8763f, -217.152f, -55.0548f},//north
};

const Position MiddleRoomLocation = {-23.6155f, -215.357f, -55.7344f, 0.0f};

const Position Phase2Location = {-80.924f, -214.299f, -82.942f, 0.0f};

static Position aSpawnLocations[3]=
{
    //Whelps
    {-30.127f, -254.463f, -89.440f, 0.0f},
    {-30.817f, -177.106f, -89.258f, 0.0f},
    //Lair Guard
    {-145.950f, -212.831f, -68.659f, 0.0f}
};

class boss_onyxia : public CreatureScript
{
public:
    boss_onyxia() : CreatureScript("boss_onyxia") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_onyxiaAI (pCreature);
    }

    struct boss_onyxiaAI : public ScriptedAI
    {
        boss_onyxiaAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            m_pInstance = pCreature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;
        SummonList Summons;

        uint32 m_uiPhase;

        uint32 m_uiFlameBreathTimer;
        uint32 m_uiCleaveTimer;
        uint32 m_uiTailSweepTimer;
        uint32 m_uiWingBuffetTimer;

        uint32 m_uiMovePoint;
        uint32 m_uiMovementTimer;
        sOnyxMove* m_pPointData;

        uint32 m_uiFireballTimer;
        uint32 m_uiWhelpTimer;
        uint32 m_uiLairGuardTimer;
        uint32 m_uiDeepBreathTimer;

        uint32 m_uiBellowingRoarTimer;

        uint8 m_uiSummonWhelpCount;
        bool m_bIsMoving;

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
            m_uiMovementTimer = 14000;
            m_pPointData = GetMoveData();

            m_uiFireballTimer = 15000;
            m_uiWhelpTimer = 60000;
            m_uiLairGuardTimer = 60000;
            m_uiDeepBreathTimer = 85000;

            m_uiBellowingRoarTimer = 30000;

            Summons.DespawnAll();
            m_uiSummonWhelpCount = 0;
            m_bIsMoving = false;

            if (m_pInstance)
            {
                m_pInstance->SetData(DATA_ONYXIA, NOT_STARTED);
                m_pInstance->SetData(DATA_ONYXIA_PHASE, m_uiPhase);
                m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  ACHIEV_TIMED_START_EVENT);
            }
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_AGGRO, me);
            me->SetInCombatWithZone();

            if (m_pInstance)
            {
                m_pInstance->SetData(DATA_ONYXIA, IN_PROGRESS);
                m_pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  ACHIEV_TIMED_START_EVENT);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (m_pInstance)
                m_pInstance->SetData(DATA_ONYXIA, DONE);

            Summons.DespawnAll();
        }

        void JustSummoned(Creature *pSummoned)
        {
            pSummoned->SetInCombatWithZone();
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                pSummoned->AI()->AttackStart(pTarget);

            switch (pSummoned->GetEntry())
            {
                case NPC_WHELP:
                    ++m_uiSummonWhelpCount;
                    break;
                case NPC_LAIRGUARD:
                    pSummoned->setActive(true);
                    break;
            }
            Summons.Summon(pSummoned);
        }

        void SummonedCreatureDespawn(Creature *summon)
        {
            Summons.Despawn(summon);
        }

        void KilledUnit(Unit* /*pVictim*/)
        {
            DoScriptText(SAY_KILL, me);
        }

        void SpellHit(Unit * /*pCaster*/, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_BREATH_EAST_TO_WEST ||
                pSpell->Id == SPELL_BREATH_WEST_TO_EAST ||
                pSpell->Id == SPELL_BREATH_SE_TO_NW ||
                pSpell->Id == SPELL_BREATH_NW_TO_SE ||
                pSpell->Id == SPELL_BREATH_SW_TO_NE ||
                pSpell->Id == SPELL_BREATH_NE_TO_SW)
            {
                m_pPointData = GetMoveData();
                m_uiMovePoint = m_pPointData->uiLocIdEnd;

                me->SetSpeed(MOVE_FLIGHT, 1.5f);
                me->GetMotionMaster()->MovePoint(8, MiddleRoomLocation);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case 8:
                        m_pPointData = GetMoveData();
                        if (m_pPointData)
                        {
                            me->SetSpeed(MOVE_FLIGHT, 1.0f);
                            me->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ);
                        }
                        break;
                    case 9:
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                        m_uiBellowingRoarTimer = 1000;
                        break;
                    case 10:
                        me->SetFlying(true);
                        me->GetMotionMaster()->MovePoint(11, Phase2Location.GetPositionX(),Phase2Location.GetPositionY(),Phase2Location.GetPositionZ()+25);
                        me->SetSpeed(MOVE_FLIGHT, 1.0f);
                        DoScriptText(SAY_PHASE_2_TRANS, me);
                        if (m_pInstance)
                            m_pInstance->SetData(DATA_ONYXIA_PHASE, m_uiPhase);
                        m_uiWhelpTimer = 5000;
                        m_uiLairGuardTimer = 15000;
                        break;
                    case 11:
                        if (m_pPointData)
                            me->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ);
                        me->GetMotionMaster()->Clear(false);
                        me->GetMotionMaster()->MoveIdle();

                        break;

                    default:
                        m_bIsMoving = false;
                        break;
                }
            }
        }

        void SpellHitTarget(Unit* target, const SpellEntry* pSpell)
        {
            //Workaround - Couldn't find a way to group this spells (All Eruption)
            if (((pSpell->Id >= 17086 && pSpell->Id <= 17095) ||
                (pSpell->Id == 17097) ||
                (pSpell->Id >= 18351 && pSpell->Id <= 18361) ||
                (pSpell->Id >= 18564 && pSpell->Id <= 18576) ||
                (pSpell->Id >= 18578 && pSpell->Id <= 18607) ||
                (pSpell->Id == 18609) ||
                (pSpell->Id >= 18611 && pSpell->Id <= 18628) ||
                (pSpell->Id >= 21132 && pSpell->Id <= 21133) ||
                (pSpell->Id >= 21135 && pSpell->Id <= 21139) ||
                (pSpell->Id >= 22191 && pSpell->Id <= 22202) ||
                (pSpell->Id >= 22267 && pSpell->Id <= 22268)) &&
                (target->GetTypeId() == TYPEID_PLAYER))
            {
                if (m_pInstance)
                {
                    m_pInstance->SetData(DATA_SHE_DEEP_BREATH_MORE, FAIL);
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

            uint32 iTemp = rand()%(uiMaxCount-1);

            if (iTemp >= m_uiMovePoint)
                ++iTemp;

            m_uiMovePoint = iTemp;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            //Common to PHASE_START && PHASE_END
            if (m_uiPhase == PHASE_START || m_uiPhase == PHASE_END)
            {
                //Specific to PHASE_START || PHASE_END
                if (m_uiPhase == PHASE_START)
                {
                    if (HealthBelowPct(60))
                    {
                        SetCombatMovement(false);
                        m_uiPhase = PHASE_BREATH;
                        me->GetMotionMaster()->MovePoint(10, Phase2Location);
                        return;
                    }
                }
                else
                {
                    if (m_uiBellowingRoarTimer <= uiDiff)
                    {
                        DoCastVictim(SPELL_BELLOWING_ROAR);
                        // Eruption
                        GameObject* pFloor = NULL;
                        Trinity::GameObjectInRangeCheck check(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 15);
                        Trinity::GameObjectLastSearcher<Trinity::GameObjectInRangeCheck> searcher(me, pFloor, check);
                        me->VisitNearbyGridObject(30, searcher);
                        if (m_pInstance && pFloor)
                            m_pInstance->SetData64(DATA_FLOOR_ERUPTION_GUID, pFloor->GetGUID());
                        m_uiBellowingRoarTimer = 30000;
                    }
                    else
                        m_uiBellowingRoarTimer -= uiDiff;
                }

                if (m_uiFlameBreathTimer <= uiDiff)
                {
                    DoCastVictim(SPELL_FLAME_BREATH);
                    m_uiFlameBreathTimer = urand(10000, 20000);
                }
                else
                    m_uiFlameBreathTimer -= uiDiff;

                if (m_uiTailSweepTimer <= uiDiff)
                {
                    DoCastAOE(SPELL_TAIL_SWEEP);
                    m_uiTailSweepTimer = urand(15000, 20000);
                }
                else
                    m_uiTailSweepTimer -= uiDiff;

                if (m_uiCleaveTimer <= uiDiff)
                {
                    DoCastVictim(SPELL_CLEAVE);
                    m_uiCleaveTimer = urand(2000, 5000);
                }
                else
                    m_uiCleaveTimer -= uiDiff;

                if (m_uiWingBuffetTimer <= uiDiff)
                {
                    DoCastVictim(SPELL_WING_BUFFET);
                    m_uiWingBuffetTimer = urand(15000, 30000);
                }
                else
                    m_uiWingBuffetTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
            else
            {
                if (HealthBelowPct(40))
                {
                    m_uiPhase = PHASE_END;
                    if (m_pInstance)
                        m_pInstance->SetData(DATA_ONYXIA_PHASE, m_uiPhase);
                    DoScriptText(SAY_PHASE_3_TRANS, me);

                    SetCombatMovement(true);
                    me->SetFlying(false);
                    m_bIsMoving = false;
                    me->GetMotionMaster()->MovePoint(9,me->GetHomePosition());
                    return;
                }

                if (m_uiDeepBreathTimer <= uiDiff)
                {
                    if (!m_bIsMoving)
                    {
                        if (me->IsNonMeleeSpellCasted(false))
                            me->InterruptNonMeleeSpells(false);

                        DoScriptText(EMOTE_BREATH, me);
                        DoCast(me, m_pPointData->uiSpellId);
                        m_uiDeepBreathTimer = 70000;
                    }
                }
                else
                    m_uiDeepBreathTimer -= uiDiff;

                if (m_uiMovementTimer <= uiDiff)
                {
                    if (!m_bIsMoving)
                    {
                        SetNextRandomPoint();
                        m_pPointData = GetMoveData();

                        if (!m_pPointData)
                            return;

                        me->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ);
                        m_bIsMoving = true;
                        m_uiMovementTimer = 25000;
                    }
                }
                else
                    m_uiMovementTimer -= uiDiff;

                if (m_uiFireballTimer <= uiDiff)
                {
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE)
                    {
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(pTarget, SPELL_FIREBALL);

                        m_uiFireballTimer = 8000;
                    }
                }
                else
                    m_uiFireballTimer -= uiDiff;

                if (m_uiLairGuardTimer <= uiDiff)
                {
                    me->SummonCreature(NPC_LAIRGUARD, aSpawnLocations[2].GetPositionX(), aSpawnLocations[2].GetPositionY(), aSpawnLocations[2].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    m_uiLairGuardTimer = 30000;
                }
                else
                    m_uiLairGuardTimer -= uiDiff;

                if (m_uiWhelpTimer <= uiDiff)
                {
                    me->SummonCreature(NPC_WHELP, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_WHELP, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                    if (m_uiSummonWhelpCount >= RAID_MODE(20,40))
                    {
                        m_uiSummonWhelpCount = 0;
                        m_uiWhelpTimer = 90000;
                    }
                    else
                        m_uiWhelpTimer = 500;
                }
                else
                    m_uiWhelpTimer -= uiDiff;
            }
        }
    };

};

void AddSC_boss_onyxia()
{
    new boss_onyxia();
}

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
SD%Complete: 95
SDComment: The Heated Ground spell has 12 spell Id triggers in total, which trips the 
           default stack overflow protection. Solutions are to either increase
           MaxSpellCastsInChain in mangosd.conf or break the chain up into two spells by
           disabling the 6th spell's trigger index in the spell_effect_mod table. This
           script is using the second solution.
           TODO: Implement summon check for areas up on the wall where Onyxia can't reach.
SDCategory: Onyxia's Lair
EndScriptData
*/

#include "scriptPCH.h"
#include "instance_onyxia_lair.h"

enum
{
    SAY_AGGRO                   = 8286,
    SAY_KILL                    = 8287,
    SAY_PHASE_2_TRANS           = 8288,
    SAY_PHASE_3_TRANS           = 8290,
    EMOTE_BREATH                = 7213,

    SPELL_WINGBUFFET            = 18500,
    SPELL_FLAMEBREATH           = 18435,
    SPELL_CLEAVE                = 19983,
    SPELL_TAILSWEEP             = 15847,
    SPELL_KNOCK_AWAY            = 19633,
    SPELL_BELLOWINGROAR         = 18431,

    SPELL_FIREBALL              = 18392,
  //SPELL_ENGULFINGFLAMES       = 20019,
    SPELL_DEEPBREATH            = 23461,
    SPELL_HEATED_GROUND_EAST    = 22191,
    SPELL_HEATED_GROUND_WEST    = 22197,
    SPELL_HOVER                 = 17131,

    SPELL_BREATH_NORTH_TO_SOUTH = 17086,                    // 20x in "array"
    SPELL_BREATH_SOUTH_TO_NORTH = 18351,                    // 11x in "array"

    SPELL_BREATH_EAST_TO_WEST   = 18576,                    // 7x in "array"
    SPELL_BREATH_WEST_TO_EAST   = 18609,                    // 7x in "array"

    SPELL_BREATH_SE_TO_NW       = 18564,                    // 12x in "array"
    SPELL_BREATH_NW_TO_SE       = 18584,                    // 12x in "array"

    SPELL_BREATH_SW_TO_NE       = 18596,                    // 12x in "array"
    SPELL_BREATH_NE_TO_SW       = 18617,                    // 12x in "array"

  //SPELL_BREATH                = 21131,                    // 8x in "array", different initial cast than the other arrays
  //SPELL_SUMMONWHELP           = 17646,
        
    NPC_ONYXIAN_WHELP           = 11262,
    NPC_ONYXIAN_WARDER          = 12129,
    NPC_ERUPTION_TRIGGER        = 20009,

    GO_LAVATRAP_1               = 177984,
    GO_LAVATRAP_2               = 177985,

    DEPART_FLIGHT               = 20,
    LANDING_FLIGHT              = 21,

    PHASE_ONE                   = 1,
    PHASE_TWO                   = 2,
    PHASE_THREE                 = 3
};

static float const ONYXIA_AGGRO_RANGE  = 58.0f;

static float const ONYXIA_NORMAL_SPEED = 1.28571f;
static float const ONYXIA_BREATH_SPEED = 3.0f;

struct sOnyxMove
{
    uint32 uiLocId;
    uint32 uiLocIdEnd;
    uint32 uiSpellId;
    float fX, fY, fZ, fZGround;
};

static sOnyxMove aMoveData[] =
{
    {0, 4, SPELL_BREATH_NE_TO_SW,        10.2191f, -247.912f, -65.896f,  -85.84668f},  // north-east
    {1, 5, SPELL_BREATH_EAST_TO_WEST,   -31.4963f, -250.123f, -65.1278f, -89.127853f}, // east
    {2, 6, SPELL_BREATH_SE_TO_NW,       -63.5156f, -240.096f, -65.477f,  -85.066696f}, // south-east
    {3, 7, SPELL_BREATH_SOUTH_TO_NORTH, -65.8444f, -213.809f, -65.2985f, -84.298462f}, // south
    {4, 0, SPELL_BREATH_SW_TO_NE,       -58.2509f, -189.020f, -65.790f,  -85.292267f}, // south-west
    {5, 1, SPELL_BREATH_WEST_TO_EAST,   -33.5561f, -182.682f, -65.9457f, -88.945686f}, // west
    {6, 2, SPELL_BREATH_NW_TO_SE,         6.8951f, -180.246f, -65.896f,  -85.634293f}, // north-west
    {7, 3, SPELL_BREATH_NORTH_TO_SOUTH,  22.8763f, -217.152f, -65.0548f, -85.054054f}, // north
};

static float afSpawnLocations[2][3] =
{
    { -30.127f, -254.463f, -89.440f},
    { -30.817f, -177.106f, -89.258f}
};

struct boss_onyxiaAI : public ScriptedAI
{
    boss_onyxiaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    uint32 m_uiPhase;
    uint32 m_uiTransTimer;
    uint32 m_uiTransCount;
    bool m_bTransition;

    uint32 m_uiFlameBreathTimer;
    uint32 m_uiCleaveTimer;
    uint32 m_uiTailSweepTimer;
    uint32 m_uiWingBuffetTimer;
    uint32 m_uiKnockAwayTimer;

    uint32 m_uiFireballTimer;
    uint32 m_uiMovementTimer;
    uint32 m_uiDeepBreathTimer;
    bool   m_bDeepBreathIsCasting;
    int    m_uiMovePoint;

    sOnyxMove* m_pPointData;

    uint32 m_uiSummonWhelpsTimer;
    uint32 m_uiWhelpTimer;
    uint8  m_uiSummonCount;
    uint8  m_uiWhelpsToSummon;
    bool   m_bIsSummoningWhelps;
    
    uint32 m_uiBellowingRoarTimer;
    bool   m_bEruptPhase;

    uint32 m_uiAggroRadiusTimer;
    uint32 m_uiLeashCheckTimer;
    uint32 m_uiSummonCheckTimer;

    ScriptedInstance* m_pInstance;
    std::list<GameObject*> GOListe;
    
    void Reset() override
    {
        m_uiPhase              = PHASE_ONE;
        m_bTransition          = false;
        m_uiTransTimer         = 0;
        m_uiTransCount         = 0;

        m_uiFlameBreathTimer   = urand(10000, 20000);
        m_uiCleaveTimer        = urand(2000, 5000);
        m_uiWingBuffetTimer    = urand(10000, 20000);
        m_uiKnockAwayTimer     = urand(15000, 25000);
        m_uiTailSweepTimer     = 5000;

        m_uiFireballTimer      = 3000;
        m_uiMovementTimer      = 20000;
        m_uiMovePoint          = 7; // set North as the initial Phase 2 waypoint
        m_pPointData           = GetMoveData();
        m_uiDeepBreathTimer    = 0;
        m_bDeepBreathIsCasting = false;

        m_uiSummonWhelpsTimer  = 5000;
        m_uiWhelpTimer         = 1000;
        m_uiSummonCount        = 0;
        m_uiWhelpsToSummon     = 16;
        m_bIsSummoningWhelps   = false;

        m_uiBellowingRoarTimer = 10000;
        
        m_uiAggroRadiusTimer   = 5000;
        m_uiLeashCheckTimer    = 5000;
        m_uiSummonCheckTimer   = 5000;

        if (m_pInstance)
            m_pInstance->SetData(DATA_ONYXIA_EVENT, NOT_STARTED);
        
        SetCombatMovement(true);
        m_creature->SetSpeedRate(MOVE_RUN, ONYXIA_NORMAL_SPEED);
        m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 15.0f);
        m_creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 16.0f);

        // Daemon: remise en mode "dort"
        m_creature->SetStandState(UNIT_STAND_STATE_SLEEP);
        m_creature->SetFly(false);
        m_creature->SetWalk(true);
        m_creature->SetLevitate(false);
    }

    void DelayEventIfNeed(uint32& event, uint32 delay)
    {
        if (event < (delay + 150)) // Time runs in increments of 150ms
            event = delay + 150;
    }

    void DelayCastEvents(uint32 delay)
    {
        DelayEventIfNeed(m_uiFlameBreathTimer, delay);
        DelayEventIfNeed(m_uiTailSweepTimer, delay);
        DelayEventIfNeed(m_uiCleaveTimer, delay);
        DelayEventIfNeed(m_uiWingBuffetTimer, delay);
        DelayEventIfNeed(m_uiKnockAwayTimer, delay);
    }
    
    void CheckForTargetsInAggroRadius(uint32 uiDiff)
    {
        // There is a grid-related bug preventing Onyxia from receiving MoveInLineOfSight calls from units in the front of her chamber, so use this check instead.
        if (m_uiAggroRadiusTimer < uiDiff)
            m_uiAggroRadiusTimer = 1000;
        else
        {
            m_uiAggroRadiusTimer -= uiDiff;
            return;
        }

        if (!m_creature->IsInCombat() && !m_creature->IsInEvadeMode())
        {
            Map::PlayerList const& lPlayers = m_creature->GetMap()->GetPlayers();
            for (const auto& itr : lPlayers)
            {
                if (Player* pPlayer = itr.getSource())
                {
                    if (m_creature->IsWithinDistInMap(pPlayer, ONYXIA_AGGRO_RANGE) && pPlayer->IsTargetable(true, false))
                    {
                        pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                        m_creature->AI()->AttackStart(pPlayer);
                        m_creature->SetInCombatWithZone();
                        break;
                    }
                }
            }
        }
    }

    void LeashIfOutOfCombatArea(uint32 uiDiff)
    {
        if (m_uiLeashCheckTimer < uiDiff)
            m_uiLeashCheckTimer = 3500;
        else
        {
            m_uiLeashCheckTimer -= uiDiff;
            return;
        }

        if (m_creature->GetPositionX() < -95.0f)
            EnterEvadeMode();
    }

    void SummonPlayerIfOutOfReach(uint32 uiDiff)
    {
        if (m_uiSummonCheckTimer < uiDiff)
            m_uiSummonCheckTimer = 3000;
        else
        {
            m_uiSummonCheckTimer -= uiDiff;
            return;
        }

        /** Teleport victim to the center of the chamber if too far away from Onyxia */
        if (Unit* pVictim = m_creature->GetVictim())
        {
            if (isOnyxiaFlying() && !m_creature->IsMoving()) 
            {
                if (pVictim->GetPositionX() < -105.0f)
                    pVictim->NearTeleportTo(-12.866907f, -216.626007f, -88.057808f, 0.0f);
            }
            else if (!isOnyxiaFlying())
            {
                if (m_creature->GetDistance2d(pVictim) > 90.0f /*|| !m_creature->GetCurrentMovementGenerator()->IsReachable()*/)
                    pVictim->NearTeleportTo(-12.866907f, -216.626007f, -88.057808f, 0.0f); 
            }
       } 
    }

    void Aggro(Unit* pWho) override
    {
        // Daemon: Fix orientation.
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);

        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->SetInCombatWithZone();
        if (m_pInstance)
            m_pInstance->SetData(DATA_ONYXIA_EVENT, IN_PROGRESS);

        std::list<Creature*> WarderList;
        GetCreatureListWithEntryInGrid(WarderList, m_creature, NPC_ONYXIAN_WARDER, 200.0f);
        for (const auto& itr : WarderList)
            if (!itr->IsAlive())
                itr->Respawn();
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(DATA_ONYXIA_EVENT, DONE);
    }

    void EnterEvadeMode() override
    {
        std::list<Creature*> WhelpList;
        GetCreatureListWithEntryInGrid(WhelpList, m_creature, NPC_ONYXIAN_WHELP, 200.0f);
        for (const auto& itr : WhelpList)
            itr->ForcedDespawn();
        
        ScriptedAI::EnterEvadeMode();
    }
    
    void JustSummoned(Creature *pSummoned) override
    {
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            pSummoned->AI()->AttackStart(pTarget);

        ++m_uiSummonCount;
    }

    void KilledUnit(Unit* pVictim) override
    {
        if (pVictim->IsPlayer())
            if (roll_chance_i(50))
                DoScriptText(SAY_KILL, m_creature);
    }

    bool isOnyxiaFlying()
    {
        return m_creature->HasAura(SPELL_HOVER);
    }
   
    sOnyxMove* GetMoveData()
    {
        uint32 uiMaxCount = sizeof(aMoveData) / sizeof(sOnyxMove);
        for (uint32 i = 0; i < uiMaxCount; ++i)
        {
            if (aMoveData[i].uiLocId == m_uiMovePoint)
                return &aMoveData[i];
        }

        return nullptr;
    } 
    
    void PhaseOne(uint32 uiDiff)
    {
        if (m_creature->IsFlying())
        {
            m_creature->SetWalk(true);
            m_creature->SetFly(false);
            m_creature->SetLevitate(false);
        }
        
        if (m_uiFlameBreathTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FLAMEBREATH) == CAST_OK)
            {
                DelayCastEvents(2000); // 2sec de cast
                m_uiFlameBreathTimer = urand(10000, 20000);
            }
        }
        else
            m_uiFlameBreathTimer -= uiDiff;

        if (m_uiCleaveTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleaveTimer = urand(2000, 5000);
        }
        else
            m_uiCleaveTimer -= uiDiff;

        if (m_uiWingBuffetTimer < uiDiff)
        {
            if (m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WINGBUFFET) == CAST_OK)
                {
                    DelayCastEvents(1500);
                    m_uiWingBuffetTimer = urand(15000, 30000);
                }
            }
        }
        else
            m_uiWingBuffetTimer -= uiDiff;

        if (m_uiKnockAwayTimer < uiDiff)
        {
            if (m_creature->CanReachWithMeleeAutoAttack(m_creature->GetVictim()))
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK_AWAY) == CAST_OK)
                {
                    if (m_creature->GetThreatManager().getThreat(m_creature->GetVictim()))
                        m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -25);

                    DelayCastEvents(1500);
                    m_uiKnockAwayTimer = urand(15000, 30000);
                }
            }
        }
        else
            m_uiKnockAwayTimer -= uiDiff;

        if (m_uiTailSweepTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_TAILSWEEP) == CAST_OK)
                m_uiTailSweepTimer = 3500;
        }
        else
            m_uiTailSweepTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void PhaseTwo(uint32 uiDiff)
    {
        if (m_uiMovementTimer < uiDiff)
        {
            m_uiMovementTimer = urand(15000, 25000);
            m_uiFireballTimer = 5000;
            if (DoMovement())
            {
                // casting Deep Breath
                m_uiMovementTimer = urand(20000, 25000);
                m_uiFireballTimer = 10000;
            }
        }
        else
            m_uiMovementTimer -= uiDiff;

        if (m_bDeepBreathIsCasting)
        {
            if (m_uiDeepBreathTimer <= uiDiff)
            {
                m_creature->SetSpeedRate(MOVE_RUN, ONYXIA_BREATH_SPEED);
                m_creature->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ, MOVE_PATHFINDING | MOVE_FLY_MODE);
                // heat up egg pit during Deep Breath
                m_creature->CastSpell(m_creature, SPELL_HEATED_GROUND_EAST, true);
                m_creature->CastSpell(m_creature, SPELL_HEATED_GROUND_WEST, true);
                m_bDeepBreathIsCasting = false;
                m_uiDeepBreathTimer = 0;
            }
            else
                m_uiDeepBreathTimer -= uiDiff;
        }

        if (m_uiFireballTimer < uiDiff)
        {
            if (m_uiMovementTimer > 3500 && m_creature->IsStopped() && !m_bDeepBreathIsCasting)
            {
                if (Unit* pTarget = m_creature->GetVictim())
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_FIREBALL) == CAST_OK)
                    {
                        if (m_creature->GetThreatManager().getThreat(pTarget))
                            m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                        m_uiFireballTimer = 3000;
                    }
                }
            }
        }
        else
            m_uiFireballTimer -= uiDiff;

        if (m_bIsSummoningWhelps)
        {
            if (m_uiSummonCount < m_uiWhelpsToSummon)
            {
                if (m_uiWhelpTimer < uiDiff)
                {
                    m_creature->SummonCreature(NPC_ONYXIAN_WHELP, afSpawnLocations[0][0], afSpawnLocations[0][1], afSpawnLocations[0][2], 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    m_creature->SummonCreature(NPC_ONYXIAN_WHELP, afSpawnLocations[1][0], afSpawnLocations[1][1], afSpawnLocations[1][2], 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    m_uiWhelpTimer = 1000;
                }
                else
                    m_uiWhelpTimer -= uiDiff;
            }
            else
            {
                m_bIsSummoningWhelps = false;
                m_uiSummonCount = 0;
                m_uiWhelpsToSummon = 5 + urand(0, 2);
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

    bool DoMovement()
    {
        m_creature->InterruptNonMeleeSpells(false);
        m_pPointData = GetMoveData();

        uint32 roll = urand(0, 99);
        if (roll < 35)          // Move clockwise
        {
            m_uiMovePoint = (m_uiMovePoint + 1) % 8;
        }
        else if (roll < 70)     // Move counter-clockwise
        {
            m_uiMovePoint = (m_uiMovePoint + 8 - 1) % 8;
        }
        else                    // Deep Breath
        {
            m_uiMovePoint = (m_uiMovePoint + 4) % 8;
            DoScriptText(EMOTE_BREATH, m_creature);

            m_bDeepBreathIsCasting = true;
            m_uiDeepBreathTimer = 5000;
            m_creature->CastSpell(m_creature, m_pPointData->uiSpellId, true);
            // face destination and clear target
            m_pPointData = GetMoveData();
            m_creature->SetFacingTo(m_creature->GetAngle(m_pPointData->fX, m_pPointData->fY));
            m_creature->SetTargetGuid(ObjectGuid());
            return true;
        }

        m_pPointData = GetMoveData();
        m_creature->SetSpeedRate(MOVE_RUN, ONYXIA_NORMAL_SPEED);
        m_creature->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ, MOVE_PATHFINDING | MOVE_FLY_MODE);
        return false;
    }

    void PhaseThree(uint32 uiDiff)
    {
        if (m_uiBellowingRoarTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BELLOWINGROAR, true) == CAST_OK)
            {
                m_uiBellowingRoarTimer = urand(15000, 30000);
                // Do not be interrupted by other casts.
                DelayCastEvents(2000);
            }
        }
        else
            m_uiBellowingRoarTimer -= uiDiff;

        if (m_uiSummonWhelpsTimer < uiDiff)
        {
            switch (urand(0, 1))
            {
                case 0: m_creature->SummonCreature(NPC_ONYXIAN_WHELP, afSpawnLocations[0][0], afSpawnLocations[0][1], afSpawnLocations[0][2], 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000); break;
                case 1: m_creature->SummonCreature(NPC_ONYXIAN_WHELP, afSpawnLocations[1][0], afSpawnLocations[1][1], afSpawnLocations[1][2], 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000); break;
            }
            m_uiSummonWhelpsTimer = urand(1000, 10000);
        }
        else
            m_uiSummonWhelpsTimer -= uiDiff;
        
        PhaseOne(uiDiff);
    }

    void PhaseTransition(uint32 uiDiff, bool bDebut)
    {
//        m_creature->CombatStop(true);
        m_creature->ClearUnitState(UNIT_STAT_MELEE_ATTACKING);

        /** P2 Event to take off */
        if (m_uiPhase == PHASE_TWO)
        {
            /** Stop combat and move to the first waypoint before taking off */
            if (bDebut && m_uiTransCount == 0)
            {
                SetCombatMovement(false);
                DoScriptText(SAY_PHASE_2_TRANS, m_creature);
                m_creature->InterruptNonMeleeSpells(false);

                m_creature->GetMotionMaster()->Clear(false);
                m_creature->GetMotionMaster()->MoveIdle();

                m_creature->SetSpeedRate(MOVE_RUN, ONYXIA_NORMAL_SPEED);
                m_creature->GetMotionMaster()->MovePoint(DEPART_FLIGHT, -57.750641f, -215.610077f, -85.094727f, MOVE_PATHFINDING);
                m_uiTransTimer = 60000; // handled by MovementInform
            }
            /** Take off in progress */
            else if (m_uiTransTimer < uiDiff && m_uiTransCount == 1)
            {
                //m_creature->InterruptNonMeleeSpells(false);
                m_creature->GetMotionMaster()->Clear(false);
                m_creature->GetMotionMaster()->MoveIdle();
                m_creature->GetMotionMaster()->MovePoint(0, -57.204933f, -215.592148f, -85.156929f, MOVE_PATHFINDING | MOVE_FLY_MODE);
                m_uiTransTimer = 2000;
                m_uiTransCount = 2;
            }
            /** Fly mode added, move to the first waypoint */
            else if (m_uiTransTimer < uiDiff && m_uiTransCount == 2)
            {
                m_creature->CastSpell(m_creature, 17131, true); /** Start flying */
                m_bTransition = false;
                m_uiTransTimer = 0;

                // increase Onyxia's hitbox while in the air to make it slightly easier for melee to use specials on her
                m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 21.0f);
                m_creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 22.0f);
                
                m_pPointData = GetMoveData();
                m_creature->GetMotionMaster()->MovePoint(m_pPointData->uiLocId, m_pPointData->fX, m_pPointData->fY, m_pPointData->fZ, MOVE_PATHFINDING | MOVE_FLY_MODE);
            }
        }
        /** P3 event to land */
        else if (m_uiPhase == PHASE_THREE)
        {
            /** Fly to the landing waypoint */
            if (bDebut && m_uiTransCount == 2)
            {
                DoResetThreat();
                DoScriptText(SAY_PHASE_3_TRANS, m_creature);
                m_creature->SetSpeedRate(MOVE_RUN, ONYXIA_NORMAL_SPEED);
                m_creature->InterruptNonMeleeSpells(false);

                if (m_creature->GetPositionX() < -40.0f)
                    m_creature->GetMotionMaster()->MovePoint(LANDING_FLIGHT, -59.895f, -214.876f, -84.855f, MOVE_FLY_MODE); // South
                else
                    m_creature->GetMotionMaster()->MovePoint(LANDING_FLIGHT, -8.86f, -212.752f, -88.542f, MOVE_FLY_MODE);   // North

                m_creature->RemoveAurasDueToSpell(17131); /** Stop flying */
                m_creature->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 15.0f);
                m_creature->SetFloatValue(UNIT_FIELD_COMBATREACH, 16.0f);
                m_uiTransTimer = 60000; // handled by MovementInform
            }
            /** Landing in progress */
            else if (m_uiTransTimer < uiDiff && m_uiTransCount == 3)
            {
                m_creature->GetMotionMaster()->MovePoint(0, -8.860f, -212.752f, -87.482f, MOVE_PATHFINDING | MOVE_FLY_MODE);
                m_uiTransTimer = 2000;
                m_uiTransCount = 4;
            }
            /** Landed. Restore target and start combat movement.*/
            else if (m_uiTransTimer < uiDiff && m_uiTransCount == 4)
            {               
                if (Unit* pVictim = m_creature->GetVictim())
                    m_creature->SetTargetGuid(pVictim->GetObjectGuid()); 

                SetCombatMovement(true);
                m_creature->GetMotionMaster()->MoveChase(m_creature->GetVictim());

                m_bTransition  = false;
                m_uiTransTimer = 0;

                m_uiFlameBreathTimer   = urand(10000, 15000);
                m_uiTailSweepTimer     = 5000;
                m_uiCleaveTimer        = urand(2000, 5000);
                m_uiWingBuffetTimer    = urand(10000, 20000);
                m_uiKnockAwayTimer     = urand(10000, 20000);
            }
        }

        if (m_uiTransTimer >= uiDiff)
            m_uiTransTimer -= uiDiff;
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        // restore Onyxia's target after movement in Phase 2
        if (uiPointId == m_pPointData->uiLocId)
        {
            if (Unit* pVictim = m_creature->GetVictim())
                m_creature->SetTargetGuid(pVictim->GetObjectGuid()); 
        }

        switch (uiPointId)
        {
            case DEPART_FLIGHT:
                m_creature->SetOrientation(0.0f);
                m_uiTransTimer = 1000;
                m_uiTransCount = 1;
                m_creature->SetFly(true);
                m_creature->SetLevitate(true);
                m_creature->HandleEmote(EMOTE_ONESHOT_LIFTOFF);
                break;
            case LANDING_FLIGHT:
                m_creature->SetOrientation(0.0f);
                m_uiTransTimer = 1000;
                m_uiTransCount = 3;
                m_creature->SetFly(false);
                m_creature->SetLevitate(false);
                m_creature->HandleEmote(EMOTE_ONESHOT_LAND);
                m_creature->CastSpell(m_creature, SPELL_BELLOWINGROAR, true);
                m_uiBellowingRoarTimer = urand (15000, 30000);
                break;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        CheckForTargetsInAggroRadius(uiDiff);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;
        
        /** whenever Onyxia is moving to a waypoint or casting Deep Breath, clear her target */
        if (m_bTransition || m_bDeepBreathIsCasting || (m_uiPhase == PHASE_TWO && m_creature->IsMoving()))
            m_creature->SetTargetGuid(ObjectGuid()); 

        if (m_bTransition)
        {
            PhaseTransition(uiDiff, false);
            return;
        }
        
        LeashIfOutOfCombatArea(uiDiff);
        
        SummonPlayerIfOutOfReach(uiDiff); 

        /** Switch to P3 */
        if (m_creature->GetHealthPercent() < 40.0f && m_uiPhase == PHASE_TWO && !m_creature->IsMoving() && !m_bDeepBreathIsCasting)
        {
            m_uiPhase = PHASE_THREE;
            m_bTransition = true;
            PhaseTransition(0, true);
            return;
        }
        /** Switch to P2 */
        else if (m_creature->GetHealthPercent() < 65.0f && m_uiPhase == PHASE_ONE)
        {
            m_uiPhase = PHASE_TWO;
            m_bTransition = true;
            PhaseTransition(0, true);
            return;
        }

        switch (m_uiPhase)
        {
            case PHASE_ONE:
                PhaseOne(uiDiff);
                break;
            case PHASE_TWO:
                PhaseTwo(uiDiff);
                break;
            case PHASE_THREE:
                PhaseThree(uiDiff);
                break;
            default:
                break;
        }
    }
};

CreatureAI* GetAI_boss_onyxiaAI(Creature* pCreature)
{
    return new boss_onyxiaAI(pCreature);
}

struct OnyxianWhelpAI: public ScriptedAI
{
    OnyxianWhelpAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }


    void Reset() override
    {
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_onyxian_whelp(Creature* pCreature)
{
    return new OnyxianWhelpAI(pCreature);
}

void AddSC_boss_onyxia()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_onyxia";
    newscript->GetAI = &GetAI_boss_onyxiaAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_onyxian_whelp";
    newscript->GetAI = &GetAI_npc_onyxian_whelp;
    newscript->RegisterSelf();
}

/*
-- SPELL_BREATH_EAST_TO_WEST
DELETE FROM spell_target_position WHERE id IN (18576, 18578, 18579, 18580, 18581, 18582, 18583);
INSERT INTO spell_target_position VALUES (18576, 249, -37.743851, -243.667923, -88.217651, 1.416);
INSERT INTO spell_target_position VALUES (18578, 249, -35.805332, -232.028900, -87.749153, 1.416);
INSERT INTO spell_target_position VALUES (18579, 249, -34.045738, -224.714661, -85.529465, 1.416);
INSERT INTO spell_target_position VALUES (18580, 249, -32.081570, -214.916962, -88.327438, 1.416);
INSERT INTO spell_target_position VALUES (18581, 249, -36.611721, -202.684677, -85.653786, 1.416);
INSERT INTO spell_target_position VALUES (18582, 249, -37.067261, -195.758652, -87.745834, 1.416);
INSERT INTO spell_target_position VALUES (18583, 249, -37.728523, -188.616806, -88.074898, 1.416);
-- SPELL_BREATH_WEST_TO_EAST
DELETE FROM spell_target_position WHERE id IN (18609, 18611, 18612, 18613, 18614, 18615, 18616);
INSERT INTO spell_target_position VALUES (18609, 249, -37.728523, -188.616806, -88.074898, 4.526);
INSERT INTO spell_target_position VALUES (18611, 249, -37.067261, -195.758652, -87.745834, 4.526);
INSERT INTO spell_target_position VALUES (18612, 249, -36.611721, -202.684677, -85.653786, 4.526);
INSERT INTO spell_target_position VALUES (18613, 249, -32.081570, -214.916962, -88.327438, 4.526);
INSERT INTO spell_target_position VALUES (18614, 249, -34.045738, -224.714661, -85.529465, 4.526);
INSERT INTO spell_target_position VALUES (18615, 249, -35.805332, -232.028900, -87.749153, 4.526);
INSERT INTO spell_target_position VALUES (18616, 249, -37.743851, -243.667923, -88.217651, 4.526);
-- SPELL_BREATH_NW_TO_SE
DELETE FROM spell_target_position WHERE id IN (18584, 18585, 18586, 18587, 18588, 18589, 18590, 18591, 18592, 18593, 18594, 18595);
INSERT INTO spell_target_position VALUES (18584, 249, 6.016711, -181.305771, -85.654648, 3.776);
INSERT INTO spell_target_position VALUES (18585, 249, 3.860220, -183.227249, -86.375381, 3.776);
INSERT INTO spell_target_position VALUES (18586, 249, -2.529650, -188.690491, -87.172859, 3.776);
INSERT INTO spell_target_position VALUES (18587, 249, -8.449303, -193.957962, -87.564957, 3.776);
INSERT INTO spell_target_position VALUES (18588, 249, -14.321238, -199.462219, -87.922478, 3.776);
INSERT INTO spell_target_position VALUES (18589, 249, -15.602085, -216.893936, -88.403183, 3.776);
INSERT INTO spell_target_position VALUES (18590, 249, -23.650263, -221.969086, -89.172699, 3.776);
INSERT INTO spell_target_position VALUES (18591, 249, -29.495876, -213.014359, -88.910423, 3.776);
INSERT INTO spell_target_position VALUES (18592, 249, -35.439922, -217.260284, -87.336311, 3.776);
INSERT INTO spell_target_position VALUES (18593, 249, -41.762104, -221.896545, -86.114113, 3.776);
INSERT INTO spell_target_position VALUES (18594, 249, -51.067528, -228.909988, -85.765556, 3.776);
INSERT INTO spell_target_position VALUES (18595, 249, -56.559654, -241.223923, -85.423607, 3.776);
-- SPELL_BREATH_SE_TO_NW
DELETE FROM spell_target_position WHERE id IN (18564, 18565, 18566, 18567, 18568, 18569, 18570, 18571, 18572, 18573, 18574, 18575);
INSERT INTO spell_target_position VALUES (18564, 249, -56.559654, -241.223923, -85.423607, 0.666);
INSERT INTO spell_target_position VALUES (18565, 249, -51.067528, -228.909988, -85.765556, 0.666);
INSERT INTO spell_target_position VALUES (18566, 249, -41.762104, -221.896545, -86.114113, 0.666);
INSERT INTO spell_target_position VALUES (18567, 249, -35.439922, -217.260284, -87.336311, 0.666);
INSERT INTO spell_target_position VALUES (18568, 249, -29.495876, -213.014359, -88.910423, 0.666);
INSERT INTO spell_target_position VALUES (18569, 249, -23.650263, -221.969086, -89.172699, 0.666);
INSERT INTO spell_target_position VALUES (18570, 249, -15.602085, -216.893936, -88.403183, 0.666);
INSERT INTO spell_target_position VALUES (18571, 249, -14.321238, -199.462219, -87.922478, 0.666);
INSERT INTO spell_target_position VALUES (18572, 249, -8.449303, -193.957962, -87.564957, 0.666);
INSERT INTO spell_target_position VALUES (18573, 249, -2.529650, -188.690491, -87.172859, 0.666);
INSERT INTO spell_target_position VALUES (18574, 249, 3.860220, -183.227249, -86.375381, 0.666);
INSERT INTO spell_target_position VALUES (18575, 249, 6.016711, -181.305771, -85.654648, 0.666);
-- SPELL_BREATH_SW_TO_NE
DELETE FROM spell_target_position WHERE id IN (18596, 18597, 18598, 18599, 18600, 18601, 18602, 18603, 18604, 18605, 18606, 18607);
INSERT INTO spell_target_position VALUES (18596, 249, -58.250900, -189.020004, -85.292267, 5.587);
INSERT INTO spell_target_position VALUES (18597, 249, -52.006271, -193.796570, -85.808769, 5.587);
INSERT INTO spell_target_position VALUES (18598, 249, -46.135464, -198.548553, -85.901764, 5.587);
INSERT INTO spell_target_position VALUES (18599, 249, -40.500187, -203.001053, -85.555107, 5.587);
INSERT INTO spell_target_position VALUES (18600, 249, -30.907579, -211.058197, -88.592125, 5.587);
INSERT INTO spell_target_position VALUES (18601, 249, -20.098139, -218.681427, -88.937088, 5.587);
INSERT INTO spell_target_position VALUES (18602, 249, -12.223192, -224.666168, -87.856300, 5.587);
INSERT INTO spell_target_position VALUES (18603, 249, -6.475297, -229.098724, -87.076401, 5.587);
INSERT INTO spell_target_position VALUES (18604, 249, -2.010256, -232.541992, -86.995140, 5.587);
INSERT INTO spell_target_position VALUES (18605, 249, 2.736300, -236.202347, -86.790367, 5.587);
INSERT INTO spell_target_position VALUES (18606, 249, 7.197779, -239.642868, -86.307297, 5.587);
INSERT INTO spell_target_position VALUES (18607, 249, 12.120926, -243.439407, -85.874260, 5.587);
-- SPELL_BREATH_NE_TO_SW
DELETE FROM spell_target_position WHERE id IN (18617, 18619, 18620, 18621, 18622, 18623, 18624, 18625, 18626, 18627, 18628, 18618);
INSERT INTO spell_target_position VALUES (18617, 249, 12.120926, -243.439407, -85.874260, 2.428);
INSERT INTO spell_target_position VALUES (18619, 249, 7.197779, -239.642868, -86.307297, 2.428);
INSERT INTO spell_target_position VALUES (18620, 249, 2.736300, -236.202347, -86.790367, 2.428);
INSERT INTO spell_target_position VALUES (18621, 249, -2.010256, -232.541992, -86.995140, 2.428);
INSERT INTO spell_target_position VALUES (18622, 249, -6.475297, -229.098724, -87.076401, 2.428);
INSERT INTO spell_target_position VALUES (18623, 249, -12.223192, -224.666168, -87.856300, 2.428);
INSERT INTO spell_target_position VALUES (18624, 249, -20.098139, -218.681427, -88.937088, 2.428);
INSERT INTO spell_target_position VALUES (18625, 249, -30.907579, -211.058197, -88.592125, 2.428);
INSERT INTO spell_target_position VALUES (18626, 249, -40.500187, -203.001053, -85.555107, 2.428);
INSERT INTO spell_target_position VALUES (18627, 249, -46.135464, -198.548553, -85.901764, 2.428);
INSERT INTO spell_target_position VALUES (18628, 249, -52.006271, -193.796570, -85.808769, 2.428);
INSERT INTO spell_target_position VALUES (18618, 249, -58.250900, -189.020004, -85.292267, 2.428);
-- SPELL_BREATH_SOUTH_TO_NORTH
DELETE FROM spell_target_position WHERE id IN (18351, 18352, 18353, 18354, 18355, 18356, 18357, 18358, 18359, 18360, 18361);
INSERT INTO spell_target_position VALUES (18351, 249, -68.834236, -215.036163, -84.018875, 6.280);
INSERT INTO spell_target_position VALUES (18352, 249, -61.834255, -215.051910, -84.673416, 6.280);
INSERT INTO spell_target_position VALUES (18353, 249, -53.343277, -215.071014, -85.597191, 6.280);
INSERT INTO spell_target_position VALUES (18354, 249, -42.619305, -215.095139, -86.663605, 6.280);
INSERT INTO spell_target_position VALUES (18355, 249, -35.899323, -215.110245, -87.196548, 6.280);
INSERT INTO spell_target_position VALUES (18356, 249, -28.248341, -215.127457, -89.191750, 6.280);
INSERT INTO spell_target_position VALUES (18357, 249, -20.324360, -215.145279, -88.963997, 6.280);
INSERT INTO spell_target_position VALUES (18358, 249, -11.189384, -215.165833, -87.817093, 6.280);
INSERT INTO spell_target_position VALUES (18359, 249, -2.047405, -215.186386, -86.279655, 6.280);
INSERT INTO spell_target_position VALUES (18360, 249, 7.479571, -215.207809, -86.075531, 6.280);
INSERT INTO spell_target_position VALUES (18361, 249, 20.730539, -215.237610, -85.254387, 6.280);
-- SPELL_BREATH_NORTH_TO_SOUTH
DELETE FROM spell_target_position WHERE id IN (17086, 17087, 17088, 17089, 17090, 17091, 17092, 17093, 17094, 17095, 17097, 22267, 22268, 21132, 21133, 21135, 21136, 21137, 21138, 21139);
INSERT INTO spell_target_position VALUES (17086, 249, 20.730539, -215.237610, -85.254387, 3.142);
INSERT INTO spell_target_position VALUES (17087, 249, 7.479571, -215.207809, -86.075531, 3.142);
INSERT INTO spell_target_position VALUES (17088, 249, -2.047405, -215.186386, -86.279655, 3.142);
INSERT INTO spell_target_position VALUES (17089, 249, -11.189384, -215.165833, -87.817093, 3.142);
INSERT INTO spell_target_position VALUES (17090, 249, -20.324360, -215.145279, -88.963997, 3.142);
INSERT INTO spell_target_position VALUES (17091, 249, -28.248341, -215.127457, -89.191750, 3.142);
INSERT INTO spell_target_position VALUES (17092, 249, -35.899323, -215.110245, -87.196548, 3.142);
INSERT INTO spell_target_position VALUES (17093, 249, -42.619305, -215.095139, -86.663605, 3.142);
INSERT INTO spell_target_position VALUES (17094, 249, -53.343277, -215.071014, -85.597191, 3.142);
INSERT INTO spell_target_position VALUES (17095, 249, -61.834255, -215.051910, -84.673416, 3.142);
INSERT INTO spell_target_position VALUES (17097, 249, -68.834236, -215.036163, -84.018875, 3.142);
INSERT INTO spell_target_position VALUES (22267, 249, -75.736046, -214.984970, -83.394188, 3.142);
INSERT INTO spell_target_position VALUES (22268, 249, -84.087578, -214.857834, -82.640053, 3.142);
INSERT INTO spell_target_position VALUES (21132, 249, -90.424416, -214.601974, -82.482697, 3.142);
INSERT INTO spell_target_position VALUES (21133, 249, -96.572411, -214.353745, -82.239967, 3.142);
INSERT INTO spell_target_position VALUES (21135, 249, -102.069931, -214.131775, -80.571190, 3.142);
INSERT INTO spell_target_position VALUES (21136, 249, -107.385597, -213.917145, -77.447037, 3.142);
INSERT INTO spell_target_position VALUES (21137, 249, -114.281258, -213.866486, -73.851128, 3.142);
INSERT INTO spell_target_position VALUES (21138, 249, -123.328560, -213.607910, -71.559921, 3.142);
INSERT INTO spell_target_position VALUES (21139, 249, -130.788300, -213.424026, -70.751007, 3.142);
-- SPELL_HEATED_GROUND
DELETE FROM spell_target_position WHERE id BETWEEN 22191 AND 22202; 
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22191', '249', '-52.5138', '-277.7293', '-92.7831', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22192', '249', '-31.4963', '-250.1230', '-65.1278', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22193', '249', '-82.0559', '-263.803', '-93.9232', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22194', '249', '-96.1528', '-252.423', '-93.7457', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22195', '249', '-106.001', '-236.07', '-94.474', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22196', '249', '-107.857', '-215.289', '-96.1121', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22197', '249', '-107.224', '-198.447', '-94.0403', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22198', '249', '-101.142', '-176.662', '-93.5392', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22199', '249', '-83.2411', '-166.152', '-93.9348', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22200', '249', '-54.4049', '-146.5873', '-91.0617', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22201', '249', '-55.1297', '-158.7988', '-94.2321', '0');
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES ('22202', '249', '-101.142', '-176.662', '-93.5392', '0');
*/

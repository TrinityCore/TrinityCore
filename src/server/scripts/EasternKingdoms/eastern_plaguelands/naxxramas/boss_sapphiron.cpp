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

// todo: Make sure he's immune to frost damage.

#include "scriptPCH.h"
#include "naxxramas.h"
#include "MovementGenerator.h"

enum SapphironData
{
    EMOTE_BREATH       = 7213,
    EMOTE_ENRAGE       = 2384,

    SPELL_ICEBOLT       = 28522,
    SPELL_STUN_IMMUNE   = 28782,

    // SPELL_SUMM_ICEBLOCK = 28535, // we manually summon an iceblock in SpellHitTarget

    //SPELL_FROST_BREATH = 29318,
    SPELL_FROST_BREATH        = 28524, // triggers the damage and explosion visual, 7sec cast
    SPELL_FROST_BREATH_DUMMY  = 30101, // shows the falling ball thing

    SPELL_FROST_AURA   = 28529,
    SPELL_LIFE_DRAIN   = 28542,
    SPELL_BESERK       = 26662,
    SPELL_CLEAVE        = 19983,
    SPELL_TAIL_SWEEP    = 15847,

    // each blizzard has 30sec duration supposedly
    SPELL_SUMMON_BLIZ1      = 28561, // summons creature 16474
    SPELL_SUMMON_BLIZ2      = 28560, // unimplemented script effect
    SPELL_BLIZZARD_PERIODIC = 28534, // triggers 28547 every 3 second
    SPELL_BLIZZARD          = 28547, // deals dmg every 2 seconds. Stationary, lasts for 15sec

    SPELL_PERIODIC_BUFFET   = 29327, // periodically does 29328
    SPELL_WING_BUFFET       = 29328, // is it the spell he does on takeoff, or another one?

    SPELL_SAPPHIRON_DIES = 29357, // adds camera-shake.
    
    GO_ICEBLOCK = 181247,

    MOVE_POINT_LIFTOFF = 1,
    MOVE_POINT_FLYPOINT = 2,

    NPC_WING_BUFFET = 17025, 
    NPC_BLIZZARD = 16474
};

enum Events
{
    EVENT_MOVE_TO_FLY = 1,
    EVENT_LIFTOFF = 2,
    EVENT_LAND = 3,
    EVENT_LANDED = 4,
    EVENT_ICEBOLT = 5,
    EVENT_BLIZZARD = 6,
    EVENT_LIFEDRAIN = 7,
    EVENT_TAIL_SWEEP = 8,
    EVENT_CLEAVE = 9,
    EVENT_FROST_BREATH_DUMMY = 10,
    EVENT_FROST_BREATH_CAST = 11,
    EVENT_CHECK_EVADE = 12
};

enum Phase
{
    PHASE_GROUND     = 1,
    PHASE_LIFT_OFF   = 2,
    PHASE_AIR_BOLTS  = 3,
    PHASE_AIR_BREATH = 4,
    PHASE_LANDING    = 5,

    PHASE_SKELETON,
    PHASE_SUMMONING,
    PHASE_DEAD
};

static float const aLiftOffPosition[3] = { 3521.300f, -5237.560f, 138.261f };
uint32 SPAWN_ANIM_TIMER = 21500;
static constexpr float AGGRO_RADIUS = 70.0f;

struct boss_sapphironAI : public ScriptedAI
{
    boss_sapphironAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_forceTargetUpdateTimer = 1000;
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        Reset();

        if (m_pInstance)
        {
            if (m_pInstance->GetData(TYPE_SAPPHIRON) != DONE)
            {
                phase = PHASE_SKELETON;
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                m_creature->SetVisibility(VISIBILITY_OFF);
            }
            else
            {
                if (GameObject* skeleton = m_pInstance->GetSingleGameObjectFromStorage(GO_SAPPHIRON_SPAWN))
                    skeleton->Despawn();
                phase = PHASE_DEAD;
            }
        }
        else
        {
            phase = PHASE_GROUND;
        }
        m_TargetNotReachableTimer = 0;
    }

    instance_naxxramas* m_pInstance;

    uint32 Icebolt_Count;
    uint32 Icebolt_Timer;
    uint32 FrostBreath_Timer;
    uint32 LifeDrain_Timer;
    uint32 Blizzard_Timer;
    uint32 Fly_Timer;
    bool landoff;
    uint32 land_Timer;

    EventMap events;
    Phase phase;
    uint32 spawnTimer;
    uint32 berserkTimer;
    std::vector<ObjectGuid> iceboltTargets;
    ObjectGuid wingBuffetCreature;
    uint32 pullCheckTimer;

    uint32 m_forceTargetUpdateTimer;
    uint32 m_TargetNotReachableTimer;

    void Reset() override
    {
        pullCheckTimer = 0;
        phase = PHASE_GROUND;
        events.Reset();
        berserkTimer = 900000; // 15 min
        m_creature->RemoveAurasDueToSpell(SPELL_FROST_AURA);
        m_creature->RemoveAurasDueToSpell(17131);
        UnSummonWingBuffet();
        DeleteAndDispellIceBlocks();
        setHover(false, true);
        SetCombatMovement(true);
        m_TargetNotReachableTimer = 0;

        if (m_pInstance && m_pInstance->GetData(TYPE_SAPPHIRON) != DONE)
            m_pInstance->SetData(TYPE_SAPPHIRON, NOT_STARTED);
    }

    void UnSummonWingBuffet()
    {
        if (wingBuffetCreature)
        {
            if (Creature* pC = m_pInstance->GetCreature(wingBuffetCreature))
            {
                TemporarySummon* tmpS = static_cast<TemporarySummon*>(pC);
                tmpS->UnSummon();
            }
            wingBuffetCreature = 0;
        }
    }

    void DeleteAndDispellIceBlocks()
    {
        std::list<GameObject*> iceblocks;
        GetGameObjectListWithEntryInGrid(iceblocks, m_creature, GO_ICEBLOCK, 300.0f);
        for(GameObject* ib : iceblocks)
        {
            ib->DeleteLater();
        }
    }

    void DamageTaken(Unit* pDoneBy, uint32&) override 
    {
        if (m_creature->GetMeleeZLimit() < 1.0f)
        {
            if (pDoneBy->CanReachWithMeleeSpellAttack(m_creature))
            {
                pDoneBy->SendMeleeAttackStop(m_creature);
            }
        }
    }

    void MakeVisible()
    {
        phase = PHASE_GROUND;
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->SetInCombatWithZone();
        if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_NEAREST,0))
        {
            AttackStart(pUnit);
        }
        if (GameObject* pGO1 = GetClosestGameObjectWithEntry(m_creature, GO_SAPPHIRON_SPAWN, 200.0f))
        {
            pGO1->Delete();
            if (GameObject* pGO2 = GetClosestGameObjectWithEntry(m_creature, GO_SAPPHIRON_SPAWN, 200.0f))
                pGO2->Delete();
        }
    }

    void AttackStart(Unit* who) override
    {
        if (phase != PHASE_GROUND)
            return;

        ScriptedAI::AttackStart(who);
    }

    void StartSkeletonSummon()
    {
        phase = PHASE_SUMMONING;
        spawnTimer = SPAWN_ANIM_TIMER;
        // atm can only get the animation to play when summoning the gameobject. Thus, as a hack,
        // we remove the old skeleton and summon a new one temporarily.
        if (GameObject* skeleton = m_pInstance->GetSingleGameObjectFromStorage(GO_SAPPHIRON_SPAWN))
        {
            skeleton->Despawn();
            m_creature->SummonGameObject(GO_SAPPHIRON_SPAWN, skeleton->GetPositionX(), skeleton->GetPositionY(), skeleton->GetPositionZ(),
                skeleton->GetRotation(), 0, 0, 0, 0, SPAWN_ANIM_TIMER);
        }
        else
        {
            MakeVisible();
        }
    }

    void AggroRadius(uint32 diff)
    {
        if (m_creature->IsInCombat() || m_creature->IsInEvadeMode())
            return;

        if (phase != PHASE_GROUND && phase != PHASE_SKELETON)
            return;

        if (pullCheckTimer < diff)
        {
            pullCheckTimer = 1000;
        }
        else
        {
            pullCheckTimer -= diff;
            return;
        }

        float x, y, z, o;
        m_creature->GetHomePosition(x, y, z, o);

        // Large aggro radius
        Map::PlayerList const &PlayerList = m_creature->GetMap()->GetPlayers();
        for (const auto& itr : PlayerList)
        {
            Player* pPlayer = itr.getSource();

            float dx = pPlayer->GetPositionX() - x;
            float dy = pPlayer->GetPositionY() - y;
            float dz = pPlayer->GetPositionZ() - z;
            float dist = sqrt((dx * dx) + (dy * dy) + (dz * dz));
            dist = (dist > 0 ? dist : 0);
            if (dist > AGGRO_RADIUS)
                continue;

            bool alert;
            if (!pPlayer->IsVisibleForOrDetect(m_creature, m_creature, true, false, &alert))
                continue;

            if (!pPlayer->IsTargetable(true, false) || !m_creature->IsHostileTo(pPlayer))
                continue;

            if (phase == PHASE_SKELETON)
            {
                StartSkeletonSummon();
                return;
            }
            if (m_creature->CanInitiateAttack())
            {
                if (pPlayer->IsInAccessablePlaceFor(m_creature) && m_creature->IsWithinLOSInMap(pPlayer))
                {
                    if (!m_creature->GetVictim())
                    {
                        AttackStart(pPlayer);
                        return;
                    }
                    else if (m_creature->GetMap()->IsDungeon())
                    {
                        pPlayer->SetInCombatWith(m_creature);
                        m_creature->AddThreat(pPlayer);
                        return;
                    }
                }
            }
        }
    }

    void Aggro(Unit* pWho) override
    {
        if (phase != PHASE_GROUND)
            return;

        if (m_pInstance)
            m_pInstance->SetData(TYPE_SAPPHIRON, IN_PROGRESS);

        events.ScheduleEvent(EVENT_LIFEDRAIN, Seconds(12));
        events.ScheduleEvent(EVENT_BLIZZARD, Seconds(10));
        events.ScheduleEvent(EVENT_MOVE_TO_FLY, Seconds(40));
        events.ScheduleEvent(EVENT_TAIL_SWEEP, Seconds(12));
        events.ScheduleEvent(EVENT_CLEAVE, Seconds(5));
    }

    void JustDied(Unit* pKiller) override
    {
        m_creature->CastSpell(m_creature, SPELL_SAPPHIRON_DIES, true);
        UnSummonWingBuffet();
        DeleteAndDispellIceBlocks();
        if (m_pInstance)
            m_pInstance->SetData(TYPE_SAPPHIRON, DONE);
    }

    void RescheduleIcebolt()
    {
        if (++Icebolt_Count < 5)
            events.Repeat(3500);
        else
            events.ScheduleEvent(EVENT_FROST_BREATH_DUMMY, 1500);
    }

    void DoIceBolt()
    {
        ThreatList const& threatlist = m_creature->GetThreatManager().getThreatList();
        if (threatlist.size() <= iceboltTargets.size())
        {
            RescheduleIcebolt();
            return;
        }

        std::vector<Unit*> suitableUnits;
        for (const auto itr : threatlist)
            if (Unit* pTarget = m_creature->GetMap()->GetPlayer(itr->getUnitGuid()))
            {
                if (pTarget->IsDead())
                    continue;

                if (std::find(iceboltTargets.begin(), iceboltTargets.end(), pTarget->GetObjectGuid()) != iceboltTargets.end())
                    continue;

                suitableUnits.push_back(pTarget);
            }

        if (suitableUnits.empty())
        {
            RescheduleIcebolt();
            return;
        }

        auto it = suitableUnits.begin();
        std::advance(it, urand(0, suitableUnits.size() - 1));
        Unit* target = *it;

        iceboltTargets.push_back(target->GetObjectGuid());
        m_creature->SetFacingToObject(target);
        DoCastSpellIfCan(target, SPELL_ICEBOLT, CF_TRIGGERED);

        RescheduleIcebolt();
    }

    void MovementInform(uint32 uiType, uint32 pointId) override
    {
        if (pointId == MOVE_POINT_LIFTOFF && phase == PHASE_LIFT_OFF)
        {
            events.ScheduleEvent(EVENT_LIFTOFF, 250);
        }
    }

    void setHover(bool on, bool onReset = false)
    {
        if (on)
        {
            m_creature->InterruptNonMeleeSpells(false);
            m_creature->AttackStop();
            m_creature->RemoveAllAttackers();
            SetCombatMovement(false);
            m_creature->SetReactState(ReactStates::REACT_PASSIVE);
            m_creature->UpdateCombatState(false);

            m_creature->HandleEmote(EMOTE_ONESHOT_LIFTOFF);
            m_creature->SetHover(true);

            m_creature->m_TargetNotReachableTimer = 0;
            if (m_creature->GetTemporaryFactionFlags() & TEMPFACTION_RESTORE_COMBAT_STOP)
                m_creature->ClearTemporaryFaction();

            //m_creature->SetFly(true);
            //m_creature->SetLevitate(true);
            m_creature->SetMeleeZLimit(0.0f);
        }
        else
        {
            m_creature->RemoveAurasDueToSpell(17131);
            if (m_creature->HasUnitMovementFlag(MOVEFLAG_HOVER))
                m_creature->HandleEmote(EMOTE_ONESHOT_LAND);

            m_creature->SetHover(false);

            if (!onReset)
            {
                m_creature->UpdateCombatState(true);
                m_creature->SetReactState(ReactStates::REACT_AGGRESSIVE);
            }

            //m_creature->SetFly(false);
            //m_creature->SetLevitate(false);
            m_creature->SetMeleeZLimit(UNIT_DEFAULT_MELEE_Z_LIMIT);
        }
    }

    void UpdateReachable(uint32 update_diff)
    {
        bool unreachableTarget = 
            !m_creature->GetMotionMaster()->empty() &&
             m_creature->GetVictim() &&
             m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE &&
            !m_creature->HasDistanceCasterMovement() &&
           (!m_creature->IsWithinDistInMap(m_creature->GetVictim(), m_creature->GetMaxChaseDistance(m_creature->GetVictim())) || !m_creature->IsWithinLOSInMap(m_creature->GetVictim())) &&
            !m_creature->GetMotionMaster()->GetCurrent()->IsReachable();

        if (unreachableTarget)
        {
            m_TargetNotReachableTimer += update_diff;
        }
        else
            m_TargetNotReachableTimer = 0;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (phase == PHASE_SKELETON)
        {
            AggroRadius(uiDiff);
            return;
        }
        else if (phase == PHASE_SUMMONING)
        {
            if (spawnTimer < uiDiff)
            {
                MakeVisible();
            }
            else
            {
                spawnTimer -= uiDiff;
                return;
            }
        }

        if (phase == PHASE_GROUND)
        {
            AggroRadius(uiDiff);
            if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
                return;

            UpdateReachable(uiDiff);

            if (m_TargetNotReachableTimer > 10000)
            {
                EnterEvadeMode();
            }

            // hack to avoid bug where players cant see target of sapphiron after initial summoning
            if (m_forceTargetUpdateTimer)
            {
                if (m_forceTargetUpdateTimer < uiDiff)
                {
                    m_forceTargetUpdateTimer = 0;
                    m_creature->ForceValuesUpdateAtIndex(UNIT_FIELD_TARGET);
                }
                else
                    m_forceTargetUpdateTimer -= uiDiff;
            }
        }
        else 
        {
            if (m_creature->GetThreatManager().isThreatListEmpty())
            {
                EnterEvadeMode();
            }
        }

        if(!m_creature->HasAura(SPELL_FROST_AURA))
            m_creature->CastSpell(m_creature, SPELL_FROST_AURA, true);

        events.Update(uiDiff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_FLY: // MovementInform() will trigger liftoff after this
                    // He does not lift below 10%
                    if (m_creature->GetHealthPercent() > 10.0f)
                    {
                        events.Reset();
                        m_creature->ClearUnitState(UNIT_STAT_MELEE_ATTACKING);
                        m_creature->InterruptNonMeleeSpells(false);
                        m_creature->GetMotionMaster()->Clear(false);
                        m_creature->GetMotionMaster()->MoveIdle();
                        m_creature->GetMotionMaster()->MovePoint(MOVE_POINT_LIFTOFF, aLiftOffPosition[0], aLiftOffPosition[1], aLiftOffPosition[2]);
                        phase = PHASE_LIFT_OFF;
                        m_creature->SetTargetGuid(0);
                    }
                    break;
                case EVENT_LIFTOFF: // liftoff is triggered from MovementInform()
                {
                    phase = PHASE_AIR_BOLTS;
                    Icebolt_Count = 0;
                    events.ScheduleEvent(EVENT_ICEBOLT, Seconds(6));

                    if (Creature* pWG = m_creature->SummonCreature(NPC_WING_BUFFET, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pWG->CastSpell(pWG, SPELL_PERIODIC_BUFFET, true);
                        wingBuffetCreature = pWG->GetObjectGuid();
                    }

                    setHover(true);
                    break;
                }
                case EVENT_LAND:
                {
                    iceboltTargets.clear();
                    // in case something is delayed, and we're not finished 
                    // casting the frost breath
                    if (m_creature->IsNonMeleeSpellCasted())
                    {
                        events.Repeat(100);
                        return;
                    }
                    setHover(false);
                    //m_creature->GetMotionMaster()->MovePoint(MOVE_POINT_FLYPOINT, m_creature->GetPositionX(), m_creature->GetPositionY(), 137.7f, MOVE_PATHFINDING | MOVE_FLY_MODE);
                    phase = PHASE_LANDING;
                    events.ScheduleEvent(EVENT_LANDED, Seconds(4));
                    break;
                }
                case EVENT_LANDED:
                {
                    DeleteAndDispellIceBlocks();
                    events.Reset();
                    events.ScheduleEvent(EVENT_LIFEDRAIN, Seconds(3));
                    events.ScheduleEvent(EVENT_BLIZZARD, Seconds(1));
                    events.ScheduleEvent(EVENT_MOVE_TO_FLY, Seconds(urand(50, 70))); // Sampling videos show its 50-70sec between engaging after landing, and disengaging to fly again
                    events.ScheduleEvent(EVENT_TAIL_SWEEP, Seconds(12));
                    events.ScheduleEvent(EVENT_CLEAVE, Seconds(5));

                    SetCombatMovement(true);
                    m_creature->GetMotionMaster()->Clear(false);
                    m_creature->SelectHostileTarget();
                    phase = PHASE_GROUND;
                    break;
                }
                case EVENT_ICEBOLT:
                {
                    DoIceBolt();
                    break;
                }
                case EVENT_FROST_BREATH_DUMMY:
                {
                    // Looks like the wing buffet dissapears as he starts casting frost breath
                    UnSummonWingBuffet();
                    if (DoCastSpellIfCan(m_creature, SPELL_FROST_BREATH_DUMMY, CF_TRIGGERED) == CAST_OK)
                        events.ScheduleEvent(EVENT_FROST_BREATH_CAST, 500);
                    else
                        events.Repeat(100);
                    break;
                }
                case EVENT_FROST_BREATH_CAST:
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_FROST_BREATH) != CAST_OK)
                        events.Repeat(100);
                    else
                        events.ScheduleEvent(EVENT_LAND, 7000);
                    break;
                }
                case EVENT_BLIZZARD:
                {
                    if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER_NOT_GM))
                    {
                        int angle = urand(0, 360);
                        float x = pUnit->GetPositionX() + cos(angle * 0.01745f) * 5.0f;
                        float y = pUnit->GetPositionY() + sin(angle * 0.01745f) * 5.0f;
                        if (!m_creature->SummonCreature(NPC_BLIZZARD, x, y, 138.0f, 0, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            events.Repeat(100);
                        else
                            events.Repeat(Seconds(20));
                    }
                    break;
                }
                case EVENT_LIFEDRAIN:
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_LIFE_DRAIN) == CAST_OK)
                        events.Repeat(Seconds(24));
                    else
                        events.Repeat(100);
                    break;
                }
                case EVENT_TAIL_SWEEP:
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_TAIL_SWEEP) == CAST_OK)
                        events.Repeat(Seconds(urand(7, 10)));
                    else
                        events.Repeat(100);
                    break;
                }
                case EVENT_CLEAVE:
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                        events.Repeat(Seconds(urand(5, 10)));
                    else
                        events.Repeat(100);
                    break;
                }
            }
        }

        // Enrage can happen in any phase
        if (berserkTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BESERK) == CAST_OK)
            {
                DoScriptText(EMOTE_ENRAGE, m_creature);
                berserkTimer = 300000;
            }
        }
        else
            berserkTimer -= uiDiff;

        if (phase == PHASE_GROUND)
            DoMeleeAttackIfReady();
    }
};

struct npc_wing_buffetAI : public ScriptedAI
{
    npc_wing_buffetAI(Creature* pCreature) : ScriptedAI(pCreature) { }
    
    void Reset() override { }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->HasAura(SPELL_PERIODIC_BUFFET))
            m_creature->CastSpell(m_creature, SPELL_PERIODIC_BUFFET, true);
    }
};

struct npc_sapphiron_blizzardAI : public ScriptedAI
{
    npc_sapphiron_blizzardAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_creature->SetWanderDistance(60.0f);
        m_creature->SetReactState(ReactStates::REACT_PASSIVE);
        m_pInstance = (instance_naxxramas*)pCreature->GetInstanceData();
        checkAuraTimer = 0;
        events.ScheduleEvent(1, 10);
    }

    EventMap events;
    instance_naxxramas* m_pInstance;
    uint32 checkAuraTimer;
    std::vector<ObjectGuid> previousTargets;

    void Reset() override { }
    void JustRespawned() override { }
    void AttackStart(Unit*) override { }
    void MoveInLineOfSight(Unit*) override { }
    void Aggro(Unit*) override { }

    void MovementInform(uint32 uiType, uint32 pointId) override
    {
        events.Reset();
        PickNewTarget();
        events.ScheduleEvent(1, Seconds(8));
    }

    void SetRandomMove()
    {
        if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != RANDOM_MOTION_TYPE)
        {
            m_creature->GetMotionMaster()->Clear();
            m_creature->GetMotionMaster()->MoveRandom();
        }
    }

    void PickNewTarget()
    {
        // if no sapphiron, move random
        Creature* pSapp = nullptr;
        if(m_pInstance)
            pSapp = m_pInstance->GetSingleCreatureFromStorage(NPC_SAPPHIRON);

        if (!pSapp)
        {
            SetRandomMove();
            return;
        }

        // if only "tank" alive, move random
        ThreatList const& threatlist = pSapp->GetThreatManager().getThreatList();
        if (threatlist.size() < 2)
        {
            SetRandomMove();
            return;
        }

        std::vector<Unit*> suitableUnits;
        auto it = threatlist.begin();
        ++it; // skip tank
        for (it; it != threatlist.end(); ++it)
        {
            if (Unit* pTarget = m_pInstance->GetMap()->GetUnit((*it)->getUnitGuid()))
            {
                if (!pTarget->IsPlayer())
                    continue;
                if (std::find(previousTargets.begin(), previousTargets.end(), pTarget->GetObjectGuid()) != previousTargets.end())
                    continue;
                // want to encourage the blizzard to move towards a semi-far-away target to make it spread out
                if (m_creature->GetDistance3dToCenter(pTarget) < 15.0f)
                    continue;
                suitableUnits.push_back(pTarget);
            }
        }
        // when no suitable units found, we move random, this will generally only happen right before a wipe
        if (suitableUnits.empty())
        {
            SetRandomMove();
            return;
        }

        Unit* target = suitableUnits[urand(0, suitableUnits.size() - 1)];
        previousTargets.push_back(target->GetObjectGuid());
        m_creature->GetMotionMaster()->Clear();
        m_creature->GetMotionMaster()->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), MOVE_PATHFINDING);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (checkAuraTimer < uiDiff)
        {
            if (!m_creature->HasAura(SPELL_BLIZZARD_PERIODIC))
                m_creature->CastSpell(m_creature, SPELL_BLIZZARD_PERIODIC, true);
            checkAuraTimer = 2000;
        }
        else
            checkAuraTimer -= uiDiff;

        events.Update(uiDiff);

        if (events.ExecuteEvent())
        {
            PickNewTarget();
            events.Repeat(Seconds(urand(8,10)));
        }
    }
};

CreatureAI* GetAI_boss_sapphiron(Creature* pCreature)
{
    return new boss_sapphironAI(pCreature);
}

CreatureAI* GetAI_npc_wing_buffet(Creature* pCreature)
{
    return new npc_wing_buffetAI(pCreature);
}

CreatureAI* GetAI_npc_sapphironBlizzard(Creature* pCreature)
{
    return new npc_sapphiron_blizzardAI(pCreature);
}

void AddSC_boss_sapphiron()
{
    Script* NewScript;
    NewScript = new Script;
    NewScript->Name = "boss_sapphiron";
    NewScript->GetAI = &GetAI_boss_sapphiron;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "npc_sapphiron_wing_buffet";
    NewScript->GetAI = &GetAI_npc_wing_buffet;
    NewScript->RegisterSelf();

    NewScript = new Script;
    NewScript->Name = "npc_sapphiron_blizzard";
    NewScript->GetAI = &GetAI_npc_sapphironBlizzard;
    NewScript->RegisterSelf();
}

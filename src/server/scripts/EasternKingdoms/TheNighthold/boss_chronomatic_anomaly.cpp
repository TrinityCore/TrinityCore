///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "thenighthold.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//Position const anomalySumPos[12] =
//{
//    {236.42f, 3108.52f, -236.93f, 0.66f}, //108786
//    {277.72f, 3087.88f, -236.93f, 1.58f}, //108786
//    {315.29f, 3163.98f, -236.95f, 3.68f}, //108786
//    {232.46f, 3156.74f, -236.95f, 5.98f}, //108786
//    {228.15f, 3132.27f, -236.95f, 0.19f}, //108786
//    {248.43f, 3175.77f, -236.95f, 5.46f}, //108786
//    {254.49f, 3093.32f, -236.93f, 1.12f}, //108786
//    {271.78f, 3184.27f, -236.95f, 4.89f}, //108786
//    {296.25f, 3179.95f, -236.95f, 4.29f}, //108786
//    {303.50f, 3097.13f, -236.95f, 2.05f}, //108786
//    {319.47f, 3116.16f, -236.95f, 2.55f}, //108786
//    {323.78f, 3140.63f, -236.93f, 3.09f}  //108786
//};
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_NORMAL_TIME = 1,
//    SAY_ADDITIONAL = 2,
//    SAY_SUM_ADD = 3,
//
//    SAY_TEMP_ORB = 4,
//    SAY_POWER = 5,
//    SAY_DEATH = 6,
//    SAY_TIME_SLOW = 7,
//    SAY_TIME_FAST = 9,
//};
//
//enum Spells
//{
//    SPELL_PASSAGE_OF_TIME = 205653,
//
//    SPELL_SPEED_SLOW = 207011,
//    SPELL_SPEED_NORMAL = 207012,
//    SPELL_SPEED_FAST = 207013,
//    SPELL_BURST_OF_TIME = 219984,
//    SPELL_BURST_OF_TIME_NORMAL = 206613,
//    SPELL_BURST_OF_TIME_SLOW = 214049,
//    SPELL_BURST_OF_TIME_FAST = 214050,
//    SPELL_POWER_OVERWHELMING = 211927,
//    SPELL_POWER_OVERWHELMING_MOD = 219823,
//    SPELL_CHRONOMETRIC_PARTICLES = 206607,
//    SPELL_CHRONOMETRIC_OVERLOAD = 207491,
//    SPELL_TIME_RELEASE_FILTER = 206610,
//    SPELL_TIME_RELEASE_ABSORB = 206609,
//    SPELL_TIME_RELEASE_DMG = 206608,
//    SPELL_TIME_RELEASE_GREEN = 219964,
//    SPELL_TIME_RELEASE_YELLOW = 219965,
//    SPELL_TIME_RELEASE_RED = 219966,
//    SPELL_TIME_BOMB_FILTER = 206618,
//    SPELL_TIME_BOMB_DMG = 206615,
//    SPELL_SUM_SLOW_ADD_FILTER = 206700,
//    SPELL_SUM_SLOW_ADD = 206698,
//    SPELL_TEMPORAL_ORB = 219815,
//    SPELL_TEMPORAL_ORB_AT = 212874,
//    SPELL_TEMPORAL_ORB_AT_2 = 227217,
//    SPELL_TEMPORAL_SMASH_MOD = 222283,
//
//    SPELL_WARP_NIGHTWELL_BIG = 207228,
//    SPELL_WARP_NIGHTWELL_SMALL = 228335,
//    SPELL_CHRONOMATE = 219808,
//    SPELL_TEMPORAL_RIFT = 212072,
//    SPELL_SUM_TEMPORAL_RIFT = 212076,
//    SPELL_TEMPORAL_RIFT_VIS = 212090,
//};
//
//enum eEvents
//{
//    EVENT_BURST_OF_TIME = 1,
//    EVENT_CHRONOMETRIC_PARTICLES = 2,
//    EVENT_TIME_RELEASE = 3,
//    EVENT_TIME_BOMB = 4,
//    EVENT_SUM_SLOW_ADD = 5,
//    EVENT_TEMPORAL_ORB = 6,
//    EVENT_POWER_OVERWHELMING = 7,
//    //Mythic
//    EVENT_CHANGE_SPEED = 8
//};
//
//enum Misc
//{
//    EVENT_1 = 1,
//    EVENT_2,
//    EVENT_3,
//};
//
////104415
//class boss_chronomatic_anomaly : public CreatureScript
//{
//public:
//    boss_chronomatic_anomaly() : CreatureScript("boss_chronomatic_anomaly") {}
//
//    struct boss_chronomatic_anomalyAI : BossAI
//    {
//        boss_chronomatic_anomalyAI(Creature* creature) : BossAI(creature, DATA_ANOMALY) {}
//
//        std::list<Creature*> triggerList;
//        bool phaseOverwhelming = false;
//        uint8 timerBombCounter = 0;
//        uint8 timeReleaseCounter = 0;
//        uint8 temporalOrbCounter = 0;
//        uint8 speedCounter = 0;
//        uint32 anomalySpeed = 0;
//        uint32 burstTimer = 0;
//        uint32 burstSpell = 0;
//
//        void Reset() override
//        {
//            _Reset();
//            timerBombCounter = 0;
//            timeReleaseCounter = 0;
//            temporalOrbCounter = 0;
//            anomalySpeed = 0;
//            speedCounter = 0;
//            phaseOverwhelming = false;
//            me->SetReactState(REACT_DEFENSIVE);
//            me->RemoveAurasDueToSpell(SPELL_PASSAGE_OF_TIME);
//            RemoveAuras();
//
//            triggerList.clear();
//
//            for (const auto& anomalySumPo : anomalySumPos)
//            {
//                if (Creature* trigger = me->SummonCreature(NPC_SURAMAR_TRIG, anomalySumPo))
//                    triggerList.push_back(trigger);
//            }
//            me->SummonCreature(NPC_THE_NIGHTWELL, 276.35f, 3136.08f, -236.95f, 0.0f);
//            me->GetMotionMaster()->MovePath(9100413, true);
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            Talk(SAY_AGGRO);
//            _JustEngagedWith();
//            SetAnomalySpeed();
//            DoCast(me, SPELL_PASSAGE_OF_TIME, true);
//            instance->DoCastSpellOnPlayers(SPELL_PASSAGE_OF_TIME);
//
//            if (IsMythicRaid())
//            {
//                burstTimer = 3000;
//                events.RescheduleEvent(EVENT_BURST_OF_TIME, 2000);
//                events.RescheduleEvent(EVENT_CHANGE_SPEED, 12000);
//            }
//            else if (IsHeroicRaid())
//            {
//                burstTimer = 4000;
//                events.RescheduleEvent(EVENT_BURST_OF_TIME, 8000);
//            }
//            else
//            {
//                burstTimer = 5000;
//                events.RescheduleEvent(EVENT_BURST_OF_TIME, 14000);
//            }
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            Talk(SAY_DEATH);
//            _JustDied();
//            RemoveAuras();
//            if (Creature* talysra = me->GetMap()->GetCreature(instance->GetGuidData(NPC_TALYSRA)))
//                talysra->AI()->DoAction(ACTION_MOVE_AFTER_SECOND);
//        }
//
//        void RemoveAuras()
//        {
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPEED_SLOW);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPEED_NORMAL);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPEED_FAST);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PASSAGE_OF_TIME);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CHRONOMETRIC_PARTICLES);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TIME_RELEASE_ABSORB);
//            instance->DoRemoveAurasDueToSpellOnPlayers(212099);
//            instance->DoRemoveAurasDueToSpellOnPlayers(226845);
//            instance->DoRemoveAurasDueToSpellOnPlayers(206617);
//        }
//
//        void SpellFinishCast(const SpellInfo* spell)
//        {
//            if (spell->Id == SPELL_POWER_OVERWHELMING)
//                phaseOverwhelming = true;
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            //Temporal Rift
//            if (spell->Id == 212109 && phaseOverwhelming)
//            {
//                phaseOverwhelming = false;
//                me->SetReactState(REACT_AGGRESSIVE);
//                caster->CastSpell(caster, 212115, true);
//                caster->CastSpell(me, SPELL_TEMPORAL_SMASH_MOD, true);
//                me->InterruptNonMeleeSpells(false);
//                me->RemoveAurasDueToSpell(SPELL_POWER_OVERWHELMING_MOD);
//
//                AddDelayedEvent(1000, [this]() -> void
//                {
//                    if (me->IsAlive() && me->IsInCombat())
//                        SetAnomalySpeed();
//                });
//            }
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_BURST_OF_TIME)
//                DoCast(target, burstSpell, true);
//        }
//
//        uint32 GetData(uint32 type) const override
//        {
//            switch (type)
//            {
//            case DATA_ANOMALY_SPEED:
//                return anomalySpeed;
//            case DATA_ANOMALY_OVERWHELMING:
//                return phaseOverwhelming;
//            }
//            return 0;
//        }
//
//        void SetAnomalySpeed(bool mythicFast = false)
//        {
//            events.Reset();
//            timerBombCounter = 0;
//            timeReleaseCounter = 0;
//            temporalOrbCounter = 0;
//
//            if (!mythicFast)
//            {
//                if (!IsMythicRaid())
//                {
//                    if (anomalySpeed == SPELL_SPEED_NORMAL)
//                        anomalySpeed = SPELL_SPEED_SLOW;
//                    else if (anomalySpeed == SPELL_SPEED_SLOW)
//                        anomalySpeed = SPELL_SPEED_FAST;
//                    else
//                        anomalySpeed = SPELL_SPEED_NORMAL;
//                }
//                else
//                {
//                    switch (speedCounter)
//                    {
//                    case 0:
//                    case 3:
//                        anomalySpeed = SPELL_SPEED_NORMAL;
//                        break;
//                    case 1:
//                    case 4:
//                    case 6:
//                        anomalySpeed = SPELL_SPEED_SLOW;
//                        break;
//                    case 2:
//                    case 5:
//                        anomalySpeed = SPELL_SPEED_FAST;
//                        break;
//                    }
//                    speedCounter++;
//
//                    if (speedCounter > 6)
//                        speedCounter = 3;
//                }
//            }
//            else
//            {
//                anomalySpeed = SPELL_SPEED_FAST;
//                events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 7000);
//                events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 22000);
//            }
//
//            events.RescheduleEvent(EVENT_CHRONOMETRIC_PARTICLES, 10000);
//
//            switch (anomalySpeed)
//            {
//            case SPELL_SPEED_SLOW:
//                burstSpell = SPELL_BURST_OF_TIME_SLOW;
//                if (IsMythicRaid())
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 14000);
//                    events.RescheduleEvent(EVENT_TIME_BOMB, 16000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 28000);
//                    events.RescheduleEvent(EVENT_TEMPORAL_ORB, 8000);
//                    if (speedCounter > 3)
//                        events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 18000);
//                }
//                else if (IsHeroicRaid())
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 10000);
//                    events.RescheduleEvent(EVENT_TIME_BOMB, 15000);
//                    events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 43000);
//                    events.RescheduleEvent(EVENT_TEMPORAL_ORB, 20000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 53000);
//                }
//                else
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 5000);
//                    events.RescheduleEvent(EVENT_TIME_BOMB, 20000);
//                    events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 38000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 60000);
//                    events.RescheduleEvent(EVENT_TEMPORAL_ORB, 30000);
//                }
//                Talk(SAY_TIME_SLOW);
//                Talk(SAY_TIME_SLOW + 1);
//                break;
//            case SPELL_SPEED_NORMAL:
//                burstSpell = SPELL_BURST_OF_TIME_NORMAL;
//                if (IsMythicRaid())
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 10000);
//                    events.RescheduleEvent(EVENT_TIME_BOMB, 5000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 20000);
//                }
//                else if (IsHeroicRaid())
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 8000);
//                    events.RescheduleEvent(EVENT_TIME_BOMB, 28000);
//                    events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 23000);
//                    events.RescheduleEvent(EVENT_TEMPORAL_ORB, 38000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 53000);
//                }
//                else
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 8000);
//                    events.RescheduleEvent(EVENT_TIME_BOMB, 35000);
//                    events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 28000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 60000);
//                    events.RescheduleEvent(EVENT_TEMPORAL_ORB, 48000);
//                }
//                Talk(SAY_NORMAL_TIME);
//                Talk(SAY_ADDITIONAL);
//                break;
//            case SPELL_SPEED_FAST:
//                burstSpell = SPELL_BURST_OF_TIME_FAST;
//                if (IsMythicRaid())
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 5000);
//                    if (speedCounter == 3 || speedCounter == 6)
//                        events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 23000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 30000);
//                }
//                else if (IsHeroicRaid())
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 5000);
//                    events.RescheduleEvent(EVENT_TIME_BOMB, 17000);
//                    events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 38000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 53000);
//                }
//                else
//                {
//                    events.RescheduleEvent(EVENT_TIME_RELEASE, 10000);
//                    events.RescheduleEvent(EVENT_SUM_SLOW_ADD, 28000);
//                    events.RescheduleEvent(EVENT_TEMPORAL_ORB, 15000);
//                    events.RescheduleEvent(EVENT_POWER_OVERWHELMING, 60000);
//                }
//                Talk(SAY_TIME_FAST);
//                Talk(SAY_ADDITIONAL);
//                break;
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_BURST_OF_TIME:
//                    DoCast(me, SPELL_BURST_OF_TIME, true);
//                    events.RescheduleEvent(EVENT_BURST_OF_TIME, burstTimer);
//                    break;
//                case EVENT_CHRONOMETRIC_PARTICLES:
//                    DoCastVictim(SPELL_CHRONOMETRIC_PARTICLES);
//                    events.RescheduleEvent(EVENT_CHRONOMETRIC_PARTICLES, 6000);
//                    break;
//                case EVENT_TIME_RELEASE:
//                    DoCast(me, SPELL_TIME_RELEASE_FILTER, true);
//                    timeReleaseCounter++;
//                    if (timerBombCounter == 1)
//                    {
//                        if (anomalySpeed == SPELL_SPEED_NORMAL)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_RELEASE, 2000);
//                            else if (IsHeroicRaid())
//                                events.RescheduleEvent(EVENT_TIME_RELEASE, 30000);
//                            else
//                                events.RescheduleEvent(EVENT_TIME_RELEASE, 16000);
//                        }
//                        else if (anomalySpeed == SPELL_SPEED_SLOW)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_RELEASE, 7000);
//                            else if (IsHeroicRaid())
//                                events.RescheduleEvent(EVENT_TIME_RELEASE, 5000);
//                        }
//                    }
//                    break;
//                case EVENT_TIME_BOMB:
//                    DoCast(me, SPELL_TIME_BOMB_FILTER, true);
//                    timerBombCounter++;
//                    if (timerBombCounter == 1)
//                    {
//                        if (anomalySpeed == SPELL_SPEED_NORMAL)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 12000);
//                            else if (IsHeroicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 5000);
//                        }
//                        else if (anomalySpeed == SPELL_SPEED_SLOW)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 2000);
//                            else if (IsHeroicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 20000);
//                        }
//                        else if (anomalySpeed == SPELL_SPEED_FAST)
//                        {
//                            if (IsHeroicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 30000);
//                        }
//                    }
//                    else if (timerBombCounter == 2)
//                    {
//                        if (anomalySpeed == SPELL_SPEED_NORMAL)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 5000);
//                        }
//                        else if (anomalySpeed == SPELL_SPEED_SLOW)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 7000);
//                        }
//                    }
//                    else if (timerBombCounter == 3)
//                    {
//                        if (anomalySpeed == SPELL_SPEED_NORMAL)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 7000);
//                        }
//                        else if (anomalySpeed == SPELL_SPEED_SLOW)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 20000);
//                        }
//                    }
//                    else if (timerBombCounter == 4)
//                    {
//                        if (anomalySpeed == SPELL_SPEED_NORMAL)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 2000);
//                        }
//                        else if (anomalySpeed == SPELL_SPEED_SLOW)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TIME_BOMB, 3000);
//                        }
//                    }
//                    break;
//                case EVENT_SUM_SLOW_ADD:
//                {
//                    Talk(SAY_SUM_ADD);
//                    DoCast(me, SPELL_SUM_SLOW_ADD_FILTER, true);
//                    uint8 counter = 0;
//                    uint8 randCounter = urand(6, 7);
//                    Creature* firstTrigger = nullptr;
//
//                    for (auto const& creature : triggerList)
//                    {
//                        firstTrigger = creature;
//                        break;
//                    }
//
//
//                    for (auto const& creature : triggerList)
//                    {
//                        counter++;
//
//                        if (IsMythicRaid())
//                        {
//                            if (counter == 6 || counter == 7)
//                            {
//                                if (Creature* sum = ObjectAccessor::GetCreature(*me, creature->GetGUID()))
//                                    DoCast(sum, SPELL_SUM_SLOW_ADD, true);
//                            }
//                        }
//                        else
//                        {
//                            if (counter == randCounter)
//                            {
//                                if (Creature* sum = ObjectAccessor::GetCreature(*me, creature->GetGUID()))
//                                    DoCast(sum, SPELL_SUM_SLOW_ADD, true);
//                            }
//                        }
//                    }
//                    break;
//                }
//                case EVENT_TEMPORAL_ORB:
//                {
//                    Talk(SAY_TEMP_ORB);
//                    DoCast(SPELL_TEMPORAL_ORB);
//                    temporalOrbCounter++;
//                    if (temporalOrbCounter == 1)
//                    {
//                        if (anomalySpeed == SPELL_SPEED_NORMAL)
//                        {
//                            if (IsMythicRaid())
//                                events.RescheduleEvent(EVENT_TEMPORAL_ORB, 14000);
//                        }
//                        else if (anomalySpeed == SPELL_SPEED_SLOW)
//                        {
//                            if (IsHeroicPlusRaid())
//                                events.RescheduleEvent(EVENT_TEMPORAL_ORB, 15000);
//                        }
//                    }
//                    break;
//                }
//                case EVENT_POWER_OVERWHELMING:
//                    events.Reset();
//                    me->AttackStop();
//                    DoCast(SPELL_POWER_OVERWHELMING);
//                    Talk(SAY_POWER);
//                    break;
//                case EVENT_CHANGE_SPEED:
//                    SetAnomalySpeed(true);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_chronomatic_anomalyAI(creature);
//    }
//};
//
////104676
//class npc_anomaly_waning_time_particle : public CreatureScript
//{
//public:
//    npc_anomaly_waning_time_particle() : CreatureScript("npc_anomaly_waning_time_particle") {}
//
//    struct npc_anomaly_waning_time_particleAI : public ScriptedAI
//    {
//        npc_anomaly_waning_time_particleAI(Creature* creature) : ScriptedAI(creature), despawn(false)
//        {
//            instance = me->GetInstanceScript();
//            me->SetDisplayId(68616);
//            me->SetReactState(REACT_PASSIVE);
//            me->AddUnitState(UNIT_STATE_ROOT);
//            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
//            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//        }
//
//        InstanceScript* instance;
//        EventMap events;
//        bool despawn = false;
//        bool interruptActive = false;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//            events.RescheduleEvent(EVENT_1, 2000);
//        }
//
//        void OnInterruptCast(Unit* caster, uint32 /*spellId*/, uint32 curSpellID, uint32 /*schoolMask*/)
//        {
//            if (curSpellID == SPELL_WARP_NIGHTWELL_BIG)
//            {
//                if (me->GetHealthPct() > 30)
//                {
//                    events.RescheduleEvent(EVENT_2, 1000);
//                    AttackStart(caster);
//                }
//            }
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (IsHeroicPlusRaid() && !interruptActive && me->GetHealthPct() <= 30)
//            {
//                interruptActive = true;
//                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
//                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
//            }
//
//            if (damage >= me->GetHealth())
//            {
//                damage = 0;
//                me->SetHealth(me->CountPctFromMaxHealth(5));
//
//                if (!despawn)
//                {
//                    despawn = true;
//                    events.Reset();
//                    me->InterruptNonMeleeSpells(false);
//                    me->AttackStop();
//                    me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//                    me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                    DoCast(me, 199615, true); //Fade
//                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//
//                    if (Unit* owner = me->GetOwner())
//                    {
//                        me->CastSpell(me, SPELL_SUM_TEMPORAL_RIFT, true);
//                        Position pos;
//                        float angle = 1.57f;
//                        for (uint8 i = 0; i < 4; i++)
//                        {
//                            me->GetNearPosition(6.0f, angle);
//                            owner->SummonCreature(NPC_FRAGMENTED_TIME, pos);
//                            angle += 1.57f;
//                        }
//                    }
//                    events.RescheduleEvent(EVENT_3, 3000);
//                }
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    me->AttackStop();
//                    if (Creature* nightwell = me->FindNearestCreature(NPC_THE_NIGHTWELL, 100.0f))
//                        me->SetFacingToObject(nightwell);
//                    DoCast(SPELL_WARP_NIGHTWELL_BIG);
//                    events.RescheduleEvent(EVENT_1, 5000);
//                    break;
//                case EVENT_2:
//                    DoCastVictim(SPELL_CHRONOMATE);
//                    break;
//                case EVENT_3:
//                    me->DespawnOrUnsummon(100);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_anomaly_waning_time_particleAI(creature);
//    }
//};
//
////114671
//class npc_anomaly_fragmented_time : public CreatureScript
//{
//public:
//    npc_anomaly_fragmented_time() : CreatureScript("npc_anomaly_fragmented_time") {}
//
//    struct npc_anomaly_fragmented_timeAI : public ScriptedAI
//    {
//        npc_anomaly_fragmented_timeAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->AddUnitState(UNIT_STATE_ROOT);
//            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
//            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//        }
//
//        EventMap events;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            events.RescheduleEvent(EVENT_1, 1000);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    DoCast(SPELL_WARP_NIGHTWELL_SMALL);
//                    events.RescheduleEvent(EVENT_1, 5000);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_anomaly_fragmented_timeAI(creature);
//    }
//};
//
////106878
//class npc_anomaly_temporal_rift : public CreatureScript
//{
//public:
//    npc_anomaly_temporal_rift() : CreatureScript("npc_anomaly_temporal_rift") {}
//
//    struct npc_anomaly_temporal_riftAI : public ScriptedAI
//    {
//        npc_anomaly_temporal_riftAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            click = false;
//        }
//
//        bool click;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner)
//        {
//            DoCast(me, SPELL_TEMPORAL_RIFT_VIS, true);
//        }
//
//       /* void OnSpellClick(Unit* clicker)
//        {
//            if (!click && !clicker->HasAura(226845))
//            {
//                click = true;
//                clicker->CastSpell(clicker, 212099, true);
//                me->DespawnOrUnsummon(100);
//            }
//        }*/
//
//        void UpdateAI(uint32 diff) {}
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_anomaly_temporal_riftAI(creature);
//    }
//};
//
////205653
//class spell_anomaly_passage_of_time : public SpellScriptLoader
//{
//public:
//    spell_anomaly_passage_of_time() : SpellScriptLoader("spell_anomaly_passage_of_time") {}
//
//    class spell_anomaly_passage_of_time_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_anomaly_passage_of_time_AuraScript);
//
//        uint32 tempData = 0;
//
//        void OnTick(AuraEffect const* aurEff)
//        {
//            if (!GetCaster())
//                return;
//
//            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//            {
//                if (Creature* anomaly = instance->instance->GetCreature(instance->GetGuidData(DATA_ANOMALY)))
//                {
//                    if (anomaly->IsInCombat() && tempData != anomaly->GetAI()->GetData(DATA_ANOMALY_SPEED))
//                    {
//                        tempData = anomaly->GetAI()->GetData(DATA_ANOMALY_SPEED);
//                        GetCaster()->CastSpell(GetCaster(), tempData, true);
//
//                        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(tempData, DIFFICULTY_NONE))
//                        {
//                            if (AuraEffect* aurEffb = GetAura()->GetEffect(EFFECT_2))
//                                aurEffb->ChangeAmount(spellInfo->GetEffect(EFFECT_0)->BasePoints);
//                        }
//                    }
//                }
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_anomaly_passage_of_time_AuraScript::OnTick, EFFECT_3, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_anomaly_passage_of_time_AuraScript();
//    }
//};
//
////219984
//class spell_anomaly_burst_of_time : public SpellScriptLoader
//{
//public:
//    spell_anomaly_burst_of_time() : SpellScriptLoader("spell_anomaly_burst_of_time") { }
//
//    class spell_anomaly_burst_of_time_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_anomaly_burst_of_time_SpellScript);
//
//        void FilterTargets(std::list<WorldObject*>& targets)
//        {
//            if (!GetCaster())
//                return;
//
//            uint8 playerCount = GetCaster()->GetMap()->GetPlayersCountExceptGMs();
//            uint8 rCount;
//
//            if (playerCount > 25)
//                rCount = 5;
//            else if (playerCount > 15)
//                rCount = 4;
//            else
//                rCount = 3;
//
//            if (targets.size() > rCount)
//                Trinity::Containers::RandomResize(targets, rCount);
//        }
//
//        void Register() override
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anomaly_burst_of_time_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_anomaly_burst_of_time_SpellScript();
//    }
//};
//
////206607
//class spell_anomaly_chronometric_particles : public SpellScriptLoader
//{
//public:
//    spell_anomaly_chronometric_particles() : SpellScriptLoader("spell_anomaly_chronometric_particles") {}
//
//    class spell_anomaly_chronometric_particles_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_anomaly_chronometric_particles_AuraScript);
//
//        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//        {
//            if (!GetCaster() || !GetTarget())
//                return;
//
//            if (Aura* aura = aurEff->GetBase())
//                if (aura->GetStackAmount() == GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints)
//                    GetCaster()->CastSpell(GetTarget(), SPELL_CHRONOMETRIC_OVERLOAD, true);
//        }
//
//        void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_anomaly_chronometric_particles_AuraScript::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAPPLY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_anomaly_chronometric_particles_AuraScript();
//    }
//};
//
////206610
//class spell_anomaly_time_release_filter : public SpellScriptLoader
//{
//public:
//    spell_anomaly_time_release_filter() : SpellScriptLoader("spell_anomaly_time_release_filter") { }
//
//    class spell_anomaly_time_release_filter_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_anomaly_time_release_filter_SpellScript);
//
//        uint8 count;
//
//        void FilterTargets(std::list<WorldObject*>& targets)
//        {
//            if (GetCaster())
//            {
//                if (GetCaster()->HasAura(SPELL_SPEED_NORMAL))
//                    count = 4;
//                else if (GetCaster()->HasAura(SPELL_SPEED_FAST))
//                    count = 2;
//                else
//                    count = 0;
//
//                if (count != 0 && targets.size() > count)
//                    Trinity::Containers::RandomResize(targets, count);
//            }
//        }
//
//
//        void Register() override
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anomaly_time_release_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_anomaly_time_release_filter_SpellScript();
//    }
//};
//
////206609
//class spell_anomaly_time_release : public SpellScriptLoader
//{
//public:
//    spell_anomaly_time_release() : SpellScriptLoader("spell_anomaly_time_release") {}
//
//    class spell_anomaly_time_release_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_anomaly_time_release_AuraScript);
//
//        uint32 absorb = 0;
//
//        void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
//        {
//            if (GetTarget())
//            {
//                int32 newAbsorb = aurEff->GetAmount() - absorbAmount;
//
//                if (newAbsorb > absorb * 0.66)
//                {
//                    if (GetTarget()->HasAura(SPELL_TIME_RELEASE_RED))
//                    {
//                        if (AuraEffect* aurEffb = GetTarget()->GetAura(SPELL_TIME_RELEASE_RED)->GetEffect(0))
//                            aurEffb->SetAmount(newAbsorb);
//                    }
//                    else
//                        GetTarget()->CastCustomSpell(SPELL_TIME_RELEASE_RED, SPELLVALUE_BASE_POINT0, newAbsorb);
//                }
//                else if (newAbsorb > absorb * 0.33)
//                {
//                    if (GetTarget()->HasAura(SPELL_TIME_RELEASE_YELLOW))
//                    {
//                        if (AuraEffect* aurEffb = GetTarget()->GetAura(SPELL_TIME_RELEASE_YELLOW)->GetEffect(0))
//                            aurEffb->SetAmount(newAbsorb);
//                    }
//                    else
//                        GetTarget()->CastCustomSpell(SPELL_TIME_RELEASE_YELLOW, SPELLVALUE_BASE_POINT0, newAbsorb);
//                }
//                else
//                {
//                    if (GetTarget()->HasAura(SPELL_TIME_RELEASE_GREEN))
//                    {
//                        if (AuraEffect* aurEffb = GetTarget()->GetAura(SPELL_TIME_RELEASE_GREEN)->GetEffect(0))
//                            aurEffb->SetAmount(newAbsorb);
//                    }
//                    else
//                        GetTarget()->CastCustomSpell(SPELL_TIME_RELEASE_GREEN, SPELLVALUE_BASE_POINT0, newAbsorb);
//                }
//            }
//        }
//
//        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//        {
//            if (GetTarget() && !absorb)
//            {
//                absorb = aurEff->GetAmount();
//                GetTarget()->CastCustomSpell(SPELL_TIME_RELEASE_RED, SPELLVALUE_BASE_POINT0, absorb);
//            }
//        }
//
//        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//        {
//            if (GetTarget())
//            {
//                GetTarget()->RemoveAurasDueToSpell(SPELL_TIME_RELEASE_GREEN);
//                GetTarget()->RemoveAurasDueToSpell(SPELL_TIME_RELEASE_RED);
//                GetTarget()->RemoveAurasDueToSpell(SPELL_TIME_RELEASE_YELLOW);
//
// 
//            }
//        }
//
//        void Register() override
//        {
//            AfterEffectAbsorb += AuraEffectAbsorbFn(spell_anomaly_time_release_AuraScript::Absorb, EFFECT_0);
//            OnEffectApply += AuraEffectApplyFn(spell_anomaly_time_release_AuraScript::OnApply, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
//            OnEffectRemove += AuraEffectRemoveFn(spell_anomaly_time_release_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_anomaly_time_release_AuraScript();
//    }
//};
//
//
////206618
//class spell_anomaly_time_bomb_filter : public SpellScriptLoader
//{
//public:
//    spell_anomaly_time_bomb_filter() : SpellScriptLoader("spell_anomaly_time_bomb_filter") {}
//
//    class spell_anomaly_time_bomb_filter_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_anomaly_time_bomb_filter_SpellScript);
//
//        uint8 count;
//
//        void FilterTargets(std::list<WorldObject*>& targets)
//        {
//            if (GetCaster())
//            {
//                if (GetCaster()->GetVictim() && targets.size() > 1)
//                    targets.remove(GetCaster()->GetVictim());
//
//                if (GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
//                    count = 2;
//                else
//                    count = 1;
//
//                if (targets.size() > count)
//                    Trinity::Containers::RandomResize(targets, count);
//            }
//        }
//
//        void Register() override
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anomaly_time_bomb_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_anomaly_time_bomb_filter_SpellScript();
//    }
//};
//
////206617
//class spell_anomaly_time_bomb : public SpellScriptLoader
//{
//public:
//    spell_anomaly_time_bomb() : SpellScriptLoader("spell_anomaly_time_bomb") {}
//
//    class spell_anomaly_time_bomb_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_anomaly_time_bomb_AuraScript);
//
//        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//        {
//            if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
//                if (GetTarget())
//                    GetTarget()->CastSpell(GetTarget(), SPELL_TIME_BOMB_DMG, true);
//        }
//
//        void Register() override
//        {
//            OnEffectRemove += AuraEffectRemoveFn(spell_anomaly_time_bomb_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_anomaly_time_bomb_AuraScript();
//    }
//};
//
////206615
//class spell_anomaly_time_bomb_dmg : public SpellScriptLoader
//{
//public:
//    spell_anomaly_time_bomb_dmg() : SpellScriptLoader("spell_anomaly_time_bomb_dmg") {}
//
//    class spell_anomaly_time_bomb_dmg_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_anomaly_time_bomb_dmg_SpellScript);
//
//        void HandleDamage(SpellEffIndex /*effIndex*/)
//        {
//            if (!GetCaster() || !GetHitUnit())
//                return;
//
//            float distance = GetCaster()->GetExactDist2d(GetHitUnit());
//            float radius = GetSpellInfo()->GetEffect(EFFECT_0)->CalcRadius(GetCaster());
//            uint32 perc = 30;
//            if (distance < 100.0f)
//                perc = 100 - (distance / radius) * 70;
//
//            uint32 damage = CalculatePct(GetHitDamage(), perc);
//            SetHitDamage(damage);
//        }
//
//        void Register() override
//        {
//            OnEffectHitTarget += SpellEffectFn(spell_anomaly_time_bomb_dmg_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_anomaly_time_bomb_dmg_SpellScript();
//    }
//};
//
////219815
//class spell_anomaly_temporal_orb : public SpellScriptLoader
//{
//public:
//    spell_anomaly_temporal_orb() : SpellScriptLoader("spell_anomaly_temporal_orb") {}
//
//    class spell_anomaly_temporal_orb_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_anomaly_temporal_orb_AuraScript);
//
//        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
//        {
//            Unit* caster = GetCaster();
//            if (!caster || !GetTarget() || !caster->IsAlive() || !caster->IsInCombat())
//                return;
//
//            if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
//            {
//                Position pos;
//                float angle = 3.14f;
//                for (uint8 i = 0; i < 36; i++)
//                {
//                    GetTarget()->GetNearPosition(20.0f, angle);
//                    caster->CastSpell(pos, SPELL_TEMPORAL_ORB_AT, true);
//
//                    GetTarget()->GetNearPosition(20.0f, angle + 0.08525f);
//
//                    uint32 spellID = SPELL_TEMPORAL_ORB_AT_2;
//                    AddDelayedEvent(2000, [caster, pos, spellID]() -> void
//                    {
//                        if (!caster)
//                            return;
//
//                        if (caster->IsAlive() && caster->IsInCombat())
//                            caster->CastSpell(pos, spellID, true);
//                    });
//                    angle += 0.1744f;
//                }
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectRemove += AuraEffectApplyFn(spell_anomaly_temporal_orb_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_anomaly_temporal_orb_AuraScript();
//    }
//};
//
////212109
//class spell_anomaly_temporal_smash : public SpellScriptLoader
//{
//public:
//    spell_anomaly_temporal_smash() : SpellScriptLoader("spell_anomaly_temporal_smash") {}
//
//    class spell_anomaly_temporal_smash_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_anomaly_temporal_smash_SpellScript);
//
//        SpellCastResult CheckRequirement()
//        {
//            Unit* target = GetExplTargetUnit();
//            if (!target)
//                return SPELL_FAILED_BAD_TARGETS;
//
//            if (Creature* creature = target->ToCreature())
//            {
//                if (!creature || creature->GetEntry() != NPC_CHRONOMATIC_ANOMALY || !creature->GetAI()->GetData(DATA_ANOMALY_OVERWHELMING))
//                    return SPELL_FAILED_BAD_TARGETS;
//            }
//
//            return SPELL_CAST_OK;
//        }
//
//        void Register() override
//        {
//            OnCheckCast += SpellCheckCastFn(spell_anomaly_temporal_smash_SpellScript::CheckRequirement);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_anomaly_temporal_smash_SpellScript();
//    }
//};
//
////226845
//class spell_anomaly_temporal_charge_remove : public AuraScript
//{
//    PrepareAuraScript(spell_anomaly_temporal_charge_remove);
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (!GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
//            return;
//
//        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
//            if (Creature* anomaly = instance->instance->GetCreature(instance->GetGuidData(DATA_ANOMALY)))
//                if (instance->GetBossState(DATA_ANOMALY) == IN_PROGRESS)
//                    GetTarget()->CastSpell(GetTarget(), SPELL_SUM_TEMPORAL_RIFT, true, nullptr, nullptr, anomaly->GetGUID());
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_anomaly_temporal_charge_remove::OnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_SPELLS, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
//void AddSC_boss_chronomatic_anomaly()
//{
//    new boss_chronomatic_anomaly();
//    new npc_anomaly_waning_time_particle();
//    new npc_anomaly_fragmented_time();
//    new npc_anomaly_temporal_rift();
//    new spell_anomaly_passage_of_time();
//    new spell_anomaly_burst_of_time();
//    new spell_anomaly_chronometric_particles();
//    new spell_anomaly_time_release_filter();
//    new spell_anomaly_time_release();
//    new spell_anomaly_time_bomb_filter();
//    new spell_anomaly_time_bomb();
//    new spell_anomaly_time_bomb_dmg();
//    new spell_anomaly_temporal_orb();
//    new spell_anomaly_temporal_smash();
//    RegisterAuraScript(spell_anomaly_temporal_charge_remove);
//}

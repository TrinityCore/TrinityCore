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
//#include "AreaTriggerAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerTemplate.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//#include "G3D/Vector3.h"
//
//enum Says
//{
//    SAY_INTRO                               = 0,
//    SAY_AGGRO                               = 1,
//    SAY_ARCANETIC_RING                      = 2,
//    SAY_ARCANETIC_RING_WARN                 = 3,
//    SAY_SPANNING_SINGULARITY                = 4,
//    SAY_CHANGE_PHASE_2                      = 5,
//    SAY_CHANGE_PHASE_3                      = 6,
//    SAY_EPOCHERIC_ORB                       = 7,
//    SAY_EPOCHERIC_ORB_WARN                  = 8,
//    SAY_DELPHURIC_BEAM                      = 9,
//    SAY_DELPHURIC_BEAM_WARN                 = 10,
//    SAY_CONFLEXIVE_BURST                    = 11,
//    SAY_CONFLEXIVE_BURST_WARN               = 12,
//    SAY_PLAYER_DEATH                        = 13,
//    SAY_DEATH                               = 14,
//    SAY_EVADE                               = 15,
//    SAY_UNK_16                              = 16,
//    SAY_UNK_17                              = 17,
//    SAY_UNK_18                              = 18,
//};
//
//enum Spells
//{
//    SPELL_CONVERS_INTRODUCTION              = 210739, //Enter room or kill all trash?
//    SPELL_TERMINATE                         = 229886, //Berserk
//    SPELL_TERMINATE_AT                      = 229889,
//    SPELL_TERMINATE_KILL                    = 229887,
//
//    SPELL_ETCHED_IN_TIME                    = 208861,
//    SPELL_LEAVE_NIGHTWELL_FILTER            = 208863,
//    SPELL_LEAVE_NIGHTWELL                   = 208866,
//    SPELL_LEAVE_NIGHTWELL_END               = 208867,
//    SPELL_LEAVE_NIGHTWELL_REMOVE_DISSOLVE   = 225485,
//    SPELL_CLEARALLDEBUFFS                   = 34098,
//    SPELL_TIME_STOP                         = 208944,
//    SPELL_TIME_STOP_ENERGY_COST             = 211647,
//    SPELL_DISAPPEAR_VISUAL                  = 209026,
//    SPELL_TIME_LAYER_CHANGE                 = 209030, //From player visual
//
//    SPELL_SUM_TIME_ELEMENTAL_SLOW_DUMMY     = 211614,
//    SPELL_SUM_TIME_ELEMENTAL_SLOW           = 209005,
//    SPELL_SUM_TIME_ELEMENTAL_FAST_DUMMY     = 211616,
//    SPELL_SUM_TIME_ELEMENTAL_FAST           = 209007,
//
//    SPELL_SPANNING_SINGULARITY_AT           = 209500,
//    SPELL_SPANNING_SINGULARITY_FILTER       = 209168,
//    SPELL_SPANNING_SINGULARITY_NORMAL_2S    = 209169, //Normal, cast 2secs
//    SPELL_SPANNING_SINGULARITY_NORMAL_0S    = 233010, //Normal, cast 0secs
//    SPELL_SPANNING_SINGULARITY_LFR_2S       = 209186, //LFR, cast 2secs
//    SPELL_SPANNING_SINGULARITY_LFR_0S       = 233009, //LFR, cast 0secs
//    SPELL_SPANNING_SINGULARITY_HEROIC_2S    = 209170, //Heroic, cast 2secs
//    SPELL_SPANNING_SINGULARITY_HEROIC_0S    = 233011, //Heroic, cast 0secs
//    SPELL_SPANNING_SINGULARITY_MYTHIC_2S    = 209171, //Mythic, cast 2secs
//    SPELL_SPANNING_SINGULARITY_MYTHIC_0S    = 233013, //Mythic, cast 0secs
//
//    SPELL_CASCADENT_STAR                    = 229738,
//    SPELL_CASCADENT_STAR_FILTER             = 229739,
//    SPELL_CASCADENT_STAR_VISUAL             = 229740,
//    SPELL_CASCADENT_STAR_DMG                = 229741,
//
//    SPELL_ABLATION                          = 209615, //Phase 1
//    SPELL_ABLATING_EXPLOSION                = 209973, //Phase 2
//    SPELL_ABLATING_EXPLOSION_DMG            = 211799,
//    SPELL_ABLATIVE_PULSE                    = 209971, //Phase 3
//    SPELL_ABLATIVE_PULSE_ABLATED            = 211887,
//
//    SPELL_ARCANETIC_TELEPORT                = 228879,
//    SPELL_ARCANETIC_RING_DUMMY              = 208807,
//    SPELL_ARCANETIC_RING_DUMMY_CAST         = 228877,
//    SPELL_ARCANETIC_RING_FILTER             = 208808,
//    SPELL_ARCANETIC_RING_AT                 = 208666,
//
//    SPELL_DELPHURIC_BEAM_FILTER             = 209242,
//    SPELL_DELPHURIC_BEAM_MARK               = 209244, //On Player
//    SPELL_DELPHURIC_BEAM                    = 214278, //On Boss
//    SPELL_DELPHURIC_BEAM_DMG                = 209248,
//
//    SPELL_EPOCHERIC_ORB_FILTER              = 210022,
//    SPELL_EPOCHERIC_ORB_MISSLE_NORMAL       = 210588, //108
//    SPELL_EPOCHERIC_ORB_MISSLE_HEROIC       = 228949, //107
//    SPELL_EPOCHERIC_ORB_MISSLE_MYTHIC       = 210589, //106
//    SPELL_EPOCHERIC_ORB_SMALL_DMG           = 210024,
//    SPELL_EPOCHERIC_ORB_BIG_DMG             = 210546,
//    SPELL_EPOCHERIC_VULNERABILITY           = 227856, //Mythic
//
//    SPELL_PERMELIATIVE_TORMENT_FILTER       = 210387, //2 targets
//    SPELL_PERMELIATIVE_TORMENT_FILTER_2     = 225653, //Unlimited targets. wtf?
//    SPELL_PERMELIATIVE_TORMENT_DOT          = 211261,
//
//    SPELL_CONFLEXIVE_BURST_FILTER           = 209597,
//    SPELL_CONFLEXIVE_BURST_AURA             = 209598,
//    SPELL_CONFLEXIVE_BURST_DMG              = 209599,
//
//    //Echo Elisande
//    SPELL_TIME_ECHO_VISUAL                  = 209292,
//    SPELL_DISSOLVE_VISUAL                   = 209267,
//    SPELL_TIME_ECHO_WAIT_STATE_SINGULAR     = 225712, //105622
/////105364
//    SPELL_TIME_ECHO_WAIT_STATE_RING         = 225471,
//    SPELL_ECHO_ARCANETIC_RING               = 209330,
/////105624
//    SPELL_TIME_ECHO_WAIT_STATE_BEAM         = 225494,
//    SPELL_ECHO_DELPHURIC_BEAM               = 214295,
/////106680
//    SPELL_TIME_ECHO_WAIT_STATE_ORB          = 225508,
/////105958
//    SPELL_ECHO_EPOCHERIC_ORB                = 213739,
//
//    //Recursive Elemental
//    SPELL_CHANGE_MODE_TIME_ELEMENTAL_SLOW   = 208914,
//    SPELL_BLAST                             = 221864,
//    SPELL_TIME_ELEMENTAL_DIES_SLOW_AT       = 209881,
//    SPELL_TIME_SLOW                         = 209165,
//    SPELL_RECURSION                         = 209620, //Mythic
//
//    //Expedient Elemental
//    SPELL_CHANGE_MODE_TIME_ELEMENTAL_FAST   = 208916,
//    SPELL_EXOTHERMIC_RELEASE_FILTER         = 209571, //Deprecated?
//    SPELL_EXOTHERMIC_RELEASE                = 209568,
//    SPELL_TIME_ELEMENTAL_DIES_FAST_AT       = 209882,
//    SPELL_TIME_FAST                         = 209166,
//    SPELL_EXPEDITE_FILTER                   = 209617, //Mythic
//    SPELL_EXPEDITE                          = 209618,
//
//    //Epocheric Orb
//    SPELL_EPOCHERIC_ORB_VISUAL              = 213955,
//    SPELL_EPOCHERIC_ORB_AT                  = 213956,
//};
//
//enum eEvents
//{
//    EVENT_CHANGE_PHASE_1                    = 1,
//    EVENT_CHANGE_PHASE_2                    = 2,
//    EVENT_CHANGE_PHASE_3                    = 3,
//    EVENT_CHANGE_PHASE_4                    = 4,
//    EVENT_SPANNING_SINGULARITY              = 5,
//    EVENT_CASCADENT_STAR                    = 6,
//    EVENT_ABLATION                          = 7,
//    EVENT_ARCANETIC_RING                    = 8,
//    EVENT_SUM_SLOW_ELEMENTAL                = 9,
//    EVENT_SUM_FAST_ELEMENTAL                = 10,
//    EVENT_DELPHURIC_BEAM                    = 11,
//    EVENT_EPOCHERIC_ORB                     = 12,
//    EVENT_ABLATING_EXPLOSION                = 13,
//    EVENT_ABLATIVE_PULSE                    = 14,
//    EVENT_PERMELIATIVE_TORMENT              = 15,
//    EVENT_CONFLEXIVE_BURST                  = 16,
//};
//
//Position const centrPos = { 282.31f, 3135.51f, 226.84f };
//
//Position const ringPos[25] =
//{
//    {224.39f, 3128.61f, 226.84f, 0.12f},
//    {224.39f, 3143.15f, 226.84f, 6.15f},
//    {228.01f, 3114.53f, 226.84f, 0.37f},
//    {228.01f, 3157.23f, 226.84f, 5.90f},
//    {235.01f, 3169.97f, 226.84f, 5.65f},
//    {235.01f, 3101.79f, 226.84f, 0.62f},
//    {244.96f, 3091.19f, 226.84f, 0.87f},
//    {244.96f, 3180.57f, 226.84f, 5.40f},
//    {257.24f, 3083.40f, 226.84f, 1.13f},
//    {257.24f, 3188.36f, 226.84f, 5.15f},
//    {271.07f, 3192.85f, 226.84f, 4.90f},
//    {271.07f, 3078.91f, 226.84f, 1.38f},
//    {285.58f, 3077.99f, 226.84f, 1.63f},
//    {285.58f, 3193.76f, 226.84f, 4.64f},
//    {299.86f, 3191.04f, 226.84f, 4.39f},
//    {299.86f, 3080.72f, 226.84f, 1.88f},
//    {313.01f, 3086.91f, 226.84f, 2.13f},
//    {313.01f, 3184.85f, 226.84f, 4.14f},
//    {324.21f, 3175.58f, 226.84f, 3.89f},
//    {324.21f, 3096.18f, 226.84f, 2.38f},
//    {332.76f, 3107.94f, 226.84f, 2.63f},
//    {332.76f, 3163.82f, 226.84f, 3.64f},
//    {338.11f, 3150.30f, 226.84f, 3.39f},
//    {338.11f, 3121.46f, 226.84f, 2.89f},
//    {339.93f, 3135.88f, 226.84f, 3.14f}
//};
//
//enum Misc
//{
//    ACTION_1 = 1,
//    ACTION_2,
//    ACTION_3,
//    ACTION_4,
//    ACTION_5,
//
//    EVENT_1,
//    EVENT_2,
//    EVENT_3,
//};
////106643
//struct boss_elisande : BossAI
//{
//    explicit boss_elisande(Creature* creature) : BossAI(creature, DATA_ELISANDE) {}
//
//    std::list<ObjectGuid> cascadentTargetsList;
//    std::list<Position> leaveNightwellSingularPos;
//    std::map<uint8, std::vector<ObjectGuid>> echoGuidVector;
//    std::map<uint8, std::vector<Position>> singularityPos;
//    std::map<uint8, std::list<ObjectGuid>> echoOrbList;
//    std::map<uint8, std::list<uint32>> SummonElementalTimeList[2];
//    std::list<uint32> singularityTimeList;
//    std::list<uint32> arcaneticRingTimeList;
//    std::list<uint32> delphuricBeamTimeList;
//    std::list<uint32> epochericTimeList;
//    std::list<uint32> permeliativeTormentTimeList;
//    std::list<uint32> conflexiveBurstTimeList;
//
//    bool _introDone = false;
//    bool switchPhase = false;
//    uint8 phase = 0;
//    uint8 singularityCount = 0;
//    uint8 arcaneticRingCount = 0;
//    uint8 delphuricBeamCount = 0;
//    uint8 echoOrbCount = 0;
//    uint32 killCDTimer = 0;
//    uint32 berserkTimer = 0;
//
//    void Reset() override
//    {
//        _Reset();
//        me->SetCanFly(true);
//        me->SetReactState(REACT_PASSIVE);
//        me->SetPower(POWER_ENERGY, 100);
//        me->RemoveAllAuras();
//        me->InterruptNonMeleeSpells(true);
//        DoCast(me, SPELL_ETCHED_IN_TIME, true);
//        singularityPos.clear();
//        leaveNightwellSingularPos.clear();
//        echoGuidVector.clear();
//        echoOrbList.clear();
//        switchPhase = true;
//        phase = 1;
//        killCDTimer = 0;
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        Talk(SAY_AGGRO);
//        _JustEngagedWith();
//        DoCast(me, SPELL_LEAVE_NIGHTWELL_FILTER, true);
//        DefaultEvents(true);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//        _JustDied();
//        RemoveDebuffPlayers();
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        Talk(SAY_EVADE);
//        BossAI::EnterEvadeMode();
//        me->NearTeleportTo(me->GetHomePosition());
//        RemoveDebuffPlayers();
//    }
//
//    void RemoveDebuffPlayers()
//    {
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ABLATION);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ABLATING_EXPLOSION);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ABLATIVE_PULSE_ABLATED);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CONFLEXIVE_BURST_AURA);
//    }
//
//    void DefaultEvents(bool JustEngagedWith)
//    {
//        singularityCount = 0;
//        arcaneticRingCount = 0;
//        delphuricBeamCount = 0;
//        echoOrbCount = 0;
//        uint32 modTime = JustEngagedWith ? 0 : 10000;
//
//        if (IsLFR())
//        {
//            SummonElementalTimeList[0][0] = { 5000, 62000, 40000, 55000 }; //Slow Elemental
//            SummonElementalTimeList[1][0] = { 55000 }; //Fast Elemental
//            singularityTimeList = { 17000, 57000, 30000 };
//            delphuricBeamTimeList = { 35000, 77000, 25000 };
//            permeliativeTormentTimeList = { 23000, 41000, 106000 };
//        }
//        else if (IsMythicRaid())
//        {
//            berserkTimer = (phase < 3 ? 199 : 194) * IN_MILLISECONDS;
//
//            SummonElementalTimeList[0][1] = { 5000, 39000, 75000 };               //Slow Elemental
//            SummonElementalTimeList[0][2] = { 5000, 39000, 45000, 30000, 30000 }; //Slow Elemental
//            SummonElementalTimeList[0][3] = { 5000, 54000, 55000, 30000 };        //Slow Elemental
//            SummonElementalTimeList[1][1] = { 8000, 81000 };        //Fast Elemental
//            SummonElementalTimeList[1][2] = { 8000, 51000 };        //Fast Elemental
//            SummonElementalTimeList[1][3] = { 8000, 36000, 45000 }; //Fast Elemental
//            singularityTimeList = { 56000, 50000, 45000 };
//            arcaneticRingTimeList = { 30000, 39000, 15000, 31000, 19000, 10000, 26000, 9000, 10000 };
//            delphuricBeamTimeList = { 58000, 50000, 65000 };
//            epochericTimeList = { 14000, 85000, 60000, 20000, 10000 };
//            permeliativeTormentTimeList = { 64000, 75000, 25000, 20000 };
//            conflexiveBurstTimeList = { 39000, 90000, 45000, 30000 };
//        }
//        else if (IsHeroicRaid())
//        {
//            berserkTimer = (phase < 3 ? 229 : 224) * IN_MILLISECONDS;
//
//            SummonElementalTimeList[0][0] = { 5000, 49000, 52000, 60000 }; //Slow Elemental
//            SummonElementalTimeList[1][0] = { 8000, 88000, 95000, 20000 }; //Fast Elemental
//            singularityTimeList = { 25000, 36000, 57000, 65000 };
//            arcaneticRingTimeList = { 35000, 40000, 10000, 63000, 10000 };
//            delphuricBeamTimeList = { 59000, 57000, 60000, 70000 };
//            epochericTimeList = { 18000, 76000, 37000, 70000, 15000, 15000, 30000, 15000 };
//            permeliativeTormentTimeList = { 23000, 61000, 37000, 60000 };
//            conflexiveBurstTimeList = { 48000, 52000, 56000, 65000, 10000 };
//        }
//        else
//        {
//            berserkTimer = (phase < 3 ? 259 : 254) * IN_MILLISECONDS;
//
//            SummonElementalTimeList[0][0] = { 5000, 49000, 41000, 60000 }; //Slow Elemental
//            SummonElementalTimeList[1][0] = { 8000, 71000, 101000 };       //Fast Elemental
//            singularityTimeList = { 23000, 36000, 46000, 65000 };
//            arcaneticRingTimeList = { 34000, 31000, 76000, 50000, 40000, 15000, 30000 };
//            delphuricBeamTimeList = { 59000, 26000, 40000, 110000 };
//            epochericTimeList = { 18000, 56000, 31000, 85000, 15000 };
//            permeliativeTormentTimeList = { 23000, 41000, 106000 };
//            conflexiveBurstTimeList = { 48000, 67000, 50000, 45000, 10000 };
//        }
//
//        events.RescheduleEvent(EVENT_SPANNING_SINGULARITY, singularityTimeList.front());
//
//        if (!IsLFR())
//            events.RescheduleEvent(EVENT_ARCANETIC_RING, arcaneticRingTimeList.front());
//
//        if (phase > 1)
//        {
//            events.RescheduleEvent(EVENT_DELPHURIC_BEAM, delphuricBeamTimeList.front());
//            if (!IsLFR())
//                events.RescheduleEvent(EVENT_EPOCHERIC_ORB, epochericTimeList.front());
//        }
//
//        if (IsMythicRaid())
//        {
//            events.RescheduleEvent(EVENT_SUM_SLOW_ELEMENTAL, SummonElementalTimeList[0][phase].front() + modTime);
//            events.RescheduleEvent(EVENT_SUM_FAST_ELEMENTAL, SummonElementalTimeList[1][phase].front() + modTime);
//        }
//        else
//        {
//            events.RescheduleEvent(EVENT_SUM_SLOW_ELEMENTAL, SummonElementalTimeList[0][0].front() + modTime);
//            events.RescheduleEvent(EVENT_SUM_FAST_ELEMENTAL, SummonElementalTimeList[1][0].front() + modTime);
//        }
//
//        switch (phase)
//        {
//            case 1:
//                events.RescheduleEvent(EVENT_CASCADENT_STAR, 12000);
//                events.RescheduleEvent(EVENT_ABLATION, 13000);
//                break;
//            case 2:
//                events.RescheduleEvent(EVENT_ABLATING_EXPLOSION, 24000);
//                break;
//            case 3:
//                events.RescheduleEvent(EVENT_ABLATIVE_PULSE, 24000);
//                events.RescheduleEvent(EVENT_PERMELIATIVE_TORMENT, permeliativeTormentTimeList.front());
//                if (!IsLFR())
//                    events.RescheduleEvent(EVENT_CONFLEXIVE_BURST, conflexiveBurstTimeList.front());
//                break;
//        }
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        if (phase < 3)
//        {
//            if (damage >= me->GetHealth())
//            {
//                damage = 0;
//                me->SetHealth(me->CountPctFromMaxHealth(10));
//            }
//
//            if (!switchPhase && me->HealthBelowPct(11))
//            {
//                switchPhase = true;
//                ++phase;
//                events.Reset();
//                
//                me->m_Events.KillAllEvents(true);
//                me->AttackStop();
//                events.RescheduleEvent(EVENT_CHANGE_PHASE_1, 100);
//                Talk(phase == 2 ? SAY_CHANGE_PHASE_2 : SAY_CHANGE_PHASE_3);
//            }
//        }
//    }
//
//    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply) 
//    {
//        if (apply || mode != AURA_REMOVE_BY_EXPIRE || !me->IsInCombat())
//            return;
//
//        if (spellId == SPELL_LEAVE_NIGHTWELL_END)
//        {
//            me->SetCanFly(false);
//            switchPhase = false;
//            me->SetReactState(REACT_AGGRESSIVE);
//            if (IsHeroicPlusRaid())
//                me->CastSpell(leaveNightwellSingularPos.back(), SPELL_SPANNING_SINGULARITY_AT, true);
//        }
//    }
//
//    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
//    {
//        if (target && mode == AURA_REMOVE_BY_EXPIRE)
//        {
//            switch (spellId)
//            {
//                case SPELL_DELPHURIC_BEAM_MARK:
//                {
//                    float angle = me->GetAngle(target);
//                    //me->PlayOrphanSpellVisual(me->GetPosition(), {0.f, 0.f, angle}, target->GetPosition(), 55186, 0.5f, ObjectGuid::Empty, true);
//                    DoCast(target, SPELL_DELPHURIC_BEAM_DMG, true);
//                    break;
//                }
//                case SPELL_ABLATING_EXPLOSION:
//                    DoCast(target, SPELL_ABLATING_EXPLOSION_DMG, true);
//                    break;
//                case SPELL_CONFLEXIVE_BURST_AURA:
//                    DoCast(target, SPELL_CONFLEXIVE_BURST_DMG, true);
//                    break;
//            }
//        }
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
//    {
//        switch (spellInfo->Id)
//        {
//            case SPELL_LEAVE_NIGHTWELL_FILTER:
//            {
//                if (phase > 1)
//                {
//                    for (auto pos : leaveNightwellSingularPos)
//                        me->CastSpell(pos, GetSingularitySpellId(), true);
//                }
//                leaveNightwellSingularPos.push_back(target->GetPosition());
//                DoCast(target, SPELL_LEAVE_NIGHTWELL, true);
//                break;
//            }
//            case SPELL_SPANNING_SINGULARITY_FILTER:
//            {
//                singularityPos[singularityCount - 1].push_back(target->GetPosition());
//                me->CastSpell(target, GetSingularitySpellId(), false);
//                break;
//            }
//            case SPELL_CASCADENT_STAR:
//            {
//                if (me->GetGUID() == target->GetGUID())
//                    return;
//
//                for (auto const& guid : cascadentTargetsList)
//                {
//                    if (target->GetGUID() == guid)
//                        continue;
//
//                    if (Unit* cascadentTarget = target->GetVictim())
//                        target->CastSpell(cascadentTarget, SPELL_CASCADENT_STAR_VISUAL, true, nullptr, nullptr, me->GetGUID());
//                }
//                break;
//            }
//            case SPELL_CASCADENT_STAR_FILTER:
//                if (me->GetGUID() != target->GetGUID())
//                    cascadentTargetsList.push_back(target->GetGUID());
//                break;
//            case SPELL_DELPHURIC_BEAM_FILTER:
//                DoCast(target, SPELL_DELPHURIC_BEAM_MARK, true);
//                break;
//            case SPELL_PERMELIATIVE_TORMENT_FILTER_2:
//                DoCast(target, SPELL_PERMELIATIVE_TORMENT_DOT, true);
//                break;
//            case SPELL_CONFLEXIVE_BURST_FILTER:
//                DoCast(target, SPELL_CONFLEXIVE_BURST_AURA, true);
//                break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//            case SPELL_TIME_STOP:
//                events.RescheduleEvent(EVENT_CHANGE_PHASE_2, 3000);
//                break;
//            case SPELL_ARCANETIC_RING_DUMMY_CAST:
//            {
//                if (IsHeroicPlusRaid())
//                {
//                    if (auto echo = me->SummonCreature(NPC_ECHO_OF_ELISANDE_RING, me->GetPosition()))
//                        echoGuidVector[1].push_back(echo->GetGUID());
//                }
//                DoCast(me, SPELL_ARCANETIC_RING_FILTER, true);
//                me->SetReactState(REACT_AGGRESSIVE);
//                break;
//            }
//            case SPELL_SPANNING_SINGULARITY_FILTER:
//            {
//                if (IsMythicRaid())
//                {
//                    if (auto echo = me->SummonCreature(NPC_ECHO_OF_ELISANDE_SINGULAR, me->GetPosition()))
//                        echoGuidVector[0].push_back(echo->GetGUID());
//                }
//                break;
//            }
//            case SPELL_DELPHURIC_BEAM:
//            {
//                Talk(SAY_DELPHURIC_BEAM_WARN);
//                if (IsMythicRaid())
//                {
//                    if (auto echo = me->SummonCreature(NPC_ECHO_OF_ELISANDE_BEAM, me->GetPosition()))
//                        echoGuidVector[2].push_back(echo->GetGUID());
//                }
//                break;
//            }
//            case SPELL_EPOCHERIC_ORB_FILTER:
//            {
//                if (IsHeroicPlusRaid())
//                {
//                    if (auto echo = me->SummonCreature(NPC_ECHO_OF_ELISANDE_ORB_VIS, me->GetPosition()))
//                        echoOrbList[echoOrbCount].push_back(echo->GetGUID());
//                }
//                uint8 count = me->GetMap()->GetPlayersCountExceptGMs();
//
//                if (count <= 15)
//                    count = 2;
//                else if (count <= 20)
//                    count = 3;
//                else if (count <= 25)
//                    count = 4;
//                else if (count <= 30)
//                    count = 5;
//
//                Position pos;
//                float angle = frand(0.0f, 6.28f);
//                for (uint8 i = 0; i < count; ++i)
//                {
//                    //centrPos.SimplePosXYRelocationByAngle(pos, frand(25.0f, 35.0f), angle);
//                    angle += 6.28f / count;
//                    me->CastSpell(pos, SPELL_EPOCHERIC_ORB_MISSLE_NORMAL, true);
//                    me->SummonCreature(NPC_EPOCHERIC_ORB_TRIGGER, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + 18.0f);
//                    if (IsHeroicPlusRaid())
//                    {
//                        if (auto echo = me->SummonCreature(NPC_ECHO_OF_ELISANDE_ORB_TRIG, pos))
//                            echoOrbList[echoOrbCount].push_back(echo->GetGUID());
//                    }
//                }
//                ++echoOrbCount;
//                break;
//            }
//        }
//    }
//
//    uint32 GetSingularitySpellId()
//    {
//        if (IsLFR())
//            return phase == 1 ? SPELL_SPANNING_SINGULARITY_LFR_2S : SPELL_SPANNING_SINGULARITY_LFR_0S;
//        else if (IsMythicRaid())
//            return phase == 1 ? SPELL_SPANNING_SINGULARITY_MYTHIC_2S : SPELL_SPANNING_SINGULARITY_MYTHIC_0S;
//        else if (IsHeroicRaid())
//            return phase == 1 ? SPELL_SPANNING_SINGULARITY_HEROIC_2S : SPELL_SPANNING_SINGULARITY_HEROIC_0S;
//        else
//            return phase == 1 ? SPELL_SPANNING_SINGULARITY_NORMAL_2S : SPELL_SPANNING_SINGULARITY_NORMAL_0S;
//    }
//
//    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//    {
//        switch (summon->GetEntry())
//        {
//            case NPC_RECURSIVE_ELEMENTAL:
//                me->CastSpell(summon->GetPosition(), SPELL_TIME_ELEMENTAL_DIES_SLOW_AT, true);
//                break;
//            case NPC_EXPEDIENT_ELEMENTAL:
//                me->CastSpell(summon->GetPosition(), SPELL_TIME_ELEMENTAL_DIES_FAST_AT, true);
//                break;
//        }
//    }
//
//    void MoveInLineOfSight(Unit* who) override
//    {
//        if (who->GetTypeId() == TYPEID_PLAYER && !_introDone && me->IsWithinDistInMap(who, 40.0f))
//        {
//            _introDone = true;
//            DoCast(me, SPELL_CONVERS_INTRODUCTION, true);
//        }
//    }
//
//    void DespawnEventTrash()
//    {
//        RemoveDebuffPlayers();
//        me->RemoveAllAreaObjects();
//        summons.DespawnEntry(NPC_RECURSIVE_ELEMENTAL);
//        summons.DespawnEntry(NPC_EXPEDIENT_ELEMENTAL);
//        summons.DespawnEntry(NPC_EPOCHERIC_ORB_TRIGGER);
//    }
//
//    void KilledUnit(Unit* who) override
//    {
//        if (who && who->IsPlayer() && !killCDTimer)
//        {
//            killCDTimer = 3000;
//            Talk(SAY_PLAYER_DEATH);
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (killCDTimer)
//        {
//            if (killCDTimer <= diff)
//                killCDTimer = 0;
//            else
//                killCDTimer -= diff;
//        }
//
//        if (berserkTimer && !switchPhase)
//        {
//            if (berserkTimer <= diff)
//            {
//                berserkTimer = 0;
//                events.Reset();
//                me->AttackStop();
//                DoCast(me, SPELL_TERMINATE, true);
//            }
//            else
//                berserkTimer -= diff;
//        }
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_CHANGE_PHASE_1:
//                    DoCast(me, SPELL_CLEARALLDEBUFFS, true);
//                    DoCast(me, SPELL_TIME_STOP_ENERGY_COST, true);
//                    DoCast(SPELL_TIME_STOP);
//                    DefaultEvents(false);
//                    break;
//                case EVENT_CHANGE_PHASE_2:
//                    DespawnEventTrash();
//                    DoCast(me, SPELL_TIME_LAYER_CHANGE, true);
//                    DoCast(me, SPELL_DISAPPEAR_VISUAL, true);
//                    events.RescheduleEvent(EVENT_CHANGE_PHASE_3, 2000);
//                    break;
//                case EVENT_CHANGE_PHASE_3:
//                    me->SetCanFly(true);
//                    me->SetHealth(me->GetMaxHealth());
//                    me->NearTeleportTo(me->GetHomePosition());
//                    DoCast(me, SPELL_ETCHED_IN_TIME, true);
//                    events.RescheduleEvent(EVENT_CHANGE_PHASE_4, 5000);
//                    break;
//                case EVENT_CHANGE_PHASE_4:
//                    DoCast(me, SPELL_LEAVE_NIGHTWELL_FILTER, true);
//                    break;
//                case EVENT_SUM_SLOW_ELEMENTAL:
//                {
//                    Position pos;
//                   // centrPos.SimplePosXYRelocationByAngle(pos, frand(30.0f, 40.0f), frand(0.0f, 6.28f));
//                    me->CastSpell(me, SPELL_SUM_TIME_ELEMENTAL_SLOW_DUMMY, true);
//                    me->CastSpell(pos, SPELL_SUM_TIME_ELEMENTAL_SLOW, true);
//                    SummonElementalTimeList[0][IsMythicRaid() ? phase : 0].pop_front();
//                    if (!SummonElementalTimeList[0][IsMythicRaid() ? phase : 0].empty())
//                        events.RescheduleEvent(EVENT_SUM_SLOW_ELEMENTAL, SummonElementalTimeList[0][IsMythicRaid() ? phase : 0].front());
//                    break;
//                }
//                case EVENT_SUM_FAST_ELEMENTAL:
//                {
//                    Position pos;
//                   // centrPos.SimplePosXYRelocationByAngle(pos, frand(20.0f, 35.0f), frand(0.0f, 6.28f));
//                    me->CastSpell(me, SPELL_SUM_TIME_ELEMENTAL_FAST_DUMMY, true);
//                    me->CastSpell(pos, SPELL_SUM_TIME_ELEMENTAL_FAST, true);
//                    SummonElementalTimeList[1][IsMythicRaid() ? phase : 0].pop_front();
//                    if (!SummonElementalTimeList[1][IsMythicRaid() ? phase : 0].empty())
//                        events.RescheduleEvent(EVENT_SUM_FAST_ELEMENTAL, SummonElementalTimeList[1][IsMythicRaid() ? phase : 0].front());
//                    break;
//                }
//                case EVENT_SPANNING_SINGULARITY:
//                {
//                    if (phase == 1)
//                    {
//                        events.DelayEvents(200);
//                        Talk(SAY_SPANNING_SINGULARITY);
//                        DoCast(SPELL_SPANNING_SINGULARITY_FILTER);
//                    }
//                    else if (singularityCount < singularityPos.size() && singularityCount < echoGuidVector[0].size())
//                    {
//                        if (IsMythicRaid())
//                            if (auto echo = Creature::GetCreature(*me, echoGuidVector[0][singularityCount]))
//                                echo->GetAI()->DoAction(ACTION_1);
//
//                        for (auto pos : singularityPos[singularityCount])
//                            me->CastSpell(pos, GetSingularitySpellId(), false);
//                    }
//                    ++singularityCount;
//                    singularityTimeList.pop_front();
//                    if (!singularityTimeList.empty())
//                        events.RescheduleEvent(EVENT_SPANNING_SINGULARITY, singularityTimeList.front());
//                    break;
//                }
//                case EVENT_ARCANETIC_RING:
//                {
//                    if (phase == 1)
//                    {
//                        me->AttackStop();
//                        for (uint8 i = 0; i < 25; ++i)
//                            me->SummonCreature(NPC_ARCANETIC_RING, ringPos[i]);
//                        Position pos;
//                        std::list<AreaTrigger*> listAT;
//                        me->GetAreaTriggerListWithSpellIDInRange(listAT, SPELL_TIME_ELEMENTAL_DIES_SLOW_AT, 100.0f);
//                        bool found = false;
//                        while (!found)
//                        {
//                            //centrPos.SimplePosXYRelocationByAngle(pos, 30.0f, frand(0.0f, 6.28f));
//                            found = true;
//
//                            for (auto const& at : listAT)
//                            {
//                                if (at->GetDistance(pos) <= 15.0f)
//                                    found = false;
//                            }
//                        }
//                        me->CastSpell(pos, SPELL_ARCANETIC_TELEPORT, true);
//                        me->CastSpell(me, SPELL_ARCANETIC_RING_DUMMY, true);
//                        me->CastSpell(me, SPELL_ARCANETIC_RING_DUMMY_CAST, false);
//                        Talk(SAY_ARCANETIC_RING);
//                        Talk(SAY_ARCANETIC_RING_WARN);
//                    }
//                    else
//                    {
//                        if (IsHeroicPlusRaid() && arcaneticRingCount < echoGuidVector[1].size())
//                            if (auto echo = Creature::GetCreature(*me, echoGuidVector[1][arcaneticRingCount++]))
//                                echo->GetAI()->DoAction(ACTION_2);
//                    }
//                    arcaneticRingTimeList.pop_front();
//                    if (!arcaneticRingTimeList.empty())
//                        events.RescheduleEvent(EVENT_ARCANETIC_RING, arcaneticRingTimeList.front());
//                }
//                case EVENT_CASCADENT_STAR:
//                    if (me->GetReactState() != REACT_PASSIVE)
//                    {
//                        cascadentTargetsList.clear();
//                        me->CastSpell(me->GetVictim(), SPELL_CASCADENT_STAR);
//                    }
//                    events.RescheduleEvent(EVENT_CASCADENT_STAR, 5000);
//                    break;
//                case EVENT_ABLATION:
//                    if (me->GetReactState() != REACT_PASSIVE)
//                        me->CastSpell(me->GetVictim(), SPELL_ABLATION);
//                    events.RescheduleEvent(EVENT_ABLATION, 5000);
//                    break;
//                case EVENT_DELPHURIC_BEAM:
//                {
//                    if (phase == 2)
//                    {
//                        Talk(SAY_DELPHURIC_BEAM);
//                        DoCast(SPELL_DELPHURIC_BEAM);
//                    }
//                    else if (IsMythicRaid() && phase == 3 && delphuricBeamCount < echoGuidVector[2].size())
//                    {
//                        if (auto echo = Creature::GetCreature(*me, echoGuidVector[2][delphuricBeamCount++]))
//                            echo->GetAI()->DoAction(ACTION_3);
//                    }
//                    delphuricBeamTimeList.pop_front();
//                    if (!delphuricBeamTimeList.empty())
//                        events.RescheduleEvent(EVENT_DELPHURIC_BEAM, delphuricBeamTimeList.front());
//                    break;
//                }
//                case EVENT_EPOCHERIC_ORB:
//                {
//                    if (phase == 2)
//                    {
//                        Talk(SAY_EPOCHERIC_ORB);
//                        Talk(SAY_EPOCHERIC_ORB_WARN);
//                        DoCast(SPELL_EPOCHERIC_ORB_FILTER);
//                    }
//                    else if (IsHeroicPlusRaid() && phase == 3 && echoOrbCount < echoOrbList.size())
//                    {
//                        for (auto const& guid : echoOrbList[echoOrbCount])
//                            if (auto echo = Creature::GetCreature(*me, guid))
//                                echo->GetAI()->DoAction(ACTION_4);
//
//                        ++echoOrbCount;
//                    }
//                    if (!IsNormalRaid())
//                        epochericTimeList.pop_front();
//                    else if (epochericTimeList.size() > 1)
//                        epochericTimeList.pop_front();
//                    if (!epochericTimeList.empty())
//                        events.RescheduleEvent(EVENT_EPOCHERIC_ORB, epochericTimeList.front());
//                    break;
//                }
//                case EVENT_ABLATING_EXPLOSION:
//                    me->CastSpell(me->GetVictim(), SPELL_ABLATING_EXPLOSION);
//                    events.RescheduleEvent(EVENT_ABLATING_EXPLOSION, 21000);
//                    break;
//                case EVENT_ABLATIVE_PULSE:
//                    me->CastSpell(me->GetVictim(), SPELL_ABLATIVE_PULSE);
//                    events.RescheduleEvent(EVENT_ABLATIVE_PULSE, 6000);
//                    break;
//                case EVENT_PERMELIATIVE_TORMENT:
//                    DoCast(SPELL_PERMELIATIVE_TORMENT_FILTER_2);
//                    permeliativeTormentTimeList.pop_front();
//                    if (!permeliativeTormentTimeList.empty())
//                        events.RescheduleEvent(EVENT_PERMELIATIVE_TORMENT, permeliativeTormentTimeList.front());
//                    break;
//                case EVENT_CONFLEXIVE_BURST:
//                    Talk(SAY_CONFLEXIVE_BURST);
//                    Talk(SAY_CONFLEXIVE_BURST_WARN);
//                    DoCast(SPELL_CONFLEXIVE_BURST_FILTER);
//                    if (!IsNormalRaid())
//                        conflexiveBurstTimeList.pop_front();
//                    else if (conflexiveBurstTimeList.size() > 1)
//                        conflexiveBurstTimeList.pop_front();
//                    if (!conflexiveBurstTimeList.empty())
//                        events.RescheduleEvent(EVENT_CONFLEXIVE_BURST, conflexiveBurstTimeList.front());
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////105364, 105622, 105624, 105958
//struct npc_elisande_echo_of_elisande : ScriptedAI
//{
//    explicit npc_elisande_echo_of_elisande(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//        me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        SetWaitState();
//
//        if (me->GetEntry() != NPC_ECHO_OF_ELISANDE_ORB_TRIG)
//            DoCast(me, SPELL_TIME_ECHO_VISUAL, true);
//    }
//
//    void SetWaitState()
//    {
//        switch (me->GetEntry())
//        {
//            case NPC_ECHO_OF_ELISANDE_RING:
//                DoCast(me, SPELL_TIME_ECHO_WAIT_STATE_RING, true);
//                break;
//            case NPC_ECHO_OF_ELISANDE_SINGULAR:
//                DoCast(me, SPELL_TIME_ECHO_WAIT_STATE_SINGULAR, true);
//                break;
//            case NPC_ECHO_OF_ELISANDE_BEAM:
//                DoCast(me, SPELL_TIME_ECHO_WAIT_STATE_BEAM, true);
//                break;
//            case NPC_ECHO_OF_ELISANDE_ORB_VIS:
//                DoCast(me, SPELL_TIME_ECHO_WAIT_STATE_ORB, true);
//                break;
//        }
//    }
//
//    uint32 GetSingularitySpellId()
//    {
//        if (IsLFR())
//            return SPELL_SPANNING_SINGULARITY_LFR_2S;
//        else if (IsMythicRaid())
//            return SPELL_SPANNING_SINGULARITY_MYTHIC_2S;
//        else if (IsHeroicRaid())
//            return SPELL_SPANNING_SINGULARITY_HEROIC_2S;
//        else
//            return SPELL_SPANNING_SINGULARITY_NORMAL_2S;
//    }
//
//    void DoAction(int32 const actionID) override
//    {
//        switch (actionID)
//        {
//            case ACTION_1: //Echo Spanning Singularity
//                Talk(0);
//                DoCast(SPELL_SPANNING_SINGULARITY_FILTER);
//                break;
//            case ACTION_2: //Echo Arcanetic Ring
//            {
//                if (auto owner = me->GetOwner())
//                {
//                    for (uint8 i = 0; i < 25; ++i)
//                        owner->SummonCreature(NPC_ARCANETIC_RING, ringPos[i]);
//                }
//                Talk(0);
//                Talk(1);
//                DoCast(SPELL_ECHO_ARCANETIC_RING);
//                break;
//            }
//            case ACTION_3: //Echo Delphuric Beam
//                Talk(0);
//                Talk(1);
//                DoCast(SPELL_ECHO_DELPHURIC_BEAM);
//                break;
//            case ACTION_4: //Echo Epocheric Orb
//            {
//                if (me->GetEntry() == NPC_ECHO_OF_ELISANDE_ORB_TRIG)
//                    DoCast(SPELL_ECHO_EPOCHERIC_ORB);
//                else if (me->GetEntry() == NPC_ECHO_OF_ELISANDE_ORB_VIS)
//                {
//                    Talk(0);
//                    Talk(1);
//                    DoCast(me, SPELL_DISSOLVE_VISUAL, true);
//                }
//                break;
//            }
//        }
//    }
//
//    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
//    {
//        if (apply || mode != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (spellId == SPELL_ECHO_DELPHURIC_BEAM)
//            DoCast(me, SPELL_DISSOLVE_VISUAL, true);
//    }
//
//    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
//    {
//        if (target && spellId == SPELL_DELPHURIC_BEAM_MARK && mode == AURA_REMOVE_BY_EXPIRE)
//        {
//            float angle = me->GetAngle(target);
//           // me->PlayOrphanSpellVisual(me->GetPosition(), {0.f, 0.f, angle}, target->GetPosition(), 55186, 0.5f, ObjectGuid::Empty, true);
//            DoCast(target, SPELL_DELPHURIC_BEAM_DMG, true);
//        }
//    }
//
//    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
//    {
//        switch (spellInfo->Id)
//        {
//            case SPELL_LEAVE_NIGHTWELL_REMOVE_DISSOLVE:
//                SetWaitState();
//                break;
//        }
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
//    {
//        switch (spellInfo->Id)
//        {
//            case SPELL_SPANNING_SINGULARITY_FILTER:
//                DoCast(target, GetSingularitySpellId());
//                break;
//            case SPELL_DELPHURIC_BEAM_FILTER:
//                DoCast(target, SPELL_DELPHURIC_BEAM_MARK, true);
//                break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell) 
//    {
//        if (spell->Id == GetSingularitySpellId())
//            DoCast(me, SPELL_DISSOLVE_VISUAL, true);
//
//        if (spell->Id == SPELL_ECHO_ARCANETIC_RING)
//        {
//            DoCast(me, SPELL_ARCANETIC_RING_FILTER, true);
//            DoCast(me, SPELL_DISSOLVE_VISUAL, true);
//        }
//
//        if (spell->Id == SPELL_ECHO_EPOCHERIC_ORB)
//        {
//            DoCast(me, SPELL_EPOCHERIC_ORB_MISSLE_NORMAL, true);
//
//            if (Unit* owner = me->GetOwner())
//                owner->SummonCreature(NPC_EPOCHERIC_ORB_TRIGGER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 18.0f);
//        }
//    }
//
//    void UpdateAI(uint32 diff) override {}
//};
//
////105315
//struct npc_elisande_arcanetic_ring : ScriptedAI
//{
//    explicit npc_elisande_arcanetic_ring(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//        me->SetSpeed(MOVE_FLIGHT, 1.0f);
//        me->SetCanFly(true);
//    }
//
//    Position pos;
//    Position casterPos;
//    bool activeMoving = false;
//    uint32 scaleTimer = 0;
//    float targetDist = 0.0f;
//    float mod = 1.15f;
//
//    void IsSummonedBy(Unit* summoner) override {}
//
//    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
//    {
//        if (!activeMoving && spellInfo->Id == SPELL_ARCANETIC_RING_FILTER)
//        {
//            activeMoving = true;
//            DoCast(me, SPELL_ARCANETIC_RING_AT, true);
//           // centrPos.SimplePosXYRelocationByAngle(pos, 115.0f, me->GetAngle(caster));
//            casterPos = {caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ()};
//            targetDist = me->GetDistance(caster);
//            Position const path[3] =
//            {
//                {me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()},
//                {caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ()},
//                {pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()}
//            };
//            me->GetMotionMaster()->MoveSmoothPath(1, path, IsMythicRaid() ? 3 : 2);
//            scaleTimer = 200;
//        }
//    }
//
//    void MovementInform(uint32 type, uint32 id) override
//    {
//        if (type == EFFECT_MOTION_TYPE)
//        {
//            if (id == 1)
//                me->DespawnOrUnsummon();
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (scaleTimer)
//        {
//            if (scaleTimer <= diff)
//            {
//                scaleTimer = 200;
//                if (auto at = me->GetAreaTrigger(SPELL_ARCANETIC_RING_AT))
//                {
//                    float scaleStep = (me->GetDistance(casterPos) / targetDist) * mod;
//                    if (scaleStep <= 0.35f && mod == 1.15f)
//                        mod = 0.6f;
//                    if (scaleStep > 0.35f && scaleStep < 0.7f)
//                        at->SetObjectScale(scaleStep);
//                    else if (scaleStep > 0.7f)
//                        at->SetObjectScale(0.7f);
//                }
//            }
//            else
//                scaleTimer -= diff;
//        }
//    }
//};
//
////105299
//struct npc_elisande_recursive_elemental : ScriptedAI
//{
//    explicit npc_elisande_recursive_elemental(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//        me->SetControlled(true, UNIT_STATE_ROOT);
//    }
//
//    InstanceScript* instance;
//    EventMap events;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//        DoCast(me, SPELL_CHANGE_MODE_TIME_ELEMENTAL_SLOW, true);
//        events.RescheduleEvent(EVENT_1, 1000);
//
//        if (IsMythicRaid())
//            events.RescheduleEvent(EVENT_2, 12000);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        me->SetVisible(false);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                    me->CastSpell(me->GetVictim(), SPELL_BLAST);
//                    events.RescheduleEvent(EVENT_1, 4000);
//                    break;
//                case EVENT_2:
//                    DoCast(SPELL_RECURSION);
//                    events.RescheduleEvent(EVENT_2, 16000);
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////105301
//struct npc_elisande_expedient_elemental : ScriptedAI
//{
//    explicit npc_elisande_expedient_elemental(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//    }
//
//    InstanceScript* instance;
//    EventMap events;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//        DoCast(me, SPELL_CHANGE_MODE_TIME_ELEMENTAL_FAST, true);
//        events.RescheduleEvent(EVENT_1, 1000);
//
//        if (IsMythicRaid())
//            events.RescheduleEvent(EVENT_2, 11000);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        me->SetVisible(false);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                    DoCast(SPELL_EXOTHERMIC_RELEASE);
//                    events.RescheduleEvent(EVENT_1, 4500);
//                    break;
//                case EVENT_2:
//                    DoCast(SPELL_EXPEDITE_FILTER);
//                    events.RescheduleEvent(EVENT_2, 16000);
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////107754
//struct npc_elisande_epocheric_orb : ScriptedAI
//{
//    explicit npc_elisande_epocheric_orb(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//        me->SetCanFly(true);
//        me->SetSpeed(MOVE_FLIGHT, 0.2f);
//    }
//
//    uint32 startTimer = 0;
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        startTimer = 2000;
//    }
//
//    void MovementInform(uint32 type, uint32 id) override
//    {
//        if (type == POINT_MOTION_TYPE)
//        {
//            if (id == 1)
//            {
//                me->RemoveAurasDueToSpell(SPELL_EPOCHERIC_ORB_VISUAL);
//                bool playerFound = false;
//                auto at = me->GetAreaTrigger(SPELL_EPOCHERIC_ORB_AT);
//                if (!at)
//                {
//                    me->DespawnOrUnsummon();
//                    return;
//                }
//                if (auto owner = me->GetOwner())
//                {
//                    if (playerFound)
//                        owner->CastSpell(me, SPELL_EPOCHERIC_ORB_SMALL_DMG, true);
//                    else
//                        owner->CastSpell(me, SPELL_EPOCHERIC_ORB_BIG_DMG, true);
//                }
//                at->Remove();
//                me->DespawnOrUnsummon();
//            }
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (startTimer)
//        {
//            if (startTimer <= diff)
//            {
//                startTimer = 0;
//                DoCast(me, SPELL_EPOCHERIC_ORB_VISUAL, true);
//                float z = me->GetPositionZ();
//                me->GetMotionMaster()->MovePoint(1, me->GetPositionX(), me->GetPositionY(), z, false);
//            }
//            else
//                startTimer -= diff;
//        }
//    }
//};
//
////209168
//class spell_elisande_spanning_singularity_filter : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_spanning_singularity_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster() || GetCaster()->GetEntry() != NPC_ELISANDE)
//            return;
//
//        if (targets.size() < 15)
//            Trinity::Containers::RandomResize(targets, 1);
//        else if (targets.size() < 25)
//            Trinity::Containers::RandomResize(targets, 2);
//        else
//            Trinity::Containers::RandomResize(targets, 3);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elisande_spanning_singularity_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
////209174
//class spell_elisande_spanning_singularity : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_spanning_singularity);
//
//    void HandleScript(SpellEffIndex /*effectIndex*/)
//    {
//        if (!GetCaster() || !GetHitDest())
//            return;
//
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//            if (Creature* elisande = instance->instance->GetCreature(instance->GetGuidData(DATA_ELISANDE)))
//                elisande->CastSpell(nullptr, SPELL_SPANNING_SINGULARITY_AT, true);
//    }
//
//    void Register() override
//    {
//        OnEffectLaunch += SpellEffectFn(spell_elisande_spanning_singularity::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////229739
//class spell_elisande_cascadent_star_filter : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_cascadent_star_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (GetCaster())
//        {
//            if (GetCaster()->GetVictim())
//                targets.remove(GetCaster()->GetVictim());
//
//            if (targets.size() > 1)
//            {
//                uint32 size = 1;
//                float mod = 1.0f;
//
//                if (GetCaster()->GetPower(POWER_ENERGY) > 51)
//                    mod = 0.7f;
//                else if (GetCaster()->GetPower(POWER_ENERGY) > 1)
//                    mod = 0.5f;
//                else
//                    mod = 0.3f;
//
//                size = uint32(targets.size() * mod);
//                Trinity::Containers::RandomResize(targets, size < 1 ? 1 : size);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elisande_cascadent_star_filter::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
//    }
//};
//
////229740
//class spell_elisande_cascadent_star : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_cascadent_star);
//
//    void HandleScript(SpellEffIndex /*effectIndex*/)
//    {
//        if (!GetCaster() || !GetHitUnit())
//            return;
//
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//            if (Creature* elisande = instance->instance->GetCreature(instance->GetGuidData(DATA_ELISANDE)))
//                elisande->CastSpell(GetHitUnit(), SPELL_CASCADENT_STAR_DMG, true);
//    }
//
//    void Register() override
//    {
//        OnEffectLaunchTarget += SpellEffectFn(spell_elisande_cascadent_star::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
//    }
//};
//
////209242
//class spell_elisande_delphuric_beam_filter : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_delphuric_beam_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (GetCaster() && !targets.empty())
//        {
//            if (GetCaster()->GetMap()->IsMythic())
//                Trinity::Containers::RandomResize(targets, 5);
//            else if (targets.size() <= 10)
//                Trinity::Containers::RandomResize(targets, 2);
//            else if (targets.size() <= 20)
//                Trinity::Containers::RandomResize(targets, 3);
//            else if (targets.size() <= 30)
//                Trinity::Containers::RandomResize(targets, 4);
//        }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elisande_delphuric_beam_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//    }
//};
//
////209248
//class spell_elisande_delphuric_beam_dmg_filter : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_delphuric_beam_dmg_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        std::list<WorldObject*> tempTargets;
//
//        if (!GetCaster() || !GetExplTargetUnit() || GetCaster()->GetMap()->IsMythic())
//            return;
//
//        for (auto const& target : targets)
//        {
//            if (target->GetGUID() == GetExplTargetUnit()->GetGUID())
//            {
//                tempTargets.push_back(target);
//                continue;
//            }
//
//            if (target->IsInBetween(GetCaster(), GetExplTargetUnit(), 2.0f))
//                tempTargets.push_back(target);
//        }
//        targets = tempTargets;
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elisande_delphuric_beam_dmg_filter::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER);
//    }
//};
//
////210024, 210546
//class spell_elisande_epocheric_orb_dmg : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_epocheric_orb_dmg);
//
//    void HandleDamage(SpellEffIndex effectIndex)
//    {
//        if (!GetCaster() || !GetHitUnit())
//            return;
//
//        int32 damage = GetHitDamage();
//
//        if (GetSpellInfo()->Id == SPELL_EPOCHERIC_ORB_BIG_DMG)
//        {
//            if (const SpellInfo* info = sSpellMgr->GetSpellInfo(SPELL_EPOCHERIC_ORB_SMALL_DMG, DIFFICULTY_NONE))
//                damage = info->GetEffect(EFFECT_0)->BasePoints;
//        }
//
//        if (GetCaster()->GetMap()->IsMythic())
//        {
//            GetCaster()->CastSpell(GetHitUnit(), SPELL_EPOCHERIC_VULNERABILITY, true);
//
//            if (uint8 count = GetHitUnit()->GetAuraCount(SPELL_EPOCHERIC_VULNERABILITY))
//                damage *= count;
//        }
//
//        SetHitDamage(damage);
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_elisande_epocheric_orb_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////211799
//class spell_elisande_ablating_explosion_dmg : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_ablating_explosion_dmg);
//
//    void HandleDamage(SpellEffIndex /*effIndex*/)
//    {
//        if (!GetHitUnit())
//            return;
//
//        if (WorldLocation const* loc = GetExplTargetDest())
//        {
//            float distance = GetHitUnit()->GetExactDist2d(loc) * 2.0f;
//            uint32 perc = 10;
//            if (distance < 100.0f)
//                perc = 100.0f - distance;
//
//            uint32 damage = CalculatePct(GetHitDamage(), perc);
//            SetHitDamage(damage);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_elisande_ablating_explosion_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////209599
//class spell_elisande_conflexive_burst_dmg : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_conflexive_burst_dmg);
//
//    void HandleDamage(SpellEffIndex /*effIndex*/)
//    {
//        if (!GetHitUnit() || !GetHitUnit()->GetMap()->IsMythic())
//            return;
//
//        if (WorldLocation const* loc = GetExplTargetDest())
//        {
//            float distance = GetHitUnit()->GetExactDist2d(loc) * 2.0f;
//            uint32 perc = 10;
//            if (distance < 100.0f)
//                perc = 100.0f - distance;
//
//            uint32 damage = CalculatePct(GetHitDamage(), perc);
//            SetHitDamage(damage);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_elisande_conflexive_burst_dmg::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////225653
//class spell_elisande_permeliative_torment_filter : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_permeliative_torment_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (GetCaster() && !targets.empty())
//        {
//            if (GetCaster()->GetMap()->IsMythic() || targets.size() <= 10)
//                Trinity::Containers::RandomResize(targets, 2);
//            else if (targets.size() <= 20)
//                Trinity::Containers::RandomResize(targets, 3);
//            else if (targets.size() <= 25)
//                Trinity::Containers::RandomResize(targets, 4);
//            else if (targets.size() <= 30)
//                Trinity::Containers::RandomResize(targets, 5);
//        }
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elisande_permeliative_torment_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
////209621
//class spell_elisande_recursion : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_recursion);
//
//    void HandleScript(SpellEffIndex /*effIndex*/)
//    {
//        if (auto target = GetHitUnit())
//        {
//            if (target->IsCreature())
//                if (Aura* aura = target->GetAura(SPELL_DELPHURIC_BEAM))
//                    aura->RefreshDuration();
//            else if (target->IsPlayer())
//            {
//                Unit::AuraApplicationMap& appliedAuras = target->GetAppliedAuras();
//                for (Unit::AuraApplicationMap::iterator iter = appliedAuras.begin(); iter != appliedAuras.end(); ++iter)
//                {
//                    if (auto aura = iter->second->GetBase())
//                    {
//                        for (auto auraEffect : aura->GetAuraEffects())
//                        {
//                            if (auraEffect->GetAuraType() == SPELL_AURA_PERIODIC_DAMAGE)
//                            {
//                                aura->RefreshDuration();
//                                continue;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_elisande_recursion::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
//    }
//};
//
////209597
//class spell_elisande_conflexive_burst_filter : public SpellScript
//{
//    PrepareSpellScript(spell_elisande_conflexive_burst_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//
//        if (targets.size() > 1 && GetCaster()->GetVictim())
//            targets.remove(GetCaster()->GetVictim());
//
//        if (targets.size() > 2)
//            Trinity::Containers::RandomResize(targets, 2);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_elisande_conflexive_burst_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
////211261
//class spell_elisande_permeliative_torment : public AuraScript
//{
//    PrepareAuraScript(spell_elisande_permeliative_torment);
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (auto aurEff = GetAura()->GetEffect(EFFECT_0))
//        {
//            float damage = aurEff->GetBaseAmount() * aurEff->GetTickNumber();
//            aurEff->SetAmount(damage);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_elisande_permeliative_torment::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
//    }
//};
//
////209165
//class spell_elisande_time_slow_regulator : public AuraScript
//{
//    PrepareAuraScript(spell_elisande_time_slow_regulator);
//
//    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool& /*canBeRecalculated*/)
//    {
//        if (GetUnitOwner() && GetUnitOwner()->IsCreature() && GetUnitOwner()->GetEntry() == NPC_ARCANETIC_RING)
//            amount = -70;
//    }
//
//    void Register()
//    {
//        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_elisande_time_slow_regulator::CalculateAmount, EFFECT_0, SPELL_AURA_DUMMY);
//        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_elisande_time_slow_regulator::CalculateAmount, EFFECT_1, SPELL_AURA_141);
//        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_elisande_time_slow_regulator::CalculateAmount, EFFECT_2, SPELL_AURA_DUMMY);
//        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_elisande_time_slow_regulator::CalculateAmount, EFFECT_5, SPELL_AURA_DUMMY);
//    }
//};
//
////214278, 214295
//class spell_elisande_delphuric_beam : public AuraScript
//{
//    PrepareAuraScript(spell_elisande_delphuric_beam);
//
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (!GetCaster() || !GetCaster()->IsInCombat())
//            return;
//
//        if (GetId() == SPELL_DELPHURIC_BEAM)
//        {
//            if (GetCaster()->GetMap()->IsMythic())
//            {
//                if (aurEff->GetTickNumber() == 1 || aurEff->GetTickNumber() == 2 || aurEff->GetTickNumber() == 3)
//                    GetCaster()->CastSpell(GetCaster(), SPELL_DELPHURIC_BEAM_FILTER, true);
//            }
//            else if (aurEff->GetTickNumber() == 1)
//            {
//                GetCaster()->CastSpell(GetCaster(), SPELL_DELPHURIC_BEAM_FILTER, true);
//            }
//        }
//        else if (GetId() == SPELL_ECHO_DELPHURIC_BEAM)
//        {
//            if (aurEff->GetTickNumber() == 1 || aurEff->GetTickNumber() == 2 || aurEff->GetTickNumber() == 3)
//                GetCaster()->CastSpell(GetCaster(), SPELL_DELPHURIC_BEAM_FILTER, true);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_elisande_delphuric_beam::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
//void AddSC_boss_elisande()
//{
//    RegisterCreatureAI(boss_elisande);
//    RegisterCreatureAI(npc_elisande_echo_of_elisande);
//    RegisterCreatureAI(npc_elisande_arcanetic_ring);
//    RegisterCreatureAI(npc_elisande_recursive_elemental);
//    RegisterCreatureAI(npc_elisande_expedient_elemental);
//    RegisterCreatureAI(npc_elisande_epocheric_orb);
//    RegisterSpellScript(spell_elisande_spanning_singularity);
//    RegisterSpellScript(spell_elisande_spanning_singularity_filter);
//    RegisterSpellScript(spell_elisande_cascadent_star_filter);
//    RegisterSpellScript(spell_elisande_cascadent_star);
//    RegisterSpellScript(spell_elisande_delphuric_beam_filter);
//    RegisterSpellScript(spell_elisande_delphuric_beam_dmg_filter);
//    RegisterSpellScript(spell_elisande_epocheric_orb_dmg);
//    RegisterSpellScript(spell_elisande_ablating_explosion_dmg);
//    RegisterSpellScript(spell_elisande_conflexive_burst_dmg);
//    RegisterSpellScript(spell_elisande_permeliative_torment_filter);
//    RegisterSpellScript(spell_elisande_recursion);
//    RegisterSpellScript(spell_elisande_conflexive_burst_filter);
//    RegisterAuraScript(spell_elisande_permeliative_torment);
//    RegisterAuraScript(spell_elisande_time_slow_regulator);
//    RegisterAuraScript(spell_elisande_delphuric_beam);
//}

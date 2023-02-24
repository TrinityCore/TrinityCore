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
//enum Says
//{
//    //Botanist
//    SAY_AGGRO                   = 0,
//    SAY_SOLAR_COLLAPSE          = 1,
//    SAY_PARASITIC_FETTER        = 2,
//    SAY_CONTROLLED_CHAOS        = 3,
//    SAY_CALL_OF_NIGHT_WARN      = 4,
//    SAY_CALL_OF_NIGHT           = 5,
//    SAY_PHASE_2                 = 6,
//    SAY_PHASE_3                 = 7,
//    SAY_DEATH                   = 8,
//    SAY_KILL_PLAYER             = 9,
//
//    //Solarist
//    SAY_S_PLASMA_SPHERES        = 0,
//    SAY_S_SOLAR_COLLAPSE        = 1,
//
//    //Arcanist
//    SAY_A_UNK0                  = 0,
//    SAY_A_AGGRO                 = 1,
//    SAY_A_CALL_OF_NIGHT_WARN    = 2,
//    SAY_A_CALL_OF_NIGHT         = 3,
//    SAY_A_CONTROLLED_CHAOS      = 4,
//
//    //Naturalist
//    SAY_N_PARASITIC_FETTER      = 0,
//    SAY_N_GRACE_OF_NATURE       = 1
//};
//
//enum Spells
//{
//    SPELL_BERSERK                   = 62535,
//    SPELL_SHARE_HEALTH              = 216897,
//    SPELL_SHARE_HEALTH_SCRIPT       = 216898,
//
//    //Phase 1
//    SPELL_RECURSIVE_STRIKES         = 218502,
//    SPELL_RECURSIVE_STRIKES_DUMMY   = 218503,
//    SPELL_RECURSIVE_STRIKES_DMG     = 218508,
//    SPELL_CONTROLLED_CHAOS_FILTER   = 218438,
//    SPELL_SUM_CONTROLLED_CHAOS      = 218447,
//    SPELL_CONTROLLED_CHAOS_DMG_10   = 218463, //10  Yard
//    SPELL_CONTROLLED_CHAOS_DMG_20   = 218466, //20  Yard
//    SPELL_CONTROLLED_CHAOS_DMG_30   = 218470, //30  Yard
//    SPELL_CONTROLLED_CHAOS_DMG_MASS = 219950, //300 Yard
//    SPELL_PARASITIC_FETTER_FILTER   = 218424,
//    SPELL_PARASITIC_FETTER_DOT      = 218304,
//    SPELL_PARASITIC_FETTER_MARK     = 219278,
//    SPELL_PARASITIC_FETTER_ROOT     = 219340,
//    SPELL_SOLAR_COLLAPSE_FILTER     = 218148,
//
//    //Phase 2
//    SPELL_NIGHTOSIS_SUM_SOLARIST    = 216830,
//    SPELL_TRANSFORM_NATURALIST      = 216832,
//
//    //Phase 3
//    SPELL_NIGHTOSIS_SUM_NATURALIST  = 216877,
//    SPELL_TRANSFORM_ARCANIST        = 216878,
//    SPELL_NIGHTOSIS_INIT_IMAGES     = 219334,
//    SPELL_CALL_OF_NIGHT_FILTER      = 218807,
//    SPELL_CALL_OF_NIGHT_AURA        = 218809,
//    SPELL_CALL_OF_NIGHT_SCALE       = 218821,
//    SPELL_CALL_OF_NIGHT_VISUAL_1    = 220249,
//    SPELL_CALL_OF_NIGHT_VISUAL_2    = 220250,
//    SPELL_CALL_OF_NIGHT_VISUAL_3    = 220251,
//    SPELL_ARCANE_ECLIPSE            = 218838,
//
//    //Solarist Telarn
//    SPELL_ARCANE_DISSOLVE_IN        = 228343, //Visual spawn
//    SPELL_FLARE                     = 218806,
//    SPELL_SUM_PLASMA_SPHERES        = 218774,
//    SPELL_COLLAPSE_OF_NIGHT         = 223437, //Mythic
//    SPELL_SOLAR_INFUSION            = 222010, //Mythic. After died cast
//
//    //Arcanist Telarn
//    SPELL_ARCANE_INFUSION           = 222021, //Mythic. After died cast
//    SPELL_SUMMON_CHAOS_SPHERES      = 223034, //Mythic
//
//    //Naturalist Telarn
//    SPELL_TOXIC_SPORES_FILTER       = 219049,
//    SPELL_TOXIC_SPORES_SUM          = 219231,
//    SPELL_GRACE_OF_NATURE_AT        = 218927,
//    SPELL_SUM_CHAOTIC_SPHERE_NATURE = 223219,
//    SPELL_CHAOTIC_NATURE_10         = 223386, //10  Yard
//    SPELL_CHAOTIC_NATURE_20         = 223387, //20  Yard
//    SPELL_CHAOTIC_NATURE_30         = 223389, //30  Yard
//    SPELL_NATURE_INFUSION           = 222020, //Mythic. After died cast
//
//    //Controlled Chaos Stalker
//    SPELL_CONTROLLED_CHAOS_VISUAL   = 239551,
//
//    //Parasitic Lasher
//    SPELL_PARASITIC_FIXATE          = 218342,
//    SPELL_PARASITIC_FETTER_AT       = 218357,
//    SPELL_RAMPANT_GROWTH            = 219248,
//
//    //Solar Collapse Stalker
//    SPELL_SOLAR_COLLAPSE_MISSLE_1   = 218152, //Speed: 0.50
//    SPELL_SOLAR_COLLAPSE_MISSLE_2   = 223734, //Speed: 3.00
//
//    //Plasma Sphere
//    SPELL_PLASMA_SPHERE             = 218520,
//    SPELL_PLASMA_EXPLOSION          = 218780,
//
//    //Toxic Spore
//    SPELL_TOXIC_SPORE_AT            = 219234,
//    SPELL_TOXIC_SPORE_DMG           = 219235,
//
//    //Other Trash
//    SPELL_MANA_ORB_VISUAL           = 224840,
//    SPELL_ARCANE_CHANNEL            = 224861,
//    SPELL_ARCANE_CHANNEL_MISSILE    = 224885,
//};
//
//enum eEvents
//{
//    //Botanist
//    EVENT_CONTROLLED_CHAOS          = 1,
//    EVENT_PARASITIC_FETTER          = 2,
//    EVENT_SOLAR_COLLAPSE            = 3,
//    EVENT_PHASE_2                   = 4,
//    EVENT_PHASE_3                   = 5,
//    EVENT_CALL_OF_NIGHT             = 6,
//
//    //Solarist
//    EVENT_FLARE,
//    EVENT_SUM_PLASMA_SPHERES,
//    EVENT_COLLAPSE_OF_NIGHT,
//
//    //Naturalist
//    EVENT_TOXIC_SPORES,
//    EVENT_GRACE_OF_NATURE,
//    EVENT_CHAOTIC_SPHERE_NATURE,
//
//    //Arcanist
//    EVENT_SUMMON_CHAOS_SPHERES
//};
//
//Position const trashPos[10] =
//{
//    {635.94f, 2793.02f, 133.21f, 1.35f}, //NPC_TELARN_GENERIC_TRIGGER
//    {651.15f, 2788.29f, 125.40f, 2.74f}, //NPC_DUSKWATCH_WEAVER
//    {653.66f, 2795.79f, 125.40f, 3.21f},
//    {635.13f, 2776.43f, 125.40f, 1.50f},
//    {632.93f, 2809.71f, 125.40f, 5.01f},
//    {627.40f, 2777.16f, 125.40f, 1.09f},
//    {625.17f, 2808.27f, 125.40f, 5.46f},
//    {623.03f, 2783.73f, 125.40f, 0.68f},
//    {621.46f, 2801.45f, 125.40f, 5.91f},
//    {649.50f, 2802.33f, 125.40f, 3.67f}
//};
//
//Position const spherePos[3] =
//{
//    {655.05f, 2777.77f, 125.39f},
//    {610.0f,  2787.85f, 125.40f},
//    {640.28f, 2817.88f, 125.39f}
//};
//
//Position const botanistPos[3] =
//{
//    {684.93f, 2764.22f, 125.33f, 2.84f},
//    {680.03f, 2756.45f, 125.33f, 2.34f},
//    {672.75f, 2751.25f, 125.33f, 1.76f}
//};
//
//uint32 const botanistsEntry[3] =
//{
//    NPC_SOLARIST_TELARN,
//    NPC_ARCANIST_TELARN,
//    NPC_NATURALIST_TELARN
//};
//
//enum Misc
//{
//    EVENT_1 = 1,
//    EVENT_2,
//    EVENT_3,
//
//    ACTION_1,
//    ACTION_2,
//    ACTION_3,
//};
////104528
//struct boss_high_botanist_telarn : BossAI
//{
//    explicit boss_high_botanist_telarn(Creature* creature) : BossAI(creature, DATA_TELARN)
//    {
//        if (me->IsAlive())
//        {
//            if (IsMythicRaid())
//            {
//                me->SetReactState(REACT_PASSIVE);
//                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//                me->SetVisible(false);
//            }
//            if (instance)
//                Init();
//        }
//    }
//
//    std::list<ObjectGuid> botanistList;
//    uint8 healthPct{};
//    uint8 CallOfNightCount{};
//    uint8 botanistDiedCount{};
//
//    void Init()
//    {
//        if (auto trigger = instance->instance->SummonCreature(NPC_TELARN_GENERIC_TRIGGER, trashPos[0]))
//        {
//            trigger->CastSpell(trigger, SPELL_MANA_ORB_VISUAL, true);
//        
//            for (uint8 i = 1; i < 10; ++i)
//                trigger->SummonCreature(NPC_DUSKWATCH_WEAVER, trashPos[i]);
//        }
//
//        if (IsMythicRaid())
//            DoAction(ACTION_1);
//    }
//
//    void Reset() override
//    {
//        if (IsMythicRaid())
//            return;
//
//        for (auto const& guid : summons)
//            if (auto summon = Unit::GetCreature(*me, guid))
//                if (summon->GetEntry() == NPC_SOLARIST_TELARN || summon->GetEntry() == NPC_NATURALIST_TELARN)
//                    summon->AI()->DoAction(true);
//
//        _Reset();
//        healthPct = 76;
//        CallOfNightCount = 0;
//        me->SetReactState(REACT_AGGRESSIVE);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        if (IsMythicRaid())
//            return;
//
//        Talk(SAY_AGGRO);
//        _JustEngagedWith();
//        DoCast(me, SPELL_BERSERK, true);
//        //DoCast(me, SPELL_SHARE_HEALTH, true);
//        DoCast(me, SPELL_RECURSIVE_STRIKES, true);
//        DefaultEvents(1);
//
//        if (auto trigger = me->SummonCreature(NPC_BOTANIST_HEALTH_CONTROLLER, me->GetPosition()))
//            trigger->CastSpell(trigger, SPELL_SHARE_HEALTH_SCRIPT, true);
//    }
//
//    void DefaultEvents(uint8 phase)
//    {
//        switch (phase)
//        {
//            case 1:
//                events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 35000);
//                events.RescheduleEvent(EVENT_PARASITIC_FETTER, 20000);
//                events.RescheduleEvent(EVENT_SOLAR_COLLAPSE, 10000);
//                break;
//            case 2:
//                Talk(SAY_PHASE_2);
//                events.RescheduleEvent(EVENT_PHASE_2, 100);
//                events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 42000);
//                events.RescheduleEvent(EVENT_PARASITIC_FETTER, 22000);
//                break;
//            case 3:
//                Talk(SAY_PHASE_3);
//                events.RescheduleEvent(EVENT_PHASE_3, 100);
//                events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 52000);
//                events.RescheduleEvent(EVENT_CALL_OF_NIGHT, 20000);
//                break;
//        }
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        BossAI::EnterEvadeMode();
//        RemoveAurasPlayers();
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//        _JustDied();
//        RemoveAurasPlayers();
//    }
//
//    void RemoveAurasPlayers()
//    {
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PARASITIC_FETTER_MARK);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CALL_OF_NIGHT_AURA);
//    }
//
//    void DoAction(int32 const action) override
//    {
//        if (!IsMythicRaid() || instance->GetBossState(DATA_TELARN) == DONE)
//            return;
//
//        switch (action)
//        {
//            case ACTION_1: //Summon Botanists
//            {
//                botanistList.clear();
//                botanistDiedCount = 0;
//                for (uint8 i = 0; i < 3; ++i)
//                    if (auto botanist = me->SummonCreature(botanistsEntry[i], botanistPos[i]))
//                        botanistList.push_back(botanist->GetGUID());
//                break;
//            }
//            case ACTION_2: //Despawn after evade 
//            {
//                if (instance->GetBossState(DATA_TELARN) != NOT_STARTED)
//                {
//                    instance->SetBossState(DATA_TELARN, NOT_STARTED);
//                    instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, me);
//
//                    for (auto const& guid : botanistList)
//                    {
//                        if (auto botanist = Unit::GetCreature(*me, guid))
//                        {
//                            botanist->SetReactState(REACT_PASSIVE);
//                            botanist->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//                            botanist->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//                            botanist->AI()->DoAction(true);
//                            botanist->DespawnOrUnsummon(200);
//                        }
//                    }
//                    RemoveAurasPlayers();
//                    DoAction(ACTION_1);
//                }
//                break;
//            }
//            case ACTION_3: //Enter Combat
//            {
//                if (instance->GetBossState(DATA_TELARN) != IN_PROGRESS)
//                {
//                    instance->SetBossState(DATA_TELARN, IN_PROGRESS);
//                    //instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_START, me);
//
//                    for (auto const& guid : botanistList)
//                    {
//                        if (auto botanist = Unit::GetCreature(*me, guid))
//                            if (botanist->IsAlive() && !botanist->IsInCombat())
//                                botanist->AI()->DoZoneInCombat(botanist, 100.0f);
//                    }
//                }
//                break;
//            }
//        }
//    }
//
//    void SummonedCreatureDies(Creature* summon, Unit* killer) override
//    {
//        switch (summon->GetEntry())
//        {
//            case NPC_SOLARIST_TELARN:
//            case NPC_ARCANIST_TELARN:
//            case NPC_NATURALIST_TELARN:
//            {
//                if (IsMythicRaid())
//                {
//                    ++botanistDiedCount;
//                    if (botanistDiedCount == 3)
//                    {
//                        instance->SendEncounterUnit(ENCOUNTER_FRAME_INSTANCE_END, me, true, true);
//                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, 1886);
//                        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_KILL_CREATURE, me->GetEntry(), 1, 0);
//                        if (instance->GetBossState(DATA_TELARN) != DONE)
//                        {
//                            instance->SetBossState(DATA_TELARN, DONE);
//                            instance->SaveToDB();
//                        }
//                        me->DespawnOrUnsummon();
//                    }
//                }
//                break;
//            }
//            default:
//                break;
//        }
//    }
//
//    void SpellHit(Unit* target, SpellInfo const* spell) override
//    {
//        if (spell->Id == SPELL_NIGHTOSIS_INIT_IMAGES)
//            DoCast(me, SPELL_TRANSFORM_ARCANIST, true);
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        if (spell->Id == SPELL_SOLAR_COLLAPSE_FILTER)
//            me->SummonCreature(NPC_SOLAR_COLLAPSE_STALKER, target->GetPosition());
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//            case SPELL_NIGHTOSIS_SUM_SOLARIST:
//                DoCast(me, SPELL_TRANSFORM_NATURALIST, true);
//                me->SetReactState(REACT_AGGRESSIVE);
//                break;
//            case SPELL_NIGHTOSIS_SUM_NATURALIST:
//                if (auto sum = me->SummonCreature(NPC_IMAGE_ARCANIST_TELARN, me->GetPosition()))
//                    sum->CastSpell(me, SPELL_NIGHTOSIS_INIT_IMAGES, true);
//                me->SetReactState(REACT_AGGRESSIVE);
//                break;
//            case SPELL_CALL_OF_NIGHT_FILTER:
//                ++CallOfNightCount;
//                break;
//        }
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage) 
//    {
//        if (me->HealthBelowPct(healthPct))
//        {
//            me->AttackStop();
//            events.Reset();
//
//            switch (healthPct)
//            {
//                case 76:
//                    healthPct = 51;
//                    DefaultEvents(2);
//                    break;
//                case 51:
//                    healthPct = 0;
//                    DefaultEvents(3);
//                    break;
//            }
//        }
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        switch (type)
//        {
//            case DATA_TELARN_CALL_OF_NIGHT:
//                return CallOfNightCount;
//        }
//        return 0;
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
//;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_CONTROLLED_CHAOS:
//                    Talk(SAY_CONTROLLED_CHAOS);
//                    DoCast(SPELL_CONTROLLED_CHAOS_FILTER);
//                    if (healthPct == 0)          //Phase 3
//                        events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 50000);
//                    else if (healthPct == 51)    //Phase 2
//                        events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 40000);
//                    else                         //Phase 1
//                        events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 35000);
//                    break;
//                case EVENT_PARASITIC_FETTER:
//                    Talk(SAY_PARASITIC_FETTER);
//                    DoCast(SPELL_PARASITIC_FETTER_FILTER);
//                    if (healthPct == 51)         //Phase 2
//                        events.RescheduleEvent(EVENT_PARASITIC_FETTER, 40000);
//                    else                         //Phase 1
//                        events.RescheduleEvent(EVENT_PARASITIC_FETTER, 35000);
//                    break;
//                case EVENT_SOLAR_COLLAPSE:
//                    Talk(SAY_SOLAR_COLLAPSE);
//                    DoCast(SPELL_SOLAR_COLLAPSE_FILTER);
//                    events.RescheduleEvent(EVENT_SOLAR_COLLAPSE, 35000);
//                    break;
//                case EVENT_PHASE_2:
//                    DoCast(SPELL_NIGHTOSIS_SUM_SOLARIST);
//                    break;
//                case EVENT_PHASE_3:
//                    DoCast(SPELL_NIGHTOSIS_SUM_NATURALIST);
//                    break;
//                case EVENT_CALL_OF_NIGHT:
//                    Talk(SAY_CALL_OF_NIGHT_WARN);
//                    Talk(SAY_CALL_OF_NIGHT);
//                    DoCast(SPELL_CALL_OF_NIGHT_FILTER);
//                    events.RescheduleEvent(EVENT_CALL_OF_NIGHT, 50000);
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////109038
//struct npc_nh_solarist_telarn : ScriptedAI
//{
//    explicit npc_nh_solarist_telarn(Creature* creature) : ScriptedAI(creature), summons(me)
//    {
//        instance = me->GetInstanceScript();
//    }
//
//    InstanceScript* instance;
//    SummonList summons;
//    EventMap events;
//    uint8 _phase{};
//    uint8 CallOfNightCount{};
//    uint32 globalTimer{};
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        if (IsMythicRaid())
//            return;
//
//        me->AttackStop();
//        me->SetRegenerateHealth(false);
//        me->SetHealth(summoner->GetHealth());
//        DoZoneInCombat(me, 100.0f);
//        DoCast(me, SPELL_ARCANE_DISSOLVE_IN, true);
//        //DoCast(me, SPELL_SHARE_HEALTH, true);
//
//        DefaultEvents(0);
//
//        if (me)
//            me->SetReactState(REACT_AGGRESSIVE);
//    }
//
//    void Reset()
//    {
//        events.Reset();
//    }
//
//    void JustEngagedWith(Unit* who) override
//    {
//        //Talk(SAY_AGGRO);
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//
//
//        DoCast(me, SPELL_BERSERK, true);
//
//        if (IsMythicRaid())
//        {
//            if (auto summoner = me->GetOwner())
//                summoner->GetAI()->DoAction(ACTION_3);
//
//            DefaultEvents(++_phase);
//        }
//    }
//
//    void DefaultEvents(uint8 phase)
//    {
//        events.Reset();
//
//        switch (phase)
//        {
//            case 0: // LFR/NORMAL/HEROIC
//                globalTimer = 40 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_FLARE, 7000);
//                events.RescheduleEvent(EVENT_SOLAR_COLLAPSE, 32000);
//                events.RescheduleEvent(EVENT_SUM_PLASMA_SPHERES, 10000);
//                break;
//            case 1:
//                globalTimer = 64 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_SOLAR_COLLAPSE, 5000);
//                events.RescheduleEvent(EVENT_FLARE, 7000);
//                events.RescheduleEvent(EVENT_SUM_PLASMA_SPHERES, 45000);
//                break;
//            case 2:
//                globalTimer = 55 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_FLARE, 2000);
//                if (me->HasAura(SPELL_NATURE_INFUSION))
//                {
//                    events.RescheduleEvent(EVENT_SOLAR_COLLAPSE, 15000);
//                    events.RescheduleEvent(EVENT_SUM_PLASMA_SPHERES, 25000);
//                }
//                else
//                {
//                    events.RescheduleEvent(EVENT_COLLAPSE_OF_NIGHT, 28000);
//                    events.RescheduleEvent(EVENT_SUM_PLASMA_SPHERES, 40000);
//                }
//                break;
//            case 3:
//                globalTimer = 35 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_FLARE, 8000);
//                events.RescheduleEvent(EVENT_COLLAPSE_OF_NIGHT, 20000);
//                events.RescheduleEvent(EVENT_SUM_PLASMA_SPHERES, 35000);
//                break;
//        }
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        ScriptedAI::EnterEvadeMode();
//
//        if (IsMythicRaid())
//        {
//            if (auto summoner = me->GetOwner())
//                summoner->GetAI()->DoAction(ACTION_2);
//        }
//    }
//
//    void JustDied(Unit* killer) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        summons.DespawnAll();
//
//        if (IsMythicRaid())
//            DoCast(me, SPELL_SOLAR_INFUSION, true);
//    }
//
//    void JustSummoned(Creature* summon) override
//    {
//        summons.Summon(summon);
//    }
//
//    bool IsDisableGenerateLoot() 
//    {
//        if (_phase == 3)
//            return false;
//
//        return true;
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        switch (type)
//        {
//            case DATA_TELARN_CALL_OF_NIGHT:
//                return CallOfNightCount;
//        }
//        return 0;
//    }
//
//    void DoAction(int32 const action) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        summons.DespawnAll();
//    }
//
//    void SpellHit(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//            case SPELL_ARCANE_INFUSION:
//            case SPELL_NATURE_INFUSION:
//                DefaultEvents(++_phase);
//                break;
//        }
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//            case SPELL_SOLAR_COLLAPSE_FILTER:
//                me->SummonCreature(NPC_SOLAR_COLLAPSE_STALKER, target->GetPosition());
//                break;
//            case SPELL_FLARE:
//                if (IsMythicRaid() && _phase == 3)
//                    DoCast(target, SPELL_PARASITIC_FETTER_MARK, true);
//                break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//            case SPELL_SUM_PLASMA_SPHERES:
//            {
//                for (uint8 i = 0; i < 3; ++i)
//                {
//                    if (!IsMythicRaid())
//                    {
//                        if (auto owner = me->GetOwner())
//                            owner->SummonCreature(NPC_PLASMA_SPHERE, spherePos[i]);
//                    }
//                    else
//                        me->SummonCreature(NPC_PLASMA_SPHERE, spherePos[i]);
//                }
//                break;
//            }
//            case SPELL_COLLAPSE_OF_NIGHT:
//                ++CallOfNightCount;
//                break;
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
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_FLARE:
//                    DoCastVictim(SPELL_FLARE);
//                    events.RescheduleEvent(EVENT_FLARE, 9 * IN_MILLISECONDS);
//                    break;
//                case EVENT_SOLAR_COLLAPSE:
//                    Talk(SAY_S_SOLAR_COLLAPSE);
//                    DoCast(SPELL_SOLAR_COLLAPSE_FILTER);
//                    events.RescheduleEvent(EVENT_SOLAR_COLLAPSE, globalTimer);
//                    break;
//                case EVENT_COLLAPSE_OF_NIGHT:
//                    DoCast(SPELL_COLLAPSE_OF_NIGHT);
//                    events.RescheduleEvent(EVENT_COLLAPSE_OF_NIGHT, globalTimer);
//                    break;
//                case EVENT_SUM_PLASMA_SPHERES:
//                    Talk(SAY_S_PLASMA_SPHERES);
//                    DoCast(SPELL_SUM_PLASMA_SPHERES);
//                    events.RescheduleEvent(EVENT_SUM_PLASMA_SPHERES, globalTimer);
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////109040
//struct npc_nh_arcanist_telarn : ScriptedAI
//{
//    explicit npc_nh_arcanist_telarn(Creature* creature) : ScriptedAI(creature), summons(me)
//    {
//        instance = me->GetInstanceScript();
//    }
//
//    InstanceScript* instance;
//    SummonList summons;
//    EventMap events;
//    uint8 _phase{};
//    uint8 CallOfNightCount{};
//    uint32 globalTimer{};
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        if (IsMythicRaid())
//            return;
//
//        me->AttackStop();
//        me->SetRegenerateHealth(false);
//        me->SetHealth(summoner->GetHealth());
//        DoZoneInCombat(me, 100.0f);
//        DoCast(me, SPELL_ARCANE_DISSOLVE_IN, true);
//        //DoCast(me, SPELL_SHARE_HEALTH, true);
//
//        if (me)
//            me->SetReactState(REACT_AGGRESSIVE);
//    }
//
//    void Reset()
//    {
//        events.Reset();
//    }
//
//    void JustEngagedWith(Unit* who) override
//    {
//        //Talk(SAY_AGGRO);
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//
//        DoCast(me, SPELL_BERSERK, true);
//
//        DoCast(me, SPELL_RECURSIVE_STRIKES, true);
//
//        if (IsMythicRaid())
//        {
//            if (auto summoner = me->GetOwner())
//                summoner->GetAI()->DoAction(ACTION_3);
//
//            DefaultEvents(++_phase);
//        }
//    }
//
//    void DefaultEvents(uint8 phase)
//    {
//        events.Reset();
//
//        switch (phase)
//        {
//            case 1:
//                globalTimer = 64 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 30000);
//                events.RescheduleEvent(EVENT_CALL_OF_NIGHT, 57000);
//                break;
//            case 2:
//                globalTimer = 55 * IN_MILLISECONDS;
//                if (me->HasAura(SPELL_SOLAR_INFUSION))
//                    events.RescheduleEvent(EVENT_SUMMON_CHAOS_SPHERES, 25000); // FIXME. Need Timing!
//                else
//                    events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 55000);
//                events.RescheduleEvent(EVENT_CALL_OF_NIGHT, 42000);
//                break;
//            case 3:
//                globalTimer = 35 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, 55000);
//                events.RescheduleEvent(EVENT_CALL_OF_NIGHT, 42000);
//                break;
//        }
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        ScriptedAI::EnterEvadeMode();
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//
//        if (IsMythicRaid())
//        {
//            if (auto summoner = me->GetOwner())
//                summoner->GetAI()->DoAction(ACTION_2);
//        }
//    }
//
//    void JustDied(Unit* killer) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        summons.DespawnAll();
//        
//        if (IsMythicRaid())
//            DoCast(me, SPELL_ARCANE_INFUSION, true);
//    }
//
//    void JustSummoned(Creature* summon) override
//    {
//        summons.Summon(summon);
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        switch (type)
//        {
//            case DATA_TELARN_CALL_OF_NIGHT:
//                return CallOfNightCount;
//        }
//        return 0;
//    }
//
//    bool IsDisableGenerateLoot()
//    {
//        if (_phase == 3)
//            return false;
//
//        return true;
//    }
//
//    void DoAction(int32 const action) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        summons.DespawnAll();
//    }
//
//    void SpellHit(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//            case SPELL_SOLAR_INFUSION:
//            case SPELL_NATURE_INFUSION:
//                DefaultEvents(++_phase);
//                break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//            case SPELL_SUMMON_CHAOS_SPHERES:
//            {
//                for (uint8 i = 0; i < 3; ++i)
//                    me->SummonCreature(NPC_CHAOS_SPHERE, spherePos[i]);
//                break;
//            }
//            case SPELL_CALL_OF_NIGHT_FILTER:
//                ++CallOfNightCount;
//                break;
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
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_CONTROLLED_CHAOS:
//                    Talk(SAY_A_CONTROLLED_CHAOS);
//                    DoCast(SPELL_CONTROLLED_CHAOS_FILTER);
//                    events.RescheduleEvent(EVENT_CONTROLLED_CHAOS, globalTimer);
//                    break;
//                case EVENT_CALL_OF_NIGHT:
//                    Talk(SAY_A_CALL_OF_NIGHT_WARN);
//                    Talk(SAY_A_CALL_OF_NIGHT);
//                    DoCast(SPELL_CALL_OF_NIGHT_FILTER);
//                    events.RescheduleEvent(EVENT_CALL_OF_NIGHT, globalTimer);
//                    break;
//                case EVENT_SUMMON_CHAOS_SPHERES:
//                    DoCast(SPELL_SUMMON_CHAOS_SPHERES);
//                    events.RescheduleEvent(EVENT_SUMMON_CHAOS_SPHERES, globalTimer);
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////109041
//struct npc_nh_naturalist_telarn : ScriptedAI
//{
//    explicit npc_nh_naturalist_telarn(Creature* creature) : ScriptedAI(creature), summons(me)
//    {
//        instance = me->GetInstanceScript();
//    }
//
//    InstanceScript* instance;
//    SummonList summons;
//    EventMap events;
//    uint8 _phase{};
//    uint32 globalTimer{};
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        if (IsMythicRaid())
//            return;
//
//        me->AttackStop();
//        me->SetRegenerateHealth(false);
//        me->SetHealth(summoner->GetHealth());
//        DoZoneInCombat(me, 100.0f);
//        DoCast(me, SPELL_ARCANE_DISSOLVE_IN, true);
//        //DoCast(me, SPELL_SHARE_HEALTH, true);
//
//        DefaultEvents(0);
//
//        if (me)
//            me->SetReactState(REACT_AGGRESSIVE);
//    }
//
//    void Reset()
//    {
//        events.Reset();
//    }
//
//    void JustEngagedWith(Unit* who) override
//    {
//        //Talk(SAY_AGGRO);
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//
//        DoCast(me, SPELL_BERSERK, true);
//
//        if (IsMythicRaid())
//        {
//            if (auto summoner = me->GetOwner())
//                summoner->GetAI()->DoAction(ACTION_3);
//
//            DefaultEvents(++_phase);
//        }
//    }
//
//    void DefaultEvents(uint8 phase)
//    {
//        events.Reset();
//
//        switch (phase)
//        {
//            case 0:
//                globalTimer = 64 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_TOXIC_SPORES, 8000);
//                events.RescheduleEvent(EVENT_GRACE_OF_NATURE, 9000);
//                events.RescheduleEvent(EVENT_PARASITIC_FETTER, 35000);
//                break;
//            case 1:
//                globalTimer = 64 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_TOXIC_SPORES, 6 * IN_MILLISECONDS);
//                events.RescheduleEvent(EVENT_GRACE_OF_NATURE, 64 * IN_MILLISECONDS);
//                events.RescheduleEvent(EVENT_PARASITIC_FETTER, 16 * IN_MILLISECONDS);
//                break;
//            case 2:
//                globalTimer = 55 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_TOXIC_SPORES, 6 * IN_MILLISECONDS);
//                events.RescheduleEvent(EVENT_GRACE_OF_NATURE, 64 * IN_MILLISECONDS);
//                events.RescheduleEvent(EVENT_PARASITIC_FETTER, 16 * IN_MILLISECONDS);
//                break;
//            case 3: //FIXME. Need Valid Timing
//                globalTimer = 35 * IN_MILLISECONDS;
//                events.RescheduleEvent(EVENT_TOXIC_SPORES, 6 * IN_MILLISECONDS);
//                events.RescheduleEvent(EVENT_CHAOTIC_SPHERE_NATURE, 35 * IN_MILLISECONDS);
//                events.RescheduleEvent(EVENT_PARASITIC_FETTER, 16 * IN_MILLISECONDS);
//                break;
//        }
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        ScriptedAI::EnterEvadeMode();
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//
//        if (IsMythicRaid())
//        {
//            if (auto summoner = me->GetOwner())
//                summoner->GetAI()->DoAction(ACTION_2);
//        }
//    }
//
//    void JustDied(Unit* killer) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        summons.DespawnAll();
//
//        if (IsMythicRaid())
//            DoCast(me, SPELL_NATURE_INFUSION, true);
//    }
//
//    void JustSummoned(Creature* summon) override
//    {
//        summons.Summon(summon);
//
//        if (_phase == 3 && summon->GetEntry() == NPC_PARASITIC_LASHER)
//        {
//            me->CastSpell(summon, SPELL_CALL_OF_NIGHT_AURA, true);
//        }
//    }
//
//    bool IsDisableGenerateLoot()
//    {
//        if (_phase == 3)
//            return false;
//
//        return true;
//    }
//
//    void DoAction(int32 const action) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        summons.DespawnAll();
//    }
//
//    void SpellHit(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//            case SPELL_ARCANE_INFUSION:
//            case SPELL_SOLAR_INFUSION:
//                DefaultEvents(++_phase);
//                break;
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//            case SPELL_SUM_CHAOTIC_SPHERE_NATURE:
//            {
//                for (uint8 i = 0; i < 3; ++i)
//                    me->SummonCreature(NPC_CHAOS_SPHERE, spherePos[i]);
//                break;
//            }
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
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_TOXIC_SPORES:
//                    DoCast(SPELL_TOXIC_SPORES_FILTER);
//                    events.RescheduleEvent(EVENT_TOXIC_SPORES, 8 * IN_MILLISECONDS);
//                    break;
//                case EVENT_GRACE_OF_NATURE:
//                    Talk(SAY_N_GRACE_OF_NATURE);
//                    DoCast(SPELL_GRACE_OF_NATURE_AT);
//                    events.RescheduleEvent(EVENT_GRACE_OF_NATURE, globalTimer);
//                    break;
//                case EVENT_PARASITIC_FETTER:
//                    Talk(SAY_N_PARASITIC_FETTER);
//                    DoCast(SPELL_PARASITIC_FETTER_FILTER);
//                    events.RescheduleEvent(EVENT_PARASITIC_FETTER, globalTimer);
//                    break;
//                case EVENT_CHAOTIC_SPHERE_NATURE:
//                    DoCast(SPELL_SUM_CHAOTIC_SPHERE_NATURE);
//                    events.RescheduleEvent(EVENT_CHAOTIC_SPHERE_NATURE, globalTimer);
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////112973
//struct npc_telarn_duskwatch_weaver : public ScriptedAI
//{
//    explicit npc_telarn_duskwatch_weaver(Creature* creature) : ScriptedAI(creature)
//    {
//        DoCast(me, SPELL_ARCANE_CHANNEL, true);
//    }
//
//    EventMap events;
//
//    void Reset() override
//    {
//        events.Reset();
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        if (me->HasAura(SPELL_ARCANE_CHANNEL))
//            me->RemoveAurasDueToSpell(SPELL_ARCANE_CHANNEL);
//    }
//
//    void JustReachedHome() override
//    {
//        DoCast(me, SPELL_ARCANE_CHANNEL, true);
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
//                    break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////109792
//struct npc_telarn_controlled_chaos_stalker : public ScriptedAI
//{
//    explicit npc_telarn_controlled_chaos_stalker(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        DoCast(me, SPELL_CONTROLLED_CHAOS_VISUAL, true);
//    }
//
//    EventMap events;
//    bool naturSolar{};
//    bool arkanSolar{};
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* owner) override
//    {
//        events.RescheduleEvent(EVENT_1, 100);
//
//        naturSolar = owner->HasAura(SPELL_NATURE_INFUSION) && owner->HasAura(SPELL_SOLAR_INFUSION);
//        arkanSolar = owner->HasAura(SPELL_ARCANE_INFUSION) && owner->HasAura(SPELL_SOLAR_INFUSION);
//    }
//
//    void CollapseRand(float minRange, float maxRange)
//    {
//        if (!IsMythicRaid())
//            return;
//
//        if (auto owner = me->GetOwner())
//        {
//            if (naturSolar)
//            {
//                Position collapsePos;
//                me->GetNearPosition(frand(minRange, maxRange), frand(0.0f, 6.28f));
//                owner->SummonCreature(NPC_SOLAR_COLLAPSE_STALKER, collapsePos);
//            }
//        }
//    }
//
//    void SpellFinishCast(const SpellInfo* spell)
//    {
//        switch (spell->Id)
//        {
//            case SPELL_CONTROLLED_CHAOS_DMG_10:
//                CollapseRand(1.0f, 10.0f);
//                DoCast(me, SPELL_CONTROLLED_CHAOS_DMG_MASS, true);
//                if (arkanSolar)
//                    DoCast(me, SPELL_CHAOTIC_NATURE_10, true);
//                events.RescheduleEvent(EVENT_2, 100);
//                break;
//            case SPELL_CONTROLLED_CHAOS_DMG_20:
//                CollapseRand(11.0f, 20.0f);
//                DoCast(me, SPELL_CONTROLLED_CHAOS_DMG_MASS, true);
//                if (arkanSolar)
//                    DoCast(me, SPELL_CHAOTIC_NATURE_20, true);
//                events.RescheduleEvent(EVENT_3, 100);
//                break;
//            case SPELL_CONTROLLED_CHAOS_DMG_30:
//                CollapseRand(21.0f, 30.0f);
//                DoCast(me, SPELL_CONTROLLED_CHAOS_DMG_MASS, true);
//                if (arkanSolar)
//                    DoCast(me, SPELL_CHAOTIC_NATURE_30, true);
//                break;
//            default:
//                break;
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                    DoCast(SPELL_CONTROLLED_CHAOS_DMG_10);
//                    break;
//                case EVENT_2:
//                    DoCast(SPELL_CONTROLLED_CHAOS_DMG_20);
//                    break;
//                case EVENT_3:
//                    DoCast(SPELL_CONTROLLED_CHAOS_DMG_30);
//                    break;
//            }
//        }
//    }
//};
//
////109075
//struct npc_telarn_parasitic_lasher : public ScriptedAI
//{
//    explicit npc_telarn_parasitic_lasher(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->SetRegenerateHealth(false);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISTRACT, true);
//        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//    }
//
//    EventMap events;
//    ObjectGuid targetGUID;
//    bool followEnd = false;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* owner) override
//    {
//        events.RescheduleEvent(EVENT_1, 2000);
//        events.RescheduleEvent(EVENT_3, 3000);
//    }
//
//    void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId)
//    {
//        // 219259
//        if (target && !targetGUID.IsEmpty() && (target->GetGUID() == targetGUID) && !followEnd)
//        {
//            followEnd = true;
//            events.Reset();
//            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//            me->RemoveAllAuras();
//            me->RemoveAurasDueToSpell(SPELL_PARASITIC_FETTER_AT);
//            me->RemoveAurasDueToSpell(SPELL_CALL_OF_NIGHT_AURA);
//            me->SetDisplayId(11686); //InvisibleDisplay
//            if (auto owner = me->GetOwner())
//            {
//                owner->CastSpell(target, SPELL_PARASITIC_FETTER_MARK, true);
//                DoCast(target, 46598, true); //Ride Player
//            }
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                    targetGUID.Clear();
//                    if (auto owner = me->GetOwner())
//                    {
//                        if (auto target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true, -SPELL_PARASITIC_FIXATE))
//                        {
//                            targetGUID = target->GetGUID();
//                            DoCast(target, SPELL_PARASITIC_FIXATE, true);
//
//                            if (!me->HasAura(SPELL_PARASITIC_FETTER_AT))
//                                DoCast(me, SPELL_PARASITIC_FETTER_AT, true);
//                        }
//                        else if (Unit* target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//                            me->GetMotionMaster()->MovePoint(1, target->GetPosition());
//                    }
//                    events.RescheduleEvent(EVENT_2, 1000);
//                    break;
//                case EVENT_2:
//                    if (auto target = ObjectAccessor::GetUnit(*me, targetGUID))
//                    {
//                        if (!target->IsAlive())
//                        {
//                            events.RescheduleEvent(EVENT_1, 1000);
//                            break;
//                        }
//                        else
//                            me->GetMotionMaster()->MovePoint(1, target->GetPosition());
//                    }
//                    else
//                    {
//                        events.RescheduleEvent(EVENT_1, 1000);
//                        break;
//                    }
//                    events.RescheduleEvent(EVENT_2, 1000);
//                    break;
//                case EVENT_3:
//                    DoCast(me, SPELL_RAMPANT_GROWTH, true);
//                    break;
//            }
//        }
//    }
//};
//
////109583
//struct npc_telarn_solar_collapse_stalker : public ScriptedAI
//{
//    explicit npc_telarn_solar_collapse_stalker(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//    uint8 SolarCount = 0;
//    float range = 30.0f;
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* owner) override
//    {
//        events.RescheduleEvent(EVENT_1, 1500); //12c-25y, 12c-20y, 6c-15y, 6c-10y, 6c-5y, 1c-0y
//        events.RescheduleEvent(EVENT_2, 15000); //Despawn Event
//
//        if (me)
//        {
//            Position pos;
//            for (uint8 i = 1; i <= 12; ++i)
//            {
//                me->GetNearPosition(25.0f, 0.523f * i);
//                // me->PlayOrphanSpellVisual(pos, 0.0f, { pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + 0.1f }, 58128, 1.5f, ObjectGuid::Empty, true);
//            }
//        }
//    }
//
//    void SolarCollapse(uint8 idx)
//    {
//        uint8 count = 1;
//
//        switch (idx)
//        {
//            case 1:
//            case 2:
//                count = 12;
//                break;
//            case 3:
//            case 4:
//            case 5:
//                count = 6;
//                break;
//            default:
//                break;
//        }
//
//        Position pos;
//        float angle = 6.28 / count;
//        range -= 5.0f;
//
//        for (uint8 i = 1; i <= count; ++i)
//        {
//            me->GetNearPosition(range, angle * i);
//            me->CastSpell(pos, SPELL_SOLAR_COLLAPSE_MISSLE_1, true);
//
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//                case EVENT_1:
//                    SolarCollapse(++SolarCount);
//                    if (SolarCount < 6)
//                        events.RescheduleEvent(EVENT_1, 1000);
//                    break;
//                case EVENT_2:
//                    me->DespawnOrUnsummon();
//                    break;
//            }
//        }
//    }
//};
//
////109804, 111993
//struct npc_telarn_plasma_sphere : ScriptedAI
//{
//    explicit npc_telarn_plasma_sphere(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->SetRegenerateHealth(false);
//    }
//
//    bool explosion = false;
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        DoCast(me, SPELL_PLASMA_SPHERE, true);
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damag)
//    {
//        if (damag >= me->GetHealth())
//        {
//            if (!explosion)
//            {
//                explosion = true;
//                if (auto owner = me->GetOwner())
//                {
//                    if (me->GetEntry() == NPC_CHAOS_SPHERE)
//                        DoCast(me, SPELL_SUM_CONTROLLED_CHAOS, true);
//
//                    if (owner->HasAura(SPELL_NATURE_INFUSION) && owner->HasAura(SPELL_ARCANE_INFUSION))
//                        owner->CastSpell(me, SPELL_TOXIC_SPORES_SUM, true);
//                    else if (owner->HasAura(SPELL_NATURE_INFUSION))
//                        owner->SummonCreature(NPC_PARASITIC_LASHER, me->GetPosition());
//                }
//                DoCast(me, SPELL_PLASMA_EXPLOSION, true);
//                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1 | UNIT_FLAG_NOT_SELECTABLE);
//                me->RemoveAurasDueToSpell(SPELL_PLASMA_SPHERE);
//                me->DespawnOrUnsummon(100);
//            }
//            damag = 0;
//        }
//    }
//
//    void UpdateAI(uint32 diff) override {}
//};
//
////110125
//struct npc_telarn_toxic_spore : public ScriptedAI
//{
//    explicit npc_telarn_toxic_spore(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    void Reset() override {}
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        DoCast(me, SPELL_TOXIC_SPORE_AT, true);
//    }
//
//    void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId)
//    {
//        if (spellId == SPELL_TOXIC_SPORE_DMG)
//        {
//            if (IsMythicRaid())
//            {
//                if (auto owner = me->GetOwner())
//                    if (owner->HasAura(SPELL_SOLAR_INFUSION))
//                        owner->SummonCreature(NPC_SOLAR_COLLAPSE_STALKER, me->GetPosition());
//            }
//            me->SetDisplayId(11686);
//            me->DespawnOrUnsummon(100);
//        }
//    }
//
//    void UpdateAI(uint32 diff) override {}
//};
//
////218508
//class spell_telarn_recursive_strikes : public SpellScript
//{
//    PrepareSpellScript(spell_telarn_recursive_strikes);
//
//    void Damage(SpellEffIndex /*effIndex*/)
//    {
//        if (!GetHitUnit())
//            return;
//
//        if (Aura* aura = GetHitUnit()->GetAura(SPELL_RECURSIVE_STRIKES_DUMMY))
//        {
//            if (aura->GetStackAmount())
//                SetHitDamage(GetHitDamage() * aura->GetStackAmount());
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_telarn_recursive_strikes::Damage, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
//    }
//};
//
////218304
//class spell_telarn_parasitic_fetter : public AuraScript
//{
//    PrepareAuraScript(spell_telarn_parasitic_fetter);
//
//    float mod = 1.0f;
//
//    void HandlePeriodicTick(AuraEffect const* aurEff)
//    {
//        if (!GetTarget()->HasAura(SPELL_PARASITIC_FETTER_ROOT))
//        {
//            aurEff->GetBase()->Remove();
//            return;
//        }
//
//        if (auto aurEff = this->GetEffect(EFFECT_1))
//        {
//            mod += 0.1f;
//            aurEff->SetAmount(GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints * mod);
//        }
//    }
//
//    void Register()
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telarn_parasitic_fetter::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
//    }
//};
//
////218342
//class spell_telarn_parasitic_fixate : public AuraScript
//{
//    PrepareAuraScript(spell_telarn_parasitic_fixate);
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        if (!GetCaster() || !GetCaster()->IsAlive())
//            aurEff->GetBase()->Remove();
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telarn_parasitic_fixate::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////219278
//class spell_telarn_parasitic_fetter_mark : public AuraScript
//{
//    PrepareAuraScript(spell_telarn_parasitic_fetter_mark);
//
//    uint16 m_checkTimer = 500;
//
//    void OnUpdate(AuraEffect const* aurEff)
//    {
//        if (!GetUnitOwner())
//            return;
//
//        if (!GetUnitOwner()->HasAura(SPELL_PARASITIC_FETTER_DOT) || !GetUnitOwner()->HasAura(SPELL_PARASITIC_FETTER_ROOT))
//        {
//            aurEff->GetBase()->Remove();
//        }
//    }
//
//    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetCaster() && GetTarget())
//        {
//            GetCaster()->CastSpell(GetTarget(), SPELL_PARASITIC_FETTER_DOT, true);
//            GetTarget()->CastSpell(GetTarget(), SPELL_PARASITIC_FETTER_ROOT, true);
//        }
//    }
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();
//
//        if (!GetTarget() || mode == AURA_REMOVE_BY_DEATH)
//            return;
//
//        GetTarget()->RemoveAurasDueToSpell(SPELL_PARASITIC_FETTER_DOT);
//        GetTarget()->RemoveAurasDueToSpell(SPELL_PARASITIC_FETTER_ROOT);
//
//        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
//        {
//            if (!GetCaster() || instance->GetBossState(DATA_TELARN) != IN_PROGRESS)
//                return;
//
//            if (instance->instance->IsMythic() && GetCaster()->HasAura(SPELL_ARCANE_INFUSION))
//                GetCaster()->CastSpell(GetTarget(), SPELL_SUM_CONTROLLED_CHAOS, true);
//
//            uint64 saveHealth = 0;
//
//            if (Aura* aura = GetTarget()->GetAura(SPELL_PARASITIC_FIXATE))
//            {
//                if (auto lasher = ObjectAccessor::GetUnit(*GetTarget(), aura->GetCasterGUID()))
//                {
//                    saveHealth = lasher->GetHealth();
//                    if (lasher->IsCreature())
//                        lasher->ToCreature()->DespawnOrUnsummon();
//                }
//                aura->Remove();
//            }
//
//            Position pos;
//            float angle = frand(0.0f, 6.28f);
//            for (uint8 i = 0; i < 2; ++i)
//            {
//                GetTarget()->GetNearPosition(5.0f, angle);
//                angle *= 2.0f;
//
//                if (auto lasher = GetCaster()->SummonCreature(NPC_PARASITIC_LASHER, pos))
//                    if (saveHealth)
//                        lasher->SetHealth(saveHealth);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telarn_parasitic_fetter_mark::OnUpdate, EFFECT_0, SPELL_AURA_DUMMY);
//        OnEffectApply += AuraEffectRemoveFn(spell_telarn_parasitic_fetter_mark::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        OnEffectRemove += AuraEffectRemoveFn(spell_telarn_parasitic_fetter_mark::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////219248
//class spell_telarn_rampant_growth : public AuraScript
//{
//    PrepareAuraScript(spell_telarn_rampant_growth);
//
//    uint8 tick = 0;
//
//    void OnTick(AuraEffect const* aurEff)
//    {
//        ++tick;
//
//        if (tick == 3)
//        {
//            tick = 0;
//            if (aurEff->GetBase()->GetStackAmount() < 10)
//                aurEff->GetBase()->ModStackAmount(1);
//
//            if (aurEff->GetBase()->GetStackAmount() == 5)
//            {
//                GetCaster()->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
//                GetCaster()->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
//                GetCaster()->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
//                GetCaster()->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
//                GetCaster()->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telarn_rampant_growth::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////218780
//class spell_telarn_plasma_explosion : public SpellScript
//{
//    PrepareSpellScript(spell_telarn_plasma_explosion);
//
//    void HandleDamage(SpellEffIndex /*effIndex*/)
//    {
//        if (!GetHitUnit())
//            return;
//
//        if (Aura* aura = GetHitUnit()->GetAura(GetSpellInfo()->Id))
//        {
//            if (aura->GetStackAmount())
//                SetHitDamage(GetHitDamage() * aura->GetStackAmount());
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_telarn_plasma_explosion::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////218809
//class spell_telarn_call_of_night_aura : public AuraScript
//{
//    PrepareAuraScript(spell_telarn_call_of_night_aura);
//
//    //FIXME! Need Timing
//    uint32 m_checkTimer = urand(10, 30) * IN_MILLISECONDS;
//
//    void HandlePeriodicTick(AuraEffect const* aurEff)
//    {
//        if (GetUnitOwner())
//        {
//            for (uint8 i = 0; i < 3; ++i)
//                GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_CALL_OF_NIGHT_VISUAL_1 + i, true);
//        }
//    }
//
//    void OnUpdate(AuraEffect const* aurEff)
//    {
//        if (!GetCaster() || !GetUnitOwner() || GetUnitOwner()->GetEntry() == NPC_PARASITIC_LASHER)
//            return;
//
//
//        if (GetCaster()->GetMap()->IsMythic())
//        {
//            if (GetCaster()->HasAura(SPELL_ARCANE_INFUSION) && GetCaster()->GetEntry() == NPC_SOLARIST_TELARN)
//            {
//                GetCaster()->SummonCreature(NPC_SOLAR_COLLAPSE_STALKER, GetUnitOwner()->GetPosition());
//            }
//            else if (GetCaster()->HasAura(SPELL_NATURE_INFUSION))
//            {
//                GetCaster()->CastSpell(GetUnitOwner(), SPELL_TOXIC_SPORES_SUM, true);
//            }
//        }
//    }
//
//    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTarget())
//            GetTarget()->CastSpell(GetTarget(), SPELL_CALL_OF_NIGHT_SCALE, true);
//    }
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (GetTarget())
//            GetTarget()->RemoveAurasDueToSpell(SPELL_CALL_OF_NIGHT_SCALE);
//    }
//
//    void Register()
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telarn_call_of_night_aura::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_telarn_call_of_night_aura::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
//        OnEffectApply += AuraEffectRemoveFn(spell_telarn_call_of_night_aura::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//        OnEffectRemove += AuraEffectRemoveFn(spell_telarn_call_of_night_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//    }
//};
////218820
//class spell_telarn_arcane_eclipse_filter : public SpellScript
//{
//    PrepareSpellScript(spell_telarn_arcane_eclipse_filter);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster() || !GetOriginalCaster())
//            return;
//
//        //Wait Time Start
//        if (Aura* aura = GetCaster()->GetAura(SPELL_CALL_OF_NIGHT_AURA))
//        {
//            if (aura->GetDuration() >= 43000)
//                return;
//        }
//
//        targets.remove(GetCaster());
//
//        if (targets.empty())
//        {
//            GetOriginalCaster()->CastSpell(GetCaster(), SPELL_ARCANE_ECLIPSE, true);
//            return;
//        }
//
//        for (auto const& target : targets)
//        {
//            if (Player* player = target->ToPlayer())
//            {
//                if (player->HasAura(SPELL_CALL_OF_NIGHT_AURA))
//                {
//                    GetOriginalCaster()->CastSpell(GetCaster(), SPELL_ARCANE_ECLIPSE, true);
//                    return;
//                }
//            }
//        }
//    }
//
//    void Register()
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_telarn_arcane_eclipse_filter::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//    }
//};
//
////218503
//class spell_telarn_recursive_strikes_dummy : public AuraScript
//{
//    PrepareAuraScript(spell_telarn_recursive_strikes_dummy);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (!GetCaster() || !GetTarget() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE || !GetCaster()->GetMap()->IsMythic())
//            return;
//
//        if (GetCaster()->HasAura(SPELL_SOLAR_INFUSION) && GetCaster()->HasAura(SPELL_NATURE_INFUSION))
//            GetCaster()->SummonCreature(NPC_PLASMA_SPHERE, GetTarget()->GetPosition());
//    }
//
//    void Register()
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_telarn_recursive_strikes_dummy::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////216896
//class spell_telarn_share_health : public SpellScript
//{
//    PrepareSpellScript(spell_telarn_share_health);
//
//    uint64 health{};
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (!GetCaster())
//            return;
//
//        health = GetCaster()->GetHealth();
//
//        for (auto const& target : targets)
//        {
//            if (auto unit = target->ToUnit())
//                if (unit->GetHealth() < health)
//                    health = unit->GetHealth();
//        }
//    }
//
//    void HandleScript(SpellEffIndex /*effIndex*/)
//    {
//        if (GetHitUnit() && GetHitUnit()->GetHealth() > health)
//        {
//            uint32 damage = GetHitUnit()->GetHealth() - health;
//        //    GetHitUnit()->DealDamage(GetHitUnit(),victim,damage);
//        }
//    }
//
//    void Register()
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_telarn_share_health::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//        OnEffectHitTarget += SpellEffectFn(spell_telarn_share_health::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
//    }
//};
//
//void AddSC_boss_high_botanist_telarn()
//{
//    RegisterCreatureAI(boss_high_botanist_telarn);
//    RegisterCreatureAI(npc_nh_solarist_telarn);
//    RegisterCreatureAI(npc_nh_arcanist_telarn);
//    RegisterCreatureAI(npc_nh_naturalist_telarn);
//    RegisterCreatureAI(npc_telarn_duskwatch_weaver);
//    RegisterCreatureAI(npc_telarn_controlled_chaos_stalker);
//    RegisterCreatureAI(npc_telarn_parasitic_lasher);
//    RegisterCreatureAI(npc_telarn_solar_collapse_stalker);
//    RegisterCreatureAI(npc_telarn_plasma_sphere);
//    RegisterCreatureAI(npc_telarn_toxic_spore);
//    RegisterSpellScript(spell_telarn_recursive_strikes);
//    RegisterAuraScript(spell_telarn_parasitic_fetter);
//    RegisterAuraScript(spell_telarn_parasitic_fixate);
//    RegisterAuraScript(spell_telarn_parasitic_fetter_mark);
//    RegisterAuraScript(spell_telarn_rampant_growth);
//    RegisterSpellScript(spell_telarn_plasma_explosion);
//    RegisterAuraScript(spell_telarn_call_of_night_aura);
//    RegisterSpellScript(spell_telarn_arcane_eclipse_filter);
//    RegisterSpellScript(spell_telarn_share_health);
//}

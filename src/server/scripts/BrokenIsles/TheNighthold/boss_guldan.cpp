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
//#include "AreaTriggerAI.h"
//#include "thenighthold.h"
//#include "WaypointManager.h"
//#include "WaypointDefines.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerTemplate.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerTemplate.h"
//#include "Spline/Spline.h"
//
//enum Says
//{
//    SAY_AGGRO = 4,
//    SAY_HELLFIRE = 5,
//    SAY_HAND_1 = 6,
//    SAY_FEL_EFLUX_1 = 7,
//    SAY_HAND_2 = 8,
//    SAY_HAND_3 = 9,
//    SAY_PEREPHASE = 10,
//    SAY_PEREPHASE_END = 11,
//    SAY_PHASE_2_START = 12,
//    SAY_EMPOWERED_1 = 13,
//    SAY_EMPOWERED_1_2 = 14,
//    SAY_EYES = 15,
//    SAY_HELLFIRE_1 = 16,
//    SAY_EMPOWERED_2_1 = 17,
//    SAY_EMPOWERED_2_2 = 18,
//    SAY_EMPOWERED_BOUNDS = 19,
//    SAY_EMPOWERED_3_1 = 20,
//    SAY_EMPOWERED_3_2 = 21,
//    SAY_KILLED = 22,
//    SAY_PEREPHASE_2 = 23,
//    SAY_PHASE_3_START = 24,
//    SAY_BLACK_HARVEST = 25,
//    SAY_STORM = 26,
//};
//
//enum Spells
//{
//    //! general
//    SPELL_LIQUID_HELLFIRE = 206219,
//    SPELL_LIQUID_HELLFIRE_SUMMON = 206561,
//    SPELL_LIQUID_HELLFIRE_SUMMON_TRIGGER = 206554,
//    SPELL_LIQUID_HELLFIRE_SUMMON_AT = 206611,
//    SPELL_LIQUID_HELLFIRE_UNKNWN = 206616, // what it is effect? some emotions ???
//
//    SPELL_HAND_OF_GULDAN = 212256,
//    SPELL_HAND_OF_GULDAN_SUMMON_1 = 215736,
//    SPELL_HAND_OF_GULDAN_SUMMON_2 = 215738,
//    SPELL_HAND_OF_GULDAN_SUMMON_3 = 215739,
//    SPELL_HAND_OF_GULDAN_SUMMON_4 = 209126, // her +
//    SPELL_HAND_OF_GULDAN_SUMMON_5 = 212721, // her +
//    SPELL_HAND_OF_GULDAN_SUMMON_6 = 212722, // her +
//    SPELL_SUMMON_VISUAL = 210277,
//
//
//    SPELL_FEL_EFFLUX = 206514, // random target
//    SPELL_FEL_EFLUX_DUMMY = 216953, // ??????????????????????????????????????
//
//    SPELL_ZERO_ENERGY = 118357,
//
//    //! second phase
//    SPELL_EMPOWERED_LIQUID_HELLFIRE = 206220, // with AT
//    SPELL_EMPOWERED_LIQUID_AT = 206581,
//    SPELL_EMPOWERED_LIQUID_HELLFIRE_SUMMON_TRIGGER = 206586,
//    SPELL_EMPOWERED_LIQUID_HELLFIRE_DMG_TICK = 209191,
//
//    SPELL_BOUNDS_OF_FEL = 206222,
//    SPELL_BOUNDS_OF_FEL_DUMMY = 206330,
//    SPELL_BOUNDS_OF_FEL_TICK = 209011,
//    SPELL_BOUNDS_OF_FEL_DMG = 206339,
//    SPELL_BOUNDS_OF_FEL_DMG_AOE = 206340,
//
//    SPELL_EMPOWERED_BOUNDS_OF_FEL = 206221,
//    SPELL_EMPOWERED_BOUNDS_OF_FEL_KNOCK = 206366,
//    SPELL_EMPOWERED_BOUNDS_OF_FEL_DUMMY = 209029,
//    SPELL_EMPOWERED_BOUNDS_OF_FEL_TICK = 206384,
//    SPELL_EMPOWERED_BOUNDS_OF_FEL_AT = 209086,
//    SPELL_EMPOWERED_BOUNDS_OF_FEL_DMG = 206367,
//    SPELL_EMPOWERED_BOUNDS_OF_FEL_DMG_AOE = 206370,
//
//    SPELL_FEL_SCYTHE = 227554,
//    SPELL_FEL_SCYTHE_TRIGGER = 228163,
//    SPELL_FEL_SCYTHE_DMG = 227550,
//    SPELL_FEL_SCYTHE_RISE_DMG = 227557,
//    SPELL_FURRY_OF_THE_FEL = 227556,
//
//
//    SPELL_EYE_OF_GULDAN = 206226,
//    SPELL_EYE_OF_GULDAN_PERIODIC = 209454,
//    SPELL_EYE_OF_GULDAN_SPAWN = 207718,
//    SPELL_EYE_OF_GULDAN_SPAWN_1 = 211133,
//    SPELL_EYE_OF_GULDAN_COPY = 209291,
//    SPELL_EYE_OF_GULDAN_COPY_BURN = 209296,
//    SPELL_EYE_OF_GULDAN_COPY_JUMP = 209297,
//
//    SPELL_EMPOWERED_EYE_OF_GULDAN = 211152,
//    SPELL_EMPOWERED_EYE_OF_GULDAN_PERIODIC = 209489,
//    SPELL_EMPOWERED_EYE_OF_GULDAN_SPAWN = 211107,
//
//    //! third phase
//    SPELL_WIND = 211101,
//    SPELL_WELL_OF_SOULS = 206939,  // 104526
//
//    SPELL_SOUL_CORROSION = 208802,
//    SPELL_SOUL_CORROSION_VISUAL = 212140,
//
//    SPELL_SOUL_SIPHON = 217766, // 110688   18
//    SPELL_SOUL_SIPHON_ABSORB = 221891, // 4 players
//
//    SPELL_BLACK_HARVEST = 206744,
//    SPELL_BLACK_HARVEST_SOUL = 209087,
//
//    SPELL_FEL_OF_SARGERAS = 221783,
//    SPELL_FEL_OF_SARGERAS_TRIGGER = 221606,
//    SPELL_FEL_OF_SARGERAS_AURA = 221603,
//
//    SPELL_STORM_OF_THE_DESTROYER = 161121,
//
//    STORM_OF_THE_DESTROYER_VISUAL = 61453,
//    STORM_OF_THE_DESTROYER_ORPHAN_1 = 55649,
//    STORM_OF_THE_DESTROYER_ORPHAN_2 = 55677,
//    STORM_OF_THE_DESTROYER_ORPHAN_3 = 55683,
//    STORM_OF_THE_DESTROYER_ORPHAN_4 = 61442,
//
//    SPELL_STORM_OF_THE_DESTROYER_END = 152987,
//    SPELL_TELEPORT_AFTER_STORM = 227732,
//
//    // perephase
//    SPELL_EYE_OF_AMANTHUL_PHASE_3 = 227489,
//    SPELL_EYE_OF_AMANTHUL_PHASE_3_1 = 227426,
//    SPELL_EYE_OF_AMANTHUL_PHASE_3_AT = 227755, // as aura
//    SPELL_EYE_OF_AMANTHUL_PHASE_3_AT_END = 232848,
//
//    SPELL_EYE_OF_AMANTHUL_PHASE_2 = 227323, // 68245 68501
//    SPELL_EYE_OF_AMANTHUL_PEREPHASE_TO_2 = 206516,
//
//    // visual and events
//    SPELL_INTRO_FOCUS_ILLIDAN = 227758,
//    SPELL_INTRO_VISUAL_CHARGING = 227433, //! triggered by above
//
//    SPELL_INTRO = 227743,
//    SPELL_VISUAL_CHARGING_1 = 227745, // 114440 NPC_VISUAL_SELECT
//    SPELL_VISUAL_CHARGING_2 = 227749,
//    SPELL_VISUAL_CHARGING_3 = 227750,
//
//    SPELL_BERSERK = 64238,
//    // others
//    SPELL_MOVIE = 234147,
//    SPELL_UNKNWN_RESET_SPELLS = 179300, // at
//    SPELL_UNKNWN_RESET_SPELLS_1 = 179296, // at
//    SPELL_UNKNWN_EDEGES_OF_ROOM = 206261,
//    SPELL_UNKNWN_DESPAWN_AT = 115905,
//    SPELL_DEAD = 206500,
//
//    // players
//    SPELL_RESONANT_BARRIER = 210336, // tank
//    SPELL_TIME_DILATION = 210345, // dd
//    SPELL_SCATTERING_FIELD = 210332, // heals
//};
//
//enum Misc
//{
//    EVENT_1 = 1,
//    EVENT_2,
//    EVENT_3,
//    EVENT_4,
//    EVENT_6,
//    EVENT_5,
//};
//
//enum SpellsDemon
//{
//
//    SPELL_DEMON_INTRO = 210969,
//    SPELL_DEMON_INTRO_END = 211439,
//
//    SPELL_PARASITIC_WOUND = 227035,  // 36 
//    SPELL_PARASITIC_WOUND_DMG = 206847,
//    SPELL_PARASITIC_EXPULSION = 226955,
//    SPELL_SHADOWY_GAZE = 206983,
//
//    SPELL_SOULSEVER = 220957,
//    SPELL_SOULSEVER_AT = 208229,
//    SPELL_SHARED_SOUL = 206458, // script on player
//    SPELL_SHARED_SOUL_ABSORB = 206506,
//    SPELL_SHARED_SOUL_DMG = 227040, // from above ?
//    SPELL_SHARED_SOUL_CLONE = 229524,
//    SPELL_SHARED_SOUL_SIZE = 229534,
//
//    SPELL_FIELD_OF_FLAME = 227094,
//    SPELL_FIELD_OF_FLAME_DUMMY = 227103,
//    SPELL_FIELD_OF_FLAME_TELE = 227106,
//
//    SPELL_AZZINOTHES = 221149, // 41 correct target
//    SPELL_AZZINOTHES_1 = 227277, // 42 correct target
//    SPELL_DEMONIC_ESSENSE = 221434,
//
//    SPELL_SUMMON_NIGHT_SPHERE = 227283, // 45 npc script ?
//    SPELL_TIMESTOP_AREA_AT = 211832, // 59     
//
//    SPELL_DARK_TITAN = 226979, // 90 SCRIPT
//    SPELL_DARK_TITAN_EFFECT = 226982,
//    SPELL_DARK_TITAN_SCREEN = 227032, // players??
//    SPELL_DARK_TITAN_AURA = 227008,
//
//
//    SPELL_STUN_WHEN_INTERRUPT = 227009, // 90 ????    
//
//    SPELL_DEAD_1 = 227401,
//
//    SPELL_DEMONBANE = 226842,
//    SPELL_SHIELD_OF_AZZINOTH = 221299,
//};
//
//enum eEvents
//{
//    EVENT_LIQUID_HELLFIRE = 1,
//    EVENT_HAND_OF_GULDAN_1,
//    EVENT_HAND_OF_GULDAN_2,
//    EVENT_HAND_OF_GULDAN_3,
//    EVENT_FEL_EFFLUX,
//
//    EVENT_PEREPHASE_1_TO_2,
//
//    EVENT_BOUNDS_OF_FEL,
//    EVENT_EYE_OF_GULDAN,
//
//    EVENT_SOUL_SIPHON,
//    EVENT_BLACK_HARVEST,
//    EVENT_FEL_OF_SARGERAS,
//    EVENT_STORM_OF_DESTROYER,
//    EVENT_WIND,
//
//    // additional boss
//    EVENT_FULL_ENERGY,
//    EVENT_DARK_TITAN,
//    EVENT_AZZINOTHES,
//    EVENT_NIGHTHOLD_SPHERE,
//    EVENT_PARASITIC
//};
//
//enum Phases : uint8
//{
//    PHASE_FIRST = 1,
//    PHASE_PEREPHASE_1_TO_2,
//    PHASE_SECOND,
//    PHASE_THIRD
//};
//
//uint32 handOfGuldanSpells[6]
//{
//    SPELL_HAND_OF_GULDAN_SUMMON_1,
//    SPELL_HAND_OF_GULDAN_SUMMON_2,
//    SPELL_HAND_OF_GULDAN_SUMMON_3,
//    SPELL_HAND_OF_GULDAN_SUMMON_4,
//    SPELL_HAND_OF_GULDAN_SUMMON_5,
//    SPELL_HAND_OF_GULDAN_SUMMON_6,
//};
//
//uint32 textsBySummons[3]
//{
//    SAY_HAND_1,
//    SAY_HAND_2,
//    SAY_HAND_3
//};
//
//uint32 textsForEmpowered[6]
//{
//    SAY_EMPOWERED_1,
//    SAY_EMPOWERED_1_2,
//
//    SAY_EMPOWERED_2_1,
//    SAY_EMPOWERED_2_2,
//
//    SAY_EMPOWERED_3_1,
//    SAY_EMPOWERED_3_2,
//};
//
//template<typename T>
//struct MySpecialList : public std::list<T>
//{
//    MySpecialList() = default;
//
//    MySpecialList(const std::initializer_list<T>& _list) :
//        std::list<T>(_list) {};
//
//    T popAndSafeLast()
//    {
//        if (this->empty())
//            throw "MySpecialList is empty!";
//
//        T val = this->front();
//        if (this->size() > 1)
//            this->pop_front();
//
//        return val;
//    }
//};
//
//
//MySpecialList<uint32> felEfluxTimersNormalAndLfr{ 11000, 14000, 19900, 15600, 16800, 15900, 15800, 12000 };
//MySpecialList<uint32> felEfluxTimersHeroic{ 11000, 14000, 18500, 12000 };
//
//
//MySpecialList<uint32> liquidHellfireTimersLfr{ 67000, 44000, 44000, 88000, 44000, 88000, 38600, 44000 };
//MySpecialList<uint32> liquidHellfireTimersNormal{ 63000, 41000, 41000, 84000, 41000, 84000, 36000, 41000 };
//MySpecialList<uint32> liquidHellfireTimersHeroic{ 59000, 36000, 36000, 74000, 36000, 74000, 31600, 36000 };
//MySpecialList<uint32> liquidHellfireTimersMythic{ 36000, 33000, 33000, 66000, 33000, 66000, 28900, 33000 };
//
//
//MySpecialList<uint32> eyeOfGuldanTimersNormal{ 42500, 71500, 71400, 28600, 114000 };
//MySpecialList<uint32> eyeOfGuldanTimersHeroic{ 39100, 625000, 625000, 25000, 100000 };
//MySpecialList<uint32> eyeOfGuldanTimersMythic{ 35100, 52600, 53300, 20400, 84200, 52600 };
//
//MySpecialList<uint32> blackHarvestTimersNormal{ 63000, 82900, 100000, 100000 };
//MySpecialList<uint32> blackHarvestTimersHeroic{ 64100, 72500, 87500,  87500 };
//MySpecialList<uint32> blackHarvestTimersMythic{ 55700, 61000, 75300,  86800 };
//
//MySpecialList<uint32> stormTimersNormal{ 94000, 78600, 70000, 87000 };
//MySpecialList<uint32> stormTimersHeroic{ 84100, 68700, 61300, 76500 };
//MySpecialList<uint32> stormTimersMythic{ 57900, 51600, 64700, 57400 };
//
//MySpecialList<uint32> darkTitanTimer{ 95000, 90000, 150000, 90000 };
//MySpecialList<uint32> nightOrbTimer{ 39000, 45000, 60000, 40000 };
//
//Position const positionsOfStatues[4]
//{
//    {320.24f, 3173.72f, 465.85f, 3.90f},
//    {320.49f, 3097.39f, 465.85f, 2.33f},
//    {244.45f, 3097.04f, 465.85f, 0.82f},
//    {244.07f, 3173.33f, 465.85f, 5.47f},
//
//};
//
//uint32 spellsVisualCharging[4]
//{
//    SPELL_INTRO_FOCUS_ILLIDAN,
//    SPELL_VISUAL_CHARGING_1,
//    SPELL_VISUAL_CHARGING_2,
//    SPELL_VISUAL_CHARGING_3,
//};
//
//uint32 statuesVisual[4]
//{
//    GO_STATUE_1,
//    GO_STATUE_2,
//    GO_STATUE_3,
//    GO_STATUE_4
//};
//
//// 104154
//class boss_guldan : public CreatureScript
//{
//public:
//    boss_guldan() : CreatureScript("boss_guldan") {}
//
//    struct boss_guldanAI : BossAI
//    {
//        boss_guldanAI(Creature* creature) : BossAI(creature, DATA_GULDAN)
//        {
//            SetCorrectTimers();
//            JustReachedHome();
//            me->m_CombatDistance = 10;
//            _introDone = false;
//        }
//
//        int8 currentAdd;
//        uint8 addDies;
//
//        bool isEmpowered[3]; // bounds (85%) -> liquid hellfire (70%) -> Eye of guldan (55%)
//        uint32 healthForEmpowered[3]{ 85, 70, 55 };
//
//        uint16 eyesOfGuldanCasts, felOfSargerasCasts;
//        MySpecialList<uint32> felEfluxTimer, liquidHellfireTimer, eyeOfGuldanTimer, blackHarvestTimer, stormTimer;
//        uint32 boundsOfFelTimer;
//
//        Creature* selectedVisual{};
//        std::map<ObjectGuid, std::vector<ObjectGuid>> addsBoundsOfFel{};
//        std::stack<ObjectGuid> souls{};
//
//        bool can_regenerate_energy;
//        uint32 timer_for_energy;
//
//        uint8 phase;
//
//        uint32 healthEvent, healthEventMythic;
//        uint32 healthForThirdPhase;
//        time_t lastTimeDestroyer = 0;
//
//        bool _introDone;
//        bool  isDead = false;
//
//        void Reset() override
//        {
//            addsBoundsOfFel.clear();
//
//            while (!souls.empty())
//                souls.pop();
//
//            me->RemoveAllAreaObjects();
//
//            currentAdd = -1;
//            addDies = 0;
//
//            eyesOfGuldanCasts = 0;
//            felOfSargerasCasts = 0;
//
//            healthEvent = 20;
//            healthEventMythic = 10;
//            isDead = false;
//            lastTimeDestroyer = 0;
//
//            if (IsMythicRaid())
//                healthForThirdPhase = 50;
//            else
//                healthForThirdPhase = 40;
//
//            for (uint8 i = 0; i < 3; ++i)
//                isEmpowered[i] = false;
//
//            can_regenerate_energy = false;
//            timer_for_energy = 1000;
//            me->SetPower(POWER_ENERGY, 0);
//
//            phase = PHASE_FIRST;
//
//            RemoveEncounterAuras(SPELL_BOUNDS_OF_FEL_TICK);
//            RemoveEncounterAuras(SPELL_SOUL_CORROSION);
//
//            RemoveEncounterAuras(SPELL_RESONANT_BARRIER);
//            RemoveEncounterAuras(SPELL_TIME_DILATION);
//            RemoveEncounterAuras(SPELL_SCATTERING_FIELD);
//
//            RemoveEncounterAuras(SPELL_SHADOWY_GAZE);
//            RemoveEncounterAuras(SPELL_PARASITIC_WOUND_DMG);
//            RemoveEncounterAuras(SPELL_SHARED_SOUL);
//            RemoveEncounterAuras(SPELL_SHARED_SOUL_ABSORB);
//            RemoveEncounterAuras(SPELL_DARK_TITAN_SCREEN);
//            RemoveEncounterAuras(SPELL_FEL_OF_SARGERAS_AURA);
//
//            KillAllDelayedEvents();
//            me->SetVisible(true);
//            me->SetReactState(REACT_DEFENSIVE);
//            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//
//            std::list<AreaTrigger*> list;
//            me->GetAreaTriggerListWithSpellIDInRange(list, 12376, 120.0f); // fel of sargeras
//            for (auto at : list)
//                at->Remove();
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            Talk(SAY_AGGRO);
//
//            me->CastStop();
//            me->RemoveAllAuras();
//
//            AddDelayedEvent(12 * MINUTE * IN_MILLISECONDS, [this]() -> void
//            {
//                if (me->IsAlive() && me->IsInCombat())
//                    me->CastSpell(me, SPELL_BERSERK);
//
//            });
//
//            if (!IsMythicRaid())
//            {
//                me->RemoveAurasDueToSpell(spellsVisualCharging[addDies]);
//
//                if (selectedVisual)
//                    selectedVisual->DespawnOrUnsummon();
//
//                selectedVisual = me->SummonCreature(NPC_VISUAL_SELECT, positionsOfStatues[addDies + 1]);
//                DoCast(spellsVisualCharging[addDies + 1]);
//
//                DefaultEvents(PHASE_FIRST);
//                me->SetControlled(true, UNIT_STATE_ROOT);
//            }
//            else
//                DefaultEvents(PHASE_SECOND); // start from 2 phase
//
//            if (IsLFR())
//                return;
//
//            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
//            if (!PlayerList.isEmpty())
//                for (auto const& itr : PlayerList)
//                    if (Player* player = itr.GetSource())
//                    {
//                        uint32 spellId = 0;
//                        switch (player->GetSpecializationId())
//                        {
//                        case ROLE_HEALER:
//                            spellId = SPELL_SCATTERING_FIELD;
//                            break;
//                        case ROLE_DAMAGE:
//                            spellId = SPELL_TIME_DILATION;
//                            break;
//                        case ROLE_TANK:
//                            spellId = SPELL_RESONANT_BARRIER;
//                            break;
//                        }
//
//                        if (spellId)
//                            player->CastSpell(player, spellId, true);
//                    }
//        }
//
//        void JustReachedHome() override
//        {
//            std::list<AreaTrigger*> list;
//            me->GetAreaTriggerListWithSpellIDInRange(list, 12376, 120.0f); // fel of sargeras
//            for (auto at : list)
//                at->Remove();
//
//            me->SetControlled(true, UNIT_STATE_ROOT);
//
//            if (IsMythicRaid())
//            {
//                for (uint8 i = 0; i < 4; ++i)
//                {
//                    me->AddAura(spellsVisualCharging[i], me);
//                }
//
//                DoCast(SPELL_EYE_OF_AMANTHUL_PEREPHASE_TO_2);
//            }
//            else
//            {
//                me->AddAura(SPELL_INTRO_FOCUS_ILLIDAN, me);
//                DoCast(SPELL_INTRO);
//
//                if (selectedVisual)
//                    selectedVisual->DespawnOrUnsummon();
//
//                selectedVisual = me->SummonCreature(NPC_VISUAL_SELECT, positionsOfStatues[addDies]);
//
//                me->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN); // visual
//                me->ClearUnitState(UNIT_STATE_CANNOT_TURN); // for correct work
//            }
//
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            if (!IsMythicRaid())
//            {
//                _JustDied();
//                DoCast(SPELL_DEAD);
//                DoCast(SPELL_MOVIE);
//
//                //instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FEL_OF_SARGERAS_AURA);
//                std::list<AreaTrigger*> list;
//                me->GetAreaTriggerListWithSpellIDInRange(list, 12376, 120.0f); // fel of sargeras
//                for (auto at : list)
//                    at->Remove();
//            }
//            else
//            {
//                me->SetVisible(false);
//                // me->RemoveAllAreaObjects();
//                me->m_Events.KillAllEvents(true);
//
//                events.Reset();
//                summons.DespawnEntry(104526);
//                summons.DespawnEntry(NPC_BLACK_SOUL);
//                summons.DespawnEntry(NPC_CRYSTALL_OF_ILLIDAN);
//            }
//
//            RemoveEncounterAuras(SPELL_BOUNDS_OF_FEL_TICK);
//            RemoveEncounterAuras(SPELL_SOUL_CORROSION);
//            RemoveEncounterAuras(SPELL_RESONANT_BARRIER);
//            RemoveEncounterAuras(SPELL_TIME_DILATION);
//            RemoveEncounterAuras(SPELL_SCATTERING_FIELD);
//        }
//
//        void KilledUnit(Unit* who) override
//        {
//            if (who->IsPlayer() && urand(1, 2) == 1)
//                Talk(SAY_KILLED);
//        }
//
//        void MoveInLineOfSight(Unit* who) override
//        {
//            if (who->GetTypeId() == TYPEID_PLAYER && !_introDone && me->IsWithinDistInMap(who, 60.0f))
//            {
//                _introDone = true;
//                if (IsMythicRaid())
//                    return;
//
//                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//
//                AddDelayedEvent(10000, [this]() -> void
//                {
//                    if (Creature* illidan = me->GetMap()->GetCreature(instance->GetGuidData(NPC_CRYSTALL_OF_ILLIDAN)))
//                    {
//                        me->CastSpell(illidan, SPELL_INTRO_FOCUS_ILLIDAN);
//                        Talk(0);
//
//                        AddDelayedEvent(23000, [this]() -> void
//                        {
//                            Talk(1);
//                            AddDelayedEvent(18000, [this]() -> void
//                            {
//                                Talk(2);
//                                AddDelayedEvent(16000, [this]() -> void
//                                {
//                                    Talk(3);
//                                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//                                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                                    me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                                    //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
//                                    DoCast(SPELL_INTRO);
//                                });
//                            });
//                        });
//
//                        AddDelayedEvent(23000 + 18000 + 16000, [illidan]() -> void
//                        {
//                            illidan->GetMotionMaster()->MovePoint(0, 278.29f, 3136.03f, 507.45f);
//                        });
//                    }
//                });
//            }
//
//        }
//
//        void SpellFinishCast(const SpellInfo* spell)
//        {
//            switch (spell->Id)
//            {
//            case SPELL_STORM_OF_THE_DESTROYER_END:
//            {
//                std::list<AreaTrigger*> list;
//                me->GetAreaTriggerListWithSpellIDInRange(list, 12376, 120.0f); // fel of sargeras
//                for (auto at : list)
//                    at->Remove();
//                break;
//            }
//            case SPELL_FEL_OF_SARGERAS:
//            {
//
//
//                    Unit* target = me->GetVictim();
//                    me->CastSpell(target, SPELL_FEL_OF_SARGERAS_TRIGGER, true);
//
//                break;
//            }
//            case SPELL_EYE_OF_GULDAN:
//            case SPELL_EMPOWERED_EYE_OF_GULDAN:
//            {
//                Unit* vict = me->GetVictim();
//                for (uint8 i = 0; i < (spell->Id == SPELL_EMPOWERED_EYE_OF_GULDAN ? 1 : 3); ++i)
//                    me->SummonCreature(spell->Id == SPELL_EYE_OF_GULDAN ? NPC_EYE_OF_GULDAN : NPC_EMPOWERED_EYE_OF_GULDAN, vict->GetPositionX() + frand(-7.0f, 7.0f), vict->GetPositionY() + frand(-7.0f, 7.0f), 465.93f);
//                break;
//            }
//            case SPELL_FEL_SCYTHE_DMG:
//                if (!me->HasAura(SPELL_FEL_SCYTHE_RISE_DMG))
//                    me->AddAura(SPELL_FEL_SCYTHE_RISE_DMG, me);
//
//                if (Aura* aura = me->GetAura(SPELL_FEL_SCYTHE_RISE_DMG))
//                    aura->SetStackAmount(aura->GetStackAmount() + me->GetPower(POWER_ENERGY));
//
//                DoCast(SPELL_FURRY_OF_THE_FEL);
//
//                me->SetPower(POWER_ENERGY, 0);
//                DoCast(SPELL_ZERO_ENERGY);
//                break;
//            }
//        }
//
//        void JustSummoned(Creature* summon) override
//        {
//            switch (summon->GetEntry())
//            {
//            case NPC_AZAGRIM:
//            case NPC_BELTERIS:
//            case NPC_DALVENGIR:
//                summon->CastSpell(summon, 209127);
//                summon->CastSpell(summon, 212625);
//                break;
//            case NPC_BLACK_SOUL:
//                souls.push(summon->GetGUID());
//                summon->SetReactState(REACT_PASSIVE);
//                summon->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                summon->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//               // summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
//                summon->GetMotionMaster()->MoveCirclePath(282.45f, 3135.35f, 471.45f + souls.size(), 14.0f, true, 24);
//                break;
//            case NPC_VISUAL_SELECT:
//                return;
//            case NPC_HELLFIRE:
//                summon->SetReactState(REACT_PASSIVE);
//                summon->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                summon->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                summon->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//                //summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
//                summon->CastSpell(summon, SPELL_LIQUID_HELLFIRE_SUMMON_AT);
//                summon->SetVisible(true);
//
//                float x, y, z;
//                summon->GetClosePoint(x, y, z, summon->GetObjectSize() / 3, 2);
//                summon->GetMotionMaster()->MovePoint(0, x, y, z + 6.0f);
//
//                AddDelayedEvent(3000, [summon, this]() -> void
//                {
//                    Unit* target = nullptr;
//                    target = SelectTarget(SELECT_TARGET_MAXDISTANCE, urand(1, 2), 0.0f, true);
//                    if (!target)
//                        target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, 0.0f, true);
//
//                    if (target)
//                        me->CastSpell(target, (isEmpowered[1] ? SPELL_EMPOWERED_LIQUID_HELLFIRE_SUMMON_TRIGGER : SPELL_LIQUID_HELLFIRE_SUMMON_TRIGGER));
//
//                    summon->RemoveAurasDueToSpell(SPELL_LIQUID_HELLFIRE_SUMMON_AT);
//                    summon->DespawnOrUnsummon(100);
//                });
//                break;
//            case NPC_EYE_OF_GULDAN:
//            case NPC_EMPOWERED_EYE_OF_GULDAN:
//                summon->Respawn(true); // fix energy
//                AddDelayedEvent(500, [summon]() -> void
//                {
//                    summon->SetControlled(true, UNIT_STATE_ROOT);
//                });
//                break;
//            case NPC_VETRIZ:
//                summon->Respawn(true); // fix energy
//            case NPC_KURAZMAL:
//            case NPC_DZORIKS:
//                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
//                instance->SendEncounterUnit(ENCOUNTER_FRAME_ADD_COMBAT_RES_LIMIT, summon);
//                me->CastSpell(me, SPELL_SUMMON_VISUAL, true);
//                break;
//            }
//
//            summon->m_CombatDistance = 10;
//
//            BossAI::JustSummoned(summon);
//        }
//
//        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//        {
//            switch (summon->GetEntry())
//            {
//            case NPC_AZAGRIM:
//            case NPC_BELTERIS:
//            case NPC_DALVENGIR:
//                summon->CastSpell(summon, 209142);
//                break;
//            case NPC_KURAZMAL:
//            case NPC_VETRIZ:
//            case NPC_DZORIKS:
//                ++addDies;
//
//                me->RemoveAurasDueToSpell(spellsVisualCharging[addDies]);
//
//                if (selectedVisual)
//                    selectedVisual->DespawnOrUnsummon();
//                selectedVisual = nullptr;
//
//        
//
//                if (addDies >= 3)
//                {
//                    DefaultEvents(PHASE_SECOND);
//                    summons.DespawnAll();
//                    return;
//                }
//
//
//                selectedVisual = me->SummonCreature(NPC_VISUAL_SELECT, positionsOfStatues[addDies + 1]);
//
//                DoCast(spellsVisualCharging[addDies + 1]);
//                break;
//            }
//        }
//
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_EMPOWERED_BOUNDS_OF_FEL_DMG_AOE:
//            case SPELL_BOUNDS_OF_FEL_DMG_AOE:
//            {
//                ObjectGuid guid = target->GetGUID();
//                AddDelayedEvent(1000, [this, guid]() -> void
//                {
//                    for (auto add_guid : addsBoundsOfFel[guid])
//                        if (Creature* add = me->GetMap()->GetCreature(add_guid))
//                            add->DespawnOrUnsummon();
//
//                    addsBoundsOfFel[guid].clear();
//                });
//                break;
//            }
//            case SPELL_EMPOWERED_BOUNDS_OF_FEL_TICK:
//                target->CastSpell(me, SPELL_EMPOWERED_BOUNDS_OF_FEL_KNOCK);
//                AddDelayedEvent(3000, [target, this]() -> void
//                {
//                    target->CastSpell(target, SPELL_EMPOWERED_BOUNDS_OF_FEL_AT);
//
//                    for (float dif = -3; dif <= 3; dif += 6)
//                        if (Creature* add = me->SummonCreature(NPC_BOUNDS_OF_FEL, { target->GetPositionX() + dif, target->GetPositionY(), target->GetPositionZ(), 0.0f }, TEMPSUMMON_MANUAL_DESPAWN, 0))
//                        {
//                            add->CastSpell(target, 206373);
//                            add->CastSpell(target, (dif == -3 ? 206401 : 206383));
//
//                            addsBoundsOfFel[target->GetGUID()].push_back(add->GetGUID());
//                        }
//
//                    me->CastSpell(target, SPELL_EMPOWERED_BOUNDS_OF_FEL_DMG, true);
//                });
//                break;
//            case SPELL_BOUNDS_OF_FEL_DUMMY:
//                for (float dif = -3; dif <= 3; dif += 6)
//                    if (Creature* add = me->SummonCreature(NPC_BOUNDS_OF_FEL, { target->GetPositionX() + dif, target->GetPositionY(), target->GetPositionZ(), 0.0f }, TEMPSUMMON_MANUAL_DESPAWN, 0))
//                    {
//                        add->CastSpell(target, 206373);
//                        add->CastSpell(target, (dif == -3 ? 206401 : 206383));
//
//                        addsBoundsOfFel[target->GetGUID()].push_back(add->GetGUID());
//                    }
//                me->CastSpell(target, SPELL_BOUNDS_OF_FEL_DMG, true);
//                break;
//            }
//        }
//
//        void DamageTaken(Unit* attacker, uint32& damage)
//        {
//            if (isDead)
//            {
//                damage = 0;
//                return;
//            }
//
//            for (uint8 i = 0; i < 3; ++i)
//                if (!isEmpowered[i] && me->HealthBelowPct(healthForEmpowered[i]))
//                {
//                    isEmpowered[i] = true;
//                    Talk(textsForEmpowered[i * 2]);
//                    Talk(textsForEmpowered[i * 2 + 1]);
//                }
//
//            if (phase != PHASE_THIRD && me->HealthBelowPct(healthForThirdPhase))
//            {
//                phase = PHASE_THIRD; // for avoiding some different bugs
//                DefaultEvents(PHASE_THIRD);
//            }
//
//            if (healthEvent && me->HealthBelowPct(healthEvent))
//            {
//                healthEvent = 0;
//                if (Creature* khadgar = me->FindNearestCreature(NPC_KHADGAR_PHASE_3, 500.0f, true))
//                    khadgar->AI()->Talk(1);
//            }
//
//            if (IsMythicRaid() && healthEventMythic && (me->HealthBelowPct(healthEventMythic) || me->HealthBelowPctDamaged(healthEventMythic, damage)))
//            {
//                switch (healthEventMythic)
//                {
//                case 10:
//                    healthEventMythic = 2;
//                    me->SummonCreature(NPC_DEMON_WITHIN, me->GetHomePosition());
//                    break;
//                case 2:
//                    damage = 0;
//
//                    if (time(NULL) - lastTimeDestroyer > 10)
//                    {
//                        healthEventMythic = 0;
//                        isDead = true;
//                        KillAllDelayedCombats();
//                        KillAllDelayedEvents();
//                        me->AttackStop();
//                        me->CastStop();
//                        JustDied(me);
//                    }
//                    break;
//                }
//            }
//        }
//
//        void DefaultEvents(uint8 _phase)
//        {
//            events.Reset();
//            phase = _phase;
//
//            eyesOfGuldanCasts = 0;
//
//            switch (_phase)
//            {
//            case PHASE_FIRST: // first phase
//                events.RescheduleEvent(EVENT_LIQUID_HELLFIRE, 2000);
//                events.RescheduleEvent(EVENT_HAND_OF_GULDAN_1, 6000);
//                events.RescheduleEvent(EVENT_HAND_OF_GULDAN_2, 6000 + 15000);
//                events.RescheduleEvent(EVENT_HAND_OF_GULDAN_3, 6000 + 15000 + 10000);
//                events.RescheduleEvent(EVENT_PEREPHASE_1_TO_2, 6000 + 15000 + 10000 + 3000);
//                events.RescheduleEvent(EVENT_FEL_EFFLUX, felEfluxTimer.popAndSafeLast());
//                break;
//            case PHASE_PEREPHASE_1_TO_2: // from 1 to 2 
//                events.RescheduleEvent(EVENT_LIQUID_HELLFIRE, 5000); // + 32000
//                events.RescheduleEvent(EVENT_FEL_EFFLUX, 11000);
//                break;
//            case PHASE_SECOND: // 2 phase
//            {
//                Talk(SAY_PEREPHASE_END);
//                EventPerephaseToSecond();
//
//                uint32 timer = 0;
//                if (IsMythicRaid())
//                    timer = 26000;
//                else if (IsHeroicRaid())
//                    timer = 48000;
//                else if (IsNormalRaid())
//                    timer = 50600;
//                else
//                    timer = 54000;
//
//                eyesOfGuldanCasts++;
//                events.RescheduleEvent(EVENT_EYE_OF_GULDAN, timer);
//
//                timer = 0;
//                if (IsMythicRaid())
//                    timer = 65000;
//                else
//                    timer = 25000;
//
//                events.RescheduleEvent(EVENT_BOUNDS_OF_FEL, timer);
//                events.RescheduleEvent(EVENT_LIQUID_HELLFIRE, liquidHellfireTimer.popAndSafeLast());
//                if (IsHeroicRaid())
//                {
//                    events.RescheduleEvent(EVENT_HAND_OF_GULDAN_1, 33000);
//                    events.RescheduleEvent(EVENT_HAND_OF_GULDAN_2, 33000 + 48000);
//                    events.RescheduleEvent(EVENT_HAND_OF_GULDAN_3, 33000 + 48000 + 138800);
//                }
//
//                if (IsMythicRaid())
//                {
//                    events.RescheduleEvent(EVENT_HAND_OF_GULDAN_1, 17000);
//                    events.RescheduleEvent(EVENT_HAND_OF_GULDAN_2, 17000 + 165000);
//                }
//                break;
//            }
//            case PHASE_THIRD:
//            {
//                me->m_Events.KillAllEvents(true);
//                RemoveEncounterAuras(SPELL_EMPOWERED_LIQUID_HELLFIRE);
//                DoCast(SPELL_EYE_OF_AMANTHUL_PHASE_3);
//                me->AddAura(SPELL_EYE_OF_AMANTHUL_PHASE_3_AT, me);
//                me->RemoveDynObject(SPELL_EMPOWERED_LIQUID_AT);
//
//                Talk(SAY_PEREPHASE_2);
//                EventPerephaseToThird();
//
//                uint32 timer = 0;
//                if (IsMythicRaid())
//                    timer = 55700;
//                else if (IsLFR())
//                    timer = 73100;
//                else
//                    timer = 63000;
//
//                events.RescheduleEvent(EVENT_BLACK_HARVEST, timer);
//
//                if (IsMythicRaid())
//                    timer = 24500;
//                else if (IsHeroicRaid())
//                    timer = 27500;
//                else
//                    timer = 29000;
//                events.RescheduleEvent(EVENT_FEL_OF_SARGERAS, timer);
//
//                if (IsMythicRaid())
//                    timer = 34300;
//                else if (IsHeroicRaid())
//                    timer = 39000;
//                else
//                    timer = 42500;
//                events.RescheduleEvent(EVENT_EYE_OF_GULDAN, timer);
//
//                if (IsMythicRaid())
//                    timer = 72600;
//                else if (IsHeroicRaid())
//                    timer = 84000;
//                else
//                    timer = 94000;
//                events.RescheduleEvent(EVENT_STORM_OF_DESTROYER, timer);
//
//                if (!IsLFR())
//                    events.RescheduleEvent(EVENT_SOUL_SIPHON, urand(25000, 30000));
//                break;
//            }
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//
//            events.Update(diff);
//
//            if (can_regenerate_energy)
//            {
//                if (timer_for_energy <= diff) // we need it there, because energy regenerate while casting too
//                {
//                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(2, 3));
//                    if (me->GetPower(POWER_ENERGY) >= 100)
//                        DoCast(SPELL_FEL_SCYTHE_DMG);
//
//                    timer_for_energy = 1000;
//                }
//                else
//                    timer_for_energy -= diff;
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_LIQUID_HELLFIRE:
//                {
//                    Talk(SAY_HELLFIRE);
//                    Talk(SAY_HELLFIRE_1);
//
//                    DisableRotation(5000);
//
//                    DoCast(SPELL_LIQUID_HELLFIRE_SUMMON); // we need cast it first for "real work"
//                    DoCast(isEmpowered[1] ? SPELL_EMPOWERED_LIQUID_HELLFIRE : SPELL_LIQUID_HELLFIRE); // then it as "visual"
//
//                    uint32 timer = 0;
//                    switch (phase)
//                    {
//                    case PHASE_FIRST:
//                        timer = 15000;
//                        break;
//                    case PHASE_PEREPHASE_1_TO_2:
//                        timer = IsHeroicRaid() ? 23800 : 32000;
//                        break;
//                    case PHASE_SECOND:
//                        timer = liquidHellfireTimer.popAndSafeLast();
//                        break;
//                    }
//                    events.RescheduleEvent(EVENT_LIQUID_HELLFIRE, timer);
//                    break;
//                }
//                case EVENT_HAND_OF_GULDAN_1:
//                case EVENT_HAND_OF_GULDAN_2:
//                case EVENT_HAND_OF_GULDAN_3:
//                    Talk(textsBySummons[++currentAdd % 3]);
//                    DoCast(SPELL_HAND_OF_GULDAN);
//                    break;
//                case EVENT_FEL_EFFLUX:
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
//                        me->SetFacingTo(me->GetAngle(target));
//
//                    DisableRotation(9000);
//
//                    DoCast(SPELL_FEL_EFFLUX);
//                    AddDelayedEvent(2010, [this]() -> void // hack. If spell hit player, when dmg started - boss rotating again
//                    {
//                        DisableRotation(9000);
//                    });
//
//                    events.RescheduleEvent(EVENT_FEL_EFFLUX, felEfluxTimer.popAndSafeLast());
//                    break;
//                case EVENT_PEREPHASE_1_TO_2:
//                    Talk(SAY_PEREPHASE);
//                    DefaultEvents(PHASE_PEREPHASE_1_TO_2);
//                    DoCast(SPELL_EYE_OF_AMANTHUL_PEREPHASE_TO_2);
//
//        
//                    break;
//                case EVENT_BOUNDS_OF_FEL:
//                {
//                    if (isEmpowered[0])
//                        Talk(SAY_EMPOWERED_BOUNDS);
//
//                    me->CastSpell(me->GetVictim(), isEmpowered[0] ? SPELL_EMPOWERED_BOUNDS_OF_FEL_DUMMY : SPELL_BOUNDS_OF_FEL_DUMMY);
//
//                    DoCast(isEmpowered[0] ? SPELL_EMPOWERED_BOUNDS_OF_FEL : SPELL_BOUNDS_OF_FEL);
//
//                    events.RescheduleEvent(EVENT_BOUNDS_OF_FEL, boundsOfFelTimer);
//                    break;
//                }
//                case EVENT_EYE_OF_GULDAN:
//                {
//                    Talk(SAY_EYES);
//                    DoCast(isEmpowered[2] ? SPELL_EMPOWERED_EYE_OF_GULDAN : SPELL_EYE_OF_GULDAN);
//
//                    uint32 timer = 0;
//                    if ((phase == PHASE_SECOND && IsMythicRaid()) || phase == PHASE_THIRD)
//                        timer = eyeOfGuldanTimer.popAndSafeLast();
//                    else
//                    {
//                        uint32 longTimer = 75000, shortTimer = 60000; // like dbm normal
//                        if (IsMythicRaid())
//                        {
//                            longTimer = 80000;
//                            shortTimer = 48000;
//                        }
//                        else if (IsHeroicRaid())
//                        {
//                            longTimer = 80000;
//                            shortTimer = 48000;
//                        }
//                        else if (IsLFR())
//                        {
//                            longTimer = 80000;
//                            shortTimer = 64000;
//                        }
//                        // else Normal
//
//                        if (eyesOfGuldanCasts == 5)
//                            timer = longTimer;
//                        else
//                            timer = shortTimer;
//
//                        eyesOfGuldanCasts++;
//                    }
//                    events.RescheduleEvent(EVENT_EYE_OF_GULDAN, timer);
//                    break;
//                }
//                case EVENT_BLACK_HARVEST:
//                    Talk(SAY_BLACK_HARVEST);
//                    DoCast(SPELL_BLACK_HARVEST);
//                    AddDelayedEvent(2000, [this]() -> void
//                    {
//                        if (!souls.size())
//                            return;
//
//                        uint32 timer = 1000 / souls.size();
//                        while (!souls.empty())
//                        {
//                            if (Creature* soul = me->GetMap()->GetCreature(souls.top()))
//                            {
//                                souls.pop();
//                                Position pos_cast(281.76f, 3135.41f, 465.99f);
//
//                                pos_cast.m_positionX += frand(15.0f, 40.0f) * (urand(0, 1) == 0 ? -1 : 1);
//                                pos_cast.m_positionY += frand(15.0f, 40.0f) * (urand(0, 1) == 0 ? -1 : 1);
//
//                                AddDelayedEvent((souls.size() + 1) * timer, [soul, pos_cast]()  -> void
//                                {
//                                    soul->CastSpell(pos_cast, SPELL_SOUL_CORROSION_VISUAL, false);
//                                    soul->DespawnOrUnsummon(1000);
//                                });
//
//                                AddDelayedEvent(3000, [this, pos_cast]()-> void
//                                {
//                                    me->CastSpell(pos_cast, SPELL_BLACK_HARVEST_SOUL, false);
//                                });
//                            }
//                            else
//                                souls.pop();
//                        }
//                    });
//
//                    if (IsMythicRaid())
//                    {
//                        if (blackHarvestTimer.size() == 3)
//                            events.RescheduleEvent(EVENT_WIND, 67000);
//                        else if (blackHarvestTimer.size() == 2)
//                            events.RescheduleEvent(EVENT_WIND, 75000);
//                    }
//                    events.RescheduleEvent(EVENT_SOUL_SIPHON, urand(25000, 30000));
//                    events.RescheduleEvent(EVENT_BLACK_HARVEST, blackHarvestTimer.popAndSafeLast());
//                    break;
//                case EVENT_FEL_OF_SARGERAS:
//                {
//                    Talk(SAY_FEL_EFLUX_1);
//                    DoCast(SPELL_FEL_OF_SARGERAS);
//                    uint32 timer = 19000;
//                    if (IsMythicRaid())
//                        timer = 7000;
//                    else if (IsHeroicRaid())
//                        timer = 8000;
//                    // else normal
//
//                    events.RescheduleEvent(EVENT_FEL_OF_SARGERAS, timer);
//                    felOfSargerasCasts++;
//
//                    if (felOfSargerasCasts == 2)
//                        events.RescheduleEvent(EVENT_WIND, 31000);
//                    break;
//                }
//                case EVENT_STORM_OF_DESTROYER:
//                    Talk(SAY_STORM);
//                    DoCast(SPELL_STORM_OF_THE_DESTROYER);
//
//                    lastTimeDestroyer = time(NULL);
//                    DoVisualCircle(0.0f, 10.0f);
//
//                    events.RescheduleEvent(EVENT_STORM_OF_DESTROYER, stormTimer.popAndSafeLast());
//                    break;
//                case EVENT_SOUL_SIPHON:
//                {
//
//                        Unit* target = me->GetVictim();
//
//                        me->CastSpell(target, SPELL_SOUL_SIPHON);
//                        me->CastSpell(target, SPELL_SOUL_SIPHON_ABSORB);
//                    
//                    break;
//                }
//                case EVENT_WIND:
//                    DoCast(SPELL_WIND);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//
//        void DoVisualCircle(float min_radius, float max_radius)
//        {
//            if (isDead)
//                return;
//
//            float step = 2 * float(M_PI) / 7;
//            Position const& pos = { me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.0f };
//            float angle = pos.GetAngle(me->GetPositionX(), me->GetPositionY());
//
//            uint32 timer = max_radius == 60 ? 3900 : 1900;
//
//            for (uint8 j = min_radius; j <= max_radius; j += (max_radius - min_radius) / 2)
//                for (uint8 i = 0; i < 7; angle += step, ++i)
//                {
//                    for (uint8 x = urand(0, 1); x < 2; ++x)
//                    {
//                        Position point;
//                        point.m_positionX = me->GetPositionX() + j * cosf(angle) + frand(-4, 4);
//                        point.m_positionY = me->GetPositionY() + j * sinf(angle) + frand(-4, 4);
//                        point.m_positionZ = me->GetPositionZ();
//
//                        Creature* _me = me;
//                    }
//                }
//
//            uint32 visual_id = 0;
//            switch (uint32(max_radius))
//            {
//            case 10:
//                visual_id = STORM_OF_THE_DESTROYER_ORPHAN_1;
//                AddDelayedCombat(timer, [this]() -> void { DoVisualCircle(10.0f, 20.0f); });
//                break;
//            case 20:
//                visual_id = STORM_OF_THE_DESTROYER_ORPHAN_2;
//                AddDelayedCombat(timer, [this]() -> void { DoVisualCircle(20.0f, 30.0f); });
//                break;
//            case 30:
//                visual_id = STORM_OF_THE_DESTROYER_ORPHAN_3;
//                AddDelayedCombat(timer, [this]() -> void { DoVisualCircle(30.0f, 60.0f); });
//                break;
//            case 60:
//                visual_id = STORM_OF_THE_DESTROYER_ORPHAN_4;
//                break;
//            }
//
//            if (!visual_id)
//                return;
//
//        }
//
//        void DisableRotation(uint32 timer)
//        {
//           // me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN); // visual
//            me->AddUnitState(UNIT_STATE_CANNOT_TURN); // for correct work
//
//            AddDelayedEvent(timer, [this]() -> void
//            {
//               // me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN); // visual
//                me->ClearUnitState(UNIT_STATE_CANNOT_TURN); // for correct work
//            });
//        }
//
//        void CreateKhadgarAndFigure() // need more information
//        {
//            if (Creature* khadgar = me->SummonCreature(NPC_KHADGAR_PHASE_3, 266.71f, 3104.82f, 491.19f))
//            {
//                khadgar->CastSpell(khadgar, 227671);
//                khadgar->GetMotionMaster()->MoveFall();
//                AddDelayedEvent(2000, [this, khadgar]() -> void
//                {
//                    khadgar->RemoveAurasDueToSpell(227671);
//                    khadgar->AI()->Talk(3);
//
//                    if (Creature* figure = me->SummonCreature(NPC_KHADGAR_FIGURE, 268.48f, 3108.41f, 469.46f, 1.11f, TEMPSUMMON_TIMED_DESPAWN, 15000))
//                    {
//                        khadgar->CastSpell(figure, 227674);
//                        if (Creature* illidan = me->GetMap()->GetCreature(instance->GetGuidData(NPC_CRYSTALL_OF_ILLIDAN)))
//                        {
//                            if (Creature* figure_gold = me->SummonCreature(NPC_KHADGAR_FIGURE_1, 270.20f, 3112.18f, 470.22f, 1.11f, TEMPSUMMON_TIMED_DESPAWN, 15000))
//                            {
//                                figure->CastSpell(figure_gold, 231256);
//                                figure_gold->CastSpell(illidan, 231256);
//                            }
//
//                            if (Creature* figure_green = me->SummonCreature(NPC_KHADGAR_FIGURE_1, 267.37f, 3111.61f, 471.98f, 1.11f, TEMPSUMMON_TIMED_DESPAWN, 15000))
//                            {
//                                figure->CastSpell(figure_green, 231262);
//                                figure_green->CastSpell(illidan, 231262);
//                            }
//
//                            if (Creature* figure_black = me->SummonCreature(NPC_KHADGAR_FIGURE_1, 269.06f, 3109.35f, 473.38f, 1.11f, TEMPSUMMON_TIMED_DESPAWN, 15000))
//                            {
//                                figure->CastSpell(figure_black, 231263);
//                                figure_black->CastSpell(illidan, 231263);
//                            }
//
//                            if (Creature* figure_purple = me->SummonCreature(NPC_KHADGAR_FIGURE_1, 271.31f, 3110.29f, 471.98f, 1.11f, TEMPSUMMON_TIMED_DESPAWN, 15000))
//                            {
//                                figure->CastSpell(figure_purple, 231264);
//                                figure_purple->CastSpell(illidan, 231264);
//                            }
//                        }
//
//                    }
//                });
//            }
//        }
//
//        void EventPerephaseToSecond()
//        {
//            AddDelayedEvent(IsMythicRaid() ? 2000 : 13000, [this]()-> void
//            {
//
//                DoCast(SPELL_EYE_OF_AMANTHUL_PHASE_2);
//                me->RemoveAurasDueToSpell(SPELL_EYE_OF_AMANTHUL_PEREPHASE_TO_2);
//
//                AddDelayedEvent(6000, [this]() -> void
//                {
//                    can_regenerate_energy = true;
//
//                    Talk(SAY_PHASE_2_START);
//                    me->SetControlled(false, UNIT_STATE_ROOT);
//                });
//
//                DoCast(SPELL_FEL_SCYTHE);
//
//            });
//        }
//        
//        void RemoveEncounterAuras(uint32 spellId)
//        {
//            Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
//            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
//                if (Player* player = itr->GetSource())
//                {
//                    if (player->HasAura(spellId))
//                        player->RemoveAura(spellId);
//                }
//        }
//
//        void EventPerephaseToThird()
//        {
//            me->SetControlled(true, UNIT_STATE_ROOT);
//            AddDelayedEvent(9000, [this]() -> void
//            {
//                RemoveEncounterAuras(SPELL_RESONANT_BARRIER);
//                RemoveEncounterAuras(SPELL_TIME_DILATION);
//                RemoveEncounterAuras(SPELL_SCATTERING_FIELD);
//
//                DoCast(SPELL_EYE_OF_AMANTHUL_PHASE_3_1);
//                AddDelayedEvent(5000, [this]() -> void
//                {
//                    Talk(SAY_PHASE_3_START);
//                    if (!IsLFR()) 
//                        me->CastSpell(me, /*282.23f, 3135.16f, 465.93f,*/ SPELL_WELL_OF_SOULS);
//
//                    me->SetControlled(false, UNIT_STATE_ROOT);
//
//                    AddDelayedEvent(4000, [this]() -> void
//                    {
//                        CreateKhadgarAndFigure();
//                    });
//                });
//            });
//            DoCast(SPELL_FEL_SCYTHE);
//        }
//
//        void SetCorrectTimers()
//        {
//            if (IsLFR())
//            {
//                liquidHellfireTimer = liquidHellfireTimersLfr;
//                felEfluxTimer = felEfluxTimersNormalAndLfr;
//                boundsOfFelTimer = 52000;
//                eyeOfGuldanTimer = eyeOfGuldanTimersNormal;
//                blackHarvestTimer = blackHarvestTimersNormal;
//                stormTimer = stormTimersNormal;
//            }
//            else if (IsNormalRaid())
//            {
//                stormTimer = stormTimersNormal;
//                blackHarvestTimer = blackHarvestTimersNormal;
//                felEfluxTimer = felEfluxTimersNormalAndLfr;
//                liquidHellfireTimer = liquidHellfireTimersNormal;
//                eyeOfGuldanTimer = eyeOfGuldanTimersNormal;
//                boundsOfFelTimer = 49000;
//            }
//            else if (IsHeroicRaid())
//            {
//                liquidHellfireTimer = liquidHellfireTimersHeroic;
//                felEfluxTimer = felEfluxTimersHeroic;
//                boundsOfFelTimer = 43000;
//                eyeOfGuldanTimer = eyeOfGuldanTimersHeroic;
//                blackHarvestTimer = blackHarvestTimersHeroic;
//                stormTimer = stormTimersHeroic;
//            }
//            else // mythic
//            {
//                liquidHellfireTimer = liquidHellfireTimersMythic;
//                boundsOfFelTimer = 39000;
//                eyeOfGuldanTimer = eyeOfGuldanTimersMythic;
//                blackHarvestTimer = blackHarvestTimersMythic;
//                stormTimer = stormTimersMythic;
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_guldanAI(creature);
//    }
//};
//
//
//Position const titansPos[4]
//{
//    {277.12f, 3042.79f, 314.56f, 1.55f},
//    {197.06f, 3137.42f, 314.56f, 6.20f},
//    {281.40f, 3220.37f, 314.56f, 4.75f},
//    {378.72f, 3133.25f, 314.56f, 3.13f}
//};
//
//MySpecialList<Position> spherePos
//{
//    {250.15f, 3148.02f, 465.85f, 6.06f},
//    {300.53f, 3170.00f, 465.85f, 4.16f},
//    {315.43f, 3123.21f, 465.85f, 2.80f},
//    {264.84f, 3099.59f, 465.85f, 1.05f}
//
//};
//
//// 111022
//class npc_demon_within : public CreatureScript
//{
//public:
//    npc_demon_within() : CreatureScript("npc_demon_within") {}
//
//    struct npc_demon_withinAI : public BossAI
//    {
//        npc_demon_withinAI(Creature* creature) : BossAI(creature, MAX_ENCOUNTER + 1) // boundary not needed, then id > boss.size()
//        {}
//
//        bool isFlameOrSoulsever;
//        uint8 darkTitanCasts;
//
//        void IsSummonedBy(Unit*) override
//        {
//            Talk(0);
//            DoCast(SPELL_DEMON_INTRO);
//            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//        }
//
//        void Reset() override
//        {
//            events.Reset();
//            isFlameOrSoulsever = true;
//            darkTitanCasts = 0;
//        }
//
//        void JustDied(Unit* who) override
//        {
//            Talk(7);
//            DoCast(SPELL_DEAD_1);
//            if (me->GetOwner() && me->GetOwner()->IsCreature())
//              Unit::Kill(who, me->GetOwner());
//
//            if (instance)
//            {
//                RemoveEncounterAuras(SPELL_SHARED_SOUL);
//                RemoveEncounterAuras(SPELL_SHIELD_OF_AZZINOTH);
//                instance->SetBossState(DATA_GULDAN, DONE);
//                instance->SaveToDB();
//            }
//        }
//
//        void JustEngagedWith(Unit*) override
//        {
//        }
//        
//        void RemoveEncounterAuras(uint32 spellId)
//        {
//            Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
//            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
//                if (Player* player = itr->GetSource())
//                {
//                    if (player->HasAura(spellId))
//                        player->RemoveAura(spellId);
//                }
//        }
//
//        void EnterEvadeMode(EvadeReason w)
//        {
//            Talk(5);
//
//            if (me->GetOwner() && me->GetOwner()->IsCreature())
//                me->GetOwner()->ToCreature()->Respawn(true);
//
//            RemoveEncounterAuras(SPELL_SHIELD_OF_AZZINOTH);
//            instance->SetBossState(DATA_GULDAN, NOT_STARTED);
//
//            me->DespawnOrUnsummon();
//        }
//
//        void JustSummoned(Creature* summon) override
//        {
//            BossAI::JustSummoned(summon);
//
//            switch (summon->GetEntry())
//            {
//            case NPC_SHADOW_SOUL:
//                summon->SetControlled(true, UNIT_STATE_ROOT);
//                break;
//            case NPC_DEMONIC_ESSENCE:
//                summon->SetControlled(true, UNIT_STATE_ROOT);
//                summon->SetReactState(REACT_PASSIVE);
//                summon->SetRegenerateHealth(false);
//                summon->SetHealth(1);
//                summon->CastSpell(summon, 221431);
//                summon->CastSpell(summon, 221436);
//                //When 100% hp - cast 221486, + (not blizzlike! But i didn't find a original spell 94316)
//                break;
//            case NPC_NIGHT_SPHERE:
//                summon->SetControlled(true, UNIT_STATE_ROOT);
//                summon->SetReactState(REACT_PASSIVE);
//                summon->SetRegenerateHealth(false);
//                // no break
//            case NPC_PART_OF_AZZINOTH:
//
//            case NPC_SHADOW_DEMON:
//                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
//                instance->SendEncounterUnit(ENCOUNTER_FRAME_ADD_COMBAT_RES_LIMIT, summon);
//                break;
//            }
//        }
//
//        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//        {
//            switch (summon->GetEntry())
//            {
//            case NPC_PART_OF_AZZINOTH:
//                me->CastSpell(summon->GetPosition(), SPELL_DEMONIC_ESSENSE, true);
//                break;
//            case NPC_NIGHT_SPHERE:
//                me->CastSpell(summon->GetPosition(), SPELL_TIMESTOP_AREA_AT, true);
//                break;
//            }
//        }
//
//        void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
//        {
//            if (target && spellId == SPELL_PARASITIC_WOUND_DMG && mode == AURA_REMOVE_BY_EXPIRE)
//            {
//                me->CastSpell(target, SPELL_PARASITIC_EXPULSION);
//                Unit* _target = nullptr;
//                _target = SelectTarget(SELECT_TARGET_RANDOM, 0, [target](Unit const* t) { return target->GetDistance2d(t) > 5.0f && t->IsPlayer() && !t->HasAura(SPELL_SHADOWY_GAZE); }); // try to select random in range > 5
//
//                if (!_target)
//                    _target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, -SPELL_SHADOWY_GAZE, false);
//
//                if (_target)
//                    if (Creature* add = me->SummonCreature(NPC_SHADOW_DEMON, target->GetPosition(), TEMPSUMMON_DEAD_DESPAWN, 1000))
//                    {
//                        add->CastSpell(_target, SPELL_SHADOWY_GAZE);
//                        add->GetMotionMaster()->MoveFollow(_target, 0, 0);
//                    }
//            }
//        }
//
//        void SpellFinishCast(const SpellInfo* spell)
//        {
//            switch (spell->Id)
//            {
//            case SPELL_FIELD_OF_FLAME_DUMMY:
//                me->CastSpell(me->GetVictim(), SPELL_FIELD_OF_FLAME_TELE, true);
//                break;
//            case SPELL_DEMON_INTRO_END:
//                Talk(2);
//                me->SetPower(POWER_ENERGY, 0);
//                DoZoneInCombat(me);
//                events.RescheduleEvent(EVENT_PARASITIC, 8000);
//                events.RescheduleEvent(EVENT_AZZINOTHES, 26000);
//                events.RescheduleEvent(EVENT_NIGHTHOLD_SPHERE, nightOrbTimer.popAndSafeLast());
//                events.RescheduleEvent(EVENT_DARK_TITAN, darkTitanTimer.popAndSafeLast());
//                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                break;
//            }
//        }
//
//        void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode /*mode*/, bool apply)
//        {
//            if (apply)
//                return;
//
//            switch (spellId)
//            {
//            case SPELL_DARK_TITAN_AURA: // for remove by script and by duration too
//                me->SetCanFly(false);
//                me->CastStop();
//                me->RemoveAurasDueToSpell(SPELL_DARK_TITAN_EFFECT);
//                me->NearTeleportTo(me->GetHomePosition());
//                me->CastSpell(282.08f + frand(-20.0f, 20.0f), 3135.37f + frand(-20.0f, 20.0f), 465.93f, SPELL_AZZINOTHES, true);
//                events.CancelEvent(EVENT_AZZINOTHES);
//                break;
//            case SPELL_INTRO:
//                Talk(1);
//                break;
//            }
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_DEMONBANE && me->HasAura(SPELL_DARK_TITAN_AURA))
//            {
//                me->RemoveAurasDueToSpell(SPELL_DARK_TITAN_AURA);
//                DoCast(SPELL_STUN_WHEN_INTERRUPT);
//            }
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_SOULSEVER:
//                DoCast(target, SPELL_SHARED_SOUL);
//                for (float angle = -3.14f / 6.0f; angle < 3.14f / 6.0f; angle += 3.14f / 24.0f)
//                    me->CastSpell({ target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), me->GetOrientation() + angle }, SPELL_SOULSEVER_AT, false);
//                break;
//            case SPELL_SHARED_SOUL:
//                if (Creature* soul = me->SummonCreature(NPC_SHADOW_SOUL, { 282.08f + frand(-20.0f, 20.0f), 3135.37f + frand(-20.0f, 20.0f), 465.93f }, TEMPSUMMON_DEAD_DESPAWN, 1000))
//                {
//                    soul->SetReactState(REACT_PASSIVE);
//                    soul->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//                    soul->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                    soul->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                    soul->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//                   // soul->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
//                    target->CastSpell(soul, SPELL_SHARED_SOUL_CLONE, true);
//                    soul->CastSpell(soul, 229534);
//                }
//                break;
//            }
//
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
//                case EVENT_PARASITIC:
//                    Talk(3);
//                    DoCast(SPELL_PARASITIC_WOUND);
//                    events.RescheduleEvent(EVENT_PARASITIC, 36000);
//                    break;
//                case EVENT_FULL_ENERGY:
//                    if (isFlameOrSoulsever) // soulsever
//                        DoCastVictim(SPELL_SOULSEVER);
//                    else // flame
//                        if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT, 0, 0, true))
//                            DoCast(target, SPELL_FIELD_OF_FLAME);
//
//                    me->SetPower(POWER_ENERGY, 0);
//                    isFlameOrSoulsever = !isFlameOrSoulsever;
//                    break;
//                case EVENT_DARK_TITAN:
//                    me->SetCanFly(true);
//                    Talk(6);
//                    events.DelayEvents(1100);
//                    DoCast(SPELL_DARK_TITAN);
//                    instance->DoCastSpellOnPlayers(SPELL_DARK_TITAN_SCREEN);
//                    if (++darkTitanCasts < 4)
//                    {
//                        events.RescheduleEvent(EVENT_DARK_TITAN, darkTitanTimer.popAndSafeLast());
//                        events.RescheduleEvent(EVENT_NIGHTHOLD_SPHERE, nightOrbTimer.popAndSafeLast());
//                    }
//                    break;
//                case EVENT_AZZINOTHES:
//                    Talk(4);
//                    me->CastSpell(282.08f + frand(-20.0f, 20.0f), 3135.37f + frand(-20.0f, 20.0f), 465.93f, urand(1, 2) == 1 ? SPELL_AZZINOTHES : SPELL_AZZINOTHES_1);
//                    events.RescheduleEvent(EVENT_AZZINOTHES, 47000);
//                    break;
//                case EVENT_NIGHTHOLD_SPHERE:
//                    me->CastSpell(spherePos.popAndSafeLast(), SPELL_SUMMON_NIGHT_SPHERE, false);
//                    break;
//                }
//            }
//
//            DoMeleeAttackIfReady();
//        }
//
//        void DoMeleeAttackIfReady()
//        {
//            me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 10);
//            if (me->GetPower(POWER_ENERGY) >= 100)
//            {
//                events.DelayEvents(700); //for avoid some bugs
//                events.RescheduleEvent(EVENT_FULL_ENERGY, 1);
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_demon_withinAI(creature);
//    }
//};
//
//// 111047
//class npc_shadow_demon_guldan : public CreatureScript
//{
//public:
//    npc_shadow_demon_guldan() : CreatureScript("npc_shadow_demon_guldan") {}
//
//    enum SpellsAdd
//    {
//        SPELL_SPEED = 227292,
//        SPELL_ABSORB = 206779
//    };
//
//    struct npc_shadow_demon_guldanAI : public ScriptedAI
//    {
//        npc_shadow_demon_guldanAI(Creature* creature) : ScriptedAI(creature) {}
//
//        uint32 timer_for_check = 1000;
//
//        void IsSummonedBy(Unit* owner)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->SetWalk(false);
//            me->CastSpell(me, SPELL_SPEED);
//            me->CastSpell(me, SPELL_ABSORB);
//        }
//
//        void UpdateAI(uint32 diff)
//        {
//            if (timer_for_check <= diff)
//            {
//                if (Unit* target = me->GetVictim())
//                {
//                    me->GetMotionMaster()->MoveFollow(target, 0, 0);
//                    if (me->GetDistance2d(target) <= 2.0f)
//                        if (Unit* owner = me->GetOwner())
//                        {
//                            target->RemoveAurasDueToSpell(SPELL_SHADOWY_GAZE);
//                            owner->CastSpell(target, SPELL_PARASITIC_WOUND_DMG);
//                            // me->DespawnOrUnsummon();
//                        }
//                }
//                timer_for_check = 1000;
//            }
//            else
//                timer_for_check -= diff;
//
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_shadow_demon_guldanAI(creature);
//    }
//};
//
//// 107229
//class npc_guldan_shadow_soul : public CreatureScript
//{
//public:
//    npc_guldan_shadow_soul() : CreatureScript("npc_guldan_shadow_soul") {}
//
//    struct npc_guldan_shadow_soulAI : public Scripted_NoMovementAI
//    {
//        npc_guldan_shadow_soulAI(Creature* creature) : Scripted_NoMovementAI(creature)
//        {
//            SetCanSeeEvenInPassiveMode(true);
//            eventDone = false;
//        }
//
//        bool eventDone;
//
//        void MoveInLineOfSight(Unit* who) override
//        {
//            if (!who || !who->IsPlayer() || who->ToPlayer()->IsGameMaster())
//                return;
//
//            if (!eventDone && me->IsWithinDistInMap(who, 2.0f))
//            {
//                eventDone = true;
//                if (Unit* target = me->GetVictim())
//                {
//                    target->RemoveAurasDueToSpell(SPELL_SHARED_SOUL);
//                    target->CastSpell(target, SPELL_SHARED_SOUL_ABSORB);
//                }
//
//                if (Unit* owner = me->GetOwner())
//                    owner->CastSpell(me, SPELL_SHARED_SOUL_DMG);
//
//                me->DespawnOrUnsummon();
//            }
//        }
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_guldan_shadow_soulAI(creature);
//    }
//};
//
//// 104537, 104536, 104534
//class npc_guldan_adds : public CreatureScript
//{
//public:
//    npc_guldan_adds() : CreatureScript("npc_guldan_adds") {}
//
//    enum Spells_add
//    {
//        SPELL_INTRO_KURAZ = 212292,
//        SPELL_OUTRO_KURAZ = 209600,
//        SPELL_OUTRO_KURAZ_1 = 209601,
//        SPELL_KURAZ = 206675,
//        SPELL_KURAZ_1 = 212519,
//        SPELL_FEL_OBELISK = 229945,
//        SPELL_FEL_OBELISK_SUM = 229946,
//
//        SPELL_INTRO_VETRIZ = 212293,
//        SPELL_VETRIZ_DMG = 207006,
//        SPELL_VETRIZ_TELE = 207938,
//        SPELL_VETRIZ_EYES = 206840,
//        SPELL_VETRIZ_EYES_SUMMON = 207627,
//        SPELL_VETRIZ_EYES_AURA = 208533,
//        SPELL_VETRIZ_EYES_CAST = 217771,
//        SPELL_VETRIZ_OUTRO = 209637,
//        SPELL_DRAIN = 212568,
//
//        SPELL_INTRO_DZORIKS = 212275,
//        SPELL_DZORIKS = 206883, //to-do: Mythic: center room
//        SPELL_DZORIKS_1 = 208581,
//        SPELL_OUTRO_DZORIKS = 208831,
//        SPELL_SOULS = 216961,
//    };
//
//    struct npc_guldan_addsAI : public ScriptedAI
//    {
//        npc_guldan_addsAI(Creature* creature) : ScriptedAI(creature) {}
//
//        EventMap events;
//        bool can_regenerate_energy;
//        uint32 timer_for_energy;
//        uint16 vetrizCasts;
//
//        void IsSummonedBy(Unit*) override
//        {
//            switch (me->GetEntry())
//            {
//            case NPC_KURAZMAL:
//                DoCast(SPELL_INTRO_KURAZ);
//                break;
//            case NPC_VETRIZ:
//                DoCast(SPELL_INTRO_VETRIZ);
//                break;
//            case NPC_DZORIKS:
//                DoCast(SPELL_INTRO_DZORIKS);
//                break;
//            }
//        }
//
//        void JustSummoned(Creature* summon) override
//        {
//            if (summon->GetEntry() == 106986)
//            {
//                AddDelayedEvent(1000, [summon]() -> void
//                {
//                    summon->SetReactState(REACT_PASSIVE);
//                    summon->CastSpell(summon, SPELL_VETRIZ_EYES_CAST);
//                    summon->GetMotionMaster()->Clear();
//                    summon->GetMotionMaster()->MoveRotate(20000, ROTATE_DIRECTION_RIGHT);
//                });
//            }
//
//            if (me->GetOwner())
//                me->GetOwner()->ToCreature()->AI()->JustSummoned(summon);
//        }
//
//        void Reset() override
//        {
//            can_regenerate_energy = false;
//            timer_for_energy = 1000;
//            events.Reset();
//            vetrizCasts = 0;
//        }
//
//        void JustDied(Unit* who) override
//        {
//            switch (me->GetEntry())
//            {
//            case NPC_KURAZMAL:
//                DoCast(SPELL_OUTRO_KURAZ);
//                DoCast(SPELL_OUTRO_KURAZ_1);
//                break;
//            case NPC_VETRIZ:
//                DoCast(SPELL_VETRIZ_OUTRO);
//                break;
//            case NPC_DZORIKS:
//                DoCast(SPELL_OUTRO_DZORIKS);
//                break;
//            }
//            me->DespawnOrUnsummon(1000);
//        }
//
//        void JustEngagedWith(Unit*) override
//        {
//            switch (me->GetEntry())
//            {
//            case NPC_KURAZMAL:
//                DoCast(SPELL_KURAZ_1);
//                events.RescheduleEvent(EVENT_1, IsMythicRaid() ? 21000 : 19000);
//                if (IsHeroicRaid() || IsMythicRaid())
//                    events.RescheduleEvent(EVENT_5, IsMythicRaid() ? 16000 : 23000);
//                break;
//            case NPC_VETRIZ:
//                me->SetPower(POWER_ENERGY, 0);
//                can_regenerate_energy = true;
//                me->SetControlled(true, UNIT_STATE_ROOT);
//                events.RescheduleEvent(EVENT_2, 3000);
//                events.RescheduleEvent(EVENT_3, 30000);
//                break;
//            case NPC_DZORIKS:
//                events.RescheduleEvent(EVENT_4, IsMythicRaid() ? 3000 : 35000);
//                if (IsHeroicRaid() || IsMythicRaid())
//                    events.RescheduleEvent(EVENT_6, 19000);
//                break;
//            }
//        }
//
//        void SpellFinishCast(const SpellInfo* spell)
//        {
//            if (spell->Id == SPELL_VETRIZ_EYES)
//            {
//                DoCast(SPELL_VETRIZ_EYES_SUMMON);
//                DoCast(SPELL_VETRIZ_EYES_SUMMON);
//            }
//        }
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (can_regenerate_energy)
//            {
//                if (timer_for_energy <= diff) // we need it there, because energy regenerate while casting too
//                {
//                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(3, 5));
//
//                    timer_for_energy = 1000;
//                }
//                else
//                    timer_for_energy -= diff;
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    Talk(0);
//                    DoCast(SPELL_KURAZ_1);
//                    DoCastVictim(SPELL_KURAZ);
//                    events.RescheduleEvent(EVENT_1, IsMythicRaid() ? 21000 : 54000);
//                    break;
//                case EVENT_2:
//                    if (me->GetPower(POWER_ENERGY) >= 100)
//                        me->CastSpell(282.08f + frand(-20.0f, 20.0f), 3135.37f + frand(-20.0f, 20.0f), 465.93f, SPELL_VETRIZ_TELE);
//                    else
//                    {
//                        if (vetrizCasts <= 5)
//                            DoCast(SPELL_VETRIZ_DMG);
//                        else
//                            DoCast(SPELL_DRAIN);
//
//                        if (IsHeroicRaid() || IsMythicRaid())
//                            vetrizCasts++;
//                    }
//                    events.RescheduleEvent(EVENT_2, 3000);
//                    break;
//                case EVENT_3:
//                    DoCast(SPELL_VETRIZ_EYES_AURA);
//                    DoCast(SPELL_VETRIZ_EYES);
//                    events.RescheduleEvent(EVENT_3, 30000);
//                    break;
//                case EVENT_4:
//                    DoCast(SPELL_DZORIKS_1);
//                    if (IsMythicRaid())
//                        me->CastSpell(282.56f, 3134.10f, 465.99f, SPELL_DZORIKS);
//                    else
//                        DoCastVictim(SPELL_DZORIKS);
//                    events.RescheduleEvent(EVENT_4, 21000);
//                    break;
//                case EVENT_5:
//                {
//
//                        if (Unit* target = me->GetVictim())
//                        {
//                            me->CastSpell(target, SPELL_FEL_OBELISK_SUM);
//                            me->CastSpell(target, SPELL_FEL_OBELISK);
//                        }
//
//                    events.RescheduleEvent(EVENT_5, IsMythicRaid() ? 16000 : 23000);
//                    break;
//                }
//                case EVENT_6:
//                {
//
//                        if (Unit* target = me->GetVictim())
//                            me->CastSpell(target, SPELL_SOULS);
//
//                    events.RescheduleEvent(EVENT_6, 26000);
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_guldan_addsAI(creature);
//    }
//};
//
//// 105630  106545
//class npc_guldan_eye : public CreatureScript
//{
//public:
//    npc_guldan_eye() : CreatureScript("npc_guldan_eye") {}
//
//    struct npc_guldan_eyeAI : public ScriptedAI
//    {
//        npc_guldan_eyeAI(Creature* creature) : ScriptedAI(creature) {}
//
//        EventMap events;
//        uint32 timer_for_energy{};
//        ObjectGuid targetGUID{};
//
//        void Reset()
//        {
//            events.Reset();
//            events.RescheduleEvent(EVENT_1, 100);
//            timer_for_energy = 1000;
//            JustEngagedWith(nullptr);
//        }
//
//        void JustDied(Unit* who) override
//        {
//            me->RemoveAurasDueToSpell(me->GetEntry() == NPC_EYE_OF_GULDAN ? SPELL_EYE_OF_GULDAN_PERIODIC : 221728);
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            DoCast(me->GetEntry() == NPC_EYE_OF_GULDAN ? SPELL_EYE_OF_GULDAN_SPAWN : SPELL_EMPOWERED_EYE_OF_GULDAN_SPAWN);
//            DoCast(SPELL_EYE_OF_GULDAN_SPAWN_1);
//
//            // me->setPowerType(POWER_ENERGY);
//            me->SetPower(POWER_ENERGY, 0);
//            if (me->GetOwner() && me->GetOwner()->IsCreature())
//                if (Unit* target = me->GetOwner()->ToCreature()->AI()->SelectTarget(SELECT_TARGET_MAXDISTANCE, urand(0, 2), 0.0f, true))
//                    targetGUID = target->GetGUID();
//            events.RescheduleEvent(EVENT_1, 100);
//        }
//
//        void SpellFinishCast(const SpellInfo* spell)
//        {
//            if (spell->Id == SPELL_EYE_OF_GULDAN_COPY && me->GetOwner())
//            {
//                me->SetPower(me->GetPowerType(), 0);
//
//                if (Creature* new_eye = me->GetOwner()->SummonCreature(me->GetEntry(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
//                {
//                    new_eye->SetHealth(me->GetHealth());
//                    new_eye->CastSpell(282.08f + frand(-20.0f, 20.0f), 3135.37f + frand(-20.0f, 20.0f), 465.93f, SPELL_EYE_OF_GULDAN_COPY_JUMP);
//                }
//
//                me->CastSpell(282.08f + frand(-20.0f, 20.0f), 3135.37f + frand(-20.0f, 20.0f), 465.93f, SPELL_EYE_OF_GULDAN_COPY_JUMP);
//            }
//        }
//
//        void UpdateAI(uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            if (timer_for_energy <= diff)
//            {
//                if (me->GetPower(POWER_ENERGY) < 100)
//                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(2, 3));
//
//                timer_for_energy = 1000;
//            }
//            else
//                timer_for_energy -= diff;
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            events.Update(diff); // i need it after casting
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                {
//                    if (me->GetPower(POWER_ENERGY) >= 100)
//                        me->CastSpell(me, SPELL_EYE_OF_GULDAN_COPY);
//                    else if (me->GetOwner() && me->GetOwner()->ToCreature())
//                    {
//                        Unit* target = ObjectAccessor::GetUnit(*me, targetGUID);
//                        if (!target)
//                            target = me->GetOwner()->ToCreature()->AI()->SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, 0.0f, true);
//                        if (target)
//                        {
//                            targetGUID = target->GetGUID();
//                            me->CastSpell(target, me->GetEntry() == NPC_EYE_OF_GULDAN ? SPELL_EYE_OF_GULDAN_PERIODIC : SPELL_EMPOWERED_EYE_OF_GULDAN_PERIODIC);
//                        }
//                    }
//                    events.RescheduleEvent(EVENT_1, 100);
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_guldan_eyeAI(creature);
//    }
//};
//
//// 212258
//class spell_nh_hand_of_guldan : public SpellScriptLoader
//{
//public:
//    spell_nh_hand_of_guldan() : SpellScriptLoader("spell_nh_hand_of_guldan") { }
//
//    class spell_nh_hand_of_guldan_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_nh_hand_of_guldan_SpellScript);
//
//        void HandleScript(SpellEffIndex effIndex)
//        {
//            Unit* caster = GetCaster();
//            if (!caster || caster->GetEntry() != NPC_GULDAN)
//                return;
//
//            WorldLocation* dest = GetHitDest();
//            if (!dest)
//                return;
//
//            uint32 spell = handOfGuldanSpells[caster->ToCreature()->AI()->GetData(true)];
//        }
//
//        void Register() override
//        {
//            OnEffectHit += SpellEffectFn(spell_nh_hand_of_guldan_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_nh_hand_of_guldan_SpellScript();
//    }
//};
//
//// 206985
//class spell_scattering_field_absorb : public SpellScriptLoader
//{
//public:
//    spell_scattering_field_absorb() : SpellScriptLoader("spell_scattering_field_absorb") { }
//
//    class spell_scattering_field_absorb_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_scattering_field_absorb_AuraScript);
//
//        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
//        {
//            // Set absorbtion amount to unlimited
//            amount = -1;
//        }
//
//        void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
//        {
//            Unit* caster = GetCaster();
//            if (!caster)
//                return;
//
//            if (Aura* aura = caster->GetAura(217830))
//            {
//                float prcnt = aura->GetSpellInfo()->GetEffect(EFFECT_0)->MiscValue / 100.0f;
//                absorbAmount = dmgInfo.GetDamage() * prcnt;
//               // aura->set(absorbAmount);
//            }
//        }
//
//        void Register() override
//        {
//            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_scattering_field_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
//            OnEffectAbsorb += AuraEffectAbsorbFn(spell_scattering_field_absorb_AuraScript::Absorb, EFFECT_0);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_scattering_field_absorb_AuraScript();
//    }
//};
//
//// 206779
//class spell_shadow_shroud : public SpellScriptLoader
//{
//public:
//    spell_shadow_shroud() : SpellScriptLoader("spell_shadow_shroud") { }
//
//    class spell_shadow_shroud_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_shadow_shroud_AuraScript);
//
//        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
//        {
//            // Set absorbtion amount to unlimited
//            amount = -1;
//        }
//
//        void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
//        {
//            Unit* caster = GetCaster();
//            if (!caster)
//                return;
//
//            Unit* attacker = dmgInfo.GetAttacker();
//            if (!attacker || !attacker->GetTarget())
//                return;
//
//            if (caster->GetDistance(caster->GetVictim()) <= 15.0f)
//                absorbAmount = dmgInfo.GetDamage();
//            else
//                absorbAmount = dmgInfo.GetDamage() * caster->GetDistance2d(attacker) / 15.0f;
//        }
//
//        void Register() override
//        {
//            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_shadow_shroud_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
//            OnEffectAbsorb += AuraEffectAbsorbFn(spell_shadow_shroud_AuraScript::Absorb, EFFECT_0);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_shadow_shroud_AuraScript();
//    }
//};
//
//// 227096
//class spell_guldan_field_of_flame : public SpellScriptLoader
//{
//public:
//    spell_guldan_field_of_flame() : SpellScriptLoader("spell_guldan_field_of_flame") {}
//
//    class spell_guldan_field_of_flame_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_guldan_field_of_flame_SpellScript);
//
//        void HandleDamage(SpellEffIndex /*effIndex*/)
//        {
//            if (!GetCaster() || !GetHitUnit())
//                return;
//            auto pos = GetCaster()->GetPosition();
//
//            Unit* target = GetHitUnit();
//
//            for (uint8 i = 1; i <= 2; ++i)
//                if (target->GetDistance2d(pos.GetPositionX(), pos.GetPositionY()) <= 15 * i)
//                {
//                    SetHitDamage(GetHitDamage() * (3 - (i - 1)));
//                    return;
//                }
//
//            SetHitDamage(GetHitDamage());
//        }
//
//        void Register() override
//        {
//            OnEffectHitTarget += SpellEffectFn(spell_guldan_field_of_flame_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_guldan_field_of_flame_SpellScript();
//    }
//};
//
//// 206458
//class spell_shared_soul_absorb : public SpellScriptLoader
//{
//public:
//    spell_shared_soul_absorb() : SpellScriptLoader("spell_shared_soul_absorb") { }
//
//    class spell_shared_soul_absorb_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_shared_soul_absorb_AuraScript);
//
//        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
//        {
//            // Set absorbtion amount to unlimited
//            amount = -1;
//        }
//
//        void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
//        {
//            absorbAmount = dmgInfo.GetDamage();
//        }
//
//        void Register() override
//        {
//            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_shared_soul_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
//            OnEffectAbsorb += AuraEffectAbsorbFn(spell_shared_soul_absorb_AuraScript::Absorb, EFFECT_0);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_shared_soul_absorb_AuraScript();
//    }
//};
//
//// 227251
//class spell_guldan_unstable : public SpellScriptLoader
//{
//public:
//    spell_guldan_unstable() : SpellScriptLoader("spell_guldan_unstable") {}
//
//    class spell_guldan_unstable_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_guldan_unstable_SpellScript);
//
//        void HandleDamage(SpellEffIndex /*effIndex*/)
//        {
//            Unit* target = GetHitUnit();
//
//            if (target)
//                SetHitDamage(target->GetMaxHealth() / 100);
//        }
//
//        void Register() override
//        {
//            OnEffectHitTarget += SpellEffectFn(spell_guldan_unstable_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_guldan_unstable_SpellScript();
//    }
//};
//
//// 221292
//class spell_guldan_night_shield : public SpellScriptLoader
//{
//public:
//    spell_guldan_night_shield() : SpellScriptLoader("spell_guldan_night_shield") { }
//
//    class spell_guldan_night_shield_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_guldan_night_shield_AuraScript);
//
//        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
//        {
//            // Set absorbtion amount to unlimited
//            amount = -1;
//        }
//
//        void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
//        {
//            Unit* attacker = dmgInfo.GetAttacker();
//            if (!attacker)
//                return;
//
//            if (attacker->HasAura(SPELL_SHIELD_OF_AZZINOTH))
//                absorbAmount = 0;
//            else
//                absorbAmount = dmgInfo.GetDamage() / 2;
//        }
//
//        void Register() override
//        {
//            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_guldan_night_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
//            OnEffectAbsorb += AuraEffectAbsorbFn(spell_guldan_night_shield_AuraScript::Absorb, EFFECT_0);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_guldan_night_shield_AuraScript();
//    }
//};
//
////221603
//class spell_guldan_flames_of_sargeras : public AuraScript
//{
//    PrepareAuraScript(spell_guldan_flames_of_sargeras);
//
//    void OnTick(AuraEffect const* /*auraEffect*/)
//    {
//        if (InstanceScript* instance = GetOwner()->GetInstanceScript())
//        {
//            if (auto guldan = instance->instance->GetCreature(instance->GetGuidData(DATA_GULDAN)))
//            {
//                guldan->CastSpell(GetUnitOwner(), 206499, true);
//                guldan->CastSpell(GetUnitOwner(), 228190, true);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_guldan_flames_of_sargeras::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////210339, 210296, 217830
//class spell_guldan_players_buff_cooldown : public SpellScript
//{
//    PrepareSpellScript(spell_guldan_players_buff_cooldown);
//
//    void HandleOnCast()
//    {
//        if (auto player = GetCaster()->ToPlayer())
//        {
//            bool IsMythicRaid = player->GetMap()->IsMythic();
//            uint32 cooldown = 0;
//
//            switch (GetSpellInfo()->Id)
//            {
//            case 210296: //Tank: Resonant Barrier
//                if (IsMythicRaid)
//                    player->RemoveAurasDueToSpell(SPELL_RESONANT_BARRIER);
//                else
//                    cooldown = 180;
//                break;
//            case 210339: //DD: Time Dilation
//                if (IsMythicRaid)
//                    player->RemoveAurasDueToSpell(SPELL_TIME_DILATION);
//                else
//                {
//                    cooldown = 55;
//                }
//                break;
//            case 217830: //Heal: Scattering Field
//                if (IsMythicRaid)
//                    player->RemoveAurasDueToSpell(SPELL_SCATTERING_FIELD);
//                else
//                    cooldown = 30;
//                break;
//            }
//
//        }
//    }
//
//    void Register() override
//    {
//        OnCast += SpellCastFn(spell_guldan_players_buff_cooldown::HandleOnCast);
//    }
//};
//
//// custom entry 10914
//class areatrigger_guldan_bounds_of_fel : public AreaTriggerScript
//{
//public:
//    areatrigger_guldan_bounds_of_fel() : AreaTriggerScript("areatrigger_guldan_bounds_of_fel") { }
//
//    struct areatrigger_guldan_bounds_of_felAI : AreaTriggerAI
//    {
//        areatrigger_guldan_bounds_of_felAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}
//
//        ObjectGuid ownerGUID{};
//
//        void OnCreate() override
//        {
//            if (at->GetCaster() && at->GetCaster()->IsPlayer())
//                ownerGUID = at->GetCaster()->GetGUID();
//            else
//            {
//                at->Remove();
//                return;
//            }
//        }
//
//        void OnUnitExit(Unit* unit) override
//        {
//            if (unit->GetGUID() == ownerGUID)
//            {
//                InstanceScript* instance = at->GetInstanceScript();
//                if (!instance)
//                    return;
//
//                if (Creature* guldan = unit->GetMap()->GetCreature(instance->GetGuidData(DATA_GULDAN)))
//                    guldan->CastSpell(unit, at->GetSpellId() == SPELL_EMPOWERED_BOUNDS_OF_FEL_AT ? SPELL_EMPOWERED_BOUNDS_OF_FEL_DMG_AOE : SPELL_BOUNDS_OF_FEL_DMG_AOE, true);
//
//                unit->RemoveAurasDueToSpell(SPELL_BOUNDS_OF_FEL_TICK);
//                unit->RemoveAurasDueToSpell(SPELL_EMPOWERED_BOUNDS_OF_FEL_TICK);
//
//                at->SetDuration(0);
//            }
//        }
//
//    };
//
//    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const
//    {
//        return new areatrigger_guldan_bounds_of_felAI(areatrigger);
//    }
//};
//
//// custom entry 6197  13355
//class areatrigger_guldan_visual_charging : public AreaTriggerScript
//{
//public:
//    areatrigger_guldan_visual_charging() : AreaTriggerScript("areatrigger_guldan_visual_charging") { }
//
//    struct areatrigger_guldan_visual_chargingAI : AreaTriggerAI
//    {
//        areatrigger_guldan_visual_chargingAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}
//
//        bool CalculateSpline(Position const* pos, Position& startPos, Position& endPos, std::vector<Position>& path)
//        {
//            bool need_reverse = false;
//            uint32 path_id = 0;
//            switch (at->GetSpellId())
//            {
//            case 227751:
//                need_reverse = true;
//            case 227433: // first
//                if (urand(1, 2) == 1)
//                    path_id = 25759822;
//                else
//                    path_id = 25759823;
//                break;
//            case 227752:
//                need_reverse = true;
//            case 227694: // second
//                if (urand(1, 2) == 1)
//                    path_id = 25759824;
//                else
//                    path_id = 25759825;
//                break;
//            case 227753:
//                need_reverse = true;
//            case 227695: // third
//                if (urand(1, 2) == 1)
//                    path_id = 25759826;
//                else
//                    path_id = 25759827;
//                break;
//            case 227754:
//                need_reverse = true;
//            case 227696: // fourth
//                if (urand(1, 2) == 1)
//                    path_id = 25759828;
//                else
//                    path_id = 25759829;
//                break;
//            }
//            if (!path_id)
//                return false;
//
//            auto WP_path = sWaypointMgr->GetPath(path_id);
//            if (!WP_path)
//                return false;
//
//        /*    for (auto cur_point = WP_path->begin(); cur_point != WP_path->end(); ++cur_point)
//                path.push_back({ (*cur_point)->x, (*cur_point)->y, (*cur_point)->z, (*cur_point)->orientation });*/
//
//            if (need_reverse)
//                std::reverse(path.begin(), path.end());
//
//            auto last = path.back();
//            auto first = path.front();
//
//            startPos = { first.GetPositionX(), first.GetPositionY(), first.GetPositionZ(), first.GetOrientation() };
//            endPos = { last.GetPositionX(), last.GetPositionY(), last.GetPositionZ(), last.GetOrientation() };
//            return true;
//        }
//
//        void OnRemove() override
//        {
//            if (at->GetSpellId() != 227751 && at->GetSpellId() != 227752 && at->GetSpellId() != 227753 && at->GetSpellId() != 227754)
//                return;
//
//            /*if (at->GetCaster())
//            {
//                auto& pos = at->GetSpline();
//                if (pos.VerticesPoints.empty())
//                    return;
//
//                float x = pos.VerticesPoints.back().x;
//                float y = pos.VerticesPoints.back().y;
//                float z = pos.VerticesPoints.back().z;
//                at->GetCaster()->CastSpell(x, y, z, SPELL_EYE_OF_AMANTHUL_PHASE_3_AT_END);
//            }*/
//        }
//    };
//
//    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const
//    {
//        return new areatrigger_guldan_visual_chargingAI(areatrigger);
//    }
//};
//
//// 9660 custom entry
//class areatrigger_guldan_soul_corrosion : public AreaTriggerScript
//{
//public:
//    areatrigger_guldan_soul_corrosion() : AreaTriggerScript("areatrigger_guldan_soul_corrosion") { }
//
//    struct areatrigger_guldan_soul_corrosionAI : AreaTriggerAI
//    {
//        areatrigger_guldan_soul_corrosionAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
//        {
//        }
//
//        std::map<ObjectGuid, uint8> playersAndStacks{};
//
//        void ActionOnUpdate(GuidList& affectedPlayers)
//        {
//            Map* map = at->GetMap();
//            if (!map || at->GetSpellId() != 206939)
//                return;
//
//            InstanceScript* instance = at->GetInstanceScript();
//            if (!instance)
//                return;
//
//            Creature* guldan = map->GetCreature(instance->GetGuidData(DATA_GULDAN));
//            if (!guldan)
//                return;
//
//            std::set<ObjectGuid> tempGuids{};
//            for (GuidList::iterator itr = affectedPlayers.begin(), next; itr != affectedPlayers.end(); ++itr)
//            {
//                Unit* unit = ObjectAccessor::GetUnit(*at, *itr);
//                if (!unit || !unit->IsPlayer())
//                    continue;
//
//                if (playersAndStacks[unit->GetGUID()]++ == 3)
//                {
//                    if (Creature* soul = map->GetCreature(guldan->AI()->GetGUID()))
//                    {
//                        soul->CastSpell(unit, SPELL_SOUL_CORROSION_VISUAL);
//                        if (map->IsNormal())
//                            soul->CastSpell(unit, SPELL_SOUL_CORROSION, false);
//                        else
//                            soul->CastSpell(unit, SPELL_SOUL_CORROSION, false);
//                        soul->SetVisible(false);
//                        soul->DespawnOrUnsummon(4000);
//                    }
//                }
//                tempGuids.insert(unit->GetGUID());
//            }
//
//            for (auto& itr : playersAndStacks) // clear
//                if (tempGuids.find(itr.first) == tempGuids.end())
//                    itr.second = 0;
//        }
//
//    };
//
//    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const
//    {
//        return new areatrigger_guldan_soul_corrosionAI(areatrigger);
//    }
//};
//
//// 12346
//class areatrigger_guldan_demonic_essence : public AreaTriggerScript
//{
//public:
//    areatrigger_guldan_demonic_essence() : AreaTriggerScript("areatrigger_guldan_demonic_essence") { }
//
//    struct areatrigger_guldan_demonic_essenceAI : AreaTriggerAI
//    {
//        areatrigger_guldan_demonic_essenceAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}
//
//        void OnUnitExit(Unit* unit)
//        {
//            unit->RemoveAurasDueToSpell(221437);
//        }
//
//        void BeforeRemove(Unit* unit) 
//        {
//            unit->RemoveAurasDueToSpell(221437);
//        }
//
//        void ActionOnUpdate(GuidList& affectedPlayers)
//        {
//            Map* map = at->GetMap();
//            if (!map)
//                return;
//
//            InstanceScript* instance = at->GetInstanceScript();
//            if (!instance)
//                return;
//
//            Creature* guldan = map->GetCreature(instance->GetGuidData(DATA_GULDAN));
//            if (!guldan)
//                return;
//
//            for (GuidList::iterator itr = affectedPlayers.begin(), next; itr != affectedPlayers.end(); ++itr)
//            {
//                Unit* unit = ObjectAccessor::GetUnit(*at, *itr);
//                if (!unit || !unit->IsPlayer())
//                    continue;
//
//                if (auto caster = at->GetCaster())
//                    caster->CastSpell(unit, 221437, true);
//            }
//        }
//
//    };
//
//    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const
//    {
//        return new areatrigger_guldan_demonic_essenceAI(areatrigger);
//    }
//};
//
//// 32456
//class achievement_nighthold_guldan_kill : public AchievementCriteriaScript
//{
//public:
//    achievement_nighthold_guldan_kill() : AchievementCriteriaScript("achievement_nighthold_guldan_kill") { }
//
//    bool OnCheck(Player* source, Unit* /*target*/) override
//    {
//        if (!source || !source->GetInstanceScript())
//            return false;
//
//        if (source->GetInstanceScript()->instance->IsHeroic())
//            return true;
//
//        return false;
//    }
//};
//
//
//void AddSC_boss_guldan()
//{
//    new boss_guldan();
//    new npc_demon_within();
//    new npc_shadow_demon_guldan();
//    new npc_guldan_shadow_soul();
//    new npc_guldan_adds();
//    new npc_guldan_eye();
//
//    new spell_nh_hand_of_guldan();
//    new spell_scattering_field_absorb();
//    new spell_shadow_shroud();
//    new spell_guldan_field_of_flame();
//    new spell_shared_soul_absorb();
//    new spell_guldan_unstable();
//    new spell_guldan_night_shield();
//    RegisterAuraScript(spell_guldan_flames_of_sargeras);
//    RegisterSpellScript(spell_guldan_players_buff_cooldown);
//
//    new areatrigger_guldan_bounds_of_fel();
//    new areatrigger_guldan_visual_charging();
//    new areatrigger_guldan_soul_corrosion();
//    new areatrigger_guldan_demonic_essence();
//
//    new achievement_nighthold_guldan_kill();
//}

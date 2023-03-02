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
//#include "trial_of_valor.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_INTRO_1 = 11,
//    SAY_INTRO_2,
//    SAY_INTRO_3,
//    SAY_AGGRO,
//    SAY_BILEWATER_BREATH,
//    SAY_PHASE_2 = 6,
//    SAY_PHASE_3,
//    SAY_ORB_OF_CORROSION,
//    SAY_CORRUPTED_BREATH,
//    SAY_DEATH
//};
//
//enum Spells
//{
//    SpellHelyaBluePower = 232229,
//    SpellHelyaPurplePower = 232230,
//    SpellBerserk = 64238,
//    SpellBilewaterBreath = 227967,
//    SpellBilewaterBreathDmg = 230229,
//    SpellBilewaterBreathNpc = 230216,
//    SpellBilewaterLiquefactionDmg = 227992,
//    SpellBilewaterLiquefactionKill = 227993,
//    SpellBilewaterRedox = 227982,
//    SpellRemoveDebuffs = 34098,
//    SpellHelyaImmunityDamage = 228847,
//    SpellHelyaAltPower = 228372,
//    SpellHelyaReuse = 200239,
//    SpellCorruptedBreath = 228565,
//    SpellCorruptedBreathDmg = 228566,
//    SpellReanimation1 = 228104,
//    SpellReanimation2 = 234199,
//    SpellHelyaVisualTentacles = 228772,
//    SpellHelyaVisualTentacles1 = 228778,
//    SpellRideVehicleHardcoded = 46598,
//    SpellFuryoftheMaw = 228032,
//    SpellFuryOfTheMawAT = 230356,
//    SpellFureOfTheMawLong = 228300,
//    SpellRagingTempest = 201119,
//    SpellHelyaAltPowerRegen = 228546,
//    SpellTaintOfTheSea = 228054,
//    SpellTaintOfTheSeaDmg = 228053,
//    SpellOrbOfCorruption = 227903,
//    SpellOrbOfCorruptionSpawnAura = 227906,
//    SpellOrbOfCorruptionVisual = 227939,
//    SpellOrbOfCorruptionDmg = 227930,
//    SpellOrbOfCorruptionAuraProc = 227926,
//    SpellOrbofCorruptionOnPlayer = 229119,
//    SpellOrbOfCorrosion = 228056,
//    SpellOrbOfCorrosionSpawnAura = 228057,
//    SpellOrbOfCorrosionVisual = 228060,
//    SpellOrbOfCorrosionAuraProc = 228061,
//    SpellOrbofCorrosionOnPlayer = 230267,
//    SpellOrbOfCorrosionShare = 228062,
//    SpellOrbOfCorrosionDmg = 228063,
//    SpellBilewaterLiquefaction = 227990,
//    SpellBilewaterLiquefactionScale = 228984,
//    SpellSlimey = 154241,
//    SpellCorrosiveNova = 228872,
//    SpellTorrent = 228514,
//    SpellBuildingStorm = 228803,
//    SpellAnchorSlam = 228519,
//    SpellSludgeNova = 228390,
//    SpellFetidRotHit = 228397,
//    SpellFetidRot = 193367,
//    SpellTaintedEssence = 228052,
//    SpellGiveNoQuarter = 228632,
//    SpellLanternOfDarkness = 228619,
//    SpellDarkness = 228383,
//    SpellGhostlyRage = 228611,
//    SpellRallyOfTheKvaldir = 232346,
//    SpellDecay = 228121,
//    SpellVigor = 203816,
//    SpellRabid = 202476,
//    SpellTentacleSlam = 228731,
//    SpellDarkHatred = 232488,
//    SpellCorruptedAxion = 232418,
//    SpellCorruptedAxionAOE = 232452,
//    SpellCorruptedAxionAura = 232450,
//    SpellCorrupted = 232350,
//    SpellBleakEruption = 231862,
//    SpellMistInfusion = 228854,
//    SpellTentacleStrike = 228730
//};
//
//enum Events
//{
//    EVENT_TAINT_OF_THE_SEA = 1,
//    EVENT_TENTECLE_STRIKE = 2,
//    EVENT_ORB_OF_CURRUPTION = 3,
//    EVENT_TORRENT = 4,
//    EVENT_TELEPORT_OUTSIDE = 5,
//    EVENT_TELEPORT_HOME = 6,
//    EVENT_ORB_OF_CORROSION = 7,
//    EVENT_FURY_OF_THE_MAW = 8,
//    EVENT_FURY_OF_THE_MAW_CLEAN_AT = 9,
//    EVENT_REANIMATION = 10,
//    EVENT_SUMMON_SKELETION = 11,
//    EVENT_BOAT = 12
//};
//
//enum Phase
//{
//    PHASE_1 = 1,
//    PHASE_2,
//    PHASE_3
//};
//
//Position const Pos_AncientBonethrall[3] =
//{
//    { 542.715f, 614.908f, 6.76841f, 2.33339f },
//    { 539.062f, 640.273f, 3.53224f, 2.64075f },
//    { 537.57f, 629.615f, 6.64555f, 3.21549f }
//};
//
//Position const Pos_DarkSeraph[4] =
//{
//    { 454.929f, 595.392f, 4.5516f, 4.69926f },
//    { 433.75f, 673.292f, 11.1958f, 5.168f },
//    { 453.01f, 676.46f, 16.4407f, 4.31975f },
//    { 564.712f, 671.016f, 22.047f, 4.89319f }
//};
//
//Position const Pos_KvaldirTideWitch[5] =
//{
//    { 438.646f, 669.132f, 7.11206f, 4.94863f },
//    { 446.311f, 669.043f, 7.02397f, 4.97584f },
//    { 466.095f, 698.087f, 18.0504f, 4.31252f },
//    { 564.804f, 664.471f, 18.0398f, 3.0071f },
//    { 462.96f, 707.84f, 18.048f, 2.79169f }
//};
//
//Position const Pos_KvaldirReefcaller[8] =
//{
//    { 554.536f, 659.163f, 18.04f, 3.40563f },
//    { 497.158f, 649.146f, 1.93921f, 1.00977f },
//    { 502.023f, 640.695f, 1.92648f, 1.16326f },
//    { 490.314f, 647.658f, 1.95429f, 0.897942f },
//    { 500.812f, 646.582f, 1.92656f, 1.08693f },
//    { 484.189f, 647.012f, 2.10088f, 0.805534f },
//    { 575.047f, 653.731f, 18.0399f, 3.20372f },
//    { 503.719f, 634.96f, 1.9753f, 1.21486f }
//};
//
//Position const Pos_DeepbrineMonstrosity[4] =
//{
//    { 465.504f, 641.476f, 5.21661f, 0.582881f },
//    { 523.799f, 662.377f, 2.27014f, 3.65067f },
//    { 500.641f, 674.398f, 2.22507f, 4.62842f },
//    { 471.521f, 708.076f, 18.0694f, 0.768197f }
//};
//
//Position const StrikingTentacle[3] =
//{
//    //{ 466.0955f, 698.0868f, 18.05038f, 4.312522f },
//    //{ 564.8038f, 664.4705f, 18.03976f, 3.007097f },
//    { 525.5886f, 678.2604f, 2.877361f, 4.050999f },
//    { 505.826f, 693.526f, 2.877363f, 4.66783f },
//    { 475.3333f, 606.6406f, 2.891779f, 0.9923878f }
//};
//
//Position const skeletionPos[10] =
//{
//    { 529.276f, 702.028f, -2.0632f, 4.31416f },
//    { 539.448f, 699.825f, -2.43245f, 4.31416f },
//    { 522.04f, 709.505f, -2.51397f, 4.31416f },
//    { 503.182f, 583.628f, -0.529175f, 1.36772f },
//    { 491.255f, 586.115f, -0.529175f, 1.4199f },
//    { 515.188f, 580.21f, -0.529175f, 1.33011f },
//    { 482.042f, 590.741f, -0.529178f, 1.5545f },
//    { 528.059f, 583.365f, -0.529168f, 1.75563f },
//    { 517.481f, 719.132f, -3.38609f, 4.31416f },
//    { 549.359f, 698.911f, -3.12035f, 4.31416f }
//};
//
//enum Miscs
//{
//    ACTION_1 = 1,
//    ACTION_2,
//
//    EVENT_1,
//    EVENT_2,
//    EVENT_3,
//    EVENT_4,
//    EVENT_5,
//};
//
//struct boss_helya_tov : BossAI
//{
//    explicit boss_helya_tov(Creature* creature) : BossAI(creature, Data::BossIDs::HelyaID)
//    {
//        HelyaIntro = false;
//        Intro();
//    }
//
//    uint32 berserk;
//    uint8 trashDiedCount;
//    uint8 trashPhase2Count;
//    uint8 eventPhase;
//    uint32 power;
//    uint32 count;
//    uint32 AOEdmg;
//    uint32 _checkEvadeTimer;
//    bool phase2;
//    bool phase3;
//    bool HelyaIntro;
//    bool checkrephase;
//    bool FuryOfTheMaw;
//    bool FuryOfTheMawTrash;
//    ObjectGuid playerGuid;
//
//    void Reset() override
//    {
//        _Reset();
//        me->SetPower(POWER_ENERGY, 0);
//        me->SetMaxPower(POWER_ENERGY, 100);
//        me->RemoveAllAuras();
//        me->AddUnitState(UNIT_STATE_ROOT);
//        me->SetReactState(REACT_AGGRESSIVE);
//        me->RemoveAllAreaObjects();
//        DoCast(SpellHelyaBluePower);
//        RemoveAllDebaffsOnPlayer();
//        playerGuid.Clear();
//        DespawnAllSummons();
//
//        berserk = 0;
//        eventPhase = 0;
//        trashDiedCount = 0;
//        trashPhase2Count = 0;
//        count = 0;
//        AOEdmg = 0;
//        _checkEvadeTimer = 0;
//        phase2 = false;
//        phase3 = false;
//        checkrephase = false;
//        FuryOfTheMawTrash = false;
//        FuryOfTheMaw = false;
//
//        events.RescheduleEvent(EVENT_REANIMATION, 1000);
//    }
//
//    void RemoveAllDebaffsOnPlayer()
//    {
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellCorruptedAxionAura);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellCorrupted);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellBleakEruption);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellBleakEruption);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellTaintOfTheSea);
//        instance->DoRemoveAurasDueToSpellOnPlayers(SpellOrbofCorrosionOnPlayer);
//    }
//
//    void DespawnAllSummons()
//    {
//        std::list<Creature*> list;
//        list.clear();
//        me->GetCreatureListWithEntryInGrid(list, 114523, 200.0f);
//        me->GetCreatureListWithEntryInGrid(list, 114566, 200.0f);
//        if (!list.empty())
//            for (auto& sum : list)
//                sum->DespawnOrUnsummon();
//    }
//
//    void Intro()
//    {
//        me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//
//        if (instance->GetBossState(Data::BossIDs::HelyaID) != DONE)
//        {
//            for (uint8 i = 0; i < 3; ++i)
//                me->SummonCreature(Data::Creatures::AncientBonethrall, Pos_AncientBonethrall[i]);
//            for (uint8 i = 0; i < 4; ++i)
//                me->SummonCreature(Data::Creatures::DarkSeraph, Pos_DarkSeraph[i]);
//            for (uint8 i = 0; i < 5; ++i)
//                me->SummonCreature(Data::Creatures::KvaldirTideWitch, Pos_KvaldirTideWitch[i]);
//            for (uint8 i = 0; i < 8; ++i)
//                me->SummonCreature(Data::Creatures::KvaldirReefcaller, Pos_KvaldirReefcaller[i]);
//            for (uint8 i = 0; i < 4; ++i)
//                me->SummonCreature(Data::Creatures::DeepbrineMonstrosity, Pos_DeepbrineMonstrosity[i]);
//
//            me->SummonCreature(Data::Creatures::RotsoulGiant, 567.617f, 656.039f, 18.2112f, 0.967337f);
//            me->SummonCreature(Data::Creatures::KvaldirCoralMaiden, 561.031f, 665.738f, 18.0399f, 5.4091f);
//        }
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        _JustEngagedWith();
//        StartEvents(PHASE_1);
//        _checkEvadeTimer = 1500;
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, 2008);
//        me->RemoveAllAreaObjects();
//        RemoveAllDebaffsOnPlayer();
//        DespawnAllSummons();
//        _JustDied();
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        Talk(SAY_INTRO_1);
//        me->NearTeleportTo(524.031f, 699.055f, 5.17631f, 4.29875f);
//    }
//
//    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//    {
//        switch (summon->GetEntry())
//        {
//        case Data::Creatures::DeepbrineMonstrosity:
//        case Data::Creatures::KvaldirReefcaller:
//        case Data::Creatures::KvaldirTideWitch:
//        case Data::Creatures::DarkSeraph:
//        case Data::Creatures::RotsoulGiant:
//        case Data::Creatures::AncientBonethrall:
//        case Data::Creatures::KvaldirCoralMaiden:
//            trashDiedCount++;
//
//            if (!HelyaIntro)
//            {
//                HelyaIntro = true;
//                DoAction(ACTION_2);
//            }
//            break;
//        case Data::Creatures::GrippingTentacle:
//            trashPhase2Count++;
//            break;
//        }
//
//        if (trashDiedCount == 26 && eventPhase == 0)
//        {
//            Talk(SAY_INTRO_3);
//            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//        }
//
//        if (trashPhase2Count == 9 && eventPhase == PHASE_2)
//            StartEvents(PHASE_3);
//    }
//
//    void SetPower(Powers power, int32 value)
//    {
//        if (power == POWER_ENERGY)
//        {
//            if (value == 100 && eventPhase == PHASE_1)
//            {
//                if (!me->HasUnitState(UNIT_STATE_CASTING))
//                {
//                    DoCast(SpellBilewaterBreath);
//                    Talk(SAY_BILEWATER_BREATH);
//                    me->SetPower(POWER_ENERGY, 0);
//                }
//            }
//
//            if (value == 100 && eventPhase == PHASE_3)
//            {
//                if (!me->HasUnitState(UNIT_STATE_CASTING))
//                {
//                    DoCast(SpellCorruptedBreath);
//                    Talk(SAY_CORRUPTED_BREATH);
//                    me->SetPower(POWER_ENERGY, 0);
//                }
//            }
//        }
//
//        if (power == POWER_ALTERNATE_POWER)
//        {
//            if (value == 100)
//            {
//                if (!me->HasUnitState(UNIT_STATE_CASTING))
//                {
//                    if (IsHeroicPlusRaid() && eventPhase == PHASE_2 && !FuryOfTheMaw)
//                    {
//                        FuryOfTheMaw = true;
//                        FuryOfTheMawTrash = false;
//                        DoCast(SpellFureOfTheMawLong);
//                        FuryOfTheMaw = false;
//                        me->SetPower(POWER_ALTERNATE_POWER, 0);
//                    }
//                    else if (IsLFR() || IsNormalRaid())
//                    {
//                        if (eventPhase == PHASE_2)
//                        {
//                            DoCast(SpellFuryoftheMaw);
//                            events.RescheduleEvent(EVENT_FURY_OF_THE_MAW_CLEAN_AT, 4000);
//                            me->SetPower(POWER_ALTERNATE_POWER, 0);
//                        }
//                    }
//
//                    if (eventPhase == PHASE_3)
//                    {
//                        FuryOfTheMawTrash = false;
//                        DoCast(SpellFuryoftheMaw);
//                        events.RescheduleEvent(EVENT_FURY_OF_THE_MAW_CLEAN_AT, 4000);
//                        me->SetPower(POWER_ALTERNATE_POWER, 0);
//                    }
//                }
//            }
//        }
//    }
//
//    void StartEvents(uint8 phase)
//    {
//        events.Reset();
//        eventPhase = phase;
//
//        switch (phase)
//        {
//        case PHASE_1:
//            Talk(SAY_AGGRO);
//            AOEdmg = 1000;
//            me->SetPower(POWER_ENERGY, 79);
//
//            if (IsMythicRaid())
//            {
//                events.RescheduleEvent(EVENT_TAINT_OF_THE_SEA, 15000);
//                events.RescheduleEvent(EVENT_TENTECLE_STRIKE, 35000);
//                events.RescheduleEvent(EVENT_ORB_OF_CURRUPTION, 14000);
//            }
//            else if (IsHeroicRaid())
//            {
//                events.RescheduleEvent(EVENT_TAINT_OF_THE_SEA, 19000);
//                events.RescheduleEvent(EVENT_TENTECLE_STRIKE, 36000);
//                events.RescheduleEvent(EVENT_ORB_OF_CURRUPTION, 29000);
//            }
//            else if (IsNormalRaid() || IsLFR())
//            {
//                events.RescheduleEvent(EVENT_TAINT_OF_THE_SEA, 12000);
//                events.RescheduleEvent(EVENT_TENTECLE_STRIKE, 53000);
//                events.RescheduleEvent(EVENT_ORB_OF_CURRUPTION, 18000);
//            }
//
//            if (IsHeroicPlusRaid())
//                berserk = 660000; // 11 min
//            break;
//        case PHASE_2:
//            events.RescheduleEvent(EVENT_TELEPORT_OUTSIDE, 1000);
//            checkrephase = true;
//            DoCast(SpellRemoveDebuffs);
//            DoCast(SpellHelyaImmunityDamage);
//            DoCast(SpellHelyaAltPower);
//            DoCast(SpellHelyaReuse);
//
//            me->CastStop();
//            me->AttackStop();
//            me->SetReactState(REACT_PASSIVE);
//            me->SetPower(POWER_ENERGY, 0);
//            me->RemoveAura(SpellHelyaBluePower);
//            me->RemoveAura(SpellCorrosiveNova);
//            me->SummonCreatureGroup(3);
//
//            DoCast(SpellHelyaReuse);
//            Talk(SAY_PHASE_2);
//            events.RescheduleEvent(EVENT_TORRENT, 9000);
//            events.RescheduleEvent(EVENT_REANIMATION, 30000);
//            if (IsLFR() || IsNormalRaid())
//            {
//                DoCast(SpellHelyaAltPowerRegen);
//                events.RescheduleEvent(EVENT_FURY_OF_THE_MAW, 2000);
//            }
//            else if (IsHeroicPlusRaid())
//                me->SetPower(POWER_ALTERNATE_POWER, 100);
//            break;
//        case PHASE_3:
//            events.RescheduleEvent(EVENT_TELEPORT_HOME, 2000);
//            DoCast(SpellHelyaReuse);
//            me->CastStop();
//            me->RemoveAura(SpellFureOfTheMawLong);
//            me->RemoveAura(SpellHelyaImmunityDamage);
//            me->RemoveAura(SpellHelyaAltPowerRegen);
//            me->RemoveAura(SpellTorrent);
//            Talk(SAY_PHASE_3);
//            me->SetPower(POWER_ENERGY, 61);
//            me->SetPower(POWER_ALTERNATE_POWER, 42);
//            me->SetReactState(REACT_AGGRESSIVE);
//            me->RemoveAura(SpellBuildingStorm);
//            me->RemoveAura(SpellCorrosiveNova);
//            DoCast(SpellHelyaAltPowerRegen);
//            checkrephase = false;
//            DoCast(SpellHelyaReuse);
//            DoCast(SpellHelyaPurplePower);
//            events.RescheduleEvent(EVENT_REANIMATION, 52000);
//            if (IsMythicRaid())
//                events.RescheduleEvent(EVENT_ORB_OF_CORROSION, 6000);
//            else if (IsHeroicRaid())
//                events.RescheduleEvent(EVENT_ORB_OF_CORROSION, 14000);
//            else if (IsNormalRaid() || IsLFR())
//                events.RescheduleEvent(EVENT_ORB_OF_CORROSION, 18000);
//            break;
//        }
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        if (!phase2 && me->HealthBelowPct(65))
//        {
//            phase2 = true;
//            StartEvents(PHASE_2);
//        }
//    }
//
//    void SpellHit(Unit* owner, SpellInfo const* spell)
//    {
//        switch (spell->Id)
//        {
//        case SpellBilewaterLiquefactionKill:
//            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(227992, DIFFICULTY_NONE))
//            {
//                float damage = spellInfo->GetEffect(EFFECT_0)->CalcValue();
//                float healthPct = owner->GetHealthPct() > 5.0f ? owner->GetHealthPct() : 5.0f;
//                damage = CalculatePct(damage, healthPct);
//                me->CastCustomSpell(owner, SpellBilewaterLiquefactionDmg, &damage, &healthPct, nullptr, true);
//            }
//            break;
//        case SpellOrbOfCorruption:
//        {
//            if (me->GetMap() && (me->GetMap()->GetDifficultyID() == DIFFICULTY_NORMAL_RAID) || (me->GetMap()->GetDifficultyID() == DIFFICULTY_LFR))
//                count = 2;
//            else if (me->GetMap() && (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID) || (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID))
//                count = 3;
//
//            std::list<Player*> playerList;
//            GetPlayerListInGrid(playerList, me, 300.0f);
//            Trinity::Containers::RandomResize(playerList, count);
//
//            if (playerList.empty())
//                return;
//
//            for (auto& player : playerList)
//            {
//                DoCast(player, SpellOrbOfCorruptionVisual, true);
//
//                playerGuid.Clear();
//                playerGuid = player->GetGUID();
//                Position pos;
//                player->GetPosition();
//                pos.m_positionX -= 6.0f;
//                pos.m_positionY -= 6.0f;
//                me->SummonCreature(Data::Creatures::OrbOfCorruption, pos, TEMPSUMMON_TIMED_DESPAWN, 9000);
//            }
//            break;
//        }
//        case SpellOrbOfCorrosion:
//        {
//            if (me->GetMap() && (me->GetMap()->GetDifficultyID() == DIFFICULTY_NORMAL_RAID) || (me->GetMap()->GetDifficultyID() == DIFFICULTY_LFR))
//                count = 2;
//            else if (me->GetMap() && (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID) || (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID))
//                count = 3;
//
//            std::list<Player*> playerList;
//            GetPlayerListInGrid(playerList, me, 300.0f);
//            Trinity::Containers::RandomResize(playerList, count);
//
//            if (playerList.empty())
//                return;
//
//            for (auto& player : playerList)
//            {
//                playerGuid.Clear();
//                playerGuid = player->GetGUID();
//
//                DoCast(player, SpellOrbOfCorrosionVisual, true);
//
//                Position pos;
//                player->GetPosition();
//                pos.m_positionX -= 6.0f;
//                pos.m_positionY -= 6.0f;
//                me->SummonCreature(Data::Creatures::OrbOfCorrosion, pos, TEMPSUMMON_TIMED_DESPAWN, 9000);
//            }
//            break;
//        }
//        case SpellBilewaterBreath:
//        {
//            uint8 count = me->GetMap()->GetPlayersCountExceptGMs();
//
//            if (count <= 10)
//                count = 2;
//            else if (count <= 15)
//                count = 3;
//            else if (count <= 20)
//                count = 4;
//            else if (count <= 25)
//                count = 5;
//            else
//                count = 6;
//
//            Position pos;
//            float angle = 0.0f;
//            float dist = 40.0f;
//            for (uint8 i = 0; i < count; ++i)
//            {
//                dist += 11.0f;
//                me->GetFirstCollisionPosition(dist, angle);
//                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SpellBilewaterBreathNpc, true);
//            }
//            break;
//        }
//        case SpellCorruptedBreath:
//        {
//            if (!IsHeroicPlusRaid())
//                return;
//
//            uint32 countTarget = 0;
//
//            if (IsMythicRaid())
//                countTarget = 5;
//            else
//                countTarget = 3;
//
//            Position pos;
//            float angle = me->GetAngle(me);
//            float dist = 30.0f;
//            for (uint8 i = 0; i < countTarget; ++i)
//            {
//                dist += 13.0f;
//                me->GetNearPosition(dist, angle);
//                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SpellCorruptedAxion, true);
//            }
//            break;
//        }
//        case SpellOrbOfCorrosionShare:
//            DoCast(owner, SpellOrbOfCorrosionDmg, true);
//            break;
//        }
//    }
//
//    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//    {
//        switch (spell->Id)
//        {
//        case SpellBilewaterBreathDmg:
//            DoCast(target, SpellBilewaterRedox, true);
//            break;
//        case SpellCorruptedBreathDmg:
//            DoCast(target, SpellDarkHatred, false);
//            break;
//        }
//    }
//
//    void SpellFinishCast(SpellInfo const* spell)
//    {
//        switch (spell->Id)
//        {
//        case SpellFuryOfTheMawAT:
//            if (IsHeroicPlusRaid())
//            {
//                if (!FuryOfTheMawTrash)
//                {
//                    events.RescheduleEvent(EVENT_BOAT, 500);
//                    events.RescheduleEvent(EVENT_SUMMON_SKELETION, 31000);
//                    events.RescheduleEvent(EVENT_SUMMON_SKELETION, 41000);
//                    FuryOfTheMawTrash = true;
//                }
//                events.RescheduleEvent(EVENT_FURY_OF_THE_MAW_CLEAN_AT, 3000);
//            }
//            else if (IsLFR() || IsNormalRaid())
//            {
//                if (eventPhase == PHASE_3 || eventPhase == PHASE_2)
//                {
//                    events.RescheduleEvent(EVENT_BOAT, 500);
//                    events.RescheduleEvent(EVENT_SUMMON_SKELETION, 31000);
//                    events.RescheduleEvent(EVENT_SUMMON_SKELETION, 41000);
//                }
//            }
//            break;
//        }
//    }
//
//    void DoAction(int32 const action) override
//    {
//        switch (action)
//        {
//        case ACTION_1:
//            DoCast(SpellHelyaAltPowerRegen);
//            events.RescheduleEvent(EVENT_TORRENT, 2000);
//            break;
//        case ACTION_2:
//            if (instance->GetBossState(Data::BossIDs::GarmID) == DONE)
//            {
//                Talk(SAY_INTRO_1);
//                Talk(SAY_INTRO_2);
//            }
//            break;
//        default:
//            break;
//        }
//    }
//
//    void JustSummoned(Creature* sum) override
//    {
//        summons.Summon(sum);
//
//        switch (sum->GetEntry())
//        {
//        case Data::Creatures::OrbOfCorruption:
//            if (auto target = ObjectAccessor::GetUnit(*sum, sum->GetTarget()))
//                sum->CastSpell(target, SpellOrbofCorruptionOnPlayer, true);
//            break;
//        case Data::Creatures::OrbOfCorrosion:
//            if (auto target = ObjectAccessor::GetUnit(*sum, sum->GetTarget()))
//                sum->CastSpell(target, SpellOrbofCorrosionOnPlayer, true);
//            break;
//        case Data::Creatures::NightWatchMariner:
//            if (eventPhase == PHASE_3)
//                sum->AddAura(SpellRallyOfTheKvaldir, sum);
//            break;
//        default:
//            break;
//        }
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        if (type == Data::BossIDs::HelyaID)
//            return eventPhase;
//        return 0;
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim() && me->IsInCombat())
//            return;
//
//        if (_checkEvadeTimer)
//        {
//            if (_checkEvadeTimer <= diff)
//            {
//                _checkEvadeTimer = 1500;
//
//                if (auto victim = me->GetVictim())
//                {
//                    if (me->GetDistance(victim) > 90.0f && eventPhase != PHASE_2)
//                        EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
//                    else if (me->GetDistance(victim) > 140.0f && eventPhase == PHASE_2)
//                        EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
//                }
//            }
//            else
//                _checkEvadeTimer -= diff;
//        }
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
//            case EVENT_TAINT_OF_THE_SEA:
//            {
//                if (eventPhase == PHASE_1 || eventPhase == PHASE_3)
//                {
//                    me->AddAura(SpellTaintOfTheSea);
//                    if (IsMythicRaid())
//                        events.RescheduleEvent(EVENT_TAINT_OF_THE_SEA, 12000);
//                    else if (IsHeroicRaid())
//                        events.RescheduleEvent(EVENT_TAINT_OF_THE_SEA, 14000);
//                    else if (IsNormalRaid() || IsLFR())
//                        events.RescheduleEvent(EVENT_TAINT_OF_THE_SEA, 12000);
//                }
//                break;
//            }
//            case EVENT_TENTECLE_STRIKE:
//                if (eventPhase == PHASE_1)
//                {
//                    me->SummonCreature(Data::Creatures::StrikingTentacle, StrikingTentacle[urand(0, 2)], TEMPSUMMON_TIMED_DESPAWN, 9000);
//
//                    if (IsMythicRaid())
//                        events.RescheduleEvent(EVENT_TENTECLE_STRIKE, 35000);
//                    else
//                        events.RescheduleEvent(EVENT_TENTECLE_STRIKE, 30000);
//                }
//                break;
//            case EVENT_ORB_OF_CURRUPTION:
//                if (eventPhase == PHASE_1)
//                {
//                    DoCast(SpellOrbOfCorruption);
//
//                    if (IsMythicRaid())
//                        events.RescheduleEvent(EVENT_ORB_OF_CURRUPTION, 23000);
//                    else
//                        events.RescheduleEvent(EVENT_ORB_OF_CURRUPTION, 26000);
//                }
//                break;
//            case EVENT_ORB_OF_CORROSION:
//                if (eventPhase == PHASE_3)
//                {
//                    Talk(SAY_ORB_OF_CORROSION);
//                    DoCast(SpellOrbOfCorrosion);
//
//                    if (IsMythicRaid())
//                        events.RescheduleEvent(EVENT_ORB_OF_CORROSION, 13000);
//                    else
//                        events.RescheduleEvent(EVENT_ORB_OF_CORROSION, 17000);
//                }
//                break;
//            case EVENT_TORRENT:
//                if (!me->HasUnitState(UNIT_STATE_CASTING))
//                {
//                    if (eventPhase == PHASE_2)
//                    {
//                        if (!me->HasAura(SpellFureOfTheMawLong))
//                        {
//                            power = me->GetPower(POWER_ALTERNATE_POWER);
//
//                            if (power <= 95)
//                            {
//                                DoCast(SpellTorrent);
//                                events.RescheduleEvent(EVENT_TORRENT, 10000);
//                            }
//                        }
//                    }
//                }
//                break;
//            case EVENT_TELEPORT_OUTSIDE:
//                me->NearTeleportTo(553.95f, 733.01f, 5.1663f, 4.03013f);
//                break;
//            case EVENT_TELEPORT_HOME:
//                me->NearTeleportTo(524.031f, 699.055f, 5.17631f, 4.29875f);
//                break;
//            case EVENT_FURY_OF_THE_MAW:
//                DoCast(SpellFuryOfTheMawAT);
//                events.RescheduleEvent(EVENT_FURY_OF_THE_MAW_CLEAN_AT, 3000);
//                break;
//            case EVENT_FURY_OF_THE_MAW_CLEAN_AT:
//                me->RemoveDynObject(SpellBilewaterLiquefactionDmg);
//                me->RemoveDynObject(SpellDecay);
//                break;
//            case EVENT_REANIMATION:
//                if (eventPhase == 0)
//                {
//                    DoCast(SpellReanimation1);
//                    DoCast(SpellReanimation2);
//                    events.RescheduleEvent(EVENT_REANIMATION, 15000);
//                }
//                break;
//            case EVENT_SUMMON_SKELETION:
//                for (uint8 i = 0; i < 10; ++i)
//                    me->SummonCreature(Data::Creatures::DecayingMinion, skeletionPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                break;
//            case EVENT_BOAT:
//                if (eventPhase == PHASE_2)
//                {
//                    me->SummonCreature(Data::Creatures::KvaldirLongboat, 569.39f, 857.6201f, 0.00213f, 4.433769f, TEMPSUMMON_TIMED_DESPAWN, 5000);
//                    me->SummonCreature(Data::Creatures::KvaldirLongboat, 638.672f, 817.6201f, 0.00213f, 3.943812f, TEMPSUMMON_TIMED_DESPAWN, 5000);
//                    me->SummonCreature(Data::Creatures::Grimelord, 458.674f, 639.483f, 7.53757f, 4.433769f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                    me->SummonCreature(Data::Creatures::NightWatchMariner, 516.007f, 614.179f, 5.5823f, 3.943812f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                    if (IsMythicRaid())
//                    {
//                        me->SummonCreature(Data::Creatures::HelarjarMistwatcher, 564.366f, 653.4237f, 17.9559f, 2.401197f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                        me->SummonCreature(Data::Creatures::HelarjarMistwatcher, 469.7802f, 703.5213f, 17.96658f, 6.12398f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                    }
//                }
//                else if (eventPhase == PHASE_3)
//                {
//                    me->SummonCreature(Data::Creatures::NightWatchMariner, 516.007f, 614.179f, 5.5823f, 3.943812f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
//                    me->SummonCreature(Data::Creatures::KvaldirLongboat, 638.672f, 817.6201f, 0.00213f, 3.943812f, TEMPSUMMON_TIMED_DESPAWN, 5000);
//                }
//                break;
//            }
//        }
//
//        if (berserk)
//        {
//            if (berserk <= diff)
//            {
//                berserk = 0;
//                DoCast(me, SpellBerserk, true);
//            }
//            else
//                berserk -= diff;
//        }
//
//        if (AOEdmg)
//        {
//            if (AOEdmg <= diff)
//            {
//                if (eventPhase != PHASE_2)
//                {
//                    if (checkrephase)
//                        return;
//
//                    if (auto victim = me->GetVictim())
//                        if (!me->IsWithinMeleeRange(victim))
//                            DoCast(SpellCorrosiveNova);
//                }
//            }
//            else
//                AOEdmg -= diff;
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////232229
//class spell_helya_blue_power_regen : public AuraScript
//{
//    PrepareAuraScript(spell_helya_blue_power_regen);
//
//    uint8 power{};
//    std::vector<uint32> energy_initial = { 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2 };
//    std::vector<uint32> energy = { 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 };
//    uint32 i = 0;
//    bool initial_energy = false;
//
//    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        if (!GetCaster())
//            return;
//
//        if (auto helya = GetCaster()->ToCreature())
//            if (helya->IsInCombat() && !initial_energy)
//                initial_energy = true;
//    }
//
//    void Tick(AuraEffect const* aurEff)
//    {
//        if (auto helya = GetCaster()->ToCreature())
//        {
//            power = helya->GetPower(POWER_ENERGY);
//
//            if (!helya->IsInCombat())
//                return;
//
//            if (power == 0 && helya->HasAura(SpellHelyaBluePower))
//                initial_energy = false;
//
//            if (power != 100)
//            {
//                if (initial_energy)
//                    helya->SetPower(POWER_ENERGY, power + energy_initial[i]);
//                else
//                    helya->SetPower(POWER_ENERGY, power + energy[i]);
//            }
//        }
//    }
//
//    void Register() override
//    {
//        AfterEffectApply += AuraEffectApplyFn(spell_helya_blue_power_regen::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_helya_blue_power_regen::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////232230
//class spell_helya_purple_power_regen : public AuraScript
//{
//    PrepareAuraScript(spell_helya_purple_power_regen);
//
//    uint8 power{};
//
//    void Tick(AuraEffect const* aurEff)
//    {
//        if (auto helya = GetCaster()->ToCreature())
//        {
//            if (!helya->IsInCombat())
//                return;
//
//            power = helya->GetPower(POWER_ENERGY);
//            helya->SetPower(POWER_ENERGY, power + 2);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_helya_purple_power_regen::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////228383
//class spell_tov_darkness : public AuraScript
//{
//    PrepareAuraScript(spell_tov_darkness);
//
//    uint8 power{};
//    std::vector<uint32> energyLfr = { 1, 2, 3, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2 };
//    std::vector<uint32> energy = { 3, 3, 4, 3, 3, 4, 3, 3, 4, 3, 3, 4, 3, 3, 4, 3, 3, 4, 3, 3, 4, 3, 3, 4, 3, 3, 4 };
//    uint32 i = 0;
//
//    void Tick(AuraEffect const* aurEff)
//    {
//        if (auto npc = GetCaster()->ToCreature())
//        {
//            if (!npc->IsInCombat())
//                return;
//
//            power = npc->GetPower(POWER_ENERGY);
//            if (npc->GetMap() && (npc->GetMap()->GetDifficultyID() == DIFFICULTY_LFR))
//                npc->SetPower(POWER_ENERGY, power + energyLfr[i]);
//            else
//                npc->SetPower(POWER_ENERGY, power + energy[i]);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tov_darkness::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////228546
//class spell_helya_alt_power_regen : public AuraScript
//{
//    PrepareAuraScript(spell_helya_alt_power_regen);
//
//    uint8 power{};
//    uint32 i = 0;
//    uint32 alt_energy[4] = { 2, 3, 2, 1 };
//
//    void Tick(AuraEffect const* aurEff)
//    {
//        if (auto helya = GetCaster()->ToCreature())
//        {
//            if (!helya->IsInCombat())
//                return;
//
//            power = helya->GetPower(POWER_ALTERNATE_POWER);
//            helya->SetPower(POWER_ALTERNATE_POWER, power + alt_energy[urand(0, 3)]);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_helya_alt_power_regen::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////228053
//class spell_taint_of_the_sea : public AuraScript
//{
//    PrepareAuraScript(spell_taint_of_the_sea);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        Unit* target = GetTarget();
//        if (!target && !target->IsInCombat())
//            return;
//        AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();
//
//        if (mode == AURA_REMOVE_BY_ENEMY_SPELL)
//            GetCaster()->CastSpell(target, SpellTaintedEssence, true);
//        else
//            target->CastSpell(target, SpellTaintOfTheSeaDmg, true);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_taint_of_the_sea::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////114523
//struct npc_orb_of_corruption_tov : ScriptedAI
//{
//    explicit npc_orb_of_corruption_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        instance = me->GetInstanceScript();
//    }
//
//    EventMap events;
//    InstanceScript* instance;
//
//    void IsSummonedBy(Unit* /*owner*/) override
//    {
//        DoCast(SpellOrbOfCorruptionSpawnAura);
//        DoCast(SpellOrbOfCorruptionAuraProc);
//        events.RescheduleEvent(EVENT_1, 500);
//    }
//
//    void Reset() override {}
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//                if (auto target = ObjectAccessor::GetUnit(*me, me->GetTarget()))
//                    me->GetMotionMaster()->MovePoint(1, target->GetPosition());
//
//                events.RescheduleEvent(EVENT_2, 1000);
//                break;
//            case EVENT_2:
//                if (auto target = ObjectAccessor::GetUnit(*me, me->GetTarget()))
//                    me->GetMotionMaster()->MovePoint(1, target->GetPosition());
//                else
//                    events.RescheduleEvent(EVENT_1, 1000);
//
//                if (instance->GetBossState(Data::BossIDs::HelyaID) == DONE)
//                    me->DespawnOrUnsummon();
//
//                events.RescheduleEvent(EVENT_2, 1000);
//                break;
//            }
//        }
//    }
//};
//
////114566
//struct npc_orb_of_corrosion_tov : ScriptedAI
//{
//    explicit npc_orb_of_corrosion_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        instance = me->GetInstanceScript();
//    }
//
//    EventMap events;
//    InstanceScript* instance;
//
//    void IsSummonedBy(Unit* /*owner*/) override
//    {
//        DoCast(SpellOrbOfCorrosionSpawnAura);
//        DoCast(SpellOrbOfCorrosionAuraProc);
//        events.RescheduleEvent(EVENT_1, 500);
//    }
//
//    void Reset() override {}
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//                if (auto target = ObjectAccessor::GetUnit(*me, me->GetTarget()))
//                    me->GetMotionMaster()->MovePoint(1, target->GetPosition());
//
//                events.RescheduleEvent(EVENT_2, 1000);
//                break;
//            case EVENT_2:
//                if (auto target = ObjectAccessor::GetUnit(*me, me->GetTarget()))
//                    me->GetMotionMaster()->MovePoint(1, target->GetPosition());
//                else
//                    events.RescheduleEvent(EVENT_1, 1000);
//
//                if (instance->GetBossState(Data::BossIDs::HelyaID) == DONE)
//                    me->DespawnOrUnsummon();
//
//                events.RescheduleEvent(EVENT_2, 1000);
//                break;
//            }
//        }
//    }
//};
//
////114553
//struct npc_bilewater_slime_tov : ScriptedAI
//{
//    explicit npc_bilewater_slime_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//        me->SetReactState(REACT_PASSIVE);
//        DoCast(me, SpellSlimey, true);
//        spellhit = false;
//    }
//
//    InstanceScript* instance;
//    bool spellhit;
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        DoCast(me, SpellBilewaterLiquefactionScale, true);
//        DoCast(SpellBilewaterLiquefaction);
//    }
//
//    void SpellHit(Unit* /*owner*/, SpellInfo const* spell) override
//    {
//        if (spell->Id == SpellBilewaterLiquefaction)
//        {
//            if (!spellhit)
//            {
//                spellhit = true;
//                DoCast(SpellBilewaterLiquefactionKill);
//            }
//        }
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        if (!spellhit)
//            DoCast(SpellBilewaterLiquefactionKill);
//    }
//};
//
////114709
//struct npc_grimelord_tov : ScriptedAI
//{
//    explicit npc_grimelord_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//    }
//
//    EventMap events;
//    InstanceScript* instance;
//
//    void Reset() override
//    {
//        events.Reset();
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//
//        events.RescheduleEvent(EVENT_1, 14000);
//        events.RescheduleEvent(EVENT_2, 16000);
//        events.RescheduleEvent(EVENT_3, 9000);
//    }
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        if (auto player = me->SelectNearestPlayer(100.0f))
//            AttackStart(player);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim() && me->IsInCombat())
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
//            case EVENT_1:
//                DoCast(SpellAnchorSlam);
//                events.RescheduleEvent(EVENT_1, 12000);
//                break;
//            case EVENT_2:
//                DoCast(SpellSludgeNova);
//                events.RescheduleEvent(EVENT_2, 25000);
//                break;
//            case EVENT_3:
//            {
//              
//                            me->AddAura(SpellFetidRot);
//
//                events.RescheduleEvent(EVENT_3, 17000);
//                break;
//            }
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////114809
//struct npc_night_watch_mariner_tov : ScriptedAI
//{
//    explicit npc_night_watch_mariner_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//    }
//
//    EventMap events;
//    InstanceScript* instance;
//
//    void Reset() override
//    {
//        events.Reset();
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        me->SetPower(POWER_ENERGY, 0);
//        me->SetMaxPower(POWER_ENERGY, 100);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//
//        DoCast(SpellDarkness);
//
//        events.RescheduleEvent(EVENT_1, 8000);
//        events.RescheduleEvent(EVENT_2, 10000);
//    }
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        if (auto player = me->SelectNearestPlayer(100.0f))
//            AttackStart(player);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//    }
//
//    void SetPower(Powers power, int32 value)
//    {
//        if (power == POWER_ENERGY)
//        {
//            if (value == 100)
//            {
//                DoCast(me, SpellLanternOfDarkness, false);
//                me->SetPower(POWER_ENERGY, 0);
//            }
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim() && me->IsInCombat())
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
//            case EVENT_1:
//            {
//
//                            DoCast(SpellGiveNoQuarter);
//                events.RescheduleEvent(EVENT_1, 9000);
//                break;
//            }
//            case EVENT_2:
//                DoCast(SpellGhostlyRage);
//                events.RescheduleEvent(EVENT_2, 16000);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////114568
//struct npc_decaying_minion_tov : ScriptedAI
//{
//    explicit npc_decaying_minion_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//        DoCast(SpellRabid);
//    }
//
//    EventMap events;
//    InstanceScript* instance;
//
//    void Reset() override
//    {
//        events.Reset();
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        events.RescheduleEvent(EVENT_1, 8000);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        if (auto helya = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Helya)))
//            helya->CastSpell(me, SpellDecay, true);
//    }
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        events.RescheduleEvent(EVENT_3, urand(500, 2000));
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim() && me->IsInCombat())
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
//            case EVENT_1:
//                DoCast(SpellVigor);
//                events.RescheduleEvent(EVENT_1, 9000);
//                break;
//            case EVENT_2:
//                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//
//                if (auto player = me->SelectNearestPlayer(200.0f))
//                    AttackStart(player);
//                break;
//            case EVENT_3:
//                if (me->GetPositionX() >= 548.3593f && me->GetPositionX() <= 550.3593f)
//                    me->GetMotionMaster()->MoveJump(532.17f, 665.08f, 2.1955f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 538.4478f && me->GetPositionX() <= 544.3593f)
//                    me->GetMotionMaster()->MoveJump(525.428f, 666.552f, 2.19553f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 529.1761f && me->GetPositionX() <= 535.3593f)
//                    me->GetMotionMaster()->MoveJump(519.117f, 665.5169f, 2.0715f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 521.0399f && me->GetPositionX() <= 526.3593f)
//                    me->GetMotionMaster()->MoveJump(506.52f, 671.52f, 2.04149f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 517.1808f && me->GetPositionX() <= 520.3593f)
//                    me->GetMotionMaster()->MoveJump(501.103f, 675.1241f, 2.17084f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 481.0416f && me->GetPositionX() <= 489.3593f)
//                    me->GetMotionMaster()->MoveJump(488.698f, 612.844f, 2.19552f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 490.2551f && me->GetPositionX() <= 495.3593f)
//                    me->GetMotionMaster()->MoveJump(494.009f, 611.8982f, 2.19546f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 501.1823f && me->GetPositionX() <= 510.3593f)
//                    me->GetMotionMaster()->MoveJump(505.3662f, 607.2649f, 2.80966f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 514.1875f && me->GetPositionX() <= 516.3593f)
//                    me->GetMotionMaster()->MoveJump(510.0153f, 606.5961f, 4.22821f, 0.0f, 20.0f, 20.0f);
//                if (me->GetPositionX() >= 528.01902f && me->GetPositionX() <= 528.9593f)
//                    me->GetMotionMaster()->MoveJump(517.567f, 609.2846f, 4.71457f, 0.0f, 20.0f, 20.0f);
//                events.RescheduleEvent(EVENT_2, 3000);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////116335
//struct npc_helarjar_mistwatcher_tov : ScriptedAI
//{
//    explicit npc_helarjar_mistwatcher_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//        me->SetReactState(REACT_PASSIVE);
//        DoCast(SpellBleakEruption);
//    }
//
//    EventMap events;
//    InstanceScript* instance;
//
//    void Reset() override
//    {
//        events.Reset();
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//    }
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//        events.RescheduleEvent(EVENT_1, 3000);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
//            case EVENT_1:
//                if (auto owner = me->GetOwner())
//                    DoCast(owner, SpellMistInfusion, false);
//
//                events.RescheduleEvent(EVENT_1, 7000);
//                break;
//            }
//        }
//    }
//};
//
////114900
//struct npc_gripping_tentacle_tov : ScriptedAI
//{
//    explicit npc_gripping_tentacle_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        instance = me->GetInstanceScript();
//        me->SetReactState(REACT_PASSIVE);
//        me->SetControlled(1, UNIT_STATE_ROOT);
//    }
//
//    InstanceScript* instance;
//
//    void Reset() override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//    }
//};
//
////114881
//struct npc_striking_tentacle_tov : ScriptedAI
//{
//    explicit npc_striking_tentacle_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetControlled(1, UNIT_STATE_ROOT);
//    }
//
//    void IsSummonedBy(Unit* /*summoner*/) override
//    {
//        DoZoneInCombat();
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        if (auto target = me->SelectNearestPlayer(40.0f))
//            me->CastSpell(target, SpellTentacleStrike, false);
//
//        if (auto helya = me->FindNearestCreature(Data::Creatures::Helya, 30.0f))
//            ZoneTalk(6, nullptr);
//        else
//            ZoneTalk(5, nullptr);
//    }
//};
//
//Position const WPLeftSide[6] =
//{
//    { 606.645f, 773.61f, 2.18505f, 0.0f },
//    { 589.789f, 751.336f, 2.81854f, 0.0f },
//    { 565.098f, 727.396f, 4.04037f, 0.0f },
//    { 537.359f, 675.583f, 5.16302f, 0.0f },
//    { 511.927f, 625.218f, 5.81001f, 0.0f },
//    { 516.007f, 614.179f, 5.5823f, 0.0f }
//};
//
//Position const WPRightSide[6] =
//{
//    { 559.634f, 835.07f, 0.00213f, 0.0f },
//    { 536.195f, 775.74f, 1.63033f, 0.0f },
//    { 531.157f, 745.006f, 5.09614f, 0.0f },
//    { 507.911f, 696.116f, 7.63036f, 0.0f },
//    { 478.192f, 654.984f, 6.92052f, 0.0f },
//    { 458.674f, 639.483f, 7.53757f, 0.0f }
//};
//
////115941
//struct npc_kvaldir_longboat_tov : ScriptedAI
//{
//    explicit npc_kvaldir_longboat_tov(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//    }
//
//    EventMap events;
//    bool leftSide = false;
//    bool rightSide = false;
//
//    void Reset() override
//    {
//        if (me->GetPositionX() >= 636.672f)
//        {
//            leftSide = true;
//            me->GetMotionMaster()->MovePoint(1, WPLeftSide[0]);
//        }
//        else if (me->GetPositionX() <= 570.39)
//        {
//            rightSide = true;
//            me->GetMotionMaster()->MovePoint(1, WPRightSide[0]);
//        }
//    }
//
//    void MovementInform(uint32 type, uint32 data) override
//    {
//        if (type == POINT_MOTION_TYPE)
//        {
//            switch (data)
//            {
//            case 1:
//                events.RescheduleEvent(EVENT_1, 100);
//                break;
//            case 2:
//                events.RescheduleEvent(EVENT_2, 100);
//                break;
//            case 3:
//                events.RescheduleEvent(EVENT_3, 100);
//                break;
//            case 4:
//                events.RescheduleEvent(EVENT_4, 100);
//                break;
//            case 5:
//                events.RescheduleEvent(EVENT_5, 100);
//                break;
//            }
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
//            case EVENT_1:
//                if (rightSide)
//                    me->GetMotionMaster()->MovePoint(2, WPRightSide[1]);
//                else if (leftSide)
//                    me->GetMotionMaster()->MovePoint(2, WPLeftSide[1]);
//                break;
//            case EVENT_2:
//                if (rightSide)
//                    me->GetMotionMaster()->MovePoint(3, WPRightSide[2]);
//                else if (leftSide)
//                    me->GetMotionMaster()->MovePoint(3, WPLeftSide[2]);
//                break;
//            case EVENT_3:
//                if (rightSide)
//                    me->GetMotionMaster()->MovePoint(4, WPRightSide[3]);
//                else if (leftSide)
//                    me->GetMotionMaster()->MovePoint(4, WPLeftSide[3]);
//                break;
//            case EVENT_4:
//                if (rightSide)
//                    me->GetMotionMaster()->MovePoint(5, WPRightSide[4]);
//                else if (leftSide)
//                    me->GetMotionMaster()->MovePoint(5, WPLeftSide[4]);
//                break;
//            case EVENT_5:
//                if (rightSide)
//                    me->GetMotionMaster()->MovePoint(6, WPRightSide[5]);
//                else if (leftSide)
//                    me->GetMotionMaster()->MovePoint(6, WPLeftSide[5]);
//                break;
//            }
//        }
//    }
//};
//
////228397
//class spell_fetid_rot : public SpellScript
//{
//    PrepareSpellScript(spell_fetid_rot);
//
//    void HandleDamage(SpellEffIndex /*effectIndex*/)
//    {
//        Unit* target = GetHitUnit();
//        if (!target)
//            return;
//
//        target->AddAura(SpellFetidRot, target);
//    }
//
//    void Register() override
//    {
//        OnEffectHitTarget += SpellEffectFn(spell_fetid_rot::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////228730
//class spell_tentacle_strike : public SpellScript
//{
//    PrepareSpellScript(spell_tentacle_strike);
//
//    uint8 targetsCount = 0;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        Unit* caster = GetCaster();
//        if (!caster)
//            return;
//
//        if (targets.empty())
//            caster->CastSpell(caster, SpellTentacleSlam, true);
//        else
//            targetsCount = targets.size();
//    }
//
//    void HandleDamage(SpellEffIndex /*effectIndex*/)
//    {
//        if (targetsCount)
//            SetHitDamage(GetHitDamage() / targetsCount);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tentacle_strike::FilterTargets, EFFECT_0, TARGET_UNIT_NEARBY_ENEMY);
//        OnEffectHitTarget += SpellEffectFn(spell_tentacle_strike::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
////232449
//class spell_corrupted_axion : public SpellScript
//{
//    PrepareSpellScript(spell_corrupted_axion);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        Unit* caster = GetCaster();
//        if (!caster)
//            return;
//
//        if (targets.empty())
//            caster->CastSpell(caster, SpellCorruptedAxionAOE, true);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_corrupted_axion::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//    }
//};
//
////232450
//class spell_corrupted_axion_aura : public AuraScript
//{
//    PrepareAuraScript(spell_corrupted_axion_aura);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        Unit* target = GetTarget();
//        if (!target)
//            return;
//
//        Unit* caster = GetCaster();
//        if (!caster || !caster->GetMap())
//            return;
//
//        if (caster->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
//            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
//                caster->CastSpell(target, SpellCorrupted, false);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_corrupted_axion_aura::OnRemove, EFFECT_1, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////232350
//class spell_corrupted_mc : public AuraScript
//{
//    PrepareAuraScript(spell_corrupted_mc);
//
//    void OnProc(AuraEffect const* aurEff)
//    {
//        Unit* target = GetTarget();
//        Unit* caster = GetCaster();
//        if (!target || !caster)
//            return;
//
//        if (target && target->HealthBelowPct(11))
//            target->RemoveAura(SpellCorrupted);
//
//        target->GetMotionMaster()->Clear();
//
//        if (!target->HasUnitState(UNIT_STATE_CASTING))
//            target->CastSpell(caster, SpellMistInfusion, false);
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_corrupted_mc::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////228300
//class spell_fury_of_the_maw : public AuraScript
//{
//    PrepareAuraScript(spell_fury_of_the_maw);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        Unit* caster = GetCaster()->ToCreature();
//        if (!caster)
//            return;
//
//        caster->GetAI()->DoAction(ACTION_1);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_fury_of_the_maw::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////228514
//class spell_tov_torrent : public SpellScript
//{
//    PrepareSpellScript(spell_tov_torrent);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        uint32 count = 5;
//
//        if (targets.size() > count)
//            targets.resize(count);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tov_torrent::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//    }
//};
//
//void AddSC_boss_helya_tov()
//{
//    RegisterCreatureAI(boss_helya_tov);
//    RegisterCreatureAI(npc_orb_of_corruption_tov);
//    RegisterCreatureAI(npc_orb_of_corrosion_tov);
//    RegisterCreatureAI(npc_bilewater_slime_tov);
//    RegisterCreatureAI(npc_grimelord_tov);
//    RegisterCreatureAI(npc_night_watch_mariner_tov);
//    RegisterCreatureAI(npc_decaying_minion_tov);
//    RegisterCreatureAI(npc_gripping_tentacle_tov);
//    RegisterCreatureAI(npc_helarjar_mistwatcher_tov);
//    RegisterCreatureAI(npc_striking_tentacle_tov);
//    RegisterCreatureAI(npc_kvaldir_longboat_tov);
//    RegisterAuraScript(spell_helya_blue_power_regen);
//    RegisterAuraScript(spell_helya_purple_power_regen);
//    RegisterAuraScript(spell_helya_alt_power_regen);
//    RegisterAuraScript(spell_tov_darkness);
//    RegisterAuraScript(spell_taint_of_the_sea);
//    RegisterAuraScript(spell_corrupted_axion_aura);
//    RegisterAuraScript(spell_corrupted_mc);
//    RegisterAuraScript(spell_fury_of_the_maw);
//    RegisterSpellScript(spell_fetid_rot);
//    RegisterSpellScript(spell_tentacle_strike);
//    RegisterSpellScript(spell_corrupted_axion);
//    RegisterSpellScript(spell_tov_torrent);
//}
//

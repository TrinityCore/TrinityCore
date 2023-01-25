#include "trial_of_valor.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

namespace
{
    enum Says
    {
        //Hymdall && Hyrja
        SAY_RAID_CAST = 5,
        SAY_CAST_SPELL,
        SAY_ANN_AGGRO_MYTHIC,
        SAY_DIE_TANK,
        SAY_AGGRO_MYTHIC,

        // ODYN
        SAY_AGGRO = 15,
        SAY_DEFEATED,
        SAY_EVADE_ODYN,
        SAY_STORM_FERGED_SPEAR_RAID,
        SAY_STORM_FERGED_SPEAR,
        SAY_START_3_PHASE = 5,
        SAY_RAID_FELMAGNARON_RUNE = 7,
        SAY_FELMAGNARON_RUNE,
        SAY_DEATH_TANK,
        SAY_STORM_OF_JUSTICE = 14,
        SAY_UNNERING_BLAST = 12
    };

    enum Spells
    {
        // SPELLS FOR ODYN
        SpellIntroConverstaion = 227863,
        SpellLeapIntoBattle = 227882,
        SpellTestForPlayersMythic = 229169,
        SpellTestOfTheChosen = 232301,
        SpellRunicBrandCleanUp = 228242,
        SpellSkyJump = 231166,
        SpellValarjarsBondDummy = 229530,
        SpellValarjarsBondHeroic = 229529,
        SpellValarjarsBondProc = 229469,
        // SPELLS FOR EVENT "Runic" (1 && 2 PHASE)
        SpellDrawPower = 227503,
        SpellDrawPowerDummy = 227888,
        SpellUnneringBlast = 227629,
        SpellUnneringBlastWipe = 231277,
        SpellUnneringBlastDmg = 230989,
        SpellProtected = 229584, // MYTHIC MODE
        SpellDrawPowerMythicCleanUp = 233002, // MYTHIC MODE
        // Spells for Player Runic Event. (MYTHIC MODE)
        SpellBrandedPlayerBlue = 231345,//Phase 3
        SpellBrandedPlayerGreen = 231346,
        SpellBrandedPlayerOrange = 231342,
        SpellBrandedPlayerPurple = 231311,
        SpellBrandedPlayerYellow = 231344,
        SpellBrandedOdynBlue = 229582,//Phase 1,2
        SpellBrandedOdynGreen = 229583,
        SpellBrandedOdynOrange = 229580,
        SpellBrandedOdynPurple = 229579,
        SpellBrandedOdynYellow = 229581,
        // Spells for Valarjar Runebearer. (trash)
        SpellBrandedValarjarOrange = 227491,
        SpellBrandedValarjarPurple = 227490,
        SpellBrandedValarjarYellow = 227498,
        SpellBrandedValarjarBlue = 227499,
        SpellBrandedValarjarGreen = 227500,
        SpellBrandedValarjarDummy = 227602,
        SpellRunicShieldOrange = 227597,
        SpellRunicShieldPurple = 227598,
        SpellRunicShieldYellow = 227596,
        SpellRunicShieldBlue = 227595,
        SpellRunicShieldGreen = 227594,
        // Spells for Create AT Runic Event.
        SpellBrandedOdynBlueAT = 227487,
        SpellBrandedOdynGreenAT = 227488,
        SpellBrandedOdynOrangeAT = 227484,
        SpellBrandedOdynPurpleAT = 227483,
        SpellBrandedOdynYellowAT = 227485,
        // Spells for Odyn Runic Event
        SpellDrawPowerOnOdynPurple = 227961,
        SpellDrawPowerOnOdynOrange = 227973,
        SpellDrawPowerOnOdynYellow = 227974,
        SpellDrawPowerOnOdynBlue = 227975,
        SpellDrawPowerOnOdynGreen = 227976,
        // ODYN PHASE 2
        SpellSpearTransitionHoly = 228734,
        SpellOdynsTestProc = 227626,
        SpellOdynsTest = 228911,
        SpellSpearOfLight = 228870,
        SpellSpearOfLight2 = 233270,
        SpellSpearOfLight3 = 227712,
        SpellSpearOfLight2Missile = 227697,
        SpellGlowingFragment = 227782,
        SpellShatteredSpearsDummy = 231013, // ?
        SpellShatteredSpears = 231019, // ?
        // ODYN PHASE 3
        SpellSpearTransitionThunder = 228740,
        SpellArcingStorm = 229255,
        SpellArcingStormBuff = 229256,
        SpellArcingStormProc = 229254,
        SpellCleancingFlame = 228683,
        SpellCleansingFlame = 227475,
        SpellStormForgedSpear = 228914,
        SpellStormForgedSpearPlayer = 228932,
        SpellStormOfJustice = 227807,
        SpellStormOfJustice2 = 227959, // UNK ?
        SpellRagingTempest = 227804,
        SpellRunicBrandMythic = 231384,
        SpellRadiantSmiteDummy = 231350, // MYTHIC MODE
        SpellCleansingFlameAT_1 = 227448,
        SpellCleansingFlameAT_2 = 227455,
        SpellCleansingFlameAT_3 = 227456,
        // ------[SPELLS FOR ODYN END]-------

        // SPELLS FOR HYMDALL
        SpellDancingBlade = 228003,
        SpellDancingBlade2 = 228007,
        SpellDancingBlade3 = 228006,
        SpellHornOfValour = 228012,
        SpellHornOfValourPlayer = 228871,

        // SPELLS FOR HYRJA
        SpellExpelLight = 228028,
        SpellExpelLight2 = 228029,
        SpellExpelLight3 = 228030,
        SpellShieldOfLight = 228162,
        SpellShieldOfLight2 = 228270,
        SpellShieldOfLight3 = 228272,
        SpellHyrjaConversation = 232132,
        SpellHoverModeAnimState = 90766,

        // SPELLS FOR HYMDALL && HYRJA
        SpellRevivify = 228171,
        SpellValarjarsBond = 228016,
        SpellValarjarsBond2 = 228018,
        SpellHeal = 163492,
        SpellClearAllDebuffs = 34098,

        // SPELLS FOR VALARJAR RUNEBEARER
        SpellRunebearerSpawn = 230415
    };

    enum Phase
    {
        PHASE_1 = 1,
        PHASE_2,
        PHASE_3
    };

    enum Events
    {
        EVENT_INTRO = 1,
        EVENT_START_ODYN = 2,
        EVENT_START_SECOND_PHASE = 3,
        EVENT_START_THIRD_PHASE = 4,
        EVENT_SPEAR_OF_LIGHT = 5,
        EVENT_FELMAGNARON_RUNE = 6,
        EVENT_ODYNS_TEST = 7,
        EVENT_STORM_OF_JUSTICE = 8,
        EVENT_STORM_FORGED_SPEAR = 9,
        EVENT_CLEANSING_FLAME_AT_1 = 10,
        EVENT_CLEANSING_FLAME_AT_2 = 11,
        EVENT_CLEANSING_FLAME_AT_3 = 12,
        EVENT_PHASE_TWO_HYMDALL = 13,
        EVENT_PHASE_TWO_HYRJA = 14,
        EVENT_ARCING_STORM_BUFF = 15,

        // Hymdall
        EVENT_HORN_OF_VALOUR = 16,
        EVENT_DANCING_BLADE = 17,

        //Hyrja
        EVENT_EXPEL_LIGHT = 18,
        EVENT_SHIELD_OF_LIGHT = 19,
        EVENT_SHIELD_OF_LIGHT_REACT = 20
    };
}

enum Miscs
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,

    EVENT_1,
};
void EnterCombatEncounter(InstanceScript* instance)
{
    if (!instance)
        return;

    if (instance->GetBossState(Data::BossIDs::OdynID) == IN_PROGRESS)
        return;

    instance->SetBossState(Data::BossIDs::OdynID, IN_PROGRESS);

    if (auto cre = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Odyn)))
        cre->AI()->DoAction(ACTION_4);
}

static uint32 SpellsRunicOnValarjar[5] =
{
    SpellBrandedValarjarPurple,
    SpellBrandedValarjarOrange,
    SpellBrandedValarjarBlue,
    SpellBrandedValarjarGreen,
    SpellBrandedValarjarYellow
};

static uint32 SpellsRunicOnPlayerMythic[5] =
{
    SpellBrandedPlayerPurple,
    SpellBrandedPlayerOrange,
    SpellBrandedPlayerBlue,
    SpellBrandedPlayerGreen,
    SpellBrandedPlayerYellow
};

static uint32 SpellsRunicOnOdynMythic[5] =
{
    SpellBrandedOdynPurple,
    SpellBrandedOdynOrange,
    SpellBrandedOdynBlue,
    SpellBrandedOdynGreen,
    SpellBrandedOdynYellow
};

static uint32 SpellsRunicAT[5] =
{
    SpellBrandedOdynPurpleAT,
    SpellBrandedOdynOrangeAT,
    SpellBrandedOdynBlueAT,
    SpellBrandedOdynGreenAT,
    SpellBrandedOdynYellowAT
};

static uint32 SpellsRunicOnOdyn[5] =
{
    SpellDrawPowerOnOdynPurple,
    SpellDrawPowerOnOdynOrange,
    SpellDrawPowerOnOdynBlue,
    SpellDrawPowerOnOdynGreen,
    SpellDrawPowerOnOdynYellow
};

static Position ValarjarRunebearer[5] =
{
    { 2465.967f, 484.0451f, 749.0782f, 2.251475f },
    { 2409.139f, 485.3073f, 749.0782f, 1.117011f },
    { 2496.684f, 556.941f, 749.0782f, 3.525565f },
    { 2466.094f, 573.3021f, 749.0782f, 4.014257f },
    { 2496.595f, 501.7517f, 749.0782f, 2.740167f }
};

struct boss_tov_odyn : BossAI
{
    explicit boss_tov_odyn(Creature* creature) : BossAI(creature, Data::BossIDs::OdynID) {}

    bool introDone = {};
    bool SecondPhaseSay = {};
    bool encounterComplete = {};
    bool unneringBlast = {};
    bool disableEvade = {};
    ObjectGuid defGUID[2];
    ObjectGuid tankGUID;
    std::vector<ObjectGuid> SpearOfLightGUID;
    std::vector<ObjectGuid> RagingTempestGUID;
    uint8 eventPhase;
    uint8 runicBrandCount;
    uint8 SummonCheckPosition;
    uint8 CountBranded;
    uint32 checktimer;
    uint32 RemoveInCorrectAuras;

    void Reset() override
    {
        if (instance->GetBossState(Data::BossIDs::OdynID) != DONE && !encounterComplete)
        {
            _Reset();

            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
            me->SetPower(POWER_ENERGY, 0);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetFaction(35);
            me->RemoveAllAuras();
            me->RemoveAllAreaObjects();

            summons.DespawnAll();
            DespawnAllSummons();
            SummonDefenders();
            RemoveDebuffsOnPlayer();

            runicBrandCount = 0;
            CountBranded = 0;
            eventPhase = 0;
            RemoveInCorrectAuras = 0;
            SecondPhaseSay = false;
            unneringBlast = false;
            introDone = false;
            disableEvade = false;

            if (IsHeroicPlusRaid())
                instance->SetData(Data::DataMisc::OdynTestOfAges, FAIL);

            for (uint8 i = 0; i < 5; ++i)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SpellsRunicOnPlayerMythic[i]);
                instance->SetData(Data::DataMisc::OdynRunesDeactivated, i);

                if (IsMythicRaid())
                    instance->DoRemoveAurasDueToSpellOnPlayers(SpellsRunicOnOdynMythic[i]);
            }

            if (instance->GetData(Data::DataMisc::OdynEvadeComplete) == DONE)
            {
                instance->SetData(Data::DataMisc::OdynEventComplete1, FAIL);
                instance->SetData(Data::DataMisc::OdynEventComplete2, FAIL);

                for (auto i : { Data::Creatures::Hymdall , Data::Creatures::Hyrja })
                    if (auto add = instance->instance->GetCreature(instance->GetGuidData(i)))
                        add->AI()->DoAction(ACTION_1);
            }
        }
    }

    void RemoveDebuffsOnPlayer()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellStormForgedSpearPlayer);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellStormOfJustice);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellProtected);
    }

    void EnterEvadeMode(EvadeReason w) 
    {
        if (disableEvade && eventPhase == PHASE_1)
            return;

        if (instance->GetBossState(Data::BossIDs::OdynID) != DONE)
        {
            Talk(SAY_EVADE_ODYN);

            if (instance->GetData(Data::DataMisc::OdynEvadeComplete) != DONE)
            {
                if ((instance->GetData(Data::DataMisc::OdynEventComplete1) == DONE) && (instance->GetData(Data::DataMisc::OdynEventComplete2) == DONE))
                    instance->SetData(Data::DataMisc::OdynEvadeComplete, DONE);
            }
        }

        BossAI::EnterEvadeMode();

        if (!encounterComplete)
            me->NearTeleportTo(2341.88f, 528.594f, 770.091f, 0.0f);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (introDone)
            return;

        if ((instance->GetBossState(Data::BossIDs::OdynID) != DONE) && (instance->GetData(Data::DataMisc::OdynIntroEvent) != DONE))
        {
            introDone = true;
            instance->SetData(Data::DataMisc::OdynIntroEvent, DONE);
            events.RescheduleEvent(EVENT_INTRO, 55000);
            DoCast(SpellIntroConverstaion);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_DEATH_TANK);
    }

    void SetPower(Powers power, int32 value)
    {
        if (power != POWER_ENERGY)
            return;

        if (value == 100)
        {
            if (!unneringBlast && !me->HasAura(SpellRunicBrandMythic) && me->IsInCombat())
            {
                unneringBlast = true;
                DoCast(SpellUnneringBlast);
                Talk(SAY_UNNERING_BLAST);
            }

            if (me->HasAura(SpellRunicBrandMythic))
                DoCast(SpellRadiantSmiteDummy);
        }
    }

    void JustSummoned(Creature* sum) override
    {
        summons.Summon(sum);

        switch (sum->GetEntry())
        {
        case Data::Creatures::Hymdall:
            defGUID[0].Clear();
            defGUID[0] = sum->GetGUID();
            break;
        case Data::Creatures::Hyrja:
            defGUID[1].Clear();
            defGUID[1] = sum->GetGUID();
            break;
        case Data::Creatures::ValarjarRunebearer:
            if (auto target = ObjectAccessor::GetUnit(*sum, sum->GetTarget()))
            {
                sum->CastSpell(target, SpellsRunicOnValarjar[CountBranded], true);
                CountBranded++;
                sum->AI()->AttackStart(target);
            }
            break;
        default:
            break;
        }
    }

    void SummonDefenders()
    {
        me->SummonCreature(Data::Creatures::Hymdall, 2382.53f, 512.628f, 749.078f, 0.292808f);
        me->SummonCreature(Data::Creatures::Hyrja, 2382.96f, 543.483f, 749.078f, 6.27582f);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, Data::Creatures::RagingTempest, 200.0f);
        me->GetCreatureListWithEntryInGrid(list, Data::Creatures::ValarjarRunebearer, 200.0f);
        if (!list.empty())
            for (auto& cre : list)
                cre->DespawnOrUnsummon();
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SpellDrawPowerDummy:
            DoCast(me, SpellsRunicAT[runicBrandCount], true);
            instance->SetData(Data::DataMisc::OdynRunesActivated, runicBrandCount);
            runicBrandCount++;
            break;
        case SpellUnneringBlast:
            if (me->HasAura(SpellDrawPowerOnOdynPurple) && me->HasAura(SpellDrawPowerOnOdynBlue) && me->HasAura(SpellDrawPowerOnOdynGreen) && me->HasAura(SpellDrawPowerOnOdynYellow) && me->HasAura(SpellDrawPowerOnOdynOrange))
                me->CastSpell(target, SpellUnneringBlastWipe, TriggerCastFlags(TRIGGERED_IGNORE_GCD));
            else
                me->CastSpell(target, SpellUnneringBlastDmg, TriggerCastFlags(TRIGGERED_IGNORE_GCD));
            break;
        case SpellTestForPlayersMythic:
            if (target->IsPlayer())
                DoCast(target, SpellTestOfTheChosen, true);
            break;
        case SpellStormForgedSpear:
            Talk(SAY_STORM_FERGED_SPEAR);
            if (auto victim = me->GetVictim())
                Talk(SAY_STORM_FERGED_SPEAR_RAID);
            break;
        }
    }

    void SpellHit(Unit* /*owner*/, SpellInfo const* spell) override
    {
        if (spell->Id == SpellValarjarsBondDummy)
            DoCast(me, SpellValarjarsBondHeroic, true);
    }

    void SpellFinishCast(SpellInfo const* spell)
    {
        switch (spell->Id)
        {
        case SpellDrawPowerDummy:
        {
            for (uint8 i = 0; i < 5; ++i)
                DoCast(me, SpellsRunicOnOdyn[i], true);

            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
            Trinity::Containers::RandomResize(playerList, 5);

            if (playerList.empty())
                return;

            for (auto& player : playerList)
            {
                ObjectGuid playerGuid = player->GetGUID();
                me->SummonCreature(Data::Creatures::ValarjarRunebearer, ValarjarRunebearer[SummonCheckPosition], TEMPSUMMON_DEAD_DESPAWN);
                SummonCheckPosition++;
            }
            break;
        }
        case SpellUnneringBlast:
            for (uint8 i = 0; i < 5; ++i)
            {
                instance->SetData(Data::DataMisc::OdynRunesDeactivated, i);
                me->RemoveAurasDueToSpell(SpellsRunicOnOdyn[i]);
                me->RemoveAurasDueToSpell(SpellsRunicOnPlayerMythic[i]);
            }
            RemoveInCorrectAuras = 0;
            DoCast(SpellDrawPowerMythicCleanUp);
            DoCast(SpellRunicBrandCleanUp);
            me->RemoveAllAreaObjects();
            DespawnAllSummons();
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (damage >= me->GetHealth())
            damage = 0;

        if (me->HealthBelowPct(10) && !encounterComplete)
        {
            encounterComplete = true;
            me->SetHomePosition(2400.65f, 529.3139f, 748.99609f, 6.18879f);
            _JustDied();
            me->SetFaction(35);
            me->RemoveAllAuras();

            Talk(SAY_DEFEATED);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
            me->SetNpcFlags(UNIT_NPC_FLAG_QUESTGIVER);

            DespawnAllSummons();
            RemoveDebuffsOnPlayer();
            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, 1958, 0, 0);
        }

        if (!SecondPhaseSay && me->HealthBelowPct(55))
        {
            SecondPhaseSay = true;
            StartEvents(PHASE_3);
        }
    }

    bool GossipSelect(Player* player, uint32 /*sender*/, uint32 action) override
    {
        if (action == 0)
        {
            player->CastSpell(player, SpellSkyJump, false);
        }

        return true;
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_1:
            if ((instance->GetData(Data::DataMisc::OdynEventComplete1) == DONE) && (instance->GetData(Data::DataMisc::OdynEventComplete2) == DONE))
            {
                Talk(SAY_AGGRO);
                me->RemoveAura(SpellDrawPower);
                me->SetPower(POWER_ENERGY, 0);
                DespawnAllSummons();
                DoCast(SpellRunicBrandCleanUp);
                DoCast(SpellDrawPowerMythicCleanUp);

                for (uint8 i = 0; i < 5; ++i)
                {
                    instance->SetData(Data::DataMisc::OdynRunesDeactivated, i);
                    me->RemoveAurasDueToSpell(SpellsRunicOnOdyn[i]);
                    me->RemoveAurasDueToSpell(SpellsRunicOnPlayerMythic[i]);
                }

                for (auto i : { Data::Creatures::Hymdall , Data::Creatures::Hyrja })
                    if (auto add = instance->instance->GetCreature(instance->GetGuidData(i)))
                        add->AI()->DoAction(ACTION_3);

                disableEvade = true;
                events.RescheduleEvent(EVENT_START_ODYN, 7000);
                events.CancelEvent(EVENT_FELMAGNARON_RUNE);
            }
            break;
        case ACTION_3:
            BossAI::EnterEvadeMode();
            events.RescheduleEvent(EVENT_INTRO, 0);
            break;
        case ACTION_4:
            StartEvents(PHASE_1);
            break;
        default:
            break;
        }
    }

    void StartEvents(uint8 phase)
    {
        events.Reset();
        eventPhase = phase;

        switch (phase)
        {
        case PHASE_1:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.RescheduleEvent(EVENT_FELMAGNARON_RUNE, 40000);
            break;
        case PHASE_2:
            if (auto player = me->SelectNearestPlayer(300.0f))
            {
                me->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->SetReactState(REACT_AGGRESSIVE);
                AttackStart(player);
            }
            disableEvade = false;
            DoCast(me, SpellSpearTransitionHoly, false);
            events.RescheduleEvent(EVENT_SPEAR_OF_LIGHT, 5000);
            events.RescheduleEvent(EVENT_ODYNS_TEST, 30000);
            events.RescheduleEvent(EVENT_FELMAGNARON_RUNE, 40000);

            if (IsHeroicPlusRaid())
            {
                instance->SetData(Data::DataMisc::OdynTestOfAges, DONE);
                events.RescheduleEvent(EVENT_PHASE_TWO_HYRJA, 10000);
                events.RescheduleEvent(EVENT_PHASE_TWO_HYMDALL, 76000);
            }

            if (IsMythicRaid())
                if (instance->GetBossState(Data::BossIDs::OdynID) != DONE)
                    DoCast(SpellTestForPlayersMythic);
            break;
        case PHASE_3:
            for (uint8 i = 0; i < 5; ++i)
            {
                instance->SetData(Data::DataMisc::OdynRunesDeactivated, i);
                me->RemoveAurasDueToSpell(SpellsRunicOnOdyn[i]);
                me->RemoveAurasDueToSpell(SpellsRunicOnPlayerMythic[i]);
            }

            Talk(SAY_START_3_PHASE);
            DoCast(SpellRunicBrandCleanUp);
            DoCast(SpellDrawPowerMythicCleanUp);
            me->RemoveAurasDueToSpell(SpellSpearTransitionHoly);
            me->RemoveAurasDueToSpell(SpellOdynsTest);
            me->RemoveAurasDueToSpell(SpellOdynsTestProc);
            me->RemoveAllAreaObjects();
            me->RemoveAura(SpellDrawPower);
            me->SetPower(POWER_ENERGY, 0);
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            DespawnAllSummons();
            events.RescheduleEvent(EVENT_START_THIRD_PHASE, 4000);
            break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == Data::BossIDs::OdynID)
            return eventPhase;
        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (instance->GetBossState(Data::BossIDs::OdynID) == DONE)
            return;

        if (me->GetFaction() == 16)
            UpdateVictim();

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_INTRO:
                for (auto i : { Data::Creatures::Hymdall , Data::Creatures::Hyrja })
                    if (auto add = instance->instance->GetCreature(instance->GetGuidData(i)))
                        add->AI()->DoAction(ACTION_1);
                break;
            case EVENT_START_ODYN:
                DoCast(SpellLeapIntoBattle);
                me->SetFaction(16);

                if (IsHeroicPlusRaid())
                    DoCast(me, SpellValarjarsBondProc, true);

                events.RescheduleEvent(EVENT_START_SECOND_PHASE, 2000);
                break;
            case EVENT_START_SECOND_PHASE:
                StartEvents(PHASE_2);
                break;
            case EVENT_START_THIRD_PHASE:
                me->SetReactState(REACT_AGGRESSIVE);
                DoCast(SpellSpearTransitionThunder);
                DoCast(SpellArcingStormProc);
                events.RescheduleEvent(EVENT_STORM_OF_JUSTICE, 4000);
                events.RescheduleEvent(EVENT_STORM_FORGED_SPEAR, 14000);
                events.RescheduleEvent(EVENT_CLEANSING_FLAME_AT_1, 1000);
                events.RescheduleEvent(EVENT_ARCING_STORM_BUFF, 6000);
                break;
            case EVENT_FELMAGNARON_RUNE:
                runicBrandCount = 0;
                SummonCheckPosition = 0;
                CountBranded = 0;
                RemoveInCorrectAuras = 500;
                unneringBlast = false;
                ZoneTalk(SAY_RAID_FELMAGNARON_RUNE, nullptr);
                Talk(SAY_FELMAGNARON_RUNE);
                DoCast(SpellDrawPowerDummy);
                DoCast(SpellDrawPower);
                events.RescheduleEvent(EVENT_FELMAGNARON_RUNE, 70000);
                break;
            case EVENT_ODYNS_TEST:
                DoCast(SpellOdynsTest);

                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_ODYNS_TEST, 80000);
                else
                    events.RescheduleEvent(EVENT_ODYNS_TEST, 70000);
                break;
            case EVENT_STORM_FORGED_SPEAR:
                DoCast(SpellStormForgedSpear);
                events.RescheduleEvent(EVENT_STORM_FORGED_SPEAR, 11000);
                break;
            case EVENT_STORM_OF_JUSTICE:
                DoCast(SpellStormOfJustice);
                events.RescheduleEvent(EVENT_STORM_OF_JUSTICE, 12000);
                break;
            case EVENT_SPEAR_OF_LIGHT:
            {
                auto threatlist = me->GetThreatManager().GetUnsortedThreatList();
                for (uint8 i = 0; i < (IsLFR() ? 3 : 5); ++i)
                {


                            DoCast(SpellSpearOfLight);

                }
                events.RescheduleEvent(EVENT_SPEAR_OF_LIGHT, 10000);
                break;
            }
            case EVENT_CLEANSING_FLAME_AT_1:
                DoCast(SpellCleansingFlameAT_1);
                events.RescheduleEvent(EVENT_CLEANSING_FLAME_AT_1, 105000);
                events.RescheduleEvent(EVENT_CLEANSING_FLAME_AT_2, 35000);
                break;
            case EVENT_CLEANSING_FLAME_AT_2:
                DoCast(SpellCleansingFlameAT_2);
                events.RescheduleEvent(EVENT_CLEANSING_FLAME_AT_2, 105000);
                events.RescheduleEvent(EVENT_CLEANSING_FLAME_AT_3, 35000);
                break;
            case EVENT_CLEANSING_FLAME_AT_3:
                DoCast(SpellCleansingFlameAT_3);
                events.RescheduleEvent(EVENT_CLEANSING_FLAME_AT_3, 105000);
                events.RescheduleEvent(EVENT_CLEANSING_FLAME_AT_1, 35000);
                break;
            case EVENT_PHASE_TWO_HYMDALL:
                if (auto hymdall = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Hymdall)))
                    if (!hymdall->IsInCombat())
                        hymdall->AI()->DoAction(ACTION_2);

                events.RescheduleEvent(EVENT_PHASE_TWO_HYMDALL, 135000);
                break;
            case EVENT_PHASE_TWO_HYRJA:
                if (auto hyrja = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Hyrja)))
                    if (!hyrja->IsInCombat())
                        hyrja->AI()->DoAction(ACTION_2);

                events.RescheduleEvent(EVENT_PHASE_TWO_HYRJA, 135000);
                break;
            case EVENT_ARCING_STORM_BUFF:
                DoCast(me, SpellArcingStormBuff, false);
                events.RescheduleEvent(EVENT_ARCING_STORM_BUFF, 9000);
                break;
            }
        }

        if (me->HasAura(SpellOdynsTest))
        {
            checktimer = 0;
            if (checktimer <= diff)
            {
                if (auto victim = me->GetVictim())
                {
                    if (victim->GetGUID() != tankGUID)
                    {
                        tankGUID = victim->GetGUID();
                        me->RemoveAura(SpellOdynsTestProc);
                        checktimer = 500;
                    }
                    else
                        checktimer -= diff;
                }
            }
        }

        if (RemoveInCorrectAuras)
        {
            if (RemoveInCorrectAuras <= diff)
            {
                RemoveInCorrectAuras = 500;

                if (me->HasAura(SpellBrandedOdynBlue) || me->HasAura(SpellBrandedOdynYellow) || me->HasAura(SpellBrandedOdynGreen) || me->HasAura(SpellBrandedOdynOrange) || me->HasAura(SpellBrandedOdynPurple))
                    for (uint8 i = 0; i < 5; ++i)
                        me->RemoveAura(SpellsRunicOnOdynMythic[i]);
            }
            else
                RemoveInCorrectAuras -= diff;
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_tov_hymdall : ScriptedAI
{
    explicit npc_tov_hymdall(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        instance = me->GetInstanceScript();
        event1 = false;
        event2 = false;
    }

    EventMap events;
    InstanceScript* instance;
    SummonList summons;
    ObjectGuid DancingBladeGUID;
    bool event1;
    bool event2;

    void Reset() override
    {
        events.Reset();

        DoCast(SpellHeal);
        DespawnAllSummons();
        event1 = false;
        event2 = false;

        if ((instance->GetData(Data::DataMisc::OdynIntroEvent) == DONE) && (instance->GetData(Data::DataMisc::OdynEventComplete1) != DONE))
            me->SetFaction(16);
        if (instance->GetData(Data::DataMisc::OdynEventComplete1) != DONE)
            DoCast(SpellValarjarsBond);
    }

    void JustReachedHome() override
    {
        if (instance->GetData(Data::DataMisc::OdynEventComplete1) == DONE)
        {
            me->setActive(false);
            me->NearTeleportTo(2402.68f, 477.41f, 772.893f, 1.31159f);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoZoneInCombat();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (IsMythicRaid())
        {
            events.RescheduleEvent(EVENT_HORN_OF_VALOUR, 8000);
            events.RescheduleEvent(EVENT_DANCING_BLADE, 15000);
        }
        else if (IsHeroicRaid())
        {
            events.RescheduleEvent(EVENT_HORN_OF_VALOUR, 8000);
            events.RescheduleEvent(EVENT_DANCING_BLADE, 16000);
        }
        else if (IsNormalRaid() || IsLFR())
        {
            events.RescheduleEvent(EVENT_HORN_OF_VALOUR, 10000);
            events.RescheduleEvent(EVENT_DANCING_BLADE, 20000);
        }

        if (instance->GetData(Data::DataMisc::OdynTestOfAges) != DONE)
        {
            EnterCombatEncounter(instance);

            if (auto Hyrja = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Hyrja)))
                if (auto player = me->SelectNearestPlayer(300.0f))
                    Hyrja->AI()->AttackStart(player);
        }

        if (IsHeroicPlusRaid())
        {
            if (instance->GetData(Data::DataMisc::OdynTestOfAges) == DONE)
            {
                Talk(SAY_AGGRO_MYTHIC);
                ZoneTalk(SAY_ANN_AGGRO_MYTHIC, nullptr);
                DoCast(me, SpellValarjarsBondProc, true);
            }
        }
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, Data::Creatures::DancingBlade, 200.0f);
        if (!list.empty())
            for (auto& cre : list)
                cre->DespawnOrUnsummon();
    }

    void SpellHit(Unit* /*owner*/, SpellInfo const* spell) override
    {
        if (spell->Id == SpellValarjarsBondDummy)
            DoCast(me, SpellValarjarsBondHeroic, true);
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_1:
            me->SetFaction(16);
            DoCast(SpellValarjarsBond);
            break;
        case ACTION_2:
            me->SetFaction(16);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->GetMotionMaster()->MoveJump(2410.51f, 508.8186f, 748.9946f, 20, 10, 2, 0.91346f);
            if (auto player = me->SelectNearestPlayer(300.0f))
                AttackStart(player);
            break;
        case ACTION_3:
            me->CastStop();
            me->SetFaction(35);
            me->RemoveAllAuras();
            me->SetHomePosition(2402.68f, 477.41f, 772.893f, 1.31159f);
            me->NearTeleportTo(2402.68f, 477.41f, 772.893f, 1.31159f);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.CancelEvent(EVENT_HORN_OF_VALOUR);
            events.CancelEvent(EVENT_DANCING_BLADE);
            break;
        default:
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) 
    {
        if (damage >= me->GetHealth())
            damage = 0;

        if (instance->GetData(Data::DataMisc::OdynTestOfAges) != DONE)
        {
            if (me->HealthAbovePct(25) || event1)
                return;

            event1 = true;
            DoCast(SpellRevivify);
            me->SetUnitFlags2(UNIT_FLAG2_REGENERATE_POWER);
            me->SetUnitFlags2(UNIT_FLAG2_DISABLE_TURN);
            me->SetUnitFlags2(UNIT_FLAG2_UNK6);

            if (instance->GetData(Data::DataMisc::OdynEventComplete1) != DONE)
            {
                instance->SetData(Data::DataMisc::OdynEventComplete1, DONE);

                if (auto owner = me->GetOwner())
                    owner->GetAI()->DoAction(ACTION_1);
            }
        }

        if (IsHeroicPlusRaid())
        {
            if (instance->GetData(Data::DataMisc::OdynTestOfAges) == DONE)
            {
                if (me->HealthAbovePct(85) || event2)
                    return;

                if (me->HealthBelowPct(85))
                {
                    event2 = true;
                    me->CastStop();
                    me->SetFaction(35);
                    me->RemoveAllAuras();
                    me->NearTeleportTo(2402.68f, 477.41f, 772.893f, 1.31159f);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                }
            }
        }
    }

    void SpellFinishCast(SpellInfo const* spell)
    {
        switch (spell->Id)
        {
        case SpellRevivify:
            event1 = false;
            me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
            me->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
            me->RemoveUnitFlag2(UNIT_FLAG2_UNK6);

            if (instance->GetData(Data::DataMisc::OdynEventComplete1) == DONE && instance->GetData(Data::DataMisc::OdynEventComplete2) != DONE)
                instance->SetData(Data::DataMisc::OdynEventComplete1, FAIL);
            break;
        case SpellHornOfValour:
            DoCast(SpellHornOfValourPlayer);
            break;
        default:
            break;
        }
    }

    void EnterEvadeMode(EvadeReason w)
    {
        if ((instance->GetData(Data::DataMisc::OdynIntroEvent) == DONE) && (instance->GetData(Data::DataMisc::OdynEventComplete1) != DONE))
        {
            if (auto owner = me->GetOwner())
                owner->GetAI()->DoAction(ACTION_3);
        }

        DespawnAllSummons();
        ScriptedAI::EnterEvadeMode();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_DIE_TANK);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_HORN_OF_VALOUR:
                DoCast(SpellHornOfValour);
                ZoneTalk(SAY_RAID_CAST, nullptr);
                Talk(SAY_CAST_SPELL);

                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_HORN_OF_VALOUR, 22000);
                else if (IsHeroicRaid())
                    events.RescheduleEvent(EVENT_HORN_OF_VALOUR, 27000);
                else if (IsLFR() || IsNormalRaid())
                    events.RescheduleEvent(EVENT_HORN_OF_VALOUR, 69000);

                break;
            case EVENT_DANCING_BLADE:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM,0, 100.0f, true, 0))
                    DoCast(target, SpellDancingBlade, false);

                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_DANCING_BLADE, 20000);
                else
                    events.RescheduleEvent(EVENT_DANCING_BLADE, 30000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_tov_hyrja : ScriptedAI
{
    explicit npc_tov_hyrja(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        event1 = false;
        event2 = false;
    }

    EventMap events;
    InstanceScript* instance;
    bool event1;
    bool event2;

    void Reset() override
    {
        events.Reset();

        DoCast(SpellHeal);
        event1 = false;
        event2 = false;

        if ((instance->GetData(Data::DataMisc::OdynIntroEvent) == DONE) && (instance->GetData(Data::DataMisc::OdynEventComplete2) != DONE))
            me->SetFaction(16);
        if (instance->GetData(Data::DataMisc::OdynEventComplete2) != DONE)
            DoCast(SpellValarjarsBond);
    }

    void JustReachedHome() override
    {
        if (instance->GetData(Data::DataMisc::OdynEventComplete2) == DONE)
        {
            me->setActive(false);
            me->NearTeleportTo(2404.92f, 578.45605f, 772.8941f, 5.05401f);
            DoCast(SpellHoverModeAnimState);
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoZoneInCombat();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (IsMythicRaid())
        {
            events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT, 20000);
            events.RescheduleEvent(EVENT_EXPEL_LIGHT, 25000);
        }
        else if (IsHeroicRaid())
        {
            events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT, 23000);
            events.RescheduleEvent(EVENT_EXPEL_LIGHT, 32000);
        }
        else if (IsNormalRaid() || IsLFR())
        {
            events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT, 30000);
            events.RescheduleEvent(EVENT_EXPEL_LIGHT, 40000);
        }

        if (instance->GetData(Data::DataMisc::OdynTestOfAges) != DONE)
        {
            DoCast(SpellHyrjaConversation);

            if (auto hymdall = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Hymdall)))
                if (auto player = me->SelectNearestPlayer(300.0f))
                    hymdall->AI()->AttackStart(player);
        }

        if (IsHeroicPlusRaid())
        {
            if (instance->GetData(Data::DataMisc::OdynTestOfAges) == DONE)
            {
                Talk(SAY_AGGRO_MYTHIC);
                ZoneTalk(SAY_ANN_AGGRO_MYTHIC, nullptr);
                DoCast(me, SpellValarjarsBondProc, true);
            }
        }
    }

    void SpellHit(Unit* /*owner*/, SpellInfo const* spell) override
    {
        if (spell->Id == SpellValarjarsBondDummy)
            DoCast(me, SpellValarjarsBondHeroic, true);
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_1:
            me->SetFaction(16);
            DoCast(SpellValarjarsBond);
            break;
        case ACTION_2:
            me->SetFaction(16);
            me->RemoveAura(SpellHoverModeAnimState);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->GetMotionMaster()->MoveJump(2414.0634f, 552.47f, 748.9953f, 20, 10, 2, 4.82082f);
            if (auto player = me->SelectNearestPlayer(300.0f))
                AttackStart(player);
            break;
        case ACTION_3:
            me->CastStop();
            me->SetFaction(35);
            me->RemoveAllAuras();
            me->SetHomePosition(2404.92f, 578.45605f, 772.8941f, 5.05401f);
            me->NearTeleportTo(2404.92f, 578.45605f, 772.8941f, 5.05401f);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.CancelEvent(EVENT_EXPEL_LIGHT);
            events.CancelEvent(EVENT_SHIELD_OF_LIGHT);
            break;
        default:
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (damage >= me->GetHealth())
            damage = 0;

        if (instance->GetData(Data::DataMisc::OdynTestOfAges) != DONE)
        {
            if (me->HealthAbovePct(25) || event1)
                return;

            event1 = true;
            DoCast(SpellRevivify);
            me->SetUnitFlags2(UNIT_FLAG2_REGENERATE_POWER);
            me->SetUnitFlags2(UNIT_FLAG2_DISABLE_TURN);
            me->SetUnitFlags2(UNIT_FLAG2_UNK6);

            if (instance->GetData(Data::DataMisc::OdynEventComplete2) != DONE)
            {
                instance->SetData(Data::DataMisc::OdynEventComplete2, DONE);

                if (auto owner = me->GetOwner())
                    owner->GetAI()->DoAction(ACTION_1);
            }
        }

        if (IsHeroicPlusRaid())
        {
            if (instance->GetData(Data::DataMisc::OdynTestOfAges) == DONE)
            {
                if (me->HealthAbovePct(85) || event2)
                    return;

                if (me->HealthBelowPct(85))
                {
                    event2 = true;
                    me->CastStop();
                    me->SetFaction(35);
                    me->RemoveAllAuras();
                    me->NearTeleportTo(2404.92f, 578.45605f, 772.8941f, 5.05401f);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                }
            }
        }
    }

    void SpellFinishCast(SpellInfo const* spell)
    {
        switch (spell->Id)
        {
        case SpellRevivify:
            event1 = false;
            me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
            me->RemoveUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
            me->RemoveUnitFlag2(UNIT_FLAG2_UNK6);

            if ((instance->GetData(Data::DataMisc::OdynEventComplete2) == DONE) && (instance->GetData(Data::DataMisc::OdynEventComplete1) != DONE))
                instance->SetData(Data::DataMisc::OdynEventComplete2, FAIL);
        default:
            break;
        }
    }

    void EnterEvadeMode(EvadeReason w)
    {
        if ((instance->GetData(Data::DataMisc::OdynIntroEvent) == DONE) && (instance->GetData(Data::DataMisc::OdynEventComplete2) != DONE))
        {
            if (auto owner = me->GetOwner())
                owner->GetAI()->DoAction(ACTION_3);
        }

        ScriptedAI::EnterEvadeMode();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_DIE_TANK);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_EXPEL_LIGHT:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 300.0f, true))
                    DoCast(target, SpellExpelLight, false);

                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_EXPEL_LIGHT, 20000);
                else if (IsHeroicRaid())
                    events.RescheduleEvent(EVENT_EXPEL_LIGHT, 32000);
                else if (IsLFR() || IsNormalRaid())
                    events.RescheduleEvent(EVENT_EXPEL_LIGHT, 19500);
                break;
            case EVENT_SHIELD_OF_LIGHT:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true, 0))
                {
                    me->SetReactState(REACT_PASSIVE);
                    events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT_REACT, 5500);
                    DoCast(target, SpellShieldOfLight2, false);
                    DoCast(target, SpellShieldOfLight, false);
                    DoCast(target, SpellShieldOfLight3, false);
                    ZoneTalk(SAY_RAID_CAST, target);
                }

                Talk(SAY_CAST_SPELL);

                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT, 20000);
                else
                    events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT, 32000);
                break;
            case EVENT_SHIELD_OF_LIGHT_REACT:
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//114560
struct npc_tov_dancing_blade : ScriptedAI
{
    explicit npc_tov_dancing_blade(Creature* creature) : ScriptedAI(creature) {}

    void IsSummonedBy(Unit* /*owner*/) override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
        DoCast(SpellDancingBlade3);
    }
};

//114485
struct npc_tov_raging_tempest : ScriptedAI
{
    explicit npc_tov_raging_tempest(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void IsSummonedBy(Unit* /*owner*/) override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);        
        me->GetMotionMaster()->MoveRandom(5.0f);
        DoCast(SpellRagingTempest);
        events.RescheduleEvent(EVENT_1, 2500);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                me->GetMotionMaster()->MoveRandom(5.0f);
                events.RescheduleEvent(EVENT_1, 2500);
                break;
            }
        }
    }
};

//114467
struct npc_tov_spear_of_light : ScriptedAI
{
    explicit npc_tov_spear_of_light(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;

    void IsSummonedBy(Unit* /*owner*/) override
    {
        for (uint8 i = 0; i < (IsLFR() ? 3 : 5); ++i)
        {
            Position pos;
            float angle = 6.28f / (IsLFR() ? 3 : 5) * i;
            me->GetNearPosition(3.0f, angle);

            if (auto odyn = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Odyn)))
            {
                if (!odyn || !odyn->IsInCombat())
                    return;

                odyn->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SpellGlowingFragment, true);
            }
        }
        me->DespawnOrUnsummon(1000);
    }
};

//114996
struct npc_valarjar_runebearer : ScriptedAI
{
    explicit npc_valarjar_runebearer(Creature* creature) : ScriptedAI(creature) {}

    uint32 spellId = 0;

    void IsSummonedBy(Unit* /*owner*/) override
    {
        DoCast(SpellRunebearerSpawn);
        me->SetReactState(REACT_PASSIVE);
    }

    void DoAction(int32 const action) override
    {
        if (action == ACTION_1)
        {
            if (spellId)
                DoCast(me, spellId, true);
        }
    }

    void SpellHit(Unit* /*owner*/, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SpellRunicShieldOrange:
        case SpellRunicShieldPurple:
        case SpellRunicShieldYellow:
        case SpellRunicShieldBlue:
        case SpellRunicShieldGreen:
            if (!spellId)
                spellId = spell->Id;
            break;
        }
    }

    void SpellFinishCast(SpellInfo const* spell)
    {
        switch (spell->Id)
        {
        case SpellBrandedValarjarOrange:
            DoCast(me, SpellRunicShieldOrange, true);
            break;
        case SpellBrandedValarjarPurple:
            DoCast(me, SpellRunicShieldPurple, true);
            break;
        case SpellBrandedValarjarYellow:
            DoCast(me, SpellRunicShieldYellow, true);
            break;
        case SpellBrandedValarjarBlue:
            DoCast(me, SpellRunicShieldBlue, true);
            break;
        case SpellBrandedValarjarGreen:
            DoCast(me, SpellRunicShieldGreen, true);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason w) 
    {
        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

//227503
class spell_odyn_power_regen : public AuraScript
{
    PrepareAuraScript(spell_odyn_power_regen);

    uint8 power{};
    std::vector<uint32> energy = { 3, 3, 4, 3, 4, 3, 4, 3, 4, 3, 3, 4, 3, 4, 3, 4, 3, 4, 3, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4 };
    uint32 i = 0;

    void Tick(AuraEffect const* aurEff)
    {
        if (auto odyn = GetCaster()->ToCreature())
        {
            power = odyn->GetPower(POWER_ENERGY);
            odyn->SetPower(POWER_ENERGY, power + energy[i]);

            if (i + 1 < energy.size())
                ++i;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_odyn_power_regen::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//229254
class spell_arcing_storm : public AuraScript
{
    PrepareAuraScript(spell_arcing_storm);

    void Periodic(AuraEffect const* aurEff)
    {
        uint32 count = 0;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (auto odyn = caster->ToCreature())
        {
            if (odyn->GetMap() && (odyn->GetMap()->GetDifficultyID() == DIFFICULTY_NORMAL_RAID || odyn->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID))
                count = 2;
            else if (odyn->GetMap() && (odyn->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID))
                count = 4;
            else if (odyn->GetMap() && (odyn->GetMap()->GetDifficultyID() == DIFFICULTY_LFR))
                count = 1;

            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, odyn, 300.0f);
            Trinity::Containers::RandomResize(playerList, count);

            if (playerList.empty())
                return;

            for (auto& player : playerList)
                odyn->CastSpell(player, SpellArcingStorm, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_arcing_storm::Periodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//231384
class spell_odyn_power_regen_mythic : public AuraScript
{
    PrepareAuraScript(spell_odyn_power_regen_mythic);

    uint8 power{};
    uint8 cap;

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (auto odyn = GetCaster()->ToCreature())
        {
            power = odyn->GetPower(POWER_ENERGY);
            cap = false;

            if (power < 100)
            {
                if (cap)
                    return;

                odyn->SetPower(POWER_ENERGY, power + 20);
            }

            if (power >= 100)
                cap = true;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_odyn_power_regen_mythic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//228911
class spell_odyn_test : public AuraScript
{
    PrepareAuraScript(spell_odyn_test);

    void OnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SpellOdynsTestProc, false);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_odyn_test::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

//227491,227490,227498,227499,227500
class spell_odyn_branded_event : public AuraScript
{
    PrepareAuraScript(spell_odyn_branded_event);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (!target || !target->IsPlayer())
            return;
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Unit* odyn = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Odyn));
        if (!odyn && !odyn->HasAura(SpellDrawPower))
            return;

        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

        if (removeMode == AURA_REMOVE_BY_DEATH)
            return;

        if (GetId() == SpellBrandedValarjarBlue)
        {
            odyn->RemoveAura(SpellDrawPowerOnOdynBlue);

            if (target && target->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID)
            {
                odyn->RemoveDynObject(SpellBrandedOdynBlueAT);
                instance->SetData(Data::DataMisc::OdynDeactivatedBlueRune, DONE);
            }
            else
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, target, 300.0f);
                Trinity::Containers::RandomResize(playerList, 4);

                if (playerList.empty())
                    return;

                for (auto& player : playerList)
                {
                    if (Player* players = player->ToPlayer())
                        if (!players->HasAura(SpellBrandedOdynPurple) && !players->HasAura(SpellBrandedOdynGreen) && !players->HasAura(SpellBrandedOdynOrange) && !players->HasAura(SpellBrandedOdynBlue) && !players->HasAura(SpellBrandedOdynYellow))
                            target->AddAura(SpellBrandedOdynBlue, players);
                }
            }
        }
        else if (GetId() == SpellBrandedValarjarPurple)
        {
            odyn->RemoveAura(SpellDrawPowerOnOdynPurple);

            if (target && target->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID)
            {
                odyn->RemoveDynObject(SpellBrandedOdynPurpleAT);
                instance->SetData(Data::DataMisc::OdynDeactivatedPurpleRune, DONE);
            }
            else
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, target, 300.0f);
                Trinity::Containers::RandomResize(playerList, 4);

                if (playerList.empty())
                    return;

                for (auto& player : playerList)
                {
                    if (Player* players = player->ToPlayer())
                        if (!players->HasAura(SpellBrandedOdynPurple) && !players->HasAura(SpellBrandedOdynGreen) && !players->HasAura(SpellBrandedOdynOrange) && !players->HasAura(SpellBrandedOdynBlue) && !players->HasAura(SpellBrandedOdynYellow))
                            target->AddAura(SpellBrandedOdynPurple, players);
                }
            }
        }
        else if (GetId() == SpellBrandedValarjarYellow)
        {
            odyn->RemoveAura(SpellDrawPowerOnOdynYellow);

            if (target && target->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID)
            {
                odyn->RemoveDynObject(SpellBrandedOdynYellowAT);
                instance->SetData(Data::DataMisc::OdynDeactivatedYellowRune, DONE);
            }
            if (target && target->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, target, 300.0f);
                Trinity::Containers::RandomResize(playerList, 4);

                if (playerList.empty())
                    return;

                for (auto& player : playerList)
                {
                    if (Player* players = player->ToPlayer())
                        if (!players->HasAura(SpellBrandedOdynPurple) && !players->HasAura(SpellBrandedOdynGreen) && !players->HasAura(SpellBrandedOdynOrange) && !players->HasAura(SpellBrandedOdynBlue) && !players->HasAura(SpellBrandedOdynYellow))
                            target->AddAura(SpellBrandedOdynYellow, players);
                }
            }
        }
        else if (GetId() == SpellBrandedValarjarOrange)
        {
            odyn->RemoveAura(SpellDrawPowerOnOdynOrange);

            if (target && target->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID)
            {
                odyn->RemoveDynObject(SpellBrandedOdynOrangeAT);
                instance->SetData(Data::DataMisc::OdynDeactivatedOrangeRune, DONE);
            }
            else
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, target, 300.0f);
                Trinity::Containers::RandomResize(playerList, 4);

                if (playerList.empty())
                    return;

                for (auto& player : playerList)
                {
                    if (Player* players = player->ToPlayer())
                        if (!players->HasAura(SpellBrandedOdynPurple) && !players->HasAura(SpellBrandedOdynGreen) && !players->HasAura(SpellBrandedOdynOrange) && !players->HasAura(SpellBrandedOdynBlue) && !players->HasAura(SpellBrandedOdynYellow))
                            target->AddAura(SpellBrandedOdynOrange, players);
                }
            }
        }
        else if (GetId() == SpellBrandedValarjarGreen)
        {
            odyn->RemoveAura(SpellDrawPowerOnOdynGreen);

            if (target && target->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID)
            {
                odyn->RemoveDynObject(SpellBrandedOdynGreenAT);
                instance->SetData(Data::DataMisc::OdynDeactivatedGreenRune, DONE);
            }
            else
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, target, 300.0f);
                Trinity::Containers::RandomResize(playerList, 4);

                if (playerList.empty())
                    return;

                for (auto& player : playerList)
                {
                    if (Player* players = player->ToPlayer())
                        if (!players->HasAura(SpellBrandedOdynPurple) && !players->HasAura(SpellBrandedOdynGreen) && !players->HasAura(SpellBrandedOdynOrange) && !players->HasAura(SpellBrandedOdynBlue) && !players->HasAura(SpellBrandedOdynYellow))
                            target->AddAura(SpellBrandedOdynGreen, players);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_odyn_branded_event::OnRemove, EFFECT_0, SPELL_AURA_MOD_FIXATE, AURA_EFFECT_HANDLE_REAL);
    }
};

//228162
class spell_shield_of_light_filter : public SpellScript
{
    PrepareSpellScript(spell_shield_of_light_filter);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targetsCount = targets.size();
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (targetsCount)
            SetHitDamage(GetHitDamage() / targetsCount);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shield_of_light_filter::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_THREAT_LIST);
        OnEffectHitTarget += SpellEffectFn(spell_shield_of_light_filter::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//227807
class spell_odyn_storm_of_justice : public SpellScript
{
    PrepareSpellScript(spell_odyn_storm_of_justice);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 count = 0;
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetMap() && (caster->GetMap()->GetDifficultyID() == DIFFICULTY_NORMAL_RAID || caster->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID))
            count = 4;
        else if (caster->GetMap() && (caster->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID))
            count = 5;
        else if (caster->GetMap() && (caster->GetMap()->GetDifficultyID() == DIFFICULTY_LFR))
            count = 2;

        if (targets.size() > count)
            targets.resize(count);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_odyn_storm_of_justice::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//8787,8788,8785,8784,8786
struct at_odyn_tov_branded : AreaTriggerAI
{
    explicit at_odyn_tov_branded(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnUnitExit(Unit* target) override
    {
        if (target->GetEntry() != Data::Creatures::ValarjarRunebearer)
            return;

        target->GetAI()->DoAction(ACTION_1);
    }
};

void AddSC_boss_odyn_tov()
{
    RegisterCreatureAI(boss_tov_odyn);
    RegisterCreatureAI(npc_tov_hymdall);
    RegisterCreatureAI(npc_tov_hyrja);
    RegisterCreatureAI(npc_tov_dancing_blade);
    RegisterCreatureAI(npc_tov_raging_tempest);
    RegisterCreatureAI(npc_tov_spear_of_light);
    RegisterCreatureAI(npc_valarjar_runebearer);
    RegisterAuraScript(spell_odyn_power_regen);
    RegisterAuraScript(spell_odyn_test);
    RegisterAuraScript(spell_odyn_power_regen_mythic);
    RegisterAuraScript(spell_odyn_branded_event);
    RegisterAuraScript(spell_arcing_storm);
    RegisterSpellScript(spell_shield_of_light_filter);
    RegisterSpellScript(spell_odyn_storm_of_justice);
    RegisterAreaTriggerAI(at_odyn_tov_branded);
}

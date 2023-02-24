/*
 * Copyright 2023 AzgathCore
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

#include "antorus.h"
#include "AreaTriggerAI.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    //Argus
    SAY_AGGRO = 0,
    SAY_WARN_WHISPER_SOULBURST = 1,
    SAY_WARN_WHISPER_SOULBOMB = 2,
    SAY_PHASE_3 = 3,
    SAY_GRASP_OF_THE_UNMAKER = 4,
    SAY_WARN_REORIGINATION_MODULE = 5,
    SAY_WARN_SARGERAS_GAZE = 6,

    //Aman'Thul
    SAY_WARN_SKY_AND_SEA = 0,
    SAY_SKY_AND_SEA = 1,
    SAY_PHASE_2 = 2,
    SAY_AVATAR_OF_AGGRAMAR = 3,
    SAY_TEMPORAL_BLAST = 4,
    SAY_REAP_SOUL = 5,

    //Golganneth
    SAY_WARN_WHISPER_SKY = 0,
    SAY_WARN_WHISPER_SEA = 1,

    //Eonar
    SAY_GIFT_OF_THE_LIFEBINDER = 0,
    SAY_GIFT_OF_THE_LIFEBINDER_2 = 1,

    //Soulblight
    SAY_WARN_SOULBLIGHT_DOT = 0,
};

enum Spells
{
    SPELL_OUTRO = 257606,
    SPELL_ARGUS_BONUS_ROLL = 250608,
    SPELL_DAILY_ESSENCE_ARGUS = 305317,

    SPELL_ZERO_ENERGY_REGEN = 72242,
    SPELL_TITANIC_ESSENCE = 258040,
    SPELL_P1_ENERGY_CONTROLLER = 258041,
    SPELL_P2_ENERGY_CONTROLLER = 258042,
    SPELL_P4_ENERGY_CONTROLLER = 258044,
    SPELL_BERSERK = 26662,

    //Phase 1
    SPELL_CONE_OF_DEATH_FILTER = 256457,
    SPELL_CONE_OF_DEATH_AT = 248166,
    SPELL_SUM_SOULBLIGHT_ORB = 248317,
    SPELL_SOULBLIGHT_ORB_AURA = 248376,
    SPELL_SOULBLIGHT_DOT = 248396,
    SPELL_DEATH_FOG_AT = 248290,
    SPELL_TORTURED_RAGE = 257296,
    SPELL_SWEEPING_SCYTHE = 248499,
    SPELL_SKY_AND_SEA = 255594,
    SPELL_GIFT_OF_THE_SKY_AURA = 258646,
    SPELL_GIFT_OF_THE_SKY_MISSILE = 253884,
    SPELL_GIFT_OF_THE_SEA_AURA = 258647,
    SPELL_GIFT_OF_THE_SEA_MISSILE = 253889,
    //Mythic
    SPELL_SARGERAS_GAZE = 258068,
    SPELL_SARGERAS_RAGE_AT = 257869,
    SPELL_SARGERAS_FEAR_AT = 257931,
    SPELL_SARGERAS_FEAR_VISUAL = 258739,
    SPELL_SARGERAS_FEAR_DMG = 257930,
    SPELL_MYTHIC_P1_CLEANUP = 258083, //Remove "Sargeras Gaze"

    //Phase 2
    SPELL_GOLGANNETH_WRATH_DUMMY = 256674,
    SPELL_GOLGANNETH_WRATH_PERSISTENT = 255648,
    SPELL_GOLGANNETH_WRATH_AURA = 255683,
    SPELL_VOLATILE_SOUL_FILTER = 252280, //100 energy
    SPELL_VOLATILE_SOUL_FILTER_2 = 258043, //50 energy
    SPELL_SOULBURST = 250669,
    SPELL_SOULBURST_DETONATION = 251572,
    SPELL_SOULBOMB = 251570,
    SPELL_EDGE_OF_OBLITERATION_SUMMON = 255826,
    SPELL_EDGE_OF_OBLITERATION_VISUAL = 251779,
    SPELL_EDGE_OF_OBLITERATION_FILTER = 252049,
    SPELL_EDGE_OF_OBLITERATION_AT = 252136,
    SPELL_EDGE_OF_OBLITERATION_DMG = 251815,
    SPELL_EDGE_OF_OBLITERATION_CHARGE = 252152,
    SPELL_AVATAR_OF_AGGRAMAR = 255199,
    SPELL_AGGRAMAR_SACRIFICE = 255201,

    //Phase 3
    SPELL_TEMPORAL_BLAST = 257645,
    SPELL_ARGUS_MYTHIC_TRANSFORM = 258104, //Mythic
    SPELL_ARGUS_MYTHIC_HEAL = 259581, //Mythic
    SPELL_P3_ARCANE_DISSOLVE_OUT = 255976,
    SPELL_CANCEL_AVATAR_OF_AGGRAMAR = 259033,
    SPELL_CONSTELLAR_COMBAT_CHECKER = 259210,
    SPELL_STARBLAST = 253061,
    SPELL_COSMIC_RAY_FILTER = 252729,
    SPELL_COSMIC_RAY_DMG = 252707,
    SPELL_COSMIC_BEACON = 252616,
    SPELL_COSMIC_SMASH = 252630,
    SPELL_BLADES_OF_THE_ETERNAL = 255478,
    SPELL_SWORD_OF_THE_COSMOS = 255496,
    SPELL_COSMIC_POWER = 255935,
    SPELL_THE_DISCS_OF_NORGANNON = 252516,
    SPELL_PHYSICAL_VULNERABILITY = 255418,
    SPELL_HOLY_VULNERABILITY = 255419,
    SPELL_NATURE_VULNERABILITY = 255422,
    SPELL_FROST_VULNERABILITY = 255425,
    SPELL_FIRE_VULNERABILITY = 255429,
    SPELL_SHADOW_VULNERABILITY = 255430,
    SPELL_ARCANE_VULNERABILITY = 255433,
    SPELL_IMPENDING_INEVITABILITY = 253026, //Heroic
    SPELL_INEVITABILITY = 253021,

    //Phase 4
    SPELL_REAP_SOUL_DUMMY = 256542,
    SPELL_REAP_SOUL_KILL_PLAYERS = 258399,
    SPELL_GRASP_OF_THE_UNMAKER = 258373,
    SPELL_P4_ARCANE_DISSOLVE_OUT = 256543,
    SPELL_GIFT_OF_THE_LIFEBINDER = 257619,
    SPELL_END_OF_ALL_THINGS = 256544,
    SPELL_GIFT_OF_THE_LIFEBINDER_AT = 256338,
    SPELL_GIFT_OF_THE_LIFEBINDER_SCRIPT = 256351,
    SPELL_LIFE_GIVING_ROOTS = 256398,
    SPELL_WITHERING_ROOTS = 256399,
    SPELL_KHAZGOROTH_ENERGY_BAR = 257213,
    SPELL_TITANFORGING_PERIODIC_REDUCT_ENERGY = 257214,
    SPELL_TITANFORGED_BUFF = 257215,
    SPELL_SOUL_GHOST = 258826,
    SPELL_HUNGERING_SOUL_AT = 256894,
    SPELL_EMBER_OF_RAGE_AURA = 257300,
    SPELL_EMBER_OF_RAGE_MISSILE = 257298,
    SPELL_REORIGINATION_MODULE_AT = 256389,
    SPELL_INITIALIZATION_SEQUENCE = 256388,
    SPELL_INITIALIZATION_SEQUENCE_SELF_DMG = 256397,
    SPELL_REORIGINATION_PULSE = 256396,
    SPELL_REORIGINATION_DISSOLVE_OUT = 256395,
    SPELL_MOTE_GHOST = 9036,
    SPELL_MOTE_OF_TITANIC_POWER_AT = 253569,
    SPELL_MOTE_OF_TITANIC_POWER_ENERGIZE = 253580,
    SPELL_DEADLY_SCYTHE = 258039, //Heroic
    //Mythic
    SPELL_SOULRENDING_SCYTHE = 258838,
    SPELL_RENT_SOUL_FILTER = 258839,
    SPELL_RENT_SOUL_MISSILE = 258939,
    SPELL_APOCALYPSIS_MODULE_FILTER = 258207,
    SPELL_APOCALYPSIS_MODULE_SUMMON = 258206,
    SPELL_APOCALYPSIS_MODULE_AT = 258007,
    SPELL_APOCALYPSIS_MODULE_PERIODIC = 258029,
    SPELL_APOCALYPSIS_MODULE_REMOVE = 258030,
    SPELL_APOCALYPSIS_PULSE = 258038,
    SPELL_APOCALYPSIS_PULSE_DMG = 258037,
    SPELL_APOCALYPSIS_ZONE_AT = 258034,
    SPELL_SENTENCE_OF_SARGERAS_FILTER = 258088,
    SPELL_SENTENCE_OF_SARGERAS_DMG = 257966,
    SPELL_SHATTERED_BONDS = 258000,
    SPELL_EDGE_OF_ANNIHILATION_VISUAL = 258832,
    SPELL_EDGE_OF_ANNIHILATION_CHARGE = 258833,
    SPELL_EDGE_OF_ANNIHILATION_DMG = 258834,

    //Has player
    SPELL_GHOST_TRACKER = 261228,
    SPELL_VULNERABLE_TO_HUNGERING_SOULS = 260022,
    SPELL_BATTLE_SCENE_STATIC = 255219,
};

enum Events
{
    //Phase 1
    EVENT_SUM_SOULBLIGHT_ORB = 1,
    EVENT_TORTURED_RAGE = 2,
    EVENT_SWEEPING_SCYTHE = 3,
    EVENT_SKY_AND_SEA = 4,

    //Phase 2
    EVENT_P2_ENERGY = 5,
    EVENT_EDGE_OF_OBLITERATION = 6,
    EVENT_AVATAR_OF_AGGRAMAR = 7,

    //Phase 3
    EVENT_TEMPORAL_BLAST = 8,
    EVENT_SUMMON_CONSTELLAR = 9,
    EVENT_COSMIC_BEACON = 10,
    EVENT_STAR_ARSENAL = 11,
    EVENT_THE_DISCS_OF_NORGANNON = 12,

    //Phase 4
    EVENT_GIFT_OF_THE_LIFEBINDER = 13,
    EVENT_END_OF_ALL_THINGS = 14,
    EVENT_REORIGINATION_MODULE = 15,

    //Mythic
    EVENT_SARGERAS_GAZE = 16,
    EVENT_APOCALYPSIS_MODULE = 17,
    EVENT_SENTENCE_OF_SARGERAS = 18,
    EVENT_EDGE_OF_ANNIHILATION = 19,
    EVENT_SOULRENDING_SCYTHE = 20
};

enum Misc
{
    PHASE_1 = 0,
    PHASE_2 = 1,
    PHASE_3 = 2,
    PHASE_4 = 3,

    //SMSG_SET_AI_ANIM_KIT
    ANIM_ARGUS_KNEEL = 3647,
    ANIM_ARGUS_REAP_SOUL = 4942,
    ANIM_GIFT = 2133,
    ANIM_MODUL = 2133,

    SUMMON_GROUP_HUNGERING_SOUL = 3,
    DATA_SARGERAS_GAZE,

    ACTION_1,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
};

Position const centrPos = { 2867.12f, -4567.54f, 292.94f };

Position const constellarPos[7] =
{
    {2828.07f, -4553.25f, 292.029f, 5.92f},
    {2856.43f, -4533.67f, 292.027f, 5.00f},
    {2828.72f, -4584.80f, 292.029f, 0.42f},
    {2890.83f, -4538.69f, 292.028f, 4.02f},
    {2852.88f, -4606.91f, 292.029f, 1.22f},
    {2905.77f, -4570.62f, 292.028f, 3.06f},
    {2888.44f, -4600.90f, 292.028f, 2.14f}
};

std::map<uint32, Position> titansPos
{
    { 125885, {2947.36f, -4567.67f, 303.86f, 3.10f} },
    { 125886, {2888.71f, -4496.38f, 296.51f, 4.79f} },
    { 125893, {2923.33f, -4612.22f, 297.24f, 2.59f} },
    { 126266, {2846.21f, -4638.35f, 296.49f, 1.38f} },
    { 126267, {2927.70f, -4523.25f, 300.60f, 3.95f} },
    { 126268, {2845.79f, -4495.85f, 296.42f, 5.09f} }
};

std::vector<uint8> sGazeVector[8]
{
    //Melee: "Rages"    |   Range: "Rages"     |    Random: "Fear"
    {1,                     0,                      1},
    {1,                     0,                      2},
    {1,                     1,                      2},
    {1,                     1,                      3},
    {2,                     1,                      3},
    {2,                     1,                      4},
    {2,                     2,                      4},
    {2,                     2,                      5}
};

uint32 vulnerabilityIDs[7] =
{
    SPELL_FROST_VULNERABILITY,
    SPELL_NATURE_VULNERABILITY,
    SPELL_ARCANE_VULNERABILITY,
    SPELL_HOLY_VULNERABILITY,
    SPELL_SHADOW_VULNERABILITY,
    SPELL_PHYSICAL_VULNERABILITY,
    SPELL_FIRE_VULNERABILITY
};

//124828
struct boss_argus : BossAI
{
    boss_argus(Creature* creature) : BossAI(creature, DATA_ARGUS) {}

    std::list<ObjectGuid> constellarList;
    std::list<uint32> sentenceSargerasTimer;
    ObjectGuid teleporterGUID;
    bool prePhaseFour = false;
    bool saySkyAndSeaSays = false;
    bool sayAvatarOfAggramar = false;
    uint8 phase = 0;
    uint8 healthPct = 0;
    uint8 constellarDiedCount = 0;
    uint8 moduleCount = 0;
    uint8 sargerasGazeCount = 0;
    uint8 edgeAnnihilationCount = 0;
    uint32 checkAliveTimer = 0;
    uint32 sweepingScytheTimer = 0;
    uint32 berserkTimer = 0;

    void Reset() override
    {
        _Reset();
        DoCast(me, SPELL_ZERO_ENERGY_REGEN, true);
        DoCast(me, SPELL_TITANIC_ESSENCE, true);
        me->SetPower(me->GetPowerType(), 0);
        prePhaseFour = false;
        saySkyAndSeaSays = false;
        sayAvatarOfAggramar = false;
        phase = PHASE_1;
        healthPct = 70;
        constellarDiedCount = 0;
        sargerasGazeCount = 0;
        edgeAnnihilationCount = 0;
        checkAliveTimer = 0;
        berserkTimer = 0;
        sentenceSargerasTimer = { 57000, 60000, 53000 };

        for (auto pair : titansPos)
            me->SummonCreature(pair.first, pair.second);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        DoCast(me, SPELL_P1_ENERGY_CONTROLLER, true);
        DefaultEvents();
        berserkTimer = (IsMythicRaid() ? 660 : 720) * IN_MILLISECONDS;
        SetVisibleTeleporter(false);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        //RemoveDebuffs();
        SetVisibleTeleporter(true);

        me->GetMap()->LoadGrid(3092.1f, -9635.22f);

        AddDelayedEvent(1000, [this]() -> void
        {
            instance->DoCastSpellOnPlayers(SPELL_OUTRO);

            instance->DoOnPlayers([](Player* player)
            {
                player->NearTeleportTo(3112.587f, -9635.071f, 62.3f, player->GetOrientation());
            });
        });
    }

    void EnterEvadeMode(EvadeReason w)
    {
        me->NearTeleportTo(me->GetHomePosition());
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetDisplayId(me->GetNativeDisplayId());
        //RemoveDebuffs();
        SetVisibleTeleporter(true);

        //Repop ghost players
        instance->DoOnPlayers([](Player* player)
        {
            if (!player->IsAlive() && player->HasAura(8326))
                player->RepopAtGraveyard();
        });
    }

    void DefaultEvents()
    {
        switch (phase)
        {
        case PHASE_1:
            if (!IsLFR())
                events.RescheduleEvent(EVENT_SUM_SOULBLIGHT_ORB, 35000);
            events.RescheduleEvent(EVENT_TORTURED_RAGE, 12000);
            sweepingScytheTimer = 8200; //Need check
            events.RescheduleEvent(EVENT_SWEEPING_SCYTHE, 6000);
            events.RescheduleEvent(EVENT_SKY_AND_SEA, 11000);
            if (IsMythicRaid())
                events.RescheduleEvent(EVENT_SARGERAS_GAZE, 8500);
            break;
        case PHASE_2:
            events.RescheduleEvent(EVENT_P2_ENERGY, 16000);
            sweepingScytheTimer = 8200; //Need check
            events.RescheduleEvent(EVENT_SWEEPING_SCYTHE, 16500);
            events.RescheduleEvent(EVENT_EDGE_OF_OBLITERATION, 21000);
            events.RescheduleEvent(EVENT_AVATAR_OF_AGGRAMAR, 21000);
            if (IsMythicRaid())
                events.RescheduleEvent(EVENT_SARGERAS_GAZE, 32000);
            break;
        case PHASE_3:
            events.RescheduleEvent(EVENT_TEMPORAL_BLAST, 12000);
            break;
        case PHASE_4:
            if (IsMythicRaid())
            {
                events.RescheduleEvent(EVENT_SARGERAS_GAZE, 20000);
                events.RescheduleEvent(EVENT_APOCALYPSIS_MODULE, 30000);
                events.RescheduleEvent(EVENT_TORTURED_RAGE, 40000);
                events.RescheduleEvent(EVENT_SENTENCE_OF_SARGERAS, 53000);
                events.RescheduleEvent(EVENT_EDGE_OF_ANNIHILATION, 5000);
                events.RescheduleEvent(EVENT_SOULRENDING_SCYTHE, 4000);
            }
            else
            {
                DoCast(me, SPELL_P4_ENERGY_CONTROLLER, true);
                DoCast(me, SPELL_EMBER_OF_RAGE_AURA, true);
                moduleCount = 3;
                events.RescheduleEvent(EVENT_REORIGINATION_MODULE, 13000);
                events.RescheduleEvent(EVENT_TORTURED_RAGE, 10000);
                sweepingScytheTimer = 8200;
                events.RescheduleEvent(EVENT_SWEEPING_SCYTHE, 5200);
            }
            break;
        }
    }

    void RemoveDebuffs()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AVATAR_OF_AGGRAMAR);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GRASP_OF_THE_UNMAKER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GHOST_TRACKER);

        if (IsMythicRaid())
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SARGERAS_RAGE_AT);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SARGERAS_FEAR_AT);
        }
    }

    void SetVisibleTeleporter(bool visible)
    {
        if (teleporterGUID.IsEmpty())
            if (auto teleporter = me->FindNearestCreature(128304, 100.0f))
                teleporterGUID = teleporter->GetGUID();

        if (auto teleporter = instance->instance->GetCreature(teleporterGUID))
            teleporter->SetVisible(visible);
    };

    void DamageTaken(Unit* /*attacker*/, uint32& damage)
    {
        if (me->HealthBelowPct(healthPct))
        {
            healthPct = healthPct == 70 ? 40 : 0;
            ++phase;
            events.Reset();

            if (phase == PHASE_2)
            {
                if (auto amanthul = instance->GetCreature(NPC_ARGUS_AMANTHUL))
                {
                    amanthul->AI()->ZoneTalk(SAY_PHASE_2, nullptr);
                }
                if (auto golganneth = instance->GetCreature(NPC_ARGUS_GOLGANNETH))
                {
                    golganneth->CastSpell(golganneth, SPELL_GOLGANNETH_WRATH_DUMMY, true);
                }
                AddDelayedCombat(5000, [this]() -> void { me->RemoveAllAreaObjects(); });
                me->RemoveAurasDueToSpell(SPELL_P1_ENERGY_CONTROLLER);
                DefaultEvents();
            }
            else if (phase == PHASE_3)
            {
                Talk(SAY_PHASE_3);
                me->AttackStop();
                me->RemoveAurasDueToSpell(SPELL_P2_ENERGY_CONTROLLER);
                me->GetMotionMaster()->MovePoint(1, me->GetHomePosition(), false);
            }
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        { 
            prePhaseFour = true;
        checkAliveTimer = 1000;
        me->SetFacingTo(0.0f);
        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
        me->RemoveAllAuras();
        //me->SetAnimKitId(ANIM_ARGUS_KNEEL);
        summons.DespawnEntry(NPC_EDGE_OF_OBLITERATION);
        DefaultEvents();
        }
   
    }

    void OnInterruptCast(Unit* /*caster*/, uint32 /*spellId*/, uint32 curSpellID, uint32 /*schoolMask*/)
    {
        if (curSpellID == SPELL_END_OF_ALL_THINGS)
        {
            prePhaseFour = false;
            me->SetReactState(REACT_AGGRESSIVE);
            DefaultEvents();
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_GRASP_OF_THE_UNMAKER:
            ZoneTalk(SAY_GRASP_OF_THE_UNMAKER, nullptr);
            break;
        case SPELL_REAP_SOUL_DUMMY:
        {
            if (auto amanthul = instance->GetCreature(NPC_ARGUS_AMANTHUL))
            {
                amanthul->AI()->ZoneTalk(SAY_REAP_SOUL, nullptr);
            }
            if (auto khazgoroth = instance->GetCreature(NPC_ARGUS_KHAZGOROTH))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, khazgoroth);
                khazgoroth->CastSpell(khazgoroth, SPELL_KHAZGOROTH_ENERGY_BAR, true);
            }
            me->CastSpell(me, SPELL_REAP_SOUL_KILL_PLAYERS, true);
            break;
        }
        case SPELL_REAP_SOUL_KILL_PLAYERS:
            me->CastSpell(me, SPELL_P4_ARCANE_DISSOLVE_OUT, false);
            events.RescheduleEvent(EVENT_GIFT_OF_THE_LIFEBINDER, 10000);
            events.RescheduleEvent(EVENT_END_OF_ALL_THINGS, 20000);
            break;
        case SPELL_P3_ARCANE_DISSOLVE_OUT:
            AddDelayedCombat(6000, [this]() -> void {
                if (IsMythicRaid())
                    PrepareEventsPhaseFour();
            });
            break;
        case SPELL_P4_ARCANE_DISSOLVE_OUT:
            //me->SetAnimKitId(0);
            me->SetDisplayId(11686);
            break;
        case SPELL_END_OF_ALL_THINGS:
            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
            break;
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_TEMPORAL_BLAST)
        {
            me->SetDisableGravity(true);
            DoCast(me, SPELL_CANCEL_AVATAR_OF_AGGRAMAR, true);

            if (IsMythicRaid())
            {
                DoCast(me, SPELL_MYTHIC_P1_CLEANUP, true);
                DoCast(me, SPELL_ARGUS_MYTHIC_TRANSFORM, true);

                for (uint8 i = 0; i < 2; ++i)
                    DoCast(me, SPELL_ARGUS_MYTHIC_HEAL, true);

                //me->SetAnimKitId(0);
                //me->PlayOneShotAnimKit(5179);
                me->CastSpell(me, SPELL_P3_ARCANE_DISSOLVE_OUT, true);
                return;
            }
            else
                DoCast(me, SPELL_P3_ARCANE_DISSOLVE_OUT, true);

            events.RescheduleEvent(EVENT_SUMMON_CONSTELLAR, 4000);
            events.RescheduleEvent(EVENT_COSMIC_BEACON, 29000);
            events.RescheduleEvent(EVENT_STAR_ARSENAL, 14000);
            events.RescheduleEvent(EVENT_THE_DISCS_OF_NORGANNON, 4100);
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_GRASP_OF_THE_UNMAKER:
            if (target->IsPlayer())
                target->GetMotionMaster()->MoveCharge(2867.12f, -4567.54f, 296.58f, 20.0f);
            break;
        case SPELL_SOULBURST:
            Talk(SAY_WARN_WHISPER_SOULBURST, target);
            break;
        case SPELL_SOULBOMB:
            Talk(SAY_WARN_WHISPER_SOULBOMB, target);
            break;
        }
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (instance->GetBossState(DATA_ARGUS) != IN_PROGRESS || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_SOULBURST:
            target->CastSpell(target, SPELL_SOULBURST_DETONATION, true);
            break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_CONSTELLAR_DESIGNATE)
        {
            constellarList.remove(summon->GetGUID());

            if (++constellarDiedCount == 7)
                PrepareEventsPhaseFour();
        }
    }

    void PrepareEventsPhaseFour()
    {
        events.Reset();
        phase = PHASE_4;
        me->SummonCreatureGroup(SUMMON_GROUP_HUNGERING_SOUL);
        me->SetFacingTo(0.0f);
        me->RemoveAurasDueToSpell(SPELL_P3_ARCANE_DISSOLVE_OUT);
        //me->SetAnimKitId(ANIM_ARGUS_REAP_SOUL);
        //me->AddDelayedCombat(4000, [this]() -> void
        
        instance->DoOnPlayers([](Player* player)
        {
            if (!player->IsAlive())
            {
                player->ResurrectPlayer(1.0f);
                player->SpawnCorpseBones();
            }
        });
       
        me->CastSpell(me, SPELL_REAP_SOUL_DUMMY, false);
        me->CastSpell(me, SPELL_GRASP_OF_THE_UNMAKER, true);
        AddDelayedCombat(10000, [this]() -> void
        {
            me->GetMotionMaster()->MoveJump(2843.37f, -4567.70f, 291.94f, 30.0f, 0.0f);
            me->SetDisableGravity(false);
        });
    }

    void EdgeAnnihilation()
    {
        ++edgeAnnihilationCount;

        if (edgeAnnihilationCount == 1)
            events.RescheduleEvent(EVENT_EDGE_OF_ANNIHILATION, 90000);
        else if (edgeAnnihilationCount == 2)
            events.RescheduleEvent(EVENT_EDGE_OF_ANNIHILATION, 45000);

        Position pos;
        float angle = frand(0.0f, 6.28f);

        for (uint8 i = 0; i < 16; ++i)
        {
            //centrPos.SimplePosXYRelocationByAngle(pos, 45.0f, angle);
            angle += 0.3925f;

            if (i < 8)
                me->SummonCreature(NPC_EDGE_OF_ANNIHILATION, pos);
            else
                me->SummonCreature(NPC_EDGE_OF_ANNIHILATION, pos);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;
                me->CastSpell(me, SPELL_BERSERK, true);
            }
            else
                berserkTimer -= diff;
        }

        if (checkAliveTimer)
        {
            if (checkAliveTimer <= diff)
            {
                checkAliveTimer = 0;

                instance->DoOnPlayers([this](Player* player)
                {
                    if ((prePhaseFour || player->IsAlive()) && player->GetDistance(centrPos) < 50.0f)
                        checkAliveTimer = 1000;
                });

                if (!checkAliveTimer)
                {
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    return;
                }
            }
            else
                checkAliveTimer -= diff;
        }

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SUM_SOULBLIGHT_ORB:
                DoCast(SPELL_SUM_SOULBLIGHT_ORB);
                events.RescheduleEvent(EVENT_SUM_SOULBLIGHT_ORB, 25000);
                break;
            case EVENT_TORTURED_RAGE:
                DoCast(SPELL_TORTURED_RAGE);
                if (IsMythicRaid() && phase == PHASE_4)
                    events.RescheduleEvent(EVENT_TORTURED_RAGE, 40000);
                else
                    events.RescheduleEvent(EVENT_TORTURED_RAGE, 13400);
                break;
            case EVENT_SWEEPING_SCYTHE:
                if (IsHeroicRaid())
                    me->CastSpell(me->GetVictim(), SPELL_DEADLY_SCYTHE);
                else
                    me->CastSpell(me->GetVictim(), SPELL_SWEEPING_SCYTHE);
                events.RescheduleEvent(EVENT_SWEEPING_SCYTHE, sweepingScytheTimer);
                sweepingScytheTimer = sweepingScytheTimer > 6200 ? 6200 : 7200;
                break;
            case EVENT_SKY_AND_SEA:
                if (auto amanthul = instance->GetCreature(NPC_ARGUS_AMANTHUL))
                {
                    amanthul->AI()->ZoneTalk(SAY_WARN_SKY_AND_SEA, nullptr);
                    if (!saySkyAndSeaSays)
                    {
                        saySkyAndSeaSays = true;
                        amanthul->AI()->ZoneTalk(SAY_SKY_AND_SEA, nullptr);
                    }
                }
                if (auto golganneth = instance->GetCreature(NPC_ARGUS_GOLGANNETH))
                    golganneth->CastSpell(golganneth, SPELL_SKY_AND_SEA);
                events.RescheduleEvent(EVENT_SKY_AND_SEA, 25000);
                break;
            case EVENT_P2_ENERGY:
                me->SetPower(me->GetPowerType(), 70);
                DoCast(me, SPELL_P2_ENERGY_CONTROLLER, true);
                break;
            case EVENT_EDGE_OF_OBLITERATION:
                me->CastSpell(centrPos, SPELL_EDGE_OF_OBLITERATION_SUMMON, false);
                events.RescheduleEvent(EVENT_EDGE_OF_OBLITERATION, 34000);
                break;
            case EVENT_AVATAR_OF_AGGRAMAR:
                if (!sayAvatarOfAggramar)
                {
                    sayAvatarOfAggramar = true;

                    if (auto amanthul = instance->GetCreature(NPC_ARGUS_AMANTHUL))
                        amanthul->AI()->ZoneTalk(SAY_AVATAR_OF_AGGRAMAR, nullptr);
                }
                if (auto target = SelectTarget(SELECT_TARGET_MAXTHREAT, 0, 100.0f, true))
                    target->CastSpell(target, SPELL_AVATAR_OF_AGGRAMAR, true);
                break;
            case EVENT_TEMPORAL_BLAST:
                if (auto amanthul = instance->GetCreature(NPC_ARGUS_AMANTHUL))
                {
                    amanthul->AI()->ZoneTalk(SAY_TEMPORAL_BLAST, nullptr);
                    amanthul->CastSpell(me, SPELL_TEMPORAL_BLAST);
                }
                break;
            case EVENT_SUMMON_CONSTELLAR:
            {
                constellarList.clear();

                for (uint8 i = 0; i < 7; ++i)
                {
                    if (auto constellar = me->SummonCreature(NPC_CONSTELLAR_DESIGNATE, constellarPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000))
                    {
                        constellarList.push_back(constellar->GetGUID());
                        constellar->AI()->DoAction(vulnerabilityIDs[i]);
                    }
                }
                break;
            }
            case EVENT_COSMIC_BEACON:
            {
                std::list<ObjectGuid> tempList = constellarList;
                tempList.remove_if([this](ObjectGuid guid) -> bool
                {
                    if (guid.IsEmpty())
                        return true;

                    if (auto constellar = instance->instance->GetCreature(guid))
                        if (constellar->HasAura(SPELL_SWORD_OF_THE_COSMOS) || constellar->HasAura(SPELL_BLADES_OF_THE_ETERNAL))
                            return true;

                    return false;
                });
                Trinity::Containers::RandomResize(tempList, IsHeroicPlusRaid() ? 3 : 2);
                for (auto guid : tempList)
                {
                    if (auto constellar = instance->instance->GetCreature(guid))
                        constellar->AI()->DoAction(ACTION_1);
                }
                events.RescheduleEvent(EVENT_COSMIC_BEACON, IsHeroicPlusRaid() ? 20000 : 30000);
                break;
            }
            case EVENT_STAR_ARSENAL:
            {
                std::list<ObjectGuid> tempList = constellarList;
                Trinity::Containers::RandomResize(tempList, 2);
                for (auto actionId : { SPELL_BLADES_OF_THE_ETERNAL, SPELL_SWORD_OF_THE_COSMOS })
                {
                    if (tempList.empty())
                        return;

                    if (auto constellar = instance->instance->GetCreature(tempList.front()))
                        constellar->AI()->DoAction(actionId);

                    tempList.remove(tempList.front());
                }
                if (IsHeroicRaid())
                    events.RescheduleEvent(EVENT_STAR_ARSENAL, 40500);
                break;
            }
            case EVENT_THE_DISCS_OF_NORGANNON:
                if (auto norgannon = instance->GetCreature(NPC_ARGUS_NORGANNON))
                    norgannon->CastSpell(me, SPELL_THE_DISCS_OF_NORGANNON);
                break;
            case EVENT_GIFT_OF_THE_LIFEBINDER:
                if (auto eonar = instance->GetCreature(NPC_ARGUS_EONAR))
                {
                    eonar->AI()->ZoneTalk(SAY_GIFT_OF_THE_LIFEBINDER, nullptr);
                    eonar->CastSpell(eonar, SPELL_GIFT_OF_THE_LIFEBINDER);
                }
                break;
            case EVENT_END_OF_ALL_THINGS:
            {
                me->SummonCreature(NPC_GIFT_OF_THE_LIFEBINDER, 2893.734f, -4545.361f, 292.02f, 3.77f, TEMPSUMMON_DEAD_DESPAWN);
                me->RemoveAurasDueToSpell(SPELL_P4_ARCANE_DISSOLVE_OUT);
                me->SetDisplayId(me->GetNativeDisplayId());
                me->SetPower(me->GetPowerType(), IsMythicRaid() ? 0 : 75);
                AddDelayedCombat(1000, [this]() -> void
                {
                    instance->DoCastSpellOnPlayers(SPELL_GHOST_TRACKER);
                });
                AddDelayedCombat(4000, [this]() -> void
                {
                    //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                    me->CastSpell(me, SPELL_END_OF_ALL_THINGS);
                });
                break;
            }
            case EVENT_REORIGINATION_MODULE:
            {
                Talk(SAY_WARN_REORIGINATION_MODULE);
                Position pos;
                float angle = 0.0f;
                for (uint8 i = 0; i < moduleCount; ++i)
                {
                    //centrPos.SimplePosXYRelocationByAngle(pos, 40.0f, angle);
                    me->SummonCreature(NPC_REORIGINATION_MODULE, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + 5.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN);
                    angle += 6.28f / moduleCount;
                }
                ++moduleCount;
                events.RescheduleEvent(EVENT_REORIGINATION_MODULE, 50000);
                break;
            }
            case EVENT_SARGERAS_GAZE:
                if (sargerasGazeCount < 8)
                    ++sargerasGazeCount;
                ZoneTalk(SAY_WARN_SARGERAS_GAZE, nullptr);
                me->CastSpell(me, SPELL_MYTHIC_P1_CLEANUP, true);
                me->CastSpell(me, SPELL_SARGERAS_GAZE, true);
                events.RescheduleEvent(EVENT_SARGERAS_GAZE, phase == PHASE_2 ? 60000 : 35000);
                break;
            case EVENT_APOCALYPSIS_MODULE:
                me->CastSpell(me, SPELL_APOCALYPSIS_MODULE_FILTER, true);
                events.RescheduleEvent(EVENT_APOCALYPSIS_MODULE, 46000);
                break;
            case EVENT_SENTENCE_OF_SARGERAS:
                me->CastSpell(me, SPELL_SENTENCE_OF_SARGERAS_FILTER, true);
                events.RescheduleEvent(EVENT_SENTENCE_OF_SARGERAS, sentenceSargerasTimer.front());
                if (sentenceSargerasTimer.size() > 1)
                    sentenceSargerasTimer.pop_front();
                break;
            case EVENT_EDGE_OF_ANNIHILATION:
                EdgeAnnihilation();
                break;
            case EVENT_SOULRENDING_SCYTHE:
                me->CastSpell(me->GetVictim(), SPELL_SOULRENDING_SCYTHE);
                events.RescheduleEvent(EVENT_SOULRENDING_SCYTHE, 8500);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//126268, 125886, 125893, 126266, 126267
struct npc_argus_titans_generic : ScriptedAI
{
    explicit npc_argus_titans_generic(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_ZERO_ENERGY_REGEN, true);
        me->SetPower(me->GetPowerType(), 0);

        switch (me->GetEntry())
        {
        case NPC_ARGUS_AMANTHUL:
        case NPC_ARGUS_NORGANNON:
        case NPC_ARGUS_GOLGANNETH:
            //me->SetAnimKitId(11572);
            break;
        case NPC_ARGUS_KHAZGOROTH:
            //me->SetAnimKitId(9901);
            break;
        case NPC_ARGUS_AGGRAMAR:
           // me->SetAnimKitId(11573);
            break;
        case NPC_ARGUS_EONAR:
            //me->SetAnimKitId(9568);
            break;
        }
    }

    void Reset() override {}

    void JustEngagedWith(Unit* who) override {}

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_GOLGANNETH_WRATH_PERSISTENT:
            if (auto owner = me->GetOwner())
                owner->AddAura(SPELL_GOLGANNETH_WRATH_AURA, me);
            break;
        case SPELL_GIFT_OF_THE_LIFEBINDER:
            ZoneTalk(SAY_GIFT_OF_THE_LIFEBINDER_2, nullptr);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_GIFT_OF_THE_SKY_AURA)
            ZoneTalk(SAY_WARN_WHISPER_SKY, target);

        if (spell->Id == SPELL_GIFT_OF_THE_SEA_AURA)
            ZoneTalk(SAY_WARN_WHISPER_SEA, target);
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (instance->GetBossState(DATA_ARGUS) != IN_PROGRESS || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_GIFT_OF_THE_SKY_AURA:
            if (auto owner = me->GetOwner())
                me->CastSpell(target, SPELL_GIFT_OF_THE_SKY_MISSILE, true);
            break;
        case SPELL_GIFT_OF_THE_SEA_AURA:
            if (auto owner = me->GetOwner())
                me->CastSpell(target, SPELL_GIFT_OF_THE_SEA_MISSILE, true);
            break;
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//125008
struct npc_argus_soulblight_orb : ScriptedAI
{
    explicit npc_argus_soulblight_orb(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_SOULBLIGHT_ORB_AURA, true);
    }

    void Reset() override {}

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SOULBLIGHT_DOT)
            ZoneTalk(SAY_WARN_SOULBLIGHT_DOT, target);
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        if (spellId == SPELL_SOULBLIGHT_ORB_AURA)
        {
            if (auto owner = me->GetOwner())
                me->CastSpell(me, SPELL_DEATH_FOG_AT, true);

            me->DespawnOrUnsummon(500);
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//126828, 130842
struct npc_arugs_edge_of_obliteration : ScriptedAI
{
    explicit npc_arugs_edge_of_obliteration(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        IsMythicEdge = me->GetEntry() == NPC_EDGE_OF_ANNIHILATION;
    }

    Position pos;
    bool IsMythicEdge = false;
    uint32 filterTimer = 0;
    uint32 chargeTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        if (IsMythicEdge)
        {
            me->SetFacingTo(me->GetAngle(centrPos.GetPositionX(), centrPos.GetPositionY()));
            DoCast(me, SPELL_EDGE_OF_ANNIHILATION_VISUAL, true);
            chargeTimer = 10000;
        }
        else
        {
            DoCast(me, SPELL_EDGE_OF_OBLITERATION_VISUAL, true);
            filterTimer = 4500;
        }
    }

    void Reset() override {}

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_EDGE_OF_OBLITERATION_FILTER)
        {
            float angle = me->GetRelativeAngle(target);
            me->GetNearPosition(70.0f, angle);

            if (centrPos.GetExactDist2d(&pos) > 50.0f)
            {
                me->GetNearPosition(50.0f, angle);
            }
            me->SetFacingTo(me->GetAngle(pos.GetPositionX(), pos.GetPositionY()));
            DoCast(me, SPELL_EDGE_OF_OBLITERATION_AT, true);
            chargeTimer = 8000;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (filterTimer)
        {
            if (filterTimer <= diff)
            {
                filterTimer = 10000;
                DoCast(me, SPELL_EDGE_OF_OBLITERATION_FILTER, true);
            }
            else
                filterTimer -= diff;
        }

        if (chargeTimer)
        {
            if (chargeTimer <= diff)
            {
                chargeTimer = 0;

                if (IsMythicEdge)
                {
                    me->GetNearPosition(90.0f, 0.0f);
                    me->CastSpell(pos, SPELL_EDGE_OF_ANNIHILATION_DMG, true);
                    me->CastSpell(pos, SPELL_EDGE_OF_ANNIHILATION_CHARGE, true);
                    AddDelayedEvent(3000, [this]() -> void { me->DespawnOrUnsummon(); });
                }
                else
                {
                    me->CastSpell(pos, SPELL_EDGE_OF_OBLITERATION_DMG, true);
                    me->CastSpell(pos, SPELL_EDGE_OF_OBLITERATION_CHARGE, true);
                }
            }
            else
                chargeTimer -= diff;
        }
    }
};

//127192
struct npc_argus_constellar_designate : ScriptedAI
{
    explicit npc_argus_constellar_designate(Creature* creature) : ScriptedAI(creature)
    {
        me->AddUnitState(UNIT_STATE_ROOT);
        me->SetReactState(REACT_PASSIVE);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    EventMap events;
    bool specialAbility = false;
    uint32 JustEngagedWith = 0;
    uint32 vulnerabilityID = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_ZERO_ENERGY_REGEN, true);

        if (IsHeroicPlusRaid())
            DoCast(me, SPELL_IMPENDING_INEVITABILITY, true);

        JustEngagedWith = 5000;
    }

    void Reset() override {}

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_THE_DISCS_OF_NORGANNON)
            me->CastSpell(me, vulnerabilityID, true);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_COSMIC_BEACON)
            me->CastSpell(target, SPELL_COSMIC_SMASH, true);
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (spellId == SPELL_COSMIC_RAY_FILTER)
            me->CastSpell(target, SPELL_COSMIC_RAY_DMG, true);
    }

    void OnInterruptCast(Unit* /*caster*/, uint32 /*spellId*/, uint32 curSpellID, uint32 /*schoolMask*/)
    {
        if (IsHeroicPlusRaid())
            me->CastSpell(me, SPELL_INEVITABILITY, true);
    }

    void DoAction(int32 const actionId)
    {
        switch (actionId)
        {
        case ACTION_1:
            events.RescheduleEvent(EVENT_3, 100);
            break;
        case SPELL_BLADES_OF_THE_ETERNAL:
            events.Reset();
            events.RescheduleEvent(EVENT_4, 100);
            me->ClearUnitState(UNIT_STATE_ROOT);
            SetEquipmentSlots(false, 45985, 45985, 0);
            break;
        case SPELL_SWORD_OF_THE_COSMOS:
            events.Reset();
            events.RescheduleEvent(EVENT_5, 100);
            events.RescheduleEvent(EVENT_6, 10500);
            me->ClearUnitState(UNIT_STATE_ROOT);
            SetEquipmentSlots(false, 113093, 0, 0);
            break;
        default:
            break;
        }

        for (uint8 i = 0; i < 7; ++i)
            if (actionId == vulnerabilityIDs[i])
                vulnerabilityID = actionId;
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        if (spellId == SPELL_BLADES_OF_THE_ETERNAL || spellId == SPELL_SWORD_OF_THE_COSMOS)
        {
            specialAbility = false;
            events.Reset();
            events.RescheduleEvent(EVENT_1, 100);
            events.RescheduleEvent(EVENT_2, 9000);
            me->AddUnitState(UNIT_STATE_ROOT);
            SetEquipmentSlots(false, 0, 0, 0);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (JustEngagedWith)
        {
            if (JustEngagedWith <= diff)
            {
                JustEngagedWith = 0;
                me->CastSpell(me, SPELL_CONSTELLAR_COMBAT_CHECKER);
                me->SetReactState(REACT_AGGRESSIVE);

                events.RescheduleEvent(EVENT_1, 100);
                events.RescheduleEvent(EVENT_2, 9000);
            }
            else
                JustEngagedWith -= diff;
        }

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    DoCast(target, SPELL_STARBLAST);
                events.RescheduleEvent(EVENT_1, 2000);
                break;
            case EVENT_2:
                DoCast(SPELL_COSMIC_RAY_FILTER);
                events.RescheduleEvent(EVENT_2, 18000); //unk
                break;
            case EVENT_3:
                DoCast(SPELL_COSMIC_BEACON);
                break;
            case EVENT_4:
                specialAbility = true;
                DoCast(me, SPELL_BLADES_OF_THE_ETERNAL, true);
                break;
            case EVENT_5:
                specialAbility = true;
                DoCast(me, SPELL_SWORD_OF_THE_COSMOS, true);
                break;
            case EVENT_6:
                DoCast(SPELL_COSMIC_POWER);
                events.RescheduleEvent(EVENT_6, 24000);
                break;
            }
        }

        if (specialAbility)
            DoMeleeAttackIfReady();
    }
};

//129386
struct npc_argus_gift_of_the_lifebinder : ScriptedAI
{
    explicit npc_argus_gift_of_the_lifebinder(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        instance = me->GetInstanceScript();
        me->SetRegenerateHealth(false);
    }

    InstanceScript* instance;
    uint32 playersCount = 0;
    int32 powerCount = 0;
    float tickCount = 0.0f;

    void IsSummonedBy(Unit* summoner) override
    {
        playersCount = me->GetMap()->GetPlayersCountExceptGMs();
        if (playersCount < 10)
            playersCount = 10;

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        //me->SetAnimKitId(ANIM_GIFT);
        me->CastSpell(me, SPELL_ZERO_ENERGY_REGEN, true);
        me->CastSpell(me, SPELL_GIFT_OF_THE_LIFEBINDER_AT, true);
        me->CastSpell(me, SPELL_LIFE_GIVING_ROOTS, true);
        powerCount = me->GetPower(me->GetPowerType());
    }

    void Reset() override {}

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_GIFT_OF_THE_LIFEBINDER_SCRIPT)
        {
            if (!target->IsAlive())
            {
                target->ToPlayer()->ResurrectPlayer(1.0f);
                target->ToPlayer()->SpawnCorpseBones();

                if (powerCount)
                {
                    tickCount = (100.0f / playersCount) - 0.5f;
                    powerCount -= tickCount;

                    if (powerCount <= 0)
                        powerCount = 0;

                    me->SetPower(me->GetPowerType(), powerCount);
                }
                else
                    me->CastSpell(me, SPELL_WITHERING_ROOTS, true);
            }
        }
    }

    void UpdateAI(uint32 diff) override {}
};

//129635
struct npc_argus_hungering_soul : ScriptedAI
{
    explicit npc_argus_hungering_soul(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(11686);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(me, SPELL_SOUL_GHOST, true);
        DoCast(me, SPELL_HUNGERING_SOUL_AT, true);
        me->GetMotionMaster()->MoveRandom(15.0f);
        me->SetDisplayId(me->GetNativeDisplayId());
    }

    void Reset() override {}

    void UpdateAI(uint32 diff) override {}
};

//127809, 130179
struct npc_argus_reorigination_module : ScriptedAI
{
    explicit npc_argus_reorigination_module(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetRegenerateHealth(false);
        isMythicModule = me->GetEntry() == NPC_APOCALYPSIS_MODULE;
    }

    bool isMythicModule = false;
    bool pulse = false;
    uint32 startTimer = 0;
    float apocalypsisSize = 0.0f;

    void IsSummonedBy(Unit* summoner) override
    {
        if (isMythicModule)
        {
            me->CastSpell(me, SPELL_APOCALYPSIS_MODULE_AT, true);
            me->CastSpell(me, SPELL_APOCALYPSIS_MODULE_PERIODIC, true);
        }
        else
        {
            //me->SetAnimKitId(ANIM_MODUL);
            startTimer = 3500;
        }
    }

    void Reset() override {}

    void DamageTaken(Unit* /*attacker*/, uint32& damage) 
    {
        if (damage >= me->GetHealth())
        {
            damage = 0;
            ReoriginationPulse();
        }
    }

    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
    {
        if (apply || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_INITIALIZATION_SEQUENCE:
        case SPELL_APOCALYPSIS_MODULE_PERIODIC:
            ReoriginationPulse();
            break;
        case SPELL_REORIGINATION_DISSOLVE_OUT:
            me->DespawnOrUnsummon();
            break;
        }
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        switch (spell->Id)
        {
        case SPELL_REORIGINATION_PULSE:
        case SPELL_APOCALYPSIS_MODULE_REMOVE:
        {
            if (isMythicModule)
            {
                me->CastSpell(me, SPELL_APOCALYPSIS_PULSE, true);
                me->CastSpell(me, SPELL_APOCALYPSIS_PULSE_DMG, true);
                me->CastSpell(me, SPELL_APOCALYPSIS_ZONE_AT, true);
            }
            else
            {
                me->CastSpell(me, SPELL_REORIGINATION_DISSOLVE_OUT, true);
                me->SetDisplayId(11686);
            }

            if (auto owner = me->GetOwner())
            {
                Position pos;
                for (uint8 i = 0; i < 5; ++i)
                {
                    //centrPos.SimplePosXYRelocationByAngle(pos, frand(5.0f, 40.0f), frand(0.0f, 6.28f));
                    owner->SummonCreature(NPC_MOTE_OF_TITANIC_POWER, pos);
                }
            }
            break;
        }
        }
    }

    void ReoriginationPulse()
    {
        if (pulse)
            return;

        pulse = true;

       // me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
        me->RemoveAllAuras();

        if (isMythicModule)
        {
            me->RemoveAurasDueToSpell(SPELL_APOCALYPSIS_MODULE_PERIODIC);
            me->CastSpell(me, SPELL_APOCALYPSIS_MODULE_REMOVE);
        }
        else
        {
            me->RemoveAurasDueToSpell(SPELL_INITIALIZATION_SEQUENCE);
            me->CastSpell(me, SPELL_REORIGINATION_PULSE);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (startTimer)
        {
            if (startTimer <= diff)
            {
                startTimer = 0;
                me->CastSpell(me, SPELL_REORIGINATION_MODULE_AT, true);
                me->CastSpell(me, SPELL_INITIALIZATION_SEQUENCE, true);
            }
            else
                startTimer -= diff;
        }
    }
};

//129722
struct npc_argus_mote_of_titanic_power : ScriptedAI
{
    explicit npc_argus_mote_of_titanic_power(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    bool energize = false;

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, SPELL_MOTE_GHOST, true);
        me->CastSpell(me, SPELL_MOTE_OF_TITANIC_POWER_AT, true);
    }

    void Reset() override {}

    void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId)
    {
        if (energize || target->IsAlive())
            return;

        if (spellId == SPELL_MOTE_OF_TITANIC_POWER_ENERGIZE)
        {
            energize = true;
            me->RemoveAurasDueToSpell(SPELL_MOTE_OF_TITANIC_POWER_AT);
            me->CastSpell(me, spellId, true);
            me->SetDisplayId(11686);
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_MOTE_OF_TITANIC_POWER_ENERGIZE)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override {}
};

//130202
struct npc_argus_chains_of_sargeras : ScriptedAI
{
    explicit npc_argus_chains_of_sargeras(Creature* creature) : ScriptedAI(creature)
    {
        instance = me->GetInstanceScript();
        me->SetReactState(REACT_PASSIVE);
    }

    InstanceScript* instance;
    uint32 checkTimer = 0;

    void IsSummonedBy(Unit* summoner) override
    {
        checkTimer = 500;

        if (summoner)
            me->CastSpell(summoner, SPELL_SENTENCE_OF_SARGERAS_DMG, true);
    }

    void Reset() override {}

    void DespawnEvent()
    {
        checkTimer = 0;
        me->InterruptNonMeleeSpells(false);
        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (checkTimer)
        {
            if (checkTimer <= diff)
            {
                checkTimer = 500;

                if (instance->GetBossState(DATA_ARGUS) != IN_PROGRESS)
                {
                    DespawnEvent();
                    return;
                }

                if (auto owner = me->GetOwner())
                {
                    if (me->GetExactDist2d(owner) >= 35.0f)
                    {
                        owner->CastSpell(owner, SPELL_SHATTERED_BONDS, true);
                        DespawnEvent();
                    }
                }
            }
            else
                checkTimer -= diff;
        }
    }
};

//258041
class spell_argus_p1_energize_periodic : public AuraScript
{
    PrepareAuraScript(spell_argus_p1_energize_periodic);

    void OnTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster();
        if (!caster || !caster->IsInCombat() || aurEff->GetTickNumber() < 11)
            return;

        uint8 powerCount = caster->GetPower(caster->GetPowerType());

        if (powerCount < 100)
            caster->SetPower(caster->GetPowerType(), powerCount + 5);
        else if (!caster->HasUnitState(UNIT_STATE_CASTING))
            caster->CastSpell(caster, SPELL_CONE_OF_DEATH_FILTER);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_argus_p1_energize_periodic::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//258042
class spell_argus_p2_energize_periodic : public AuraScript
{
    PrepareAuraScript(spell_argus_p2_energize_periodic);

    uint8 powerCount = 0;
    uint8 tickCount = 0;
    float effectValue = 0.0f;

    void OnTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster();
        if (!caster || !caster->IsInCombat())
            return;

        powerCount = caster->GetPower(caster->GetPowerType());
        tickCount = aurEff->GetTickNumber() % 2 ? 2 : 3;

        if (powerCount < 100)
        {
            caster->SetPower(caster->GetPowerType(), powerCount + tickCount);

            if (powerCount == 50)
            {
                effectValue = 2.0f;
                caster->CastSpell(caster, SPELL_VOLATILE_SOUL_FILTER_2);
            }
        }
        else if (!caster->HasUnitState(UNIT_STATE_CASTING))
        {
            effectValue = 3.0f;
            caster->CastSpell(caster, SPELL_VOLATILE_SOUL_FILTER);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_argus_p2_energize_periodic::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//258044
class spell_argus_p4_energize_periodic : public AuraScript
{
    PrepareAuraScript(spell_argus_p4_energize_periodic);

    uint8 powerCount = 0;
    uint8 tickCount = 0;
    uint8 maxTick = 20;
    float effectValue = 0.0f;

    void OnTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster();
        if (!caster || !caster->IsInCombat())
            return;

        powerCount = caster->GetPower(caster->GetPowerType());

        if (powerCount < 99)
            caster->SetPower(caster->GetPowerType(), powerCount + 2);
        else
            caster->SetPower(caster->GetPowerType(), 0);

        if (++tickCount == maxTick)
        {
            if (maxTick == 20)
                maxTick = 40;

            tickCount = 0;

            if (effectValue < 3.0f)
            {
                effectValue = 3.0f;
                caster->CastSpell(caster, SPELL_VOLATILE_SOUL_FILTER);
            }
            else
            {
                effectValue = 2.0f;
                caster->CastSpell(caster, SPELL_VOLATILE_SOUL_FILTER_2);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_argus_p4_energize_periodic::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//256388, 258029
class spell_argus_initialization_sequence_periodic : public AuraScript
{
    PrepareAuraScript(spell_argus_initialization_sequence_periodic);

    float dmgPct = 0.0f;

    void OnTick(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        if (!dmgPct)
            dmgPct = 100.0f / (aurEff->GetBase()->GetMaxDuration() / 1000);

        if (auto at = GetCaster()->GetAreaTrigger(SPELL_INITIALIZATION_SEQUENCE ? SPELL_REORIGINATION_MODULE_AT : SPELL_APOCALYPSIS_MODULE_AT))
        {
            //at->SetObjectScale(dmgPct * 0.05f);
            GetCaster()->CastSpell(GetCaster(), SPELL_INITIALIZATION_SEQUENCE_SELF_DMG);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_argus_initialization_sequence_periodic::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//255200
class spell_argus_aggramar_boon : public AuraScript
{
    PrepareAuraScript(spell_argus_aggramar_boon);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        if (!GetCaster() || !GetTarget())
            return;

        if (float dmg = dmgInfo.GetDamage())
        {
            absorbAmount = dmg;
            GetTarget()->CastSpell(GetCaster(), SPELL_AGGRAMAR_SACRIFICE);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_argus_aggramar_boon::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_argus_aggramar_boon::Absorb, EFFECT_0);
    }
};

//257213, 257214
class spell_argus_titanforging_energize_periodic : public AuraScript
{
    PrepareAuraScript(spell_argus_titanforging_energize_periodic);

    bool allowCast = false;
    uint8 powerCount = 0;
    float amount = 0.0f;

    void OnReductedTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster();
        if (!caster)
            return;

        if (powerCount = caster->GetPower(caster->GetPowerType()))
            caster->SetPower(caster->GetPowerType(), powerCount - 1);
    }

    void OnCheckTick(AuraEffect const* aurEff)
    {
        auto caster = GetCaster();
        if (!caster)
            return;

        powerCount = caster->GetPower(caster->GetPowerType());

        if (!allowCast && powerCount >= 20)
        {
            allowCast = true;
            caster->CastSpell(caster, SPELL_TITANFORGING_PERIODIC_REDUCT_ENERGY, true);
        }
        else if (allowCast && powerCount == 0)
        {
            allowCast = false;
            caster->RemoveAurasDueToSpell(SPELL_TITANFORGING_PERIODIC_REDUCT_ENERGY);
        }

        if (powerCount < 40)
            amount = 15.0f;
        else if (powerCount < 60)
            amount = 30.0f;
        else if (powerCount < 80)
            amount = 45.0f;
        else if (powerCount <= 100)
            amount = 60.0f;

        if (allowCast)
            caster->CastSpell(caster, SPELL_TITANFORGED_BUFF);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_argus_titanforging_energize_periodic::OnReductedTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_argus_titanforging_energize_periodic::OnCheckTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//253026
class spell_argus_impending_inevitability : public AuraScript
{
    PrepareAuraScript(spell_argus_impending_inevitability);

    void OnProc(AuraEffect* /*auraEffect*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_argus_impending_inevitability::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

//255594
class spell_argus_sky_and_sea : public SpellScript
{
    PrepareSpellScript(spell_argus_sky_and_sea);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster())
            return;

        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            return false;
        });

        Trinity::Containers::RandomResize(targets, 2);

        for (auto spellId : { SPELL_GIFT_OF_THE_SKY_AURA, SPELL_GIFT_OF_THE_SEA_AURA })
        {
            if (targets.empty())
                return;

            if (auto object = targets.front())
            {
                targets.remove(object);

                if (auto target = object->ToUnit())
                    target->CastSpell(target, spellId, true, nullptr, nullptr, GetCaster()->GetGUID());
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argus_sky_and_sea::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

//256674
class spell_argus_golganneth_wrath : public SpellScript
{
    PrepareSpellScript(spell_argus_golganneth_wrath);

    void HandleScript(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster() || !GetHitDest())
            return;

        GetCaster()->CastSpell(GetCaster()->GetPosition(), SPELL_GOLGANNETH_WRATH_PERSISTENT, false);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_argus_golganneth_wrath::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//255646
class spell_argus_golganneth_wrath_filter : public SpellScript
{
    PrepareSpellScript(spell_argus_golganneth_wrath_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer() || object->GetDistance(centrPos) <= 18.0f)
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argus_golganneth_wrath_filter::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

//252280, 258043
class spell_argus_volatile_soul_filter : public SpellScript
{
    PrepareSpellScript(spell_argus_volatile_soul_filter);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            return false;
        });

        SpellValue const* val = GetSpellValue();
        if (!val)
            return;

        uint32 count = 2;

        Trinity::Containers::RandomResize(targets, count);

        for (auto spellId : { SPELL_SOULBURST, SPELL_SOULBURST, SPELL_SOULBOMB })
        {
            if (targets.empty())
                return;

            if (auto object = targets.front())
            {
                targets.remove(object);
                GetCaster()->CastSpell(object->ToUnit(), spellId, true);
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argus_volatile_soul_filter::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

//251571, 251572
class spell_argus_soul_detonation : public SpellScript
{
    PrepareSpellScript(spell_argus_soul_detonation);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        float maxDist = GetCaster()->GetMap()->IsHeroic() ? 45.0f : 35.0f;
        float distance = GetCaster()->GetExactDist2d(GetHitUnit());
        float pct = 100.0f - (distance / maxDist) * 100.0f;
        if (pct < 0.0f)
            pct = 0.0f;

        SetHitDamage(CalculatePct(GetHitDamage(), pct));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_argus_soul_detonation::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//258068
class spell_argus_sargeras_gaze : public SpellScript
{
    PrepareSpellScript(spell_argus_sargeras_gaze);

    std::list<WorldObject*> rangedList;
    std::list<WorldObject*> meleeList;
    std::list<WorldObject*> tempList;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        auto argus = GetCaster()->ToCreature();
        if (!argus)
            return;

        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            if (auto player = object->ToPlayer())
            {
                switch (player->GetRoleForGroup())
                {
                case ROLE_DAMAGE:
                    meleeList.push_back(object);
                    break;
                case ROLE_HEALER:
                    rangedList.push_back(object);
                    break;
                }
            }
            return false;
        });

        uint8 gazeCount = argus->AI()->GetData(DATA_SARGERAS_GAZE) - 1;
        uint8 idx = 0;

        for (auto targetCount : sGazeVector[gazeCount])
        {
            switch (idx)
            {
            case 0: // Melee: "Rages"
            {
                for (uint8 i = 0; i < targetCount; ++i)
                {
                    if (!meleeList.empty())
                    {
                        auto object = Trinity::Containers::SelectRandomContainerElement(meleeList);
                        meleeList.remove(object);
                        tempList.splice(tempList.end(), meleeList);

                        if (auto target = object->ToPlayer())
                            target->CastSpell(target, SPELL_SARGERAS_RAGE_AT, true);
                    }
                }
                break;
            }
            case 1: // Range: "Rages"
            {
                for (uint8 i = 0; i < targetCount; ++i)
                {
                    if (!rangedList.empty())
                    {
                        auto object = Trinity::Containers::SelectRandomContainerElement(rangedList);
                        rangedList.remove(object);
                        tempList.splice(tempList.end(), rangedList);

                        if (auto target = object->ToPlayer())
                            target->CastSpell(target, SPELL_SARGERAS_RAGE_AT, true);
                    }
                }
                break;
            }
            case 2: // Random: "Fear"
            {
                Trinity::Containers::RandomResize(tempList, targetCount);
                for (auto object : tempList)
                    if (auto target = object->ToPlayer())
                        target->CastSpell(target, SPELL_SARGERAS_FEAR_AT, true);
                break;
            }
            }
            ++idx;
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argus_sargeras_gaze::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

//258207
class spell_argus_apocalypsis_module : public SpellScript
{
    PrepareSpellScript(spell_argus_apocalypsis_module);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* object) -> bool
        {
            if (object == nullptr || !object->IsPlayer())
                return true;

            return false;
        });
    }

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        PreventHitDefaultEffect(EFFECT_0);

        if (GetCaster() && GetHitUnit())
            GetCaster()->CastSpell(GetHitUnit()->GetPositionX(), GetHitUnit()->GetPositionY(), GetHitUnit()->GetPositionZ() + 3.0f, SPELL_APOCALYPSIS_MODULE_SUMMON, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_argus_apocalypsis_module::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_argus_apocalypsis_module::HandleDummy, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

//258838
class spell_argus_soulrending_scythe_script : public SpellScript
{
    PrepareSpellScript(spell_argus_soulrending_scythe_script);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (!GetHitUnit())
            return;

        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_RENT_SOUL_FILTER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_argus_soulrending_scythe_script::HandleScript, EFFECT_3, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

//258839
class spell_argus_rent_soul : public SpellScript
{
    PrepareSpellScript(spell_argus_rent_soul);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        Position pos;
        GetHitUnit()->GetFirstCollisionPosition(frand(10.0f, 25.0f), frand(0.0f, 6.28f));
        GetCaster()->CastSpell(pos, SPELL_RENT_SOUL_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_argus_rent_soul::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};


void AddSC_boss_argus()
{
    RegisterCreatureAI(boss_argus);
    RegisterCreatureAI(npc_argus_titans_generic);
    RegisterCreatureAI(npc_argus_soulblight_orb);
    RegisterCreatureAI(npc_arugs_edge_of_obliteration);
    RegisterCreatureAI(npc_argus_constellar_designate);
    RegisterCreatureAI(npc_argus_gift_of_the_lifebinder);
    RegisterCreatureAI(npc_argus_hungering_soul);
    RegisterCreatureAI(npc_argus_reorigination_module);
    RegisterCreatureAI(npc_argus_mote_of_titanic_power);
    RegisterCreatureAI(npc_argus_chains_of_sargeras);
    RegisterAuraScript(spell_argus_p1_energize_periodic);
    RegisterAuraScript(spell_argus_p2_energize_periodic);
    RegisterAuraScript(spell_argus_p4_energize_periodic);
    RegisterAuraScript(spell_argus_initialization_sequence_periodic);
    RegisterAuraScript(spell_argus_aggramar_boon);
    RegisterAuraScript(spell_argus_titanforging_energize_periodic);
    RegisterAuraScript(spell_argus_impending_inevitability);
    RegisterSpellScript(spell_argus_sky_and_sea);
    RegisterSpellScript(spell_argus_golganneth_wrath);
    RegisterSpellScript(spell_argus_golganneth_wrath_filter);
    RegisterSpellScript(spell_argus_volatile_soul_filter);
    RegisterSpellScript(spell_argus_soul_detonation);
    RegisterSpellScript(spell_argus_sargeras_gaze);
    RegisterSpellScript(spell_argus_apocalypsis_module);
    RegisterSpellScript(spell_argus_soulrending_scythe_script);
    RegisterSpellScript(spell_argus_rent_soul);
}

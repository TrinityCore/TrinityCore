/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "throne_of_the_four_winds.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "MoveSplineInit.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Spell.h"
#include "Vehicle.h"

enum Spells
{
    // Al'Akir
    SPELL_WIND_BURST                                        = 87770,
    SPELL_LIGHTNING_STRIKE_TARGETING                        = 91327,
    SPELL_ICE_STORM                                         = 88239,
    SPELL_ELECTROCUTE                                       = 88427,
    SPELL_SQUALL_LINE_BACK_LEFT                             = 88781,
    SPELL_SQUALL_LINE_BACK_RIGHT                            = 91104,
    SPELL_SQUALL_LINE_SCRIPT                                = 91129,
    SPELL_SQUALL_LINE_SCRIPT_2                              = 91110,
    SPELL_ACID_RAIN                                         = 88290,
    SPELL_STORMLING                                         = 88272,
    SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TRIGGER     = 89528,
    SPELL_RELENTLESS_STORM_CHANNEL                          = 88875,
    SPELL_WIND_BURST_PERIODIC                               = 89638,
    SPELL_SUMMON_LIGHTNING_CLOUDS_PERIODIC                  = 89639,
    SPELL_SUMMON_LIGHTNING_CLOUDS_SUMMON                    = 89565,
    SPELL_LIGHTNING_ROD_PERIODIC                            = 89690,
    SPELL_STATIC_SHOCK                                      = 87873,
    SPELL_LIGHTNING                                         = 89644,
    SPELL_SUMMON_CHEST                                      = 95386,

    // Squall Line Vehicle
    SPELL_SQUALL_LINE_FORCE_CAST                            = 88779,

    // Lightning Strike Trigger
    SPELL_LIGHTNING_STRIKE_SUMMON                           = 93250,
    SPELL_LIGHTNING_STRIKE_PERIODIC                         = 88238,

    // Lightning Strike Trigger (Heroic Chain-Caster)
    SPELL_LIGHTNING_STRIKE_DAMAGE                           = 88214,
    SPELL_LIGHTNING_STRIKE_VISUAL                           = 88230,

    // Ice Storm
    SPELL_ICE_STORM_PING                                    = 87406,
    SPELL_ICE_STORM_CHARGE                                  = 87103,
    SPELL_ICE_STORM_UNK                                     = 87408, // Todo: research purpose

    // Ice Storm (Damage)
    SPELL_ICE_STORM_PRE_VISUAL                              = 87472,
    SPELL_ICE_STORM_AURA                                    = 87469,

    // Stormling Pre-effect
    SPELL_STORMLING_PRE_EFFECT_VISUAL                       = 87913,
    SPELL_STORMLING_SUMMON                                  = 87914,

    // Stormling
    SPELL_FEEDBACK                                          = 87904,

    // Relentless Storm Initial Vehicle
    SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE             = 89527,

    // World Trigger (Infinite AOI)
    SPELL_RELENTLESS_STORM_VISUAL                           = 88866,
    SPELL_STORM_DISTANCE_CHECK                              = 88899,

    // Lightning Clouds
    SPELL_LIGHTNING_CLOUDS_SUMMON_EXTRA_VISUALS_BOTTOM      = 95783,
    SPELL_LIGHTNING_CLOUDS_SUMMON_EXTRA_VISUALS             = 89577,
    SPELL_LIGHTNING_CLOUDS_VISUAL_DEST                      = 89569,
    SPELL_LIGHTNING_CLOUDS_PERIODIC_DAMAGE_AURA             = 89587,

    // Player
    SPELL_EYE_OF_THE_STORM                                  = 82724,
    SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TELEPORT    = 89661,
    SPELL_PET_FLIGHT                                        = 90786,
    SPELL_RELENTLESS_STORM_RIDE                             = 89104
};

#define SPELL_ACID_RAIN         RAID_MODE<uint32>(88290, 101451, 101452, 101453)
#define SPELL_ACID_RAIN_DAMAGE  RAID_MODE<uint32>(88301, 93279, 93280, 93281)

enum Texts
{
    SAY_CONCLAVE_OF_WIND_DEFEATED   = 0,
    SAY_AGGRO                       = 1,
    SAY_ANNOUNCE_WIND_BURST         = 2,
    SAY_SQUALL_LINE                 = 3,
    SAY_PHASE_TWO                   = 4,
    SAY_SUMMON_STORMLING            = 5,
    SAY_PHASE_THREE                 = 6,
    SAY_SLAY                        = 7,
    SAY_DEATH                       = 8
};

enum Events
{
    // Al'Akir
    EVENT_WIND_BURST = 1,
    EVENT_LIGHTNING_STRIKE,
    EVENT_ICE_STORM,
    EVENT_SQUALL_LINE,
    EVENT_SUMMON_STORMLING,
    EVENT_EYE_OF_THE_STORM,
    EVENT_WIND_BURST_PERIODIC,
    EVENT_LIGHTNING_CLOUDS_PERIODIC,
    EVENT_LIGHTNING_ROD_PERIODIC,
    EVENT_LIGHTNING_PERIODIC,
    EVENT_STATIC_SHOCK,

    // Ice Storm
    EVENT_PING_ICE_STORM_TRIGGERS,
    EVENT_ICE_STORM_CHARGE,

    // Stormling
    EVENT_ATTACK_PLAYERS
};

enum Phases
{
    PHASE_ONE   = 1,
    PHASE_TWO   = 2,
    PHASE_THREE = 3
};

enum Actions
{
};

enum Data
{
    DATA_PRIMARY_LIGHTNING_STRIKE_TARGET = 0
};

enum SummonGroups
{
    SUMMON_GROUP_SLIPSTREAM = 0
};

#define MAX_HOME_POSITION_DISTANCE 70.0f

class DelayedSpellCastEvent : public BasicEvent
{
    public:
        DelayedSpellCastEvent(Unit* owner, uint32 spellId, bool triggered = false) :  _owner(owner), _spellId(spellId), _triggered(triggered) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, _spellId, _triggered);
            return true;
        }
    private:
        Unit* _owner;
        uint32 _spellId;
        bool _triggered;
};

class SquallLineImmunityRemovalEvent : public BasicEvent
{
    public:
        SquallLineImmunityRemovalEvent(Unit* owner, uint32 spellId) : _owner(owner), _spellId(spellId) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->ApplySpellImmune(0, IMMUNITY_ID, _spellId, false);
            return true;
        }
    private:
        Unit* _owner;
        uint32 _spellId;
};

Position const RelentlessStormTeleportReferencePos = { -126.0f, 838.0f, 316.0f };

class RelentlessStormTeleportEvent : public BasicEvent
{
    public:
        RelentlessStormTeleportEvent(Unit* owner) : _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            float x = RelentlessStormTeleportReferencePos.GetPositionX() + frand(-15.0f, 15.0f);
            float y = RelentlessStormTeleportReferencePos.GetPositionY() + frand(-15.0f, 15.0f);
            float z = RelentlessStormTeleportReferencePos.GetPositionZ() + frand(-15.0f, 15.0f);

            _owner->CastSpell(x, y, z, SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TELEPORT, true);
            return true;
        }
    private:
        Unit* _owner;
};

Position const SquallLineDistanceReferencePos       = { -13.16094f, 780.8931f, 191.1842f };
Position const LightningCloudBottomPos              = { -49.84375f, 815.3073f, 166.7302f };
Position const RelentlessStormSummonPositions[] =
{
    { -48.91272f, 828.0051f, 227.6183f, 1.482902f  },
    { -57.98315f, 825.0812f, 227.6183f, 2.267889f  },
    { -62.30005f, 816.451f,  227.6183f, 3.053086f  },
    { -37.53573f, 814.9442f, 227.6183f, 6.195712f  },
    { -59.3063f,  807.1537f, 227.6183f, 3.838088f  },
    { -40.49203f, 823.7983f, 227.6183f, 0.6977134f },
    { -40.9393f,  805.7899f, 227.6183f, 5.408307f  },
    { -50.4652f,  802.7259f, 227.6183f, 4.623291f  }
};

Position const LightningCloudsExtraVisualsBottomPositions[] =
{
    { -77.03298f, 827.9858f, 166.7302f },
    { -104.2222f, 840.6644f, 166.7302f },
    { -131.4114f, 853.343f, 166.7302f },
    { -60.10435f, 843.4981f, 166.7302f },
    { -70.36495f, 871.6888f, 166.7302f },
    { -80.62555f, 899.8796f, 166.7302f },
    { -37.1652f, 842.4965f, 166.7302f },
    { -24.48665f, 869.6858f, 166.7302f },
    { -11.8081f, 896.875f, 166.7302f },
    { -21.65297f, 825.5679f, 166.7302f },
    { 6.537807f, 835.8285f, 166.7302f },
    { 34.72858f, 846.0891f, 166.7302f },
    { -22.65452f, 802.6288f, 166.7302f },
    { 4.534714f, 789.9502f, 166.7302f },
    { 31.72395f, 777.2717f, 166.7302f },
    { -39.58315f, 787.1165f, 166.7302f },
    { -29.32254f, 758.9258f, 166.7302f },
    { -19.06194f, 730.735f, 166.7302f },
    { -62.5223f, 788.1181f, 166.7302f },
    { -75.20085f, 760.9288f, 166.7302f },
    { -87.87939f, 733.7396f, 166.7302f },
    { -78.03453f, 805.0467f, 166.7302f },
    { -106.2253f, 794.7861f, 166.7302f },
    { -134.4161f, 784.5255f, 166.7302f },
    { -79.80264f, 816.8774f, 181.3786f },
    { -109.7615f, 818.4474f, 181.3786f },
    { -139.7204f, 820.0176f, 181.3786f },
    { -69.91766f, 837.6017f, 181.3786f },
    { -89.99158f, 859.896f, 181.3786f },
    { -110.0655f, 882.1904f, 181.3786f },
    { -48.27367f, 845.2662f, 181.3786f },
    { -46.70358f, 875.2251f, 181.3786f },
    { -45.1335f, 905.184f, 181.3786f },
    { -27.5494f, 835.3812f, 181.3786f },
    { -5.255058f, 855.4551f, 181.3786f },
    { 17.03929f, 875.5291f, 181.3786f },
    { -19.88486f, 813.7372f, 181.3786f },
    { 10.07402f, 812.1671f, 181.3786f },
    { 40.03291f, 810.597f, 181.3786f },
    { -29.76983f, 793.0129f, 181.3786f },
    { -9.695915f, 770.7186f, 181.3786f },
    { 10.378f, 748.4243f, 181.3786f },
    { -51.41383f, 785.3484f, 181.3786f },
    { -52.98391f, 755.3895f, 181.3786f },
    { -54.55399f, 725.4307f, 181.3786f },
    { -72.13809f, 795.2334f, 181.3786f },
    { -94.43243f, 775.1595f, 181.3786f },
    { -116.7268f, 755.0856f, 181.3786f }
};

Position const LightningCloudsExtraVisualsPositions[] =
{
    { -49.64583f, 845.0816f, 302.6394f },
    { -49.64584f, 875.0816f, 302.6394f },
    { -49.64584f, 905.0816f, 302.6394f },
    { -28.43263f, 836.2948f, 302.6394f },
    { -7.219425f, 857.508f, 302.6394f },
    { 13.99378f, 878.7212f, 302.6394f },
    { -19.64583f, 815.0816f, 302.6394f },
    { 10.35417f, 815.0816f, 302.6394f },
    { 40.35417f, 815.0816f, 302.6394f },
    { -28.43263f, 793.8684f, 302.6394f },
    { -7.219421f, 772.6552f, 302.6394f },
    { 13.99378f, 751.442f, 302.6394f },
    { -49.64583f, 785.0816f, 302.6394f },
    { -49.64584f, 755.0816f, 302.6394f },
    { -49.64584f, 725.0816f, 302.6394f },
    { -70.85904f, 793.8684f, 302.6394f },
    { -92.07224f, 772.6552f, 302.6394f },
    { -113.2854f, 751.442f, 302.6394f },
    { -79.64583f, 815.0816f, 302.6394f },
    { -109.6458f, 815.0816f, 302.6394f },
    { -139.6458f, 815.0816f, 302.6394f },
    { -70.85904f, 836.2948f, 302.6394f },
    { -92.07225f, 857.508f, 302.6394f },
    { -113.2855f, 878.7212f, 302.6394f }
};

struct boss_alakir : public BossAI
{
    boss_alakir(Creature* creature) : BossAI(creature, DATA_ALAKIR)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        _useLeftSquallLineSpell = true;
        _useTempoaryCloudSpawns = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        me->SetReactState(REACT_AGGRESSIVE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_WIND_BURST, 23s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_LIGHTNING_STRIKE, 9s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_ICE_STORM, 5s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SQUALL_LINE, 10s);

        if (IsHeroic())
            events.ScheduleEvent(EVENT_STATIC_SHOCK, 5s, 0, PHASE_ONE);
    }

    void Reset()
    {
        _Reset();
        if (instance->GetBossState(DATA_CONCLAVE_OF_WIND) == DONE)
            me->SummonCreatureGroup(SUMMON_GROUP_SLIPSTREAM);
    }

    void KilledUnit(Unit* killed) override
    {
        if (killed->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ACID_RAIN_DAMAGE);
        summons.DespawnAll();

        if (GameObject* platform = instance->GetGameObject(DATA_SKYWALL_RAID_CENTER_PLATFORM))
            platform->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);

        if (GameObject* draftEffect = instance->GetGameObject(DATA_SKYWALL_WIND_DRAFT_EFFECT_CENTER))
            draftEffect->ResetDoorOrButton();

        if (Creature* worldTrigger = instance->GetCreature(DATA_WORLD_TRIGGER_INFINITE_AOI))
            worldTrigger->RemoveAllAuras();

        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ACID_RAIN_DAMAGE);
        instance->DoCastSpellOnPlayers(SPELL_SERENITY);
        DoCastSelf(SPELL_SUMMON_CHEST, true);
        me->GetMotionMaster()->MoveFall();

        if (Creature* worldTrigger = instance->GetCreature(DATA_WORLD_TRIGGER_INFINITE_AOI))
            worldTrigger->RemoveAllAuras();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CONCLAVE_DEFEATED:
                Talk(SAY_CONCLAVE_OF_WIND_DEFEATED);
                me->SummonCreatureGroup(SUMMON_GROUP_SLIPSTREAM);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(80, damage) && events.IsInPhase(PHASE_ONE))
        {
            DoCastSelf(SPELL_ACID_RAIN);
            instance->SetData(DATA_ACID_RAIN_WEATHER, IN_PROGRESS);
            Talk(SAY_PHASE_TWO);
            events.SetPhase(PHASE_TWO);
            events.ScheduleEvent(EVENT_SUMMON_STORMLING, 10s, 11s, 0, PHASE_TWO);
        }
        else if (me->HealthBelowPctDamaged(25, damage) && events.IsInPhase(PHASE_TWO))
        {
            Talk(SAY_PHASE_THREE);
            me->SetCanFly(true);
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->SetFacingTo(3.141593f);
            me->InterruptNonMeleeSpells(true);
            me->RemoveAurasDueToSpell(SPELL_ACID_RAIN);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ACID_RAIN_DAMAGE);
            instance->SetData(DATA_ACID_RAIN_WEATHER, NOT_STARTED);
            DoCastAOE(SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE_TRIGGER);
            DoCastAOE(SPELL_RELENTLESS_STORM_CHANNEL);
            summons.DespawnEntry(NPC_SQUALL_LINE_SE);
            summons.DespawnEntry(NPC_SQUALL_LINE_SW);
            summons.DespawnEntry(NPC_SQUALL_LINE_VEHICLE_SE);
            summons.DespawnEntry(NPC_SQUALL_LINE_VEHICLE_SW);
            summons.DespawnEntry(NPC_LIGHTNING_STRIKE_TRIGGER_HEROIC_CHAIN_CASTER);
            events.CancelEvent(EVENT_SQUALL_LINE);
            events.SetPhase(PHASE_THREE);
            events.ScheduleEvent(EVENT_WIND_BURST_PERIODIC, 6s, 0, PHASE_THREE);
            events.ScheduleEvent(EVENT_LIGHTNING_ROD_PERIODIC, 6s, 0, PHASE_THREE);
            events.ScheduleEvent(EVENT_EYE_OF_THE_STORM, 7s, 0, PHASE_THREE);
            events.ScheduleEvent(EVENT_LIGHTNING_CLOUDS_PERIODIC, 26s, 0, PHASE_THREE);

            if (IsHeroic())
                events.ScheduleEvent(EVENT_LIGHTNING_PERIODIC, 6s, 0, PHASE_THREE);

            if (GameObject* platform = instance->GetGameObject(DATA_SKYWALL_RAID_CENTER_PLATFORM))
                platform->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);

            if (GameObject* draftEffect = instance->GetGameObject(DATA_SKYWALL_WIND_DRAFT_EFFECT_CENTER))
                draftEffect->UseDoorOrButton();

            if (Creature* worldTrigger = instance->GetCreature(DATA_WORLD_TRIGGER_INFINITE_AOI))
            {
                worldTrigger->CastSpell(worldTrigger, SPELL_RELENTLESS_STORM_VISUAL);
                worldTrigger->CastSpell(worldTrigger, SPELL_STORM_DISTANCE_CHECK);
            }

            for (uint8 i = 0; i < 8; i++)
                if (Creature* stormTrigger = DoSummon(NPC_RELENTLESS_STORM, RelentlessStormSummonPositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
                    stormTrigger->GetMotionMaster()->MoveCirclePath(me->GetPositionX(), me->GetPositionY(), RelentlessStormSummonPositions[i].GetPositionZ(),
                        107.3f, false, 11);

            if (Creature* cloud = DoSummon(NPC_LIGHTNING_CLOUDS_BOTTOM, LightningCloudBottomPos, 0, TEMPSUMMON_MANUAL_DESPAWN))
                for (uint8 i = 0; i < 48; i++)
                    cloud->CastSpell(LightningCloudsExtraVisualsBottomPositions[i].GetPositionX(), LightningCloudsExtraVisualsBottomPositions[i].GetPositionY(),
                        LightningCloudsExtraVisualsBottomPositions[i].GetPositionZ(), SPELL_LIGHTNING_CLOUDS_SUMMON_EXTRA_VISUALS_BOTTOM);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SLIPSTREAM:
                summon->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                break;
            case NPC_ICE_STORM:
                summon->CastSpell(summon, SPELL_ICE_STORM_PRE_VISUAL);
                summon->m_Events.AddEventAtOffset(new DelayedSpellCastEvent(summon, SPELL_ICE_STORM_AURA), 3s + 500ms);
                break;
            case NPC_SQUALL_LINE_VEHICLE_SW:
                DoCastSelf(SPELL_SQUALL_LINE_SCRIPT);
                summon->GetMotionMaster()->MoveCirclePath(me->GetPositionX(), me->GetPositionY(), SquallLineDistanceReferencePos.GetPositionZ(), me->GetExactDist2d(SquallLineDistanceReferencePos), true, 11);
                // Delay the spell cast by 100ms to give the core time to place the accessories into the seats for the following spellscript to take effect
                summon->m_Events.AddEventAtOffset(new DelayedSpellCastEvent(summon, SPELL_SQUALL_LINE_FORCE_CAST), 100ms);
                break;
            case NPC_SQUALL_LINE_VEHICLE_SE:
                DoCastSelf(SPELL_SQUALL_LINE_SCRIPT);
                summon->GetMotionMaster()->MoveCirclePath(me->GetPositionX(), me->GetPositionY(), SquallLineDistanceReferencePos.GetPositionZ(), me->GetExactDist2d(SquallLineDistanceReferencePos), false, 11);
                summon->m_Events.AddEventAtOffset(new DelayedSpellCastEvent(summon, SPELL_SQUALL_LINE_FORCE_CAST), 100ms);
                break;
            case NPC_SQUALL_LINE_SW:
            case NPC_SQUALL_LINE_SE:
                // We don't use that spell. We just cast it because in sniffs they do the same
                DoCast(summon, SPELL_SQUALL_LINE_SCRIPT_2, true);
                break;
            case NPC_STORMLING_PRE_EFFECT:
                summon->CastSpell(summon, SPELL_STORMLING_PRE_EFFECT_VISUAL);
                summon->m_Events.AddEventAtOffset(new DelayedSpellCastEvent(summon, SPELL_STORMLING_SUMMON), 3s + 500ms);
                break;
            case NPC_LIGHTNING_CLOUDS_BOTTOM:
                summon->m_Events.AddEventAtOffset(new DelayedSpellCastEvent(summon, SPELL_LIGHTNING_CLOUDS_PERIODIC_DAMAGE_AURA), 5s);
                break;
            case NPC_LIGHTNING_CLOUDS:
                summon->m_Events.AddEventAtOffset(new DelayedSpellCastEvent(summon, SPELL_LIGHTNING_CLOUDS_PERIODIC_DAMAGE_AURA), 5s);
                for (uint8 i = 0; i < 24; i++)
                    summon->CastSpell(LightningCloudsExtraVisualsPositions[i].GetPositionX(), LightningCloudsExtraVisualsPositions[i].GetPositionY(),
                        summon->GetPositionZ(), SPELL_LIGHTNING_CLOUDS_SUMMON_EXTRA_VISUALS);
                break;
            default:
                break;
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        if (type == DATA_PRIMARY_LIGHTNING_STRIKE_TARGET)
            return _primaryLightningStrikeTarget;

        return ObjectGuid::Empty;
    }

    void SetGUID(ObjectGuid const& guid, int32 type) override
    {
        if (type == DATA_PRIMARY_LIGHTNING_STRIKE_TARGET)
            _primaryLightningStrikeTarget = guid;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WIND_BURST:
                    Talk(SAY_ANNOUNCE_WIND_BURST);
                    DoCastAOE(SPELL_WIND_BURST);
                    events.Repeat(26s);
                    break;
                case EVENT_LIGHTNING_STRIKE:
                    DoCastAOE(SPELL_LIGHTNING_STRIKE_TARGETING);
                    events.Repeat(8s);
                    break;
                case EVENT_ICE_STORM:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true, 0))
                        DoCast(target, SPELL_ICE_STORM);
                    events.Repeat(16s);
                    break;
                case EVENT_SQUALL_LINE:
                    if (events.IsInPhase(PHASE_ONE))
                        Talk(SAY_SQUALL_LINE);

                    DoCastSelf(_useLeftSquallLineSpell ? SPELL_SQUALL_LINE_BACK_LEFT : SPELL_SQUALL_LINE_BACK_RIGHT);
                    _useLeftSquallLineSpell = !_useLeftSquallLineSpell;
                    events.Repeat(31s);
                    break;
                case EVENT_SUMMON_STORMLING:
                    Talk(SAY_SUMMON_STORMLING);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_STORMLING);
                    events.Repeat(20s);
                    break;
                case EVENT_EYE_OF_THE_STORM:
                    instance->DoCastSpellOnPlayers(SPELL_EYE_OF_THE_STORM);
                    break;
                case EVENT_WIND_BURST_PERIODIC:
                    DoCastSelf(SPELL_WIND_BURST_PERIODIC);
                    break;
                case EVENT_LIGHTNING_CLOUDS_PERIODIC:
                    DoCastSelf(SPELL_SUMMON_LIGHTNING_CLOUDS_PERIODIC);
                    break;
                case EVENT_LIGHTNING_ROD_PERIODIC:
                    DoCastSelf(SPELL_LIGHTNING_ROD_PERIODIC);
                    break;
                case EVENT_STATIC_SHOCK:
                    DoCastAOE(SPELL_STATIC_SHOCK);
                    events.Repeat(6s);
                    break;
                case EVENT_LIGHTNING_PERIODIC:
                    DoCastSelf(SPELL_LIGHTNING);
                    break;
                default:
                    break;
            }
        }
        if (me->IsWithinMeleeRange(me->GetVictim()))
            DoMeleeAttackIfReady();
        else
            DoSpellAttackIfReady(SPELL_ELECTROCUTE);
    }

private:
    ObjectGuid _primaryLightningStrikeTarget;
    bool _useLeftSquallLineSpell;
    bool _useTempoaryCloudSpawns;
};

struct npc_alakir_ice_storm : public ScriptedAI
{
    npc_alakir_ice_storm(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_PING_ICE_STORM_TRIGGERS, 1s);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ICE_STORM_PING && target->GetExactDist2d(me) > 20.0f)
            _iceStormPositions.push_back(target->GetPosition());
    }

    void MovementInform(uint32 /*type*/, uint32 pointId) override
    {
        if (pointId == EVENT_CHARGE)
            _events.ScheduleEvent(EVENT_ICE_STORM_CHARGE, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PING_ICE_STORM_TRIGGERS:
                    DoCastAOE(SPELL_ICE_STORM_PING);
                    _events.ScheduleEvent(EVENT_ICE_STORM_CHARGE, 500ms);
                    break;
                case EVENT_ICE_STORM_CHARGE:
                {
                    Creature* alakir = _instance->GetCreature(DATA_ALAKIR);
                    if (!alakir)
                        break;

                    Position pos = alakir->GetPosition();
                    pos.SetOrientation(alakir->GetAngle(me) + float(M_PI / 4));

                    std::vector<Position> possibleDestinations;
                    for (Position destination : _iceStormPositions)
                    {
                        if (pos.HasInLine(&destination, alakir->GetCombatReach()))
                            possibleDestinations.push_back(destination);
                    }

                    if (!possibleDestinations.empty())
                    {
                        Position dest = Trinity::Containers::SelectRandomContainerElement(possibleDestinations);
                        me->CastSpell(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), SPELL_ICE_STORM_CHARGE, true);
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    InstanceScript* _instance;
    std::vector<Position> _iceStormPositions;
};

struct npc_alakir_stormling : public ScriptedAI
{
    npc_alakir_stormling(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 2s + 300ms);
        if (Creature* alakir = _instance->GetCreature(DATA_ALAKIR))
            _alakirPos = alakir->GetHomePosition();
    }

    void AttackStart(Unit* who) override
    {
        if (IsTargetOnPlatform(who))
            ScriptedAI::AttackStart(who);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastAOE(SPELL_FEEDBACK, true);
        me->DespawnOrUnsummon(4s);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();
        UpdatePlatformVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ATTACK_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    Position _alakirPos;

    void UpdatePlatformVictim()
    {
        if (Unit* victim = me->GetVictim())
            if (victim->GetExactDist2d(_alakirPos) > MAX_HOME_POSITION_DISTANCE)
                me->AttackStop();
    }

    bool IsTargetOnPlatform(Unit* target) const
    {
        return (target->GetExactDist2d(_alakirPos) < MAX_HOME_POSITION_DISTANCE);
    }
};

class spell_alakir_lightning_strike_script : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_strike_script);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LIGHTNING_STRIKE_SUMMON,
                SPELL_LIGHTNING_STRIKE_PERIODIC
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();
        target->SetFacingToObject(caster);
        target->SetOrientation(target->GetAngle(caster)); // Update orientation immediately for the following cast

        if (InstanceScript* instance = caster->GetInstanceScript())
            if (Creature* alakir = instance->GetCreature(DATA_ALAKIR))
                alakir->AI()->SetGUID(caster->GetGUID(), DATA_PRIMARY_LIGHTNING_STRIKE_TARGET);

        if (target->GetMap()->IsHeroic())
            target->CastSpell(target, SPELL_LIGHTNING_STRIKE_SUMMON, true);
        else
            target->CastSpell(target, SPELL_LIGHTNING_STRIKE_PERIODIC, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_strike_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_alakir_lightning_strike_periodic : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_strike_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_LIGHTNING_STRIKE_DAMAGE,
                SPELL_LIGHTNING_STRIKE_VISUAL
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_LIGHTNING_STRIKE_DAMAGE, true);

        float orientation = caster->GetOrientation();
        float coneAngle = float(M_PI / 3);
        float coneSegment = coneAngle / 10;
        for (uint8 i = 0; i < 10; i++)
        {
            float angle = orientation - (coneAngle / 2) + (coneSegment * i);
            float x = caster->GetPositionX() + cos(angle) * 75.0f;
            float y = caster->GetPositionY() + sin(angle) * 75.0f;
            float z = caster->GetPositionZ();
            caster->CastSpell(x, y, z, SPELL_LIGHTNING_STRIKE_VISUAL, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_strike_periodic::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_alakir_lightning_strike_damage : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_strike_damage);

    void HandleDamageReuction(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (InstanceScript* instance = caster->GetInstanceScript())
            if (Creature* alakir = instance->GetCreature(DATA_ALAKIR))
                if (GetHitUnit()->GetGUID() != alakir->AI()->GetGUID(DATA_PRIMARY_LIGHTNING_STRIKE_TARGET))
                    SetHitDamage(GetHitDamage() * 0.5f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_strike_damage::HandleDamageReuction, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_alakir_electrocute : public AuraScript
{
    PrepareAuraScript(spell_alakir_electrocute);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();

        if (!caster || !target)
            return;

        if (caster->IsWithinMeleeRange(target))
        {
            Remove();
            return;
        }

        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
        {
            int32 basePoints = 3600;
            basePoints += CalculatePct(basePoints * (aurEff->GetTickNumber() - 1), 50);
            aurEff->ChangeAmount(basePoints);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_alakir_electrocute::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

class SquallLineGapTargetSelector
{
    public:
        SquallLineGapTargetSelector(uint8 seatIndex) : _seatIndex(seatIndex) { }

        bool operator()(WorldObject* object)
        {
            Unit* target = object->ToUnit();
            if (!target)
                return true;

            if (Vehicle* vehicle = target->GetVehicle())
                if (TempSummon* summon = vehicle->GetBase()->ToTempSummon())
                    if (summon->GetTimer() < 49 * IN_MILLISECONDS)
                        return true;


            if (target->GetTransSeat() == _seatIndex || target->GetTransSeat() == _seatIndex + 2)
                return true;

            return false;
        }
    private:
        uint8 _seatIndex;
};

class spell_alakir_squall_line_pre_aura : public SpellScript
{
    PrepareSpellScript(spell_alakir_squall_line_pre_aura);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint8 seatIndex = urand(0, 4);
        targets.remove_if(SquallLineGapTargetSelector(seatIndex));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alakir_squall_line_pre_aura::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_alakir_squall_line_script : public SpellScript
{
    PrepareSpellScript(spell_alakir_squall_line_script);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetHitUnit();
            if (caster->GetVehicleKit() && caster->GetVehicleKit()->GetAvailableSeatCount())
            {
                target->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints, true);
                target->ApplySpellImmune(0, IMMUNITY_ID, GetSpellInfo()->Id, true);
                target->m_Events.AddEventAtOffset(new SquallLineImmunityRemovalEvent(target, GetSpellInfo()->Id), 6s);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_squall_line_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_alakir_relentless_storm_initial_vehicle_ride_trigger : public SpellScript
{
    PrepareSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride_trigger);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_RELENTLESS_STORM_INITIAL_VEHICLE_RIDE, true);
        target->m_Events.AddEventAtOffset(new RelentlessStormTeleportEvent(target), 7s);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_relentless_storm_initial_vehicle_ride_trigger::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_alakir_relentless_storm_initial_vehicle_ride : public SpellScript
{
    PrepareSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride);

    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (ObjectGuid guid = instance->GetGuidData(DATA_FREE_RELENTLESS_STORM_INITIAL_VEHICLE))
                if (Creature* hurricane = ObjectAccessor::GetCreature(*GetCaster(), guid))
                    target = hurricane;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_alakir_relentless_storm_initial_vehicle_ride::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

class spell_alakir_wind_burst : public AuraScript
{
    PrepareAuraScript(spell_alakir_wind_burst);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->SetCanFly(true, true);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_alakir_wind_burst::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_alakir_lightning_clouds_periodic : public AuraScript
{
    PrepareAuraScript(spell_alakir_lightning_clouds_periodic);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_LIGHTNING_CLOUDS_VISUAL_DEST });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        Position pos = target->GetRandomPoint(target->GetPosition(), 80.0f);
        pos.m_positionZ = target->GetPositionZ() + frand(-10.0f, 10.0f);
        target->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_LIGHTNING_CLOUDS_VISUAL_DEST);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_alakir_lightning_clouds_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class LightningCloudsAltitudeTargetSelector
{
    public:
        LightningCloudsAltitudeTargetSelector(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object)
        {
            return (std::abs(object->GetPositionZ() - _caster->GetPositionZ()) > 10.0f);
        }
    private:
        Unit* _caster;
};

class spell_alakir_lightning_clouds_damage : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_clouds_damage);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(LightningCloudsAltitudeTargetSelector(GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alakir_lightning_clouds_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_alakir_lightning_clouds_targeting : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_clouds_targeting);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LIGHTNING_CLOUDS_SUMMON });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            float x = caster->GetPositionX();
            float y = caster->GetPositionY();
            float z = GetHitUnit()->GetPositionZ();
            float o = GetHitUnit()->GetOrientation();
            caster->CastSpell(x, y, z, o, SPELL_SUMMON_LIGHTNING_CLOUDS_SUMMON);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_clouds_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_alakir_lightning_clouds_dummy : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_clouds_dummy);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(LightningCloudsAltitudeTargetSelector(GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alakir_lightning_clouds_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class LightningRodTargetSelector
{
    public:
        LightningRodTargetSelector(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object)
        {
            return (std::abs(object->GetPositionZ() - _caster->GetPositionZ()) > 5.0f);
        }
    private:
        Unit* _caster;
};

class spell_alakir_lightning_rod_damage : public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_rod_damage);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(LightningRodTargetSelector(GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alakir_lightning_rod_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

class spell_alakir_relentless_storm : public SpellScript
{
    PrepareSpellScript(spell_alakir_relentless_storm);

    void SetTarget(WorldObject*& target)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (ObjectGuid guid = instance->GetGuidData(DATA_FREE_RELENTLESS_STORM_VEHICLE))
                if (Creature* hurricane = ObjectAccessor::GetCreature(*GetCaster(), guid))
                    target = hurricane;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_alakir_relentless_storm::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

class RelentlessStormTargetSelector
{
    public:
        RelentlessStormTargetSelector(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object)
        {
            return (object->GetExactDist2d(_caster) < 110.0f);
        }
    private:
        Unit* _caster;
};

class spell_alakir_storm_distance_check: public SpellScript
{
    PrepareSpellScript(spell_alakir_storm_distance_check);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_RELENTLESS_STORM_RIDE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(RelentlessStormTargetSelector(GetCaster()));
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_RELENTLESS_STORM_RIDE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alakir_storm_distance_check::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_alakir_storm_distance_check::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_alakir_lightning_script: public SpellScript
{
    PrepareSpellScript(spell_alakir_lightning_script);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetHitUnit();
            caster->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_alakir_lightning_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_alakir()
{
    RegisterThroneOfTheFourWindsCreatureAI(boss_alakir);
    RegisterThroneOfTheFourWindsCreatureAI(npc_alakir_ice_storm);
    RegisterThroneOfTheFourWindsCreatureAI(npc_alakir_stormling);
    RegisterSpellScript(spell_alakir_lightning_strike_script);
    RegisterSpellScript(spell_alakir_lightning_strike_periodic);
    RegisterSpellScript(spell_alakir_lightning_strike_damage);
    RegisterAuraScript(spell_alakir_electrocute);
    RegisterSpellScript(spell_alakir_squall_line_pre_aura);
    RegisterSpellScript(spell_alakir_squall_line_script);
    RegisterSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride_trigger);
    RegisterSpellScript(spell_alakir_relentless_storm_initial_vehicle_ride);
    RegisterAuraScript(spell_alakir_wind_burst);
    RegisterAuraScript(spell_alakir_lightning_clouds_periodic);
    RegisterSpellScript(spell_alakir_lightning_clouds_damage);
    RegisterSpellScript(spell_alakir_lightning_clouds_targeting);
    RegisterSpellScript(spell_alakir_lightning_clouds_dummy);
    RegisterSpellScript(spell_alakir_lightning_rod_damage);
    RegisterSpellScript(spell_alakir_relentless_storm);
    RegisterSpellScript(spell_alakir_storm_distance_check);
    RegisterSpellScript(spell_alakir_lightning_script);
}

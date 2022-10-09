/*
* This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "firelands.h"
#include "InstanceScript.h"
#include "PassiveAI.h"
#include "PathGenerator.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Optional.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum Texts
{
    // Lord Rhyolith
    SAY_ENGAGE                  = 0,
    SAY_CONCUSSIVE_STOMP        = 1,
    SAY_ANNOUNCE_DRINK_MAGMA    = 2,
    SAY_HEATED_VOLCANO          = 3,
    SAY_ANNOUNCE_ARMOR_WEAKENED = 4,
    SAY_ARMOR_WEAKENED          = 5,
    SAY_ANNOUNCE_ARMOR_BROKEN   = 6,
    SAY_ARMOR_BROKEN            = 7,
    SAY_DEATH                   = 8,
    SAY_SLAY                    = 9
};

enum Spells
{
    // Lord Rhyolith
    SPELL_OBSIDIAN_ARMOR                = 98632,
    SPELL_BALANCE_BAR                   = 98226,
    SPELL_CONCUSSIVE_STOMP              = 97282,
    SPELL_HEATED_VOLCANO                = 98493,
    SPELL_DRINK_MAGMA                   = 98034,
    SPELL_MOLTEN_SPEW                   = 98043,
    SPELL_LAVA_LINE                     = 100650,
    SPELL_SUMMON_TUBE                   = 98266, // Serverside spell
    SPELL_SUMMON_FRAGMENT_OF_RHYOLITH   = 98135,
    SPELL_SUMMON_SPARK_OF_RHYOLITH      = 98553,
    SPELL_SUMMON_ROCK_ELEMENTALS        = 98146,
    SPELL_IMMOLATION_1                  = 99846,
    SPELL_UNLEASHED_FLAME               = 101324,
    SPELL_SUMMON_ARMOR_FRAGMENT         = 98558,
    SPELL_SUPERHEATED                   = 101304,
    SPELL_BURNING_FEET                  = 98837,

    // Feet
    SPELL_RIDE_VEHICLE                  = 98843,
    SPELL_START_FIGHT                   = 103019, // Serverside spell
    SPELL_FOOT_DAMAGE_TRACKER           = 98192,  // Serverside spell

    // Volcano
    SPELL_VOLCANO_BASE                  = 98250,
    SPELL_ERUPTION                      = 98264,
    SPELL_ERUPTION_AURA                 = 98492,
    SPELL_EXPLOSION                     = 97719,
    SPELL_MAGMA                         = 98472,
    SPELL_MAGMA_FLOW                    = 97225,
    SPELL_MAGMA_FLOW_MISSILE            = 97230,
    SPELL_MAGMA_FLOW_DAMAGE             = 97234,
    SPELL_MOLTEN_ARMOR_10N              = 98255, // Duplicate enum as NullCreatureAI does not have access to the raid mode macro

    // Pillar
    SPELL_LAVA_TUBE                     = 98265,

    // Fragment of Rhyolith
    SPELL_MELTDOWN                      = 98646,

    // Spark of Rhyolith
    SPELL_IMMOLATION_2                  = 98597,
    SPELL_INFERNAL_RAGE                 = 98596,

    // Unleashed Flame
    SPELL_UNLEASHED_FLAME_AURA          = 101313,
    SPELL_UNLEASHED_FLAME_CHANNELING    = 101314,

    // Liquid Obsidian
    SPELL_FUSE                          = 99875
};

#define SPELL_MOLTEN_ARMOR RAID_MODE<uint32>(98255, 101157, 101158, 101159)

enum Events
{
    // Lord Rhyolith
    EVENT_CONCUSSIVE_STOMP = 1,
    EVENT_UPDATE_BALANCE,
    EVENT_HEATED_VOLCANO,
    EVENT_BALANCE_FEET_HEALTH,
    EVENT_LAVA_LINE,
    EVENT_THERMAL_VENT,
    EVENT_STAND_UP,
    EVENT_TURN_AGGRESSIVE,
    EVENT_UNLEASHED_FLAME,
    EVENT_SUPERHEATED,
    EVENT_SEARCH_FOR_VOLANOS,

    // Movement Controller - Lord Rhyolith
    EVENT_TELEPORT,
    EVENT_MOVE_LORD_RHYOLITH,

    // Volcano
    EVENT_ERUPTION,
    EVENT_MAGMA_FLOW,

    // Liquid Obsidian
    EVENT_FUSE_WITH_LORD_RHYOLITH
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO = 2
};

enum Actions
{
    // Lord Rhyolith
    ACTION_DROP_MOLTEN_ARMOR_CHARGE = 1,

    // Feet
    ACTION_RECALCULATE_DAMAGE_REDUCTION_MOD = 1,

    // Movement Controller - Lord Rhyolith
    ACTION_ENCOUNTER_STARTED        = 1,
    ACTION_STOP_MOVEMENT_CONTROL    = 2,

    // Volcano
    ACTION_ACTIVATE_VOLCANO         = 1,
    ACTION_SCHEDULE_MAGMA_FLOW      = 2,
    ACTION_DESTROY_VOLCANO          = 3
};

enum AIAnimKits
{
    AI_ANIM_KIT_LORD_RHYOLITH_SITTING = 1498
};

enum MovePoints
{
    // Lord Rholith
    POINT_DRINK_MAGMA = 0,

    // Pillar
    POINT_NONE
};

enum Balance : uint32
{
    MIN_LEFT_BALANCE    = 0,
    CENTER_BALANCE      = 25,
    MAX_RIGHT_BALANCE   = 50
};

enum Data
{
    DATA_CURRENT_BALANCE            = 0,
    DATA_DAMAGE_PER_SECOND          = 0,
    DATA_RECENTLY_BROKEN_VOLCANO    = 0,
};

enum WorldStates
{
    WORLD_STATE_ID_NOT_AN_AMBI_TURNER = 5931
};

static Position const MovementControllerSummonPosition  = { -366.00174f,  -349.65277f,  100.378845f, 1.7802358f };
static Position const PlateauPlatformCenterPosition     = { -371.577393f, -318.680725f, 102.f };
static constexpr float PlateauRadius                    = 50.f;

static std::array<uint32, 3> TransformationEntries =
{
    NPC_LORD_RHYOLITH_DAMAGED_1,
    NPC_LORD_RHYOLITH_DAMAGED_2,
    NPC_LORD_RHYOLITH_PHASE_TWO
};

static std::array<float, 2> BalanceDamageThresholds =
{
    3000.f, // Hotfix (2011-07-01): Rhyolith is now slightly easier to turn in 10-player mode.
    9000.f
};

struct boss_lord_rhyolith : public BossAI
{
    boss_lord_rhyolith(Creature* creature) : BossAI(creature, DATA_LORD_RHYOLITH),
        _currentBalance(CENTER_BALANCE), _transformationCount(0), _hasBrokenFirstVolcano(false), _achievementFailed(false), _hasBurningFeet(false) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->m_SightDistance = PlateauRadius;
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_OBSIDIAN_ARMOR, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_AURA_STACK, 80));

        uint8 seatId = 1;
        for (uint16 entry : { NPC_LEFT_FOOT, NPC_RIGHT_FOOT })
        {
            if (Creature* foot = DoSummon(entry, me->GetPosition(), 0, TEMPSUMMON_MANUAL_DESPAWN))
            {
                foot->SetDisplayId(foot->GetCreatureTemplate()->Modelid2);
                foot->CastSpell(me, SPELL_RIDE_VEHICLE, CastSpellExtraArgs().AddSpellBP0(seatId));
                foot->CastSpell(foot, SPELL_START_FIGHT);
                foot->CastSpell(foot, SPELL_FOOT_DAMAGE_TRACKER);
                foot->CastSpell(foot, SPELL_OBSIDIAN_ARMOR, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_AURA_STACK, 80));
            }

            ++seatId;
        }

        DoSummon(NPC_MOVEMENT_CONTROLLER_LORD_RHYOLITH, MovementControllerSummonPosition, 0, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_ENGAGE, who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->DoUpdateWorldState(WORLD_STATE_ID_NOT_AN_AMBI_TURNER, 0);

        uint8 frameIndex = 2;
        for (uint32 type : { DATA_LEFT_FOOT, DATA_RIGHT_FOOT })
        {
            if (Creature* foot = instance->GetCreature(type))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, foot, frameIndex);

                if (CreatureAI* ai = foot->AI())
                    ai->DoAction(ACTION_RECALCULATE_DAMAGE_REDUCTION_MOD);
            }

            ++frameIndex;
        }

        DoCastSelf(SPELL_BALANCE_BAR);

        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_UPDATE_BALANCE, 500ms, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_CONCUSSIVE_STOMP, 16s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_HEATED_VOLCANO, 30s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_BALANCE_FEET_HEALTH, 5s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_THERMAL_VENT, 23s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SUPERHEATED, IsHeroic() ? 5min : 6min);
        events.ScheduleEvent(EVENT_SEARCH_FOR_VOLANOS, 1ms, 0, PHASE_ONE);

        if (Creature* movementController = instance->GetCreature(DATA_LORD_RHYOLITH_MOVEMENT_CONTROLLER))
        {
            if (CreatureAI* ai = movementController->AI())
            {
                ai->DoAction(ACTION_ENCOUNTER_STARTED);
                return;
            }
        }

        // The controller has not been found or does not have any AI enabled. The fight will be dysfunctional, so let's prevent that and reset the encounter
        EnterEvadeMode(EVADE_REASON_OTHER);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        CleanupEncounter();
        BossAI::EnterEvadeMode(why);
        _DespawnAtEvade();
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_DEATH);
        CleanupEncounter();
        BossAI::JustDied(killer);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim && victim->IsPlayer())
            Talk(SAY_SLAY, victim);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who->IsPlayer())
            return;

        if (!me->IsEngaged())
            me->EngageWithTarget(who);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.RemoveNotExisting();

        switch (summon->GetEntry())
        {
            case NPC_MOVEMENT_CONTROLLER_LORD_RHYOLITH:
                summons.Summon(summon);
                break;
            case NPC_VOLCANO:
                summon->CastSpell(nullptr, SPELL_VOLCANO_BASE);
                summon->SetDisplayId(summon->GetCreatureTemplate()->Modelid2);
                summons.Summon(summon);
                break;
            case NPC_PILLAR:
                summon->CastSpell(nullptr, SPELL_LAVA_TUBE);
                summon->GetMotionMaster()->MovePoint(POINT_NONE, summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ() + 6.f, false, 2.f);
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->GetMotionMaster()->MovePoint(POINT_NONE, summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ() - 6.f, false, 2.f);
                    summon->DespawnOrUnsummon(4s + 500ms);
                }, 11s);
                summons.Summon(summon);
                break;
            case NPC_FRAGMENT_OF_RHYOLITH:
                summon->CastSpell(nullptr, SPELL_MELTDOWN);
                [[fallthrough]];
            case NPC_SPARK_OF_RHYOLITH:
                summon->SetCorpseDelay(3);
                summon->SetReactState(REACT_PASSIVE);
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->SetReactState(REACT_AGGRESSIVE);
                    if (CreatureAI* ai = summon->AI())
                        ai->DoZoneInCombat(summon);

                    if (summon->GetEntry() == NPC_SPARK_OF_RHYOLITH)
                        summon->CastSpell(nullptr, SPELL_IMMOLATION_2);
                }, 1s);
                summons.Summon(summon);
                break;
            case NPC_UNLEASHED_FLAME:
                summon->CastSpell(nullptr, SPELL_UNLEASHED_FLAME_AURA);
                summon->CastSpell(nullptr, SPELL_UNLEASHED_FLAME_CHANNELING);
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->GetMotionMaster()->MoveCirclePath(summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ(), 10.f, true, 6);
                }, 1s);
                summons.Summon(summon);
                break;
            default:
                BossAI::JustSummoned(summon);
                break;
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_DRINK_MAGMA:
                Talk(SAY_ANNOUNCE_DRINK_MAGMA);
                DoCastSelf(SPELL_DRINK_MAGMA);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if ((me->HealthBelowPctDamaged(75, damage) && _transformationCount == 0)
            || (me->HealthBelowPctDamaged(50, damage) && _transformationCount == 1)
            || (me->HealthBelowPctDamaged(25, damage) && _transformationCount == 2))
        {
            me->UpdateEntry(TransformationEntries[_transformationCount], nullptr, false);
            {
                // UpdateEntry resets the react state and clears the combat flag which causes false evades, so we gotta handle that problem
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                me->SetReactState(REACT_PASSIVE);
            }
            ++_transformationCount;
        }

        if (_transformationCount == 3 && !events.IsInPhase(PHASE_TWO))
        {
            me->InterruptNonMeleeSpells(true);
            me->GetMotionMaster()->Clear(MOTION_SLOT_ACTIVE);
            me->StopMoving();

            for (uint32 type : { DATA_LEFT_FOOT, DATA_RIGHT_FOOT })
            {
                if (Creature* foot = instance->GetCreature(type))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, foot);
                    foot->DespawnOrUnsummon();
                }
            }

            // Despawn all summons except for volcanos that have been turned into craters
            summons.DespawnEntry(NPC_FRAGMENT_OF_RHYOLITH);
            summons.DespawnEntry(NPC_SPARK_OF_RHYOLITH);
            summons.DespawnEntry(NPC_VOLCANO);
            summons.DespawnEntry(NPC_VOLCANO_HEATED);
            summons.DespawnEntry(NPC_PILLAR);

            if (Creature* controller = instance->GetCreature(DATA_LORD_RHYOLITH_MOVEMENT_CONTROLLER))
                if (CreatureAI* ai = controller->AI())
                    ai->DoAction(ACTION_STOP_MOVEMENT_CONTROL);

            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_UNIT_FRAME);
            me->SetAIAnimKitId(AI_ANIM_KIT_LORD_RHYOLITH_SITTING);
            DoCastSelf(SPELL_IMMOLATION_1);
            Talk(SAY_ANNOUNCE_ARMOR_BROKEN);
            Talk(SAY_ARMOR_BROKEN);

            // Hotfix (2011-07-14): The Eruption debuff is now cleared when transitioning into phase 2 of the fight.
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ERUPTION_AURA);

            events.SetPhase(PHASE_TWO);
            events.ScheduleEvent(EVENT_STAND_UP, 3s);
            events.ScheduleEvent(EVENT_CONCUSSIVE_STOMP, 7s, 0, PHASE_TWO);
            if (IsHeroic())
                events.ScheduleEvent(EVENT_UNLEASHED_FLAME, 1s, 0, PHASE_TWO);
        }

        // Ensure that Lord Rhyolith has transformed into his final entry before dying so achievements and credits work properly.
        if (damage >= me->GetHealth() && _transformationCount < 3)
            damage = me->GetHealth() - 1;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DROP_MOLTEN_ARMOR_CHARGE:
                if (Aura* armorAura = me->GetAura(SPELL_MOLTEN_ARMOR))
                    armorAura->ModStackAmount(-1);

                for (uint32 type : { DATA_LEFT_FOOT, DATA_RIGHT_FOOT })
                    if (Creature* foot = instance->GetCreature(type))
                        if (Aura* armorAura = foot->GetAura(SPELL_MOLTEN_ARMOR))
                            armorAura->ModStackAmount(-1);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_CURRENT_BALANCE:
                return _currentBalance;
            default:
                return 0;
        }

        return 0;
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_RECENTLY_BROKEN_VOLCANO:
                if (_recentlyBrokenVolcanos.empty())
                    return ObjectGuid::Empty;
                return _recentlyBrokenVolcanos.front();
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
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
                case EVENT_CONCUSSIVE_STOMP:
                    Talk(SAY_CONCUSSIVE_STOMP);
                    DoCastAOE(SPELL_CONCUSSIVE_STOMP);
                    events.Repeat(30s);
                    break;
                case EVENT_UPDATE_BALANCE:
                {
                    uint32 damageLeft = 0;
                    uint32 damageRight = 0;
                    int16 balanceOffset = 0;

                    if (Creature* footLeft = instance->GetCreature(DATA_LEFT_FOOT))
                        if (CreatureAI* ai = footLeft->AI())
                            damageLeft = ai->GetData(DATA_DAMAGE_PER_SECOND);

                    if (Creature* footRight = instance->GetCreature(DATA_RIGHT_FOOT))
                        if (CreatureAI* ai = footRight->AI())
                            damageRight = ai->GetData(DATA_DAMAGE_PER_SECOND);

                    if (damageLeft != damageRight)
                    {
                        uint8 is25ManRaid = Is25ManRaid();
                        balanceOffset -= uint8(static_cast<float>(damageLeft) / BalanceDamageThresholds[is25ManRaid]);
                        balanceOffset += uint8(static_cast<float>(damageRight) / BalanceDamageThresholds[is25ManRaid]);
                    }

                    _currentBalance = std::clamp<int8>(CENTER_BALANCE + balanceOffset, MIN_LEFT_BALANCE, MAX_RIGHT_BALANCE);

                    if (!_achievementFailed && _currentBalance < CENTER_BALANCE)
                    {
                        instance->DoUpdateWorldState(WORLD_STATE_ID_NOT_AN_AMBI_TURNER, 1);
                        _achievementFailed = true;
                    }

                    // Balance updated, update player power
                    for (auto const& i : me->GetMap()->GetPlayers())
                        if (Player* player = i.GetSource())
                            player->SetPower(POWER_ALTERNATE_POWER, _currentBalance);

                    events.Repeat(500ms); // The timer for this event is very inconsistent in sniffs
                    break;
                }
                case EVENT_HEATED_VOLCANO:
                    Talk(SAY_HEATED_VOLCANO);
                    DoCastAOE(SPELL_HEATED_VOLCANO, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    events.Repeat(25s);
                    break;
                case EVENT_BALANCE_FEET_HEALTH:
                {
                    Creature* footLeft = instance->GetCreature(DATA_LEFT_FOOT);
                    Creature* footRight = instance->GetCreature(DATA_RIGHT_FOOT);

                    if (!footLeft || !footRight)
                    {
                        // One of the feet is missing. Encounter broke. Reset.
                        EnterEvadeMode(EVADE_REASON_OTHER);
                        break;
                    }

                    float targetHealthPct = (footLeft->GetHealthPct() + footRight->GetHealthPct()) / 2;
                    footLeft->SetHealth(CalculatePct(footLeft->GetMaxHealth(), targetHealthPct));
                    footRight->SetHealth(CalculatePct(footRight->GetMaxHealth(), targetHealthPct));

                    // Deal damage to trigger the damage taken hook, which manages the model changes and phase switch
                    if (targetHealthPct < me->GetHealthPct())
                        Unit::DealDamage(me, me, CalculatePct(me->GetMaxHealth(), me->GetHealthPct() - targetHealthPct));
                    events.Repeat(5s);
                    break;
                }
                case EVENT_LAVA_LINE:
                    if (!_recentlyBrokenVolcanos.empty())
                    {
                        DoCastAOE(SPELL_LAVA_LINE);
                        _recentlyBrokenVolcanos.pop();
                    }
                    events.Repeat(10s);
                    break;
                case EVENT_THERMAL_VENT:
                    DoCastAOE(SPELL_SUMMON_ROCK_ELEMENTALS);
                    events.Repeat(23s);
                    break;
                case EVENT_STAND_UP:
                    me->SetAIAnimKitId(0);
                    events.ScheduleEvent(EVENT_TURN_AGGRESSIVE, 3s + 600ms);
                    break;
                case EVENT_TURN_AGGRESSIVE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_UNLEASHED_FLAME:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.f, true))
                        DoCast(target, SPELL_UNLEASHED_FLAME);
                    events.Repeat(6s);
                    break;
                case EVENT_SUPERHEATED:
                    DoCastSelf(SPELL_SUPERHEATED);
                    events.Repeat(10s);
                    break;
                case EVENT_SEARCH_FOR_VOLANOS:
                {
                    // There does not seem to be any serverside spell for searching for volcanos, so we have to do it like this
                    bool isOnAVolcano = false;
                    for (ObjectGuid const& summonGuid : summons)
                    {
                        Creature* summon = ObjectAccessor::GetCreature(*me, summonGuid);
                        if (!summon || summon->GetOriginalEntry() != NPC_VOLCANO)
                            continue;

                        if (summon->GetEntry() == NPC_VOLCANO || summon->GetEntry() == NPC_VOLCANO_HEATED || summon->GetEntry() == NPC_VOLCANO_CRATER)
                        {
                            if (me->GetExactDist2d(summon) < 10.f)
                            {
                                if (summon->GetEntry() == NPC_VOLCANO || summon->GetEntry() == NPC_VOLCANO_HEATED)
                                {
                                    // Volcano has been heated, the Obsidian Armor is being weakened
                                    if (summon->GetEntry() == NPC_VOLCANO_HEATED)
                                    {
                                        Talk(SAY_ANNOUNCE_ARMOR_WEAKENED);
                                        Talk(SAY_ARMOR_WEAKENED);
                                        if (Aura* armorAura = me->GetAura(SPELL_OBSIDIAN_ARMOR, me->GetGUID()))
                                            armorAura->ModStackAmount(-16);

                                        for (uint32 type : { DATA_LEFT_FOOT, DATA_RIGHT_FOOT })
                                        {
                                            if (Creature* foot = instance->GetCreature(type))
                                            {
                                                if (Aura* armorAura = foot->GetAura(SPELL_OBSIDIAN_ARMOR))
                                                    armorAura->ModStackAmount(-16);

                                                if (CreatureAI* ai = foot->AI())
                                                    ai->DoAction(ACTION_RECALCULATE_DAMAGE_REDUCTION_MOD);
                                            }
                                        }

                                        if (IsHeroic())
                                            for (uint8 i = 0; i < 5; ++i)
                                                DoCastSelf(SPELL_SUMMON_ARMOR_FRAGMENT);
                                    }

                                    if (CreatureAI* ai = summon->AI())
                                    {
                                        ai->DoAction(ACTION_DESTROY_VOLCANO);
                                        _recentlyBrokenVolcanos.push(summonGuid);
                                        if (!_hasBrokenFirstVolcano)
                                        {
                                            _hasBrokenFirstVolcano = true;
                                            events.ScheduleEvent(EVENT_LAVA_LINE, 11s);
                                        }
                                    }
                                }

                                isOnAVolcano = true;
                            }
                        }
                    }

                    if (isOnAVolcano && !_hasBurningFeet)
                    {
                        DoCastSelf(SPELL_BURNING_FEET);

                        for (uint32 type : { DATA_LEFT_FOOT, DATA_RIGHT_FOOT })
                            if (Creature* foot = instance->GetCreature(type))
                                foot->CastSpell(nullptr, SPELL_BURNING_FEET);

                        _hasBurningFeet = true;
                    }
                    else if (!isOnAVolcano && _hasBurningFeet)
                    {
                        me->RemoveAurasDueToSpell(SPELL_BURNING_FEET);
                        for (uint32 type : { DATA_LEFT_FOOT, DATA_RIGHT_FOOT })
                            if (Creature* foot = instance->GetCreature(type))
                                foot->RemoveAurasDueToSpell(SPELL_BURNING_FEET);

                        _hasBurningFeet = false;
                    }

                    events.Repeat(500ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
private:
    void CleanupEncounter()
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        for (uint32 type : { DATA_LEFT_FOOT, DATA_RIGHT_FOOT })
        {
            if (Creature* foot = instance->GetCreature(type))
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, foot);
        }

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BALANCE_BAR);
        summons.DespawnAll();
    }

    uint8 _currentBalance;
    uint8 _transformationCount;
    bool _hasBrokenFirstVolcano;
    bool _achievementFailed;
    bool _hasBurningFeet; // used instead of HasAura(SPELL_BURNING_FEET) to increase performance
    std::queue<ObjectGuid> _recentlyBrokenVolcanos;
};

static Optional<Position> GetIntersectionPoint(Position const& start, Position const& dest, Position const& center, float radius)
{
    Position dp;
    dp.m_positionX = dest.GetPositionX() - start.GetPositionX();
    dp.m_positionY = dest.GetPositionY() - start.GetPositionY();

    float a, b, c;
    float bb4ac;
    float mu1;

    a = dp.m_positionX * dp.m_positionX + dp.m_positionY * dp.m_positionY;
    b = 2 * (dp.m_positionX * (start.m_positionX - center.m_positionX) + dp.m_positionY * (start.m_positionY - center.m_positionY));
    c = center.m_positionX * center.m_positionX + center.m_positionY * center.m_positionY;
    c += start.m_positionX * start.m_positionX + start.m_positionY * start.m_positionY;
    c -= 2 * (center.m_positionX * start.m_positionX + center.m_positionY * start.m_positionY);
    c -= radius * radius;
    bb4ac = b * b - 4 * a * c;

    // No intersections, return nullopt
    if (std::fabs(a) < std::numeric_limits<float>::epsilon() || bb4ac < 0)
        return std::nullopt;

    mu1 = (-b + std::sqrt(bb4ac)) / (2 * a);

    return Position(start.m_positionX + mu1 * (dest.m_positionX - start.m_positionX), start.m_positionY + mu1 * (dest.m_positionY - start.m_positionY), PlateauPlatformCenterPosition.GetPositionZ());
}

struct npc_rhyolith_movement_controller_lord_rhyolith : public NullCreatureAI
{
    npc_rhyolith_movement_controller_lord_rhyolith(Creature* creature) : NullCreatureAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ENCOUNTER_STARTED:
                // Launch an initial spline for the boss
                _events.ScheduleEvent(EVENT_MOVE_LORD_RHYOLITH, 1ms);
                _events.ScheduleEvent(EVENT_TELEPORT, 1s);
                break;
            case ACTION_STOP_MOVEMENT_CONTROL:
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TELEPORT:
                    if (Creature* rhyolith = _instance->GetCreature(DATA_LORD_RHYOLITH))
                    {
                        if (!rhyolith->IsAIEnabled())
                            break;

                        float angle = rhyolith->GetOrientation();
                        uint32 balance = rhyolith->AI()->GetData(DATA_CURRENT_BALANCE);

                        if (balance < 25)
                            angle += CalculatePct(float(M_PI_4), uint32(25) - balance);
                        else if (balance > 25)
                            angle -= CalculatePct(float(M_PI_4), balance - uint32(25));

                        Position lineDest = rhyolith->GetPosition();
                        lineDest.m_positionX += 1.f * std::cos(angle);
                        lineDest.m_positionY += 1.f * std::sin(angle);

                        Optional<Position> destination = GetIntersectionPoint(rhyolith->GetPosition(), lineDest, PlateauPlatformCenterPosition, PlateauRadius);
                        if (!destination.has_value())
                        {
                            // No intersections. The boss literally broke. Time for a reset.
                            if (CreatureAI* ai = rhyolith->AI())
                                ai->EnterEvadeMode();
                            break;
                        }

                        Position previousPosition = me->GetPosition();

                        me->NearTeleportTo(*destination);

                        if (*destination != previousPosition)
                            _events.RescheduleEvent(EVENT_MOVE_LORD_RHYOLITH, 400ms);

                        _events.Repeat(1s);
                    }
                    break;
                case EVENT_MOVE_LORD_RHYOLITH:
                    if (Creature* rhyolith = _instance->GetCreature(DATA_LORD_RHYOLITH))
                    {
                        if (!rhyolith->IsMovementPreventedByCasting())
                            rhyolith->GetMotionMaster()->MovePoint(POINT_DRINK_MAGMA, me->GetPosition());
                        else
                            _events.RescheduleEvent(EVENT_MOVE_LORD_RHYOLITH, 400ms);
                    }
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_rhyolith_foot : public NullCreatureAI
{
    npc_rhyolith_foot(Creature* creature) : NullCreatureAI(creature), _damageCleanupTimer(500), _damageReductionModifier(0.f)
    {
        _damagePerSecond = { };
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        _damagePerSecond[0] += CalculatePct(damage, 100.f + _damageReductionModifier);

        if (damage >= me->GetHealth())
            damage = me->GetHealth() - 1;
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_DAMAGE_PER_SECOND:
                return _damagePerSecond[0] + _damagePerSecond[1];
            default:
                return 0;
        }

        return 0;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RECALCULATE_DAMAGE_REDUCTION_MOD:
                _damageReductionModifier = 100.f * (1.f - me->GetTotalAuraMultiplier(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, [&](AuraEffect const* aurEff)
                {
                    return aurEff->GetSpellInfo()->Id == SPELL_OBSIDIAN_ARMOR;
                }));
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        // We store the damage of the past second in two array slots so each stores the last second for a more smooth result
        _damageCleanupTimer -= diff;
        if (_damageCleanupTimer <= 0)
        {
            _damagePerSecond[1] = _damagePerSecond[0];
            _damagePerSecond[0] = 0;
            _damageCleanupTimer += 1 * IN_MILLISECONDS;
        }
    }

private:
    int32 _damageCleanupTimer;
    float _damageReductionModifier;
    std::array<uint32, 2> _damagePerSecond;
};

struct npc_rhyolith_volcano : public NullCreatureAI
{
    npc_rhyolith_volcano(Creature* creature) : NullCreatureAI(creature) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_VOLCANO:
                me->UpdateEntry(NPC_VOLCANO_HEATED, nullptr, false);
                if (CreatureTemplate const* transformTemplate = sObjectMgr->GetCreatureTemplate(NPC_VOLCANO_HEATED))
                    me->SetDisplayId(transformTemplate->Modelid2);
                _events.ScheduleEvent(EVENT_ERUPTION, 5s);
                break;
            case ACTION_SCHEDULE_MAGMA_FLOW:
                _events.ScheduleEvent(EVENT_MAGMA_FLOW, 4s);
                break;
            case ACTION_DESTROY_VOLCANO:
                _events.CancelEvent(EVENT_ERUPTION);
                me->RemoveAurasDueToSpell(SPELL_VOLCANO_BASE);
                me->RemoveAurasDueToSpell(SPELL_ERUPTION);
                DoCastSelf(SPELL_EXPLOSION);
                DoCastSelf(SPELL_MAGMA);

                me->UpdateEntry(NPC_VOLCANO_CRATER, nullptr, false);
                if (CreatureTemplate const* transformTemplate = sObjectMgr->GetCreatureTemplate(NPC_VOLCANO_CRATER))
                    me->SetDisplayId(transformTemplate->Modelid2);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ERUPTION:
                    DoCastSelf(SPELL_ERUPTION);
                    break;
                case EVENT_MAGMA_FLOW:
                    DoCastSelf(SPELL_MAGMA_FLOW);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

struct npc_rhyolith_liquid_obsidian : public PassiveAI
{
    npc_rhyolith_liquid_obsidian(Creature* creature) : PassiveAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_FUSE_WITH_LORD_RHYOLITH, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FUSE_WITH_LORD_RHYOLITH:
                    if (Creature* rhyolith = _instance->GetCreature(DATA_LORD_RHYOLITH))
                    {
                        if (me->GetExactDist2d(rhyolith) < 10.f)
                            DoCastSelf(SPELL_FUSE);
                        else
                        {
                            me->GetMotionMaster()->MovePoint(POINT_NONE, rhyolith->GetPosition());
                            _events.Repeat(1s);
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

class spell_rhyolith_drink_magma : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_MOLTEN_SPEW });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        target->SetFacingTo(target->GetAngle(PlateauPlatformCenterPosition));
        target->SetOrientation(target->GetAngle(PlateauPlatformCenterPosition));
        target->CastSpell(nullptr, SPELL_MOLTEN_SPEW);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_rhyolith_drink_magma::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_rhyolith_concussive_stomp : public SpellScript
{
    void StoreVolcanoTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint8 volcanoTargetCount = urand(2, 3);
        for (uint8 i = 0; i < volcanoTargetCount; ++i)
            _volcanoTargetGUIDs.emplace_back(Trinity::Containers::SelectRandomContainerElement(targets)->GetGUID());
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        Creature* caster = GetHitCreature();
        if (!caster)
            return;

        if (CreatureAI* ai = caster->AI())
            ai->DoAction(ACTION_DROP_MOLTEN_ARMOR_CHARGE);

        // The Volcanos are not getting summoned when Lord Rhyolith is in his final phase
        if (caster->GetEntry() == NPC_LORD_RHYOLITH_PHASE_TWO)
            return;

        for (ObjectGuid const& guid : _volcanoTargetGUIDs)
            if (Unit* target = ObjectAccessor::GetUnit(*caster, guid))
                caster->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_rhyolith_concussive_stomp::StoreVolcanoTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_rhyolith_concussive_stomp::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
private:
    std::vector<ObjectGuid> _volcanoTargetGUIDs;
};

class spell_rhyolith_heated_volcano : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ERUPTION });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // Hotfix (2011-07-06): Lord Rhyolith now prefers to activate volcanoes that are in front of him over volcanoes that are behind him.
        std::list<WorldObject*> targetsCopy = targets;
        targetsCopy.remove_if([&](WorldObject const* target)
        {
            return !GetCaster()->isInFront(target);
        });

        if (!targetsCopy.empty())
            targets = targetsCopy;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            if (CreatureAI* ai = target->AI())
                ai->DoAction(ACTION_ACTIVATE_VOLCANO);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_rhyolith_heated_volcano::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_rhyolith_heated_volcano::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_rhyolith_lava_strike_visual : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ frand(-20.f, 20.f), frand(-20.f, 20.f), frand(25.f, 70.f), 0.f });
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_rhyolith_lava_strike_visual::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_rhyolith_lava_strike: public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint8 size = GetCaster()->GetMap()->Is25ManRaid() ? 6 : 3;

        if (targets.size() > size)
            Trinity::Containers::RandomResize(targets, size);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_rhyolith_lava_strike::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_rhyolith_lava_strike::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_rhyolith_lava_line : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_TUBE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        if (CreatureAI* ai = caster->AI())
        {
            ObjectGuid volcanoGuid = ai->GetGUID(DATA_RECENTLY_BROKEN_VOLCANO);
            if (!volcanoGuid.IsEmpty())
                targets.remove_if([volcanoGuid](WorldObject const* target)
                {
                    return target->GetGUID() != volcanoGuid;
                });
        }
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Creature* target = GetHitCreature();
        if (!target || !caster)
            return;

        if (CreatureAI* ai = target->AI())
            ai->DoAction(ACTION_SCHEDULE_MAGMA_FLOW);

        Position summonDest = target->GetPosition();
        summonDest.m_positionZ -= 6.f;
        caster->CastSpell(summonDest, SPELL_SUMMON_TUBE);

    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_rhyolith_lava_line::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_rhyolith_lava_line::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

static constexpr float Magnitude = 1.f;  // Maximum wave outbreak

static Position GetSineWavePoint(Position const& origin, float angle, uint32 auraTickNumber, float frequency)
{
    float distance = static_cast<float>(auraTickNumber);
    Position point = origin;
    point.m_positionX += std::cos(angle) * distance;
    point.m_positionY += std::sin(angle) * distance;

    G3D::Vector2 perpendicularDirection(point.GetPositionY() - origin.GetPositionY(), -(point.GetPositionX() - origin.GetPositionX()));

    point.m_positionX += perpendicularDirection.direction().x * std::sin(auraTickNumber * frequency) * Magnitude;
    point.m_positionY += perpendicularDirection.direction().y * std::sin(auraTickNumber * frequency) * Magnitude;

    return point;
}

class spell_rhyolith_magma_flow : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MAGMA_FLOW_DAMAGE,
            SPELL_MAGMA_FLOW_MISSILE
        });
    }

    bool Load() override
    {
        _lineCount = urand(4, 6);
        _angleOffset = float(M_PI * 2) / _lineCount;
        _frequencyForLines.resize(_lineCount);
        for (float& frequency : _frequencyForLines)
            frequency = frand(0.1f, 0.5f);
        return true;
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        // The periodic casting stops at 8 seconds (40 ticks)
        if (aurEff->GetTickNumber() > 40)
        {
            if (!_detonated)
            {
                for (Position const& dest : _missileDestinations)
                    target->CastSpell(dest, SPELL_MAGMA_FLOW_DAMAGE);
                _detonated = true;
            }
            return;
        }

        for (uint8 i = 0; i < _lineCount; ++i)
        {
            float angle = _angleOffset * i;
            Position dest = GetSineWavePoint(target->GetPosition(), angle, aurEff->GetTickNumber(), _frequencyForLines[i]);

            // increase hight for proper ground snapping
            dest.m_positionZ += 5.f;
            dest.m_positionZ = target->GetMapHeight(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ());

            target->CastSpell(dest, SPELL_MAGMA_FLOW_MISSILE);

            // Store every 4th location for one final blast at the end
            if (!(aurEff->GetTickNumber() % 4))
                _missileDestinations.emplace_back(dest);
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAllDynObjects();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_rhyolith_magma_flow::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove.Register(&spell_rhyolith_magma_flow::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
private:
    bool _detonated = false;
    uint8 _lineCount = 0;
    float _angleOffset = 0.f;
    std::vector<Position> _missileDestinations;
    std::vector<float> _frequencyForLines;
};

class spell_rhyolith_immolation : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_INFERNAL_RAGE });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (!(aurEff->GetTickNumber() % 5))
            GetTarget()->CastSpell(nullptr, SPELL_INFERNAL_RAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_rhyolith_immolation::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_rhyolith_meltdown : public SpellScript
{
    void StoreTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
        _storedTargets = targets;
    }

    void PassTargets(std::list<WorldObject*>& targets)
    {
        targets.clear();
        targets = _storedTargets;
    }


    void CalculateDamage()
    {
        Unit* caster = GetCaster();
        damage = CalculatePct(caster->GetHealth(), GetSpellInfo()->Effects[EFFECT_0].BasePoints);
    }

    void ModifyDamage(SpellEffIndex /*effIndex*/)
    {
        SetEffectValue(damage);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_rhyolith_meltdown::StoreTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_rhyolith_meltdown::PassTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        BeforeCast.Register(&spell_rhyolith_meltdown::CalculateDamage);
        OnEffectLaunchTarget.Register(&spell_rhyolith_meltdown::ModifyDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
private:
    int32 damage = 0;
    std::list<WorldObject*> _storedTargets;
};

class spell_rhyolith_summon_rock_elementals : public SpellScript
{
    void StoreElementalTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        _summonSpellId = RAND(GetSpellInfo()->Effects[EFFECT_0].BasePoints, GetSpellInfo()->Effects[EFFECT_1].BasePoints);

        uint8 elementalTargetCount = _summonSpellId == SPELL_SUMMON_FRAGMENT_OF_RHYOLITH ? 5 : 1;
        for (uint8 i = 0; i < elementalTargetCount; ++i)
            _elementalTargetGUIDs.emplace_back(Trinity::Containers::SelectRandomContainerElement(targets)->GetGUID());
    }

    void SummonElementals()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Creature* creatureCaster = caster->ToCreature())
            if (CreatureAI* ai = creatureCaster->AI())
                ai->DoAction(ACTION_DROP_MOLTEN_ARMOR_CHARGE);

        for (ObjectGuid const& guid : _elementalTargetGUIDs)
            if (Unit* target = ObjectAccessor::GetUnit(*caster, guid))
                caster->CastSpell(target, _summonSpellId);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_rhyolith_summon_rock_elementals::StoreElementalTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        AfterCast.Register(&spell_rhyolith_summon_rock_elementals::SummonElementals);
    }

private:
    std::vector<ObjectGuid> _elementalTargetGUIDs;
    uint32 _summonSpellId = 0;
};

void AddSC_boss_lord_rhyolith()
{
    RegisterFirelandsCreatureAI(boss_lord_rhyolith);
    RegisterFirelandsCreatureAI(npc_rhyolith_movement_controller_lord_rhyolith);
    RegisterFirelandsCreatureAI(npc_rhyolith_foot);
    RegisterFirelandsCreatureAI(npc_rhyolith_volcano);
    RegisterFirelandsCreatureAI(npc_rhyolith_liquid_obsidian);
    RegisterSpellScript(spell_rhyolith_drink_magma);
    RegisterSpellScript(spell_rhyolith_concussive_stomp);
    RegisterSpellScript(spell_rhyolith_heated_volcano);
    RegisterSpellScript(spell_rhyolith_lava_strike_visual);
    RegisterSpellScript(spell_rhyolith_lava_strike);
    RegisterSpellScript(spell_rhyolith_lava_line);
    RegisterSpellScript(spell_rhyolith_magma_flow);
    RegisterSpellScript(spell_rhyolith_immolation);
    RegisterSpellScript(spell_rhyolith_meltdown);
    RegisterSpellScript(spell_rhyolith_summon_rock_elementals);
}

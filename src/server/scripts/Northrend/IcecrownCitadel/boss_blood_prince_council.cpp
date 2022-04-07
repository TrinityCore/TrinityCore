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

#include "ScriptMgr.h"
#include "icecrown_citadel.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Texts
{
    // Blood Queen Lana'Thel
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,

    // Prince Keleseth
    SAY_KELESETH_INVOCATION     = 0,
    EMOTE_KELESETH_INVOCATION   = 1,
    SAY_KELESETH_SPECIAL        = 2,
    SAY_KELESETH_KILL           = 3,
    EMOTE_KELESETH_BERSERK      = 4,
    SAY_KELESETH_DEATH          = 5,

    // Prince Taldaram
    SAY_TALDARAM_INVOCATION     = 0,
    EMOTE_TALDARAM_INVOCATION   = 1,
    SAY_TALDARAM_SPECIAL        = 2,
    EMOTE_TALDARAM_FLAME        = 3,
    SAY_TALDARAM_KILL           = 4,
    EMOTE_TALDARAM_BERSERK      = 5,
    EMOTE_TALDARAM_DEATH        = 6,

    // Prince Valanar
    SAY_VALANAR_INVOCATION      = 0,
    EMOTE_VALANAR_INVOCATION    = 1,
    SAY_VALANAR_SPECIAL         = 2,
    EMOTE_VALANAR_SHOCK_VORTEX  = 3,
    SAY_VALANAR_KILL            = 4,
    SAY_VALANAR_BERSERK         = 5,
    SAY_VALANAR_DEATH           = 6
};

enum Spells
{
    SPELL_FEIGN_DEATH                   = 71598,
    SPELL_OOC_INVOCATION_VISUAL         = 70934,
    SPELL_INVOCATION_VISUAL_ACTIVE      = 71596,

    // Heroic mode
    SPELL_SHADOW_PRISON                 = 72998,
    SPELL_SHADOW_PRISON_DAMAGE          = 72999,
    SPELL_SHADOW_PRISON_DUMMY           = 73001,

    // Prince Keleseth
    SPELL_INVOCATION_OF_BLOOD_KELESETH  = 70981,
    SPELL_SHADOW_RESONANCE              = 71943,
    SPELL_SHADOW_LANCE                  = 71405,
    SPELL_EMPOWERED_SHADOW_LANCE        = 71815,

    // Dark Nucleus
    SPELL_SHADOW_RESONANCE_AURA         = 72980,
    SPELL_SHADOW_RESONANCE_RESIST       = 71822,

    // Prince Taldaram
    SPELL_INVOCATION_OF_BLOOD_TALDARAM  = 70982,
    SPELL_GLITTERING_SPARKS             = 71806,
    SPELL_CONJURE_FLAME                 = 71718,
    SPELL_CONJURE_EMPOWERED_FLAME       = 72040,

    // Ball of Flame
    SPELL_FLAME_SPHERE_SPAWN_EFFECT     = 55891,
    SPELL_BALL_OF_FLAMES_VISUAL         = 71706,
    SPELL_BALL_OF_FLAMES                = 71714,
    SPELL_FLAMES                        = 71393,
    SPELL_FLAME_SPHERE_DEATH_EFFECT     = 55947,

    // Ball of Inferno Flame
    SPELL_BALL_OF_FLAMES_PROC           = 71756,
    SPELL_BALL_OF_FLAMES_PERIODIC       = 71709,

    // Prince Valanar
    SPELL_INVOCATION_OF_BLOOD_VALANAR   = 70952,
    SPELL_KINETIC_BOMB_TARGET           = 72053,
    SPELL_KINETIC_BOMB                  = 72080,
    SPELL_SHOCK_VORTEX                  = 72037,
    SPELL_EMPOWERED_SHOCK_VORTEX        = 72039,
    SPELL_REMOVE_EMPOWERED_BLOOD        = 72131,

    // Kinetic Bomb
    SPELL_UNSTABLE                      = 72059,
    SPELL_KINETIC_BOMB_VISUAL           = 72054,
    SPELL_KINETIC_BOMB_EXPLOSION        = 72052,
    SPELL_KINETIC_BOMB_KNOCKBACK        = 72087,

    // Shock Vortex
    SPELL_SHOCK_VORTEX_PERIODIC         = 71945,
    SPELL_SHOCK_VORTEX_DUMMY            = 72633,

    // Visual Spells
    SPELL_INVOCATION_VISUAL_VALANAR     = 71070,
    SPELL_INVOCATION_VISUAL_TALDARAM    = 71081,
    SPELL_INVOCATION_VISUAL_KELESETH    = 71080
};

enum Events
{
    EVENT_INTRO_1               = 1,
    EVENT_INTRO_2,

    EVENT_INVOCATION_OF_BLOOD,
    EVENT_BERSERK,

    // Keleseth
    EVENT_SHADOW_RESONANCE,
    EVENT_SHADOW_LANCE,

    // Taldaram
    EVENT_GLITTERING_SPARKS,
    EVENT_CONJURE_FLAME,

    // Valanar
    EVENT_KINETIC_BOMB,
    EVENT_SHOCK_VORTEX,
    EVENT_BOMB_DESPAWN,
    EVENT_CONTINUE_FALLING
};

enum Actions
{
    ACTION_START_INTRO          = 1,
    ACTION_INTRO_DONE,
    ACTION_STAND_UP,
    ACTION_CAST_INVOCATION,
    ACTION_REMOVE_INVOCATION,
    ACTION_KINETIC_BOMB_JUMP,
    ACTION_FLAME_BALL_CHASE
};

enum Points
{
    POINT_INTRO_DESPAWN         = 380040,
    POINT_KINETIC_BOMB_IMPACT   = 384540
};

enum Misc
{
    DISPLAY_KINETIC_BOMB        = 31095,
    SUMMON_PRINCES_GROUP        = 1,
    DATA_INTRO                  = 2,
    DATA_INTRO_DONE             = 3,
    DATA_PRINCE_EVADE           = 4
};

class StandUpEvent : public BasicEvent
{
    public:
        StandUpEvent(Creature* owner) : BasicEvent(), _owner(owner) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
        {
            _owner->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            _owner->SetReactState(REACT_AGGRESSIVE);
            return true;
        }

    private:
        Creature* _owner;
};

class VortexEvent : public BasicEvent
{
public:
    VortexEvent(Creature* owner) : _owner(owner) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_SHOCK_VORTEX_PERIODIC, true);
            return true;
        }

private:
    Creature* _owner;
};

Position const introFinalPos = {4660.490f, 2769.200f, 430.0000f, 0.000000f};
Position const triggerPos    = {4680.231f, 2769.134f, 379.9256f, 3.121708f};
Position const triggerEndPos = {4680.180f, 2769.150f, 365.5000f, 3.121708f};

uint32 const PrincesData[] =
{
    DATA_PRINCE_KELESETH,
    DATA_PRINCE_TALDARAM,
    DATA_PRINCE_VALANAR
};

struct boss_blood_council_controller : public BossAI
{
    boss_blood_council_controller(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
    {
        Initialize();
        SetCombatMovement(false);
    }

    void Initialize()
    {
        _invocationStage = 0;
        _resetCounter = 0;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        me->SummonCreatureGroup(SUMMON_PRINCES_GROUP);

        if (!instance->GetData(DATA_BLOOD_PRINCE_COUNCIL_INTRO))
            for (uint32 bossData : PrincesData)
                if (Creature* prince = ObjectAccessor::GetCreature(*me, instance->GetGuidData(bossData)))
                {
                    prince->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    prince->SetImmuneToPC(false);
                    if (bossData == DATA_PRINCE_VALANAR)
                    {
                        prince->SetHealth(prince->GetMaxHealth());
                        prince->CastSpell(prince, SPELL_REMOVE_EMPOWERED_BLOOD, true);
                    }
                }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        for (uint32 bossData : PrincesData)
            if (Creature* prince = ObjectAccessor::GetCreature(*me, instance->GetGuidData(bossData)))
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, prince);

        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        if (instance->GetBossState(DATA_BLOOD_PRINCE_COUNCIL) == IN_PROGRESS)
            return;

        if (!instance->CheckRequiredBosses(DATA_BLOOD_PRINCE_COUNCIL, who->ToPlayer()))
        {
            EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
            instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
            return;
        }

        me->SetCombatPulseDelay(5);
        me->setActive(true);
        DoZoneInCombat();
        instance->SetBossState(DATA_BLOOD_PRINCE_COUNCIL, IN_PROGRESS);

        DoCastSelf(SPELL_INVOCATION_OF_BLOOD_VALANAR);

        for (uint32 bossData : PrincesData)
            if (Creature* prince = ObjectAccessor::GetCreature(*me, instance->GetGuidData(bossData)))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, prince);
                DoZoneInCombat(prince);
            }

        events.ScheduleEvent(EVENT_INVOCATION_OF_BLOOD, Seconds(46) + Milliseconds(500));

        _invocationOrder[0] = InvocationData(instance->GetGuidData(DATA_PRINCE_VALANAR), SPELL_INVOCATION_OF_BLOOD_VALANAR, EMOTE_VALANAR_INVOCATION, SPELL_INVOCATION_VISUAL_VALANAR);
        if (roll_chance_i(50))
        {
            _invocationOrder[1] = InvocationData(instance->GetGuidData(DATA_PRINCE_TALDARAM), SPELL_INVOCATION_OF_BLOOD_TALDARAM, EMOTE_TALDARAM_INVOCATION, SPELL_INVOCATION_VISUAL_TALDARAM);
            _invocationOrder[2] = InvocationData(instance->GetGuidData(DATA_PRINCE_KELESETH), SPELL_INVOCATION_OF_BLOOD_KELESETH, EMOTE_KELESETH_INVOCATION, SPELL_INVOCATION_VISUAL_KELESETH);
        }
        else
        {
            _invocationOrder[1] = InvocationData(instance->GetGuidData(DATA_PRINCE_KELESETH), SPELL_INVOCATION_OF_BLOOD_KELESETH, EMOTE_KELESETH_INVOCATION, SPELL_INVOCATION_VISUAL_KELESETH);
            _invocationOrder[2] = InvocationData(instance->GetGuidData(DATA_PRINCE_TALDARAM), SPELL_INVOCATION_OF_BLOOD_TALDARAM, EMOTE_TALDARAM_INVOCATION, SPELL_INVOCATION_VISUAL_TALDARAM);
        }
    }

    void SetData(uint32 /*type*/, uint32 data) override
    {
        _resetCounter += uint8(data);
        if (_resetCounter == 3)
            EnterEvadeMode(EVADE_REASON_OTHER);
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_INTRO && !instance->GetData(DATA_BLOOD_PRINCE_COUNCIL_INTRO))
            return DATA_INTRO_DONE;
        return 0;
    }

    void JustDied(Unit* killer) override
    {
        events.Reset();
        instance->SetBossState(DATA_BLOOD_PRINCE_COUNCIL, DONE);
        // Kill all prices
        for (uint8 i = 0; i < 3; ++i)
        {
            if (++_invocationStage == 3)
                _invocationStage = 0;

            if (Creature* prince = ObjectAccessor::GetCreature(*me, _invocationOrder[_invocationStage].guid))
            {
                // Make sure looting is allowed
                if (me->IsDamageEnoughForLootingAndReward())
                    prince->LowerPlayerDamageReq(prince->GetMaxHealth());
                Unit::Kill(killer, prince);
            }
        }
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_START_INTRO && instance->GetData(DATA_BLOOD_PRINCE_COUNCIL_INTRO) && instance->GetBossState(DATA_BLOOD_PRINCE_COUNCIL) != DONE)
        {
            instance->SetData(DATA_BLOOD_PRINCE_COUNCIL_INTRO, 0);
            if (Creature* bloodQueen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_QUEEN_LANA_THEL_COUNCIL)))
                bloodQueen->AI()->DoAction(ACTION_START_INTRO);
        }
        else if (actionId == ACTION_INTRO_DONE)
        {
            // Remove feigh death from princes
            for (uint32 bossData : PrincesData)
                if (Creature* prince = ObjectAccessor::GetCreature(*me, instance->GetGuidData(bossData)))
                {
                    prince->AI()->DoAction(ACTION_STAND_UP);
                    if (bossData == DATA_PRINCE_VALANAR)
                        prince->SetHealth(prince->GetMaxHealth());
                }
        }
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
                case EVENT_INVOCATION_OF_BLOOD:
                {
                    Creature* oldPrince = ObjectAccessor::GetCreature(*me, _invocationOrder[_invocationStage].guid);
                    if (++_invocationStage == 3)
                        _invocationStage = 0;

                    Creature* newPrince = ObjectAccessor::GetCreature(*me, _invocationOrder[_invocationStage].guid);
                    if (oldPrince)
                    {
                        oldPrince->AI()->DoAction(ACTION_REMOVE_INVOCATION);
                        if (newPrince)
                            oldPrince->CastSpell(newPrince, _invocationOrder[_invocationStage].visualSpell, true);
                    }

                    if (newPrince)
                    {
                        newPrince->SetHealth(me->GetHealth());
                        newPrince->AI()->Talk(uint8(_invocationOrder[_invocationStage].textId));
                    }

                    DoCastSelf(_invocationOrder[_invocationStage].spellId);
                    events.Repeat(Seconds(46) + Milliseconds(500));
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    struct InvocationData
    {
        ObjectGuid guid;
        uint32 spellId;
        uint32 textId;
        uint32 visualSpell;

        InvocationData(ObjectGuid _guid, uint32 _spellId, uint32 _textId, uint32 _visualSpell)
        {
            guid = _guid;
            spellId = _spellId;
            textId = _textId;
            visualSpell = _visualSpell;
        }

        InvocationData() : spellId(0), textId(0), visualSpell(0) { }
    } _invocationOrder[3];

    uint32 _invocationStage;
    uint32 _resetCounter;
};

struct BloodPrincesBossAI : public BossAI
{
    BloodPrincesBossAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _spawnHealth (creature->GetMaxHealth()), _isEmpowered(false)
    {
        SetBoundary(instance->GetBossBoundary(DATA_BLOOD_PRINCE_COUNCIL));
    }

    void InitializeAI() override
    {
        _spawnHealth = 1;
        if (!me->isDead())
            JustAppeared();
    }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
        me->SetCombatPulseDelay(0);

        me->SetImmuneToPC(false);
        _isEmpowered = false;
        me->SetHealth(_spawnHealth);
        instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
            DoZoneInCombat(controller);
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustDied(Unit* /*killer*/) override
    {
        events.Reset();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        switch (me->GetEntry())
        {
            case NPC_PRINCE_KELESETH:
                Talk(SAY_KELESETH_DEATH);
                break;
            case NPC_PRINCE_TALDARAM:
                Talk(EMOTE_TALDARAM_DEATH);
                break;
            case NPC_PRINCE_VALANAR:
                Talk(SAY_VALANAR_DEATH);
                break;
            default:
                break;
        }
    }

    void JustAppeared() override
    {
        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
            if (controller->AI()->GetData(DATA_INTRO) != DATA_INTRO_DONE)
                DoCastSelf(SPELL_FEIGN_DEATH);

        me->SetHealth(_spawnHealth);
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isEmpowered)
        {
            AddThreat(attacker, float(damage));
            damage = 0;
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            switch (me->GetEntry())
            {
                case NPC_PRINCE_KELESETH:
                    Talk(SAY_KELESETH_KILL);
                    break;
                case NPC_PRINCE_TALDARAM:
                    Talk(SAY_TALDARAM_KILL);
                    break;
                case NPC_PRINCE_VALANAR:
                    Talk(SAY_VALANAR_KILL);
                    break;
                default:
                    break;
            }
    }

    void JustReachedHome() override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->SetHealth(_spawnHealth);
        _isEmpowered = false;
        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
        {
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            controller->AI()->SetData(DATA_PRINCE_EVADE, 1);
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SelectInvocationSpell())
            DoAction(ACTION_CAST_INVOCATION);
    }

    void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType) override
    {
        if (damageType != SPELL_DIRECT_DAMAGE)
            return;

        if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
            instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_STAND_UP:
                me->RemoveAurasDueToSpell(SPELL_FEIGN_DEATH);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetImmuneToPC(false);
                me->ForceValuesUpdateAtIndex(UNIT_NPC_FLAGS);   // was in sniff. don't ask why
                me->m_Events.AddEvent(new StandUpEvent(me), me->m_Events.CalculateTime(1s));
                break;
            case ACTION_CAST_INVOCATION:
                Talk(SelectInvocationSay());
                DoCastSelf(SPELL_INVOCATION_VISUAL_ACTIVE, true);
                _isEmpowered = true;
                break;
            case ACTION_REMOVE_INVOCATION:
                me->SetHealth(_spawnHealth);
                me->RemoveAurasDueToSpell(SPELL_INVOCATION_VISUAL_ACTIVE);
                me->RemoveAurasDueToSpell(SelectInvocationSpell());
                _isEmpowered = false;
                break;
            default:
                break;
        }
    }

    uint32 SelectInvocationSay()
    {
        switch (me->GetEntry())
        {
            case NPC_PRINCE_KELESETH:
                return SAY_KELESETH_INVOCATION;
            case NPC_PRINCE_TALDARAM:
                return SAY_TALDARAM_INVOCATION;
            case NPC_PRINCE_VALANAR:
                return SAY_KELESETH_INVOCATION;
            default: // Should never happen
                return 0;
        }
    }

    uint32 SelectInvocationSpell()
    {
        switch (me->GetEntry())
        {
            case NPC_PRINCE_KELESETH:
                return SPELL_INVOCATION_OF_BLOOD_KELESETH;
            case NPC_PRINCE_TALDARAM:
                return SPELL_INVOCATION_OF_BLOOD_TALDARAM;
            case NPC_PRINCE_VALANAR:
                return SPELL_INVOCATION_OF_BLOOD_VALANAR;
            default: // Should never happen
                return 0;
        }
    }

protected:
    uint32 _spawnHealth;
    bool _isEmpowered;
};

struct boss_prince_keleseth_icc : public BloodPrincesBossAI
{
    boss_prince_keleseth_icc(Creature* creature) : BloodPrincesBossAI(creature, DATA_PRINCE_KELESETH) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_BERSERK, 10min);
        events.ScheduleEvent(EVENT_SHADOW_RESONANCE, 10s, 15s);
        events.ScheduleEvent(EVENT_SHADOW_LANCE, 2s);

        if (IsHeroic())
        {
            DoCastSelf(SPELL_SHADOW_PRISON, true);
            DoCastSelf(SPELL_SHADOW_PRISON_DUMMY);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        Position pos = me->GetPosition();
        float maxRange = me->GetDistance2d(summon);
        float angle = me->GetAbsoluteAngle(summon);
        me->MovePositionToFirstCollision(pos, maxRange, angle);
        summon->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
        summon->ToTempSummon()->SetTempSummonType(TEMPSUMMON_CORPSE_DESPAWN);
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
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    Talk(EMOTE_KELESETH_BERSERK);
                    break;
                case EVENT_SHADOW_RESONANCE:
                    Talk(SAY_KELESETH_SPECIAL);
                    DoCastSelf(SPELL_SHADOW_RESONANCE);
                    events.Repeat(Seconds(10), Seconds(15));
                    break;
                case EVENT_SHADOW_LANCE:
                    _isEmpowered ? DoCastVictim(SPELL_EMPOWERED_SHADOW_LANCE) : DoCastVictim(SPELL_SHADOW_LANCE);
                    events.Repeat(Seconds(2));
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        // does not melee
    }
};

struct boss_prince_taldaram_icc : public BloodPrincesBossAI
{
    boss_prince_taldaram_icc(Creature* creature) : BloodPrincesBossAI(creature, DATA_PRINCE_TALDARAM) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_BERSERK, 10min);
        events.ScheduleEvent(EVENT_GLITTERING_SPARKS, 12s, 15s);
        events.ScheduleEvent(EVENT_CONJURE_FLAME, 20s);
        if (IsHeroic())
            DoCastSelf(SPELL_SHADOW_PRISON, true);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        Unit* target = SelectTarget(SelectTargetMethod::Random, 1, -10.0f, true); // first try at distance
        if (!target)
            target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true);     // too bad for you raiders, its going to boom

        if (summon->GetEntry() == NPC_BALL_OF_INFERNO_FLAME && target)
            Talk(EMOTE_TALDARAM_FLAME, target);

        if (target)
            summon->AI()->SetGUID(target->GetGUID());
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
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    Talk(EMOTE_TALDARAM_BERSERK);
                    break;
                case EVENT_GLITTERING_SPARKS:
                    DoCastVictim(SPELL_GLITTERING_SPARKS);
                    events.Repeat(Seconds(15), Seconds(50));
                    break;
                case EVENT_CONJURE_FLAME:
                    if (_isEmpowered)
                    {
                        DoCastSelf(SPELL_CONJURE_EMPOWERED_FLAME);
                        events.Repeat(Seconds(15), Seconds(25));
                    }
                    else
                    {
                        DoCastSelf(SPELL_CONJURE_FLAME);
                        events.Repeat(Seconds(20), Seconds(30));
                    }
                    Talk(SAY_TALDARAM_SPECIAL);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct boss_prince_valanar_icc : public BloodPrincesBossAI
{
    boss_prince_valanar_icc(Creature* creature) : BloodPrincesBossAI(creature, DATA_PRINCE_VALANAR) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_BERSERK, 10min);
        events.ScheduleEvent(EVENT_KINETIC_BOMB, 18s, 24s);
        events.ScheduleEvent(EVENT_SHOCK_VORTEX, 15s, 20s);
        if (IsHeroic())
            DoCastSelf(SPELL_SHADOW_PRISON, true);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_KINETIC_BOMB_TARGET:
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, SPELL_KINETIC_BOMB, me->GetGUID());
                break;
            case NPC_KINETIC_BOMB:
            {
                float x, y, z;
                summon->GetPosition(x, y, z);
                float ground_Z = summon->GetMap()->GetHeight(summon->GetPhaseMask(), x, y, z, true, 500.0f);
                summon->GetMotionMaster()->MovePoint(POINT_KINETIC_BOMB_IMPACT, x, y, ground_Z);
                summon->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                break;
            }
            case NPC_SHOCK_VORTEX:
                summon->CastSpell(summon, SPELL_SHOCK_VORTEX_DUMMY, true);
                summon->m_Events.AddEvent(new VortexEvent(summon), summon->m_Events.CalculateTime(5s));
                break;
            default:
                break;
        }

        summons.Summon(summon);
        if (me->IsInCombat())
            DoZoneInCombat(summon);
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
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    Talk(SAY_VALANAR_BERSERK);
                    break;
                case EVENT_KINETIC_BOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                    {
                        DoCast(target, SPELL_KINETIC_BOMB_TARGET);
                        Talk(SAY_VALANAR_SPECIAL);
                    }
                    events.Repeat(Seconds(18), Seconds(24));
                    break;
                case EVENT_SHOCK_VORTEX:
                    if (_isEmpowered)
                    {
                        DoCastSelf(SPELL_EMPOWERED_SHOCK_VORTEX);
                        Talk(EMOTE_VALANAR_SHOCK_VORTEX);
                        events.Repeat(Seconds(30));
                    }
                    else
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                            DoCast(target, SPELL_SHOCK_VORTEX);
                        events.Repeat(Seconds(18), Seconds(23));
                    }
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_blood_queen_lana_thel : public PassiveAI
{
    npc_blood_queen_lana_thel(Creature* creature) : PassiveAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        me->SetDisableGravity(true);
        _instance->GetBossState(DATA_BLOOD_PRINCE_COUNCIL) != DONE ? me->SetVisible(true) : me->SetVisible(false);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_INTRO:
                Talk(SAY_INTRO_1);
                _events.SetPhase(1);
                _events.ScheduleEvent(EVENT_INTRO_1, Seconds(14));
                // summon a visual trigger
                if (Creature* summon = DoSummon(NPC_FLOATING_TRIGGER, triggerPos, 15s, TEMPSUMMON_TIMED_DESPAWN))
                {
                    summon->CastSpell(summon, SPELL_OOC_INVOCATION_VISUAL, true);
                    summon->SetSpeedRate(MOVE_RUN, 0.14f);
                    summon->GetMotionMaster()->MovePoint(0, triggerEndPos);
                }
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_INTRO_DESPAWN)
            me->SetVisible(false);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_events.GetPhaseMask())
            return;

        _events.Update(diff);

        if (_events.ExecuteEvent() == EVENT_INTRO_1)
        {
            Talk(SAY_INTRO_2);
            me->GetMotionMaster()->MovePoint(POINT_INTRO_DESPAWN, introFinalPos);
            _events.Reset();

            if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                controller->AI()->DoAction(ACTION_INTRO_DONE);
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_ball_of_flame : public ScriptedAI
{
    npc_ball_of_flame(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        DoCastSelf(SPELL_FLAME_SPHERE_SPAWN_EFFECT, true);
        DoCastSelf(SPELL_BALL_OF_FLAMES_VISUAL, true);
        if (me->GetEntry() == NPC_BALL_OF_INFERNO_FLAME)
        {
            DoCastSelf(SPELL_BALL_OF_FLAMES_PROC, true);
            DoCastSelf(SPELL_BALL_OF_FLAMES_PERIODIC, true);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == CHASE_MOTION_TYPE && id == _chaseGUID.GetCounter() && _chaseGUID)
        {
            me->RemoveAurasDueToSpell(SPELL_BALL_OF_FLAMES_PERIODIC);
            DoCastSelf(SPELL_FLAMES);
            _scheduler.Schedule(Seconds(2), [this](TaskContext /*context*/)
            {
                DoCastSelf(SPELL_FLAME_SPHERE_DEATH_EFFECT);
            });
            _chaseGUID.Clear();
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        _chaseGUID = guid;
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_FLAME_BALL_CHASE)
            if (Player* target = ObjectAccessor::GetPlayer(*me, _chaseGUID))
            {
                // need to clear states now because this call is before AuraEffect is fully removed
                me->ClearUnitState(UNIT_STATE_CASTING | UNIT_STATE_STUNNED);
                if (me->Attack(target, true))
                    me->GetMotionMaster()->MoveChase(target, 1.0f);
            }
    }

    void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType) override
    {
        if (damageType != SPELL_DIRECT_DAMAGE)
            return;

        if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
            _instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    ObjectGuid _chaseGUID;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

struct npc_kinetic_bomb : public ScriptedAI
{
    npc_kinetic_bomb(Creature* creature) : ScriptedAI(creature), _x(0.f), _y(0.f), _groundZ(0.f) { }

    void Reset() override
    {
        _events.Reset();
        me->SetWalk(true);
        DoCastSelf(SPELL_UNSTABLE, true);
        DoCastSelf(SPELL_KINETIC_BOMB_VISUAL, true);
        me->SetReactState(REACT_PASSIVE);
        me->GetPosition(_x, _y, _groundZ);
        me->DespawnOrUnsummon(60s);
        _groundZ = me->GetMap()->GetHeight(me->GetPhaseMask(), _x, _y, _groundZ, true, 500.0f);
    }

    void DoAction(int32 action) override
    {
        if (action == SPELL_KINETIC_BOMB_EXPLOSION)
            _events.ScheduleEvent(EVENT_BOMB_DESPAWN, 1s);

        else if (action == ACTION_KINETIC_BOMB_JUMP)
        {
            if (!me->HasAura(SPELL_KINETIC_BOMB_KNOCKBACK))
            {
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveCharge(_x, _y, me->GetPositionZ() + 100.0f, me->GetSpeed(MOVE_RUN), POINT_KINETIC_BOMB_IMPACT);
            }
            _events.RescheduleEvent(EVENT_CONTINUE_FALLING, Seconds(3));
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BOMB_DESPAWN:
                    me->SetVisible(false);
                    me->DespawnOrUnsummon(5s);
                    break;
                case EVENT_CONTINUE_FALLING:
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveCharge(_x, _y, _groundZ, me->GetSpeed(MOVE_RUN), POINT_KINETIC_BOMB_IMPACT);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    float _x;
    float _y;
    float _groundZ;
};

struct npc_dark_nucleus : public ScriptedAI
{
    npc_dark_nucleus(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_DEFENSIVE);
        DoCastSelf(SPELL_SHADOW_RESONANCE_AURA, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        _scheduler.Schedule(Seconds(1), [this](TaskContext targetAuraCheck)
        {
            if (Unit* victim = me->GetVictim())
            {
                if (me->GetDistance(victim) < 15.0f && !victim->HasAura(SPELL_SHADOW_RESONANCE_RESIST, me->GetGUID()))
                    DoCast(victim, SPELL_SHADOW_RESONANCE_RESIST);
                else
                    MoveInLineOfSight(me->GetVictim());
            }
            targetAuraCheck.Repeat();
        });

        if (me->GetDistance(who) >= 15.0f)
        {
            DoStartMovement(who);
            return;
        }

        DoCast(who, SPELL_SHADOW_RESONANCE_RESIST);
    }

    void DamageTaken(Unit* attacker, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (attacker == me)
            return;

        me->GetThreatManager().ResetAllThreat();
        AddThreat(attacker, 500000000.0f);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 71806 - Glittering Sparks
class spell_taldaram_glittering_sparks : public SpellScript
{
    PrepareSpellScript(spell_taldaram_glittering_sparks);

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_taldaram_glittering_sparks::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/* 71718 - Conjure Flame
   72040 - Conjure Empowered Flame */
class spell_taldaram_summon_flame_ball : public SpellScript
{
    PrepareSpellScript(spell_taldaram_summon_flame_ball);

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_taldaram_summon_flame_ball::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/* 55891 - Flame Sphere Spawn Effect
   55947 - Flame Sphere Death Effect */
class spell_taldaram_flame_ball_visual : public AuraScript
{
    PrepareAuraScript(spell_taldaram_flame_ball_visual);

    bool Load() override
    {
        if (GetCaster()->GetEntry() == NPC_BALL_OF_FLAME || GetCaster()->GetEntry() == NPC_BALL_OF_INFERNO_FLAME)
            return true;
        return false;
    }

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BALL_OF_FLAMES });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* target = GetTarget()->ToCreature();
        if (!target)
            return;

        // SPELL_FLAME_SPHERE_SPAWN_EFFECT
        if (GetSpellInfo()->Id == SPELL_FLAME_SPHERE_SPAWN_EFFECT)
        {
            target->CastSpell(target, SPELL_BALL_OF_FLAMES, true);
            target->AI()->DoAction(ACTION_FLAME_BALL_CHASE);
        }
        else // SPELL_FLAME_SPHERE_DEATH_EFFECT
            target->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_taldaram_flame_ball_visual::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

/* 71756 - Ball of Flames Proc
   72782 - Ball of Flames Proc
   72783 - Ball of Flames Proc
   72784 - Ball of Flames Proc */
class spell_taldaram_ball_of_inferno_flame : public SpellScript
{
    PrepareSpellScript(spell_taldaram_ball_of_inferno_flame);

    void ModAuraStack()
    {
        if (Aura* aur = GetHitAura())
            aur->SetStackAmount(uint8(GetSpellInfo()->StackAmount));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_taldaram_ball_of_inferno_flame::ModAuraStack);
    }
};

class spell_taldaram_ball_of_inferno_flame_aura : public AuraScript
{
    PrepareAuraScript(spell_taldaram_ball_of_inferno_flame_aura);

    void HandleStackDrop(ProcEventInfo& /*eventInfo*/)
    {
        ModStackAmount(-1);
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_taldaram_ball_of_inferno_flame_aura::HandleStackDrop);
    }
};

// 72080 - Kinetic Bomb
class spell_valanar_kinetic_bomb : public SpellScript
{
    PrepareSpellScript(spell_valanar_kinetic_bomb);

    void SetDest(SpellDestination& dest)
    {
        Position const offset = { 0.0f, 0.0f, 20.0f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_valanar_kinetic_bomb::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_valanar_kinetic_bomb_aura : public AuraScript
{
    PrepareAuraScript(spell_valanar_kinetic_bomb_aura);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_KINETIC_BOMB_EXPLOSION, SPELL_KINETIC_BOMB_VISUAL });
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (target->GetTypeId() != TYPEID_UNIT)
            return;

        if (Creature* bomb = target->FindNearestCreature(NPC_KINETIC_BOMB, 1.0f, true))
        {
            bomb->CastSpell(bomb, SPELL_KINETIC_BOMB_EXPLOSION, true);
            bomb->RemoveAurasDueToSpell(SPELL_KINETIC_BOMB_VISUAL);
            target->RemoveAura(GetAura());
            bomb->AI()->DoAction(SPELL_KINETIC_BOMB_EXPLOSION);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_valanar_kinetic_bomb_aura::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 72087 - Kinetic Bomb Knockback
class spell_valanar_kinetic_bomb_knockback : public SpellScript
{
    PrepareSpellScript(spell_valanar_kinetic_bomb_knockback);

    void KnockIntoAir(SpellMissInfo missInfo)
    {
        if (missInfo != SPELL_MISS_NONE)
            return;

        if (Creature* target = GetHitCreature())
            target->AI()->DoAction(ACTION_KINETIC_BOMB_JUMP);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_valanar_kinetic_bomb_knockback::KnockIntoAir);
    }
};

// 72054 - Kinetic Bomb Visual
class spell_valanar_kinetic_bomb_absorb : public AuraScript
{
    PrepareAuraScript(spell_valanar_kinetic_bomb_absorb);

    void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        absorbAmount = CalculatePct(dmgInfo.GetDamage(), aurEff->GetAmount());
        RoundToInterval<uint32>(absorbAmount, 0, dmgInfo.GetDamage());
        dmgInfo.AbsorbDamage(absorbAmount);
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_valanar_kinetic_bomb_absorb::OnAbsorb, EFFECT_0);
    }
};

// 73001 - Shadow Prison
class spell_blood_council_shadow_prison : public AuraScript
{
    PrepareAuraScript(spell_blood_council_shadow_prison);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_PRISON_DAMAGE });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (GetTarget()->isMoving())
            GetTarget()->CastSpell(GetTarget(), SPELL_SHADOW_PRISON_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_blood_council_shadow_prison::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 72999 - Shadow Prison
class spell_blood_council_shadow_prison_damage : public SpellScript
{
    PrepareSpellScript(spell_blood_council_shadow_prison_damage);

    void AddExtraDamage(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aur = GetHitUnit()->GetAura(GetSpellInfo()->Id))
            if (AuraEffect const* eff = aur->GetEffect(EFFECT_1))
                SetEffectValue(GetEffectValue() + eff->GetAmount());
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_blood_council_shadow_prison_damage::AddExtraDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class at_blood_prince_council_start_intro : public AreaTriggerScript
{
    public:
        at_blood_prince_council_start_intro() : AreaTriggerScript("at_blood_prince_council_start_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* controller = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                    controller->AI()->DoAction(ACTION_START_INTRO);

            return true;
        }
};

void AddSC_boss_blood_prince_council()
{
    // Creatures
    RegisterIcecrownCitadelCreatureAI(boss_blood_council_controller);
    RegisterIcecrownCitadelCreatureAI(boss_prince_keleseth_icc);
    RegisterIcecrownCitadelCreatureAI(boss_prince_taldaram_icc);
    RegisterIcecrownCitadelCreatureAI(boss_prince_valanar_icc);
    RegisterIcecrownCitadelCreatureAI(npc_blood_queen_lana_thel);
    RegisterIcecrownCitadelCreatureAI(npc_ball_of_flame);
    RegisterIcecrownCitadelCreatureAI(npc_kinetic_bomb);
    RegisterIcecrownCitadelCreatureAI(npc_dark_nucleus);

    // Spells
    RegisterSpellScript(spell_taldaram_glittering_sparks);
    RegisterSpellScript(spell_taldaram_summon_flame_ball);
    RegisterSpellScript(spell_taldaram_flame_ball_visual);
    RegisterSpellAndAuraScriptPair(spell_taldaram_ball_of_inferno_flame, spell_taldaram_ball_of_inferno_flame_aura);
    RegisterSpellAndAuraScriptPair(spell_valanar_kinetic_bomb, spell_valanar_kinetic_bomb_aura);
    RegisterSpellScript(spell_valanar_kinetic_bomb_knockback);
    RegisterSpellScript(spell_valanar_kinetic_bomb_absorb);
    RegisterSpellScript(spell_blood_council_shadow_prison);
    RegisterSpellScript(spell_blood_council_shadow_prison_damage);

    // AreaTriggers
    new at_blood_prince_council_start_intro();
}

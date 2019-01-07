/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "icecrown_citadel.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "PassiveAI.h"

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
    SPELL_FLAME_SPHERE_SPAWN_EFFECT     = 55891, // cast from creature_template_addon (needed cast before entering world)
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

class boss_blood_council_controller : public CreatureScript
{
    public:
        boss_blood_council_controller() : CreatureScript("boss_blood_council_controller") { }

        struct boss_blood_council_controllerAI : public BossAI
        {
            boss_blood_council_controllerAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL), _intro(true)
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

                if (!_intro)
                    for (uint32 bossData : PrincesData)
                        if (Creature* prince = ObjectAccessor::GetCreature(*me, instance->GetGuidData(bossData)))
                        {
                            prince->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                            if (bossData == DATA_PRINCE_VALANAR)
                                prince->SetHealth(prince->GetMaxHealth());
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

            void EnterCombat(Unit* who) override
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
                if (data == DATA_INTRO && !_intro)
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
                        killer->Kill(prince);
                    }
                }
            }

            void DoAction(int32 actionId) override
            {
                if (actionId == ACTION_START_INTRO && _intro && instance->GetBossState(DATA_BLOOD_PRINCE_COUNCIL) != DONE)
                {
                    _intro = false;
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
            bool _intro;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<boss_blood_council_controllerAI>(creature);
        }
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
            JustRespawned();
    }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
        me->SetCombatPulseDelay(0);

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        _isEmpowered = false;
        me->SetHealth(_spawnHealth);
        instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
    }

    void EnterCombat(Unit* /*who*/) override
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

    void JustRespawned() override
    {
        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
            if (controller->AI()->GetData(DATA_INTRO) != DATA_INTRO_DONE)
                DoCastSelf(SPELL_FEIGN_DEATH);

        me->SetHealth(_spawnHealth);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (!_isEmpowered)
        {
            me->AddThreat(attacker, float(damage));
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
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            controller->AI()->SetData(DATA_PRINCE_EVADE, 1);
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SelectInvocationSpell())
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
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                me->ForceValuesUpdateAtIndex(UNIT_NPC_FLAGS);   // was in sniff. don't ask why
                me->m_Events.AddEvent(new StandUpEvent(me), me->m_Events.CalculateTime(1000));
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

class boss_prince_keleseth_icc : public CreatureScript
{
    public:
        boss_prince_keleseth_icc() : CreatureScript("boss_prince_keleseth_icc") { }

        struct boss_prince_kelesethAI : public BloodPrincesBossAI
        {
            boss_prince_kelesethAI(Creature* creature) : BloodPrincesBossAI(creature, DATA_PRINCE_KELESETH) { }

            void ScheduleEvents() override
            {
                events.ScheduleEvent(EVENT_BERSERK, Minutes(10));
                events.ScheduleEvent(EVENT_SHADOW_RESONANCE, Seconds(10), Seconds(15));
                events.ScheduleEvent(EVENT_SHADOW_LANCE, Seconds(2));

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
                float angle = me->GetAngle(summon);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<boss_prince_kelesethAI>(creature);
        }
};

class boss_prince_taldaram_icc : public CreatureScript
{
    public:
        boss_prince_taldaram_icc() : CreatureScript("boss_prince_taldaram_icc") { }

        struct boss_prince_taldaramAI : public BloodPrincesBossAI
        {
            boss_prince_taldaramAI(Creature* creature) : BloodPrincesBossAI(creature, DATA_PRINCE_TALDARAM) { }

            void ScheduleEvents() override
            {
                events.ScheduleEvent(EVENT_BERSERK, Minutes(10));
                events.ScheduleEvent(EVENT_GLITTERING_SPARKS, Seconds(12), Seconds(15));
                events.ScheduleEvent(EVENT_CONJURE_FLAME, Seconds(20));
                if (IsHeroic())
                    DoCastSelf(SPELL_SHADOW_PRISON, true);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -10.0f, true); // first try at distance
                if (!target)
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);     // too bad for you raiders, its going to boom

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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<boss_prince_taldaramAI>(creature);
        }
};

class boss_prince_valanar_icc : public CreatureScript
{
    public:
        boss_prince_valanar_icc() : CreatureScript("boss_prince_valanar_icc") { }

        struct boss_prince_valanarAI : public BloodPrincesBossAI
        {
            boss_prince_valanarAI(Creature* creature) : BloodPrincesBossAI(creature, DATA_PRINCE_TALDARAM) { }

            void ScheduleEvents() override
            {
                events.ScheduleEvent(EVENT_BERSERK, Minutes(10));
                events.ScheduleEvent(EVENT_KINETIC_BOMB, Seconds(18), Seconds(24));
                events.ScheduleEvent(EVENT_SHOCK_VORTEX, Seconds(15), Seconds(20));
                if (IsHeroic())
                    DoCastSelf(SPELL_SHADOW_PRISON, true);
            }

            void JustSummoned(Creature* summon) override
            {
                switch (summon->GetEntry())
                {
                    case NPC_KINETIC_BOMB_TARGET:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->CastSpell(summon, SPELL_KINETIC_BOMB, true, nullptr, nullptr, me->GetGUID());
                        break;
                    case NPC_KINETIC_BOMB:
                    {
                        float x, y, z;
                        summon->GetPosition(x, y, z);
                        float ground_Z = summon->GetMap()->GetHeight(summon->GetPhaseShift(), x, y, z, true, 500.0f);
                        summon->GetMotionMaster()->MovePoint(POINT_KINETIC_BOMB_IMPACT, x, y, ground_Z);
                        summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    }
                    case NPC_SHOCK_VORTEX:
                        summon->CastSpell(summon, SPELL_SHOCK_VORTEX_DUMMY, true);
                        summon->m_Events.AddEvent(new VortexEvent(summon), summon->m_Events.CalculateTime(5000));
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
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
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
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<boss_prince_valanarAI>(creature);
        }
};

class npc_blood_queen_lana_thel : public CreatureScript
{
    public:
        npc_blood_queen_lana_thel() : CreatureScript("npc_blood_queen_lana_thel") { }

        struct npc_blood_queen_lana_thelAI : public PassiveAI
        {
            npc_blood_queen_lana_thelAI(Creature* creature) : PassiveAI(creature), _instance(creature->GetInstanceScript()) { }

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
                        if (Creature* summon = DoSummon(NPC_FLOATING_TRIGGER, triggerPos, 15000, TEMPSUMMON_TIMED_DESPAWN))
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_blood_queen_lana_thelAI>(creature);
        }
};

class npc_ball_of_flame : public CreatureScript
{
    public:
        npc_ball_of_flame() : CreatureScript("npc_ball_of_flame") { }

        struct npc_ball_of_flameAI : public ScriptedAI
        {
            npc_ball_of_flameAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                DoCastSelf(SPELL_BALL_OF_FLAMES_VISUAL, true);
                if (me->GetEntry() == NPC_BALL_OF_INFERNO_FLAME)
                {
                    DoCastSelf(SPELL_BALL_OF_FLAMES_PROC, true);
                    DoCastSelf(SPELL_BALL_OF_FLAMES_PERIODIC, true);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == CHASE_MOTION_TYPE && id == _chaseGUID.GetCounter() && !_chaseGUID.IsEmpty())
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

            void SetGUID(ObjectGuid guid, int32 /*type*/) override
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
                        if (target && me->Attack(target, true))
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_ball_of_flameAI>(creature);
        }
};

class npc_kinetic_bomb : public CreatureScript
{
    public:
        npc_kinetic_bomb() : CreatureScript("npc_kinetic_bomb") { }

        struct npc_kinetic_bombAI : public ScriptedAI
        {
            npc_kinetic_bombAI(Creature* creature) : ScriptedAI(creature), _x(0.f), _y(0.f), _groundZ(0.f) { }

            void Reset() override
            {
                _events.Reset();
                me->SetWalk(true);
                DoCastSelf(SPELL_UNSTABLE, true);
                DoCastSelf(SPELL_KINETIC_BOMB_VISUAL, true);
                me->SetReactState(REACT_PASSIVE);
                me->GetPosition(_x, _y, _groundZ);
                me->DespawnOrUnsummon(60000);
                _groundZ = me->GetMap()->GetHeight(me->GetPhaseShift(), _x, _y, _groundZ, true, 500.0f);
            }

            void DoAction(int32 action) override
            {
                if (action == SPELL_KINETIC_BOMB_EXPLOSION)
                    _events.ScheduleEvent(EVENT_BOMB_DESPAWN, Seconds(1));

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
                            me->DespawnOrUnsummon(5000);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_kinetic_bombAI>(creature);
        }
};

class npc_dark_nucleus : public CreatureScript
{
    public:
        npc_dark_nucleus() : CreatureScript("npc_dark_nucleus") { }

        struct npc_dark_nucleusAI : public ScriptedAI
        {
            npc_dark_nucleusAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                me->SetReactState(REACT_DEFENSIVE);
                DoCastSelf(SPELL_SHADOW_RESONANCE_AURA, true);
            }

            void EnterCombat(Unit* who) override
            {
                _scheduler.Schedule(Seconds(1), [this](TaskContext targetAuraCheck)
                {
                    if (Unit* victim = me->GetVictim())
                    {
                        if (me->GetDistance(victim) < 15.0f && !victim->HasAura(SPELL_SHADOW_RESONANCE_RESIST, me->GetGUID()))
                        {
                            DoCast(victim, SPELL_SHADOW_RESONANCE_RESIST);
                            me->ClearUnitState(UNIT_STATE_CASTING);
                        }
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
                me->ClearUnitState(UNIT_STATE_CASTING);
            }

            void DamageTaken(Unit* attacker, uint32& /*damage*/) override
            {
                if (attacker == me)
                    return;

                me->DeleteThreatList();
                me->AddThreat(attacker, 500000000.0f);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_dark_nucleusAI>(creature);
        }
};

// 71806 - Glittering Sparks
class spell_taldaram_glittering_sparks : public SpellScriptLoader
{
    public:
        spell_taldaram_glittering_sparks() : SpellScriptLoader("spell_taldaram_glittering_sparks") { }

        class spell_taldaram_glittering_sparks_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_taldaram_glittering_sparks_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_taldaram_glittering_sparks_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_taldaram_glittering_sparks_SpellScript();
        }
};

/* 71718 - Conjure Flame
   72040 - Conjure Empowered Flame */
class spell_taldaram_summon_flame_ball : public SpellScriptLoader
{
    public:
        spell_taldaram_summon_flame_ball() : SpellScriptLoader("spell_taldaram_summon_flame_ball") { }

        class spell_taldaram_summon_flame_ball_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_taldaram_summon_flame_ball_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_taldaram_summon_flame_ball_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_taldaram_summon_flame_ball_SpellScript();
        }
};

/* 55891 - Flame Sphere Spawn Effect
   55947 - Flame Sphere Death Effect */
class spell_taldaram_flame_ball_visual : public SpellScriptLoader
{
    public:
        spell_taldaram_flame_ball_visual() : SpellScriptLoader("spell_taldaram_flame_ball_visual") { }

        class spell_flame_ball_visual_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_flame_ball_visual_AuraScript);

            bool Load() override
            {
                if (GetCaster()->GetEntry() == NPC_BALL_OF_FLAME || GetCaster()->GetEntry() == NPC_BALL_OF_INFERNO_FLAME)
                    return true;
                return false;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
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
                AfterEffectRemove += AuraEffectRemoveFn(spell_flame_ball_visual_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_flame_ball_visual_AuraScript();
        }
};

/* 71756 - Ball of Flames Proc
   72782 - Ball of Flames Proc
   72783 - Ball of Flames Proc
   72784 - Ball of Flames Proc */
class spell_taldaram_ball_of_inferno_flame : public SpellScriptLoader
{
    public:
        spell_taldaram_ball_of_inferno_flame() : SpellScriptLoader("spell_taldaram_ball_of_inferno_flame") { }

        class spell_taldaram_ball_of_inferno_flame_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_taldaram_ball_of_inferno_flame_SpellScript);

            void ModAuraStack()
            {
                if (Aura* aur = GetHitAura())
                    aur->SetStackAmount(uint8(GetSpellInfo()->StackAmount));
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_taldaram_ball_of_inferno_flame_SpellScript::ModAuraStack);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_taldaram_ball_of_inferno_flame_SpellScript();
        }

        class spell_taldaram_ball_of_inferno_flame_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_taldaram_ball_of_inferno_flame_AuraScript);

            void HandleStackDrop(ProcEventInfo& /*eventInfo*/)
            {
                ModStackAmount(-1);
            }

            void Register() override
            {
                OnProc += AuraProcFn(spell_taldaram_ball_of_inferno_flame_AuraScript::HandleStackDrop);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_taldaram_ball_of_inferno_flame_AuraScript();
        }
};

// 72080 - Kinetic Bomb
class spell_valanar_kinetic_bomb : public SpellScriptLoader
{
    public:
        spell_valanar_kinetic_bomb() : SpellScriptLoader("spell_valanar_kinetic_bomb") { }

        class spell_valanar_kinetic_bomb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valanar_kinetic_bomb_SpellScript);

            void SetDest(SpellDestination& dest)
            {
                Position const offset = { 0.0f, 0.0f, 20.0f, 0.0f };
                dest.RelocateOffset(offset);
            }

            void Register() override
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_valanar_kinetic_bomb_SpellScript::SetDest, EFFECT_0, TARGET_DEST_CASTER);
            }
        };

        class spell_valanar_kinetic_bomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valanar_kinetic_bomb_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
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
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_valanar_kinetic_bomb_AuraScript::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valanar_kinetic_bomb_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_valanar_kinetic_bomb_AuraScript();
        }
};

// 72087 - Kinetic Bomb Knockback
class spell_valanar_kinetic_bomb_knockback : public SpellScriptLoader
{
    public:
        spell_valanar_kinetic_bomb_knockback() : SpellScriptLoader("spell_valanar_kinetic_bomb_knockback") { }

        class spell_valanar_kinetic_bomb_knockback_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_valanar_kinetic_bomb_knockback_SpellScript);

            void KnockIntoAir(SpellMissInfo missInfo)
            {
                if (missInfo != SPELL_MISS_NONE)
                    return;

                if (Creature* target = GetHitCreature())
                    target->AI()->DoAction(ACTION_KINETIC_BOMB_JUMP);
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_valanar_kinetic_bomb_knockback_SpellScript::KnockIntoAir);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_valanar_kinetic_bomb_knockback_SpellScript();
        }
};

// 72054 - Kinetic Bomb Visual
class spell_valanar_kinetic_bomb_absorb : public SpellScriptLoader
{
    public:
        spell_valanar_kinetic_bomb_absorb() : SpellScriptLoader("spell_valanar_kinetic_bomb_absorb") { }

        class spell_valanar_kinetic_bomb_absorb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_valanar_kinetic_bomb_absorb_AuraScript);

            void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                absorbAmount = CalculatePct(dmgInfo.GetDamage(), aurEff->GetAmount());
                RoundToInterval<uint32>(absorbAmount, 0, dmgInfo.GetDamage());
                dmgInfo.AbsorbDamage(absorbAmount);
            }

            void Register() override
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_valanar_kinetic_bomb_absorb_AuraScript::OnAbsorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_valanar_kinetic_bomb_absorb_AuraScript();
        }
};

// 73001 - Shadow Prison
class spell_blood_council_shadow_prison : public SpellScriptLoader
{
    public:
        spell_blood_council_shadow_prison() : SpellScriptLoader("spell_blood_council_shadow_prison") { }

        class spell_blood_council_shadow_prison_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_blood_council_shadow_prison_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHADOW_PRISON_DAMAGE });
            }

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (GetTarget()->isMoving())
                    GetTarget()->CastSpell(GetTarget(), SPELL_SHADOW_PRISON_DAMAGE, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_blood_council_shadow_prison_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_blood_council_shadow_prison_AuraScript();
        }
};

// 72999 - Shadow Prison
class spell_blood_council_shadow_prison_damage : public SpellScriptLoader
{
    public:
        spell_blood_council_shadow_prison_damage() : SpellScriptLoader("spell_blood_council_shadow_prison_damage") { }

        class spell_blood_council_shadow_prison_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_blood_council_shadow_prison_SpellScript);

            void AddExtraDamage()
            {
                if (Aura* aur = GetHitUnit()->GetAura(GetSpellInfo()->Id))
                    if (AuraEffect const* eff = aur->GetEffect(EFFECT_1))
                        SetHitDamage(GetHitDamage() + eff->GetAmount());
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_blood_council_shadow_prison_SpellScript::AddExtraDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_blood_council_shadow_prison_SpellScript();
        }
};

class at_blood_prince_council_start_intro : public AreaTriggerScript
{
    public:
        at_blood_prince_council_start_intro() : AreaTriggerScript("at_blood_prince_council_start_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool /*entered*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* controller = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                    controller->AI()->DoAction(ACTION_START_INTRO);

            return true;
        }
};

void AddSC_boss_blood_prince_council()
{
    new boss_blood_council_controller();
    new boss_prince_keleseth_icc();
    new boss_prince_taldaram_icc();
    new boss_prince_valanar_icc();
    new npc_blood_queen_lana_thel();
    new npc_ball_of_flame();
    new npc_kinetic_bomb();
    new npc_dark_nucleus();
    new spell_taldaram_glittering_sparks();
    new spell_taldaram_summon_flame_ball();
    new spell_taldaram_flame_ball_visual();
    new spell_taldaram_ball_of_inferno_flame();
    new spell_valanar_kinetic_bomb();
    new spell_valanar_kinetic_bomb_knockback();
    new spell_valanar_kinetic_bomb_absorb();
    new spell_blood_council_shadow_prison();
    new spell_blood_council_shadow_prison_damage();
    new at_blood_prince_council_start_intro();
}

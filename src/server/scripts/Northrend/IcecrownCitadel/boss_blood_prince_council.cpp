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
    SAY_VALANAR_DEATH           = 6,
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
};

enum Events
{
    EVENT_INTRO_1               = 1,
    EVENT_INTRO_2               = 2,

    EVENT_INVOCATION_OF_BLOOD   = 3,
    EVENT_BERSERK               = 4,

    // Keleseth
    EVENT_SHADOW_RESONANCE      = 5,
    EVENT_SHADOW_LANCE          = 6,

    // Taldaram
    EVENT_GLITTERING_SPARKS     = 7,
    EVENT_CONJURE_FLAME         = 8,

    // Valanar
    EVENT_KINETIC_BOMB          = 9,
    EVENT_SHOCK_VORTEX          = 10,
    EVENT_BOMB_DESPAWN          = 11,
    EVENT_CONTINUE_FALLING      = 12,
};

enum Actions
{
    ACTION_START_INTRO          = 1,
    ACTION_STAND_UP             = 2,
    ACTION_CAST_INVOCATION      = 3,
    ACTION_REMOVE_INVOCATION    = 4,
    ACTION_KINETIC_BOMB_JUMP    = 5,
    ACTION_FLAME_BALL_CHASE     = 6,
};

enum Points
{
    POINT_INTRO_DESPAWN         = 380040,
    POINT_KINETIC_BOMB_IMPACT   = 384540,
};

enum Displays
{
    DISPLAY_KINETIC_BOMB        = 31095,
};

class StandUpEvent : public BasicEvent
{
    public:
        StandUpEvent(Creature& owner) : BasicEvent(), _owner(owner) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
        {
            _owner.HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
            _owner.SetReactState(REACT_AGGRESSIVE);
            return true;
        }

    private:
        Creature& _owner;
};

Position const introFinalPos = {4660.490f, 2769.200f, 430.0000f, 0.000000f};
Position const triggerPos    = {4680.231f, 2769.134f, 379.9256f, 3.121708f};
Position const triggerEndPos = {4680.180f, 2769.150f, 365.5000f, 3.121708f};

class boss_blood_council_controller : public CreatureScript
{
    public:
        boss_blood_council_controller() : CreatureScript("boss_blood_council_controller") { }

        struct boss_blood_council_controllerAI : public BossAI
        {
            boss_blood_council_controllerAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
                Initialize();
            }

            void Initialize()
            {
                _invocationStage = 0;
                _resetCounter = 0;
            }

            void Reset() override
            {
                events.Reset();
                me->SetReactState(REACT_PASSIVE);
                Initialize();

                instance->SetBossState(DATA_BLOOD_PRINCE_COUNCIL, NOT_STARTED);
            }

            void EnterCombat(Unit* who) override
            {
                if (instance->GetBossState(DATA_BLOOD_PRINCE_COUNCIL) == IN_PROGRESS)
                    return;

                if (!instance->CheckRequiredBosses(DATA_BLOOD_PRINCE_COUNCIL, who->ToPlayer()))
                {
                    EnterEvadeMode();
                    instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
                    return;
                }

                instance->SetBossState(DATA_BLOOD_PRINCE_COUNCIL, IN_PROGRESS);

                DoCast(me, SPELL_INVOCATION_OF_BLOOD_VALANAR);

                if (Creature* keleseth = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_KELESETH_GUID)))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, keleseth);
                    DoZoneInCombat(keleseth);
                }

                if (Creature* taldaram = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_TALDARAM_GUID)))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, taldaram);
                    DoZoneInCombat(taldaram);
                }

                if (Creature* valanar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_VALANAR_GUID)))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, valanar);
                    DoZoneInCombat(valanar);
                }

                events.ScheduleEvent(EVENT_INVOCATION_OF_BLOOD, 46500);

                _invocationOrder[0] = InvocationData(instance->GetGuidData(DATA_PRINCE_VALANAR_GUID), SPELL_INVOCATION_OF_BLOOD_VALANAR, EMOTE_VALANAR_INVOCATION, 71070);
                if (urand(0, 1))
                {
                    _invocationOrder[1] = InvocationData(instance->GetGuidData(DATA_PRINCE_TALDARAM_GUID), SPELL_INVOCATION_OF_BLOOD_TALDARAM, EMOTE_TALDARAM_INVOCATION, 71081);
                    _invocationOrder[2] = InvocationData(instance->GetGuidData(DATA_PRINCE_KELESETH_GUID), SPELL_INVOCATION_OF_BLOOD_KELESETH, EMOTE_KELESETH_INVOCATION, 71080);
                }
                else
                {
                    _invocationOrder[1] = InvocationData(instance->GetGuidData(DATA_PRINCE_KELESETH_GUID), SPELL_INVOCATION_OF_BLOOD_KELESETH, EMOTE_KELESETH_INVOCATION, 71080);
                    _invocationOrder[2] = InvocationData(instance->GetGuidData(DATA_PRINCE_TALDARAM_GUID), SPELL_INVOCATION_OF_BLOOD_TALDARAM, EMOTE_TALDARAM_INVOCATION, 71081);
                }
            }

            void SetData(uint32 /*type*/, uint32 data) override
            {
                _resetCounter += uint8(data);
                if (_resetCounter == 3)
                    EnterEvadeMode();
            }

            void JustReachedHome() override
            {
                _resetCounter = 0;
                if (Creature* keleseth = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_KELESETH_GUID)))
                    keleseth->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                if (Creature* taldaram = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_TALDARAM_GUID)))
                    taldaram->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                if (Creature* valanar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_VALANAR_GUID)))
                    valanar->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void JustDied(Unit* killer) override
            {
                _JustDied();
                // kill all prices
                for (uint8 i = 0; i < 3; ++i)
                {
                    if (++_invocationStage == 3)
                        _invocationStage = 0;

                    if (Creature* prince = ObjectAccessor::GetCreature(*me, _invocationOrder[_invocationStage].guid))
                    {
                        // make sure looting is allowed
                        if (me->IsDamageEnoughForLootingAndReward())
                            prince->LowerPlayerDamageReq(prince->GetMaxHealth());
                        killer->Kill(prince);
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

                            DoCast(me, _invocationOrder[_invocationStage].spellId);
                            events.ScheduleEvent(EVENT_INVOCATION_OF_BLOOD, 46500);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<boss_blood_council_controllerAI>(creature);
        }
};

class boss_prince_keleseth_icc : public CreatureScript
{
    public:
        boss_prince_keleseth_icc() : CreatureScript("boss_prince_keleseth_icc") { }

        struct boss_prince_kelesethAI : public BossAI
        {
            boss_prince_kelesethAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
                _isEmpowered = false;
                _spawnHealth = creature->GetMaxHealth();
            }

            void InitializeAI() override
            {
                if (CreatureData const* data = me->GetCreatureData())
                    if (data->curhealth)
                        _spawnHealth = data->curhealth;

                if (!me->isDead())
                    JustRespawned();
            }

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                _isEmpowered = false;
                me->SetHealth(_spawnHealth);
                instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                    DoZoneInCombat(controller);

                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_SHADOW_RESONANCE, urand(10000, 15000));
                events.ScheduleEvent(EVENT_SHADOW_LANCE, 2000);

                if (IsHeroic())
                {
                    me->AddAura(SPELL_SHADOW_PRISON, me);
                    DoCast(me, SPELL_SHADOW_PRISON_DUMMY);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
                summons.DespawnAll();

                Talk(SAY_KELESETH_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustReachedHome() override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->SetHealth(_spawnHealth);
                _isEmpowered = false;
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    controller->AI()->SetData(0, 1);
                }
            }

            void JustRespawned() override
            {
                DoCast(me, SPELL_FEIGN_DEATH);
                me->SetHealth(_spawnHealth);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_INVOCATION_OF_BLOOD_KELESETH)
                    DoAction(ACTION_CAST_INVOCATION);
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

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType) override
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;

                if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
                    instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
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
                    Talk(SAY_KELESETH_KILL);
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
                        me->m_Events.AddEvent(new StandUpEvent(*me), me->m_Events.CalculateTime(1000));
                        break;
                    case ACTION_CAST_INVOCATION:
                        Talk(SAY_KELESETH_INVOCATION);
                        DoCast(me, SPELL_INVOCATION_VISUAL_ACTIVE, true);
                        _isEmpowered = true;
                        break;
                    case ACTION_REMOVE_INVOCATION:
                        me->SetHealth(_spawnHealth);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_VISUAL_ACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_OF_BLOOD_KELESETH);
                        _isEmpowered = false;
                        break;
                    default:
                        break;
                }
            }

            bool CheckInRoom() override
            {
                if (!CheckBoundary(me))
                {
                    EnterEvadeMode();
                    if (Creature* taldaram = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_TALDARAM_GUID)))
                        taldaram->AI()->EnterEvadeMode();

                    if (Creature* valanar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_VALANAR_GUID)))
                        valanar->AI()->EnterEvadeMode();

                    return false;
                }

                return true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(EMOTE_KELESETH_BERSERK);
                            break;
                        case EVENT_SHADOW_RESONANCE:
                            Talk(SAY_KELESETH_SPECIAL);
                            DoCast(me, SPELL_SHADOW_RESONANCE);
                            events.ScheduleEvent(EVENT_SHADOW_RESONANCE, urand(10000, 15000));
                            break;
                        case EVENT_SHADOW_LANCE:
                            if (_isEmpowered)
                                DoCastVictim(SPELL_EMPOWERED_SHADOW_LANCE);
                            else
                                DoCastVictim(SPELL_SHADOW_LANCE);
                            events.ScheduleEvent(EVENT_SHADOW_LANCE, 2000);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                // does not melee
            }

        private:
            uint32 _spawnHealth;
            bool _isEmpowered;
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

        struct boss_prince_taldaramAI : public BossAI
        {
            boss_prince_taldaramAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
                _isEmpowered = false;
                _spawnHealth = creature->GetMaxHealth();
            }

            void InitializeAI() override
            {
                if (CreatureData const* data = me->GetCreatureData())
                    if (data->curhealth)
                        _spawnHealth = data->curhealth;

                if (!me->isDead())
                    JustRespawned();
            }

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                _isEmpowered = false;
                me->SetHealth(_spawnHealth);
                instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                    DoZoneInCombat(controller);

                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_GLITTERING_SPARKS, urand(12000, 15000));
                events.ScheduleEvent(EVENT_CONJURE_FLAME, 20000);
                if (IsHeroic())
                    me->AddAura(SPELL_SHADOW_PRISON, me);
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
                summons.DespawnAll();

                Talk(EMOTE_TALDARAM_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustReachedHome() override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->SetHealth(_spawnHealth);
                _isEmpowered = false;
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    controller->AI()->SetData(0, 1);
                }
            }

            void JustRespawned() override
            {
                DoCast(me, SPELL_FEIGN_DEATH);
                me->SetHealth(_spawnHealth);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_INVOCATION_OF_BLOOD_TALDARAM)
                    DoAction(ACTION_CAST_INVOCATION);
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

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType) override
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;

                if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
                    instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
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
                    Talk(SAY_TALDARAM_KILL);
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
                        me->m_Events.AddEvent(new StandUpEvent(*me), me->m_Events.CalculateTime(1000));
                        break;
                    case ACTION_CAST_INVOCATION:
                        Talk(SAY_TALDARAM_INVOCATION);
                        DoCast(me, SPELL_INVOCATION_VISUAL_ACTIVE, true);
                        _isEmpowered = true;
                        break;
                    case ACTION_REMOVE_INVOCATION:
                        me->SetHealth(_spawnHealth);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_VISUAL_ACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_OF_BLOOD_TALDARAM);
                        _isEmpowered = false;
                        break;
                    default:
                        break;
                }
            }

            bool CheckInRoom() override
            {
                if (!CheckBoundary(me))
                {
                    EnterEvadeMode();
                    if (Creature* keleseth = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_KELESETH_GUID)))
                        keleseth->AI()->EnterEvadeMode();

                    if (Creature* valanar = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_VALANAR_GUID)))
                        valanar->AI()->EnterEvadeMode();

                    return false;
                }

                return true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(EMOTE_TALDARAM_BERSERK);
                            break;
                        case EVENT_GLITTERING_SPARKS:
                            DoCastVictim(SPELL_GLITTERING_SPARKS);
                            events.ScheduleEvent(EVENT_GLITTERING_SPARKS, urand(15000, 50000));
                            break;
                        case EVENT_CONJURE_FLAME:
                            if (_isEmpowered)
                            {
                                DoCast(me, SPELL_CONJURE_EMPOWERED_FLAME);
                                events.ScheduleEvent(EVENT_CONJURE_FLAME, urand(15000, 25000));
                            }
                            else
                            {
                                DoCast(me, SPELL_CONJURE_FLAME);
                                events.ScheduleEvent(EVENT_CONJURE_FLAME, urand(20000, 30000));
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

        private:
            uint32 _spawnHealth;
            bool _isEmpowered;
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

        struct boss_prince_valanarAI : public BossAI
        {
            boss_prince_valanarAI(Creature* creature) : BossAI(creature, DATA_BLOOD_PRINCE_COUNCIL)
            {
                _isEmpowered = false;
                _spawnHealth = creature->GetMaxHealth();
            }

            void InitializeAI() override
            {
                if (CreatureData const* data = me->GetCreatureData())
                    if (data->curhealth)
                        _spawnHealth = data->curhealth;

                if (!me->isDead())
                    JustRespawned();
            }

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                _isEmpowered = false;
                me->SetHealth(me->GetMaxHealth());
                instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(true));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                    DoZoneInCombat(controller);

                events.ScheduleEvent(EVENT_BERSERK, 600000);
                events.ScheduleEvent(EVENT_KINETIC_BOMB, urand(18000, 24000));
                events.ScheduleEvent(EVENT_SHOCK_VORTEX, urand(15000, 20000));
                if (IsHeroic())
                    me->AddAura(SPELL_SHADOW_PRISON, me);
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();
                summons.DespawnAll();

                Talk(SAY_VALANAR_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustReachedHome() override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->SetHealth(me->GetMaxHealth());
                _isEmpowered = false;
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_BLOOD_PRINCES_CONTROL)))
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    controller->AI()->SetData(0, 1);
                }
            }

            void JustRespawned() override
            {
                DoCast(me, SPELL_FEIGN_DEATH);
                me->SetHealth(_spawnHealth);
            }

            void JustSummoned(Creature* summon) override
            {
                switch (summon->GetEntry())
                {
                    case NPC_KINETIC_BOMB_TARGET:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->CastSpell(summon, SPELL_KINETIC_BOMB, true, NULL, NULL, me->GetGUID());
                        break;
                    case NPC_KINETIC_BOMB:
                    {
                        float x, y, z;
                        summon->GetPosition(x, y, z);
                        float ground_Z = summon->GetMap()->GetHeight(summon->GetPhases(), x, y, z, true, 500.0f);
                        summon->GetMotionMaster()->MovePoint(POINT_KINETIC_BOMB_IMPACT, x, y, ground_Z);
                        summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                    }
                    case NPC_SHOCK_VORTEX:
                        summon->CastSpell(summon, SPELL_SHOCK_VORTEX_DUMMY, true);
                        summon->CastSpell(summon, SPELL_SHOCK_VORTEX_PERIODIC, true);
                        break;
                    default:
                        break;
                }

                summons.Summon(summon);
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_INVOCATION_OF_BLOOD_VALANAR)
                    DoAction(ACTION_CAST_INVOCATION);
            }

            void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType damageType) override
            {
                if (damageType != SPELL_DIRECT_DAMAGE)
                    return;

                if (damage > RAID_MODE<uint32>(23000, 25000, 23000, 25000))
                    instance->SetData(DATA_ORB_WHISPERER_ACHIEVEMENT, uint32(false));
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
                    Talk(SAY_VALANAR_KILL);
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
                        me->m_Events.AddEvent(new StandUpEvent(*me), me->m_Events.CalculateTime(1000));
                        break;
                    case ACTION_CAST_INVOCATION:
                        Talk(SAY_VALANAR_INVOCATION);
                        DoCast(me, SPELL_INVOCATION_VISUAL_ACTIVE, true);
                        _isEmpowered = true;
                        break;
                    case ACTION_REMOVE_INVOCATION:
                        me->SetHealth(_spawnHealth);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_VISUAL_ACTIVE);
                        me->RemoveAurasDueToSpell(SPELL_INVOCATION_OF_BLOOD_VALANAR);
                        _isEmpowered = false;
                        break;
                    default:
                        break;
                }
            }

            bool CheckInRoom() override
            {
                if (!CheckBoundary(me))
                {
                    EnterEvadeMode();
                    if (Creature* keleseth = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_KELESETH_GUID)))
                        keleseth->AI()->EnterEvadeMode();

                    if (Creature* taldaram = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRINCE_TALDARAM_GUID)))
                        taldaram->AI()->EnterEvadeMode();

                    return false;
                }

                return true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            Talk(SAY_VALANAR_BERSERK);
                            break;
                        case EVENT_KINETIC_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                DoCast(target, SPELL_KINETIC_BOMB_TARGET);
                                Talk(SAY_VALANAR_SPECIAL);
                            }
                            events.ScheduleEvent(EVENT_KINETIC_BOMB, urand(18000, 24000));
                            break;
                        case EVENT_SHOCK_VORTEX:
                            if (_isEmpowered)
                            {
                                DoCast(me, SPELL_EMPOWERED_SHOCK_VORTEX);
                                Talk(EMOTE_VALANAR_SHOCK_VORTEX);
                                events.ScheduleEvent(EVENT_SHOCK_VORTEX, 30000);
                            }
                            else
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                    DoCast(target, SPELL_SHOCK_VORTEX);
                                events.ScheduleEvent(EVENT_SHOCK_VORTEX, urand(18000, 23000));
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

        private:
            uint32 _spawnHealth;
            bool _isEmpowered;
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

        struct npc_blood_queen_lana_thelAI : public ScriptedAI
        {
            npc_blood_queen_lana_thelAI(Creature* creature) : ScriptedAI(creature)
            {
                _introDone = false;
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _events.Reset();
                me->SetDisableGravity(true);
                if (_instance->GetBossState(DATA_BLOOD_PRINCE_COUNCIL) == DONE)
                {
                    me->SetVisible(false);
                    _introDone = true;
                }
                else
                    me->SetVisible(true);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_START_INTRO:
                        if (!_introDone)
                        {
                            _introDone = true;
                            Talk(SAY_INTRO_1);
                            _events.SetPhase(1);
                            _events.ScheduleEvent(EVENT_INTRO_1, 14000);
                            // summon a visual trigger
                            if (Creature* summon = DoSummon(NPC_FLOATING_TRIGGER, triggerPos, 15000, TEMPSUMMON_TIMED_DESPAWN))
                            {
                                summon->CastSpell(summon, SPELL_OOC_INVOCATION_VISUAL, true);
                                summon->SetSpeedRate(MOVE_FLIGHT, 0.15f); // todo: creature is swimming, check if this is blizzlike or not.
                                summon->GetMotionMaster()->MovePoint(0, triggerEndPos);
                            }
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

                    // remove Feign Death from princes
                    if (Creature* keleseth = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_PRINCE_KELESETH_GUID)))
                        keleseth->AI()->DoAction(ACTION_STAND_UP);

                    if (Creature* taldaram = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_PRINCE_TALDARAM_GUID)))
                        taldaram->AI()->DoAction(ACTION_STAND_UP);

                    if (Creature* valanar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_PRINCE_VALANAR_GUID)))
                    {
                        valanar->AI()->DoAction(ACTION_STAND_UP);
                        valanar->SetHealth(valanar->GetMaxHealth());
                    }
                }
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            bool _introDone;
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
            npc_ball_of_flameAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                _despawnTimer = 0;
            }

            void Reset() override
            {
                me->CastSpell(me, SPELL_BALL_OF_FLAMES_VISUAL, true);
                if (me->GetEntry() == NPC_BALL_OF_INFERNO_FLAME)
                {
                    me->CastSpell(me, SPELL_BALL_OF_FLAMES_PROC, true);
                    me->CastSpell(me, SPELL_BALL_OF_FLAMES_PERIODIC, true);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == CHASE_MOTION_TYPE && id == _chaseGUID.GetCounter() && !_chaseGUID.IsEmpty())
                {
                    me->RemoveAurasDueToSpell(SPELL_BALL_OF_FLAMES_PERIODIC);
                    DoCast(me, SPELL_FLAMES);
                    _despawnTimer = 1000;
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
                if (!_despawnTimer)
                    return;

                if (_despawnTimer <= diff)
                {
                    _despawnTimer = 0;
                    DoCast(me, SPELL_FLAME_SPHERE_DEATH_EFFECT);
                }
                else
                    _despawnTimer -= diff;
            }

        private:
            ObjectGuid _chaseGUID;
            InstanceScript* _instance;
            uint32 _despawnTimer;
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
            npc_kinetic_bombAI(Creature* creature) : ScriptedAI(creature)
            {
                _x = 0.f;
                _y = 0.f;
                _groundZ = 0.f;
            }

            void Reset() override
            {
                _events.Reset();
                me->SetWalk(true);
                me->CastSpell(me, SPELL_UNSTABLE, true);
                me->CastSpell(me, SPELL_KINETIC_BOMB_VISUAL, true);
                me->SetReactState(REACT_PASSIVE);
                me->GetPosition(_x, _y, _groundZ);
                me->DespawnOrUnsummon(60000);
                _groundZ = me->GetMap()->GetHeight(me->GetPhases(), _x, _y, _groundZ, true, 500.0f);
            }

            void DoAction(int32 action) override
            {
                if (action == SPELL_KINETIC_BOMB_EXPLOSION)
                    _events.ScheduleEvent(EVENT_BOMB_DESPAWN, 1000);
                else if (action == ACTION_KINETIC_BOMB_JUMP)
                {
                    if (!me->HasAura(SPELL_KINETIC_BOMB_KNOCKBACK))
                        me->GetMotionMaster()->MoveCharge(_x, _y, me->GetPositionZ() + 100.0f, me->GetSpeed(MOVE_RUN), 0);
                    _events.RescheduleEvent(EVENT_CONTINUE_FALLING, 3000);
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
                            me->GetMotionMaster()->MoveCharge(_x, _y, _groundZ, me->GetSpeed(MOVE_WALK), POINT_KINETIC_BOMB_IMPACT);
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
            npc_dark_nucleusAI(Creature* creature) : ScriptedAI(creature)
            {
                _lockedTarget = false;
                _targetAuraCheck = 0;
            }

            void Reset() override
            {
                me->SetReactState(REACT_DEFENSIVE);
                me->CastSpell(me, SPELL_SHADOW_RESONANCE_AURA, true);
            }

            void EnterCombat(Unit* who) override
            {
                _targetAuraCheck = 1000;
                if (me->GetDistance(who) >= 15.0f)
                {
                    DoStartMovement(who);
                    return;
                }

                DoCast(who, SPELL_SHADOW_RESONANCE_RESIST);
                me->ClearUnitState(UNIT_STATE_CASTING);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                ScriptedAI::MoveInLineOfSight(who);
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

                if (_targetAuraCheck <= diff)
                {
                    _targetAuraCheck = 1000;
                    if (Unit* victim = me->GetVictim())
                    {
                        if (me->GetDistance(victim) < 15.0f &&
                            !victim->HasAura(SPELL_SHADOW_RESONANCE_RESIST, me->GetGUID()))
                        {
                            DoCast(victim, SPELL_SHADOW_RESONANCE_RESIST);
                            me->ClearUnitState(UNIT_STATE_CASTING);
                        }
                        else
                            MoveInLineOfSight(me->GetVictim());
                    }
                }
                else
                    _targetAuraCheck -= diff;
            }

        private:
            uint32 _targetAuraCheck;
            bool _lockedTarget;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_dark_nucleusAI>(creature);
        }
};

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

// 72080 - Kinetic Bomb (Valanar)
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

class spell_blood_council_shadow_prison : public SpellScriptLoader
{
    public:
        spell_blood_council_shadow_prison() : SpellScriptLoader("spell_blood_council_shadow_prison") { }

        class spell_blood_council_shadow_prison_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_blood_council_shadow_prison_AuraScript);

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (GetTarget()->isMoving())
                    GetTarget()->CastSpell(GetTarget(), SPELL_SHADOW_PRISON_DAMAGE, true, NULL, aurEff);
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
                if (Creature* bloodQueen = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_BLOOD_QUEEN_LANA_THEL_COUNCIL)))
                    bloodQueen->AI()->DoAction(ACTION_START_INTRO);

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

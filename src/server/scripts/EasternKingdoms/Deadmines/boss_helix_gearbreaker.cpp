/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "Vehicle.h"
#include "deadmines.h"

enum Texts
{
    // Helix Gearbreaker
    SAY_AGGRO                   = 0,
    SAY_STICKY_BOMB             = 1,
    SAY_THROW_HELIX             = 2,
    SAY_ANNOUNCE_CHEST_BOMB     = 3,
    SAY_OAF_DEAD                = 4,
    SAY_SLAY                    = 5,
    SAY_DEATH                   = 6,

    // Lumbering Oaf
    SAY_OAF_SMASH_1             = 0,
    SAY_OAF_SMASH_2             = 1,

    // Helix' Crew
    SAY_CREW_JOIN_FIGHT         = 0
};

enum Spells
{
    // Helix Gearbreaker
    SPELL_THROW_BOMB_TARGETING          = 88268,
    SPELL_RIDE_FACE_TARGETING           = 88349,
    SPELL_RIDE_VEHICLE_OAF              = 52391,
    SPELL_RIDE_VEHICLE                  = 88360,
    SPELL_HELIX_RIDE_FACE_TIMER_AURA    = 88351,
    SPELL_HELIX_RIDE                    = 88337,
    SPELL_HELIX_CHEST_BOMB_EMOTE        = 91572,
    SPELL_CHEST_BOMB                    = 88352,
    SPELL_CHEST_BOMB_DAMAGE             = 88250,
    SPELL_OAFGUARD                      = 90546,
    SPELL_EMOTE_TALK                    = 79506,

    // Lumbering Oaf
    SPELL_OAF_GRAB_TARGETING            = 88289,
    SPELL_CHARGE                        = 88295,
    SPELL_OAF_SMASH                     = 88300,

    // Sticky Bomb
    SPELL_ARMING_VISUAL_YELLOW          = 88315,
    SPELL_ARMING_VISUAL_ORANGE          = 88316,
    SPELL_ARMING_VISUAL_RED             = 88317,
    SPELL_STICKY_BOMB_ARMED_STATE       = 88319,
    SPELL_STICKY_BOMB_PERIODIC_TRIGGER  = 88329,
    SPELL_EXPLODE                       = 88974,
};

enum DisplayIds
{
    DISPLAY_ID_BOMB_INVISIBLE = 11686,
};

enum Events
{
    // Helix Gearbreaker
    EVENT_STICKY_BOMB = 1,
    EVENT_OAF_SMASH,
    EVENT_THROW_HELIX,
    EVENT_RIDE_FACE,

    // Lumbering Oaf
    EVENT_MOVE_TO_PREPARE_POSITION,
    EVENT_CHARGE_DEST,

    // Sticky Bomb
    EVENT_ARMING_VISUAL_YELLOW,
    EVENT_ARMING_VISUAL_ORANGE,
    EVENT_ARMING_VISUAL_RED,
    EVENT_PREPARED_STATE,
    EVENT_PERIODIC_TRIGGER,
    EVENT_EXPLOSION_COUNTDOWN,
    EVENT_COUNTDOWN,

    // Helix' Crew
    EVENT_TALK_READY,
};

enum Actions
{
    ACTION_OAF_SMASH = 1,
    ACTION_OAF_DEAD,
    ACTION_TALK_CREW,
};

enum Points
{
    POINT_CHARGE_PREP = 1
};

enum Phases
{
    PHASE_1 = 1,
    PHASE_2 = 2
};

Position const ChargePreparationPos = { -289.8343f, -526.2162f, 49.83808f };
Position const ChargePos = { -289.5868f, -489.5746f, 49.91263f };

Position const HelixCrewPositions[] =
{
    { -283.8438f, -503.3698f, 60.512f, 1.902409f },
    { -285.8681f, -503.8264f, 60.55348f, 5.009095f },
    { -292.6788f, -503.7274f, 60.27357f, 4.468043f },
    { -289.8316f, -503.4063f, 60.36356f, 1.815142f }
};

class boss_helix_gearbreaker : public CreatureScript
{
    public:
        boss_helix_gearbreaker() : CreatureScript("boss_helix_gearbreaker") { }

        struct boss_helix_gearbreakerAI : public BossAI
        {
            boss_helix_gearbreakerAI(Creature* creature) : BossAI(creature, DATA_HELIX_GEARBREAKER)
            {
                Initialize();
            }

            void Initialize()
            {
                _crewSummoned = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);

                if (Creature* lumberingOaf = instance->GetCreature(DATA_LUMBERING_OAF))
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, lumberingOaf);

                events.SetPhase(PHASE_1);
                events.ScheduleEvent(EVENT_STICKY_BOMB, Seconds(5), 0, PHASE_1);
                events.ScheduleEvent(EVENT_OAF_SMASH, Seconds(16), 0, PHASE_1);
                events.ScheduleEvent(EVENT_THROW_HELIX, Seconds(34), 0, PHASE_1);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (Creature* lumberingOaf = instance->GetCreature(DATA_LUMBERING_OAF))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, lumberingOaf);
                    lumberingOaf->DespawnOrUnsummon(0, Seconds(30));
                }
                me->DespawnOrUnsummon();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_OAF_DEAD:
                        Talk(SAY_OAF_DEAD);
                        DoCastSelf(SPELL_EMOTE_TALK);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveAurasDueToSpell(SPELL_OAFGUARD);
                        events.SetPhase(PHASE_2);
                        if (!me->GetVehicleBase())
                            events.ScheduleEvent(EVENT_RIDE_FACE, Seconds(2) + Milliseconds(500), 0, PHASE_2);
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth() && me->HasAura(SPELL_OAFGUARD))
                    damage = me->GetHealth() - 1;
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
                        case EVENT_STICKY_BOMB:
                            if (!_crewSummoned && IsHeroic())
                            {
                                for (uint8 i = 0; i < 4; i++)
                                {
                                    if (Creature* crew = DoSummon(NPC_HELIX_CREW, HelixCrewPositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
                                        if (i == 1)
                                            crew->AI()->DoAction(ACTION_TALK_CREW);
                                }
                                _crewSummoned = true;
                            }

                            DoCastAOE(SPELL_THROW_BOMB_TARGETING, true);
                            events.Repeat(Seconds(3) + Milliseconds(500));
                            break;
                        case EVENT_OAF_SMASH:
                            if (Creature* lumberingOaf = me->GetVehicleCreatureBase())
                            {
                                lumberingOaf->AI()->DoAction(ACTION_OAF_SMASH);
                                events.RescheduleEvent(EVENT_STICKY_BOMB, Seconds(10), 0, PHASE_1);
                                events.Repeat(Seconds(52));
                            }
                            break;
                        case EVENT_THROW_HELIX:
                            Talk(SAY_THROW_HELIX);
                            events.ScheduleEvent(EVENT_RIDE_FACE, Seconds(2));
                            events.Repeat(Seconds(52));
                            break;
                        case EVENT_RIDE_FACE:
                            DoCastAOE(SPELL_RIDE_FACE_TARGETING, true);
                            events.RescheduleEvent(EVENT_STICKY_BOMB, Seconds(20), 0, PHASE_1);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
            private:
                bool _crewSummoned;
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetDeadminesAI<boss_helix_gearbreakerAI>(creature);
        }
};

class npc_helix_lumbering_oaf : public CreatureScript
{
    public:
        npc_helix_lumbering_oaf() : CreatureScript("npc_helix_lumbering_oaf") { }

        struct npc_helix_lumbering_oafAI : public ScriptedAI
        {
            npc_helix_lumbering_oafAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void JustEngagedWith(Unit* who) override
            {
                if (Creature* helix = _instance->GetCreature(DATA_HELIX_GEARBREAKER))
                    if (!helix->IsInCombat())
                        helix->AI()->AttackStart(who);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_OAF_SMASH:
                        Talk(SAY_OAF_SMASH_1);
                        DoCastAOE(SPELL_OAF_GRAB_TARGETING, true);
                        break;
                    default:
                        break;
                }
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (!passenger)
                    return;

                if (apply && passenger->GetTypeId() == TYPEID_PLAYER)
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    _events.ScheduleEvent(EVENT_MOVE_TO_PREPARE_POSITION, Milliseconds(500));
                }

                if (!apply && passenger->GetEntry() == BOSS_HELIX_GEARBREAKER && me->IsInCombat())
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, passenger);
                else if (apply && passenger->GetEntry() == BOSS_HELIX_GEARBREAKER && me->IsInCombat())
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, passenger);
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_CHARGE_PREP:
                        me->SetFacingTo(1.570796f);
                        _events.ScheduleEvent(EVENT_CHARGE_DEST, Seconds(1));
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (Creature* helix = _instance->GetCreature(DATA_HELIX_GEARBREAKER))
                    helix->AI()->DoAction(ACTION_OAF_DEAD);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_TO_PREPARE_POSITION:
                            Talk(SAY_OAF_SMASH_2);
                            me->GetMotionMaster()->MovePoint(POINT_CHARGE_PREP, ChargePreparationPos, true);
                            break;
                        case EVENT_CHARGE_DEST:
                            DoCastAOE(SPELL_CHARGE);
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
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_helix_lumbering_oafAI>(creature);
        }
};

class npc_helix_sticky_bomb : public CreatureScript
{
    public:
        npc_helix_sticky_bomb() : CreatureScript("npc_helix_sticky_bomb") { }

        struct npc_helix_sticky_bombAI : public PassiveAI
        {
            npc_helix_sticky_bombAI(Creature* creature) : PassiveAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _countdown = 0;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                _events.ScheduleEvent(EVENT_ARMING_VISUAL_YELLOW, Seconds(2) + Milliseconds(500));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARMING_VISUAL_YELLOW:
                            DoCastSelf(SPELL_ARMING_VISUAL_YELLOW);
                            _events.ScheduleEvent(EVENT_ARMING_VISUAL_ORANGE, Seconds(1));
                            break;
                        case EVENT_ARMING_VISUAL_ORANGE:
                            DoCastSelf(SPELL_ARMING_VISUAL_ORANGE);
                            _events.ScheduleEvent(EVENT_ARMING_VISUAL_RED, Seconds(2));
                            break;
                        case EVENT_ARMING_VISUAL_RED:
                            DoCastSelf(SPELL_ARMING_VISUAL_RED);
                            _events.ScheduleEvent(EVENT_PREPARED_STATE, Seconds(1));
                            break;
                        case EVENT_PREPARED_STATE:
                            DoCastSelf(SPELL_STICKY_BOMB_ARMED_STATE);
                            _events.ScheduleEvent(EVENT_PERIODIC_TRIGGER, Seconds(1));
                            break;
                        case EVENT_PERIODIC_TRIGGER:
                            DoCastSelf(SPELL_STICKY_BOMB_PERIODIC_TRIGGER);
                            _events.ScheduleEvent(EVENT_EXPLOSION_COUNTDOWN, Seconds(15) + Milliseconds(500));
                            break;
                        case EVENT_EXPLOSION_COUNTDOWN:
                            DoCastSelf(SPELL_ARMING_VISUAL_RED);
                            _events.ScheduleEvent(EVENT_COUNTDOWN, Seconds(1));
                            break;
                        case EVENT_COUNTDOWN:
                            if (_countdown != 3)
                            {
                                DoCastSelf(SPELL_ARMING_VISUAL_RED);
                                _countdown++;
                                _events.Repeat(Seconds(1));
                            }
                            else
                            {
                                me->RemoveAllAuras();
                                DoCastSelf(SPELL_EXPLODE, true);
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
            uint8 _countdown;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_helix_sticky_bombAI>(creature);
        }
};

class npc_helix_crew : public CreatureScript
{
    public:
        npc_helix_crew() : CreatureScript("npc_helix_crew") { }

        struct npc_helix_crewAI : public PassiveAI
        {
            npc_helix_crewAI(Creature* creature) : PassiveAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                _events.ScheduleEvent(EVENT_STICKY_BOMB, Seconds(1));
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_TALK_CREW:
                        _events.ScheduleEvent(EVENT_TALK_READY, Seconds(1));
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
                        case EVENT_STICKY_BOMB:
                            DoCastAOE(SPELL_THROW_BOMB_TARGETING, true);
                            _events.Repeat(Seconds(5));
                            break;
                        case EVENT_TALK_READY:
                            Talk(SAY_CREW_JOIN_FIGHT);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_helix_crewAI>(creature);
        }
};

class spell_helix_throw_bomb_targeting : public SpellScriptLoader
{
    public:
        spell_helix_throw_bomb_targeting() : SpellScriptLoader("spell_helix_throw_bomb_targeting") { }

        class spell_helix_throw_bomb_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_throw_bomb_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                GetCaster()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_helix_throw_bomb_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_helix_throw_bomb_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_helix_throw_bomb_targeting_SpellScript();
        }
};

class spell_helix_sticky_bomb_periodic_trigger : public SpellScriptLoader
{
    public:
        spell_helix_sticky_bomb_periodic_trigger() : SpellScriptLoader("spell_helix_sticky_bomb_periodic_trigger") { }

        class spell_helix_sticky_bomb_periodic_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_helix_sticky_bomb_periodic_trigger_AuraScript);

            void HandleTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell))
                        if (Player* player = caster->SelectNearestPlayer(spell->Effects[EFFECT_0].CalcRadius()))
                            if (!player->GetVehicleBase())
                                caster->CastSpell(GetCaster()->GetVictim(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_helix_sticky_bomb_periodic_trigger_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_helix_sticky_bomb_periodic_trigger_AuraScript();
        }
};

class spell_helix_explode : public SpellScriptLoader
{
    public:
        spell_helix_explode() : SpellScriptLoader("spell_helix_explode") { }

        class spell_helix_explode_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_explode_SpellScript);

            void HandleLaunch(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->GetTypeId() == TYPEID_UNIT)
                    {
                        caster->RemoveAllAuras();
                        caster->SetDisplayId(DISPLAY_ID_BOMB_INVISIBLE);
                        caster->ToCreature()->DespawnOrUnsummon(Seconds(2) + Milliseconds(400));
                    }
                }
            }

            void Register() override
            {
                OnEffectLaunch += SpellEffectFn(spell_helix_explode_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        private:
            uint8 _targetsCounter;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_helix_explode_SpellScript();
        }
};

class spell_helix_oaf_grab_targeting : public SpellScriptLoader
{
    public:
        spell_helix_oaf_grab_targeting() : SpellScriptLoader("spell_helix_oaf_grab_targeting") { }

        class spell_helix_oaf_grab_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_oaf_grab_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                GetCaster()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_helix_oaf_grab_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_helix_oaf_grab_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_helix_oaf_grab_targeting_SpellScript();
        }
};

class spell_helix_force_player_to_ride_oaf : public SpellScriptLoader
{
    public:
        spell_helix_force_player_to_ride_oaf() : SpellScriptLoader("spell_helix_force_player_to_ride_oaf") { }

        class spell_helix_force_player_to_ride_oaf_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_force_player_to_ride_oaf_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetHitUnit())
                        if (caster->GetVehicleKit())
                        {
                            target->CastStop();
                            target->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints, false);
                        }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_helix_force_player_to_ride_oaf_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_helix_force_player_to_ride_oaf_SpellScript();
        }
};

class spell_helix_oaf_smash : public SpellScriptLoader
{
    public:
        spell_helix_oaf_smash() : SpellScriptLoader("spell_helix_oaf_smash") { }

        class spell_helix_oaf_smash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_oaf_smash_SpellScript);

            void HandleLaunch(SpellEffIndex effIndex)
            {
                // We do our own knockback here because the boss is immune to knockback effects
                // ... and because we have to use some additional spellinfo data
                if (Unit* caster = GetCaster())
                {
                    float angle = caster->GetOrientation();
                    float x = caster->GetPositionX() + cos(angle) * 1;
                    float y = caster->GetPositionX() + sin(angle) * 1;
                    float speedxy = float(GetSpellInfo()->Effects[effIndex].MiscValue) * 0.1;
                    float speedz = float(GetSpellInfo()->Effects[effIndex].MiscValueB) * 0.1;

                    caster->KnockbackFrom(x, y, speedxy, speedz);

                    if (Creature* creature = caster->ToCreature())
                    {
                        creature->SetReactState(REACT_AGGRESSIVE);
                        creature->setAttackTimer(BASE_ATTACK, creature->GetFloatValue(UNIT_FIELD_BASEATTACKTIME));
                    }
                }
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_helix_oaf_smash_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_helix_oaf_smash_SpellScript();
        }
};

class spell_helix_ride_face_targeting : public SpellScriptLoader
{
    public:
        spell_helix_ride_face_targeting() : SpellScriptLoader("spell_helix_ride_face_targeting") { }

        class spell_helix_ride_face_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_ride_face_targeting_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_HELIX_RIDE,
                    SPELL_HELIX_RIDE_FACE_TIMER_AURA
                });
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HELIX_RIDE));

                if (targets.empty())
                {
                    if (Unit* caster = GetCaster())
                        caster->CastSpell(caster, SPELL_HELIX_RIDE_FACE_TIMER_AURA, true);
                    return;
                }

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (Creature* creature = caster->ToCreature())
                            if (creature->IsAIEnabled && creature->GetVictim())
                                creature->getThreatManager().modifyThreatPercent(caster->GetVictim(), -100);

                        caster->CastSpell(caster, SPELL_HELIX_RIDE_FACE_TIMER_AURA, true);
                        // Until we have core support for hiding vehicle datas clientside, we handle it like this
                        target->AddAura(SPELL_HELIX_RIDE, target);
                        caster->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_helix_ride_face_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_helix_ride_face_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_helix_ride_face_targeting_SpellScript();
        }
};

class spell_helix_ride_vehicle : public SpellScriptLoader
{
    public:
        spell_helix_ride_vehicle() : SpellScriptLoader("spell_helix_ride_vehicle") { }

        class spell_helix_ride_vehicle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_ride_vehicle_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Creature* creature = caster->ToCreature())
                    {
                        if (creature->IsAIEnabled)
                        {
                            creature->SetReactState(REACT_AGGRESSIVE);
                            creature->AI()->AttackStart(GetHitUnit());
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_helix_ride_vehicle_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_THREAT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_helix_ride_vehicle_SpellScript();
        }

        class spell_helix_ride_vehicle_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_helix_ride_vehicle_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_RIDE_VEHICLE });
            }

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetOwner()->ToUnit())
                    owner->RemoveAurasDueToSpell(SPELL_HELIX_RIDE);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_helix_ride_vehicle_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_helix_ride_vehicle_AuraScript();
        }
};

class spell_helix_ride_face_timer_aura: public SpellScriptLoader
{
    public:
        spell_helix_ride_face_timer_aura() : SpellScriptLoader("spell_helix_ride_face_timer_aura") { }

        class spell_helix_ride_face_timer_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_helix_ride_face_timer_aura_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_RIDE_VEHICLE_OAF,
                    SPELL_CHEST_BOMB,
                    SPELL_HELIX_CHEST_BOMB_EMOTE
                });
            }

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetOwner()->ToUnit())
                {
                    if (InstanceScript* instance = owner->GetInstanceScript())
                    {
                        if (Unit* vehicle = owner->GetVehicleBase())
                        {
                            if (owner->GetMap() && owner->GetMap()->IsHeroic())
                                if (vehicle->GetTypeId() == TYPEID_PLAYER)
                                {
                                    owner->CastSpell(vehicle, SPELL_CHEST_BOMB, true);
                                    owner->CastSpell(vehicle, SPELL_HELIX_CHEST_BOMB_EMOTE, true);
                                }

                            if (Creature* oaf = instance->GetCreature(DATA_LUMBERING_OAF))
                            {
                                if (oaf->IsAlive())
                                {
                                    owner->CastSpell(oaf, SPELL_RIDE_VEHICLE_OAF);
                                    if (Creature* creature = owner->ToCreature())
                                    {
                                        creature->AttackStop();
                                        creature->SetReactState(REACT_PASSIVE);
                                    }
                                }
                                else
                                    owner->CastSpell(owner, SPELL_RIDE_FACE_TARGETING, true);
                            }
                            vehicle->RemoveAurasDueToSpell(SPELL_HELIX_RIDE);
                        }
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_helix_ride_face_timer_aura_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_helix_ride_face_timer_aura_AuraScript();
        }
};

class spell_helix_chest_bomb_emote : public SpellScriptLoader
{
    public:
        spell_helix_chest_bomb_emote() : SpellScriptLoader("spell_helix_chest_bomb_emote") { }

        class spell_helix_chest_bomb_emote_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_helix_chest_bomb_emote_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* creature = caster->ToCreature())
                        if (creature->IsAIEnabled)
                            creature->AI()->Talk(SAY_ANNOUNCE_CHEST_BOMB, GetHitUnit());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_helix_chest_bomb_emote_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_helix_chest_bomb_emote_SpellScript();
        }
};

class spell_helix_chest_bomb : public SpellScriptLoader
{
    public:
        spell_helix_chest_bomb() : SpellScriptLoader("spell_helix_chest_bomb") { }

        class spell_helix_chest_bomb_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_helix_chest_bomb_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_CHEST_BOMB_DAMAGE });
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (Unit* owner = GetOwner()->ToUnit())
                    owner->CastSpell(owner, SPELL_CHEST_BOMB_DAMAGE, true);
            }

            void Register() override
            {
                 OnEffectPeriodic += AuraEffectPeriodicFn(spell_helix_chest_bomb_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_helix_chest_bomb_AuraScript();
        }
};

void AddSC_boss_helix_gearbreaker()
{
    new boss_helix_gearbreaker();
    new npc_helix_lumbering_oaf();
    new npc_helix_sticky_bomb();
    new npc_helix_crew();
    new spell_helix_throw_bomb_targeting();
    new spell_helix_sticky_bomb_periodic_trigger();
    new spell_helix_explode();
    new spell_helix_oaf_grab_targeting();
    new spell_helix_force_player_to_ride_oaf();
    new spell_helix_oaf_smash();
    new spell_helix_ride_face_targeting();
    new spell_helix_ride_vehicle();
    new spell_helix_ride_face_timer_aura();
    new spell_helix_chest_bomb_emote();
    new spell_helix_chest_bomb();
}

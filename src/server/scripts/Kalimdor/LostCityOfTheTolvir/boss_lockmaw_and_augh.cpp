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
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Texts
{
    // Augh Boss
    SAY_ANNOUNCE_AUGH_APPEAR    = 0,
    SAY_AUGH_INTRO_1            = 1,
    SAY_AUGH_INTRO_2            = 2,
    SAY_AUGH_TAUNT_1            = 3,
    SAY_AUGH_TAUNT_2            = 4,
    SAY_AUGH_TAUNT_3            = 5
};

enum Spells
{
    // Lockmaw
    SPELL_VISCOUS_POISON        = 81630,
    SPELL_SCENT_OF_BLOOD        = 81690,
    SPELL_SCENT_OF_BLOOD_HC     = 89998,
    SPELL_DUST_FLAIL_DUMMY      = 81652,
    SPELL_DUST_FLAIL            = 81642,
    SPELL_VENOMOUS_RAGE         = 81706,

    // Frenzied Crocolisk
    SPELL_STEALTHED             = 84244,

    // Augh (Combat Assistance)
    SPELL_PARALYTIC_BLOW_DART   = 84799,
    SPELL_SMOKE_BOMB            = 84768,
    SPELL_RANDOM_AGGRO_TAUNT    = 50230,
    SPELL_WHIRLWIND             = 84784,

    // Augh (Heroic Boss)
    SPELL_DRAGONS_BREATH        = 83776,
    SPELL_FRENZY                = 91415,
    SPELL_WHIRLWIND_BOSS        = 91408
};

enum Events
{
    // Lockmaw
    EVENT_VISCOUS_POISON = 1,
    EVENT_SCENT_OF_BLOOD,
    EVENT_DUST_FLAIL,
    EVENT_MAKE_AGGRESSIVE,
    EVENT_SUMMON_CROCOLISK,
    EVENT_SUMMON_AUGH,

    // Frenzied Crocolisk
    EVENT_FIND_PLAYER_TARGET,

    // Augh (Assistance)
    EVENT_ROAR_EMOTE,
    EVENT_PARALYTIC_BLOW_DART,
    EVENT_SMOKE_BOMB,
    EVENT_WHIRLWIND,
    EVENT_RANDOM_AGGRO,
    EVENT_ATTACK_STOP,

    // Augh Boss
    EVENT_MOVE_HOME_POS,
    EVENT_TALK_INTRO_1,
    EVENT_TALK_INTRO_2,
    EVENT_PLAY_EMOTE,
    EVENT_MAKE_ATTACKABLE,
    EVENT_TALK_TAUNT_1,
    EVENT_TALK_TAUNT_2,
    EVENT_TALK_TAUNT_3,
    EVENT_DRAGONS_BREATH

};

enum Phases
{
    PHASE_INTRO = 1,
    PHASE_COMBAT
};

enum Actions
{
    ACTION_AUGH_INTRO       = 1,
    ACTION_AUGH_ATTACKABLE  = 2
};

Position const AughMovePoint = { -11062.5f, -1662.39f, 0.7606202f, 0.8028514f };

class ScentOfBloodTargetSelector
{
    public:
        ScentOfBloodTargetSelector() { }

        bool operator()(Unit* unit) const
        {
            return (unit->HasAura(SPELL_SCENT_OF_BLOOD) || unit->HasAura(SPELL_SCENT_OF_BLOOD_HC));
        }
};

class boss_lockmaw : public CreatureScript
{
    public:
        boss_lockmaw() : CreatureScript("boss_lockmaw") { }

        struct boss_lockmawAI : public BossAI
        {
            boss_lockmawAI(Creature* creature) : BossAI(creature, DATA_LOCKMAW)
            {
                Initialize();
            }

            void Initialize()
            {
                _enraged = false;
                _lastSpellID = 0;
            }

            void Reset() override
            {
                instance->SetBossState(DATA_LOCKMAW_AND_AUGH, NOT_STARTED);
                instance->SetData(DATA_LOCKMAW_COMBAT_ASSISTANCE, ASSISTANCE_NONE);
                _Reset();
                Initialize();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_VISCOUS_POISON, Seconds(6));
                events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, Seconds(6));
                events.ScheduleEvent(EVENT_DUST_FLAIL, Seconds(8));
                events.ScheduleEvent(EVENT_SUMMON_AUGH, Seconds(6));
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _DespawnAtEvade();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_DUST_FLAIL_FRONT_STALKER)
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->StopMoving();
                    me->AttackStop();
                    me->SetFacingToObject(summon);
                    DoCastSelf(SPELL_DUST_FLAIL);
                    events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, Seconds(5));
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HealthBelowPct(30) && !_enraged)
                {
                    DoCastSelf(SPELL_VENOMOUS_RAGE, true);
                    _enraged = true;
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
                        case EVENT_VISCOUS_POISON:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true, 0))
                                DoCast(target, SPELL_VISCOUS_POISON);
                            events.Repeat(Seconds(26));
                            break;
                        case EVENT_SCENT_OF_BLOOD:
                            DoCastAOE(SPELL_SCENT_OF_BLOOD, true);
                            events.ScheduleEvent(EVENT_SCENT_OF_BLOOD, Seconds(30));
                            events.ScheduleEvent(EVENT_SUMMON_CROCOLISK, Milliseconds(100));
                            break;
                        case EVENT_SUMMON_CROCOLISK:
                            instance->SetData(DATA_LOCKMAW_COMBAT_ASSISTANCE, ASSISTANCE_SUMMON_CROCOLISKS);
                            break;
                        case EVENT_DUST_FLAIL:
                            DoCastAOE(SPELL_DUST_FLAIL_DUMMY, true);
                            events.Repeat(Seconds(39));
                            break;
                        case EVENT_MAKE_AGGRESSIVE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_SUMMON_AUGH:
                            if (_lastSpellID != SPELL_SUMMON_AUGH_DART)
                            {
                                _lastSpellID = SPELL_SUMMON_AUGH_DART;
                                instance->SetData(DATA_LOCKMAW_COMBAT_ASSISTANCE, ASSISTANCE_SUMMON_AUGH_DART);
                                events.Repeat(Seconds(20));
                            }
                            else
                            {
                                _lastSpellID = SPELL_SUMMON_AUGH_WHIRLWIND;
                                instance->SetData(DATA_LOCKMAW_COMBAT_ASSISTANCE, ASSISTANCE_SUMMON_AUGH_WHIRLWIND);
                                events.Repeat(Seconds(40));
                            }
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            bool _enraged;
            uint32 _lastSpellID;
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return GetLostCityOfTheTolvirAI<boss_lockmawAI>(creature);
        }
};

class boss_augh : public CreatureScript
{
    public:
        boss_augh() : CreatureScript("boss_augh") { }

        struct boss_aughAI : public BossAI
        {
            boss_aughAI(Creature* creature) : BossAI(creature, DATA_AUGH)
            {
                Initialize();
            }

            void Initialize()
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                DoCastSelf(SPELL_FRENZY);
                events.Reset();
                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_PARALYTIC_BLOW_DART, Seconds(8));
                events.ScheduleEvent(EVENT_WHIRLWIND, Seconds(9));
                events.ScheduleEvent(EVENT_DRAGONS_BREATH, Seconds(6));
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SetBossState(DATA_AUGH, FAIL);
                _DespawnAtEvade();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_AUGH_INTRO:
                        Talk(SAY_ANNOUNCE_AUGH_APPEAR);
                        events.SetPhase(PHASE_INTRO);
                        events.ScheduleEvent(EVENT_MOVE_HOME_POS, Seconds(1));
                        break;
                    case ACTION_AUGH_ATTACKABLE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_HOME_POS:
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(0, AughMovePoint, true);
                            events.ScheduleEvent(EVENT_TALK_INTRO_1, Seconds(10) + Milliseconds(500), 0, PHASE_INTRO);
                            break;
                        case EVENT_TALK_INTRO_1:
                            me->SetFacingTo(AughMovePoint.GetOrientation());
                            Talk(SAY_AUGH_INTRO_1);
                            events.ScheduleEvent(EVENT_TALK_INTRO_2, Seconds(4), 0, PHASE_INTRO);
                            break;
                        case EVENT_TALK_INTRO_2:
                            Talk(SAY_AUGH_INTRO_2);
                            events.ScheduleEvent(EVENT_PLAY_EMOTE, Seconds(3), 0, PHASE_INTRO);
                            break;
                        case EVENT_PLAY_EMOTE:
                            me->HandleEmoteCommand(EMOTE_STATE_SPELL_CHANNEL_OMNI);
                            events.ScheduleEvent(EVENT_MAKE_ATTACKABLE, Seconds(4), 0, PHASE_INTRO);
                            events.ScheduleEvent(EVENT_TALK_TAUNT_1, Seconds(15), PHASE_INTRO);
                            break;
                        case EVENT_MAKE_ATTACKABLE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                            break;
                        case EVENT_TALK_TAUNT_1:
                            Talk(SAY_AUGH_TAUNT_1);
                            events.ScheduleEvent(EVENT_TALK_TAUNT_2, Seconds(8), 0, PHASE_INTRO);
                            break;
                        case EVENT_TALK_TAUNT_2:
                            Talk(SAY_AUGH_TAUNT_2);
                            events.ScheduleEvent(EVENT_TALK_TAUNT_3, Seconds(8), 0, PHASE_INTRO);
                            break;
                        case EVENT_TALK_TAUNT_3:
                            Talk(SAY_AUGH_TAUNT_3);
                            events.ScheduleEvent(EVENT_TALK_TAUNT_1, Seconds(8), 0, PHASE_INTRO);
                            break;
                        case EVENT_PARALYTIC_BLOW_DART:
                            DoCastAOE(SPELL_PARALYTIC_BLOW_DART);
                            events.Repeat(Seconds(10), Seconds(15));
                            break;
                        case EVENT_WHIRLWIND:
                            DoCastAOE(SPELL_RANDOM_AGGRO_TAUNT, true);
                            DoCastSelf(SPELL_WHIRLWIND_BOSS);
                            events.Repeat(Seconds(29));
                            break;
                        case EVENT_DRAGONS_BREATH:
                            DoCastAOE(SPELL_DRAGONS_BREATH);
                            events.Repeat(Seconds(28));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return GetLostCityOfTheTolvirAI<boss_aughAI>(creature);
        }
};

class npc_lockmaw_frenzied_crocolisk : public CreatureScript
{
    public:
        npc_lockmaw_frenzied_crocolisk() :  CreatureScript("npc_lockmaw_frenzied_crocolisk") { }

        struct npc_lockmaw_frenzied_crocoliskAI : public ScriptedAI
        {
            npc_lockmaw_frenzied_crocoliskAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(Seconds(5));
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                if (Creature* lockmaw = _instance->GetCreature(DATA_LOCKMAW))
                    lockmaw->AI()->JustSummoned(me);
                me->SetReactState(REACT_PASSIVE);
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_FIND_PLAYER_TARGET, Seconds(1));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIND_PLAYER_TARGET:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, ScentOfBloodTargetSelector()))
                            {
                                DoCastSelf(SPELL_STEALTHED);
                                AddThreat(target, 50000000.0f);
                                AttackStart(target);
                            }
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetLostCityOfTheTolvirAI<npc_lockmaw_frenzied_crocoliskAI>(creature);
        }
};

class npc_lockmaw_augh : public CreatureScript
{
    public:
        npc_lockmaw_augh() :  CreatureScript("npc_lockmaw_augh") { }

        struct npc_lockmaw_aughAI : public ScriptedAI
        {
            npc_lockmaw_aughAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                if (Creature* lockmaw = _instance->GetCreature(DATA_LOCKMAW))
                    lockmaw->AI()->JustSummoned(me);

                DoCastSelf(SPELL_STEALTHED, true);

                if (me->GetEntry() == NPC_AUGH_DART)
                {
                    me->SetReactState(REACT_PASSIVE);
                    _events.ScheduleEvent(EVENT_ROAR_EMOTE, Seconds(7));
                    _events.ScheduleEvent(EVENT_PARALYTIC_BLOW_DART, Seconds(8));
                    _events.ScheduleEvent(EVENT_SMOKE_BOMB, Seconds(12));
                }
                else
                    _events.ScheduleEvent(EVENT_WHIRLWIND, Seconds(4));
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                // There is indeed now immunity aura...
                damage = 0;
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ROAR_EMOTE:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_BATTLE_ROAR);
                            break;
                        case EVENT_PARALYTIC_BLOW_DART:
                            DoCastAOE(SPELL_PARALYTIC_BLOW_DART);
                            break;
                        case EVENT_SMOKE_BOMB:
                            DoCastSelf(SPELL_SMOKE_BOMB);
                            me->DespawnOrUnsummon(Seconds(3));
                            break;
                        case EVENT_WHIRLWIND:
                            DoCastAOE(SPELL_RANDOM_AGGRO_TAUNT, true);
                            DoCastSelf(SPELL_WHIRLWIND);
                            _events.ScheduleEvent(EVENT_RANDOM_AGGRO, Seconds(10));
                            break;
                        case EVENT_RANDOM_AGGRO:
                            DoCastAOE(SPELL_RANDOM_AGGRO_TAUNT, true);
                            _events.ScheduleEvent(EVENT_ATTACK_STOP, Seconds(10));
                            break;
                        case EVENT_ATTACK_STOP:
                            me->AttackStop();
                            me->SetReactState(REACT_PASSIVE);
                            me->DespawnOrUnsummon(Seconds(6));
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetLostCityOfTheTolvirAI<npc_lockmaw_aughAI>(creature);
        }
};

class spell_lockmaw_scent_of_blood : public SpellScriptLoader
{
    public:
        spell_lockmaw_scent_of_blood() : SpellScriptLoader("spell_lockmaw_scent_of_blood") { }

        class spell_lockmaw_scent_of_blood_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_lockmaw_scent_of_blood_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_lockmaw_scent_of_blood_SpellScript();
        }
};

class spell_lockmaw_paralytic_blow_dart : public SpellScriptLoader
{
    public:
        spell_lockmaw_paralytic_blow_dart() : SpellScriptLoader("spell_lockmaw_paralytic_blow_dart") { }

        class spell_lockmaw_paralytic_blow_dart_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_lockmaw_paralytic_blow_dart_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_lockmaw_paralytic_blow_dart_SpellScript();
        }
};

class spell_lockmaw_random_aggro_taunt : public SpellScriptLoader
{
    public:
        spell_lockmaw_random_aggro_taunt() : SpellScriptLoader("spell_lockmaw_random_aggro_taunt") { }

        class spell_lockmaw_random_aggro_taunt_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void EffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetHitPlayer()->CastSpell(GetCaster(), GetSpellInfo()->Effects[EFFECT_0].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_lockmaw_random_aggro_taunt_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget.Register(&spell_lockmaw_random_aggro_taunt_SpellScript::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_lockmaw_random_aggro_taunt_SpellScript();
        }
};

void AddSC_boss_lockmaw_and_augh()
{
    new boss_lockmaw();
    new boss_augh();
    new npc_lockmaw_frenzied_crocolisk();
    new npc_lockmaw_augh();
    new spell_lockmaw_scent_of_blood();
    new spell_lockmaw_paralytic_blow_dart();
    new spell_lockmaw_random_aggro_taunt();
}

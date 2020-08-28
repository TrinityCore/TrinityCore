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

#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "deadmines.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"

enum Texts
{
    // Admiral Ripsnarl
    SAY_AGGRO               = 0,
    SAY_FOG_1               = 1,
    SAY_FOG_2               = 2,
    SAY_SLAY                = 3,
    SAY_GO_FOR_THE_THROAT   = 4,
    SAY_ANNOUNCE_VAPORS     = 5,
    SAY_DEATH               = 6
};

enum Spells
{
    // Admiral Ripsnarl
    SPELL_RIPSNARL_CANNON_KILL              = 95408,
    SPELL_THIRST_FOR_BLOOD                  = 88736,
    SPELL_SWIPE                             = 88839,
    SPELL_EMOTE_TALK                        = 79506,
    SPELL_VANISH                            = 88840,
    SPELL_GO_FOR_THE_THROAT_TARGETING       = 88838,
    SPELL_SUMMON_VAPOR_TARGETING            = 88833,
    SPELL_WEAR_CHRISTMAS_HAT_RED_SELF_DND   = 61400,

    // Vapor
    SPELL_STEAM_AURA                        = 95503,
    SPELL_CONDENSATION                      = 92013,
    SPELL_SWIRLING_VAPOR                    = 92007,
    SPELL_CONDENSING_VAPOR                  = 92008,
    SPELL_FREEZING_VAPOR                    = 92011,
    SPELL_COALESCE                          = 92042,
    SPELL_CONDENSE_TRANSFORM_1              = 92016,
    SPELL_CONDENSE_TRANSFORM_2              = 92020,
    SPELL_VAPOR_ANIMUS                      = 92038,

    // General Purpose Bunny JMF
    SPELL_RIPSNARLS_FOG_AURA                = 89247
};

enum Events
{
    // Admiral Ripsnarl
    EVENT_SWIPE = 1,
    EVENT_SAY_VANISH_INTRO,
    EVENT_VANISH,
    EVENT_CAST_VANISH,
    EVENT_CAST_RIPSNARLS_FOG_AURA,
    EVENT_GO_FOR_THE_THROAT,
    EVENT_SUMMON_VAPOR,

    // Vapor
    EVENT_VAPOR,
};

enum Sounds
{
    SOUND_HOWL = 19881
};

enum Misc
{
    GAME_EVENT_WINTER_VEIL = 2
};

class boss_admiral_ripsnarl: public CreatureScript
{
    public:
        boss_admiral_ripsnarl() : CreatureScript("boss_admiral_ripsnarl") { }

        struct boss_admiral_ripsnarlAI : public BossAI
        {
            boss_admiral_ripsnarlAI(Creature* creature) : BossAI(creature, DATA_ADMIRAL_RIPSNARL), _vanishCounter(0) { }

            void JustAppeared() override
            {
                if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
                    DoCastSelf(SPELL_WEAR_CHRISTMAS_HAT_RED_SELF_DND);

                if (Creature* bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 50.0f, true))
                    _bunnyGuid = bunny->GetGUID();

                DoCastSelf(SPELL_THIRST_FOR_BLOOD, true);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
                DoCastAOE(SPELL_RIPSNARL_CANNON_KILL, true);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_SWIPE, Seconds(3) + Milliseconds(500));
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_GO_FOR_THE_THROAT, Seconds(11));
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetData(DATA_RIPSNARL_FOG, NOT_STARTED);
                Talk(SAY_DEATH);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetData(DATA_RIPSNARL_FOG, NOT_STARTED);
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                if (_firstVaporGuid.IsEmpty())
                    _firstVaporGuid = summon->GetGUID();
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                switch (summon->GetEntry())
                {
                    case NPC_VAPOR:
                        if (summon->GetGUID() == _firstVaporGuid)
                            Talk(SAY_GO_FOR_THE_THROAT);
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (HealthBelowPct(75) && _vanishCounter == 0)
                {
                    Talk(SAY_FOG_1);
                    DoCastSelf(SPELL_EMOTE_TALK, true);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_GO_FOR_THE_THROAT);
                    events.CancelEvent(EVENT_SWIPE);
                    events.CancelEvent(EVENT_SUMMON_VAPOR);
                    events.ScheduleEvent(EVENT_VANISH, Seconds(3) + Milliseconds(600));
                    events.ScheduleEvent(EVENT_SAY_VANISH_INTRO, Seconds(3) + Milliseconds(600));
                    events.ScheduleEvent(EVENT_CAST_RIPSNARLS_FOG_AURA, Seconds(3) + Milliseconds(600));
                    _vanishCounter++;
                }
                else if (HealthBelowPct(50) && _vanishCounter == 1)
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_GO_FOR_THE_THROAT);
                    events.CancelEvent(EVENT_SWIPE);
                    events.CancelEvent(EVENT_SUMMON_VAPOR);
                    events.ScheduleEvent(EVENT_VANISH, Milliseconds(1));
                    _vanishCounter++;
                }
                else if (HealthBelowPct(25) && _vanishCounter == 2)
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_GO_FOR_THE_THROAT);
                    events.CancelEvent(EVENT_SWIPE);
                    events.CancelEvent(EVENT_SUMMON_VAPOR);
                    events.ScheduleEvent(EVENT_VANISH, Milliseconds(1));
                    _vanishCounter++;
                }
                else if (IsHeroic() && HealthBelowPct(10) && _vanishCounter == 3)
                {
                    for (uint8 i = 0; i < 3; i++)
                        DoCastAOE(SPELL_SUMMON_VAPOR_TARGETING, true);

                    _vanishCounter++;
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
                        case EVENT_SWIPE:
                            DoCastVictim(SPELL_SWIPE);
                            events.Repeat(Seconds(3) + Milliseconds(500));
                            break;
                        case EVENT_SAY_VANISH_INTRO:
                            Talk(SAY_FOG_2);
                            instance->SetData(DATA_RIPSNARL_FOG, IN_PROGRESS);
                            break;
                        case EVENT_VANISH:
                        {
                            float angle = me->GetOrientation() + float(M_PI);
                            float x = me->GetPositionX() + cos(angle) * 5;
                            float y = me->GetPositionY() + sin(angle) * 5;
                            float z = me->GetPositionZ();
                            me->GetMotionMaster()->MovePoint(0, x, y, z, false);

                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            _firstVaporGuid.Clear();
                            events.ScheduleEvent(EVENT_CAST_VANISH, Milliseconds(1));
                            events.ScheduleEvent(EVENT_GO_FOR_THE_THROAT, Seconds(22) + Milliseconds(500));
                            events.ScheduleEvent(EVENT_SUMMON_VAPOR, Seconds(3));
                            break;
                        }
                        case EVENT_CAST_VANISH:
                            DoCastSelf(SPELL_VANISH);
                            break;
                        case EVENT_CAST_RIPSNARLS_FOG_AURA:
                            if (Creature* bunny = ObjectAccessor::GetCreature(*me, _bunnyGuid))
                                bunny->CastSpell(bunny, SPELL_RIPSNARLS_FOG_AURA);
                            events.Repeat(Seconds(2));
                            break;
                        case EVENT_GO_FOR_THE_THROAT:
                            if (me->HasAura(SPELL_VANISH))
                            {
                                me->RemoveAurasDueToSpell(SPELL_VANISH);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                me->SetReactState(REACT_AGGRESSIVE);
                                me->PlayDirectSound(SOUND_HOWL);
                                events.ScheduleEvent(EVENT_SWIPE, Seconds(3) + Milliseconds(500));
                                events.RescheduleEvent(EVENT_SUMMON_VAPOR, Seconds(10));
                            }
                            DoCastAOE(SPELL_GO_FOR_THE_THROAT_TARGETING, true);
                            if (IsHeroic())
                                events.Repeat(_vanishCounter > 0 ? Seconds(9) + Milliseconds(500) : Seconds(10), _vanishCounter > 0 ? Seconds(10) : Seconds(12));
                            break;
                        case EVENT_SUMMON_VAPOR:
                            DoCastAOE(SPELL_SUMMON_VAPOR_TARGETING, true);
                            events.Repeat(me->HasAura(SPELL_VANISH) ? Seconds(4) : Seconds(12), me->HasAura(SPELL_VANISH) ? Seconds(5) : Seconds(16));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            uint8 _vanishCounter;
            ObjectGuid _firstVaporGuid;
            ObjectGuid _bunnyGuid;
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetDeadminesAI<boss_admiral_ripsnarlAI>(creature);
        }
};

class npc_ripsnarl_vapor : public CreatureScript
{
    public:
        npc_ripsnarl_vapor() : CreatureScript("npc_ripsnarl_vapor") { }

        struct npc_ripsnarl_vaporAI : public ScriptedAI
        {
            npc_ripsnarl_vaporAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCastSelf(SPELL_STEAM_AURA, true);
                if (Player* player = me->SelectNearestPlayer(50.0f))
                    me->AI()->AttackStart(player);

                if (IsHeroic())
                {
                    DoCastSelf(SPELL_CONDENSATION, true);
                    _events.ScheduleEvent(EVENT_VAPOR, Seconds(3), Seconds(4));
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(Seconds(5));
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_VAPOR_ANIMUS)
                    DoCastAOE(SPELL_COALESCE, true);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_VAPOR:
                        {
                            uint32 spellId = SPELL_SWIRLING_VAPOR;
                            if (me->HasAura(SPELL_CONDENSE_TRANSFORM_1))
                                spellId = SPELL_CONDENSING_VAPOR;
                            else if (me->HasAura(SPELL_CONDENSE_TRANSFORM_2))
                                spellId = SPELL_FREEZING_VAPOR;

                            DoCastSelf(spellId);
                            _events.Repeat(Seconds(9), Seconds(10));
                            break;
                        }
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_ripsnarl_vaporAI>(creature);
        }
};

class TargetingCheck
{
    public:
        TargetingCheck() { }

        bool operator()(WorldObject* object)
        {
            if (Unit* unit = object->ToUnit())
                if ((unit->IsCharmedOwnedByPlayerOrPlayer()) || unit->GetTypeId() == TYPEID_PLAYER)
                    return false;

            return true;
        }
};

class spell_ripsnarl_go_for_the_throat_targeting : public SpellScriptLoader
{
    public:
        spell_ripsnarl_go_for_the_throat_targeting() : SpellScriptLoader("spell_ripsnarl_go_for_the_throat_targeting") { }

        class spell_ripsnarl_go_for_the_throat_targeting_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(TargetingCheck());

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_ripsnarl_go_for_the_throat_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget.Register(&spell_ripsnarl_go_for_the_throat_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ripsnarl_go_for_the_throat_targeting_SpellScript();
        }
};

class spell_ripsnarl_summon_vapor_targeting : public SpellScriptLoader
{
    public:
        spell_ripsnarl_summon_vapor_targeting() : SpellScriptLoader("spell_ripsnarl_summon_vapor_targeting") { }

        class spell_ripsnarl_summon_vapor_targeting_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                {
                    if (Creature* caster = GetCaster()->ToCreature())
                        caster->AI()->EnterEvadeMode();
                    return;
                }

                targets.remove_if(TargetingCheck());

                if (targets.empty())
                {
                    if (Creature* caster = GetCaster()->ToCreature())
                        caster->AI()->EnterEvadeMode();
                    return;
                }

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                GetCaster()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_ripsnarl_summon_vapor_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget.Register(&spell_ripsnarl_summon_vapor_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ripsnarl_summon_vapor_targeting_SpellScript();
        }
};

void AddSC_boss_admiral_ripsnarl()
{
    new boss_admiral_ripsnarl();
    new npc_ripsnarl_vapor();
    new spell_ripsnarl_go_for_the_throat_targeting();
    new spell_ripsnarl_summon_vapor_targeting();
}

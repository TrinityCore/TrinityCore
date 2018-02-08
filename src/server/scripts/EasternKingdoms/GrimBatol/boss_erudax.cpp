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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "grim_batol.h"

enum Spells
{
    // Erudax
    SPELL_BINDING_SHADOWS                       = 79466,
    SPELL_ENFEEBLING_BLOW                       = 75789,
    SPELL_SHADOW_GALE_TRIGGER                   = 75656,
    SPELL_SHADOW_GALE                           = 75664,
    SPELL_SUMMON_FACELESS_CORRUPTOR             = 75704,
    SPELL_SHIELD_OF_NIGHTMARES                  = 75809,

    // Shadow Gale Controller
    SPELL_SUMMON_SHADOW_GALE_STALKER            = 75655,

    // Shadow Gale Stalker
    SPELL_SHADOW_GALE_TRIGGER_RUN_SPEED_TRIGGER = 75675,

    // Faceless Corruptor
    SPELL_TWILIGHT_CORRUPTION                   = 75520,
    SPELL_UMBRAL_MENDING                        = 75763,
    SPELL_SIPHON_ESSENCE                        = 75755,

    // Alexstrasza's Egg
    SPELL_SUMMON_TWILIGHT_EGG                   = 91056,
    SPELL_SUMMON_TWILIGHT_HATCHLING             = 91058
};

enum Texts
{
    SAY_AGGRO                           = 0,
    SAY_ANNOUNCE_SHADOW_GALE            = 1,
    SAY_SHADOW_GALE                     = 2,
    SAY_FACELESS_CORRUPTORS             = 3,
    SAY_ANNOUNCE_GUARDIANS              = 4,
    SAY_ANNOUNCE_SHIELD_OF_NIGHTMARES   = 5,
    SAY_SLAY                            = 6,
    SAY_DEATH                           = 7
};

enum Events
{
    // Erudax
    EVENT_BINDING_SHADOWS = 1,
    EVENT_ENFEEBLING_BLOW,
    EVENT_SUMMON_SHADOW_GALE_STALKER,
    EVENT_SHADOW_GALE,
    EVENT_SUMMON_FACELESS_CORRUPTOR,
    EVENT_SHIELD_OF_NIGHTMARES,

    // Faceless Corruptor
    EVENT_SEND_ENCOUNTER_FRAME,
    EVENT_TWILIGHT_CORRUPTION,
    EVENT_UMBRAL_MENDING,
    EVENT_ATTACK_PLAYER,
    EVENT_SIPHON_ESSENCE
};

enum Actions
{
    ACTION_FINISH_CORRUPTION    = 1,
    ACTION_FAIL_ACHIEVEMENT     = 1
};

enum Data
{
    DATA_ACHIEVEMT_ENLIGIBLE = 1
};

Position const facelessCorruptorPositions1[] =
{
    { -656.2604f, -833.0052f, 234.1771f },
    { -701.7274f, -833.2674f, 232.4126f },
    { -729.4792f, -865.7899f, 232.5132f },
};

Position const facelessCorruptorPositions2[] =
{
    { -660.3993f, -824.5052f, 233.6518f },
    { -699.3420f, -818.5434f, 232.4729f },
    { -728.7292f, -791.1129f, 232.4201f }
};

enum Points
{
    POINT_PATH_1,
    POINT_PATH_2,
    POINT_PATH_3
};

enum ModelIds
{
    MODEL_ID_INVISIBLE = 11686
};

class boss_erudax : public CreatureScript
{
    public:
        boss_erudax() : CreatureScript("boss_erudax") { }

        struct boss_erudaxAI : public BossAI
        {
            boss_erudaxAI(Creature* creature) : BossAI(creature, DATA_ERUDAX)
            {
                Initialize();
            }

            void Initialize()
            {
                _achievementEnligible = true;
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_BINDING_SHADOWS, Seconds(10) + Milliseconds(500));
                events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, Seconds(19));
                events.ScheduleEvent(EVENT_SUMMON_SHADOW_GALE_STALKER, Seconds(21) + Milliseconds(500));
            }

            void Reset()
            {
                _Reset();
                Initialize();
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
                DespawnFacelessCorruptors();
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                DespawnFacelessCorruptors();
                summons.DespawnAll();
            }

            void DespawnFacelessCorruptors()
            {
                for (auto itr = _corruptorGUIDList.begin(); itr != _corruptorGUIDList.end(); itr++)
                {
                    if (Creature* corruptor = ObjectAccessor::GetCreature(*me, *itr))
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, corruptor);
                        corruptor->DespawnOrUnsummon(Milliseconds(100));
                    }
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_FAIL_ACHIEVEMENT)
                    _achievementEnligible = false;
            }

            void JustSummoned(Creature* summon) override
            {
                switch (summon->GetEntry())
                {
                    case NPC_SHADOW_GALE_STALKER:
                        Talk(SAY_SHADOW_GALE);
                        Talk(SAY_ANNOUNCE_SHADOW_GALE);
                        // needed because the summons visual effect of the following spell cast gets lost else
                        events.ScheduleEvent(EVENT_SHADOW_GALE, Milliseconds(1));
                        summons.Summon(summon);
                        break;
                    case NPC_FACELESS_CORRUPTOR_1:
                    case NPC_FACELESS_CORRUPTOR_2:
                        _corruptorGUIDList.insert(summon->GetGUID());
                        break;
                    default:
                        summons.Summon(summon);
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_ACHIEVEMT_ENLIGIBLE)
                    return _achievementEnligible;

                return 0;
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
                        case EVENT_BINDING_SHADOWS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, true, 0, 0))
                                DoCast(target, SPELL_BINDING_SHADOWS);
                            break;
                        case EVENT_ENFEEBLING_BLOW:
                            DoCastVictim(SPELL_ENFEEBLING_BLOW);
                            break;
                        case EVENT_SUMMON_SHADOW_GALE_STALKER:
                            DoCastSelf(SPELL_SHADOW_GALE_TRIGGER, true);
                            break;
                        case EVENT_SHADOW_GALE:
                            if (Creature* shadowGale = instance->GetCreature(DATA_SHADOW_GALE_STALKER))
                                shadowGale->CastSpell(shadowGale, SPELL_SHADOW_GALE_TRIGGER_RUN_SPEED_TRIGGER);
                            DoCastAOE(SPELL_SHADOW_GALE);
                            events.ScheduleEvent(EVENT_BINDING_SHADOWS, Seconds(21));
                            events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, Seconds(20));
                            events.ScheduleEvent(EVENT_SUMMON_FACELESS_CORRUPTOR, Seconds(18));
                            events.ScheduleEvent(EVENT_SUMMON_SHADOW_GALE_STALKER, Seconds(55));
                            break;
                        case EVENT_SUMMON_FACELESS_CORRUPTOR:
                            Talk(SAY_FACELESS_CORRUPTORS);
                            Talk(SAY_ANNOUNCE_GUARDIANS);
                            DoCastSelf(SPELL_SUMMON_FACELESS_CORRUPTOR, true);
                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_SHIELD_OF_NIGHTMARES, Seconds(19));
                            break;
                        case EVENT_SHIELD_OF_NIGHTMARES:
                            if (instance->GetCreature(DATA_FACELESS_CORRUPTOR_1) || instance->GetCreature(DATA_FACELESS_CORRUPTOR_2))
                            {
                                Talk(SAY_ANNOUNCE_SHIELD_OF_NIGHTMARES);
                                DoCastAOE(SPELL_SHIELD_OF_NIGHTMARES);
                            }
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            bool _achievementEnligible;
            GuidSet _corruptorGUIDList;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGrimBatolAI<boss_erudaxAI>(creature);
        }
};

class npc_erudax_faceless_corruptor : public CreatureScript
{
    public:
        npc_erudax_faceless_corruptor() : CreatureScript("npc_erudax_faceless_corruptor") { }

        struct npc_erudax_faceless_corruptorAI : public ScriptedAI
        {
            npc_erudax_faceless_corruptorAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()){ }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                me->SetReactState(REACT_PASSIVE);
                if (me->GetEntry() == NPC_FACELESS_CORRUPTOR_1)
                    me->GetMotionMaster()->MovePoint(POINT_PATH_1, facelessCorruptorPositions1[0], true);
                else
                    me->GetMotionMaster()->MovePoint(POINT_PATH_1, facelessCorruptorPositions2[0], true);
                _events.ScheduleEvent(EVENT_SEND_ENCOUNTER_FRAME, Seconds(7) + Milliseconds(500));
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->DespawnOrUnsummon(Milliseconds(100));
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_PATH_1:
                        if (me->GetEntry() == NPC_FACELESS_CORRUPTOR_1)
                            me->GetMotionMaster()->MovePoint(POINT_PATH_2, facelessCorruptorPositions1[1], true);
                        else
                            me->GetMotionMaster()->MovePoint(POINT_PATH_2, facelessCorruptorPositions2[1], true);
                        break;
                    case POINT_PATH_2:
                        if (me->GetEntry() == NPC_FACELESS_CORRUPTOR_1)
                            me->GetMotionMaster()->MovePoint(POINT_PATH_3, facelessCorruptorPositions1[2], true);
                        else
                            me->GetMotionMaster()->MovePoint(POINT_PATH_3, facelessCorruptorPositions2[2], true);
                        break;
                    case POINT_PATH_3:
                        _events.ScheduleEvent(EVENT_TWILIGHT_CORRUPTION, Seconds(1));
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_FINISH_CORRUPTION)
                    _events.ScheduleEvent(EVENT_UMBRAL_MENDING, Milliseconds(400));
            }

            void JustDied(Unit* /*killer*/) override
            {
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->DespawnOrUnsummon(Seconds(5));
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
                        case EVENT_SEND_ENCOUNTER_FRAME:
                            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                            break;
                        case EVENT_TWILIGHT_CORRUPTION:
                            if (Creature* erudax = _instance->GetCreature(DATA_ERUDAX))
                                erudax->AI()->DoAction(ACTION_FAIL_ACHIEVEMENT);
                            DoCastAOE(SPELL_TWILIGHT_CORRUPTION);
                            break;
                        case EVENT_UMBRAL_MENDING:
                            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, false);
                            DoCastAOE(SPELL_UMBRAL_MENDING);
                            _events.ScheduleEvent(EVENT_ATTACK_PLAYER, Seconds(3));
                            _events.ScheduleEvent(EVENT_SIPHON_ESSENCE, Seconds(55));
                            break;
                        case EVENT_ATTACK_PLAYER:
                            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Player* player = me->SelectNearestPlayer(100.0f))
                                me->AI()->AttackStart(player);
                            break;
                        case EVENT_SIPHON_ESSENCE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true, 0))
                                DoCast(target, SPELL_SIPHON_ESSENCE);
                            _events.Repeat(Seconds(11));
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
            return GetGrimBatolAI<npc_erudax_faceless_corruptorAI>(creature);
        }
};

class spell_erudax_shadow_gale_trigger : public SpellScriptLoader
{
    public:
        spell_erudax_shadow_gale_trigger() : SpellScriptLoader("spell_erudax_shadow_gale_trigger") { }

        class spell_erudax_shadow_gale_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_shadow_gale_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_SHADOW_GALE_STALKER });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_SHADOW_GALE_STALKER, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_erudax_shadow_gale_trigger_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_erudax_shadow_gale_trigger_SpellScript();
        }
};

class ShadowGaleDistanceCheck
{
    public:
        ShadowGaleDistanceCheck(Position pos) : _pos(pos) { }

        bool operator()(WorldObject* object)
        {
            return (object->GetDistance2d(_pos.GetPositionX(), _pos.GetPositionY()) <= 4.0f);
        }
    private:
        Position _pos;
};

class spell_erudax_shadow_gale : public SpellScriptLoader
{
    public:
        spell_erudax_shadow_gale() : SpellScriptLoader("spell_erudax_shadow_gale") { }

        class spell_erudax_shadow_gale_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_shadow_gale_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                if (Unit* caster = GetCaster())
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (Creature* shadowGale = instance->GetCreature(DATA_SHADOW_GALE_STALKER))
                            targets.remove_if(ShadowGaleDistanceCheck(shadowGale->GetPosition()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_erudax_shadow_gale_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_erudax_shadow_gale_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_erudax_shadow_gale_SpellScript();
        }
};

class spell_erudax_shadow_gale_aura : public SpellScriptLoader
{
    public:
        spell_erudax_shadow_gale_aura() : SpellScriptLoader("spell_erudax_shadow_gale_aura") { }

        class spell_erudax_shadow_gale_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_shadow_gale_aura_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(ShadowGaleDistanceCheck(GetCaster()->GetPosition()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_erudax_shadow_gale_aura_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_erudax_shadow_gale_aura_SpellScript();
        }
};

class spell_erudax_twilight_corruption: public SpellScriptLoader
{
    public:
        spell_erudax_twilight_corruption() : SpellScriptLoader("spell_erudax_twilight_corruption") { }

        class spell_erudax_twilight_corruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_twilight_corruption_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
                targets.resize(1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_erudax_twilight_corruption_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_erudax_twilight_corruption_SpellScript();
        }

        class spell_erudax_twilight_corruption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_erudax_twilight_corruption_AuraScript);

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* target = GetOwner()->ToUnit())
                {
                    if (uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, target))
                    {
                        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(spellId))
                        {
                            int32 damage = CalculatePct(target->GetMaxHealth(), spell->Effects[EFFECT_0].BasePoints);
                            target->CastCustomSpell(target, spellId, &damage, 0, 0, true);
                        }
                    }
                }
            }

            void OnAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                {
                    if (Unit* caster = GetCaster())
                        if (Creature* creature = caster->ToCreature())
                            if (creature->IsAIEnabled)
                                creature->AI()->DoAction(ACTION_FINISH_CORRUPTION);

                    if (Unit* owner = GetOwner()->ToUnit())
                    {
                        owner->CastSpell(owner, SPELL_SUMMON_TWILIGHT_EGG, true);
                        owner->CastSpell(owner, SPELL_SUMMON_TWILIGHT_HATCHLING, true);
                        owner->SetDisplayId(MODEL_ID_INVISIBLE);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_erudax_twilight_corruption_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                OnEffectRemove += AuraEffectRemoveFn(spell_erudax_twilight_corruption_AuraScript::OnAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_erudax_twilight_corruption_AuraScript();
        }
};

class achievement_dont_need_to_break_eggs : public AchievementCriteriaScript
{
    public:
        achievement_dont_need_to_break_eggs() : AchievementCriteriaScript("achievement_dont_need_to_break_eggs") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            if (target->GetMap()->IsHeroic())
                return target->GetAI()->GetData(DATA_ACHIEVEMT_ENLIGIBLE);

            return false;
        }
};

void AddSC_boss_erudax()
{
    new boss_erudax();
    new npc_erudax_faceless_corruptor();
    new spell_erudax_shadow_gale_trigger();
    new spell_erudax_shadow_gale();
    new spell_erudax_shadow_gale_aura();
    new spell_erudax_twilight_corruption();
    new achievement_dont_need_to_break_eggs();
}

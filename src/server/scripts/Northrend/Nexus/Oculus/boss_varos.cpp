/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "oculus.h"

enum Says
{
    SAY_AGGRO           = 0,
    SAY_AZURE           = 1,
    SAY_AZURE_EMOTE     = 2,
    SAY_DEATH           = 3
};

enum Spells
{
    SPELL_ENERGIZE_CORES_VISUAL                   = 62136,
    SPELL_ENERGIZE_CORES                          = 50785, //Damage 5938 to 6562, effec2 Triggers 54069, effect3 Triggers 56251
    SPELL_CALL_AZURE_RING_CAPTAIN                 = 51002, //Effect    Send Event (12229)
    /*SPELL_CALL_AZURE_RING_CAPTAIN_2               = 51006, //Effect    Send Event (10665)
    SPELL_CALL_AZURE_RING_CAPTAIN_3               = 51007, //Effect    Send Event (18454)
    SPELL_CALL_AZURE_RING_CAPTAIN_4               = 51008, //Effect    Send Event (18455)*/
    SPELL_CALL_AMPLIFY_MAGIC                      = 51054,

    SPELL_ICE_BEAM                                = 49549,
    SPELL_ARCANE_BEAM_PERIODIC                    = 51019,
    SPELL_SUMMON_ARCANE_BEAM                      = 51017
};

enum Events
{
    EVENT_ENERGIZE_CORES = 1,
    EVENT_CALL_AZURE,
    EVENT_AMPLIFY_MAGIC,
    EVENT_ENERGIZE_CORES_VISUAL
};

class boss_varos : public CreatureScript
{
    public:
        boss_varos() : CreatureScript("boss_varos") { }

        struct boss_varosAI : public BossAI
        {
            boss_varosAI(Creature* creature) : BossAI(creature, DATA_VAROS)
            {
                Initialize();
            }

            void Initialize()
            {
                firstCoreEnergize = false;
                coreEnergizeOrientation = 0.0f;
            }

            void InitializeAI() override
            {
                BossAI::InitializeAI();
                if (instance->GetBossState(DATA_DRAKOS) != DONE)
                    DoCast(me, SPELL_CENTRIFUGE_SHIELD);
            }

            void Reset() override
            {
                _Reset();

                events.ScheduleEvent(EVENT_AMPLIFY_MAGIC, urand(20, 25) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_ENERGIZE_CORES_VISUAL, 5000);
                // not sure if this is handled by a timer or hp percentage
                events.ScheduleEvent(EVENT_CALL_AZURE, urand(15, 30) * IN_MILLISECONDS);

                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();

                Talk(SAY_AGGRO);
            }

            float GetCoreEnergizeOrientation()
            {
                return coreEnergizeOrientation;
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
                        case EVENT_ENERGIZE_CORES:
                            DoCast(me, SPELL_ENERGIZE_CORES);
                            events.CancelEvent(EVENT_ENERGIZE_CORES);
                            break;
                        case EVENT_ENERGIZE_CORES_VISUAL:
                            if (!firstCoreEnergize)
                            {
                                coreEnergizeOrientation = me->GetOrientation();
                                firstCoreEnergize = true;
                            }
                            else
                                coreEnergizeOrientation = Position::NormalizeOrientation(coreEnergizeOrientation - 2.0f);

                            DoCast(me, SPELL_ENERGIZE_CORES_VISUAL);
                            events.ScheduleEvent(EVENT_ENERGIZE_CORES_VISUAL, 5000);
                            events.ScheduleEvent(EVENT_ENERGIZE_CORES, 4000);
                            break;
                        case EVENT_CALL_AZURE:
                            // not sure how blizz handles this, i cant see any pattern between the differnt spells
                            DoCast(me, SPELL_CALL_AZURE_RING_CAPTAIN);
                            Talk(SAY_AZURE);
                            Talk(SAY_AZURE_EMOTE);
                            events.ScheduleEvent(EVENT_CALL_AZURE, urand(20, 25) * IN_MILLISECONDS);
                            break;
                        case EVENT_AMPLIFY_MAGIC:
                            DoCastVictim(SPELL_CALL_AMPLIFY_MAGIC);
                            events.ScheduleEvent(EVENT_AMPLIFY_MAGIC, urand(17, 20) * IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                DoCast(me, SPELL_DEATH_SPELL, true); // we cast the spell as triggered or the summon effect does not occur
            }

        private:
            bool firstCoreEnergize;
            float coreEnergizeOrientation;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetOculusAI<boss_varosAI>(creature);
        }
};

class npc_azure_ring_captain : public CreatureScript
{
    public:
        npc_azure_ring_captain() : CreatureScript("npc_azure_ring_captain") { }

        struct npc_azure_ring_captainAI : public ScriptedAI
        {
            npc_azure_ring_captainAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                targetGUID.Clear();
            }

            void Reset() override
            {
                Initialize();

                me->SetWalk(true);
                //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_ICE_BEAM)
                {
                    target->CastSpell(target, SPELL_SUMMON_ARCANE_BEAM, true);
                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE ||
                    id != ACTION_CALL_DRAGON_EVENT)
                    return;

                me->GetMotionMaster()->MoveIdle();

                if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                    DoCast(target, SPELL_ICE_BEAM);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                   case ACTION_CALL_DRAGON_EVENT:
                        if (Creature* varos = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VAROS)))
                        {
                            if (Unit* victim = varos->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                me->SetReactState(REACT_PASSIVE);
                                me->SetWalk(false);
                                me->GetMotionMaster()->MovePoint(ACTION_CALL_DRAGON_EVENT, victim->GetPositionX(), victim->GetPositionY(), victim->GetPositionZ() + 20.0f);
                                targetGUID = victim->GetGUID();
                            }
                        }
                        break;
                }
           }

        private:
            ObjectGuid targetGUID;
            InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_azure_ring_captainAI>(creature);
        }
};

class spell_varos_centrifuge_shield : public SpellScriptLoader
{
    public:
        spell_varos_centrifuge_shield() : SpellScriptLoader("spell_varos_centrifuge_shield") { }

        class spell_varos_centrifuge_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_varos_centrifuge_shield_AuraScript);

            bool Load() override
            {
                Unit* caster = GetCaster();
                return (caster && caster->ToCreature());
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // flags taken from sniffs
                    if (caster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_15|UNIT_FLAG_IMMUNE_TO_NPC|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_6))
                    {
                        caster->ToCreature()->SetReactState(REACT_PASSIVE);
                        caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_15|UNIT_FLAG_IMMUNE_TO_NPC|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_6);
                    }
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    caster->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                    caster->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_15|UNIT_FLAG_IMMUNE_TO_NPC|UNIT_FLAG_IMMUNE_TO_PC|UNIT_FLAG_UNK_6);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_varos_centrifuge_shield_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectApply += AuraEffectApplyFn(spell_varos_centrifuge_shield_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_varos_centrifuge_shield_AuraScript();
        }
};

class spell_varos_energize_core_area_enemy : public SpellScriptLoader
{
    public:
        spell_varos_energize_core_area_enemy() : SpellScriptLoader("spell_varos_energize_core_area_enemy") { }

        class spell_varos_energize_core_area_enemySpellScript : public SpellScript
        {
            PrepareSpellScript(spell_varos_energize_core_area_enemySpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Creature* varos = GetCaster()->ToCreature();
                if (!varos)
                    return;

                if (varos->GetEntry() != NPC_VAROS)
                    return;

                float orientation = ENSURE_AI(boss_varos::boss_varosAI, varos->AI())->GetCoreEnergizeOrientation();

                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
                {
                    float angle = varos->GetAngle((*itr)->GetPositionX(), (*itr)->GetPositionY());
                    float diff = std::fabs(orientation - angle);

                    if (diff > 1.0f)
                        itr = targets.erase(itr);
                    else
                        ++itr;
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_varos_energize_core_area_enemySpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_varos_energize_core_area_enemySpellScript();
        }
};

class spell_varos_energize_core_area_entry : public SpellScriptLoader
{
    public:
        spell_varos_energize_core_area_entry() : SpellScriptLoader("spell_varos_energize_core_area_entry") { }

        class spell_varos_energize_core_area_entrySpellScript : public SpellScript
        {
            PrepareSpellScript(spell_varos_energize_core_area_entrySpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Creature* varos = GetCaster()->ToCreature();
                if (!varos)
                    return;

                if (varos->GetEntry() != NPC_VAROS)
                    return;

                float orientation = ENSURE_AI(boss_varos::boss_varosAI, varos->AI())->GetCoreEnergizeOrientation();

                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
                {
                    float angle = varos->GetAngle((*itr)->GetPositionX(), (*itr)->GetPositionY());
                    float diff = std::fabs(orientation - angle);

                    if (diff > 1.0f)
                        itr = targets.erase(itr);
                    else
                        ++itr;
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_varos_energize_core_area_entrySpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_varos_energize_core_area_entrySpellScript();
        }
};

void AddSC_boss_varos()
{
    new boss_varos();
    new npc_azure_ring_captain();
    new spell_varos_centrifuge_shield();
    new spell_varos_energize_core_area_enemy();
    new spell_varos_energize_core_area_entry();
}

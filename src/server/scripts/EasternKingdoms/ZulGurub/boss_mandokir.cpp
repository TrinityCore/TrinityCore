/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "zulgurub.h"

enum Yells
{
    SAY_AGGRO                   = 0,
    SAY_PLAYER_KILL             = 1,
    SAY_DISMOUNT_OHGAN          = 2,
    EMOTE_DEVASTATING_SLAM      = 3,
    SAY_REANIMATE_OHGAN         = 4,
    EMOTE_FRENZY                = 5,
    SAY_FRENZY                  = 6,
    SAY_DEATH                   = 7
};

enum Spells
{
    // Bloodlord Mandokir
    SPELL_BLOODLORD_AURA            = 96480,
    SPELL_SUMMON_OHGAN              = 96717,
    SPELL_REANIMATE_OHGAN           = 96724,
    SPELL_DECAPITATE                = 96682,
    SPELL_BLOODLETTING              = 96776,
    SPELL_BLOODLETTING_DAMAGE       = 96777,
    SPELL_BLOODLETTING_HEAL         = 96778,
    SPELL_FRENZY                    = 96800,
    SPELL_LEVEL_UP                  = 96662,
    SPELL_DEVASTATING_SLAM          = 96740,
    SPELL_DEVASTATING_SLAM_TRIGGER  = 96761,
    SPELL_DEVASTATING_SLAM_DAMAGE   = 97385,
    SPELL_SPIRIT_VENGEANCE_CANCEL   = 96821,

    // Chained Spirit
    SPELL_REVIVE                    = 96484,

    // Ohgan
    SPELL_OHGAN_HEART_VISUAL        = 96727,
    SPELL_PERMANENT_FEIGN_DEATH     = 96733,
    SPELL_CLEAR_ALL                 = 28471,
    SPELL_OHGAN_ORDERS              = 96721,
    SPELL_OHGAN_ORDERS_TRIGGER      = 96722
};

enum Events
{
    // Bloodlord Mandokir
    EVENT_SUMMON_OHGAN              = 1,
    EVENT_DECAPITATE                = 2,
    EVENT_BLOODLETTING              = 3,
    EVENT_REANIMATE_OHGAN           = 4,
    EVENT_REANIMATE_OHGAN_COOLDOWN  = 5,
    EVENT_DEVASTATING_SLAM          = 6
};

enum Action
{
    // Bloodlord Mandokir
    ACTION_OHGAN_IS_DEATH       = 1,
    ACTION_START_REVIVE         = 2,

    // Chained Spirit
    ACTION_REVIVE               = 1
};

enum Misc
{
    POINT_START_REVIVE          = 1,

    DATA_OHGANOT_SO_FAST        = 5762,

    FACTION_NONE                = 1665
};

enum SummonGroups
{
    SUMMON_GROUP_CHAINED_SPIRIT = 0
};

class boss_mandokir : public CreatureScript
{
    public:

        boss_mandokir() : CreatureScript("boss_mandokir") { }

        struct boss_mandokirAI : public BossAI
        {
            boss_mandokirAI(Creature* creature) : BossAI(creature, DATA_MANDOKIR)
            {
                Initialize();
            }

            void Initialize()
            {
                _ohganotSoFast = true;
                _reanimateOhganCooldown = false;
            }

            void Reset() override
            {
                DoCastAOE(SPELL_SPIRIT_VENGEANCE_CANCEL);

                _Reset();

                me->SummonCreatureGroup(SUMMON_GROUP_CHAINED_SPIRIT);
                Initialize();
                _reviveGUID.Clear();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);

                DoCastAOE(SPELL_BLOODLORD_AURA);

                if (!summons.empty())
                {
                    for (SummonList::const_iterator itr = summons.begin(); itr != summons.end(); ++itr)
                    {
                        if (Creature* chainedSpirit = ObjectAccessor::GetCreature(*me, *itr))
                            if (chainedSpirit->GetEntry() == NPC_CHAINED_SPIRIT && chainedSpirit->AI())
                                chainedSpirit->setFaction(FACTION_NONE);
                    }
                }

                events.ScheduleEvent(EVENT_DECAPITATE, 10000);
                events.ScheduleEvent(EVENT_BLOODLETTING, 15000);
                events.ScheduleEvent(EVENT_SUMMON_OHGAN, 20000);
                events.ScheduleEvent(EVENT_DEVASTATING_SLAM, 25000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCastAOE(SPELL_SPIRIT_VENGEANCE_CANCEL);
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_PLAYER_KILL);
                    DoCast(SPELL_LEVEL_UP);
                    _reviveGUID = victim->GetGUID();
                    DoAction(ACTION_START_REVIVE);
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(20, damage) && !me->HasAura(SPELL_FRENZY))
                {
                    DoCast(me, SPELL_FRENZY, true);
                    Talk(SAY_FRENZY);
                    Talk(EMOTE_FRENZY);
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_OHGAN_IS_DEATH:
                        events.ScheduleEvent(EVENT_REANIMATE_OHGAN, 4000);
                        _ohganotSoFast = false;
                        break;
                    case ACTION_START_REVIVE:
                    {
                        std::list<Creature*> creatures;
                        GetCreatureListWithEntryInGrid(creatures, me, NPC_CHAINED_SPIRIT, 200.0f);
                        creatures.remove_if(Trinity::AnyDeadUnitCheck());
                        creatures.remove_if(Trinity::UnitAuraCheck(true, SPELL_OHGAN_ORDERS_TRIGGER));
                        Trinity::Containers::RandomResize(creatures, 1);
                        if (creatures.empty())
                            return;

                        for (std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                        {
                            if (Creature* chainedSpirit = ObjectAccessor::GetCreature(*me, (*itr)->GetGUID()))
                            {
                                chainedSpirit->AI()->SetGUID(_reviveGUID);
                                chainedSpirit->AI()->DoAction(ACTION_REVIVE);
                                _reviveGUID.Clear();
                            }
                        }
                        break;
                    }
                    default:
                        break;

                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_OHGANOT_SO_FAST)
                    return _ohganotSoFast;

                return 0;
            }

            void SetGUID(ObjectGuid guid, int32 /*type = 0 */) override
            {
                _reviveGUID = guid;
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
                        case EVENT_SUMMON_OHGAN:
                            me->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
                            DoCast(me, SPELL_SUMMON_OHGAN, true);
                            break;
                        case EVENT_DECAPITATE:
                            DoCastAOE(SPELL_DECAPITATE);
                            events.ScheduleEvent(EVENT_DECAPITATE, me->HasAura(SPELL_FRENZY) ? 17500 : 35000);
                            break;
                        case EVENT_BLOODLETTING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                DoCast(target, SPELL_BLOODLETTING, true);
                                me->ClearUnitState(UNIT_STATE_CASTING);
                            }
                            events.ScheduleEvent(EVENT_BLOODLETTING, 25000);
                            break;
                        case EVENT_REANIMATE_OHGAN:
                            if (_reanimateOhganCooldown)
                                events.ScheduleEvent(EVENT_REANIMATE_OHGAN, 1000);
                            else
                            {
                                DoCastAOE(SPELL_REANIMATE_OHGAN);
                                Talk(SAY_REANIMATE_OHGAN);
                                // Cooldown
                                _reanimateOhganCooldown = true;
                                events.ScheduleEvent(EVENT_REANIMATE_OHGAN_COOLDOWN, 20000);
                            }
                            break;
                        case EVENT_REANIMATE_OHGAN_COOLDOWN:
                            _reanimateOhganCooldown = false;
                            break;
                        case EVENT_DEVASTATING_SLAM:
                            DoCastAOE(SPELL_DEVASTATING_SLAM_TRIGGER);
                            events.ScheduleEvent(EVENT_DEVASTATING_SLAM, 30000);
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
            bool _ohganotSoFast;
            bool _reanimateOhganCooldown;
            ObjectGuid _reviveGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_mandokirAI>(creature);
        }
};

class npc_ohgan : public CreatureScript
{
    public:
        npc_ohgan() : CreatureScript("npc_ohgan") { }

        struct npc_ohganAI : public ScriptedAI
        {
            npc_ohganAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = me->GetInstanceScript();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoCastAOE(SPELL_OHGAN_ORDERS, true);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                 {
                    damage = 0;
                    me->AttackStop();
                    me->SetHealth(0);
                    me->SetTarget(ObjectGuid::Empty);
                    DoCast(me, SPELL_CLEAR_ALL, true);
                    DoCast(me, SPELL_PERMANENT_FEIGN_DEATH);

                    if (Creature* mandokir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MANDOKIR)))
                        mandokir->AI()->DoAction(ACTION_OHGAN_IS_DEATH);
                }
            }

            void KilledUnit(Unit* victim) override
            {
                if (Creature* creature = victim->ToCreature())
                {
                    if (creature->GetEntry() == NPC_CHAINED_SPIRIT)
                        DoCastAOE(SPELL_OHGAN_ORDERS, true);
                }
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<npc_ohganAI>(creature);
        }
};

class npc_chained_spirit : public CreatureScript
{
    public:
        npc_chained_spirit() : CreatureScript("npc_chained_spirit") { }

        struct npc_chained_spiritAI : public ScriptedAI
        {
            npc_chained_spiritAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = me->GetInstanceScript();
                me->AddUnitMovementFlag(MOVEMENTFLAG_HOVER);
                me->SetReactState(REACT_PASSIVE); // correct?
            }

            void Reset() override
            {
                _revivePlayerGUID.Clear();
            }

            void SetGUID(ObjectGuid guid, int32 /*type = 0 */) override
            {
                _revivePlayerGUID = guid;
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_REVIVE)
                {
                    Position pos;
                    if (Player* target = ObjectAccessor::GetPlayer(*me, _revivePlayerGUID))
                    {
                        target->GetNearPoint(me, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0.0f, 5.0f, target->GetAngle(me));
                        me->GetMotionMaster()->MovePoint(POINT_START_REVIVE, pos);
                    }
                }
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE || !_revivePlayerGUID)
                    return;

                if (pointId == POINT_START_REVIVE)
                {
                    if (Player* target = ObjectAccessor::GetPlayer(*me, _revivePlayerGUID))
                        DoCast(target, SPELL_REVIVE);

                    me->DespawnOrUnsummon(2000);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                Player* target = ObjectAccessor::GetPlayer(*me, _revivePlayerGUID);
                if (!target || target->IsAlive())
                    return;

                if (Creature* mandokir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_MANDOKIR)))
                {
                    mandokir->GetAI()->SetGUID(target->GetGUID());
                    mandokir->GetAI()->DoAction(ACTION_START_REVIVE);
                }

                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 /*diff*/) override { }

        private:
            InstanceScript* _instance;
            ObjectGuid _revivePlayerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<npc_chained_spiritAI>(creature);
        }
};

class spell_mandokir_decapitate : public SpellScriptLoader
{
    public:
        spell_mandokir_decapitate() : SpellScriptLoader("spell_mandokir_decapitate") { }

        class spell_mandokir_decapitate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mandokir_decapitate_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Player* target = GetHitPlayer())
                    caster->CastSpell(target, uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mandokir_decapitate_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mandokir_decapitate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mandokir_decapitate_SpellScript();
        }
};

class spell_mandokir_bloodletting : public SpellScriptLoader
{
    public:
        spell_mandokir_bloodletting() : SpellScriptLoader("spell_mandokir_bloodletting") { }

        class spell_mandokir_bloodletting_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mandokir_bloodletting_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_BLOODLETTING_DAMAGE, SPELL_BLOODLETTING_HEAL });
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                Unit* target = GetTarget();
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                int32 damage = std::max<int32>(7500, target->CountPctFromCurHealth(aurEff->GetAmount()));

                caster->CastCustomSpell(target, SPELL_BLOODLETTING_DAMAGE, &damage, 0, 0, true);
                target->CastCustomSpell(caster, SPELL_BLOODLETTING_HEAL, &damage, 0, 0, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mandokir_bloodletting_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mandokir_bloodletting_AuraScript();
        }
};

class spell_mandokir_spirit_vengeance_cancel : public SpellScriptLoader
{
    public:
        spell_mandokir_spirit_vengeance_cancel() : SpellScriptLoader("spell_mandokir_spirit_vengeance_cancel") { }

        class spell_mandokir_spirit_vengeance_cancel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mandokir_spirit_vengeance_cancel_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Player* target = GetHitPlayer())
                    target->RemoveAura(uint32(GetEffectValue()));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mandokir_spirit_vengeance_cancel_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_mandokir_spirit_vengeance_cancel_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mandokir_spirit_vengeance_cancel_SpellScript();
        }
};

class DevastatingSlamTargetSelector : public std::unary_function<Unit *, bool>
{
    public:
        DevastatingSlamTargetSelector(Creature* me, const Unit* victim) : _me(me), _victim(victim) {}

        bool operator() (WorldObject* target)
        {
            if (target == _victim && _me->getThreatManager().getThreatList().size() > 1)
                return true;

            if (target->GetTypeId() != TYPEID_PLAYER)
                return true;

            return false;
        }

        Creature* _me;
        Unit const* _victim;
};

class spell_mandokir_devastating_slam : public SpellScriptLoader
{
    public:
        spell_mandokir_devastating_slam() : SpellScriptLoader("spell_mandokir_devastating_slam") { }

        class spell_mandokir_devastating_slam_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mandokir_devastating_slam_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(DevastatingSlamTargetSelector(GetCaster()->ToCreature(), GetCaster()->GetVictim()));
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                float angle = 0.0f;
                float x, y, z;

                if (Player* target = GetHitPlayer())
                {
                    caster->AttackStop();
                    caster->SetOrientation(caster->GetAngle(target));
                    caster->SetFacingTo(caster->GetAngle(target));

                    caster->CastSpell(caster, SPELL_DEVASTATING_SLAM, false);

                    // HACK: Need better way for pos calculation
                    for (uint8 i = 0; i <= 50; ++i)
                    {
                        angle = float(rand_norm()) * static_cast<float>(M_PI * 35.0f / 180.0f) - static_cast<float>(M_PI * 17.5f / 180.0f);
                        caster->GetClosePoint(x, y, z, 4.0f, frand(-2.5f, 50.0f), angle);

                        caster->CastSpell(x, y, z, SPELL_DEVASTATING_SLAM_DAMAGE, true);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mandokir_devastating_slam_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mandokir_devastating_slam_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mandokir_devastating_slam_SpellScript();
        }
};

class spell_mandokir_ohgan_orders : public SpellScriptLoader
{
    public:
        spell_mandokir_ohgan_orders() : SpellScriptLoader("spell_mandokir_ohgan_orders") { }

        class spell_mandokir_ohgan_orders_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mandokir_ohgan_orders_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                    caster->CastSpell(target, uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mandokir_ohgan_orders_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_mandokir_ohgan_orders_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mandokir_ohgan_orders_SpellScript();
        }
};

class spell_mandokir_ohgan_orders_trigger : public SpellScriptLoader
{
    public:
        spell_mandokir_ohgan_orders_trigger() : SpellScriptLoader("spell_mandokir_ohgan_orders_trigger") { }

        class spell_mandokir_ohgan_orders_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mandokir_ohgan_orders_trigger_AuraScript);

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (Unit* caster = GetCaster())
                {
                    // HACK: research better way
                    caster->ClearUnitState(UNIT_STATE_CASTING);
                    caster->GetMotionMaster()->Clear();
                    caster->DeleteThreatList();
                    caster->AddThreat(target, 50000000.0f);
                    caster->TauntApply(target);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_mandokir_ohgan_orders_trigger_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mandokir_ohgan_orders_trigger_AuraScript();
        }
};

class spell_mandokir_reanimate_ohgan : public SpellScriptLoader
{
    public:
        spell_mandokir_reanimate_ohgan() : SpellScriptLoader("spell_mandokir_reanimate_ohgan") { }

        class spell_mandokir_reanimate_ohgan_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mandokir_reanimate_ohgan_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    target->RemoveAura(SPELL_PERMANENT_FEIGN_DEATH);
                    target->CastSpell(target, SPELL_OHGAN_HEART_VISUAL, true);
                    target->CastSpell((Unit*)NULL, SPELL_OHGAN_ORDERS, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_mandokir_reanimate_ohgan_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mandokir_reanimate_ohgan_SpellScript();
        }
};

class spell_clear_all : public SpellScriptLoader
{
    public:
        spell_clear_all() : SpellScriptLoader("spell_clear_all") { }

        class spell_clear_all_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_clear_all_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->RemoveAllAurasOnDeath();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_clear_all_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_clear_all_SpellScript();
        }
};

class achievement_ohganot_so_fast : public AchievementCriteriaScript
{
   public:
       achievement_ohganot_so_fast() : AchievementCriteriaScript("achievement_ohganot_so_fast") { }

       bool OnCheck(Player* /*player*/, Unit* target) override
       {
           return target && target->GetAI()->GetData(DATA_OHGANOT_SO_FAST);
       }
};

void AddSC_boss_mandokir()
{
    new boss_mandokir();
    new npc_ohgan();
    new npc_chained_spirit();
    new spell_mandokir_decapitate();
    new spell_mandokir_bloodletting();
    new spell_mandokir_spirit_vengeance_cancel();
    new spell_mandokir_devastating_slam();
    new spell_mandokir_ohgan_orders();
    new spell_mandokir_ohgan_orders_trigger();
    new spell_mandokir_reanimate_ohgan();
    new spell_clear_all();
    new achievement_ohganot_so_fast();
}

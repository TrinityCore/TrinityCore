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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Yells
{
    EMOTE_AIR_PHASE         = 0,
    EMOTE_GROUND_PHASE      = 1,
    EMOTE_BREATH            = 2,
    EMOTE_ENRAGE            = 3
};

enum Spells
{
    SPELL_FROST_AURA                = 28531,
    SPELL_CLEAVE                    = 19983,
    SPELL_TAIL_SWEEP                = 55697,
    SPELL_SUMMON_BLIZZARD           = 28560,
    SPELL_LIFE_DRAIN                = 28542,
    SPELL_ICEBOLT                   = 28522,
    SPELL_FROST_BREATH_ANTICHEAT    = 29318, // damage effect ignoring LoS on the entrance platform to prevent cheese
    SPELL_FROST_BREATH              = 28524, // damage effect below sapphiron
    SPELL_FROST_MISSILE             = 30101, // visual only
    SPELL_BERSERK                   = 26662,
    SPELL_DIES                      = 29357,
    SPELL_CHECK_RESISTS             = 60539,
    SPELL_SAPPHIRON_WING_BUFFET     = 29328
};

enum Phases
{
    PHASE_BIRTH = 1,
    PHASE_GROUND,
    PHASE_FLIGHT
};

enum Events
{
    EVENT_BERSERK       = 1,
    EVENT_CLEAVE,
    EVENT_TAIL,
    EVENT_DRAIN,
    EVENT_BLIZZARD,
    EVENT_FLIGHT,
    EVENT_LIFTOFF,
    EVENT_ICEBOLT,
    EVENT_BREATH,
    EVENT_EXPLOSION,
    EVENT_LAND,
    EVENT_GROUND,
    EVENT_BIRTH,
    EVENT_CHECK_RESISTS
};

enum Actions
{
    ACTION_BIRTH = 1
};

enum Misc
{
    NPC_BLIZZARD            = 16474,
    NPC_WING_BUFFET         = 17025,
    GO_ICEBLOCK             = 181247,

    // The Hundred Club
    DATA_THE_HUNDRED_CLUB   = 21462147,
    MAX_FROST_RESISTANCE    = 100
};

typedef std::map<ObjectGuid, ObjectGuid> IceBlockMap;

class boss_sapphiron : public CreatureScript
{
    public:
        boss_sapphiron() : CreatureScript("boss_sapphiron") { }

        struct boss_sapphironAI : public BossAI
        {
            boss_sapphironAI(Creature* creature) :
                BossAI(creature, BOSS_SAPPHIRON)
            {
                Initialize();
            }

            void Initialize()
            {
                _delayedDrain = false;
                _canTheHundredClub = true;
            }

            void InitializeAI() override
            {
                if (instance->GetBossState(BOSS_SAPPHIRON) == DONE)
                    return;

                _canTheHundredClub = true;

                if (!instance->GetData(DATA_HAD_SAPPHIRON_BIRTH))
                {
                    me->SetVisible(false);
                    me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_PASSIVE);
                }

                BossAI::InitializeAI();
            }

            void Reset() override
            {
                if (events.IsInPhase(PHASE_FLIGHT))
                {
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ICEBOLT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (me->IsHovering())
                    {
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                        me->SetHover(false);
                    }
                }

                _Reset();
                Initialize();
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (damage < me->GetHealth() || !events.IsInPhase(PHASE_FLIGHT))
                    return;
                damage = me->GetHealth()-1; // don't die during air phase
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();

                me->CastSpell(me, SPELL_FROST_AURA, true);

                events.SetPhase(PHASE_GROUND);
                events.ScheduleEvent(EVENT_CHECK_RESISTS, Seconds(0));
                events.ScheduleEvent(EVENT_BERSERK, Minutes(15));
                EnterPhaseGround(true);
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                switch(spell->Id)
                {
                    case SPELL_CHECK_RESISTS:
                        if (target && target->GetResistance(SPELL_SCHOOL_MASK_FROST) > MAX_FROST_RESISTANCE)
                            _canTheHundredClub = false;
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                me->CastSpell(me, SPELL_DIES, true);
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id == 1)
                    events.ScheduleEvent(EVENT_LIFTOFF, Seconds(0), 0, PHASE_FLIGHT);
            }

            void DoAction(int32 param) override
            {
                if (param == ACTION_BIRTH)
                {
                    events.SetPhase(PHASE_BIRTH);
                    events.ScheduleEvent(EVENT_BIRTH, Seconds(23));
                }
            }

            void EnterPhaseGround(bool initial)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                events.ScheduleEvent(EVENT_CLEAVE, randtime(Seconds(5), Seconds(15)), 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_TAIL, randtime(Seconds(7), Seconds(10)), 0, PHASE_GROUND);
                events.ScheduleEvent(EVENT_BLIZZARD, randtime(Seconds(5), Seconds(10)), 0, PHASE_GROUND);
                if (initial)
                {
                    events.ScheduleEvent(EVENT_DRAIN, randtime(Seconds(22), Seconds(28)));
                    events.ScheduleEvent(EVENT_FLIGHT, Seconds(48) + Milliseconds(500), 0, PHASE_GROUND);
                }
                else
                    events.ScheduleEvent(EVENT_FLIGHT, Minutes(1), 0, PHASE_GROUND);
            }

            inline void CastDrain()
            {
                DoCastAOE(SPELL_LIFE_DRAIN);
                events.ScheduleEvent(EVENT_DRAIN, randtime(Seconds(22), Seconds(28)));
            }

            uint32 GetData(uint32 data) const override
            {
                if (data == DATA_THE_HUNDRED_CLUB)
                    return _canTheHundredClub;

                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                if (!events.IsInPhase(PHASE_BIRTH) && !UpdateVictim())
                    return;

                if (events.IsInPhase(PHASE_GROUND))
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CHECK_RESISTS:
                                DoCast(me, SPELL_CHECK_RESISTS);
                                events.Repeat(Seconds(30));
                                return;
                            case EVENT_GROUND:
                                EnterPhaseGround(false);
                                return;
                            case EVENT_BERSERK:
                                Talk(EMOTE_ENRAGE);
                                DoCast(me, SPELL_BERSERK);
                                return;
                            case EVENT_CLEAVE:
                                DoCastVictim(SPELL_CLEAVE);
                                events.ScheduleEvent(EVENT_CLEAVE, randtime(Seconds(5), Seconds(15)), 0, PHASE_GROUND);
                                return;
                            case EVENT_TAIL:
                                DoCastAOE(SPELL_TAIL_SWEEP);
                                events.ScheduleEvent(EVENT_TAIL, randtime(Seconds(7), Seconds(10)), 0, PHASE_GROUND);
                                return;
                            case EVENT_DRAIN:
                                if (events.IsInPhase(PHASE_FLIGHT))
                                    _delayedDrain = true;
                                else
                                    CastDrain();
                                return;
                            case EVENT_BLIZZARD:
                                DoCastAOE(SPELL_SUMMON_BLIZZARD);
                                events.ScheduleEvent(EVENT_BLIZZARD, RAID_MODE(Seconds(20), Seconds(7)), 0, PHASE_GROUND);
                                break;
                            case EVENT_FLIGHT:
                                if (HealthAbovePct(10))
                                {
                                    _delayedDrain = false;
                                    events.SetPhase(PHASE_FLIGHT);
                                    me->SetReactState(REACT_PASSIVE);
                                    me->AttackStop();
                                    float x, y, z, o;
                                    me->GetHomePosition(x, y, z, o);
                                    me->GetMotionMaster()->MovePoint(1, x, y, z);
                                    return;
                                }
                                break;
                        }
                    }

                    DoMeleeAttackIfReady();
                }
                else
                {
                    if (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CHECK_RESISTS:
                                DoCast(me, SPELL_CHECK_RESISTS);
                                events.Repeat(Seconds(30));
                                return;
                            case EVENT_LIFTOFF:
                            {
                                Talk(EMOTE_AIR_PHASE);
                                if (Creature* buffet = DoSummon(NPC_WING_BUFFET, me, 0.0f, 0, TEMPSUMMON_MANUAL_DESPAWN))
                                    _buffet = buffet->GetGUID();
                                me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                                me->SetHover(true);
                                events.ScheduleEvent(EVENT_ICEBOLT, Seconds(7), 0, PHASE_FLIGHT);

                                _iceboltTargets.clear();
                                std::list<Unit*> targets;
                                SelectTargetList(targets, RAID_MODE(2, 3), SELECT_TARGET_RANDOM, 0, 200.0f, true);
                                for (Unit* target : targets)
                                    _iceboltTargets.push_back(target->GetGUID());
                                return;
                            }
                            case EVENT_ICEBOLT:
                            {
                                if (_iceboltTargets.empty())
                                {
                                    events.ScheduleEvent(EVENT_BREATH, Seconds(2), 0, PHASE_FLIGHT);
                                    return;
                                }
                                ObjectGuid target = _iceboltTargets.back();
                                if (Player* pTarget = ObjectAccessor::GetPlayer(*me, target))
                                    if (pTarget->IsAlive())
                                        DoCast(pTarget, SPELL_ICEBOLT);
                                _iceboltTargets.pop_back();

                                if (_iceboltTargets.empty())
                                    events.ScheduleEvent(EVENT_BREATH, Seconds(2), 0, PHASE_FLIGHT);
                                else
                                    events.Repeat(Seconds(3));
                                return;
                            }
                            case EVENT_BREATH:
                            {
                                Talk(EMOTE_BREATH);
                                DoCastAOE(SPELL_FROST_MISSILE);
                                events.ScheduleEvent(EVENT_EXPLOSION, Seconds(8), 0, PHASE_FLIGHT);
                                return;
                            }
                            case EVENT_EXPLOSION:
                                DoCastAOE(SPELL_FROST_BREATH);
                                DoCastAOE(SPELL_FROST_BREATH_ANTICHEAT);
                                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ICEBOLT);
                                events.ScheduleEvent(EVENT_LAND, Seconds(3) + Milliseconds(500), 0, PHASE_FLIGHT);
                                return;
                            case EVENT_LAND:
                                if (_delayedDrain)
                                    CastDrain();
                                if (Creature* cBuffet = ObjectAccessor::GetCreature(*me, _buffet))
                                {
                                    cBuffet->DespawnOrUnsummon(1 * IN_MILLISECONDS);
                                    _buffet.Clear();
                                }
                                me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                                Talk(EMOTE_GROUND_PHASE);
                                me->SetHover(false);
                                events.SetPhase(PHASE_GROUND);
                                events.ScheduleEvent(EVENT_GROUND, Seconds(3) + Milliseconds(500), 0, PHASE_GROUND);
                                return;
                            case EVENT_BIRTH:
                                me->SetVisible(true);
                                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                                me->SetReactState(REACT_AGGRESSIVE);
                                return;
                        }
                    }
                }
            }

        private:
            std::vector<ObjectGuid> _iceboltTargets;
            ObjectGuid _buffet;
            bool _delayedDrain;
            bool _canTheHundredClub;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNaxxramasAI<boss_sapphironAI>(creature);
        }
};

class go_sapphiron_birth : public GameObjectScript
{
    public:
        go_sapphiron_birth() : GameObjectScript("go_sapphiron_birth") { }

        struct go_sapphiron_birthAI : public GameObjectAI
        {
            go_sapphiron_birthAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            void OnLootStateChanged(uint32 state, Unit* who) override
            {
                if (state == GO_ACTIVATED)
                {
                    if (who)
                    {
                        if (Creature* sapphiron = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SAPPHIRON)))
                            sapphiron->AI()->DoAction(ACTION_BIRTH);
                        instance->SetData(DATA_HAD_SAPPHIRON_BIRTH, 1u);
                    }
                }
                else if (state == GO_JUST_DEACTIVATED)
                { // prevent ourselves from going back to _READY and resetting the client anim
                    me->SetRespawnTime(0);
                    me->Delete();
                }
            }

            InstanceScript* instance;
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetNaxxramasAI<go_sapphiron_birthAI>(go);
        }
};

class spell_sapphiron_change_blizzard_target : public SpellScriptLoader
{
    public:
    spell_sapphiron_change_blizzard_target() : SpellScriptLoader("spell_sapphiron_change_blizzard_target") { }

    class spell_sapphiron_change_blizzard_target_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sapphiron_change_blizzard_target_AuraScript);

        void HandlePeriodic(AuraEffect const* /*eff*/)
        {
            TempSummon* me = GetTarget()->ToTempSummon();
            if (Creature* owner = me ? me->GetSummonerCreatureBase() : nullptr)
            {
                Unit* newTarget = owner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true);
                if (!newTarget)
                    newTarget = owner->getAttackerForHelper();
                if (newTarget)
                    me->GetMotionMaster()->MoveFollow(newTarget, 0.1f, 0.0f);
                else
                {
                    me->StopMoving();
                    me->GetMotionMaster()->Clear();
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sapphiron_change_blizzard_target_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sapphiron_change_blizzard_target_AuraScript();
    }
};

class spell_sapphiron_icebolt : public SpellScriptLoader
{
    public:
    spell_sapphiron_icebolt() : SpellScriptLoader("spell_sapphiron_icebolt") { }

    class spell_sapphiron_icebolt_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sapphiron_icebolt_AuraScript);

        void HandleApply(AuraEffect const* /*eff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->ApplySpellImmune(SPELL_ICEBOLT, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_FROST, true);
        }

        void HandleRemove(AuraEffect const* /*eff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!_block.IsEmpty())
                if (GameObject* oBlock = ObjectAccessor::GetGameObject(*GetTarget(), _block))
                    oBlock->Delete();
            GetTarget()->ApplySpellImmune(SPELL_ICEBOLT, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_FROST, false);
        }

        void HandlePeriodic(AuraEffect const* /*eff*/)
        {
            if (!_block.IsEmpty())
                return;
            if (GetTarget()->isMoving())
                return;
            float x, y, z;
            GetTarget()->GetPosition(x, y, z);
            if (GameObject* block = GetTarget()->SummonGameObject(GO_ICEBLOCK, x, y, z, 0.f, QuaternionData(), 25))
                _block = block->GetGUID();
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_sapphiron_icebolt_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_sapphiron_icebolt_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sapphiron_icebolt_AuraScript::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

        ObjectGuid _block;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sapphiron_icebolt_AuraScript();
    }
};

class spell_sapphiron_summon_blizzard : public SpellScriptLoader
{
    public:
        spell_sapphiron_summon_blizzard() : SpellScriptLoader("spell_sapphiron_summon_blizzard") { }

        class spell_sapphiron_summon_blizzard_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sapphiron_summon_blizzard_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_BLIZZARD });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    if (Creature* blizzard = GetCaster()->SummonCreature(NPC_BLIZZARD, *target, TEMPSUMMON_TIMED_DESPAWN, urandms(25, 30)))
                    {
                        blizzard->CastSpell(nullptr, blizzard->m_spells[0], TRIGGERED_NONE);
                        if (Creature* creatureCaster = GetCaster()->ToCreature())
                        {
                            if (Unit* newTarget = creatureCaster->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                blizzard->GetMotionMaster()->MoveFollow(newTarget, 0.1f, 0.0f);
                                return;
                            }
                        }
                        blizzard->GetMotionMaster()->MoveFollow(target, 0.1f, 0.0f);
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sapphiron_summon_blizzard_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sapphiron_summon_blizzard_SpellScript();
        }
};

class achievement_the_hundred_club : public AchievementCriteriaScript
{
    public:
        achievement_the_hundred_club() : AchievementCriteriaScript("achievement_the_hundred_club") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_THE_HUNDRED_CLUB);
        }
};

void AddSC_boss_sapphiron()
{
    new boss_sapphiron();
    new go_sapphiron_birth();
    new spell_sapphiron_change_blizzard_target();
    new spell_sapphiron_icebolt();
    new spell_sapphiron_summon_blizzard();
    new achievement_the_hundred_club();
}

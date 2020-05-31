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
#include "black_temple.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"

enum Says
{
    // Essence of Suffering
    SUFF_SAY_AGRO       = 0,
    SUFF_SAY_SLAY       = 1,
    SUFF_SAY_ENRAGE     = 2,
    SUFF_SAY_RECAP      = 3,
    //SUFF_SAY_AFTER    = 4,
    SUFF_EMOTE_ENRAGE   = 5,

    // Essence of Desire
    DESI_SAY_FREED      = 0,
    DESI_SAY_SLAY       = 1,
    DESI_SAY_SPEC       = 2,
    DESI_SAY_RECAP      = 3,
    //DESI_SAY_AFTER    = 4,

    // Essence of Anger
    ANGER_SAY_FREED     = 0,
    ANGER_SAY_FREED_2   = 1,
    ANGER_SAY_SEETHE    = 2,
    ANGER_EMOTE_SEETHE  = 3,
    //ANGER_SAY_SPEC    = 4,
    ANGER_SAY_SPITE     = 5,
    //ANGER_SAY_DEATH   = 6
};

enum Spells
{
    // Reliquary
    SPELL_SUMMON_ESSENCE_OF_SUFFERING   = 41488,
    SPELL_SUBMERGE_VISUAL               = 28819,
    SPELL_SUMMON_ESSENCE_OF_DESIRE      = 41493,
    SPELL_SUMMON_ESSENCE_OF_ANGER       = 41496,

    // Essence of Suffering
    SPELL_AURA_OF_SUFFERING             = 41292,
    SPELL_SOUL_DRAIN                    = 41303,
    SPELL_FRENZY                        = 41305,

    // Essence of Desire
    SPELL_AURA_OF_DESIRE                = 41350,
    SPELL_SPIRIT_SHOCK                  = 41426,
    SPELL_RUNE_SHIELD                   = 41431,
    SPELL_DEADEN                        = 41410,
    SPELL_AURA_OF_DESIRE_DAMAGE         = 41352,

    // Essence of Anger
    SPELL_AURA_OF_ANGER                 = 41337,
    SPELL_SOUL_SCREAM                   = 41545,
    SPELL_SPITE                         = 41376,
    SPELL_SPITE_DAMAGE                  = 41377,
    SPELL_SEETHE                        = 41364,

    // Enslaved Soul
    SPELL_ENSLAVED_SOUL_PASSIVE         = 41535,
    SPELL_SOUL_RELEASE                  = 41542,

    // World Trigger
    SUMMON_ENSLAVED_SOUL                = 41538
};

enum Misc
{
    RELIQUARY_DESPAWN_WAYPOINT = 0,
    ACTION_ESSENCE_OF_SUFFERING_DEAD,
    ACTION_ESSENCE_OF_DESIRE_DEAD,
    ACTION_KILL_SELF,
    ANGER_SOUND_ID_DEATH       = 11401
};

enum Phases
{
    PHASE_ESSENCE_OF_SUFFERING = 1,
    PHASE_ESSENCE_OF_DESIRE,
    PHASE_ESSENCE_OF_ANGER
};

enum Events
{
    EVENT_SUBMERGE = 1,
    EVENT_SUMMON_ESSENCE,
    EVENT_DESPAWN,
    EVENT_SOUL_DRAIN,
    EVENT_FRENZY,
    EVENT_SPIRIT_SHOCK,
    EVENT_RUNE_SHIELD,
    EVENT_DEADEN,
    EVENT_SOUL_SCREAM,
    EVENT_SPITE,
    EVENT_CHECK_TANKER,
    EVENT_START_CHECK_TANKER,
    EVENT_FREED_2
};

Position const DespawnPoint = { 497.4939f, 183.2081f, 94.53341f };

class EnslavedSoulEvent : public BasicEvent
{
    public: EnslavedSoulEvent(Creature* owner) : _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SUMMON_ENSLAVED_SOUL, true);
            return true;
        }

    private:
        Creature* _owner;
};

class boss_reliquary_of_souls : public CreatureScript
{
public:
    boss_reliquary_of_souls() : CreatureScript("boss_reliquary_of_souls") { }

    struct boss_reliquary_of_soulsAI : public BossAI
    {
        boss_reliquary_of_soulsAI(Creature* creature) : BossAI(creature, DATA_RELIQUARY_OF_SOULS), _inCombat(false)
        {
            creature->m_SightDistance = 70.0f;
        }

        void Reset() override
        {
            _Reset();
            me->SetReactState(REACT_PASSIVE);
            _inCombat = false;
            events.SetPhase(PHASE_ESSENCE_OF_SUFFERING);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!_inCombat && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && CanAIAttack(who))
            {
                _inCombat = true;
                DoZoneInCombat();
                me->SetStandState(UNIT_STAND_STATE_STAND);
                events.ScheduleEvent(EVENT_SUBMERGE, Seconds(10));
            }
        }

        uint32 GetSummonSpell()
        {
            if (events.IsInPhase(PHASE_ESSENCE_OF_SUFFERING))
                return SPELL_SUMMON_ESSENCE_OF_SUFFERING;
            else if (events.IsInPhase(PHASE_ESSENCE_OF_DESIRE))
                return SPELL_SUMMON_ESSENCE_OF_DESIRE;
            else if (events.IsInPhase(PHASE_ESSENCE_OF_ANGER))
                return SPELL_SUMMON_ESSENCE_OF_ANGER;
            else //Should never happen
                return 0;
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_ESSENCE_OF_SUFFERING_DEAD:
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_VISUAL);
                    events.SetPhase(PHASE_ESSENCE_OF_DESIRE);
                    HandleSpirits();
                    events.ScheduleEvent(EVENT_SUBMERGE, Seconds(40));
                    break;
                case ACTION_ESSENCE_OF_DESIRE_DEAD:
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_VISUAL);
                    events.SetPhase(PHASE_ESSENCE_OF_ANGER);
                    HandleSpirits();
                    events.ScheduleEvent(EVENT_SUBMERGE, Seconds(40));
                    break;
                case ACTION_KILL_SELF:
                    me->KillSelf();
                    break;
            }
        }

        void HandleSpirits()
        {
            std::vector<Creature*> _worldTriggerList;
            me->GetCreatureListWithEntryInGrid(_worldTriggerList, NPC_RELIQUARY_WORLD_TRIGGER, 70.0f);

            if (_worldTriggerList.empty())
                return;

            //Get random creatures
            Trinity::Containers::RandomShuffle(_worldTriggerList);
            _worldTriggerList.resize(21);

            for (uint8 i = 0; i < 21; i++)
            {
                Creature* wTrigger = _worldTriggerList[i];
                if (i < 3)
                    wTrigger->m_Events.AddEvent(new EnslavedSoulEvent(wTrigger), wTrigger->m_Events.CalculateTime(4000));
                else if (i < 6)
                    wTrigger->m_Events.AddEvent(new EnslavedSoulEvent(wTrigger), wTrigger->m_Events.CalculateTime(8000));
                else if (i < 9)
                    wTrigger->m_Events.AddEvent(new EnslavedSoulEvent(wTrigger), wTrigger->m_Events.CalculateTime(12000));
                else if (i < 12)
                    wTrigger->m_Events.AddEvent(new EnslavedSoulEvent(wTrigger), wTrigger->m_Events.CalculateTime(16000));
                else if (i < 15)
                    wTrigger->m_Events.AddEvent(new EnslavedSoulEvent(wTrigger), wTrigger->m_Events.CalculateTime(20000));
                else if (i < 18)
                    wTrigger->m_Events.AddEvent(new EnslavedSoulEvent(wTrigger), wTrigger->m_Events.CalculateTime(24000));
                else
                    wTrigger->m_Events.AddEvent(new EnslavedSoulEvent(wTrigger), wTrigger->m_Events.CalculateTime(28000));
            }
        }

        void KillAssyncEvents()
        {
            std::vector<Creature*> _worldTriggerList;
            me->GetCreatureListWithEntryInGrid(_worldTriggerList, NPC_RELIQUARY_WORLD_TRIGGER, 70.0f);

            if (_worldTriggerList.empty())
                return;

            for (Creature* trigger : _worldTriggerList)
                trigger->m_Events.KillAllEvents(true);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            events.Reset();
            summons.DespawnAll();
            KillAssyncEvents();
            _DespawnAtEvade();
        }

        void JustDied(Unit* /*killer*/) override
        {
            events.Reset();
            instance->SetBossState(DATA_RELIQUARY_OF_SOULS, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SUBMERGE:
                        DoCastSelf(SPELL_SUBMERGE_VISUAL, true);
                        events.ScheduleEvent(EVENT_SUMMON_ESSENCE, Seconds(3));
                        break;
                    case EVENT_SUMMON_ESSENCE:
                    {
                        EntryCheckPredicate pred(NPC_ENSLAVED_SOUL);
                        summons.DoAction(ACTION_KILL_SELF, pred);
                        DoCastSelf(GetSummonSpell());
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
        bool _inCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_reliquary_of_soulsAI>(creature);
    }
};

class boss_essence_of_suffering : public CreatureScript
{
public:
    boss_essence_of_suffering() : CreatureScript("boss_essence_of_suffering") { }

    struct boss_essence_of_sufferingAI : public BossAI
    {
        boss_essence_of_sufferingAI(Creature* creature) : BossAI(creature, DATA_ESSENCE_OF_SUFFERING), _dead(false)
        {
            SetBoundary(instance->GetBossBoundary(DATA_RELIQUARY_OF_SOULS));
        }

        void Reset() override
        {
            DoCastAOE(SPELL_AURA_OF_SUFFERING, true);
            events.Reset();
            _dead = false;
        }

        void MovementInform(uint32 motionType, uint32 pointId) override
        {
            if (motionType != POINT_MOTION_TYPE)
                return;

            if (pointId == RELIQUARY_DESPAWN_WAYPOINT)
            {
                if (Creature* reliquary = instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
                    reliquary->AI()->DoAction(ACTION_ESSENCE_OF_SUFFERING_DEAD);

                DoCastSelf(SPELL_SUBMERGE_VISUAL, true);
                me->DespawnOrUnsummon(Seconds(2));
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!_dead)
                {
                    _dead = true;
                    Talk(SUFF_SAY_RECAP);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    events.Reset();
                    me->InterruptNonMeleeSpells(false);
                    me->GetMotionMaster()->MovePoint(RELIQUARY_DESPAWN_WAYPOINT, DespawnPoint);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->SetCombatPulseDelay(5);
            me->setActive(true);
            DoZoneInCombat();

            events.ScheduleEvent(EVENT_SOUL_DRAIN, Seconds(20));
            events.ScheduleEvent(EVENT_FRENZY, Seconds(45));
            Talk(SUFF_SAY_AGRO);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SUFF_SAY_SLAY);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (Creature* reliquary = instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
                reliquary->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SOUL_DRAIN:
                        me->CastCustomSpell(SPELL_SOUL_DRAIN, SPELLVALUE_MAX_TARGETS, 5, me);
                        events.Repeat(Seconds(30), Seconds(35));
                        break;
                    case EVENT_FRENZY:
                        Talk(SUFF_SAY_ENRAGE);
                        DoCastSelf(SPELL_FRENZY);
                        events.Repeat(Seconds(45), Seconds(50));
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
        bool _dead;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_essence_of_sufferingAI>(creature);
    }
};

class boss_essence_of_desire : public CreatureScript
{
public:
    boss_essence_of_desire() : CreatureScript("boss_essence_of_desire") { }

    struct boss_essence_of_desireAI : public BossAI
    {
        boss_essence_of_desireAI(Creature* creature) : BossAI(creature, DATA_ESSENCE_OF_DESIRE), _dead(false)
        {
            SetBoundary(instance->GetBossBoundary(DATA_RELIQUARY_OF_SOULS));
        }

        void Reset() override
        {
            DoCastSelf(SPELL_AURA_OF_DESIRE, true);
            events.Reset();
            _dead = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SPIRIT_SHOCK, Seconds(11));
            events.ScheduleEvent(EVENT_RUNE_SHIELD, Seconds(16));
            events.ScheduleEvent(EVENT_DEADEN, Seconds(31));

            me->SetCombatPulseDelay(5);
            me->setActive(true);
            DoZoneInCombat();
            Talk(DESI_SAY_FREED);
        }

        void MovementInform(uint32 motionType, uint32 pointId) override
        {
            if (motionType != POINT_MOTION_TYPE)
                return;

            if (pointId == RELIQUARY_DESPAWN_WAYPOINT)
            {
                if (Creature* reliquary = instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
                    reliquary->AI()->DoAction(ACTION_ESSENCE_OF_DESIRE_DEAD);

                DoCastSelf(SPELL_SUBMERGE_VISUAL, true);
                me->DespawnOrUnsummon(Seconds(2));
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!_dead)
                {
                    _dead = true;
                    Talk(DESI_SAY_RECAP);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    events.Reset();
                    me->InterruptNonMeleeSpells(false);
                    me->GetMotionMaster()->MovePoint(RELIQUARY_DESPAWN_WAYPOINT, DespawnPoint);
                }
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(DESI_SAY_SLAY);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (Creature* reliquary = instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
                reliquary->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPIRIT_SHOCK:
                        DoCastVictim(SPELL_SPIRIT_SHOCK);
                        events.Repeat(Seconds(10), Seconds(15));
                        break;
                    case EVENT_RUNE_SHIELD:
                        DoCastSelf(SPELL_RUNE_SHIELD);
                        events.Repeat(Seconds(16));
                        break;
                    case EVENT_DEADEN:
                        Talk(DESI_SAY_SPEC);
                        DoCastVictim(SPELL_DEADEN);
                        events.Repeat(Seconds(31));
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
        bool _dead;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_essence_of_desireAI>(creature);
    }
};

class boss_essence_of_anger : public CreatureScript
{
public:
    boss_essence_of_anger() : CreatureScript("boss_essence_of_anger") { }

    struct boss_essence_of_angerAI : public BossAI
    {
        boss_essence_of_angerAI(Creature* creature) :BossAI(creature, DATA_ESSENCE_OF_ANGER)
        {
            SetBoundary(instance->GetBossBoundary(DATA_RELIQUARY_OF_SOULS));
        }

        void Reset() override
        {
            events.Reset();
            _targetGUID.Clear();
            DoCastSelf(SPELL_AURA_OF_ANGER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(ANGER_SAY_FREED);

            events.ScheduleEvent(EVENT_START_CHECK_TANKER, Seconds(5));
            events.ScheduleEvent(EVENT_SOUL_SCREAM, Seconds(11));
            events.ScheduleEvent(EVENT_SPITE, Seconds(20));
            events.ScheduleEvent(EVENT_FREED_2, Seconds(1), Minutes(3));

            me->SetCombatPulseDelay(5);
            me->setActive(true);
            DoZoneInCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoPlaySoundToSet(me, ANGER_SOUND_ID_DEATH);
            if (Creature* reliquary = instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
                reliquary->AI()->DoAction(ACTION_KILL_SELF);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_TANKER:
                    {
                        Unit* target = me->GetVictim();
                        if (!_targetGUID || !target)
                            return;

                        if (target->GetGUID() != _targetGUID)
                        {
                            Talk(ANGER_SAY_SEETHE);
                            Talk(ANGER_EMOTE_SEETHE, me);
                            _targetGUID = target->GetGUID();
                            DoCastSelf(SPELL_SEETHE, true);
                        }
                        break;
                    }
                    case EVENT_SOUL_SCREAM:
                        DoCastSelf(SPELL_SOUL_SCREAM);
                        events.Repeat(Seconds(11));
                        break;
                    case EVENT_SPITE:
                        Talk(ANGER_SAY_SPITE);
                        me->CastCustomSpell(SPELL_SPITE, SPELLVALUE_MAX_TARGETS, 3, me);
                        events.Repeat(Seconds(20));
                        break;
                    case EVENT_START_CHECK_TANKER:
                        if (Unit* target = me->GetVictim())
                        {
                            _targetGUID = target->GetGUID();
                            events.ScheduleEvent(EVENT_CHECK_TANKER, Seconds(1));
                        }
                        else
                            events.Repeat(Seconds(1));
                        break;
                    case EVENT_FREED_2:
                        Talk(ANGER_SAY_FREED_2);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (Creature* reliquary = instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
                reliquary->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
        }

    private:
        ObjectGuid _targetGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_essence_of_angerAI>(creature);
    }
};

class npc_enslaved_soul : public CreatureScript
{
public:
    npc_enslaved_soul() : CreatureScript("npc_enslaved_soul") { }

    struct npc_enslaved_soulAI : public ScriptedAI
    {
        npc_enslaved_soulAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            if (Creature* reliquary = _instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
                reliquary->AI()->JustSummoned(me);

            DoCastSelf(SPELL_ENSLAVED_SOUL_PASSIVE, true);

            _scheduler.Schedule(Seconds(3), [this](TaskContext /*context*/)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetInCombatWithZone();
            });
        }

        void DoAction(int32 actionId) override
        {
            if (actionId == ACTION_KILL_SELF)
                me->KillSelf();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _scheduler.Update(diff);

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCastSelf(SPELL_SOUL_RELEASE, true);
        }

    private:
        InstanceScript* _instance;
        TaskScheduler _scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_enslaved_soulAI>(creature);
    }
};

// 41350 - Aura of Desire
class spell_reliquary_of_souls_aura_of_desire : public SpellScriptLoader
{
    public:
        spell_reliquary_of_souls_aura_of_desire() : SpellScriptLoader("spell_reliquary_of_souls_aura_of_desire") { }

        class spell_reliquary_of_souls_aura_of_desire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_reliquary_of_souls_aura_of_desire_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_AURA_OF_DESIRE_DAMAGE });
            }

            void OnProcSpell(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                Unit* caster = eventInfo.GetActor();
                int32 bp = damageInfo->GetDamage() / 2;
                caster->CastCustomSpell(SPELL_AURA_OF_DESIRE_DAMAGE, SPELLVALUE_BASE_POINT0, bp, caster, true, nullptr, aurEff);
            }

            void UpdateAmount(AuraEffect* /*aurEff*/)
            {
                if (AuraEffect* effect = GetAura()->GetEffect(EFFECT_1))
                    effect->ChangeAmount(effect->GetAmount() - 5);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_reliquary_of_souls_aura_of_desire_AuraScript::OnProcSpell, EFFECT_0, SPELL_AURA_MOD_HEALING_PCT);
                OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_reliquary_of_souls_aura_of_desire_AuraScript::UpdateAmount, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_reliquary_of_souls_aura_of_desire_AuraScript();
        }
};

// 28819 - Submerge Visual
class spell_reliquary_of_souls_submerge : public SpellScriptLoader
{
    public:
        spell_reliquary_of_souls_submerge() : SpellScriptLoader("spell_reliquary_of_souls_submerge") { }

        class spell_reliquary_of_souls_submerge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_reliquary_of_souls_submerge_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->SetStandState(UNIT_STAND_STATE_SUBMERGED);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->SetStandState(UNIT_STAND_STATE_STAND);
            }


            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_reliquary_of_souls_submerge_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_reliquary_of_souls_submerge_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_reliquary_of_souls_submerge_AuraScript();
        }
};

// 41376 - Spite
class spell_reliquary_of_souls_spite : public SpellScriptLoader
{
    public:
        spell_reliquary_of_souls_spite() : SpellScriptLoader("spell_reliquary_of_souls_spite") { }

        class spell_reliquary_of_souls_spite_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_reliquary_of_souls_spite_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SPITE_DAMAGE });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetTarget(), SPELL_SPITE_DAMAGE, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_reliquary_of_souls_spite_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_reliquary_of_souls_spite_AuraScript();
        }
};

// 41305 - Frenzy
class spell_reliquary_of_souls_frenzy : public SpellScriptLoader
{
    public:
        spell_reliquary_of_souls_frenzy() : SpellScriptLoader("spell_reliquary_of_souls_frenzy") { }

        class spell_reliquary_of_souls_frenzy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_reliquary_of_souls_frenzy_SpellScript);

            void HandleAfterCast()
            {
                if (Creature* caster = GetCaster()->ToCreature())
                    caster->AI()->Talk(SUFF_EMOTE_ENRAGE, caster);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_reliquary_of_souls_frenzy_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_reliquary_of_souls_frenzy_SpellScript();
        }
};

void AddSC_boss_reliquary_of_souls()
{
    new boss_reliquary_of_souls();
    new boss_essence_of_suffering();
    new boss_essence_of_desire();
    new boss_essence_of_anger();
    new npc_enslaved_soul();
    new spell_reliquary_of_souls_aura_of_desire();
    new spell_reliquary_of_souls_submerge();
    new spell_reliquary_of_souls_spite();
    new spell_reliquary_of_souls_frenzy();
}

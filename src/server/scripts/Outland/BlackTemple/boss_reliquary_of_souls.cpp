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
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

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
    ACTION_START_COMBAT,
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

struct boss_reliquary_of_souls : public BossAI
{
    boss_reliquary_of_souls(Creature* creature) : BossAI(creature, DATA_RELIQUARY_OF_SOULS), _inCombat(false) { }

    void Reset() override
    {
        _Reset();
        me->SetReactState(REACT_PASSIVE);
        _inCombat = false;
        events.SetPhase(PHASE_ESSENCE_OF_SUFFERING);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        summon->AI()->DoZoneInCombat();
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
                events.ScheduleEvent(EVENT_SUBMERGE, 40s);
                break;
            case ACTION_ESSENCE_OF_DESIRE_DEAD:
                me->RemoveAurasDueToSpell(SPELL_SUBMERGE_VISUAL);
                events.SetPhase(PHASE_ESSENCE_OF_ANGER);
                HandleSpirits();
                events.ScheduleEvent(EVENT_SUBMERGE, 40s);
                break;
            case ACTION_KILL_SELF:
                me->KillSelf();
                if (Creature* combatTrigger = instance->GetCreature(DATA_RELIQUARY_COMBAT_TRIGGER))
                    combatTrigger->AI()->DoAction(ACTION_KILL_SELF);
                break;
            case ACTION_START_COMBAT:
                _inCombat = true;
                me->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, UNIT_STAND_STATE_STAND);
                events.ScheduleEvent(EVENT_SUBMERGE, 10s);
                break;
            default:
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
                wTrigger->m_Events.AddEventAtOffset(new EnslavedSoulEvent(wTrigger), 4s);
            else if (i < 6)
                wTrigger->m_Events.AddEventAtOffset(new EnslavedSoulEvent(wTrigger), 8s);
            else if (i < 9)
                wTrigger->m_Events.AddEventAtOffset(new EnslavedSoulEvent(wTrigger), 12s);
            else if (i < 12)
                wTrigger->m_Events.AddEventAtOffset(new EnslavedSoulEvent(wTrigger), 16s);
            else if (i < 15)
                wTrigger->m_Events.AddEventAtOffset(new EnslavedSoulEvent(wTrigger), 20s);
            else if (i < 18)
                wTrigger->m_Events.AddEventAtOffset(new EnslavedSoulEvent(wTrigger), 24s);
            else
                wTrigger->m_Events.AddEventAtOffset(new EnslavedSoulEvent(wTrigger), 28s);
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
        if (!_inCombat)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId == EVENT_SUBMERGE)
            {
                DoCastSelf(SPELL_SUBMERGE_VISUAL, true);
                EntryCheckPredicate pred(NPC_ENSLAVED_SOUL);
                summons.DoAction(ACTION_KILL_SELF, pred);
                DoCastSelf(GetSummonSpell());
            }
        }
    }

private:
    bool _inCombat;
};

struct boss_essence_of_suffering : public BossAI
{
    boss_essence_of_suffering(Creature* creature) : BossAI(creature, DATA_ESSENCE_OF_SUFFERING), _dead(false)
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

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
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

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetCombatPulseDelay(5);
        me->setActive(true);

        events.ScheduleEvent(EVENT_SOUL_DRAIN, 20s);
        events.ScheduleEvent(EVENT_FRENZY, 45s);
        Talk(SUFF_SAY_AGRO);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SUFF_SAY_SLAY);
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
                    DoCastSelf(SPELL_SOUL_DRAIN, { SPELLVALUE_MAX_TARGETS, 5 });
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

struct boss_essence_of_desire : public BossAI
{
    boss_essence_of_desire(Creature* creature) : BossAI(creature, DATA_ESSENCE_OF_DESIRE), _dead(false)
    {
        SetBoundary(instance->GetBossBoundary(DATA_RELIQUARY_OF_SOULS));
    }

    void Reset() override
    {
        DoCastSelf(SPELL_AURA_OF_DESIRE, true);
        events.Reset();
        _dead = false;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_SPIRIT_SHOCK, 11s);
        events.ScheduleEvent(EVENT_RUNE_SHIELD, 16s);
        events.ScheduleEvent(EVENT_DEADEN, 31s);

        me->SetCombatPulseDelay(5);
        me->setActive(true);
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

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
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

struct boss_essence_of_anger : public BossAI
{
    boss_essence_of_anger(Creature* creature) :BossAI(creature, DATA_ESSENCE_OF_ANGER)
    {
        SetBoundary(instance->GetBossBoundary(DATA_RELIQUARY_OF_SOULS));
    }

    void Reset() override
    {
        events.Reset();
        _targetGUID.Clear();
        DoCastSelf(SPELL_AURA_OF_ANGER);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(ANGER_SAY_FREED);

        events.ScheduleEvent(EVENT_START_CHECK_TANKER, 5s);
        events.ScheduleEvent(EVENT_SOUL_SCREAM, 11s);
        events.ScheduleEvent(EVENT_SPITE, 20s);
        events.ScheduleEvent(EVENT_FREED_2, Seconds(1), Minutes(3));

        me->SetCombatPulseDelay(5);
        me->setActive(true);
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
                    DoCastSelf(SPELL_SPITE, { SPELLVALUE_MAX_TARGETS, 3 });
                    events.Repeat(Seconds(20));
                    break;
                case EVENT_START_CHECK_TANKER:
                    if (Unit* target = me->GetVictim())
                    {
                        _targetGUID = target->GetGUID();
                        events.ScheduleEvent(EVENT_CHECK_TANKER, 1s);
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

private:
    ObjectGuid _targetGUID;
};

struct npc_enslaved_soul : public ScriptedAI
{
    npc_enslaved_soul(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _dead(false) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        if (Creature* reliquary = _instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
            reliquary->AI()->JustSummoned(me);

        DoCastSelf(SPELL_ENSLAVED_SOUL_PASSIVE, true);

        _scheduler.Schedule(Seconds(3), [this](TaskContext /*context*/)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat();
        });
        _dead = false;
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_KILL_SELF)
            HandleSoulRelease();
    }

    void HandleSoulRelease()
    {
        me->SetReactState(REACT_PASSIVE);
        me->AttackStop();
        me->GetMotionMaster()->Clear();
        DoCastSelf(SPELL_SOUL_RELEASE);
        me->m_Events.AddEventAtOffset([this]() { me->KillSelf(); }, 500ms);
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = 0;
            if (!_dead)
            {
                _dead = true;
                HandleSoulRelease();
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    bool _dead;
};

struct npc_reliquary_combat_trigger : public ScriptedAI
{
    npc_reliquary_combat_trigger(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        SetCombatMovement(false);
        creature->m_SightDistance = 70.0f;
        SetBoundary(_instance->GetBossBoundary(DATA_RELIQUARY_OF_SOULS));
    }

    bool CanAIAttack(Unit const* who) const override
    {
        return ScriptedAI::CanAIAttack(who) && IsInBoundary(who);
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        if (_instance->GetBossState(DATA_RELIQUARY_OF_SOULS) == DONE)
            me->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!me->IsEngaged() && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && CanAIAttack(who))
        {
            if (Creature* reliquary = _instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
            {
                DoZoneInCombat();
                reliquary->AI()->DoAction(ACTION_START_COMBAT);
            }
        }
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        damage = 0;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        if (Creature* reliquary = _instance->GetCreature(DATA_RELIQUARY_OF_SOULS))
            reliquary->AI()->EnterEvadeMode(why);
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_KILL_SELF)
            me->KillSelf();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;
    }

private:
    InstanceScript* _instance;
};

// 41350 - Aura of Desire
class spell_reliquary_of_souls_aura_of_desire : public AuraScript
{
    PrepareAuraScript(spell_reliquary_of_souls_aura_of_desire);

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
        caster->CastSpell(caster, SPELL_AURA_OF_DESIRE_DAMAGE, CastSpellExtraArgs(aurEff).AddSpellBP0(damageInfo->GetDamage() / 2));
    }

    void UpdateAmount(AuraEffect* /*aurEff*/)
    {
        if (AuraEffect* effect = GetAura()->GetEffect(EFFECT_1))
            effect->ChangeAmount(effect->GetAmount() - 5);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_reliquary_of_souls_aura_of_desire::OnProcSpell, EFFECT_0, SPELL_AURA_MOD_HEALING_PCT);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_reliquary_of_souls_aura_of_desire::UpdateAmount, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 41337 - Aura of Anger
class spell_reliquary_of_souls_aura_of_anger : public AuraScript
{
    PrepareAuraScript(spell_reliquary_of_souls_aura_of_anger);

    void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
    {
        if (AuraEffect* aurEff1 = aurEff->GetBase()->GetEffect(EFFECT_1))
            aurEff1->ChangeAmount(aurEff1->GetAmount() + 5);
        aurEff->SetAmount(100 * aurEff->GetTickNumber());
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_reliquary_of_souls_aura_of_anger::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 28819 - Submerge Visual
class spell_reliquary_of_souls_submerge : public AuraScript
{
    PrepareAuraScript(spell_reliquary_of_souls_submerge);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, UNIT_STAND_STATE_SUBMERGED);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, UNIT_STAND_STATE_STAND);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_reliquary_of_souls_submerge::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_reliquary_of_souls_submerge::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 41376 - Spite
class spell_reliquary_of_souls_spite : public AuraScript
{
    PrepareAuraScript(spell_reliquary_of_souls_spite);

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
        AfterEffectRemove += AuraEffectRemoveFn(spell_reliquary_of_souls_spite::OnRemove, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 41305 - Frenzy
class spell_reliquary_of_souls_frenzy : public SpellScript
{
    PrepareSpellScript(spell_reliquary_of_souls_frenzy);

    void HandleAfterCast()
    {
        if (Creature* caster = GetCaster()->ToCreature())
            caster->AI()->Talk(SUFF_EMOTE_ENRAGE, caster);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_reliquary_of_souls_frenzy::HandleAfterCast);
    }
};

void AddSC_boss_reliquary_of_souls()
{
    RegisterBlackTempleCreatureAI(boss_reliquary_of_souls);
    RegisterBlackTempleCreatureAI(boss_essence_of_suffering);
    RegisterBlackTempleCreatureAI(boss_essence_of_desire);
    RegisterBlackTempleCreatureAI(boss_essence_of_anger);
    RegisterBlackTempleCreatureAI(npc_enslaved_soul);
    RegisterBlackTempleCreatureAI(npc_reliquary_combat_trigger);
    RegisterSpellScript(spell_reliquary_of_souls_aura_of_desire);
    RegisterSpellScript(spell_reliquary_of_souls_aura_of_anger);
    RegisterSpellScript(spell_reliquary_of_souls_submerge);
    RegisterSpellScript(spell_reliquary_of_souls_spite);
    RegisterSpellScript(spell_reliquary_of_souls_frenzy);
}

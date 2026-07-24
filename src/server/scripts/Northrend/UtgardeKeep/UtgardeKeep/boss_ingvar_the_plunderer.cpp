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

/*
 * Combat timers requires to be revisited
 * Everything related to Ingvar Throw Dummy requires additional research and checks
   since it may be handled wrongly or something may be missing
 * Out of Combat events are NYI, should be handled from Proto-Drake Rider's script (DB issue)
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "utgarde_keep.h"

enum IngvarTexts
{
    // Ingvar (Human / Undead)
    SAY_AGGRO                             = 0,
    SAY_SLAY                              = 1,
    SAY_DEATH                             = 2,
    EMOTE_ROAR                            = 3,

    // Annhylde The Caller
    SAY_RESURRECT                         = 0
};

enum IngvarSpells
{
    // Human Form
    SPELL_CLEAVE                          = 42724,
    SPELL_SMASH                           = 42669,
    SPELL_STAGGERING_ROAR                 = 42708,
    SPELL_ENRAGE                          = 42705,

    // Undead Form
    SPELL_DARK_SMASH                      = 42723,
    SPELL_DREADFUL_ROAR                   = 42729,
    SPELL_WOE_STRIKE                      = 42730,
    SPELL_SHADOW_AXE                      = 42748,

    // Feign Death & Resurrection
    SPELL_CLEAR_ALL_DEBUFFS               = 34098,
    SPELL_INGVAR_FEIGN_DEATH              = 42795,
    SPELL_SUMMON_BANSHEE                  = 42912,
    SPELL_ETHEREAL_TELEPORT               = 34427,
    SPELL_SCOURGE_RESURRECTION_CHANNEL    = 42857,
    SPELL_SCOURGE_RESURRECTION_VISUAL     = 42863,
    SPELL_SCOURGE_RESURRECTION_HEAL       = 42704,

    // Ingvar Throw Dummy
    SPELL_THROW_AXE                       = 42750,

    // Scripts
    SPELL_WOE_STRIKE_EFFECT               = 42739
};

enum IngvarEvents
{
    EVENT_CLEAVE                          = 1,
    EVENT_SMASH,
    EVENT_STAGGERING_ROAR,
    EVENT_ENRAGE,

    EVENT_SUMMON_BANSHEE,

    EVENT_DARK_SMASH,
    EVENT_DREADFUL_ROAR,
    EVENT_WOE_STRIKE,
    EVENT_SHADOW_AXE,

    EVENT_RESURRECTION_1,
    EVENT_RESURRECTION_2,
    EVENT_RESURRECTION_3,
    EVENT_RESURRECTION_4,
    EVENT_RESURRECTION_5,
    EVENT_RESURRECTION_6,
    EVENT_RESURRECTION_7,
    EVENT_RESURRECTION_8,
    EVENT_RESURRECTION_9,
    EVENT_RESURRECTION_10
};

enum IngvarActions
{
    ACTION_START_UNDEAD_PHASE             = 0,
    ACTION_AXE_RETURNS                    = 1
};

enum IngvarPoints
{
    POINT_CALLER_DOWN                     = 0,
    POINT_CALLER_UP                       = 1,
    POINT_AXE_TO_TARGET                   = 2,
    POINT_AXE_TO_OWNER                    = 3
};

enum IngvarCreatures
{
    NPC_INGVAR_UNDEAD                     = 23980,
    NPC_THROW_TARGET                      = 23996
};

// 23954 - Ingvar the Plunderer
struct boss_ingvar_the_plunderer : public BossAI
{
    boss_ingvar_the_plunderer(Creature* creature) : BossAI(creature, DATA_INGVAR), _isUnkillable(true), _isInTransition(false) { }

    void Reset() override
    {
        if (me->GetEntry() != NPC_INGVAR)
            me->UpdateEntry(NPC_INGVAR);
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_AGGRESSIVE);

        _Reset();

        _isUnkillable = true;
        _isInTransition = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_CLEAVE, 6s, 12s);
        events.ScheduleEvent(EVENT_SMASH, 12s, 17s);
        events.ScheduleEvent(EVENT_STAGGERING_ROAR, 18s, 21s);
        events.ScheduleEvent(EVENT_ENRAGE, 7s, 14s);
    }

    void DamageTaken(Unit* /*doneBy*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && _isUnkillable)
        {
            damage = me->GetHealth() - 1;

            if (_isInTransition)
                return;

            _isInTransition = true;
            me->InterruptNonMeleeSpells(false);
            Talk(SAY_DEATH);
            /// @todo: This should not be called. Clear All Debuffs should remove all debuffs. Does it work? Remove this
            me->RemoveAllAuras();
            DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
            DoCastSelf(SPELL_INGVAR_FEIGN_DEATH);
            /// This one is removed manually
            me->RemoveAurasDueToSpell(SPELL_ENRAGE);
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetReactState(REACT_PASSIVE);

            events.Reset();
            events.ScheduleEvent(EVENT_SUMMON_BANSHEE, 2400ms);
        }
    }

    void OnSpellStart(SpellInfo const* spell) override
    {
        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_STAGGERING_ROAR, me) ||
            spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_DREADFUL_ROAR, me))
            Talk(EMOTE_ROAR);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SHADOW_AXE)
            SetEquipmentSlots(false, EQUIP_UNEQUIP);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_UNDEAD_PHASE:
                me->UpdateEntry(NPC_INGVAR_UNDEAD);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetReactState(REACT_AGGRESSIVE);
                Talk(SAY_AGGRO);
                DoZoneInCombat();

                _isUnkillable = false;

                events.ScheduleEvent(EVENT_DARK_SMASH, 14s, 18s);
                events.ScheduleEvent(EVENT_DREADFUL_ROAR, 0s);
                events.ScheduleEvent(EVENT_WOE_STRIKE, 10s, 14s);
                events.ScheduleEvent(EVENT_SHADOW_AXE, 30s);
                break;
            case ACTION_AXE_RETURNS:
                me->LoadEquipment(1, true);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                // Human Phase
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(6s, 12s);
                    break;
                case EVENT_SMASH:
                    DoCastSelf(SPELL_SMASH);
                    events.Repeat(12s, 16s);
                    break;
                case EVENT_STAGGERING_ROAR:
                    DoCastSelf(SPELL_STAGGERING_ROAR);
                    events.Repeat(18s, 22s);
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE);
                    events.Repeat(7s, 14s);
                    break;

                // Transition Phase
                case EVENT_SUMMON_BANSHEE:
                    DoCastSelf(SPELL_SUMMON_BANSHEE);
                    break;

                // Undead Phase
                case EVENT_DARK_SMASH:
                    DoCastSelf(SPELL_DARK_SMASH);
                    events.Repeat(12s, 16s);
                    break;
                case EVENT_DREADFUL_ROAR:
                    DoCastSelf(SPELL_DREADFUL_ROAR);
                    events.Repeat(18s, 22s);
                    break;
                case EVENT_WOE_STRIKE:
                    DoCastVictim(SPELL_WOE_STRIKE);
                    events.Repeat(10s, 14s);
                    break;
                case EVENT_SHADOW_AXE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_SHADOW_AXE);
                    events.Repeat(30s);
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
    bool _isUnkillable;
    bool _isInTransition;
};

// 24068 - Annhylde the Caller
struct npc_annhylde_the_caller : public ScriptedAI
{
    npc_annhylde_the_caller(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_RESURRECTION_1, 0s);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_CALLER_DOWN:
                _events.ScheduleEvent(EVENT_RESURRECTION_3, 1s);
                break;
            case POINT_CALLER_UP:
                _events.ScheduleEvent(EVENT_RESURRECTION_10, 1s);
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
                case EVENT_RESURRECTION_1:
                    DoCastSelf(SPELL_ETHEREAL_TELEPORT);
                    _events.ScheduleEvent(EVENT_RESURRECTION_2, 2400ms);
                    break;
                case EVENT_RESURRECTION_2:
                    me->GetMotionMaster()->MovePoint(POINT_CALLER_DOWN, me->GetPositionWithOffset({ 0.0f, 0.0f, -15.0f }));
                    break;
                case EVENT_RESURRECTION_3:
                    Talk(SAY_RESURRECT);
                    _events.ScheduleEvent(EVENT_RESURRECTION_4, 2400ms);
                    break;
                case EVENT_RESURRECTION_4:
                    if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_INGVAR)))
                        ingvar->RemoveAurasDueToSpell(SPELL_SUMMON_BANSHEE);
                    _events.ScheduleEvent(EVENT_RESURRECTION_5, 1200ms);
                    break;
                case EVENT_RESURRECTION_5:
                    DoCastSelf(SPELL_SCOURGE_RESURRECTION_CHANNEL);
                    _events.ScheduleEvent(EVENT_RESURRECTION_6, 2400ms);
                    break;
                case EVENT_RESURRECTION_6:
                    if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_INGVAR)))
                        ingvar->CastSpell(ingvar, SPELL_SCOURGE_RESURRECTION_VISUAL);
                    _events.ScheduleEvent(EVENT_RESURRECTION_7, 6s);
                    break;
                case EVENT_RESURRECTION_7:
                    if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_INGVAR)))
                    {
                        ingvar->RemoveAurasDueToSpell(SPELL_INGVAR_FEIGN_DEATH);
                        ///! HACK: Removing Feign Death changes react state to default
                        ingvar->SetReactState(REACT_PASSIVE);
                        ingvar->CastSpell(ingvar, SPELL_SCOURGE_RESURRECTION_HEAL);
                    }
                    _events.ScheduleEvent(EVENT_RESURRECTION_8, 3600ms);
                    break;
                case EVENT_RESURRECTION_8:
                    if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_INGVAR)))
                        ingvar->AI()->DoAction(ACTION_START_UNDEAD_PHASE);
                    _events.ScheduleEvent(EVENT_RESURRECTION_9, 1200ms);
                    break;
                case EVENT_RESURRECTION_9:
                    me->GetMotionMaster()->MovePoint(POINT_CALLER_UP, me->GetPositionWithOffset({ 0.0f, 0.0f, 15.0f }));
                    break;
                case EVENT_RESURRECTION_10:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

// 23997 - Ingvar Throw Dummy
struct npc_ingvar_throw_dummy : public ScriptedAI
{
    npc_ingvar_throw_dummy(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_THROW_AXE);

        _scheduler.Schedule(1s, [this](TaskContext /*task*/)
        {
            if (Creature* target = me->FindNearestCreature(NPC_THROW_TARGET, 200.0f))
                me->GetMotionMaster()->MovePoint(POINT_AXE_TO_TARGET, target->GetPosition());
        });

        _scheduler.Schedule(6s, 10s, [this](TaskContext /*task*/)
        {
            if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_INGVAR)))
                me->GetMotionMaster()->MovePoint(POINT_AXE_TO_OWNER, ingvar->GetPosition());
        });
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_AXE_TO_OWNER)
        {
            if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_INGVAR)))
                ingvar->AI()->DoAction(ACTION_AXE_RETURNS);

            _scheduler.Schedule(1s, [this](TaskContext /*task*/)
            {
                SetEquipmentSlots(false, EQUIP_UNEQUIP);
                me->DespawnOrUnsummon();
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 42912 - Summon Banshee
class spell_ingvar_summon_banshee : public SpellScript
{
    PrepareSpellScript(spell_ingvar_summon_banshee);

    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 30.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ingvar_summon_banshee::SetDest, EFFECT_0, TARGET_DEST_CASTER_BACK);
    }
};

// 42730, 59735 - Woe Strike
class spell_ingvar_woe_strike : public AuraScript
{
    PrepareAuraScript(spell_ingvar_woe_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WOE_STRIKE_EFFECT });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_WOE_STRIKE_EFFECT, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_ingvar_woe_strike::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_ingvar_woe_strike::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_boss_ingvar_the_plunderer()
{
    RegisterUtgardeKeepCreatureAI(boss_ingvar_the_plunderer);
    RegisterUtgardeKeepCreatureAI(npc_annhylde_the_caller);
    RegisterUtgardeKeepCreatureAI(npc_ingvar_throw_dummy);
    RegisterSpellScript(spell_ingvar_summon_banshee);
    RegisterSpellScript(spell_ingvar_woe_strike);
}

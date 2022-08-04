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

#include "zulgurub.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Says
{
    TALK_TIGER_PHASE          = 0,
    TALK_DEATH                = 1,
    TALK_FAKE_DEATH           = 2,
    TALK_FRENZY               = 3
};

enum Spells
{
    SPELL_RESURRECT           = 24173, // ToDo: find out how this should be used
    SPELL_RESURRECT_VISUAL    = 24171,

    // High Priest Thekal
    // Phase 1
    SPELL_MORTALCLEAVE        = 22859,
    SPELL_SILENCE             = 22666,
    // Phase 2
    SPELL_TIGER_FORM          = 24169,
    SPELL_FRENZY              = 8269,
    SPELL_FORCEPUNCH          = 24189,
    SPELL_CHARGE              = 24193,
    SPELL_SUMMONTIGERS        = 24183,

    // Zealot Lor'Khan
    SPELL_SHIELD              = 20545,
    SPELL_BLOODLUST           = 24185,
    SPELL_GREATERHEAL         = 24208,
    SPELL_DISARM              = 6713,

    // Zealot Zath
    SPELL_SWEEPINGSTRIKES     = 18765,
    SPELL_SINISTERSTRIKE      = 15581,
    SPELL_GOUGE               = 12540,
    SPELL_KICK                = 15614,
    SPELL_BLIND               = 21060,

    SPELL_PERMANENT_FEIGN_DEATH = 29266
};

enum ThekalEvents
{
    EVENT_MORTALCLEAVE = 1,
    EVENT_SILENCE,
    EVENT_RESURRECT_TIMER,
    EVENT_CHANGE_PHASE_1,
    EVENT_CHANGE_PHASE_2,
    EVENT_CHANGE_PHASE_3,

    EVENT_FORCEPUNCH,
    EVENT_SPELL_CHARGE,
    EVENT_SUMMONTIGERS
};

enum Phases
{
    PHASE_ONE                 = 1,
    PHASE_TWO                 = 2
};

// Resurrection is handled by the main boss' script, dispatching resurrection as needed
enum Data
{
    DATA_FAKE_DEATH = 1,
    DATA_RESURRECTED
};

float const DamageIncrease = 40.0f;
float const DamageDecrease = 100.f / (1.f + DamageIncrease / 100.f) - 100.f;

struct boss_thekal : public BossAI
{
    boss_thekal(Creature* creature) : BossAI(creature, DATA_THEKAL)
    {
        Initialize();
    }

    void Initialize()
    {
        _enraged = false;
        _isThekalDead = false;
        _isLorkhanDead = false;
        _isZathDead = false;
        _isResurrectTimerActive = false;
        _isChangingPhase = false;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_EnterEvadeMode(why))
            return;
        me->AddUnitState(UNIT_STATE_EVADE);
        me->GetMotionMaster()->MoveTargetedHome();
        Reset();
    }

    void Reset() override
    {
        if (events.IsInPhase(PHASE_TWO))
            me->ApplyStatPctModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, DamageDecrease);
        me->SetControlled(false, UNIT_STATE_ROOT);
        events.Reset();
        _Reset();
        Initialize();
        me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(TALK_DEATH);

        // Adds are still feign-deathing, so kill them when the encounter is over
        if (Creature* creature = instance->GetCreature(DATA_LORKHAN))
            creature->KillSelf();
        if (Creature* creature = instance->GetCreature(DATA_ZATH))
            creature->KillSelf();
        instance->SetBossState(DATA_LORKHAN, DONE);
        instance->SetBossState(DATA_ZATH, DONE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_MORTALCLEAVE, 4s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SILENCE, 9s, 0, PHASE_ONE);
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_FAKE_DEATH)
        {
            // A mob died
            switch (data)
            {
                case NPC_HIGH_PRIEST_THEKAL:
                    _isThekalDead = true;
                    break;
                case NPC_ZEALOT_LORKHAN:
                    _isLorkhanDead = true;
                    break;
                case NPC_ZEALOT_ZATH:
                    _isZathDead = true;
                    break;
                default:
                    return;
            }

            if (_isThekalDead && _isLorkhanDead && _isZathDead)
            {
                _isResurrectTimerActive = false;
                events.Reset();
                events.ScheduleEvent(EVENT_CHANGE_PHASE_1, 3s);
            }
            else
            {
                // Start resurrection timer if not already started, otherwise ignore
                if (!_isResurrectTimerActive)
                {
                    events.ScheduleEvent(EVENT_RESURRECT_TIMER, 10s);
                    _isResurrectTimerActive = true;
                }
            }
        }
        else if (type == DATA_RESURRECTED)
        {
            Creature* creature = nullptr;
            if (data == NPC_HIGH_PRIEST_THEKAL)
                creature = me;
            else if (data == NPC_ZEALOT_LORKHAN)
                creature = instance->GetCreature(DATA_LORKHAN);
            else if (data == NPC_ZEALOT_ZATH)
                creature = instance->GetCreature(DATA_ZATH);

            // Resurrect
            if (creature)
            {
                creature->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                creature->SetFullHealth();
                creature->SetImmuneToPC(false, true);
                creature->SetImmuneToNPC(false, true);
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && events.IsInPhase(PHASE_ONE))
        {
            Talk(TALK_FAKE_DEATH);
            me->RemoveAllAuras();
            me->SetImmuneToPC(true, true);
            me->SetImmuneToNPC(true, true);
            DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH, true);
            events.DelayEvents(10s);
            SetData(DATA_FAKE_DEATH, me->GetEntry());
            damage = 0;
        }
        else if (events.IsInPhase(PHASE_TWO) && !_enraged && me->HealthBelowPct(10))
        {
            DoCastSelf(SPELL_FRENZY);
            Talk(TALK_FRENZY);
            _enraged = true;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MORTALCLEAVE:
                    DoCastVictim(SPELL_MORTALCLEAVE);
                    events.ScheduleEvent(EVENT_MORTALCLEAVE, 15s, 20s, 0, PHASE_ONE);
                    break;
                case EVENT_SILENCE:
                    DoCastVictim(SPELL_SILENCE);
                    events.ScheduleEvent(EVENT_SILENCE, 20s, 25s, 0, PHASE_ONE);
                    break;
                case EVENT_RESURRECT_TIMER:
                {
                    // If only one or two of the three mobs were killed, resurrect them
                    _isResurrectTimerActive = false;

                    if (_isThekalDead)
                    {
                        DoCastSelf(SPELL_RESURRECT_VISUAL);
                        SetData(DATA_RESURRECTED, me->GetEntry());
                        _isThekalDead = false;
                    }

                    if (_isLorkhanDead)
                    {
                        if (Creature* lorkhan = instance->GetCreature(DATA_LORKHAN))
                        {
                            lorkhan->AI()->DoCastSelf(SPELL_RESURRECT_VISUAL);
                            SetData(DATA_RESURRECTED, lorkhan->GetEntry());
                        }
                        _isLorkhanDead = false;
                    }

                    if (_isZathDead)
                    {
                        if (Creature* zath = instance->GetCreature(DATA_ZATH))
                        {
                            zath->AI()->DoCastSelf(SPELL_RESURRECT_VISUAL);
                            SetData(DATA_RESURRECTED, zath->GetEntry());
                        }
                        _isZathDead = false;
                    }
                    break;
                }
                case EVENT_CHANGE_PHASE_1:
                    _isChangingPhase = true;
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                    me->SetFullHealth();
                    DoCastSelf(SPELL_RESURRECT_VISUAL);
                    events.ScheduleEvent(EVENT_CHANGE_PHASE_2, 1s);
                    break;
                case EVENT_CHANGE_PHASE_2:
                    Talk(TALK_TIGER_PHASE);
                    events.ScheduleEvent(EVENT_CHANGE_PHASE_3, 1s);
                    break;
                case EVENT_CHANGE_PHASE_3:
                {
                    // Trigger phase change
                    _isChangingPhase = false;
                    DoCastSelf(SPELL_TIGER_FORM);
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                    me->ApplyStatPctModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, DamageIncrease);
                    ResetThreatList();
                    me->SetControlled(false, UNIT_STATE_ROOT);
                    events.ScheduleEvent(EVENT_FORCEPUNCH, 4s, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SPELL_CHARGE, 12s, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SUMMONTIGERS, 25s, 0, PHASE_TWO);
                    events.SetPhase(PHASE_TWO);
                    break;
                }
                case EVENT_FORCEPUNCH:
                    DoCastVictim(SPELL_FORCEPUNCH, true);
                    events.ScheduleEvent(EVENT_FORCEPUNCH, 16s, 21s, 0, PHASE_TWO);
                    break;
                case EVENT_CHARGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.f, true))
                    {
                        ResetThreatList();
                        AttackStart(target);
                        DoCast(target, SPELL_CHARGE);
                    }
                    events.ScheduleEvent(EVENT_CHARGE, 15s, 22s, 0, PHASE_TWO);
                    break;
                case EVENT_SUMMONTIGERS:
                    DoCastVictim(SPELL_SUMMONTIGERS, true);
                    events.ScheduleEvent(EVENT_SUMMONTIGERS, 10s, 14s, 0, PHASE_TWO);
                    break;
                default:
                    break;
            }
        }

        if (_isChangingPhase)
            return;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    bool _enraged;
    bool _isThekalDead;
    bool _isLorkhanDead;
    bool _isZathDead;
    bool _isResurrectTimerActive;
    bool _isChangingPhase;
};

enum LorkhanEvents
{
    EVENT_SHIELD = 1,
    EVENT_BLOODLUST,
    EVENT_GREATER_HEAL,
    EVENT_DISARM
};

// Find which one of the three creatures Lor'Khan should heal (self, Thekal or Zath)
class LorKhanSelectTargetToHeal
{
    public:
        LorKhanSelectTargetToHeal(Unit const* reference, float range) : _reference(reference), _range(range), _hp(0) { }

        bool operator()(Unit* object)
        {
            if (object->GetTypeId() != TYPEID_UNIT || !object->IsAlive() || !object->IsInCombat())
                return false;

            if (object->ToCreature()->GetEntry() != NPC_HIGH_PRIEST_THEKAL && object->GetEntry() != NPC_ZEALOT_LORKHAN && object->GetEntry() != NPC_ZEALOT_ZATH)
                return false;

            // Don't allow to heal a target that is waiting for resurrection
            if (object->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                return false;

            if ((object->GetMaxHealth() - object->GetHealth() > _hp) && _reference->IsWithinDistInMap(object, _range))
            {
                _hp = object->GetMaxHealth() - object->GetHealth();
                return true;
            }

            return false;
        }

    private:
        Unit const* _reference;
        float const _range;
        uint32 _hp;
};

// Zealot Lor'Khan
struct npc_zealot_lorkhan : public ScriptedAI
{
    npc_zealot_lorkhan(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            Talk(TALK_FAKE_DEATH);
            me->RemoveAllAuras();
            me->SetImmuneToPC(true, true);
            me->SetImmuneToNPC(true, true);
            DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH, true);
            me->AttackStop();
            if (Creature* thekal = _instance->GetCreature(DATA_THEKAL))
                thekal->AI()->SetData(DATA_FAKE_DEATH, me->GetEntry());
            _events.DelayEvents(10s);
            damage = 0;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SHIELD, 1s);
        _events.ScheduleEvent(EVENT_BLOODLUST, 16s);
        _events.ScheduleEvent(EVENT_GREATER_HEAL, 32s);
        _events.ScheduleEvent(EVENT_DISARM, 6s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHIELD:
                    DoCastSelf(SPELL_SHIELD);
                    _events.ScheduleEvent(EVENT_SHIELD, 61s);
                    break;
                case EVENT_BLOODLUST:
                    DoCastSelf(SPELL_BLOODLUST);
                    _events.ScheduleEvent(EVENT_BLOODLUST, 20s, 28s);
                    break;
                case EVENT_GREATER_HEAL:
                {
                    Unit* target = nullptr;
                    LorKhanSelectTargetToHeal check(me, 100.0f);
                    Trinity::UnitLastSearcher<LorKhanSelectTargetToHeal> searcher(me, target, check);
                    Cell::VisitAllObjects(me, searcher, 100.0f);

                    if (target)
                        DoCast(target, SPELL_GREATERHEAL);

                    _events.ScheduleEvent(EVENT_GREATER_HEAL, 15s, 20s);
                    break;
                }
                case EVENT_DISARM:
                    DoCastVictim(SPELL_DISARM);
                    _events.ScheduleEvent(EVENT_DISARM, 15s, 25s);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

enum ZathEvents
{
    EVENT_SWEEPING_STRIKES = 1,
    EVENT_SINISTER_STRIKE,
    EVENT_GOUGE,
    EVENT_KICK,
    EVENT_BLIND,
};

// Zealot Zath
struct npc_zealot_zath : public ScriptedAI
{
    npc_zealot_zath(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            Talk(TALK_FAKE_DEATH);
            me->RemoveAllAuras();
            me->SetImmuneToPC(true, true);
            me->SetImmuneToNPC(true, true);
            DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH, true);
            me->AttackStop();
            if (Creature* thekal = _instance->GetCreature(DATA_THEKAL))
                thekal->AI()->SetData(DATA_FAKE_DEATH, me->GetEntry());
            _events.DelayEvents(10s);
            damage = 0;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SWEEPING_STRIKES, 13s);
        _events.ScheduleEvent(EVENT_SINISTER_STRIKE, 8s);
        _events.ScheduleEvent(EVENT_GOUGE, 25s);
        _events.ScheduleEvent(EVENT_KICK, 18s);
        _events.ScheduleEvent(EVENT_BLIND, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SWEEPING_STRIKES:
                    DoCastVictim(SPELL_SWEEPINGSTRIKES);
                    _events.ScheduleEvent(EVENT_SWEEPING_STRIKES, 22s, 26s);
                    break;
                case EVENT_SINISTER_STRIKE:
                    DoCastVictim(SPELL_SINISTERSTRIKE);
                    _events.ScheduleEvent(EVENT_SINISTER_STRIKE, 8s, 16s);
                    break;
                case EVENT_GOUGE:
                    DoCastVictim(SPELL_GOUGE);
                    if (GetThreat(me->GetVictim()))
                        ModifyThreatByPercent(me->GetVictim(), -100);
                    _events.ScheduleEvent(EVENT_GOUGE, 17s, 27s);
                    break;
                case EVENT_KICK:
                    DoCastVictim(SPELL_KICK);
                    _events.ScheduleEvent(EVENT_KICK, 15s, 25s);
                    break;
                case EVENT_BLIND:
                    DoCastVictim(SPELL_BLIND);
                    _events.ScheduleEvent(EVENT_BLIND, 10s, 20s);
                    break;
                default:
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

void AddSC_boss_thekal()
{
    RegisterZulGurubCreatureAI(boss_thekal);
    RegisterZulGurubCreatureAI(npc_zealot_lorkhan);
    RegisterZulGurubCreatureAI(npc_zealot_zath);
}

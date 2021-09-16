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

#include "shadowfang_keep.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "InstanceScript.h"
#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_SLAY  = 2
};

enum Events
{
    // Baron Silverlaine
    EVENT_VEIL_OF_SHADOW = 1,
    EVENT_CURSED_VEIL,
    EVENT_SUMMON_WORGEN_SPIRIT,

    // Odo the Blindwatcher
    EVENT_HOWLING_RAGE,
    EVENT_BLINDING_SHADOWS,

    // Wolf Master Nandos
    EVENT_CLAW,

    // Razorclaw the Butcher
    EVENT_SPECTRAL_RUSH,

    // Rethilgore
    EVENT_SOUL_DRAIN
};

enum Actions
{
    ACTION_DESPAWN = 0
};

enum Spells
{
    SPELL_VEIL_OF_SHADOWS                               = 23224,
    SPELL_CURSED_VEIL                                   = 93956,
    SPELL_SUMMON_WORGEN_SPIRIT                          = 93857,

    SPELL_SUMMON_SPIRIT_OF_WOLF_MASTER_NANDOS_DUMMY     = 93896, // Dummy Summon
    SPELL_SUMMON_SPIRIT_OF_WOLF_MASTER_NANDOS_SUMMON    = 93899,

    SPELL_SUMMON_SPIRIT_OF_ODO_THE_BLINDWATCHER_DUMMY   = 93859, // Dummy Summon
    SPELL_SUMMON_SPIRIT_OF_ODO_THE_BLINDWATCHER_SUMMON  = 93864,

    SPELL_SUMMON_SPIRIT_OF_RAZORCLAW_THE_BUTCHER_DUMMY  = 93921, // Dummy Summon
    SPELL_SUMMON_SPIRIT_OF_RAZORCLAW_THE_BUTCHER_SUMMON = 93924,
    
    SPELL_SUMMON_SPIRIT_OF_RETHILGORE_DUMMY             = 93925, // Dummy Summon
    SPELL_SUMMON_SPIRIT_OF_RETHILGORE_SUMMON            = 93927,

    // Odo the Blindwatcher
    SPELL_HOWLING_RAGE                                  = 93931,
    SPELL_BLINDING_SHADOWS                              = 93952,

    // Wolf Master Nandos
    SPELL_CLAW                                          = 93861,
    SPELL_SUMMON_LUPINE_SPECTRE                         = 94199,

    // Razorclaw the Butcher
    SPELL_SPECTRAL_RUSH                                 = 93914,

    // Rethilgore
    SPELL_SOUL_DRAIN                                    = 93863
};

struct boss_baron_silverlaine : public BossAI
{
    boss_baron_silverlaine(Creature* creature) : BossAI(creature, DATA_BARON_SILVERLAINE), _summonedSpiritCounter(0) { }

    void InitializeAI() override
    {
        // Initialize the summon spells that we are going to use in this encounter
        _worgenSummonSpells =
        {
            SPELL_SUMMON_SPIRIT_OF_WOLF_MASTER_NANDOS_DUMMY,
            SPELL_SUMMON_SPIRIT_OF_ODO_THE_BLINDWATCHER_DUMMY,
            SPELL_SUMMON_SPIRIT_OF_RAZORCLAW_THE_BUTCHER_DUMMY,
            SPELL_SUMMON_SPIRIT_OF_RETHILGORE_DUMMY
        };

        Trinity::Containers::RandomResize(_worgenSummonSpells, IsHeroic() ? 3 : 2);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        if (IsHeroic())
            events.ScheduleEvent(EVENT_CURSED_VEIL, 5s);
        else
            events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, 5s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DespawnWorgenSpirits();
        _JustDied();
    }

    void KilledUnit(Unit* target) override
    {
        if (target->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SetBossState(DATA_BARON_SILVERLAINE, FAIL);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DespawnWorgenSpirits();
        _DespawnAtEvade();
    }

    void DespawnWorgenSpirits()
    {
        EntryCheckPredicate nandos(NPC_WOLF_MASTER_NANDOS);
        summons.DoAction(ACTION_DESPAWN, nandos);

        EntryCheckPredicate odo(NPC_ODO_THE_BLINDWATCHER);
        summons.DoAction(ACTION_DESPAWN, odo);

        EntryCheckPredicate razorclaw(NPC_RAZORCLAW_THE_BUTCHER);
        summons.DoAction(ACTION_DESPAWN, razorclaw);

        EntryCheckPredicate rethilgore(NPC_RETHILGORE);
        summons.DoAction(ACTION_DESPAWN, rethilgore);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        switch (summon->GetEntry())
        {
            case NPC_WORGEN_SPIRIT_ODO:
                summon->CastSpell(summon, SPELL_SUMMON_SPIRIT_OF_ODO_THE_BLINDWATCHER_SUMMON);
                break;
            case NPC_WORGEN_SPIRIT_RAZORCLAW:
                summon->CastSpell(summon, SPELL_SUMMON_SPIRIT_OF_RAZORCLAW_THE_BUTCHER_SUMMON);
                break;
            case NPC_WORGEN_SPIRIT_NANDOS:
                summon->CastSpell(summon, SPELL_SUMMON_SPIRIT_OF_WOLF_MASTER_NANDOS_SUMMON);
                break;
            case NPC_WORGEN_SPIRIT_RETHILGORE:
                summon->CastSpell(summon, SPELL_SUMMON_SPIRIT_OF_RETHILGORE_SUMMON);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (IsHeroic())
        {
            if (me->HealthBelowPctDamaged(90, damage) && _summonedSpiritCounter == 0)
            {
                events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, 1ms);
                ++_summonedSpiritCounter;
            }
            else if (me->HealthBelowPctDamaged(60, damage) && _summonedSpiritCounter == 1)
            {
                events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, 1ms);
                ++_summonedSpiritCounter;
            }
            else if (me->HealthBelowPctDamaged(30, damage) && _summonedSpiritCounter == 2)
            {
                events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, 1ms);
                ++_summonedSpiritCounter;
            }
        }
        else
        {
            if (me->HealthBelowPctDamaged(75, damage) && _summonedSpiritCounter == 0)
            {
                events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, 1ms);
                ++_summonedSpiritCounter;
            }
            else if (me->HealthBelowPctDamaged(35, damage) && _summonedSpiritCounter == 1)
            {
                events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, 1ms);
                ++_summonedSpiritCounter;
            }
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
                case EVENT_VEIL_OF_SHADOW:
                    DoCastVictim(SPELL_VEIL_OF_SHADOWS);
                    events.Repeat(17s);
                    break;
                case EVENT_CURSED_VEIL:
                    DoCastAOE(SPELL_CURSED_VEIL);
                    events.Repeat(27s);
                    break;
                case EVENT_SUMMON_WORGEN_SPIRIT:
                {
                    int32 bp0 = _worgenSummonSpells.front();
                    _worgenSummonSpells.erase(_worgenSummonSpells.begin());
                    DoCastAOE(SPELL_SUMMON_WORGEN_SPIRIT, CastSpellExtraArgs().AddSpellBP0(bp0));
                    break;
                }
                default:
                    break;
            }
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }
private:
    std::vector<uint32> _worgenSummonSpells;
    uint8 _summonedSpiritCounter;
};

struct npc_sfk_worgen_spirit : public ScriptedAI
{
    npc_sfk_worgen_spirit(Creature* creature) : ScriptedAI(creature), _instance(nullptr), _summons(me) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        if (!_instance)
            return;

        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        if (Creature* silverlaine = _instance->GetCreature(DATA_BARON_SILVERLAINE))
            if (silverlaine->IsAIEnabled())
                silverlaine->AI()->JustSummoned(me);

        DoZoneInCombat();

        switch (me->GetEntry())
        {
            case NPC_WOLF_MASTER_NANDOS:
                for (uint8 i = 0; i < 3; ++i)
                    DoCastSelf(SPELL_SUMMON_LUPINE_SPECTRE);
                _events.ScheduleEvent(EVENT_CLAW, 7s);
                break;
            case NPC_ODO_THE_BLINDWATCHER:
                _events.ScheduleEvent(EVENT_HOWLING_RAGE, 5s);
                _events.ScheduleEvent(EVENT_BLINDING_SHADOWS, 5s);
                break;
            case NPC_RAZORCLAW_THE_BUTCHER:
                _events.ScheduleEvent(EVENT_SPECTRAL_RUSH, 4s);
                break;
            case NPC_RETHILGORE:
                _events.ScheduleEvent(EVENT_SOUL_DRAIN, 8s);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _summons.DespawnAll();
        me->DespawnOrUnsummon(5s);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DESPAWN:
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->DespawnOrUnsummon();
                _summons.DespawnAll();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLAW:
                    DoCastVictim(SPELL_CLAW);
                    _events.Repeat(6s, 7s);
                    break;
                case EVENT_HOWLING_RAGE:
                    DoCastAOE(SPELL_HOWLING_RAGE);
                    _events.Repeat(11s);
                    break;
                case EVENT_BLINDING_SHADOWS:
                    DoCastVictim(SPELL_BLINDING_SHADOWS);
                    _events.Repeat(14s);
                    break;
                case EVENT_SPECTRAL_RUSH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.f, true, false))
                        DoCast(target, SPELL_SPECTRAL_RUSH);
                    else
                        DoCastVictim(SPELL_SPECTRAL_RUSH);
                    _events.Repeat(11s);
                    break;
                case EVENT_SOUL_DRAIN:
                    DoCastVictim(SPELL_SOUL_DRAIN);
                    _events.Repeat(13s);
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
    InstanceScript* _instance;
    EventMap _events;
    SummonList _summons;
};

class spell_sfk_summon_worgen_spirit : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_sfk_summon_worgen_spirit::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_baron_silverlaine()
{
    RegisterShadowfangKeepCreatureAI(boss_baron_silverlaine);
    RegisterShadowfangKeepCreatureAI(npc_sfk_worgen_spirit);
    RegisterSpellScript(spell_sfk_summon_worgen_spirit);
}

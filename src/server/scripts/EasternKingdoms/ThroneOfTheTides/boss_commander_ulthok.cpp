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
#include "throne_of_the_tides.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Player.h"
#include "InstanceScript.h"

enum Texts
{
    // Commander Ulthok
    SAY_AGGRO           = 0,
    SAY_WHISPER_AGGRO   = 1,
    SAY_SLAY            = 2,
    SAY_WHISPER_SLAY    = 3,
    SAY_DEATH           = 4,
    SAY_WHISPER_DEATH   = 5
};

enum Spells
{
    // Commander Ulthok
    SPELL_ULTHOK_VO_AGGRO       = 94481,
    SPELL_ULTHOK_VO_SLAY        = 94483,
    SPELL_ULTHOK_VO_DEATH       = 94484,
    SPELL_SQUEEZE_RIDE_VEHICLE  = 76038,
    SPELL_ENRAGE                = 76100,
    SPELL_CURSE_OF_FATIGUE      = 76094,
    SPELL_DARK_FISSURE          = 76047,
};

#define SPELL_SQUEEZE RAID_MODE<uint32>(76026, 91484)

enum Events
{
    // Commander Ulthok
    EVENT_ROAR_EMOTE = 1,
    EVENT_READY_ULTHOK,
    EVENT_SQUEEZE,
    EVENT_ENRAGE,
    EVENT_CURSE_OF_FATIGUE,
    EVENT_DARK_FISSURE,
};

enum Phases
{
    PHASE_INTRO     = 0,
    PHASE_COMBAT    = 1
};

struct boss_commander_ulthok : public BossAI
{
    boss_commander_ulthok(Creature* creature) : BossAI(creature, DATA_COMMANDER_ULTHOK) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        DoCastAOE(SPELL_ULTHOK_VO_AGGRO, true);
        events.SetPhase(PHASE_COMBAT);
        events.ScheduleEvent(EVENT_SQUEEZE, 13s + 200ms);
        events.ScheduleEvent(EVENT_ENRAGE, 32s, 33s);
        events.ScheduleEvent(EVENT_CURSE_OF_FATIGUE, 13s);
        events.ScheduleEvent(EVENT_DARK_FISSURE, 7s);
    }

    void Reset() override
    {
        _Reset();
        events.SetPhase(PHASE_INTRO);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        events.ScheduleEvent(EVENT_ROAR_EMOTE, 1s, 0, PHASE_INTRO);
    }

    void KilledUnit(Unit* killed) override
    {
        if (killed->GetTypeId() == TYPEID_PLAYER)
        {
            Talk(SAY_SLAY);
            DoCastAOE(SPELL_ULTHOK_VO_SLAY, true);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SetBossState(DATA_COMMANDER_ULTHOK, FAIL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SQUEEZE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CURSE_OF_FATIGUE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        DoCastAOE(SPELL_ULTHOK_VO_DEATH, true);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SQUEEZE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CURSE_OF_FATIGUE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (!target)
            return;

        switch (spell->Id)
        {
            case SPELL_ULTHOK_VO_AGGRO:
                Talk(SAY_WHISPER_AGGRO, target);
                break;
            case SPELL_ULTHOK_VO_SLAY:
                Talk(SAY_WHISPER_SLAY, target);
                break;
            case SPELL_ULTHOK_VO_DEATH:
                Talk(SAY_WHISPER_DEATH, target);
                break;
            default:
                break;
        }

        if (spell->Id == SPELL_SQUEEZE)
            target->CastSpell(me, SPELL_SQUEEZE_RIDE_VEHICLE, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ROAR_EMOTE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                    events.ScheduleEvent(EVENT_READY_ULTHOK, 4s);
                    break;
                case EVENT_READY_ULTHOK:
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY_UNARMED);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    break;
                case EVENT_SQUEEZE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_SQUEEZE);
                    events.Repeat(20s);
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE);
                    events.Repeat(32s, 33s);
                    break;
                case EVENT_CURSE_OF_FATIGUE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        DoCast(target, SPELL_CURSE_OF_FATIGUE);
                    events.Repeat(18s, 23s);
                    break;
                case EVENT_DARK_FISSURE:
                    DoCastSelf(SPELL_DARK_FISSURE);
                    events.Repeat(20s, 23s);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

class spell_ulthok_dark_fissure : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (Unit* target = GetTarget())
        {
            uint32 triggerSpell = GetSpellInfo()->Effects[EFFECT_0].TriggerSpell;
            int32 radius = target->GetObjectScale() * 300;
            target->CastSpell(nullptr, triggerSpell, CastSpellExtraArgs(aurEff).SetOriginalCaster(target->GetGUID()).AddSpellMod(SPELLVALUE_RADIUS_MOD, radius));
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_ulthok_dark_fissure::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_commander_ulthok()
{
    RegisterThroneOfTheTidesCreatureAI(boss_commander_ulthok);
    RegisterSpellScript(spell_ulthok_dark_fissure);
}

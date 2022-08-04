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
#include "InstanceScript.h"
#include "magisters_terrace.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

enum Says
{
    // Kael'thas Sunstrider
    SAY_INTRO_1                 = 0,
    SAY_INTRO_2                 = 1,
    SAY_GRAVITY_LAPSE_1         = 2,
    SAY_GRAVITY_LAPSE_2         = 3,
    SAY_POWER_FEEDBACK          = 4,
    SAY_SUMMON_PHOENIX          = 5,
    SAY_ANNOUNCE_PYROBLAST      = 6,
    SAY_FLAME_STRIKE            = 7,
    SAY_DEATH                   = 8
};

enum Spells
{
    // Kael'thas Sunstrider
    SPELL_FIREBALL                              = 44189,
    SPELL_GRAVITY_LAPSE_CENTER_TELEPORT         = 44218,
    SPELL_GRAVITY_LAPSE_LEFT_TELEPORT           = 44219,
    SPELL_GRAVITY_LAPSE_FRONT_LEFT_TELEPORT     = 44220,
    SPELL_GRAVITY_LAPSE_FRONT_TELEPORT          = 44221,
    SPELL_GRAVITY_LAPSE_FRONT_RIGHT_TELEPORT    = 44222,
    SPELL_GRAVITY_LAPSE_RIGHT_TELEPORT          = 44223,
    SPELL_GRAVITY_LAPSE_INITIAL                 = 44224,
    SPELL_GRAVITY_LAPSE_FLY                     = 44227,
    SPELL_GRAVITY_LAPSE_BEAM_VISUAL_PERIODIC    = 44251,
    SPELL_SUMMON_ARCANE_SPHERE                  = 44265,
    SPELL_POWER_FEEDBACK                        = 44233,
    SPELL_FLAME_STRIKE                          = 46162,
    SPELL_SHOCK_BARRIER                         = 46165,
    SPELL_PYROBLAST                             = 36819,
    SPELL_PHOENIX                               = 44194,
    SPELL_EMOTE_TALK_EXCLAMATION                = 48348,
    SPELL_EMOTE_POINT                           = 48349,
    SPELL_EMOTE_ROAR                            = 48350,
    SPELL_CLEAR_FLIGHT                          = 44232,
    SPELL_QUITE_SUICIDE                         = 3617, // Serverside spell

    // Flame Strike
    SPELL_FLAME_STRIKE_DUMMY                    = 44191,
    SPELL_FLAME_STRIKE_DAMAGE                   = 44190,

    // Phoenix
    SPELL_REBIRTH                               = 44196,
    SPELL_BURN                                  = 44197,
    SPELL_EMBER_BLAST                           = 44199,
    SPELL_SUMMON_PHOENIX_EGG                    = 44195, // Serverside spell
    SPELL_FULL_HEAL                             = 17683
};

uint32 gravityLapseTeleportSpells[] =
{
    SPELL_GRAVITY_LAPSE_LEFT_TELEPORT,
    SPELL_GRAVITY_LAPSE_FRONT_LEFT_TELEPORT,
    SPELL_GRAVITY_LAPSE_FRONT_TELEPORT,
    SPELL_GRAVITY_LAPSE_FRONT_RIGHT_TELEPORT,
    SPELL_GRAVITY_LAPSE_RIGHT_TELEPORT
};

#define SPELL_GRAVITY_LAPSE_DAMAGE  RAID_MODE<uint32>(49887, 44226)

enum Events
{
    // Kael'thas Sunstrider
    EVENT_TALK_INTRO_1 = 1,
    EVENT_TALK_INTRO_2,
    EVENT_LAUGH_EMOTE,
    EVENT_FINISH_INTRO,
    EVENT_FIREBALL,
    EVENT_FLAME_STRIKE,
    EVENT_SHOCK_BARRIER,
    EVENT_PYROBLAST,
    EVENT_PHOENIX,
    EVENT_PREPARE_GRAVITY_LAPSE,
    EVENT_GRAVITY_LAPSE_CENTER_TELEPORT,
    EVENT_GRAVITY_LAPSE,
    EVENT_GRAVITY_LAPSE_BEAM_VISUAL_PERIODIC,
    EVENT_SUMMON_ARCANE_SPHERE,
    EVENT_POWER_FEEDBACK,
    EVENT_TALK_NEXT_GRAVITY_LAPSE,
    EVENT_EMOTE_TALK_EXCLAMATION,
    EVENT_EMOTE_POINT,
    EVENT_EMOTE_ROAR,
    EVENT_QUITE_SUICIDE,

    // Phoenix
    EVENT_ATTACK_PLAYERS,
    EVENT_HATCH_FROM_EGG,
    EVENT_REBIRTH,
    EVENT_PREPARE_REENGAGE
};

enum Phases
{
    PHASE_INTRO = 0,
    PHASE_ONE   = 1,
    PHASE_TWO   = 2,
    PHASE_OUTRO = 3
};

struct boss_felblood_kaelthas : public BossAI
{
    boss_felblood_kaelthas(Creature* creature) : BossAI(creature, DATA_KAELTHAS_SUNSTRIDER)
    {
        Initialize();
    }

    void Initialize()
    {
        _gravityLapseTargetCount = 0;
        _firstGravityLapse = true;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_FIREBALL, 1ms, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_FLAME_STRIKE, 44s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_PHOENIX, 12s, 0, PHASE_ONE);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SHOCK_BARRIER, 1min + 1s, 0, PHASE_ONE);
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        events.SetPhase(PHASE_INTRO);
    }

    void JustDied(Unit* /*killer*/) override
    {
        // No _JustDied() here because otherwise we would reset the events which will trigger the death sequence twice.
        instance->SetBossState(DATA_KAELTHAS_SUNSTRIDER, DONE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        DoCastAOE(SPELL_CLEAR_FLIGHT, true);
        _EnterEvadeMode();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // Checking for lethal damage first so we trigger the outro phase without triggering phase two in case of oneshot attacks
        if (damage >= me->GetHealth() && !events.IsInPhase(PHASE_OUTRO))
        {
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->InterruptNonMeleeSpells(true);
            me->RemoveAurasDueToSpell(SPELL_POWER_FEEDBACK);
            summons.DespawnAll();
            DoCastAOE(SPELL_CLEAR_FLIGHT);
            Talk(SAY_DEATH);
            events.SetPhase(PHASE_OUTRO);
            events.ScheduleEvent(EVENT_EMOTE_TALK_EXCLAMATION, 1s, 0, PHASE_OUTRO);
            events.ScheduleEvent(EVENT_EMOTE_POINT, 3s + 800ms, 0, PHASE_OUTRO);
            events.ScheduleEvent(EVENT_EMOTE_ROAR, 7s + 400ms, 0, PHASE_OUTRO);
            events.ScheduleEvent(EVENT_EMOTE_ROAR, 10s, 0, PHASE_OUTRO);
            events.ScheduleEvent(EVENT_QUITE_SUICIDE, 11s, 0, PHASE_OUTRO);
        }

        // Phase two checks. Skip phase two if we are in the outro already
        if (me->HealthBelowPctDamaged(50, damage) && !events.IsInPhase(PHASE_TWO) && !events.IsInPhase(PHASE_OUTRO))
        {
            events.SetPhase(PHASE_TWO);
            events.ScheduleEvent(EVENT_PREPARE_GRAVITY_LAPSE, 1ms, 0, PHASE_TWO);
        }

        // Kael'thas may only kill himself via Quite Suicide
        if (damage >= me->GetHealth() && attacker != me)
            damage = me->GetHealth() - 1;
    }

    void SetData(uint32 type, uint32 /*data*/) override
    {
        if (type == DATA_KAELTHAS_INTRO)
        {
            // skip the intro if Kael'thas is engaged already
            if (!events.IsInPhase(PHASE_INTRO))
                return;

            me->SetImmuneToPC(true);
            events.ScheduleEvent(EVENT_TALK_INTRO_1, 6s, 0, PHASE_INTRO);
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        Unit* unitTarget = target->ToUnit();
        if (!unitTarget)
            return;

        switch (spellInfo->Id)
        {
            case SPELL_GRAVITY_LAPSE_INITIAL:
            {
                DoCast(unitTarget, gravityLapseTeleportSpells[_gravityLapseTargetCount], true);
                uint32 gravityLapseDamageSpell = SPELL_GRAVITY_LAPSE_DAMAGE;
                target->m_Events.AddEventAtOffset([target, gravityLapseDamageSpell]()
                {
                    target->CastSpell(target, gravityLapseDamageSpell);
                    target->CastSpell(target, SPELL_GRAVITY_LAPSE_FLY);

                }, 400ms);
                _gravityLapseTargetCount++;
                break;
            }
            case SPELL_CLEAR_FLIGHT:
                unitTarget->RemoveAurasDueToSpell(SPELL_GRAVITY_LAPSE_FLY);
                unitTarget->RemoveAurasDueToSpell(SPELL_GRAVITY_LAPSE_DAMAGE);
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_ARCANE_SPHERE:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 70.0f, true))
                    summon->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                break;
            case NPC_FLAME_STRIKE:
                summon->CastSpell(summon, SPELL_FLAME_STRIKE_DUMMY);
                summon->DespawnOrUnsummon(15s);
                break;
            default:
                break;
        }
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
                case EVENT_TALK_INTRO_1:
                    Talk(SAY_INTRO_1);
                    me->SetEmoteState(EMOTE_STATE_TALK);
                    events.ScheduleEvent(EVENT_TALK_INTRO_2, 20s + 600ms, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_LAUGH_EMOTE, 15s + 600ms, 0, PHASE_INTRO);
                    break;
                case EVENT_TALK_INTRO_2:
                    Talk(SAY_INTRO_2);
                    events.ScheduleEvent(EVENT_FINISH_INTRO, 15s + 500ms, 0, PHASE_INTRO);
                    break;
                case EVENT_LAUGH_EMOTE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH_NO_SHEATHE);
                    break;
                case EVENT_FINISH_INTRO:
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    me->SetImmuneToPC(false);
                    break;
                case EVENT_FIREBALL:
                    DoCastVictim(SPELL_FIREBALL);
                    events.Repeat(2s + 500ms);
                    break;
                case EVENT_FLAME_STRIKE:
                    Talk(SAY_FLAME_STRIKE);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                        DoCast(target, SPELL_FLAME_STRIKE);
                    events.Repeat(44s);
                    break;
                case EVENT_SHOCK_BARRIER:
                    Talk(SAY_ANNOUNCE_PYROBLAST);
                    DoCastSelf(SPELL_SHOCK_BARRIER);
                    events.RescheduleEvent(EVENT_FIREBALL, 2s + 500ms, 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_PYROBLAST, 2s, 0, PHASE_ONE);
                    events.Repeat(1min);
                    break;
                case EVENT_PYROBLAST:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                        DoCast(target, SPELL_PYROBLAST);
                    break;
                case EVENT_PHOENIX:
                    Talk(SAY_SUMMON_PHOENIX);
                    DoCastSelf(SPELL_PHOENIX);
                    events.Repeat(45s);
                    break;
                case EVENT_PREPARE_GRAVITY_LAPSE:
                    Talk(_firstGravityLapse ? SAY_GRAVITY_LAPSE_1 : SAY_GRAVITY_LAPSE_2);
                    _firstGravityLapse = false;
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->GetMotionMaster()->Clear();
                    events.ScheduleEvent(EVENT_GRAVITY_LAPSE_CENTER_TELEPORT, 1s, 0, PHASE_TWO);
                    break;
                case EVENT_GRAVITY_LAPSE_CENTER_TELEPORT:
                    DoCastSelf(SPELL_GRAVITY_LAPSE_CENTER_TELEPORT);
                    events.ScheduleEvent(EVENT_GRAVITY_LAPSE, 1s, 0, PHASE_TWO);
                    break;
                case EVENT_GRAVITY_LAPSE:
                    _gravityLapseTargetCount = 0;
                    DoCastAOE(SPELL_GRAVITY_LAPSE_INITIAL);
                    events.ScheduleEvent(EVENT_SUMMON_ARCANE_SPHERE, 4s, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_GRAVITY_LAPSE_BEAM_VISUAL_PERIODIC, 5s, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_POWER_FEEDBACK, 35s, 0, PHASE_TWO);
                    break;
                case EVENT_GRAVITY_LAPSE_BEAM_VISUAL_PERIODIC:
                    DoCastAOE(SPELL_GRAVITY_LAPSE_BEAM_VISUAL_PERIODIC);
                    break;
                case EVENT_SUMMON_ARCANE_SPHERE:
                    for (uint8 i = 0; i < 3; i++)
                        DoCastSelf(SPELL_SUMMON_ARCANE_SPHERE, true);
                    break;
                case EVENT_POWER_FEEDBACK:
                    Talk(SAY_POWER_FEEDBACK);
                    DoCastAOE(SPELL_CLEAR_FLIGHT);
                    DoCastSelf(SPELL_POWER_FEEDBACK);
                    summons.DespawnEntry(NPC_ARCANE_SPHERE);
                    events.ScheduleEvent(EVENT_PREPARE_GRAVITY_LAPSE, 11s, 0, PHASE_TWO);
                    break;
                case EVENT_EMOTE_TALK_EXCLAMATION:
                    DoCastSelf(SPELL_EMOTE_TALK_EXCLAMATION);
                    break;
                case EVENT_EMOTE_POINT:
                    DoCastSelf(SPELL_EMOTE_POINT);
                    break;
                case EVENT_EMOTE_ROAR:
                    DoCastSelf(SPELL_EMOTE_ROAR);
                    break;
                case EVENT_QUITE_SUICIDE:
                    DoCastSelf(SPELL_QUITE_SUICIDE);
                    break;
                default:
                    break;
            }
        }
    }

private:
    uint8 _gravityLapseTargetCount;
    bool _firstGravityLapse;
};

struct npc_felblood_kaelthas_phoenix : public ScriptedAI
{
    npc_felblood_kaelthas_phoenix(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        _isInEgg = false;
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        DoZoneInCombat();
        DoCastSelf(SPELL_BURN);
        DoCastSelf(SPELL_REBIRTH);
        _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 2s);
    }

    void JustEngagedWith(Unit* /*who*/) override { }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            if (!_isInEgg)
            {
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->RemoveAllAuras();
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                DoCastSelf(SPELL_EMBER_BLAST);
                // DoCastSelf(SPELL_SUMMON_PHOENIX_EGG); -- We do a manual summon for now. Feel free to move it to spelleffect_dbc
                if (Creature* egg = DoSummon(NPC_PHOENIX_EGG, me->GetPosition(), 0s))
                {
                    if (Creature* kaelthas = _instance->GetCreature(DATA_KAELTHAS_SUNSTRIDER))
                    {
                        kaelthas->AI()->JustSummoned(egg);
                        _eggGUID = egg->GetGUID();
                    }
                }

                _events.ScheduleEvent(EVENT_HATCH_FROM_EGG, 15s);
                _isInEgg = true;
            }
            damage = me->GetHealth() - 1;
        }

    }

    void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
    {
        // Egg has been destroyed within 15 seconds so we lose the phoenix.
        me->DespawnOrUnsummon();
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
                case EVENT_ATTACK_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_HATCH_FROM_EGG:
                    if (Creature* egg = ObjectAccessor::GetCreature(*me, _eggGUID))
                        egg->DespawnOrUnsummon();
                    me->RemoveAllAuras();
                    _events.ScheduleEvent(EVENT_REBIRTH, 2s);
                    break;
                case EVENT_REBIRTH:
                    DoCastSelf(SPELL_REBIRTH);
                    _events.ScheduleEvent(EVENT_PREPARE_REENGAGE, 2s);
                    break;
                case EVENT_PREPARE_REENGAGE:
                    _isInEgg = false;
                    DoCastSelf(SPELL_FULL_HEAL);
                    DoCastSelf(SPELL_BURN);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 2s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    InstanceScript* _instance;
    EventMap _events;
    bool _isInEgg;
    ObjectGuid _eggGUID;
};

// 44191 - Flame Strike
class spell_felblood_kaelthas_flame_strike : public AuraScript
{
    PrepareAuraScript(spell_felblood_kaelthas_flame_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_STRIKE_DAMAGE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(target, SPELL_FLAME_STRIKE_DAMAGE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_felblood_kaelthas_flame_strike::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_felblood_kaelthas()
{
    RegisterMagistersTerraceCreatureAI(boss_felblood_kaelthas);
    RegisterMagistersTerraceCreatureAI(npc_felblood_kaelthas_phoenix);
    RegisterSpellScript(spell_felblood_kaelthas_flame_strike);
}

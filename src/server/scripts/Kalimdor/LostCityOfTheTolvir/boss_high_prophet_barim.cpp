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
#include "lost_city_of_the_tolvir.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum Spells
{
    // High Prophet Barim
    SPELL_FIFTY_LASHINGS                        = 82506,
    SPELL_PLAGUE_OF_AGES                        = 82622,
    SPELL_PLAGUE_OF_AGES_FIRST_LEAP             = 82637,
    SPELL_HEAVENS_FURY                          = 81939,
    SPELL_REPENTANCE                            = 82320,
    SPELL_REPENTANCE_PULL                       = 82168,
    SPELL_REPENTANCE_STUN                       = 81947,
    SPELL_REPENTANCE_KNOCKBACK                  = 82012,
    SPELL_REPENTANCE_PHASE_AURA                 = 82139,
    SPELL_WAIL_OF_DARKNESS                      = 82195,
    SPELL_BLAZE_OF_THE_HEAVENS                  = 91181,

    // Repentance
    SPELL_REPENTANCE_SCRIPT_1                   = 82009,
    SPELL_REPENTANCE_SCRIPT_2                   = 81960,
    SPELL_REPENTANCE_PULL_BACK                  = 82430,

    // Blaze of the Heavens (Summoner)
    SPELL_BLAZE_OF_THE_HEAVENS_GROUND_EFFECT    = 91179,
    SPELL_BLAZE_OF_THE_HEAVENS_SUMMON           = 91180,

    // Veil of Twilight (Summoner)
    SPELL_VEIL_OF_DARKNESS_GROUND_EFFECT        = 82197,
    SPELL_VEIL_OF_DARKNESS_SUMMON               = 82203,

    // Phoenixes
    SPELL_BIRTH                                 = 26586,

    // Blaze of the Heavens
    SPELL_BLAZE_OF_THE_HEAVENS_PERIODIC_AURA    = 95248,
    SPELL_BLAZE_OF_THE_HEAVENS_FLAME            = 91189,
    SPELL_TRANSFORM                             = 95276,

    // Harbinger of Darkness
    SPELL_WAIL_OF_DARKNESS_DAMAGE               = 82533,
    SPELL_SOUL_SEVER                            = 82255,
    SPELL_WAIL_OF_DARKNESS_END                  = 82425,

    // Soul Fragment
    SPELL_SOUL_SEVER_SCRIPT                     = 82220,
    SPELL_SOUL_FRAGMENT_DUMMY                   = 82224,
    SPELL_MERGED_SOULS                          = 82263
};

enum Events
{
    // High Prophet Barim
    EVENT_FIFTY_LASHINGS = 1,
    EVENT_PLAGUE_OF_AGES,
    EVENT_HEAVENS_FURY,
    EVENT_REPENTANCE,
    EVENT_REPENTANCE_PULL,
    EVENT_REPENTANCE_STUN,
    EVENT_REPENTANCE_KNOCKBACK,
    EVENT_BLAZE_OF_THE_HEAVENS,

    // Phoenix Summoner
    EVENT_GROUND_VISUAL,
    EVENT_SUMMON_PHOENIX,
    EVENT_REMOVE_ALL_AURAS,

    // Phoenix
    EVENT_ENGAGE_PLAYERS,
    EVENT_ENABLE_ATTACKS,

    // Blaze of the Heavens
    EVENT_SUMMON_FIRE_TRAIL,
    EVENT_CHECK_HEALTH,
    EVENT_TRANSFORMED,

    // Harbinger of Darkness
    EVENT_MAKE_AGGRESSIVE,
    EVENT_WAIL_OF_DARKNESS,
    EVENT_SOUL_SEVER,

    // Soul Fragment
    EVENT_MOVE_TO_HARBINGER,
    EVENT_CHECK_DISTANCE
};

enum Actions
{
    // High Prophet Barim
    ACTION_PULL_PLAYERS_BACK = 1,

    // Blaze of the Heavens
    ACTION_DISABLE_COMBAT = 1,
    ACTION_RESUME_COMBAT
};

enum Texts
{
    // High Prophet Barim
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_REPENTEANCE         = 2,
    SAY_DEATH               = 3,

    // Soul Fragment
    SAY_ANNOUNCE_MERGE_SOUL = 0
};

enum PhaseMisc
{
    PHASE_ID_REPENTANCE     = 173,
    PHASE_GROUP_ENCOUNTER_1 = 391
};

struct boss_high_prophet_barim : public BossAI
{
    boss_high_prophet_barim(Creature* creature) : BossAI(creature, DATA_HIGH_PROPHET_BARIM), _repentanceStarted(false) {}

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.ScheduleEvent(EVENT_FIFTY_LASHINGS, 8s);
        events.ScheduleEvent(EVENT_PLAGUE_OF_AGES, 8s);
        events.ScheduleEvent(EVENT_HEAVENS_FURY, 10s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_BLAZE_OF_THE_HEAVENS, 6s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);

        for (uint32 data : { DATA_BLAZE_OF_THE_HEAVENS, DATA_HARBINGER_OF_DARKNESS })
        {
            if (Creature* phoenix = instance->GetCreature(data))
            {
                if (phoenix->IsAIEnabled)
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, phoenix);
                    phoenix->DespawnOrUnsummon();
                }
            }
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        for (uint32 data : { DATA_BLAZE_OF_THE_HEAVENS, DATA_HARBINGER_OF_DARKNESS })
        {
            if (Creature* phoenix = instance->GetCreature(data))
            {
                if (phoenix->IsAIEnabled)
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, phoenix);
                    phoenix->DespawnOrUnsummon();
                }
            }
        }

        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_SEVER);
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !_repentanceStarted)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_REPENTANCE, 1ms);
            _repentanceStarted = true;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PULL_PLAYERS_BACK:
            {
                me->RemoveAurasDueToSpell(SPELL_REPENTANCE);
                me->SetReactState(REACT_AGGRESSIVE);
                summons.DespawnEntry(NPC_SOUL_FRAGMENT);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_SEVER);

                EntryCheckPredicate pred(NPC_REPENTANCE);
                summons.DoAction(ACTION_PULL_PLAYERS_BACK, pred);

                if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
                    if (blaze->IsAIEnabled)
                        blaze->AI()->DoAction(ACTION_RESUME_COMBAT);

                events.ScheduleEvent(EVENT_FIFTY_LASHINGS, 2s);
                events.ScheduleEvent(EVENT_PLAGUE_OF_AGES, 2s);
                events.ScheduleEvent(EVENT_HEAVENS_FURY, 3s + 500ms);
                break;
            }
            default:
                break;
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
                case EVENT_FIFTY_LASHINGS:
                    DoCastSelf(SPELL_FIFTY_LASHINGS);
                    events.Repeat(34s);
                    break;
                case EVENT_PLAGUE_OF_AGES:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.f, true, false))
                        DoCast(target, SPELL_PLAGUE_OF_AGES);
                    else
                        DoCastVictim(SPELL_PLAGUE_OF_AGES);
                    events.Repeat(25s);
                    break;
                case EVENT_HEAVENS_FURY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.f, true, false))
                        DoCast(target, SPELL_HEAVENS_FURY);
                    else
                        DoCastVictim(SPELL_HEAVENS_FURY);
                    events.Repeat(23s);
                    break;
                case EVENT_REPENTANCE:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_REPENTANCE);
                    events.ScheduleEvent(EVENT_REPENTANCE_PULL, 1s);

                    if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
                        if (blaze->IsAIEnabled)
                            blaze->AI()->DoAction(ACTION_DISABLE_COMBAT);
                    break;
                case EVENT_REPENTANCE_PULL:
                    Talk(SAY_REPENTEANCE);
                    DoCastSelf(SPELL_REPENTANCE_PULL);
                    events.ScheduleEvent(EVENT_REPENTANCE_STUN, 1s);
                    break;
                case EVENT_REPENTANCE_STUN:
                    DoCastAOE(SPELL_REPENTANCE_STUN);
                    events.ScheduleEvent(EVENT_REPENTANCE_KNOCKBACK, 6s);
                    break;
                case EVENT_REPENTANCE_KNOCKBACK:
                    DoCastAOE(SPELL_REPENTANCE_KNOCKBACK);
                    DoCastAOE(SPELL_REPENTANCE_PHASE_AURA);
                    DoCastSelf(SPELL_WAIL_OF_DARKNESS);

                    // The phoenix is in a passive state so he won't evade on his own in that state so we give him a little push here.
                    if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
                        if (blaze->IsAIEnabled && blaze->HasReactState(REACT_PASSIVE))
                            blaze->AI()->EnterEvadeMode();
                    break;
                case EVENT_BLAZE_OF_THE_HEAVENS:
                    DoCastSelf(SPELL_BLAZE_OF_THE_HEAVENS);
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
    bool _repentanceStarted;
};

// This npc is the copy of the player when he is being pulled into the shadow realm.
struct npc_barim_repentance : public NullCreatureAI
{
    npc_barim_repentance(Creature* creature) : NullCreatureAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* barim = instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
                barim->AI()->JustSummoned(me);

        PhasingHandler::AddPhaseGroup(me, PHASE_GROUP_ENCOUNTER_1, true);

        DoCastSelf(SPELL_REPENTANCE_SCRIPT_1);
        me->m_Events.AddEventAtOffset([&]()
        {
            DoCastSelf(SPELL_REPENTANCE_SCRIPT_2);
        }, 2s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_PULL_PLAYERS_BACK)
        {
            DoCastAOE(SPELL_REPENTANCE_PULL_BACK);
            me->DespawnOrUnsummon(1s + 500ms);
        }
    }
};

struct npc_barim_phoenix_summoner : public NullCreatureAI
{
    npc_barim_phoenix_summoner(Creature* creature) : NullCreatureAI(creature), _summonBlaze(me->GetEntry() == NPC_BLAZE_OF_THE_HEAVENS_SUMMONER) {}

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_GROUND_VISUAL, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GROUND_VISUAL:
                    DoCastSelf(_summonBlaze ? SPELL_BLAZE_OF_THE_HEAVENS_GROUND_EFFECT : SPELL_VEIL_OF_DARKNESS_GROUND_EFFECT);
                    _events.ScheduleEvent(EVENT_SUMMON_PHOENIX, 1s);
                    break;
                case EVENT_SUMMON_PHOENIX:
                    DoCastSelf(_summonBlaze ? SPELL_BLAZE_OF_THE_HEAVENS_SUMMON : SPELL_VEIL_OF_DARKNESS_SUMMON);
                    _events.ScheduleEvent(EVENT_REMOVE_ALL_AURAS, 5s);
                    break;
                case EVENT_REMOVE_ALL_AURAS:
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon(5s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    bool _summonBlaze;
};

struct npc_barim_harbinger_of_darkness : public ScriptedAI
{
    npc_barim_harbinger_of_darkness(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
        DoCastSelf(SPELL_BIRTH);
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
        _events.ScheduleEvent(EVENT_ENABLE_ATTACKS, 2s + 500ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DoCastAOE(SPELL_WAIL_OF_DARKNESS_END, true);
        me->DespawnOrUnsummon(1s + 500ms);

        if (Creature* barim = _instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
            barim->AI()->DoAction(ACTION_PULL_PLAYERS_BACK);
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
                case EVENT_ENABLE_ATTACKS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    _events.ScheduleEvent(EVENT_WAIL_OF_DARKNESS, 5s);
                    _events.ScheduleEvent(EVENT_SOUL_SEVER, 3s + 500ms);
                    break;
                case EVENT_WAIL_OF_DARKNESS:
                    DoCastAOE(SPELL_WAIL_OF_DARKNESS_DAMAGE);
                    _events.Repeat(2s + 500ms);
                    break;
                case EVENT_SOUL_SEVER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.f, true, false))
                        DoCast(target, SPELL_SOUL_SEVER);
                    else
                        DoCastVictim(SPELL_SOUL_SEVER);
                    _events.Repeat(11s);
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
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_barim_blaze_of_the_heavens : public ScriptedAI
{
    npc_barim_blaze_of_the_heavens(Creature* creature) : ScriptedAI(creature), _transformed(false)
    {
        me->SetReactState(REACT_PASSIVE);
        PhasingHandler::ResetPhaseShift(me);
    }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_BIRTH);
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1s);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _events.Reset();
    }

    void JustSummoned(Creature* summon) override
    {
        if (Creature* barim = _instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
            barim->AI()->JustSummoned(summon);

        PhasingHandler::AddPhaseGroup(summon, PHASE_GROUP_ENCOUNTER_1, false);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (damage >= me->GetHealth())
        {
            if (!_transformed)
            {
                DoCastSelf(SPELL_TRANSFORM);
                _events.CancelEvent(EVENT_SUMMON_FIRE_TRAIL);
                me->RemoveAurasDueToSpell(SPELL_BLAZE_OF_THE_HEAVENS_PERIODIC_AURA);
                _transformed = true;
            }

            // The Blaze of the Heavens cannot die
            damage = me->GetHealth() - 1;
        }
    }

    void HealReceived(Unit* /*healer*/, uint32& heal) override
    {
        if (me->HealthAbovePctHealed(99, heal) && _transformed)
        {
            me->RemoveAurasDueToSpell(SPELL_TRANSFORM);
            DoCastSelf(SPELL_BIRTH);
            _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1s);
            _transformed = false;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DISABLE_COMBAT:
                me->SetHomePosition(me->GetPosition());
                me->AttackStop();
                if (!_transformed)
                    me->SetReactState(REACT_PASSIVE);
                _events.CancelEvent(EVENT_SUMMON_FIRE_TRAIL);
                me->RemoveAurasDueToSpell(SPELL_BLAZE_OF_THE_HEAVENS_PERIODIC_AURA);
                break;
            case ACTION_RESUME_COMBAT:
                _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1ms);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_transformed)
            UpdateVictim();

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    DoZoneInCombat();
                    _events.ScheduleEvent(EVENT_ENABLE_ATTACKS, 500ms);
                    break;
                case EVENT_ENABLE_ATTACKS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_BLAZE_OF_THE_HEAVENS_PERIODIC_AURA);
                    _events.ScheduleEvent(EVENT_SUMMON_FIRE_TRAIL, 1s);
                    break;
                case EVENT_SUMMON_FIRE_TRAIL:
                    DoCastSelf(SPELL_BLAZE_OF_THE_HEAVENS_FLAME);
                    _events.Repeat(5s, 6s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _transformed;
};

struct npc_barim_soul_fragment : public NullCreatureAI
{
    npc_barim_soul_fragment(Creature* creature) : NullCreatureAI(creature) {}

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SOUL_SEVER_SCRIPT);
        DoCastSelf(SPELL_REPENTANCE_SCRIPT_2);
        DoCastAOE(SPELL_SOUL_FRAGMENT_DUMMY);
        _events.ScheduleEvent(EVENT_MOVE_TO_HARBINGER, 5s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_HARBINGER:
                    if (Creature* harbinger = _instance->GetCreature(DATA_HARBINGER_OF_DARKNESS))
                    {
                        me->GetMotionMaster()->MovePoint(0, harbinger->GetPosition());
                        _events.ScheduleEvent(EVENT_CHECK_DISTANCE, 1s);
                    }
                    break;
                case EVENT_CHECK_DISTANCE:
                    if (me->FindNearestCreature(NPC_HARBINGER_OF_DARKNESS, 0.3f, true))
                    {
                        Talk(SAY_ANNOUNCE_MERGE_SOUL);
                        me->CastStop();
                        DoCastAOE(SPELL_MERGED_SOULS, true);
                        me->DespawnOrUnsummon(1s);
                    }
                    else
                    {
                        if (Creature* harbinger = _instance->GetCreature(DATA_HARBINGER_OF_DARKNESS))
                            me->GetMotionMaster()->MovePoint(0, harbinger->GetPosition());
                        _events.Repeat(1s);
                    }
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

class spell_barim_plague_of_ages : public SpellScript
{
public:
    spell_barim_plague_of_ages(std::initializer_list<uint32> excludeSpellIds) : _excludeSpellIds(excludeSpellIds) {}

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([&](WorldObject const* target)
        {
            Unit const* unit = target->ToUnit();
            if (!unit)
                return true;

            for (uint32 spellId : _excludeSpellIds)
                if (unit->HasAura(sSpellMgr->GetSpellIdForDifficulty(spellId, GetCaster())))
                    return true;

            return false;
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_barim_plague_of_ages::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
    }
protected:
    std::initializer_list<uint32> _excludeSpellIds;
};

class spell_barim_repentance_script : public SpellScript
{
    void EffectScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* playerTarget = GetHitPlayer())
            playerTarget->CastSpell(GetCaster(), GetSpellInfo()->Effects[EFFECT_0].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_barim_repentance_script::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_barim_repentance_pull : public SpellScript
{
    void HandPullEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Unit* playerTarget = GetHitPlayer();
        Unit* barim = GetCaster();

        if (!barim || !playerTarget)
            return;

        // Calculate our own destination since players should land in front of Barim instead of inside him
        Position pos;
        float angle = barim->GetAngle(playerTarget);
        float distance = barim->GetCombatReach() * 2;
        pos.m_positionX = barim->GetPositionX() + cos(angle) * distance;
        pos.m_positionY = barim->GetPositionY() + sin(angle) * distance;
        pos.m_positionZ = barim->GetPositionZ();

        float speedXY = float(GetSpellInfo()->Effects[EFFECT_0].MiscValue) * 0.1f;
        float speedZ = playerTarget->GetDistance(pos) / speedXY * 0.5f * Movement::gravity;
        playerTarget->GetMotionMaster()->MoveJump(pos, speedXY, speedZ);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_barim_repentance_pull::HandPullEffect, EFFECT_0, SPELL_EFFECT_PULL_TOWARDS);
    }
};

class spell_barim_repentance_stun : public AuraScript
{
    void DisablePeriodic(AuraEffect const* aurEff)
    {
        // We only want one copy being summoned
        const_cast<AuraEffect*>(aurEff)->SetPeriodic(false);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_barim_repentance_stun::DisablePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_high_prophet_barim()
{
    RegisterLostCityOfTheTolvirAI(boss_high_prophet_barim);
    RegisterLostCityOfTheTolvirAI(npc_barim_repentance);
    RegisterLostCityOfTheTolvirAI(npc_barim_phoenix_summoner);
    RegisterLostCityOfTheTolvirAI(npc_barim_harbinger_of_darkness);
    RegisterLostCityOfTheTolvirAI(npc_barim_blaze_of_the_heavens);
    RegisterLostCityOfTheTolvirAI(npc_barim_soul_fragment);
    RegisterSpellScriptWithArgs(spell_barim_plague_of_ages, "spell_barim_plague_of_ages_first", std::initializer_list<uint32>({ SPELL_PLAGUE_OF_AGES }));
    RegisterSpellScriptWithArgs(spell_barim_plague_of_ages, "spell_barim_plague_of_ages_second", std::initializer_list<uint32>({ SPELL_PLAGUE_OF_AGES, SPELL_PLAGUE_OF_AGES_FIRST_LEAP }));
    RegisterSpellScript(spell_barim_repentance_script);
    RegisterSpellScript(spell_barim_repentance_pull);
    RegisterSpellScript(spell_barim_repentance_stun);
}

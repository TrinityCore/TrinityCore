/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ulduar.h"

enum AuriayaSpells
{
    // Auriaya
    SPELL_SENTINEL_BLAST                    = 64389,
    SPELL_SONIC_SCREECH                     = 64422,
    SPELL_TERRIFYING_SCREECH                = 64386,
    SPELL_SUMMON_SWARMING_GUARDIAN          = 64396,
    SPELL_ACTIVATE_DEFENDER                 = 64449,
    SPELL_DEFENDER_TRIGGER                  = 64448,
    SPELL_BERSERK                           = 47008,
    SPELL_INSTAKILL_ARACHNOPOD              = 64900,

    // Feral Defender
    SPELL_FERAL_RUSH                        = 64496,
    SPELL_FERAL_RUSH_2                      = 64489,
    SPELL_FERAL_POUNCE                      = 64478,
    SPELL_SUMMON_ESSENCE                    = 64457,
    SPELL_FERAL_ESSENCE                     = 64455,
    SPELL_SHADOW_PAWS                       = 64479,
    SPELL_REDUCE_CRITCAL                    = 64481,
    SPELL_RANDOM_AGRO_PERIODIC              = 61906,
    SPELL_PERMANENT_FEIGN_DEATH             = 58951,
    SPELL_FERAL_ESSENCE_APPLICATION_REMOVAL = 64456,
    SPELL_CLEAR_ALL_DEBUFFS                 = 34098,
    SPELL_DROWNED_STATE                     = 64462,
    SPELL_FULL_HEAL                         = 64460,

    // Seeping Essence Stalker
    SPELL_SEEPING_ESSENCE                   = 64458,

    // Sanctum Sentry
    SPELL_SAVAGE_POUNCE                     = 64666,
    SPELL_RIP_FLESH                         = 64375,
    SPELL_STRENGHT_OF_THE_PACK              = 64369,

    // Swarming Guardian
    SPELL_AGRO_CREATOR                      = 63709,
    SPELL_POUNCE                            = 64399
};

enum AuriayaEvents
{
    // Auriaya
    EVENT_SONIC_SCREECH = 1,
    EVENT_BLAST,
    EVENT_TERRIFYING_SCREECH,
    EVENT_SWARNING_GUARDIAN,
    EVENT_SUMMON_DEFENDER,
    EVENT_ACTIVATE_DEFENDER,
    EVENT_BERSERK,

    // Sanctum Sentry
    EVENT_RIP,
    EVENT_SAVAGE_POUNCE,

    // Feral Defender
    EVENT_FERAL_POUNCE,
    EVENT_RUSH,
    EVENT_START_COMBAT,
    EVENT_RESPAWN_DEFENDER,
    EVENT_RESPAWN_DEFENDER_2,
    EVENT_RESPAWN_DEFENDER_3
};

enum AuriayaYells
{
    SAY_AGGRO      = 0,
    SAY_SLAY       = 1,
    SAY_BERSERK    = 2,
    EMOTE_FEAR     = 3,
    EMOTE_DEFENDER = 4
};

enum AuriayaActions
{
    ACTION_CRAZY_CAT_LADY = 0,
    ACTION_DEFENDER_DIED
};

enum Misc
{
    DATA_NINE_LIVES       = 30763077,
    DATA_CRAZY_CAT_LADY   = 30063007,
    PHASE_NONE            = 1,
    PHASE_COMBAT          = 2,
    SUMMON_GROUP_10_MAN   = 1,
    SUMMON_GROUP_25_MAN   = 2,
    AURIAYA_DEATH_SOUNDID = 15476,
    NPC_SANCTUM_SENTRY    = 34014
};

class CatsTargetSelector
{
public:
    CatsTargetSelector(Unit const* unit, float minDist, float maxDist) : _me(unit), _minDist(minDist), _maxDist(maxDist) { }

    bool operator()(Unit* unit) const
    {
        float dist = _me->GetDistance(unit);
        return unit->GetTypeId() == TYPEID_PLAYER && dist >= _minDist && dist < _maxDist && _me->IsWithinLOSInMap(unit);
    }

private:
    Unit const* _me;
    float _minDist;
    float _maxDist;
};

struct boss_auriaya : public BossAI
{
    boss_auriaya(Creature* creature) : BossAI(creature, BOSS_AURIAYA), _crazyCatLady(true), _nineLives(false) { }

    void Reset() override
    {
        _Reset();
        _crazyCatLady = true;
        _nineLives = false;
        HandleCats(true);
    }

    void HandleCats(bool isResetting)
    {
        std::list<Creature*> catList;
        me->GetCreatureListWithEntryInGrid(catList, NPC_SANCTUM_SENTRY, 500.0f);
        for (std::list<Creature*>::const_iterator itr = catList.begin(); itr != catList.end(); ++itr)
        {
            if (isResetting)
                (*itr)->Respawn();
            else
                (*itr)->DespawnOrUnsummon();
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_SONIC_SCREECH, Seconds(48));
        events.ScheduleEvent(EVENT_TERRIFYING_SCREECH, Seconds(38));
        events.ScheduleEvent(EVENT_SUMMON_DEFENDER, Seconds(60));
        events.ScheduleEvent(EVENT_SWARNING_GUARDIAN, Seconds(51));
        events.ScheduleEvent(EVENT_BERSERK, Minutes(10));
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && roll_chance_i(50))
            Talk(SAY_SLAY);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CRAZY_CAT_LADY:
                _crazyCatLady = false;
                break;
            case ACTION_DEFENDER_DIED:
                _nineLives = true;
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_NINE_LIVES:
                return _nineLives ? 1 : 0;
            case DATA_CRAZY_CAT_LADY:
                return _crazyCatLady ? 1 : 0;
            default:
                return 0;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoPlaySoundToSet(me, AURIAYA_DEATH_SOUNDID);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        HandleCats(false);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade(Seconds(5));
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
                case EVENT_SONIC_SCREECH:
                    DoCastVictim(SPELL_SONIC_SCREECH);
                    events.Repeat(Seconds(22), Seconds(30));
                    break;
                case EVENT_TERRIFYING_SCREECH:
                    Talk(EMOTE_FEAR);
                    DoCastSelf(SPELL_TERRIFYING_SCREECH);
                    events.ScheduleEvent(EVENT_BLAST, Milliseconds(1));
                    events.Repeat(Seconds(36), Seconds(45));
                    break;
                case EVENT_BLAST:
                    DoCastAOE(SPELL_SENTINEL_BLAST);
                    break;
                case EVENT_SUMMON_DEFENDER:
                    Talk(EMOTE_DEFENDER);
                    DoCastSelf(SPELL_DEFENDER_TRIGGER);
                    events.ScheduleEvent(EVENT_ACTIVATE_DEFENDER, Seconds(2));
                    break;
                case EVENT_ACTIVATE_DEFENDER:
                    DoCastSelf(SPELL_ACTIVATE_DEFENDER);
                    break;
                case EVENT_SWARNING_GUARDIAN:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                        DoCast(target, SPELL_SUMMON_SWARMING_GUARDIAN);
                    events.Repeat(Seconds(25), Seconds(45));
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    Talk(SAY_BERSERK);
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
    bool _crazyCatLady;
    bool _nineLives;
};

struct npc_sanctum_sentry : public ScriptedAI
{
    npc_sanctum_sentry(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        DoCastSelf(SPELL_STRENGHT_OF_THE_PACK, true);
        me->SetWalk(true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_RIP, Seconds(6));
        _events.ScheduleEvent(EVENT_SAVAGE_POUNCE, Milliseconds(1));
        me->SetWalk(false);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* auriaya = _instance->GetCreature(BOSS_AURIAYA))
            auriaya->AI()->DoAction(ACTION_CRAZY_CAT_LADY);
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
                case EVENT_RIP:
                    DoCastVictim(SPELL_RIP_FLESH);
                    _events.Repeat(Seconds(10), Seconds(12));
                    break;
                case EVENT_SAVAGE_POUNCE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, CatsTargetSelector(me, 10.0f, 15.0f)))
                    {
                        DoCast(target, SPELL_SAVAGE_POUNCE);
                        _events.Repeat(Seconds(10));
                        break;
                    }
                    _events.Repeat(Seconds(1));
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
};

struct npc_feral_defender : public ScriptedAI
{
    npc_feral_defender(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_SHADOW_PAWS, true);
        DoCastSelf(SPELL_REDUCE_CRITCAL, true);
        me->SetAuraStack(SPELL_FERAL_ESSENCE, me, 8);
        DoCastSelf(SPELL_RANDOM_AGRO_PERIODIC, true);
        _events.SetPhase(PHASE_NONE);
        _events.ScheduleEvent(EVENT_START_COMBAT, Seconds(1));

        if (Creature* auriaya = _instance->GetCreature(BOSS_AURIAYA))
            auriaya->AI()->JustSummoned(me);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !_events.IsInPhase(PHASE_NONE))
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_COMBAT:
                    _events.SetPhase(PHASE_COMBAT);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        AttackStart(target);
                    _events.ScheduleEvent(EVENT_RUSH, Seconds(1));
                    break;
                case EVENT_RUSH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, CatsTargetSelector(me, 10.0f, 11.0f)))
                    {
                        DoCast(target, SPELL_FERAL_RUSH, true);
                        _events.Repeat(Seconds(5));
                        break;
                    }
                    _events.Repeat(Seconds(1));
                    break;
                case EVENT_RESPAWN_DEFENDER:
                    me->SetDisableGravity(true);
                    me->SetHover(true);
                    DoCastSelf(SPELL_DROWNED_STATE, true);
                    _events.ScheduleEvent(EVENT_RESPAWN_DEFENDER_2, Seconds(3));
                    _events.ScheduleEvent(EVENT_RESPAWN_DEFENDER_3, Seconds(5));
                    break;
                case EVENT_RESPAWN_DEFENDER_2:
                    me->RemoveAurasDueToSpell(SPELL_DROWNED_STATE);
                    break;
                case EVENT_RESPAWN_DEFENDER_3:
                    me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                    DoCastSelf(SPELL_FULL_HEAL, true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetDisableGravity(false);
                    me->SetHover(false);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        AttackStart(target);
                    _events.ScheduleEvent(EVENT_RUSH, Seconds(1));
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
    {
        if (damage >= me->GetHealth() && me->HasAura(SPELL_FERAL_ESSENCE))
        {
            damage = 0;
            if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
            {
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH, true);
                DoCastSelf(SPELL_FERAL_ESSENCE_APPLICATION_REMOVAL, true);
                DoCastSelf(SPELL_SUMMON_ESSENCE, true);
                DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS, true);
                ResetThreatList();
                _events.ScheduleEvent(EVENT_RESPAWN_DEFENDER, Seconds(30));
                _events.CancelEvent(EVENT_RUSH);
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_SUMMON_ESSENCE, true);
        if (Creature* auriaya = _instance->GetCreature(BOSS_AURIAYA))
            auriaya->AI()->DoAction(ACTION_DEFENDER_DIED);
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_swarming_guardian : public ScriptedAI
{
    npc_swarming_guardian(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _scheduler.Schedule(Seconds(1), [this](TaskContext /*context*/)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            DoCastSelf(SPELL_AGRO_CREATOR);
        });
        if (Creature* auriaya = _instance->GetCreature(BOSS_AURIAYA))
            auriaya->AI()->JustSummoned(me);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

struct npc_seeping_essence_stalker : public ScriptedAI
{
    npc_seeping_essence_stalker(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        DoCastSelf(SPELL_SEEPING_ESSENCE);
        if (Creature* auriaya = _instance->GetCreature(BOSS_AURIAYA))
            auriaya->AI()->JustSummoned(me);
    }

    void UpdateAI(uint32 /*diff*/) override { }

private:
    InstanceScript* _instance;
};

// 64381 - Strength of the Pack
class spell_auriaya_strenght_of_the_pack : public SpellScript
{
    PrepareSpellScript(spell_auriaya_strenght_of_the_pack);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if([](WorldObject* obj) { return obj->GetEntry() != NPC_SANCTUM_SENTRY; });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_auriaya_strenght_of_the_pack::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// 64392, 64679 - Sentinel Blast
class spell_auriaya_sentinel_blast : public SpellScript
{
    PrepareSpellScript(spell_auriaya_sentinel_blast);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if(PlayerOrPetCheck());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_auriaya_sentinel_blast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_auriaya_sentinel_blast::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 63709 - Aggro Creator
class spell_auriaya_agro_creator : public SpellScript
{
    PrepareSpellScript(spell_auriaya_agro_creator);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POUNCE });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsAIEnabled() || caster->HasReactState(REACT_PASSIVE))
            return;

        if (Unit* target = caster->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, CatsTargetSelector(caster, 5.0f, 10.0f)))
        {
            caster->CastSpell(target, SPELL_POUNCE, true);
            caster->GetThreatManager().AddThreat(target, 50000000.0f, nullptr, true);
            caster->AI()->AttackStart(target);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_auriaya_agro_creator::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 61906 - Random Aggro Periodic (5 sec)
class spell_auriaya_random_agro_periodic : public AuraScript
{
    PrepareAuraScript(spell_auriaya_random_agro_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FERAL_POUNCE });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Creature* owner = GetUnitOwner()->ToCreature();
        if (!owner || !owner->IsAIEnabled() || owner->HasReactState(REACT_PASSIVE))
            return;

        bool farTarget = true;
        Unit* target = owner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, CatsTargetSelector(owner, 15.0f, 25.0f));
        if (!target)
        {
            farTarget = false;
            target = owner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0);
        }

        if (!target)
            return;

        owner->GetThreatManager().AddThreat(target, 3000000.0f, nullptr, true);
        if (farTarget)
            owner->CastSpell(target, SPELL_FERAL_POUNCE, true);
        owner->AI()->AttackStart(target);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_auriaya_random_agro_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 64456 - Feral Essence Application Removal
class spell_auriaya_feral_essence_removal : public SpellScript
{
    PrepareSpellScript(spell_auriaya_feral_essence_removal);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FERAL_ESSENCE });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Aura* essence = GetCaster()->GetAura(SPELL_FERAL_ESSENCE))
            essence->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_auriaya_feral_essence_removal::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 64496, 64674 - Feral Rush
class spell_auriaya_feral_rush : public SpellScript
{
    PrepareSpellScript(spell_auriaya_feral_rush);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FERAL_RUSH_2 });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_FERAL_RUSH_2, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_auriaya_feral_rush::HandleOnHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class achievement_nine_lives : public AchievementCriteriaScript
{
    public:
        achievement_nine_lives() : AchievementCriteriaScript("achievement_nine_lives") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* auriaya = target->ToCreature())
                if (auriaya->AI()->GetData(DATA_NINE_LIVES))
                    return true;

            return false;
        }
};

class achievement_crazy_cat_lady : public AchievementCriteriaScript
{
    public:
        achievement_crazy_cat_lady() : AchievementCriteriaScript("achievement_crazy_cat_lady") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* auriaya = target->ToCreature())
                if (auriaya->AI()->GetData(DATA_CRAZY_CAT_LADY))
                    return true;

            return false;
        }
};

void AddSC_boss_auriaya()
{
    RegisterUlduarCreatureAI(boss_auriaya);
    RegisterUlduarCreatureAI(npc_feral_defender);
    RegisterUlduarCreatureAI(npc_sanctum_sentry);
    RegisterUlduarCreatureAI(npc_swarming_guardian);
    RegisterUlduarCreatureAI(npc_seeping_essence_stalker);
    RegisterSpellScript(spell_auriaya_strenght_of_the_pack);
    RegisterSpellScript(spell_auriaya_sentinel_blast);
    RegisterSpellScript(spell_auriaya_agro_creator);
    RegisterAuraScript(spell_auriaya_random_agro_periodic);
    RegisterSpellScript(spell_auriaya_feral_essence_removal);
    RegisterSpellScript(spell_auriaya_feral_rush);
    new achievement_nine_lives();
    new achievement_crazy_cat_lady();
}

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
#include "halls_of_stone.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum Texts
{
    SAY_AGGRO                            = 0,
    SAY_SLAY                             = 1,
    SAY_DEATH                            = 2,
    EMOTE_FRENZY                         = 3
};

enum Spells
{
    SPELL_LIGHTNING_RING_1               = 50840,
    SPELL_LIGHTNING_RING_2               = 51849,
    SPELL_STATIC_CHARGE                  = 50834,
    SPELL_CHAIN_LIGHTNING                = 50830,
    SPELL_LIGHTNING_SHIELD               = 50831,
    SPELL_FRENZY                         = 28747,

    SPELL_SUMMON_IRON_DWARF_PERIODIC     = 50789,   // 59860 not used
    SPELL_SUMMON_IRON_DWARF_1            = 50790,
    SPELL_SUMMON_IRON_DWARF_2            = 50791,
    SPELL_SUMMON_IRON_TROGG_PERIODIC     = 50792,
    SPELL_SUMMON_IRON_TROGG_1            = 50793,
    SPELL_SUMMON_IRON_TROGG_2            = 50794,
    SPELL_SUMMON_MALFORMED_OOZE_PERIODIC = 50801,
    SPELL_SUMMON_MALFORMED_OOZE_1        = 50802,
    SPELL_SUMMON_MALFORMED_OOZE_2        = 50803,
    SPELL_SUMMON_EARTHEN_DWARF_PERIODIC  = 50824,
    SPELL_SUMMON_EARTHEN_DWARF_1         = 50825,
    SPELL_SUMMON_EARTHEN_DWARF_2         = 50826,

    // Malformed Ooze
    SPELL_OOZE_COMBINE_PERIODIC          = 50741,
    SPELL_OOZE_COMBINE_EFFECT            = 50742,
    SPELL_SUMMON_IRON_SLUDGE             = 50747,

    // Iron Sludge
    SPELL_IRON_SLUDGE_SPAWN_VISUAL       = 50777,
    SPELL_TOXIC_VOLLEY                   = 50838
};

enum Creatures
{
    NPC_FORGED_IRON_TROGG                = 27979,
    NPC_FORGED_IRON_DWARF                = 27982,
    NPC_EARTHEN_DWARF                    = 27980
};

enum Misc
{
    POINT_CENTER                         = 0,
    POINT_COMBINE                        = 1,

    ACTION_SLUDGE_DEAD                   = 1,
    DATA_ABUSE_THE_OOZE                  = 2
};

enum Events
{
    EVENT_CHAIN_LIGHTNING                = 1,
    EVENT_LIGHTNING_SHIELD,
    EVENT_STATIC_CHARGE,
    EVENT_LIGHTNING_RING_1,
    EVENT_LIGHTNING_RING_2,
    EVENT_FRENZY
};

Position const CenterPoint = { 1293.8799f, 666.942f, 189.60754f, 0.0f };

struct boss_sjonnir : public BossAI
{
    boss_sjonnir(Creature* creature) : BossAI(creature, DATA_SJONNIR),
        _sludgesKilled(0), _summonsTroggs(false), _summonsOozes(false), _summonsDwarfs(false), _frenzied(false) { }

    void JustEngagedWith(Unit* who) override
    {
        if (!instance->CheckRequiredBosses(DATA_SJONNIR, who->ToPlayer()))
        {
            EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
            return;
        }

        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_SUMMON_IRON_DWARF_PERIODIC);

        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 10s, 15s);
        events.ScheduleEvent(EVENT_STATIC_CHARGE, 15s, 20s);
        events.ScheduleEvent(EVENT_LIGHTNING_RING_1, 30s);
        /// @todo: Schedule both in combat and out of combat
        events.ScheduleEvent(EVENT_LIGHTNING_SHIELD, 5s, 15s);
    }

    void JustSummoned(Creature* summoned) override
    {
        switch (summoned->GetEntry())
        {
            case NPC_FORGED_IRON_DWARF:
            case NPC_FORGED_IRON_TROGG:
                // AttackStart(me->GetVictim()) does not work in case of very first spawn
                if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat))
                    summoned->AI()->AttackStart(target);
                break;
            case NPC_EARTHEN_DWARF:
                summoned->AI()->AttackStart(me);
                break;
        }
        summons.Summon(summoned);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(75, damage) && !_summonsTroggs)
        {
            _summonsTroggs = true;
            me->RemoveAurasDueToSpell(SPELL_SUMMON_IRON_DWARF_PERIODIC);
            DoCastSelf(SPELL_SUMMON_IRON_TROGG_PERIODIC, true);
        }

        if (me->HealthBelowPctDamaged(50, damage) && !_summonsOozes)
        {
            _summonsOozes = true;
            me->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_SUMMON_IRON_TROGG_PERIODIC, me));
            DoCastSelf(SPELL_SUMMON_MALFORMED_OOZE_PERIODIC, true);
        }

        if (me->HealthBelowPctDamaged(25, damage) && !_summonsDwarfs)
        {
            _summonsDwarfs = true;
            me->RemoveAurasDueToSpell(sSpellMgr->GetSpellIdForDifficulty(SPELL_SUMMON_MALFORMED_OOZE_PERIODIC, me));
            DoCastSelf(SPELL_SUMMON_EARTHEN_DWARF_PERIODIC, true);
        }

        if (me->HealthBelowPctDamaged(20, damage) && !_frenzied)
        {
            _frenzied = true;
            // Old removed, more powerful added
            events.CancelEvent(EVENT_LIGHTNING_RING_1);
            events.ScheduleEvent(EVENT_FRENZY, 0s);
            events.ScheduleEvent(EVENT_LIGHTNING_RING_2, 0s);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        /// @todo: Despawn Brann too but respawn his pre-fight version (https://www.youtube.com/watch?v=hxAxbjGfuDw)
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SLUDGE_DEAD)
            ++_sludgesKilled;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ABUSE_THE_OOZE)
            return _sludgesKilled;

        return 0;
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
                case EVENT_CHAIN_LIGHTNING:
                    DoCastVictim(SPELL_CHAIN_LIGHTNING);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_LIGHTNING_SHIELD:
                    if (!me->HasAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_LIGHTNING_SHIELD, me)))
                        DoCastSelf(SPELL_LIGHTNING_SHIELD);
                    events.Repeat(5s, 15s);
                    break;
                case EVENT_STATIC_CHARGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true, true))
                        DoCast(target, SPELL_STATIC_CHARGE);
                    events.Repeat(20s, 27s);
                    break;
                case EVENT_LIGHTNING_RING_1:
                    DoCastSelf(SPELL_LIGHTNING_RING_1);
                    events.Repeat(50s);
                    break;
                case EVENT_LIGHTNING_RING_2:
                    DoCastSelf(SPELL_LIGHTNING_RING_2);
                    events.Repeat(15s);
                    break;
                case EVENT_FRENZY:
                    Talk(EMOTE_FRENZY);
                    DoCastSelf(SPELL_FRENZY);
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
    uint8 _sludgesKilled;
    bool _summonsTroggs;
    bool _summonsOozes;
    bool _summonsDwarfs;
    bool _frenzied;
};

struct npc_malformed_ooze : public ScriptedAI
{
    npc_malformed_ooze(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePoint(POINT_CENTER, CenterPoint);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_CENTER)
        {
            DoCastSelf(SPELL_OOZE_COMBINE_PERIODIC);
            me->GetMotionMaster()->MoveRandom(10);
        }
    }

    /* This is far from correct implementation. Once ooze reaches center point, it casts periodic aura. When spell hits another ooze, both
    caster and target removes periodic aura and caster starts moving to target. Target does not stop random movement. Once caster is close
    enough to target, caster casts a spell to combine with target. Target despawns instantly, caster despawns after 1sec.

    Since target does not stop random movement, that causes problems because combine spell is used when oozes are close enough to each other
    but with current implementation it takes too much time to reach target, as result there may be too much oozes trying to combine at
    the same time.
    Increasing radius at which combine spell can be used or trying to change the way oozes chases target only creates more problems because
    combine spell may target not required target but just ooze which was closer to caster. That leaves multiple spawns which can't combine
    anymore since combining process was started(auras were removed) but wasn't finished sucessfully

    Currently target is forced to stop random movement and caster just casts spell when is close enough to target. Spells has additional
    conditions in DB. That makes oozes combine every time sucessfully but not too fast and give players more time too kill sludges
    Ideally both spells should be scripted, filtering targets(if possible) and casting spell on target which was stored previously may look
    overcomplicated but saves from casting spell on wrong target. Or maybe solving the problem with moving to stored target will be enough */
    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        Creature* creatureTarget = target->ToCreature();
        if (!creatureTarget)
            return;

        switch (spellInfo->Id)
        {
            case SPELL_OOZE_COMBINE_EFFECT:
                _combineTarget = creatureTarget->GetGUID();
                me->RemoveAurasDueToSpell(SPELL_OOZE_COMBINE_PERIODIC);
                creatureTarget->RemoveAurasDueToSpell(SPELL_OOZE_COMBINE_PERIODIC);
                creatureTarget->GetMotionMaster()->MoveIdle();
                me->GetMotionMaster()->MoveIdle();
                me->GetMotionMaster()->MovePoint(POINT_COMBINE, creatureTarget->GetPosition());

                _scheduler.Schedule(1s, [this](TaskContext task)
                {
                    Creature* combineTarget = ObjectAccessor::GetCreature(*me, _combineTarget);
                    // Completely unclear what should happen in this case or in case when caster dies
                    if (!combineTarget || !combineTarget->IsAlive())
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }

                    if (me->GetExactDist2d(combineTarget) <= 0.1f)
                        DoCast(combineTarget, SPELL_SUMMON_IRON_SLUDGE);
                    else
                    {
                        me->GetMotionMaster()->MovePoint(POINT_COMBINE, combineTarget->GetPosition());
                        task.Repeat();
                    }
                });
                break;
            case SPELL_SUMMON_IRON_SLUDGE:
                creatureTarget->DespawnOrUnsummon();
                me->DespawnOrUnsummon(1s);
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _combineTarget;
};

struct npc_iron_sludge : public ScriptedAI
{
    npc_iron_sludge(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        me->SetCorpseDelay(4, true);
        DoCastSelf(SPELL_IRON_SLUDGE_SPAWN_VISUAL);

        if (Creature* sjonnir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_SJONNIR)))
            sjonnir->AI()->JustSummoned(me);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(3s, 6s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_TOXIC_VOLLEY);
            task.Repeat(3s, 6s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* sjonnir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_SJONNIR)))
            sjonnir->AI()->DoAction(ACTION_SLUDGE_DEAD);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

/* 50789 - Summon Iron Dwarf
   50792 - Summon Iron Trogg
   59859 - Summon Iron Trogg
   50801 - Summon Malformed Ooze
   59858 - Summon Malformed Ooze
   50824 - Summon Earthen Dwarf */
class spell_sjonnir_periodic_summon : public AuraScript
{
    PrepareAuraScript(spell_sjonnir_periodic_summon);

public:
    spell_sjonnir_periodic_summon(uint32 leftPipeSpell, uint32 rightPipeSpell)
        : AuraScript(), _leftPipeSpell(leftPipeSpell), _rightPipeSpell(rightPipeSpell) { }

private:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ _leftPipeSpell, _rightPipeSpell });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), RAND(_leftPipeSpell, _rightPipeSpell), true);
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(GetTarget(), RAND(_leftPipeSpell, _rightPipeSpell), true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_sjonnir_periodic_summon::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sjonnir_periodic_summon::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

    uint32 _leftPipeSpell;
    uint32 _rightPipeSpell;
};

// 50777 - Iron Sludge Spawn Visual
class spell_sjonnir_iron_sludge_spawn_visual : public AuraScript
{
    PrepareAuraScript(spell_sjonnir_iron_sludge_spawn_visual);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // They're indeed passive but I'm not sure enough if it's handled by this aura or directly in script
        if (Creature* creature = GetTarget()->ToCreature())
            creature->SetReactState(REACT_PASSIVE);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
        {
            creature->SetReactState(REACT_AGGRESSIVE);
            if (creature->IsAIEnabled() && creature->IsAlive())
                creature->AI()->DoZoneInCombat();
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_sjonnir_iron_sludge_spawn_visual::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sjonnir_iron_sludge_spawn_visual::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_abuse_the_ooze : public AchievementCriteriaScript
{
    public:
        achievement_abuse_the_ooze() : AchievementCriteriaScript("achievement_abuse_the_ooze")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Sjonnir = target->ToCreature())
                if (Sjonnir->AI()->GetData(DATA_ABUSE_THE_OOZE) >= 5)
                    return true;

            return false;
        }
};

void AddSC_boss_sjonnir()
{
    RegisterHallsOfStoneCreatureAI(boss_sjonnir);
    RegisterHallsOfStoneCreatureAI(npc_malformed_ooze);
    RegisterHallsOfStoneCreatureAI(npc_iron_sludge);
    RegisterSpellScriptWithArgs(spell_sjonnir_periodic_summon, "spell_sjonnir_periodic_summon_iron_dwarf", SPELL_SUMMON_IRON_DWARF_1, SPELL_SUMMON_IRON_DWARF_2);
    RegisterSpellScriptWithArgs(spell_sjonnir_periodic_summon, "spell_sjonnir_periodic_summon_iron_trogg", SPELL_SUMMON_IRON_TROGG_1, SPELL_SUMMON_IRON_TROGG_2);
    RegisterSpellScriptWithArgs(spell_sjonnir_periodic_summon, "spell_sjonnir_periodic_summon_malformed_ooze", SPELL_SUMMON_MALFORMED_OOZE_1, SPELL_SUMMON_MALFORMED_OOZE_2);
    RegisterSpellScriptWithArgs(spell_sjonnir_periodic_summon, "spell_sjonnir_periodic_summon_earthen_dwarf", SPELL_SUMMON_EARTHEN_DWARF_1, SPELL_SUMMON_EARTHEN_DWARF_2);
    RegisterSpellScript(spell_sjonnir_iron_sludge_spawn_visual);
    new achievement_abuse_the_ooze();
}

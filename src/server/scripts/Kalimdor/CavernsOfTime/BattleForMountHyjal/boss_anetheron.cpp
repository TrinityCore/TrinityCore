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
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "hyjal.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum AnetheronTexts
{
    SAY_INTRO                   = 0,
    SAY_SLEEP                   = 1,
    SAY_SWARM                   = 2,
    SAY_INFERNO                 = 3,
    SAY_SLAY                    = 4,
    SAY_DEATH                   = 5
};

enum AnetheronSpells
{
    // Anetheron
    SPELL_VAMPIRIC_AURA         = 31317,

    SPELL_SLEEP                 = 31298,
    SPELL_INFERNO               = 31299,
    SPELL_CARRION_SWARM         = 31306,
    SPELL_BERSERK               = 26662,

    // Towering Infernal
    SPELL_IMMOLATION            = 31304,
    SPELL_INFERNO_EFFECT        = 31302,
    SPELL_INSTAKILL_SELF        = 29878,

    // Scripts
    SPELL_VAMPIRIC_AURA_HEAL    = 31285
};

enum AnetheronEvents
{
    EVENT_SLEEP                 = 1,
    EVENT_INFERNO,
    EVENT_CARRION_SWARM,
    EVENT_BERSERK
};

enum AnetheronMisc
{
    NPC_TOWERING_INFERNAL       = 17818,
    ACTION_KILL_SELF            = 0
};

// 17808 - Anetheron
struct boss_anetheron : public BossAI
{
    boss_anetheron(Creature* creature) : BossAI(creature, DATA_ANETHERON), _summons(me) { }

    void JustAppeared() override
    {
        Talk(SAY_INTRO);
        me->GetMotionMaster()->MovePath(RAND(PATH_ALLY_INITIAL_1, PATH_ALLY_INITIAL_2, PATH_ALLY_INITIAL_3), false);
    }

    void Reset() override
    {
        _Reset();
        DoCastSelf(SPELL_VAMPIRIC_AURA);
        _summons.DespawnAll();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SLEEP, 25s, 35s);
        events.ScheduleEvent(EVENT_INFERNO, 15s, 35s);
        events.ScheduleEvent(EVENT_CARRION_SWARM, 10s, 15s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SLEEP:
                if (roll_chance_i(30))
                    Talk(SAY_SLEEP);
                break;
            case SPELL_INFERNO:
                if (roll_chance_i(30))
                    Talk(SAY_INFERNO);
                break;
            case SPELL_CARRION_SWARM:
                if (roll_chance_i(30))
                    Talk(SAY_SWARM);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*waypointId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_ALLY_INITIAL_1:
            case PATH_ALLY_INITIAL_2:
            case PATH_ALLY_INITIAL_3:
                me->GetMotionMaster()->MovePath(RAND(PATH_ALLY_BASE_1, PATH_ALLY_BASE_2, PATH_ALLY_BASE_3), true);
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    // Do not reset SetActive, we want boss to be active all the time
    void JustReachedHome() override { }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        std::vector<Creature*> infernals;
        GetCreatureListWithEntryInGrid(infernals, me, NPC_TOWERING_INFERNAL, 500.0f);
        for (Creature* infernal : infernals)
            infernal->AI()->DoAction(ACTION_KILL_SELF);
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
                case EVENT_SLEEP:
                    DoCastSelf(SPELL_SLEEP);
                    events.Repeat(15s, 35s);
                    break;
                case EVENT_INFERNO:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 250.0f, true))
                        DoCast(target, SPELL_INFERNO);
                    events.Repeat(55s);
                    break;
                case EVENT_CARRION_SWARM:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 60.0f))
                        DoCast(target, SPELL_CARRION_SWARM);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
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
    SummonList _summons;
};

// 17818 - Towering Infernal
struct npc_towering_infernal : public ScriptedAI
{
    npc_towering_infernal(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_IMMOLATION);

        _scheduler.Schedule(1200ms, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_INFERNO_EFFECT);
            DoZoneInCombat();
            me->SetReactState(REACT_AGGRESSIVE);
        });
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_KILL_SELF)
            DoCastSelf(SPELL_INSTAKILL_SELF, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 38196 - Vampiric Aura
class spell_anetheron_vampiric_aura : public AuraScript
{
    PrepareAuraScript(spell_anetheron_vampiric_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VAMPIRIC_AURA_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        Unit* actor = eventInfo.GetActor();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, damageInfo->GetDamage() * 3);
        actor->CastSpell(actor, SPELL_VAMPIRIC_AURA_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_anetheron_vampiric_aura::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 31298 - Sleep
class spell_anetheron_sleep : public SpellScript
{
    PrepareSpellScript(spell_anetheron_sleep);

    bool Load() override
    {
        return GetCaster()->IsUnit();
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster()->GetVictim());
        Trinity::Containers::RandomResize(targets, 3);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anetheron_sleep::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_anetheron()
{
    RegisterHyjalCreatureAI(boss_anetheron);
    RegisterHyjalCreatureAI(npc_towering_infernal);
    RegisterSpellScript(spell_anetheron_vampiric_aura);
    RegisterSpellScript(spell_anetheron_sleep);
}

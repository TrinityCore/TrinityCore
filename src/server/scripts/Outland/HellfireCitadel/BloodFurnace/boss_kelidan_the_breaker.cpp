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
 * Timers requires to be revisited
 * What exactly happens on wipe when one or more channelers are alive? Current behavior in this scenario is guessed for both boss and channelers
 */

#include "ScriptMgr.h"
#include "blood_furnace.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum KelidanTexts
{
    // Keli'dan the Breaker
    SAY_WAKE                    = 0,
    SAY_NOVA                    = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3,

    // Shadowmoon Channeler
    SAY_AGGRO_1                 = 0,
    SAY_AGGRO_2                 = 1
};

enum KelidanSpells
{
    // Keli'dan the Breaker - Out of Combat
    SPELL_EVOCATION             = 30935,

    // Keli'dan the Breaker - Combat
    SPELL_SHADOW_BOLT_VOLLEY    = 17228,
    SPELL_SHADOW_BOLT_VOLLEY_H  = 40070,
    SPELL_CORRUPTION            = 30938,
    SPELL_BURNING_NOVA          = 30940,

    // Shadowmoon Channeler - Out of Combat
    SPELL_STAR_BEAM             = 30888,

    // Shadowmoon Channeler - Combat
    SPELL_SHADOW_BOLT           = 12739,
    SPELL_SHADOW_BOLT_H         = 15472,
    SPELL_MARK_OF_SHADOW        = 30937,

    // Scripts
    SPELL_VORTEX                = 37370,
    SPELL_FIRE_NOVA             = 33775,
    SPELL_FIRE_NOVA_H           = 37371
};

enum KelidanEvents
{
    // Out of Combat
    EVENT_EVOCATION             = 1,

    // Combat
    EVENT_SHADOW_BOLT_VOLLEY,
    EVENT_CORRUPTION,
    EVENT_BURNING_NOVA
};

enum KelidanMisc
{
    ACTION_CHANNELER_DIES       = 0,
    ACTION_RESET_ENCOUNTER      = 1,
    MAX_CHANNELERS              = 5
};

enum KelidanSpawnGroups
{
    SPAWN_GROUP_CHANNELER_1     = 360,
    SPAWN_GROUP_CHANNELER_2     = 361,
    SPAWN_GROUP_CHANNELER_3     = 362,
    SPAWN_GROUP_CHANNELER_4     = 363,
    SPAWN_GROUP_CHANNELER_5     = 364
};

static constexpr std::array<uint32, 5> ChannelersSpawnGroupsData =
{
    SPAWN_GROUP_CHANNELER_1,
    SPAWN_GROUP_CHANNELER_2,
    SPAWN_GROUP_CHANNELER_3,
    SPAWN_GROUP_CHANNELER_4,
    SPAWN_GROUP_CHANNELER_5
};

// 17377 - Keli'dan the Breaker
struct boss_kelidan_the_breaker : public BossAI
{
    boss_kelidan_the_breaker(Creature* creature) : BossAI(creature, DATA_KELIDAN), _deadChannelersCount(0) { }

    void JustAppeared() override
    {
        me->SetImmuneToNPC(true);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);

        DoCastSelf(SPELL_EVOCATION);

        for (uint32 group : ChannelersSpawnGroupsData)
            me->GetMap()->SpawnGroupSpawn(group, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_WAKE);

        me->InterruptNonMeleeSpells(true);

        events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 0s, 2s);
        events.ScheduleEvent(EVENT_CORRUPTION, 5s, 10s);
        events.ScheduleEvent(EVENT_BURNING_NOVA, 10s, 20s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CHANNELER_DIES:
            {
                _deadChannelersCount++;

                if (_deadChannelersCount == MAX_CHANNELERS)
                {
                    me->SetImmuneToNPC(false);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    _deadChannelersCount = 0;
                }
                break;
            }
            case ACTION_RESET_ENCOUNTER:
                _deadChannelersCount = 0;
                for (uint32 group : ChannelersSpawnGroupsData)
                    me->GetMap()->SpawnGroupSpawn(group, true);
                break;
            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BURNING_NOVA)
            Talk(SAY_NOVA);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();

        me->SetImmuneToNPC(true);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);

        events.ScheduleEvent(EVENT_EVOCATION, 5s);

        for (uint32 group : ChannelersSpawnGroupsData)
            me->GetMap()->SpawnGroupSpawn(group, true);
    }

    void KilledUnit(Unit* /*victim*/) override
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
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_EVOCATION)
                    DoCastSelf(SPELL_EVOCATION);
            }

            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_BOLT_VOLLEY:
                    DoCastSelf(DUNGEON_MODE(SPELL_SHADOW_BOLT_VOLLEY, SPELL_SHADOW_BOLT_VOLLEY_H));
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_CORRUPTION:
                    DoCastSelf(SPELL_CORRUPTION);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_BURNING_NOVA:
                    me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, false);
                    DoCastSelf(SPELL_BURNING_NOVA);
                    me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);
                    events.Repeat(25s, 35s);
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
    uint8 _deadChannelersCount;
};

// 17653 - Shadowmoon Channeler
struct npc_shadowmoon_channeler : public ScriptedAI
{
    npc_shadowmoon_channeler(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
        me->SetCorpseDelay(3, true);
    }

    void JustAppeared() override
    {
        DoCastChanneledSpell();
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* who) override
    {
        _scheduler.CancelAll();

        me->InterruptNonMeleeSpells(false);

        Talk(SAY_AGGRO_1);

        if (roll_chance_i(15))
            Talk(SAY_AGGRO_2);

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(0s, 5s, [this](TaskContext task)
            {
                DoCastVictim(DUNGEON_MODE(SPELL_SHADOW_BOLT, SPELL_SHADOW_BOLT_H));
                task.Repeat(10s, 15s);
            })
            .Schedule(5s, 15s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, false, true, -SPELL_MARK_OF_SHADOW))
                    DoCast(target, SPELL_MARK_OF_SHADOW);
                task.Repeat(5s, 15s);
            });
    }

    void DoCastChanneledSpell()
    {
        _scheduler.Schedule(10s, [this](TaskContext task)
        {
            Creature* channeler = me->FindNearestCreatureWithOptions(100.0f, { .StringId = GetStringIdOfChanneler() });
            if (!channeler || channeler->IsInEvadeMode())
            {
                task.Repeat(1s);
                return;
            }

            DoCast(channeler, SPELL_STAR_BEAM);
        });
    }

    std::string_view GetStringIdOfChanneler() const
    {
        if (me->HasStringId("KelidansShadowmoonChanneler1"))
            return "KelidansShadowmoonChanneler4";
        else if (me->HasStringId("KelidansShadowmoonChanneler2"))
            return "KelidansShadowmoonChanneler3";
        else if (me->HasStringId("KelidansShadowmoonChanneler3"))
            return "KelidansShadowmoonChanneler5";
        else if (me->HasStringId("KelidansShadowmoonChanneler4"))
            return "KelidansShadowmoonChanneler2";
        else if (me->HasStringId("KelidansShadowmoonChanneler5"))
            return "KelidansShadowmoonChanneler1";
        return "";
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);

        if (Creature* kelidan = _instance->GetCreature(DATA_KELIDAN))
            kelidan->AI()->DoAction(ACTION_RESET_ENCOUNTER);
    }

    void JustReachedHome() override
    {
        DoCastChanneledSpell();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* kelidan = _instance->GetCreature(DATA_KELIDAN))
            kelidan->AI()->DoAction(ACTION_CHANNELER_DIES);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 30940 - Burning Nova
class spell_kelidan_the_breaker_burning_nova : public AuraScript
{
    PrepareAuraScript(spell_kelidan_the_breaker_burning_nova);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VORTEX, SPELL_FIRE_NOVA, SPELL_FIRE_NOVA_H });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->GetMap()->IsHeroic())
            target->CastSpell(target, SPELL_VORTEX, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, target->GetMap()->IsHeroic() ? SPELL_FIRE_NOVA_H : SPELL_FIRE_NOVA);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_kelidan_the_breaker_burning_nova::AfterApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_kelidan_the_breaker_burning_nova::AfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_kelidan_the_breaker()
{
    RegisterBloodFurnaceCreatureAI(boss_kelidan_the_breaker);
    RegisterBloodFurnaceCreatureAI(npc_shadowmoon_channeler);
    RegisterSpellScript(spell_kelidan_the_breaker_burning_nova);
}

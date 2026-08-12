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
 * SPELL_CHARM_BREAK_HARDCODED is NYI. Don't know what is the purpose of this spell
 * Blackheart should engage all creatures in his room on aggro
 * Waypoint script requires rewrite
 * For unknown reason only current Blackheart's victim runs to attack other player while charmed
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Player.h"
#include "PlayerAI.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "shadow_labyrinth.h"

enum BlackheartTexts
{
    SAY_CHAOS                      = 0,
    SAY_AGGRO                      = 1,
    SAY_SLAY                       = 2,
    SAY_DEATH                      = 3
};

enum BlackheartSpells
{
    // Blackheart - Combat
    SPELL_INCITE_CHAOS             = 33676,
    SPELL_WAR_STOMP                = 33707,
    SPELL_CHARGE                   = 33709,

    // Blackheart - Combat - Misc
    SPELL_LAUGH                    = 33722,

    // Dummy
    SPELL_THREAT                   = 34915,
    SPELL_INCITE_CHAOS_CHARM       = 33684,
    SPELL_INCITER_THREAT_TRIGGER   = 45339,
    SPELL_DUMMY_NUKE               = 21912,
    SPELL_CHARM_BREAK_HARDCODED    = 65634,

    // Scripts
    SPELL_INCITE_CHAOS_SUMMON_1    = 33677,
    SPELL_INCITE_CHAOS_SUMMON_2    = 33680,
    SPELL_INCITE_CHAOS_SUMMON_3    = 33681,
    SPELL_INCITE_CHAOS_SUMMON_4    = 33682,
    SPELL_INCITE_CHAOS_SUMMON_5    = 33683
};

enum BlackheartEvents
{
    EVENT_INCITE_CHAOS             = 1,
    EVENT_WAR_STOMP,
    EVENT_CHARGE_ATTACK
};

static constexpr std::array<uint32, 5> InciteChaosSummonSpells =
{
    SPELL_INCITE_CHAOS_SUMMON_1,
    SPELL_INCITE_CHAOS_SUMMON_2,
    SPELL_INCITE_CHAOS_SUMMON_3,
    SPELL_INCITE_CHAOS_SUMMON_4,
    SPELL_INCITE_CHAOS_SUMMON_5
};

// 18667 - Blackheart the Inciter
struct boss_blackheart_the_inciter : public BossAI
{
    boss_blackheart_the_inciter(Creature* creature) : BossAI(creature, DATA_BLACKHEART_THE_INCITER) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_INCITE_CHAOS, 15s, 25s);
        events.ScheduleEvent(EVENT_WAR_STOMP, 10s, 15s);
        events.ScheduleEvent(EVENT_CHARGE_ATTACK, 10s, 20s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_INCITE_CHAOS)
        {
            Talk(SAY_CHAOS);
            DoCastSelf(SPELL_LAUGH);
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
                case EVENT_INCITE_CHAOS:
                    if (me->GetThreatManager().GetThreatListPlayerCount() > 1)
                    {
                        ResetThreatList();
                        DoCastSelf(SPELL_INCITE_CHAOS);
                    }
                    events.Repeat(50s, 80s);
                    break;
                case EVENT_WAR_STOMP:
                    DoCastSelf(SPELL_WAR_STOMP);
                    events.Repeat(15s, 30s);
                    break;
                case EVENT_CHARGE_ATTACK:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CHARGE);
                    events.Repeat(15s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

class BlackheartCharmedPlayerAI : public SimpleCharmedPlayerAI
{
    using SimpleCharmedPlayerAI::SimpleCharmedPlayerAI;

    bool CanAIAttack(Unit const* target) const override
    {
        if (target->GetEntry() == NPC_BLACKHEART)
            return false;

        return SimpleCharmedPlayerAI::CanAIAttack(target);
    }

    Unit* SelectAttackTarget() const override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* creature = instance->GetCreature(DATA_BLACKHEART_THE_INCITER))
                if (Unit* target = creature->AI()->SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true, true))
                    return target;

        return nullptr;
    }
};

// 19300, 19301, 19302, 19303, 19304 - Blackheart the Inciter
struct npc_blackheart_the_inciter_dummy : public ScriptedAI
{
    npc_blackheart_the_inciter_dummy(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
    }

    void JustAppeared() override
    {
        if (Creature* creature = _instance->GetCreature(DATA_BLACKHEART_THE_INCITER))
            DoCast(creature, SPELL_THREAT);

        if (TempSummon* summon = me->ToTempSummon())
            if (Unit* summoner = summon->GetSummonerUnit())
                DoCast(summoner, SPELL_INCITE_CHAOS_CHARM);

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(5s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_INCITER_THREAT_TRIGGER);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                    DoCast(target, SPELL_DUMMY_NUKE);
                task.Repeat(2s, 4s);
            });
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

    PlayerAI* GetAIForCharmedPlayer(Player* player) override
    {
        return new BlackheartCharmedPlayerAI(player);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 33676 - Incite Chaos
class spell_blackheart_incite_chaos : public SpellScript
{
    PrepareSpellScript(spell_blackheart_incite_chaos);

public:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(InciteChaosSummonSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, InciteChaosSummonSpells[std::min(_targetCount, InciteChaosSummonSpells.size() - 1)], true);
        _targetCount++;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_blackheart_incite_chaos::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }

private:
    std::size_t _targetCount = 0;
};

// 33684 - Incite Chaos
class spell_blackheart_incite_chaos_charm : public AuraScript
{
    PrepareAuraScript(spell_blackheart_incite_chaos_charm);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_blackheart_incite_chaos_charm::AfterRemove, EFFECT_0, SPELL_AURA_MOD_CHARM, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_blackheart_the_inciter()
{
    RegisterShadowLabyrinthCreatureAI(boss_blackheart_the_inciter);
    RegisterShadowLabyrinthCreatureAI(npc_blackheart_the_inciter_dummy);
    RegisterSpellScript(spell_blackheart_incite_chaos);
    RegisterSpellScript(spell_blackheart_incite_chaos_charm);
}

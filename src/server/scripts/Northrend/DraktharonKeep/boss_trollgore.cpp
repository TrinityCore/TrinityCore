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
#include "drak_tharon_keep.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_INFECTED_WOUND                = 49637,
    SPELL_CRUSH                         = 49639,
    SPELL_CORPSE_EXPLODE                = 49555,
    SPELL_CORPSE_EXPLODE_DAMAGE         = 49618,
    SPELL_CONSUME                       = 49380,
    SPELL_CONSUME_BUFF                  = 49381,
    SPELL_CONSUME_BUFF_H                = 59805,

    SPELL_SUMMON_INVADER_A              = 49456,
    SPELL_SUMMON_INVADER_B              = 49457,
    SPELL_SUMMON_INVADER_C              = 49458, // can't find any sniffs

    SPELL_INVADER_TAUNT                 = 49405
};

#define SPELL_CONSUME_BUFF_HELPER DUNGEON_MODE<uint32>(SPELL_CONSUME_BUFF, SPELL_CONSUME_BUFF_H)

enum Yells
{
    SAY_AGGRO                           = 0,
    SAY_KILL                            = 1,
    SAY_CONSUME                         = 2,
    SAY_EXPLODE                         = 3,
    SAY_DEATH                           = 4
};

enum Misc
{
    DATA_CONSUMPTION_JUNCTION           = 1,
    POINT_LANDING                       = 1
};

enum Events
{
    EVENT_CONSUME = 1,
    EVENT_CRUSH,
    EVENT_INFECTED_WOUND,
    EVENT_CORPSE_EXPLODE,
    EVENT_SPAWN
};

Position const Landing = { -263.0534f, -660.8658f, 26.50903f, 0.0f };

struct boss_trollgore : public BossAI
{
    boss_trollgore(Creature* creature) : BossAI(creature, DATA_TROLLGORE)
    {
        Initialize();
    }

    void Initialize()
    {
        _consumptionJunction = true;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_CONSUME, 15s);
        events.ScheduleEvent(EVENT_CRUSH, 1s, 5s);
        events.ScheduleEvent(EVENT_INFECTED_WOUND, 10s, 60s);
        events.ScheduleEvent(EVENT_CORPSE_EXPLODE, 3s);
        events.ScheduleEvent(EVENT_SPAWN, 30s, 40s);
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
                case EVENT_CONSUME:
                    Talk(SAY_CONSUME);
                    DoCastAOE(SPELL_CONSUME);
                    events.ScheduleEvent(EVENT_CONSUME, 15s);
                    break;
                case EVENT_CRUSH:
                    DoCastVictim(SPELL_CRUSH);
                    events.ScheduleEvent(EVENT_CRUSH, 10s, 15s);
                    break;
                case EVENT_INFECTED_WOUND:
                    DoCastVictim(SPELL_INFECTED_WOUND);
                    events.ScheduleEvent(EVENT_INFECTED_WOUND, 25s, 35s);
                    break;
                case EVENT_CORPSE_EXPLODE:
                    Talk(SAY_EXPLODE);
                    DoCastAOE(SPELL_CORPSE_EXPLODE);
                    events.ScheduleEvent(EVENT_CORPSE_EXPLODE, 15s, 19s);
                    break;
                case EVENT_SPAWN:
                    for (uint8 i = 0; i < 3; ++i)
                        if (Creature* trigger = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TROLLGORE_INVADER_SUMMONER_1 + i)))
                            trigger->CastSpell(trigger, RAND(SPELL_SUMMON_INVADER_A, SPELL_SUMMON_INVADER_B, SPELL_SUMMON_INVADER_C), CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCaster(me->GetGUID()));

                    events.ScheduleEvent(EVENT_SPAWN, 30s, 40s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (_consumptionJunction)
        {
            Aura* ConsumeAura = me->GetAura(SPELL_CONSUME_BUFF_HELPER);
            if (ConsumeAura && ConsumeAura->GetStackAmount() > 9)
                _consumptionJunction = false;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_CONSUMPTION_JUNCTION)
            return _consumptionJunction ? 1 : 0;

        return 0;
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        Talk(SAY_KILL);
    }

    void JustSummoned(Creature* summon) override
    {
        summon->GetMotionMaster()->MovePoint(POINT_LANDING, Landing);
        summons.Summon(summon);
    }

    private:
        bool _consumptionJunction;
};

struct npc_drakkari_invader : public ScriptedAI
{
    npc_drakkari_invader(Creature* creature) : ScriptedAI(creature) { }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == POINT_MOTION_TYPE && pointId == POINT_LANDING)
        {
            me->Dismount();
            me->SetImmuneToAll(false);
            DoCastAOE(SPELL_INVADER_TAUNT);
        }
    }
};

// 49380, 59803 - Consume
class spell_trollgore_consume : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CONSUME_BUFF });
    }

    void HandleConsume(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(GetCaster(), SPELL_CONSUME_BUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_trollgore_consume::HandleConsume, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 49555, 59807 - Corpse Explode
class spell_trollgore_corpse_explode : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CORPSE_EXPLODE_DAMAGE });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 2)
            if (Unit* caster = GetCaster())
                caster->CastSpell(GetTarget(), SPELL_CORPSE_EXPLODE_DAMAGE, aurEff);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_trollgore_corpse_explode::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_trollgore_corpse_explode::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 49405 - Invader Taunt Trigger
class spell_trollgore_invader_taunt : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleTaunt(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            target->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_trollgore_invader_taunt::HandleTaunt, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class achievement_consumption_junction : public AchievementCriteriaScript
{
    public:
        achievement_consumption_junction() : AchievementCriteriaScript("achievement_consumption_junction")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Trollgore = target->ToCreature())
                if (Trollgore->AI()->GetData(DATA_CONSUMPTION_JUNCTION))
                    return true;

            return false;
        }
};

void AddSC_boss_trollgore()
{
    RegisterDrakTharonKeepCreatureAI(boss_trollgore);
    RegisterDrakTharonKeepCreatureAI(npc_drakkari_invader);
    RegisterSpellScript(spell_trollgore_consume);
    RegisterSpellScript(spell_trollgore_corpse_explode);
    RegisterSpellScript(spell_trollgore_invader_taunt);
    new achievement_consumption_junction();
}

/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "GuardAI.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Random.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "CreatureAIImpl.h"

enum GuardMisc
{
    SAY_GUARD_SIL_AGGRO = 0,

    NPC_CENARION_HOLD_INFANTRY = 15184,
    NPC_STORMWIND_CITY_GUARD = 68,
    NPC_STORMWIND_CITY_PATROLLER = 1976,
    NPC_ORGRIMMAR_GRUNT = 3296,
    NPC_ALDOR_VINDICATOR = 18549,

    SPELL_BANISHED_SHATTRATH_A = 36642,
    SPELL_BANISHED_SHATTRATH_S = 36671,
    SPELL_BANISH_TELEPORT = 36643,
    SPELL_EXILE = 39533,
};

struct npc_guard_generic : public GuardAI
{
    npc_guard_generic(Creature* creature) : GuardAI(creature)
    {
        _scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING) && !me->IsInEvadeMode() && me->IsAlive();
        });
        _combatScheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
        _combatScheduler.CancelAll();
        _scheduler.Schedule(Seconds(1), [this](TaskContext context)
        {
            // Find a spell that targets friendly and applies an aura (these are generally buffs)
            if (SpellInfo const* spellInfo = SelectSpell(me, 0, 0, SELECT_TARGET_ANY_FRIEND, 0, 0, SELECT_EFFECT_AURA))
                DoCast(me, spellInfo->Id);

            context.Repeat(Minutes(10));
        });
    }

    void DoReplyToTextEmote(uint32 emote)
    {
        switch (emote)
        {
            case TEXT_EMOTE_KISS:
                me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                break;
            case TEXT_EMOTE_WAVE:
                me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                break;
            case TEXT_EMOTE_SALUTE:
                me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                break;
            case TEXT_EMOTE_SHY:
                me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);
                break;
            case TEXT_EMOTE_RUDE:
            case TEXT_EMOTE_CHICKEN:
                me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                break;
            default:
                break;
        }
    }

    void ReceiveEmote(Player* player, uint32 textEmote) override
    {
        switch (me->GetEntry())
        {
            case NPC_STORMWIND_CITY_GUARD:
            case NPC_STORMWIND_CITY_PATROLLER:
            case NPC_ORGRIMMAR_GRUNT:
                break;
            default:
                return;
        }

        if (!me->IsFriendlyTo(player))
            return;

        DoReplyToTextEmote(textEmote);
    }

    void EnterCombat(Unit* who) override
    {
        if (me->GetEntry() == NPC_CENARION_HOLD_INFANTRY)
            Talk(SAY_GUARD_SIL_AGGRO, who);

        _combatScheduler.Schedule(Seconds(1), [this](TaskContext meleeContext)
        {
            Unit* victim = me->GetVictim();
            if (!me->isAttackReady() || !me->IsWithinMeleeRange(victim))
            {
                meleeContext.Repeat();
                return;
            }
            if (roll_chance_i(20))
            {
                if (SpellInfo const* spellInfo = SelectSpell(me->GetVictim(), 0, 0, SELECT_TARGET_ANY_ENEMY, 0, NOMINAL_MELEE_RANGE, SELECT_EFFECT_DONTCARE))
                {
                    me->resetAttackTimer();
                    DoCastVictim(spellInfo->Id);
                    meleeContext.Repeat();
                    return;
                }
            }
            if (ShouldSparWith(victim))
                me->FakeAttackerStateUpdate(victim);
            else
                me->AttackerStateUpdate(victim);
            me->resetAttackTimer();
            meleeContext.Repeat();
        }).Schedule(Seconds(5), [this](TaskContext spellContext)
        {
            bool healing = false;
            SpellInfo const* spellInfo = nullptr;

            // Select a healing spell if less than 30% hp and ONLY 33% of the time
            if (me->HealthBelowPct(30) && roll_chance_i(33))
                spellInfo = SelectSpell(me, 0, 0, SELECT_TARGET_ANY_FRIEND, 0, 0, SELECT_EFFECT_HEALING);

            // No healing spell available, check if we can cast a ranged spell
            if (spellInfo)
                healing = true;
            else
                spellInfo = SelectSpell(me->GetVictim(), 0, 0, SELECT_TARGET_ANY_ENEMY, NOMINAL_MELEE_RANGE, 0, SELECT_EFFECT_DONTCARE);

            // Found a spell
            if (spellInfo)
            {
                if (healing)
                    DoCast(me, spellInfo->Id);
                else
                    DoCastVictim(spellInfo->Id);
                spellContext.Repeat(Seconds(5));
            }
            else
                spellContext.Repeat(Seconds(1));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _combatScheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    TaskScheduler _combatScheduler;
};

struct npc_guard_shattrath_faction : public GuardAI
{
    npc_guard_shattrath_faction(Creature* creature) : GuardAI(creature)
    {
        _scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        ScheduleVanish();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, std::bind(&GuardAI::DoMeleeAttackIfReady, this));
    }

    void ScheduleVanish()
    {
        _scheduler.Schedule(Seconds(5), [this](TaskContext banishContext)
        {
            Unit* temp = me->GetVictim();
            if (temp && temp->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(temp, me->GetEntry() == NPC_ALDOR_VINDICATOR ? SPELL_BANISHED_SHATTRATH_S : SPELL_BANISHED_SHATTRATH_A);
                ObjectGuid playerGUID = temp->GetGUID();
                banishContext.Schedule(Seconds(9), [this, playerGUID](TaskContext /*exileContext*/)
                {
                    if (Unit* temp = ObjectAccessor::GetUnit(*me, playerGUID))
                    {
                        temp->CastSpell(temp, SPELL_EXILE, true);
                        temp->CastSpell(temp, SPELL_BANISH_TELEPORT, true);
                    }
                    ScheduleVanish();
                });
            }
            else
                banishContext.Repeat();
        });
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_npc_guard()
{
    RegisterCreatureAI(npc_guard_generic);
    RegisterCreatureAI(npc_guard_shattrath_faction);
}

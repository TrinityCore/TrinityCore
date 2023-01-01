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
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "the_underbog.h"

enum HungarfenTexts
{
    EMOTE_ROARS                      = 0
};

enum HungarfenSpells
{
    SPELL_FOUL_SPORES                = 31673,
    SPELL_SUMMON_UNDERBOG_MUSHROOM   = 31692,
    SPELL_PUTRID_MUSHROOM_PRIMER     = 31693,
    SPELL_DESPAWN_UNDERBOG_MUSHROOMS = 34874,
    SPELL_ACID_GEYSER                = 38739,

    SPELL_SPORE_CLOUD                = 34168,
    SPELL_PUTRID_MUSHROOM            = 31690,
    SPELL_SHRINK                     = 31691,
    SPELL_GROW                       = 31698
};

struct boss_hungarfen : public BossAI
{
    boss_hungarfen(Creature* creature) : BossAI(creature, DATA_HUNGARFEN), _roared(false) { }

    void Reset() override
    {
        BossAI::Reset();
        _roared = false;
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        _scheduler.Schedule(IsHeroic() ? 2500ms : 5s, [this](TaskContext task)
        {
            /// @todo cast here SPELL_PUTRID_MUSHROOM_PRIMER and do it in spell script
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                target->CastSpell(target, SPELL_SUMMON_UNDERBOG_MUSHROOM, true);
            task.Repeat(IsHeroic() ? 2500ms : 10s);
        });

        if (IsHeroic())
        {
            _scheduler.Schedule(3s, 5s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_ACID_GEYSER);
                task.Repeat(10s, 15s);
            });
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DoCastSelf(SPELL_DESPAWN_UNDERBOG_MUSHROOMS, true);
        BossAI::EnterEvadeMode(why);
    }

    void JustDied(Unit* killer) override
    {
        DoCastSelf(SPELL_DESPAWN_UNDERBOG_MUSHROOMS, true);
        BossAI::JustDied(killer);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });

        if (!HealthAbovePct(20) && !_roared)
        {
            Talk(EMOTE_ROARS);
            _roared = true;
            me->SetReactState(REACT_PASSIVE);

            _scheduler.Schedule(2s, [this](TaskContext /*task*/)
            {
                DoCastSelf(SPELL_FOUL_SPORES);
                me->SetReactState(REACT_AGGRESSIVE);
            });
        }
    }

private:
    TaskScheduler _scheduler;
    bool _roared;
};

struct npc_underbog_mushroom : public ScriptedAI
{
    npc_underbog_mushroom(Creature* creature) : ScriptedAI(creature), _counter(0) { }

    void InitializeAI() override
    {
        _counter = RAND(8, 9, 10);
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_SHRINK);
        DoCastSelf(SPELL_PUTRID_MUSHROOM);

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_GROW);

            // It's random(sniffs), makes them grow to different size. We need here count of stacks
            // and not task repeat counter because first stack is applied not when task is repeated
            Aura* growAura = me->GetAura(SPELL_GROW);
            if (growAura && growAura->GetStackAmount() != _counter)
                task.Repeat(2s);
            else
            {
                task.Schedule(1s, [this](TaskContext task)
                {
                    DoCastSelf(SPELL_SPORE_CLOUD);

                    task.Schedule(4s, [this](TaskContext /*task*/)
                    {
                        me->RemoveAurasDueToSpell(SPELL_GROW);
                        me->DespawnOrUnsummon(4s);
                    });
                });
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    uint32 _counter;
};

void AddSC_boss_hungarfen()
{
    RegisterTheUnderbogCreatureAI(boss_hungarfen);
    RegisterTheUnderbogCreatureAI(npc_underbog_mushroom);
}

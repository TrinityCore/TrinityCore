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
#include "gundrak.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_POISON_NOVA                             = 55081,
    SPELL_POWERFULL_BITE                          = 48287,
    SPELL_VENOM_BOLT                              = 54970,
    SPELL_SUMMON_SNAKES                           = 55060, // NYI
    SPELL_SUMMON_CONSTRICTORS                     = 54969  // NYI
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_SUMMON_SNAKES                             = 3,
    SAY_SUMMON_CONSTRICTORS                       = 4,
    EMOTE_NOVA                                    = 5,
    EMOTE_ACTIVATE_ALTAR                          = 6
};

enum Creatures
{
    CREATURE_SNAKE                                = 29680,
    CREATURE_CONSTRICTORS                         = 29713
};

enum ConstrictorSpells
{
    SPELL_GRIP_OF_SLAD_RAN                        = 55093,
    SPELL_SNAKE_WRAP                              = 55126, // 55099 -> 55126
    SPELL_VENOMOUS_BITE                           = 54987
};

static Position SpawnLoc[]=
{
    {1783.81f, 646.637f, 133.948f, 3.71755f},
    {1775.03f, 606.586f, 134.165f, 1.43117f},
    {1717.39f, 630.041f, 129.282f, 5.96903f},
    {1765.66f, 646.542f, 134.02f,  5.11381f},
    {1716.76f, 635.159f, 129.282f, 0.191986f}
};

enum Misc
{
    DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES       = 1
};

enum Phase
{
    PHASE_NONE = 0,
    PHASE_SNAKES = 1,
    PHASE_CONSTRICTORS = 2
};

enum TaskGroup
{
    GROUP_SNAKES = 0
};

struct boss_slad_ran : public BossAI
{
    boss_slad_ran(Creature* creature) : BossAI(creature, DATA_SLAD_RAN)
    {
        Initialize();
    }

    void Initialize()
    {
        _phase = Phase::PHASE_NONE;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        _wrappedPlayers.clear();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
    }

    void ScheduleTasks() override
    {
        scheduler
            .Schedule(10s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_POISON_NOVA);
                Talk(EMOTE_NOVA);
                task.Repeat(15s);
            })
            .Schedule(3s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_POWERFULL_BITE);
                task.Repeat(10s);
            })
            .Schedule(15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_VENOM_BOLT);
                task.Repeat(10s);
            });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
    {
        if (_phase == Phase::PHASE_NONE && HealthBelowPct(30))
        {
            Talk(SAY_SUMMON_SNAKES);
            _phase = Phase::PHASE_SNAKES;

            scheduler.Schedule(5s, GROUP_SNAKES, [this](TaskContext task)
            {
                for (uint8 i = 0; i < DUNGEON_MODE(3, 5); ++i)
                    me->SummonCreature(CREATURE_SNAKE, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s);

                task.Repeat();
            });
        }

        if (_phase == Phase::PHASE_SNAKES && HealthBelowPct(25))
        {
            Talk(SAY_SUMMON_CONSTRICTORS);
            _phase = Phase::PHASE_CONSTRICTORS;

            scheduler.CancelGroup(GROUP_SNAKES);
            scheduler.Schedule(5s, [this](TaskContext task)
            {
                for (uint8 i = 0; i < DUNGEON_MODE(3, 5); ++i)
                    me->SummonCreature(CREATURE_CONSTRICTORS, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s);

                task.Repeat();
            });
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(EMOTE_ACTIVATE_ALTAR);
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        summon->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
        summons.Summon(summon);
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES)
            _wrappedPlayers.insert(guid);
    }

    bool WasWrapped(ObjectGuid guid) const
    {
        return _wrappedPlayers.count(guid) != 0;
    }

private:
    Phase _phase;
    GuidSet _wrappedPlayers;
};

struct npc_slad_ran_constrictor : public ScriptedAI
{
    npc_slad_ran_constrictor(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(2s, [this](TaskContext task)
        {
            Unit* target = me->GetVictim();

            DoCast(target, SPELL_GRIP_OF_SLAD_RAN);

            Aura* grip = target->GetAura(SPELL_GRIP_OF_SLAD_RAN, me->GetGUID());
            if (grip && grip->GetStackAmount() == 5)
            {
                target->RemoveAurasDueToSpell(SPELL_GRIP_OF_SLAD_RAN, me->GetGUID());
                target->CastSpell(target, SPELL_SNAKE_WRAP, true);

                if (TempSummon* _me = me->ToTempSummon())
                    if (Unit* summoner = _me->GetSummonerUnit())
                        if (Creature* sladran = summoner->ToCreature())
                            sladran->AI()->SetGUID(target->GetGUID(), DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES);

                me->DespawnOrUnsummon();
            }

            task.Repeat(3s, 6s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }
private:
    TaskScheduler _scheduler;
};

struct npc_slad_ran_viper : public ScriptedAI
{
    npc_slad_ran_viper(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(2s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_VENOMOUS_BITE);
            task.Repeat(10s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);
    }
private:
    TaskScheduler _scheduler;
};

class achievement_snakes_whyd_it_have_to_be_snakes : public AchievementCriteriaScript
{
    public:
        achievement_snakes_whyd_it_have_to_be_snakes() : AchievementCriteriaScript("achievement_snakes_whyd_it_have_to_be_snakes") { }

        bool OnCheck(Player* player, Unit* target) override
        {
            if (!target)
                return false;

            if (boss_slad_ran* sladRanAI = CAST_AI(boss_slad_ran, target->GetAI()))
                return !sladRanAI->WasWrapped(player->GetGUID());
            return false;
        }
};

void AddSC_boss_slad_ran()
{
    RegisterGundrakCreatureAI(boss_slad_ran);
    RegisterGundrakCreatureAI(npc_slad_ran_constrictor);
    RegisterGundrakCreatureAI(npc_slad_ran_viper);
    new achievement_snakes_whyd_it_have_to_be_snakes();
}

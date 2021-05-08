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
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_SHROUD_OF_DARKNESS                    = 54524,
    SPELL_SUMMON_VOID_SENTRY                    = 54369,
    SPELL_VOID_SHIFT                            = 54361,
    SPELL_VOID_SHIFTED                          = 54343,
    SPELL_ZURAMAT_ADD                           = 54341,
    SPELL_ZURAMAT_ADD_2                         = 54342,
    SPELL_ZURAMAT_ADD_DUMMY                     = 54351,
    SPELL_SUMMON_VOID_SENTRY_BALL               = 58650
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_SHIELD                                  = 4,
    SAY_WHISPER                                 = 5
};

enum Misc
{
    ACTION_DESPAWN_VOID_SENTRY_BALL             = 1,
    DATA_VOID_DANCE                             = 2153
};

struct boss_zuramat : public BossAI
{
    boss_zuramat(Creature* creature) : BossAI(creature, DATA_ZURAMAT)
    {
        Initialize();
    }

    void Initialize()
    {
        _voidDance = true;
    }

    void Reset() override
    {
        BossAI::Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
    }

    void JustReachedHome() override
    {
        BossAI::JustReachedHome();
        instance->SetData(DATA_HANDLE_CELLS, DATA_ZURAMAT);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*who*/) override
    {
        if (summon->GetEntry() == NPC_VOID_SENTRY)
            _voidDance = false;
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_VOID_SENTRY)
            summon->AI()->DoAction(ACTION_DESPAWN_VOID_SENTRY_BALL);
        BossAI::SummonedCreatureDespawn(summon);
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_VOID_DANCE)
            return _voidDance ? 1 : 0;

        return 0;
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff,
            std::bind(&BossAI::DoMeleeAttackIfReady, this));
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(Seconds(4), [this](TaskContext task)
        {
            DoCast(me, SPELL_SUMMON_VOID_SENTRY);
            task.Repeat(Seconds(7), Seconds(10));
        });

        scheduler.Schedule(Seconds(9), [this](TaskContext task)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 60.0f, true))
                DoCast(target, SPELL_VOID_SHIFT);
            task.Repeat(Seconds(15));
        });

        scheduler.Schedule(Seconds(18), Seconds(20), [this](TaskContext task)
        {
            DoCast(me, SPELL_SHROUD_OF_DARKNESS);
            task.Repeat(Seconds(18), Seconds(20));
        });
    }

private:
    bool _voidDance;
};

struct npc_void_sentry : public ScriptedAI
{
    npc_void_sentry(Creature* creature) : ScriptedAI(creature), _summons(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        me->CastSpell(me, SPELL_SUMMON_VOID_SENTRY_BALL, true);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
        summon->SetReactState(REACT_PASSIVE);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_DESPAWN_VOID_SENTRY_BALL)
            _summons.DespawnAll();
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoAction(ACTION_DESPAWN_VOID_SENTRY_BALL);
    }

private:
    SummonList _summons;
};

class achievement_void_dance : public AchievementCriteriaScript
{
    public:
        achievement_void_dance() : AchievementCriteriaScript("achievement_void_dance") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Zuramat = target->ToCreature())
                if (Zuramat->AI()->GetData(DATA_VOID_DANCE))
                    return true;

            return false;
        }
};

void AddSC_boss_zuramat()
{
    RegisterVioletHoldCreatureAI(boss_zuramat);
    RegisterVioletHoldCreatureAI(npc_void_sentry);
    new achievement_void_dance();
}

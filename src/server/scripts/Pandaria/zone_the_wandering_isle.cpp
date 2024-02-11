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

#include "CellImpl.h"
#include "Containers.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "TaskScheduler.h"

enum TraineeMisc
{
    SAY_FINISH_FIGHT                    = 0,

    SPELL_BLACKOUT_KICK                 = 109080,

    QUEST_29524_KILLCREDIT              = 54586,

    POINT_DESPAWN                       = 0,

    NPC_HUOJIN_TRAINEE_MALE             = 54586,
    NPC_HUOJIN_TRAINEE_FEMALE           = 65470,
    NPC_TUSHUI_TRAINEE_MALE             = 54587,
    NPC_TUSHUI_TRAINEE_FEMALE           = 65471,
};

Position const TraineeEndpoints[] = {
    { 1465.3872f, 3283.8604f, 137.69096f },
    { 1431.401f, 3264.001f, 136.02579f },
    { 1397.2067f, 3276.5618f, 133.84508f },
    { 1441.566f, 3232.8013f, 135.01802f },
    { 1403.632f, 3229.1094f, 132.14877f },
    { 1347.1927f, 3286.5842f, 131.94803f },
    { 1365.1865f, 3338.9502f, 128.57233f },
    { 1349.6024f, 3315.0574f, 130.97443f },
    { 1335.4618f, 3344.019f, 130.42047f },
    { 1360.1198f, 3378.02f, 127.34183f },
    { 1435.8524f, 3355.6423f, 173.77744f },
    { 1432.7031f, 3385.1572f, 184.4187f },
    { 1452.6094f, 3373.3315f, 187.0402f },
    { 1426.7778f, 3364.7517f, 184.39569f },
    { 1450.3646f, 3361.264f, 184.42484f },
};

Emote constexpr TraineeEmotes[5] =
{
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED,
    EMOTE_ONESHOT_PALMSTRIKE,
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF,
};

// 54586 - Huojin Trainee
// 65470 - Huojin Trainee
// 54587 - Tushui Trainee
// 65471 - Tushui Trainee
struct npc_tushui_huojin_trainee : public ScriptedAI
{
    npc_tushui_huojin_trainee(Creature* creature) : ScriptedAI(creature), _defeated(false) { }

    Emote PlayRandomEmote() const
    {
        Emote emote = Trinity::Containers::SelectRandomContainerElement(TraineeEmotes);
        me->HandleEmoteCommand(emote);
        return emote;
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(20, damage))
        {
            damage = 0;
            if (_defeated)
                return;

            _defeated = true;
            if (attacker)
            {
                if (Player* player = attacker->ToPlayer())
                    player->KilledMonsterCredit(QUEST_29524_KILLCREDIT);
            }

            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->CombatStop();

            _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/)
            {
                Talk(SAY_FINISH_FIGHT);
            });

            _scheduler.Schedule(Seconds(3), [this](TaskContext /*task*/)
            {
                Position currentPosition;
                float currentDist = 1000.0f;
                for (Position const& pos : TraineeEndpoints)
                {
                    float dist = pos.GetExactDist(me);
                    if (dist >= currentDist)
                        continue;

                    currentPosition = pos;
                    currentDist = dist;
                }
                me->GetMotionMaster()->MovePoint(POINT_DESPAWN, currentPosition);
            });
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id != POINT_DESPAWN)
            return;

        me->DespawnOrUnsummon();
    }

    void JustEngagedWith(Unit* /*attacker*/) override
    {
        _scheduler.Schedule(Seconds(4), [this](TaskContext task)
        {
            if (me->GetVictim())
                DoCastVictim(SPELL_BLACKOUT_KICK);

            task.Repeat(Seconds(8));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_defeated)
            ScriptedAI::EnterEvadeMode(why);
    }

protected:
    TaskScheduler _scheduler;
    bool _defeated;
};

enum HuojinTraineeMisc
{
    ACTION_PARTNER_ENTERED_COMBAT = 1,
};

class HuojinTraineePartnerSearch
{
public:
    HuojinTraineePartnerSearch(Creature* partner) : _partner(partner), _minDist(10.0f) { }

    bool operator()(Creature const* target)
    {
        if (target->GetEntry() != NPC_HUOJIN_TRAINEE_MALE && target->GetEntry() != NPC_HUOJIN_TRAINEE_FEMALE)
            return false;
        if (target == _partner)
            return false;
        if (target->IsInCombat())
            return false;
        if (target->IsInEvadeMode())
            return false;
        if (target->isDead())
            return false;

        float dist = target->GetDistance(_partner);
        if (dist >= _minDist)
            return false;

        _minDist = dist;
        return true;
    }

private:
    Unit* _partner;
    float _minDist;
};

// 54586 - Huojin Trainee
// 65470 - Huojin Trainee
struct npc_huojin_trainee : public npc_tushui_huojin_trainee
{
    npc_huojin_trainee(Creature* creature) : npc_tushui_huojin_trainee(creature) { }

    void JustEngagedWith(Unit* attacker) override
    {
        _scheduler.CancelAll();
        npc_tushui_huojin_trainee::JustEngagedWith(attacker);

        Creature* partner = ObjectAccessor::GetCreature(*me, _partnerGuid);
        if (!partner)
            return;

        if (partner->AI())
            partner->AI()->DoAction(ACTION_PARTNER_ENTERED_COMBAT);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_PARTNER_ENTERED_COMBAT)
        {
            _scheduler.CancelAll();

            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/ )
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
            });
        }
    }

    void BeginSparring(ObjectGuid guid)
    {
        _partnerGuid = guid;
        me->SetEmoteState(EMOTE_ONESHOT_NONE);
        me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);

        _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/)
        {
            me->SetEmoteState(EMOTE_STATE_MONKOFFENSE_READYUNARMED);
        });

        _scheduler.Schedule(Seconds(4), [this](TaskContext task)
        {
            PlayRandomEmote();
            task.Repeat(Seconds(4));
        });
    }

    Creature* GetNewPartner() const
    {
        Creature* partner = nullptr;
        HuojinTraineePartnerSearch check(me);
        Trinity::CreatureLastSearcher<HuojinTraineePartnerSearch> searcher(me, partner, check);
        Cell::VisitGridObjects(me, searcher, 10.0f);
        return partner;
    }

    void BeginSparringDelayed(ObjectGuid partnerGuid)
    {
        _partnerGuid = partnerGuid;
        _scheduler.Schedule(Seconds(1), [this, partnerGuid](TaskContext /*task*/)
        {
            BeginSparring(partnerGuid);
        });
    }

    void InitiateSparring()
    {
        Creature* partner = GetNewPartner();

        if (!partner)
            return;

        BeginSparring(partner->GetGUID());
        if (Creature* partner = ObjectAccessor::GetCreature(*me, _partnerGuid))
        {
            if (npc_huojin_trainee* ai = CAST_AI(npc_huojin_trainee, partner->GetAI()))
                ai->BeginSparringDelayed(me->GetGUID());
        }
    }

    void JustReachedHome() override
    {
        InitiateSparring();
    }

    void JustAppeared() override
    {
        // partner is already assigned, sparring start is delayed
        if (!ObjectAccessor::GetCreature(*me, _partnerGuid))
            InitiateSparring();
    }
private:
    ObjectGuid _partnerGuid;
};

class TushuiTraineeSearch
{
public:
    TushuiTraineeSearch(Creature* leader, float maxDist) : _leader(leader), _maxDist(maxDist) { }

    bool operator()(Creature const* target) const
    {
        if (target->GetEntry() != NPC_TUSHUI_TRAINEE_MALE && target->GetEntry() != NPC_TUSHUI_TRAINEE_FEMALE)
            return false;
        if (target->IsInCombat())
            return false;
        if (target->IsInEvadeMode())
            return false;
        if (target->GetDistance(_leader) >= _maxDist)
            return false;
        if (target->isDead())
            return false;

        return true;
    }

private:
    Creature* _leader;
    float _maxDist;
};

void HandleEmoteNearbyTushuiTrainees(Creature* leader, Emote emote)
{
    std::list<Creature*> traineeList;
    TushuiTraineeSearch check(leader, 10.0f);
    Trinity::CreatureListSearcher<TushuiTraineeSearch> searcher(leader, traineeList, check);
    Cell::VisitGridObjects(leader, searcher, 10.0f);

    for (Creature* trainee : traineeList)
        trainee->HandleEmoteCommand(emote);
}

// 54587 - Tushui Trainee
// 65471 - Tushui Trainee
struct npc_tushui_leading_trainee : public npc_tushui_huojin_trainee
{
    npc_tushui_leading_trainee(Creature* creature) : npc_tushui_huojin_trainee(creature) { }

    void ScheduleEmoteExecution()
    {
        _scheduler.Schedule(Seconds(1), [this](TaskContext task)
        {
            Emote emote = PlayRandomEmote();
            HandleEmoteNearbyTushuiTrainees(me, emote);
            task.Repeat(Seconds(6));
        });
    }

    void JustReachedHome() override
    {
        ScheduleEmoteExecution();
    }

    void JustAppeared() override
    {
        ScheduleEmoteExecution();
    }

    void JustEngagedWith(Unit* attacker) override
    {
        _scheduler.CancelAll();
        npc_tushui_huojin_trainee::JustEngagedWith(attacker);
    }
};

// 61411 - Instructor Zhi
struct npc_instructor_zhi : public ScriptedAI
{
    npc_instructor_zhi(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(Seconds(6), [this](TaskContext task)
        {
            Emote emote = Trinity::Containers::SelectRandomContainerElement(TraineeEmotes);
            me->HandleEmoteCommand(emote);

            task.Schedule(Seconds(1), [this, emote](TaskContext /*task*/)
            {
                HandleEmoteNearbyTushuiTrainees(me, emote);
            });
            task.Repeat(Seconds(6));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_zone_the_wandering_isle()
{
    RegisterCreatureAI(npc_tushui_huojin_trainee);
    RegisterCreatureAI(npc_huojin_trainee);
    RegisterCreatureAI(npc_tushui_leading_trainee);
    RegisterCreatureAI(npc_instructor_zhi);
}

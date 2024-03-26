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
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"

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

// Quest 29419 - The Missing Driver
enum TheMissingDriverMisc
{
    // Spells
    SPELL_SERVERSIDE_KILL_CREDIT    = 106231,
    SPELL_FORCE_SUMMON_CART_DRIVER  = 106206,
    SPELL_SUMMON_CART_DRIVER        = 106205,

    // Texts
    SAY_MIN_DIMWIND_TEXT_0          = 0,
    SAY_MIN_DIMWIND_TEXT_1          = 1,
    SAY_MIN_DIMWIND_TEXT_2          = 2,
    SAY_MIN_DIMWIND_TEXT_3          = 3,

    SAY_AMBERLEAF_SCAMP_0           = 0,
    SAY_AMBERLEAF_SCAMP_1           = 1,

    // Waypoint
    PATH_MOVE_RUN                   = 5650300,
    PATH_MOVE_WALK                  = 5650301,

    WAYPOINT_ID_0                   = 0,
    WAYPOINT_ID_3                   = 3,
    WAYPOINT_ID_11                  = 11,

    // Quests
    QUEST_THE_MISSING_DRIVER        = 29419
};

Position const amberleafPos[5] =
{
    { 1410.2014f, 3598.6494f, 89.59319f },
    { 1456.201f,  3568.265f,  88.39075f },
    { 1383.158f,  3595.447f,  90.3155f  },
    { 1367.333f,  3594.927f,  88.89806f },
    { 1350.278f,  3588.938f,  89.17908f }
};

// 6958 - Areatrigger
class at_min_dimwind_captured : public AreaTriggerScript
{
    public:
        at_min_dimwind_captured() : AreaTriggerScript("at_min_dimwind_captured") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (!player->isDead() && player->GetQuestStatus(QUEST_THE_MISSING_DRIVER) == QUEST_STATUS_INCOMPLETE)
            {
                Creature* minDimwind = player->FindNearestCreatureWithOptions(20.0f, { .StringId = "npc_min_dimwind" });

                if (!minDimwind)
                    return false;

                minDimwind->CastSpell(player, SPELL_FORCE_SUMMON_CART_DRIVER, TRIGGERED_FULL_MASK);
                player->CastSpell(player, SPELL_SERVERSIDE_KILL_CREDIT, TRIGGERED_FULL_MASK);
                PhasingHandler::OnConditionChange(player); // blizzard adds phase 630 when kill credit but immediately is removed to add it again when Min Dimwind reaches final waypoint
            }

            return false;
        }
};

// 56503 - Min Dimwind (Summon)
struct npc_min_dimwind_summon : public ScriptedAI
{
    npc_min_dimwind_summon(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (!summoner->IsPlayer())
            return;

        Creature* amberleafScamp1 = me->FindNearestCreatureWithOptions(20.0f, { .StringId = "npc_amberleaf_scamp_1" });
        Creature* amberleafScamp2 = me->FindNearestCreatureWithOptions(20.0f, { .StringId = "npc_amberleaf_scamp_2" });
        Creature* amberleafScamp3 = me->FindNearestCreatureWithOptions(20.0f, { .StringId = "npc_amberleaf_scamp_3" });
        Creature* amberleafScamp5 = me->FindNearestCreatureWithOptions(20.0f, { .StringId = "npc_amberleaf_scamp_5" });

        if (!amberleafScamp1 || !amberleafScamp2 || !amberleafScamp3 || !amberleafScamp5)
            return;

        amberleafScamp1->AI()->Talk(SAY_AMBERLEAF_SCAMP_0);
        amberleafScamp1->GetMotionMaster()->MovePoint(0, amberleafPos[0]);

        amberleafScamp2->GetMotionMaster()->MovePoint(0, amberleafPos[1]);

        amberleafScamp3->GetMotionMaster()->MovePoint(0, amberleafPos[2]);

        amberleafScamp5->GetMotionMaster()->MovePoint(0, amberleafPos[4]);

        _scheduler.Schedule(Seconds(2), [this](TaskContext /*task*/)
        {
            Creature* amberleafScamp4 = me->FindNearestCreatureWithOptions(20.0f, { .StringId = "npc_amberleaf_scamp_4" });

            if (!amberleafScamp4)
                return;

            amberleafScamp4->AI()->Talk(SAY_AMBERLEAF_SCAMP_1);
            amberleafScamp4->GetMotionMaster()->MovePoint(0, amberleafPos[3]);
        });

        _scheduler.Schedule(Seconds(5), [this](TaskContext task)
        {
            me->SetFacingToObject(me->ToTempSummon()->GetSummonerUnit());
            Talk(SAY_MIN_DIMWIND_TEXT_0, me->ToTempSummon()->GetSummonerUnit());

            task.Schedule(Seconds(4), [this](TaskContext task)
            {
                Talk(SAY_MIN_DIMWIND_TEXT_1);

                task.Schedule(Seconds(4), [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePath(PATH_MOVE_RUN, false);
                });
            });
        });
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_MOVE_RUN)
        {
            switch (waypointId)
            {
                case WAYPOINT_ID_0:
                case WAYPOINT_ID_3:
                {
                    Talk(SAY_MIN_DIMWIND_TEXT_2);
                    break;
                }
                case WAYPOINT_ID_11:
                {
                    Talk(SAY_MIN_DIMWIND_TEXT_3);
                    me->GetMotionMaster()->MovePath(PATH_MOVE_WALK, false);
                    break;
                }
            }
        }
        else if (pathId == PATH_MOVE_WALK)
        {
            if (waypointId == WAYPOINT_ID_3)
            {
                me->SetFacingTo(0.575958f);
                me->DespawnOrUnsummon(2s);

                _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/)
                {
                    if (me->IsSummon())
                    {
                        Unit* summoner = me->ToTempSummon()->GetSummonerUnit();

                        if (!summoner)
                            return;

                        summoner->RemoveAurasDueToSpell(SPELL_SUMMON_CART_DRIVER);
                        PhasingHandler::OnConditionChange(summoner);
                    }
                });
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 54130 - Amberleaf Scamp
struct npc_amberleaf_scamp : public ScriptedAI
{
    npc_amberleaf_scamp(Creature* creature) : ScriptedAI(creature) {  }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == 0)
        {
            me->GetMotionMaster()->MoveRandom(10.0f);

            _scheduler.Schedule(Seconds(10), [this](TaskContext /*task*/)
            {
                me->GetMotionMaster()->MoveTargetedHome();
            });
        }
    }

    void JustReachedHome() override
    {
        me->GetMotionMaster()->MoveIdle();
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
    RegisterCreatureAI(npc_min_dimwind_summon);
    RegisterCreatureAI(npc_amberleaf_scamp);

    new at_min_dimwind_captured();
}

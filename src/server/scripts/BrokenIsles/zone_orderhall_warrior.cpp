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

#include "Containers.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "WaypointDefines.h"
#include <span>

enum ValarjarSpells
{
    SPELL_EMOTE_BELCH                                   = 65937,
    SPELL_WARRIOR_ORDER_FORMATION_SCENE                 = 193709,
    SPELL_CANCEL_COMPLETE_SCENE_WARRIOR_ORDER_FORMATION = 193711
};

enum Phases
{
    PHASE_ODYN      = 5107,
    PHASE_DANICA    = 5090
};

enum Quests
{
    QUEST_ODYN_AND_THE_VALARJAR = 39654
};

enum Creatures
{
    NPC_KILL_CREDIT_FOLLOWED_DANICA = 103036,
    NPC_DANICA_THE_RECLAIMER        = 93823,
    NPC_KILL_CREDIT_ARRIVED_AT_ODYN = 96532
};

enum Items
{
    ITEM_MONSTER_ITEM_MUTTON_WITH_BITE  = 2202,
    ITEM_MONSTER_ITEM_TANKARD_WOODEN    = 2703,
    ITEM_HOV_2H_AXE                     = 137176,
    ITEM_HOV_1H_SWORD                   = 137263,
    ITEM_HOV_SHIELD_2                   = 137265
};

struct npc_danica_the_reclaimer : public ScriptedAI
{
    npc_danica_the_reclaimer(Creature* creature) : ScriptedAI(creature) { }

    enum Points
    {
        POINT_FORGE_OF_ODYN,
        POINT_INTRODUCE_MEAD_HALL,
        POINT_ODYN
    };

    enum Texts
    {
        SAY_FIRST_LINE  = 1,
        SAY_SECOND_LINE = 2,
        SAY_THIRD_LINE  = 3
    };

    WaypointPath const DanicaPath01 =
    {
        POINT_FORGE_OF_ODYN,
        {
            { 0, 1050.219f, 7232.470f, 100.5846f },
            { 1, 1046.207f, 7240.372f, 100.5846f },
            { 2, 1040.963f, 7245.498f, 100.6819f },
            { 3, 1034.726f, 7250.083f, 100.5846f },
            { 4, 1027.422f, 7257.835f, 100.5846f },
            { 5, 1027.542f, 7259.735f, 100.5846f }
        },
        WaypointMoveType::Run,
        WaypointPathFlags::FlyingPath
    };

    WaypointPath const DanicaPath02 =
    {
        POINT_INTRODUCE_MEAD_HALL,
        {
            { 0, 1018.493f, 7247.438f, 100.5846f },
            { 1, 1013.535f, 7243.327f, 100.5846f },
            { 2, 1007.063f, 7235.723f, 100.5846f },
            { 3, 1003.337f, 7229.650f, 100.5846f },
            { 4, 995.4549f, 7227.286f, 100.5846f },
            { 5, 984.4410f, 7224.357f, 100.5846f }
        },
        WaypointMoveType::Run,
        WaypointPathFlags::FlyingPath
    };

    WaypointPath const DanicaPath03 =
    {
        POINT_ODYN,
        {
            { 0, 962.5208f, 7223.089f, 100.5846f },
            { 1, 934.2795f, 7223.116f, 100.5846f },
            { 2, 911.8507f, 7223.776f, 100.5846f },
            { 3, 879.0139f, 7224.100f, 100.9079f },
            { 4, 851.691f, 7224.5490f, 109.5846f }
        },
        WaypointMoveType::Run,
        WaypointPathFlags::FlyingPath
    };

    // Should be the player
    // Personal spawn ? Demon Creator is the player who accepts the quest, no phasing involved but the quest giver dissapears and gets replaced with a new one
    void IsSummonedBy(WorldObject* summoner) override
    {
        if (summoner->GetTypeId() != TYPEID_PLAYER)
            return;

        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        _summonerGuid = summoner->GetGUID();
        _scheduler.Schedule(2s, [this, summoner](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MovePath(DanicaPath01, false);
            Talk(SAY_FIRST_LINE, summoner);
        });
    }

    void WaypointPathEnded(uint32 /*pointId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case POINT_FORGE_OF_ODYN:
                _scheduler.Schedule(10s, [this](TaskContext /*context*/)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, _summonerGuid);
                    me->GetMotionMaster()->MovePath(DanicaPath02, false);
                    Talk(SAY_SECOND_LINE, player);
                });
                break;
            case POINT_INTRODUCE_MEAD_HALL:
                _scheduler.Schedule(10s, [this](TaskContext /*context*/)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, _summonerGuid);
                    me->GetMotionMaster()->MovePath(DanicaPath03, false);
                    Talk(SAY_THIRD_LINE, player);

                    if (player)
                        player->KilledMonsterCredit(NPC_KILL_CREDIT_FOLLOWED_DANICA);
                });
                break;
            case POINT_ODYN:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    // Should be some other way to do this...
    void OnQuestAccept(Player* player, Quest const* /*quest*/) override
    {
        me->SummonPersonalClone(me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _summonerGuid;
};

struct npc_feasting_valarjar : public ScriptedAI
{
    npc_feasting_valarjar(Creature* creature) : ScriptedAI(creature),
        _randomEmotes({ EMOTE_ONESHOT_EAT_NO_SHEATHE, EMOTE_ONESHOT_LAUGH_NO_SHEATHE, EMOTE_ONESHOT_ROAR, EMOTE_ONESHOT_LAUGH, EMOTE_ONESHOT_POINT,
            EMOTE_ONESHOT_TALK, EMOTE_ONESHOT_CHEER_NO_SHEATHE }) { }

    enum Points
    {
        POINT_LEAVING
    };

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void Reset() override
    {
        _scheduler.Schedule(5s, 30s, [this](TaskContext context)
        {
            Emote emoteID = Trinity::Containers::SelectRandomContainerElement(_randomEmotes);
            if (emoteID == EMOTE_ONESHOT_EAT_NO_SHEATHE)
            {
                me->SetVirtualItem(0, urand(0, 1) ? ITEM_MONSTER_ITEM_MUTTON_WITH_BITE : ITEM_MONSTER_ITEM_TANKARD_WOODEN);
                _scheduler.Schedule(1s, [this](TaskContext /*context*/)
                {
                    me->SetVirtualItem(0, 0);
                    if (roll_chance_i(85))
                        DoCastSelf(SPELL_EMOTE_BELCH);
                });
            }

            me->HandleEmoteCommand(emoteID);
            context.Repeat();
        });

        _scheduler.Schedule(5min, 20min, [this](TaskContext /*context*/)
        {
            float direction = me->GetOrientation() + M_PI;
            me->GetMotionMaster()->MovePoint(POINT_LEAVING, me->GetFirstCollisionPosition(5.0f, direction));
        });
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
            case POINT_LEAVING:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
    std::unordered_set<Emote> _randomEmotes;
};

struct npc_valarjar_paying_respect_to_odyn : ScriptedAI
{
    npc_valarjar_paying_respect_to_odyn(Creature* creature) : ScriptedAI(creature),
        _randomEmotes({ EMOTE_ONESHOT_POINT, EMOTE_ONESHOT_TALK, EMOTE_ONESHOT_NO }) { }

    enum Points
    {
        POINT_TABLE,
        POINT_ODYN,
        POINT_DESPAWN
    };

    virtual std::span<WaypointNode const> GetPathToTable() const = 0;
    virtual std::span<WaypointNode const> GetPathToOdyn() const = 0;
    virtual std::span<WaypointNode const> GetPathToDespawnPoint() const = 0;

    void Reset() override
    {
        me->GetMotionMaster()->MovePath({ POINT_TABLE, { GetPathToTable().begin(), GetPathToTable().end() }, WaypointMoveType::Walk, WaypointPathFlags::ExactSplinePath }, false);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
            case POINT_TABLE:
                _scheduler.Schedule(3s, 6s, [this](TaskContext /*context*/)
                {
                    me->HandleEmoteCommand(Trinity::Containers::SelectRandomContainerElement(_randomEmotes));
                });

                _scheduler.Schedule(7s, 15s, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePath({ POINT_ODYN, { GetPathToOdyn().begin(), GetPathToOdyn().end() }, WaypointMoveType::Walk, WaypointPathFlags::ExactSplinePath }, false);
                });
                break;
            case POINT_ODYN:
                _scheduler.Schedule(1s, 3s, [this](TaskContext /*context*/)
                {
                    me->PlayOneShotAnimKitId(1431);
                    _scheduler.Schedule(3s, 10s, [this](TaskContext /*context*/)
                    {
                        me->GetMotionMaster()->MovePath({ POINT_DESPAWN, { GetPathToDespawnPoint().begin(), GetPathToDespawnPoint().end() }, WaypointMoveType::Run, WaypointPathFlags::ExactSplinePath }, false);
                    });
                });
                break;
            case POINT_DESPAWN:
                me->DespawnOrUnsummon(2s);
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
    std::unordered_set<Emote> _randomEmotes;
};

struct npc_incoming_valarjar_aspirant_1 : public npc_valarjar_paying_respect_to_odyn
{
    npc_incoming_valarjar_aspirant_1(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    static constexpr WaypointNode IncommingValarjarAspirantPath01[] =
    {
        { 0, 876.7396f, 7220.805f, 98.91662f },
        { 1, 870.6129f, 7220.945f, 101.8951f },
        { 2, 865.0677f, 7220.975f, 103.7846f },
        { 3, 854.6389f, 7221.030f, 106.7846f },
        { 4, 851.1597f, 7220.292f, 106.7846f },
        { 5, 848.0573f, 7216.386f, 106.7846f },
        { 6, 844.7570f, 7210.920f, 106.7846f },
        { 7, 841.9844f, 7207.228f, 106.7846f },
        { 8, 839.2396f, 7203.619f, 107.5846f },
        { 9, 836.4844f, 7200.202f, 107.5846f },
        { 10, 834.2430f, 7196.000f, 107.5846f }
    };

    static constexpr WaypointNode IncommingValarjarAspirantPath02[] =
    {
        { 0, 828.5851f, 7204.096f, 106.7846f },
        { 1, 819.4636f, 7212.124f, 106.7846f },
        { 2, 814.2853f, 7215.074f, 106.7846f },
        { 3, 809.4948f, 7217.543f, 106.7846f },
        { 4, 806.0313f, 7219.614f, 106.7846f }
    };

    static constexpr WaypointNode IncommingValarjarAspirantPath03[] =
    {
        { 0, 824.1597f, 7221.822f, 106.7846f },
        { 1, 831.7500f, 7221.092f, 106.7846f },
        { 2, 842.4236f, 7222.208f, 106.7846f },
        { 3, 853.5781f, 7222.473f, 106.7846f },
        { 4, 863.9618f, 7223.012f, 103.7846f },
        { 5, 867.9358f, 7223.165f, 103.3735f },
        { 6, 880.6215f, 7222.569f, 97.78457f },
        { 7, 887.8438f, 7221.310f, 97.78457f },
        { 8, 903.7118f, 7215.743f, 97.78458f }
    };

    std::span<WaypointNode const> GetPathToTable() const override { return IncommingValarjarAspirantPath01; }
    std::span<WaypointNode const> GetPathToOdyn() const override { return IncommingValarjarAspirantPath02; }
    std::span<WaypointNode const> GetPathToDespawnPoint() const override { return IncommingValarjarAspirantPath03; }
};

struct npc_incoming_valarjar_aspirant_2 : public npc_valarjar_paying_respect_to_odyn
{
    npc_incoming_valarjar_aspirant_2(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    static constexpr WaypointNode IncommingValarjarAspirantPath01[] =
    {
        { 0, 890.5521f, 7235.710f, 97.78457f },
        { 1, 883.8073f, 7233.402f, 97.78457f },
        { 2, 872.1979f, 7234.018f, 101.2886f },
        { 3, 863.5941f, 7234.594f, 103.7846f },
        { 4, 855.2899f, 7235.626f, 106.7593f },
        { 5, 849.8177f, 7236.571f, 106.7846f },
        { 6, 845.7830f, 7241.082f, 106.7846f },
        { 7, 841.8489f, 7246.654f, 106.7846f },
        { 8, 839.7205f, 7250.986f, 106.7846f },
        { 9, 840.8889f, 7254.773f, 107.5846f },
        { 10, 841.9254f, 7259.517f, 107.5846f },
        { 11, 840.6077f, 7266.662f, 107.5846f }
    };

    static constexpr WaypointNode IncommingValarjarAspirantPath02[6] =
    {
        { 0, 838.1493f, 7260.027f, 107.5846f },
        { 1, 832.2691f, 7253.756f, 106.7846f },
        { 2, 823.1996f, 7246.677f, 106.7846f },
        { 3, 821.2500f, 7244.573f, 106.7846f },
        { 4, 815.8906f, 7241.437f, 106.7846f },
        { 5, 809.8281f, 7239.580f, 106.7846f }
    };

    static constexpr WaypointNode IncommingValarjarAspirantPath03[] =
    {
        { 0, 827.4757f, 7236.593f, 106.7846f },
        { 1, 837.1840f, 7236.047f, 106.7846f },
        { 2, 847.1684f, 7235.377f, 106.7846f },
        { 3, 854.7185f, 7235.294f, 106.7846f },
        { 4, 862.3524f, 7234.287f, 104.4290f },
        { 5, 882.3489f, 7233.743f, 97.78457f },
        { 6, 894.3768f, 7233.098f, 97.78457f },
        { 7, 906.0660f, 7232.520f, 97.78458f },
        { 8, 915.0070f, 7233.368f, 97.78458f },
        { 9, 924.6910f, 7233.694f, 97.78458f }
    };

    std::span<WaypointNode const> GetPathToTable() const override { return IncommingValarjarAspirantPath01; }
    std::span<WaypointNode const> GetPathToOdyn() const override { return IncommingValarjarAspirantPath02; }
    std::span<WaypointNode const> GetPathToDespawnPoint() const override { return IncommingValarjarAspirantPath03; }
};

struct npc_leaving_valarjar_1 : public npc_valarjar_paying_respect_to_odyn
{
    npc_leaving_valarjar_1(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    static constexpr WaypointNode PathLeavingValarjar01[] =
    {
        { 0, 802.5903f, 7304.605f, 106.7846f },
        { 1, 809.3333f, 7296.529f, 106.7846f },
        { 2, 811.8004f, 7293.676f, 106.7846f },
        { 3, 817.4219f, 7287.498f, 106.7846f },
        { 4, 821.0313f, 7283.637f, 106.7846f },
        { 5, 822.1111f, 7275.672f, 106.7846f },
        { 6, 826.4662f, 7270.601f, 107.5846f },
        { 7, 830.8212f, 7268.729f, 107.5846f }
    };

    static constexpr WaypointNode PathLeavingValarjar02[] =
    {
        { 0, 824.9757f, 7261.047f, 107.5846f },
        { 1, 822.0989f, 7256.705f, 106.7846f },
        { 2, 819.0261f, 7253.674f, 106.7846f },
        { 3, 813.1910f, 7249.034f, 106.7846f },
        { 4, 809.1493f, 7245.616f, 106.7846f },
        { 5, 806.3559f, 7243.057f, 106.7846f }
    };

    static constexpr WaypointNode PathLeavingValarjar03[] =
    {
        { 0, 825.3177f, 7244.253f, 106.7846f },
        { 1, 837.5816f, 7243.241f, 106.7846f },
        { 2, 845.0243f, 7240.063f, 106.7846f },
        { 3, 853.7274f, 7238.423f, 106.7953f },
        { 4, 862.9948f, 7238.000f, 103.9737f },
        { 5, 872.7899f, 7236.939f, 100.8285f },
        { 6, 882.8333f, 7235.922f, 97.78457f },
        { 7, 897.2813f, 7235.469f, 97.78457f },
        { 8, 908.8090f, 7234.836f, 97.78458f },
        { 9, 919.8750f, 7238.241f, 97.78458f }
    };

    std::span<WaypointNode const> GetPathToTable() const override { return PathLeavingValarjar01; }
    std::span<WaypointNode const> GetPathToOdyn() const override { return PathLeavingValarjar02; }
    std::span<WaypointNode const> GetPathToDespawnPoint() const override { return PathLeavingValarjar03; }
};

struct npc_leaving_valarjar_2 : public npc_valarjar_paying_respect_to_odyn
{
    npc_leaving_valarjar_2(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    static constexpr WaypointNode PathLeavingValarjar01[] =
    {
        { 0, 787.2361f, 7155.902f, 107.5846f },
        { 1, 792.4844f, 7154.038f, 106.7846f },
        { 2, 798.7830f, 7154.968f, 106.7846f },
        { 3, 807.8160f, 7162.251f, 106.7846f },
        { 4, 813.2882f, 7167.856f, 106.7846f },
        { 5, 816.4913f, 7170.818f, 106.7846f },
        { 6, 819.8299f, 7166.373f, 107.6281f }
    };

    static constexpr WaypointNode PathLeavingValarjar02[] =
    {
        { 0, 818.2708f, 7175.469f, 106.7846f },
        { 1, 819.5643f, 7185.691f, 106.7846f },
        { 2, 818.4184f, 7193.082f, 106.7846f },
        { 3, 818.8750f, 7199.256f, 106.7846f },
        { 4, 815.2361f, 7203.648f, 106.7846f },
        { 5, 809.6198f, 7208.319f, 106.7846f },
        { 6, 804.2743f, 7215.379f, 106.7846f }
    };

    static constexpr WaypointNode PathLeavingValarjar03[] =
    {
        { 0, 810.8403f, 7231.531f, 106.7846f },
        { 1, 807.5087f, 7248.719f, 106.7846f },
        { 2, 801.2587f, 7254.592f, 106.7846f },
        { 3, 794.6649f, 7265.814f, 107.5846f },
        { 4, 792.0191f, 7274.151f, 107.5846f },
        { 5, 790.1823f, 7282.182f, 107.5846f }
    };

    std::span<WaypointNode const> GetPathToTable() const override { return PathLeavingValarjar01; }
    std::span<WaypointNode const> GetPathToOdyn() const override { return PathLeavingValarjar02; }
    std::span<WaypointNode const> GetPathToDespawnPoint() const override { return PathLeavingValarjar03; }
};

struct npc_odyn : public ScriptedAI
{
    npc_odyn(Creature* creature) : ScriptedAI(creature) { }

    // Should be an better way of doing this...
    // What about a QuestScript with a hook "OnPlayerChangeArea" ? But The Great Mead Hall does not have a specific area...
    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_ODYN_AND_THE_VALARJAR) == QUEST_STATUS_INCOMPLETE)
            {
                if (player->IsInDist(me, 60.0f))
                {
                    player->KilledMonsterCredit(NPC_KILL_CREDIT_ARRIVED_AT_ODYN); // SPELL_WARRIOR_ORDER_FORMATION_SCENE does not has this credit.
                    player->CastSpell(player, SPELL_WARRIOR_ORDER_FORMATION_SCENE);
                }
            }
        }
    }
};

struct npc_spectating_valarjar : public ScriptedAI
{
    npc_spectating_valarjar(Creature* creature) : ScriptedAI(creature),
        _randomEmotes({ EMOTE_ONESHOT_CHEER_NO_SHEATHE, EMOTE_ONESHOT_SALUTE, EMOTE_ONESHOT_ROAR, EMOTE_ONESHOT_POINT, EMOTE_ONESHOT_SHOUT }) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void Reset() override
    {
        _scheduler.Schedule(5s, 30s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(Trinity::Containers::SelectRandomContainerElement(_randomEmotes));
            context.Repeat();
        });

        _scheduler.Schedule(5min, 20min, [this](TaskContext /*context*/)
        {
            float direction = me->GetOrientation() + M_PI;
            me->GetMotionMaster()->MovePoint(0, me->GetFirstCollisionPosition(5.0f, direction));
        });
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
            case 0:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
    std::unordered_set<Emote> _randomEmotes;
};

struct npc_valkyr_of_odyn : public ScriptedAI
{
    npc_valkyr_of_odyn(Creature* creature) : ScriptedAI(creature) { }

    virtual std::span<WaypointNode const> GetPath() const = 0;

    enum Points
    {
        POINT_DESPAWN = 1,
        POINT_JUMP,
        POINT_DESPAWN_JUMP
    };

    void Reset() override
    {
        if (me->GetPositionZ() >= 100.0f)
        {
            _scheduler.Schedule(3s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePath({ POINT_JUMP, { GetPath().begin(), GetPath().end() }, WaypointMoveType::Run, WaypointPathFlags::FlyingPath }, false);
            });
        }
        else
            me->GetMotionMaster()->MovePath({ POINT_DESPAWN, { GetPath().begin(), GetPath().end() }, WaypointMoveType::Run, WaypointPathFlags::FlyingPath }, false);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void WaypointPathEnded(uint32 /*pointId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case POINT_JUMP:
                _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
                {
                    /*
                     * (MovementMonsterSpline) (MovementSpline) MoveTime: 3111
                     * (MovementMonsterSpline) (MovementSpline) JumpGravity: 19.2911 -> +-Movement::gravity
                     * 1.4125f is guessed value. Which makes the JumpGravity way closer to the intended one. Not sure how to do it 100% blizzlike.
                     * Also the MoveTime is not correct but I don't know how to set it here.
                     */
                    me->GetMotionMaster()->MoveJump({ 1107.84f, 7222.57f, 38.9725f, me->GetOrientation() }, me->GetSpeed(MOVE_RUN), Movement::gravity * 1.4125f, POINT_DESPAWN_JUMP);
                });
                break;
            case POINT_DESPAWN:
                me->DespawnOrUnsummon(500ms);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
            case POINT_DESPAWN_JUMP:
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
};

struct npc_valkyr_of_odyn_1 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_1(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    static constexpr WaypointNode Path[] =
    {
        { 0, 996.5347f, 7321.393f, 124.0931f },
        { 1, 1009.880f, 7311.655f, 118.0898f },
        { 2, 1024.688f, 7293.689f, 120.4009f },
        { 3, 1038.288f, 7266.321f, 122.2708f },
        { 4, 1049.439f, 7235.418f, 120.1065f },
        { 5, 1067.825f, 7229.589f, 114.6320f },
        { 6, 1082.800f, 7223.660f, 98.63562f }
    };

    std::span<WaypointNode const> GetPath() const override { return Path; }
};

struct npc_valkyr_of_odyn_2 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_2(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    static constexpr WaypointNode Path[] =
    {
        { 0, 1113.635f, 7214.023f, 7.808200f },
        { 1, 1110.443f, 7213.999f, 17.28479f },
        { 2, 1108.583f, 7213.984f, 22.80371f },
        { 3, 1103.488f, 7221.702f, 70.68047f },
        { 4, 1101.911f, 7222.535f, 82.51234f },
        { 5, 1098.861f, 7222.271f, 90.03111f },
        { 6, 1095.129f, 7223.033f, 94.15130f },
        { 7, 1089.240f, 7223.335f, 97.94925f },
        { 8, 1077.932f, 7222.822f, 110.2143f },
        { 9, 1068.802f, 7223.216f, 110.2143f },
        { 10, 1045.356f, 7224.674f, 114.5371f },
        { 11, 1023.946f, 7224.304f, 120.0150f },
        { 12, 1002.535f, 7224.943f, 121.1011f },
        { 13, 911.7552f, 7227.165f, 121.7384f },
        { 14, 879.1285f, 7227.272f, 121.7384f },
        { 15, 830.8785f, 7233.613f, 121.7384f },
        { 16, 809.5052f, 7267.270f, 121.7384f },
        { 17, 795.2899f, 7311.849f, 121.7384f }
    };

    std::span<WaypointNode const> GetPath() const override { return Path; }
};

struct npc_valkyr_of_odyn_3 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_3(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    static constexpr WaypointNode Path[] =
    {
        { 0, 1133.929f, 7223.167f, 38.90330f },
        { 1, 1124.510f, 7222.310f, 42.15336f },
        { 2, 1119.903f, 7221.891f, 43.74335f },
        { 3, 1103.934f, 7227.212f, 69.99904f },
        { 4, 1097.554f, 7226.132f, 89.09371f },
        { 5, 1092.602f, 7224.059f, 101.1545f },
        { 6, 1078.701f, 7228.348f, 109.5599f },
        { 7, 1068.967f, 7232.247f, 116.7876f },
        { 8, 1053.540f, 7229.623f, 117.8927f },
        { 9, 1044.104f, 7242.757f, 118.7891f },
        { 10, 1031.111f, 7256.717f, 118.7891f },
        { 11, 1029.684f, 7288.019f, 126.3048f },
        { 12, 1029.889f, 7325.333f, 126.3061f },
        { 13, 1039.043f, 7365.176f, 133.2310f }
    };

    std::span<WaypointNode const> GetPath() const override { return Path; }
};

struct npc_valkyr_of_odyn_4 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_4(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    static constexpr WaypointNode Path[] =
    {
        { 0, 914.8663f, 7204.922f, 128.1687f },
        { 1, 945.4445f, 7216.170f, 128.1687f },
        { 2, 987.2483f, 7220.554f, 125.4318f },
        { 3, 1015.882f, 7222.849f, 126.0546f },
        { 4, 1053.023f, 7224.076f, 119.6729f },
        { 5, 1071.891f, 7222.934f, 108.9545f },
        { 6, 1081.530f, 7224.331f, 98.63076f }
    };

    std::span<WaypointNode const> GetPath() const override { return Path; }
};

struct npc_valkyr_of_odyn_5 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_5(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    static constexpr WaypointNode Path[] =
    {
        { 0, 1038.141f, 7134.033f, 105.8965f },
        { 1, 1033.373f, 7134.492f, 105.8965f },
        { 2, 1027.882f, 7136.373f, 105.8965f },
        { 3, 1026.943f, 7144.288f, 105.8965f },
        { 4, 1027.608f, 7167.030f, 108.4167f },
        { 5, 1027.767f, 7180.922f, 108.4167f },
        { 6, 1028.484f, 7197.977f, 108.4167f },
        { 7, 1034.113f, 7207.747f, 108.4167f },
        { 8, 1041.977f, 7216.452f, 108.4167f },
        { 9, 1054.269f, 7223.207f, 108.4167f },
        { 10, 1075.891f, 7224.811f, 101.7954f },
        { 11, 1082.438f, 7224.540f, 99.12900f }
    };

    std::span<WaypointNode const> GetPath() const override { return Path; }
};

struct npc_valkyr_of_odyn_6 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_6(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    static constexpr WaypointNode Path[] =
    {
        { 0, 1112.011f, 7233.799f, 45.87240f },
        { 1, 1107.887f, 7234.073f, 54.97818f },
        { 2, 1106.264f, 7234.181f, 58.56218f },
        { 3, 1099.969f, 7236.397f, 75.87664f },
        { 4, 1096.552f, 7233.196f, 85.53920f },
        { 5, 1095.531f, 7229.387f, 89.86687f },
        { 6, 1092.981f, 7225.366f, 97.69602f },
        { 7, 1082.800f, 7221.249f, 109.4660f },
        { 8, 1070.983f, 7218.749f, 112.6827f },
        { 9, 1057.455f, 7216.709f, 112.6827f },
        { 10, 1051.859f, 7210.338f, 112.6827f },
        { 11, 1042.427f, 7200.762f, 112.6827f },
        { 12, 1032.616f, 7183.982f, 112.6827f },
        { 13, 1027.792f, 7157.764f, 112.6827f },
        { 14, 1026.870f, 7126.981f, 112.6827f },
        { 15, 1053.083f, 7102.808f, 125.9283f },
        { 16, 1055.122f, 7059.807f, 130.4395f }
    };

    std::span<WaypointNode const> GetPath() const override { return Path; }
};

struct npc_valkyr_of_odyn_7 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_7(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    static constexpr WaypointNode Path[] =
    {
        { 0, 1064.076f, 7305.979f, 117.5428f },
        { 1, 1058.290f, 7305.543f, 117.5428f },
        { 2, 1046.578f, 7305.583f, 117.5428f },
        { 3, 1034.373f, 7295.979f, 117.5428f },
        { 4, 1026.639f, 7275.582f, 114.1900f },
        { 5, 1030.729f, 7251.381f, 114.1900f },
        { 6, 1040.950f, 7237.213f, 114.1900f },
        { 7, 1057.274f, 7229.228f, 114.1900f },
        { 8, 1070.297f, 7226.421f, 111.7502f },
        { 9, 1082.146f, 7225.846f, 101.0798f }
    };

    std::span<WaypointNode const> GetPath() const override { return Path; }
};

struct npc_weapon_inspector_valarjar : public ScriptedAI
{
    npc_weapon_inspector_valarjar(Creature* creature) : ScriptedAI(creature),
        _randomWeapons({ { ITEM_HOV_2H_AXE, 0 }, { ITEM_HOV_1H_SWORD, ITEM_HOV_SHIELD_2 } }) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void Reset() override
    {
        _scheduler.Schedule(15s, 20s, [this](TaskContext context)
        {
            me->SetAIAnimKitId(0);
            std::pair<uint32, uint32> weapons = Trinity::Containers::SelectRandomContainerElement(_randomWeapons);
            me->SetVirtualItem(0, weapons.first);
            me->SetVirtualItem(1, weapons.second);

            context.Schedule(8s, 10s, [this](TaskContext context)
            {
                me->SetVirtualItem(0, 0);
                me->SetVirtualItem(1, 0);
                context.Schedule(10s, [this](TaskContext /*context*/)
                {
                    me->SetAIAnimKitId(1583);
                });
            });

            context.Repeat(30s);
        });
    }

private:
    TaskScheduler _scheduler;
    std::unordered_set<std::pair<uint32, uint32>> _randomWeapons;
};

class scene_odyn_intro : public SceneScript
{
public:
    scene_odyn_intro() : SceneScript("scene_odyn_intro") { }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        PhasingHandler::RemovePhase(player, PHASE_DANICA, false);
        PhasingHandler::RemovePhase(player, PHASE_ODYN, true);
        player->SetControlled(true, UNIT_STATE_ROOT);
    }

    // Called when a scene is canceled
    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        Finish(player);
    }

    // Called when a scene is completed
    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        Finish(player);
    }

    void Finish(Player* player)
    {
        PhasingHandler::AddPhase(player, PHASE_ODYN, true);
        player->SetControlled(false, UNIT_STATE_ROOT);
        player->CastSpell(player, SPELL_CANCEL_COMPLETE_SCENE_WARRIOR_ORDER_FORMATION);
    }
};

void AddSC_orderhall_warrior()
{
    RegisterCreatureAI(npc_danica_the_reclaimer);
    RegisterCreatureAI(npc_feasting_valarjar);
    RegisterCreatureAI(npc_incoming_valarjar_aspirant_1);
    RegisterCreatureAI(npc_incoming_valarjar_aspirant_2);
    RegisterCreatureAI(npc_leaving_valarjar_1);
    RegisterCreatureAI(npc_leaving_valarjar_2);
    RegisterCreatureAI(npc_odyn);
    RegisterCreatureAI(npc_spectating_valarjar);
    RegisterCreatureAI(npc_valkyr_of_odyn_1);
    RegisterCreatureAI(npc_valkyr_of_odyn_2);
    RegisterCreatureAI(npc_valkyr_of_odyn_3);
    RegisterCreatureAI(npc_valkyr_of_odyn_4);
    RegisterCreatureAI(npc_valkyr_of_odyn_5);
    RegisterCreatureAI(npc_valkyr_of_odyn_6);
    RegisterCreatureAI(npc_valkyr_of_odyn_7);
    RegisterCreatureAI(npc_weapon_inspector_valarjar);
    new scene_odyn_intro();
}

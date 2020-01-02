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

#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"

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

    Position const DanicaPath01[6] =
    {
        { 1050.219f, 7232.470f, 100.5846f },
        { 1046.207f, 7240.372f, 100.5846f },
        { 1040.963f, 7245.498f, 100.6819f },
        { 1034.726f, 7250.083f, 100.5846f },
        { 1027.422f, 7257.835f, 100.5846f },
        { 1027.542f, 7259.735f, 100.5846f }
    };

    using DanicaPath01Size = std::extent<decltype(DanicaPath01)>;

    Position const DanicaPath02[6] =
    {
        { 1018.493f, 7247.438f, 100.5846f },
        { 1013.535f, 7243.327f, 100.5846f },
        { 1007.063f, 7235.723f, 100.5846f },
        { 1003.337f, 7229.650f, 100.5846f },
        { 995.4549f, 7227.286f, 100.5846f },
        { 984.4410f, 7224.357f, 100.5846f }
    };

    using DanicaPath02Size = std::extent<decltype(DanicaPath02)>;

    Position const DanicaPath03[5] =
    {
        { 962.5208f, 7223.089f, 100.5846f },
        { 934.2795f, 7223.116f, 100.5846f },
        { 911.8507f, 7223.776f, 100.5846f },
        { 879.0139f, 7224.100f, 100.9079f },
        { 851.691f, 7224.5490f, 109.5846f }
    };

    using DanicaPath03Size = std::extent<decltype(DanicaPath03)>;

    enum Texts
    {
        SAY_FIRST_LINE  = 1,
        SAY_SECOND_LINE = 2,
        SAY_THIRD_LINE  = 3
    };

    enum Points
    {
        POINT_FORGE_OF_ODYN,
        POINT_INTRODUCE_MEAD_HALL,
        POINT_ODYN
    };

    // Should be the player
    // Personal spawn ? Demon Creator is the player who accepts the quest, no phasing involved but the quest giver dissapears and gets replaced with a new one
    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner->GetTypeId() != TYPEID_PLAYER)
            return;

        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        _summonerGuid = summoner->GetGUID();
        _scheduler.Schedule(2s, [this, summoner](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MoveSmoothPath(POINT_FORGE_OF_ODYN, DanicaPath01, DanicaPath01Size::value, false, true);
            Talk(SAY_FIRST_LINE, summoner);
        });
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
            case POINT_FORGE_OF_ODYN:
                _scheduler.Schedule(10s, [this](TaskContext /*context*/)
                {
                    Player* player = ObjectAccessor::FindConnectedPlayer(_summonerGuid);
                    me->GetMotionMaster()->MoveSmoothPath(POINT_INTRODUCE_MEAD_HALL, DanicaPath02, DanicaPath02Size::value, false, true);
                    Talk(SAY_SECOND_LINE, player);
                });
                break;
            case POINT_INTRODUCE_MEAD_HALL:
                _scheduler.Schedule(10s, [this](TaskContext /*context*/)
                {
                    Player* player = ObjectAccessor::FindConnectedPlayer(_summonerGuid);
                    me->GetMotionMaster()->MoveSmoothPath(POINT_ODYN, DanicaPath03, DanicaPath03Size::value, false, true);
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
    void sQuestAccept(Player* player, Quest const* /*quest*/) override
    {
        TempSummon* summon = player->SummonCreature(NPC_DANICA_THE_RECLAIMER, 1059.613f, 7224.605f, 100.4608f, 0.03462749f, TEMPSUMMON_MANUAL_DESPAWN, 0, true);
        if (!summon)
            return;

        summon->SetDemonCreatorGUID(player->GetGUID());
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
            uint32 emoteID = Trinity::Containers::SelectRandomContainerElement(_randomEmotes);
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
    std::unordered_set<uint32> _randomEmotes;
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

    virtual size_t GetPathToTableSize() const = 0;
    virtual Position const* GetPathToTable() const = 0;
    virtual size_t GetPathToOdynSize() const = 0;
    virtual Position const* GetPathToOdyn() const = 0;
    virtual size_t GetPathToDespawnPointSize() const = 0;
    virtual Position const* GetPathToDespawnPoint() const = 0;

    void Reset() override
    {
        me->GetMotionMaster()->MoveSmoothPath(POINT_TABLE, GetPathToTable(), GetPathToTableSize(), true);
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
                    me->GetMotionMaster()->MoveSmoothPath(POINT_ODYN, GetPathToOdyn(), GetPathToOdynSize(), true);
                });
                break;
            case POINT_ODYN:
                _scheduler.Schedule(1s, 3s, [this](TaskContext /*context*/)
                {
                    me->PlayOneShotAnimKitId(1431);
                    _scheduler.Schedule(3s, 10s, [this](TaskContext /*context*/)
                    {
                        me->GetMotionMaster()->MoveSmoothPath(POINT_DESPAWN, GetPathToDespawnPoint(), GetPathToDespawnPointSize());
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
    std::unordered_set<uint32> _randomEmotes;
};

struct npc_incoming_valarjar_aspirant_1 : public npc_valarjar_paying_respect_to_odyn
{
    npc_incoming_valarjar_aspirant_1(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    Position const IncommingValarjarAspirantPath01[11] =
    {
        { 876.7396f, 7220.805f, 98.91662f },
        { 870.6129f, 7220.945f, 101.8951f },
        { 865.0677f, 7220.975f, 103.7846f },
        { 854.6389f, 7221.030f, 106.7846f },
        { 851.1597f, 7220.292f, 106.7846f },
        { 848.0573f, 7216.386f, 106.7846f },
        { 844.7570f, 7210.920f, 106.7846f },
        { 841.9844f, 7207.228f, 106.7846f },
        { 839.2396f, 7203.619f, 107.5846f },
        { 836.4844f, 7200.202f, 107.5846f },
        { 834.2430f, 7196.000f, 107.5846f }
    };

    using IncommingValarjarAspirantPath01Size = std::extent<decltype(IncommingValarjarAspirantPath01)>;

    Position const IncommingValarjarAspirantPath02[5] =
    {
        { 828.5851f, 7204.096f, 106.7846f },
        { 819.4636f, 7212.124f, 106.7846f },
        { 814.2853f, 7215.074f, 106.7846f },
        { 809.4948f, 7217.543f, 106.7846f },
        { 806.0313f, 7219.614f, 106.7846f }
    };

    using IncommingValarjarAspirantPath02Size = std::extent<decltype(IncommingValarjarAspirantPath02)>;

    Position const IncommingValarjarAspirantPath03[9] =
    {
        { 824.1597f, 7221.822f, 106.7846f },
        { 831.7500f, 7221.092f, 106.7846f },
        { 842.4236f, 7222.208f, 106.7846f },
        { 853.5781f, 7222.473f, 106.7846f },
        { 863.9618f, 7223.012f, 103.7846f },
        { 867.9358f, 7223.165f, 103.3735f },
        { 880.6215f, 7222.569f, 97.78457f },
        { 887.8438f, 7221.310f, 97.78457f },
        { 903.7118f, 7215.743f, 97.78458f }
    };

    using IncommingValarjarAspirantPath03Size = std::extent<decltype(IncommingValarjarAspirantPath03)>;

    size_t GetPathToTableSize() const override { return IncommingValarjarAspirantPath01Size::value; }
    Position const* GetPathToTable() const override { return IncommingValarjarAspirantPath01; }
    size_t GetPathToOdynSize() const override { return IncommingValarjarAspirantPath02Size::value; }
    Position const* GetPathToOdyn() const override { return IncommingValarjarAspirantPath02; }
    size_t GetPathToDespawnPointSize() const override { return IncommingValarjarAspirantPath03Size::value; }
    Position const* GetPathToDespawnPoint() const override { return IncommingValarjarAspirantPath03; }
};

struct npc_incoming_valarjar_aspirant_2 : public npc_valarjar_paying_respect_to_odyn
{
    npc_incoming_valarjar_aspirant_2(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    Position const IncommingValarjarAspirantPath01[12] =
    {
        { 890.5521f, 7235.710f, 97.78457f },
        { 883.8073f, 7233.402f, 97.78457f },
        { 872.1979f, 7234.018f, 101.2886f },
        { 863.5941f, 7234.594f, 103.7846f },
        { 855.2899f, 7235.626f, 106.7593f },
        { 849.8177f, 7236.571f, 106.7846f },
        { 845.7830f, 7241.082f, 106.7846f },
        { 841.8489f, 7246.654f, 106.7846f },
        { 839.7205f, 7250.986f, 106.7846f },
        { 840.8889f, 7254.773f, 107.5846f },
        { 841.9254f, 7259.517f, 107.5846f },
        { 840.6077f, 7266.662f, 107.5846f }
    };

    using IncommingValarjarAspirantPath01Size = std::extent<decltype(IncommingValarjarAspirantPath01)>;

    Position const IncommingValarjarAspirantPath02[6] =
    {
        { 838.1493f, 7260.027f, 107.5846f },
        { 832.2691f, 7253.756f, 106.7846f },
        { 823.1996f, 7246.677f, 106.7846f },
        { 821.2500f, 7244.573f, 106.7846f },
        { 815.8906f, 7241.437f, 106.7846f },
        { 809.8281f, 7239.580f, 106.7846f }
    };

    using IncommingValarjarAspirantPath02Size = std::extent<decltype(IncommingValarjarAspirantPath02)>;

    Position const IncommingValarjarAspirantPath03[10] =
    {
        { 827.4757f, 7236.593f, 106.7846f },
        { 837.1840f, 7236.047f, 106.7846f },
        { 847.1684f, 7235.377f, 106.7846f },
        { 854.7185f, 7235.294f, 106.7846f },
        { 862.3524f, 7234.287f, 104.4290f },
        { 882.3489f, 7233.743f, 97.78457f },
        { 894.3768f, 7233.098f, 97.78457f },
        { 906.0660f, 7232.520f, 97.78458f },
        { 915.0070f, 7233.368f, 97.78458f },
        { 924.6910f, 7233.694f, 97.78458f }
    };

    using IncommingValarjarAspirantPath03Size = std::extent<decltype(IncommingValarjarAspirantPath03)>;

    size_t GetPathToTableSize() const override { return IncommingValarjarAspirantPath01Size::value; }
    Position const* GetPathToTable() const override { return IncommingValarjarAspirantPath01; }
    size_t GetPathToOdynSize() const override { return IncommingValarjarAspirantPath02Size::value; }
    Position const* GetPathToOdyn() const override { return IncommingValarjarAspirantPath02; }
    size_t GetPathToDespawnPointSize() const override { return IncommingValarjarAspirantPath03Size::value; }
    Position const* GetPathToDespawnPoint() const override { return IncommingValarjarAspirantPath03; }
};

struct npc_leaving_valarjar_1 : public npc_valarjar_paying_respect_to_odyn
{
    npc_leaving_valarjar_1(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    Position const PathLeavingValarjar01[8] =
    {
        { 802.5903f, 7304.605f, 106.7846f },
        { 809.3333f, 7296.529f, 106.7846f },
        { 811.8004f, 7293.676f, 106.7846f },
        { 817.4219f, 7287.498f, 106.7846f },
        { 821.0313f, 7283.637f, 106.7846f },
        { 822.1111f, 7275.672f, 106.7846f },
        { 826.4662f, 7270.601f, 107.5846f },
        { 830.8212f, 7268.729f, 107.5846f }
    };

    using PathLeavingValarjar01Size = std::extent<decltype(PathLeavingValarjar01)>;

    Position const PathLeavingValarjar02[6] =
    {
        { 824.9757f, 7261.047f, 107.5846f },
        { 822.0989f, 7256.705f, 106.7846f },
        { 819.0261f, 7253.674f, 106.7846f },
        { 813.1910f, 7249.034f, 106.7846f },
        { 809.1493f, 7245.616f, 106.7846f },
        { 806.3559f, 7243.057f, 106.7846f }
    };

    using PathLeavingValarjar02Size = std::extent<decltype(PathLeavingValarjar02)>;

    Position const PathLeavingValarjar03[10] =
    {
        { 825.3177f, 7244.253f, 106.7846f },
        { 837.5816f, 7243.241f, 106.7846f },
        { 845.0243f, 7240.063f, 106.7846f },
        { 853.7274f, 7238.423f, 106.7953f },
        { 862.9948f, 7238.000f, 103.9737f },
        { 872.7899f, 7236.939f, 100.8285f },
        { 882.8333f, 7235.922f, 97.78457f },
        { 897.2813f, 7235.469f, 97.78457f },
        { 908.8090f, 7234.836f, 97.78458f },
        { 919.8750f, 7238.241f, 97.78458f }
    };

    using PathLeavingValarjar03Size = std::extent<decltype(PathLeavingValarjar03)>;

    size_t GetPathToTableSize() const override { return PathLeavingValarjar01Size::value; }
    Position const* GetPathToTable() const override { return PathLeavingValarjar01; }
    size_t GetPathToOdynSize() const override { return PathLeavingValarjar02Size::value; }
    Position const* GetPathToOdyn() const override { return PathLeavingValarjar02; }
    size_t GetPathToDespawnPointSize() const override { return PathLeavingValarjar03Size::value; }
    Position const* GetPathToDespawnPoint() const override { return PathLeavingValarjar03; }
};

struct npc_leaving_valarjar_2 : public npc_valarjar_paying_respect_to_odyn
{
    npc_leaving_valarjar_2(Creature* creature) : npc_valarjar_paying_respect_to_odyn(creature) { }

    Position const PathLeavingValarjar01[7] =
    {
        { 787.2361f, 7155.902f, 107.5846f },
        { 792.4844f, 7154.038f, 106.7846f },
        { 798.7830f, 7154.968f, 106.7846f },
        { 807.8160f, 7162.251f, 106.7846f },
        { 813.2882f, 7167.856f, 106.7846f },
        { 816.4913f, 7170.818f, 106.7846f },
        { 819.8299f, 7166.373f, 107.6281f }
    };

    using PathLeavingValarjar01Size = std::extent<decltype(PathLeavingValarjar01)>;

    Position const PathLeavingValarjar02[7] =
    {
        { 818.2708f, 7175.469f, 106.7846f },
        { 819.5643f, 7185.691f, 106.7846f },
        { 818.4184f, 7193.082f, 106.7846f },
        { 818.8750f, 7199.256f, 106.7846f },
        { 815.2361f, 7203.648f, 106.7846f },
        { 809.6198f, 7208.319f, 106.7846f },
        { 804.2743f, 7215.379f, 106.7846f }
    };

    using PathLeavingValarjar02Size = std::extent<decltype(PathLeavingValarjar02)>;

    Position const PathLeavingValarjar03[6] =
    {
        { 810.8403f, 7231.531f, 106.7846f },
        { 807.5087f, 7248.719f, 106.7846f },
        { 801.2587f, 7254.592f, 106.7846f },
        { 794.6649f, 7265.814f, 107.5846f },
        { 792.0191f, 7274.151f, 107.5846f },
        { 790.1823f, 7282.182f, 107.5846f }
    };

    using PathLeavingValarjar03Size = std::extent<decltype(PathLeavingValarjar03)>;

    size_t GetPathToTableSize() const override { return PathLeavingValarjar01Size::value; }
    Position const* GetPathToTable() const override { return PathLeavingValarjar01; }
    size_t GetPathToOdynSize() const override { return PathLeavingValarjar02Size::value; }
    Position const* GetPathToOdyn() const override { return PathLeavingValarjar02; }
    size_t GetPathToDespawnPointSize() const override { return PathLeavingValarjar03Size::value; }
    Position const* GetPathToDespawnPoint() const override { return PathLeavingValarjar03; }
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
    std::unordered_set<uint32> _randomEmotes;
};

struct npc_valkyr_of_odyn : public ScriptedAI
{
    npc_valkyr_of_odyn(Creature* creature) : ScriptedAI(creature) { }

    virtual Position const* GetPath() const = 0;
    virtual size_t GetPathSize() const = 0;

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
                me->GetMotionMaster()->MoveSmoothPath(POINT_JUMP, GetPath(), GetPathSize(), false, true);
            });
        }
        else
            me->GetMotionMaster()->MoveSmoothPath(POINT_DESPAWN, GetPath(), GetPathSize(), false, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
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

    Position const Path[7] =
    {
        { 996.5347f, 7321.393f, 124.0931f },
        { 1009.880f, 7311.655f, 118.0898f },
        { 1024.688f, 7293.689f, 120.4009f },
        { 1038.288f, 7266.321f, 122.2708f },
        { 1049.439f, 7235.418f, 120.1065f },
        { 1067.825f, 7229.589f, 114.6320f },
        { 1082.800f, 7223.660f, 98.63562f }
    };

    using PathSize = std::extent<decltype(Path)>;

    Position const* GetPath() const override { return Path; }
    size_t GetPathSize() const override { return PathSize::value; }
};

struct npc_valkyr_of_odyn_2 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_2(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    Position const Path[18] =
    {
        { 1113.635f, 7214.023f, 7.808200f },
        { 1110.443f, 7213.999f, 17.28479f },
        { 1108.583f, 7213.984f, 22.80371f },
        { 1103.488f, 7221.702f, 70.68047f },
        { 1101.911f, 7222.535f, 82.51234f },
        { 1098.861f, 7222.271f, 90.03111f },
        { 1095.129f, 7223.033f, 94.15130f },
        { 1089.240f, 7223.335f, 97.94925f },
        { 1077.932f, 7222.822f, 110.2143f },
        { 1068.802f, 7223.216f, 110.2143f },
        { 1045.356f, 7224.674f, 114.5371f },
        { 1023.946f, 7224.304f, 120.0150f },
        { 1002.535f, 7224.943f, 121.1011f },
        { 911.7552f, 7227.165f, 121.7384f },
        { 879.1285f, 7227.272f, 121.7384f },
        { 830.8785f, 7233.613f, 121.7384f },
        { 809.5052f, 7267.270f, 121.7384f },
        { 795.2899f, 7311.849f, 121.7384f }
    };

    using PathSize = std::extent<decltype(Path)>;

    Position const* GetPath() const override { return Path; }
    size_t GetPathSize() const override { return PathSize::value; }
};

struct npc_valkyr_of_odyn_3 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_3(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    Position const Path[14] =
    {
        { 1133.929f, 7223.167f, 38.90330f },
        { 1124.510f, 7222.310f, 42.15336f },
        { 1119.903f, 7221.891f, 43.74335f },
        { 1103.934f, 7227.212f, 69.99904f },
        { 1097.554f, 7226.132f, 89.09371f },
        { 1092.602f, 7224.059f, 101.1545f },
        { 1078.701f, 7228.348f, 109.5599f },
        { 1068.967f, 7232.247f, 116.7876f },
        { 1053.540f, 7229.623f, 117.8927f },
        { 1044.104f, 7242.757f, 118.7891f },
        { 1031.111f, 7256.717f, 118.7891f },
        { 1029.684f, 7288.019f, 126.3048f },
        { 1029.889f, 7325.333f, 126.3061f },
        { 1039.043f, 7365.176f, 133.2310f }
    };

    using PathSize = std::extent<decltype(Path)>;

    Position const* GetPath() const override { return Path; }
    size_t GetPathSize() const override { return PathSize::value; }
};

struct npc_valkyr_of_odyn_4 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_4(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    Position const Path[7] =
    {
        { 914.8663f, 7204.922f, 128.1687f },
        { 945.4445f, 7216.170f, 128.1687f },
        { 987.2483f, 7220.554f, 125.4318f },
        { 1015.882f, 7222.849f, 126.0546f },
        { 1053.023f, 7224.076f, 119.6729f },
        { 1071.891f, 7222.934f, 108.9545f },
        { 1081.530f, 7224.331f, 98.63076f }
    };

    using PathSize = std::extent<decltype(Path)>;

    Position const* GetPath() const override { return Path; }
    size_t GetPathSize() const override { return PathSize::value; }
};

struct npc_valkyr_of_odyn_5 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_5(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    Position const Path[12] =
    {
        { 1038.141f, 7134.033f, 105.8965f },
        { 1033.373f, 7134.492f, 105.8965f },
        { 1027.882f, 7136.373f, 105.8965f },
        { 1026.943f, 7144.288f, 105.8965f },
        { 1027.608f, 7167.030f, 108.4167f },
        { 1027.767f, 7180.922f, 108.4167f },
        { 1028.484f, 7197.977f, 108.4167f },
        { 1034.113f, 7207.747f, 108.4167f },
        { 1041.977f, 7216.452f, 108.4167f },
        { 1054.269f, 7223.207f, 108.4167f },
        { 1075.891f, 7224.811f, 101.7954f },
        { 1082.438f, 7224.540f, 99.12900f }
    };

    using PathSize = std::extent<decltype(Path)>;

    Position const* GetPath() const override { return Path; }
    size_t GetPathSize() const override { return PathSize::value; }
};

struct npc_valkyr_of_odyn_6 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_6(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    Position const Path[17] =
    {
        { 1112.011f, 7233.799f, 45.87240f },
        { 1107.887f, 7234.073f, 54.97818f },
        { 1106.264f, 7234.181f, 58.56218f },
        { 1099.969f, 7236.397f, 75.87664f },
        { 1096.552f, 7233.196f, 85.53920f },
        { 1095.531f, 7229.387f, 89.86687f },
        { 1092.981f, 7225.366f, 97.69602f },
        { 1082.800f, 7221.249f, 109.4660f },
        { 1070.983f, 7218.749f, 112.6827f },
        { 1057.455f, 7216.709f, 112.6827f },
        { 1051.859f, 7210.338f, 112.6827f },
        { 1042.427f, 7200.762f, 112.6827f },
        { 1032.616f, 7183.982f, 112.6827f },
        { 1027.792f, 7157.764f, 112.6827f },
        { 1026.870f, 7126.981f, 112.6827f },
        { 1053.083f, 7102.808f, 125.9283f },
        { 1055.122f, 7059.807f, 130.4395f }
    };

    using PathSize = std::extent<decltype(Path)>;

    Position const* GetPath() const override { return Path; }
    size_t GetPathSize() const override { return PathSize::value; }
};

struct npc_valkyr_of_odyn_7 : public npc_valkyr_of_odyn
{
    npc_valkyr_of_odyn_7(Creature* creature) : npc_valkyr_of_odyn(creature) { }

    Position const Path[10] =
    {
        { 1064.076f, 7305.979f, 117.5428f },
        { 1058.290f, 7305.543f, 117.5428f },
        { 1046.578f, 7305.583f, 117.5428f },
        { 1034.373f, 7295.979f, 117.5428f },
        { 1026.639f, 7275.582f, 114.1900f },
        { 1030.729f, 7251.381f, 114.1900f },
        { 1040.950f, 7237.213f, 114.1900f },
        { 1057.274f, 7229.228f, 114.1900f },
        { 1070.297f, 7226.421f, 111.7502f },
        { 1082.146f, 7225.846f, 101.0798f }
    };

    using PathSize = std::extent<decltype(Path)>;

    Position const* GetPath() const override { return Path; }
    size_t GetPathSize() const override { return PathSize::value; }
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

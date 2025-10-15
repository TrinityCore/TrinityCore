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
#include "G3DPosition.hpp"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"

/*####
# npc_rizzle_sprysprocket
####*/

enum RizzleSprysprocketData
{
    QUEST_CHASING_THE_MOONSTONE = 10994,

    NPC_DEPTH_CHARGE = 23025,

    SPELL_RIZZLE_BLACKJACK = 39865,
    SPELL_RIZZLE_ESCAPE = 39871,
    SPELL_RIZZLE_FROST_GRENADE = 40525,
    SPELL_DEPTH_CHARGE_TRAP = 38576,
    SPELL_PERIODIC_DEPTH_CHARGE = 39912,
    SPELL_GIVE_SOUTHFURY_MOONSTONE = 39886,

    SAY_RIZZLE_START = 0,
    SAY_RIZZLE_GRENADE = 1,
    SAY_RIZZLE_FINAL = 2,
    MSG_ESCAPE_NOTICE = 3,

    GOSSIP_MENU_GET_MOONSTONE = 57025,
    GOSSIP_OPTION_GET_MOONSTONE = 0,

    POINT_END = 1
};

static constexpr uint8 const RizzlePathSize = 58;
G3D::Vector3 const RizzlePath[RizzlePathSize] =
{
    { 3691.97f, -3962.41f, 35.9118f },
    { 3675.02f, -3960.49f, 35.9118f },
    { 3653.19f, -3958.33f, 33.9118f },
    { 3621.12f, -3958.51f, 29.9118f },
    { 3604.86f, -3963,     29.9118f },
    { 3569.94f, -3970.25f, 29.9118f },
    { 3541.03f, -3975.64f, 29.9118f },
    { 3510.84f, -3978.71f, 29.9118f },
    { 3472.7f,  -3997.07f, 29.9118f },
    { 3439.15f, -4014.55f, 29.9118f },
    { 3412.8f,  -4025.87f, 29.9118f },
    { 3384.95f, -4038.04f, 29.9118f },
    { 3346.77f, -4052.93f, 29.9118f },
    { 3299.56f, -4071.59f, 29.9118f },
    { 3261.22f, -4080.38f, 30.9118f },
    { 3220.68f, -4083.09f, 31.9118f },
    { 3187.11f, -4070.45f, 33.9118f },
    { 3162.78f, -4062.75f, 33.9118f },
    { 3136.09f, -4050.32f, 33.9118f },
    { 3119.47f, -4044.51f, 36.0363f },
    { 3098.95f, -4019.8f,  33.9118f },
    { 3073.07f, -4011.42f, 33.9118f },
    { 3051.71f, -3993.37f, 33.9118f },
    { 3027.52f, -3978.6f,  33.9118f },
    { 3003.78f, -3960.14f, 33.9118f },
    { 2977.99f, -3941.98f, 31.9118f },
    { 2964.57f, -3932.07f, 30.9118f },
    { 2947.9f,  -3921.31f, 29.9118f },
    { 2924.91f, -3910.8f,  29.9118f },
    { 2903.04f, -3896.42f, 29.9118f },
    { 2884.75f, -3874.03f, 29.9118f },
    { 2868.19f, -3851.48f, 29.9118f },
    { 2854.62f, -3819.72f, 29.9118f },
    { 2825.53f, -3790.4f,  29.9118f },
    { 2804.31f, -3773.05f, 29.9118f },
    { 2769.78f, -3763.57f, 29.9118f },
    { 2727.23f, -3745.92f, 30.9118f },
    { 2680.12f, -3737.49f, 30.9118f },
    { 2647.62f, -3739.94f, 30.9118f },
    { 2616.6f,  -3745.75f, 30.9118f },
    { 2589.38f, -3731.97f, 30.9118f },
    { 2562.94f, -3722.35f, 31.9118f },
    { 2521.05f, -3716.6f,  31.9118f },
    { 2485.26f, -3706.67f, 31.9118f },
    { 2458.93f, -3696.67f, 31.9118f },
    { 2432,     -3692.03f, 31.9118f },
    { 2399.59f, -3681.97f, 31.9118f },
    { 2357.75f, -3666.6f,  31.9118f },
    { 2311.99f, -3656.88f, 31.9118f },
    { 2263.41f, -3649.55f, 31.9118f },
    { 2209.05f, -3641.76f, 31.9118f },
    { 2164.83f, -3637.64f, 31.9118f },
    { 2122.42f, -3639,     31.9118f },
    { 2075.73f, -3643.59f, 31.9118f },
    { 2033.59f, -3649.52f, 31.9118f },
    { 1985.22f, -3662.99f, 31.9118f },
    { 1927.09f, -3679.56f, 33.9118f },
    { 1873.57f, -3695.32f, 33.9118f }
};

struct npc_rizzle_sprysprocket : public ScriptedAI
{
    npc_rizzle_sprysprocket(Creature* creature) : ScriptedAI(creature)  { }

    void Reset() override
    {
        _playerGUID.Clear();
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (Player* player = summoner->ToPlayer())
        {
            _playerGUID = player->GetGUID();
            DoCast(player, SPELL_RIZZLE_BLACKJACK, true);
            Talk(MSG_ESCAPE_NOTICE, player);
            DoCastSelf(SPELL_RIZZLE_ESCAPE, true);
            _scheduler.Schedule(1s, [this](TaskContext teleportContext)
            {
                me->SetHover(true);
                me->SetSwim(false);
                me->SetSpeedRate(MOVE_RUN, 0.85f);
                DoCastSelf(SPELL_PERIODIC_DEPTH_CHARGE, true);
                Talk(SAY_RIZZLE_START);
                std::function<void(Movement::MoveSplineInit&)> initializer = [=, me = me](Movement::MoveSplineInit& init)
                {
                    Movement::PointsArray path(RizzlePath, RizzlePath + RizzlePathSize);
                    init.MovebyPath(path);
                    init.SetVelocity(me->GetSpeed(MOVE_RUN));
                };
                me->GetMotionMaster()->LaunchMoveSpline(std::move(initializer), POINT_END, MOTION_PRIORITY_NORMAL, POINT_MOTION_TYPE);
                teleportContext.Schedule(1s, [this](TaskContext checkDistanceContext)
                {
                    Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID);
                    if (!player)
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }
                    if (me->IsWithinDist(player, 5.0f))
                    {
                        checkDistanceContext.CancelAll();
                        Talk(SAY_RIZZLE_FINAL);
                        me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);
                        me->RemoveAurasDueToSpell(SPELL_PERIODIC_DEPTH_CHARGE);
                    }
                    else
                        checkDistanceContext.Repeat(1s);
                }).Schedule(20s, [this](TaskContext granadeContext)
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    {
                        Talk(SAY_RIZZLE_GRENADE, player);
                        DoCast(player, SPELL_RIZZLE_FROST_GRENADE, true);
                    }
                    granadeContext.Repeat(20s, 30s);
                });
            });
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && id != POINT_END)
            return;

        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    bool OnGossipHello(Player* player) override
    {
        if (player->GetQuestStatus(QUEST_CHASING_THE_MOONSTONE) != QUEST_STATUS_INCOMPLETE)
            return false;

        InitGossipMenuFor(player, GOSSIP_MENU_GET_MOONSTONE);
        AddGossipItemFor(player, GOSSIP_MENU_GET_MOONSTONE, GOSSIP_OPTION_GET_MOONSTONE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        SendGossipMenuFor(player, player->GetGossipTextId(GOSSIP_MENU_GET_MOONSTONE, me), me->GetGUID());        
        return true;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        CloseGossipMenuFor(player);
        if (player->GetQuestStatus(QUEST_CHASING_THE_MOONSTONE) == QUEST_STATUS_INCOMPLETE)
            DoCast(player, SPELL_GIVE_SOUTHFURY_MOONSTONE, true);
        me->DespawnOrUnsummon(3s);
        return true;
    }

private:
    ObjectGuid _playerGUID;
    TaskScheduler _scheduler;
};

/*####
# npc_depth_charge
####*/

struct npc_depth_charge : public NullCreatureAI
{
    npc_depth_charge(Creature * creature) : NullCreatureAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetHover(true);
        me->SetSwim(true);
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
    }

    void MoveInLineOfSight(Unit * who) override
    {
        if (!who)
            return;

        if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 5.f))
        {
            DoCast(who, SPELL_DEPTH_CHARGE_TRAP);
            me->DespawnOrUnsummon(1s);
        }
    }
};

void AddSC_azshara()
{
    RegisterCreatureAI(npc_rizzle_sprysprocket);
    RegisterCreatureAI(npc_depth_charge);
}

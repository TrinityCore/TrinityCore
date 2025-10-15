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
#include "ObjectAccessor.h"
#include "MotionMaster.h"
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
    QUEST_CHASING_THE_MOONSTONE     = 10994,

    NPC_DEPTH_CHARGE                = 23025,

    SPELL_RIZZLE_BLACKJACK          = 39865,
    SPELL_RIZZLE_ESCAPE             = 39871,
    SPELL_RIZZLE_FROST_GRENADE      = 40525,
    SPELL_DEPTH_CHARGE_TRAP         = 38576,
    SPELL_PERIODIC_DEPTH_CHARGE     = 39912,
    SPELL_GIVE_SOUTHFURY_MOONSTONE  = 39886,

    SAY_RIZZLE_START                = 0,
    SAY_RIZZLE_GRENADE              = 1,
    SAY_RIZZLE_FINAL                = 2,
    MSG_ESCAPE_NOTICE               = 3,

    GOSSIP_MENU_GET_MOONSTONE       = 57025,
    GOSSIP_OPTION_GET_MOONSTONE     = 0,

    PATH_RIZZLE                     = 2300200
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
            Talk(SAY_RIZZLE_START);
            DoCast(player, SPELL_RIZZLE_BLACKJACK, true);
            _scheduler.Schedule(1s, [this](TaskContext teleportContext)
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                    Talk(MSG_ESCAPE_NOTICE, player);
                DoCastSelf(SPELL_RIZZLE_ESCAPE);
                teleportContext.Schedule(1ms, [this](TaskContext/* startPathContext*/)
                {
                    me->SetSpeedRate(MOVE_SWIM, 0.85f);
                    DoCastSelf(SPELL_PERIODIC_DEPTH_CHARGE, true);
                    me->GetMotionMaster()->MovePath(PATH_RIZZLE, false);
                });
            });
        }
    }

    void WaypointStarted(uint32 waypointId, uint32 pathId) override
    {
        if (pathId != PATH_RIZZLE || waypointId != 1)
            return;

        _scheduler.Schedule(1s, [this](TaskContext checkDistanceContext)
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
                me->GetMotionMaster()->MoveIdle();
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
    }

    void WaypointPathEnded(uint32/* waypointId*/, uint32 pathId) override
    {
        if (pathId != PATH_RIZZLE)
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
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetFacingTo(me->GetOrientation() + float(M_PI));
    }

    void MoveInLineOfSight(Unit* who) override
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

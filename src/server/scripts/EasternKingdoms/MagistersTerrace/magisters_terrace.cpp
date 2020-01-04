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

/* ScriptData
SDName: Magisters_Terrace
SD%Complete: 100
SDComment: Quest support: 11490(post-event)
SDCategory: Magisters Terrace
EndScriptData */

/* ContentData
npc_kalecgos
EndContentData */

#include "ScriptMgr.h"
#include "magisters_terrace.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

/*######
## npc_kalecgos
######*/

enum Spells
{
    SPELL_KALECGOS_TRANSFORM    = 44670,
    SPELL_TRANSFORM_VISUAL      = 24085,
    SPELL_CAMERA_SHAKE          = 44762,
    SPELL_ORB_KILL_CREDIT       = 46307
};

enum MovementPoints
{
    POINT_ID_PREPARE_LANDING    = 6
};

enum EventIds
{
    EVENT_KALECGOS_TRANSFORM         = 1,
    EVENT_KALECGOS_LANDING           = 2
};

#define GOSSIP_ITEM_KAEL_1      "Who are you?"
#define GOSSIP_ITEM_KAEL_2      "What can we do to assist you?"
#define GOSSIP_ITEM_KAEL_3      "What brings you to the Sunwell?"
#define GOSSIP_ITEM_KAEL_4      "You're not alone here?"
#define GOSSIP_ITEM_KAEL_5      "What would Kil'jaeden want with a mortal woman?"

class npc_kalecgos : public CreatureScript
{
public:
    npc_kalecgos() : CreatureScript("npc_kalecgos") { }

    struct npc_kalecgosAI : public ScriptedAI
    {
        npc_kalecgosAI(Creature* creature) : ScriptedAI(creature) { }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != WAYPOINT_MOTION_TYPE)
                return;

            if (pointId == POINT_ID_PREPARE_LANDING)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                me->SetDisableGravity(false);
                me->SetHover(false);
                events.ScheduleEvent(EVENT_KALECGOS_LANDING, Seconds(2));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_KALECGOS_LANDING:
                    DoCastAOE(SPELL_CAMERA_SHAKE);
                    me->SetObjectScale(0.6f);
                    events.ScheduleEvent(EVENT_KALECGOS_TRANSFORM, Seconds(1));
                    break;
                case EVENT_KALECGOS_TRANSFORM:
                    DoCast(me, SPELL_ORB_KILL_CREDIT, true);
                    DoCast(me, SPELL_TRANSFORM_VISUAL, false);
                    DoCast(me, SPELL_KALECGOS_TRANSFORM, false);
                    me->UpdateEntry(NPC_HUMAN_KALECGOS);
                    break;
                default:
                    break;
            }
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF:
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    SendGossipMenuFor(player, 12500, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 1:
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    SendGossipMenuFor(player, 12502, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                    SendGossipMenuFor(player, 12606, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 3:
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                    SendGossipMenuFor(player, 12607, me->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 4:
                    SendGossipMenuFor(player, 12608, me->GetGUID());
                    break;
            }

            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            SendGossipMenuFor(player, 12498, me->GetGUID());

            return true;
        }

        private:
            EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetMagistersTerraceAI<npc_kalecgosAI>(creature);
    }
};

enum ShatteredSunSentry
{
    POINT_ID_PREPARE_SPLINE_PATH            = 1,
    POINT_ID_REPEAT_PATH                    = 1,
    MAX_SHATTERED_SUN_SENTRY_SPLINE_POINTS  = 10
};

// Sniffed data. There is one single waypoint before the 2nd one is a smooth round
Position const ShatteredSunSentryWaypoint1 = { 22.85059f, -7.226434f, -2.813324f };
Position const ShatteredSunSentryPath[MAX_SHATTERED_SUN_SENTRY_SPLINE_POINTS] =
{
    { 22.86974f, -8.028148f, -2.570914f },
    { 22.61974f, -14.77815f, -2.070914f },
    { 27.86974f, -17.52815f, -1.570914f },
    { 32.86974f, -15.77815f, -2.070914f },
    { 33.61974f, -3.778147f, -2.570914f },
    { 33.61974f, 7.971852f,  -2.570914f },
    { 33.11974f, 17.72185f,  -1.820914f },
    { 28.11974f, 18.97185f,  -1.570914f },
    { 23.36974f, 15.97185f,  -2.070914f },
    { 22.38889f, 0.6701389f, -2.828505f }
};

struct npc_mgt_shattered_sun_sentry : public ScriptedAI
{
    npc_mgt_shattered_sun_sentry(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetWalk(true);
        Unit* unit = me;
        me->m_Events.AddEventAtOffset([unit]()
        {
            unit->GetMotionMaster()->MovePoint(POINT_ID_PREPARE_SPLINE_PATH, ShatteredSunSentryWaypoint1);
        }, 2s);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == POINT_MOTION_TYPE && pointId == POINT_ID_PREPARE_SPLINE_PATH)
            me->GetMotionMaster()->MoveSmoothPath(MAX_SHATTERED_SUN_SENTRY_SPLINE_POINTS, ShatteredSunSentryPath, MAX_SHATTERED_SUN_SENTRY_SPLINE_POINTS, true);

        if (type == EFFECT_MOTION_TYPE && pointId == MAX_SHATTERED_SUN_SENTRY_SPLINE_POINTS)
            me->GetMotionMaster()->MovePoint(POINT_ID_PREPARE_SPLINE_PATH, ShatteredSunSentryWaypoint1);
    }
};

void AddSC_magisters_terrace()
{
    new npc_kalecgos();
    RegisterMagistersTerraceCreatureAI(npc_mgt_shattered_sun_sentry);
}

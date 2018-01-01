/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        ClearGossipMenuFor(player);
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 12500, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, 12502, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                SendGossipMenuFor(player, 12606, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                SendGossipMenuFor(player, 12607, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                SendGossipMenuFor(player, 12608, creature->GetGUID());
                break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAEL_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        SendGossipMenuFor(player, 12498, creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kalecgosAI(creature);
    }

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

        private:
            EventMap events;
    };
};

void AddSC_magisters_terrace()
{
    new npc_kalecgos();
}

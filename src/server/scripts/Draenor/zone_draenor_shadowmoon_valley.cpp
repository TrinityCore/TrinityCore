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

#include "PhasingHandler.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

// 79243 - Baros Alexston
enum BarosAlexstonMisc
{
    // Quest
    QUEST_ESTABLISH_YOUR_GARRISON                    = 34586,

    // Gossip
    OPTION_GOSSIP_0                                  = 0,
    GOSSIP_START_GARRISON                            = 16871,

    // Spells
    SPELL_QUEST_34586_KILLCREDIT                     = 161033,
    SPELL_CREATE_GARRISON_SHADOWMOON_VALLEY_ALLIANCE = 156020,
    SPELL_DESPAWN_ALL_SUMMONS_GARRISON_INTRO_ONLY    = 160938,

    // Map
    MAP_SMV_ALLIANCE_GARRISON_LEVEL_1                = 1158
};

Position const garrisonPlayerPosition = {1904.58f, 312.906f, 88.9542f, 4.303615f};

class DelayedCastEvent : public BasicEvent
{
public:
    DelayedCastEvent(Player* player, uint32 spellId) : _player(player), _spellId(spellId) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _player->CastSpell(_player, _spellId, true);
        return true;
    }

private:
    Player* _player;
    uint32 _spellId;
};

class DelayedTeleportEvent : public BasicEvent
{
public:
    DelayedTeleportEvent(Player* player) : _player(player) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _player->NearTeleportTo(garrisonPlayerPosition);
        PhasingHandler::AddVisibleMapId(_player, MAP_SMV_ALLIANCE_GARRISON_LEVEL_1);
        return true;
    }

private:
    Player* _player;
};

struct npc_baros_alexston : public ScriptedAI
{
    npc_baros_alexston(Creature* creature) : ScriptedAI(creature) { }

    bool OnGossipHello(Player* player) override
    {
        if (me->IsQuestGiver())
            player->PrepareQuestMenu(me->GetGUID());

        if (player->GetQuestStatus(QUEST_ESTABLISH_YOUR_GARRISON) == QUEST_STATUS_INCOMPLETE)
        {
            AddGossipItemFor(player, GOSSIP_START_GARRISON, OPTION_GOSSIP_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            SendGossipMenuFor(player, GOSSIP_START_GARRISON, me->GetGUID());
        }
        else
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
        if (action == GOSSIP_ACTION_INFO_DEF)
        {
            CloseGossipMenuFor(player); 
            player->CastSpell(player, SPELL_QUEST_34586_KILLCREDIT, true);
            player->m_Events.AddEventAtOffset(new DelayedCastEvent(player, SPELL_CREATE_GARRISON_SHADOWMOON_VALLEY_ALLIANCE), 1s);
            player->m_Events.AddEventAtOffset(new DelayedCastEvent(player, SPELL_DESPAWN_ALL_SUMMONS_GARRISON_INTRO_ONLY), 2s);
            player->m_Events.AddEventAtOffset(new DelayedTeleportEvent(player), 3s);
        }

        return true;
    }
};

void AddSC_draenor_shadowmoon_valley()
{
    RegisterCreatureAI(npc_baros_alexston);
};

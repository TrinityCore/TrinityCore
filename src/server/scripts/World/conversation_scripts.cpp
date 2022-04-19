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
#include "Conversation.h"
#include "Player.h"

class conversation_allied_race_dk_defender_of_azeroth : public ConversationScript
{
public:
    enum DefenderOfAzerothIds : uint32
    {
        NPC_TALK_TO_YOUR_COMMANDER_CREDIT   = 161709,
        NPC_LISTEN_TO_YOUR_COMMANDER_CREDIT = 163027,

        CONVERSATION_LINE_PLAYER            = 32926
    };

    conversation_allied_race_dk_defender_of_azeroth() : ConversationScript("conversation_allied_race_dk_defender_of_azeroth") { }

    void OnConversationCreate(Conversation* /*conversation*/, Unit* creator) override
    {
        if (Player* player = creator->ToPlayer())
            player->KilledMonsterCredit(NPC_TALK_TO_YOUR_COMMANDER_CREDIT);
    }

    void OnConversationLineStarted(Conversation* /*conversation*/, uint32 lineId, Player* sender) override
    {
        if (lineId != CONVERSATION_LINE_PLAYER)
            return;

        sender->KilledMonsterCredit(NPC_LISTEN_TO_YOUR_COMMANDER_CREDIT);
    }
};

void AddSC_conversation_scripts()
{
    new conversation_allied_race_dk_defender_of_azeroth();
}

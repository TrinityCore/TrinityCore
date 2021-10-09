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

#include "Conversation.h"
#include "ObjectAccessor.h"

class conversation_allied_race_dk_defender_of_azeroth : public ConversationScript
{
public:
    enum KilledMonsterCreditIds : uint32
    {
        NPC_TALK_TO_YOUR_COMMANDER_CREDIT   = 161709,
        NPC_LISTEN_TO_YOUR_COMMANDER_CREDIT = 163027
    };

    conversation_allied_race_dk_defender_of_azeroth() : ConversationScript("conversation_allied_race_dk_defender_of_azeroth") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        conversation->AddActor(creator->GetGUID(), 1);
        if (Player* player = creator->ToPlayer())
            player->KilledMonsterCredit(NPC_TALK_TO_YOUR_COMMANDER_CREDIT);
    }

    void OnConversationExpire(Conversation* conversation) override
    {
        if (Player* creator = ObjectAccessor::GetPlayer(*conversation, conversation->GetCreatorGuid()))
            creator->KilledMonsterCredit(NPC_LISTEN_TO_YOUR_COMMANDER_CREDIT);
    }
};

void AddSC_conversation_scripts()
{
    new conversation_allied_race_dk_defender_of_azeroth();
}

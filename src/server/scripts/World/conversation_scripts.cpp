/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ConversationDataStore.h"
#include "Creature.h"
#include "Player.h"
#include "Object.h"
#include "ScriptMgr.h"
#include "Unit.h"

/*class conversation_example : public ConversationScript
{
public:
    conversation_example() : ConversationScript("conversation_example") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator)
    {
        Creature* firstCreature = creator->FindNearestCreature(CREATURE_ONE, 100.0f);
        Creature* secondCreature = creator->FindNearestCreature(CREATURE_TWO, 100.0f);

        if (firstCreature && secondCreature)
        {
            conversation->AddActor(firstCreature->GetGUID(), 0);
            conversation->AddActor(secondCreature->GetGUID(), 1);
        }
        else
            // kill conversation before AddToMap (prevents clientcrash)
            conversation->SetValidState(false);
    }
};*/

void AddSC_conversation_scripts()
{
    //new conversation_example();
}

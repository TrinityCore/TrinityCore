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
#include "Conversation.h"
#include "ConversationAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum TheExpeditionAwaitsData
{
    NPC_CHIEF_OFFICER_HAMMERFLANGE  = 236055,
    NPC_GREASMONKEY_SURVEYOR        = 234986,
    NPC_ZEPPELIN_ENGINEER           = 234231
};

// 27051 - Conversation
class conversation_dawn_accept_the_expedition_awaits : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        if (Creature* hammerflangeObject = GetClosestCreatureWithOptions(creator, 15.0f, { .CreatureId = NPC_CHIEF_OFFICER_HAMMERFLANGE, .IgnorePhases = true }))
            hammerflangeObject->SummonPersonalClone(hammerflangeObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());

        if (Creature* surveyorObject = GetClosestCreatureWithOptions(creator, 15.0f, { .CreatureId = NPC_GREASMONKEY_SURVEYOR, .IgnorePhases = true }))
            surveyorObject->SummonPersonalClone(surveyorObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());

        if (Creature* engineerObject = GetClosestCreatureWithOptions(creator, 15.0f, { .CreatureId = NPC_ZEPPELIN_ENGINEER, .IgnorePhases = true }))
            engineerObject->SummonPersonalClone(engineerObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());

        conversation->Start();
    }
};

void AddSC_zone_dornogal()
{
    // Conversation
    RegisterConversationAI(conversation_dawn_accept_the_expedition_awaits);
}

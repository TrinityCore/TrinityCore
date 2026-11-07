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
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

namespace Scripts::KhazAlgar::HallOfAwakening
{
namespace Creatures
{
    static constexpr uint32 DawnStairs = 224782;
    static constexpr uint32 ForemanUzjaxStairs = 224783;
}

constexpr Position DawnInitCloneSpawnPos = { 1441.6336f, -261.7257f, 11.0389f, 4.623f };
constexpr Position ForemasterUjaxInitCloneSpawnPos = { 1443.10241f, -261.6111f, 11.0424f, 4.7068f };

// 25327 - Conversation
class conversation_quest_who_am_i : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        if (Creature* dawnObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = Creatures::DawnStairs, .StringId = "CloneTarget", .IgnorePhases = true }))
            dawnObject->SummonPersonalClone(DawnInitCloneSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());

        if (Creature* foremanUzjaxObject = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = Creatures::ForemanUzjaxStairs, .StringId = "CloneTarget", .IgnorePhases = true }))
            foremanUzjaxObject->SummonPersonalClone(ForemasterUjaxInitCloneSpawnPos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, creator->ToPlayer());

        conversation->Start();
    }
};
}

void AddSC_zone_hall_of_awakening()
{
    using namespace Scripts::KhazAlgar::HallOfAwakening;

    // Conversations
    RegisterConversationAI(conversation_quest_who_am_i);
}

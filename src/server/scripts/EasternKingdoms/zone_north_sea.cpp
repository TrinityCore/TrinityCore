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
#include "GridNotifiersImpl.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedEscortAI.h"

enum CaptainGarrickConversation
{
    CONVERSATION_WARMING_UP = 12818,
};

enum CaptainGarrickQuests
{
    QUEST_WARMING_UP = 56775,
};

enum CaptainGarrick
{
    CREATURE_GARRICK_QUARTERDECK_SPAWN_ID = 1050589,
};

struct npc_captain_garrick : public EscortAI
{
    npc_captain_garrick(Creature* creature) : EscortAI(creature) { }

    const float CloneOrientation = 5.124503135681152343f;
    const float CloneSpawnZOffSet = 0.308f;

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() != QUEST_WARMING_UP)
            return;

        Conversation::CreateConversation(CONVERSATION_WARMING_UP, player, *player, player->GetGUID());
    }

    void OnQuestReward(Player* player, Quest const* quest, LootItemType /*type*/, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() != QUEST_WARMING_UP)
            return;

        Creature* garrick = me->GetMap()->GetCreatureBySpawnId(CREATURE_GARRICK_QUARTERDECK_SPAWN_ID);
        if (!garrick)
            return;

        Position pos(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - CloneSpawnZOffSet, CloneOrientation);
        garrick->SummonPersonalClone(pos, TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player, me->GetGUID());
    }

    void InitializeAI() override
    {
        EscortAI::InitializeAI();

        if (!me->IsPrivateObject())
            return;

        SetPauseTimer(1ms);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
    }

    void IsSummonedBy(WorldObject* /*owner*/) override
    {
        _scheduler.Schedule(1600ms, [this](TaskContext task)
        {
            Talk(0);
            SetDespawnAtEnd(false);
            Start(false, false, me->GetPrivateObjectOwner());
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        EscortAI::UpdateAI(diff);
    }

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        switch (waypointId)
        {
            case 1:
                me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                break;
            case 13:
                me->SetFacingTo(3.319117546081542968f, true);
                _scheduler.Schedule(400ms, [this](TaskContext task)
                {
                    me->SetFacingTo(2.809980392456054687f, true);
                    me->DespawnOrUnsummon();
                });
                break;
        }
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_north_sea()
{
    RegisterCreatureAI(npc_captain_garrick);
}

/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include <ScriptMgr.h>
#include <Player.h>
#include <GameEventMgr.h>

enum GameEvents : uint16
{
    GAME_EVENT_MIDSUMMER_FIRE_FESTIVAL = 1,
    GAME_EVENT_WINTER_VEIL = 2,
    GAME_EVENT_LUNAR_FESTIVAL = 7,
    GAME_EVENT_LOVE_IS_IN_THE_AIR = 8,
    GAME_EVENT_NOBLEGARDEN = 9,
    GAME_EVENT_CHILDRENS_WEEK = 10,
    GAME_EVENT_HARVEST_FESTIVAL = 11,
    GAME_EVENT_HALLOWS_END = 12,
    GAME_EVENT_BREWFEST = 24,
    GAME_EVENT_PILGRIMS_BOUNTY = 26,
};

class GameEventQuestCleanupScript : public PlayerScript
{
    public:
        GameEventQuestCleanupScript() : PlayerScript("GameEventQuestCleanupScript") { }

        void OnLogin(Player* player, bool /*firstLogin*/) override
        {
            std::for_each(GameEventEntries.begin(), GameEventEntries.end(), [&player](uint16 eventId)
            {
                if (sGameEventMgr->IsActiveEvent(eventId))
                    return;

                QuestSet eventQuests = player->GetQuestForEvent(eventId);
                std::for_each(eventQuests.begin(), eventQuests.end(), [&player](uint32 questId)
                {
                    player->AbandonQuest(questId);
                    player->RemoveActiveQuest(questId);
                });
            });
            
        }
    private:
        std::vector<uint16> GameEventEntries
        {
          GAME_EVENT_BREWFEST,
          GAME_EVENT_CHILDRENS_WEEK,
          GAME_EVENT_HALLOWS_END,
          GAME_EVENT_HARVEST_FESTIVAL,
          GAME_EVENT_LOVE_IS_IN_THE_AIR,
          GAME_EVENT_LUNAR_FESTIVAL,
          GAME_EVENT_MIDSUMMER_FIRE_FESTIVAL,
        };
};

void AddSC_game_event_quest_cleanup()
{
    new GameEventQuestCleanupScript();
}

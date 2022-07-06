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

#include "GameEventMgr.h"
#include "ScriptMgr.h"

constexpr auto MAX_WEEKLY_EVENT = 5;

int32 events[MAX_WEEKLY_EVENT] = {
    91,  //  561 - Arena Skirmish Bonus Event
    99,  //  563 - Battleground Bonus Event
    86,  //  565 - Pet Battle Bonus Event
    102, // 1217 - Shadowlands Dungeon Event
    94   //  592 - World Quest Bonus Event
};

int32 auras[MAX_WEEKLY_EVENT] = {
    186401, // Sign of the Skirmisher
    186403, // Sign of Battle
    186406, // Sign of the Critter
    225787, // Sign of the Warrior
    225788  // Sign of the Emissary
};

class Weekly_Bonus_Event_PlayerScript : public PlayerScript
{
public:
    Weekly_Bonus_Event_PlayerScript() :PlayerScript("Weekly_Bonus_Event_PlayerScript") {}

    void OnLogin(Player* player, bool /*firstLogin*/)
    {
        for (uint8 i = 0; i < MAX_WEEKLY_EVENT; ++i)
            if (!sGameEventMgr->IsActiveEvent(events[i]))
                if (player->HasAura(auras[i]))
                    player->RemoveAura(auras[i]);

        for (uint8 i = 0; i < MAX_WEEKLY_EVENT; ++i)        
            if (sGameEventMgr->IsActiveEvent(events[i]))
            {
                player->AddAura(auras[i], player);
                break;
            }
    }
};

void AddSC_event_weekly_bonus()
{
    new Weekly_Bonus_Event_PlayerScript();
};

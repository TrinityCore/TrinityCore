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

enum Spells
{
    SPELL_SIGN_OF_THE_SKIRMISHER    = 186401,
    SPELL_SIGN_OF_BATTLE            = 186403,
    SPELL_SIGN_OF_THE_CRITTER       = 186406,
    SPELL_SIGN_OF_THE_WARRIOR       = 225787,
    SPELL_SIGN_OF_THE_EMISSARY      = 225787
};

enum Events
{
    ARENA_SKIRMISH_BONUS_EVENT      = 91,
    BATTLEGROUND_BONUS_EVENT        = 99,
    PET_BATTLE_BONUS_EVENT          = 86,
    SHADOWLANDS_DUNGEON_EVENT       = 102,
    WORLD_QUEST_BONUS_EVENT         = 94
};

int32 events[MAX_WEEKLY_EVENT] = {
    ARENA_SKIRMISH_BONUS_EVENT,
    BATTLEGROUND_BONUS_EVENT,
    PET_BATTLE_BONUS_EVENT,
    SHADOWLANDS_DUNGEON_EVENT,
    WORLD_QUEST_BONUS_EVENT
};

int32 auras[MAX_WEEKLY_EVENT] = {
    SPELL_SIGN_OF_THE_SKIRMISHER,
    SPELL_SIGN_OF_BATTLE,
    SPELL_SIGN_OF_THE_CRITTER,
    SPELL_SIGN_OF_THE_WARRIOR,
    SPELL_SIGN_OF_THE_EMISSARY
};

class Weekly_Bonus_Event_PlayerScript : public PlayerScript
{
public:
    Weekly_Bonus_Event_PlayerScript() :PlayerScript("Weekly_Bonus_Event_PlayerScript") {}

    void OnLogin(Player* player, bool /*firstLogin*/)
    {
        for (uint8 i = 0; i < MAX_WEEKLY_EVENT; ++i)
        {
            if (!sGameEventMgr->IsActiveEvent(events[i]))
                if (player->HasAura(auras[i]))
                    player->RemoveAura(auras[i]);

            if (sGameEventMgr->IsActiveEvent(events[i]))
                player->CastSpell(nullptr, auras[i]);
        }
    }
};

void AddSC_event_weekly_bonus()
{
    new Weekly_Bonus_Event_PlayerScript();
};

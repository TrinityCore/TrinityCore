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
#include "SceneMgr.h"
#include "ScenePackets.h"
#include "ScriptMgr.h"
#include "Player.h"

enum Quests
{
    QUEST_THE_INVASION_BEGINS               = 40077
};

enum Spells
{
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_01      = 59073,     // Phase 170
    SPELL_START_DEMON_HUNTERS_PLAY_SCENE    = 193525
};

class player_start_demon_hunters : public PlayerScript
{
public:
    player_start_demon_hunters() : PlayerScript("player_start_demon_hunters") { }

    uint32 timer = 1000;

    void OnLogin(Player* player, bool firstLogin) override
    {
        if (player->getClass() == CLASS_DEMON_HUNTER && player->GetZoneId() == 7705 && firstLogin)
            player->RemoveAurasDueToSpell(SPELL_PHASE_QUEST_ZONE_SPECIFIC_01);
    }


    void OnUpdate(Player* player, uint32 diff) override
    {
        if (timer <= diff)
        {
            if (player->getClass() == CLASS_DEMON_HUNTER && player->GetZoneId() == 7705 && player->GetPositionY() < 3281.f)
            	if (!player->HasAura(SPELL_START_DEMON_HUNTERS_PLAY_SCENE) && !player->HasAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_01))
                    if (player->GetQuestStatus(QUEST_THE_INVASION_BEGINS) == QUEST_STATUS_NONE)
                    {
                        player->CastSpell(player, SPELL_START_DEMON_HUNTERS_PLAY_SCENE, true);
                        Conversation::CreateConversation(705, player, player->GetPosition(), { player->GetGUID() });
                    }

            timer = 1000;
        }
        else
            timer -= diff;
    }
};

void AddSC_zone_mardum()
{
	new player_start_demon_hunters();
}

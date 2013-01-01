/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedGossip.h"
#include "ulduar.h"
#include "InstanceScript.h"
#include "Player.h"

/*
The teleporter appears to be active and stable.

- Expedition Base Camp
- Formation Grounds
- Colossal Forge
- Scrapyard
- Antechamber of Ulduar
- Shattered Walkway
- Conservatory of Life
*/

enum UlduarTeleporter
{
    BASE_CAMP                                    = 200,
    GROUNDS                                      = 201,
    FORGE                                        = 202,
    SCRAPYARD                                    = 203,
    ANTECHAMBER                                  = 204,
    WALKWAY                                      = 205,
    CONSERVATORY                                 = 206,
};

class ulduar_teleporter : public GameObjectScript
{
    public:
        ulduar_teleporter() : GameObjectScript("ulduar_teleporter") { }

        bool OnGossipSelect(Player* player, GameObject* /*gameObject*/, uint32 sender, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            if (sender != GOSSIP_SENDER_MAIN)
                return false;
            if (!player->getAttackers().empty())
                return false;

            switch (action)
            {
                case BASE_CAMP:
                    player->TeleportTo(603, -706.122f, -92.6024f, 429.876f, 0.0f);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case GROUNDS:
                    player->TeleportTo(603, 131.248f, -35.3802f, 409.804f, 0.0f);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case FORGE:
                    player->TeleportTo(603, 553.233f, -12.3247f, 409.679f, 0.0f);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case SCRAPYARD:
                    player->TeleportTo(603, 926.292f, -11.4635f, 418.595f, 0.0f);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case ANTECHAMBER:
                    player->TeleportTo(603, 1498.09f, -24.246f, 420.967f, 0.0f);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case WALKWAY:
                    player->TeleportTo(603, 1859.45f, -24.1f, 448.9f, 0.0f);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case CONSERVATORY:
                    player->TeleportTo(603, 2086.27f, -24.3134f, 421.239f, 0.0f);
                    player->CLOSE_GOSSIP_MENU();
                    break;
            }

            return true;
        }

        bool OnGossipHello(Player* player, GameObject* gameObject)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Expedition Base Camp", GOSSIP_SENDER_MAIN, BASE_CAMP);
            if (InstanceScript* instance = gameObject->GetInstanceScript())
            {
                if (instance->GetData(DATA_COLOSSUS) == 2) //count of 2 collossus death
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Formation Grounds", GOSSIP_SENDER_MAIN, GROUNDS);
                if (instance->GetBossState(BOSS_LEVIATHAN) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Colossal Forge", GOSSIP_SENDER_MAIN, FORGE);
                if (instance->GetBossState(BOSS_XT002) == DONE)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Scrapyard", GOSSIP_SENDER_MAIN, SCRAPYARD);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Antechamber of Ulduar", GOSSIP_SENDER_MAIN, ANTECHAMBER);
                }
                if (instance->GetBossState(BOSS_KOLOGARN) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Shattered Walkway", GOSSIP_SENDER_MAIN, WALKWAY);
                if (instance->GetBossState(BOSS_AURIAYA) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Conservatory of Life", GOSSIP_SENDER_MAIN, CONSERVATORY);
            }

            player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
            return true;
        }
};

void AddSC_ulduar_teleporter()
{
    new ulduar_teleporter();
}

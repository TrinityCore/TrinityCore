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
    // Definitions for actions & gossips
    BASE_CAMP    = GOSSIP_ACTION_INFO_DEF + 0,
    GROUNDS      = GOSSIP_ACTION_INFO_DEF + 1,
    FORGE        = GOSSIP_ACTION_INFO_DEF + 2,
    SCRAPYARD    = GOSSIP_ACTION_INFO_DEF + 3,
    ANTECHAMBER  = GOSSIP_ACTION_INFO_DEF + 4,
    WALKWAY      = GOSSIP_ACTION_INFO_DEF + 5,
    CONSERVATORY = GOSSIP_ACTION_INFO_DEF + 6,
    SPARK        = GOSSIP_ACTION_INFO_DEF + 7,
    MADNESS      = GOSSIP_ACTION_INFO_DEF + 8,
};

float TeleportPointsUlduar[9][3] =
{
    {-706.122f, -92.6024f, 429.876f},   // Base Camp
    { 131.248f, -35.3802f, 409.804f},   // Grounds
    { 553.233f, -12.3247f, 409.679f},   // Forge
    { 926.292f, -11.4635f, 418.595f},   // Scrapyard
    { 1498.09f, -24.246f,  420.967f},   // Antechamber
    { 1859.45f, -24.1f,    448.9f  },   // Walkway
    { 2086.27f, -24.3134f, 421.239f},   // Conservatory
    { 2518.13f,  2569.34f, 421.382f},   // Spark
    { 1855.03f, -11.629f,  334.58f },   // Descent into Madness
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
            if (action < BASE_CAMP || action > MADNESS)
                return false;

            action -= GOSSIP_ACTION_INFO_DEF;   // eases evaluation

            player->CLOSE_GOSSIP_MENU();

            if (player->GetVehicle())    // If player is on vehicle, throw him out - we cannot teleport both (or maybe we can? dunno)
                player->ExitVehicle();

            if (action > SCRAPYARD)
            {
                // Drop player from mount - they are only allowed on the outside, up to XT002
                player->Dismount();
                player->RemoveAurasByType(SPELL_AURA_MOUNTED);
            }
            player->TeleportTo(MAP_ULDUAR, TeleportPointsUlduar[action][0], TeleportPointsUlduar[action][1], TeleportPointsUlduar[action][2], 0.0f);
            return true;
        }

        bool OnGossipHello(Player* player, GameObject* gameObject)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Expedition Base Camp", GOSSIP_SENDER_MAIN, BASE_CAMP);
            if (InstanceScript* instance = gameObject->GetInstanceScript())
            {
                if (player->isGameMaster())
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Formation Grounds", GOSSIP_SENDER_MAIN, GROUNDS);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Colossal Forge", GOSSIP_SENDER_MAIN, FORGE);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Scrapyard", GOSSIP_SENDER_MAIN, SCRAPYARD);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Antechamber of Ulduar", GOSSIP_SENDER_MAIN, ANTECHAMBER);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Shattered Walkway", GOSSIP_SENDER_MAIN, WALKWAY);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Conservatory of Life", GOSSIP_SENDER_MAIN, CONSERVATORY);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Spark of Imagination", GOSSIP_SENDER_MAIN, SPARK);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to Descent into Madness", GOSSIP_SENDER_MAIN, MADNESS);
                }
                else
                {
                    if (instance->GetData(DATA_COLOSSUS) == 2) //count of 2 collossus death
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Formation Grounds", GOSSIP_SENDER_MAIN, GROUNDS);
                    //if (instance->GetBossState(BOSS_LEVIATHAN) == DONE)
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
                    if (instance->GetBossState(BOSS_FREYA) == DONE)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Spark of Imagination", GOSSIP_SENDER_MAIN, SPARK);
                    if (instance->GetBossState(BOSS_VEZAX) == DONE)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to Descent into Madness", GOSSIP_SENDER_MAIN, MADNESS);
                }
            }

            player->SEND_GOSSIP_MENU(gameObject->GetGOInfo()->GetGossipMenuId(), gameObject->GetGUID());
            return true;
        }
};

void AddSC_ulduar_teleporter()
{
    new ulduar_teleporter();
}

/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#define MAP_ULDUAR 603

enum UlduarTeleportTargets
{
    BASE_CAMP       = 0,
    GROUNDS         = 1,
    FORGE           = 2,
    SCRAPYARD       = 3,
    ANTECHAMBER     = 4,
    WALKWAY         = 5,
    CONSERVATORY    = 6,
    SPARK           = 7,
    MADNESS         = 8,
    MAX             = 9
};

float TeleportPointsUlduarGOs[9][3] =
{
    {-706.122f, -92.6024f, 429.876f},   // Base Camp
    {131.248f, -35.3802f, 409.804f},    // Grounds
    {553.233f, -12.3247f, 409.679f},    // Forge
    {926.292f, -11.4635f, 418.595f},    // Scrapyard
    {1498.09f, -24.246f, 420.967f},     // Antechamber
    {1859.45f, -24.1f, 448.9f},         // Walkway
    {2086.27f, -24.3134f, 421.239f},    // Conservatory
    {2518.13f, 2569.34f, 421.382f},     // Spark
    {1855.03f, -11.629f, 334.58f},      // Descent into Madness
};

enum TeleportSpells
{
    //64024
    //64032
};

class ulduar_teleporter : public GameObjectScript
{
public:
    ulduar_teleporter() : GameObjectScript("ulduar_teleporter") { }

    bool OnGossipSelect(Player *pPlayer, GameObject * /*pGO*/, uint32 sender, uint32 action)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (sender != GOSSIP_SENDER_MAIN)
            return false;
        if (!pPlayer->getAttackers().empty())
            return false;

        int pos = action - GOSSIP_ACTION_INFO_DEF;
        if (pos >= 0 && pos < MAX)
            pPlayer->TeleportTo(MAP_ULDUAR, TeleportPointsUlduarGOs[pos][0], TeleportPointsUlduarGOs[pos][1], TeleportPointsUlduarGOs[pos][2], 0.0f);
        pPlayer->CLOSE_GOSSIP_MENU();

        return true;
    }

    bool OnGossipHello(Player *pPlayer, GameObject *pGO)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Expedition Base Camp", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + BASE_CAMP);
        if (InstanceScript* pInstance = pGO->GetInstanceScript())
        {
            if (pInstance->GetData(TYPE_COLOSSUS) == 2) //count of 2 collossus death
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Formation Grounds", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + GROUNDS);
            if (pInstance->GetBossState(TYPE_LEVIATHAN) == DONE)
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Colossal Forge", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + FORGE);
            if (pInstance->GetBossState(TYPE_XT002) == DONE)
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Scrapyard", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SCRAPYARD);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Antechamber of Ulduar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + ANTECHAMBER);
            }
            if (pInstance->GetBossState(TYPE_KOLOGARN) == DONE)
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Shattered Walkway", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + WALKWAY);
            if (pInstance->GetBossState(TYPE_AURIAYA) == DONE)
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Conservatory of Life", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + CONSERVATORY);
            if (pInstance->GetBossState(TYPE_FREYA) == DONE)
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to the Spark of Imagination", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SPARK);
            if (pInstance->GetBossState(TYPE_VEZAX) == DONE)
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Teleport to Descent into Madness", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + MADNESS);
        }
        pPlayer->SEND_GOSSIP_MENU(pGO->GetGOInfo()->GetGossipMenuId(), pGO->GetGUID());
        return true;
    }

};

void AddSC_ulduar_teleporter()
{
    new ulduar_teleporter();
}

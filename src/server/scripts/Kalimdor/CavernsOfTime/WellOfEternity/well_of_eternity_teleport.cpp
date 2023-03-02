/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "well_of_eternity.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ScriptedGossip.h"

enum Spells
{
    SPELL_TELEPORT_TO_START                 = 107934,
    SPELL_TELEPORT_TO_AZSHARA_PALACE        = 107979,
    SPELL_TELEPORT_TO_WELL_OF_ETERNITY      = 107691,
};

enum InstanceTeleporter
{
    START_TELEPORT          = 1,
    AZSHARA_TELEPORT        = 2,
    WOE_TELEPORT            = 3,
};

class go_well_of_eternity_teleport : public GameObjectScript
{
public:
    go_well_of_eternity_teleport() : GameObjectScript("go_well_of_eternity_teleport") { }

    bool OnGossipHello(Player* pPlayer, GameObject* pGo) override
    {
        if (pPlayer->IsInCombat())
            return true;

        if (InstanceScript* pInstance = pGo->GetInstanceScript())
        {
            AddGossipItemFor(pPlayer, GOSSIP_ICON_CHAT, "Teleport to Start.", GOSSIP_SENDER_MAIN, START_TELEPORT);

            if (pPlayer->IsGameMaster())
            {
                AddGossipItemFor(pPlayer, GOSSIP_ICON_CHAT, "Teleport to Azshara's Palace.", GOSSIP_SENDER_MAIN, AZSHARA_TELEPORT);
                AddGossipItemFor(pPlayer, GOSSIP_ICON_CHAT, "Teleport to Well of Eternity.", GOSSIP_SENDER_MAIN, WOE_TELEPORT);
            } else
            {
                if (pInstance->GetBossState(DATA_PEROTHARN) == DONE)
                    AddGossipItemFor(pPlayer, GOSSIP_ICON_CHAT, "Teleport to Azshara's Palace.", GOSSIP_SENDER_MAIN, AZSHARA_TELEPORT);
                if (pInstance->GetBossState(DATA_AZSHARA) == DONE)
                    AddGossipItemFor(pPlayer, GOSSIP_ICON_CHAT, "Teleport to Well of Eternity.", GOSSIP_SENDER_MAIN, WOE_TELEPORT);
            }
        }

        SendGossipMenuFor(pPlayer, pPlayer->GetGossipTextId(pGo), pGo->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 /*sender*/, uint32 action) override
    {
        //player->PlayerTalkClass->ClearMenus();
        if (player->IsInCombat())
            return true;

        InstanceScript* pInstance = player->GetInstanceScript();
        if (!pInstance)
            return true;

        switch (action)
        {
            case START_TELEPORT:
                player->CastSpell(player, SPELL_TELEPORT_TO_START, true);
                CloseGossipMenuFor(player);
                break;
            case AZSHARA_TELEPORT:
                player->CastSpell(player, SPELL_TELEPORT_TO_AZSHARA_PALACE, true);
                CloseGossipMenuFor(player);
                break;
            case WOE_TELEPORT:
                player->CastSpell(player, SPELL_TELEPORT_TO_WELL_OF_ETERNITY, true);
                CloseGossipMenuFor(player);
                break;
        }

        return true;
    }
};

void AddSC_well_of_eternity_teleport()
{
    new go_well_of_eternity_teleport();
}

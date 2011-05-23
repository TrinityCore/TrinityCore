/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "icecrown_citadel.h"
#include "Spell.h"

#define GOSSIP_SENDER_ICC_PORT 631
#define GOSSIP_TEXT(id) sObjectMgr->GetGossipText(id)->Options[0].Text_0

enum eTeleportGossips
{
    GOSSIP_TELEPORT_LIGHTS_HAMMER           = 800000,
    GOSSIP_TELEPORT_ORATORY_OF_THE_DAMNED   = 800001,
    GOSSIP_TELEPORT_RAMPART_OF_SKULLS       = 800002,
    GOSSIP_TELEPORT_DEATHBRINGERS_RISE      = 800003,
    GOSSIP_TELEPORT_UPPER_SPIRE             = 800004,
    GOSSIP_TELEPORT_SINDRAGOSAS_LAIR        = 800005,
    GOSSIP_TELEPORT_FROZEN_THRONE           = 800006
};

class icecrown_citadel_teleport : public GameObjectScript
{
    public:
        icecrown_citadel_teleport() : GameObjectScript("icecrown_citadel_teleport") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_LIGHTS_HAMMER), GOSSIP_SENDER_ICC_PORT, LIGHT_S_HAMMER_TELEPORT);
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (instance->GetBossState(DATA_LORD_MARROWGAR) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_ORATORY_OF_THE_DAMNED), GOSSIP_SENDER_ICC_PORT, ORATORY_OF_THE_DAMNED_TELEPORT);
                if (instance->GetBossState(DATA_LADY_DEATHWHISPER) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_RAMPART_OF_SKULLS), GOSSIP_SENDER_ICC_PORT, RAMPART_OF_SKULLS_TELEPORT);
                if (instance->GetBossState(DATA_GUNSHIP_EVENT) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_DEATHBRINGERS_RISE), GOSSIP_SENDER_ICC_PORT, DEATHBRINGER_S_RISE_TELEPORT);
                if (instance->GetData(DATA_COLDFLAME_JETS) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_UPPER_SPIRE), GOSSIP_SENDER_ICC_PORT, UPPER_SPIRE_TELEPORT);
                if (instance->GetBossState(DATA_VALITHRIA_DREAMWALKER) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_SINDRAGOSAS_LAIR), GOSSIP_SENDER_ICC_PORT, SINDRAGOSA_S_LAIR_TELEPORT);
                if (instance->GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE && instance->GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE && instance->GetBossState(DATA_SINDRAGOSA) == DONE)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT(GOSSIP_TELEPORT_FROZEN_THRONE), GOSSIP_SENDER_ICC_PORT, FROZEN_THRONE_TELEPORT);
            }

            player->SEND_GOSSIP_MENU(go->GetGOInfo()->GetGossipMenuId(), go->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 sender, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            player->CLOSE_GOSSIP_MENU();
            SpellEntry const* spell = sSpellStore.LookupEntry(action);
            if (!spell)
                return false;

            if (player->isInCombat())
            {
                Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                return true;
            }

            if (sender == GOSSIP_SENDER_ICC_PORT)
                player->CastSpell(player, spell, true);

            return true;
        }
};

void AddSC_icecrown_citadel_teleport()
{
    new icecrown_citadel_teleport();
}

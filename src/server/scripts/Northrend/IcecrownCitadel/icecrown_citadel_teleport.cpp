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

#include "icecrown_citadel.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

static std::vector<uint32> const TeleportSpells =
{
    LIGHT_S_HAMMER_TELEPORT,        // 0
    ORATORY_OF_THE_DAMNED_TELEPORT, // 1
    0,                              // 2
    RAMPART_OF_SKULLS_TELEPORT,     // 3
    DEATHBRINGER_S_RISE_TELEPORT,   // 4
    UPPER_SPIRE_TELEPORT,           // 5
    SINDRAGOSA_S_LAIR_TELEPORT      // 6
};

class icecrown_citadel_teleport : public GameObjectScript
{
    static_assert(DATA_UPPERSPIRE_TELE_ACT == 41, "icecrown_citadel.h DATA_UPPERSPIRE_TELE_ACT set to value != 41, gossip condition of the teleporters won't work as intended.");

    public:
        icecrown_citadel_teleport() : GameObjectScript("icecrown_citadel_teleport") { }

        struct icecrown_citadel_teleportAI : public GameObjectAI
        {
            icecrown_citadel_teleportAI(GameObject* go) : GameObjectAI(go)
            {
            }

            bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                if (gossipListId >= TeleportSpells.size())
                    return false;

                ClearGossipMenuFor(player);
                CloseGossipMenuFor(player);
                SpellInfo const* spell = sSpellMgr->GetSpellInfo(TeleportSpells[gossipListId], DIFFICULTY_NONE);
                if (!spell)
                    return false;

                if (player->IsInCombat())
                {
                    ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, player->GetMapId(), spell->Id, player->GetMap()->GenerateLowGuid<HighGuid::Cast>());
                    Spell::SendCastResult(player, spell, {}, castId, SPELL_FAILED_AFFECTING_COMBAT);
                    return true;
                }

                player->CastSpell(player, spell, true);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetIcecrownCitadelAI<icecrown_citadel_teleportAI>(go);
        }
};

class at_frozen_throne_teleport : public AreaTriggerScript
{
    public:
        at_frozen_throne_teleport() : AreaTriggerScript("at_frozen_throne_teleport") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool /*entered*/) override
        {
            if (player->IsInCombat())
            {
                if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(FROZEN_THRONE_TELEPORT, DIFFICULTY_NONE))
                {
                    ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, player->GetMapId(), spell->Id, player->GetMap()->GenerateLowGuid<HighGuid::Cast>());
                    Spell::SendCastResult(player, spell, {}, castId, SPELL_FAILED_AFFECTING_COMBAT);
                }
                return true;
            }

            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE &&
                    instance->GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE &&
                    instance->GetBossState(DATA_SINDRAGOSA) == DONE &&
                    instance->GetBossState(DATA_THE_LICH_KING) != IN_PROGRESS)
                    player->CastSpell(player, FROZEN_THRONE_TELEPORT, true);

            return true;
        }
};

void AddSC_icecrown_citadel_teleport()
{
    new icecrown_citadel_teleport();
    new at_frozen_throne_teleport();
}

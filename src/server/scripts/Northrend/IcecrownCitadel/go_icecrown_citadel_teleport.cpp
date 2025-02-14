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
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "VehicleDefines.h"

static constexpr std::array<uint32, 7> TeleportSpells =
{
    LIGHT_S_HAMMER_TELEPORT,        // 0
    ORATORY_OF_THE_DAMNED_TELEPORT, // 1
    0,                              // 2
    RAMPART_OF_SKULLS_TELEPORT,     // 3
    DEATHBRINGER_S_RISE_TELEPORT,   // 4
    UPPER_SPIRE_TELEPORT,           // 5
    SINDRAGOSA_S_LAIR_TELEPORT      // 6
};

struct icecrown_citadel_teleport : public GameObjectAI
{
    static_assert(DATA_UPPERSPIRE_TELE_ACT == 41, "icecrown_citadel.h DATA_UPPERSPIRE_TELE_ACT set to value != 41, gossip condition of the teleporters won't work as intended.");

    using GameObjectAI::GameObjectAI;

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        if (gossipListId >= TeleportSpells.size())
            return false;

        ClearGossipMenuFor(player);
        CloseGossipMenuFor(player);
        if (!TeleportSpells[gossipListId])
            return false;

        me->CastSpell(player, TeleportSpells[gossipListId], true);
        return true;
    }
};

class at_frozen_throne_teleport : public AreaTriggerScript
{
public:
    at_frozen_throne_teleport() : AreaTriggerScript("at_frozen_throne_teleport") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return true;

        if (instance->GetBossState(DATA_PROFESSOR_PUTRICIDE) != DONE
            || instance->GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) != DONE
            || instance->GetBossState(DATA_SINDRAGOSA) != DONE
            || instance->GetBossState(DATA_THE_LICH_KING) == IN_PROGRESS)
            return true;

        player->CastSpell(player, FROZEN_THRONE_TELEPORT, true);
        return true;
    }
};

class spell_icc_teleport_check : public SpellScript
{
    SpellCastResult CheckCombat() const
    {
        Unit const* target = GetExplTargetUnit();
        if (!target)
            return SPELL_FAILED_BAD_TARGETS;

        if (target->IsInCombat())
            return SPELL_FAILED_AFFECTING_COMBAT;

        return SPELL_CAST_OK;
    }

    void OnPrecast() override
    {
        // If the player is on the ship, Unit::NearTeleport() will try to keep the player on the ship, causing issues.
        // For that we simply always remove the player from the ship.
        Unit* target = GetExplTargetUnit();
        if (TransportBase* transport = target->GetTransport())
            transport->RemovePassenger(target);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_icc_teleport_check::CheckCombat);
    }
};

void AddSC_icecrown_citadel_teleport()
{
    RegisterGameObjectAIWithFactory(icecrown_citadel_teleport, GetIcecrownCitadelAI);
    new at_frozen_throne_teleport();
    RegisterSpellScript(spell_icc_teleport_check);
}

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

#include "ScriptMgr.h"
#include "BattlegroundSA.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "SpellScript.h"
#include "ZoneScript.h"

// 191305 - Horde Banner
// 191306 - Alliance Banner
// 191307 - Horde Banner
// 191308 - Alliance Banner
// 191309 - Horde Banner
// 191310 - Alliance Banner
struct go_sota_capturable_object : public GameObjectAI
{
    go_sota_capturable_object(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* player) override
    {
        if (me->GetGoState() != GO_STATE_READY || me->HasFlag(GO_FLAG_NOT_SELECTABLE))
            return true;

        if (ZoneScript* zonescript = me->GetZoneScript())
        {
            zonescript->DoAction(ACTION_SOTA_CAPTURE_GRAVEYARD, player, me);
            return false;
        }

        return true;
    }
};

// 52410 - Place Seaforium Charge
class spell_place_seaforium_charge : public SpellScript
{
    enum Spells
    {
        SPELL_PLACE_SEAFORIUM_CHARGE_HORDE = 226090,
        SPELL_PLACE_SEAFORIUM_CHARGE_ALLIANCE = 226094
    };

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PLACE_SEAFORIUM_CHARGE_HORDE, SPELL_PLACE_SEAFORIUM_CHARGE_ALLIANCE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* playerCaster = GetCaster()->ToPlayer())
        {
            Team const team = playerCaster->GetBGTeam();
            if (team == ALLIANCE)
                playerCaster->CastSpell(playerCaster, SPELL_PLACE_SEAFORIUM_CHARGE_ALLIANCE, true);
            else if (team == HORDE)
                playerCaster->CastSpell(playerCaster, SPELL_PLACE_SEAFORIUM_CHARGE_HORDE, true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_place_seaforium_charge::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_strand_of_the_ancients()
{
    RegisterGameObjectAI(go_sota_capturable_object);
    RegisterSpellScript(spell_place_seaforium_charge);
}

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
#include "Player.h"
#include "SpellScript.h"

/*######
## Quest 3628: You Are Rakh'likh, Demon
######*/

enum YouAreRakhlikhDemon
{
    SPELL_TELEPORT_TO_RAZELIKH_GROUP    = 27694
};

// 27686 - Teleport to Razelikh (GROUP)
class spell_blasted_lands_teleport_to_razelikh_group : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TELEPORT_TO_RAZELIKH_GROUP });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, SPELL_TELEPORT_TO_RAZELIKH_GROUP, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_blasted_lands_teleport_to_razelikh_group::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quests 36881 and 34398: Warlords of Draenor: The Dark Portal
######*/

enum TeleportToTanaan
{
    SPELL_TELEPORT_TO_TANAAN = 167771,

    MOVIE_INTO_THE_PORTAL    = 185
};

class player_teleport_to_tanaan : public PlayerScript
{
public:
    player_teleport_to_tanaan() : PlayerScript("player_teleport_to_tanaan") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        if (movieId == MOVIE_INTO_THE_PORTAL)
            player->CastSpell(player, SPELL_TELEPORT_TO_TANAAN, true);
    }
};

void AddSC_blasted_lands()
{
    RegisterSpellScript(spell_blasted_lands_teleport_to_razelikh_group);
    new player_teleport_to_tanaan();
}

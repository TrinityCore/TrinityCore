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
#include "SpellScript.h"
#include "Player.h"
#include "Group.h"

/*######
## Quest 3628: You Are Rakh'likh, Demon
######*/

enum TeleportToRazelikh
{
    SPELL_TELEPORT_SINGLE               = 12885,
    SPELL_TELEPORT_SINGLE_IN_GROUP      = 13142
};

// 27686 - Teleport to Razelikh (GROUP)
class spell_razelikh_teleport_group : public SpellScript
{
    PrepareSpellScript(spell_razelikh_teleport_group);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_TELEPORT_SINGLE, SPELL_TELEPORT_SINGLE_IN_GROUP });
    }

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        if (Player* player = GetHitPlayer())
        {
            if (Group* group = player->GetGroup())
            {
                for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    if (Player* member = itr->GetSource())
                        if (member->IsWithinDistInMap(player, 20.0f) && !member->isDead())
                            member->CastSpell(member, SPELL_TELEPORT_SINGLE_IN_GROUP, true);
            }
            else
                player->CastSpell(player, SPELL_TELEPORT_SINGLE, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_razelikh_teleport_group::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_blasted_lands()
{
    RegisterSpellScript(spell_razelikh_teleport_group);
}

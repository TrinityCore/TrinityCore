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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum AllOurFriendsAreDead
{
    // spells
    SPELL_SPEAK_TO_FALLEN_SPIRIT_FEMALE    = 94879,
    SPELL_SPEAK_TO_FALLEN_SPIRIT_MALE      = 79658,

    // npcs
    NPC_SLAIN_CREW_MEMBER_MALE             = 42681
};

// 79614 - Spirit Totem
class spell_spirit_totem : public SpellScript
{
    PrepareSpellScript(spell_spirit_totem);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SPEAK_TO_FALLEN_SPIRIT_FEMALE, SPELL_SPEAK_TO_FALLEN_SPIRIT_MALE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId = SPELL_SPEAK_TO_FALLEN_SPIRIT_FEMALE;
        if (GetHitUnit()->GetEntry() == NPC_SLAIN_CREW_MEMBER_MALE)
            spellId = SPELL_SPEAK_TO_FALLEN_SPIRIT_MALE;

        GetHitUnit()->CastSpell(GetCaster(), spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_spirit_totem::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_deepholm()
{
    RegisterSpellScript(spell_spirit_totem);
}

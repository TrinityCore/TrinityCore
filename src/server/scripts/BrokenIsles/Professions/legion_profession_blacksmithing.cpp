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
#include "Player.h"
#include "SpellMgr.h"

// 184758
class spell_firmament_stone : public SpellScript
{
    PrepareSpellScript(spell_firmament_stone);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster()->IsPlayer())
            return;

        uint32 killCredit = 0;
        switch (GetCaster()->Variables.Increment("spell_firmament_stone"))
        {
            case 1:
                killCredit = 93304;
                break;
            case 2:
                killCredit = 93305;
                break;
            case 3:
                killCredit = 93306;
                GetCaster()->Variables.Remove("spell_firmament_stone");
                break;
        }

        GetCaster()->ToPlayer()->KilledMonsterCredit(killCredit);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_firmament_stone::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_legion_profession_blacksmithing()
{
    RegisterSpellScript(spell_firmament_stone);
}

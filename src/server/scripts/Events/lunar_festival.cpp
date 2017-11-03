/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "Creature.h"
#include "GameEventMgr.h"
#include "Pet.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "Unit.h"

class spell_lunar_festival_invitation : public SpellScriptLoader
{
public:
    spell_lunar_festival_invitation() : SpellScriptLoader("spell_lunar_festival_invitation") { }

    class spell_lunar_festival_invitation_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_lunar_festival_invitation_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Player* player = caster->ToPlayer())
                    player->TeleportTo(1, 7585.24f, -2214.63f, 472.17f, 5.54f);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_lunar_festival_invitation_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_lunar_festival_invitation_SpellScript();
    }
};

void AddSC_event_lunar_festival()
{
    new spell_lunar_festival_invitation();
};

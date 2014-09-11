/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Felwood
SD%Complete: 95
SDComment: Quest support:
SDCategory: Felwood
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"


enum BeesInfo
{
    EMOTE_SPELL_TEXT            = 47835,
    SPELL_BEES_BEES_DAMAGE      = 88425
};

class spell_gen_bees : public SpellScriptLoader
{
public:
    spell_gen_bees() : SpellScriptLoader("spell_gen_bees") { }

    class spell_gen_bees_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_bees_SpellScript);

        void ScriptedEffect(SpellEffIndex /* effIndex */)
        {
            if (Unit * target = GetHitUnit())
                if (Creature * caster = GetCaster()->ToCreature())
                    caster->MonsterTextEmote(EMOTE_SPELL_TEXT, target, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_gen_bees_SpellScript::ScriptedEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gen_bees_SpellScript();
    }
};

void AddSC_felwood()
{
    new spell_gen_bees();
}

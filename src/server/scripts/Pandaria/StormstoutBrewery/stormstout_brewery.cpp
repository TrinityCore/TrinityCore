/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "stormstout_brewery.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum eHabaneroBeer
{
    NPC_BARREL              = 56731,

    SPELL_PROC_EXPLOSION    = 106787
};

class spell_stormstout_brewery_habanero_beer: public SpellScriptLoader
{
    public:
        spell_stormstout_brewery_habanero_beer() : SpellScriptLoader("spell_stormstout_brewery_habanero_beer") { }

        class spell_stormstout_brewery_habanero_beer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_stormstout_brewery_habanero_beer_SpellScript);

            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                std::list<Creature*> creatureList;

                GetCaster()->GetCreatureListWithEntryInGrid(creatureList, NPC_BARREL, 10.0f);

                GetCaster()->RemoveAurasDueToSpell(SPELL_PROC_EXPLOSION);

                for (auto barrel : creatureList)
                {
                    if (barrel->HasAura(SPELL_PROC_EXPLOSION))
                    {
                        barrel->RemoveAurasDueToSpell(SPELL_PROC_EXPLOSION);
                        barrel->CastSpell(barrel, GetSpellInfo()->Id, true);
                    }
                }
            }

            void HandleAfterCast()
            {
                if (Unit* caster = GetCaster())
                    if (caster->ToCreature())
                        caster->ToCreature()->ForcedDespawn(1000);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_stormstout_brewery_habanero_beer_SpellScript::HandleInstaKill, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                AfterCast += SpellCastFn(spell_stormstout_brewery_habanero_beer_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_stormstout_brewery_habanero_beer_SpellScript();
        }
};

void AddSC_stormstout_brewery()
{
    new spell_stormstout_brewery_habanero_beer();
}

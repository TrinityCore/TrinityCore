/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Player.h"

class spell_summon_troublemaker : public SpellScriptLoader
{
    public:
        spell_summon_troublemaker() : SpellScriptLoader("spell_summon_troublemaker") { }

        class spell_summon_troublemaker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_summon_troublemaker_SpellScript);

            void HandleSummon(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                uint32 entry = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(GetSpellInfo()->GetEffect(effIndex)->MiscValueB);
                if (!entry || !properties)
                    return;

                int32 duration = GetSpellInfo()->GetDuration();

                int32 radius;
                if (urand(0, 2) == 0)
                    radius = urand(0, 6);
                else
                    radius = 7;
                float angle = M_PI * (urand(0, 7) / 7.f);
                float x = 1181.75f + radius * sin(angle);
                float y = 3444.5f + radius * cos(angle);

                Position const SpawnPosition = { x, y, 102.9385f, 3.285759f };

                if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, SpawnPosition, properties, duration, GetCaster()))
                    summon->SetTempSummonType(TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_summon_troublemaker_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_summon_troublemaker_SpellScript();
        }
};

void AddSC_the_wandering_isle()
{
    new spell_summon_troublemaker();
}

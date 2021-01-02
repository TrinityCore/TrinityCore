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

/* ScriptData
SDName: Feralas
SD%Complete: 100
SDComment: Quest support: 2987
SDCategory: Feralas
EndScriptData */

/* ContentData
spell_gordunni_trap
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "WorldSession.h"

/*######
## spell_gordunni_trap
######*/

enum GordunniTrapSpells
{
    SPELL_GORDUNNI_DIRT_MOUND_CHEST = 11756,
    SPELL_GORDUNNI_DIRT_MOUND_JUNK = 19394
};

class spell_gordunni_trap : public SpellScriptLoader
{
    public:
        spell_gordunni_trap() : SpellScriptLoader("spell_gordunni_trap") { }

        class spell_gordunni_trap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gordunni_trap_SpellScript);

            void HandleDummy()
            {
                GameObject* caster = GetGObjCaster();
                caster->CastSpell(caster, urand(0, 1) ? SPELL_GORDUNNI_DIRT_MOUND_CHEST : SPELL_GORDUNNI_DIRT_MOUND_JUNK);
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_gordunni_trap_SpellScript::HandleDummy);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gordunni_trap_SpellScript();
        }
};

void AddSC_feralas()
{
    new spell_gordunni_trap();
}

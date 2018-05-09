/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef SC_HELPER_H
#define SC_HELPER_H

#include "Player.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "ScriptMgr.h"

template<SpellEffIndex effecIndex, AuraType auraType, uint32 spellId>
class GenericCastSpellOnProcAuraScriptLoader : public SpellScriptLoader
{
public:
    GenericCastSpellOnProcAuraScriptLoader(const char* name) : SpellScriptLoader(name) { }

    class GenericCastSpellOnProcAuraScriptLoaderAuraScript : public AuraScript
    {
        PrepareAuraScript(GenericCastSpellOnProcAuraScriptLoaderAuraScript);

        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), spellId, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(GenericCastSpellOnProcAuraScriptLoaderAuraScript::OnProc, effecIndex, auraType);
        }
    };

    AuraScript* GetAuraScript() const override { return new GenericCastSpellOnProcAuraScriptLoaderAuraScript(); }
};
#define RegisterCastSpellOnProcAuraScript(name, effecIndex, auraType, spellId) new GenericCastSpellOnProcAuraScriptLoader<effecIndex, auraType, spellId>(name)

#endif

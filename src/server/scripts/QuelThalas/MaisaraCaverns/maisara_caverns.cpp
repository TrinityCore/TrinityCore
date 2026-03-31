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

#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "maisara_caverns.h"
#include "WorldStateMgr.h"

namespace Scripts::QuelThalas::MaisaraCaverns::MaisaraCaverns
{
    namespace Misc
    {
        static constexpr int32 PrisonersFreedWorldState = 29249;
        static constexpr uint8 AllPrisonersFreed        = 8;
    }

// WorldStateId - 29249
class worldstate_maisara_caverns_prisoners_freed : public WorldStateScript
{
public:
    worldstate_maisara_caverns_prisoners_freed() : WorldStateScript("worldstate_maisara_caverns_prisoners_freed") { }

    void OnValueChange(int32 /*worldStateId*/, int32 /*oldValue*/, int32 newValue, Map const* map)
    {
        if (newValue == Misc::AllPrisonersFreed)
        {
            InstanceScript const* instanceScript = const_cast<Map*>(map)->ToInstanceMap()->GetInstanceScript();
            if (!instanceScript)
                return;

            Creature const* nekraxx = instanceScript->GetCreature(DATA_NEKRAXX);
            if (!nekraxx)
                return;

            nekraxx->AI()->DoAction(ACTION_NEKRAXX_INTRO);
        }
    }
};

// 1259069 - Release Captive
class spell_maisara_caverns_release_captive : public SpellScript
{
    void HandleCast() const
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        uint8 prisonersFreed = sWorldStateMgr->GetValue(Misc::PrisonersFreedWorldState, GetCaster()->GetMap());
        instance->DoUpdateWorldState(Misc::PrisonersFreedWorldState, prisonersFreed + 1);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_maisara_caverns_release_captive::HandleCast);
    }
};
}

void AddSC_maisara_caverns()
{
    using namespace Scripts::QuelThalas::MaisaraCaverns::MaisaraCaverns;

    new worldstate_maisara_caverns_prisoners_freed();
    RegisterSpellScript(spell_maisara_caverns_release_captive);
}

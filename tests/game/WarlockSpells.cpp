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

#include "tc_catch2.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "DB2Structure.h"
#include "DummyData.h"
#include "ObjectMgr.h"
#include "Map.h"
#include "MMapManager.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"

void AddSC_warlock_spell_scripts();

namespace
{
struct WarlockCaster : Creature
{
    ~WarlockCaster() override { ResetMap(); }
};

struct WarlockSpell : Spell
{
    using Spell::Spell;
    using Spell::CallScriptEffectHandlers;

    void Attach(SpellScript* script)
    {
        m_loadedScripts.push_back(script);
    }
};

SpellScriptLoader* GetWarlockScript(char const* name)
{
    static bool const loaded = []
    {
        sScriptMgr->SetScriptContext("warlock_tests");
        AddSC_warlock_spell_scripts();
        sScriptMgr->SwapScriptContext();
        return true;
    }();
    (void)loaded;
    return sScriptMgr->GetSpellScriptLoader(sObjectMgr->GetScriptId(name));
}
}

TEST_CASE("Summon Sayaad replaces the summon-pet effect through its registered script", "[Spells][Warlock][Sayaad]")
{
    static UnitTestDataLoader::DB2<FlightCapabilityEntry, &FlightCapabilityEntry::ID> flightCapabilities(sFlightCapabilityStore);
    if (!sFlightCapabilityStore.LookupEntry(1))
    {
        auto loader = flightCapabilities.Loader();
        loader.Add().ID = 1;
    }
    SpellNameEntry name{};
    name.ID = 366222;
    SpellEffectEntry effect{};
    effect.Effect = SPELL_EFFECT_SUMMON_PET;
    effect.EffectMiscValue[0] = 1863;
    effect.EffectBasePoints = 1;
    SpellInfo info{ &name, DIFFICULTY_NONE, { effect } };
    static UnitTestDataLoader::DB2<MapEntry, &MapEntry::ID> maps(sMapStore);
    if (!sMapStore.LookupEntry(0))
    {
        auto loader = maps.Loader();
        MapEntry& map = loader.Add();
        map.ID = 0;
        map.Directory = "fixture";
        map.MapName.Str.fill("");
        map.ParentMapID = -1;
        map.CosmeticParentMapID = -1;
        MMAP::MMapManager::instance()->InitializeThreadUnsafe({ { 0, {} } });
    }
    Map map{ 0, 0, 0, DIFFICULTY_NONE };
    WarlockCaster caster;
    caster.SetMap(&map);
    WarlockSpell spell{ &caster, &info, TRIGGERED_FULL_MASK };
    SpellScriptLoader* loader = GetWarlockScript("spell_warl_summon_sayaad");
    REQUIRE(loader);
    std::unique_ptr<SpellScript> script{ loader->GetSpellScript() };
    REQUIRE(script);
    script->_Init("spell_warl_summon_sayaad", info.Id);
    REQUIRE(script->_Load(&spell));
    script->_Register();
    spell.Attach(script.release());

    REQUIRE_FALSE(spell.CallScriptEffectHandlers(EFFECT_0, SPELL_EFFECT_HANDLE_LAUNCH));
    REQUIRE(spell.CallScriptEffectHandlers(EFFECT_0, SPELL_EFFECT_HANDLE_HIT));
}

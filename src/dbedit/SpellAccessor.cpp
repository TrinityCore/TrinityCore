#include "SpellAccessor.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "GlobalDBCStores.h"
#include "Globals.h"

/*static*/ SpellEntry const* SpellAccessor::GetDBSpellEntry(uint32 spellId)
{
    return DatabaseDBCStore<SpellEntry>::LookupEntry(spellId);
}

/*static*/ SpellEntry const* SpellAccessor::GetDBCSpellEntry(uint32 spellId)
{
    return StaticDBCStore<SpellEntry>::LookupEntry(spellId);
}

char const* SpellAccessor::_GetSpellName(uint32 spellId) const
{
    auto it = _allSpells.find(spellId);
    if (it != _allSpells.end())
        return it->second;
    return "";
}

// unchanging indices only pulled from data we don't touch
void SpellAccessor::_BuildIndices()
{
    _learnedByClassesRaces.clear();
    for (auto* entry : StaticDBCStore<SkillLineAbilityEntry>::iterate())
    {
        uint32 const classmask = entry->classmask ? (entry->classmask & CLASSMASK_ALL_PLAYABLE) : CLASSMASK_ALL_PLAYABLE;
        uint32 const racemask = entry->racemask ? (entry->racemask & RACEMASK_ALL_PLAYABLE) : RACEMASK_ALL_PLAYABLE;
        if (classmask == CLASSMASK_ALL_PLAYABLE && racemask == RACEMASK_ALL_PLAYABLE)
            continue;
        auto* spellEntry = StaticDBCStore<SpellEntry>::LookupEntry(entry->spellId);
        if (!spellEntry)
            continue;
        _learnedByClassesRaces[entry->spellId] = { classmask, racemask };
    }
}

void SpellAccessor::_RebuildIndices()
{
    _allSpells.clear();
    for (SpellEntry const* entry : DatabaseDBCStore<SpellEntry>::iterate())
        _allSpells.emplace(entry->Id, entry->SpellName[0]);
    for (SpellEntry const* entry : StaticDBCStore<SpellEntry>::iterate())
        _allSpells.emplace(entry->Id, entry->SpellName[0]);
}

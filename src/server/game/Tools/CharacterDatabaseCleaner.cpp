/*
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
USA
 */

#include "Common.h"
#include "CharacterDatabaseCleaner.h"
#include "World.h"
#include "Database/DatabaseEnv.h"
#include "DBCStores.h"
#include "ProgressBar.h"

void CharacterDatabaseCleaner::CleanDatabase()
{
    // config to disable
    if(!sWorld.getConfig(CONFIG_CLEAN_CHARACTER_DB))
        return;

    sLog.outString("Cleaning character database...");

    // check flags which clean ups are necessary
    QueryResult_AutoPtr result = CharacterDatabase.Query("SELECT value FROM worldstates WHERE entry=20004");
    if(!result)
        return;
    uint32 flags = (*result)[0].GetUInt32();

    // clean up
    if(flags & CLEANING_FLAG_ACHIEVEMENT_PROGRESS)
        CleanCharacterAchievementProgress();
    if(flags & CLEANING_FLAG_SKILLS)
        CleanCharacterSkills();
    if(flags & CLEANING_FLAG_SPELLS)
        CleanCharacterSpell();
    if(flags & CLEANING_FLAG_TALENTS)
        CleanCharacterTalent();
    CharacterDatabase.Query("UPDATE worldstates SET value = 0 WHERE entry=20004");
}

void CharacterDatabaseCleaner::CheckUnique(const char* column, const 
char* table, bool (*check)(uint32))
{
    QueryResult_AutoPtr result = CharacterDatabase.PQuery("SELECT DISTINCT %s FROM %s", column, table);
    if(!result)
    {
        sLog.outString( "Table %s is empty.", table );
        return;
    }

    bool found = false;
    std::ostringstream ss;
    barGoLink bar( (int)result->GetRowCount() );
    do
    {
        bar.step();

        Field *fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();

        if(!check(id))
        {
            if(!found)
            {
                ss << "DELETE FROM " << table << " WHERE " << column << 
" IN (";
                found = true;
            }
            else
                ss << ",";
            ss << id;
        }
    }
    while( result->NextRow() );

    if (found)
    {
        ss << ")";
        CharacterDatabase.Execute( ss.str().c_str() );
    }
}

bool CharacterDatabaseCleaner::AchievementProgressCheck(uint32 criteria)
{
    return sAchievementCriteriaStore.LookupEntry(criteria);
}

void CharacterDatabaseCleaner::CleanCharacterAchievementProgress()
{
    CheckUnique("criteria", "character_achievement_progress", 
&AchievementProgressCheck);
}

bool CharacterDatabaseCleaner::SkillCheck(uint32 skill)
{
    return sSkillLineStore.LookupEntry(skill);
}

void CharacterDatabaseCleaner::CleanCharacterSkills()
{
    CheckUnique("skill", "character_skills", &SkillCheck);
}

bool CharacterDatabaseCleaner::SpellCheck(uint32 spell_id)
{
    return sSpellStore.LookupEntry(spell_id) && 
!GetTalentSpellPos(spell_id);
}

void CharacterDatabaseCleaner::CleanCharacterSpell()
{
    CheckUnique("spell", "character_spell", &SpellCheck);
}

bool CharacterDatabaseCleaner::TalentCheck(uint32 talent_id)
{
    TalentEntry const *talentInfo = sTalentStore.LookupEntry( talent_id 
);
    if(!talentInfo)
        return false;

    return sTalentTabStore.LookupEntry( talentInfo->TalentTab );
}

void CharacterDatabaseCleaner::CleanCharacterTalent()
{
    CharacterDatabase.DirectPExecute("DELETE FROM character_talent WHERE spec > %u OR current_rank > %u", MAX_TALENT_SPECS, 
MAX_TALENT_RANK);

    CheckUnique("talent_id", "character_talent", &TalentCheck);
}


/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef _PLAYER_DUMP_H
#define _PLAYER_DUMP_H

#include "ObjectGuid.h"
#include <string>
#include <map>
#include <set>

enum DumpTableType
{
    DTT_CHARACTER,      //                                  // characters

    DTT_CHAR_TABLE,     //                                  // character_achievement, character_achievement_progress,
                                                            // character_action, character_aura, character_homebind,
                                                            // character_queststatus, character_queststatus_rewarded, character_reputation,
                                                            // character_spell, character_spell_cooldown, character_ticket, character_talent.
                                                            // character_cuf_profiles

    DTT_CURRENCY,       //                                  // character_currency

    DTT_EQSET_TABLE,    // <- guid                          // character_equipmentsets

    DTT_INVENTORY,      //    -> item guids collection      // character_inventory

    DTT_CHAR_TRANSMOG,  // <- guid                          // character_transmog_outfits

    DTT_MAIL,           //    -> mail ids collection        // mail
                        //    -> item_text

    DTT_MAIL_ITEM,      // <- mail ids                      // mail_items
                        //    -> item guids collection

    DTT_ITEM,           // <- item guids                    // item_instance
                        //    -> item_text

    DTT_ITEM_GIFT,      // <- item guids                    // character_gifts

    DTT_ITEM_TABLE,     // <- item guids                    // item_instance_artifact, item_instance_artifact_powers, item_instance_gems, item_instance_modifiers, item_instance_transmog

    DTT_PET,            //    -> pet guids collection       // character_pet
    DTT_PET_TABLE       // <- pet guids                     // pet_aura, pet_spell, pet_spell_cooldown
};

enum DumpReturn
{
    DUMP_SUCCESS,
    DUMP_FILE_OPEN_ERROR,
    DUMP_TOO_MANY_CHARS,
    DUMP_UNEXPECTED_END,
    DUMP_FILE_BROKEN,
    DUMP_CHARACTER_DELETED
};

class TC_GAME_API PlayerDump
{
    public:
        typedef std::set<ObjectGuid::LowType> DumpGuidSet;
        typedef std::map<ObjectGuid::LowType, ObjectGuid::LowType> DumpGuidMap;

        static void InitializeColumnDefinition();

    protected:
        PlayerDump() { }
};

class TC_GAME_API PlayerDumpWriter : public PlayerDump
{
    public:
        PlayerDumpWriter() { }

        bool GetDump(ObjectGuid::LowType guid, std::string& dump);
        DumpReturn WriteDump(std::string const& file, ObjectGuid::LowType guid);

    private:

        bool DumpTable(std::string& dump, ObjectGuid::LowType guid, char const* tableFrom, char const* tableTo, DumpTableType type);
        std::string GenerateWhereStr(char const* field, DumpGuidSet const& guids, DumpGuidSet::const_iterator& itr);
        std::string GenerateWhereStr(char const* field, ObjectGuid::LowType guid);

        DumpGuidSet pets;
        DumpGuidSet mails;
        DumpGuidSet items;
};

class TC_GAME_API PlayerDumpReader : public PlayerDump
{
    public:
        PlayerDumpReader() { }

        DumpReturn LoadDump(std::string const& file, uint32 account, std::string name, ObjectGuid::LowType guid);
};

#endif

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

#ifndef _PLAYER_DUMP_H
#define _PLAYER_DUMP_H

#include <string>
#include <iosfwd>
#include <map>
#include <set>
#include "ObjectGuid.h"

enum DumpTableType
{
    DTT_CHARACTER,      //                                  // characters

    DTT_CHAR_TABLE,     //                                  // character_achievement, character_achievement_progress,
                                                            // character_action, character_aura, character_homebind,
                                                            // character_queststatus, character_queststatus_rewarded, character_reputation,
                                                            // character_spell, character_spell_cooldown, character_ticket, character_talent

    DTT_EQSET_TABLE,    // <- guid                          // character_equipmentsets

    DTT_INVENTORY,      //    -> item guids collection      // character_inventory

    DTT_MAIL,           //    -> mail ids collection        // mail
                        //    -> item_text

    DTT_MAIL_ITEM,      // <- mail ids                      // mail_items
                        //    -> item guids collection

    DTT_ITEM,           // <- item guids                    // item_instance
                        //    -> item_text

    DTT_ITEM_GIFT,      // <- item guids                    // character_gifts

    DTT_PET,            //    -> pet guids collection       // character_pet
    DTT_PET_TABLE       // <- pet guids                     // pet_aura, pet_spell, pet_spell_cooldown
};

enum DumpReturn
{
    DUMP_SUCCESS,
    DUMP_FILE_OPEN_ERROR,
    DUMP_TOO_MANY_CHARS,
    DUMP_FILE_BROKEN,
    DUMP_CHARACTER_DELETED
};

struct DumpTable;
struct TableStruct;
class StringTransaction;

class TC_GAME_API PlayerDump
{
    public:
        static void InitializeTables();

    protected:
        PlayerDump() { }
};

class TC_GAME_API PlayerDumpWriter : public PlayerDump
{
    public:
        PlayerDumpWriter() { }

        bool GetDump(ObjectGuid::LowType guid, std::string& dump);
        DumpReturn WriteDumpToFile(std::string const& file, ObjectGuid::LowType guid);
        DumpReturn WriteDumpToString(std::string& dump, ObjectGuid::LowType guid);

    private:
        bool AppendTable(StringTransaction& trans, ObjectGuid::LowType guid, TableStruct const& tableStruct, DumpTable const& dumpTable);
        void PopulateGuids(ObjectGuid::LowType guid);

        std::set<ObjectGuid::LowType> _pets;
        std::set<ObjectGuid::LowType> _mails;
        std::set<ObjectGuid::LowType> _items;

        std::set<uint64> _itemSets;
};

class TC_GAME_API PlayerDumpReader : public PlayerDump
{
    public:
        PlayerDumpReader() { }

        DumpReturn LoadDumpFromFile(std::string const& file, uint32 account, std::string name, ObjectGuid::LowType guid);
        DumpReturn LoadDumpFromString(std::string const& dump, uint32 account, std::string name, ObjectGuid::LowType guid);

    private:
        DumpReturn LoadDump(std::istream& input, uint32 account, std::string name, ObjectGuid::LowType guid);
};

#endif

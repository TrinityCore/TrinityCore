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

#ifndef TRINITY_LOOTMGR_H
#define TRINITY_LOOTMGR_H

#include "Define.h"
#include "ConditionMgr.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include <list>
#include <vector>

class LootStore;
class LootTemplate;
class Player;
struct Loot;
struct LootItem;

struct TC_GAME_API LootStoreItem
{
    uint32  itemid;                                         // id of the item
    uint32  reference;                                      // referenced TemplateleId
    float   chance;                                         // chance to drop for both quest and non-quest items, chance to be used for refs
    uint16  lootmode;
    bool    needs_quest;                                    // quest drop (quest is required for item to drop)
    uint8   groupid;
    uint8   mincount;                                       // mincount for drop items
    uint8   maxcount;                                       // max drop count for the item mincount or Ref multiplicator
    ConditionContainer conditions;                               // additional loot condition

    // Constructor
    // displayid is filled in IsValid() which must be called after
    LootStoreItem(uint32 _itemid, uint32 _reference, float _chance, bool _needs_quest, uint16 _lootmode, uint8 _groupid, int32 _mincount, uint8 _maxcount)
        : itemid(_itemid), reference(_reference), chance(_chance), lootmode(_lootmode),
        needs_quest(_needs_quest), groupid(_groupid), mincount(_mincount), maxcount(_maxcount)
         { }

    bool Roll(bool rate) const;                             // Checks if the entry takes it's chance (at loot generation)
    bool IsValid(LootStore const& store, uint32 entry) const;
                                                            // Checks correctness of values
};

typedef std::list<LootStoreItem*> LootStoreItemList;
typedef std::unordered_map<uint32, LootTemplate*> LootTemplateMap;

typedef std::set<uint32> LootIdSet;

class TC_GAME_API LootStore
{
    public:
        explicit LootStore(char const* name, char const* entryName, bool ratesAllowed)
            : m_name(name), m_entryName(entryName), m_ratesAllowed(ratesAllowed) { }

        virtual ~LootStore() { Clear(); }

        void Verify() const;

        uint32 LoadAndCollectLootIds(LootIdSet& ids_set);
        void CheckLootRefs(LootIdSet* ref_set = nullptr) const; // check existence reference and remove it from ref_set
        void ReportUnusedIds(LootIdSet const& ids_set) const;
        void ReportNonExistingId(uint32 lootId, char const* ownerType, uint32 ownerId) const;

        bool HaveLootFor(uint32 loot_id) const { return m_LootTemplates.find(loot_id) != m_LootTemplates.end(); }
        bool HaveQuestLootFor(uint32 loot_id) const;
        bool HaveQuestLootForPlayer(uint32 loot_id, Player* player) const;

        LootTemplate const* GetLootFor(uint32 loot_id) const;
        void ResetConditions();
        LootTemplate* GetLootForConditionFill(uint32 loot_id);

        char const* GetName() const { return m_name; }
        char const* GetEntryName() const { return m_entryName; }
        bool IsRatesAllowed() const { return m_ratesAllowed; }
    protected:
        uint32 LoadLootTable();
        void Clear();
    private:
        LootTemplateMap m_LootTemplates;
        char const* m_name;
        char const* m_entryName;
        bool m_ratesAllowed;
};

class TC_GAME_API LootTemplate
{
    class LootGroup;                                       // A set of loot definitions for items (refs are not allowed inside)
    typedef std::vector<LootGroup*> LootGroups;

    public:
        LootTemplate() { }
        ~LootTemplate();

        // Adds an entry to the group (at loading stage)
        void AddEntry(LootStoreItem* item);
        // Rolls for every item in the template and adds the rolled items the the loot
        void Process(Loot& loot, bool rate, uint16 lootMode, uint8 groupId = 0) const;
        void CopyConditions(ConditionContainer const& conditions);
        void CopyConditions(LootItem* li) const;

        // True if template includes at least 1 quest drop entry
        bool HasQuestDrop(LootTemplateMap const& store, uint8 groupId = 0) const;
        // True if template includes at least 1 quest drop for an active quest of the player
        bool HasQuestDropForPlayer(LootTemplateMap const& store, Player const* player, uint8 groupId = 0) const;

        // Checks integrity of the template
        void Verify(LootStore const& store, uint32 Id) const;
        void CheckLootRefs(LootTemplateMap const& store, LootIdSet* ref_set) const;
        bool addConditionItem(Condition* cond);
        bool isReference(uint32 id);

    private:
        LootStoreItemList Entries;                          // not grouped only
        LootGroups        Groups;                           // groups have own (optimised) processing, grouped entries go there

        // Objects of this class must never be copied, we are storing pointers in container
        LootTemplate(LootTemplate const&) = delete;
        LootTemplate& operator=(LootTemplate const&) = delete;
};

//=====================================================

TC_GAME_API extern LootStore LootTemplates_Creature;
TC_GAME_API extern LootStore LootTemplates_Fishing;
TC_GAME_API extern LootStore LootTemplates_Gameobject;
TC_GAME_API extern LootStore LootTemplates_Item;
TC_GAME_API extern LootStore LootTemplates_Mail;
TC_GAME_API extern LootStore LootTemplates_Milling;
TC_GAME_API extern LootStore LootTemplates_Pickpocketing;
TC_GAME_API extern LootStore LootTemplates_Reference;
TC_GAME_API extern LootStore LootTemplates_Skinning;
TC_GAME_API extern LootStore LootTemplates_Disenchant;
TC_GAME_API extern LootStore LootTemplates_Prospecting;
TC_GAME_API extern LootStore LootTemplates_Spell;

TC_GAME_API void LoadLootTemplates_Creature();
TC_GAME_API void LoadLootTemplates_Fishing();
TC_GAME_API void LoadLootTemplates_Gameobject();
TC_GAME_API void LoadLootTemplates_Item();
TC_GAME_API void LoadLootTemplates_Mail();
TC_GAME_API void LoadLootTemplates_Milling();
TC_GAME_API void LoadLootTemplates_Pickpocketing();
TC_GAME_API void LoadLootTemplates_Skinning();
TC_GAME_API void LoadLootTemplates_Disenchant();
TC_GAME_API void LoadLootTemplates_Prospecting();

TC_GAME_API void LoadLootTemplates_Spell();
TC_GAME_API void LoadLootTemplates_Reference();

TC_GAME_API void LoadLootTables();

#endif

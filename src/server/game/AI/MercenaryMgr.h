/*
    ©2013-2016 EmuDevs <http://www.emudevs.com/>
    MaNGOS <http://getmangos.eu>
    TrinityCore <http://www.trinitycore.org>
*/
#ifndef MERCENARYMGR_H
#define MERCENARYMGR_H

#include "Mercenary.h"
#include <random>
#include <unordered_map>

typedef std::vector<MercenarySpell> MercenarySpells;
typedef std::vector<MercenaryStarterGear> MercenaryStartGear;
typedef std::vector<MercenaryTalking> MercenaryTalk;
typedef std::vector<MercenaryProficiency> MercenaryProficiencies;
typedef std::unordered_map<uint32, Mercenary*> MercenaryMap;
typedef std::unordered_map<uint32, MercenaryWorld> MercenaryWorldMap;

class Random
{
public:
    Random() = default;
    Random(std::mt19937::result_type seed) : eng(seed) { }

    int Next(int min, int max)
    {
        return std::uniform_int_distribution < int > {min, max}(eng);
    }

private:
    std::mt19937 eng{ std::random_device{}() };
};

class MercenaryMgr
{
public:
    static MercenaryMgr* GetInstance()
    {
        static MercenaryMgr instance;
        return &instance;
    }

    /*
    * Loads Mercenaries from Database
    */
    void LoadMercenaries();
    /*
    * Saves Mercenary to a container
    */
    void SaveToList(Mercenary* mercenary);
    /*
    /*
    * Deletes Mercenary from a container
    */
    void DeleteFromList(Mercenary* mercenary);
    /*
    * Sets if the Mercenary is currently summoned
    */
    void UpdateSummoned(uint32 Id, bool summoned);
    /*
    * On Mercenary save to database
    * Also updates gear and saves Mercenary spells
    * Cals when players saves
    */
    void OnSave(Player* player, Pet* pet);
    /*
    * On Mercenary delete when a character with Mercenaries was deleted
    */
    void OnDelete(uint32 guidLow);
    /*
    * On Mercenary summon
    * Calls when you change zones
    * If your Mercenary isn't with you, you can change zones to summon it back automatically
    */
    void OnSummon(Player* player);
    /*
    * Clears all containers
    */
    void Clear();
    /*
    * Returns the item's icon
    * Thanks Rochet2 for the function
    */
    std::string GetItemIcon(uint32 entry, bool rawPath = false) const;
    /*
    * Returns the slot icon, empty bag if no icon is found for a slot
    * Thanks Rochet2 for the function
    */
    std::string GetSlotIcon(uint8 slot) const;
    /*
    * Returns item link
    * Thanks Rochet2 for the function
    */
    std::string GetItemLink(uint32 entry, WorldSession* session) const;
    /*
    * Returns slot name
    * Thanks Rochet2 for the function
    */
    const char* GetSlotName(uint8 slot) const;
    /*
    * Returns spell icon & spell name
    */
    std::string GetSpellIcon(uint32 entry, WorldSession* session) const;

    const char* GetAIName() const { return "mercenary_bot"; }

    MercenaryMap::const_iterator MercenaryBegin() const { return MercenaryContainer.begin(); }
    MercenaryMap::const_iterator MercenaryEnd() const { return MercenaryContainer.end(); }
    MercenaryStartGear::const_iterator MercenaryStartGearBegin() const { return MercenaryStartGearContainer.begin(); }
    MercenaryStartGear::const_iterator MercenaryStartGearEnd() const { return MercenaryStartGearContainer.end(); }
    MercenarySpells::const_iterator MercenarySpellsBegin() const { return MercenarySpellsContainer.begin(); }
    MercenarySpells::const_iterator MercenarySpellsEnd() const { return MercenarySpellsContainer.end(); }
    MercenaryTalk::const_iterator MercenaryTalkBegin() const { return MercenaryTalkContainer.begin(); }
    MercenaryTalk::const_iterator MercenaryTalkEnd() const { return MercenaryTalkContainer.end(); }

    /*
    * Returns MercenaryContainer size
    * Used for `fakeEntry` when creating a Mercenary
    */
    uint32 MaxMercenaryId()
    {
        return MercenaryContainer.size();
    }

    /*
    * Returns Mercenary by player guidLow
    */
    Mercenary* GetMercenary(uint32 Id)
    {
        auto itr = MercenaryContainer.find(Id);
        if (itr != MercenaryEnd())
            return itr->second;

        return nullptr;
    }

    /*
    * Returns Mercenary's class by search for owner's guid
    */
    Mercenary* GetMercenaryByOwner(uint32 ownerGUID)
    {
        for (auto itr = MercenaryBegin(); itr != MercenaryEnd(); ++itr)
            if (itr->second->GetOwnerGUID() == ownerGUID)
                return itr->second;

        return nullptr;
    }

    /*
    *  Returns a vector of the correct talk sayings for that Mercenary type and role
    */
    std::vector<MercenaryTalking> GetTalk(uint8 type, uint8 role)
    {
        std::vector<MercenaryTalking> tempTalk;
        for (auto itr = MercenaryTalkBegin(); itr != MercenaryTalkEnd(); ++itr)
            if (itr->type == type && itr->role == role)
                tempTalk.push_back(*itr);

        return tempTalk;
    }

    /*
    * Returns Mercenary world data
    * `MercenaryWorld` data is for Mercenaries spawned in the world
    * On creation, modelId, race and gender will be used, so the data must be
    *     actual race, modelId and gender values
    */
    MercenaryWorld* GetMercenaryWorldData(uint32 entry)
    {
        auto it = MercenaryWorldContainer.find(entry);
        if (it != MercenaryWorldContainer.end())
            return &it->second;

        return nullptr;
    }

    /*
    * Returns item's displayId by itemEntry
    */
    uint32 GetItemDisplayId(uint32 itemEntry)
    {
#ifndef MANGOS
        const ItemTemplate* proto = sObjectMgr->GetItemTemplate(itemEntry);
#else
        const ItemPrototype* proto = sObjectMgr.GetItemPrototype(itemEntry);
#endif
        if (proto)
            return proto->DisplayInfoID;

        return NULL;
    }

    /*
    * Returns Starter Gear for the specified creature entry
    */
    MercenaryStarterGear* GetStarterGearByEntry(uint32 entry)
    {
        for (MercenaryStartGear::iterator it = MercenaryStartGearContainer.begin(); it != MercenaryStartGearContainer.end(); ++it)
            if (it->creature_entry == entry)
                return &(*it);

        return nullptr;
    }

    /*
    * Returns true if the Mercenary type can use that armor or weapon proficiency
    * If for example armor proficiency column is 0 and weapon proficiency column contains
    *     a value, that row will be loaded (considered) as weapon proficiency. Vice versa is implied here.
    */
    bool CheckProficiencies(uint8 type, uint32 itemClass, uint32 itemSubClass)
    {
        bool check = false;
        for (auto& itr : MercenaryProficiencyContainer)
        {
            if (itr.type != type)
                continue;

            if (itemClass == ITEM_CLASS_ARMOR)
            {
                if (itr.armorSubClass == 0 && !(itr.armorSubClass == 0 && itr.weaponSubClass == 0))
                    continue;

                if (itr.armorSubClass == itemSubClass)
                {
                    check = true;
                    break;
                }
            }
            else if (itemClass == ITEM_CLASS_WEAPON)
            {
                if (itr.weaponSubClass == 0 && !(itr.weaponSubClass == 0 && itr.armorSubClass == 0))
                    continue;

                if (itr.weaponSubClass == itemSubClass)
                {
                    check = true;
                    break;
                }
            }
        }

        return check;
    }

    Random random;

private:
    MercenaryMgr();
    ~MercenaryMgr();

    MercenarySpells MercenarySpellsContainer;
    MercenaryStartGear MercenaryStartGearContainer;
    MercenaryProficiencies MercenaryProficiencyContainer;
    MercenaryMap MercenaryContainer;
    MercenaryTalk MercenaryTalkContainer;
    MercenaryWorldMap MercenaryWorldContainer;
};

#define sMercenaryMgr MercenaryMgr::GetInstance()

#endif
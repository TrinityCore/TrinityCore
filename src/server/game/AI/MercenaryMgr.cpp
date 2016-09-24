/*
    ©2013-2016 EmuDevs <http://www.emudevs.com/>
    MaNGOS <http://getmangos.eu>
    TrinityCore <http://www.trinitycore.org>
*/
#include "MercenaryMgr.h"

MercenaryMgr::MercenaryMgr() { }

MercenaryMgr::~MercenaryMgr()
{
    Clear();
}

void MercenaryMgr::SaveToList(Mercenary* mercenary)
{
    MercenaryContainer[mercenary->GetId()] = mercenary;
}

void MercenaryMgr::DeleteFromList(Mercenary* mercenary)
{
    MercenaryContainer.erase(mercenary->GetId());
}

void MercenaryMgr::LoadMercenaries()
{
    Clear();
#ifndef MANGOS
    TC_LOG_INFO("server.loading", "Loading Mercenaries..");
#else
    sLog.outBasic("Loading Mercenaries...");
#endif

#ifndef MANGOS
    QueryResult result = CharacterDatabase.Query("SELECT mercenaryType, mercenaryRole, entry, headEntry, shoulderEntry, chestEntry, legEntry, handEntry, feetEntry, weaponEntry, "
        "offHandEntry, rangedEntry FROM mercenary_start_gear");
#else
    QueryResult* result = CharacterDatabase.Query("SELECT mercenaryType, mercenaryRole, entry, headEntry, shoulderEntry, chestEntry, legEntry, handEntry, feetEntry, weaponEntry, "
        "offHandEntry, rangedEntry FROM mercenary_start_gear");
#endif
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            MercenaryStarterGear starterGear;
            starterGear.mercenaryType = fields[0].GetUInt8();
            starterGear.mercenaryRole = fields[1].GetUInt8();
            starterGear.creature_entry = fields[2].GetUInt32();
            starterGear.headEntry = fields[3].GetUInt32();
            starterGear.shoulderEntry = fields[4].GetUInt32();
            starterGear.chestEntry = fields[5].GetUInt32();
            starterGear.legEntry = fields[6].GetUInt32();
            starterGear.handEntry = fields[7].GetUInt32();
            starterGear.feetEntry = fields[8].GetUInt32();
            starterGear.weaponEntry = fields[9].GetUInt32();
            starterGear.offHandEntry = fields[10].GetUInt32();
            starterGear.rangedEntry = fields[11].GetUInt32();

            MercenaryStartGearContainer.push_back(starterGear);
        } while (result->NextRow());
    }

    result = CharacterDatabase.Query("SELECT type, role, healthpct, message FROM mercenary_talk");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            MercenaryTalking mercenaryTalking;
            mercenaryTalking.type = fields[0].GetUInt8();
            mercenaryTalking.role = fields[1].GetUInt8();
            mercenaryTalking.healthPercentageToTalk = fields[2].GetUInt8();
            mercenaryTalking.text = fields[3].GetString();

            MercenaryTalkContainer.push_back(mercenaryTalking);
        } while (result->NextRow());
    }

    result = CharacterDatabase.Query("SELECT type, role, spellId, isDefaultAura, isActive FROM mercenary_spells");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            MercenarySpell spells;
            spells.type = fields[0].GetUInt8();
            spells.role = fields[1].GetUInt8();
            spells.spellId = fields[2].GetUInt32();
            spells.isDefaultAura = fields[3].GetBool();
            spells.isActive = fields[4].GetBool();

            MercenarySpellsContainer.push_back(spells);
        } while (result->NextRow());
    }

    result = CharacterDatabase.Query("SELECT entry, modelId, race, gender FROM mercenary_world");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            MercenaryWorld world;
            world.modelId = fields[1].GetUInt32();
            world.race = fields[2].GetUInt8();
            world.gender = fields[3].GetUInt8();

            MercenaryWorldContainer[fields[0].GetUInt32()] = world;
        } while (result->NextRow());
    }

    result = CharacterDatabase.Query("SELECT type, armor_prof, weapon_prof FROM mercenary_proficiencies");
    if (result)
    {
        do
        {
            Field* field = result->Fetch();

            MercenaryProficiency prof;
            prof.type = field[0].GetUInt8();
            prof.armorSubClass = uint32(field[1].GetUInt8());
            prof.weaponSubClass = uint32(field[2].GetUInt8());

            MercenaryProficiencyContainer.push_back(prof);
        } while (result->NextRow());
    }

    result = CharacterDatabase.Query("SELECT Id, ownerGUID, role, displayId, race, gender, type, summoned FROM mercenaries");
    if (result)
    {
        do
        {
            Mercenary* mercenary = new Mercenary;
            if (!mercenary->LoadFromDB(result))
            {
                delete mercenary;
                continue;
            }

            MercenaryContainer[mercenary->GetId()] = mercenary;
        } while (result->NextRow());
   }

#ifndef MANGOS
    TC_LOG_INFO("server.loading", "Loading Mercenaries Completed..");
#else
    sLog.outBasic("Loading Mercenaries Completed..");
#endif
}

void MercenaryMgr::Clear()
{
    for (auto itr = MercenaryContainer.begin(); itr != MercenaryContainer.end(); ++itr)
        delete itr->second;
    for (auto itr = MercenaryWorldContainer.begin(); itr != MercenaryWorldContainer.end(); ++itr)
        delete &itr->second;

    MercenaryContainer.clear();
    MercenaryWorldContainer.clear();
    MercenarySpellsContainer.clear();
    MercenaryStartGearContainer.clear();
    MercenaryTalkContainer.clear();
}

void MercenaryMgr::UpdateSummoned(uint32 Id, bool summoned)
{
#ifndef MANGOS
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MERCENARY_SUMMON);
    stmt->setBool(0, summoned);
    stmt->setUInt32(1, Id);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
#endif
}

void MercenaryMgr::OnSave(Player* player, Pet* pet)
{
#ifndef MANGOS
    Mercenary* mercenary = GetMercenaryByOwner(player->GetGUID().GetCounter());
#else
    Mercenary* mercenary = GetMercenaryByOwner(player->GetGUIDLow());
#endif
    if (!mercenary)
        return;

    if (!mercenary->IsBeingCreated())
    {
        mercenary->UpdateGear();
#ifndef MANGOS
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MERCENARY);
        stmt->setUInt32(0, mercenary->GetId());
        trans->Append(stmt);
        CharacterDatabase.CommitTransaction(trans);
#else
        CharacterDatabase.BeginTransaction();
        static SqlStatementID delMerc;

        SqlStatement stmt = CharacterDatabase.CreateStatement(delMerc, "DELETE FROM mercenaries WHERE Id=?");
        stmt.PExecute(mercenary->GetId());

        CharacterDatabase.CommitTransaction();
#endif
        mercenary->SaveToDB();
    }
}

void MercenaryMgr::OnDelete(uint32 guidLow)
{
    Mercenary* mercenary = GetMercenary(guidLow);
    if (!mercenary)
        return;

    mercenary->DeleteFromDB();
}

void MercenaryMgr::OnSummon(Player* player)
{
#ifndef MANGOS
    if (Mercenary* mercenary = GetMercenaryByOwner(player->GetGUID().GetCounter()))
#else
    if (Mercenary* mercenary = GetMercenaryByOwner(player->GetGUIDLow()))
#endif
        mercenary->Summon(player);
}

std::string MercenaryMgr::GetSpellIcon(uint32 entry, WorldSession* session) const
{
    std::ostringstream ss;
    ss << "|T";
#ifndef MANGOS
    const SpellInfo* temp = sSpellMgr->GetSpellInfo(entry);
#else
    const SpellEntry* temp = sSpellStore.LookupEntry(entry);
#endif
    const SpellIconEntry* icon = nullptr;
    std::string name = "";
    if (temp)
    {
        name = temp->SpellName[session->GetSessionDbcLocale()];
        icon = sSpellIconStore.LookupEntry(temp->SpellIconID);
        if (icon)
            ss << icon->spellIcon;
    }
    if (!icon)
        ss << "Interface/ICONS/InventoryItems/WoWUnknownItem01";
    ss << ":" << 32 << ":" << 32 << ":" << -18 << ":" << 0 << "|t" << name;
    return ss.str();
}

std::string MercenaryMgr::GetItemIcon(uint32 entry, bool rawPath) const
{
    std::ostringstream ss;
    ss << "|TInterface";
#ifndef MANGOS
    const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);
#else
    const ItemPrototype* temp = sObjectMgr.GetItemPrototype(entry);
#endif
    const ItemDisplayInfoEntry* dispInfo = nullptr;
    if (temp)
    {
        dispInfo = sItemDisplayInfoStore.LookupEntry(temp->DisplayInfoID);
        if (dispInfo)
        {
            ss << "/ICONS/" << dispInfo->inventoryIcon;
            if (rawPath)
            {
                ss.str("");
                ss << "Interface/ICONS/" << dispInfo->inventoryIcon;
                return ss.str();
            }
        }
    }
    if (!dispInfo)
        ss << "/InventoryItems/WoWUnknownItem01";
    ss << ":" << 32 << ":" << 32 << ":" << -18 << ":" << 0 << "|t";
    return ss.str();
}

std::string MercenaryMgr::GetSlotIcon(uint8 slot) const
{
    std::ostringstream ss;
    ss << "|TInterface/PaperDoll/";
	switch (slot)
    {
        case SLOT_HEAD: ss << "UI-PaperDoll-Slot-Head"; break;
        case SLOT_SHOULDERS: ss << "UI-PaperDoll-Slot-Shoulder"; break;
        case SLOT_SHIRT: ss << "UI-PaperDoll-Slot-Shirt"; break;
        case SLOT_CHEST: ss << "UI-PaperDoll-Slot-Chest"; break;
        case SLOT_WAIST: ss << "UI-PaperDoll-Slot-Waist"; break;
        case SLOT_LEGS: ss << "UI-PaperDoll-Slot-Legs"; break;
        case SLOT_FEET: ss << "UI-PaperDoll-Slot-Feet"; break;
        case SLOT_WRISTS: ss << "UI-PaperDoll-Slot-Wrists"; break;
        case SLOT_HANDS: ss << "UI-PaperDoll-Slot-Hands"; break;
        case SLOT_BACK: ss << "UI-PaperDoll-Slot-Chest"; break;
        case SLOT_MAIN_HAND: ss << "UI-PaperDoll-Slot-MainHand"; break;
        case SLOT_OFF_HAND: ss << "UI-PaperDoll-Slot-SecondaryHand"; break;
        case SLOT_RANGED: ss << "UI-PaperDoll-Slot-Ranged"; break;
        case SLOT_TABARD: ss << "UI-PaperDoll-Slot-Tabard"; break;
        default: ss << "UI-Backpack-EmptySlot";
    }
    ss << ":" << 32 << ":" << 32 << ":" << -18 << ":" << 0 << "|t";
    return ss.str();
}

const char* MercenaryMgr::GetSlotName(uint8 slot) const
{
    switch (slot)
    {
        case SLOT_HEAD: return  "Head";
        case SLOT_SHOULDERS: return  "Shoulders";
        case SLOT_SHIRT: return  "Shirt";
        case SLOT_CHEST: return  "Chest";
        case SLOT_WAIST: return  "Waist";
        case SLOT_LEGS: return  "Legs";
        case SLOT_FEET: return  "Feet";
        case SLOT_WRISTS: return  "Wrists";
        case SLOT_HANDS: return  "Hands";
        case SLOT_BACK: return  "Back";
        case SLOT_MAIN_HAND: return  "Main hand";
        case SLOT_OFF_HAND: return  "Off hand";
        case SLOT_RANGED: return  "Ranged";
        case SLOT_TABARD: return  "Tabard";
        default: return "";
    }
}

std::string MercenaryMgr::GetItemLink(uint32 entry, WorldSession* session) const
{
#ifndef MANGOS
    const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);
#else
    const ItemPrototype* temp = sObjectMgr.GetItemPrototype(entry);
#endif
    int loc_idx = session->GetSessionDbLocaleIndex();
    std::string name = temp->Name1;
#ifndef MANGOS
    if (ItemLocale const* il = sObjectMgr->GetItemLocale(entry))
        ObjectMgr::GetLocaleString(il->Name, loc_idx, name);
#else
    if (ItemLocale const* il = sObjectMgr.GetItemLocale(entry))
        ObjectMgr::GetLocaleString(il->Name, loc_idx, name);
#endif

    std::ostringstream oss;
    oss << "|c" << std::hex << ItemQualityColors[temp->Quality] << std::dec <<
        "|Hitem:" << entry << ":0:0:0:0:0:0:0:0:0|h[" << name << "]|h|r";

    return oss.str();
}
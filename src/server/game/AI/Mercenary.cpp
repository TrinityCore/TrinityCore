/*
    ©2013-2016 EmuDevs <http://www.emudevs.com/>
    MaNGOS <http://getmangos.eu>
    TrinityCore <http://www.trinitycore.org>
*/
#include "Mercenary.h"
#include "MercenaryMgr.h"

Mercenary::Mercenary() { }

Mercenary::Mercenary(uint32 model, uint8 r, uint8 g, uint8 role, uint8 type)
	: displayId(model), race(r), gender(g), role(role), type(type) { }

Mercenary::~Mercenary()
{
    for (auto itr = GearContainer.begin(); itr != GearContainer.end(); ++itr)
        delete &itr;

    GearContainer.clear();
}

void Mercenary::LoadGearFromDB()
{
    GearContainer.clear();

#ifdef MANGOS
    QueryResult* result = CharacterDatabase.PQuery("SELECT itemId, slot FROM mercenary_gear WHERE guid='%u'", GetId());
#else
    QueryResult result = CharacterDatabase.PQuery("SELECT itemId, slot FROM mercenary_gear WHERE guid='%u'", GetId());
#endif
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            GearContainer.push_back(MercenaryGear(fields[0].GetUInt32(), fields[1].GetUInt8()));
        } while (result->NextRow());
    }
}

#ifdef MANGOS
bool Mercenary::LoadFromDB(QueryResult* result)
#else
bool Mercenary::LoadFromDB(QueryResult result)
#endif
{
    Field* fields = result->Fetch();
    Id = fields[0].GetUInt32();
    ownerGUID = fields[1].GetUInt32();
    role = fields[2].GetUInt8();
    displayId = fields[3].GetUInt32();
    race = fields[4].GetUInt8();
    gender = fields[5].GetUInt8();
    type = fields[6].GetUInt8();
    summoned = fields[7].GetBool();

    LoadGearFromDB();

    return true;
}

void Mercenary::SaveToDB()
{
#ifndef MANGOS
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MERCENARY);
    stmt->setUInt32(0, Id);
    stmt->setUInt32(1, ownerGUID);
    stmt->setUInt8(2, role);
    stmt->setUInt32(3, displayId);
    stmt->setUInt8(4, race);
    stmt->setUInt8(5, gender);
    stmt->setUInt8(6, type);
    stmt->setBool(7, summoned);

    trans->Append(stmt);
    CharacterDatabase.CommitTransaction(trans);
#else
    CharacterDatabase.BeginTransaction();

    static SqlStatementID insMerc;
    SqlStatement saveMerc = CharacterDatabase.CreateStatement(insMerc, "INSERT INTO mercenaries (Id, ownerGUID, role, displayId, race, gender, type, "
        "summoned) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

    saveMerc.addUInt32(Id);
    saveMerc.addUInt32(ownerGUID);
    saveMerc.addUInt8(role);
    saveMerc.addUInt32(displayId);
    saveMerc.addUInt8(race);
    saveMerc.addUInt8(gender);
    saveMerc.addUInt8(type);
    saveMerc.addBool(summoned);

    saveMerc.Execute();
    CharacterDatabase.CommitTransaction();
#endif
}

void Mercenary::SaveGearToDB()
{
#ifndef MANGOS
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    for (auto itr = GearContainer.begin(); itr != GearContainer.end(); ++itr)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MERCENARY_GEAR);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, itr->itemId);
        stmt->setUInt8(2, itr->slot);
        trans->Append(stmt);
    }
    CharacterDatabase.CommitTransaction(trans);
#else
    CharacterDatabase.BeginTransaction();

    for (auto itr = GearContainer.begin(); itr != GearContainer.end(); ++itr)
        CharacterDatabase.PExecute("INSERT INTO mercenary_gear (guid, itemId, slot) VALUES ('%u', '%u', '%u')", GetId(), itr->itemId, itr->slot);

    CharacterDatabase.CommitTransaction();
#endif
}

void Mercenary::DeleteFromDB()
{
#ifndef MANGOS
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MERCENARY);
    stmt->setUInt32(0, GetId());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MERCENARY_GEAR);
    stmt->setUInt32(0, GetId());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
#else
    static SqlStatementID delMerc;
    static SqlStatementID delGear;

    SqlStatement stmt = CharacterDatabase.CreateStatement(delMerc, "DELETE FROM mercenaries WHERE Id=?");
    stmt.PExecute(GetId());

    stmt = CharacterDatabase.CreateStatement(delGear, "DELETE FROM mercenary_gear WHERE guid=?");
    stmt.PExecute(GetId());
#endif

    sMercenaryMgr->DeleteFromList(this);
}

bool Mercenary::Create(Player* player)
{
    if (!player)
        return false;

    Id = sMercenaryMgr->MaxMercenaryId() + 1;
#ifndef MANGOS
    ownerGUID = player->GetGUID().GetCounter();
#else
    ownerGUID = player->GetGUIDLow();
#endif
    role = ROLE_NONE;
    displayId = 1;
    race = 0;
    gender = GENDER_NONE;
    type = MERCENARY_TYPE_NONE;
    summoned = false;
    beingCreated = true;

    sMercenaryMgr->SaveToList(this);

    return true;
}

bool Mercenary::Create(Player* player, uint32 model, uint8 r, uint8 g, uint8 mercType, uint8 mercRole, const std::string& name)
{
    if (!player)
        return false;

#ifndef MANGOS
    Pet* pet = new Pet(player, SUMMON_PET);
#else
    Pet* pet = new Pet;
#endif
    if (!pet)
        return false;

    if (mercType >= MAX_MERCENARY_TYPES || mercType == MERCENARY_TYPE_NONE)
    {
        delete pet;
        return false;
    }

    float x, y, z, o = 0;
#ifndef MANGOS
    player->GetPosition(x, y, z, o);
#else
    player->GetPosition(x, y, z);
#endif

    pet->Relocate(x, y, z, o);
    if (!pet->IsPositionValid())
    {
#ifndef MANGOS
        TC_LOG_ERROR("misc", "Pet (guidlow %d) suggested coordinates isn't valid (X: %f Y: %f)", pet->GetGUID().GetCounter(), pet->GetPositionX(), pet->GetPositionY());
#endif
        delete pet;
        return false;
    }

    Map* map = player->GetMap();
#ifndef MANGOS
    uint32 petNumber = sObjectMgr->GeneratePetNumber();
    uint32 guidLow = map->GenerateLowGuid<HighGuid::Pet>();

    if (!pet->Create(guidLow, map, player->GetPhaseMask(), MERCENARY_DEFAULT_ENTRY, petNumber))
#else
    CreatureCreatePos pos(player, player->GetOrientation());
    CreatureInfo const* creatureInfo = ObjectMgr::GetCreatureTemplate(MERCENARY_DEFAULT_ENTRY);
    if (!creatureInfo)
    {
        delete pet;
        return false;
    }

    uint32 petNumber = sObjectMgr.GeneratePetNumber();
    uint32 guid = pos.GetMap()->GenerateLocalLowGuid(HIGHGUID_PET);

    if (!pet->Create(guid, pos, creatureInfo, petNumber))
#endif
    {
        delete pet;
        return false;
    }

    Id = petNumber;
#ifndef MANGOS
    ownerGUID = player->GetGUID().GetCounter();
#else
    ownerGUID = player->GetGUIDLow();
#endif
    role = mercRole;
    displayId = model;
    race = r;
    gender = g;
    type = mercType;
    if (!name.empty())
        pet->SetName(name);

    Initialize(player, pet, true);

    ChatHandler(player->GetSession()).SendSysMessage("Successfully created a mercenary!");
#ifndef MANGOS
    pet->Say("Thanks for choosing me as your mercenary! Talk to me to setup my skills, gear, etc.", LANG_UNIVERSAL, player);
#else
    pet->MonsterSay("Thanks for choosing me as your mercenary! Talk to me to setup my skills, gear, etc.", LANG_UNIVERSAL, player);
#endif
    editSlot = SLOT_EMPTY;
    summoned = true;
    beingCreated = false;

    SaveToDB();
    sMercenaryMgr->SaveToList(this);

    return true;
}

bool Mercenary::LearnSpell(Player* player, uint32 spellId)
{
    if (!player)
        return false;

    Pet* pet = player->GetPet();
    if (!pet)
        return false;

    pet->learnSpell(spellId);

    return true;
}

bool Mercenary::Summon(Player* player)
{
    if (!player)
        return false;

    Pet* pet = player->GetPet();
    if (!pet)
        return false;

    Initialize(player, pet, false);

    return true;
}

void Mercenary::Initialize(Player* player, Pet* pet, bool create)
{
    if (!create)
    {
        pet->SetDisplayId(GetDisplay());
        pet->SetNativeDisplayId(GetDisplay());
        pet->SetPower(POWER_MANA, pet->GetMaxPower(POWER_MANA));
        pet->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

        InitStats(player, pet);

        pet->SetUInt32Value(UNIT_FIELD_PETNUMBER, GetId());

        for (auto itr = GearBegin(); itr != GearEnd(); ++itr)
        {
            if (itr->slot == SLOT_MAIN_HAND)
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, itr->itemId);
            if (itr->slot == SLOT_OFF_HAND)
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, itr->itemId);
            if (itr->slot == SLOT_RANGED)
               pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, itr->itemId);
        }
    }
    else
    {
#ifndef MANGOS
        pet->SetCreatorGUID(player->GetGUID());
        pet->setPowerType(POWER_MANA);
#else
        pet->SetUInt32Value(UNIT_FIELD_PETNUMBER, GetId());
        pet->SetOwnerGuid(player->GetObjectGuid());
        pet->SetCreatorGuid(player->GetObjectGuid());
        pet->SetPowerType(POWER_MANA);
        pet->setPetType(SUMMON_PET);
#endif
        pet->GetCharmInfo()->SetPetNumber(GetId(), true);
        pet->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, player->getFaction());
        pet->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        pet->SetDisplayId(GetDisplay());
        pet->SetNativeDisplayId(GetDisplay());
        pet->SetPower(POWER_MANA, pet->GetMaxPower(POWER_MANA));

        if (player->IsPvP())
            pet->SetPvP(true);
        if (player->IsFFAPvP())
#ifdef MANGOS
            pet->SetFFAPvP(true);
#else
            pet->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
#endif
        InitStats(player, pet);

        pet->SetUInt32Value(UNIT_FIELD_BYTES_0, 2048);
        pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
        pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, 1000);
        pet->SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, uint32(time(NULL)));
#ifdef MANGOS
        pet->GetCharmInfo()->SetReactState(REACT_DEFENSIVE);
#else
        pet->SetReactState(REACT_DEFENSIVE);
#endif
        pet->InitPetCreateSpells();

        for (auto itr = sMercenaryMgr->MercenaryStartGearBegin(); itr != sMercenaryMgr->MercenaryStartGearEnd(); ++itr)
        {
            if (GetType() == itr->mercenaryType && role == itr->mercenaryRole && itr->creature_entry == pet->GetEntry())
            {
                GearContainer.push_back(MercenaryGear(itr->headEntry, SLOT_HEAD));
                GearContainer.push_back(MercenaryGear(itr->shoulderEntry, SLOT_SHOULDERS));
                GearContainer.push_back(MercenaryGear(itr->chestEntry, SLOT_CHEST));
                GearContainer.push_back(MercenaryGear(itr->legEntry, SLOT_LEGS));
                GearContainer.push_back(MercenaryGear(itr->feetEntry, SLOT_FEET));
                GearContainer.push_back(MercenaryGear(itr->handEntry, SLOT_HANDS));
                GearContainer.push_back(MercenaryGear(itr->weaponEntry, SLOT_MAIN_HAND));
                GearContainer.push_back(MercenaryGear(itr->offHandEntry, SLOT_OFF_HAND));
                GearContainer.push_back(MercenaryGear(itr->rangedEntry, SLOT_RANGED));
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, itr->weaponEntry);
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, itr->offHandEntry);
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, itr->rangedEntry);
                SaveGearToDB();
            }
        }

#ifndef MANGOS
        pet->SetFullHealth();
        player->SetMinion(pet, true);
        player->GetMap()->AddToMap(pet->ToCreature());
#else
        pet->SetHealth(pet->GetMaxHealth());
        pet->AIM_Initialize();
        player->GetMap()->Add((Creature*)pet);
        player->SetPet(pet);
#endif
        player->PetSpellInitialize();
    }
}

bool Mercenary::CanEquipItem(Player* player, Item* item)
{
    WorldSession* session = player->GetSession();
    if (!item)
        return false;

#ifndef MANGOS
    const ItemTemplate* proto = item->GetTemplate();
#else
    const ItemPrototype* proto = item->GetProto();
#endif
    if (!proto)
    {
        ChatHandler(session).SendSysMessage("Invalid item! Your mercenary could not equip this item.");
#ifndef MANGOS
        TC_LOG_ERROR("misc", "Tried to equip invalid item %u. Item does not have a template.", item->GetEntry());
#else
        sLog.outError("Tried to equip invalid item %u.Item does not have a template.", item->GetEntry());
#endif
        return false;
    }

    Pet* pet = player->GetPet();
    if (!pet)
        return false;

    uint32 itemClass = proto->Class;
    uint32 itemSubClass = proto->SubClass;
    uint32 invType = proto->InventoryType;
    bool isCorrectProficiency = sMercenaryMgr->CheckProficiencies(type, itemClass, itemSubClass);
    bool isCorrectLevel = pet->getLevel() >= proto->RequiredLevel;
    if (proto->RequiredLevel > 0 && !isCorrectLevel)
    {
        ChatHandler(session).PSendSysMessage("Equip item failed! Item level is too high. You can equip this item on your Mercenary when they are level %u.", proto->RequiredLevel);
        return false;
    }

    if (itemClass == ITEM_CLASS_ARMOR && (invType != INVTYPE_SHIELD && invType != INVTYPE_HOLDABLE) && !isCorrectProficiency)
    {
        ChatHandler(session).SendSysMessage("Equip failed. Mercenary cannot equip this armor proficiency.");
        return false;
    }

    if ((itemClass == ITEM_CLASS_WEAPON || (itemClass == ITEM_CLASS_ARMOR && (invType == INVTYPE_SHIELD || invType == INVTYPE_HOLDABLE))) && !isCorrectProficiency)
    {
        ChatHandler(session).SendSysMessage("Equip failed. Mercenary cannot equip this weapon proficiency.");
        return false;
    }

    if (editSlot == SLOT_MAIN_HAND)
    {
        if (invType != INVTYPE_2HWEAPON && invType != INVTYPE_WEAPONMAINHAND && invType != INVTYPE_WEAPON)
        {
            ChatHandler(session).SendSysMessage("Equip failed. Cannot equip an off hand weapon in your Mercenary's main hand.");
            return false;
        }
    }
    else if (editSlot == SLOT_OFF_HAND)
    {
        if (invType == INVTYPE_2HWEAPON && invType == INVTYPE_WEAPONMAINHAND && invType == INVTYPE_WEAPON)
        {
            ChatHandler(session).SendSysMessage("Equip failed. Cannot equip a two handed, main hand or one handed in your Mercenary's off hand.");
            return false;
        }
    }

    uint32 newItemId = item->GetEntry();
    for (auto itr = GearContainer.begin(); itr != GearContainer.end(); ++itr)
    {
        if (itemClass == ITEM_CLASS_ARMOR || itemClass == ITEM_CLASS_WEAPON)
        {
            if (itr->slot == editSlot)
                itr->itemId = newItemId;

            if (itr->slot == editSlot && editSlot == SLOT_MAIN_HAND)
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, itr->itemId);
            else if (itr->slot == editSlot && editSlot == SLOT_OFF_HAND)
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, itr->itemId);
            else if (itr->slot == editSlot && editSlot == SLOT_RANGED)
                pet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, itr->itemId);
        }
    }

    if (editSlot != SLOT_MAIN_HAND || editSlot != SLOT_OFF_HAND || editSlot != SLOT_RANGED)
        SendMirrorImagePacket(pet);

    UpdateAllStats(player, pet);

    return true;
}

bool Mercenary::InitStats(Player* player, Pet* pet)
{
    uint8 mercenaryLevel = player->getLevel();

#ifndef MANGOS
    CreatureTemplate const* creatureInfo = pet->GetCreatureTemplate();
#else
    CreatureInfo const* creatureInfo = pet->GetCreatureInfo();
#endif
    if (!creatureInfo)
    {
#ifdef MANGOS
        sLog.outError("Failed to load creature info for Mercenary");
#else
        TC_LOG_ERROR("misc", "Failed to load creature info for Mercenary");
#endif
        return false;
    }

    pet->SetLevel(mercenaryLevel);

#ifndef MANGOS
    pet->SetMeleeDamageSchool(SpellSchools(creatureInfo->dmgschool));
#else
    pet->SetMeleeDamageSchool(SpellSchools(creatureInfo->DamageSchool));
#endif
    //@TODO Below, Change by stats (gear)
    pet->SetModifierValue(UNIT_MOD_ARMOR, BASE_VALUE, float(mercenaryLevel * 50));
    pet->SetAttackTime(BASE_ATTACK, BASE_ATTACK_TIME);
    pet->SetAttackTime(OFF_ATTACK, BASE_ATTACK_TIME);
    pet->SetAttackTime(RANGED_ATTACK, BASE_ATTACK_TIME);
    pet->SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);

    pet->SetObjectScale(1.0f);

#ifndef MANGOS
    for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
        pet->SetModifierValue(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, float(creatureInfo->resistance[i]));
#else
    int32 createResistance[MAX_SPELL_SCHOOL] = { 0, 0, 0, 0, 0, 0, 0 };
    createResistance[SPELL_SCHOOL_HOLY] = creatureInfo->ResistanceHoly;
    createResistance[SPELL_SCHOOL_FIRE] = creatureInfo->ResistanceFire;
    createResistance[SPELL_SCHOOL_NATURE] = creatureInfo->ResistanceNature;
    createResistance[SPELL_SCHOOL_FROST] = creatureInfo->ResistanceFrost;
    createResistance[SPELL_SCHOOL_SHADOW] = creatureInfo->ResistanceShadow;
    createResistance[SPELL_SCHOOL_ARCANE] = creatureInfo->ResistanceArcane;
    for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
        pet->SetModifierValue(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, float(createResistance[i]));
#endif

#ifndef MANGOS
    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(mercenaryLevel, creatureInfo->unit_class);
    pet->SetCreateHealth(stats->BaseHealth[creatureInfo->expansion]);
    pet->SetCreateMana(stats->BaseMana);
#else
    pet->SetCreateHealth(uint32(((float(creatureInfo->MaxLevelHealth) / creatureInfo->MaxLevel) / (1 + 2 * creatureInfo->Rank)) * mercenaryLevel));
    pet->SetCreateMana(uint32(((float(creatureInfo->MaxLevelMana) / creatureInfo->MaxLevel) / (1 + 2 * creatureInfo->Rank)) * mercenaryLevel));
#endif

    pet->SetCreateStat(STAT_STRENGTH, 22);
    pet->SetCreateStat(STAT_AGILITY, 22);
    pet->SetCreateStat(STAT_STAMINA, 25);
    pet->SetCreateStat(STAT_INTELLECT, 28);
    pet->SetCreateStat(STAT_SPIRIT, 27);

#ifndef MANGOS
    pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32(sObjectMgr->GetXPForLevel(mercenaryLevel) * 0.05f));
#else
    pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32(sObjectMgr.GetXPForLevel(mercenaryLevel) * 0.05f));
#endif

    pet->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(mercenaryLevel - (mercenaryLevel / 4)));
    pet->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(mercenaryLevel + (mercenaryLevel / 4)));

    for (uint8 i = STAT_STRENGTH; i < MAX_STATS; ++i)
        UpdateStats(player, Stats(i), pet);
    for (uint8 i = POWER_MANA; i < MAX_POWERS; ++i)
        UpdateMaxPower(Powers(i), pet);
#ifndef MANGOS
    pet->UpdateAllResistances();
    pet->SetFullHealth();
#else
    for (int i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
        pet->UpdateResistances(i);
    pet->SetHealth(pet->GetMaxHealth());
#endif
    pet->SetPower(POWER_MANA, pet->GetMaxPower(POWER_MANA));

    return true;
}

bool Mercenary::UpdateStats(Player* player, Stats stat, Pet* pet)
{
    if (stat >= MAX_STATS)
        return false;

    float value = pet->GetTotalStatValue(stat);
    pet->ApplyStatBuffMod(stat, player->GetStat(stat), false);
    float ownersBonus = 0.0f;

    float mod = 0.75f;
    if (stat == STAT_STAMINA)
    {
        // Small stamina gain (Basic advantage of having a Mercenary)
#ifndef MANGOS
        value += CalculatePct(player->GetStat(stat), 15);
#else
        value += float(player->GetStat(stat)) * 0.3f;
#endif
    }
    else if (stat == STAT_INTELLECT)
    {
        // Small intellect gain (Basic advantage of having a Mercenary)
#ifndef MANGOS
        value += CalculatePct(player->GetStat(stat), 15);
#else
        value += float(player->GetStat(stat)) * 0.3f;
#endif
    }
    else if (stat == STAT_STRENGTH)
    {
        // Small strength gain (Basic advantage of having a Mercenary)
#ifndef MANGOS
        value += CalculatePct(player->GetStat(stat), 15);
#else
        value += float(player->GetStat(stat)) * 0.3f;
#endif
    }

    for (auto itr = GearBegin(); itr != GearEnd(); ++itr)
    {
#ifndef MANGOS
        const ItemTemplate* proto = sObjectMgr->GetItemTemplate(itr->itemId);
#else
        const ItemPrototype* proto = sObjectMgr.GetItemPrototype(itr->itemId);
#endif
        if (proto)
        {
            for (uint32 i = 0; i < proto->StatsCount; i++)
            {
                uint32 statType = proto->ItemStat[i].ItemStatType;
                uint32 statTypeVal = proto->ItemStat[i].ItemStatValue;
                if ((stat == STAT_STRENGTH && statType == ITEM_MOD_STRENGTH) || (stat == STAT_AGILITY && statType == ITEM_MOD_AGILITY) ||
                    (stat == STAT_INTELLECT && statType == ITEM_MOD_INTELLECT) || (stat == STAT_STAMINA && statType == ITEM_MOD_STAMINA))
                    value += float(statTypeVal);
            }
        }
    }

    pet->SetStat(stat, int32(value));
    pet->ApplyStatBuffMod(stat, player->GetStat(stat) + ownersBonus, true);

    switch (stat)
    {
        case STAT_STRENGTH: UpdateStrength(pet); break;
        case STAT_AGILITY: UpdateArmor(pet); break;
        case STAT_STAMINA: UpdateMaxHealth(pet); break;
        case STAT_INTELLECT: UpdateMaxPower(POWER_MANA, pet); break;
        case STAT_SPIRIT:
        default:
            break;
    }

    return true;
}

bool Mercenary::UpdateAllStats(Player* player, Pet* pet)
{
    if (!player)
        return false;

    if (!pet)
        return false;

    for (int i = STAT_STRENGTH; i < MAX_STATS; ++i)
        UpdateStats(player, Stats(i), pet);
    for (int i = POWER_MANA; i < MAX_POWERS; ++i)
        UpdateMaxPower(Powers(i), pet);

    return true;
}

void Mercenary::SetValues(uint32 model, uint8 r, uint8 g)
{
    displayId = model;
    race = r;
    gender = g;
}

void Mercenary::UpdateGear()
{
#ifndef MANGOS
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    for (auto itr = GearContainer.begin(); itr != GearContainer.end(); ++itr)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MERCENARY_GEAR);
        stmt->setUInt32(0, itr->itemId);
        stmt->setUInt32(1, GetId());
        stmt->setUInt32(2, itr->slot);
        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);
#else
    CharacterDatabase.BeginTransaction();

    for (auto itr = GearContainer.begin(); itr != GearContainer.end(); ++itr)
        CharacterDatabase.PExecute("UPDATE mercenary_gear SET itemId='%u' WHERE guid='%u' AND slot='%u'", itr->itemId, GetId(), itr->slot);

    CharacterDatabase.CommitTransaction();
#endif
}

void Mercenary::RemoveOffHand(Creature* creature)
{
    if (!creature)
        return;

    for (auto itr = GearContainer.begin(); itr != GearContainer.end(); ++itr)
    {
        if (itr->slot == SLOT_OFF_HAND)
            itr->itemId = 0;
    }
    creature->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, 0);
}

void Mercenary::SendMirrorImagePacket(Creature* creature)
{
    WorldPacket data(SMSG_MIRRORIMAGE_DATA, 68);
#ifndef MANGOS
    data << uint64(creature->GetGUID());
#else
    data << creature->GetObjectGuid();
#endif
    data << uint32(GetDisplay());
    data << uint8(GetRace());
    data << uint8(GetGender());
    data << uint8(1);
    data << uint8(0); // Skin
    data << uint8(0); // Face
    data << uint8(0); // Hair
    data << uint8(0); // Hair color
    data << uint8(0); // Facial hair
    data << uint32(0);
    data << uint32(sMercenaryMgr->GetItemDisplayId(GetItemBySlot(SLOT_HEAD)));
    data << uint32(sMercenaryMgr->GetItemDisplayId(GetItemBySlot(SLOT_SHOULDERS)));
    data << uint32(0); // Shirt?
    data << uint32(sMercenaryMgr->GetItemDisplayId(GetItemBySlot(SLOT_CHEST)));
    data << uint32(0); // Waist
    data << uint32(sMercenaryMgr->GetItemDisplayId(GetItemBySlot(SLOT_LEGS)));
    data << uint32(sMercenaryMgr->GetItemDisplayId(GetItemBySlot(SLOT_FEET)));
    data << uint32(0); // Wrists
    data << uint32(sMercenaryMgr->GetItemDisplayId(GetItemBySlot(SLOT_HANDS)));
    data << uint32(0); // Cloak
    data << uint32(0); // Tabard

    creature->SendMessageToSet(&data, false);
}

void Mercenary::UpdateStrength(Pet* pet, bool ranged)
{
    if (ranged)
        return;

    float val = 0.0f;
    float bonusAP = 0.0f;
    UnitMods unitMod = UNIT_MOD_ATTACK_POWER;

	val = 2 * pet->GetStat(STAT_STRENGTH) - 20.0f;

    Unit* owner = pet->GetOwner();

    pet->SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, val + bonusAP);

    float base_attPower = pet->GetModifierValue(unitMod, BASE_VALUE) * pet->GetModifierValue(unitMod, BASE_PCT);
    float attPowerMod = pet->GetModifierValue(unitMod, TOTAL_VALUE);
    float attPowerMultiplier = pet->GetModifierValue(unitMod, TOTAL_PCT) - 1.0f;

    pet->SetInt32Value(UNIT_FIELD_ATTACK_POWER, (int32)base_attPower);
    pet->SetInt32Value(UNIT_FIELD_ATTACK_POWER_MODS, (int32)attPowerMod);
    pet->SetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER, attPowerMultiplier);

    UpdatePhysicalDamage(BASE_ATTACK, pet);
}

void Mercenary::UpdatePhysicalDamage(WeaponAttackType attackType, Pet* pet)
{
    if (attackType > BASE_ATTACK)
        return;

    UnitMods unitMod = UNIT_MOD_DAMAGE_MAINHAND;

    float att_speed = float(pet->GetAttackTime(BASE_ATTACK)) / 1000.0f;
    float base_value = pet->GetModifierValue(unitMod, BASE_VALUE) + pet->GetTotalAttackPowerValue(attackType) / 14.0f * att_speed;
    float base_pct = pet->GetModifierValue(unitMod, BASE_PCT);
    float total_value = pet->GetModifierValue(unitMod, TOTAL_VALUE);
    float total_pct = pet->GetModifierValue(unitMod, TOTAL_PCT);
    float weapon_mindamage = pet->GetWeaponDamageRange(BASE_ATTACK, MINDAMAGE);
    float weapon_maxdamage = pet->GetWeaponDamageRange(BASE_ATTACK, MAXDAMAGE);
    float mindamage = ((base_value + weapon_mindamage) * base_pct + total_value) * total_pct;
    float maxdamage = ((base_value + weapon_maxdamage) * base_pct + total_value) * total_pct;
    for (auto itr = GearBegin(); itr != GearEnd(); ++itr)
    {
        if (itr->slot == SLOT_MAIN_HAND || itr->slot == SLOT_OFF_HAND)
        {
#ifndef MANGOS
            const ItemTemplate* proto = sObjectMgr->GetItemTemplate(itr->itemId);
#else
            const ItemPrototype* proto = sObjectMgr.GetItemPrototype(itr->itemId);
#endif
            if (proto)
            {
                mindamage += proto->Damage[0].DamageMin;
                maxdamage += proto->Damage[0].DamageMax;
            }
        }
    }

    pet->SetStatFloatValue(UNIT_FIELD_MINDAMAGE, mindamage);
    pet->SetStatFloatValue(UNIT_FIELD_MAXDAMAGE, maxdamage);
}

void Mercenary::UpdateArmor(Pet* pet)
{
    uint32 armor = 0.0f;
    float value = 0.0f;
    float bonusArmor = 0.0f;
    UnitMods unitMod = UNIT_MOD_ARMOR;

    for (auto itr = GearBegin(); itr != GearEnd(); ++itr)
    {
#ifndef MANGOS
        const ItemTemplate* proto = sObjectMgr->GetItemTemplate(itr->itemId);
#else
        const ItemPrototype* proto = sObjectMgr.GetItemPrototype(itr->itemId);
#endif
        if (proto)
        {
            if (proto->Armor > 0)
                armor += proto->Armor;
        }
    }

    value = pet->GetModifierValue(unitMod, BASE_VALUE);
    value *= pet->GetModifierValue(unitMod, BASE_PCT);
    value += pet->GetStat(STAT_AGILITY) * 1.5f; // Decreased gain by 0.5
    value += pet->GetModifierValue(unitMod, TOTAL_VALUE);
    value *= pet->GetModifierValue(unitMod, TOTAL_PCT);
    value += (float)armor;

    pet->SetArmor(int32(value));
}

void Mercenary::UpdateMaxHealth(Pet* pet)
{
    UnitMods unitMod = UNIT_MOD_HEALTH;
    float stamina = pet->GetStat(STAT_STAMINA) - pet->GetCreateStat(STAT_STAMINA);

    float value = pet->GetModifierValue(unitMod, BASE_VALUE) + pet->GetCreateHealth();
    value *= pet->GetModifierValue(unitMod, BASE_PCT);
    value += pet->GetModifierValue(unitMod, TOTAL_VALUE) + stamina * 10.0f;
    value *= pet->GetModifierValue(unitMod, TOTAL_PCT);

    pet->SetMaxHealth((uint32)value);
}

void Mercenary::UpdateMaxPower(Powers power, Pet* pet)
{
    UnitMods unitMod = UnitMods(UNIT_MOD_POWER_START + power);

    float addValue = (power == POWER_MANA) ? pet->GetStat(STAT_INTELLECT) - pet->GetCreateStat(STAT_INTELLECT) : 0.0f;

    float value = pet->GetModifierValue(unitMod, BASE_VALUE) + pet->GetCreatePowers(power);
    value *= pet->GetModifierValue(unitMod, BASE_PCT);
    value += pet->GetModifierValue(unitMod, TOTAL_VALUE) + addValue * 15.0f;
    value *= pet->GetModifierValue(unitMod, TOTAL_PCT);

    pet->SetMaxPower(power, uint32(value));
}

uint8 Mercenary::GetInvTypeSlot(uint8 characterSlot) const
{
    static uint8 invSlots[] =
    {
        INVTYPE_HEAD,
        INVTYPE_NECK,
        INVTYPE_SHOULDERS,
        NULL,
        INVTYPE_CHEST,
        INVTYPE_WAIST,
        INVTYPE_LEGS,
        INVTYPE_FEET,
        INVTYPE_WRISTS,
        INVTYPE_HANDS,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        INVTYPE_WEAPONMAINHAND,
        INVTYPE_WEAPONOFFHAND,
        INVTYPE_RANGED
    };
    return invSlots[characterSlot];
}
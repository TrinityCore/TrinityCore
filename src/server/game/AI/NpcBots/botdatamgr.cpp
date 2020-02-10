#include "botdatamgr.h"
#include "Item.h"
#include "Map.h"
#include "MapManager.h"
/*
Npc Bot Data Manager by Trickerer (onlysuffering@gmail.com)
NpcBots DB Data management
%Complete: ???
*/

typedef std::unordered_map<uint32 /*entry*/, NpcBotData*> NpcBotDataMap;
typedef std::unordered_map<uint32 /*entry*/, NpcBotAppearanceData*> NpcBotAppearanceDataMap;
typedef std::unordered_map<uint32 /*entry*/, NpcBotExtras*> NpcBotExtrasMap;
NpcBotDataMap _botsData;
NpcBotAppearanceDataMap _botsAppearanceData;
NpcBotExtrasMap _botsExtras;

bool allBotsLoaded = false;

void BotDataMgr::LoadNpcBots()
{
    uint32 botoldMSTime = getMSTime();

    TC_LOG_INFO("server.loading", "Starting NpcBot system...");

    Field* field;
    uint8 index;

    //                                                      1       2     3     4     5          6
    QueryResult result = WorldDatabase.Query("SELECT entry, gender, skin, face, hair, haircolor, features FROM creature_template_npcbot_appearance");
    if (result)
    {
        do
        {
            field = result->Fetch();
            index = 0;
            uint32 entry = field[  index].GetUInt32();

            NpcBotAppearanceData* appearanceData = new NpcBotAppearanceData();
            appearanceData->gender =    field[++index].GetUInt8();
            appearanceData->skin =      field[++index].GetUInt8();
            appearanceData->face =      field[++index].GetUInt8();
            appearanceData->hair =      field[++index].GetUInt8();
            appearanceData->haircolor = field[++index].GetUInt8();
            appearanceData->features =  field[++index].GetUInt8();

            _botsAppearanceData[entry] = appearanceData;

        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Bot appearance data loaded");
    }
    else
        TC_LOG_INFO("server.loading", ">> Bots appearance data is not loaded. Table `creature_template_npcbot_appearance` is empty!");

    //                                          1      2
    result = WorldDatabase.Query("SELECT entry, class, race FROM creature_template_npcbot_extras");
    if (result)
    {
        do
        {
            field = result->Fetch();
            index = 0;
            uint32 entry = field[  index].GetUInt32();

            NpcBotExtras* extras = new NpcBotExtras();
            extras->bclass = field[++index].GetUInt8();
            extras->race   = field[++index].GetUInt8();

            _botsExtras[entry] = extras;

        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Bot race data loaded");
    }
    else
        TC_LOG_INFO("server.loading", ">> Bots race data is not loaded. Table `creature_template_npcbot_extras` is empty!");

    //                                                     1      2      3       4        5          6          7            8            9             10         11          12        13
    result = CharacterDatabase.Query("SELECT entry, owner, roles, faction, equipMhEx, equipOhEx, equipRhEx, equipHead, equipShoulders, equipChest, equipWaist, equipLegs, equipFeet,"
    //       14          15         16         17          18             19             20            21            22
        "equipWrist, equipHands, equipBack, equipBody, equipFinger1, equipFinger2, equipTrinket1, equipTrinket2, equipNeck FROM characters_npcbot");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Spawned 0 npcbots. Table `characters_npcbot` is empty!");
        allBotsLoaded = true;
        return;
    }

    uint32 botcounter = 0;
    uint32 datacounter = 0;
    std::list<uint32> botgrids;
    QueryResult infores;
    CreatureTemplate const* proto;
    NpcBotData* botData;
    std::list<uint32> entryList;

    do
    {
        field = result->Fetch();
        index = 0;
        uint32 entry = field[  index].GetUInt32();
        entryList.push_back(entry);

        //load data
        botData = new NpcBotData(0, 0);
        botData->owner =         field[++index].GetUInt32();
        botData->roles =         field[++index].GetUInt16();
        botData->faction =       field[++index].GetUInt32();

        for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
            botData->equips[i] = field[++index].GetUInt32();

        _botsData[entry] = botData;
        ++datacounter;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u bot data entries", datacounter);

    for (std::list<uint32>::const_iterator itr = entryList.begin(); itr != entryList.end(); ++itr)
    {
        uint32 entry = *itr;
        proto = sObjectMgr->GetCreatureTemplate(entry);
        if (!proto)
        {
            TC_LOG_ERROR("server.loading", "Cannot find creature_template entry for npcbot (id: %u)!", entry);
            continue;
        }
        //                                      1    2       3           4           5            6
        infores = WorldDatabase.PQuery("SELECT guid, map, position_x, position_y"/*, position_z, orientation*/" FROM creature WHERE id = %u", entry);
        if (!infores)
        {
            TC_LOG_ERROR("server.loading", "Cannot spawn npcbot %s (id: %u), not found in `creature` table!", proto->Name.c_str(), entry);
            continue;
        }

        field = infores->Fetch();
        uint32 tableGuid = field[0].GetUInt32();
        uint32 mapId = uint32(field[1].GetUInt16());
        float pos_x = field[2].GetFloat();
        float pos_y = field[3].GetFloat();
        //float pos_z = field[4].GetFloat();
        //float ori = field[5].GetFloat();

        //TC_LOG_ERROR("entiites.unit", "Loading bot: map %u guid %u entry %u", mapId, tableGuid, entry);

        CellCoord c = Trinity::ComputeCellCoord(pos_x, pos_y);
        GridCoord g = Trinity::ComputeGridCoord(pos_x, pos_y);
        ASSERT(c.IsCoordValid() && "Invalid Cell coord!");
        ASSERT(g.IsCoordValid() && "Invalid Grid coord!");
        Map* map = sMapMgr->CreateBaseMap(mapId);
        map->LoadGrid(pos_x, pos_y);
        /*This code fails on TC 2019 but everything works just fine*/
        //Creature* bot = map->GetCreature(ObjectGuid(HighGuid::Unit, entry, tableGuid));
        //ASSERT(bot);
        //debug
        //if (!bot->IsAlive())
        //{
        //    bot->Respawn();
        //    bot->ResetBotAI(1);
        //}

        TC_LOG_DEBUG("server.loading", ">> Spawned npcbot %s (id: %u, map: %u, grid: %u, cell: %u)", proto->Name.c_str(), entry, mapId, g.GetId(), c.GetId());
        botgrids.push_back(g.GetId());
        ++botcounter;
    }

    botgrids.sort();
    botgrids.unique();
    TC_LOG_INFO("server.loading", ">> Spawned %u npcbot(s) within %u grid(s) in %u ms", botcounter, uint32(botgrids.size()), GetMSTimeDiffToNow(botoldMSTime));

    allBotsLoaded = true;
}

void BotDataMgr::AddNpcBotData(uint32 entry, uint16 roles, uint32 faction)
{
    //botData must be allocated explicitly
    NpcBotDataMap::iterator itr = _botsData.find(entry);
    if (itr == _botsData.end())
    {
        NpcBotData* botData = new NpcBotData(roles, faction);
        _botsData[entry] = botData;

        PreparedStatement* bstmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_NPCBOT);
        //"INSERT INTO characters_npcbot (entry, roles) VALUES (?, ?)", CONNECTION_ASYNCH
        bstmt->setUInt32(0, entry);
        bstmt->setUInt16(1, roles);
        CharacterDatabase.Execute(bstmt);

        //move this
        BotDataMgr::UpdateNpcBotData(entry, NPCBOT_UPDATE_FACTION, &(botData->faction));
        return;
    }

    TC_LOG_ERROR("sql.sql", "BotMgr::AddNpcBotData(): trying to add new data but entry already exists! entry = %u", entry);
}
NpcBotData const* BotDataMgr::SelectNpcBotData(uint32 entry)
{
    NpcBotDataMap::const_iterator itr = _botsData.find(entry);
    return itr != _botsData.end() ? itr->second : nullptr;
}
void BotDataMgr::UpdateNpcBotData(uint32 entry, NpcBotDataUpdateType updateType, void* data)
{
    NpcBotDataMap::iterator itr = _botsData.find(entry);
    if (itr == _botsData.end())
        return;

    PreparedStatement* bstmt;
    switch (updateType)
    {
        case NPCBOT_UPDATE_OWNER:
            itr->second->owner = *(uint32*)(data);
            bstmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER);
            //"UPDATE characters_npcbot SET owner = ? WHERE entry = ?", CONNECTION_ASYNC
            bstmt->setUInt32(0, itr->second->owner);
            bstmt->setUInt32(1, entry);
            CharacterDatabase.Execute(bstmt);
            break;
        case NPCBOT_UPDATE_ROLES:
            itr->second->roles = *(uint16*)(data);
            bstmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_ROLES);
            //"UPDATE character_npcbot SET roles = ? WHERE entry = ?", CONNECTION_ASYNC
            bstmt->setUInt16(0, itr->second->roles);
            bstmt->setUInt32(1, entry);
            CharacterDatabase.Execute(bstmt);
            break;
        case NPCBOT_UPDATE_FACTION:
            itr->second->faction = *(uint32*)(data);
            bstmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_FACTION);
            //"UPDATE characters_npcbot SET faction = ? WHERE entry = ?", CONNECTION_ASYNCH
            bstmt->setUInt32(0, itr->second->faction);
            bstmt->setUInt32(1, entry);
            CharacterDatabase.Execute(bstmt);
            break;
        case NPCBOT_UPDATE_EQUIPS:
        {
            Item** items = (Item**)(data);

            int8 id = 1;
            EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(entry, id);

            SQLTransaction trans = CharacterDatabase.BeginTransaction();

            bstmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_EQUIP);
            //"UPDATE character_npcbot SET equipMhEx = ?, equipOhEx = ?, equipRhEx = ?, equipHead = ?, equipShoulders = ?, equipChest = ?, equipWaist = ?, equipLegs = ?,
            //equipFeet = ?, equipWrist = ?, equipHands = ?, equipBack = ?, equipBody = ?, equipFinger1 = ?, equipFinger2 = ?, equipTrinket1 = ?, equipTrinket2 = ?, equipNeck = ? WHERE entry = ?", CONNECTION_ASYNC
            PreparedStatement* stmt;
            uint8 k;
            for (k = BOT_SLOT_MAINHAND; k != BOT_INVENTORY_SIZE; ++k)
            {
                itr->second->equips[k] = items[k] ? items[k]->GetGUID().GetCounter() : 0;
                if (Item const* botitem = items[k])
                {
                    bool standard = false;
                    for (uint8 i = 0; i != MAX_EQUIPMENT_ITEMS; ++i)
                    {
                        if (einfo->ItemEntry[i] == botitem->GetEntry())
                        {
                            itr->second->equips[k] = 0;
                            bstmt->setUInt32(k, 0);
                            standard = true;
                            break;
                        }
                    }
                    if (standard)
                        continue;

                    uint8 index = 0;
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_ITEM_INSTANCE);
                    //REPLACE INTO item_instance (itemEntry, owner_guid, creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, guid)
                    //VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC : 0-13
                    stmt->setUInt32(  index, botitem->GetEntry());
                    stmt->setUInt32(++index, botitem->GetOwnerGUID().GetCounter());
                    stmt->setUInt32(++index, botitem->GetGuidValue(ITEM_FIELD_CREATOR).GetCounter());
                    stmt->setUInt32(++index, botitem->GetGuidValue(ITEM_FIELD_GIFTCREATOR).GetCounter());
                    stmt->setUInt32(++index, botitem->GetCount());
                    stmt->setUInt32(++index, botitem->GetUInt32Value(ITEM_FIELD_DURATION));

                    std::ostringstream ssSpells;
                    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
                        ssSpells << botitem->GetSpellCharges(i) << ' ';
                    stmt->setString(++index, ssSpells.str());

                    stmt->setUInt32(++index, botitem->GetUInt32Value(ITEM_FIELD_FLAGS));

                    std::ostringstream ssEnchants;
                    for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
                    {
                        ssEnchants << botitem->GetEnchantmentId(EnchantmentSlot(i)) << ' ';
                        ssEnchants << botitem->GetEnchantmentDuration(EnchantmentSlot(i)) << ' ';
                        ssEnchants << botitem->GetEnchantmentCharges(EnchantmentSlot(i)) << ' ';
                    }
                    stmt->setString(++index, ssEnchants.str());

                    stmt->setInt16 (++index, botitem->GetItemRandomPropertyId());
                    stmt->setUInt16(++index, botitem->GetUInt32Value(ITEM_FIELD_DURABILITY));
                    stmt->setUInt32(++index, botitem->GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME));
                    stmt->setString(++index, botitem->GetText());
                    stmt->setUInt32(++index, botitem->GetGUID().GetCounter());

                    trans->Append(stmt);

                    Item::DeleteFromInventoryDB(trans, botitem->GetGUID().GetCounter()); //prevent duplicates

                    bstmt->setUInt32(k, botitem->GetGUID().GetCounter());
                }
                else
                    bstmt->setUInt32(k, uint32(0));
            }

            bstmt->setUInt32(k, entry);
            trans->Append(bstmt);
            CharacterDatabase.CommitTransaction(trans);
            break;
        }
        case NPCBOT_UPDATE_ERASE:
        {
            NpcBotDataMap::iterator itr = _botsData.find(entry);
            ASSERT(itr != _botsData.end());
            delete itr->second;
            _botsData.erase(itr);
            bstmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_NPCBOT);
            //"DELETE FROM characters_npcbot WHERE entry = ?", CONNECTION_ASYNC
            bstmt->setUInt32(0, entry);
            CharacterDatabase.Execute(bstmt);
            break;
        }
        default:
        {
            TC_LOG_ERROR("sql.sql", "BotDataMgr:UpdateNpcBotData: unhandled updateType %u", uint32(updateType));
            break;
        }
    }
}
void BotDataMgr::UpdateNpcBotDataAll(uint32 playerGuid, NpcBotDataUpdateType updateType, void* data)
{
    PreparedStatement* bstmt;
    switch (updateType)
    {
        case NPCBOT_UPDATE_OWNER:
            bstmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER_ALL);
            //"UPDATE characters_npcbot SET owner = ? WHERE owner = ?", CONNECTION_ASYNC
            bstmt->setUInt32(0, *(uint32*)(data));
            bstmt->setUInt32(1, playerGuid);
            CharacterDatabase.Execute(bstmt);
            break;
        //case NPCBOT_UPDATE_ROLES:
        //case NPCBOT_UPDATE_FACTION:
        //case NPCBOT_UPDATE_EQUIPS:
        default:
            break;
    }
}

NpcBotAppearanceData const* BotDataMgr::SelectNpcBotAppearance(uint32 entry)
{
    NpcBotAppearanceDataMap::const_iterator itr = _botsAppearanceData.find(entry);
    return itr != _botsAppearanceData.end() ? itr->second : nullptr;
}

NpcBotExtras const* BotDataMgr::SelectNpcBotExtras(uint32 entry)
{
    NpcBotExtrasMap::const_iterator itr = _botsExtras.find(entry);
    return itr != _botsExtras.end() ? itr->second : nullptr;
}

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

#include "CharacterDatabase.h"
#include "MySQLPreparedStatement.h"

void CharacterDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_CHARACTERDATABASE_STATEMENTS);

    PrepareStatement(CHAR_DEL_POOL_QUEST_SAVE, "DELETE FROM pool_quest_save WHERE pool_id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_POOL_QUEST_SAVE, "INSERT INTO pool_quest_save (pool_id, quest_id) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM, "DELETE FROM guild_bank_item WHERE guildid = ? AND TabId = ? AND SlotId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_EXPIRED_BANS, "UPDATE character_banned SET active = 0 WHERE unbandate <= UNIX_TIMESTAMP() AND unbandate <> bandate", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHECK_NAME, "SELECT 1 FROM characters WHERE name = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_SEL_CHECK_GUID, "SELECT 1 FROM characters WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_SUM_CHARS, "SELECT COUNT(guid) FROM characters WHERE account = ? AND deleteDate IS NULL", CONNECTION_BOTH);
    PrepareStatement(CHAR_SEL_CHAR_CREATE_INFO, "SELECT level, race, class FROM characters WHERE account = ? LIMIT 0, ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHARACTER_BAN, "INSERT INTO character_banned (guid, bandate, unbandate, bannedby, banreason, active) VALUES (?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, ?, ?, 1)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHARACTER_BAN, "UPDATE character_banned SET active = 0 WHERE guid = ? AND active != 0", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_BAN, "DELETE cb FROM character_banned cb INNER JOIN characters c ON c.guid = cb.guid WHERE c.account = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_BANINFO, "SELECT bandate, unbandate-bandate, active, unbandate, banreason, bannedby FROM character_banned WHERE guid = ? ORDER BY bandate ASC", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_GUID_BY_NAME_FILTER, "SELECT guid, name FROM characters WHERE name LIKE CONCAT('%%', ?, '%%')", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_BANINFO_LIST, "SELECT bandate, unbandate, bannedby, banreason FROM character_banned WHERE guid = ? ORDER BY unbandate", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_BANNED_NAME, "SELECT characters.name FROM characters, character_banned WHERE character_banned.guid = ? AND character_banned.guid = characters.guid", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_MAIL_LIST_COUNT, "SELECT COUNT(id) FROM mail WHERE receiver = ? ", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_MAIL_LIST_INFO, "SELECT id, sender, (SELECT name FROM characters WHERE guid = sender) AS sendername, receiver, (SELECT name FROM characters WHERE guid = receiver) AS receivername, "
                     "subject, deliver_time, expire_time, money, has_items FROM mail WHERE receiver = ? ", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_MAIL_LIST_ITEMS, "SELECT itemEntry,count FROM item_instance WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_ENUM, "SELECT c.guid, c.name, c.race, c.class, c.gender, c.skin, c.face, c.hairStyle, c.hairColor, c.facialStyle, c.level, c.zone, c.map, c.position_x, c.position_y, c.position_z, "
                     "gm.guildid, c.playerFlags, c.at_login, cp.entry, cp.modelid, cp.level, c.equipmentCache, cb.guid "
                     "FROM characters AS c LEFT JOIN character_pet AS cp ON c.guid = cp.owner AND cp.slot = ? LEFT JOIN guild_member AS gm ON c.guid = gm.guid "
                     "LEFT JOIN character_banned AS cb ON c.guid = cb.guid AND cb.active = 1 WHERE c.account = ? AND c.deleteInfos_Name IS NULL ORDER BY c.guid", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_ENUM_DECLINED_NAME, "SELECT c.guid, c.name, c.race, c.class, c.gender, c.skin, c.face, c.hairStyle, c.hairColor, c.facialStyle, c.level, c.zone, c.map, "
                     "c.position_x, c.position_y, c.position_z, gm.guildid, c.playerFlags, c.at_login, cp.entry, cp.modelid, cp.level, c.equipmentCache, "
                     "cb.guid, cd.genitive FROM characters AS c LEFT JOIN character_pet AS cp ON c.guid = cp.owner AND cp.slot = ? "
                     "LEFT JOIN character_declinedname AS cd ON c.guid = cd.guid LEFT JOIN guild_member AS gm ON c.guid = gm.guid "
                     "LEFT JOIN character_banned AS cb ON c.guid = cb.guid AND cb.active = 1 WHERE c.account = ?  AND c.deleteInfos_Name IS NULL ORDER BY c.guid", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_FREE_NAME, "SELECT name, at_login FROM characters WHERE guid = ? AND NOT EXISTS (SELECT NULL FROM characters WHERE name = ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHAR_ZONE, "SELECT zone FROM characters WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHARACTER_NAME_DATA, "SELECT race, class, gender, level, name FROM characters WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_POSITION_XYZ, "SELECT map, position_x, position_y, position_z FROM characters WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_POSITION, "SELECT position_x, position_y, position_z, orientation, map, taxi_path FROM characters WHERE guid = ?", CONNECTION_SYNCH);

    PrepareStatement(CHAR_DEL_BATTLEGROUND_RANDOM_ALL, "DELETE FROM character_battleground_random", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_BATTLEGROUND_RANDOM, "DELETE FROM character_battleground_random WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_BATTLEGROUND_RANDOM, "INSERT INTO character_battleground_random (guid) VALUES (?)", CONNECTION_ASYNC);

    PrepareStatement(CHAR_SEL_CHARACTER, "SELECT c.guid, account, name, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, restState, playerFlags, "
                     "position_x, position_y, position_z, map, orientation, taximask, cinematic, totaltime, leveltime, rest_bonus, logout_time, is_logout_resting, resettalents_cost, "
                     "resettalents_time, trans_x, trans_y, trans_z, trans_o, transguid, extra_flags, stable_slots, at_login, zone, online, death_expire_time, taxi_path, instance_mode_mask, "
                     "arenaPoints, totalHonorPoints, todayHonorPoints, yesterdayHonorPoints, totalKills, todayKills, yesterdayKills, chosenTitle, knownCurrencies, watchedFaction, drunk, "
                     "health, power1, power2, power3, power4, power5, power6, power7, instance_id, talentGroupsCount, activeTalentGroup, exploredZones, equipmentCache, ammoId, knownTitles, actionBars, grantableLevels, fishingSteps "
                     "FROM characters c LEFT JOIN character_fishingsteps cfs ON c.guid = cfs.guid WHERE c.guid = ?", CONNECTION_ASYNC);

    PrepareStatement(CHAR_SEL_GROUP_MEMBER, "SELECT guid FROM group_member WHERE memberGuid = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_SEL_CHARACTER_INSTANCE, "SELECT id, permanent, map, difficulty, extendState, resettime FROM character_instance LEFT JOIN instance ON instance = id WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_AURAS, "SELECT casterGuid, itemGuid, spell, effectMask, recalculateMask, stackCount, amount0, amount1, amount2, "
                     "base_amount0, base_amount1, base_amount2, maxDuration, remainTime, remainCharges, critChance, applyResilience FROM character_aura WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_SPELL, "SELECT spell, active, disabled FROM character_spell WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_QUESTSTATUS, "SELECT quest, status, explored, timer, mobcount1, mobcount2, mobcount3, mobcount4, "
                     "itemcount1, itemcount2, itemcount3, itemcount4, itemcount5, itemcount6, playercount FROM character_queststatus WHERE guid = ? AND status <> 0", CONNECTION_ASYNC);

    PrepareStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_DAILY, "SELECT quest, time FROM character_queststatus_daily WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_WEEKLY, "SELECT quest FROM character_queststatus_weekly WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_MONTHLY, "SELECT quest FROM character_queststatus_monthly WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_QUESTSTATUS_SEASONAL, "SELECT quest, event, completedTime FROM character_queststatus_seasonal WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_DAILY, "DELETE FROM character_queststatus_daily WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_WEEKLY, "DELETE FROM character_queststatus_weekly WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_MONTHLY, "DELETE FROM character_queststatus_monthly WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_QUESTSTATUS_SEASONAL, "DELETE FROM character_queststatus_seasonal WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHARACTER_QUESTSTATUS_DAILY, "INSERT INTO character_queststatus_daily (guid, quest, time) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHARACTER_QUESTSTATUS_WEEKLY, "INSERT INTO character_queststatus_weekly (guid, quest) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHARACTER_QUESTSTATUS_MONTHLY, "INSERT INTO character_queststatus_monthly (guid, quest) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHARACTER_QUESTSTATUS_SEASONAL, "INSERT INTO character_queststatus_seasonal (guid, quest, event, completedTime) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_DAILY, "DELETE FROM character_queststatus_daily", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_WEEKLY, "DELETE FROM character_queststatus_weekly", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_MONTHLY, "DELETE FROM character_queststatus_monthly", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_SEASONAL_BY_EVENT, "DELETE FROM character_queststatus_seasonal WHERE event = ? AND completedTime < ?", CONNECTION_ASYNC);

    PrepareStatement(CHAR_SEL_CHARACTER_REPUTATION, "SELECT faction, standing, flags FROM character_reputation WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_INVENTORY, "SELECT creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, bag, slot, "
                     "item, itemEntry FROM character_inventory ci JOIN item_instance ii ON ci.item = ii.guid WHERE ci.guid = ? ORDER BY bag, slot", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_ACTIONS, "SELECT a.button, a.action, a.type FROM character_action as a, characters as c WHERE a.guid = c.guid AND a.spec = c.activeTalentGroup AND a.guid = ? ORDER BY button", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_MAIL_COUNT, "SELECT COUNT(*) FROM mail WHERE receiver = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_SOCIALLIST, "SELECT friend, flags, note FROM character_social JOIN characters ON characters.guid = character_social.friend WHERE character_social.guid = ? AND deleteinfos_name IS NULL LIMIT 255", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_HOMEBIND, "SELECT mapId, zoneId, posX, posY, posZ FROM character_homebind WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_SPELLCOOLDOWNS, "SELECT spell, item, time, categoryId, categoryEnd FROM character_spell_cooldown WHERE guid = ? AND time > UNIX_TIMESTAMP()", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_DECLINEDNAMES, "SELECT genitive, dative, accusative, instrumental, prepositional FROM character_declinedname WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_GUILD_MEMBER, "SELECT guildid, `rank` FROM guild_member WHERE guid = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_SEL_GUILD_MEMBER_EXTENDED, "SELECT g.guildid, g.name, gr.rname, gr.rid, gm.pnote, gm.offnote "
                     "FROM guild g JOIN guild_member gm ON g.guildid = gm.guildid "
                     "JOIN guild_rank gr ON g.guildid = gr.guildid AND gm.`rank` = gr.rid WHERE gm.guid = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_SEL_CHARACTER_ACHIEVEMENTS, "SELECT achievement, date FROM character_achievement WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_CRITERIAPROGRESS, "SELECT criteria, counter, date FROM character_achievement_progress WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_EQUIPMENTSETS, "SELECT setguid, setindex, name, iconname, ignore_mask, item0, item1, item2, item3, item4, item5, item6, item7, item8, "
                     "item9, item10, item11, item12, item13, item14, item15, item16, item17, item18 FROM character_equipmentsets WHERE guid = ? ORDER BY setindex", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_BGDATA, "SELECT instanceId, team, joinX, joinY, joinZ, joinO, joinMapId, taxiStart, taxiEnd, mountSpell FROM character_battleground_data WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_GLYPHS, "SELECT talentGroup, glyph1, glyph2, glyph3, glyph4, glyph5, glyph6 FROM character_glyphs WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_TALENTS, "SELECT spell, talentGroup FROM character_talent WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_SKILLS, "SELECT skill, value, max FROM character_skills WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_RANDOMBG, "SELECT guid FROM character_battleground_random WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_BANNED, "SELECT guid FROM character_banned WHERE guid = ? AND active = 1", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_QUESTSTATUSREW, "SELECT quest FROM character_queststatus_rewarded WHERE guid = ? AND active = 1", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_ACCOUNT_INSTANCELOCKTIMES, "SELECT instanceId, releaseTime FROM account_instance_times WHERE accountId = ?", CONNECTION_ASYNC);

    PrepareStatement(CHAR_SEL_CHARACTER_ACTIONS_SPEC, "SELECT button, action, type FROM character_action WHERE guid = ? AND spec = ? ORDER BY button", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_MAILITEMS, "SELECT creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, item_guid, itemEntry, ii.owner_guid, m.id FROM mail_items mi INNER JOIN mail m ON mi.mail_id = m.id LEFT JOIN item_instance ii ON mi.item_guid = ii.guid WHERE m.receiver = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_SEL_AUCTION_ITEMS, "SELECT creatorGuid, giftCreatorGuid, count, duration, charges, ii.flags, enchantments, randomPropertyId, durability, playedTime, text, itemguid, itemEntry FROM auctionhouse ah JOIN item_instance ii ON ah.itemguid = ii.guid", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_AUCTIONS, "SELECT id, houseid, itemguid, itemEntry, count, itemowner, buyoutprice, time, buyguid, lastbid, startbid, deposit, ah.Flags FROM auctionhouse ah INNER JOIN item_instance ii ON ii.guid = ah.itemguid", CONNECTION_SYNCH);
    PrepareStatement(CHAR_INS_AUCTION, "INSERT INTO auctionhouse (id, houseid, itemguid, itemowner, buyoutprice, time, buyguid, lastbid, startbid, deposit, Flags) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_AUCTION, "DELETE FROM auctionhouse WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_AUCTION_BIDDERS, "SELECT id, bidderguid FROM auctionbidders", CONNECTION_SYNCH);
    PrepareStatement(CHAR_INS_AUCTION_BIDDERS, "INSERT IGNORE INTO auctionbidders (id, bidderguid) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_AUCTION_BIDDERS, "DELETE FROM auctionbidders WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_AUCTION_BID, "UPDATE auctionhouse SET buyguid = ?, lastbid = ?, Flags = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_MAIL, "INSERT INTO mail(id, messageType, stationery, mailTemplateId, sender, receiver, subject, body, has_items, expire_time, deliver_time, money, cod, checked) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_MAIL_BY_ID, "DELETE FROM mail WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_MAIL_ITEM, "INSERT INTO mail_items(mail_id, item_guid, receiver) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_MAIL_ITEM, "DELETE FROM mail_items WHERE item_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_INVALID_MAIL_ITEM, "DELETE FROM mail_items WHERE item_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_EMPTY_EXPIRED_MAIL, "DELETE FROM mail WHERE expire_time < ? AND has_items = 0 AND body = ''", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_EXPIRED_MAIL, "SELECT id, messageType, sender, receiver, has_items, expire_time, cod, checked, mailTemplateId FROM mail WHERE expire_time < ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_EXPIRED_MAIL_ITEMS, "SELECT item_guid, itemEntry, mail_id FROM mail_items mi INNER JOIN item_instance ii ON ii.guid = mi.item_guid LEFT JOIN mail mm ON mi.mail_id = mm.id WHERE mm.id IS NOT NULL AND mm.expire_time < ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_UPD_MAIL_RETURNED, "UPDATE mail SET sender = ?, receiver = ?, expire_time = ?, deliver_time = ?, cod = 0, checked = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_MAIL_ITEM_RECEIVER, "UPDATE mail_items SET receiver = ? WHERE item_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ITEM_OWNER, "UPDATE item_instance SET owner_guid = ? WHERE guid = ?", CONNECTION_ASYNC);

    PrepareStatement(CHAR_SEL_ITEM_REFUNDS, "SELECT paidMoney, paidExtendedCost FROM item_refund_instance WHERE item_guid = ? AND player_guid = ? LIMIT 1", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_ITEM_BOP_TRADE, "SELECT allowedPlayers FROM item_soulbound_trade_data WHERE itemGuid = ? LIMIT 1", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_ITEM_BOP_TRADE, "DELETE FROM item_soulbound_trade_data WHERE itemGuid = ? LIMIT 1", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ITEM_BOP_TRADE, "INSERT INTO item_soulbound_trade_data VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_INVENTORY_ITEM, "REPLACE INTO character_inventory (guid, bag, slot, item) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_ITEM_INSTANCE, "REPLACE INTO item_instance (itemEntry, owner_guid, creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, guid) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ITEM_INSTANCE, "UPDATE item_instance SET itemEntry = ?, owner_guid = ?, creatorGuid = ?, giftCreatorGuid = ?, count = ?, duration = ?, charges = ?, flags = ?, enchantments = ?, randomPropertyId = ?, durability = ?, playedTime = ?, text = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ITEM_INSTANCE_ON_LOAD, "UPDATE item_instance SET duration = ?, flags = ?, durability = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ITEM_INSTANCE, "DELETE FROM item_instance WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ITEM_INSTANCE_BY_OWNER, "DELETE FROM item_instance WHERE owner_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GIFT_OWNER, "UPDATE character_gifts SET guid = ? WHERE item_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GIFT, "DELETE FROM character_gifts WHERE item_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_GIFT_BY_ITEM, "SELECT entry, flags FROM character_gifts WHERE item_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_ACCOUNT_BY_NAME, "SELECT account FROM characters WHERE name = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_UPD_ACCOUNT_BY_GUID, "UPDATE characters SET account = ? WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_ACCOUNT_INSTANCE_LOCK_TIMES, "DELETE FROM account_instance_times WHERE accountId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ACCOUNT_INSTANCE_LOCK_TIMES, "INSERT INTO account_instance_times (accountId, instanceId, releaseTime) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_MATCH_MAKER_RATING, "SELECT matchMakerRating FROM character_arena_stats WHERE guid = ? AND slot = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHARACTER_COUNT, "SELECT account, COUNT(guid) FROM characters WHERE account = ? GROUP BY account", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_NAME_BY_GUID, "UPDATE characters SET name = ? WHERE guid = ?", CONNECTION_ASYNC);

    // Guild handling
    // 0: uint32, 1: string, 2: uint32, 3: string, 4: string, 5: uint64, 6-10: uint32, 11: uint64
    PrepareStatement(CHAR_INS_GUILD, "INSERT INTO guild (guildid, name, leaderguid, info, motd, createdate, EmblemStyle, EmblemColor, BorderStyle, BorderColor, BackgroundColor, BankMoney) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD, "DELETE FROM guild WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    // 0: string, 1: uint32
    PrepareStatement(CHAR_UPD_GUILD_NAME, "UPDATE guild SET name = ? WHERE guildid = ?", CONNECTION_ASYNC);
    // 0: uint32, 1: uint32, 2: uint8, 4: string, 5: string
    PrepareStatement(CHAR_INS_GUILD_MEMBER, "INSERT INTO guild_member (guildid, guid, `rank`, pnote, offnote) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_MEMBER, "DELETE FROM guild_member WHERE guid = ?", CONNECTION_ASYNC); // 0: uint32
    PrepareStatement(CHAR_DEL_GUILD_MEMBERS, "DELETE FROM guild_member WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    // 0: uint32, 1: uint8, 3: string, 4: uint32, 5: uint32
    PrepareStatement(CHAR_INS_GUILD_RANK, "INSERT INTO guild_rank (guildid, rid, rname, rights, BankMoneyPerDay) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_RANKS, "DELETE FROM guild_rank WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    PrepareStatement(CHAR_DEL_GUILD_RANK, "DELETE FROM guild_rank WHERE guildid = ? AND rid = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint8
    PrepareStatement(CHAR_INS_GUILD_BANK_TAB, "INSERT INTO guild_bank_tab (guildid, TabId) VALUES (?, ?)", CONNECTION_ASYNC); // 0: uint32, 1: uint8
    PrepareStatement(CHAR_DEL_GUILD_BANK_TAB, "DELETE FROM guild_bank_tab WHERE guildid = ? AND TabId = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint8
    PrepareStatement(CHAR_DEL_GUILD_BANK_TABS, "DELETE FROM guild_bank_tab WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    // 0: uint32, 1: uint8, 2: uint8, 3: uint32, 4: uint32
    PrepareStatement(CHAR_INS_GUILD_BANK_ITEM, "INSERT INTO guild_bank_item (guildid, TabId, SlotId, item_guid) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_BANK_ITEM, "DELETE FROM guild_bank_item WHERE guildid = ? AND TabId = ? AND SlotId = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint8, 2: uint8
    PrepareStatement(CHAR_DEL_GUILD_BANK_ITEMS, "DELETE FROM guild_bank_item WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    // 0: uint32, 1: uint8, 2: uint8, 3: uint8, 4: uint32
    PrepareStatement(CHAR_INS_GUILD_BANK_RIGHT, "INSERT INTO guild_bank_right (guildid, TabId, rid, gbright, SlotPerDay) VALUES (?, ?, ?, ?, ?) "
                     "ON DUPLICATE KEY UPDATE gbright = VALUES(gbright), SlotPerDay = VALUES(SlotPerDay)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_BANK_RIGHTS, "DELETE FROM guild_bank_right WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    PrepareStatement(CHAR_DEL_GUILD_BANK_RIGHTS_FOR_RANK, "DELETE FROM guild_bank_right WHERE guildid = ? AND rid = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint8
    // 0-1: uint32, 2-3: uint8, 4-5: uint32, 6: uint16, 7: uint8, 8: uint64
    PrepareStatement(CHAR_INS_GUILD_BANK_EVENTLOG, "INSERT INTO guild_bank_eventlog (guildid, LogGuid, TabId, EventType, PlayerGuid, ItemOrMoney, ItemStackCount, DestTabId, TimeStamp) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_BANK_EVENTLOG, "DELETE FROM guild_bank_eventlog WHERE guildid = ? AND LogGuid = ? AND TabId = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint32, 2: uint8
    PrepareStatement(CHAR_DEL_GUILD_BANK_EVENTLOGS, "DELETE FROM guild_bank_eventlog WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    // 0-1: uint32, 2: uint8, 3-4: uint32, 5: uint8, 6: uint64
    PrepareStatement(CHAR_INS_GUILD_EVENTLOG, "INSERT INTO guild_eventlog (guildid, LogGuid, EventType, PlayerGuid1, PlayerGuid2, NewRank, TimeStamp) VALUES (?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_EVENTLOG, "DELETE FROM guild_eventlog WHERE guildid = ? AND LogGuid = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint32
    PrepareStatement(CHAR_DEL_GUILD_EVENTLOGS, "DELETE FROM guild_eventlog WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32
    PrepareStatement(CHAR_UPD_GUILD_MEMBER_PNOTE, "UPDATE guild_member SET pnote = ? WHERE guid = ?", CONNECTION_ASYNC); // 0: string, 1: uint32
    PrepareStatement(CHAR_UPD_GUILD_MEMBER_OFFNOTE, "UPDATE guild_member SET offnote = ? WHERE guid = ?", CONNECTION_ASYNC); // 0: string, 1: uint32
    PrepareStatement(CHAR_UPD_GUILD_MEMBER_RANK, "UPDATE guild_member SET `rank` = ? WHERE guid = ?", CONNECTION_ASYNC); // 0: uint8, 1: uint32
    PrepareStatement(CHAR_UPD_GUILD_MOTD, "UPDATE guild SET motd = ? WHERE guildid = ?", CONNECTION_ASYNC); // 0: string, 1: uint32
    PrepareStatement(CHAR_UPD_GUILD_INFO, "UPDATE guild SET info = ? WHERE guildid = ?", CONNECTION_ASYNC); // 0: string, 1: uint32
    PrepareStatement(CHAR_UPD_GUILD_LEADER, "UPDATE guild SET leaderguid = ? WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint32
    PrepareStatement(CHAR_UPD_GUILD_RANK_NAME, "UPDATE guild_rank SET rname = ? WHERE rid = ? AND guildid = ?", CONNECTION_ASYNC); // 0: string, 1: uint8, 2: uint32
    PrepareStatement(CHAR_UPD_GUILD_RANK_RIGHTS, "UPDATE guild_rank SET rights = ? WHERE rid = ? AND guildid = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint8, 2: uint32
    // 0-5: uint32
    PrepareStatement(CHAR_UPD_GUILD_EMBLEM_INFO, "UPDATE guild SET EmblemStyle = ?, EmblemColor = ?, BorderStyle = ?, BorderColor = ?, BackgroundColor = ? WHERE guildid = ?", CONNECTION_ASYNC);
    // 0: string, 1: string, 2: uint32, 3: uint8
    PrepareStatement(CHAR_UPD_GUILD_BANK_TAB_INFO, "UPDATE guild_bank_tab SET TabName = ?, TabIcon = ? WHERE guildid = ? AND TabId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GUILD_BANK_MONEY, "UPDATE guild SET BankMoney = ? WHERE guildid = ?", CONNECTION_ASYNC); // 0: uint64, 1: uint32
    // 0: uint8, 1: uint32, 2: uint8, 3: uint32
    PrepareStatement(CHAR_UPD_GUILD_RANK_BANK_MONEY, "UPDATE guild_rank SET BankMoneyPerDay = ? WHERE rid = ? AND guildid = ?", CONNECTION_ASYNC); // 0: uint32, 1: uint8, 2: uint32
    PrepareStatement(CHAR_UPD_GUILD_BANK_TAB_TEXT, "UPDATE guild_bank_tab SET TabText = ? WHERE guildid = ? AND TabId = ?", CONNECTION_ASYNC); // 0: string, 1: uint32, 2: uint8

    PrepareStatement(CHAR_INS_GUILD_MEMBER_WITHDRAW,
                     "INSERT INTO guild_member_withdraw (guid, tab0, tab1, tab2, tab3, tab4, tab5, money) VALUES (?, ?, ?, ?, ?, ?, ?, ?) "
                     "ON DUPLICATE KEY UPDATE tab0 = VALUES (tab0), tab1 = VALUES (tab1), tab2 = VALUES (tab2), tab3 = VALUES (tab3), tab4 = VALUES (tab4), tab5 = VALUES (tab5), money = VALUES (money)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_MEMBER_WITHDRAW, "TRUNCATE guild_member_withdraw", CONNECTION_ASYNC);

    // 0: uint32, 1: uint32, 2: uint32
    PrepareStatement(CHAR_SEL_CHAR_DATA_FOR_GUILD, "SELECT name, level, class, gender, zone, account FROM characters WHERE guid = ?", CONNECTION_SYNCH);

    // Chat channel handling
    PrepareStatement(CHAR_UPD_CHANNEL, "INSERT INTO channels (name, team, announce, ownership, password, bannedList, lastUsed) VALUES (?, ?, ?, ?, ?, ?, UNIX_TIMESTAMP()) "
                                       "ON DUPLICATE KEY UPDATE announce=VALUES(announce), ownership=VALUES(ownership), password=VALUES(password), bannedList=VALUES(bannedList), lastUsed=VALUES(lastUsed)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHANNEL_USAGE, "UPDATE channels SET lastUsed = UNIX_TIMESTAMP() WHERE name = ? AND team = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHANNEL_OWNERSHIP, "UPDATE channels SET ownership = ? WHERE name LIKE ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHANNEL, "DELETE FROM channels WHERE name = ? AND team = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_OLD_CHANNELS, "DELETE FROM channels WHERE ownership = 1 AND lastUsed + ? < UNIX_TIMESTAMP()", CONNECTION_ASYNC);

    // Equipmentsets
    PrepareStatement(CHAR_UPD_EQUIP_SET, "UPDATE character_equipmentsets SET name=?, iconname=?, ignore_mask=?, item0=?, item1=?, item2=?, item3=?, "
                     "item4=?, item5=?, item6=?, item7=?, item8=?, item9=?, item10=?, item11=?, item12=?, item13=?, item14=?, item15=?, item16=?, "
                     "item17=?, item18=? WHERE guid=? AND setguid=? AND setindex=?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_EQUIP_SET, "INSERT INTO character_equipmentsets (guid, setguid, setindex, name, iconname, ignore_mask, item0, item1, item2, item3, "
                     "item4, item5, item6, item7, item8, item9, item10, item11, item12, item13, item14, item15, item16, item17, item18) "
                     "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_EQUIP_SET, "DELETE FROM character_equipmentsets WHERE setguid=?", CONNECTION_ASYNC);

    // Auras
    PrepareStatement(CHAR_INS_AURA, "INSERT INTO character_aura (guid, casterGuid, itemGuid, spell, effectMask, recalculateMask, stackCount, amount0, amount1, amount2, base_amount0, base_amount1, base_amount2, maxDuration, remainTime, remainCharges, critChance, applyResilience) "
                     "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);

    // Account data
    PrepareStatement(CHAR_SEL_ACCOUNT_DATA, "SELECT type, time, data FROM account_data WHERE accountId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_ACCOUNT_DATA, "REPLACE INTO account_data (accountId, type, time, data) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ACCOUNT_DATA, "DELETE FROM account_data WHERE accountId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_PLAYER_ACCOUNT_DATA, "SELECT type, time, data FROM character_account_data WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_PLAYER_ACCOUNT_DATA, "REPLACE INTO character_account_data(guid, type, time, data) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PLAYER_ACCOUNT_DATA, "DELETE FROM character_account_data WHERE guid = ?", CONNECTION_ASYNC);

    // Tutorials
    PrepareStatement(CHAR_SEL_TUTORIALS, "SELECT tut0, tut1, tut2, tut3, tut4, tut5, tut6, tut7 FROM account_tutorial WHERE accountId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_TUTORIALS, "INSERT INTO account_tutorial(tut0, tut1, tut2, tut3, tut4, tut5, tut6, tut7, accountId) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_TUTORIALS, "UPDATE account_tutorial SET tut0 = ?, tut1 = ?, tut2 = ?, tut3 = ?, tut4 = ?, tut5 = ?, tut6 = ?, tut7 = ? WHERE accountId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_TUTORIALS, "DELETE FROM account_tutorial WHERE accountId = ?", CONNECTION_ASYNC);

    // Instance saves
    PrepareStatement(CHAR_INS_INSTANCE_SAVE, "INSERT INTO instance (id, map, resettime, difficulty, completedEncounters, data) VALUES (?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_INSTANCE_DATA, "UPDATE instance SET completedEncounters=?, data=? WHERE id=?", CONNECTION_ASYNC);

    // Game event saves
    PrepareStatement(CHAR_DEL_GAME_EVENT_SAVE, "DELETE FROM game_event_save WHERE eventEntry = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_GAME_EVENT_SAVE, "INSERT INTO game_event_save (eventEntry, state, next_start) VALUES (?, ?, ?)", CONNECTION_ASYNC);

    // Game event condition saves
    PrepareStatement(CHAR_DEL_ALL_GAME_EVENT_CONDITION_SAVE, "DELETE FROM game_event_condition_save WHERE eventEntry = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GAME_EVENT_CONDITION_SAVE, "DELETE FROM game_event_condition_save WHERE eventEntry = ? AND condition_id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_GAME_EVENT_CONDITION_SAVE, "INSERT INTO game_event_condition_save (eventEntry, condition_id, done) VALUES (?, ?, ?)", CONNECTION_ASYNC);

    // Petitions
    PrepareStatement(CHAR_SEL_PETITION, "SELECT ownerguid, name, type FROM petition WHERE petitionguid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PETITION_SIGNATURE, "SELECT playerguid FROM petition_sign WHERE petitionguid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_ALL_PETITION_SIGNATURES, "DELETE FROM petition_sign WHERE playerguid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PETITION_SIGNATURE, "DELETE FROM petition_sign WHERE playerguid = ? AND type = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_PETITION_BY_OWNER, "SELECT petitionguid FROM petition WHERE ownerguid = ? AND type = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PETITION_TYPE, "SELECT type FROM petition WHERE petitionguid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PETITION_SIGNATURES, "SELECT ownerguid, (SELECT COUNT(playerguid) FROM petition_sign WHERE petition_sign.petitionguid = ?) AS signs, type FROM petition WHERE petitionguid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PETITION_SIG_BY_ACCOUNT, "SELECT playerguid FROM petition_sign WHERE player_account = ? AND petitionguid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PETITION_OWNER_BY_GUID, "SELECT ownerguid FROM petition WHERE petitionguid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PETITION_SIG_BY_GUID, "SELECT ownerguid, petitionguid FROM petition_sign WHERE playerguid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PETITION_SIG_BY_GUID_TYPE, "SELECT ownerguid, petitionguid FROM petition_sign WHERE playerguid = ? AND type = ?", CONNECTION_SYNCH);

    // Arena teams
    PrepareStatement(CHAR_SEL_CHARACTER_ARENAINFO, "SELECT arenaTeamId, weekGames, seasonGames, seasonWins, personalRating FROM arena_team_member WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ARENA_TEAM, "INSERT INTO arena_team (arenaTeamId, name, captainGuid, type, rating, backgroundColor, emblemStyle, emblemColor, borderStyle, borderColor) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ARENA_TEAM_MEMBER, "INSERT INTO arena_team_member (arenaTeamId, guid, personalRating) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ARENA_TEAM, "DELETE FROM arena_team where arenaTeamId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ARENA_TEAM_MEMBERS, "DELETE FROM arena_team_member WHERE arenaTeamId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ARENA_TEAM_CAPTAIN, "UPDATE arena_team SET captainGuid = ? WHERE arenaTeamId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ARENA_TEAM_MEMBER, "DELETE FROM arena_team_member WHERE arenaTeamId = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ARENA_TEAM_STATS, "UPDATE arena_team SET rating = ?, weekGames = ?, weekWins = ?, seasonGames = ?, seasonWins = ?, `rank` = ? WHERE arenaTeamId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ARENA_TEAM_MEMBER, "UPDATE arena_team_member SET personalRating = ?, weekGames = ?, weekWins = ?, seasonGames = ?, seasonWins = ? WHERE arenaTeamId = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_ARENA_STATS, "DELETE FROM character_arena_stats WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_CHARACTER_ARENA_STATS, "REPLACE INTO character_arena_stats (guid, slot, matchMakerRating) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ARENA_TEAM_NAME, "UPDATE arena_team SET name = ? WHERE arenaTeamId = ?", CONNECTION_ASYNC);

    // Character battleground data
    PrepareStatement(CHAR_INS_PLAYER_BGDATA, "INSERT INTO character_battleground_data (guid, instanceId, team, joinX, joinY, joinZ, joinO, joinMapId, taxiStart, taxiEnd, mountSpell) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PLAYER_BGDATA, "DELETE FROM character_battleground_data WHERE guid = ?", CONNECTION_ASYNC);

    // Character homebind
    PrepareStatement(CHAR_INS_PLAYER_HOMEBIND, "INSERT INTO character_homebind (guid, mapId, zoneId, posX, posY, posZ) VALUES (?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_PLAYER_HOMEBIND, "UPDATE character_homebind SET mapId = ?, zoneId = ?, posX = ?, posY = ?, posZ = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PLAYER_HOMEBIND, "DELETE FROM character_homebind WHERE guid = ?", CONNECTION_ASYNC);

    // Corpse
    PrepareStatement(CHAR_SEL_CORPSES, "SELECT posX, posY, posZ, orientation, mapId, displayId, itemCache, bytes1, bytes2, guildId, flags, dynFlags, time, corpseType, instanceId, phaseMask, guid FROM corpse WHERE mapId = ? AND instanceId = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_INS_CORPSE, "INSERT INTO corpse (guid, posX, posY, posZ, orientation, mapId, displayId, itemCache, bytes1, bytes2, guildId, flags, dynFlags, time, corpseType, instanceId, phaseMask) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CORPSE, "DELETE FROM corpse WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CORPSES_FROM_MAP, "DELETE FROM corpse WHERE mapId = ? AND instanceId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CORPSE_LOCATION, "SELECT mapId, posX, posY, posZ, orientation FROM corpse WHERE guid = ?", CONNECTION_ASYNC);

    // Respawns
    PrepareStatement(CHAR_SEL_RESPAWNS, "SELECT type, spawnId, respawnTime FROM respawn WHERE mapId = ? AND instanceId = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_REP_RESPAWN, "REPLACE INTO respawn (type, spawnId, respawnTime, mapId, instanceId) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_RESPAWN, "DELETE FROM respawn WHERE type = ? AND spawnId = ? AND mapId = ? AND instanceId = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ALL_RESPAWNS, "DELETE FROM respawn WHERE mapId = ? AND instanceId = ?", CONNECTION_ASYNC);

    // GM Tickets
    PrepareStatement(CHAR_SEL_GM_TICKETS, "SELECT id, type, playerGuid, name, description, createTime, mapId, posX, posY, posZ, lastModifiedTime, closedBy, assignedTo, comment, response, completed, escalated, viewed, needMoreHelp FROM gm_ticket", CONNECTION_SYNCH);
    PrepareStatement(CHAR_REP_GM_TICKET, "REPLACE INTO gm_ticket (id, type, playerGuid, name, description, createTime, mapId, posX, posY, posZ, lastModifiedTime, closedBy, assignedTo, comment, response, completed, escalated, viewed, needMoreHelp, resolvedBy) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GM_TICKET, "DELETE FROM gm_ticket WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PLAYER_GM_TICKETS, "DELETE FROM gm_ticket WHERE playerGuid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_PLAYER_GM_TICKETS_ON_CHAR_DELETION, "UPDATE gm_ticket SET type = 2 WHERE playerGuid = ?", CONNECTION_ASYNC);

    // GM Survey/subsurvey/lag report
    PrepareStatement(CHAR_INS_GM_SURVEY, "INSERT INTO gm_survey (guid, surveyId, mainSurvey, comment, createTime) VALUES (?, ?, ?, ?, UNIX_TIMESTAMP(NOW()))", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_GM_SUBSURVEY, "INSERT INTO gm_subsurvey (surveyId, questionId, answer, answerComment) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_LAG_REPORT, "INSERT INTO lag_reports (guid, lagType, mapId, posX, posY, posZ, latency, createTime) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);

    // LFG Data
    PrepareStatement(CHAR_INS_LFG_DATA, "INSERT INTO lfg_data (guid, dungeon, state) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_LFG_DATA, "DELETE FROM lfg_data WHERE guid = ?", CONNECTION_ASYNC);

    // Player saving
    PrepareStatement(CHAR_INS_CHARACTER, "INSERT INTO characters (guid, account, name, race, class, gender, level, xp, money, skin, face, hairStyle, hairColor, facialStyle, bankSlots, restState, playerFlags, "
                     "map, instance_id, instance_mode_mask, position_x, position_y, position_z, orientation, trans_x, trans_y, trans_z, trans_o, transguid, "
                     "taximask, cinematic, "
                     "totaltime, leveltime, rest_bonus, logout_time, is_logout_resting, resettalents_cost, resettalents_time, "
                     "extra_flags, stable_slots, at_login, zone, "
                     "death_expire_time, taxi_path, arenaPoints, totalHonorPoints, todayHonorPoints, yesterdayHonorPoints, totalKills, "
                     "todayKills, yesterdayKills, chosenTitle, knownCurrencies, watchedFaction, drunk, health, power1, power2, power3, "
                     "power4, power5, power6, power7, latency, talentGroupsCount, activeTalentGroup, exploredZones, equipmentCache, ammoId, knownTitles, actionBars, grantableLevels) VALUES "
                     "(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHARACTER, "UPDATE characters SET name=?,race=?,class=?,gender=?,level=?,xp=?,money=?,skin=?,face=?,hairStyle=?,hairColor=?,facialStyle=?,bankSlots=?,restState=?,playerFlags=?,"
                     "map=?,instance_id=?,instance_mode_mask=?,position_x=?,position_y=?,position_z=?,orientation=?,trans_x=?,trans_y=?,trans_z=?,trans_o=?,transguid=?,taximask=?,cinematic=?,totaltime=?,leveltime=?,rest_bonus=?,"
                     "logout_time=?,is_logout_resting=?,resettalents_cost=?,resettalents_time=?,extra_flags=?,stable_slots=?,at_login=?,zone=?,death_expire_time=?,taxi_path=?,"
                     "arenaPoints=?,totalHonorPoints=?,todayHonorPoints=?,yesterdayHonorPoints=?,totalKills=?,todayKills=?,yesterdayKills=?,chosenTitle=?,knownCurrencies=?,"
                     "watchedFaction=?,drunk=?,health=?,power1=?,power2=?,power3=?,power4=?,power5=?,power6=?,power7=?,latency=?,talentGroupsCount=?,activeTalentGroup=?,exploredZones=?,"
                     "equipmentCache=?,ammoId=?,knownTitles=?,actionBars=?,grantableLevels=?,online=? WHERE guid=?", CONNECTION_ASYNC);

    PrepareStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG, "UPDATE characters SET at_login = at_login | ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_REM_AT_LOGIN_FLAG, "UPDATE characters set at_login = at_login & ~ ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ALL_AT_LOGIN_FLAGS, "UPDATE characters SET at_login = at_login | ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_BUG_REPORT, "INSERT INTO bugreport (type, content) VALUES(?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_PETITION_NAME, "UPDATE petition SET name = ? WHERE petitionguid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_PETITION_SIGNATURE, "INSERT INTO petition_sign (ownerguid, petitionguid, playerguid, player_account) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ACCOUNT_ONLINE, "UPDATE characters SET online = 0 WHERE account = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_GROUP, "INSERT INTO `groups` (guid, leaderGuid, lootMethod, looterGuid, lootThreshold, icon1, icon2, icon3, icon4, icon5, icon6, icon7, icon8, groupType, difficulty, raidDifficulty, masterLooterGuid) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_GROUP_MEMBER, "INSERT INTO group_member (guid, memberGuid, memberFlags, subgroup, roles) VALUES(?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GROUP_MEMBER, "DELETE FROM group_member WHERE memberGuid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GROUP_INSTANCE_PERM_BINDING, "DELETE FROM group_instance WHERE guid = ? AND instance = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GROUP_LEADER, "UPDATE `groups` SET leaderGuid = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GROUP_TYPE, "UPDATE `groups` SET groupType = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GROUP_MEMBER_SUBGROUP, "UPDATE group_member SET subgroup = ? WHERE memberGuid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GROUP_MEMBER_FLAG, "UPDATE group_member SET memberFlags = ? WHERE memberGuid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GROUP_DIFFICULTY, "UPDATE `groups` SET difficulty = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GROUP_RAID_DIFFICULTY, "UPDATE `groups` SET raiddifficulty = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ALL_GM_TICKETS, "TRUNCATE TABLE gm_ticket", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_INVALID_SPELL_TALENTS, "DELETE FROM character_talent WHERE spell = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_INVALID_SPELL_SPELLS, "DELETE FROM character_spell WHERE spell = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_DELETE_INFO, "UPDATE characters SET deleteInfos_Name = name, deleteInfos_Account = account, deleteDate = UNIX_TIMESTAMP(), name = NULL, account = 0 WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_RESTORE_DELETE_INFO, "UPDATE characters SET name = ?, account = ?, deleteDate = NULL, deleteInfos_Name = NULL, deleteInfos_Account = NULL WHERE deleteDate IS NOT NULL AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ZONE, "UPDATE characters SET zone = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_LEVEL, "UPDATE characters SET level = ?, xp = 0 WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA, "DELETE FROM character_achievement_progress WHERE criteria = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_INVALID_ACHIEVMENT, "DELETE FROM character_achievement WHERE achievement = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ADDON, "INSERT INTO addons (name, crc) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_INVALID_PET_SPELL, "DELETE FROM pet_spell WHERE spell = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GROUP_INSTANCE_BY_INSTANCE, "DELETE FROM group_instance WHERE instance = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GROUP_INSTANCE_BY_GUID, "DELETE FROM group_instance WHERE guid = ? AND instance = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_GROUP_INSTANCE, "REPLACE INTO group_instance (guid, instance, permanent) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_INSTANCE_RESETTIME, "UPDATE instance SET resettime = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_GLOBAL_INSTANCE_RESETTIME, "INSERT INTO instance_reset (mapid, difficulty, resettime) VALUES (?, ?, ?)", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_GLOBAL_INSTANCE_RESETTIME, "DELETE FROM instance_reset WHERE mapid = ? AND difficulty = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_UPD_GLOBAL_INSTANCE_RESETTIME, "UPDATE instance_reset SET resettime = ? WHERE mapid = ? AND difficulty = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_UPD_CHAR_ONLINE, "UPDATE characters SET online = 1 WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_NAME_AT_LOGIN, "UPDATE characters SET name = ?, at_login = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_WORLDSTATE, "UPDATE worldstates SET value = ? WHERE entry = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_WORLDSTATE, "INSERT INTO worldstates (entry, value) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_INSTANCE_BY_INSTANCE_GUID, "DELETE FROM character_instance WHERE guid = ? AND instance = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_INSTANCE, "UPDATE character_instance SET instance = ?, permanent = ?, extendState = ? WHERE guid = ? AND instance = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_INSTANCE, "INSERT INTO character_instance (guid, instance, permanent, extendState) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_GENDER_AND_APPEARANCE, "UPDATE characters SET gender = ?, skin = ?, face = ?, hairStyle = ?, hairColor = ?, facialStyle = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_SKILL, "DELETE FROM character_skills WHERE guid = ? AND skill = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHARACTER_SOCIAL_FLAGS, "UPDATE character_social SET flags = ? WHERE guid = ? AND friend = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHARACTER_SOCIAL, "INSERT INTO character_social (guid, friend, flags) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER_SOCIAL, "DELETE FROM character_social WHERE guid = ? AND friend = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHARACTER_SOCIAL_NOTE, "UPDATE character_social SET note = ? WHERE guid = ? AND friend = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHARACTER_POSITION, "UPDATE characters SET position_x = ?, position_y = ?, position_z = ?, orientation = ?, map = ?, zone = ?, trans_x = 0, trans_y = 0, trans_z = 0, transguid = 0, taxi_path = '', cinematic = 1 WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHARACTER_POSITION_BY_MAPID, "UPDATE characters SET position_x = ?, position_y = ?, position_z = ?, orientation = ?, map = ?, zone = ?, trans_x = 0, trans_y = 0, trans_z = 0, transguid = 0, taxi_path = '', cinematic = 1 WHERE guid = ? AND map = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHARACTER_AURA_FROZEN, "SELECT characters.name, character_aura.remainTime FROM characters LEFT JOIN character_aura ON (characters.guid = character_aura.guid) WHERE character_aura.spell = 9454", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHARACTER_ONLINE, "SELECT name, account, map, zone FROM characters WHERE online > 0", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_DEL_INFO_BY_GUID, "SELECT guid, deleteInfos_Name, deleteInfos_Account, deleteDate FROM characters WHERE deleteDate IS NOT NULL AND guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_DEL_INFO_BY_NAME, "SELECT guid, deleteInfos_Name, deleteInfos_Account, deleteDate FROM characters WHERE deleteDate IS NOT NULL AND deleteInfos_Name LIKE CONCAT('%%', ?, '%%')", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_DEL_INFO, "SELECT guid, deleteInfos_Name, deleteInfos_Account, deleteDate FROM characters WHERE deleteDate IS NOT NULL", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHARS_BY_ACCOUNT_ID, "SELECT guid FROM characters WHERE account = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_PINFO, "SELECT totaltime, level, money, account, race, class, map, zone, gender, health, playerFlags FROM characters WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PINFO_BANS, "SELECT unbandate, bandate = unbandate, bannedby, banreason FROM character_banned WHERE guid = ? AND active ORDER BY bandate ASC LIMIT 1", CONNECTION_SYNCH);
    //0: lowGUID
    PrepareStatement(CHAR_SEL_PINFO_MAILS, "SELECT SUM(CASE WHEN (checked & 1) THEN 1 ELSE 0 END) AS 'readmail', COUNT(*) AS 'totalmail' FROM mail WHERE `receiver` = ?", CONNECTION_SYNCH);
    //0: lowGUID
    PrepareStatement(CHAR_SEL_PINFO_XP, "SELECT a.xp, b.guid FROM characters a LEFT JOIN guild_member b ON a.guid = b.guid WHERE a.guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_HOMEBIND, "SELECT mapId, zoneId, posX, posY, posZ FROM character_homebind WHERE guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_GUID_NAME_BY_ACC, "SELECT guid, name, online FROM characters WHERE account = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_CUSTOMIZE_INFO, "SELECT name, race, class, gender, at_login FROM characters WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHAR_RACE_OR_FACTION_CHANGE_INFOS, "SELECT c.at_login, c.knownTitles, gm.guid, c.map FROM characters c LEFT JOIN group_member gm ON c.guid = gm.memberGuid WHERE c.guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_INSTANCE, "SELECT data, completedEncounters FROM instance WHERE map = ? AND id = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_PERM_BIND_BY_INSTANCE, "SELECT guid FROM character_instance WHERE instance = ? and permanent = 1", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_COD_ITEM_MAIL, "SELECT id, messageType, mailTemplateId, sender, subject, body, money, has_items FROM mail WHERE receiver = ? AND has_items <> 0 AND cod <> 0", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_SOCIAL, "SELECT DISTINCT guid FROM character_social WHERE friend = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_OLD_CHARS, "SELECT guid, deleteInfos_Account FROM characters WHERE deleteDate IS NOT NULL AND deleteDate < ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_MAIL, "SELECT id, messageType, sender, receiver, subject, body, expire_time, deliver_time, money, cod, checked, stationery, mailTemplateId FROM mail WHERE receiver = ? ORDER BY id DESC", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_AURA_FROZEN, "DELETE FROM character_aura WHERE spell = 9454 AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHAR_INVENTORY_COUNT_ITEM, "SELECT COUNT(itemEntry) FROM character_inventory ci INNER JOIN item_instance ii ON ii.guid = ci.item WHERE itemEntry = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_MAIL_COUNT_ITEM, "SELECT COUNT(itemEntry) FROM mail_items mi INNER JOIN item_instance ii ON ii.guid = mi.item_guid WHERE itemEntry = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_AUCTIONHOUSE_COUNT_ITEM,"SELECT COUNT(itemEntry) FROM auctionhouse ah INNER JOIN item_instance ii ON ii.guid = ah.itemguid WHERE itemEntry = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_GUILD_BANK_COUNT_ITEM, "SELECT COUNT(itemEntry) FROM guild_bank_item gbi INNER JOIN item_instance ii ON ii.guid = gbi.item_guid WHERE itemEntry = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_CHAR_INVENTORY_ITEM_BY_ENTRY, "SELECT ci.item, cb.slot AS bag, ci.slot, ci.guid, c.account, c.name FROM characters c "
                     "INNER JOIN character_inventory ci ON ci.guid = c.guid "
                     "INNER JOIN item_instance ii ON ii.guid = ci.item "
                     "LEFT JOIN character_inventory cb ON cb.item = ci.bag WHERE ii.itemEntry = ? LIMIT ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_MAIL_ITEMS_BY_ENTRY, "SELECT mi.item_guid, m.sender, m.receiver, cs.account, cs.name, cr.account, cr.name "
                     "FROM mail m INNER JOIN mail_items mi ON mi.mail_id = m.id INNER JOIN item_instance ii ON ii.guid = mi.item_guid "
                     "INNER JOIN characters cs ON cs.guid = m.sender INNER JOIN characters cr ON cr.guid = m.receiver WHERE ii.itemEntry = ? LIMIT ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_AUCTIONHOUSE_ITEM_BY_ENTRY, "SELECT ah.itemguid, ah.itemowner, c.account, c.name FROM auctionhouse ah INNER JOIN characters c ON c.guid = ah.itemowner INNER JOIN item_instance ii ON ii.guid = ah.itemguid WHERE ii.itemEntry = ? LIMIT ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_GUILD_BANK_ITEM_BY_ENTRY, "SELECT gi.item_guid, gi.guildid, g.name FROM guild_bank_item gi INNER JOIN guild g ON g.guildid = gi.guildid INNER JOIN item_instance ii ON ii.guid = gi.item_guid WHERE ii.itemEntry = ? LIMIT ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_CHAR_ACHIEVEMENT, "DELETE FROM character_achievement WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS, "DELETE FROM character_achievement_progress WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_ACHIEVEMENT, "INSERT INTO character_achievement (guid, achievement, date) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS_BY_CRITERIA, "DELETE FROM character_achievement_progress WHERE guid = ? AND criteria = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_ACHIEVEMENT_PROGRESS, "INSERT INTO character_achievement_progress (guid, criteria, counter, date) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_REPUTATION_BY_FACTION, "DELETE FROM character_reputation WHERE guid = ? AND faction = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_REPUTATION_BY_FACTION, "INSERT INTO character_reputation (guid, faction, standing, flags) VALUES (?, ?, ? , ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_ADD_CHAR_ARENA_POINTS, "UPDATE characters SET arenaPoints = (arenaPoints + ?) WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ITEM_REFUND_INSTANCE, "DELETE FROM item_refund_instance WHERE item_guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ITEM_REFUND_INSTANCE, "INSERT INTO item_refund_instance (item_guid, player_guid, paidMoney, paidExtendedCost) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GROUP, "DELETE FROM `groups` WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GROUP_MEMBER_ALL, "DELETE FROM group_member WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_GIFT, "INSERT INTO character_gifts (guid, item_guid, entry, flags) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_INSTANCE_BY_INSTANCE, "DELETE FROM instance WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_INSTANCE_BY_INSTANCE, "DELETE FROM character_instance WHERE instance = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_EXPIRED_CHAR_INSTANCE_BY_MAP_DIFF, "DELETE FROM character_instance USING character_instance LEFT JOIN instance ON character_instance.instance = id WHERE (extendState = 0 or permanent = 0) and map = ? and difficulty = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GROUP_INSTANCE_BY_MAP_DIFF, "DELETE FROM group_instance USING group_instance LEFT JOIN instance ON group_instance.instance = id WHERE map = ? and difficulty = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_EXPIRED_INSTANCE_BY_MAP_DIFF, "DELETE FROM instance WHERE map = ? and difficulty = ? and (SELECT guid FROM character_instance WHERE extendState != 0 AND instance = id LIMIT 1) IS NULL", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_EXPIRE_CHAR_INSTANCE_BY_MAP_DIFF, "UPDATE character_instance LEFT JOIN instance ON character_instance.instance = id SET extendState = extendState-1 WHERE map = ? and difficulty = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_MAIL_ITEM_BY_ID, "DELETE FROM mail_items WHERE mail_id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_PETITION, "INSERT INTO petition (ownerguid, petitionguid, name, type) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PETITION_BY_GUID, "DELETE FROM petition WHERE petitionguid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PETITION_SIGNATURE_BY_GUID, "DELETE FROM petition_sign WHERE petitionguid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_DECLINED_NAME, "DELETE FROM character_declinedname WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_DECLINED_NAME, "INSERT INTO character_declinedname (guid, genitive, dative, accusative, instrumental, prepositional) VALUES (?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_RACE, "UPDATE characters SET race = ?, extra_flags = extra_flags | ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SKILL_LANGUAGES, "DELETE FROM character_skills WHERE skill IN (98, 113, 759, 111, 313, 109, 115, 315, 673, 137) AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_SKILL_LANGUAGE, "INSERT INTO `character_skills` (guid, skill, value, max) VALUES (?, ?, 300, 300)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_TAXI_PATH, "UPDATE characters SET taxi_path = '' WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_TAXIMASK, "UPDATE characters SET taximask = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_QUESTSTATUS, "DELETE FROM character_queststatus WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SOCIAL_BY_GUID, "DELETE FROM character_social WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SOCIAL_BY_FRIEND, "DELETE FROM character_social WHERE friend = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_ACHIEVEMENT_BY_ACHIEVEMENT, "DELETE FROM character_achievement WHERE achievement = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_ACHIEVEMENT, "UPDATE character_achievement SET achievement = ? where achievement = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_INVENTORY_FACTION_CHANGE, "UPDATE item_instance ii, character_inventory ci SET ii.itemEntry = ? WHERE ii.itemEntry = ? AND ci.guid = ? AND ci.item = ii.guid", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SPELL_BY_SPELL, "DELETE FROM character_spell WHERE spell = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_SPELL_FACTION_CHANGE, "UPDATE character_spell SET spell = ? where spell = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_CHAR_REP_BY_FACTION, "SELECT standing FROM character_reputation WHERE faction = ? AND guid = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_CHAR_REP_BY_FACTION, "DELETE FROM character_reputation WHERE faction = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_REP_FACTION_CHANGE, "UPDATE character_reputation SET faction = ?, standing = ? WHERE faction = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_TITLES_FACTION_CHANGE, "UPDATE characters SET knownTitles = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_RES_CHAR_TITLES_FACTION_CHANGE, "UPDATE characters SET chosenTitle = 0 WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SPELL_COOLDOWNS, "DELETE FROM character_spell_cooldown WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_SPELL_COOLDOWN, "INSERT INTO character_spell_cooldown (guid, spell, item, time, categoryId, categoryEnd) VALUES (?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHARACTER, "DELETE FROM characters WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_ACTION, "DELETE FROM character_action WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_AURA, "DELETE FROM character_aura WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_GIFT, "DELETE FROM character_gifts WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_INSTANCE, "DELETE FROM character_instance WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_INVENTORY, "DELETE FROM character_inventory WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED, "DELETE FROM character_queststatus_rewarded WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_REPUTATION, "DELETE FROM character_reputation WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SPELL, "DELETE FROM character_spell WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_MAIL, "DELETE FROM mail WHERE receiver = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_MAIL_ITEMS, "DELETE FROM mail_items WHERE receiver = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_ACHIEVEMENTS, "DELETE FROM character_achievement WHERE guid = ? AND achievement NOT BETWEEN '456' AND '467' AND achievement NOT BETWEEN '1400' AND '1427' AND achievement NOT IN(1463, 3117, 3259)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_EQUIPMENTSETS, "DELETE FROM character_equipmentsets WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_EVENTLOG_BY_PLAYER, "DELETE FROM guild_eventlog WHERE PlayerGuid1 = ? OR PlayerGuid2 = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_GUILD_BANK_EVENTLOG_BY_PLAYER, "DELETE FROM guild_bank_eventlog WHERE PlayerGuid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_GLYPHS, "DELETE FROM character_glyphs WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_TALENT, "DELETE FROM character_talent WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SKILLS, "DELETE FROM character_skills WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_HONOR_POINTS, "UPDATE characters SET totalHonorPoints = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_ARENA_POINTS, "UPDATE characters SET arenaPoints = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_MONEY, "UPDATE characters SET money = ? WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_ACTION, "INSERT INTO character_action (guid, spec, button, action, type) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_ACTION, "UPDATE character_action SET action = ?, type = ? WHERE guid = ? AND button = ? AND spec = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_ACTION_BY_BUTTON_SPEC, "DELETE FROM character_action WHERE guid = ? and button = ? and spec = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_INVENTORY_BY_ITEM, "DELETE FROM character_inventory WHERE item = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_INVENTORY_BY_BAG_SLOT, "DELETE FROM character_inventory WHERE bag = ? AND slot = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_MAIL, "UPDATE mail SET has_items = ?, expire_time = ?, deliver_time = ?, money = ?, cod = ?, checked = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_CHAR_QUESTSTATUS, "REPLACE INTO character_queststatus (guid, quest, status, explored, timer, mobcount1, mobcount2, mobcount3, mobcount4, itemcount1, itemcount2, itemcount3, itemcount4, itemcount5, itemcount6, playercount) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_QUESTSTATUS_BY_QUEST, "DELETE FROM character_queststatus WHERE guid = ? AND quest = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_QUESTSTATUS_REWARDED, "INSERT IGNORE INTO character_queststatus_rewarded (guid, quest, active) VALUES (?, ?, 1)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED_BY_QUEST, "DELETE FROM character_queststatus_rewarded WHERE guid = ? AND quest = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_FACTION_CHANGE, "UPDATE character_queststatus_rewarded SET quest = ? WHERE quest = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_ACTIVE, "UPDATE character_queststatus_rewarded SET active = 1 WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_ACTIVE_BY_QUEST, "UPDATE character_queststatus_rewarded SET active = 0 WHERE guid = ? AND quest = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_SKILL_BY_SKILL, "DELETE FROM character_skills WHERE guid = ? AND skill = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_SKILLS, "INSERT INTO character_skills (guid, skill, value, max) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_SKILLS, "UPDATE character_skills SET value = ?, max = ? WHERE guid = ? AND skill = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_SPELL, "INSERT INTO character_spell (guid, spell, active, disabled) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_STATS, "DELETE FROM character_stats WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_STATS, "INSERT INTO character_stats (guid, maxhealth, maxpower1, maxpower2, maxpower3, maxpower4, maxpower5, maxpower6, maxpower7, strength, agility, stamina, intellect, spirit, "
                     "armor, resHoly, resFire, resNature, resFrost, resShadow, resArcane, blockPct, dodgePct, parryPct, critPct, rangedCritPct, spellCritPct, attackPower, rangedAttackPower, "
                     "spellPower, resilience) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PETITION_BY_OWNER, "DELETE FROM petition WHERE ownerguid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PETITION_SIGNATURE_BY_OWNER, "DELETE FROM petition_sign WHERE ownerguid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PETITION_BY_OWNER_AND_TYPE, "DELETE FROM petition WHERE ownerguid = ? AND type = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PETITION_SIGNATURE_BY_OWNER_AND_TYPE, "DELETE FROM petition_sign WHERE ownerguid = ? AND type = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_GLYPHS, "INSERT INTO character_glyphs VALUES(?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_TALENT_BY_SPELL_SPEC, "DELETE FROM character_talent WHERE guid = ? AND spell = ? AND talentGroup = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_TALENT, "INSERT INTO character_talent (guid, spell, talentGroup) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_ACTION_EXCEPT_SPEC, "DELETE FROM character_action WHERE spec<>? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_FISHINGSTEPS, "INSERT INTO character_fishingsteps (guid, fishingSteps) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_FISHINGSTEPS, "DELETE FROM character_fishingsteps WHERE guid = ?", CONNECTION_ASYNC);

    // Items that hold loot or money
    PrepareStatement(CHAR_SEL_ITEMCONTAINER_ITEMS, "SELECT container_id, item_id, item_count, item_index, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_prop, rnd_suffix FROM item_loot_items", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_ITEMCONTAINER_ITEMS, "DELETE FROM item_loot_items WHERE container_id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_ITEMCONTAINER_ITEM, "DELETE FROM item_loot_items WHERE container_id = ? AND item_id = ? AND item_count = ? AND item_index = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ITEMCONTAINER_ITEMS, "INSERT INTO item_loot_items (container_id, item_id, item_count, item_index, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_prop, rnd_suffix) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_ITEMCONTAINER_MONEY, "SELECT container_id, money FROM item_loot_money", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_ITEMCONTAINER_MONEY, "DELETE FROM item_loot_money WHERE container_id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_ITEMCONTAINER_MONEY, "INSERT INTO item_loot_money (container_id, money) VALUES (?, ?)", CONNECTION_ASYNC);

    // Calendar
    PrepareStatement(CHAR_REP_CALENDAR_EVENT, "REPLACE INTO calendar_events (id, creator, title, description, type, dungeon, eventtime, flags, time2) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CALENDAR_EVENT, "DELETE FROM calendar_events WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_REP_CALENDAR_INVITE, "REPLACE INTO calendar_invites (id, event, invitee, sender, status, statustime, `rank`, text) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CALENDAR_INVITE, "DELETE FROM calendar_invites WHERE id = ?", CONNECTION_ASYNC);

    // Pet
    PrepareStatement(CHAR_SEL_CHAR_PET_IDS, "SELECT id FROM character_pet WHERE owner = ?", CONNECTION_SYNCH);
    PrepareStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME_BY_OWNER, "DELETE FROM character_pet_declinedname WHERE owner = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME, "DELETE FROM character_pet_declinedname WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_CHAR_PET_DECLINEDNAME, "INSERT INTO character_pet_declinedname (id, owner, genitive, dative, accusative, instrumental, prepositional) VALUES (?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_PET_AURA, "SELECT casterGuid, spell, effectMask, recalculateMask, stackCount, amount0, amount1, amount2, base_amount0, base_amount1, base_amount2, maxDuration, remainTime, remainCharges, critChance, applyResilience FROM pet_aura WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_PET_SPELL, "SELECT spell, active FROM pet_spell WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_PET_SPELL_COOLDOWN, "SELECT spell, time, categoryId, categoryEnd FROM pet_spell_cooldown WHERE guid = ? AND time > UNIX_TIMESTAMP()", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_PET_DECLINED_NAME, "SELECT genitive, dative, accusative, instrumental, prepositional FROM character_pet_declinedname WHERE owner = ? AND id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PET_AURAS, "DELETE FROM pet_aura WHERE guid = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_DEL_PET_SPELLS, "DELETE FROM pet_spell WHERE guid = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_PET_SPELL_COOLDOWNS, "DELETE FROM pet_spell_cooldown WHERE guid = ?", CONNECTION_BOTH);
    PrepareStatement(CHAR_INS_PET_SPELL_COOLDOWN, "INSERT INTO pet_spell_cooldown (guid, spell, time, categoryId, categoryEnd) VALUES (?, ?, ?, ?, ?)", CONNECTION_BOTH);
    PrepareStatement(CHAR_DEL_PET_SPELL_BY_SPELL, "DELETE FROM pet_spell WHERE guid = ? and spell = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_PET_SPELL, "INSERT INTO pet_spell (guid, spell, active) VALUES (?, ?, ?)", CONNECTION_BOTH);
    PrepareStatement(CHAR_INS_PET_AURA, "INSERT INTO pet_aura (guid, casterGuid, spell, effectMask, recalculateMask, stackCount, amount0, amount1, amount2, "
                     "base_amount0, base_amount1, base_amount2, maxDuration, remainTime, remainCharges, critChance, applyResilience) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_BOTH);
    PrepareStatement(CHAR_SEL_CHAR_PETS, "SELECT id, entry, modelid, level, exp, Reactstate, slot, name, renamed, curhealth, curmana, curhappiness, abdata, savetime, CreatedBySpell, PetType FROM character_pet WHERE owner = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_PET_BY_OWNER, "DELETE FROM character_pet WHERE owner = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_PET_NAME, "UPDATE character_pet SET name = ?, renamed = 1 WHERE owner = ? AND id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_CHAR_PET_SLOT_BY_ID, "UPDATE character_pet SET slot = ? WHERE owner = ? AND id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_PET_BY_ID, "DELETE FROM character_pet WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_CHAR_PET_BY_SLOT, "DELETE FROM character_pet WHERE owner = ? AND (slot = ? OR slot > ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_PET, "INSERT INTO character_pet (id, entry, owner, modelid, level, exp, Reactstate, slot, name, renamed, curhealth, curmana, curhappiness, abdata, savetime, CreatedBySpell, PetType) "
                    "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);

    // PvPstats
    PrepareStatement(CHAR_SEL_PVPSTATS_MAXID, "SELECT MAX(id) FROM pvpstats_battlegrounds", CONNECTION_SYNCH);
    PrepareStatement(CHAR_INS_PVPSTATS_BATTLEGROUND, "INSERT INTO pvpstats_battlegrounds (id, winner_faction, bracket_id, type, date) VALUES (?, ?, ?, ?, NOW())", CONNECTION_ASYNC);
    PrepareStatement(CHAR_INS_PVPSTATS_PLAYER, "INSERT INTO pvpstats_players (battleground_id, character_guid, winner, score_killing_blows, score_deaths, score_honorable_kills, score_bonus_honor, score_damage_done, score_healing_done, attr_1, attr_2, attr_3, attr_4, attr_5) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_SEL_PVPSTATS_FACTIONS_OVERALL, "SELECT winner_faction, COUNT(*) AS count FROM pvpstats_battlegrounds WHERE DATEDIFF(NOW(), date) < 7 GROUP BY winner_faction ORDER BY winner_faction ASC", CONNECTION_SYNCH);

    // QuestTracker
    PrepareStatement(CHAR_INS_QUEST_TRACK, "INSERT INTO quest_tracker (id, character_guid, quest_accept_time, core_hash, core_revision) VALUES (?, ?, NOW(), ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_QUEST_TRACK_GM_COMPLETE, "UPDATE quest_tracker SET completed_by_gm = 1 WHERE id = ? AND character_guid = ? ORDER BY quest_accept_time DESC LIMIT 1", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_QUEST_TRACK_COMPLETE_TIME, "UPDATE quest_tracker SET quest_complete_time = NOW() WHERE id = ? AND character_guid = ? ORDER BY quest_accept_time DESC LIMIT 1", CONNECTION_ASYNC);
    PrepareStatement(CHAR_UPD_QUEST_TRACK_ABANDON_TIME, "UPDATE quest_tracker SET quest_abandon_time = NOW() WHERE id = ? AND character_guid = ? ORDER BY quest_accept_time DESC LIMIT 1", CONNECTION_ASYNC);

    // DeserterTracker
    PrepareStatement(CHAR_INS_DESERTER_TRACK, "INSERT INTO battleground_deserters (guid, type, datetime) VALUES (?, ?, NOW())", CONNECTION_ASYNC);

    // AIWorld (Milestone 2.2A) - startup-only, never used from the world update loop
    // Milestone 2.11A: home_*/work_* are nullable and always NULL or set
    // together in pairs - see ai_agents' own migration comment.
    // Milestone 2.11E2: money/food/resource/last_rewarded_work_window_id/
    // economy_version are NOT NULL (default 0, never "unset" the way
    // home_*/work_* can be).
    // Milestone 2.12D (STATIC review P2 fix): the territory_*/hunger/
    // resources/kind/group_version columns 2.12A/2.12B/2.12C added here are
    // gone - an AgentGroup is no longer an ai_agents row at all (see
    // GroupId.h/AgentGroupRecord.h), so this is back to plain individual-
    // agent identity/economy columns only, the same shape it had before
    // 2.12A. See CHAR_SEL_AI_AGENT_GROUPS below for where that state lives
    // now.
    // Milestone 2.12F4A: control_mode appended at the very end of the
    // column list (not inserted next to agent_type/map_id/spawn_id where
    // the schema itself places it, see ai_agents' own 2.12F4A migration
    // comment) so every existing field index in AgentPersistence::
    // LoadAgents() stays unchanged - the same "append, don't reindex"
    // convention CHAR_SEL_AI_AGENT_GROUPS's own profile_id column already
    // follows.
    // AI WorldFactionId (see AgentRecord.h's own field comment): world_faction_id
    // appended after control_mode - fields[20], not reindexed among the
    // identity columns above, the exact same "append, don't reindex"
    // convention control_mode itself established one column earlier - see
    // the 2026_09_16_00 migration's own comment.
    PrepareStatement(CHAR_SEL_AI_AGENTS, "SELECT agent_id, agent_type, map_id, spawn_id, "
        "home_map_id, home_x, home_y, home_z, home_o, work_map_id, work_x, work_y, work_z, work_o, "
        "money, food, resource, last_rewarded_work_window_id, economy_version, control_mode, world_faction_id FROM ai_agents", CONNECTION_SYNCH);
    PrepareStatement(CHAR_SEL_AI_AGENT_BY_BINDING, "SELECT agent_id, agent_type, map_id, spawn_id FROM ai_agents WHERE map_id = ? AND spawn_id = ?", CONNECTION_SYNCH);
    // Milestone 2.12F4A: control_mode is deliberately never set here -
    // every newly created agent must get the column's own ObserveOnly
    // (0) DEFAULT, the same "don't set what the schema already defaults"
    // convention this INSERT already follows for every other defaulted
    // column (there are none here yet, but see ai_agent_groups' own
    // version column for the precedent). AgentRecord::ControlMode's own
    // in-memory default matches this exactly - see its own comment for
    // why neither may ever default to AIWorldControlled.
    //
    // Milestone 2.12F4A2 (P2 fix, STATIC review round 2: namespace policy
    // locked, not deferred to 2.12F4B - see the 2026_08_30_01 migration's
    // own comment): agent_id is bound explicitly here (=spawn_id, see
    // AgentPersistence::CreateCreatureAgent()'s own comment) - for a
    // persistent non-instance Creature agent, AgentId must equal the
    // TrinityCore Creature SpawnId it is bound to, and the column is no
    // longer AUTO_INCREMENT at all, so no auto-generated id can ever
    // collide with a real spawn_id-derived one.
    PrepareStatement(CHAR_INS_AI_AGENT, "INSERT INTO ai_agents (agent_id, agent_type, map_id, spawn_id) VALUES (?, ?, ?, ?)", CONNECTION_SYNCH);

    // Milestone 2.12F4A P2 fix (STATIC review): AgentPersistence::
    // SetControlMode() - the explicit, startup-only follow-up step
    // AIWorld.TestSpawnId's own agent-creation path uses to become
    // AIWorldControlled immediately after CreateCreatureAgent() creates it
    // at the schema's own ObserveOnly default, so a fresh-DB bootstrap of
    // that config value ends up AIWorldControlled the same way an upgrade
    // of an already-existing row for the same (map_id, spawn_id) binding
    // already does via this migration's own UPDATE. CONNECTION_SYNCH/
    // DirectExecute(), the same startup-only synchronous pattern
    // CHAR_INS_AI_AGENT above already uses - never called from the world
    // update loop.
    PrepareStatement(CHAR_UPD_AI_AGENT_CONTROL_MODE, "UPDATE ai_agents SET control_mode = ? WHERE agent_id = ?", CONNECTION_SYNCH);

    // Milestone 2.12F4A P2 fix (STATIC review, round 2): CHAR_UPD_AI_AGENT_
    // CONTROL_MODE above, like every DirectExecute() statement, never
    // reports success/failure - AgentPersistence::SetControlMode() reads
    // the row back through this to confirm the write actually landed
    // before its caller may treat the agent as AIWorldControlled, the same
    // discipline CHAR_SEL_AI_AGENT_BY_BINDING already applies to
    // CHAR_INS_AI_AGENT's own INSERT.
    PrepareStatement(CHAR_SEL_AI_AGENT_CONTROL_MODE, "SELECT control_mode FROM ai_agents WHERE agent_id = ?", CONNECTION_SYNCH);

    // Milestone 2.12F4B: lightweight bulk identity/binding read - just
    // agent_id/map_id/spawn_id, none of CHAR_SEL_AI_AGENTS' other columns.
    // AgentPersistence::LoadAllBindings() uses this to confirm a batch
    // reconciliation INSERT (AgentPersistence::CreateCreatureAgentsBatch(),
    // one CharacterDatabaseTransaction/DirectCommitTransaction for
    // potentially thousands of rows, which - like every DirectExecute()/
    // DirectCommitTransaction() call in this file - reports no per-row
    // success/failure) with exactly ONE additional query, regardless of
    // batch size - never one confirmation query per inserted row.
    PrepareStatement(CHAR_SEL_AI_AGENT_BINDINGS, "SELECT agent_id, map_id, spawn_id FROM ai_agents", CONNECTION_SYNCH);

    // Milestone 2.12F4B3: lightweight bulk read of every agent_id's
    // current control_mode - none of CHAR_SEL_AI_AGENTS' other columns.
    // AgentPersistence::LoadAllControlModes() uses this to confirm a
    // batch ControlMode promotion (AgentPersistence::
    // PromoteControlModeBatch(), one chunked raw UPDATE ... WHERE
    // agent_id IN (...) for potentially thousands of ids) with exactly
    // one query, regardless of batch size - never one confirmation query
    // per id, the same discipline CHAR_SEL_AI_AGENT_BINDINGS above
    // already applies to CreateCreatureAgentsBatch()'s own INSERT.
    PrepareStatement(CHAR_SEL_AI_AGENT_CONTROL_MODES, "SELECT agent_id, control_mode FROM ai_agents", CONNECTION_SYNCH);

    // AI WorldFactionId: lightweight bulk read of every agent_id's current
    // world_faction_id - none of CHAR_SEL_AI_AGENTS' other columns. Used by
    // AgentPersistence::ReconcileWorldFactionsBatch() to confirm its own
    // batch UPDATE with exactly one query, the same shape
    // CHAR_SEL_AI_AGENT_CONTROL_MODES above already provides for
    // PromoteControlModeBatch().
    PrepareStatement(CHAR_SEL_AI_AGENT_WORLD_FACTIONS, "SELECT agent_id, world_faction_id FROM ai_agents", CONNECTION_SYNCH);

    // AgentType identity fix (AIWorld_Current_Roadmap.md, Etapa 3):
    // lightweight bulk read of every agent_id's current agent_type - none
    // of CHAR_SEL_AI_AGENTS' other columns. Used by AgentPersistence::
    // ReconcileAgentTypesBatch() to confirm its own batch UPDATE with
    // exactly one query, the same shape CHAR_SEL_AI_AGENT_WORLD_FACTIONS
    // above already provides for ReconcileWorldFactionsBatch().
    PrepareStatement(CHAR_SEL_AI_AGENT_TYPES, "SELECT agent_id, agent_type FROM ai_agents", CONNECTION_SYNCH);

    // Milestone 2.11E2: unlike CHAR_SEL_AI_AGENTS/CHAR_INS_AI_AGENT above
    // (startup-only), this is used from the world update thread every time
    // a WORK ActionCompletion reaches Succeeded/Performed - CONNECTION_ASYNC/
    // Execute() only, the same rule CHAR_INS_AI_LONG_TERM_MEMORY below
    // already follows, never CONNECTION_SYNCH/DirectExecute(), which would
    // block that thread on the DB.
    // Milestone 2.11E2 P2 fix: money/food/resource and the WORK reward's
    // idempotency marker (last_rewarded_work_window_id) are written
    // together in this one UPDATE, never as two separate async writes -
    // see AgentEconomyState::LastRewardedWorkWindowId for why a reward
    // that persisted only one of the two would let a restart either
    // repeat or silently lose the payment.
    // Milestone 2.11E2 P3 fix: "AND economy_version < ?" makes this
    // monotonic - the async queue does not itself guarantee execution
    // order across worker threads, so without this an older snapshot
    // finishing after a newer one could otherwise silently revert it. A
    // no-op (matches zero rows) whenever the row already holds a version
    // >= the one being written; AgentPersistence::SaveEconomyState() does
    // not need to check for that, since it is already fire-and-forget with
    // no result to act on either way.
    PrepareStatement(CHAR_UPD_AI_AGENT_ECONOMY, "UPDATE ai_agents SET money = ?, food = ?, resource = ?, "
        "last_rewarded_work_window_id = ?, economy_version = ? WHERE agent_id = ? AND economy_version < ?", CONNECTION_ASYNC);

    // Milestone 2.12E1 P2 fix (STATIC review): the persistent, monotonic
    // GroupId allocator - see ai_agent_group_id_sequence's own migration
    // comment for why this exists (a plain MAX(group_id) over
    // ai_agent_groups would let a dissolved group's id be handed out
    // again after a restart). CHAR_SEL_AI_AGENT_GROUP_ID_SEQUENCE is
    // startup-only (synchronous read, AgentGroupPersistence::
    // LoadGroupIdSequence()). CHAR_UPD_AI_AGENT_GROUP_ID_SEQUENCE
    // (Milestone 2.12E2) is CONNECTION_ASYNC - it is only ever appended to
    // the same CharacterDatabaseTransaction as CHAR_INS_AI_AGENT_GROUP
    // below and committed via AsyncCommitTransaction(), never issued on
    // its own, so the reservation and the group row it protects always
    // land (or fail) together.
    //
    // Milestone 2.12E2 P2 fix (STATIC review): GREATEST(next_group_id, ?),
    // not a plain "SET next_group_id = ?" - with more than one
    // CharacterDatabase async worker thread (AIWorld.* config does not
    // control this; CharacterDatabase.WorkerThreads does, and is a normal
    // deployment tunable, not something this subsystem can assume stays at
    // 1), two CreateGroupAsync() transactions can commit out of order (the
    // one reserving the HIGHER id finishing first). A plain SET would let
    // the later-committing, lower-value transaction silently regress
    // next_group_id below a group_id that already exists, which
    // LoadGroupIdSequence()'s own high-water-mark check would then reject
    // as an invalid allocator on the next restart - not a silent identity
    // collision, but a real allocator outage from a valid deployment
    // config change. GREATEST() makes the persisted value monotonic
    // regardless of commit order: whichever of the two commits lands
    // second can never lower it back down.
    PrepareStatement(CHAR_SEL_AI_AGENT_GROUP_ID_SEQUENCE, "SELECT next_group_id FROM ai_agent_group_id_sequence WHERE id = 1", CONNECTION_SYNCH);
    PrepareStatement(CHAR_UPD_AI_AGENT_GROUP_ID_SEQUENCE, "UPDATE ai_agent_group_id_sequence SET next_group_id = GREATEST(next_group_id, ?) WHERE id = 1", CONNECTION_ASYNC);

    // Milestone 2.12E1 P2 fix (STATIC review, round 4): AgentGroupPersistence::
    // LoadGroupIdSequence()'s own high-water-mark sanity check - a
    // next_group_id that is 0 or does not exceed the highest group_id
    // physically present in ai_agent_groups (including a row LoadGroups()
    // itself would reject, e.g. for an invalid kind - this query applies
    // no such filter) is not a trustworthy allocator state, and
    // LoadGroupIdSequence() refuses to trust it. NULL (an empty
    // ai_agent_groups table) reads back as no result, the same
    // "MAX() over zero rows" shape CHAR_SEL_PVPSTATS_MAXID already has.
    PrepareStatement(CHAR_SEL_AI_AGENT_GROUP_MAX_ID, "SELECT MAX(group_id) FROM ai_agent_groups", CONNECTION_SYNCH);

    // Milestone 2.12D (STATIC review P2 fix): AgentGroup identity/state now
    // lives in its own table, ai_agent_groups, not in ai_agents any more -
    // see GroupId.h/AgentGroupRecord.h/AgentGroupPersistence.h for why.
    // Startup-only (synchronous load), same as CHAR_SEL_AI_AGENTS - called
    // once from AIWorldMgr::Initialize(), never from the world update loop.
    // Milestone 2.12E4C2 P2 fix (STATIC review): profile_id appended at the
    // end (not inserted alphabetically among the other columns) so every
    // existing field index in AgentGroupPersistence::LoadGroups() stays
    // unchanged - see AgentGroupRecord::ProfileId for what it means.
    PrepareStatement(CHAR_SEL_AI_AGENT_GROUPS, "SELECT group_id, kind, territory_map_id, territory_x, territory_y, territory_z, "
        "resources, version, profile_id FROM ai_agent_groups", CONNECTION_SYNCH);

    // Milestone 2.12E1/2.12E2: AgentGroupPersistence::CreateGroupAsync() -
    // group_id is bound explicitly (minted in C++, see ai_agent_groups'
    // own 2.12E1 migration comment for why it is no longer AUTO_INCREMENT),
    // version is left at its column DEFAULT 0, the same "don't set what
    // the schema already defaults" convention CHAR_INS_AI_AGENT follows
    // for ai_agents. CONNECTION_ASYNC - appended to the same
    // CharacterDatabaseTransaction as CHAR_UPD_AI_AGENT_GROUP_ID_SEQUENCE
    // above and committed via AsyncCommitTransaction(), never blocking the
    // world thread - see AgentGroupPersistence::CreateGroupAsync()'s own
    // comment.
    // Milestone 2.12E4C2 P2 fix (STATIC review): profile_id is now always
    // bound explicitly (never left at a column DEFAULT) - CreateGroupAsync()
    // itself defaults its own profileId parameter to
    // CoalitionFormationProfileId::Invalid for any caller that does not
    // pass one, so this never silently falls back to a DB-side default
    // that could drift from that same fail-closed value.
    PrepareStatement(CHAR_INS_AI_AGENT_GROUP, "INSERT INTO ai_agent_groups (group_id, kind, territory_map_id, territory_x, "
        "territory_y, territory_z, resources, profile_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);

    // Milestone 2.12B/2.12D: same shape as CHAR_UPD_AI_AGENT_ECONOMY above -
    // used from the world update thread every group coarse tick
    // (CONNECTION_ASYNC/Execute() only), and "AND version < ?" makes it
    // monotonic for the same reason (the async queue does not itself
    // guarantee execution order across worker threads) - see
    // AgentGroupPersistence::SaveGroupState(). No Hunger any more (2.12D
    // P2 fix) - see AgentGroupRecord.h.
    // Milestone 2.12E4C2 P2 fix (STATIC review): profile_id is written back
    // on every save too, the same "persist the whole snapshot" shape every
    // other field here already gets - it never actually changes after
    // creation, but SaveGroupState() has no special-case for "fields that
    // happen not to change" for anything else either.
    PrepareStatement(CHAR_UPD_AI_AGENT_GROUP, "UPDATE ai_agent_groups SET kind = ?, territory_map_id = ?, territory_x = ?, "
        "territory_y = ?, territory_z = ?, resources = ?, version = ?, profile_id = ? WHERE group_id = ? AND version < ?", CONNECTION_ASYNC);

    // Milestone 2.12E4C2 P2 fix (STATIC review): AgentGroupPersistence::
    // AdoptGroupProfileAsync() - a dedicated, single-column, confirmed-
    // commit UPDATE for AIWorldMgr::RunGroupProfileAdoption()'s own legacy-
    // provenance recovery, deliberately NOT reusing CHAR_UPD_AI_AGENT_GROUP/
    // SaveGroupState()'s fire-and-forget Execute() path - unlike the
    // continuously-redundant Resources drift write that already tolerates,
    // a one-shot operator-triggered identity/provenance correction must be
    // reported as adopted (and only then trusted by
    // RunCoalitionMaintenance()) after a genuine DB-driver-reported commit
    // result, not merely "the write was submitted". CONNECTION_ASYNC,
    // committed via AsyncCommitTransaction() like every other confirmed
    // AgentGroup write in this file - never blocks the world thread.
    PrepareStatement(CHAR_UPD_AI_AGENT_GROUP_PROFILE_ID, "UPDATE ai_agent_groups SET profile_id = ? WHERE group_id = ?", CONNECTION_ASYNC);

    // Milestone 2.12E1/2.12E2: AgentGroupPersistence::DeleteGroupAsync() -
    // the group-row half, appended to the same CharacterDatabaseTransaction
    // as CHAR_DEL_AI_AGENT_GROUP_MEMBERS_BY_GROUP below and committed
    // atomically via AsyncCommitTransaction() (never two independent
    // statements - a crash or error between two separate commits could
    // otherwise leave an orphaned membership row pointing at a group_id
    // that no longer exists). CONNECTION_ASYNC, same non-blocking category
    // as CHAR_INS_AI_AGENT_GROUP above.
    PrepareStatement(CHAR_DEL_AI_AGENT_GROUP, "DELETE FROM ai_agent_groups WHERE group_id = ?", CONNECTION_ASYNC);

    // Milestone 2.12C/2.12D: startup-only (synchronous load), same as
    // CHAR_SEL_AI_AGENTS - called once from AIWorldMgr::Initialize(),
    // never from the world update loop. group_id (not group_agent_id any
    // more - a group's identity is its own GroupId now, not an AgentId,
    // see GroupId.h) and member_agent_id are two different id spaces, both
    // validated by AgentGroupPersistence::LoadGroupMembers() at load time.
    PrepareStatement(CHAR_SEL_AI_AGENT_GROUP_MEMBERS, "SELECT group_id, member_agent_id, joined_at_ms FROM ai_agent_group_members", CONNECTION_SYNCH);

    // Milestone 2.12E1/2.12E2: AgentGroupPersistence::AddGroupMemberAsync()/
    // RemoveGroupMemberAsync() - each its own single-statement
    // CharacterDatabaseTransaction, committed via AsyncCommitTransaction()
    // (CONNECTION_ASYNC, never blocking the world thread - see
    // AgentGroupPersistence.h's own class comment for why a transaction's
    // own reported commit result replaces the read-back-based confirmation
    // 2.12E1 originally used here). Duplicate-membership prevention is
    // AgentGroupLifecycleSystem::RequestJoinGroup()'s job (checked against
    // the in-memory AgentGroupRecord::Members before this is ever issued),
    // not this statement's - it does not need its own "ON DUPLICATE KEY"
    // handling.
    PrepareStatement(CHAR_INS_AI_AGENT_GROUP_MEMBER, "INSERT INTO ai_agent_group_members (group_id, member_agent_id, joined_at_ms) "
        "VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(CHAR_DEL_AI_AGENT_GROUP_MEMBER, "DELETE FROM ai_agent_group_members WHERE group_id = ? AND member_agent_id = ?", CONNECTION_ASYNC);

    // Milestone 2.12E1/2.12E2: the membership half of AgentGroupPersistence::
    // DeleteGroupAsync()'s CharacterDatabaseTransaction - see
    // CHAR_DEL_AI_AGENT_GROUP above for why this is appended to the same
    // transaction rather than committed independently.
    PrepareStatement(CHAR_DEL_AI_AGENT_GROUP_MEMBERS_BY_GROUP, "DELETE FROM ai_agent_group_members WHERE group_id = ?", CONNECTION_ASYNC);

    // AIWorld (Milestone 2.5B) - CHAR_SEL_AI_LONG_TERM_MEMORIES is startup-only (synchronous
    // load, same as CHAR_SEL_AI_AGENTS). CHAR_INS_AI_LONG_TERM_MEMORY is used from the world
    // update thread when a memory is promoted, so it must stay CONNECTION_ASYNC/Execute() -
    // never CONNECTION_SYNCH/DirectExecute(), which would block that thread on the DB.
    PrepareStatement(CHAR_SEL_AI_LONG_TERM_MEMORIES,
        "SELECT memory_id, agent_id, observation_type, importance, source_event_id, has_source_event_type, "
        "source_event_type, correlation_id, source_occurred_at_ms, first_observed_at_ms, last_observed_at_ms, "
        "observation_count, map_id, position_x, position_y, position_z, actor_guid, actor_spawn_id, actor_entry, "
        "actor_agent_id, target_guid, target_spawn_id, target_entry, target_agent_id, channel FROM ai_long_term_memories",
        CONNECTION_SYNCH);
    PrepareStatement(CHAR_INS_AI_LONG_TERM_MEMORY,
        "INSERT INTO ai_long_term_memories (agent_id, observation_type, importance, source_event_id, "
        "has_source_event_type, source_event_type, correlation_id, source_occurred_at_ms, first_observed_at_ms, "
        "last_observed_at_ms, observation_count, map_id, position_x, position_y, position_z, actor_guid, "
        "actor_spawn_id, actor_entry, actor_agent_id, target_guid, target_spawn_id, target_entry, target_agent_id, "
        "channel) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
        CONNECTION_ASYNC);
}

CharacterDatabaseConnection::CharacterDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo)
{
}

CharacterDatabaseConnection::CharacterDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo)
{
}

CharacterDatabaseConnection::~CharacterDatabaseConnection()
{
}

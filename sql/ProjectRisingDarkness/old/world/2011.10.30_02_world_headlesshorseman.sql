-- Script texts
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23682, -1189100, 'It is over, your search is done. Let fate choose now, the righteous one.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 11961, 0, 0, 0, 'headless horseman SAY_ENTRANCE');
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23775, -1189102, 'Get over here, you idiot!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 12569, 0, 0, 0, 'headless horseman SAY_LOST_HEAD');
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23775, -1189103, 'Iam over here ou fool', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 12568, 0, 0, 0, 'headless horseman SAY_LOST_HEAD');
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23682, -1189101, 'Here\'s my body, fit and pure! Now, your blackened souls I\'ll cure!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 12567, 0, 0, 0, 'headless horseman SAY_REJOINED');
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23682, -1189105, 'Soldiers arise, stand and fight! Bring victory at last to this fallen knight!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 11963, 0, 0, 0, 'headless horseman SAY_SPROUTING_PUMPKINS');
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23682, -1189104, 'Harken, cur! Tis you I spurn! Now feel... the burn!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 12574, 0, 0, 0, 'headless horseman SAY_CONFLAGRATION');
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23682, -1189107, 'This end have I reached before. What new adventure lies in store?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 11964, 0, 0, 0, 'headless horseman SAY_DEATH');
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES (23682, -1189106, 'Your body lies beaten, battered and broken. Let my curse be your own, fate has spoken.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 11962, 0, 0, 0, 'headless horseman SAY_PLAYER_DEATH');

-- Correct equip template
REPLACE INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES (3001, 49128, 0, 0);
UPDATE `creature_template` SET `equipment_id`=3001 WHERE `entry`=23682;

-- Scriptnames
UPDATE `creature_template` SET `ScriptName`='mob_pulsing_pumpkin' WHERE `entry` = 23694;
UPDATE `creature_template` SET `ScriptName`='mob_wisp_invis', `faction_A`=35, `faction_H`=35, `unit_flags`='33554434' WHERE `entry`='23686';
UPDATE `creature_template` SET `ScriptName`='mob_wisp_invis', `unit_flags`='33554434' WHERE `entry`='24034';

-- Fix Loot-Filled Pumpkin's loot`creature_template_addon`
DELETE FROM `item_loot_template` WHERE `entry` = 54516;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 33292, 0, 1, 1, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 33154, 0, 1, 1, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 33176, 0, 1, 1, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 49128, 0, 1, 1, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 49126, 0, 1, 1, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 37012, 0, 1, 1, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20569, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 34003, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20572, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20567, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20391, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20570, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20573, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 34000, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20562, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20392, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20565, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20563, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20571, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20574, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20561, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20564, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 34001, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20568, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 20566, 0, 1, 2, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (54516, 34002, 0, 1, 2, 1, 1);

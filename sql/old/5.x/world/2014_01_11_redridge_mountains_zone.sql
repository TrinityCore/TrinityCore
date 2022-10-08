-- Generic Modify
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE  `entry`=43329 AND `item`=58954;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE  `entry`=43327 AND `item`=58953;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE  `entry`=703 AND `item`=59522;
DELETE FROM `creature_loot_template` WHERE  `entry`=703 AND `item`=3632;
UPDATE `creature_template_addon` SET `auras`='' WHERE  entry IN (382, 43270, 43272, 43274);
UPDATE `creature_queststarter` SET `id`=43270 WHERE  `id`=43300 AND `quest`=26560;
UPDATE `creature_queststarter` SET `id`=43272 WHERE  `id`=43305 AND `quest`=26561;
UPDATE `creature_queststarter` SET `id`=43274 WHERE  `id`=43303 AND `quest`=26562;
UPDATE `creature_queststarter` SET `id`=43275 WHERE  `id`=43302 AND `quest`=26563;
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`=5 WHERE  `Id`=26708;
DELETE FROM `gameobject_queststarter` WHERE  `id`=47 AND `quest`=180;
-- Quest Insert/Modify
DELETE FROM `gameobject_template` WHERE entry=(204344);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (204344, 2, 156, 'Wanted!', '', '', '', 35, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15383, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 15595);
UPDATE `quest_template` SET `NextQuestIdChain`=26560 WHERE  `Id`=26587;
UPDATE `quest_template` SET `PrevQuestId`=26560, `NextQuestIdChain`=26562 WHERE  `Id`=26561;
UPDATE `quest_template` SET `PrevQuestId`=26561, `NextQuestIdChain`=26563 WHERE  `Id`=26562;
UPDATE `quest_template` SET `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE  `Id`=26573;
UPDATE `quest_template` SET `PrevQuestId`=26562 WHERE  `Id`=26563;
-- Quest:Bravo Company Field Kit: Camouflage
DELETE FROM `gameobject_template` WHERE entry=(204424);
DELETE FROM `gameobject_template` WHERE entry=(204425);
DELETE FROM `gameobject_loot_template` WHERE entry=(204424);
DELETE FROM `gameobject_loot_template` WHERE entry=(204425);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (204424, 59152, -100, 1, 0, 1, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (204425, 59153, -100, 1, 0, 1, 1);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (204425, 3, 9572, 'Fox Poop', '', 'Collecting', '', 0, 4, 1, 59153, 0, 0, 0, 0, 0, 1691, 204425, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 13329);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (204424, 3, 8646, 'Pile of Leaves', '', 'Collecting', '', 0, 0, 1, 59152, 0, 0, 0, 0, 0, 1691, 204424, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 13329);
-- Quest:The Grand Magus Doane (se il mob va in texture uscire dalla torre e riappare)
UPDATE `creature_template` SET `faction_A`=39, `faction_H`=39, `npcflag`=2 WHERE  `entry`=397;
-- Quest:Showdown at Stonewatch
DELETE FROM `creature` WHERE id=334;
DELETE FROM `creature` WHERE id=486;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (8174668, 334, 0, 1, 4294967295, 0, 1, -9384.39, -3017.97, 136.687, 6.24415, 300, 0, 0, 15000, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (8174669, 486, 0, 1, 4294967295, 0, 1, -9383.35, -3080.05, 157.872, 1.61424, 300, 0, 0, 12, 1, 0, 0, 0, 0);
UPDATE `creature_template` SET `Health_mod`=6564 WHERE  `entry`=486;
-- Quest:We Must Prepare!
DELETE FROM `gameobject_template` WHERE entry=(204350);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (204350, 3, 7764, 'Gnomecorder', '', 'Retrieving', '', 0, 0, 1, 58894, 0, 0, 0, 0, 0, 1691, 30888, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23645, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 15595);
-- Quest:Breaking Out is Hard to Do
DELETE FROM `gameobject_template` WHERE entry=(204389);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (204389, 3, 7144, 'Blackrock Key Pouch', '', 'Stealing', '', 0, 0, 0.6, 58950, 59261, 0, 0, 0, 0, 1691, 204389, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26365, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 13329);
-- Quest:Wanted: Gath'Ilzogg
DELETE FROM `gameobject_template` WHERE entry=(60);
DELETE FROM `gameobject_template` WHERE entry=(47);
DELETE FROM `creature_questender` WHERE quest=(169);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (47, 2, 17, 'Wanted!', '', '', '', 12, 0, 1, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 15595);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (60, 2, 2, 'Wanted: Gath''Ilzogg', '', '', '', 84, 0, 1.15, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 15595);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (344, 169);
-- Quest not working
UPDATE `quest_template` SET `Method`=0 WHERE Id IN (26616, 26646, 26651, 26668);

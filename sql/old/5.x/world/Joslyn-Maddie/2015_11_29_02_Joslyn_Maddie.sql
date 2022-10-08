-- Gameobject Loot template and fix template for moss covered chest (223101) there are a few chests

DELETE FROM `gameobject_template` WHERE `entry` = '223101' ;

INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WDBVerified`) VALUES('223101','3','5744','Moss-Covered Chest','','Opening','','0','0','1','0','0','0','0','0','0','57','223101','0','1','0','0','-1','0','0','0','0','0','0','1','21400','0','0','15343','0','0','0','0','0','0','0','0','147926','0','0','0','49476','0','0','','','17658');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountorRef`, `maxcount`) VALUES ('223101', '102318', '3', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102291', '1.8', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '104347', '1.6', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102269', '1.4', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102267', '1.3', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102288', '1.2', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102286', '1.1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountorRef`,`maxcount`) VALUES ('223101', '102289', '1.1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102320', '1.1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102285', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102287', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102284', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102322', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102279', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102280', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102281', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102275', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102264', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102266', '1', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102277', '0.9', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102282', '0.9', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102276', '0.9', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102271', '0.9', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102323', '0.9', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102272', '0.9', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102263', '0.9', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102321', '0.8', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102278', '0.8', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102270', '0.8', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102274', '0.8', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102268', '0.8', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102283', '0.7', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102273', '0.7', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '102265', '0.7', '0', '0', '1', '1');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`,`mincountorRef`, `maxcount`) VALUES ('223101', '104345', '0.5', '0', '0', '1', '1');


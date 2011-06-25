-- Flame Leviathan (10) (0 Tower)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=33113 AND `item`=47241;
-- Flame Leviathan (25) (0 Tower)
UPDATE `creature_loot_template` SET `item`=45624 WHERE `entry`=34003 AND `item`=47241;

-- Ignis (10)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=33118 AND `item`=47241;
-- Ignis (25)
UPDATE `creature_loot_template` SET `item`=45624 WHERE `entry`=33190 AND `item`=47241;

-- Razorscale (10)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=33186 AND `item`=47241;
-- Razorscale (25)
UPDATE `creature_loot_template` SET `item`=45624 WHERE `entry`=33724 AND `item`=47241;

-- XT-002 (10)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=33293 AND `item`=47241;
DELETE FROM `reference_loot_template` WHERE `entry`=34121 AND `lootmode`=2;
DELETE FROM `creature_loot_template` WHERE `entry`=33293 AND `lootmode`=2;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('33293','45624','100','2','0','1','1'),
('33293','45867','0','2','1','1','1'),
('33293','45868','0','2','1','1','1'),
('33293','45869','0','2','1','1','1'),
('33293','45870','0','2','1','1','1'),
('33293','45871','0','2','1','1','1');
-- XT-002 (25)
UPDATE `creature_loot_template` SET `item`=45624 WHERE `entry`=33885 AND `item`=47241;

-- Stormcaller Brundir (10)
UPDATE `creature_loot_template` SET `item`=40753, `mincountOrRef`=2, `maxcount`=2 WHERE `entry`=32857 AND `item`=47241;
-- Stormcaller Brundir (25)
UPDATE `creature_loot_template` SET `item`=45624, `mincountOrRef`=2, `maxcount`=2 WHERE `entry`=33694 AND `item`=47241;

-- Runemaster Molgeim (10)
UPDATE `creature_loot_template` SET `item`=40753, `mincountOrRef`=2, `maxcount`=2 WHERE `entry`=32927 AND `item`=47241;
DELETE FROM `creature_loot_template` WHERE `entry`=32927 AND `item`=45624;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('32927','45624','100','1','0','1','1');
-- Runemaster Molgeim (25)
UPDATE `creature_loot_template` SET `item`=45624, `mincountOrRef`=3, `maxcount`=3 WHERE `entry`=33692 AND `item`=47241;

-- Steelbreaker (10)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=32867 AND `item`=47241;
DELETE FROM `creature_loot_template` WHERE `entry`=32867 AND `item`=45624;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('32867','45624','100','1','0','2','2');
-- Steelbreaker (25)
UPDATE `creature_loot_template` SET `item`=45624, `mincountOrRef`=3, `maxcount`=3 WHERE `entry`=33693 AND `item`=47241;

-- Auriaya (10)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=33515 AND `item`=47241;
-- Auriaya (25)
UPDATE `creature_loot_template` SET `item`=45624 WHERE `entry`=34175 AND `item`=47241;

-- Kologarn (10)
UPDATE `gameobject_loot_template` SET `item`=40753 WHERE `entry`=27061 AND `item`=47241;
-- Kologarn (25)
UPDATE `gameobject_loot_template` SET `item`=45624 WHERE `entry`=26929 AND `item`=47241;

-- Freya (25)
DELETE FROM `reference_loot_template` WHERE `entry` IN (12020,12021,12022);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- t8.5
('12020','45653','0','1','1','1','1'),
('12020','45654','0','1','1','1','1'),
('12020','45655','0','1','1','1','1'),
-- 1 elder alive emblems
('12021','45624','100','2','0','1','1'),
-- 2 elder alive emblems
('12022','45624','100','4','0','1','1'),
('12022','45087','100','4','0','1','1');

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (27079,26962);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- Freya (25) normal
('27079','1','100','1','0','1','1'),
('27079','2','100','1','0','-34154','1'),
('27079','3','100','1','0','-12020','2'),
('27079','4','100','2','0','-12021','1'),
('27079','5','100','4','0','-12022','1'),
('27079','45038','18','1','0','1','1'),
('27079','45087','100','1','0','1','1'),
('27079','45479','0','1','1','1','1'),
('27079','45480','0','1','1','1','1'),
('27079','45481','0','1','1','1','1'),
('27079','45482','0','1','1','1','1'),
('27079','45483','0','1','1','1','1'),
('27079','45624','100','1','0','1','1'),
('27079','46110','100','1','0','1','1'),
-- Freya (25) hard
('26962','1','100','1','0','-34154','1'),
('26962','2','100','1','0','-12020','2'),
('26962','45038','18','1','0','1','1'),
('26962','45087','100','1','0','3','3'),
('26962','45479','0','1','1','1','1'),
('26962','45480','0','1','1','1','1'),
('26962','45481','0','1','1','1','1'),
('26962','45482','0','1','1','1','1'),
('26962','45483','0','1','1','1','1'),
('26962','45484','0','2','2','1','1'),
('26962','45485','0','2','2','1','1'),
('26962','45486','0','2','2','1','1'),
('26962','45487','0','2','2','1','1'),
('26962','45488','0','2','2','1','1'),
('26962','45613','0','2','2','1','1'),
('26962','45624','100','1','0','5','5'),
('26962','45814','-100','1','0','1','1'),
('26962','46110','100','1','0','1','1');

-- Mimiron (10) normal
UPDATE `gameobject_template` SET `size`=1.5 WHERE `entry`=194956;
DELETE FROM `reference_loot_template` WHERE `entry`=34129 AND `lootmode`=2;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27085 AND `lootmode`=2;
UPDATE `gameobject_loot_template` SET `item`=40753 WHERE `entry`=27085 AND `item`=47241;
-- Mimiron (10) hard
DELETE FROM `gameobject_loot_template` WHERE `entry`=27086;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('27086','1','100','1','0','-34129','1'),
('27086','45982','0','1','2','1','1'),
('27086','45988','0','1','2','1','1'),
('27086','45989','0','1','2','1','1'),
('27086','45990','0','1','2','1','1'),
('27086','45993','0','1','2','1','1'),
('27086','45647','0','1','1','1','1'),
('27086','45648','0','1','1','1','1'),
('27086','45649','0','1','1','1','1'),
('27086','45787','-100','1','0','1','1'),
('27086','40753','100','1','0','1','1'),
('27086','45624','100','1','0','1','1');

-- Mimiron (25) normal
DELETE FROM `gameobject_loot_template` WHERE `entry`=26963 AND (`lootmode`=2 OR `groupid`=3);
UPDATE `gameobject_loot_template` SET `item`=45624 WHERE `entry`=26963 AND `item`=47241;

DELETE FROM `reference_loot_template` WHERE `entry`=34180;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('34180','45641','0','1','1','1','1'),
('34180','45642','0','1','1','1','1'),
('34180','45643','0','1','1','1','1');

DELETE FROM `gameobject_loot_template` WHERE `entry`=26963 AND `mincountOrRef`=-34180;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('26963','2','100','1','0','-34180','2');

-- Mimiron (25) hard
DELETE FROM `gameobject_loot_template` WHERE `entry`=26967;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('26967','1','10','1','0','-34154','1'),
('26967','2','100','1','0','-34180','2'),
('26967','45038','18','1','0','1','1'),
('26967','45087','75','1','0','1','1'),
('26967','45489','0','1','1','1','1'),
('26967','45490','0','1','1','1','1'),
('26967','45491','0','1','1','1','1'),
('26967','45492','0','1','1','1','1'),
('26967','45493','0','1','1','1','1'),
('26967','45494','0','1','2','1','1'),
('26967','45495','0','1','2','1','1'),
('26967','45496','0','1','2','1','1'),
('26967','45497','0','1','2','1','1'),
('26967','45620','0','1','2','1','1'),
('26967','45624','100','1','0','2','2'),
('26967','45663','0','1','2','1','1'),
('26967','45816','-100','1','0','1','1');

-- Thorim (10) normal
UPDATE `gameobject_template` SET `faction`=0, `flags`=0 WHERE `entry`=194312;
UPDATE `gameobject_template` SET `size`=3, `data1`=40000 WHERE `entry`=194315;
DELETE FROM `reference_loot_template` WHERE `entry`=34130 AND `lootmode`=2;
DELETE FROM `gameobject_loot_template` WHERE `entry`=27073 AND `lootmode`=2;
UPDATE `gameobject_loot_template` SET `item`=40753 WHERE `entry`=27073 AND `item`=47241;
-- Thorim (10) hard
DELETE FROM `gameobject_loot_template` WHERE `entry`=27074;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('27074','1','100','1','0','-34130','1'),
('27074','45928','0','1','2','1','1'),
('27074','45929','0','1','2','1','1'),
('27074','45930','0','1','2','1','1'),
('27074','45931','0','1','2','1','1'),
('27074','45933','0','1','2','1','1'),
('27074','45659','0','1','1','1','1'),
('27074','45660','0','1','1','1','1'),
('27074','45661','0','1','1','1','1'),
('27074','45784','-100','1','0','1','1'),
('27074','40753','100','1','0','1','1'),
('27074','45624','100','1','0','1','1');

-- Thorim (25) normal
DELETE FROM `reference_loot_template` WHERE `entry`=34181;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('34181','45638','0','1','1','1','1'),
('34181','45639','0','1','1','1','1'),
('34181','45640','0','1','1','1','1');

DELETE FROM `gameobject_loot_template` WHERE `entry`=40000;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('40000','1','10','1','0','-34154','1'),
('40000','2','100','1','0','-34181','2'),
('40000','45038','18','1','0','1','1'),
('40000','45087','75','1','0','1','1'),
('40000','45463','0','1','1','1','1'),
('40000','45466','0','1','1','1','1'),
('40000','45467','0','1','1','1','1'),
('40000','45468','0','1','1','1','1'),
('40000','45469','0','1','1','1','1'),
('40000','45624','100','1','0','1','1');

-- Thorim (25) hard
DELETE FROM `gameobject_loot_template` WHERE `entry`=26955;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('26955','1','10','1','0','-34154','1'),
('26955','2','100','1','0','-34181','2'),
('26955','45038','18','1','0','1','1'),
('26955','45087','75','1','0','1','1'),
('26955','45463','0','1','1','1','1'),
('26955','45466','0','1','1','1','1'),
('26955','45467','0','1','1','1','1'),
('26955','45468','0','1','1','1','1'),
('26955','45469','0','1','1','1','1'),
('26955','45470','0','1','2','1','1'),
('26955','45471','0','1','2','1','1'),
('26955','45472','0','1','2','1','1'),
('26955','45473','0','1','2','1','1'),
('26955','45474','0','1','2','1','1'),
('26955','45570','0','1','2','1','1'),
('26955','45624','100','1','0','2','2'),
('26955','45817','-100','1','0','1','1');

-- Hodir (10) normal
UPDATE `gameobject_template` SET `flags`=16 WHERE `entry`=194201;
UPDATE `gameobject_loot_template` SET `item`=40753 WHERE `entry`=27068 AND `item`=47241;
-- Hodir (10) hard
UPDATE `gameobject_loot_template` SET `lootmode`=1 WHERE `entry`=27069 AND `lootmode`=2;
UPDATE `gameobject_loot_template` SET `item`=45624 WHERE `entry`=27069 AND `item`=47241;

-- Hodir (25) normal
DELETE FROM `reference_loot_template` WHERE `entry`=34182;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('34182','45632','0','1','1','1','1'),
('34182','45633','0','1','1','1','1'),
('34182','45634','0','1','1','1','1');

DELETE FROM `gameobject_loot_template` WHERE `entry`=26946;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('26946','1','10','1','0','-34154','1'),
('26946','2','100','1','0','-34182','2'),
('26946','45038','8','1','0','1','1'),
('26946','45087','75','1','0','1','1'),
('26946','45450','0','1','1','1','1'),
('26946','45451','0','1','1','1','1'),
('26946','45452','0','1','1','1','1'),
('26946','45453','0','1','1','1','1'),
('26946','45454','0','1','1','1','1'),
('26946','45624','100','1','0','1','1');

-- Hodir (25) hard
UPDATE `gameobject_loot_template` SET `lootmode`=1 WHERE `entry`=26950 AND `lootmode`=2;
UPDATE `gameobject_loot_template` SET `item`=45624 WHERE `entry`=26950 AND `item`=47241;

-- Vezax (10)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=33271 AND `item`=47241;
DELETE FROM `reference_loot_template` WHERE `entry`=34131 AND `lootmode`=2;
DELETE FROM `creature_loot_template` WHERE `entry`=33271 AND `lootmode`=2;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('33271','45624','100','2','0','1','1'),
('33271','46032','0','2','1','1','1'),
('33271','46033','0','2','1','1','1'),
('33271','46034','0','2','1','1','1'),
('33271','46035','0','2','1','1','1'),
('33271','46036','0','2','1','1','1');
-- Vezax (25)
UPDATE `creature_loot_template` SET `item`=45624 WHERE `entry`=33449 AND `item`=47241;

-- Yogg-Saron (10) (4 Keeper)
UPDATE `creature_loot_template` SET `item`=40753 WHERE `entry`=33288 AND `item`=47241;
-- Yogg-Saron (25) (4 Keeper)
UPDATE `creature_loot_template` SET `item`=45624 WHERE `entry`=33955 AND `item`=47241;
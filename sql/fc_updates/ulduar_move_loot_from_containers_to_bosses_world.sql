/* Hack floor 2 of Ulduar YTDB 563 trinity*/

-- delete doors from floor 2 Ulduar instance
-- delete from gameobject where id in(194556, 194560, 194557, 194558, 194255, 194750, 194767);

-- move loot from Gift of the Observer(container) to boss Algalon
DELETE FROM `gameobject_loot_template` WHERE `entry`=194822;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194822;
UPDATE `creature_template` SET `lootid` = 32871 WHERE `entry` = 32871;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32871, 46037, 0, 1, 3, 1, 1),
(32871, 46038, 0, 1, 2, 1, 1),
(32871, 46039, 0, 1, 1, 1, 1),
(32871, 46040, 0, 1, 1, 1, 1),
(32871, 46041, 0, 1, 3, 1, 1),
(32871, 46042, 0, 1, 2, 1, 1),
(32871, 46043, 0, 1, 2, 1, 1),
(32871, 46044, 0, 1, 2, 1, 1),
(32871, 46045, 0, 1, 1, 1, 1),
(32871, 46046, 0, 1, 2, 1, 1),
(32871, 46047, 0, 1, 3, 1, 1),
(32871, 46048, 0, 1, 1, 1, 1),
(32871, 46049, 0, 1, 3, 1, 1),
(32871, 46050, 0, 1, 3, 1, 1),
(32871, 46051, 0, 1, 1, 1, 1),
(32871, 46052, 100, 1, 0, 1, 1),
(32871, 47241, 100, 1, 0, 2, 2);
DELETE FROM `gameobject_loot_template` WHERE `entry`=194821;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194821;
UPDATE `creature_template` SET `lootid` = 33070 WHERE `entry` = 33070;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(33070, 45570, 0, 1, 3, 1, 1),
(33070, 45587, 0, 1, 1, 1, 1),
(33070, 45594, 0, 1, 1, 1, 1),
(33070, 45599, 0, 1, 2, 1, 1),
(33070, 45609, 0, 1, 2, 1, 1),
(33070, 45610, 0, 1, 1, 1, 1),
(33070, 45611, 0, 1, 3, 1, 1),
(33070, 45612, 0, 1, 2, 1, 1),
(33070, 45615, 0, 1, 2, 1, 1),
(33070, 45616, 0, 1, 3, 1, 1),
(33070, 45617, 0, 1, 2, 1, 1),
(33070, 45619, 0, 1, 3, 1, 1),
(33070, 45620, 0, 1, 3, 1, 1),
(33070, 45665, 0, 1, 1, 1, 1),
(33070, 46053, 100, 1, 0, 1, 1),
(33070, 47241, 100, 1, 0, 1, 1);

-- move loot from Cache of Storms (container) to boss Thorim
DELETE FROM `gameobject_loot_template` WHERE `entry`=194313;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194313;
UPDATE `creature_template` SET `lootid` = 32865 WHERE `entry` = 32865;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32865, 45661, 100, 1, 0, -45661, 1),
(32865, 45784, -100, 1, 0, 1, 1),
(32865, 45893, 100, 1, 0, -45893, 1),
(32865, 45928, 100, 1, 0, -45928, 1),
(32865, 47241, 100, 1, 0, 1, 1);
DELETE FROM `gameobject_loot_template` WHERE `entry`=194315;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194315;
UPDATE `creature_template` SET `lootid` = 33147 WHERE `entry` = 33147;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(33147, 45038, 10, 1, 0, 1, 1),
(33147, 45087, 33, 1, 0, 1, 1),
(33147, 45089, 5, 1, 0, -45089, 1),
(33147, 45467, 100, 1, 0, -45467, 1),
(33147, 45474, 100, 1, 0, -45474, 1),
(33147, 45640, 100, 1, 0, -45640, 1),
(33147, 45817, -100, 1, 0, 1, 1),
(33147, 47241, 100, 1, 0, 1, 1);

-- move loot from Rare Cache of Winter (container) to boss Hodir
DELETE FROM `gameobject_loot_template` WHERE `entry`=194307;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194307;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194200;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194200;
UPDATE `creature_template` SET `lootid` = 32845 WHERE `entry` = 32845;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32845, 45095, 0.7278, 1, 0, 1, 1),
(32845, 45095, 0.308, 1, 0, 1, 1),
(32845, 45458, 0, 1, 1, 1, 1),
(32845, 45464, 0, 1, 1, 1, 1),
(32845, 45652, 100, 1, 0, -45652, 1),
(32845, 45786, -100, 1, 0, 1, 1),
(32845, 45872, 0, 1, 1, 1, 1),
(32845, 45873, 0, 1, 1, 1, 1),
(32845, 45874, 0, 1, 1, 1, 1),
(32845, 45876, 0, 1, 1, 1, 1),
(32845, 45877, 0, 1, 1, 1, 1),
(32845, 45886, 0, 1, 1, 1, 1),
(32845, 45887, 0, 1, 1, 1, 1),
(32845, 45888, 0, 1, 1, 1, 1),
(32845, 47241, 100, 1, 0, 1, 1),
(32845, 47241, 100, 1, 0, 1, 1);
DELETE FROM `gameobject_loot_template` WHERE `entry`=194308;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194308;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194201;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194201;
UPDATE `creature_template` SET `lootid` = 32846 WHERE `entry` = 32846;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32846, 45038, 10, 1, 0, 1, 1),
(32846, 45087, 33, 1, 0, 1, 1),
(32846, 45089, 5, 1, 0, -45089, 1),
(32846, 45089, 5, 1, 0, -45089, 1),
(32846, 45450, 0, 1, 1, 1, 1),
(32846, 45451, 0, 1, 1, 1, 1),
(32846, 45452, 0, 1, 1, 1, 1),
(32846, 45453, 0, 1, 1, 1, 1),
(32846, 45454, 0, 1, 1, 1, 1),
(32846, 45457, 0, 1, 1, 1, 1),
(32846, 45459, 0, 1, 1, 1, 1),
(32846, 45460, 0, 1, 1, 1, 1),
(32846, 45461, 0, 1, 1, 1, 1),
(32846, 45462, 0, 1, 1, 1, 1),
(32846, 45634, 100, 1, 0, -45634, 2),
(32846, 45815, -100, 1, 0, 1, 1),
(32846, 47241, 100, 1, 0, 1, 1),
(32846, 47241, 100, 1, 0, 1, 1);

-- move loot from Freya's Gift (container) to boss Freya
DELETE FROM `gameobject_loot_template` WHERE `entry`=194324;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194324;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194325;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194325;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194326;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194326;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194327;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194327;
UPDATE `creature_template` SET `lootid` = 32906 WHERE `entry` = 32906;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32906, 45091, 0.3086, 1, 0, 1, 1),
(32906, 45095, 0.3449, 1, 0, 1, 1),
(32906, 45485, 1.3514, 1, 0, 1, 1),
(32906, 45486, 0.4194, 1, 0, 1, 1),
(32906, 45646, 100, 1, 0, -45646, 1),
(32906, 45788, -100, 1, 0, 1, 1),
(32906, 45934, 100, 1, 0, -45934, 1),
(32906, 45943, 100, 1, 0, -45943, 1),
(32906, 45947, 100, 1, 0, -45947, 1),
(32906, 46110, 75, 1, 0, 1, 1),
(32906, 47241, 100, 1, 0, 1, 1);
DELETE FROM `gameobject_loot_template` WHERE `entry`=194328;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194328;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194329;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194329;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194330;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194330;
DELETE FROM `gameobject_loot_template` WHERE `entry`=194331;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 194331;
UPDATE `creature_template` SET `lootid` = 33360 WHERE `entry` = 33360;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(33360, 45038, 20, 1, 0, 1, 1),
(33360, 45087, 50, 1, 0, 1, 2),
(33360, 45089, 5, 1, 0, -45089, 1),
(33360, 45479, 100, 1, 0, -45479, 1),
(33360, 45481, 100, 1, 0, -45481, 1),
(33360, 45488, 100, 1, 0, -45488, 1),
(33360, 45655, 100, 1, 0, -45655, 1),
(33360, 45814, -100, 1, 0, 1, 1),
(33360, 46110, 75, 1, 0, 1, 1),
(33360, 47241, 100, 1, 0, 1, 1);

-- move loot from Cache of Living Stone to boss Kologarn
DELETE FROM `gameobject_loot_template` WHERE `entry`=195046;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 195046;
UPDATE `creature_template` SET `lootid` = 32930 WHERE `entry` = 32930;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(32930, 45091, 0.1587, 1, 0, 1, 1),
(32930, 45095, 0.3042, 1, 0, 1, 1),
(32930, 45695, 0, 1, 1, 1, 1),
(32930, 45696, 0, 1, 1, 1, 1),
(32930, 45697, 0, 1, 2, 1, 1),
(32930, 45698, 0, 1, 2, 1, 1),
(32930, 45699, 0, 1, 2, 1, 1),
(32930, 45700, 0, 1, 1, 1, 1),
(32930, 45701, 0, 1, 1, 1, 1),
(32930, 45702, 0, 1, 2, 1, 1),
(32930, 45703, 0, 1, 2, 1, 1),
(32930, 45704, 0, 1, 1, 1, 1),
(32930, 47241, 100, 1, 0, 1, 1);
DELETE FROM `gameobject_loot_template` WHERE `entry`=195047;
UPDATE `gameobject_template` SET `data1` = 0 WHERE `entry` = 195047;
UPDATE `creature_template` SET `lootid` = 33909 WHERE `entry` = 33909;
REPLACE INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(33909, 45038, 10, 1, 0, 1, 1),
(33909, 45087, 33, 1, 0, 1, 1),
(33909, 45089, 5, 1, 0, -45089, 1),
(33909, 45261, 0, 1, 3, 1, 1),
(33909, 45262, 0, 1, 2, 1, 1),
(33909, 45263, 0, 1, 1, 1, 1),
(33909, 45264, 0, 1, 3, 1, 1),
(33909, 45265, 0, 1, 3, 1, 1),
(33909, 45266, 0, 1, 3, 1, 1),
(33909, 45267, 0, 1, 2, 1, 1),
(33909, 45268, 0, 1, 1, 1, 1),
(33909, 45269, 0, 1, 2, 1, 1),
(33909, 45270, 0, 1, 2, 1, 1),
(33909, 45271, 0, 1, 2, 1, 1),
(33909, 45272, 0, 1, 1, 1, 1),
(33909, 45273, 0, 1, 1, 1, 1),
(33909, 45274, 0, 1, 3, 1, 1),
(33909, 45275, 0, 1, 1, 1, 1),
(33909, 47241, 100, 1, 0, 1, 1);

-- Red Silk Bandana has High drop rate
-- http://eu.battle.net/wow/en/item/915
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-75 WHERE `entry`=594 and`item`=915; -- Defias Henchman
DELETE FROM `creature_loot_template` WHERE `entry` IN (48417,48418,48419,48420,48421,48521,48522) and `item`=915;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(48417,915,-75,1,0,1,1), -- Defias Blood Wizard
(48418,915,-75,1,0,1,1), -- Defias Envoker
(48419,915,-75,1,0,1,1), -- Defias Miner
(48420,915,-75,1,0,1,1), -- Defias Digger
(48421,915,-75,1,0,1,1), -- Defias Overseer
(48521,915,-75,1,0,1,1), -- Defias Squallshaper
(48522,915,-75,1,0,1,1); -- Defias Pirate
UPDATE `creature_template` SET `lootid`=48417 WHERE `entry`=48417;
UPDATE `creature_template` SET `lootid`=48418 WHERE `entry`=48418;
UPDATE `creature_template` SET `lootid`=48419 WHERE `entry`=48419;
UPDATE `creature_template` SET `lootid`=48420 WHERE `entry`=48420;
UPDATE `creature_template` SET `lootid`=48421 WHERE `entry`=48421;
UPDATE `creature_template` SET `lootid`=48521 WHERE `entry`=48521;
UPDATE `creature_template` SET `lootid`=48522 WHERE `entry`=48522;

-- Missing database loot entries for Mature Lasher
SET @lasher := 34300;
DELETE FROM `creature_loot_template` WHERE `entry`=@lasher;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@lasher,37704,100,1,0,1,3), -- Crystalised Life
(@lasher,43324,-75,1,0,1,1), -- Alliance Herb Pouch
(@lasher,44809,-75,1,0,1,1), -- Horde Herb Pouch
(@lasher,44774,80,1,0,1,1), -- Ice-Piercing Thorn
(@lasher,44775,20,1,0,1,1); -- Revolting Flower

-- Missing database harvest loot entries for Mature and Living Lasher
UPDATE `creature_template` SET `skinloot`=80007 WHERE `entry` IN (34300,30845);

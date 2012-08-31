-- New Battered Hilt Ref
DELETE FROM `reference_loot_template` WHERE `entry`=35075;
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(35075, 50379, 0, 1, 1, 1, 1), -- Alliance
(35075, 50380, 0, 1, 1, 1, 1); -- Horde
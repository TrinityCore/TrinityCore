-- Remove unused skinning_loot_template.
DELETE FROM `skinning_loot_template` WHERE `entry`=100015;
-- Spell effects without target types AREA/NEARBY/CONE so this conditions are useless. 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `sourcegroup`=1 AND `sourceentry` IN (43789,43891);
-- Must have the same loot as item 35348. In TDB it uses reference 11112 which is empty.
DELETE FROM `item_loot_template` WHERE `entry`=34863;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(34863,1,100,1,0,-11113,1),
(34863,2,60,1,0,-11116,1),
(34863,3,5,1,0,-11114,1),
(34863,4,60,1,0,-11115,1);

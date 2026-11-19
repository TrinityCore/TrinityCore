-- High Priest Venoxis
UPDATE `creature_template` SET `lootid` = 52155 WHERE `entry` = 52155;
 
DELETE FROM `creature_loot_template` WHERE `Entry` = 52155;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `LootMode`, `MinCount`, `MaxCount`) VALUES
(52155, 521550, 521550, 100, 1, 1, 1);
 
DELETE FROM `reference_loot_template` WHERE `Entry` = 521550;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(521550, 69600, 0, 1, 1, 1, 1), -- Belt of Slithering Serpents
(521550, 69603, 0, 1, 1, 1, 1), -- Breastplate of Serenity
(521550, 69604, 0, 1, 1, 1, 1), -- Coils of Hate
(521550, 69601, 0, 1, 1, 1, 1), -- Serpentine Leggings
(521550, 69602, 0, 1, 1, 1, 1); -- Signet of Venoxis
 
-- Bloodlord Mandokir
UPDATE `creature_template` SET `lootid` = 52151 WHERE `entry` = 52151;
 
DELETE FROM `creature_loot_template` WHERE `entry`= 52151;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `LootMode`, `MinCount`, `MaxCount`) VALUES
(52151, 521510, 521510, 100, 1, 1, 1);
 
DELETE FROM `reference_loot_template` WHERE `Entry` = 521510;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(521510, 69605, 0, 1, 1, 1, 1), -- Amulet of the Watcher
(521510, 69609, 0, 1, 1, 1, 1), -- Bloodlord's Protector
(521510, 69608, 0, 1, 1, 1, 1), -- Deathcharged Wristguards
(521510, 69606, 0, 1, 1, 1, 1), -- Hakkari Loa Drape
(521510, 69607, 0, 1, 1, 1, 1), -- Touch of Discord
(521510, 68823, 1, 1, 2, 1, 1); -- Amored Razzashi Raptor Mount

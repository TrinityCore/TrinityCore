SET @ITEM := 50406; -- Formula: Enchant Gloves - Angler
UPDATE `creature_template` SET `lootid` = `entry` WHERE `entry` IN(26343,26344,26336);
DELETE FROM `creature_loot_template` WHERE `item`=@ITEM;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(26343, @ITEM, 1.1, 1, 0, 1, 1), -- Indu'Le Fisherman
(26336, @ITEM, 0.9, 1, 0, 1, 1), -- Indu'Le Mystic
(26344, @ITEM, 1, 1, 0, 1, 1); -- Indu'Le Warrior

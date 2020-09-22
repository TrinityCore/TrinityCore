-- Lady Naz'jar
DELETE FROM `creature_loot_template` WHERE `Entry` IN (40586, 49080);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (40586, 49080);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `QuestRequired`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(40586, 0, 55202, 0, 0, 1, 1, 1),
(40586, 0, 55203, 0, 0, 1, 1, 1),
(40586, 0, 55195, 0, 0, 1, 1, 1),
(40586, 0, 55198, 0, 0, 1, 1, 1),
(40586, 0, 55201, 0, 0, 1, 1, 1),
-- 
(49080, 0, 56269, 0, 0, 1, 1, 1),
(49080, 0, 56266, 0, 0, 1, 1, 1),
(49080, 0, 56270, 0, 0, 1, 1, 1),
(49080, 0, 56268, 0, 0, 1, 1, 1),
(49080, 0, 56267, 0, 0, 1, 1, 1);

-- Commander Ulthok
DELETE FROM `creature_loot_template` WHERE `Entry` IN (40765, 49064);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (40765, 49064);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `QuestRequired`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(40765, 0, 55228, 0, 0, 1, 1, 1),
(40765, 0, 55204, 0, 0, 1, 1, 1),
(40765, 0, 55206, 0, 0, 1, 1, 1),
(40765, 0, 55205, 0, 0, 1, 1, 1),
(40765, 0, 55207, 0, 0, 1, 1, 1),
-- 
(49064, 0, 56273, 0, 0, 1, 1, 1),
(49064, 0, 56271, 0, 0, 1, 1, 1),
(49064, 0, 56274, 0, 0, 1, 1, 1),
(49064, 0, 56272, 0, 0, 1, 1, 1),
(49064, 0, 56275, 0, 0, 1, 1, 1);

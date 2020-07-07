-- Lady Naz'jar
DELETE FROM `creature_loot_template` WHERE `Entry` IN (40586, 49080);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (40586, 49080);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `QuestRequired`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(40586, 0, 55202, 100, 0, 1, 1, 1),
(40586, 0, 55203, 100, 0, 1, 1, 1),
(40586, 0, 55195, 100, 0, 1, 1, 1),
(40586, 0, 55198, 100, 0, 1, 1, 1),
(40586, 0, 55201, 100, 0, 1, 1, 1),
-- 
(49080, 0, 56269, 100, 0, 1, 1, 1),
(49080, 0, 56266, 100, 0, 1, 1, 1),
(49080, 0, 56270, 100, 0, 1, 1, 1),
(49080, 0, 56268, 100, 0, 1, 1, 1),
(49080, 0, 56267, 100, 0, 1, 1, 1);

-- Commander Ulthok
DELETE FROM `creature_loot_template` WHERE `Entry` IN (40765, 49064);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (40765, 49064);
INSERT INTO `creature_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `QuestRequired`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(40765, 0, 55228, 100, 0, 1, 1, 1),
(40765, 0, 55204, 100, 0, 1, 1, 1),
(40765, 0, 55206, 100, 0, 1, 1, 1),
(40765, 0, 55205, 100, 0, 1, 1, 1),
(40765, 0, 55207, 100, 0, 1, 1, 1),
-- 
(49064, 0, 56273, 100, 0, 1, 1, 1),
(49064, 0, 56271, 100, 0, 1, 1, 1),
(49064, 0, 56274, 100, 0, 1, 1, 1),
(49064, 0, 56272, 100, 0, 1, 1, 1),
(49064, 0, 56275, 100, 0, 1, 1, 1);

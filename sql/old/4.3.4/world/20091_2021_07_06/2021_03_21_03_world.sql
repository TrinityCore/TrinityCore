DELETE FROM `creature_template_addon` WHERE `entry`= 44223;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `emote`) VALUES
(44223, 1, 375);

UPDATE `creature_template` SET `exp`= 1 WHERE `entry`= 44223;
DELETE FROM `creature_loot_template` WHERE `Entry`= 11321 AND `Item`= 60499;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `MinCount`, `MaxCount`) VALUES
(11321, 60499, 100, 1, 1, 1, 1);

-- General Husam
UPDATE creature_template SET `difficulty_entry_1` = 48932, `lootid` = 44577 WHERE `entry` = 44577;
DELETE FROM `creature_loot_template` WHERE entry IN (44577, 48932);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(44577, 55858, 0, 1, 1, 1, 1),
(44577, 55857, 0, 1, 1, 1, 1),
(44577, 55856, 0, 1, 1, 1, 1),
(44577, 55859, 0, 1, 1, 1, 1),
(44577, 55860, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid` = 48932 WHERE `entry` = 48932;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48932, 56379, 0, 1, 1, 1, 1),
(48932, 56383, 0, 1, 1, 1, 1),
(48932, 56381, 0, 1, 1, 1, 1),
(48932, 56380, 0, 1, 1, 1, 1),
(48932, 56382, 0, 1, 1, 1, 1);

-- Siamat
DELETE FROM `creature_loot_template` WHERE `Entry` IN (44819, 51088);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (44819, 51088);
INSERT INTO `creature_loot_template` (`Entry`, `Chance`, `LootMode`, `Reference`, `MinCount`, `MaxCount`) VALUES
(44819, 100, 1, 448190, 2, 2);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(448190, 55872, 0, 1, 1, 1, 1),
(448190, 55876, 0, 1, 1, 1, 1),
(448190, 55878, 0, 1, 1, 1, 1),
(448190, 55877, 0, 1, 1, 1, 1),
(448190, 55871, 0, 1, 1, 1, 1),
(448190, 55873, 0, 1, 1, 1, 1),
(448190, 55874, 0, 1, 1, 1, 1),
(448190, 55879, 0, 1, 1, 1, 1),
(448190, 55875, 0, 1, 1, 1, 1),
(448190, 55880, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid`= 51088 WHERE `entry`= 51088;
INSERT INTO `creature_loot_template` (`Entry`, `Chance`, `LootMode`, `Reference`, `MinCount`, `MaxCount`) VALUES
(51088, 100, 1, 510880, 2, 2);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(510880, 56397, 0, 1, 1, 1, 1),
(510880, 56399, 0, 1, 1, 1, 1),
(510880, 56403, 0, 1, 1, 1, 1),
(510880, 56401, 0, 1, 1, 1, 1),
(510880, 56395, 0, 1, 1, 1, 1),
(510880, 56398, 0, 1, 1, 1, 1),
(510880, 56394, 0, 1, 1, 1, 1),
(510880, 56400, 0, 1, 1, 1, 1),
(510880, 56396, 0, 1, 1, 1, 1),
(510880, 56402, 0, 1, 1, 1, 1),
(510880, 52078, 100, 1, 2, 1, 1); -- Chaos Orb

-- Gold Loot
UPDATE `creature_template` SET `mingold`= 19800, `maxgold`= 19900 WHERE entry IN (44577, 48932, 43614, 49045, 43612, 48951, 44819, 51088);

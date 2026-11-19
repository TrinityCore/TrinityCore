-- 
-- Remove unique items from reference table 24076
DELETE FROM `reference_loot_template` WHERE `Item` IN (826, 1211, 1287, 1394, 1926, 1927, 1933, 2088, 4767, 4768, 4771);
-- Add former items from reference table 24076 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (826, 1211, 1287, 1394, 1926, 1927, 1933, 2088, 4767, 4768, 4771);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`) VALUES
(124, 826, 0.1, 0),
(423, 1211, 0.1, 0),
(442, 1287, 0.1, 0),
(171, 1394, 0.1, 0),
(824, 1926, 0.1, 0),
(594, 1927, 0.1, 0),
(619, 1933, 0.1, 0),
(831, 2088, 0.1, 0),
(3578, 4767, 3, 0),
(3270, 4768, 3, 2),
(3270, 4771, 3, 2);

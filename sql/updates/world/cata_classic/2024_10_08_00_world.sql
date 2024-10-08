SET @CGUID := 2990004;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 35507, 571, 4395, 4395, '0', 169, 0, 0, 1, 5758.39501953125, 745.38543701171875, 653.74774169921875, 4.276056766510009765, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713), -- Enchanter Isian (Area: Dalaran - Difficulty: 0) CreateObject1
(@CGUID+1, 35508, 571, 4395, 4616, '0', 169, 0, 0, 1, 5946.11962890625, 512.11114501953125, 650.26263427734375, 2.932153224945068359, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 56713); -- Enchanter Erodin (Area: Sunreaver's Sanctuary - Difficulty: 0) CreateObject1

DELETE FROM `npc_vendor` WHERE `entry` IN (35507, 35508, 32509);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(35508, 25, 42991, 0, 3319, 1, 0, 0, 56713), -- Swift Hand of Justice
(35508, 24, 42992, 0, 3319, 1, 0, 0, 56713), -- Discerning Eye of the Beast
(35508, 23, 69893, 0, 3318, 1, 0, 0, 56713), -- Bloodsoaked Skullforge Reaver
(35508, 22, 48716, 0, 3318, 1, 0, 0, 56713), -- Venerable Mass of McGowan
(35508, 21, 42945, 0, 3318, 1, 0, 0, 56713), -- Venerable Dal'Rend's Sacred Charge
(35508, 20, 48718, 0, 2551, 1, 0, 0, 56713), -- Repurposed Lava Dredger
(35508, 19, 42947, 0, 2551, 1, 0, 0, 56713), -- Dignified Headmaster's Charge
(35508, 18, 42948, 0, 3319, 1, 0, 0, 56713), -- Devout Aurastone Hammer
(35508, 17, 42946, 0, 2551, 1, 0, 0, 56713), -- Charmed Ancient Bone Bow
(35508, 16, 42943, 0, 2551, 1, 0, 0, 56713), -- Bloodied Arcanite Reaper
(35508, 15, 42944, 0, 3318, 1, 0, 0, 56713), -- Balanced Heartseeker
(35508, 14, 48691, 0, 3318, 1, 0, 0, 56713), -- Tattered Dreadmist Robe
(35508, 13, 42985, 0, 3318, 1, 0, 0, 56713), -- Tattered Dreadmist Mantle
(35508, 12, 48689, 0, 3318, 1, 0, 0, 56713), -- Stained Shadowcraft Tunic
(35508, 11, 42952, 0, 3318, 1, 0, 0, 56713), -- Stained Shadowcraft Spaulders
(35508, 10, 42984, 0, 3318, 1, 0, 0, 56713), -- Preened Ironfeather Shoulders
(35508, 9, 48687, 0, 3318, 1, 0, 0, 56713), -- Preened Ironfeather Breastplate
(35508, 8, 48683, 0, 3318, 1, 0, 0, 56713), -- Mystical Vest of Elements
(35508, 7, 42951, 0, 3318, 1, 0, 0, 56713), -- Mystical Pauldrons of Elements
(35508, 6, 48677, 0, 3318, 1, 0, 0, 56713), -- Champion's Deathdealer Breastplate
(35508, 5, 42950, 0, 3318, 1, 0, 0, 56713), -- Champion Herod's Shoulder
(35508, 4, 42949, 0, 3318, 1, 0, 0, 56713), -- Polished Spaulders of Valor
(35508, 3, 48685, 0, 3318, 1, 0, 0, 56713), -- Polished Breastplate of Valor
(35508, 2, 69890, 0, 3318, 1, 0, 0, 56713), -- Burnished Pauldrons of Might
(35508, 1, 69889, 0, 3318, 1, 0, 0, 56713), -- Burnished Breastplate of Might
(32509, 25, 42991, 0, 3319, 1, 0, 0, 56713), -- Swift Hand of Justice
(32509, 24, 42992, 0, 3319, 1, 0, 0, 56713), -- Discerning Eye of the Beast
(32509, 23, 69893, 0, 3318, 1, 0, 0, 56713), -- Bloodsoaked Skullforge Reaver
(32509, 22, 48716, 0, 3318, 1, 0, 0, 56713), -- Venerable Mass of McGowan
(32509, 21, 42945, 0, 3318, 1, 0, 0, 56713), -- Venerable Dal'Rend's Sacred Charge
(32509, 20, 48718, 0, 2551, 1, 0, 0, 56713), -- Repurposed Lava Dredger
(32509, 19, 42947, 0, 2551, 1, 0, 0, 56713), -- Dignified Headmaster's Charge
(32509, 18, 42948, 0, 3319, 1, 0, 0, 56713), -- Devout Aurastone Hammer
(32509, 17, 42946, 0, 2551, 1, 0, 0, 56713), -- Charmed Ancient Bone Bow
(32509, 16, 42943, 0, 2551, 1, 0, 0, 56713), -- Bloodied Arcanite Reaper
(32509, 15, 42944, 0, 3318, 1, 0, 0, 56713), -- Balanced Heartseeker
(32509, 14, 48691, 0, 3318, 1, 0, 0, 56713), -- Tattered Dreadmist Robe
(32509, 13, 42985, 0, 3318, 1, 0, 0, 56713), -- Tattered Dreadmist Mantle
(32509, 12, 48689, 0, 3318, 1, 0, 0, 56713), -- Stained Shadowcraft Tunic
(32509, 11, 42952, 0, 3318, 1, 0, 0, 56713), -- Stained Shadowcraft Spaulders
(32509, 10, 42984, 0, 3318, 1, 0, 0, 56713), -- Preened Ironfeather Shoulders
(32509, 9, 48687, 0, 3318, 1, 0, 0, 56713), -- Preened Ironfeather Breastplate
(32509, 8, 48683, 0, 3318, 1, 0, 0, 56713), -- Mystical Vest of Elements
(32509, 7, 42951, 0, 3318, 1, 0, 0, 56713), -- Mystical Pauldrons of Elements
(32509, 6, 48677, 0, 3318, 1, 0, 0, 56713), -- Champion's Deathdealer Breastplate
(32509, 5, 42950, 0, 3318, 1, 0, 0, 56713), -- Champion Herod's Shoulder
(32509, 4, 42949, 0, 3318, 1, 0, 0, 56713), -- Polished Spaulders of Valor
(32509, 3, 48685, 0, 3318, 1, 0, 0, 56713), -- Polished Breastplate of Valor
(32509, 2, 69890, 0, 3318, 1, 0, 0, 56713), -- Burnished Pauldrons of Might
(32509, 1, 69889, 0, 3318, 1, 0, 0, 56713), -- Burnished Breastplate of Might
(35507, 25, 42991, 0, 3319, 1, 0, 0, 56713), -- Swift Hand of Justice
(35507, 24, 42992, 0, 3319, 1, 0, 0, 56713), -- Discerning Eye of the Beast
(35507, 23, 69893, 0, 3318, 1, 0, 0, 56713), -- Bloodsoaked Skullforge Reaver
(35507, 22, 48716, 0, 3318, 1, 0, 0, 56713), -- Venerable Mass of McGowan
(35507, 21, 42945, 0, 3318, 1, 0, 0, 56713), -- Venerable Dal'Rend's Sacred Charge
(35507, 20, 48718, 0, 2551, 1, 0, 0, 56713), -- Repurposed Lava Dredger
(35507, 19, 42947, 0, 2551, 1, 0, 0, 56713), -- Dignified Headmaster's Charge
(35507, 18, 42948, 0, 3319, 1, 0, 0, 56713), -- Devout Aurastone Hammer
(35507, 17, 42946, 0, 2551, 1, 0, 0, 56713), -- Charmed Ancient Bone Bow
(35507, 16, 42943, 0, 2551, 1, 0, 0, 56713), -- Bloodied Arcanite Reaper
(35507, 15, 42944, 0, 3318, 1, 0, 0, 56713), -- Balanced Heartseeker
(35507, 14, 48691, 0, 3318, 1, 0, 0, 56713), -- Tattered Dreadmist Robe
(35507, 13, 42985, 0, 3318, 1, 0, 0, 56713), -- Tattered Dreadmist Mantle
(35507, 12, 48689, 0, 3318, 1, 0, 0, 56713), -- Stained Shadowcraft Tunic
(35507, 11, 42952, 0, 3318, 1, 0, 0, 56713), -- Stained Shadowcraft Spaulders
(35507, 10, 42984, 0, 3318, 1, 0, 0, 56713), -- Preened Ironfeather Shoulders
(35507, 9, 48687, 0, 3318, 1, 0, 0, 56713), -- Preened Ironfeather Breastplate
(35507, 8, 48683, 0, 3318, 1, 0, 0, 56713), -- Mystical Vest of Elements
(35507, 7, 42951, 0, 3318, 1, 0, 0, 56713), -- Mystical Pauldrons of Elements
(35507, 6, 48677, 0, 3318, 1, 0, 0, 56713), -- Champion's Deathdealer Breastplate
(35507, 5, 42950, 0, 3318, 1, 0, 0, 56713), -- Champion Herod's Shoulder
(35507, 4, 42949, 0, 3318, 1, 0, 0, 56713), -- Polished Spaulders of Valor
(35507, 3, 48685, 0, 3318, 1, 0, 0, 56713), -- Polished Breastplate of Valor
(35507, 2, 69890, 0, 3318, 1, 0, 0, 56713), -- Burnished Pauldrons of Might
(35507, 1, 69889, 0, 3318, 1, 0, 0, 56713); -- Burnished Breastplate of Might

-- Northern Barrens Fixes

-- NPC: 5837 Stonearm
-- NPC: 3295 Sludge Anomaly
-- NPC: 5841 Rocklance
-- NPC: 5828 Humar the Pridelord
-- NPC: 5835 Foreman Grills
-- NPC: 5836 Engineer Whirleygig
-- NPC: 3672 Boahn <Druid of the Fang>
-- NPC: 5831 Swiftmane
-- NPC: 3652 Trigore the Lasher
-- NPC: 3270 Elder Mystic Razorsnout
-- NPC: 38554 Dead Taurajo Refugee

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE Entry IN (5837,3295,5841,5828,5835,5836,3672,5831,3270) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (5837,3295,5841,5828,5835,5836,3672,5831,3270) AND `DifficultyID` = 1;

UPDATE creature_template_difficulty SET ContentTuningID = 3 WHERE Entry = 3652;

-- Template Fixes
UPDATE `creature_template` SET `unit_flags3` = 8193 WHERE `Entry` = 38554;

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `Entry` = 38554;
INSERT INTO `creature_template_addon` (`Entry`, `StandState`) VALUES
(38554, 7);

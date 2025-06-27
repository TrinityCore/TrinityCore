-- Update stats
-- In 5.3.0 level requirement was lowered from 70 to 68, levels of almost all creatures too were lowered
-- Levels in CreatureDifficulty just were lowered by 2
UPDATE `creature_template` SET `speed_walk` = 1, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20478; -- Arcane Servant
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 21521; -- Arcane Servant (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19510; -- Bloodwarder Centurion
UPDATE `creature_template` SET `minlevel` = 71, `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21522; -- Bloodwarder Centurion (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20990; -- Bloodwarder Physician
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21523; -- Bloodwarder Physician (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19167; -- Bloodwarder Slayer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21524; -- Bloodwarder Slayer (1)
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 19218; -- Gatewatcher Gyro-Kill
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.42857, `BaseAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 21525; -- Gatewatcher Gyro-Kill (1)
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 19710; -- Gatewatcher Iron-Hand
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.42857, `unit_flags` = 64 WHERE `entry` = 21526; -- Gatewatcher Iron-Hand (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 19231; -- Mechanar Crusher
UPDATE `creature_template` SET `speed_walk` = 0.944444, `speed_run` = 0.95238, `BaseAttackTime` = 2200, `unit_flags` = 64 WHERE `entry` = 21527; -- Mechanar Crusher (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 19712; -- Mechanar Driller
UPDATE `creature_template` SET `speed_walk` = 0.944444, `speed_run` = 0.95238, `BaseAttackTime` = 2200, `unit_flags` = 64 WHERE `entry` = 21528; -- Mechanar Driller (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000 WHERE `entry` = 19716; -- Mechanar Tinkerer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 21531; -- Mechanar Tinkerer (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 19713; -- Mechanar Wrecker
UPDATE `creature_template` SET `speed_walk` = 0.944444, `speed_run` = 0.95238, `BaseAttackTime` = 2200, `unit_flags` = 64 WHERE `entry` = 21532; -- Mechanar Wrecker (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 19219; -- Mechano-Lord Capacitus
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.42857, `BaseAttackTime` = 2000, `unit_flags` = 64 WHERE `entry` = 21533; -- Mechano-Lord Capacitus (1)
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `RangeAttackTime` = 2000, `unit_flags` = 33554432 WHERE `entry` = 20405; -- Nether Charge
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `BaseAttackTime` = 2000, `unit_flags` = 33554432 WHERE `entry` = 21534; -- Nether Charge (1)
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `speed_walk` = 1, `speed_run` = 0.85714, `RangeAttackTime` = 2000 WHERE `entry` = 21062; -- Nether Wraith
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `speed_walk` = 1, `speed_run` = 0.85714, `BaseAttackTime` = 2000 WHERE `entry` = 21535; -- Nether Wraith (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19221; -- Nethermancer Sepethrea
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21536; -- Nethermancer Sepethrea (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19220; -- Pathaleon the Calculator
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 1200, `unit_flags` = 32832 WHERE `entry` = 21537; -- Pathaleon the Calculator (1)
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 0.57142, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20481; -- Raging Flames
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 0.57142, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 21538; -- Raging Flames (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19168; -- Sunseeker Astromage
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21539; -- Sunseeker Astromage (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20988; -- Sunseeker Engineer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21540; -- Sunseeker Engineer (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20059; -- Sunseeker Netherbinder
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21541; -- Sunseeker Netherbinder (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19735; -- Tempest-Forge Destroyer
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21542; -- Tempest-Forge Destroyer (1)
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19166; -- Tempest-Forge Patroller
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 21543; -- Tempest-Forge Patroller (1)

-- Update equipment
DELETE FROM `creature_equip_template` WHERE
(`ID` BETWEEN 2 AND 5 AND `CreatureID` = 19510) OR (`ID` BETWEEN 2 AND 5 AND `CreatureID` = 19167) OR (`ID` = 2 AND `CreatureID` = 19220);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
-- All used in scripts only, default equipment is already set
(19510, 2, 29403, 24328, 0, 14545), -- 19510
(19510, 3, 29404, 24328, 0, 14545), -- 19510
(19510, 4, 29405, 24328, 0, 14545), -- 19510
(19510, 5, 29406, 24328, 0, 14545), -- 19510
(19167, 2, 29407, 0, 0, 14545), -- 19167
(19167, 3, 29408, 0, 0, 14545), -- 19167
(19167, 4, 29409, 0, 0,     0), -- 19167
(19167, 5, 29410, 0, 0, 14545), -- 19167
(19220, 2, 29455, 0, 0, 14545); -- 19220

-- Update model info
UPDATE `creature_model_info` SET `CombatReach` = 5.25 WHERE `DisplayID` = 18662;
UPDATE `creature_model_info` SET `CombatReach` = 6 WHERE `DisplayID` = 19165;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.765, `CombatReach` = 3 WHERE `DisplayID` = 20033;

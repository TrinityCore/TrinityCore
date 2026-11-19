-- 
SET @CGUID := 1050144;

DELETE FROM `creature` WHERE `guid` IN(@CGUID+0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 178908, 2222, 10565, 13499, '0', 17339, 0, 0, 0, -1789.6458740234375, 1124.9271240234375, 5271.64208984375, 5.499353885650634765, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40906); -- Al'dalil (Area: Ring of Fates - Difficulty: 0)

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (178908));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178908, 0, 0, 0, 783, 40906);

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048, `VerifiedBuild`=40906 WHERE `entry`=178908; -- Al'dalil
UPDATE `creature_template_model` SET `VerifiedBuild`=40906 WHERE (`CreatureID`=178908 AND `Idx`=0); -- Al'dalil
UPDATE `creature_template_scaling` SET `VerifiedBuild`=40906 WHERE (`Entry`=156688 AND `DifficultyID`=0);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (101478);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(101478, 1.888888955116271972, 2, 0, 40906);

DELETE FROM `creature_template_addon` WHERE `entry`=178908;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(178908, 0, 0, 0, 1, 720, 0, 0, 0, '');

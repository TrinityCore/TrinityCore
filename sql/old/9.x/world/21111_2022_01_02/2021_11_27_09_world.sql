-- 
SET @CGUID := 850184;

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 134976, 1642, 8500, 8942, '0', 10613, 0, 0, 0, 1693.6458740234375, 93.3506927490234375, -0.05085717886686325, 1.774286270141601562, 120, 0, 0, 114475, 0, 0, 0, 0, 0, 41079); -- Krag'wa the Huge (Area: Zal'amak - Difficulty: 0)

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (134976));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(134976, 0, 1, 1, 805, 41079);

UPDATE `gossip_menu` SET `VerifiedBuild`=41079 WHERE (`MenuId`=22338 AND `TextId`=34297);
UPDATE `npc_text` SET `VerifiedBuild`=41079 WHERE `ID`=34297;
UPDATE `gossip_menu_option` SET `VerifiedBuild`=41079 WHERE (`MenuId`=22338 AND `OptionIndex`=0);

UPDATE `creature_template` SET `minlevel`=51, `maxlevel`=51, `VerifiedBuild`=41079 WHERE `entry`=134976; -- Krag'wa the Huge
UPDATE `creature_template_model` SET `VerifiedBuild`=41079 WHERE (`Idx`=0 AND `CreatureID`=134976);
UPDATE `creature_model_info` SET `VerifiedBuild`=41079 WHERE `DisplayID`=77323;

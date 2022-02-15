-- 
SET @CGUID := 1050143;

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 158653, 2222, 10413, 12917, '0', 14496, 0, 0, 0, -1891.49658203125, 7650.267578125, 4193.98095703125, 2.196262121200561523, 120, 0, 0, 117910, 2434, 0, 0, 0, 0, 40443); -- Prince Renathal (Area: Sinfall - Difficulty: 0)

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=158653; -- Prince Renathal
UPDATE `creature_template` SET `VerifiedBuild`=40443 WHERE `entry`=158653; -- Prince Renathal
UPDATE `creature_template_model` SET `VerifiedBuild`=40443 WHERE (`CreatureID`=158653 AND `Idx`=0); -- Prince Renathal
UPDATE `creature_model_info` SET `VerifiedBuild`=40443 WHERE `DisplayID`=94910;

DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry`=158653;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(158653, 0, 0, 0, 837, 40443);

UPDATE `creature_template` SET `gossip_menu_id`=25001 WHERE `entry`=158653; -- Prince Renathal
UPDATE `npc_text` SET `VerifiedBuild`=40725 WHERE `ID`=39418; -- 39418

DELETE FROM `gossip_menu` WHERE (`MenuId`=25001 AND `TextId`=39418);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25001, 39418, 40725); -- 158653 (Prince Renathal)

DELETE FROM `phase_area` WHERE `AreaId`=12917 AND `PhaseId`=14496;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(12917, 14496, 'Cosmetic: Venthyr Covenant Sanctum - Prince Renathal');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND `SourceGroup`=14496 AND `SourceEntry`=12917;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 14496, 12917, 0, 0, 8, 0, 59321, 0, 0, 0, 'Allow phase 14986 if quest state of Sacred Covenant (59321) is rewarded');

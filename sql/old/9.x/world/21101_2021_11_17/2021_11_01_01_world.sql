-- 
SET @CGUID := 850007;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 35594, 1643, 8717, 8718, '0', 12240, 0, 0, 0, 1167.0086669921875, -653.15106201171875, 29.13440704345703125, 2.342009305953979492, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 40725), -- Brassbolt Mechawrench (Area: Tradewinds Market - Difficulty: 0)
(@CGUID+1, 35607, 1642, 8499, 8670, '0', 12241, 0, 0, 0, -1016.76910400390625, 944.9375, 323.511016845703125, 2.361545324325561523, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 40725); -- Reginald Arcfire (Area: Dazar'alor - Difficulty: 0)

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN(35594, 35607));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(35594, 0, 0, 0, 196, 40725),
(35607, 0, 0, 0, 196, 40725);

DELETE FROM `phase_area` WHERE (`AreaId`=8717 AND `PhaseId`=12240) OR (`AreaId`=8670 AND `PhaseId`=12241);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8717, 12240, 'Cosmetic: Boralus - Engineering Auction House'),
(8670, 12241, 'Cosmetic: Dazaralor - Engineering Auction House');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12240, 12241));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 12240, 0, 0, 0, 7, 0, 2506, 1, 0, 0, 'Player has at least value 1 for skill 2506'),
(26, 12240, 0, 0, 0, 6, 0, 469, 0, 0, 0, 'Player belongs to Alliance'),
(26, 12241, 0, 0, 0, 7, 0, 2506, 1, 0, 0, 'Player has at least value 1 for skill 2506'),
(26, 12241, 0, 0, 0, 6, 0, 67, 0, 0, 0, 'Player belongs to Horde');

UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=35594; -- 35594 (Brassbolt Mechawrench)
UPDATE `creature_template` SET `gossip_menu_id`=0, `VerifiedBuild`=40725 WHERE `entry`=35594; -- Brassbolt Mechawrench
UPDATE `creature_template_model` SET `VerifiedBuild`=40725 WHERE (`CreatureID`=35594 AND `Idx`=0); -- Brassbolt Mechawrench
UPDATE `creature_model_info` SET `VerifiedBuild`=40725 WHERE `DisplayID`=28282;

UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=35607; -- 35607 (Reginald Arcfire)
UPDATE `creature_template` SET `gossip_menu_id`=0, `VerifiedBuild`=40725 WHERE `entry`=35607; -- Reginald Arcfire
UPDATE `creature_template_model` SET `VerifiedBuild`=40725 WHERE (`CreatureID`=35607 AND `Idx`=0); -- Reginald Arcfire
UPDATE `creature_model_info` SET `VerifiedBuild`=40725 WHERE `DisplayID`=28282;

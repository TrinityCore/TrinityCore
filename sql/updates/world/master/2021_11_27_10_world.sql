-- 
SET @CGUID := 850185;

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 144181, 0, 1519, 9171, '0', 11955, 0, 0, 0, -8180.82666015625, 807.92535400390625, 74.4301910400390625, 2.608142375946044921, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 40725); -- Mole Machine to Shadowforge City (Area: Stormwind Embassy - Difficulty: 0) (Auras: )

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16777216, `speed_walk`=2, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=16384, `unit_flags2`=100352, `VehicleId`=6257, `VerifiedBuild`=40725 WHERE `entry`=144181; -- Mole Machine to Shadowforge City
UPDATE `creature_template_model` SET `VerifiedBuild`=40725 WHERE (`CreatureID`=144181 AND `Idx`=0); -- Mole Machine to Shadowforge City
UPDATE `creature_model_info` SET `VerifiedBuild`=40725 WHERE `DisplayID`=80349;

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (144181));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(144181, 0, 0, 0, 674, 40725);

DELETE FROM `phase_area` WHERE `AreaId`=1519 AND `PhaseId`=11955;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 11955, 'Cosmetic: Dark Iron Dwarf Mole Machine in Stormwind');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup`=11955 AND `SourceEntry`=1519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 11955, 1519, 0, 0, 16, 0, 0x800, 0, 0, 0, 'Player is race Dark Iron Dwarf');

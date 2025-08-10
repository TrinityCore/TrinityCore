SET @CGUID := 1051924;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 161666, 2175, 10424, 10529, '0', 15017, 0, 0, 1, 187.6006927490234375, -2290.87841796875, 81.6041259765625, 0.230253174901008605, 120, 0, 0, 95, 382, 0, 0, 0, 0, 46924); -- Austin Huxworth (Area: Ogre Ruins - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 214, 0, 0, 0, 0, ''); -- Austin Huxworth

UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=164989; -- Austin Huxworth
UPDATE `creature_template` SET `gossip_menu_id`=24886, `minlevel`=10, `maxlevel`=10, `faction`=35, `npcflag`=4194307, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=161666; -- Austin Huxworth

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 15017;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(15017, 'Cosmetic - See Austin Huxworth at Alliance Populated Camp');

DELETE FROM `phase_area` WHERE `AreaId` = 10424 AND `PhaseId` = 15017;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(10424, 15017, 'Cosmetic - See Austin Huxworth at Alliance Populated Camp');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 15017 AND `SourceEntry` = 10424);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 15017, 10424, 0, 0, 47, 0, 55879, 64, 0, 0, 'Apply Phase 15017 if Quest 55879 is rewarded');

-- Equip Template
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=164989 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(164989, 1, 0, 0, 0, 0, 0, 0, 110178, 0, 0, 46924); -- Austin Huxworth

-- Scaling Data
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (164990,164989,164986));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(164990, 0, 0, 0, 482, 46924),
(164989, 0, 0, 0, 741, 46924),
(164986, 0, 0, 0, 741, 46924);

-- Spawngroup
DELETE FROM `spawn_group` WHERE `groupId` = 128 AND `spawnId` = @CGUID+0;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(128, 0, @CGUID+0);

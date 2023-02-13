SET @CGUID := 1250040;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 197274, 0, 10, 42, '0', 0, 0, 0, 1, -10541.248046875, -1150.6944580078125, 27.97782325744628906, 2.251291990280151367, 120, 0, 0, 2035, 100, 0, 0, 0, 0, 46702); -- Dregoth (Area: Darkshire - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry`=197274;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(197274, 0, 0, 0, 0, 720, 0, 0, 0, 0, ''); -- 197274 (Dregoth)

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=197274 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(197274, 1, 45165, 0, 0, 0, 0, 0, 0, 0, 0, 46702); -- Dregoth

UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction`=12, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=197274; -- Dregoth

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`Entry`=197274 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(197274, 0, 0, 0, 13, 46702);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46702 WHERE (`DifficultyID`=0 AND `Entry` IN (1672,664,3137,633,661,887,225,3138,2110,826,49673,1673,663,2668,265,24110,886,5464,2669,44022,11040,226,273,3136,468,6790,325,268,272,270,271,267,269,2112,263,2470,274,17104,495,4076,10062,576,264,227,494,228,960));

DELETE FROM `creature_model_info` WHERE `DisplayID`=109488;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(109488, 0.305999994277954101, 1.5, 0, 46702);

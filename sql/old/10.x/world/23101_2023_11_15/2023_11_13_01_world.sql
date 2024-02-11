SET @CGUID := 9004105;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 211051, 0, 1519, 5390, '0', 0, 0, 0, 0, -8826.216796875, 840.52606201171875, 99.5051422119140625, 5.998556137084960937, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 52106); -- Kerbjorn (Area: The Canals - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=211051; -- Kerbjorn

-- Difficulty & Model
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=211051 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(211051, 0, 0, 0, 864, 9, 1, 1, 260400, 0, 0, 52106); -- Kerbjorn

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52106 WHERE (`DifficultyID`=0 AND `Entry` IN (198482,1312,185468,42288,185467,198529,49701,198589,5494,5493,152643,201312,198581,42339,52031,11068,197287,1318,30713,1317,185672,198579,1316,185670,49893,1315,185669,93223,30730,133509,46180,5386,68,183978,199602,338));

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (114299, 105301);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(114299, 0.347000002861022949, 1.5, 0, 52106),
(105301, 0.349482834339141845, 0.25, 0, 52106);

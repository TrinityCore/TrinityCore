SET @CGUID := 9004106;
SET @OGUID := 9003863;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 216439, 0, 1519, 10523, '0', 0, 0, 0, 0, -9119.3369140625, 968.26739501953125, 73.12485504150390625, 2.944386720657348632, 120, 0, 0, 6099, 3801, 0, NULL, NULL, NULL, NULL, 53162), -- Bel'ameth Mage (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1 (Auras: 287193 - Azsuna Portal Channel)
(@CGUID+1, 216439, 0, 1519, 10523, '0', 0, 0, 0, 0, -9125.4150390625, 963.73089599609375, 73.12451934814453125, 1.798837065696716308, 120, 0, 0, 6099, 3801, 0, NULL, NULL, NULL, NULL, 53162); -- Bel'ameth Mage (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1 (Auras: 287193 - Azsuna Portal Channel)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 421496, 0, 1519, 10523, '0', 0, 0, -9125.9990234375, 971.2142333984375, 74.318328857421875, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 53162); -- Portal to Bel'ameth (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503); -- Portal to Bel'ameth

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 216439;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(216439, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, '287193'); -- 216439 (Bel'ameth Mage) - Azsuna Portal Channel

DELETE FROM `gameobject_template_addon` WHERE `entry`=421496;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(421496, 1732, 0, 0, 3503); -- Portal to Bel'ameth

-- Template
DELETE FROM `gameobject_template` WHERE `entry`=421496;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(421496, 22, 87382, 'Portal to Bel\'ameth', '', '', '', 0.999999761581420898, 433911, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 53162); -- Portal to Bel'ameth

-- Model & Difficulty
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=53162 WHERE (`DifficultyID`=0 AND `Entry` IN (111190,5497,2485,151937,52408,148233,149099,147785,198096,149121,149445,32520,148796,103033,173545,331));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=488, `VerifiedBuild`=53162 WHERE (`Entry`=216439 AND `DifficultyID`=0); -- Bel'ameth Mage

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (116639, 116640);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(116639, 0.388999998569488525, 1.5, 0, 53162),
(116640, 0.305999994277954101, 1.5, 0, 53162);

UPDATE `creature_model_info` SET `VerifiedBuild`=53162 WHERE `DisplayID` IN (89786, 89930, 3292, 89932, 104198, 99430, 90344, 11686, 37874, 25375, 89931, 26069, 89785, 104187, 90104, 90343, 21342, 89933, 16910, 25777, 1484);

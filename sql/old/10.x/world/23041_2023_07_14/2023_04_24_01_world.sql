SET @DF_CGUID := 9003508;
SET @SL_CGUID := 1051930;
SET @BFA_CGUID := 850878;
SET @MOP_CGUID := 397099;

-- Creature (Dragonflight)
DELETE FROM `creature` WHERE `guid` BETWEEN @DF_CGUID+0 AND @DF_CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@DF_CGUID+0, 68, 0, 1519, 5148, '0', 0, 0, 0, 1, -8824.2607421875, 608.84893798828125, 95.21520233154296875, 6.018694877624511718, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48999), -- Stormwind City Guard (Area: Trade District - Difficulty: 0) CreateObject1 (Auras: )
(@DF_CGUID+1, 68, 0, 1519, 5148, '0', 0, 0, 0, 1, -8822.5, 607.9444580078125, 95.52862548828125, 2.22620391845703125, 120, 0, 0, 169379, 0, 0, 0, 0, 0, 48999); -- Stormwind City Guard (Area: Trade District - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @DF_CGUID+0 AND @DF_CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@DF_CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Stormwind City Guard
(@DF_CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Stormwind City Guard

-- Creature (Shadowlands)
DELETE FROM `creature` WHERE `guid` BETWEEN @SL_CGUID+0 AND @SL_CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@SL_CGUID+0, 175416, 0, 1519, 5148, '0', 0, 0, 0, 0, -8790.6181640625, 693.607666015625, 102.415252685546875, 4.17626190185546875, 120, 0, 0, 124211, 0, 0, 0, 0, 0, 48999), -- Miggi (Area: Trade District - Difficulty: 0) CreateObject1
(@SL_CGUID+1, 175420, 0, 1519, 5148, '0', 0, 0, 0, 0, -8789.2744140625, 693.34552001953125, 102.4373626708984375, 3.584607124328613281, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999), -- Mangeclaw (Area: Trade District - Difficulty: 0) CreateObject1 (Auras: 266099 - Cosmetic - Sleep Zzz)
(@SL_CGUID+2, 179896, 0, 1519, 5148, '0', 0, 0, 0, 0, -8758.4111328125, 652.02606201171875, 104.3722991943359375, 3.906674623489379882, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48999); -- Finn (Area: Trade District - Difficulty: 0) CreateObject1

-- Creature (Battle for Azeroth)
DELETE FROM `creature` WHERE `guid` BETWEEN @BFA_CGUID+0 AND @BFA_CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@BFA_CGUID+0, 140253, 0, 1519, 5148, '0', 11595, 0, 0, 0, -8847.5087890625, 547.97222900390625, 97.18389892578125, 0.448394298553466796, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Trade District - Difficulty: 0) CreateObject1
(@BFA_CGUID+1, 140253, 0, 1519, 5148, '0', 11595, 0, 0, 0, -8907.6025390625, 621.65106201171875, 99.60980224609375, 2.419799327850341796, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Trade District - Difficulty: 0) CreateObject1
(@BFA_CGUID+2, 140253, 0, 1519, 5148, '0', 11595, 0, 0, 0, -8847.7587890625, 549.6163330078125, 97.0777587890625, 5.656514644622802734, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Trade District - Difficulty: 0) CreateObject1
(@BFA_CGUID+3, 140253, 0, 1519, 5148, '0', 11595, 0, 0, 0, -8908.9482421875, 622.732666015625, 99.610015869140625, 5.622133255004882812, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999); -- Darnassian Refugee (Area: Trade District - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @BFA_CGUID+0 AND @BFA_CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@BFA_CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@BFA_CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''); -- Darnassian Refugee

-- Creature (Mists of Pandaria)
DELETE FROM `creature` WHERE `guid` BETWEEN @MOP_CGUID+0 AND @MOP_CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@MOP_CGUID+0, 61896, 0, 1519, 5148, '0', 0, 0, 0, 0, -8907.1337890625, 552.16839599609375, 94.367950439453125, 4.079800605773925781, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999), -- Josie (Area: Trade District - Difficulty: 0) CreateObject1
(@MOP_CGUID+1, 61895, 0, 1519, 5148, '0', 0, 0, 0, 0, -8908.3125, 550.623291015625, 94.46007537841796875, 0.706794440746307373, 120, 0, 0, 85, 0, 0, 0, 0, 0, 48999); -- Marty (Area: Trade District - Difficulty: 0) CreateObject1

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 175420;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(175420, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '266099'); -- 175420 (Mangeclaw) - Cosmetic - Sleep Zzz

UPDATE `creature_template_addon` SET `mount`=28912 WHERE `entry`=49877; -- 49877 (Captain Lancy Revshon)

-- SAI
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@DF_CGUID+0), -(@DF_CGUID+1), -(@BFA_CGUID+1), -(@BFA_CGUID+3));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@DF_CGUID+0), 0, 0, 0, 1, 0, 100, 0, 5000, 8000, 5000, 8000, 10, 273, 6, 274, 11, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC every 5-8s - do random Emote - to self'),
(-(@DF_CGUID+1), 0, 0, 0, 1, 0, 100, 0, 5000, 8000, 5000, 8000, 10, 273, 6, 274, 11, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC every 5-8s - do random Emote - to self'),
(-(@BFA_CGUID+1), 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 3000, 5000, 10, 25, 6, 603, 273, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC every 3-5s - do random Emote - to self'),
(-(@BFA_CGUID+3), 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 3000, 5000, 10, 1, 25, 6, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC every 3-5s - do random Emote - to self');

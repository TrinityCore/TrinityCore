SET @DF_CGUID := 9003520;

SET @BFA_CGUID := 850928;

-- Creature (Dragonflight)
DELETE FROM `creature` WHERE `guid` BETWEEN @DF_CGUID+0 AND @DF_CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@DF_CGUID+0, 197267, 0, 1519, 5150, '0', 0, 0, 0, 0, -8387.6162109375, 666.25177001953125, 95.39621734619140625, 2.397474050521850585, 120, 0, 0, 112919, 100, 0, 0, 0, 0, 48999), -- Riley Tidy (Area: Dwarven District - Difficulty: 0) CreateObject1 (Auras: 390427 - Breakable WAHammer 01)
(@DF_CGUID+1, 197253, 0, 1519, 5150, '0', 0, 0, 0, 0, -8387.09375, 669.20489501953125, 96.47650146484375, 4.155570030212402343, 120, 0, 0, 112919, 100, 0, 0, 0, 0, 48999), -- "Lefty" Lucy (Area: Dwarven District - Difficulty: 0) CreateObject1
(@DF_CGUID+2, 197269, 0, 1519, 5150, '0', 0, 0, 0, 0, -8388.8720703125, 667.15277099609375, 95.37870025634765625, 0, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48999); -- Toy Tank (Area: Dwarven District - Difficulty: 0) CreateObject1

-- Creature (Battle for Azeroth)
DELETE FROM `creature` WHERE `guid` BETWEEN @BFA_CGUID+0 AND @BFA_CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@BFA_CGUID+0, 140407, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8388.1611328125, 624.0242919921875, 95.39727783203125, 3.9364013671875, 120, 0, 0, 17621, 0, 0, 0, 0, 0, 48999), -- Stormwind City Clerk (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+1, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8359.654296875, 666.609375, 97.23799896240234375, 0.162257343530654907, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+2, 140403, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8389.5400390625, 621.54168701171875, 95.4215240478515625, 0.904929339885711669, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Displaced Gilnean Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+3, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8331.7080078125, 636.967041015625, 95.6412811279296875, 3.299002408981323242, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+4, 140403, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8387.17578125, 621.7413330078125, 95.44271087646484375, 1.890208244323730468, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Displaced Gilnean Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+5, 140403, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8391.001953125, 625.62847900390625, 95.376739501953125, 5.785946369171142578, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Displaced Gilnean Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+6, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8430.7451171875, 661.1627197265625, 93.89919281005859375, 0.588002622127532958, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+7, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8333.0673828125, 635.76214599609375, 95.719482421875, 1.657125830650329589, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+8, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8357.9599609375, 666.93231201171875, 97.23799896240234375, 3.400092124938964843, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+9, 140403, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8392.6962890625, 624.21356201171875, 95.4002227783203125, 6.235099315643310546, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Displaced Gilnean Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+10, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8390.326171875, 623.67706298828125, 95.40625, 0.230352774262428283, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+11, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8388.6611328125, 619.875, 95.42708587646484375, 1.446156620979309082, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
(@BFA_CGUID+12, 140253, 0, 1519, 5150, '0', 11595, 0, 0, 0, -8332.6630859375, 638.0867919921875, 95.79345703125, 3.712284564971923828, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999); -- Darnassian Refugee (Area: Dwarven District - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @BFA_CGUID+0 AND @BFA_CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@BFA_CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Stormwind City Clerk
(@BFA_CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@BFA_CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@BFA_CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''); -- Darnassian Refugee

-- Creature Template
UPDATE `creature_template` SET `faction`=12, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=197253; -- "Lefty" Lucy
UPDATE `creature_template` SET `faction`=12, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=197267; -- Riley Tidy
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=335546368, `unit_flags3`=32768 WHERE `entry`=197269; -- Toy Tank

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (197269, 197253, 197267);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(197269, 0, 0, 0, 0, 0, 1, 0, 0, 1421, 0, 0, 0, ''), -- 197269 (Toy Tank)
(197253, 0, 0, 0, 0, 0, 1, 0, 732, 0, 0, 0, 0, ''), -- "Lefty" Lucy
(197267, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '390427'); -- 197267 (Riley Tidy) - Breakable WAHammer 01

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`Entry`=80329 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(80329, 0, 0, 0, 371, 48999);

-- Waypoints for CGUID+6
SET @PATH := ((@BFA_CGUID+6) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8381.748, 641.8195, 94.9442, NULL, 0),
(@PATH, 1, -8375.254, 629.4063, 95.16992, NULL, 0),
(@PATH, 2, -8378.219, 620.7882, 95.3291, NULL, 0),
(@PATH, 3, -8387.56, 615.7344, 95.31641, NULL, 0),
(@PATH, 4, -8395.344, 602.6198, 94.26697, NULL, 0),
(@PATH, 5, -8398.103, 586.3073, 92.67611, NULL, 0),
(@PATH, 6, -8402.248, 575.2136, 91.88956, NULL, 0),
(@PATH, 7, -8411.781, 570.5903, 92.40152, NULL, 0),
(@PATH, 8, -8422.063, 570.0504, 93.51981, NULL, 0),
(@PATH, 9, -8430.297, 572.4271, 94.38309, NULL, 0),
(@PATH, 10, -8444.821, 585.5573, 94.56425, NULL, 0),
(@PATH, 11, -8453.643, 594.6389, 94.32915, NULL, 0),
(@PATH, 12, -8465.841, 607.5434, 94.79446, NULL, 0),
(@PATH, 13, -8471.234, 614.3386, 94.71692, NULL, 0),
(@PATH, 14, -8473.783, 618.6893, 94.73132, NULL, 0),
(@PATH, 15, -8474.802, 625.3993, 94.02014, NULL, 0),
(@PATH, 16, -8468.014, 633.3698, 93.00346, NULL, 0),
(@PATH, 17, -8454.573, 642.5364, 92.08357, NULL, 0),
(@PATH, 18, -8441.085, 653.0868, 93.12044, NULL, 0),
(@PATH, 19, -8432.029, 660.3073, 93.59958, NULL, 0),
(@PATH, 20, -8422.004, 666.9739, 94.7771, NULL, 0),
(@PATH, 21, -8412.899, 671.8785, 95.1521, NULL, 0),
(@PATH, 22, -8405.596, 671.4913, 95.2771, NULL, 0),
(@PATH, 23, -8396.426, 666.6858, 94.84495, NULL, 0),
(@PATH, 24, -8389.958, 655.7396, 95.23558, NULL, 0);

UPDATE `creature` SET `position_x`= -8381.748, `position_y`= 641.8195, `position_z`= 94.9442, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @BFA_CGUID+6;
DELETE FROM `creature_addon` WHERE `guid`= @BFA_CGUID+6;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@BFA_CGUID+6, @PATH, 1);

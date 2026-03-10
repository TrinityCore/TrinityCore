SET @CGUID := 7003691;
SET @OGUID := 7000697;
SET @SPAWN_GROUP := 1271;
SET @AT_ID := 168;
SET @AT_PROP_ID := 162;
SET @AT_SPAWN_ID = 265;

SET @AT_RADIUS := 53;
SET @AT_HEIGHT := 25;

DELETE FROM `areatrigger_template` WHERE `Id` = @AT_ID AND `IsCustom` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`) VALUES
(@AT_ID, 1);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = @AT_PROP_ID AND `IsCustom` = 1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`) VALUES
(@AT_PROP_ID, 1, @AT_ID, 1, 4, @AT_RADIUS, @AT_RADIUS, @AT_HEIGHT, @AT_HEIGHT, 0 /*LocationZOffset*/, 0 /*LocationZOffsetTarget*/, 0, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = @AT_ID AND `IsCustom` = 1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@AT_ID, 1, 0, 307005, 0); -- Arena Inbounds Area Marker

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @AT_SPAWN_ID+0 AND @AT_SPAWN_ID+1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `Comment`) VALUES
(@AT_SPAWN_ID+0, @AT_PROP_ID, 1, 2167, -281.619598, -278.841583, 70.442131, 0, 'The Robodrome Inbounds');

DELETE FROM `battleground_scripts` WHERE `MapId` = 2167 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(2167, 0, 'arena_the_robodrome'); -- The Robodrome

DELETE FROM `battleground_template` WHERE `ID` = 1025;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(1025, 7208, 7209, 0, 1, 'The Robodrome');

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (329743 /*Doodad_8XP_MECHAGONARENA_PVPDOOR002*/, 329742 /*Doodad_8XP_MECHAGONARENA_PVPDOOR001*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(329743, 1375, 0x20, 0, 0), -- Doodad_8XP_MECHAGONARENA_PVPDOOR002
(329742, 1375, 0x20, 0, 0); -- Doodad_8XP_MECHAGONARENA_PVPDOOR001

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 329742, 2167, 10497, 10497, '0', '0', 0, -206.134368896484375, -279.045745849609375, 90.6704559326171875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Doodad_8XP_MECHAGONARENA_PVPDOOR001 (Area: The Robodrome - Difficulty: 0) CreateObject1
(@OGUID+1, 329743, 2167, 10497, 10497, '0', '0', 0, -356.5426025390625, -279.0457763671875, 90.6704559326171875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Doodad_8XP_MECHAGONARENA_PVPDOOR002 (Area: The Robodrome - Difficulty: 0) CreateObject1
(@OGUID+2, 184664, 2167, 10497, 10497, '0', '0', 0, -274.296875, -229.8125, 70.89987945556640625, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 360, 255, 1, 63305), -- Shadow Sight (Area: The Robodrome - Difficulty: 0) CreateObject2
(@OGUID+3, 184663, 2167, 10497, 10497, '0', '0', 0, -303.149322509765625, -322.75, 70.8999176025390625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305); -- Shadow Sight (Area: The Robodrome - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8XP_MECHAGONARENA_PVPDOOR001
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0); -- Doodad_8XP_MECHAGONARENA_PVPDOOR002

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 154584, 2167, 10497, 10497, '0', '0', 0, 0, 0, -279.16064453125, -285.21630859375, 70.90320587158203125, 1.714475393295288085, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Mechagon - Critters (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+1, 151328, 2167, 10497, 10497, '0', '0', 0, 0, 0, -202.092010498046875, -275.758697509765625, 87.35225677490234375, 6.244936943054199218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Alarm-o-Bot (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+2, 154573, 2167, 10497, 10497, '0', '0', 0, 0, 0, -275.10882568359375, -280.9892578125, 70.91278839111328125, 4.349936485290527343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Rustbolt Spraybot (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+3, 154591, 2167, 10497, 10497, '0', '0', 0, 0, 0, -276.982635498046875, -222.970489501953125, 74.18817901611328125, 4.494670391082763671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Tussle Tonks Fanatic (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+4, 151328, 2167, 10497, 10497, '0', '0', 0, 0, 0, -362.87847900390625, -284.111114501953125, 87.442413330078125, 2.975072622299194335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Alarm-o-Bot (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+5, 154584, 2167, 10497, 10497, '0', '0', 0, 0, 0, -190.091873168945312, -271.7298583984375, 90.784027099609375, 4.562215328216552734, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Mechagon - Critters (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+6, 154591, 2167, 10497, 10497, '0', '0', 0, 0, 0, -269.03125, -334.00347900390625, 74.168731689453125, 1.862302780151367187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Tussle Tonks Fanatic (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+7, 154573, 2167, 10497, 10497, '0', '0', 0, 0, 0, -318.529510498046875, -277.732635498046875, 70.96363067626953125, 0.66805046796798706, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Rustbolt Spraybot (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+8, 154584, 2167, 10497, 10497, '0', '0', 0, 0, 0, -285.705780029296875, -318.30328369140625, 70.95305633544921875, 0.141363665461540222, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Mechagon - Critters (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+9, 154588, 2167, 10497, 10497, '0', '0', 0, 0, 0, -257.2725830078125, -357.494781494140625, 73.93599700927734375, 1.66351318359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rustbolt Enforcer (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+10, 154589, 2167, 10497, 10497, '0', '0', 0, 0, 0, -278.923614501953125, -194.838546752929687, 75.69069671630859375, 4.549063682556152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Anodized Coilbearer (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+11, 154591, 2167, 10497, 10497, '0', '0', 0, 0, 0, -267.19097900390625, -332.907989501953125, 74.25550079345703125, 2.054608106613159179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Tussle Tonks Fanatic (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+12, 154584, 2167, 10497, 10497, '0', '0', 0, 0, 0, -260.35589599609375, -273.05902099609375, 70.95305633544921875, 4.912654876708984375, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Mechagon - Critters (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+13, 154577, 2167, 10497, 10497, '0', '0', 0, 0, 0, -303.650848388671875, -268.24676513671875, 96.34787750244140625, 4.066770553588867187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Flying Claw (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+14, 154588, 2167, 10497, 10497, '0', '0', 0, 0, 0, -284.211822509765625, -361.923614501953125, 75.19763946533203125, 1.437150359153747558, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rustbolt Enforcer (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+15, 154589, 2167, 10497, 10497, '0', '0', 0, 0, 0, -307.013885498046875, -200.819442749023437, 72.72412109375, 4.55579996109008789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Anodized Coilbearer (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+16, 154591, 2167, 10497, 10497, '0', '0', 0, 0, 0, -323.314239501953125, -319.861114501953125, 79.107696533203125, 0.718692898750305175, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Tussle Tonks Fanatic (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+17, 154593, 2167, 10497, 10497, '0', '0', 0, 0, 0, -190.355911254882812, -271.848968505859375, 89.967559814453125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Power Coil (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+18, 154584, 2167, 10497, 10497, '0', '0', 0, 0, 0, -371.203125, -278.057281494140625, 89.25567626953125, 0.988933026790618896, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Mechagon - Critters (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+19, 154591, 2167, 10497, 10497, '0', '0', 0, 0, 0, -321.545135498046875, -321.77777099609375, 79.05933380126953125, 0.856421470642089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Tussle Tonks Fanatic (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+20, 154584, 2167, 10497, 10497, '0', '0', 0, 0, 0, -317.527862548828125, -255.51348876953125, 70.95305633544921875, 0.34594881534576416, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Mechagon - Critters (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+21, 154577, 2167, 10497, 10497, '0', '0', 0, 0, 0, -281.0594482421875, -296.726165771484375, 95.95363616943359375, 0.924684226512908935, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Flying Claw (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+22, 154593, 2167, 10497, 10497, '0', '0', 0, 0, 0, -372.34375, -285.48785400390625, 89.76513671875, 0.578076422214508056, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Power Coil (Area: The Robodrome - Difficulty: 0) CreateObject1
(@CGUID+23, 154591, 2167, 10497, 10497, '0', '0', 0, 0, 0, -340.82464599609375, -253.720489501953125, 76.2044219970703125, 5.556685447692871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Tussle Tonks Fanatic (Area: The Robodrome - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+23;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 3, 0, 1, 0, 0, 18059, 0, 0, 0, ''), -- Tussle Tonks Fanatic
(@CGUID+6, 0, 0, 0, 3, 0, 1, 0, 0, 18059, 0, 0, 0, ''), -- Tussle Tonks Fanatic
(@CGUID+9, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Rustbolt Enforcer
(@CGUID+10, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Anodized Coilbearer
(@CGUID+11, 0, 0, 0, 3, 0, 1, 0, 0, 18059, 0, 0, 0, ''), -- Tussle Tonks Fanatic
(@CGUID+13, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Flying Claw
(@CGUID+14, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Rustbolt Enforcer
(@CGUID+15, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Anodized Coilbearer
(@CGUID+16, 0, 0, 0, 3, 0, 1, 0, 0, 18059, 0, 0, 0, ''), -- Tussle Tonks Fanatic
(@CGUID+19, 0, 0, 0, 3, 0, 1, 0, 0, 835, 0, 0, 0, ''), -- Tussle Tonks Fanatic
(@CGUID+21, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Flying Claw
(@CGUID+23, 0, 0, 0, 3, 0, 1, 0, 0, 18059, 0, 0, 0, ''); -- Tussle Tonks Fanatic

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP, 'The Robodrome - Shadow sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+2),
(@SPAWN_GROUP, 1, @OGUID+3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` = @SPAWN_GROUP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

DELETE FROM `vehicle_template_accessory` WHERE (`entry`=154577 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(154577, 150520, 0, 0, 'Flying Claw - Cubed Clutter', 5, 0); -- Flying Claw - Cubed Clutter

UPDATE `creature_template` SET `unit_flags`=0x300, `unit_flags3`=0x41000000 WHERE `entry`=154593; -- Power Coil
UPDATE `creature_template` SET `unit_flags`=0x2000100, `unit_flags3`=0x1000000 WHERE `entry`=154577; -- Flying Claw
UPDATE `creature_template` SET `unit_flags`=0x2000040, `unit_flags3`=0x1000000 WHERE `entry`=154589; -- Anodized Coilbearer
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x1800000 WHERE `entry`=154588; -- Rustbolt Enforcer
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=150520; -- Cubed Clutter
UPDATE `creature_template` SET `unit_flags`=0x2000300, `unit_flags3`=0x1000000 WHERE `entry`=154591; -- Tussle Tonks Fanatic
UPDATE `creature_template` SET `unit_flags`=0x2000300, `unit_flags3`=0x1000000 WHERE `entry`=154573; -- Rustbolt Spraybot
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x1000000 WHERE `entry`=151328; -- Alarm-o-Bot
UPDATE `creature_template` SET `unit_flags`=0x2000300, `unit_flags3`=0x1000000 WHERE `entry`=154584; -- Mechagon - Critters

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63305 WHERE (`Entry`=154593 AND `DifficultyID`=0); -- 154593 (Power Coil) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=63305 WHERE (`Entry`=154577 AND `DifficultyID`=0); -- 154577 (Flying Claw) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=154589 AND `DifficultyID`=0); -- 154589 (Anodized Coilbearer) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=63305 WHERE (`Entry`=154588 AND `DifficultyID`=0); -- 154588 (Rustbolt Enforcer) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=63305 WHERE (`Entry`=154591 AND `DifficultyID`=0); -- 154591 (Tussle Tonks Fanatic) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=154573 AND `DifficultyID`=0); -- 154573 (Rustbolt Spraybot) - CanSwim

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_the_robodrome_zap_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(300642, 'spell_the_robodrome_zap_damage');

SET @MOVERGUID := @CGUID+13;
SET @ENTRY := 154577;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2946, 'Flying Claw - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -303.28534, -267.82578, 96.34789, NULL, 0),
(@PATH, 1, -297.62848, -265.48264, 96.34789, NULL, 0),
(@PATH, 2, -291.97162, -267.82578, 96.34789, NULL, 0),
(@PATH, 3, -289.62848, -273.48264, 96.34789, NULL, 0),
(@PATH, 4, -291.97162, -279.1395, 96.34789, NULL, 0),
(@PATH, 5, -297.62848, -281.48264, 96.34789, NULL, 0),
(@PATH, 6, -303.28534, -279.1395, 96.34789, NULL, 0),
(@PATH, 7, -305.62848, -273.48264, 96.34789, NULL, 0);

UPDATE `creature` SET `position_x`=-303.28534, `position_y`=-267.82578, `position_z`=96.34789, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+21;
SET @ENTRY := 154577;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2946, 'Flying Claw - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -280.69507, -296.30667, 95.95362, NULL, 0),
(@PATH, 1, -275.0382, -293.96353, 95.95362, NULL, 0),
(@PATH, 2, -269.38135, -296.30667, 95.95362, NULL, 0),
(@PATH, 3, -267.0382, -301.96353, 95.95362, NULL, 0),
(@PATH, 4, -269.38135, -307.6204, 95.95362, NULL, 0),
(@PATH, 5, -275.0382, -309.96353, 95.95362, NULL, 0),
(@PATH, 6, -280.69507, -307.6204, 95.95362, NULL, 0),
(@PATH, 7, -283.0382, -301.96353, 95.95362, NULL, 0);

UPDATE `creature` SET `position_x`=-280.69507, `position_y`=-296.30667, `position_z`=95.95362, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

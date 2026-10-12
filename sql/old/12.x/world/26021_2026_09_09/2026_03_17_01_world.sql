SET @POOLID := 1100000;
SET @EENTRY := 95;

-- Old spawns
SET @CGUID := 11000000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+156;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+156;

SET @OGUID := 11000000;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;

-- Game event
DELETE FROM `world_state` WHERE `ID` IN (29191);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(29191, 0, NULL, NULL, '', 'Event - Twilight Ascension');

DELETE FROM `game_event` WHERE `eventEntry`=@EENTRY+0;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `holidayStage`,`WorldStateId`, `description`, `world_event`, `announce`) VALUES 
(@EENTRY+0, NULL, NULL, 5184000, 2592000, 0, 0, 29191, 'Midnight Pre-Patch - Twilight Ascension', 0, 2);

-- Phases
DELETE FROM `phase_name` WHERE `ID` IN (27453);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(27453, 'Cosmetic - See Twilight Ascension important NPCs and portals');

DELETE FROM `phase_area` WHERE `PhaseId` IN (27453);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4922, 27453, 'See Twilight Ascension important NPCs and portals');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (27073,27265);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 27265, 0, 0, 0, 11, 0, 29191, 1, 0, 0, 'Apply phase 27265 if world state 29191 (Event - Twilight Ascension) is 1'),
(26, 27073, 0, 0, 0, 11, 0, 29191, 1, 0, 0, 'Apply phase 27073 if world state 29191 (Event - Twilight Ascension) is 1');

-- Creatures
SET @CGUID := 11800000;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 246156, 0, 1519, 5390, '0', 27073, 0, 0, 1, -8690.58203125, 474.2257080078125, 95.44113922119140625, 2.275526762008666992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65655); -- Magister Umbric (Area: The Canals - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Magister Umbric

SET @CGUID := 11800001;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+98;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8706.138671875, 421.68402099609375, 99.2193145751953125, 3.769489288330078125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+1, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8707.3125, 418.868072509765625, 99.166351318359375, 1.298754453659057617, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+2, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8708.701171875, 420.166656494140625, 98.98682403564453125, 0.660206139087677001, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+3, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8708.5556640625, 422.135406494140625, 98.97164154052734375, 6.099417686462402343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+4, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8704.826171875, 421.03125, 99.46875, 3.861049890518188476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+5, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8733.9775390625, 398.015625, 98.06345367431640625, 4.755939483642578125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+6, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8725.1162109375, 458.267364501953125, 98.2146148681640625, 3.68799757957458496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+7, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8729.30078125, 396.9375, 98.0351409912109375, 4.234243392944335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+8, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.1025390625, 393.69964599609375, 98.290496826171875, 1.383632540702819824, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+9, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8730.7861328125, 395.951385498046875, 98.0367889404296875, 4.365546226501464843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+10, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8727.0849609375, 457.0625, 98.44086456298828125, 0.49616822600364685, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+11, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8734.7236328125, 396.369781494140625, 98.290496826171875, 5.020342826843261718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+12, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.267578125, 397.796875, 98.04198455810546875, 4.564572811126708984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+13, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.138671875, 390.947906494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+14, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.5830078125, 396.748260498046875, 98.047882080078125, 4.808267593383789062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+15, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8733.607421875, 392.916656494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+16, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8728.9150390625, 395.01910400390625, 98.290496826171875, 3.808313846588134765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+17, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8701.357421875, 460.29339599609375, 96.6452178955078125, 4.635957717895507812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+18, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8728.2900390625, 434.00347900390625, 98.45070648193359375, 3.09932708740234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+19, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.5576171875, 433.13714599609375, 98.990234375, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+20, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8702.5595703125, 456.34375, 96.9482421875, 2.311017751693725585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+21, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.3662109375, 436.48089599609375, 99.1847076416015625, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+22, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8727.4912109375, 432.421875, 98.39881134033203125, 3.258150577545166015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+23, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8728.935546875, 436.064239501953125, 98.60760498046875, 3.642995834350585937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+24, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8704.5869140625, 458.539947509765625, 96.72534942626953125, 5.85458230972290039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+25, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8729.169921875, 432.359375, 98.54477691650390625, 3.09932708740234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+26, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8703.2099609375, 460.0538330078125, 96.57634735107421875, 5.124796390533447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+27, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8701.9287109375, 457.6475830078125, 96.85198974609375, 2.219457626342773437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+28, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.2763671875, 434.828125, 99.09869384765625, 0.263248145580291748, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+29, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8730.0517578125, 439.17535400390625, 98.6682586669921875, 4.292134761810302734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+30, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8711.171875, 447.369781494140625, 97.25511932373046875, 4.629204273223876953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+31, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8730.12890625, 437.623260498046875, 98.7930450439453125, 4.278536796569824218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+32, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8672.234375, 409.133697509765625, 103.7615585327148437, 1.756839275360107421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+33, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8670.46875, 410.005218505859375, 103.6328125, 2.270540714263916015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+34, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8660.1337890625, 499.782989501953125, 101.5218276977539062, 0.942570984363555908, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+35, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8678.908203125, 481.548614501953125, 97.16225433349609375, 5.323331832885742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+36, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8657.484375, 502.211822509765625, 101.7852783203125, 3.836822509765625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+37, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8672.75390625, 411.470489501953125, 104.1501235961914062, 5.113438129425048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+38, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8658.97265625, 503.2100830078125, 102.05401611328125, 3.905642986297607421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+39, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8677.7236328125, 479.203125, 97.2174530029296875, 1.931082606315612792, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+40, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8662.2294921875, 502.505218505859375, 102.05401611328125, 0.066855460405349731, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+41, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8661.50390625, 500.703125, 101.5715179443359375, 0.581144869327545166, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+42, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8671.2392578125, 412.689239501953125, 103.9925765991210937, 5.027472972869873046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+43, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8696.6298828125, 391.001739501953125, 102.516326904296875, 5.568322658538818359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+44, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8629.935546875, 441.1319580078125, 102.9605331420898437, 5.398550033569335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+45, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8691.3505859375, 391.4913330078125, 102.4295196533203125, 4.6082611083984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+46, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8693.7255859375, 388.447906494140625, 102.6494827270507812, 2.02476668357849121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+47, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8628.6630859375, 438.751739501953125, 103.2975692749023437, 2.327332258224487304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+48, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8628.6005859375, 442.3975830078125, 103.3246536254882812, 5.323331832885742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+49, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8711.373046875, 444.755218505859375, 97.34857177734375, 1.649069786071777343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+50, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8629.91015625, 442.883697509765625, 102.928955078125, 5.398550033569335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+51, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8693.9443359375, 392.31597900390625, 102.3186569213867187, 4.946494102478027343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+52, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8691.3037109375, 386.8194580078125, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+53, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8630.9150390625, 439.10589599609375, 102.9737548828125, 6.007556438446044921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+54, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8696.4736328125, 389.5382080078125, 102.6932754516601562, 5.395518302917480468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+55, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8694.45703125, 386.930572509765625, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+56, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8627.0537109375, 440.26910400390625, 103.3104934692382812, 2.563581705093383789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+57, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8694.6337890625, 390.59027099609375, 102.4197921752929687, 5.139936447143554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+58, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8692.5849609375, 390.5694580078125, 102.4608230590820312, 4.6082611083984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+59, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8672.75390625, 411.470489501953125, 104.1501235961914062, 5.113438129425048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+60, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8643.4423828125, 454.994781494140625, 102.58160400390625, 0.744741797447204589, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+61, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8677.7236328125, 479.203125, 97.2174530029296875, 1.931082606315612792, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+62, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8641.404296875, 456.701385498046875, 102.4747238159179687, 3.672198772430419921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+63, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8671.2392578125, 412.689239501953125, 103.9925765991210937, 5.027472972869873046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+64, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8676.888671875, 389.734375, 103.4172286987304687, 5.674918174743652343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+65, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8627.0537109375, 440.26910400390625, 103.3104934692382812, 2.563581705093383789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+66, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8628.6630859375, 438.751739501953125, 103.2975692749023437, 2.327332258224487304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+67, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8691.3037109375, 386.8194580078125, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+68, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8694.45703125, 386.930572509765625, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+69, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8693.7255859375, 388.447906494140625, 102.6494827270507812, 2.02476668357849121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+70, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8675.0224609375, 388.2569580078125, 103.5077590942382812, 2.638671636581420898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+71, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8648.2294921875, 409.76910400390625, 102.71514892578125, 2.250457286834716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+72, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8649.794921875, 411.760406494140625, 102.730712890625, 5.3607940673828125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+73, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8705.5380859375, 456.96527099609375, 96.8568878173828125, 0.0028458540327847, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+74, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.3662109375, 436.48089599609375, 99.1847076416015625, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+75, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8733.607421875, 392.916656494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+76, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.2763671875, 434.828125, 99.09869384765625, 0.263248145580291748, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+77, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.1025390625, 393.69964599609375, 98.290496826171875, 1.383632540702819824, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+78, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.5576171875, 433.13714599609375, 98.990234375, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+79, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.138671875, 390.947906494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+80, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8684.671875, 441.361114501953125, 99.6461639404296875, 4.193150997161865234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+81, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8687.767578125, 438.008697509765625, 99.445098876953125, 1.054665088653564453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+82, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8682.7236328125, 439.13714599609375, 99.59661865234375, 3.662360668182373046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+83, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8682.576171875, 441.729156494140625, 99.7542266845703125, 4.158257484436035156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+84, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8686.3330078125, 437.81597900390625, 99.44927978515625, 0.963104486465454101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+85, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8687.1630859375, 441.614593505859375, 99.5476226806640625, 4.526597023010253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+86, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8658.97265625, 503.2100830078125, 102.05401611328125, 3.905642986297607421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+87, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8657.484375, 502.211822509765625, 101.7852783203125, 3.836822509765625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+88, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8706.138671875, 421.68402099609375, 99.2193145751953125, 3.769489288330078125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+89, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8704.826171875, 421.03125, 99.46875, 3.861049890518188476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+90, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8658.232421875, 437.513885498046875, 101.367095947265625, 2.250457286834716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+91, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8660.0673828125, 439.701385498046875, 101.081573486328125, 5.461605548858642578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+92, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8675.0224609375, 388.2569580078125, 103.5077590942382812, 2.638671636581420898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+93, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8648.2294921875, 409.76910400390625, 102.71514892578125, 2.250457286834716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+94, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8643.4423828125, 454.994781494140625, 102.58160400390625, 0.744741797447204589, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+95, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8742.671875, 415.802093505859375, 98.290496826171875, 3.555392026901245117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+96, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8745.9658203125, 414.34027099609375, 98.290496826171875, 0.251413047313690185, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+97, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8741.5595703125, 414.333343505859375, 98.0711822509765625, 3.011341571807861328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+98, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8742.9970703125, 413.3819580078125, 98.290496826171875, 3.011341571807861328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727); -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2

DELETE FROM `pool_members` WHERE `type` = 0 AND `poolSpawnId` BETWEEN @POOLID+0 AND @POOLID+20;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, @CGUID+74, @POOLID+0, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+21, @POOLID+0, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+76, @POOLID+1, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+28, @POOLID+1, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+78, @POOLID+2, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+19, @POOLID+2, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+88, @POOLID+3, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+0, @POOLID+3, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+89, @POOLID+4, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+4, @POOLID+4, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+15, @POOLID+5, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+75, @POOLID+5, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+77, @POOLID+6, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+8, @POOLID+6, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+13, @POOLID+7, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+79, @POOLID+7, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+68, @POOLID+8, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+55, @POOLID+8, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+46, @POOLID+9, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+69, @POOLID+9, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+52, @POOLID+10, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+67, @POOLID+10, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+70, @POOLID+11, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+92, @POOLID+11, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+37, @POOLID+12, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+59, @POOLID+12, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+63, @POOLID+13, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+42, @POOLID+13, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+71, @POOLID+14, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+93, @POOLID+14, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+47, @POOLID+15, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+66, @POOLID+15, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+56, @POOLID+16, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+65, @POOLID+16, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+60, @POOLID+17, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+94, @POOLID+17, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+36, @POOLID+18, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+87, @POOLID+18, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+38, @POOLID+19, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+86, @POOLID+19, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+39, @POOLID+20, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+61, @POOLID+20, 0, 'Stormwind - Suspicious Citizen');

SET @CGUID := 11800100;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+55;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4971.126953125, -5044.8056640625, 198.989227294921875, 0.638297557830810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+1, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4985.8818359375, -5052.7900390625, 197.3719329833984375, 4.984168052673339843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+2, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5037.15478515625, -5088.328125, 197.732635498046875, 1.694147586822509765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+3, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4979.96533203125, -5053.767578125, 196.9564666748046875, 4.895166873931884765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+4, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4969.47216796875, -5038.62158203125, 199.4388580322265625, 1.328086495399475097, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+5, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5008.0712890625, -5031.01220703125, 195.62530517578125, 6.275734424591064453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 32783 - Arcane Channeling)
(@CGUID+6, 249999, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5001.24853515625, -5017.875, 197.1177978515625, 3.817080020904541015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Shan (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+7, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4994.5068359375, -5042.84033203125, 197.2259063720703125, 0.20652174949645996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+8, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4995.43212890625, -5034.2568359375, 196.587310791015625, 3.0001373291015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+9, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4993.98291015625, -5040.8193359375, 197.2646942138671875, 6.275734901428222656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+10, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4975.814453125, -5044.14404296875, 198.438079833984375, 1.933497548103332519, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 174127 - UseKneeling)
(@CGUID+11, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5005.212890625, -5050.2421875, 194.90032958984375, 2.907874107360839843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+12, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4996.05224609375, -5029.28125, 196.126251220703125, 4.565880298614501953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 174127 - UseKneeling)
(@CGUID+13, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 2, -4973.65625, -5029.4462890625, 198.3276214599609375, 0.573106944561004638, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+14, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5014.9912109375, -5055.88037109375, 195.7083282470703125, 4.574382781982421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+15, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5039.96875, -5084.9775390625, 197.87060546875, 5.584947109222412109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+16, 249197, 0, 4922, 4922, '0', 27453, 0, 0, 0, -5013.625, -5057.05712890625, 195.8836822509765625, 4.837193012237548828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Armorer Kalinovan (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+17, 249198, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4981.658203125, -5040.10595703125, 198.5344696044921875, 0.155717164278030395, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Vigilant Magister (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+18, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5040.578125, -5086.56787109375, 198.149169921875, 6.108037471771240234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+19, 237504, 0, 4922, 4922, '0', 27453, 0, 0, 1, -4993.71875, -5066.96533203125, 194.8557586669921875, 4.195984840393066406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Grand Magister Rommath (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+20, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4994.59228515625, -5045.0849609375, 197.063262939453125, 0.20652174949645996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+21, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5018.6494140625, -5043.34228515625, 195.3802032470703125, 3.794791698455810546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+22, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5015.20849609375, -5061.07470703125, 196.1805572509765625, 0.947215557098388671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+23, 237506, 0, 4922, 4922, '0', 27453, 0, 0, 1, -4994.673828125, -5069.345703125, 194.8094482421875, 1.30216217041015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Magister Umbric (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1249978 - [DNT] RP Chat Bubble)
(@CGUID+24, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5023.72314453125, -5063.12890625, 195.8147125244140625, 2.327123641967773437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+25, 249196, 0, 4922, 4922, '0', 27453, 0, 0, 0, -5013.91845703125, -5060.1162109375, 196.142364501953125, 1.269718527793884277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Materialist Ophinell (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+26, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5019.76416015625, -5045.08349609375, 195.735687255859375, 1.001331925392150878, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+27, 249541, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4995.74462890625, -5061.34228515625, 195.231231689453125, 5.649254798889160156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Farstrider Helia (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+28, 249199, 0, 4922, 4922, '0', 27265, 0, 0, 1, -4989.611328125, -5043.40966796875, 197.700103759765625, 3.332261323928833007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Knight Adept (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+29, 249534, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4969.75537109375, -5043.7880859375, 199.1597137451171875, 3.663061380386352539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Blood Elf Farstrider (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+30, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5003.96337890625, -5090.8369140625, 194.5930328369140625, 3.603682994842529296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+31, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5029.5712890625, -5082.8974609375, 196.6885833740234375, 0.557758629322052001, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 32783 - Arcane Channeling)
(@CGUID+32, 249994, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5001.703125, -5086.689453125, 194.898406982421875, 0.587304770946502685, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Riftwalker Dellyn (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+33, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5012.79150390625, -5089.33984375, 195.72760009765625, 0.888574600219726562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+34, 249995, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5003.033203125, -5084.57470703125, 194.9622039794921875, 0.587304770946502685, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Riftwalker Soran (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+35, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5021.814453125, -5090.29345703125, 197.185546875, 4.665406703948974609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+36, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5014.70849609375, -5086.6181640625, 195.844879150390625, 2.935244560241699218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+37, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5033.6943359375, -5047.3369140625, 197.591400146484375, 0.196390017867088317, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 32783 - Arcane Channeling)
(@CGUID+38, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5033.05224609375, -5062.50341796875, 196.4577178955078125, 5.6346435546875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+39, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5025.8505859375, -5066.0380859375, 196.1237335205078125, 1.399336099624633789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+40, 249996, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5006.27294921875, -5019.51416015625, 196.6754913330078125, 2.597052335739135742, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 65893), -- Teely (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 244519 - Void Infested)
(@CGUID+41, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5029.673828125, -5072.705078125, 196.685455322265625, 1.146155238151550292, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 374151 - Channel: Read Floating Book (Reliquary) [DNT])
(@CGUID+42, 249998, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5006.0224609375, -5021.26416015625, 196.5396728515625, 0.489578485488891601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Voidlight Everdawn (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+43, 249542, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5033.9150390625, -5071.89404296875, 196.6855010986328125, 1.010324478149414062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Riftblade Maella (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+44, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5005.4775390625, -5091.87158203125, 194.6150360107421875, 0.337612122297286987, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT])
(@CGUID+45, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5026.017578125, -5064.205078125, 196.142242431640625, 4.665406703948974609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+46, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5023.751953125, -5102.60400390625, 198.196807861328125, 0.457683414220809936, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+47, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5012.4912109375, -5122.69287109375, 196.443359375, 4.839010238647460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+48, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5034.3525390625, -5086.953125, 197.212982177734375, 3.542521953582763671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+49, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5037.75537109375, -5086.40966796875, 197.60321044921875, 4.494048595428466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+50, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5009.0849609375, -5122.40283203125, 194.9400177001953125, 5.313063621520996093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+51, 249194, 0, 4922, 4922, '0', 27265, 0, 0, 1, -5028.69921875, -5101.705078125, 198.7400360107421875, 0.071811713278293609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Scout (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 1239411 - Hold Sack [DNT])
(@CGUID+52, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5020.98095703125, -5094.703125, 197.841827392578125, 1.327726364135742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+53, 245514, 0, 4922, 4922, '0', 27265, 0, 0, 0, -4968.4443359375, -5026.57470703125, 200.9065399169921875, 4.452251911163330078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- (Bunny) Sessile (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@CGUID+54, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5028.93212890625, -5096.1005859375, 198.37738037109375, 3.889490604400634765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893), -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1 (Auras: 174127 - UseKneeling)
(@CGUID+55, 249200, 0, 4922, 4922, '0', 27265, 0, 0, 0, -5018.5068359375, -5099.91162109375, 197.718414306640625, 4.659598350524902343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65893); -- Ren'dorei Arcanist (Area: Twilight Highlands - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+55;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, ''), -- Blood Elf Farstrider
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, ''), -- Blood Knight Adept
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Blood Elf Farstrider
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'), -- Vigilant Magister - 174127 - UseKneeling
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'), -- Blood Knight Adept - 174127 - UseKneeling
(@CGUID+13, 0, 0, 0, 0, 0, 2, 0, 376, 0, 0, 0, 0, ''), -- Blood Elf Farstrider
(@CGUID+15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Grand Magister Rommath
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Blood Elf Farstrider - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '1249978'), -- Magister Umbric - 1249978 - [DNT] RP Chat Bubble
(@CGUID+26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Farstrider Helia
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371815'), -- Blood Elf Farstrider - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Riftwalker Dellyn
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Riftwalker Soran
(@CGUID+35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+38, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ren'dorei Scout - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244519'), -- Teely - 244519 - Void Infested
(@CGUID+44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '371815'), -- Ren'dorei Scout - 371815 - Conversation Aura: Talk/Question/Flex/Laugh [DNT]
(@CGUID+45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+46, 0, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+50, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Scout
(@CGUID+52, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Ren'dorei Arcanist
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'); -- Ren'dorei Arcanist - 174127 - UseKneeling

UPDATE `creature` SET `StringID` = 'CosmeticOne' WHERE `guid` IN (@CGUID+11,@CGUID+24);
UPDATE `creature` SET `StringID` = 'CosmeticTwo' WHERE `guid` IN (@CGUID+8,@CGUID+33);
UPDATE `creature` SET `StringID` = 'CosmeticThree' WHERE `guid` = @CGUID+51;
UPDATE `creature` SET `StringID` = 'CosmeticBook' WHERE `guid` IN (@CGUID+4, @CGUID+17, @CGUID+36, @CGUID+41);
UPDATE `creature` SET `StringID` = 'CosmeticChannel' WHERE `guid` IN (@CGUID+5,@CGUID+31,@CGUID+37);

SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 249534;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature` SET `position_x`=-5014.6025, `position_y`=-5046.5938, `position_z`=195.3017, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

SET @MOVERGUID := @CGUID+8;
SET @ENTRY := 249534;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature` SET `position_x`=-5005.724, `position_y`=-5041.165, `position_z`=195.59567, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 249194;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature` SET `position_x`=-5029.125, `position_y`=-5061.6895, `position_z`=196.43124, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 249194;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature` SET `position_x`=-5003.08, `position_y`=-5075.988, `position_z`=195.24622, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

SET @MOVERGUID := @CGUID+51;
SET @ENTRY := 249194;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
UPDATE `creature` SET `position_x`=-5025.979, `position_y`=-5095.0454, `position_z`=198.14531, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);

-- Gameobjects
SET @OGUID := 11800000;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 566765, 0, 4922, 4922, '0', 27265, 0, -5017.98974609375, -5086.82275390625, 197.3301849365234375, 0, 0, 0, 0, 1, 120, 255, 1, 65893), -- Stolen Twilight's Blade Stratagem (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+1, 508355, 0, 4922, 4922, '0', 27453, 0, -5030.33154296875, -5047.12158203125, 196.7599945068359375, 0, 0, 0, 0, 1, 120, 255, 1, 65893), -- Portal to Dornogal (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+2, 508353, 0, 4922, 4922, '0', 27453, 0, -5003.83154296875, -5031.783203125, 195.6225128173828125, 0.240502700209617614, 0, 0, 0.119961738586425781, 0.992778539657592773, 120, 255, 1, 65893), -- Portal to Orgrimmar (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+3, 566765, 0, 4922, 4922, '0', 27265, 0, -4975.2880859375, -5041.923828125, 199.766082763671875, 0, 0, 0, 0, 1, 120, 255, 1, 65893), -- Stolen Twilight's Blade Stratagem (Area: Twilight Highlands - Difficulty: 0) CreateObject1
(@OGUID+4, 508350, 0, 4922, 4922, '0', 27453, 0, -5026.205078125, -5081.51025390625, 196.7755889892578125, 0.474069505929946899, 0, 0, 0.234821319580078125, 0.972038567066192626, 120, 255, 1, 65893); -- Portal to Stormwind (Area: Twilight Highlands - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 19925, 0), -- Stolen Twilight's Blade Stratagem
(@OGUID+2, 0, 0, 0, 1, 0, 3503), -- Portal to Orgrimmar
(@OGUID+3, 0, 0, 0, 1, 19925, 0), -- Stolen Twilight's Blade Stratagem
(@OGUID+4, 0, 0, 0, 1, 0, 3503); -- Portal to Stormwind

-- Game event spawns
SET @CGUID := 11800000;
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EENTRY+0 AND `guid` BETWEEN @CGUID+0 AND @CGUID+155;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EENTRY+0, @CGUID+0),
(@EENTRY+0, @CGUID+2),
(@EENTRY+0, @CGUID+3),
(@EENTRY+0, @CGUID+4),
(@EENTRY+0, @CGUID+6),
(@EENTRY+0, @CGUID+7),
(@EENTRY+0, @CGUID+8),
(@EENTRY+0, @CGUID+10),
(@EENTRY+0, @CGUID+11),
(@EENTRY+0, @CGUID+12),
(@EENTRY+0, @CGUID+13),
(@EENTRY+0, @CGUID+15),
(@EENTRY+0, @CGUID+17),
(@EENTRY+0, @CGUID+18),
(@EENTRY+0, @CGUID+19),
(@EENTRY+0, @CGUID+21),
(@EENTRY+0, @CGUID+23),
(@EENTRY+0, @CGUID+24),
(@EENTRY+0, @CGUID+25),
(@EENTRY+0, @CGUID+26),
(@EENTRY+0, @CGUID+27),
(@EENTRY+0, @CGUID+28),
(@EENTRY+0, @CGUID+30),
(@EENTRY+0, @CGUID+31),
(@EENTRY+0, @CGUID+32),
(@EENTRY+0, @CGUID+33),
(@EENTRY+0, @CGUID+34),
(@EENTRY+0, @CGUID+35),
(@EENTRY+0, @CGUID+36),
(@EENTRY+0, @CGUID+41),
(@EENTRY+0, @CGUID+42),
(@EENTRY+0, @CGUID+44),
(@EENTRY+0, @CGUID+45),
(@EENTRY+0, @CGUID+46),
(@EENTRY+0, @CGUID+49),
(@EENTRY+0, @CGUID+50),
(@EENTRY+0, @CGUID+51),
(@EENTRY+0, @CGUID+52),
(@EENTRY+0, @CGUID+54),
(@EENTRY+0, @CGUID+55),
(@EENTRY+0, @CGUID+58),
(@EENTRY+0, @CGUID+59),
(@EENTRY+0, @CGUID+63),
(@EENTRY+0, @CGUID+65),
(@EENTRY+0, @CGUID+73),
(@EENTRY+0, @CGUID+74),
(@EENTRY+0, @CGUID+81),
(@EENTRY+0, @CGUID+82),
(@EENTRY+0, @CGUID+83),
(@EENTRY+0, @CGUID+84),
(@EENTRY+0, @CGUID+85),
(@EENTRY+0, @CGUID+86),
(@EENTRY+0, @CGUID+91),
(@EENTRY+0, @CGUID+92),
(@EENTRY+0, @CGUID+96),
(@EENTRY+0, @CGUID+97),
(@EENTRY+0, @CGUID+98),
(@EENTRY+0, @CGUID+99),
(@EENTRY+0, @CGUID+100),
(@EENTRY+0, @CGUID+101),
(@EENTRY+0, @CGUID+102),
(@EENTRY+0, @CGUID+103),
(@EENTRY+0, @CGUID+104),
(@EENTRY+0, @CGUID+105),
(@EENTRY+0, @CGUID+106),
(@EENTRY+0, @CGUID+107),
(@EENTRY+0, @CGUID+108),
(@EENTRY+0, @CGUID+109),
(@EENTRY+0, @CGUID+110),
(@EENTRY+0, @CGUID+111),
(@EENTRY+0, @CGUID+112),
(@EENTRY+0, @CGUID+113),
(@EENTRY+0, @CGUID+114),
(@EENTRY+0, @CGUID+115),
(@EENTRY+0, @CGUID+116),
(@EENTRY+0, @CGUID+117),
(@EENTRY+0, @CGUID+118),
(@EENTRY+0, @CGUID+119),
(@EENTRY+0, @CGUID+120),
(@EENTRY+0, @CGUID+121),
(@EENTRY+0, @CGUID+122),
(@EENTRY+0, @CGUID+123),
(@EENTRY+0, @CGUID+124),
(@EENTRY+0, @CGUID+125),
(@EENTRY+0, @CGUID+126),
(@EENTRY+0, @CGUID+127),
(@EENTRY+0, @CGUID+128),
(@EENTRY+0, @CGUID+129),
(@EENTRY+0, @CGUID+130),
(@EENTRY+0, @CGUID+131),
(@EENTRY+0, @CGUID+132),
(@EENTRY+0, @CGUID+133),
(@EENTRY+0, @CGUID+134),
(@EENTRY+0, @CGUID+135),
(@EENTRY+0, @CGUID+136),
(@EENTRY+0, @CGUID+137),
(@EENTRY+0, @CGUID+138),
(@EENTRY+0, @CGUID+139),
(@EENTRY+0, @CGUID+140),
(@EENTRY+0, @CGUID+141),
(@EENTRY+0, @CGUID+142),
(@EENTRY+0, @CGUID+143),
(@EENTRY+0, @CGUID+144),
(@EENTRY+0, @CGUID+145),
(@EENTRY+0, @CGUID+146),
(@EENTRY+0, @CGUID+147),
(@EENTRY+0, @CGUID+148),
(@EENTRY+0, @CGUID+149),
(@EENTRY+0, @CGUID+150),
(@EENTRY+0, @CGUID+151),
(@EENTRY+0, @CGUID+152),
(@EENTRY+0, @CGUID+153),
(@EENTRY+0, @CGUID+154),
(@EENTRY+0, @CGUID+155);

SET @OGUID := 11800000;
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EENTRY+0 AND `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EENTRY+0, @OGUID+0),
(@EENTRY+0, @OGUID+1),
(@EENTRY+0, @OGUID+2),
(@EENTRY+0, @OGUID+3),
(@EENTRY+0, @OGUID+4);

DELETE FROM `game_event_pool` WHERE `eventEntry`=@EENTRY+0 AND `pool_entry` BETWEEN @POOLID+0 AND @POOLID+20;
INSERT INTO `game_event_pool` (`eventEntry`, `pool_entry`) VALUES
(@EENTRY+0, @POOLID+0),
(@EENTRY+0, @POOLID+1),
(@EENTRY+0, @POOLID+2),
(@EENTRY+0, @POOLID+3),
(@EENTRY+0, @POOLID+4),
(@EENTRY+0, @POOLID+5),
(@EENTRY+0, @POOLID+6),
(@EENTRY+0, @POOLID+7),
(@EENTRY+0, @POOLID+8),
(@EENTRY+0, @POOLID+9),
(@EENTRY+0, @POOLID+10),
(@EENTRY+0, @POOLID+11),
(@EENTRY+0, @POOLID+12),
(@EENTRY+0, @POOLID+13),
(@EENTRY+0, @POOLID+14),
(@EENTRY+0, @POOLID+15),
(@EENTRY+0, @POOLID+16),
(@EENTRY+0, @POOLID+17),
(@EENTRY+0, @POOLID+18),
(@EENTRY+0, @POOLID+19),
(@EENTRY+0, @POOLID+20);

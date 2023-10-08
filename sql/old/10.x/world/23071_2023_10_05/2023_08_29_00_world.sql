SET @CGUID := 7000000;
SET @OGUID := 7000000;

SET @TRIGGER_ID_ALLIANCE := 30; -- Trigger ID for capture flag area trigger alliance
SET @TRIGGER_ID_HORDE := 31; -- Trigger ID for capture flag area trigger horde
SET @TRIGGER_SPAWN_ID := 35;

-- new trigger capture flag
DELETE FROM `areatrigger_template` WHERE `Id` IN (@TRIGGER_ID_ALLIANCE, @TRIGGER_ID_HORDE) AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Data0`, `Data1`) VALUES
(@TRIGGER_ID_ALLIANCE, 1, 0, 5.0, 5.0),
(@TRIGGER_ID_HORDE, 1, 0, 5.0, 5.0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @TRIGGER_SPAWN_ID+0 AND @TRIGGER_SPAWN_ID+2 AND `IsServerSide` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `ShapeData0`, `ShapeData1`, `ScriptName`, `Comment`) VALUES
(@TRIGGER_SPAWN_ID+0, @TRIGGER_ID_ALLIANCE, 1, 2106, 1540.4461669921875, 1481.217041015625, 353.577301025390625, 3.089183330535888671, 5.0, 5.0, 'areatrigger_action_capture_flag', 'Warsong Gulch - Capture Flag - Alliance'),
(@TRIGGER_SPAWN_ID+1, @TRIGGER_ID_HORDE, 1, 2106, 917.310791015625, 1434.0035400390625, 346.1337890625, 0.017452461645007133, 5.0, 5.0, 'areatrigger_action_capture_flag', 'Warsong Gulch - Capture Flag - Horde');

-- Areatrigger Scripts for buffs
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (10500, 10501, 10502, 10503, 10504, 10505);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(10500, 'at_battleground_buffs'),
(10501, 'at_battleground_buffs'),
(10502, 'at_battleground_buffs'),
(10503, 'at_battleground_buffs'),
(10504, 'at_battleground_buffs'),
(10505, 'at_battleground_buffs');

-- Graveyards
DELETE FROM `graveyard_zone` WHERE `ID` IN (7052, 7053);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`,`Comment`) VALUES
(7053, 10218, 'Warsong Gulch - Horde Graveyard'),
(7052, 10218, 'Warsong Gulch - Alliance Graveyard');

-- Graveyard conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (7052, 7053);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(27, 7052, 10218, 0, 6, 469, 0, 'Graveyard - Warsong Gulch - Alliance Graveyard - Team Alliance'),
(27, 7053, 10218, 0, 6, 67, 0, 'Graveyard - Warsong Gulch - Horde Graveyard - Team Horde');

UPDATE `battleground_template` SET `comment` = 'Warsong Gulch - Classic' WHERE `ID` = 2;
DELETE FROM `battleground_template` WHERE `ID`=1014;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `Weight`, `ScriptName`, `Comment`) VALUES
(1014, 7051, 7050, 1, '', 'Warsong Gulch');

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (227744 /*Horde Flag*/, 227745 /*Alliance Flag*/, 352710 /*Horde Gate*/, 352709 /*Horde Gate*/, 227741 /*Alliance Flag*/, 227740 /*Horde Flag*/, 309883 /*Doodad_7NE_Blackrook_Portcullis002*/, 309705 /*Doodad_7NE_Blackrook_Portcullis009*/, 309704 /*Alliance Door*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(227744, 2058, 0, 0, 0), -- Horde Flag
(227745, 1913, 0, 0, 0), -- Alliance Flag
(352710, 1375, 32, 0, 0), -- Horde Gate
(352709, 1375, 32, 0, 0), -- Horde Gate
(227741, 1995, 32, 0, 0), -- Alliance Flag
(227740, 1997, 32, 0, 0), -- Horde Flag
(309883, 1375, 32, 0, 0), -- Doodad_7NE_Blackrook_Portcullis002
(309705, 1375, 32, 0, 0), -- Doodad_7NE_Blackrook_Portcullis009
(309704, 1375, 32, 0, 0); -- Alliance Door

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 61750, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1402.9974365234375, 1345.5699462890625, 329.3948974609375, 2.346344232559204101, 7200, 10, 0, 1, 0, 1, 0, 0, 50000), -- Deer (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 147662, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1506.2882080078125, 1483.5694580078125, 364.8609619140625, 0.645661056041717529, 7200, 0, 0, 84689, 0, 0, 0, 0, 50000), -- Owl (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@CGUID+2, 61750, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1282.609375, 1521.671875, 314.936370849609375, 1.985947966575622558, 7200, 10, 0, 1, 0, 1, 0, 0, 50000), -- Deer (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 147693, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1052.4820556640625, 1375.9078369140625, 328.55780029296875, 3.76127481460571289, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Coral Snake (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 147694, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1174.87109375, 1620.51611328125, 313.747344970703125, 5.750471115112304687, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Rabbit (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 147693, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1094.83447265625, 1494.9989013671875, 327.934967041015625, 2.633371829986572265, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Coral Snake (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 147694, 2106, 10218, 12835, '0', '0', 0, 0, 0, 946.44940185546875, 1531.2198486328125, 358.988311767578125, 0.561181128025054931, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Rabbit (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 147695, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1471.9176025390625, 1487.6875, 374.7779541015625, 4.924968719482421875, 7200, 10, 0, 21508, 0, 1, 0, 0, 50000), -- Forest Moth (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 61750, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1272.109375, 1335.9427490234375, 312.37847900390625, 2.319414615631103515, 7200, 10, 0, 1, 0, 1, 0, 0, 50000), -- Deer (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 61750, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1358.2359619140625, 1573.6336669921875, 319.684722900390625, 1.636260390281677246, 7200, 10, 0, 1, 0, 1, 0, 0, 50000), -- Deer (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 147662, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1506.59375, 1495.2760009765625, 364.965576171875, 5.427386760711669921, 7200, 0, 0, 84689, 0, 0, 0, 0, 50000), -- Owl (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@CGUID+11, 147693, 2106, 10218, 12835, '0', '0', 0, 0, 0, 939.52435302734375, 1462.2064208984375, 367.303619384765625, 2.263118505477905273, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Coral Snake (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 147694, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1161.0198974609375, 1293.515625, 319.525360107421875, 4.396508216857910156, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Rabbit (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+13, 147695, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1386.3555908203125, 1621.4478759765625, 324.60595703125, 1.856943249702453613, 7200, 10, 0, 21508, 0, 1, 0, 0, 50000), -- Forest Moth (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 61750, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1294.1875, 1378.4305419921875, 311.818695068359375, 0, 7200, 10, 0, 1, 0, 1, 0, 0, 50000), -- Deer (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+15, 147693, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1016.89788818359375, 1318.869140625, 337.970428466796875, 5.617191314697265625, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Coral Snake (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 147694, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1019.16583251953125, 1397.8968505859375, 341.267486572265625, 4.985507011413574218, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Rabbit (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 61750, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1463.2850341796875, 1543.6378173828125, 344.3548583984375, 5.42351531982421875, 7200, 10, 0, 1, 0, 1, 0, 0, 50000), -- Deer (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 147693, 2106, 10218, 12835, '0', '0', 0, 0, 0, 942.4390869140625, 1431.4508056640625, 345.58868408203125, 5.040985107421875, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Coral Snake (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 147694, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1089.4793701171875, 1593.7698974609375, 321.227325439453125, 6.239905357360839843, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Rabbit (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 147695, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1522.5980224609375, 1425.98046875, 373.12481689453125, 3.617821216583251953, 7200, 10, 0, 21508, 0, 1, 0, 0, 50000), -- Forest Moth (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 61750, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1367.4722900390625, 1348.548583984375, 327.42950439453125, 0, 7200, 10, 0, 1, 0, 1, 0, 0, 50000), -- Deer (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 147695, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1415.2279052734375, 1568.1527099609375, 330.19384765625, 2.975586175918579101, 7200, 10, 0, 21508, 0, 1, 0, 0, 50000), -- Forest Moth (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 147693, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1133.1231689453125, 1470.9544677734375, 314.525146484375, 3.480478525161743164, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Coral Snake (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+24, 147694, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1106.4130859375, 1659.8427734375, 322.794708251953125, 5.533683300018310546, 7200, 10, 0, 1129, 0, 1, 0, 0, 50000), -- Rabbit (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 147695, 2106, 10218, 12835, '0', '0', 0, 0, 0, 1318.541015625, 1526.775390625, 317.263580322265625, 3.778635025024414062, 7200, 10, 0, 21508, 0, 1, 0, 0, 50000), -- Forest Moth (Area: Warsong Flag Room - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 13116, 2106, 10218, 0, '0', '0', 0, 0, 1, 1395.6353759765625, 1560.8367919921875, 329.86895751953125, 6.114908695220947265, 7200, 0, 0, 1129190, 6310, 0, 0, 0, 50000), -- Alliance Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+27, 13117, 2106, 10218, 0, '0', '0', 0, 0, 1, 1064.1788330078125, 1371.8975830078125, 328.837646484375, 2.728983640670776367, 7200, 0, 0, 1129190, 6310, 0, 0, 0, 50000); -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 3, 0, 1, 0, 0, 835, 0, 0, 0, ''), -- Owl
(@CGUID+7, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forest Moth
(@CGUID+10, 0, 0, 0, 3, 0, 1, 0, 0, 835, 0, 0, 0, ''), -- Owl
(@CGUID+13, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forest Moth
(@CGUID+20, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forest Moth
(@CGUID+22, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forest Moth
(@CGUID+25, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forest Moth
(@CGUID+26, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036 9617'), -- Alliance Spirit Guide - 9036 - Ghost, 9617 - Ghost Visual
(@CGUID+27, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, '9036 9617'); -- Horde Spirit Guide - 9036 - Ghost, 9617 - Ghost Visual

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179904, 2106, 10218, 12835, '0', '0', 0, 1317.0833740234375, 1551.6614990234375, 315.25006103515625, 5.758442401885986328, 0, 0, -0.25937175750732421, 0.965777516365051269, 90, 255, 1, 50000), -- Food Buff (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+1, 179905, 2106, 10218, 12835, '0', '0', 0, 1319.6875, 1379.923583984375, 316.90704345703125, 1.080207586288452148, 0, 0, 0.514225006103515625, 0.857655286788940429, 90, 255, 1, 50000), -- Berserk Buff (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+2, 179906, 2106, 10218, 12835, '0', '0', 0, 1104.73095703125, 1352.21533203125, 318.598541259765625, 5.946152687072753906, 0, 0, -0.16771984100341796, 0.985834717750549316, 90, 255, 1, 50000), -- Food Buff (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+3, 179907, 2106, 10218, 12835, '0', '0', 0, 1144.795166015625, 1558.779541015625, 308.874053955078125, 3.608199357986450195, 0, 0, -0.97290802001953125, 0.231192529201507568, 90, 255, 1, 50000), -- Berserk Buff (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+4, 179899, 2106, 10218, 12835, '0', '0', 0, 1005.4774169921875, 1448.092041015625, 335.867950439453125, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 90, 255, 1, 50000), -- Speed Buff (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+5, 309704, 2106, 10218, 12835, '0', '0', 0, 1503.0211181640625, 1492.2269287109375, 352.20233154296875, 6.257006168365478515, 0, 0, -0.01308917999267578, 0.999914348125457763, 7200, 255, 1, 50000), -- Alliance Door (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+6, 309705, 2106, 10218, 12835, '0', '0', 0, 1492.7191162109375, 1457.802490234375, 344.8914794921875, 6.257006168365478515, 0, 0, -0.01308917999267578, 0.999914348125457763, 7200, 255, 1, 50000), -- Doodad_7NE_Blackrook_Portcullis009 (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+7, 309883, 2106, 10218, 12835, '0', '0', 0, 1468.5399169921875, 1493.1424560546875, 352.219512939453125, 6.257006168365478515, 0, 0, -0.01308917999267578, 0.999914348125457763, 7200, 255, 1, 50000), -- Doodad_7NE_Blackrook_Portcullis002 (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+8, 179871, 2106, 10218, 12835, '0', '0', 0, 1449.65625, 1470.8367919921875, 343.069000244140625, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 90, 255, 1, 50000), -- Speed Buff (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+9, 227740, 2106, 10218, 12835, '0', '0', 0, 917.310791015625, 1434.0035400390625, 346.1337890625, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 7200, 255, 1, 50000), -- Horde Flag (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+10, 227741, 2106, 10218, 12835, '0', '0', 0, 1540.4461669921875, 1481.217041015625, 353.577301025390625, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 7200, 255, 1, 50000), -- Alliance Flag (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+11, 242273, 2106, 10218, 12835, '0', '0', 0, 1524.5, 1514.3663330078125, 358.001007080078125, 0, 0, 0, 0, 1, 7200, 255, 1, 50000), -- Collision PC Size (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+12, 352709, 2106, 10218, 12835, '0', '0', 0, 949.561279296875, 1422.976318359375, 345.614593505859375, 0, 0, 0, 0, 1, 7200, 255, 1, 50000), -- Horde Gate (Area: Warsong Flag Room - Difficulty: 0) CreateObject1
(@OGUID+13, 352710, 2106, 10218, 12835, '0', '0', 0, 957.255859375, 1459.40087890625, 340.62237548828125, 0, 0, 0.130525588989257812, 0, 0.991444945335388183, 7200, 255, 1, 50000); -- Horde Gate (Area: Warsong Flag Room - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+5, 0, 0, 0.697790503501892089, 0.716301918029785156, 0, 0), -- Alliance Door
(@OGUID+6, 0, 0, 0.697790503501892089, 0.716301918029785156, 0, 0), -- Doodad_7NE_Blackrook_Portcullis009
(@OGUID+7, 0, 0, 0.697790503501892089, 0.716301918029785156, 0, 0), -- Doodad_7NE_Blackrook_Portcullis002
(@OGUID+12, 0, 0, -0.70710659027099609, 0.707106947898864746, 0, 0), -- Horde Gate
(@OGUID+13, 0, 0, -0.70710659027099609, 0.707106947898864746, 0, 0); -- Horde Gate

DELETE FROM `creature_template_addon` WHERE `entry` IN (147695 /*147695 (Forest Moth)*/, 147662 /*147662 (Owl)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(147695, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 147695 (Forest Moth)
(147662, 0, 0, 0, 3, 0, 1, 0, 0, 835, 0, 0, 0, ''); -- 147662 (Owl)

-- Quick Cap Server Side Spell
-- Spell with dummy aura application
DELETE FROM `serverside_spell` WHERE `id` = 183317;
INSERT INTO `serverside_spell` (`Id`, `Attributes`, `AttributesEx2`, `AttributesEx6`, `RangeIndex`, `EquippedItemClass`, `SpellName`, `SchoolMask`, `AuraInterruptFlags1`) VALUES
(183317, 134217984, 4, 1, 13, -1, 'CTF Tracking Aura', 1, 0x00080000 | 0x00020000 | 0x00100000); -- Removed when leaving world/mounting/stealth/invis

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 183317;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `Effect`, `EffectAura`) VALUES
(183317, 0, 6, 4);

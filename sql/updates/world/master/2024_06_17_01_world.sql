SET @OGUID := 7000316;
SET @ATID := 69;
SET @ATCP := 56;
SET @ATIDSPAWN := 70;
SET @SPAWNGROUP := 1251;
SET @WORLDSAFELOCID := 100042;

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+18;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 276643, 1754, 9164, 9640, '1,2,23,8', 0, 0, -1563.5816650390625, -1020.588623046875, 76.08814239501953125, 2.35677337646484375, 0, 0, 0.923990249633789062, 0.382416039705276489, 7200, 255, 1, 55142), -- Instance Portal (Area: Smuggler's Run - Difficulty: 0) CreateObject1
(@OGUID+1, 280662, 1771, 9327, 9327, '1,2,23,8', 0, 0, 79.2725677490234375, -2941.302001953125, -0.23841531574726104, 4.660104751586914062, 0, 0, -0.72534847259521484, 0.688381910324096679, 7200, 255, 1, 55142), -- Boat (Area: Tol Dagor - Difficulty: 0) CreateObject1
(@OGUID+2, 252245, 1771, 9327, 9327, '1,2,23,8', 0, 0, 79.109375, -2942.5244140625, 1.989225983619689941, 1.440670013427734375, 0, 0, 0.659636497497558593, 0.751584768295288085, 7200, 255, 1, 55142), -- Instance Portal (Area: Tol Dagor - Difficulty: 0) CreateObject1
(@OGUID+3, 252245, 1643, 10015, 10015, '0', 0, 0, 33.43229293823242187, -2658.704833984375, 27.01893424987792968, 5.491595268249511718, 0, 0, -0.38554191589355468, 0.922690331935882568, 120, 255, 1, 55142), -- Instance Portal (Area: Tol Dagor - Difficulty: 0) CreateObject1
(@OGUID+4, 252245, 1643, 8721, 9561, '0', 0, 0, 793.57989501953125, 3371.655517578125, 235.0142669677734375, 0, 0, 0, 0, 1, 120, 255, 1, 55142), -- Instance Portal (Area: Waycrest Manor - Difficulty: 0) CreateObject1
(@OGUID+5, 252245, 1862, 9424, 9424, '1,23,2,8', 0, 0, -634.33160400390625, -259.921875, 238.173828125, 0, 0, 0, 0, 1, 7200, 255, 1, 55142), -- Instance Portal (Area: Waycrest Manor - Difficulty: 0) CreateObject1
(@OGUID+6, 252248, 1643, 9042, 9767, '0', 0, 0, 4161.1318359375, -1140.779541015625, 164.7171478271484375, 1.737511277198791503, 0, 0, 0.763525962829589843, 0.64577716588973999, 120, 255, 1, 55142), -- Instance Portal (Area: Shrine of the Storm - Difficulty: 0) CreateObject1
(@OGUID+7, 252247, 1642, 8499, 8965, '0', 0, 0, -2647.25, 2388.3837890625, 10.04741477966308593, 3.517940521240234375, 0, 0, -0.98234748840332031, 0.187065258622169494, 120, 255, 1, 55142), -- Instance Portal (Area: Xibala - Difficulty: 0) CreateObject1
(@OGUID+8, 252247, 1594, 8064, 9729, '1,2,23,8', 0, 0, 630.34027099609375, -3620.70654296875, 3.562418222427368164, 5.49183511734008789, 0, 0, -0.38543128967285156, 0.922736525535583496, 7200, 255, 1, 55142), -- Instance Portal (Area: Platinum Sands - Difficulty: 0) CreateObject1
(@OGUID+9, 252248, 1642, 8499, 8731, '0', 0, 0, -848.28472900390625, 2044.1492919921875, 728.180908203125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 55142), -- Instance Portal (Area: Mount Mugamba - Difficulty: 0) CreateObject1
(@OGUID+10, 252237, 1642, 8499, 9404, '0', 0, 0, -848.59375, 2541.303955078125, 734.68096923828125, 4.717230796813964843, 0, 0, -0.70539283752441406, 0.7088165283203125, 120, 255, 1, 55142), -- Instance Portal (Area: Atal'Dazar - Difficulty: 0) CreateObject1
(@OGUID+11, 252247, 1642, 8500, 0, '0', 0, 0, 1257.55908203125, 747.90277099609375, -268.368682861328125, 0.762700915336608886, 0, 0, 0.372174263000488281, 0.928162872791290283, 120, 255, 1, 55142), -- Instance Portal (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+12, 252247, 1642, 8501, 0, '0', 0, 0, 3205.748291015625, 3151.78125, 124.6168594360351562, 0, 0, 0, 0, 1, 120, 255, 1, 55142), -- Instance Portal (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+13, 252247, 1877, 9527, 9527, '1,2,23,8', 0, 0, 3172.3203125, 3151, 125.0942001342773437, 0, 0, 0, 0, 1, 7200, 255, 1, 55142), -- Instance Portal (Area: Temple of Sethraliss - Difficulty: 0) CreateObject1
(@OGUID+14, 252248, 1642, 8499, 8665, '0', 0, 0, -2001.7882080078125, 967.2569580078125, 8.890947341918945312, 1.561707258224487304, 0, 0, 0.703886032104492187, 0.710312962532043457, 120, 255, 1, 55142), -- Instance Portal (Area: Port of Zandalar - Difficulty: 0) CreateObject1
(@OGUID+15, 252247, 1594, 8064, 9729, '1,2,23,8', 0, 0, 616.23785400390625, -3637.442626953125, 6.78265237808227539, 6.111760616302490234, 0, 0, -0.08560752868652343, 0.996328949928283691, 7200, 255, 1, 55142), -- Instance Portal (Area: Platinum Sands - Difficulty: 0) CreateObject1
(@OGUID+16, 252245, 1643, 8567, 9694, '0', 0, 0, -211.807296752929687, -1561.48095703125, 4.032770633697509765, 0.795597970485687255, 0, 0, 0.38739013671875, 0.921915888786315917, 120, 255, 1, 55142), -- Instance Portal (Area: Plunder Harbor - Difficulty: 0) CreateObject1
(@OGUID+17, 252245, 1822, 9354, 9354, '23,8,2', 0, 0, 1078.1754150390625, -590.232666015625, 2.224796772003173828, 1.598357081413269042, 0, 0, 0.716783523559570312, 0.697295784950256347, 7200, 255, 1, 55142), -- Instance Portal (Area: Siege of Boralus - Difficulty: 0) CreateObject1
(@OGUID+18, 252245, 1822, 9354, 9354, '23,8,2', 0, 0, 1070.451416015625, -626.623291015625, 19.12912750244140625, 0, 0, 0, 0, 1, 86400, 255, 1, 55142); -- Instance Portal (Area: Siege of Boralus - Difficulty: Heroic) CreateObject1

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @ATID+0 AND @ATID+23;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0),
(@ATID+1, 1, 1, 0),
(@ATID+2, 1, 1, 0),
(@ATID+3, 1, 1, 0),
(@ATID+4, 1, 1, 0),
(@ATID+5, 1, 1, 0),
(@ATID+6, 1, 1, 0),
(@ATID+7, 1, 1, 0),
(@ATID+8, 1, 1, 0),
(@ATID+9, 1, 1, 0),
(@ATID+10, 1, 1, 0),
(@ATID+11, 1, 1, 0),
(@ATID+12, 1, 1, 0),
(@ATID+13, 1, 1, 0),
(@ATID+14, 1, 1, 0),
(@ATID+15, 1, 1, 0),
(@ATID+16, 1, 1, 0),
(@ATID+17, 1, 1, 0),
(@ATID+18, 1, 1, 0),
(@ATID+19, 1, 1, 0),
(@ATID+20, 1, 1, 0),
(@ATID+21, 1, 1, 0),
(@ATID+22, 1, 1, 0),
(@ATID+23, 1, 1, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @ATID+0 AND @ATID+23;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 2, @WORLDSAFELOCID+0, 5),
(@ATID+1, 1, 2, @WORLDSAFELOCID+1, 5),
(@ATID+2, 1, 2, @WORLDSAFELOCID+2, 5),
(@ATID+3, 1, 2, @WORLDSAFELOCID+3, 5),
(@ATID+4, 1, 2, @WORLDSAFELOCID+4, 5),
(@ATID+5, 1, 2, @WORLDSAFELOCID+5, 5),
(@ATID+6, 1, 2, @WORLDSAFELOCID+6, 5),
(@ATID+7, 1, 2, @WORLDSAFELOCID+7, 5),
(@ATID+8, 1, 2, @WORLDSAFELOCID+8, 5),
(@ATID+9, 1, 2, @WORLDSAFELOCID+9, 5),
(@ATID+10, 1, 2, @WORLDSAFELOCID+10, 5),
(@ATID+11, 1, 2, @WORLDSAFELOCID+11, 5),
(@ATID+12, 1, 2, @WORLDSAFELOCID+12, 5),
(@ATID+13, 1, 2, @WORLDSAFELOCID+13, 5),
(@ATID+14, 1, 2, @WORLDSAFELOCID+14, 5),
(@ATID+15, 1, 2, @WORLDSAFELOCID+15, 5),
(@ATID+16, 1, 2, @WORLDSAFELOCID+16, 5),
(@ATID+17, 1, 2, @WORLDSAFELOCID+17, 5),
(@ATID+18, 1, 2, @WORLDSAFELOCID+18, 5),
(@ATID+19, 1, 2, @WORLDSAFELOCID+19, 5),
(@ATID+20, 1, 2, @WORLDSAFELOCID+20, 5),
(@ATID+21, 1, 2, @WORLDSAFELOCID+21, 5),
(@ATID+22, 1, 2, @WORLDSAFELOCID+22, 5),
(@ATID+23, 1, 2, @WORLDSAFELOCID+23, 5);

DELETE FROM `areatrigger_create_properties` WHERE `Id` BETWEEN @ATCP+0 AND @ATCP+23;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 3, 4, 5, 3, 4, 5, 0, 0, '', 0), -- Siege of Boralus (A) entrance
(@ATCP+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 3, 3, 5, 3, 3, 5, 0, 0, '', 0), -- Siege of Boralus (A) exit
(@ATCP+2, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 5, 8, 8, 5, 8, 8, 0, 0, '', 0), -- Freehold entrance
(@ATCP+3, 1, @ATID+3, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 5, 10, 8, 5, 10, 8, 0, 0, '', 0), -- Freehold exit
(@ATCP+4, 1, @ATID+4, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 1, 2, 5, 1, 2, 5, 0, 0, '', 0), -- Tol Dagor entrance
(@ATCP+5, 1, @ATID+5, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 2, 2, 5, 2, 2, 5, 0, 0, '', 0), -- Tol Dagor exit
(@ATCP+6, 1, @ATID+6, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 1, 3, 5, 1, 3, 5, 0, 0, '', 0), -- Waycrest Manor entrance
(@ATCP+7, 1, @ATID+7, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 2, 4, 5, 2, 4, 5, 0, 0, '', 0), -- Waycrest Manor exit
(@ATCP+8, 1, @ATID+8, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 4, 8, 4, 4, 8, 0, 0, '', 0), -- Shrine of Storms entrance
(@ATCP+9, 1, @ATID+9, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 5, 8, 4, 5, 8, 0, 0, '', 0), -- Shrine of Storms exit
(@ATCP+10, 1, @ATID+10, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 6, 10, 4, 6, 10, 0, 0, '', 0), -- Motherlode (A) entrance
(@ATCP+11, 1, @ATID+11, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 8, 10, 4, 8, 10, 0, 0, '', 0), -- Motherlode (A) exit
(@ATCP+12, 1, @ATID+12, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 3, 6, 15, 3, 6, 15, 0, 0, '', 0), -- Atal Dazar entrance
(@ATCP+13, 1, @ATID+13, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 3, 6, 15, 3, 6, 15, 0, 0, '', 0), -- Atal Dazar exit
(@ATCP+14, 1, @ATID+14, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 5, 16, 20, 5, 16, 20, 0, 0, '', 0), -- KingsRest entrance
(@ATCP+15, 1, @ATID+15, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 5, 16, 15, 5, 16, 15, 0, 0, '', 0), -- KingsRest exit
(@ATCP+16, 1, @ATID+16, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 18, 20, 4, 18, 20, 0, 0, '', 0), -- Underrot entrance
(@ATCP+17, 1, @ATID+17, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 18, 20, 4, 18, 20, 0, 0, '', 0), -- Underrot exit
(@ATCP+18, 1, @ATID+18, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 8, 20, 4, 8, 20, 0, 0, '', 0), -- Temple of Sethraliss entrance
(@ATCP+19, 1, @ATID+19, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 8, 20, 4, 8, 20, 0, 0, '', 0), -- Temple of Sethraliss exit
(@ATCP+20, 1, @ATID+20, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 3, 6, 20, 3, 6, 20, 0, 0, '', 0), -- Motherlode (H) entrance
(@ATCP+21, 1, @ATID+21, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 4, 10, 10, 4, 10, 10, 0, 0, '', 0), -- Motherlode (H) exit
(@ATCP+22, 1, @ATID+22, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 2, 4, 15, 2, 4, 15, 0, 0, '', 0), -- Siege of Boralus (H) entrance
(@ATCP+23, 1, @ATID+23, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 3, 8, 10, 3, 8, 10, 0, 0, '', 0); -- Siege of Boralus (H) exit

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+23;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1643, '0', 1149.427, -554.867, 1.699, 1.375182, 0, 0, 0, '', '8.x Dungeon - Siege of Boralus - Entrance', 0),
(@ATIDSPAWN+1, @ATCP+1, 1, 1822, '23,8,2', 1068.079, -626.600, 17.993, 3.164860, 0, 0, 0, '', '8.x Dungeon - Siege of Boralus - Exit', 0),
(@ATIDSPAWN+2, @ATCP+2, 1, 1643, '0', -1587.766, -1274.649, 36.3525, 5.097314, 0, 0, 0, '', '8.x Dungeon - Freehold - Entrance', 0),
(@ATIDSPAWN+3, @ATCP+3, 1, 1754, '1,2,23,8', -1562.680, -1019.890, 73.518, 5.533423, 0, 0, 0, '', '8.x Dungeon - Freehold - Exit', 0),
(@ATIDSPAWN+4, @ATCP+4, 1, 1643, '0', 33.886, -2658.966, 26.349, 5.665448, 0, 0, 0, '', '8.x Dungeon - Tol Dagor - Entrance', 0),
(@ATIDSPAWN+5, @ATCP+5, 1, 1771, '1,2,23,8', 79.330, -2942.568, 0.385, 4.662903, 0, 0, 0, '', '8.x Dungeon - Tol Dagor - Exit', 0),
(@ATIDSPAWN+6, @ATCP+6, 1, 1643, '0', 794.152, 3371.817, 234.490, 6.174334, 0, 0, 0, '', '8.x Dungeon - Waycrest Manor - Entrance', 0),
(@ATIDSPAWN+7, @ATCP+7, 1, 1862, '1,2,23,8', -634.967, -259.9255, 236.156, 3.127803, 0, 0, 0, '', '8.x Dungeon - Waycrest Manor - Exit', 0),
(@ATIDSPAWN+8, @ATCP+8, 1, 1643, '0', 4161.641, -1142.632, 164.774, 4.822304, 0, 0, 0, '', '8.x Dungeon - Shrine of Storms - Entrance', 0),
(@ATIDSPAWN+9, @ATCP+9, 1, 1864, '1,2,23,8', 4167.192, -1220.847, 187.712, 1.577227, 0, 0, 0, '', '8.x Dungeon - Shrine of Storms - Exit', 0),
(@ATIDSPAWN+10, @ATCP+10, 1, 1642, '0', -2646.077, 2389.278, 8.7910, 0.205582, 0, 0, 0, '', '8.x Dungeon - Motherlode (Alliance) - Entrance', 0),
(@ATIDSPAWN+11, @ATCP+11, 1, 1594, '1,2,23,8', 626.649, -3619.271, -0.8169, 2.221698, 0, 0, 0, '', '8.x Dungeon - Motherlode (Alliance) - Exit', 0),
(@ATIDSPAWN+12, @ATCP+12, 1, 1642, '0', -848.366, 2044.2585, 726.1221, 1.564042, 0, 0, 0, '', '8.x Dungeon - Atal Dazar - Entrance', 0),
(@ATIDSPAWN+13, @ATCP+13, 1, 1763, '1,2,23,8', -848.193, 2043.196, 726.1222, 4.705334, 0, 0, 0, '', '8.x Dungeon - Atal Dazar - Exit', 0),
(@ATIDSPAWN+14, @ATCP+14, 1, 1642, '0', -848.042, 2542.115, 732.573, 1.573840, 0, 0, 0, '', '8.x Dungeon - KingsRest - Entrance', 0),
(@ATIDSPAWN+15, @ATCP+15, 1, 1762, '23,8,2', -945.247, 2521.6589, 833.5416, 4.739499, 0, 0, 0, '', '8.x Dungeon - KingsRest - Exit', 0),
(@ATIDSPAWN+16, @ATCP+16, 1, 1642, '0', 1258.614, 748.319, -273.2040, 0.756919, 0, 0, 0, '', '8.x Dungeon - Underrot - Entrance', 0),
(@ATIDSPAWN+17, @ATCP+17, 1, 1841, '1,2,23,8', 615.851, 1256.516, 100.362, 2.7162, 0, 0, 0, '', '8.x Dungeon - Underrot - Exit', 0),
(@ATIDSPAWN+18, @ATCP+18, 1, 1642, '0', 3208.812, 3151.754, 121.34663, 0.010269, 0, 0, 0, '', '8.x Dungeon - Temple of Sethraliss - Entrance', 0),
(@ATIDSPAWN+19, @ATCP+19, 1, 1877, '1,2,23,8', 3169.462, 3150.905, 121.6228, 3.082911, 0, 0, 0, '', '8.x Dungeon - Temple of Sethraliss - Exit', 0),
(@ATIDSPAWN+20, @ATCP+20, 1, 1642, '0', -2001.899, 967.272, 6.2339, 1.542327, 0, 0, 0, '', '8.x Dungeon - Motherlode (Horde) - Entrance', 0),
(@ATIDSPAWN+21, @ATCP+21, 1, 1594, '1,2,23,8', 614.331, -3637.275, 4.1750, 2.9619, 0, 0, 0, '', '8.x Dungeon - Motherlode (Horde) - Exit', 0),
(@ATIDSPAWN+22, @ATCP+22, 1, 1643, '0', -211.818, -1562.208, 2.8376, 3.846468, 0, 0, 0, '', '8.x Dungeon - Siege of Boralus (Horde) - Entrance', 0),
(@ATIDSPAWN+23, @ATCP+23, 1, 1822, '23,8,2', 1074.387, -588.369, 1.0748, 1.602863, 0, 0, 0, '', '8.x Dungeon - Siege of Boralus (Horde) - Exit', 0);

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLDSAFELOCID+0 AND @WORLDSAFELOCID+23;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `COMMENT`) VALUES
(@WORLDSAFELOCID+0, 1822, 1084.48, -617.952, 17.5513, 0.42834568, '8.x Dungeon - Siege of Boralus - Entrance'),
(@WORLDSAFELOCID+1, 1643, 1138.77, -575.858, 1.1963, 4.4846063, '8.x Dungeon - Siege of Boralus - Exit'),
(@WORLDSAFELOCID+2, 1754, -1586.72, -1002.61, 73.4672, 2.866721, '8.x Dungeon - Freehold - Entrance'),
(@WORLDSAFELOCID+3, 1643, -1580.16, -1293.06, 34.3126, 5.385859, '8.x Dungeon - Freehold - Exit'),
(@WORLDSAFELOCID+4, 1771, 85.2528, -2933.52, 1.37269, 1.3391021, '8.x Dungeon - Tol Dagor - Entrance'),
(@WORLDSAFELOCID+5, 1643, 26.1921, -2650.23, 23.5238, 2.5878694, '8.x Dungeon - Tol Dagor - Exit'),
(@WORLDSAFELOCID+6, 1862, -626.408, -260.15103, 236.03317, 0.072306424, '8.x Dungeon - Waycrest Manor - Entrance'),
(@WORLDSAFELOCID+7, 1643, 789.7552, 3372.0774, 232.72673, 3.067398, '8.x Dungeon - Waycrest Manor - Exit'),
(@WORLDSAFELOCID+8, 1864, 4167.202, -1238.5278, 186.89357, 4.73095, '8.x Dungeon - Shrine of Storms - Entrance'),
(@WORLDSAFELOCID+9, 1643, 4151.3, -1097, 158.385, 1.7824349, '8.x Dungeon - Shrine of Storms - Exit'),
(@WORLDSAFELOCID+10, 1594, 630.774, -3640.81, 1.74989, 6.0063233, '8.x Dungeon - Motherlode (Alliance) - Entrance'),
(@WORLDSAFELOCID+11, 1642, -2653.96, 2387.93, 5.05817, 3.607927, '8.x Dungeon - Motherlode (Alliance) - Exit'),
(@WORLDSAFELOCID+12, 1763, -848.363, 2082.47, 725.146, 1.5707964, '8.x Dungeon - Atal Dazar - Entrance'),
(@WORLDSAFELOCID+13, 1642, -848.42, 2028.05, 726.19, 4.7006083, '8.x Dungeon - Atal Dazar - Exit'),
(@WORLDSAFELOCID+14, 1762, -945.114, 2544.25, 833.052, 1.578214, '8.x Dungeon - KingsRest - Entrance'),
(@WORLDSAFELOCID+15, 1642, -848.205, 2515.88, 730.225, 4.752863, '8.x Dungeon - KingsRest - Exit'),
(@WORLDSAFELOCID+16, 1841, 636.715, 1253.03, 98.588, 6.232135, '8.x Dungeon - Underrot - Entrance'),
(@WORLDSAFELOCID+17, 1642, 1242.41, 736.916, -271.521, 3.843372, '8.x Dungeon - Underrot - Exit'),
(@WORLDSAFELOCID+18, 1877, 3199.21, 3151.17, 121.316, 6.275331, '8.x Dungeon - Temple of Sethraliss - Entrance'),
(@WORLDSAFELOCID+19, 1642, 3196.15, 3151.61, 121.654, 3.1415577, '8.x Dungeon - Temple of Sethraliss - Exit'),
(@WORLDSAFELOCID+20, 1594, 630.774, -3640.81, 1.74989, 6.0063233, '8.x Dungeon - Motherlode (H) - Entrance'),
(@WORLDSAFELOCID+21, 1642, -2002.65, 959.031, 5.93225, 4.740838, '8.x Dungeon - Motherlode (H) - Exit'),
(@WORLDSAFELOCID+22, 1822, 1080.03, -604.543, 0.985657, 4.8422937, '8.x Dungeon - Siege of Boralus (H) - Entrance'),
(@WORLDSAFELOCID+23, 1643, -204.47, -1550.87, 2.95007, 0.7578639, '8.x Dungeon - Siege of Boralus (H) - Exit');

-- Spawngroups
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+3;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Siege of Boralus - Alliance spawns', 32),
(@SPAWNGROUP+1, 'Siege of Boralus - Horde spawns', 32),
(@SPAWNGROUP+2, 'Motherlode - Alliance spawns', 32),
(@SPAWNGROUP+3, 'Motherlode - Horde spawns', 32);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+3 AND `spawnType`= 1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 1, @OGUID+18),
(@SPAWNGROUP+1, 1, @OGUID+17),
(@SPAWNGROUP+2, 1, @OGUID+8),
(@SPAWNGROUP+3, 1, @OGUID+15);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceGroup` = 0 AND `SourceEntry` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Siege of Boralus - Spawn Alliance NPCs if you are Alliance Player'),
(33, 0, @SPAWNGROUP+1, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Siege of Boralus - Spawn Horde NPCs if you are Horde Player'),
(33, 0, @SPAWNGROUP+2, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'Motherlode - Spawn Alliance NPCs if you are Alliance Player'),
(33, 0, @SPAWNGROUP+3, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'Motherlode - Spawn Horde NPCs if you are Horde Player');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 28 AND `SourceGroup` IN (@ATID+1, @ATID+23, @ATID+11, @ATID+21) AND `SourceEntry` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+1, 1, 0, 0, 6, 0, 469, 0, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when player is Alliance'),
(28, @ATID+23, 1, 0, 0, 6, 0, 67, 0, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when player is Horde'),
(28, @ATID+11, 1, 0, 0, 6, 0, 469, 0, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when player is Alliance'),
(28, @ATID+21, 1, 0, 0, 6, 0, 67, 0, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when player is Horde');

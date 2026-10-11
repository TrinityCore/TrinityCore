SET @OGUID := 3000045;
SET @SPAWN_GROUP := 1280;

DELETE FROM `battleground_scripts` WHERE `MapId` = 980 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(980, 0, 'arena_tol_viron_arena');

DELETE FROM `battleground_template` WHERE `ID` = 719;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(719, 4137, 4136, 0, 1, 'Tol''Viron Arena');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Tol''Viron Arena - Shadow sight', 0x20);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 174863, 980, 6296, 6296, '0', '0', 0, -10702.828125, 915.14263916015625, 26.43194770812988281, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 7200, 255, 1, 63305), -- Stove (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+1, 213197, 980, 6296, 6296, '0', '0', 0, -10774.611328125, 431.23828125, 23.54276275634765625, 0, 0, 0, 0, 1, 7200, 255, 1, 63305), -- Arena Door (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+2, 213196, 980, 6296, 6296, '0', '0', 0, -10654.30078125, 428.3046875, 23.54276275634765625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Arena Door (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+3, 174863, 980, 6296, 6296, '0', '0', 0, -10698.638671875, 1078.226806640625, 25.42545700073242187, 0.584681987762451171, -0.00155210494995117, 0.000661849975585937, 0.288195610046386718, 0.957570075988769531, 7200, 255, 1, 63305), -- Stove (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+4, 160409, 980, 6296, 6296, '0', '0', 0, -10703.166015625, 917.15948486328125, 26.689788818359375, 4.860742568969726562, 0, 0, -0.65275955200195312, 0.757565200328826904, 7200, 255, 1, 63305), -- Chair (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+5, 160410, 980, 6296, 6296, '0', '0', 0, -10701.15625, 916.4442138671875, 26.689788818359375, 3.848456144332885742, 0, 0, -0.93819046020507812, 0.346119433641433715, 7200, 255, 1, 63305), -- Chair (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+6, 160409, 980, 6296, 6296, '0', '0', 0, -10698.5322265625, 1080.269775390625, 25.67640495300292968, 4.642578601837158203, -0.00128030776977539, -0.0010986328125, -0.73135185241699218, 0.681998252868652343, 7200, 255, 1, 63305), -- Chair (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+7, 160410, 980, 6296, 6296, '0', '0', 0, -10696.724609375, 1079.136474609375, 25.67953109741210937, 3.630285263061523437, -0.00058650970458984, -0.00158119201660156, -0.97029399871826171, 0.241922914981842041, 7200, 255, 1, 63305), -- Chair (Area: Tol'viron Arena - Difficulty: 0) CreateObject1
(@OGUID+8, 184663, 980, 6296, 6296, '0', '0', 0, -10715.2392578125, 484.53472900390625, 24.69634437561035156, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305), -- Shadow Sight (Area: Tol'viron Arena - Difficulty: 0) CreateObject2
(@OGUID+9, 184664, 980, 6296, 6296, '0', '0', 0, -10715.873046875, 375.99652099609375, 24.44685173034667968, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 360, 255, 1, 63305); -- Shadow Sight (Area: Tol'viron Arena - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.995804905891418457, -0.0915016159415245, 0, 0), -- Stove
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Arena Door
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Arena Door
(@OGUID+3, 0.000157425383804365, 0.001680092304013669, 0.999846339225769042, 0.01745205745100975, 0, 0), -- Stove
(@OGUID+4, 0, 0, 0.995804905891418457, -0.0915016159415245, 0, 0), -- Chair
(@OGUID+5, 0, 0, 0.995804905891418457, -0.0915016159415245, 0, 0), -- Chair
(@OGUID+6, 0.000157425383804365, 0.001680092304013669, 0.999846339225769042, 0.01745205745100975, 0, 0), -- Chair
(@OGUID+7, 0.000157425383804365, 0.001680092304013669, 0.999846339225769042, 0.01745205745100975, 0, 0); -- Chair

UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=0x20 WHERE `entry` IN (213196, 213197); -- Arena Door

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+8),
(@SPAWN_GROUP, 1, @OGUID+9);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

SET @OGUID := 4000246;
SET @SPAWN_GROUP := 1281;

DELETE FROM `battleground_scripts` WHERE `MapId` = 1134 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(1134, 0, 'arena_tigers_peak');

DELETE FROM `battleground_template` WHERE `ID` = 757;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(757, 4535, 4534, 0, 1, 'The Tigers Peak');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Tigers Peak - Shadow sight', 0x20);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 219395, 1134, 6732, 6732, '0', '0', 0, 502.437042236328125, 633.0946044921875, 380.65478515625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Door (Area: The Tiger's Peak - Difficulty: 0) CreateObject1
(@OGUID+1, 219396, 1134, 6732, 6732, '0', '0', 0, 632.4952392578125, 633.09466552734375, 380.65478515625, 0, 0, 0, 0, 1, 7200, 255, 1, 63305), -- Door (Area: The Tiger's Peak - Difficulty: 0) CreateObject1
(@OGUID+2, 184663, 1134, 6732, 6732, '0', '0', 0, 566.65625, 664.56597900390625, 383.680908203125, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305), -- Shadow Sight (Area: The Tiger's Peak - Difficulty: 0) CreateObject2
(@OGUID+3, 184664, 1134, 6732, 6732, '0', '0', 0, 566.6805419921875, 602.2274169921875, 383.6812744140625, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 360, 255, 1, 63305); -- Shadow Sight (Area: The Tiger's Peak - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0); -- Door

UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=0x20 WHERE `entry` IN (219396, 219395); -- Door

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+2),
(@SPAWN_GROUP, 1, @OGUID+3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

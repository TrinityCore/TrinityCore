SET @CGUID := 8000870;
SET @OGUID := 8000141 ;
SET @WORLD_SAFE_LOC_ID := 100107;
SET @SPAWN_GROUP := 1283;

SET @AT_ID := 181;
SET @AT_PROP_ID := 172;
SET @AT_SPAWN_ID := 277;

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @AT_ID+0 AND @AT_ID+1 AND `IsCustom` = 1;
INSERT INTO `areatrigger_template` (`ID`, `IsCustom`, `Flags`) VALUES
(@AT_ID+0, 1, 0x1),
(@AT_ID+1, 1, 0x1);

DELETE FROM `areatrigger_create_properties` WHERE `Id` BETWEEN @AT_PROP_ID+0 AND @AT_PROP_ID+1 and `IsCustom` = 1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Shape`, `ShapeData0`, `ShapeData1`, `ScriptName`) VALUES
(@AT_PROP_ID+0, 1, @AT_ID+0, 1, 0, 5, 5, ''),
(@AT_PROP_ID+1, 1, @AT_ID+1, 1, 0, 25, 25, '');

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @AT_SPAWN_ID+0 AND @AT_SPAWN_ID+3 and `IsCustom` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`) VALUES
(@AT_SPAWN_ID+0, @AT_PROP_ID+0, 1, 2373, -1318.0222, 797.89947, 7266, 0),
(@AT_SPAWN_ID+1, @AT_PROP_ID+0, 1, 2373, -1182.7753, 663.14099, 7266, 0),
(@AT_SPAWN_ID+2, @AT_PROP_ID+1, 1, 2373, -1331.0243, 811.23785, 7266, 0),
(@AT_SPAWN_ID+3, @AT_PROP_ID+1, 1, 2373, -1168.4149, 648.90625, 7266, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = @AT_ID+1 AND `IsCustom` = 1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@AT_ID+1, 1, 0, 228212, 0); -- Arena Starting Area Marker

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLD_SAFE_LOC_ID + 0 AND @WORLD_SAFE_LOC_ID + 1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WORLD_SAFE_LOC_ID+0, 2373, -1331.0243, 811.23785, 7266.021, DEGREES(5.4997163), 'Empyrean Domain - Purple Team'),
(@WORLD_SAFE_LOC_ID+1, 2373, -1168.4149, 648.90625, 7266.021, DEGREES(2.373393), 'Empyrean Domain - Gold Team');

DELETE FROM `battleground_scripts` WHERE `MapId` = 2373 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(2373, 0, 'arena_empyrean_domain');

DELETE FROM `battleground_template` WHERE `ID` = 1041;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(1041, @WORLD_SAFE_LOC_ID+0, @WORLD_SAFE_LOC_ID+1, 0, 1, 'Empyrean Domain');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Empyrean Domain - Shadow sight', 0x20);

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (353495 /*Door*/, 352927 /*Collision Wall*/, 353497 /*Door*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(353495, 1375, 0x20, 0, 0), -- Door
(352927, 0, 0x2000, 0, 0), -- Collision Wall
(353497, 1375, 0x20, 0, 0); -- Door

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 169468, 2373, 13428, 13428, '0', '0', 0, 0, 0, -1179.140625, 659.29168701171875, 7266.06298828125, 5.461753368377685546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Invisible Stalker (Area: Empyrean Domain - Difficulty: 0) CreateObject1 (Auras: 329804 - Wind Drift)
(@CGUID+1, 169472, 2373, 13428, 13428, '0', '0', 0, 0, 1, -1184.1597900390625, 665.7742919921875, 7266.1708984375, 4.923828601837158203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@CGUID+2, 169472, 2373, 13428, 13428, '0', '0', 0, 0, 1, -1316.0677490234375, 793.80035400390625, 7266.1708984375, 2.083611249923706054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@CGUID+3, 169472, 2373, 13428, 13428, '0', '0', 0, 0, 1, -1314.3038330078125, 795.30206298828125, 7266.05224609375, 2.815283060073852539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@CGUID+4, 169472, 2373, 13428, 13428, '0', '0', 0, 0, 1, -1185.5052490234375, 664.28472900390625, 7266.30859375, 6.134205818176269531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@CGUID+5, 169468, 2373, 13428, 13428, '0', '0', 0, 0, 0, -1320.8663330078125, 800.67706298828125, 7266.05224609375, 2.387862682342529296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Invisible Stalker (Area: Empyrean Domain - Difficulty: 0) CreateObject1 (Auras: 329804 - Wind Drift)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+56;

UPDATE `creature` SET `StringId` = 'empyrean_domain_guard_01' WHERE `guid` = @CGUID+1;
UPDATE `creature` SET `StringId` = 'empyrean_domain_guard_02' WHERE `guid` = @CGUID+2;
UPDATE `creature` SET `StringId` = 'empyrean_domain_guard_03' WHERE `guid` = @CGUID+3;
UPDATE `creature` SET `StringId` = 'empyrean_domain_guard_04' WHERE `guid` = @CGUID+4;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 353497, 2373, 13428, 13428, '0', '0', 0, -543.6697998046875, 812.83056640625, 7139.91943359375, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 7200, 255, 1, 63305), -- Door (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+1, 352927, 2373, 13428, 13428, '0', '0', 0, -1181.173583984375, 667.8125, 7265.3173828125, 4.696715354919433593, 0, 0, -0.71262645721435546, 0.701543688774108886, 7200, 255, 1, 63305), -- Collision Wall (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+2, 352927, 2373, 13428, 13428, '0', '0', 0, -1187.3941650390625, 660.578125, 7265.19970703125, 6.261324882507324218, 0, 0, -0.01093006134033203, 0.999940276145935058, 7200, 255, 1, 63305), -- Collision Wall (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+3, 352927, 2373, 13428, 13428, '0', '0', 0, -1314.7916259765625, 794.357666015625, 7259.49951171875, 5.463855266571044921, 0, 0, -0.39830207824707031, 0.917254269123077392, 7200, 255, 1, 63305), -- Collision Wall (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+4, 352927, 2373, 13428, 13428, '0', '0', 0, -1319.0833740234375, 792.38543701171875, 7261.0439453125, 1.522531628608703613, 0, 0, 0.689838409423828125, 0.723963379859924316, 7200, 255, 1, 63305), -- Collision Wall (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+5, 352927, 2373, 13428, 13428, '0', '0', 0, -1312.6805419921875, 799.22918701171875, 7260.9267578125, 3.0871124267578125, 0, 0, 0.999629020690917968, 0.027236729860305786, 7200, 255, 1, 63305), -- Collision Wall (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+6, 352927, 2373, 13428, 13428, '0', '0', 0, -1185.5538330078125, 665.75, 7264.8837890625, 5.463855266571044921, 0, 0, -0.39830207824707031, 0.917254269123077392, 7200, 255, 1, 63305), -- Collision Wall (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+7, 352927, 2373, 13428, 13428, '0', '0', 0, -1314.68408203125, 794.125, 7260.9267578125, 2.289668798446655273, 0, 0, 0.910641670227050781, 0.413196951150894165, 7200, 255, 1, 63305), -- Collision Wall (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+8, 353495, 2373, 13428, 13428, '0', '0', 0, -942.49676513671875, -349.16644287109375, 7313.7900390625, 3.115387916564941406, 0, 0, 0.999914169311523437, 0.013101960532367229, 7200, 255, 1, 63305), -- Door (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+9, 353497, 2373, 13428, 13428, '0', '0', 0, -1038.48779296875, -346.65277099609375, 7313.7900390625, 3.115387916564941406, 0, 0, 0.999914169311523437, 0.013101960532367229, 7200, 255, 1, 63305), -- Door (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+10, 353495, 2373, 13428, 13428, '0', '0', 0, -455.27923583984375, 850.35015869140625, 7139.91943359375, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 7200, 255, 1, 63305), -- Door (Area: Empyrean Domain - Difficulty: 0) CreateObject1
(@OGUID+11, 184663, 2373, 13428, 13428, '0', '0', 0, -1216.71533203125, 764.11981201171875, 7249.49072265625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305), -- Shadow Sight (Area: Empyrean Domain - Difficulty: 0) CreateObject2
(@OGUID+12, 184664, 2373, 13428, 13428, '0', '0', 0, -1284.453125, 696.36981201171875, 7249.49072265625, 0.706303238868713378, 0, 0, 0.345856666564941406, 0.938287317752838134, 360, 255, 1, 63305); -- Shadow Sight (Area: Empyrean Domain - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.833885848522186279, 0.551936984062194824, 0, 0), -- Door
(@OGUID+8, 0, 0, 0.697790205478668212, 0.716302275657653808, 0, 0), -- Door
(@OGUID+9, 0, 0, 0.697790205478668212, 0.716302275657653808, 0, 0), -- Door
(@OGUID+10, 0, 0, 0.833885848522186279, 0.551936984062194824, 0, 0); -- Door

DELETE FROM `creature_template_addon` WHERE `entry` IN (169472 /*169472 (Guard)*/, 169468 /*169468 (Invisible Stalker)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(169472, 0, 0, 0, 0, 0, 1, 0, 0, 14502, 0, 0, 0, ''), -- 169472 (Guard)
(169468, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 169468 (Invisible Stalker)

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+11),
(@SPAWN_GROUP, 1, @OGUID+12);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=169472 AND `DifficultyID`=0); -- 169472 (Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63305 WHERE (`Entry`=169468 AND `DifficultyID`=0); -- 169468 (Invisible Stalker) - Sessile, Floating

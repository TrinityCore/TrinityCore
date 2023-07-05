-- Arathi Basin Spawns. Build: 44325

SET @CGUID := 850952;
SET @OGUID := 502216;
SET @POOL := 800000;

SET @SPAWNGROUP_HORDE_FARM := 1000;
SET @SPAWNGROUP_HORDE_LUMBERMILL := 1001;
SET @SPAWNGROUP_HORDE_BLACKSMITH := 1002;
SET @SPAWNGROUP_HORDE_STABLES := 1003;
SET @SPAWNGROUP_HORDE_GOLDMINE := 1004;
SET @SPAWNGROUP_ALLIANCE_FARM := 1005;
SET @SPAWNGROUP_ALLIANCE_LUMBERMILL := 1006;
SET @SPAWNGROUP_ALLIANCE_BLACKSMITH := 1007;
SET @SPAWNGROUP_ALLIANCE_STABLES := 1008;
SET @SPAWNGROUP_ALLIANCE_GOLDMINE := 1009;
-- graveyards get their own spawn group as they should be despawned when condition fails and new guids should be generated
SET @SPAWNGROUP_HORDE_FARM_GRAVEYARD := 1010;
SET @SPAWNGROUP_HORDE_LUMBERMILL_GRAVEYARD := 1011;
SET @SPAWNGROUP_HORDE_BLACKSMITH_GRAVEYARD := 1012;
SET @SPAWNGROUP_HORDE_STABLES_GRAVEYARD := 1013;
SET @SPAWNGROUP_HORDE_GOLDMINE_GRAVEYARD := 1014;
SET @SPAWNGROUP_ALLIANCE_FARM_GRAVEYARD := 1015;
SET @SPAWNGROUP_ALLIANCE_LUMBERMILL_GRAVEYARD := 1016;
SET @SPAWNGROUP_ALLIANCE_BLACKSMITH_GRAVEYARD := 1017;
SET @SPAWNGROUP_ALLIANCE_STABLES_GRAVEYARD := 1018;
SET @SPAWNGROUP_ALLIANCE_GOLDMINE_GRAVEYARD := 1019;

UPDATE `battleground_template` SET `Comment` = 'Arathi Basin - Classic' WHERE `ID`=3;
DELETE FROM `battleground_template` WHERE `ID`=1018;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `Weight`, `ScriptName`, `Comment`) VALUES
(1018, 7056, 7055, 1, '', 'Arathi Basin');

DELETE FROM `spawn_group_template` WHERE `groupId` IN (@SPAWNGROUP_HORDE_FARM, @SPAWNGROUP_HORDE_LUMBERMILL, @SPAWNGROUP_HORDE_BLACKSMITH, @SPAWNGROUP_HORDE_STABLES,
    @SPAWNGROUP_HORDE_GOLDMINE, @SPAWNGROUP_ALLIANCE_FARM, @SPAWNGROUP_ALLIANCE_LUMBERMILL, @SPAWNGROUP_ALLIANCE_BLACKSMITH, @SPAWNGROUP_ALLIANCE_STABLES, @SPAWNGROUP_ALLIANCE_GOLDMINE,
    @SPAWNGROUP_HORDE_FARM_GRAVEYARD, @SPAWNGROUP_HORDE_LUMBERMILL_GRAVEYARD, @SPAWNGROUP_HORDE_BLACKSMITH_GRAVEYARD, @SPAWNGROUP_HORDE_STABLES_GRAVEYARD,
    @SPAWNGROUP_HORDE_GOLDMINE_GRAVEYARD, @SPAWNGROUP_ALLIANCE_FARM_GRAVEYARD, @SPAWNGROUP_ALLIANCE_LUMBERMILL_GRAVEYARD, @SPAWNGROUP_ALLIANCE_BLACKSMITH_GRAVEYARD, @SPAWNGROUP_ALLIANCE_STABLES_GRAVEYARD, @SPAWNGROUP_ALLIANCE_GOLDMINE_GRAVEYARD);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP_HORDE_FARM, 'Arathi Basin - Farm - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_LUMBERMILL, 'Arathi Basin - Lumber Mill - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_BLACKSMITH, 'Arathi Basin - Blacksmith - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_STABLES, 'Arathi Basin - Stables - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_GOLDMINE, 'Arathi Basin - Gold Mine - Horde Controlled', 32),
(@SPAWNGROUP_ALLIANCE_FARM, 'Arathi Basin - Farm - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 'Arathi Basin - Lumber Mill - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 'Arathi Basin - Blacksmith - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_STABLES, 'Arathi Basin - Stables - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 'Arathi Basin - Gold Mine - Alliance Controlled', 32),
(@SPAWNGROUP_HORDE_FARM_GRAVEYARD, 'Arathi Basin - Farm Graveyard - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_LUMBERMILL_GRAVEYARD, 'Arathi Basin - Lumber Mill Graveyard - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_BLACKSMITH_GRAVEYARD, 'Arathi Basin - Blacksmith Graveyard - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_STABLES_GRAVEYARD, 'Arathi Basin - Stables Graveyard - Horde Controlled', 32),
(@SPAWNGROUP_HORDE_GOLDMINE_GRAVEYARD, 'Arathi Basin - Gold Mine Graveyard - Horde Controlled', 32),
(@SPAWNGROUP_ALLIANCE_FARM_GRAVEYARD, 'Arathi Basin - Farm Graveyard - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL_GRAVEYARD, 'Arathi Basin - Lumber Mill Graveyard - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH_GRAVEYARD, 'Arathi Basin - Blacksmith Graveyard - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_STABLES_GRAVEYARD, 'Arathi Basin - Stables Graveyard - Alliance Controlled', 32),
(@SPAWNGROUP_ALLIANCE_GOLDMINE_GRAVEYARD, 'Arathi Basin - Gold Mine Graveyard - Alliance Controlled', 32);

-- Spawn Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` IN (@SPAWNGROUP_HORDE_FARM, @SPAWNGROUP_HORDE_LUMBERMILL, @SPAWNGROUP_HORDE_BLACKSMITH, @SPAWNGROUP_HORDE_STABLES,
    @SPAWNGROUP_HORDE_GOLDMINE, @SPAWNGROUP_ALLIANCE_FARM, @SPAWNGROUP_ALLIANCE_LUMBERMILL, @SPAWNGROUP_ALLIANCE_BLACKSMITH, @SPAWNGROUP_ALLIANCE_STABLES, @SPAWNGROUP_ALLIANCE_GOLDMINE,
    @SPAWNGROUP_HORDE_FARM_GRAVEYARD, @SPAWNGROUP_HORDE_LUMBERMILL_GRAVEYARD, @SPAWNGROUP_HORDE_BLACKSMITH_GRAVEYARD, @SPAWNGROUP_HORDE_STABLES_GRAVEYARD,
    @SPAWNGROUP_HORDE_GOLDMINE_GRAVEYARD, @SPAWNGROUP_ALLIANCE_FARM_GRAVEYARD, @SPAWNGROUP_ALLIANCE_LUMBERMILL_GRAVEYARD, @SPAWNGROUP_ALLIANCE_BLACKSMITH_GRAVEYARD, @SPAWNGROUP_ALLIANCE_STABLES_GRAVEYARD, @SPAWNGROUP_ALLIANCE_GOLDMINE_GRAVEYARD);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP_HORDE_FARM, 0, 0, 11, 0, 8808, 4, 0, 0, 0, 0, '', 'Arathi Basin - Farm - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_FARM, 0, 0, 11, 0, 8808, 5, 0, 0, 0, 0, '', 'Arathi Basin - Farm - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_LUMBERMILL, 0, 0, 11, 0, 8805, 4, 0, 0, 0, 0, '', 'Arathi Basin - Lumber Mill - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, 0, 11, 0, 8805, 5, 0, 0, 0, 0, '', 'Arathi Basin - Lumber Mill - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_BLACKSMITH, 0, 0, 11, 0, 8799, 4, 0, 0, 0, 0, '', 'Arathi Basin - Blacksmith - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, 0, 11, 0, 8799, 5, 0, 0, 0, 0, '', 'Arathi Basin - Blacksmith - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_STABLES, 0, 0, 11, 0, 5834, 4, 0, 0, 0, 0, '', 'Arathi Basin - Stables - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_STABLES, 0, 0, 11, 0, 5834, 5, 0, 0, 0, 0, '', 'Arathi Basin - Stables - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_GOLDMINE, 0, 0, 11, 0, 8809, 4, 0, 0, 0, 0, '', 'Arathi Basin - Gold Mine - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_GOLDMINE, 0, 0, 11, 0, 8809, 5, 0, 0, 0, 0, '', 'Arathi Basin - Gold Mine - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_FARM_GRAVEYARD, 0, 0, 11, 0, 8808, 4, 0, 0, 0, 0, '', 'Arathi Basin - Farm Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_FARM_GRAVEYARD, 0, 0, 11, 0, 8808, 5, 0, 0, 0, 0, '', 'Arathi Basin - Farm Graveyard - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_LUMBERMILL_GRAVEYARD, 0, 0, 11, 0, 8805, 4, 0, 0, 0, 0, '', 'Arathi Basin - Lumber Mill Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_LUMBERMILL_GRAVEYARD, 0, 0, 11, 0, 8805, 5, 0, 0, 0, 0, '', 'Arathi Basin - Lumber Mill Graveyard - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_BLACKSMITH_GRAVEYARD, 0, 0, 11, 0, 8799, 4, 0, 0, 0, 0, '', 'Arathi Basin - Blacksmith Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_BLACKSMITH_GRAVEYARD, 0, 0, 11, 0, 8799, 5, 0, 0, 0, 0, '', 'Arathi Basin - Blacksmith Graveyard - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_STABLES_GRAVEYARD, 0, 0, 11, 0, 5834, 4, 0, 0, 0, 0, '', 'Arathi Basin - Stables Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_STABLES_GRAVEYARD, 0, 0, 11, 0, 5834, 5, 0, 0, 0, 0, '', 'Arathi Basin - Stables Graveyard - Alliance Controlled'),
(33, 0, @SPAWNGROUP_HORDE_GOLDMINE_GRAVEYARD, 0, 0, 11, 0, 8809, 4, 0, 0, 0, 0, '', 'Arathi Basin - Gold Mine Graveyard - Horde Controlled'),
(33, 0, @SPAWNGROUP_ALLIANCE_GOLDMINE_GRAVEYARD, 0, 0, 11, 0, 8809, 5, 0, 0, 0, 0, '', 'Arathi Basin - Gold Mine Graveyard - Alliance Controlled');

-- Graveyards
DELETE FROM `graveyard_zone` WHERE `ID` IN (7251, 7252, 7253, 7254, 7255, 7256, 7257);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`,`Comment`) VALUES
(7251, 10053, 'Arathi Basin - Alliance Base'),
(7252, 10053, 'Arathi Basin - Stables'),
(7253, 10053, 'Arathi Basin - Gold Mine'),
(7254, 10053, 'Arathi Basin - Lumber Mil'),
(7255, 10053, 'Arathi Basin - Horde Base'),
(7256, 10053, 'Arathi Basin - Farm'),
(7257, 10053, 'Arathi Basin - Blacksmith');

-- Graveyard conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (7251, 7252, 7253, 7254, 7255, 7256, 7257);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
-- Bases
(27, 7251, 10053, 0, 6, 469, 0, 'Graveyard - Arathi Basin - Alliance Base - Team Alliance'),
(27, 7255, 10053, 0, 6, 67, 0, 'Graveyard - Arathi Basin - Horde Base - Team Horde'),
-- Stables
(27, 7252, 10053, 0, 6, 469, 0, 'Graveyard - Arathi Basin - Stables - Team Alliance'),
(27, 7252, 10053, 0, 11, 5834, 5, 'Graveyard - Arathi Basin - Stables - Alliance Controlled'),
(27, 7252, 10053, 1, 6, 67, 0, 'Graveyard - Arathi Basin - Stables - Team Horde'),
(27, 7252, 10053, 1, 11, 5834, 4, 'Graveyard - Arathi Basin - Stables - Horde Controlled'),
-- Gold Mine
(27, 7253, 10053, 0, 6, 469, 0, 'Graveyard - Arathi Basin - Gold Mine - Team Alliance'),
(27, 7253, 10053, 0, 11, 8809, 5, 'Graveyard - Arathi Basin - Gold Mine - Alliance Controlled'),
(27, 7253, 10053, 1, 6, 67, 0, 'Graveyard - Arathi Basin - Gold Mine - Team Horde'),
(27, 7253, 10053, 1, 11, 8809, 4, 'Graveyard - Arathi Basin - Gold Mine - Horde Controlled'),
-- Lumber Mill
(27, 7254, 10053, 0, 6, 469, 0, 'Graveyard - Arathi Basin - Lumber Mill - Team Alliance'),
(27, 7254, 10053, 0, 11, 8805, 5, 'Graveyard - Arathi Basin - Lumber Mill - Alliance Controlled'),
(27, 7254, 10053, 1, 6, 67, 0, 'Graveyard - Arathi Basin - Lumber Mill - Team Horde'),
(27, 7254, 10053, 1, 11, 8805, 4, 'Graveyard - Arathi Basin - Lumber Mill - Horde Controlled'),
-- Farm
(27, 7256, 10053, 0, 6, 469, 0, 'Graveyard - Arathi Basin - Farm - Team Alliance'),
(27, 7256, 10053, 0, 11, 8808, 5, 'Graveyard - Arathi Basin - Farm - Alliance Controlled'),
(27, 7256, 10053, 1, 6, 67, 0, 'Graveyard - Arathi Basin - Farm - Team Horde'),
(27, 7256, 10053, 1, 11, 8808, 4, 'Graveyard - Arathi Basin - Farm - Horde Controlled'),
-- Blacksmith
(27, 7257, 10053, 0, 6, 469, 0, 'Graveyard - Arathi Basin - Blacksmith - Team Alliance'),
(27, 7257, 10053, 0, 11, 8799, 5, 'Graveyard - Arathi Basin - Blacksmith - Alliance Controlled'),
(27, 7257, 10053, 1, 6, 67, 0, 'Graveyard - Arathi Basin - Blacksmith - Team Horde'),
(27, 7257, 10053, 1, 11, 8799, 4, 'Graveyard - Arathi Basin - Blacksmith - Horde Controlled');

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (322274 /*Horde Door*/, 322273 /*Alliance Door*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(322274, 1375, 33, 0, 0), -- Horde Door
(322273, 1375, 33, 0, 0); -- Alliance Door

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+308;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 719.01318359375, 631.47576904296875, -10.4975643157958984, 1.681953787803649902, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 700.219482421875, 755.3856201171875, -23.5969429016113281, 1.819434046745300292, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+2, 150426, 2107, 10053, 10521, '0', '0', 0, 0, 0, 481.103424072265625, 1500.848876953125, 195.8998870849609375, 6.191287994384765625, 7200, 10, 0, 11791, 0, 1, 0, 0, '', 44325), -- Arathi Giant (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+3, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1283.9395751953125, 1314.7276611328125, -11.0609874725341796, 2.398959875106811523, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+4, 150426, 2107, 10053, 10521, '0', '0', 0, 0, 0, 270.673614501953125, 813.68927001953125, 217.37396240234375, 6.094564437866210937, 7200, 0, 0, 11791, 0, 0, 0, 0,  '', 44325), -- Arathi Giant (Area: Defiler's Den - Difficulty: 0)
(@CGUID+5, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 640.86962890625, 1074.461669921875, 90.9493255615234375, 1.224027872085571289, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1281.8531494140625, 714.66741943359375, 4.30950927734375, 5.105314254760742187, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+7, 150655, 2107, 10053, 10521, '0', '0', 0, 0, 1, 1333.734375, 1321.8819580078125, -8.73986625671386718, 2.030910730361938476, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Groundskeeper Olivia (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+8, 149760, 2107, 10053, 10521, '0', '0', 0, 0, 0, 535.7117919921875, 489.0069580078125, 85.134735107421875, 1.336545228958129882, 7200, 0, 0, 4579, 0, 0, 0, 0, '', 44325), -- Spell Bunny (Area: Defiler's Den - Difficulty: 0) (Auras: )
(@CGUID+9, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 640.20159912109375, 1064.5498046875, 92.400726318359375, 1.390209197998046875, 7200, 10, 0, 6441, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1097.817138671875, 651.25885009765625, 24.62078666687011718, 6.138581752777099609, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+11, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1380.501953125, 1301.3232421875, -7.9797372817993164, 3.398830890655517578, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 149760, 2107, 10053, 10521, '0', '0', 0, 0, 0, 711.51910400390625, 683.28643798828125, -15.1177291870117187, 3.388207435607910156, 1, 0, 0, 4579, 0, 0, 0, 0, '', 44325), -- Spell Bunny (Area: Defiler's Den - Difficulty: 0)
(@CGUID+13, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1387.0928955078125, 1312.1898193359375, -6.2264413833618164, 4.357081413269042968, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 150429, 2107, 10053, 10521, '0', '0', 0, 0, 1, 658.76214599609375, 668.44964599609375, 7.71792459487915039, 1.834298372268676757, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Defiler Combatant (Area: Defiler's Den - Difficulty: 0) (Auras: 282578 - Hold Torch) (possible waypoints or random movement)
(@CGUID+15, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1170.2982177734375, 632.3450927734375, 23.96047019958496093, 0.953545689582824707, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+16, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1363.8733, 1353.7639, -4.9591475, 2.381939411163330078, 7200, 0, 0, 11791, 0, 2, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0) (Auras: 282578 - Hold Torch) (possible waypoints or random movement)
(@CGUID+17, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1060.4078369140625, 1004.0341796875, -51.1669082641601562, 2.335479259490966796, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+18, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 504.144073486328125, 406.05364990234375, 130.13250732421875, 5.262158393859863281, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+19, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 936.64385986328125, 855.83038330078125, -64.4358444213867187, 2.88435983657836914, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+20, 150426, 2107, 10053, 10521, '0', '0', 0, 0, 0, 357.19024658203125, 578.93963623046875, 164.0836029052734375, 6.098437786102294921, 7200, 10, 0, 11791, 0, 1, 0, 0, '', 44325), -- Arathi Giant (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1290.329833984375, 1323.484375, 18.60406112670898437, 4.883936882019042968, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0) (Auras: 282578 - Hold Torch)
(@CGUID+22, 150426, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1491.3177490234375, 779.60418701171875, 54.917236328125, 3.911062002182006835, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Giant (Area: Defiler's Den - Difficulty: 0)
(@CGUID+23, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 713.4669189453125, 1180.54931640625, 57.40172195434570312, 6.03346872329711914, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+24, 150501, 2107, 10053, 10521, '0', '0', 0, 0, 1, 656.09375, 636.46265, -9.3995950, 1.105017066001892089, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- The Black Bride (Area: Defiler's Den - Difficulty: 0)
(@CGUID+25, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 675.07989501953125, 669.2899169921875, -12.5684747695922851, 1.537112712860107421, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0)
(@CGUID+26, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 602.65960693359375, 826.01800537109375, 68.0590057373046875, 3.483433485031127929, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+27, 149755, 2107, 10053, 10521, '0', '0', 0, 0, 6, 1364.2379150390625, 1299.77783203125, -8.4645395278930664, 0.07065419852733612, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Kevin Young (Area: Defiler's Den - Difficulty: 0) (Auras: 261985 - Blacksmith Working) (possible waypoints or random movement)
(@CGUID+28, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 717.7391357421875, 660.68255615234375, -13.0123090744018554, 1.231605291366577148, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+29, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1107.2972412109375, 1280.739501953125, -45.0814323425292968, 5.295517921447753906, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+30, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1384.93408203125, 861.232666015625, 39.87235260009765625, 2.954025030136108398, 7200, 0, 0, 916, 0, 0, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0)
(@CGUID+31, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1089.1663818359375, 580.81988525390625, 51.79526519775390625, 2.421999931335449218, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 149793, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1483.43408203125, 767.93402099609375, 52.163665771484375, 0.696394264698028564, 7200, 0, 0, 4294, 0, 0, 0, 0, '', 44325), -- Bound Arathi Rager (Area: Defiler's Den - Difficulty: 0)
(@CGUID+33, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1356.439208984375, 1335.2413330078125, 0.447226583957672119, 0.327374935150146484, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+34, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 907.33160400390625, 856.546630859375, -63.2753677368164062, 2.080382347106933593, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+35, 149795, 2107, 10053, 10521, '0', '0', 0, 0, 0, 772.6754150390625, 1123.4193115234375, 15.40657520294189453, 4.274608612060546875, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Beaver (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+36, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1317.5816650390625, 1361.99658203125, 0.656701624393463134, 3.265699148178100585, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0) (Auras: 282578 - Hold Torch)
(@CGUID+37, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1237.3538818359375, 980.76422119140625, -90.9696731567382812, 1.361477255821228027, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+38, 150505, 2107, 10053, 10521, '0', '0', 0, 0, 1, 1392.1213, 1345.5967, 0.21549422, 3.650683403015136718, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Radulf Leder (Area: Defiler's Den - Difficulty: 0)
(@CGUID+39, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 557.4913330078125, 866.638916015625, 99.32508087158203125, 1.57762157917022705, 7200, 10, 0, 6441, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+40, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1210.8082275390625, 694.72723388671875, -4.61177682876586914, 5.562703132629394531, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+41, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 553.6456298828125, 857.6728515625, 99.81238555908203125, 2.588786840438842773, 7200, 10, 0, 6441, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+42, 150543, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1316.3819580078125, 1342.8072509765625, -9.88712501525878906, 3.539296627044677734, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Belle (Area: Defiler's Den - Difficulty: 0)
(@CGUID+43, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 690.5262451171875, 636.86944580078125, -10.0310144424438476, 2.606237173080444335, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+44, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 866.51824951171875, 613.09075927734375, 52.96668624877929687, 3.467667102813720703, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+45, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 688.54168701171875, 654.72222900390625, -11.3487586975097656, 1.537112712860107421, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0)
(@CGUID+46, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1235.2691650390625, 970.940185546875, -92.8533401489257812, 1.484998703002929687, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+47, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 643.75, 633.333984375, -8.70977592468261718, 4.542739391326904296, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+48, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 973.8271484375, 1074.3173828125, -45.1417160034179687, 1.7982712984085083, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+49, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1183.0433349609375, 557.20745849609375, 30.43250656127929687, 4.146334171295166015, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 700.39013671875, 1197.4639892578125, 63.95070648193359375, 3.565069913864135742, 7200, 10, 0, 916, 0, 1, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+51, 150513, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1376.2254638671875, 1372.066650390625, 156.5288543701171875, 3.895016908645629882, 7200, 0, 0, 11791, 0, 0, 0, 0, 'npc_bg_ab_arathor_gryphon_rider_leader', 44325), -- Arathor Gryphon Rider (Area: Defiler's Den - Difficulty: 0)
(@CGUID+52, 149793, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1538.1163330078125, 882.7413330078125, 107.3975753784179687, 0.318225383758544921, 7200, 0, 0, 4579, 0, 0, 0, 0, '', 44325), -- Bound Arathi Rager (Area: Defiler's Den - Difficulty: 0)
(@CGUID+53, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1313.8524169921875, 1383.638916015625, -9.01089763641357421, 1.476471662521362304, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+54, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 524.27410888671875, 372.629058837890625, 130.08770751953125, 1.890980839729309082, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+55, 149795, 2107, 10053, 10521, '0', '0', 0, 0, 0, 746.31640625, 1205.2843017578125, 21.6436767578125, 0.456220895051956176, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Beaver (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+56, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1338.31103515625, 877.51458740234375, 5.128692626953125, 4.27995157241821289, 7200, 10, 0, 916, 0, 1, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+57, 150513, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1397.6243896484375, 1385.233642578125, 157.1707611083984375, 5.732475757598876953, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Gryphon Rider (Area: Defiler's Den - Difficulty: 0)
(@CGUID+58, 149793, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1511.75, 687.59722900390625, 52.81597137451171875, 4.936140060424804687, 7200, 0, 0, 4294, 0, 0, 0, 0, '', 44325), -- Bound Arathi Rager (Area: Defiler's Den - Difficulty: 0)
(@CGUID+59, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 663.03643798828125, 724.86981201171875, -11.5520706176757812, 1.340009450912475585, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0) (Auras: 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+60, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1378.6597900390625, 1356.232666015625, -0.23344957828521728, 0.447986364364624023, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+61, 149795, 2107, 10053, 10521, '0', '0', 0, 0, 0, 836.35247802734375, 1164.8739013671875, 11.99005699157714843, 1.119794964790344238, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Beaver (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+62, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1294.390625, 1342.9600830078125, -10.5788164138793945, 6.201286792755126953, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+63, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1222.544189453125, 759.67901611328125, -77.957000732421875, 5.781805038452148437, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+64, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 698.44140625, 632.8671875, -10.4185800552368164, 5.378872394561767578, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+65, 150459, 2107, 10053, 10521, '0', '0', 0, 0, 0, 629.9687, 376.4514, 178.24315, 1.61511242389678955, 7200, 0, 0, 11791, 0, 0, 0, 0, 'npc_bg_ab_defiler_bat_rider_leader', 44325), -- Defiler Bat Rider (Area: Defiler's Den - Difficulty: 0)
(@CGUID+66, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 719.77490234375, 651.41754150390625, -12.3436079025268554, 3.3506622314453125, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+67, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1298.5242919921875, 1379.0572509765625, -6.90602064132690429, 5.550839424133300781, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0)
(@CGUID+68, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 919.12396240234375, 920.71795654296875, -61.7486801147460937, 3.646725177764892578, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+69, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1387.1541748046875, 1199.1875, 19.23383331298828125, 2.778135299682617187, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+70, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1017.29522705078125, 666.74481201171875, 22.91433334350585937, 2.534416675567626953, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+71, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 1, 1337.5728759765625, 1368.63720703125, -7.77858304977416992, 0.937136530876159667, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+72, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1308.5889892578125, 1374.7808837890625, -9.6841278076171875, 2.433773994445800781, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+73, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 983.51629638671875, 858.30718994140625, -63.717864990234375, 3.388092517852783203, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+74, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 623.11517333984375, 701.9610595703125, -8.1608896255493164, 3.716466903686523437, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+75, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 762.36956787109375, 877.7882080078125, -49.3338241577148437, 1.16210639476776123, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+76, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1390.52197265625, 1329.17578125, -0.02822490036487579, 0.734154105186462402, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+77, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 659.10858154296875, 673.026123046875, -12.1359291076660156, 5.33001565933227539, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+78, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1374.5650634765625, 1321.392822265625, -5.3021249771118164, 4.243195056915283203, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+79, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 640.955322265625, 1059.954345703125, 91.897918701171875, 1.358333110809326171, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+80, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1323.49658203125, 1343.517333984375, 12.2651214599609375, 4.617429256439208984, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+81, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 699.35205078125, 1219.0498046875, 68.07843780517578125, 5.263020992279052734, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+82, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1323.2760009765625, 1341.8004150390625, 12.26622295379638671, 1.421558141708374023, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+83, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1311.988037109375, 1331.2960205078125, -9.6644906997680664, 5.351158618927001953, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+84, 149718, 2107, 10053, 10521, '0', '0', 0, 0, 0, 706.732666015625, 679.89239501953125, -16.0542812347412109, 2.884756326675415039, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Derek Darkmetal (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+85, 149719, 2107, 10053, 10521, '0', '0', 0, 0, 0, 671.85589599609375, 636.69268798828125, -9.23107337951660156, 2.02702641487121582, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Captain (Area: Defiler's Den - Difficulty: 0) (Auras: 32951 - Sleeping Sleep)
(@CGUID+86, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1362.0052490234375, 1274.1754150390625, -10.5525951385498046, 2.933927774429321289, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0)
(@CGUID+87, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 905.44866943359375, 841.3917236328125, -64.7079849243164062, 5.579193115234375, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+88, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1296.30908203125, 1326.359375, -9.63511180877685546, 5.2727813720703125, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0)
(@CGUID+89, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 936.30810546875, 737.00299072265625, -54.9457015991210937, 5.101164817810058593, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+90, 150426, 2107, 10053, 10521, '0', '0', 0, 0, 0, 492.71527099609375, 1019.15875244140625, 120.0015716552734375, 0.181504324078559875, 7200, 10, 0, 11791, 0, 1, 0, 0, '', 44325), -- Arathi Giant (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+91, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1022.890625, 1398.763916015625, 92.1630401611328125, 0, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+92, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1315.43115234375, 1012.087890625, -12.0875930786132812, 4.248086929321289062, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+93, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1191.970458984375, 663.21875, 15.63309955596923828, 2.55128788948059082, 7200, 10, 0, 6441, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+94, 149721, 2107, 10053, 10521, '0', '0', 0, 0, 1, 672.81427001953125, 714.83160400390625, -13.2683420181274414, 5.277019500732421875, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Davis Bradley (Area: Defiler's Den - Difficulty: 0)
(@CGUID+95, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 913.08148193359375, 651.31689453125, 35.60742950439453125, 3.488675117492675781, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+96, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1361.8961181640625, 1387.364990234375, 9.519557952880859375, 0.08193150907754898, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+97, 150418, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1451.37158203125, 1444.0052490234375, 57.979736328125, 3.972086191177368164, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Siege Tank (Area: Defiler's Den - Difficulty: 0)
(@CGUID+98, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1337.43359375, 1375.7352294921875, -9.27597427368164062, 3.31734013557434082, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+99, 150429, 2107, 10053, 10521, '0', '0', 0, 0, 1, 534.29864501953125, 499.359375, 73.03855133056640625, 4.788630008697509765, 7200, 0, 0, 11791, 0, 0, 0, 0, 'npc_bg_ab_defiler_combatant_2', 44325), -- Defiler Combatant (Area: Defiler's Den - Difficulty: 0) (Auras: 282578 - Hold Torch)
(@CGUID+100, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1206.9317626953125, 607.90557861328125, 23.35107612609863281, 3.82182478904724121, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+101, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1079.7535400390625, 1402.453125, 72.65193939208984375, 5.6436004638671875, 7200, 0, 0, 916, 0, 0, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0)
(@CGUID+102, 149793, 2107, 10053, 10521, '0', '0', 0, 0, 0, 513.170166015625, 390.836822509765625, 130.0107879638671875, 0.769220530986785888, 7200, 0, 0, 4294, 0, 0, 0, 0, '', 44325), -- Bound Arathi Rager (Area: Defiler's Den - Difficulty: 0) (Auras: 285977 - Earth Channel Omni)
(@CGUID+103, 150431, 2107, 10053, 10521, '0', '0', 0, 0, 0, 608.72222900390625, 596.30731201171875, 19.47521781921386718, 0.844112336635589599, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Defiler Demolisher (Area: Defiler's Den - Difficulty: 0)
(@CGUID+104, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1043.3177490234375, 958.15277099609375, -50.6088371276855468, 0, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+105, 150429, 2107, 10053, 10521, '0', '0', 0, 0, 1, 642.37847900390625, 649.435791015625, -2.86745500564575195, 0.523410201072692871, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Defiler Combatant (Area: Defiler's Den - Difficulty: 0) (Auras: 282578 - Hold Torch)
(@CGUID+106, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 491.214263916015625, 379.14031982421875, 131.9445953369140625, 3.667277812957763671, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+107, 149795, 2107, 10053, 10521, '0', '0', 0, 0, 0, 788.763427734375, 1140.6043701171875, 14.28294277191162109, 2.394186019897460937, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Beaver (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+108, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 528.68829345703125, 622.2509765625, 64.87746429443359375, 2.245537281036376953, 7200, 10, 0, 916, 0, 1, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+109, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1277.8802490234375, 1331.310791015625, 19.27090835571289062, 3.265699386596679687, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0) (Auras: 172660 - Spyglass)
(@CGUID+110, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 947.0775146484375, 1067.1544189453125, -55.7641258239746093, 5.347291946411132812, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+111, 150426, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1549.7535400390625, 890.6788330078125, 112.892364501953125, 3.532892704010009765, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Giant (Area: Defiler's Den - Difficulty: 0)
(@CGUID+112, 150426, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1518.5555419921875, 675.26739501953125, 52.62845993041992187, 1.867624282836914062, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Giant (Area: Defiler's Den - Difficulty: 0)
(@CGUID+113, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 564.30047607421875, 857.50628662109375, 93.77088165283203125, 1.87021803855895996, 7200, 10, 0, 6441, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+114, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1324.3533935546875, 844.531982421875, -0.64782577753067016, 2.942090988159179687, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+115, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 649.79168701171875, 657.42706298828125, -10.7366352081298828, 5.683919906616210937, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0)
(@CGUID+116, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1481.1475830078125, 1250.6632080078125, 53.71390914916992187, 1.520047664642333984, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+117, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 704.7845458984375, 654.721435546875, -14.21417236328125, 1.108022451400756835, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+118, 149786, 2107, 10053, 10521, '0', '0', 0, 0, 0, 587.18597412109375, 619.87261962890625, 25.62053108215332031, 0.19487994909286499, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Plains Creeper (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+119, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 692.1875, 714.5830078125, -16.0187740325927734, 6.006227016448974609, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+120, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1176.8089599609375, 1267.6905517578125, -43.9940338134765625, 4.638944625854492187, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+121, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1181.0621337890625, 1016.4072265625, -63.0742263793945312, 5.361910820007324218, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+122, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1141.239501953125, 590.187744140625, 32.22942352294921875, 5.403130054473876953, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+123, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1464.8623046875, 1179.0068359375, 81.2415313720703125, 2.319583415985107421, 7200, 10, 0, 916, 0, 1, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+124, 150513, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1390.861572265625, 1392.4630126953125, 157.1707611083984375, 2.02684640884399414, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Gryphon Rider (Area: Defiler's Den - Difficulty: 0)
(@CGUID+125, 150445, 2107, 10053, 10521, '0', '0', 0, 0, 0, 639.5069580078125, 699.53472900390625, -11.3885421752929687, 4.1896209716796875, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Warhorse (Area: Defiler's Den - Difficulty: 0)
(@CGUID+126, 149793, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1173.2413330078125, 602.27606201171875, 29.60327529907226562, 1.039626121520996093, 7200, 0, 0, 4294, 0, 0, 0, 0, '', 44325), -- Bound Arathi Rager (Area: Defiler's Den - Difficulty: 0) (Auras: 285977 - Earth Channel Omni)
(@CGUID+127, 150446, 2107, 10053, 10521, '0', '0', 0, 0, 0, 644.40625, 705.56597900390625, -11.6578969955444335, 2.920136451721191406, 7200, 10, 0, 11791, 0, 1, 0, 0, '', 44325), -- Horde War Wolf (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+128, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1342.1632080078125, 1327.0364990234375, -7.45473289489746093, 5.776561737060546875, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+129, 149792, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1098.4041748046875, 565.98858642578125, 51.28850555419921875, 4.761273860931396484, 7200, 10, 0, 4294, 0, 1, 0, 0, '', 44325), -- Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+130, 149795, 2107, 10053, 10521, '0', '0', 0, 0, 0, 850.741943359375, 1258.933837890625, 21.20541000366210937, 2.685371637344360351, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Beaver (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+131, 149793, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1080.3509521484375, 576.28143310546875, 57.54082489013671875, 2.838066816329956054, 7200, 10, 0, 4579, 0, 1, 0, 0, '', 44325), -- Bound Arathi Rager (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+132, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1305.1944580078125, 1349.1754150390625, -10.5335168838500976, 4.780579566955566406, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+133, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1358.060791015625, 1335.842041015625, 0.412317454814910888, 3.52324533462524414, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+134, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1076.629150390625, 1162.1763916015625, -61.3454360961914062, 4.583348274230957031, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+135, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1380.107666015625, 1362.15625, 0.848607659339904785, 0.126308128237724304, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+136, 149795, 2107, 10053, 10521, '0', '0', 0, 0, 0, 768.52081298828125, 1068.3646240234375, 3.261466503143310546, 0, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Basin Beaver (Area: Defiler's Den - Difficulty: 0)
(@CGUID+137, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1053.7099609375, 1255.5152587890625, -43.996826171875, 3.702295303344726562, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+138, 150414, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1321.204833984375, 1385.078125, -7.35576200485229492, 3.184440851211547851, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Lightning (Area: Defiler's Den - Difficulty: 0) (Auras: 217075 - Sleeping Sleep)
(@CGUID+139, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 672.2615966796875, 630.21954345703125, -8.8275156021118164, 1.02733469009399414, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+140, 150622, 2107, 10053, 10521, '0', '0', 0, 0, 1, 684.045166015625, 675.263916015625, -14.6660480499267578, 4.539567470550537109, 7200, 0, 0, 11791, 0, 0, 0, 0, 'npc_bg_ab_dominic_masonwrite', 44325), -- Dominic Masonwrite (Area: Defiler's Den - Difficulty: 0) (Auras: 122236 - Read Scroll) (possible waypoints or random movement)
(@CGUID+141, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 681.27001953125, 703.30963134765625, -15.3807687759399414, 5.276788711547851562, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+142, 149759, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1298.251708984375, 1351.4322509765625, -10.3935556411743164, 5.208214282989501953, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Sarah Gardner (Area: Defiler's Den - Difficulty: 0)
(@CGUID+143, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1052.803955078125, 1177.83251953125, -53.6215629577636718, 2.972865581512451171, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+144, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1221.4097900390625, 1418.125, -6.12056922912597656, 4.823981285095214843, 7200, 10, 0, 916, 0, 1, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+145, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1356.857666015625, 892.73089599609375, 15.06451225280761718, 2.954025030136108398, 7200, 0, 0, 916, 0, 0, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0)
(@CGUID+146, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1331.4132080078125, 1329.59375, 13.7649688720703125, 4.857148170471191406, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0) (Auras: 271087 - Cosmetic - Human Male Kul Tiran Spyglass) (possible waypoints or random movement)
(@CGUID+147, 150461, 2107, 10053, 10521, '0', '0', 0, 0, 0, 633.95489501953125, 389.423614501953125, 171.862152099609375, 1.21834874153137207, 7200, 0, 0, 4579, 0, 0, 0, 0, '', 44325), -- Spell Bunny (Area: Defiler's Den - Difficulty: 0)
(@CGUID+148, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1299.8072509765625, 1338.8646240234375, -10.6652584075927734, 3.047743797302246093, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+149, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 678.849853515625, 793.946044921875, -19.0406970977783203, 5.245444297790527343, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+150, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1262, 1284.045166015625, -22.2945213317871093, 0, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+151, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1308.410400390625, 1364.8486328125, -9.66704940795898437, 5.814202308654785156, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+152, 150429, 2107, 10053, 10521, '0', '0', 0, 0, 1, 676.01043701171875, 674.05035400390625, -14.6389789581298828, 3.677953243255615234, 7200, 0, 0, 11791, 0, 2, 0, 0, '', 44325), -- Defiler Combatant (Area: Defiler's Den - Difficulty: 0) (Auras: 282578 - Hold Torch) (possible waypoints or random movement)
(@CGUID+153, 150459, 2107, 10053, 10521, '0', '0', 0, 0, 0, 629.9687, 362.30926, 178.24315, 1.623220682144165039, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Defiler Bat Rider (Area: Defiler's Den - Difficulty: 0)
(@CGUID+154, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 620.75433349609375, 696.850341796875, -8.03371715545654296, 0.011967432685196399, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+155, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1331.0491943359375, 1296.4215087890625, -10.2797775268554687, 0.945124149322509765, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+156, 150431, 2107, 10053, 10521, '0', '0', 0, 0, 0, 658.40802001953125, 497.07464599609375, 56.04854965209960937, 1.667433381080627441, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Defiler Demolisher (Area: Defiler's Den - Difficulty: 0)
(@CGUID+157, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1386.0718994140625, 1355.3785400390625, 0.96052408218383789, 2.15455174446105957, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+158, 150459, 2107, 10053, 10521, '0', '0', 0, 0, 0, 615.8266, 362.3093, 178.24315, 1.61513519287109375, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Defiler Bat Rider (Area: Defiler's Den - Difficulty: 0)
(@CGUID+159, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1326.69970703125, 1294.9879150390625, -8.62847137451171875, 3.266753673553466796, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0)
(@CGUID+160, 14848, 2107, 10053, 10521, '0', '0', 0, 0, 2, 1304.2584228515625, 1322.562744140625, 43.8479156494140625, 0.645771801471710205, 7200, 0, 0, 176865, 0, 0, 0, 0, '', 44325), -- Herald (Area: Defiler's Den - Difficulty: 0)
(@CGUID+161, 149785, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1087.740478515625, 610.6932373046875, 40.4268035888671875, 2.534158229827880859, 7200, 10, 0, 6869, 0, 1, 0, 0, '', 44325), -- Highland Thrasher (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+162, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 643.58856201171875, 673.51739501953125, -9.29238128662109375, 0.675543844699859619, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0) (Auras: 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+163, 150403, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1295.5347900390625, 1344.095458984375, -10.5542268753051757, 4.780579566955566406, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Watchman (Area: Defiler's Den - Difficulty: 0)
(@CGUID+164, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1337.89794921875, 1272.5301513671875, -10.4476747512817382, 3.465642213821411132, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+165, 150647, 2107, 10053, 10521, '0', '0', 0, 0, 0, 662.10418701171875, 645.953125, -12.0993022918701171, 1.804074406623840332, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Basin Rat (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+166, 149794, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1350, 1287.5, -10.2733583450317382, 5.15164947509765625, 7200, 10, 0, 27, 0, 1, 0, 0, '', 44325), -- Highland Hare (Area: Defiler's Den - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+167, 150449, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1229.2725830078125, 1549.9375, 134.137725830078125, 4.80943918228149414, 7200, 0, 0, 916, 0, 0, 0, 0, '', 44325), -- Highland Bristleback (Area: Defiler's Den - Difficulty: 0)
(@CGUID+168, 150418, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1554.53125, 1366.814208984375, 75.9812774658203125, 4.347634792327880859, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathor Siege Tank (Area: Defiler's Den - Difficulty: 0)
(@CGUID+169, 150461, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1412.7742919921875, 1389.326416015625, 152.241973876953125, 1.21834874153137207, 7200, 0, 0, 4579, 0, 0, 0, 0, '', 44325), -- Spell Bunny (Area: Defiler's Den - Difficulty: 0)

-- STABLES (ALLIANCE)
(@CGUID+170, 15107, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1157.76220703125, 1172.59033203125, -56.2799491882324218, 2.808322429656982421, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Arathi Horse (Area: Lumber Mill - Difficulty: 0)
(@CGUID+171, 15107, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1181.2100830078125, 1153.0242919921875, -56.2896270751953125, 0, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Arathi Horse (Area: Lumber Mill - Difficulty: 0)
(@CGUID+172, 15086, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1172.9278564453125, 1173.1795654296875, -56.3817291259765625, 2.805151224136352539, 7200, 0, 0, 11791, 0, 2, 0, 0, '', 44325), -- Arathi Stablehand (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+173, 15086, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1196.217, 1174.0764, -56.75803, 0.798887610435485839, 7200, 0, 0, 11791, 0, 2, 0, 0, '', 44325), -- Arathi Stablehand (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+174, 15086, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1194.7708740234375, 1190.2396240234375, -55.9351806640625, 0.811477959156036376, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Stablehand (Area: Lumber Mill - Difficulty: 0)
(@CGUID+175, 15107, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1187.3367919921875, 1192.09033203125, -55.82574462890625, 3.86099553108215332, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Arathi Horse (Area: Lumber Mill - Difficulty: 0)
(@CGUID+176, 15107, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1173.68408203125, 1168.3316650390625, -56.3639869689941406, 2.164245128631591796, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Arathi Horse (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+177, 15107, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1191.7066650390625, 1174.986083984375, -56.392364501953125, 0.310988456010818481, 7200, 0, 0, 27, 0, 0, 0, 0, '', 44325), -- Arathi Horse (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+178, 15107, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1167.48095703125, 1159.8177490234375, -56.3874015808105468, 6.067793846130371093, 7200, 15, 0, 27, 0, 1, 0, 0, '', 44325), -- Arathi Horse (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+179, 15086, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1207.6632080078125, 1197.0069580078125, -56.174530029296875, 1.940982580184936523, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Stablehand (Area: Lumber Mill - Difficulty: 0)
(@CGUID+180, 15086, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1207.4913330078125, 1198.98095703125, -56.1753044128417968, 5.04430246353149414, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Stablehand (Area: Lumber Mill - Difficulty: 0)

-- FARM (HORDE)
(@CGUID+181, 150443, 2107, 10053, 10516, '0', '0', 0, 0, 0, 789.80035400390625, 829.967041015625, -55.4852371215820312, 0, 7200, 0, 0, 1, 0, 0, 0, 0, '', 44325), -- Chicken (Area: Lumber Mill - Difficulty: 0)
(@CGUID+182, 150443, 2107, 10053, 10516, '0', '0', 0, 0, 0, 792.66143798828125, 822.859375, -56.582122802734375, 0, 7200, 10, 0, 1, 0, 1, 0, 0, '', 44325), -- Chicken (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+183, 61366, 2107, 10053, 10516, '0', '0', 0, 0, 0, 860.58856201171875, 835.23614501953125, -57.2612037658691406, 5.8817596435546875, 7200, 10, 0, 5, 0, 1, 0, 0, '', 44325), -- Rat (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+184, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 0, 825.98089599609375, 806.86456298828125, -57.625885009765625, 1.02881479263305664, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+185, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 1, 837.29864501953125, 831.94268798828125, -57.492767333984375, 4.234867572784423828, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+186, 4075, 2107, 10053, 10516, '0', '0', 0, 0, 0, 819.17364501953125, 792.9617919921875, -57.339813232421875, 4.403332233428955078, 7200, 10, 0, 5, 0, 1, 0, 0, '', 44325), -- Rat (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+187, 4075, 2107, 10053, 10516, '0', '0', 0, 0, 0, 799.78472900390625, 842.3819580078125, -57.2786216735839843, 1.98999035358428955, 7200, 10, 0, 5, 0, 1, 0, 0, '', 44325), -- Rat (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+188, 150443, 2107, 10053, 10516, '0', '0', 0, 0, 0, 797.20489501953125, 829.888916015625, -56.8450546264648437, 0, 7200, 10, 0, 1, 0, 1, 0, 0, '', 44325), -- Chicken (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+189, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 1, 860.5225830078125, 846.13714599609375, -58.0085182189941406, 4.185294151306152343, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+190, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 1, 857.28302001953125, 825.342041015625, -57.1301002502441406, 4.251018524169921875, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+191, 4075, 2107, 10053, 10516, '0', '0', 0, 0, 0, 835.21527099609375, 844.826416015625, -57.7741508483886718, 5.8817596435546875, 7200, 10, 0, 5, 0, 1, 0, 0, '', 44325), -- Rat (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+192, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 0, 845.685791015625, 812.9617919921875, -50.7067489624023437, 1.819554686546325683, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0)
(@CGUID+193, 4075, 2107, 10053, 10516, '0', '0', 0, 0, 0, 835.57061767578125, 807.02935791015625, -57.1240196228027343, 6.072569847106933593, 7200, 10, 0, 5, 0, 1, 0, 0, '', 44325), -- Rat (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+194, 150443, 2107, 10053, 10516, '0', '0', 0, 0, 0, 815.5980224609375, 827.02947998046875, -56.5844612121582031, 5.315833568572998046, 7200, 10, 0, 1, 0, 1, 0, 0, '', 44325), -- Chicken (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+195, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 0, 789.4461669921875, 815.8992919921875, -56.2427864074707031, 3.338526010513305664, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+196, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 0, 830.52777099609375, 823.3367919921875, -57.7775764465332031, 1.02881479263305664, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+197, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 0, 811.34375, 783.17535400390625, -57.2960281372070312, 2.273226261138916015, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0)
(@CGUID+198, 4075, 2107, 10053, 10516, '0', '0', 0, 0, 0, 821.537353515625, 867.22613525390625, -57.7848434448242187, 4.078652381896972656, 7200, 10, 0, 5, 0, 1, 0, 0, '', 44325), -- Rat (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+199, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 0, 826.89239501953125, 814.22393798828125, -57.7080497741699218, 0.982451319694519042, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+200, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 1, 831.953125, 870.5625, -58.0505104064941406, 4.234867572784423828, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+201, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 0, 810.529541015625, 784.89581298828125, -57.4264144897460937, 5.515162467956542968, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0)
(@CGUID+202, 15046, 2107, 10053, 10516, '0', '0', 0, 0, 1, 837.6805419921875, 852.9288330078125, -57.4091415405273437, 3.991605520248413085, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Farmer (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)

-- LUMBER MILL (HORDE)
(@CGUID+203, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 2, 852.6875, 1236.064208984375, 15.5935516357421875, 0.13475009799003601, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0)
(@CGUID+204, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 757.3975830078125, 1162.171875, 20.36017227172851562, 3.34941720962524414, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+205, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 0, 814.2882080078125, 1096.765625, 10.53528881072998046, 4.617629528045654296, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+206, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 2, 854.97918701171875, 1236.6910400390625, 15.65137004852294921, 4.472290515899658203, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0)
(@CGUID+207, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 0, 825.779541015625, 1255.8836669921875, 22.23864173889160156, 0.499742180109024047, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+208, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 761.328125, 1127.359375, 19.03442955017089843, 6.225657939910888671, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+209, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 904.35418701171875, 1182.953125, 3.927566051483154296, 5.970508098602294921, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+210, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 0, 854.49481201171875, 1233.670166015625, 15.39551734924316406, 1.891628742218017578, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+211, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 924.763916015625, 1302.88720703125, 22.37109375, 2.183487892150878906, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+212, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 752.47918701171875, 1236.529541015625, 25.32699966430664062, 2.994447708129882812, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+213, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 867.34722900390625, 1280.8785400390625, 25.11534881591796875, 1.559418201446533203, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+214, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 753.4132080078125, 1059.0885009765625, 11.60284328460693359, 4.122416973114013671, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+215, 15089, 2107, 10053, 10516, '0', '0', 0, 0, 1, 911.7725830078125, 1252.185791015625, 13.25510692596435546, 5.554555892944335937, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Lumberjack (Area: Lumber Mill - Difficulty: 0) (Auras: 290604 - Lumberjackin')

-- GOLD MINE (ALLIANCE)
(@CGUID+216, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1201.4791259765625, 757.44793701171875, -78.8430328369140625, 1.773384571075439453, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0)
(@CGUID+217, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1212.013916015625, 809.5555419921875, -82.8137741088867187, 3.915925502777099609, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0) (Auras: 175121 - Carry Sack) (possible waypoints or random movement)
(@CGUID+218, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1216.34375, 832.71875, -65.9708786010742187, 2.809300422668457031, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0)
(@CGUID+219, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1197.3055419921875, 864.31597900390625, -98.8753128051757812, 4.500833034515380859, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0) (Auras: 175121 - Carry Sack) (possible waypoints or random movement)
(@CGUID+220, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1181.5660400390625, 864.623291015625, -104.827781677246093, 4.266554832458496093, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0)
(@CGUID+221, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1181.1910400390625, 862.80206298828125, -104.996734619140625, 1.279518365859985351, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0)
(@CGUID+222, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1186.59375, 755.99652099609375, -78.9993667602539062, 1.870739698410034179, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0) (Auras: 217075 - Sleeping Sleep)
(@CGUID+223, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1180.2569580078125, 901.3819580078125, -103.944252014160156, 5.930918216705322265, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0)
(@CGUID+224, 15074, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1182.779541015625, 828.31427001953125, -100.446136474609375, 4.575056076049804687, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Miner (Area: Lumber Mill - Difficulty: 0) (Auras: 175121 - Carry Sack) (possible waypoints or random movement)

-- BLACKSMITH (HORDE)
(@CGUID+225, 15064, 2107, 10053, 10516, '0', '0', 0, 0, 0, 978, 994.0538330078125, -43.8363761901855468, 5.185836315155029296, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Blacksmith (Area: Lumber Mill - Difficulty: 0)
(@CGUID+226, 15064, 2107, 10053, 10516, '0', '0', 0, 0, 0, 978.7742919921875, 992.14239501953125, -43.9096717834472656, 2.039242506027221679, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Blacksmith (Area: Lumber Mill - Difficulty: 0)
(@CGUID+227, 15064, 2107, 10053, 10516, '0', '0', 0, 0, 1, 995.27777099609375, 1009.78472900390625, -42.1646804809570312, 0.476098626852035522, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Blacksmith (Area: Lumber Mill - Difficulty: 0) (Auras: 261985 - Blacksmith Working)
(@CGUID+228, 15071, 2107, 10053, 10516, '0', '0', 0, 0, 0, 993.205322265625, 1036.7705078125, -42.7558250427246093, 3.140616178512573242, 7200, 0, 0, 118, 0, 0, 0, 0, '', 44325), -- Underfoot (Area: Lumber Mill - Difficulty: 0)
(@CGUID+229, 15064, 2107, 10053, 10516, '0', '0', 0, 0, 3, 988.95489501953125, 1005.00701904296875, -42.1504898071289062, 3.150818347930908203, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Blacksmith (Area: Lumber Mill - Difficulty: 0) (Auras: 261985 - Blacksmith Working)
(@CGUID+230, 15064, 2107, 10053, 10516, '0', '0', 0, 0, 2, 979.4617919921875, 1003.3992919921875, -42.8633880615234375, 3.48093271255493164, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Blacksmith (Area: Lumber Mill - Difficulty: 0)
(@CGUID+231, 15072, 2107, 10053, 10516, '0', '0', 0, 0, 0, 1008.79681396484375, 1005.8079833984375, -44.0266914367675781, 6.248278617858886718, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Spike (Area: Lumber Mill - Difficulty: 0)
(@CGUID+232, 15064, 2107, 10053, 10516, '0', '0', 0, 0, 0, 971.12847900390625, 976.25518798828125, -43.8743324279785156, 2.090637445449829101, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Blacksmith (Area: Lumber Mill - Difficulty: 0) (Auras: 282906 - Carry Stone)
(@CGUID+233, 15064, 2107, 10053, 10516, '0', '0', 0, 0, 4, 967.42364501953125, 996.73785400390625, -43.9448280334472656, 2.711585760116577148, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325); -- Forsaken Blacksmith (Area: Lumber Mill - Difficulty: 0) (Auras: 261985 - Blacksmith Working)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `ScriptName`, `VerifiedBuild`) VALUES

-- BLACKSMITH (ALLIANCE)
(@CGUID+234, 15065, 2107, 10053, 10514, '0', '0', 0, 0, 0, 1008.76611328125, 1005.79931640625, -44.0248184204101562, 6.213372230529785156, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Lady (Area: Blacksmith - Difficulty: 0)
(@CGUID+235, 15066, 2107, 10053, 10514, '0', '0', 0, 0, 0, 1017.9132080078125, 1008.7742919921875, -44.3178443908691406, 4.465655803680419921, 7200, 0, 0, 118, 0, 0, 0, 0, '', 44325), -- Cleo (Area: Blacksmith - Difficulty: 0)
(@CGUID+236, 15063, 2107, 10053, 10514, '0', '0', 0, 0, 3, 967.42364501953125, 996.73785400390625, -43.9448280334472656, 2.711585760116577148, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Blacksmith (Area: Blacksmith - Difficulty: 0) (Auras: 261985 - Blacksmith Working)
(@CGUID+237, 15063, 2107, 10053, 10514, '0', '0', 0, 0, 1, 988.95489501953125, 1005.00701904296875, -42.1504898071289062, 3.150818347930908203, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Blacksmith (Area: Blacksmith - Difficulty: 0) (Auras: 261985 - Blacksmith Working)
(@CGUID+238, 15063, 2107, 10053, 10514, '0', '0', 0, 0, 0, 971.12847900390625, 976.25518798828125, -43.8743324279785156, 2.090637445449829101, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Blacksmith (Area: Blacksmith - Difficulty: 0) (Auras: 262247 - Carry Crate)
(@CGUID+239, 15063, 2107, 10053, 10514, '0', '0', 0, 0, 0, 978, 994.0538330078125, -43.8363761901855468, 5.185836315155029296, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Blacksmith (Area: Blacksmith - Difficulty: 0)
(@CGUID+240, 15063, 2107, 10053, 10514, '0', '0', 0, 0, 0, 978.7742919921875, 992.14239501953125, -43.9096717834472656, 2.039242506027221679, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Blacksmith (Area: Blacksmith - Difficulty: 0)
(@CGUID+241, 15063, 2107, 10053, 10514, '0', '0', 0, 0, 4, 995.0555419921875, 1009.43402099609375, -42.1646804809570312, 0.476098626852035522, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Blacksmith (Area: Blacksmith - Difficulty: 0) (Auras: 261985 - Blacksmith Working)
(@CGUID+242, 15063, 2107, 10053, 10514, '0', '0', 0, 0, 2, 979.4617919921875, 1003.3992919921875, -42.8633880615234375, 3.48093271255493164, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Arathi Blacksmith (Area: Blacksmith - Difficulty: 0)

-- STABLES (HORDE)
(@CGUID+243, 15108, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1157.76220703125, 1172.59033203125, -56.2799491882324218, 2.808322429656982421, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Horse (Area: Farm - Difficulty: 0)
(@CGUID+244, 15108, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1167.48095703125, 1159.8177490234375, -56.3874015808105468, 0, 7200, 15, 0, 11791, 0, 1, 0, 0, '', 44325), -- Forsaken Horse (Area: Farm - Difficulty: 0)
(@CGUID+245, 15108, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1181.2100830078125, 1153.0242919921875, -56.2896270751953125, 0, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Horse (Area: Farm - Difficulty: 0)
(@CGUID+246, 15087, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1173.6597900390625, 1172.923583984375, -56.3418312072753906, 2.805151224136352539, 7200, 0, 0, 11791, 0, 2, 0, 0, '', 44325), -- Forsaken Stablehand (Area: Farm - Difficulty: 0)
(@CGUID+247, 15087, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1207.6632080078125, 1197.0069580078125, -56.174530029296875, 1.940982580184936523, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Stablehand (Area: Farm - Difficulty: 0)
(@CGUID+248, 15108, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1173.68408203125, 1168.3316650390625, -56.3639869689941406, 2.576671123504638671, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Horse (Area: Farm - Difficulty: 0)
(@CGUID+249, 15108, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1187.3367919921875, 1192.09033203125, -55.82574462890625, 3.86099553108215332, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Horse (Area: Farm - Difficulty: 0)
(@CGUID+250, 15108, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1191.7066650390625, 1174.986083984375, -56.392364501953125, 0.798887610435485839, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Horse (Area: Farm - Difficulty: 0)
(@CGUID+251, 15087, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1207.4913330078125, 1198.98095703125, -56.1753044128417968, 5.04430246353149414, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 44325), -- Forsaken Stablehand (Area: Farm - Difficulty: 0)
(@CGUID+252, 15087, 2107, 10053, 10517, '0', '0', 0, 0, 0, 1196.217, 1174.0764, -56.75803, 0.798887610435485839, 7200, 0, 0, 11791, 0, 2, 0, 0, '', 44325), -- Forsaken Stablehand (Area: Farm - Difficulty: 0)

-- HONORABLE DEFENDERS
-- no create object found for those, positions are based on the capture points (like core did already)
-- FARM
(@CGUID+253, 20212, 2107, 0, 0, '0', '0', 0, 0, 0, 806.25, 874.279541015625, -56.5307502746582031, 0.818242669105529785, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Horde Friendly + Invis Man)
(@CGUID+254, 20213, 2107, 0, 0, '0', '0', 0, 0, 0, 806.25, 874.279541015625, -56.5307502746582031, 0.818242669105529785, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Alliance Friendly + Invis Man)
-- LUMBER MILL
(@CGUID+255, 20212, 2107, 0, 0, '0', '0', 0, 0, 0, 856.8663330078125, 1150.2135009765625, 11.04314804077148437, 0.989707827568054199, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Horde Friendly + Invis Man)
(@CGUID+256, 20213, 2107, 0, 0, '0', '0', 0, 0, 0, 856.8663330078125, 1150.2135009765625, 11.04314804077148437, 0.989707827568054199, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Alliance Friendly + Invis Man)
-- BLACKSMITH
(@CGUID+257, 20212, 2107, 0, 0, '0', '0', 0, 0, 0, 977.50518798828125, 1051.0728759765625, -44.7925682067871093, 0.497109025716781616, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Horde Friendly + Invis Man)
(@CGUID+258, 20213, 2107, 0, 0, '0', '0', 0, 0, 0, 977.50518798828125, 1051.0728759765625, -44.7925682067871093, 0.497109025716781616, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Alliance Friendly + Invis Man)
-- GOLD MINE
(@CGUID+259, 20212, 2107, 0, 0, '0', '0', 0, 0, 0, 1146.9288330078125, 848.2274169921875, -110.917579650878906, 2.417101383209228515, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Horde Friendly + Invis Man)
(@CGUID+260, 20213, 2107, 0, 0, '0', '0', 0, 0, 0, 1146.9288330078125, 848.2274169921875, -110.917579650878906, 2.417101383209228515, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Alliance Friendly + Invis Man)
-- STABLES
(@CGUID+261, 20212, 2107, 0, 0, '0', '0', 0, 0, 0, 1166.85595703125, 1200.12158203125, -56.3867416381835937, 0.886092901229858398, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Horde Friendly + Invis Man)
(@CGUID+262, 20213, 2107, 0, 0, '0', '0', 0, 0, 0, 1166.85595703125, 1200.12158203125, -56.3867416381835937, 0.886092901229858398, 7200, 0, 0, 0, 0, 0, 0, 0, '', 44325), -- World Trigger (Alliance Friendly + Invis Man)

-- LUMBER MILL (ALLIANCE)
(@CGUID+263, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 2, 924.763916015625, 1302.88720703125, 22.37109375, 2.183487892150878906, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+264, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 0, 904.35418701171875, 1182.953125, 3.927566051483154296, 5.970508098602294921, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+265, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 2, 752.47918701171875, 1236.529541015625, 25.32699966430664062, 2.994447708129882812, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+266, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 0, 825.779541015625, 1255.8836669921875, 22.23864173889160156, 0.499742180109024047, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+267, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 0, 757.3975830078125, 1162.171875, 20.36017227172851562, 3.34941720962524414, 7200, 10, 0, 11791, 0, 1, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+268, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 1, 854.97918701171875, 1236.6910400390625, 15.65137004852294921, 4.472290515899658203, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0)
(@CGUID+269, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 2, 753.4132080078125, 1059.0885009765625, 11.60284328460693359, 4.122416973114013671, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+270, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 0, 814.2882080078125, 1096.765625, 10.53528881072998046, 4.617629528045654296, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin') (possible waypoints or random movement)
(@CGUID+271, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 2, 867.34722900390625, 1280.8785400390625, 25.11534881591796875, 1.559418201446533203, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+272, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 2, 911.7725830078125, 1252.185791015625, 13.25510692596435546, 5.554555892944335937, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin')
(@CGUID+273, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 0, 854.49481201171875, 1233.670166015625, 15.39551734924316406, 1.891628742218017578, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+274, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 1, 852.6875, 1236.064208984375, 15.5935516357421875, 0.13475009799003601, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0)
(@CGUID+275, 15062, 2107, 10053, 10519, '0', '0', 0, 0, 2, 761.328125, 1127.359375, 19.03442955017089843, 6.225657939910888671, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Lumberjack (Area: Gold Mine - Difficulty: 0) (Auras: 290604 - Lumberjackin')

-- FARM (ALLIANCE)
(@CGUID+276, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 0, 845.685791015625, 812.9617919921875, -50.7067489624023437, 1.819554686546325683, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+277, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 0, 810.529541015625, 784.89581298828125, -57.4264144897460937, 5.515162467956542968, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+278, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 1, 860.5225830078125, 846.13714599609375, -58.0085182189941406, 4.185294151306152343, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+279, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 1, 857.28302001953125, 825.342041015625, -57.1301002502441406, 4.251018524169921875, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+280, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 1, 837.6805419921875, 852.9288330078125, -57.4091415405273437, 3.991605520248413085, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+281, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 0, 826.89239501953125, 814.22393798828125, -57.7080497741699218, 0.982451319694519042, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+282, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 0, 811.34375, 783.17535400390625, -57.2960281372070312, 2.273226261138916015, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+283, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 0, 789.4461669921875, 815.8992919921875, -56.2427864074707031, 3.338526010513305664, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+284, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 0, 825.98089599609375, 806.86456298828125, -57.625885009765625, 1.02881479263305664, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+285, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 0, 830.52777099609375, 823.3367919921875, -57.7775764465332031, 1.02881479263305664, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+286, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 1, 837.29864501953125, 831.94268798828125, -57.492767333984375, 4.234867572784423828, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)
(@CGUID+287, 15045, 2107, 10053, 10519, '0', '0', 0, 0, 1, 831.953125, 870.5625, -58.0505104064941406, 4.234867572784423828, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Arathi Farmer (Area: Gold Mine - Difficulty: 0)

-- GOLD MINE (HORDE)
(@CGUID+288, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1201.4791259765625, 757.44793701171875, -78.8430328369140625, 1.773384571075439453, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0)
(@CGUID+289, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1186.59375, 755.99652099609375, -78.9993667602539062, 1.870739698410034179, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0) (Auras: 217075 - Sleeping Sleep)
(@CGUID+290, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1212.013916015625, 809.5555419921875, -82.8137741088867187, 3.915925502777099609, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0) (Auras: 175121 - Carry Sack)
(@CGUID+291, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1181.5660400390625, 864.623291015625, -104.827781677246093, 4.266554832458496093, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0)
(@CGUID+292, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1181.1910400390625, 862.80206298828125, -104.996734619140625, 1.279518365859985351, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0)
(@CGUID+293, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1197.3055419921875, 864.31597900390625, -98.8753128051757812, 4.500833034515380859, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0)
(@CGUID+294, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1182.779541015625, 828.31427001953125, -100.446136474609375, 4.575056076049804687, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0)
(@CGUID+295, 15075, 2107, 10053, 10521, '0', '0', 0, 0, 0, 1216.34375, 832.71875, -65.9723968505859375, 2.809300422668457031, 7200, 0, 0, 11791, 0, 0, 0, 0, '', 45745), -- Forsaken Miner (Area: Defiler's Den - Difficulty: 0)

-- spirit guides
-- (Auras: 9036 - Ghost, 9617 - Ghost Visual, 22011 - Spirit Heal Channel)
-- -- Alliance base
(@CGUID+296, 13116, 2107, 10053, 10519, '0', '0', 0, 0, 1, 1347.453125, 1274.0538330078125, -11.1052913665771484, 5.742133140563964843, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Alliance Spirit Guide (Area: Gold Mine - Difficulty: 0) (Auras: 9036 - Ghost, 9617 - Ghost Visual, 22011 - Spirit Heal Channel)
-- -- Horde base
(@CGUID+297, 13117, 2107, 10053, 10519, '0', '0', 0, 0, 1, 713.01043701171875, 645.0382080078125, -12.6849632263183593, 4.852015495300292968, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Horde Spirit Guide (Area: Gold Mine - Difficulty: 0) (Auras: 9036 - Ghost, 9617 - Ghost Visual, 22011 - Spirit Heal Channel)

-- -- Stables
(@CGUID+298, 13116, 2107, 10053, 10519, '0', '0', 0, 0, 1, 1199.6649169921875, 1168.6353759765625, -56.055328369140625, 5.201081275939941406, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Alliance Spirit Guide (Area: Gold Mine - Difficulty: 0) (Auras: 9036 - Ghost)
-- HACK: Position is not sniffed. Copied from alliance counter part.
(@CGUID+299, 13117, 2107, 10053, 10519, '0', '0', 0, 0, 1, 1199.6649169921875, 1168.6353759765625, -56.055328369140625, 5.201081275939941406, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Horde Spirit Guide (Area: Gold Mine - Difficulty: 0) (Auras: 9036 - Ghost)

-- Blacksmith
(@CGUID+300, 13116, 2107, 10053, 10519, '0', '0', 0, 0, 1, 1015.827880859375, 961.35675048828125, -42.9489517211914062, 4.991641521453857421, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Alliance Spirit Guide (Area: Gold Mine - Difficulty: 0) (Auras: 9036 - Ghost)
(@CGUID+301, 13117, 2107, 10053, 10519, '0', '0', 0, 0, 1, 1018.02081298828125, 958.703125, -42.7447128295898437, 2.298978567123413085, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Horde Spirit Guide (Area: Gold Mine - Difficulty: 0) (Auras: 9036 - Ghost)

-- Lumber mill
(@CGUID+303, 13116, 2107, 10053, 10519, '0', '0', 0, 0, 1, 775.123291015625, 1206.0521240234375, 15.70810127258300781, 2.146754980087280273, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Alliance Spirit Guide (Area: Gold Mine - Difficulty: 0) (Auras: 9036 - Ghost)
(@CGUID+304, 13117, 2107, 10053, 0, '0', '0', 0, 0, 1, 775.24481201171875, 1206.3663330078125, 15.69617557525634765, 2.007128715515136718, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Horde Spirit Guide (Area: 0 - Difficulty: 0) (Auras: 9036 - Ghost)

-- Farm
(@CGUID+305, 13116, 2107, 10053, 10521, '0', '0', 0, 0, 1, 834.0694580078125, 790.50518798828125, -56.0770912170410156, 4.677482128143310546, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Alliance Spirit Guide (Area: Defiler's Den - Difficulty: 0) (Auras: 9036 - Ghost)
(@CGUID+306, 13117, 2107, 10053, 10521, '0', '0', 0, 0, 1, 833.66143798828125, 790.6805419921875, -56.15740966796875, 4.660028934478759765, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Horde Spirit Guide (Area: Defiler's Den - Difficulty: 0) (Auras: 9036 - Ghost)

-- Gold Mine
(@CGUID+307, 13117, 2107, 10053, 10521, '0', '0', 0, 0, 1, 1204.3228759765625, 786.48089599609375, -83.17376708984375, 5.672319889068603515, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745), -- Horde Spirit Guide (Area: Defiler's Den - Difficulty: 0) (Auras: 9036 - Ghost)
(@CGUID+308, 13116, 2107, 10053, 10517, '0', '0', 0, 0, 1, 1204.3367919921875, 786.421875, -83.171295166015625, 5.707226753234863281, 7200, 0, 0, 117910, 4868, 0, 0, 0, '', 45745); -- Alliance Spirit Guide (Area: Farm - Difficulty: 0) (Auras: 9036 - Ghost)

-- Spawn Groups
DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` BETWEEN @CGUID+0 AND @CGUID+308;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+253),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+184),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+185),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+189),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+190),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+192),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+195),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+196),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+197),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+199),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+200),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+201),
(@SPAWNGROUP_HORDE_FARM, 0, @CGUID+202),
(@SPAWNGROUP_HORDE_FARM_GRAVEYARD, 0, @CGUID+306),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+254),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+276),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+277),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+278),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+279),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+280),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+281),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+282),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+283),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+284),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+285),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+286),
(@SPAWNGROUP_ALLIANCE_FARM, 0, @CGUID+287),
(@SPAWNGROUP_ALLIANCE_FARM_GRAVEYARD, 0, @CGUID+305),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+255),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+203),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+204),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+205),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+206),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+207),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+208),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+209),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+210),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+211),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+212),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+213),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+214),
(@SPAWNGROUP_HORDE_LUMBERMILL, 0, @CGUID+215),
(@SPAWNGROUP_HORDE_LUMBERMILL_GRAVEYARD, 0, @CGUID+304),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+256),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+263),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+264),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+265),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+266),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+267),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+268),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+269),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+270),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+271),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+272),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+273),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+274),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL, 0, @CGUID+275),
(@SPAWNGROUP_ALLIANCE_LUMBERMILL_GRAVEYARD, 0, @CGUID+303),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+257),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+225),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+226),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+227),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+228),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+229),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+230),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+231),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+232),
(@SPAWNGROUP_HORDE_BLACKSMITH, 0, @CGUID+233),
(@SPAWNGROUP_HORDE_BLACKSMITH_GRAVEYARD, 0, @CGUID+301),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+258),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+234),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+235),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+236),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+237),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+238),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+239),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+240),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+241),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH, 0, @CGUID+242),
(@SPAWNGROUP_ALLIANCE_BLACKSMITH_GRAVEYARD, 0, @CGUID+300),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+259),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+288),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+289),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+290),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+291),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+292),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+293),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+294),
(@SPAWNGROUP_HORDE_GOLDMINE, 0, @CGUID+295),
(@SPAWNGROUP_HORDE_GOLDMINE_GRAVEYARD, 0, @CGUID+307),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+260),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+216),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+217),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+218),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+219),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+220),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+221),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+222),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+223),
(@SPAWNGROUP_ALLIANCE_GOLDMINE, 0, @CGUID+224),
(@SPAWNGROUP_ALLIANCE_GOLDMINE_GRAVEYARD, 0, @CGUID+308),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+261),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+243),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+244),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+245),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+246),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+247),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+248),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+249),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+250),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+251),
(@SPAWNGROUP_HORDE_STABLES, 0, @CGUID+252),
(@SPAWNGROUP_HORDE_STABLES_GRAVEYARD, 0, @CGUID+299),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+262),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+170),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+171),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+172),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+173),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+174),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+175),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+176),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+177),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+178),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+179),
(@SPAWNGROUP_ALLIANCE_STABLES, 0, @CGUID+180),
(@SPAWNGROUP_ALLIANCE_STABLES_GRAVEYARD, 0, @CGUID+298);

DELETE FROM `creature_formations` WHERE `memberGUID` BETWEEN @CGUID AND @CGUID+295 OR `leaderGUID` BETWEEN @CGUID AND @CGUID+295;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+51, @CGUID+51, 0, 0, 515, 0, 0),
(@CGUID+51, @CGUID+57, 10, 45, 515, 0, 0),
(@CGUID+51, @CGUID+124, 10, 315, 515, 0, 0),
(@CGUID+65, @CGUID+65, 0, 0, 515, 0, 0),
(@CGUID+65, @CGUID+153, 10, 45, 515, 0, 0),
(@CGUID+65, @CGUID+158, 10, 315, 515, 0, 0),
(@CGUID+172, @CGUID+172, 0, 0, 515, 0, 0),
(@CGUID+172, @CGUID+176, 4, 315, 515, 0, 0),
(@CGUID+173, @CGUID+173, 0, 0, 515, 0, 0),
(@CGUID+173, @CGUID+177, 2, 315, 515, 0, 0),
(@CGUID+246, @CGUID+246, 0, 0, 515, 0, 0),
(@CGUID+246, @CGUID+248, 4, 315, 515, 0, 0),
(@CGUID+252, @CGUID+252, 0, 0, 515, 0, 0),
(@CGUID+252, @CGUID+250, 2, 315, 515, 0, 0);

-- movement templates
DELETE FROM `creature_movement_override` WHERE `SpawnId` BETWEEN @CGUID+0 AND @CGUID+295;
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@CGUID+21, 1, 0, 0, 1, 0, 0, NULL), -- Arathor Watchman
(@CGUID+62, 1, 0, 0, 1, 0, 0, NULL), -- Arathor Watchman
(@CGUID+71, 1, 0, 0, 1, 0, 0, NULL), -- Arathor Watchman
(@CGUID+132, 1, 0, 0, 1, 0, 0, NULL), -- Arathor Watchman
(@CGUID+148, 1, 0, 0, 1, 0, 0, NULL), -- Arathor Watchman
(@CGUID+163, 1, 0, 0, 1, 0, 0, NULL), -- Arathor Watchman
(@CGUID+175, 1, 0, 0, 1, 0, 0, NULL), -- Arathi Horse
(@CGUID+203, 1, 0, 0, 1, 0, 0, NULL), -- Forsaken Lumberjack
(@CGUID+206, 1, 0, 0, 1, 0, 0, NULL), -- Forsaken Lumberjack
(@CGUID+230, 1, 0, 0, 1, 0, 0, NULL), -- Forsaken Blacksmith
(@CGUID+242, 1, 0, 0, 1, 0, 0, NULL), -- Arathi Blacksmith
(@CGUID+249, 1, 0, 0, 1, 0, 0, NULL); -- Forsaken Horse

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+295;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '282578'), -- Defiler Combatant - 282578 - Hold Torch
(@CGUID+16, (((@CGUID + 16) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '282578'), -- Arathor Watchman - 282578 - Hold Torch
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '282578'), -- Arathor Watchman - 282578 - Hold Torch
(@CGUID+24, 0, 10719, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- The Black Bride
(@CGUID+38, 0, 14337, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Radulf Leder
(@CGUID+59, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '145363'), -- Arathor Watchman - 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+51, (((@CGUID + 51) * 10) << 3) + 0, 47166, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Arathor Gryphon Rider
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Arathor Watchman
(@CGUID+65, (((@CGUID + 58) * 10) << 3) + 0, 1566, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Defiler Bat Rider
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Arathor Watchman
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '282578'), -- Defiler Combatant - 282578 - Hold Torch
(@CGUID+102, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '285977'), -- Bound Arathi Rager - 285977 - Earth Channel Omni
(@CGUID+126, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '285977'), -- Bound Arathi Rager - 285977 - Earth Channel Omni
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Arathor Watchman
(@CGUID+148, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Arathor Watchman
(@CGUID+152, (((@CGUID + 152) * 10) << 3) + 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '282578'), -- Defiler Combatant - 282578 - Hold Torch
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145363'), --  Arathor Watchman - 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+163, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Arathor Watchman
(@CGUID+172, (((@CGUID + 246) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Stablehand
(@CGUID+173, (((@CGUID + 252) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Arathi Stablehand
(@CGUID+203, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Forsaken Lumberjack
(@CGUID+206, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Forsaken Lumberjack
(@CGUID+208, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Forsaken Lumberjack - 290604 - Lumberjackin
(@CGUID+211, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Forsaken Lumberjack - 290604 - Lumberjackin
(@CGUID+212, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Forsaken Lumberjack - 290604 - Lumberjackin
(@CGUID+213, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Forsaken Lumberjack - 290604 - Lumberjackin
(@CGUID+214, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Forsaken Lumberjack - 290604 - Lumberjackin
(@CGUID+215, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Forsaken Lumberjack - 290604 - Lumberjackin
(@CGUID+216, 0, 0, 0, 0, 0, 1, 0, 766, 0, 0, 0, 0, ''), -- Arathi Miner
(@CGUID+218, 0, 0, 0, 0, 0, 1, 0, 766, 0, 0, 0, 0, ''), -- Arathi Miner
(@CGUID+222, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '217075'), -- Arathi Miner - 217075 - Sleeping Sleep
(@CGUID+223, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Arathi Miner
(@CGUID+227, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '261985'), -- Forsaken Blacksmith - 261985 - Blacksmith Working
(@CGUID+230, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Forsaken Blacksmith
(@CGUID+241, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '261985'), -- Forsaken Blacksmith - 261985 - Blacksmith Working
(@CGUID+242, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Arathi Blacksmith
(@CGUID+246, (((@CGUID + 246) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forsaken Stablehand
(@CGUID+252, (((@CGUID + 252) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forsaken Stablehand
(@CGUID+253, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+254, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Alliance Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+255, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Alliance Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+257, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+258, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Alliance Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+259, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+260, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Alliance Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+261, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+262, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Alliance Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+263, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Arathi Lumberjack - 290604 - Lumberjackin
(@CGUID+265, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Arathi Lumberjack - 290604 - Lumberjackin
(@CGUID+268, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Arathi Lumberjack
(@CGUID+269, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Arathi Lumberjack - 290604 - Lumberjackin
(@CGUID+271, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Arathi Lumberjack - 290604 - Lumberjackin
(@CGUID+272, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Arathi Lumberjack - 290604 - Lumberjackin
(@CGUID+274, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Arathi Lumberjack
(@CGUID+275, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '290604'), -- Arathi Lumberjack - 290604 - Lumberjackin
(@CGUID+288, 0, 0, 0, 0, 0, 1, 0, 766, 0, 0, 0, 0, ''), -- Forsaken Miner
(@CGUID+289, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '217075'), -- Forsaken Miner - 217075 - Sleeping Sleep
(@CGUID+295, 0, 0, 0, 0, 0, 1, 0, 766, 0, 0, 0, 0, ''), -- Forsaken Miner
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, ''), -- Arathi Giant
(@CGUID+111, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, ''), -- Arathi Giant
(@CGUID+112, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 3, ''), -- Arathi Giant
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Bound Arathi Rager
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Bound Arathi Rager
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''); -- Bound Arathi Rager

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 322273, 2107, 10053, 10521, '0', '0', 0, 1284.77783203125, 1280.7239990234375, -15.5517463684082031, 3.961897850036621093, 0.003005027770996093, -0.01773643493652343, -0.91688156127929687, 0.398753851652145385, 7200, 255, 1, 44325), -- Alliance Door (Area: Defiler's Den - Difficulty: 0)
(@OGUID+1, 322274, 2107, 10053, 10521, '0', '0', 0, 708.14239501953125, 708.76043701171875, -17.631387710571289, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 7200, 255, 1, 44325), -- Horde Door (Area: Defiler's Den - Difficulty: 0)
(@OGUID+2, 319261, 2107, 10053, 10521, '0', '0', 0, 1295.513916015625, 1337.625, -5.47695112228393554, 5.192355155944824218, 0, 0, -0.51877307891845703, 0.854911983013153076, 7200, 255, 1, 44325), -- Fine Food and Refreshments (Area: Defiler's Den - Difficulty: 0)
(@OGUID+3, 319262, 2107, 10053, 10521, '0', '0', 0, 1365.282958984375, 1306.4461669921875, -4.43625354766845703, 0.061086613684892654, 0, 0, 0.030538558959960937, 0.999533593654632568, 7200, 255, 1, 44325), -- Blacksmith (Area: Defiler's Den - Difficulty: 0)
(@OGUID+4, 317303, 2107, 10053, 10521, '0', '0', 0, 810.8836669921875, 782.1024169921875, -56.8683090209960937, 1.265360832214355468, 0.038332939147949218, -0.08645439147949218, 0.587144851684570312, 0.803938508033752441, 7200, 255, 1, 44325), -- First Prize: "Big Bertha" (Area: Defiler's Den - Difficulty: 0)
(@OGUID+5, 322022, 2107, 10053, 10521, '0', '0', 0, 528.5538330078125, 516.2882080078125, 64.067626953125, 1.659621834754943847, -0.03941202163696289, 0.236527442932128906, 0.696545600891113281, 0.676258623600006103, 7200, 255, 1, 44325), -- Defiler Wagon (Area: Defiler's Den - Difficulty: 0)
(@OGUID+6, 180322, 2107, 10053, 10521, '0', '0', 0, 1284.63720703125, 1280.6822509765625, -16.3245010375976562, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 7200, 255, 1, 44325), -- Ghost Gate (Area: Defiler's Den - Difficulty: 0)
(@OGUID+7, 180322, 2107, 10053, 10521, '0', '0', 0, 708.107666015625, 708.6180419921875, -18.3004169464111328, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 7200, 255, 1, 44325), -- Ghost Gate (Area: Defiler's Den - Difficulty: 0)
(@OGUID+8, 325741, 2107, 10053, 10521, '0', '0', 0, 987.8297119140625, 1005.13458251953125, -42.2905387878417968, 3.116126298904418945, 0, 0, 0.999918937683105468, 0.012732816860079765, 7200, 255, 1, 44325), -- Anvil (Area: Defiler's Den - Difficulty: 0)
(@OGUID+9, 325742, 2107, 10053, 10521, '0', '0', 0, 996.26495361328125, 1009.94683837890625, -42.3335304260253906, 3.701466083526611328, 0, 0, -0.96107292175292968, 0.276294827461242675, 7200, 255, 1, 44325), -- Anvil (Area: Defiler's Den - Difficulty: 0)
(@OGUID+10, 325743, 2107, 10053, 10521, '0', '0', 0, 993.944091796875, 1001.09075927734375, -42.6673851013183593, 1.89441680908203125, 0, 0, 0.811788558959960937, 0.583951532840728759, 7200, 255, 1, 44325), -- Anvil (Area: Defiler's Den - Difficulty: 0)
(@OGUID+11, 319223, 2107, 10053, 10521, '0', '0', 0, 711.23785400390625, 687.91668701171875, -16.0303688049316406, 3.473215818405151367, -0.02870512008666992, -0.0069131851196289, -0.98584461212158203, 0.165041223168373107, 7200, 255, 1, 44325), -- Derek's Heavy Metals (Area: Defiler's Den - Difficulty: 0)
(@OGUID+12, 319224, 2107, 10053, 10521, '0', '0', 0, 678.578125, 719.45831298828125, -13.0993480682373046, 1.562067508697509765, 0.010341644287109375, -0.00907707214355468, 0.70395660400390625, 0.710109710693359375, 7200, 255, 1, 44325), -- Meats and Treats (Area: Defiler's Den - Difficulty: 0)
(@OGUID+13, 319225, 2107, 10053, 10521, '0', '0', 0, 799.94964599609375, 1173.1041259765625, 15.10321426391601562, 3.935718059539794921, -0.10708475112915039, -0.04864788055419921, -0.91564178466796875, 0.384403884410858154, 7200, 255, 1, 44325), -- Days Since Last Incident: 0 (Area: Defiler's Den - Difficulty: 0)
(@OGUID+14, 227536, 2107, 10053, 0, '0', '0', 0, 806.25, 874.279541015625, -56.5307502746582031, 0.818242669105529785, 0, 0, 0.397803306579589843, 0.917470753192901611, 7200, 255, 1, 44325), -- Capture Point (Area: 0 - Difficulty: 0)
(@OGUID+15, 227420, 2107, 10053, 0, '0', '0', 0, 1166.85595703125, 1200.12158203125, -56.3867416381835937, 0.886092901229858398, 0, 0, 0.428693771362304687, 0.903449833393096923, 7200, 255, 1, 44325), -- Capture Point (Area: 0 - Difficulty: 0)
(@OGUID+16, 227522, 2107, 10053, 0, '0', '0', 0, 977.50518798828125, 1051.0728759765625, -44.7925682067871093, 0.497109025716781616, 0, 0, 0.246003150939941406, 0.969269037246704101, 7200, 255, 1, 44325), -- Capture Point (Area: 0 - Difficulty: 0)
(@OGUID+17, 239300, 2107, 10053, 0, '0', '0', 0, 1647.1859130859375, 1520.0076904296875, 131.380218505859375, 0.846484839916229248, 0, 0, 0.410718917846679687, 0.911761999130249023, 7200, 255, 1, 44325), -- Chair (Area: 0 - Difficulty: 0)
(@OGUID+18, 239301, 2107, 10053, 0, '0', '0', 0, 1646.765869140625, 1522.818603515625, 131.380218505859375, 5.907940864562988281, 0, 0, -0.1865234375, 0.982450485229492187, 7200, 255, 1, 44325), -- Chair (Area: 0 - Difficulty: 0)
(@OGUID+19, 227544, 2107, 10053, 10516, '0', '0', 0, 856.8663330078125, 1150.2135009765625, 11.04314804077148437, 0.989707827568054199, 0, 0, 0.474903106689453125, 0.880038082599639892, 7200, 255, 1, 44325), -- Capture Point (Area: Lumber Mill - Difficulty: 0)
(@OGUID+20, 227538, 2107, 10053, 10516, '0', '0', 0, 1146.9288330078125, 848.2274169921875, -110.917579650878906, 2.417101383209228515, 0, 0, 0.935103416442871093, 0.354374974966049194, 7200, 255, 1, 44325), -- Capture Point (Area: Lumber Mill - Difficulty: 0)
-- buffs
-- -- Farm
(@OGUID+21, 180145, 2107, 10053, 10521, '0', '0', 0, 815.29339599609375, 842.58331298828125, -56.0177841186523437, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 90, 255, 1, 45745), -- Food Buff (Area: Defiler's Den - Difficulty: 0)
(@OGUID+22, 180382, 2107, 10053, 10517, '0', '0', 0, 815.29339599609375, 842.58331298828125, -56.0177841186523437, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 90, 255, 1, 45745), -- Berserk Buff (Area: Farm - Difficulty: 0)
(@OGUID+23, 180147, 2107, 10053, 10519, '0', '0', 0, 815.29339599609375, 842.58331298828125, -56.0177841186523437, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 90, 255, 1, 45745), -- Speed Buff (Area: Gold Mine - Difficulty: 0)
-- -- Gold Mine
(@OGUID+24, 180147, 2107, 10053, 10519, '0', '0', 0, 1147.0242919921875, 816.83160400390625, -99.2923507690429687, 0.4253254234790802, 0, 0, 0.211063385009765625, 0.977472364902496337, 90, 255, 1, 45745), -- Speed Buff (Area: Gold Mine - Difficulty: 0)
(@OGUID+25, 180376, 2107, 10053, 10519, '0', '0', 0, 1147.0242919921875, 816.83160400390625, -99.2923507690429687, 0.4253254234790802, 0, 0, 0.211063385009765625, 0.977472364902496337, 90, 255, 1, 45745), -- Berserk Buff (Area: Gold Mine - Difficulty: 0)
(@OGUID+26, 180362, 2107, 10053, 10514, '0', '0', 0, 1147.0242919921875, 816.83160400390625, -99.2923507690429687, 0.4253254234790802, 0, 0, 0.211063385009765625, 0.977472364902496337, 90, 255, 1, 45745), -- Food Buff (Area: Blacksmith - Difficulty: 0)
-- -- lumber mill
(@OGUID+27, 180146, 2107, 10053, 10519, '0', '0', 0, 808.84625244140625, 1185.41748046875, 11.92160511016845703, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 90, 255, 1, 45745), -- Speed Buff (Area: Gold Mine - Difficulty: 0)
(@OGUID+28, 180376, 2107, 10053, 10514, '0', '0', 0, 808.84625244140625, 1185.41748046875, 11.92160511016845703, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 90, 255, 1, 45745), -- Berserk Buff (Area: Blacksmith - Difficulty: 0)
(@OGUID+29, 180362, 2107, 10053, 10514, '0', '0', 0, 808.84625244140625, 1185.41748046875, 11.92160511016845703, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 90, 255, 1, 45745), -- Food Buff (Area: Blacksmith - Difficulty: 0)
-- -- Blacksmith
(@OGUID+30, 180384, 2107, 10053, 10514, '0', '0', 0, 990.046875, 1008.62152099609375, -42.2709541320800781, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 90, 255, 1, 45745), -- Speed Buff (Area: Blacksmith - Difficulty: 0)
(@OGUID+31, 180376, 2107, 10053, 10514, '0', '0', 0, 990.046875, 1008.62152099609375, -42.2709541320800781, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 90, 255, 1, 45745), -- Berserk Buff (Area: Blacksmith - Difficulty: 0)
(@OGUID+32, 180362, 2107, 10053, 10514, '0', '0', 0, 990.046875, 1008.62152099609375, -42.2709541320800781, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 90, 255, 1, 45745), -- Food Buff (Area: Blacksmith - Difficulty: 0)
-- -- Stables
(@OGUID+33, 180379, 2107, 10053, 10521, '0', '0', 0, 1184.251708984375, 1186.52783203125, -56.126007080078125, 2.367344856262207031, 0, 0, 0.925998687744140625, 0.377526760101318359, 90, 255, 1, 45745), -- Speed Buff (Area: Defiler's Den - Difficulty: 0)
(@OGUID+34, 180376, 2107, 10053, 10521, '0', '0', 0, 1184.251708984375, 1186.52783203125, -56.126007080078125, 2.367344856262207031, 0, 0, 0.925998687744140625, 0.377526760101318359, 90, 255, 1, 45745), -- Berserk Buff (Area: Defiler's Den - Difficulty: 0)
(@OGUID+35, 180362, 2107, 10053, 10521, '0', '0', 0, 1184.251708984375, 1186.52783203125, -56.126007080078125, 2.367344856262207031, 0, 0, 0.925998687744140625, 0.377526760101318359, 90, 255, 1, 45745); -- Food Buff (Area: Defiler's Den - Difficulty: 0)

-- remove in use flag from horde door & alliance door
UPDATE `gameobject_template_addon` SET `flags` = `flags` &~ 0x1 WHERE `entry` IN (322273, 322274);

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+8, 0, 0, 0.944089233875274658, 0.329689979553222656, 0, 0), -- Anvil
(@OGUID+9, 0, 0, 0.944089233875274658, 0.329689979553222656, 0, 0), -- Anvil
(@OGUID+10, 0, 0, 0.944089233875274658, 0.329689979553222656, 0, 0), -- Anvil
(@OGUID+17, 0, 0, -0.65275973081588745, 0.757565081119537353, 0, 0), -- Chair
(@OGUID+18, 0, 0, -0.65275973081588745, 0.757565081119537353, 0, 0); -- Chair

-- pooling for buffs
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL AND @POOL+4;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL, 1, 'Arathi Basin - Buffs - Farm'),
(@POOL+1, 1, 'Arathi Basin - Buffs - Gold Mine'),
(@POOL+2, 1, 'Arathi Basin - Buffs - Lumber Mill'),
(@POOL+3, 1, 'Arathi Basin - Buffs - Blacksmith'),
(@POOL+4, 1, 'Arathi Basin - Buffs - Stables');

DELETE FROM `pool_members` WHERE poolSpawnId BETWEEN @POOL AND @POOL+4;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+21, @POOL, 0, 'Food Buff'),
(1, @OGUID+22, @POOL, 0, 'Berserker Buff'),
(1, @OGUID+23, @POOL, 0, 'Speed Buff'),
(1, @OGUID+24, @POOL+1, 0, 'Speed Buff'),
(1, @OGUID+25, @POOL+1, 0, 'Berserker Buff'),
(1, @OGUID+26, @POOL+1, 0, 'Food Buff'),
(1, @OGUID+27, @POOL+2, 0, 'Speed Buff'),
(1, @OGUID+28, @POOL+2, 0, 'Berserker Buff'),
(1, @OGUID+29, @POOL+2, 0, 'Food Buff'),
(1, @OGUID+30, @POOL+3, 0, 'Speed Buff'),
(1, @OGUID+31, @POOL+3, 0, 'Berserker Buff'),
(1, @OGUID+32, @POOL+3, 0, 'Food Buff'),
(1, @OGUID+33, @POOL+4, 0, 'Speed Buff'),
(1, @OGUID+34, @POOL+4, 0, 'Berserker Buff'),
(1, @OGUID+35, @POOL+4, 0, 'Food Buff');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (150513 /*150513 (Arathor Gryphon Rider)*/, 150459 /*Defiler Bat Rider*/);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(150513, 0, 0, 1, 0, 0, NULL),
(150459, 0, 0, 1, 0, 0, NULL);

DELETE FROM `creature_template_addon` WHERE `entry` IN (26350 /*Alliance Graveyard Teleporter*/, 15071 /*15071 (Underfoot) - Grow*/, 73400 /*73400 (Healing Ran Invisible Stalker DND) - Healing Rain Visual*/, 15063 /*15063 (Arathi Blacksmith) - Blacksmith Working*/, 15065 /*15065 (Lady)*/, 15064 /*15064 (Forsaken Blacksmith) - Blacksmith Working*/, 15074 /*15074 (Arathi Miner) - Carry Sack*/, 15089 /*15089 (Forsaken Lumberjack) - Lumberjackin'*/, 15046 /*15046 (Forsaken Farmer)*/, 150622 /*150622 (Dominic Masonwrite) - Read Scroll*/, 150414 /*150414 (Lightning) - Sleeping Sleep*/, 150418 /*150418 (Arathor Siege Tank)*/, 150459 /*150459 (Defiler Bat Rider)*/, 150513 /*150513 (Arathor Gryphon Rider)*/, 150543 /*150543 (Belle)*/, 149755 /*149755 (Kevin Young) - Blacksmith Working*/, 150403 /*150403 (Arathor Watchman) - Hold Torch*/, 150429 /*150429 (Defiler Combatant) - Hold Torch*/, 150655 /*150655 (Groundskeeper Olivia)*/, 150426 /*150426 (Arathi Giant)*/, 149719, 150501, 150505);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(15065, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 15065 (Lady)
(15071, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '24244'), -- 15071 (Underfoot) - Grow
(26350, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '8149'), -- 26350 (Alliance Graveyard Teleporter) - Super Invis
(150414, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '217075'), -- 150414 (Lightning) - Sleeping Sleep
(150418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 150418 (Arathor Siege Tank)
(150426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 150426 (Arathi Giant)
(150459, 0, 1566, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 150459 (Defiler Bat Rider)
(150513, 0, 47166, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 150513 (Arathor Gryphon Rider)
(150543, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 150543 (Belle)
(149719, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '32951'); -- 149719 - Sleeping Sleep

-- add UNIT_FLAG_IMMUNE_TO_PC & UNIT_FLAG_IMMUNE_TO_NPC
UPDATE `creature_template` SET `unit_flags` = `unit_flags` | 0x100 | 0x200 WHERE `entry` IN (
    15087, -- Forsaken Stablehand
    15062, -- Arathi Lumberjack
    15063, -- Arathi Blacksmith
    15064, -- Forsaken Blacksmith
    15074, -- Arathi Miner
    15075, -- Forsaken Miner
    15089, -- Forsaken Lumberjack
    15045, -- Arathi Farmer
    15046, -- Forsaken Farmer
    15086 -- Arathi Stablehand
);

DELETE FROM `creature_template_gossip` WHERE `CreatureID` = 150622 AND `MenuID` = 23883;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(150622, 23883, 48676);

DELETE FROM `npc_vendor` WHERE (`entry`=149721 AND `item`=163054 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149721 AND `item`=161127 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149721 AND `item`=159900 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149721 AND `item`=163060 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149721 AND `item`=159868 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149721 AND `item`=159867 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=149718 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(149721, 6, 163054, 0, 0, 1, 0, 0, 45745), -- Stranglethorn Prickly Pear
(149721, 5, 161127, 0, 0, 1, 0, 0, 45745), -- Unsalted Pine Nuts
(149721, 4, 159900, 0, 0, 1, 0, 0, 45745), -- Caraway Rye Loaf
(149721, 3, 163060, 0, 0, 1, 0, 0, 45745), -- Fried Sweetbread
(149721, 2, 159868, 0, 0, 1, 0, 0, 45745), -- Free-Range Goat's Milk
(149721, 1, 159867, 0, 0, 1, 0, 0, 45745), -- Rockskip Mineral Water
(149718, 34, 39505, 0, 0, 1, 0, 0, 45745), -- Virtuoso Inking Set
(149718, 33, 20815, 0, 0, 1, 0, 0, 45745), -- Jeweler's Kit
(149718, 32, 6532, 0, 0, 1, 0, 0, 45745), -- Bright Baubles
(149718, 31, 6530, 0, 0, 1, 0, 0, 45745), -- Nightcrawlers
(149718, 30, 4400, 0, 0, 1, 0, 0, 45745), -- Heavy Stock
(149718, 29, 4399, 0, 0, 1, 0, 0, 45745), -- Wooden Stock
(149718, 28, 4289, 0, 0, 1, 0, 0, 45745), -- Salt
(149718, 27, 3371, 0, 0, 1, 0, 0, 45745), -- Crystal Vial
(149718, 26, 4340, 0, 0, 1, 0, 0, 45745), -- Gray Dye
(149718, 25, 4342, 0, 0, 1, 0, 0, 45745), -- Purple Dye
(149718, 24, 4341, 0, 0, 1, 0, 0, 45745), -- Yellow Dye
(149718, 23, 2325, 0, 0, 1, 0, 0, 45745), -- Black Dye
(149718, 22, 2604, 0, 0, 1, 0, 0, 45745), -- Red Dye
(149718, 21, 3857, 0, 0, 1, 0, 0, 45745), -- Coal
(149718, 20, 3466, 0, 0, 1, 0, 0, 45745), -- Strong Flux
(149718, 19, 2880, 0, 0, 1, 0, 0, 45745), -- Weak Flux
(149718, 18, 2678, 0, 0, 1, 0, 0, 45745), -- Mild Spices
(149718, 17, 38426, 0, 0, 1, 0, 0, 45745), -- Eternium Thread
(149718, 16, 14341, 0, 0, 1, 0, 0, 45745), -- Rune Thread
(149718, 15, 8343, 0, 0, 1, 0, 0, 45745), -- Heavy Silken Thread
(149718, 14, 4291, 0, 0, 1, 0, 0, 45745), -- Silken Thread
(149718, 13, 2321, 0, 0, 1, 0, 0, 45745), -- Fine Thread
(149718, 12, 2320, 0, 0, 1, 0, 0, 45745), -- Coarse Thread
(149718, 11, 5956, 0, 0, 1, 0, 0, 45745), -- Blacksmith Hammer
(149718, 10, 6217, 0, 0, 1, 0, 0, 45745), -- Copper Rod
(149718, 9, 6256, 0, 0, 1, 0, 0, 45745), -- Fishing Pole
(149718, 8, 85663, 0, 0, 1, 0, 0, 45745), -- Herbalist's Spade
(149718, 7, 7005, 0, 0, 1, 0, 0, 45745), -- Skinning Knife
(149718, 6, 2901, 0, 0, 1, 0, 0, 45745), -- Mining Pick
(149718, 5, 160059, 0, 0, 1, 0, 0, 45745), -- Amber Tanning Oil
(149718, 4, 160298, 0, 0, 1, 0, 0, 45745), -- Durable Flux
(149718, 3, 159959, 0, 0, 1, 0, 0, 45745), -- Nylon Thread
(149718, 2, 158205, 0, 0, 1, 0, 0, 45745), -- Acacia Powder
(149718, 1, 158186, 0, 0, 1, 0, 0, 45745); -- Distilled Water

DELETE FROM `gossip_menu` WHERE (`MenuID`=23883 AND `TextID`=37443);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23883, 37443, 45745); -- 150622 (Dominic Masonwrite)

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_bg_ab_blacksmith_working');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(261985, 'spell_bg_ab_blacksmith_working');

-- waypoints

-- Kevin Young @CGUID+27
SET @WAYPOINT_ID := ((@CGUID + 27) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN  @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 1361.5504, 1302.3229, -8.83024, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1362.7517, 1303.1233, -8.924723, NULL, 0, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 1362.7517, 1303.1233, -8.924723, 3.141592741012573242, 1000, 0),
(@WAYPOINT_ID + 1, 2, 1361.2170, 1300.3594, -8.796671, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 1362.4202, 1299.8959, -8.533002, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 1364.2379, 1299.7778, -8.600507, 0.07065419852733612, 1, 0);


-- Forksane Stablehand (@CGUID+246) & Arathi Stablehand (@CGUID+172)
SET @WAYPOINT_ID := ((@CGUID + 246) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`=@WAYPOINT_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 1168.0868, 1175.5591, -56.53989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1164.5139, 1175.382, -56.555138, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 1162.6632, 1173.7223, -56.38717, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 1158.8767, 1168.1892, -56.305138, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 1157.8298, 1166.2639, -56.33967, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 1157.3524, 1163.5747, -56.33967, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 1157.3577, 1160.342, -56.356636, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 1157.7188, 1157.8021, -56.46467, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 1158.3021, 1155.125, -56.845894, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 1159.0192, 1152.8854, -56.74848, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 1159.9185, 1151.0591, -56.529243, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 1161.1007, 1148.7812, -56.4842, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 1162.9166, 1146.7743, -56.265083, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 1164.4115, 1145.8212, -56.33967, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 1166.5122, 1145.2969, -56.33967, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 1169.224, 1145.0295, -56.16866, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 1172.2743, 1145.6979, -56.04366, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 1175.724, 1147.474, -56.16866, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 1176.6823, 1148.6233, -56.190876, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 1177.4618, 1152.8091, -56.31075, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 1177.5017, 1155.7743, -56.41866, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 1177.5382, 1158.7535, -56.426594, NULL, 0, 0),
(@WAYPOINT_ID + 0, 23, 1177.4288, 1161.132, -56.41866, NULL, 0, 0),
(@WAYPOINT_ID + 0, 24, 1177.3247, 1162.9375, -56.41866, NULL, 0, 0),
(@WAYPOINT_ID + 0, 25, 1175.9774, 1166.3004, -56.41866, NULL, 0, 0),
(@WAYPOINT_ID + 0, 26, 1173.6598, 1172.9236, -56.388157, 2.576671123504638671, 1, 0);


-- Forsaken Stablehand (@CGUID+252) & Arathi Stablehand (@CGUID+173)
SET @WAYPOINT_ID := ((@CGUID + 252) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`=@WAYPOINT_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 1197.5729, 1178.9827, -56.41489, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1199.8976, 1181.3785, -56.46506, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 1201.481, 1185.2084, -56.59116, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 1201.9791, 1187.9149, -56.46616, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 1201.8854, 1190.375, -56.46616, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 1200.2274, 1193.618, -56.46616, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 1198.7048, 1195.9375, -56.41489, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 1196.9098, 1198.151, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 1194.1945, 1200.2118, -56.350773, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 1190.4757, 1201.0243, -56.37409, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 1188.1545, 1200.717, -56.212223, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 1185.6927, 1199.5087, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 1183.0938, 1197.4098, -56.232273, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 1178.3942, 1192.8091, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 1174.033, 1188.9236, -56.128025, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 1171.1615, 1187.4827, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 1169.3142, 1186.9479, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 1167.8142, 1185.4062, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 1167.1163, 1183.3055, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 1170.1875, 1179.632, -56.421604, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 1173.1459, 1177.6198, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 1176.9219, 1174.7274, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 23, 1178.8976, 1172.125, -56.28989, NULL, 0, 0),
(@WAYPOINT_ID + 0, 24, 1179.5712, 1169.3976, -56.135838, NULL, 0, 0),
(@WAYPOINT_ID + 0, 25, 1180.3229, 1167.0851, -56.41489, NULL, 0, 0),
(@WAYPOINT_ID + 0, 26, 1182.2952, 1164.8785, -56.41866, NULL, 0, 0),
(@WAYPOINT_ID + 0, 27, 1185.9185, 1163.3177, -56.29598, NULL, 0, 0),
(@WAYPOINT_ID + 0, 28, 1188.5365, 1163.7882, -56.29366, NULL, 0, 0),
(@WAYPOINT_ID + 0, 29, 1190.0399, 1166.0885, -56.29366, NULL, 0, 0),
(@WAYPOINT_ID + 0, 30, 1196.217, 1174.0764, -56.75803, 0.798887610435485839, 1, 0);

-- Forsaken Farmer (@CGUID+184)
SET @WAYPOINT_ID := ((@CGUID + 184) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` IN(@WAYPOINT_ID+0, @WAYPOINT_ID+1);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 821.6684, 810.80554, -57.48747, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 818.63367, 813.94965, -57.375774, 0.837758064270019531, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 825.9809, 806.86456, -57.72697, 1.02881479263305664, 1500, 0);

-- Forsaken Farmer (@CGUID+199)
SET @WAYPOINT_ID := ((@CGUID + 199) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 821.04517, 819.8733, -57.59074, 0.837758064270019531, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 826.8924, 814.22394, -57.71574, 0.982451319694519042, 1500, 0);


-- Forsaken Farmer (@CGUID+196)
SET @WAYPOINT_ID := ((@CGUID + 196) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 834.49133, 818.9601, -57.790867, 0.837758064270019531, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 830.5278, 823.3368, -57.84074, 1.02881479263305664, 1500, 0);

-- Forsaken Farmer (@CGUID+185)
SET @WAYPOINT_ID := ((@CGUID + 185) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 845.2882, 824.1458, -57.665867, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 848.0174, 821.48956, -57.724216, 3.96189737319946289, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 837.29865, 831.9427, -57.502537, 4.234867572784423828, 1500, 0);

-- Forsaken Farmer (@CGUID+190)
SET @WAYPOINT_ID := ((@CGUID + 190) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 849.059, 833.38196, -57.263157, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 842.88544, 839.25, -57.944798, 3.96189737319946289, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 857.283, 825.34204, -57.18735, 4.251018524169921875, 1500, 0);

-- Forsaken Farmer (@CGUID+189)
SET @WAYPOINT_ID := ((@CGUID + 189) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 853.86285, 853.3299, -58.031956, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 846.90454, 860.46875, -58.069798, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 832.0643, 875.191, -58.3522, 3.96189737319946289, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 860.5226, 846.13715, -58.069798, 4.185294151306152343, 1500, 0);

-- Forsaken Farmer (@CGUID+202)
SET @WAYPOINT_ID := ((@CGUID + 202) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 846.434, 844.30383, -57.694798, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 854.8785, 835.316, -57.444798, 3.96189737319946289, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 837.68054, 852.92883, -57.490086, 3.991605520248413085, 1500, 0);

-- Forsaken Farmer (@CGUID+200)
SET @WAYPOINT_ID := ((@CGUID + 200) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 838.99304, 863.658, -58.021336, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 844.9097, 858.0625, -58.021458, 3.96189737319946289, 1, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 831.9531, 870.5625, -58.04678, 4.234867572784423828, 1500, 0);

-- Forsaken Farmer (@CGUID+195)
SET @WAYPOINT_ID := ((@CGUID + 195) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 796.25867, 816.6042, -57.209515, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 800.2066, 817.04865, -57.253338, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 803.4375, 816.31946, -57.13664, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 807.3802, 813.7917, -57.28886, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 812.7465, 808.69446, -57.46574, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 818.84375, 802.658, -57.46574, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 823.4514, 798.7934, -57.478104, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 824.7552, 794.9184, -57.39766, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 825.1424, 790.25696, -57.121414, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 822.8733, 788.542, -57.103104, NULL, 0, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 822.01044, 800.2743, -57.46574, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 817.59204, 805.8403, -57.46574, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 812.0156, 810.816, -57.470135, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 806.3906, 816.0139, -57.21574, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 800.7083, 818.2639, -57.19328, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 794.7197, 817.9238, -56.77946, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 790.19617, 816.32294, -56.43681, NULL, 0, 0);

-- Arathi Miner (@CGUID+217)
SET @WAYPOINT_ID := ((@CGUID + 217) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+2;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 1188.9341, 786.9722, -86.24333, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1183.2153, 786.27606, -87.766525, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 1176.981, 788.4549, -90.15129, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 1172.5608, 792.07294, -92.63066, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 1168.1562, 798.0955, -95.59209, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 1166.3837, 805.44965, -97.83262, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 1166.1823, 812.6441, -99.58799, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 1167.0928, 816.53906, -100.406746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 1171.1442, 820.7222, -101.43043, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 1171.1445, 820.72266, -101.156746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 1174.3524, 823.30383, -101.045906, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 1177.0903, 823.94446, -100.59107, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 1179.167, 822.98267, -100.10218, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 1179.167, 822.9824, -100.281746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 1179.6484, 822.10254, -100.031746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 1180.372, 821.67926, -99.51519, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 1180.5938, 821.57117, -99.43369, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 1180.7952, 821.3516, -99.33265, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 1181.4823, 820.6026, -99.37994, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 1183.8889, 817.9792, -99.3759, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 1184.9452, 815.8343, -98.78215, NULL, 0, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 1176.9271, 825.2448, -100.87818, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 1173.0416, 824.86456, -101.54798, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 1170.5712, 822.57294, -101.66822, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 1168.9132, 819.78644, -101.218636, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 1167.7188, 816.28125, -100.37794, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 1167.2361, 810.9844, -99.16798, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 1167.7848, 805.5608, -97.77418, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 1168.441, 801.6632, -96.66749, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 1169.9844, 797.6285, -95.110275, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 1172.8976, 794.0868, -93.13591, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 1173.6348, 793.4121, -92.697556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 12, 1174.3721, 792.7373, -92.447556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 13, 1175.1094, 792.0625, -91.697556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 14, 1175.8467, 791.3877, -91.447556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 15, 1176.584, 790.7129, -90.947556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 16, 1177.3213, 790.0381, -90.322556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 17, 1178.0586, 789.3633, -90.072556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 18, 1178.3055, 789.13715, -89.83769, NULL, 0, 0),
(@WAYPOINT_ID + 1, 19, 1183.5798, 786.4028, -87.569016, NULL, 0, 0),
(@WAYPOINT_ID + 1, 20, 1188.6979, 787.19794, -86.354904, NULL, 0, 0),
(@WAYPOINT_ID + 1, 21, 1195.8837, 790.03644, -84.26213, NULL, 0, 0),
(@WAYPOINT_ID + 1, 22, 1202.3663, 795.625, -83.31508, NULL, 0, 0),
(@WAYPOINT_ID + 1, 23, 1204.9115, 797.96875, -83.0901, NULL, 0, 0),
(@WAYPOINT_ID + 1, 24, 1207.1841, 800.2483, -82.8877, NULL, 0, 0),
(@WAYPOINT_ID + 1, 25, 1213.2205, 807.0643, -82.56556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 26, 1214.9288, 809.0347, -82.054695, NULL, 0, 0),
(@WAYPOINT_ID + 1, 27, 1218.9424, 813.49414, -81.7627, NULL, 0, 0),
(@WAYPOINT_ID + 1, 28, 1222.3923, 818.0903, -81.88807, NULL, 0, 0),
(@WAYPOINT_ID + 1, 29, 1224.2692, 823.4653, -81.66285, NULL, 0, 0),
(@WAYPOINT_ID + 1, 30, 1225.9774, 826.0799, -81.445564, NULL, 0, 0),
(@WAYPOINT_ID + 1, 31, 1228.3976, 828.6493, -81.2627, NULL, 0, 0),
(@WAYPOINT_ID + 1, 32, 1231.5834, 829.9375, -81.2627, NULL, 0, 0),
-- -- Path 3
(@WAYPOINT_ID + 2, 1, 1231.5834, 829.9375, -81.2627, 0.506145477294921875, 3000, 0),
(@WAYPOINT_ID + 2, 2, 1212.0139, 809.55554, -82.8877, 3.84004974365234375, 500, 0);

-- Arathi Miner (@CGUID+224)
SET @WAYPOINT_ID := ((@CGUID + 224) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+2;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 1183.1233, 822.8299, -99.30141, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1187.6035, 817.4174, -98.85347, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 1189.8086, 814.625, -99.177666, NULL, 0, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 1189.8086, 814.625, -99.177666, 2.216568231582641601, 1000, 0),
(@WAYPOINT_ID + 1, 2, 1180.0903, 828.88367, -100.88697, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 1176.9132, 829.73956, -101.87086, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 1172.8629, 828.5417, -102.33814, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 1167.8473, 825.5208, -102.281746, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 1163.5469, 821.96356, -101.50144, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 1159.5591, 817.2552, -100.444435, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 1156.2627, 813.4951, -99.80332, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 1152.9323, 810.5903, -99.55332, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 1147.4548, 808.7882, -99.79624, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 1141.7517, 806.38196, -99.84995, NULL, 0, 0),
-- -- Path 3
(@WAYPOINT_ID + 2, 1, 1141.7517, 806.38196, -99.84995, 0.506145477294921875, 3000, 0),
(@WAYPOINT_ID + 2, 2, 1182.7795, 828.3143, -100.581184, 4.636138439178466796, 500, 0);

-- Arathi Miner (@CGUID+219)
SET @WAYPOINT_ID := ((@CGUID + 219) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+2;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
(@WAYPOINT_ID + 0, 1, 1195.6979, 856.8368, -98.682175, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1193.9341, 852.82117, -98.682175, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 1191.606, 847.8993, -98.82182, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 1189.592, 841.23267, -99.741745, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 1187.3594, 837.88544, -100.37456, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 1185.8496, 836.5752, -100.807175, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 1185.0947, 835.9199, -101.057175, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 1184.1267, 835.0799, -101.12822, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 1181.2396, 832.57465, -101.4773, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 1180.6182, 831.791, -101.406746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 1179.1598, 829.9514, -101.34644, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 1179.1602, 829.9512, -101.531746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 1178.707, 829.0596, -101.281746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 1177.7205, 827.1215, -101.1377, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 1179.167, 821.2518, -99.89454, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 1178.6465, 822.917, -100.156746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 1179.6484, 822.10254, -100.031746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 1180.2783, 821.0825, -99.3563, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 1180.9325, 820.0231, -99.3759, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 1181.7715, 816.1465, -99.781746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 1182.6533, 815.4121, -99.18284, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 1183.0591, 815.65454, -99.134384, NULL, 0, 0),
-- -- Path 2
(@WAYPOINT_ID + 1, 1, 1183.0591, 815.65454, -99.134384, 2.216568231582641601, 1000, 0),
(@WAYPOINT_ID + 1, 2, 1176.8837, 825.0816, -100.84937, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 1177.4341, 829.30383, -101.75623, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 1178.4115, 832.80035, -102.18348, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 1181.5173, 835.5799, -101.82512, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 1185.401, 837.1285, -101.01811, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 1189.1788, 839.691, -99.90434, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 1192.033, 845.25, -98.969284, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 1194.9705, 849.65625, -98.682175, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 1196.1805, 856.4184, -98.682175, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 1196.9288, 863.4948, -98.92009, NULL, 0, 0),
(@WAYPOINT_ID + 1, 12, 1196.5677, 871.31946, -100.20993, NULL, 0, 0),
(@WAYPOINT_ID + 1, 13, 1195.276, 876.5226, -101.98813, NULL, 0, 0),
(@WAYPOINT_ID + 1, 14, 1194.3317, 881.78125, -103.36398, NULL, 0, 0),
(@WAYPOINT_ID + 1, 15, 1193.6163, 887.0833, -104.13132, NULL, 0, 0),
(@WAYPOINT_ID + 1, 16, 1193.7535, 890.2049, -104.368866, NULL, 0, 0),
(@WAYPOINT_ID + 1, 17, 1194.4375, 892.92883, -104.457855, NULL, 0, 0),
(@WAYPOINT_ID + 1, 18, 1196.2935, 895.51044, -104.258514, NULL, 0, 0),
(@WAYPOINT_ID + 1, 19, 1197.0684, 896.1426, -103.993866, NULL, 0, 0),
(@WAYPOINT_ID + 1, 20, 1198.6191, 897.40625, -103.618866, NULL, 0, 0),
(@WAYPOINT_ID + 1, 21, 1200.1699, 898.6699, -103.29617, NULL, 0, 0),
(@WAYPOINT_ID + 1, 22, 1203.2988, 901.166, -102.75918, NULL, 0, 0),
-- -- Path 3
(@WAYPOINT_ID + 2, 1, 1203.2988, 901.166, -102.75918, 0.506145477294921875, 3000, 0),
(@WAYPOINT_ID + 2, 2, 1197.3055, 864.316, -98.932175, 4.242938518524169921, 250, 0);

-- Defiler Combatant (@CGUID+152)
SET @WAYPOINT_ID := ((@CGUID + 152) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+0;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 679.4757, 676.5625, -14.697695, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 673.566, 672.5955, -14.456118, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 671.625, 670.6493, -14.3707905, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 670.3976, 668.24304, -13.940615, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 668.3993, 662.32465, -13.433236, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 668.6493, 657.4601, -12.956796, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 669.7083, 654.38196, -12.754769, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 671.2778, 651.7639, -12.450936, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 673.6441, 649.8924, -12.1316, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 675.8524, 648.99304, -11.709237, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 686.5573, 648.2518, -11.8818445, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 692.8368, 649.0035, -12.828256, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 686.5573, 648.2518, -11.8818445, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 677.8542, 648.8524, -11.50184, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 675.8524, 648.99304, -11.709237, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 671.2778, 651.7639, -12.450936, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 669.7083, 654.38196, -12.754769, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 668.6493, 657.4601, -12.956796, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 668.3993, 662.32465, -13.433236, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 670.3976, 668.24304, -13.940615, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 671.625, 670.6493, -14.3707905, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 673.566, 672.5955, -14.456118, NULL, 0, 0),
(@WAYPOINT_ID + 0, 23, 676.01044, 674.05035, -14.638979, NULL, 0, 0);

-- Defiler Combatant (@CGUID+14)
SET @WAYPOINT_ID := ((@CGUID + 14) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+0;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 661.67365, 667.5417, 7.8209686, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 663.79517, 666.92365, 7.8209686, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 670.1597, 665.309, 7.820969, 4.520402908325195312, 2000, 0);

-- Derek Darkmetal
SET @WAYPOINT_ID := ((@CGUID + 84) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+2;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 708.559, 676.041, -15.8257885, NULL, 0, 0),
(@WAYPOINT_ID + 1, 1, 708.7535, 680.67883, -15.962873, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 709.375, 681.7708, -15.8882885, 0.401425719261169433, 1, 0),
(@WAYPOINT_ID + 2, 1, 706.73267, 679.8924, -16.100447, 2.884756326675415039, 1, 0);

-- Arathor Watchman (@CGUID+146)
SET @WAYPOINT_ID := ((@CGUID + 146) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 1326.243, 1331.1216, 12.214721, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1323.5469, 1332.816, 12.214721, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 1321.4392, 1335.481, 12.214722, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 1319.5712, 1336.4341, 12.203757, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 1318.0798, 1336.4791, 11.677477, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 1314.6041, 1336.0469, 11.417847, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 1307.0416, 1335.2726, 11.417846, 4.607669353485107421, 1, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 1313.1163, 1336.0243, 11.417846, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 1318.1788, 1336.6666, 11.723722, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 1321.5712, 1337.1649, 12.214722, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 1322.9445, 1334.3351, 12.214722, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 1324.7274, 1332.3334, 12.214721, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 1327.6632, 1330.2048, 12.214723, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 1331.4132, 1329.5938, 12.214723, 4.857148170471191406, 1500, 0);

-- Arathor Watchman (@CGUID+16)
SET @WAYPOINT_ID := ((@CGUID + 16) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+0;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
((((@CGUID + 16) * 10) << 3) + 0, 1, 1363.8733, 1353.7639, -4.9591475, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 2, 1360.3368, 1357.0435, -6.4125166, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 3, 1356.0192, 1360.7466, -7.969157, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 4, 1349.6632, 1365.3854, -9.153361, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 5, 1341.5017, 1370.026, -9.8801, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 6, 1335.5226, 1372.5365, -9.787571, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 7, 1331.4479, 1374.6788, -9.702032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 8, 1328.191, 1376.4966, -9.702032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 9, 1323.9635, 1378.0295, -9.702032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 10, 1318.9567, 1379.0521, -9.952032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 11, 1314.7413, 1377.6337, -10.077032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 12, 1311.3264, 1376.0625, -9.998663, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 13, 1308.5052, 1374.2812, -9.952032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 14, 1305.3993, 1371.8125, -9.882086, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 15, 1301.9254, 1369.0712, -9.783453, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 16, 1297.0591, 1366.2969, -9.691166, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 17, 1301.9254, 1369.0712, -9.783453, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 18, 1305.3993, 1371.8125, -9.882086, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 19, 1308.5052, 1374.2812, -9.952032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 20, 1311.3264, 1376.0625, -9.998663, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 21, 1314.7413, 1377.6337, -10.077032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 22, 1318.9567, 1379.0521, -9.952032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 23, 1323.9635, 1378.0295, -9.702032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 24, 1328.191, 1376.4966, -9.702032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 25, 1331.4479, 1374.6788, -9.702032, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 26, 1335.5226, 1372.5365, -9.787571, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 27, 1341.5017, 1370.026, -9.8801, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 28, 1349.6632, 1365.3854, -9.153361, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 29, 1356.0192, 1360.7466, -7.969157, NULL, 0, 0),
((((@CGUID + 16) * 10) << 3) + 0, 30, 1360.3368, 1357.0435, -6.4125166, NULL, 0, 0);

-- Groundskeeper Olivia
SET @WAYPOINT_ID := ((@CGUID + 7) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+2;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- Path 1
((((@CGUID + 7) * 10) << 3) + 0, 1, 1333.7344, 1321.882, -8.739866, 5.009094715118408203, 1000, 0),
((((@CGUID + 7) * 10) << 3) + 0, 2, 1336.9341, 1316.3142, -9.289713, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 0, 3, 1338.856, 1315.6788, -9.317301, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 0, 4, 1341.2517, 1315.842, -9.229044, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 0, 5, 1345.1459, 1317.1805, -8.956095, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 0, 6, 1347.4028, 1320.0555, -8.736002, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 0, 7, 1348.8438, 1322.3473, -8.015421, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 0, 8, 1349.3906, 1325.5677, -7.324625, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 0, 10, 1349.7067, 1328.5591, -7.597086, NULL, 0, 0),
-- -- Path 2
((((@CGUID + 7) * 10) << 3) + 1, 1, 1349.7067, 1328.5591, -7.597086, 4.642575740814208984, 1000, 0),
((((@CGUID + 7) * 10) << 3) + 1, 2, 1354.4323, 1321.9358, -8.135416, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 3, 1357.9948, 1319.5712, -7.9332676, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 4, 1362.3872, 1316.9045, -7.6902256, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 5, 1365.6337, 1314.8611, -7.2958164, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 6, 1369.4497, 1313.092, -7.4354258, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 7, 1371.566, 1311.8959, -7.722535, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 8, 1373.3368, 1311.6146, -7.790162, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 9, 1375.5885, 1311.6598, -7.857667, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 1, 10, 1377.9358, 1312.1997, -7.3599863, NULL, 0, 0),
-- -- Path 3
((((@CGUID + 7) * 10) << 3) + 2, 1, 1366.3663, 1314.9445, -7.197916, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 2, 2, 1359.9584, 1315.3541, -7.822794, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 2, 3, 1350.8212, 1315.8976, -8.9192295, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 2, 4, 1344.7916, 1315.816, -9.244791, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 2, 5, 1339.7916, 1315.7673, -9.296061, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 2, 6, 1336.5504, 1316.1754, -9.32316, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 2, 7, 1334.5868, 1318.9132, -9.0861, NULL, 0, 0),
((((@CGUID + 7) * 10) << 3) + 2, 8, 1333.7344, 1321.882, -8.766886, 2.030910730361938476, 1000, 0);

-- lumberjack 1
SET @WAYPOINT_ID := ((@CGUID + 204) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 757.3975830078125, 1162.171875, 20.36017227172851562, 6.161012172698974609, 1000, 0),
(@WAYPOINT_ID + 0, 2, 763.60940, 1162.6997, 19.185547, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 768.91320, 1163.0938, 17.919909, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 773.53990, 1162.6198, 16.651964, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 780.72394, 1160.9202, 14.971056, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 786.81430, 1158.3073, 13.368517, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 792.07640, 1156.3004, 12.370470, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 796.70996, 1154.4209, 11.467760, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 801.67190, 1154.1736, 10.690050, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 806.19100, 1155.5330, 10.758654, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 810.42365, 1157.9254, 11.216784, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 813.33510, 1160.5642, 11.446154, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 815.10420, 1162.7795, 11.703234, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 815.94794, 1165.0591, 11.685045, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 815.08680, 1167.5747, 11.673909, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 812.89240, 1170.6632, 11.548909, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 810.76390, 1173.1250, 11.820969, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 809.62680, 1175.0139, 11.820969, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 808.92883, 1177.5538, 11.869650, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 808.85940, 1179.9062, 11.919118, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 808.67017, 1183.1892, 11.886209, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 808.11804, 1189.6077, 11.820969, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 808.11804, 1189.6077, 11.820969, 5.585053443908691406, 1, 0),
(@WAYPOINT_ID + 1, 2, 817.11804, 1161.6423, 11.936632, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 819.98090, 1157.6528, 12.288439, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 821.38196, 1154.5312, 12.427843, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 821.38196, 1152.1841, 11.845812, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 820.17480, 1150.5879, 11.578234, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 819.78820, 1150.0764, 11.346544, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 817.35940, 1148.5834, 11.095690, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 813.87500, 1148.1649, 10.398058, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 809.02430, 1148.3959, 10.198229, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 803.09375, 1149.1736, 10.717760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 12, 798.41600, 1150.9414, 11.717760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 13, 794.29865, 1153.0452, 12.283068, NULL, 0, 0),
(@WAYPOINT_ID + 1, 14, 790.55554, 1155.2795, 12.967272, NULL, 0, 0),
(@WAYPOINT_ID + 1, 15, 786.27606, 1158.0330, 13.725695, NULL, 0, 0),
(@WAYPOINT_ID + 1, 16, 786.27637, 1158.0332, 13.967760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 17, 785.34375, 1158.3945, 14.217760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 18, 783.47850, 1159.1172, 14.717760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 19, 782.63020, 1159.4462, 14.820543, NULL, 0, 0),
(@WAYPOINT_ID + 1, 20, 782.62990, 1159.4463, 14.592760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 21, 781.66895, 1159.7236, 14.967760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 22, 779.74710, 1160.2783, 15.342760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 23, 777.82520, 1160.8330, 15.592760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 24, 776.86426, 1161.1104, 15.967760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 25, 776.10420, 1161.3317, 16.085192, NULL, 0, 0),
(@WAYPOINT_ID + 1, 26, 770.10450, 1161.4316, 17.842760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 27, 757.39760, 1162.5000, 20.350830, 3.34941720962524414, 1, 0);

-- lumberjack 2
SET @WAYPOINT_ID := ((@CGUID + 209) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 904.35418701171875, 1182.953125, 3.927566051483154296, 2.914699792861938476, 1000, 0),
(@WAYPOINT_ID + 0, 2, 898.26910, 1182.4705, 6.0160184, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 894.47266, 1181.2090, 7.2055936, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 890.85767, 1181.6632, 8.2749290, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 887.24650, 1182.3420, 8.8231470, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 883.76740, 1183.5087, 9.3508570, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 880.16320, 1184.9149, 9.5843770, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 875.34375, 1186.5903, 9.7420920, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 870.68400, 1188.0504, 9.2020530, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 864.78125, 1189.4827, 8.8908010, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 860.43750, 1190.4618, 9.6863340, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 857.81080, 1190.9844, 10.066461, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 855.62150, 1191.5798, 10.027032, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 853.07294, 1192.7466, 9.8742000, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 850.10940, 1193.5764, 9.9905330, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 846.69965, 1194.5851, 10.115777, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 846.69920, 1194.5850, 10.316216, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 842.94100, 1195.4080, 10.293267, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 837.82810, 1196.1442, 10.341363, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 834.32465, 1196.6146, 10.759820, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 829.89410, 1196.9358, 11.304280, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 827.27080, 1197.5798, 11.441854, NULL, 0, 0),
(@WAYPOINT_ID + 0, 23, 825.77780, 1197.6406, 11.613729, NULL, 0, 0),
(@WAYPOINT_ID + 0, 24, 821.12500, 1196.4305, 11.951375, NULL, 0, 0),
(@WAYPOINT_ID + 0, 25, 818.02606, 1194.6024, 11.995651, NULL, 0, 0),
(@WAYPOINT_ID + 0, 26, 814.62150, 1190.9723, 11.954003, NULL, 0, 0),
(@WAYPOINT_ID + 0, 27, 813.22570, 1190.0868, 11.948299, NULL, 0, 0),
(@WAYPOINT_ID + 0, 28, 810.54517, 1190.8403, 11.924964, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 810.54517, 1190.8403, 11.924964, 5.585053443908691406, 1, 0),
(@WAYPOINT_ID + 1, 2, 817.30900, 1192.8160, 11.9687850, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 819.99304, 1195.8330, 11.8855790, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 823.78300, 1199.3611, 11.6324050, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 826.57810, 1200.3785, 11.3140460, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 831.10240, 1200.7952, 10.9239090, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 838.42535, 1200.7344, 10.5952425, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 842.16490, 1200.3854, 10.3479280, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 847.22220, 1199.1945, 9.81621600, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 853.81600, 1197.1754, 9.54570900, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 855.68555, 1196.4648, 9.31621600, NULL, 0, 0),
(@WAYPOINT_ID + 1, 12, 858.21704, 1195.5000, 9.14629500, NULL, 0, 0),
(@WAYPOINT_ID + 1, 13, 858.21680, 1195.5000, 9.31621600, NULL, 0, 0),
(@WAYPOINT_ID + 1, 14, 862.91406, 1193.7910, 9.06621600, NULL, 0, 0),
(@WAYPOINT_ID + 1, 15, 864.79297, 1193.1074, 8.81621600, NULL, 0, 0),
(@WAYPOINT_ID + 1, 16, 865.60590, 1192.8142, 8.75603600, NULL, 0, 0),
(@WAYPOINT_ID + 1, 17, 870.72570, 1190.3055, 8.93142300, NULL, 0, 0),
(@WAYPOINT_ID + 1, 18, 874.51044, 1188.2760, 9.14053000, NULL, 0, 0),
(@WAYPOINT_ID + 1, 19, 879.54170, 1186.2344, 9.25857200, NULL, 0, 0),
(@WAYPOINT_ID + 1, 20, 885.18230, 1184.0868, 8.80288300, NULL, 0, 0),
(@WAYPOINT_ID + 1, 21, 890.51390, 1182.8698, 8.10024600, NULL, 0, 0),
(@WAYPOINT_ID + 1, 22, 904.16700, 1182.9531, 3.92786800, 5.970508098602294921, 1, 0);

-- lumberjack 3
SET @WAYPOINT_ID := ((@CGUID + 205) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 814.2882080078125, 1096.765625, 10.53528881072998046, 1.326450228691101074, 1000, 0),
(@WAYPOINT_ID + 0, 2, 816.76390, 1103.9497, 11.596175, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 817.82810, 1106.5435, 12.693831, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 818.93230, 1110.2517, 13.963119, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 819.54785, 1113.1875, 14.296615, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 820.28990, 1116.9098, 14.549300, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 821.73090, 1122.4913, 14.443831, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 821.30554, 1128.2240, 12.163192, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 820.90970, 1131.8403, 11.538314, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 819.78820, 1135.9271, 10.516588, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 818.54865, 1139.9688, 10.094103, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 818.52080, 1144.5399, 10.668322, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 817.79517, 1149.6111, 11.359972, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 817.69446, 1154.2396, 11.824816, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 816.99133, 1159.2448, 11.906115, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 814.95140, 1164.3854, 11.646105, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 812.21180, 1169.9531, 11.548909, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 808.78644, 1173.4896, 11.820969, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 808.72490, 1173.6804, 11.820969, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 808.10240, 1175.6111, 11.820969, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 807.93750, 1176.5817, 11.860204, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 807.80554, 1177.7709, 11.958746, NULL, 0, 0),
(@WAYPOINT_ID + 0, 23, 806.81600, 1180.4392, 11.944935, NULL, 0, 0),
(@WAYPOINT_ID + 0, 24, 804.06946, 1183.7361, 11.951467, NULL, 0, 0),
(@WAYPOINT_ID + 0, 25, 802.97394, 1184.8455, 11.956316, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 802.97394, 1184.8455, 11.956316, 5.970508098602294921, 1, 0),
(@WAYPOINT_ID + 1, 2, 807.85420, 1175.5747, 11.8209690, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 809.12500, 1173.4010, 11.8209690, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 810.95830, 1171.2188, 11.8209690, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 812.53644, 1169.5399, 11.5489090, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 813.74133, 1165.9635, 11.5396595, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 814.00520, 1163.1823, 11.5712760, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 813.55206, 1154.9531, 11.0806750, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 813.35767, 1148.5382, 10.3807240, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 812.93750, 1141.3750, 10.2206900, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 813.04170, 1137.6805, 9.91246200, NULL, 0, 0),
(@WAYPOINT_ID + 1, 12, 813.62150, 1133.6476, 9.74705700, NULL, 0, 0),
(@WAYPOINT_ID + 1, 13, 813.99900, 1130.6709, 10.2966150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 14, 814.68054, 1127.7743, 11.0800620, NULL, 0, 0),
(@WAYPOINT_ID + 1, 15, 814.99023, 1126.8232, 11.6716150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 16, 815.57117, 1125.0416, 12.3871910, NULL, 0, 0),
(@WAYPOINT_ID + 1, 17, 815.57130, 1125.0420, 12.0466150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 18, 815.91700, 1124.1035, 12.9216150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 19, 816.26270, 1123.1650, 13.1716150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 20, 816.60840, 1122.2266, 13.5466150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 21, 816.71180, 1121.9497, 13.8431230, NULL, 0, 0),
(@WAYPOINT_ID + 1, 22, 817.82227, 1119.1631, 14.5466150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 23, 818.89580, 1116.0087, 14.7801350, NULL, 0, 0),
(@WAYPOINT_ID + 1, 24, 818.67190, 1112.9427, 14.3497150, NULL, 0, 0),
(@WAYPOINT_ID + 1, 25, 817.30383, 1107.4410, 12.8464190, NULL, 0, 0),
(@WAYPOINT_ID + 1, 26, 814.28820, 1096.7656, 10.5019870, 4.617629528045654296, 1, 0);

-- lumberjack 4
SET @WAYPOINT_ID := ((@CGUID + 207) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 825.779541015625, 1255.8836669921875, 22.23864173889160156, 2.914699792861938476, 1000, 0),
(@WAYPOINT_ID + 0, 2, 820.56250, 1253.2118, 22.741510, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 817.42190, 1250.6771, 22.510065, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 814.84030, 1247.6459, 22.467340, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 813.21010, 1243.2986, 21.401056, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 813.59720, 1238.7344, 19.852716, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 814.07640, 1234.1945, 18.955744, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 815.24304, 1228.7240, 17.935383, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 817.93400, 1222.2882, 14.859212, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 819.77606, 1218.1060, 13.147786, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 821.81430, 1213.1094, 11.934529, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 824.09894, 1208.4010, 11.673909, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 824.52780, 1205.6423, 11.407796, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 824.08510, 1202.4670, 11.471272, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 822.54517, 1198.9531, 11.780965, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 821.11633, 1195.6910, 11.798909, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 818.05900, 1190.7067, 11.952708, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 816.19100, 1188.0104, 11.904458, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 814.51044, 1186.5642, 11.880142, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 811.92883, 1185.3577, 11.820969, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 807.23440, 1185.7310, 11.880688, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 804.28300, 1186.1771, 11.921508, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 804.28300, 1186.1771, 11.921508, 5.970508098602294921, 1, 0),
(@WAYPOINT_ID + 1, 2, 819.90454, 1193.0139, 11.996414, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 822.26390, 1195.8330, 11.798909, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 825.00000, 1197.9160, 11.673909, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 825.22920, 1198.7535, 11.545857, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 825.96580, 1200.6133, 11.298909, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 826.05900, 1200.8490, 11.320027, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 826.64240, 1204.1476, 11.359090, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 826.43230, 1206.6997, 11.314534, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 825.08984, 1211.5137, 11.798909, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 824.85767, 1212.3507, 11.968465, NULL, 0, 0),
(@WAYPOINT_ID + 1, 12, 824.85740, 1212.3506, 11.798909, NULL, 0, 0),
(@WAYPOINT_ID + 1, 13, 824.50195, 1214.3193, 12.298909, NULL, 0, 0),
(@WAYPOINT_ID + 1, 14, 823.96875, 1217.2725, 13.423909, NULL, 0, 0),
(@WAYPOINT_ID + 1, 15, 823.90625, 1217.6077, 13.562703, NULL, 0, 0),
(@WAYPOINT_ID + 1, 16, 822.64060, 1222.0173, 14.755696, NULL, 0, 0),
(@WAYPOINT_ID + 1, 17, 821.30760, 1226.8369, 16.673908, NULL, 0, 0),
(@WAYPOINT_ID + 1, 18, 819.63020, 1232.4479, 18.505207, NULL, 0, 0),
(@WAYPOINT_ID + 1, 19, 818.15625, 1237.7986, 19.616755, NULL, 0, 0),
(@WAYPOINT_ID + 1, 20, 817.15970, 1242.3923, 20.581354, NULL, 0, 0),
(@WAYPOINT_ID + 1, 21, 817.34720, 1246.1354, 21.580378, NULL, 0, 0),
(@WAYPOINT_ID + 1, 22, 818.43750, 1249.5295, 22.212702, NULL, 0, 0),
(@WAYPOINT_ID + 1, 23, 820.62850, 1251.7291, 22.377863, NULL, 0, 0),
(@WAYPOINT_ID + 1, 24, 825.77954, 1255.8837, 22.169000, 0.499742180109024047, 1, 0);

-- lumberjack wanderer
SET @WAYPOINT_ID := ((@CGUID + 210) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 856.48090, 1229.4810, 14.3900420, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 857.34180, 1227.6758, 13.9702425, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 858.63380, 1224.9688, 13.5952425, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 858.67365, 1224.8854, 13.3668490, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 858.67380, 1224.8857, 13.5952425, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 859.46680, 1223.0498, 13.2202425, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 860.25977, 1221.2139, 12.9702425, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 860.60420, 1220.4166, 12.7002230, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 861.36456, 1215.1354, 11.9964880, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 859.28990, 1211.0104, 11.4966100, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 851.72740, 1204.9861, 9.79202000, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 847.78990, 1202.3403, 9.79787900, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 844.04865, 1198.8004, 10.1364070, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 838.91490, 1195.3785, 10.5601130, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 836.15625, 1193.8334, 11.0199520, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 863.21530, 1207.7517, 10.196927, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 865.19100, 1212.7709, 10.503690, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 866.67535, 1217.4166, 11.192437, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 866.73785, 1221.1337, 12.000665, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 865.20490, 1224.3438, 12.579007, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 860.36804, 1229.3802, 13.751737, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 854.49480, 1233.6702, 15.472480, 1.8916287, 1, 0);

-- blacksmith 1
SET @WAYPOINT_ID := ((@CGUID + 233) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 967.42364501953125, 996.73785400390625, -43.9448280334472656, 5.829399585723876953, 1000, 0),
(@WAYPOINT_ID + 0, 2, 972.2552, 995.43750, -44.371353, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 974.3698, 998.61804, -44.399430, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 974.4549, 1000.1684, -44.628548, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 974.7083, 1003.1945, -44.339120, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 976.2066, 1005.1927, -44.089120, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 974.00000, 1000.8090, -44.497078, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 970.75867, 997.15280, -44.493546, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 967.70800, 996.73785, -44.027725, 2.711585760116577148, 1, 0);

-- blacksmith 2
SET @WAYPOINT_ID := ((@CGUID + 229) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 988.95489501953125, 1005.00701904296875, -42.1504898071289062, 5.829399585723876953, 1000, 0),
(@WAYPOINT_ID + 0, 2, 993.61285, 1004.66140, -42.179028, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 995.52344, 1002.85455, -42.179028, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 995.81250, 1000.52780, -42.426790, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 995.12680, 1005.9514, -42.179028, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 992.38196, 1005.8177, -42.179028, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 988.95490, 1005.0070, -42.179030, 3.150818347930908203, 1, 0);

-- blacksmith stone carrier
SET @WAYPOINT_ID := ((@CGUID + 232) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 971.12847900390625, 976.25518798828125, -43.8743324279785156, 5.340707302093505859, 1000, 0),
(@WAYPOINT_ID + 0, 2, 975.20830, 970.99830, -44.298965, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 977.93054, 968.85940, -44.310684, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 980.48090, 967.64580, -44.676650, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 983.70830, 966.57294, -45.271420, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 983.70800, 966.57324, -44.986263, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 985.69434, 966.33300, -44.736263, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 986.68750, 966.21290, -44.486263, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 987.31250, 966.13544, -44.531185, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 991.44965, 966.54865, -43.586850, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 996.54340, 967.62680, -43.219130, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 999.69270, 969.21010, -43.496720, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 1002.9462, 970.83160, -43.768970, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 1006.0521, 973.06600, -43.890675, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 1008.3768, 975.68230, -43.877980, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 1010.1250, 979.04690, -43.887135, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 1011.0000, 987.86115, -43.916065, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 1010.8698, 992.03300, -44.185230, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 1009.9462, 994.50696, -44.191334, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 1008.6162, 997.19630, -44.435230, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 1008.2379, 997.95830, -44.361378, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 1006.3750, 1000.4583, -43.751490, NULL, 0, 0),
(@WAYPOINT_ID + 0, 23, 1003.4427, 1002.5417, -42.423004, NULL, 0, 0),
(@WAYPOINT_ID + 0, 24, 999.16670, 1005.2535, -42.599384, NULL, 0, 0),
(@WAYPOINT_ID + 0, 25, 994.89060, 1007.7465, -42.179028, NULL, 0, 0),
(@WAYPOINT_ID + 0, 26, 991.21010, 1009.6059, -42.179028, NULL, 0, 0),
(@WAYPOINT_ID + 0, 27, 987.20490, 1011.2656, -42.658790, NULL, 0, 0),
(@WAYPOINT_ID + 0, 28, 985.44100, 1011.3264, -42.672867, NULL, 0, 0),
(@WAYPOINT_ID + 0, 29, 982.34204, 1009.6250, -42.658398, NULL, 0, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 984.96356, 1012.9236, -42.639954, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 982.86285, 1014.7570, -42.382156, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 978.98615, 1017.9688, -44.173225, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 974.40970, 1020.5521, -44.693733, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 970.86456, 1019.9774, -45.456795, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 968.49830, 1019.3299, -45.332040, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 966.33856, 1018.0625, -45.338310, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 964.56600, 1015.5052, -45.591484, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 963.10940, 1011.6476, -45.570244, NULL, 0, 0),
(@WAYPOINT_ID + 1, 10, 961.63196, 1006.4132, -45.967705, NULL, 0, 0),
(@WAYPOINT_ID + 1, 11, 958.08680, 999.61804, -47.041462, NULL, 0, 0),
(@WAYPOINT_ID + 1, 12, 956.02780, 996.21010, -47.037556, NULL, 0, 0),
(@WAYPOINT_ID + 1, 13, 954.94794, 992.51390, -47.363970, NULL, 0, 0),
(@WAYPOINT_ID + 1, 14, 954.96180, 990.39240, -46.776447, NULL, 0, 0),
(@WAYPOINT_ID + 1, 15, 957.01044, 987.75350, -45.411457, NULL, 0, 0),
(@WAYPOINT_ID + 1, 16, 957.01074, 987.75390, -45.590656, NULL, 0, 0),
(@WAYPOINT_ID + 1, 17, 957.99510, 987.57910, -45.215656, NULL, 0, 0),
(@WAYPOINT_ID + 1, 18, 958.97950, 987.40430, -44.715656, NULL, 0, 0),
(@WAYPOINT_ID + 1, 19, 959.79340, 987.25867, -44.386555, NULL, 0, 0),
(@WAYPOINT_ID + 1, 20, 960.79297, 987.27440, -44.215656, NULL, 0, 0),
(@WAYPOINT_ID + 1, 21, 962.79297, 987.30566, -43.965656, NULL, 0, 0),
(@WAYPOINT_ID + 1, 22, 963.19100, 987.31250, -44.110188, NULL, 0, 0),
(@WAYPOINT_ID + 1, 23, 966.20490, 987.55383, -43.965656, NULL, 0, 0),
(@WAYPOINT_ID + 1, 24, 971.07640, 986.16320, -44.103043, NULL, 0, 0),
(@WAYPOINT_ID + 1, 25, 972.71180, 984.27080, -44.174330, NULL, 0, 0),
(@WAYPOINT_ID + 1, 26, 973.83160, 981.18400, -44.183730, NULL, 0, 0),
(@WAYPOINT_ID + 1, 27, 974.39930, 978.69965, -44.251846, NULL, 0, 0),
(@WAYPOINT_ID + 1, 28, 971.12850, 976.04200, -43.859390, 2.090637445449829101, 1, 0);

-- Defiler Bat Rider
SET @WAYPOINT_ID := ((@CGUID + 58) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+0;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 629.96870, 376.45140, 178.24315, NULL, 0, 1),
(@WAYPOINT_ID + 0, 2, 635.94270, 390.70140, 183.16116, NULL, 0, 1),
(@WAYPOINT_ID + 0, 3, 641.91670, 404.95140, 188.07918, NULL, 0, 1),
(@WAYPOINT_ID + 0, 4, 637.18750, 570.82640, 188.07918, NULL, 0, 1),
(@WAYPOINT_ID + 0, 5, 664.32294, 666.79170, 188.07918, NULL, 0, 1),
(@WAYPOINT_ID + 0, 6, 747.86115, 754.01910, 188.07918, NULL, 0, 1),
(@WAYPOINT_ID + 0, 7, 772.32810, 794.37850, 153.96823, NULL, 0, 1),
(@WAYPOINT_ID + 0, 8, 821.42365, 961.00520, 86.460680, NULL, 0, 1),
(@WAYPOINT_ID + 0, 9, 854.28820, 1031.4028, 86.460680, NULL, 0, 1),
(@WAYPOINT_ID + 0, 10, 894.32640, 1095.7466, 86.460680, NULL, 0, 1),
(@WAYPOINT_ID + 0, 11, 973.75000, 1197.5052, 86.460680, NULL, 0, 1),
(@WAYPOINT_ID + 0, 12, 1048.9098, 1304.7448, 86.460680, NULL, 0, 1),
(@WAYPOINT_ID + 0, 13, 1105.8663, 1379.1945, 134.64104, NULL, 0, 1),
(@WAYPOINT_ID + 0, 14, 1198.5817, 1537.4548, 221.42233, NULL, 0, 1),
(@WAYPOINT_ID + 0, 15, 1349.2379, 1750.9497, 328.39390, NULL, 0, 1);

-- Arathor Gryphon Rider
SET @WAYPOINT_ID := ((@CGUID + 51) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+0;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 1394.0209, 1388.9167, 153.32262, NULL, 0, 1),
(@WAYPOINT_ID + 0, 2, 1386.4341, 1381.7153, 154.89734, NULL, 0, 1),
(@WAYPOINT_ID + 0, 3, 1378.8473, 1374.5139, 156.47206, NULL, 0, 1),
(@WAYPOINT_ID + 0, 4, 1234.1875, 1240.4185, 156.47206, NULL, 0, 1),
(@WAYPOINT_ID + 0, 5, 1094.5555, 1138.9271, 92.392740, NULL, 0, 1),
(@WAYPOINT_ID + 0, 6, 1001.7864, 1033.8993, 92.392740, NULL, 0, 1),
(@WAYPOINT_ID + 0, 7, 984.01215, 991.08680, 92.392740, NULL, 0, 1),
(@WAYPOINT_ID + 0, 8, 975.03125, 916.90625, 92.392740, NULL, 0, 1),
(@WAYPOINT_ID + 0, 9, 962.58510, 842.50180, 92.392740, NULL, 0, 1),
(@WAYPOINT_ID + 0, 10, 954.42017, 765.47570, 92.392740, NULL, 0, 1),
(@WAYPOINT_ID + 0, 11, 949.10240, 676.44617, 143.17484, NULL, 0, 1),
(@WAYPOINT_ID + 0, 12, 962.75000, 423.92014, 219.66528, NULL, 0, 1),
(@WAYPOINT_ID + 0, 13, 993.89930, 76.503470, 219.66528, NULL, 0, 1);

-- Radulf Leder
SET @WAYPOINT_ID := ((@CGUID + 38) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+0;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 1392.1213, 1345.5967, 0.21549422, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 1389.2448, 1344.75, -0.23260853, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 1386.3682, 1343.9033, -0.68071127, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 1385.4092, 1343.6211, -0.93071127, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 1385.0764, 1343.5226, -0.8739486, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 1383.3301, 1342.5479, -1.3057113, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 1381.584, 1341.5732, -1.6807113, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 1381.3038, 1341.4166, -1.760179, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 1377.7865, 1338.7291, -2.676927, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 1374.0416, 1334.5712, -3.772142, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 1371.4341, 1331.8993, -4.5526133, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 1367.3524, 1327.6406, -5.8033457, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 1363.4062, 1324.2899, -7.010416, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 1359.8524, 1321.842, -7.5854893, NULL, 0, 0),
(@WAYPOINT_ID + 0, 15, 1355.7916, 1319.158, -8.197672, NULL, 0, 0),
(@WAYPOINT_ID + 0, 16, 1350.9497, 1316.6702, -8.767374, NULL, 0, 0),
(@WAYPOINT_ID + 0, 17, 1345.941, 1314.1041, -9.379801, NULL, 0, 0),
(@WAYPOINT_ID + 0, 18, 1332.7899, 1308.2778, -10.540589, NULL, 0, 0),
(@WAYPOINT_ID + 0, 19, 1323.4462, 1305.3247, -11.040589, NULL, 0, 0),
(@WAYPOINT_ID + 0, 20, 1319.1423, 1305.5365, -11.30597, NULL, 0, 0),
(@WAYPOINT_ID + 0, 21, 1316.0851, 1306.4375, -11.547914, NULL, 0, 0),
(@WAYPOINT_ID + 0, 22, 1314.0677, 1307.5104, -11.665589, NULL, 0, 0),
(@WAYPOINT_ID + 0, 23, 1309.5035, 1310.7031, -11.712586, 0.837758064270019531, 1, 0);

-- The Black Bride
SET @WAYPOINT_ID := ((@CGUID + 24) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+0;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@WAYPOINT_ID + 0, 1, 656.09375, 636.46265, -9.399595, NULL, 0, 0),
(@WAYPOINT_ID + 0, 2, 656.09375, 636.4618, -9.585997, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 656.09375, 636.46094, -9.772398, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 656.96875, 638.2578, -10.272398, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 657.2518, 638.8351, -10.535215, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 657.92017, 640.8264, -10.932798, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 660.56946, 648.6719, -12.425474, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 663.0243, 655.53644, -13.124327, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 667.84894, 667.0052, -13.949526, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 671.3143, 674.7656, -14.572695, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 674.30554, 681.6007, -14.822695, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 674.6823, 685.2049, -15.096987, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 673.88544, 687.2778, -15.126406, NULL, 0, 0),
(@WAYPOINT_ID + 0, 14, 671.5382, 691.3472, -14.969912, 3.612831592559814453, 1, 0);

-- Dominic Masonwrite
SET @WAYPOINT_ID := ((@CGUID + 140) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WAYPOINT_ID+0 AND @WAYPOINT_ID+1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
-- -- path 1
(@WAYPOINT_ID + 0, 1, 684.045166015625, 675.263916015625, -14.6660480499267578, 1.431169986724853515, 1000, 0),
(@WAYPOINT_ID + 0, 2, 683.56946, 681.07990, -15.072695, NULL, 0, 0),
(@WAYPOINT_ID + 0, 3, 681.10070, 682.70830, -15.185122, NULL, 0, 0),
(@WAYPOINT_ID + 0, 4, 677.38544, 684.03644, -15.193178, NULL, 0, 0),
(@WAYPOINT_ID + 0, 5, 673.01390, 684.93750, -14.901796, NULL, 0, 0),
(@WAYPOINT_ID + 0, 6, 668.88196, 686.10070, -14.651186, NULL, 0, 0),
(@WAYPOINT_ID + 0, 7, 665.32294, 687.55035, -14.100773, NULL, 0, 0),
(@WAYPOINT_ID + 0, 8, 662.53990, 690.65454, -14.015690, NULL, 0, 0),
(@WAYPOINT_ID + 0, 9, 661.71180, 694.51560, -13.638004, NULL, 0, 0),
(@WAYPOINT_ID + 0, 10, 661.72220, 699.52260, -13.538639, NULL, 0, 0),
(@WAYPOINT_ID + 0, 11, 663.10070, 703.08330, -13.669305, NULL, 0, 0),
(@WAYPOINT_ID + 0, 12, 665.31600, 706.72570, -13.534661, NULL, 0, 0),
(@WAYPOINT_ID + 0, 13, 667.43750, 709.48615, -13.347998, 2.042035102844238281, 1, 0),
-- -- path 2
(@WAYPOINT_ID + 1, 1, 666.94617, 704.70830, -13.737280, NULL, 0, 0),
(@WAYPOINT_ID + 1, 2, 665.11804, 701.34720, -13.938592, NULL, 0, 0),
(@WAYPOINT_ID + 1, 3, 663.72920, 696.17365, -14.034611, NULL, 0, 0),
(@WAYPOINT_ID + 1, 4, 663.91320, 691.64240, -14.134220, NULL, 0, 0),
(@WAYPOINT_ID + 1, 5, 665.21530, 686.40280, -14.101261, NULL, 0, 0),
(@WAYPOINT_ID + 1, 6, 668.96875, 681.58680, -14.139223, NULL, 0, 0),
(@WAYPOINT_ID + 1, 7, 672.43580, 679.47050, -14.551455, NULL, 0, 0),
(@WAYPOINT_ID + 1, 8, 678.19100, 679.64580, -15.018129, NULL, 0, 0),
(@WAYPOINT_ID + 1, 9, 684.04517, 676.04100, -14.635073, 4.539567470550537109, 1, 0);

-- smart scripts

-- The Black Bride
SET @ENTRY := 150501;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 24) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', ((((@CGUID + 24) * 10) << 3) + 0), ', walk, do not repeat, Passive'));

-- Radulf Leder
SET @ENTRY := 150505;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 38) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', ((((@CGUID + 38) * 10) << 3) + 0), ', walk, do not repeat, Passive'));

-- Bat/Gryphon Leaders
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid` IN (@CGUID+51, @CGUID+65);

-- Dominic Masonwrite
SET @DOMINIC_GUID := -(@CGUID+140);
SET @ENTRY := 150622;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @DOMINIC_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (15062200, 15062201);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@DOMINIC_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY * 100 + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ENTRY * 100 + 1), ' (update always)')),
(@DOMINIC_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 140) * 10) << 3) + 0, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 140) * 10) << 3) + 0), ' ended - Self: Start timed action list id #', (@ENTRY * 100), ' (update always) // -inline')),
(@DOMINIC_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 140) * 10) << 3) + 1, 0, 0, 80, @ENTRY * 100 + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 140) * 10) << 3) + 1), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 1), ' (update always) // -inline')),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 122236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 122236 on Self'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 28, 122236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Remove aura due to spell 122236'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 140) * 10) << 3) + 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 140) * 10) << 3) + 1), ', walk, do not repeat, Passive')),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 122236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 122236 on Self'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 28, 122236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Remove aura due to spell 122236'),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 140) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 140) * 10) << 3) + 0), ', walk, do not repeat, Passive'));

-- Kevin Young
SET @ENTRY := 149755;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+27);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (14975500, 14975501);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+27), 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ENTRY * 100), ' (update always)')),
(-(@CGUID+27), 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, ((@CGUID + 27) * 10) << 3, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (((@CGUID + 27) * 10) << 3), ' ended - Self: Start timed action list id #', (@ENTRY * 100), ' (update always) // -inline')),
(-(@CGUID+27), 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 27) * 10) << 3) + 1, 0, 0, 80, @ENTRY * 100 + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 27) * 10) << 3) + 1), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 1), ' (update always) // -inline')),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 470, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 470'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 27) * 10) << 3) + 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 27) * 10) << 3) + 1), ', walk, do not repeat, Passive')),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 261985, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 261985 on Self'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 10000, 20000, 0, 0, 53, 0, ((@CGUID + 27) * 10) << 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 10 - 20 seconds - Self: Start path #', (((@CGUID + 27) * 10) << 3), ', walk, do not repeat, Passive'));

-- Defiler Combatant
SET @ENTRY := 150429;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+14);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ENTRY * 100);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+14), 0, 0, 0, 60, 0, 100, 1, 60000, 60000, 0, 0, 53, 0, (((@CGUID + 14) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('Time = 60 seconds - Self: Start path #', ((((@CGUID + 14) * 10) << 3) + 0), ', walk, do not repeat, Passive')),
(-(@CGUID+14), 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 14) * 10) << 3) + 0, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 14) * 10) << 3) + 0), ' ended - Self: Start timed action list id #', (@ENTRY * 100), ' (update always) // -inline')),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 53, 0, (((@CGUID + 14) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 10 seconds - Self: Start path #', ((((@CGUID + 14) * 10) << 3) + 0), ', walk, do not repeat, Passive'));

-- Defiler Combatant
SET @ENTRY := 150429;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+99);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ENTRY * 100 + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+99), 0, 0, 0, 60, 0, 100, 0, 10000, 10000, 10000, 10000, 80, @ENTRY * 100 + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('Every 10 seconds - Self: Start timed action list id #', (@ENTRY * 100 + 1), ' (update always) // -inline')),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 282578, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 282578'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 291606, 0, 0, 0, 0, 0, 9, 149760, 0, 20, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 291606 on Creature Spell Bunny (149760) in 0 - 20 yards'),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 282578, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 282578 on Self');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (291606));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 291606, 0, 0, 31, 0, 3, 149760, 0, 0, 'Potential target of the spell is creature, entry is Spell Bunny (149760)');

-- Arathor Watchman Drink
SET @ENTRY := 150403;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+62);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ENTRY * 100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+62), 0, 0, 1, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 128, 2358, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Plays Anim with ID 2358'),
(-(@CGUID+62), 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('Every 5 - 15 seconds - Self: Start timed action list id #', (@ENTRY * 100), ' (update always) // -inline')),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Plays Anim with ID 0');

-- Arathor Watchman Drink
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN(-(@CGUID+71), -(@CGUID+132), -(@CGUID+148), -(@CGUID+163));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+71), 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Plays Anim with ID 17347'),
(-(@CGUID+132), 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Plays Anim with ID 17347'),
(-(@CGUID+148), 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Plays Anim with ID 17347'),
(-(@CGUID+163), 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Plays Anim with ID 17347');

-- Arathor Watchman Talk
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN(-(@CGUID+80), -(@CGUID+82));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+80), 0, 0, 0, 60, 0, 100, 0, 10000, 15000, 10000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 15 seconds - Self: Play emote 1'),
(-(@CGUID+82), 0, 0, 0, 60, 0, 100, 0, 10000, 15000, 10000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 15 seconds - Self: Play emote 1');

-- Arathor Watchman Patrol
SET @PATROL_GUID := -(@CGUID+146);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @PATROL_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ENTRY * 100 + 1, @ENTRY * 100 + 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@PATROL_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 15040301, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (15040301), ' (update always) // -inline')),
(@PATROL_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 184) * 10) << 3) + 0, 0, 0, 80, @ENTRY * 100 + 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 184) * 10) << 3) + 0), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 2), ' (update always) // -inline')),
(@PATROL_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 184) * 10) << 3) + 1, 0, 0, 80, @ENTRY * 100 + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 184) * 10) << 3) + 1), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 1), ' (update always)')),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 271087, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 271087 on Self'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 28, 271087, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Remove aura due to spell 271087'),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 146) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 146) * 10) << 3) + 0), ', walk, do not repeat, Passive')),
(@ENTRY * 100 + 2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 271087, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 271087 on Self'),
(@ENTRY * 100 + 2, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 271087, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 271087'),
(@ENTRY * 100 + 2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 146) * 10) << 3) + 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 146) * 10) << 3) + 1), ', walk, do not repeat, Passive'));

-- Derek Darkmetal
SET @ENTRY := 149718;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ENTRY * 100, @ENTRY * 100 + 1, @ENTRY * 100 + 2, @ENTRY * 100 + 3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ENTRY * 100), ' (update always) // -inline')),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 613, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 613'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, (((@CGUID + 84) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', ((((@CGUID + 84) * 10) << 3) + 0), ', walk, do not repeat, Passive')),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 84) * 10) << 3) + 0, 0, 0, 80, @ENTRY * 100 + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 84) * 10) << 3) + 0), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 1), ' (update always) // -inline')),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 10825, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 0, 10825, 0'),
(@ENTRY * 100 + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 84) * 10) << 3) + 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 84) * 10) << 3) + 1), ', walk, do not repeat, Passive')),
(@ENTRY, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 84) * 10) << 3) + 1, 0, 0, 80, @ENTRY * 100 + 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 84) * 10) << 3) + 1), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 2), ' (update always) // -inline')),
(@ENTRY * 100 + 2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 148, 0, 0, 0, 0, 0, 0, 9, 149760, 0, 20, 0, 0, 0, 0, 'After 0 seconds - Self: Add Creature 149760 in 0 - 20 yards to storedTarget[0]'),
(@ENTRY * 100 + 2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 86, 0, 0, 12, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - storedTarget[0]: Cast spell 0 at storedTarget[0]'),
(@ENTRY * 100 + 2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 17343, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 17343'),
(@ENTRY * 100 + 2, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - storedTarget[0]: Despawn instantly'),
(@ENTRY * 100 + 2, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 84) * 10) << 3) + 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 84) * 10) << 3) + 2), ', walk, do not repeat, Passive')),
(@ENTRY, 0, 3, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 84) * 10) << 3) + 2, 0, 0, 80, @ENTRY * 100 + 3, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 84) * 10) << 3) + 2), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 3), ' (update always) // -inline')),
(@ENTRY * 100 + 3, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Take off all equipped items'),
(@ENTRY * 100 + 3, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 613, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Set emote state to 613'),
(@ENTRY * 100 + 3, 9, 2, 0, 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0'),
(@ENTRY * 100 + 3, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, (((@CGUID + 84) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', ((((@CGUID + 84) * 10) << 3) + 0), ', walk, do not repeat, Passive'));

-- Groundskeeper Olivia
SET @ENTRY := 150655;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (15065500, 15065501);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ENTRY * 100), ' (update always) // -inline')),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 17436, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 17436'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Plays Anim with ID 0'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, (((@CGUID + 7) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', ((((@CGUID + 7) * 10) << 3) + 0), ', walk, do not repeat, Passive')),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 7) * 10) << 3) + 0, 0, 0, 80, @ENTRY * 100 + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 7) * 10) << 3) + 0), ' ended - Self: Start timed action list id #', (@ENTRY * 100 + 1), ' (update always) // -inline')),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 4760, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Plays Anim with ID 0'),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, (((@CGUID + 7) * 10) << 3) + 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', ((((@CGUID + 7) * 10) << 3) + 1), ', walk, do not repeat, Passive')),
(@ENTRY, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 7) * 10) << 3) + 1, 0, 0, 80, @ENTRY * 100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 7) * 10) << 3) + 1), ' ended - Self: Start timed action list id #', (@ENTRY * 100), ' (update always)'));

-- ---------------------------------------------------------------
-- Horde Lumber Mill
-- ---------------------------------------------------------------

-- Forsaken Lumberjack Carrier 1 Horde
SET @ENTRY := 15089;
SET @LUMBERJACK_GUID := -(@CGUID+204);
SET @LUMBERJACK_PATH1 := (((@CGUID + 204) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 204) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 0;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Forsaken Lumberjack Carrier 2 Horde
SET @ENTRY := 15089;
SET @LUMBERJACK_GUID := -(@CGUID+209);
SET @LUMBERJACK_PATH1 := (((@CGUID + 209) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 209) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 1;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Forsaken Lumberjack Carrier 3 Horde
SET @ENTRY := 15089;
SET @LUMBERJACK_GUID := -(@CGUID+205);
SET @LUMBERJACK_PATH1 := (((@CGUID + 205) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 205) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 2;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Forsaken Lumberjack Carrier 4 Horde
SET @ENTRY := 15089;
SET @LUMBERJACK_GUID := -(@CGUID+207);
SET @LUMBERJACK_PATH1 := (((@CGUID + 207) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 207) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 3;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Forsaken Lumberjack Wanderer Horde
SET @ENTRY := 15089;
SET @LUMBERJACK_GUID := -(@CGUID+210);
SET @ACTIONLIST_START := @ENTRY * 100 + 8;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Play emote 1'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 53, 0, (((@CGUID + 210) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 3.5 seconds - Self: Start path #', ((((@CGUID + 210) * 10) << 3) + 0), ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 210) * 10) << 3) + 0, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 210) * 10) << 3) + 0), ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 210) * 10) << 3) + 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 210) * 10) << 3) + 1), ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 210) * 10) << 3) + 1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 210) * 10) << 3) + 1), ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Forsaken Lumberjack Passive Horde
SET @LUMBERJACK_GUID := -(@CGUID+203);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Plays Anim with ID 17347');

-- Forsaken Lumberjack Passive Horde
SET @LUMBERJACK_GUID := -(@CGUID+206);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Plays Anim with ID 17347');

-- ---------------------------------------------------------------
-- Alliance Lumber Mill
-- ---------------------------------------------------------------

-- Arathi Lumberjack Carrier 1 Alliance
SET @ENTRY := 15062;
SET @LUMBERJACK_GUID := -(@CGUID+267);
SET @LUMBERJACK_PATH1 := (((@CGUID + 204) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 204) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 0;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Arathi Lumberjack Carrier 2 Alliance
SET @ENTRY := 15062;
SET @LUMBERJACK_GUID := -(@CGUID+264);
SET @LUMBERJACK_PATH1 := (((@CGUID + 209) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 209) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 1;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Arathi Lumberjack Carrier 3 Alliance
SET @ENTRY := 15062;
SET @LUMBERJACK_GUID := -(@CGUID+270);
SET @LUMBERJACK_PATH1 := (((@CGUID + 205) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 205) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 2;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Arathi Lumberjack Carrier 4 Alliance
SET @ENTRY := 15062;
SET @LUMBERJACK_GUID := -(@CGUID+266);
SET @LUMBERJACK_PATH1 := (((@CGUID + 207) * 10) << 3) + 0;
SET @LUMBERJACK_PATH2 := (((@CGUID + 207) * 10) << 3) + 1;
SET @LUMBERJACK_ID := 3;
SET @ACTIONLIST_START := @ENTRY * 100 + @LUMBERJACK_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 109579, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Equip items 109579, 0, 0'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 290604 on Self'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 290604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell 290604'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Take off all equipped items'),
(@ACTIONLIST_START, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244453 on Self'),
(@ACTIONLIST_START, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @LUMBERJACK_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', @LUMBERJACK_PATH1, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH1, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 244453, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 244453'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set stand state to KNEEL'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Set stand state to STAND'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 707, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 707'),
(@ACTIONLIST_START + 1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @LUMBERJACK_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', @LUMBERJACK_PATH2, ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @LUMBERJACK_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', @LUMBERJACK_PATH2, ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Arathi Lumberjack Wanderer Alliance
SET @ENTRY := 15062;
SET @LUMBERJACK_GUID := -(@CGUID+273);
SET @ACTIONLIST_START := @ENTRY * 100 + 8;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Play emote 1'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 53, 0, (((@CGUID + 210) * 10) << 3) + 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 3.5 seconds - Self: Start path #', ((((@CGUID + 210) * 10) << 3) + 0), ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 210) * 10) << 3) + 0, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 210) * 10) << 3) + 0), ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, (((@CGUID + 210) * 10) << 3) + 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', ((((@CGUID + 210) * 10) << 3) + 1), ', walk, do not repeat, Passive')),
(@LUMBERJACK_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, (((@CGUID + 210) * 10) << 3) + 1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', ((((@CGUID + 210) * 10) << 3) + 1), ' ended - Self: Start timed action list id #', @ACTIONLIST_START, ' (update always)'));

-- Arathi Lumberjack Passive Alliance
SET @LUMBERJACK_GUID := -(@CGUID+268);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Plays Anim with ID 17347');

-- Arathi Lumberjack Passive Alliance
SET @LUMBERJACK_GUID := -(@CGUID+274);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @LUMBERJACK_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LUMBERJACK_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 128, 17347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Plays Anim with ID 17347');

-- ---------------------------------------------------------------
-- Horde Blacksmith
-- ---------------------------------------------------------------

-- Forsaken Blacksmith Sitting
SET @ENTRY := 15064;
SET @BLACKSMITH_GUID := -(@CGUID+230);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 128, 5182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Plays Anim with ID 5182');

-- Forsaken Blacksmith Talking
SET @BLACKSMITH_GUID := -(@CGUID+225);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 60, 0, 100, 0, 10000, 15000, 10000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 15 seconds - Self: Play emote 1');

-- Forsaken Blacksmith Talking
SET @BLACKSMITH_GUID := -(@CGUID+226);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 60, 0, 100, 0, 10000, 15000, 10000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 15 seconds - Self: Play emote 1');

-- Forsaken Blacksmith Working 1
SET @BLACKSMITH_GUID := -(@CGUID+233);
SET @BLACKSMITH_PATH1 := (((@CGUID + 233) * 10) << 3) + 0;
SET @BLACKSMITH_PATH2 := (((@CGUID + 233) * 10) << 3) + 1;
SET @BLACKSMITH_ID := 0;
SET @ACTIONLIST_START := @ENTRY * 100 + @BLACKSMITH_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 261985, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 261985 on Self'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 10000, 20000, 0, 0, 53, 0, @BLACKSMITH_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 10 - 20 seconds - Self: Start path #', (@BLACKSMITH_PATH1), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 124, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Force load EquipmentId 0'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH2), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Blacksmith Working 2
SET @BLACKSMITH_GUID := -(@CGUID+229);
SET @BLACKSMITH_PATH1 := (((@CGUID + 229) * 10) << 3) + 0;
SET @BLACKSMITH_PATH2 := (((@CGUID + 229) * 10) << 3) + 1;
SET @BLACKSMITH_ID := 1;
SET @ACTIONLIST_START := @ENTRY * 100 + @BLACKSMITH_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 261985, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 261985 on Self'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 10000, 20000, 0, 0, 53, 0, @BLACKSMITH_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 10 - 20 seconds - Self: Start path #', (@BLACKSMITH_PATH1), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH2), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Blacksmith Carrier
SET @BLACKSMITH_GUID := -(@CGUID+232);
SET @BLACKSMITH_PATH1 := (((@CGUID + 232) * 10) << 3) + 0;
SET @BLACKSMITH_PATH2 := (((@CGUID + 232) * 10) << 3) + 1;
SET @ACTIONLIST_START := @ENTRY * 100 + 4;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` =  @BLACKSMITH_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 282906, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 282906 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH1), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 282906, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 282906'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH2), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- ---------------------------------------------------------------
-- Alliance Blacksmith
-- ---------------------------------------------------------------

-- Arathi Blacksmith Sitting
SET @ENTRY := 15063;
SET @BLACKSMITH_GUID := -(@CGUID+242);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 128, 5182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Plays Anim with ID 5182');

-- Arathi Blacksmith Talking
SET @BLACKSMITH_GUID := -(@CGUID+239);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 60, 0, 100, 0, 10000, 15000, 10000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 15 seconds - Self: Play emote 1');

-- Arathi Blacksmith Talking
SET @BLACKSMITH_GUID := -(@CGUID+240);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 60, 0, 100, 0, 10000, 15000, 10000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 15 seconds - Self: Play emote 1');

-- Arathi Blacksmith Working 1
SET @BLACKSMITH_GUID := -(@CGUID+236);
SET @BLACKSMITH_PATH1 := (((@CGUID + 233) * 10) << 3) + 0;
SET @BLACKSMITH_PATH2 := (((@CGUID + 233) * 10) << 3) + 1;
SET @BLACKSMITH_ID := 0;
SET @ACTIONLIST_START := @ENTRY * 100 + @BLACKSMITH_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 261985, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 261985 on Self'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 10000, 20000, 0, 0, 53, 0, @BLACKSMITH_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 10 - 20 seconds - Self: Start path #', (@BLACKSMITH_PATH1), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 124, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Force load EquipmentId 0'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH2), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Blacksmith Working 2
SET @BLACKSMITH_GUID := -(@CGUID+237);
SET @BLACKSMITH_PATH1 := (((@CGUID + 229) * 10) << 3) + 0;
SET @BLACKSMITH_PATH2 := (((@CGUID + 229) * 10) << 3) + 1;
SET @BLACKSMITH_ID := 1;
SET @ACTIONLIST_START := @ENTRY * 100 + @BLACKSMITH_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @BLACKSMITH_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 261985, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 261985 on Self'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 10000, 20000, 0, 0, 53, 0, @BLACKSMITH_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 10 - 20 seconds - Self: Start path #', (@BLACKSMITH_PATH1), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH2), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Blacksmith Carrier
SET @BLACKSMITH_GUID := -(@CGUID+238);
SET @BLACKSMITH_PATH1 := (((@CGUID + 232) * 10) << 3) + 0;
SET @BLACKSMITH_PATH2 := (((@CGUID + 232) * 10) << 3) + 1;
SET @ACTIONLIST_START := @ENTRY * 100 + 4;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` =  @BLACKSMITH_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@BLACKSMITH_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 282906, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 282906 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH1), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 282906, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 282906'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @BLACKSMITH_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@BLACKSMITH_PATH2), ', walk, do not repeat, Passive')),
(@BLACKSMITH_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @BLACKSMITH_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@BLACKSMITH_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- ---------------------------------------------------------------
-- Horde Stables
-- ---------------------------------------------------------------

SET @ENTRY := 15086;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;

-- Forsaken Stablehand Talking
SET @STABLEHAND_GUID := -(@CGUID+179);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @STABLEHAND_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@STABLEHAND_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Play emote 1');

-- Forsaken Stablehand Talking
SET @STABLEHAND_GUID := -(@CGUID+180);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @STABLEHAND_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@STABLEHAND_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Play emote 1');

-- ---------------------------------------------------------------
-- Alliance Stables
-- ---------------------------------------------------------------

SET @ENTRY := 15087;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;

-- Arathi Stablehand Talking
SET @STABLEHAND_GUID := -(@CGUID+247);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @STABLEHAND_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@STABLEHAND_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Play emote 1');

-- Arathi Stablehand Talking
SET @STABLEHAND_GUID := -(@CGUID+251);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @STABLEHAND_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@STABLEHAND_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Play emote 1');

-- ---------------------------------------------------------------
-- Horde Farm
-- ---------------------------------------------------------------

SET @ENTRY := 15046;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;

-- Forsaken Farmer Talking
SET @FARMER_GUID := -(@CGUID + 197);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 60, 0, 100, 0, 9000, 11000, 9000, 11000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 9 - 11 seconds - Self: Play emote 1');

-- Forsaken Farmer Talking
SET @FARMER_GUID := -(@CGUID + 201);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 60, 0, 100, 0, 9000, 11000, 9000, 11000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 9 - 11 seconds - Self: Play emote 1');

-- Forsaken Farmer Shouting
SET @FARMER_GUID := -(@CGUID + 192);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 5, 22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Play emote 22');

-- Forsaken Farmer Working 1
SET @FARMER_GUID := -(@CGUID + 184);
SET @FARMER_PATH1 := (((@CGUID + 184) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 184) * 10) << 3) + 1;
SET @FARMER_ID := 0;
SET @AIANIMKIT := 4760;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Working 2
SET @FARMER_GUID := -(@CGUID + 199);
SET @FARMER_PATH1 := (((@CGUID + 199) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 199) * 10) << 3) + 1;
SET @FARMER_ID := 1;
SET @AIANIMKIT := 4760;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Working 3
SET @FARMER_GUID := -(@CGUID + 196);
SET @FARMER_PATH1 := (((@CGUID + 196) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 196) * 10) << 3) + 1;
SET @FARMER_ID := 2;
SET @AIANIMKIT := 4760;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Working 4
SET @FARMER_GUID := -(@CGUID + 185);
SET @FARMER_PATH1 := (((@CGUID + 185) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 185) * 10) << 3) + 1;
SET @FARMER_ID := 3;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Working 5
SET @FARMER_GUID := -(@CGUID + 190);
SET @FARMER_PATH1 := (((@CGUID + 190) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 190) * 10) << 3) + 1;
SET @FARMER_ID := 4;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Working 6
SET @FARMER_GUID := -(@CGUID + 189);
SET @FARMER_PATH1 := (((@CGUID + 189) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 189) * 10) << 3) + 1;
SET @FARMER_ID := 5;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Working 7
SET @FARMER_GUID := -(@CGUID + 202);
SET @FARMER_PATH1 := (((@CGUID + 202) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 202) * 10) << 3) + 1;
SET @FARMER_ID := 6;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Working 8
SET @FARMER_GUID := -(@CGUID + 200);
SET @FARMER_PATH1 := (((@CGUID + 200) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 200) * 10) << 3) + 1;
SET @FARMER_ID := 7;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Forsaken Farmer Wanderer
SET @FARMER_GUID := -(@CGUID + 195);
SET @FARMER_PATH1 := (((@CGUID + 195) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 195) * 10) << 3) + 1;
SET @ACTIONLIST_START := @ENTRY * 100 + 16;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- ---------------------------------------------------------------
-- Alliance Farm
-- ---------------------------------------------------------------

-- Arathi Farmer Talking
SET @FARMER_GUID := -(@CGUID + 277);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 60, 0, 100, 0, 9000, 11000, 9000, 11000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 9 - 11 seconds - Self: Play emote 1');

-- Arathi Farmer Talking
SET @FARMER_GUID := -(@CGUID + 282);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 60, 0, 100, 0, 9000, 11000, 9000, 11000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 9 - 11 seconds - Self: Play emote 1');

-- Arathi Farmer Shouting
SET @FARMER_GUID := -(@CGUID + 276);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 10000, 5000, 10000, 5, 22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 10 seconds - Self: Play emote 22');

-- Arathi Farmer Working 1
SET @FARMER_GUID := -(@CGUID + 284);
SET @FARMER_PATH1 := (((@CGUID + 184) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 184) * 10) << 3) + 1;
SET @FARMER_ID := 0;
SET @AIANIMKIT := 4760;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Working 2
SET @FARMER_GUID := -(@CGUID + 281);
SET @FARMER_PATH1 := (((@CGUID + 199) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 199) * 10) << 3) + 1;
SET @FARMER_ID := 1;
SET @AIANIMKIT := 4760;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Working 3
SET @FARMER_GUID := -(@CGUID + 285);
SET @FARMER_PATH1 := (((@CGUID + 196) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 196) * 10) << 3) + 1;
SET @FARMER_ID := 2;
SET @AIANIMKIT := 4760;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Working 4
SET @FARMER_GUID := -(@CGUID + 286);
SET @FARMER_PATH1 := (((@CGUID + 185) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 185) * 10) << 3) + 1;
SET @FARMER_ID := 3;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Working 5
SET @FARMER_GUID := -(@CGUID + 279);
SET @FARMER_PATH1 := (((@CGUID + 190) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 190) * 10) << 3) + 1;
SET @FARMER_ID := 4;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Working 6
SET @FARMER_GUID := -(@CGUID + 278);
SET @FARMER_PATH1 := (((@CGUID + 189) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 189) * 10) << 3) + 1;
SET @FARMER_ID := 5;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Working 7
SET @FARMER_GUID := -(@CGUID + 280);
SET @FARMER_PATH1 := (((@CGUID + 202) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 202) * 10) << 3) + 1;
SET @FARMER_ID := 6;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Working 8
SET @FARMER_GUID := -(@CGUID + 287);
SET @FARMER_PATH1 := (((@CGUID + 200) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 200) * 10) << 3) + 1;
SET @FARMER_ID := 7;
SET @AIANIMKIT := 7424;
SET @ACTIONLIST_START := @ENTRY * 100 + @FARMER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 2 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, @AIANIMKIT, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Plays Anim with ID ', @AIANIMKIT)),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 15000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 15 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- Arathi Farmer Wanderer
SET @FARMER_GUID := -(@CGUID + 283);
SET @FARMER_PATH1 := (((@CGUID + 195) * 10) << 3) + 0;
SET @FARMER_PATH2 := (((@CGUID + 195) * 10) << 3) + 1;
SET @ACTIONLIST_START := @ENTRY * 100 + 16;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @FARMER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@FARMER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH1), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH1, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @FARMER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@FARMER_PATH2), ', walk, do not repeat, Passive')),
(@FARMER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @FARMER_PATH2, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@FARMER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always)'));

-- ---------------------------------------------------------------
-- Horde Mine
-- ---------------------------------------------------------------

SET @ENTRY := 15075;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;

-- Forsaken Miner Talking
SET @MINER_GUID := -(@CGUID + 291);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Play emote 1');

-- Forsaken Miner Talking
SET @MINER_GUID := -(@CGUID + 292);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Play emote 1');

-- Forsaken Miner Working 1
SET @MINER_GUID := -(@CGUID + 290);
SET @MINER_PATH1 := (((@CGUID + 217) * 10) << 3) + 0;
SET @MINER_PATH2 := (((@CGUID + 217) * 10) << 3) + 1;
SET @MINER_PATH3 := (((@CGUID + 217) * 10) << 3) + 2;
SET @MINER_ID := 0;
SET @ACTIONLIST_START := @ENTRY * 100 + @MINER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 1320, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 1320'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 175121 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @MINER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', (@MINER_PATH2), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH2, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 175121'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@MINER_PATH3), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 3, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH3, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH3), ' ended - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive'));

-- Forsaken Miner Working 2
SET @MINER_GUID := -(@CGUID + 294);
SET @MINER_PATH1 := (((@CGUID + 224) * 10) << 3) + 0;
SET @MINER_PATH2 := (((@CGUID + 224) * 10) << 3) + 1;
SET @MINER_PATH3 := (((@CGUID + 224) * 10) << 3) + 2;
SET @MINER_ID := 1;
SET @ACTIONLIST_START := @ENTRY * 100 + @MINER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 1320, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 1320'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 175121 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @MINER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', (@MINER_PATH2), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH2, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 175121'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@MINER_PATH3), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 3, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH3, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH3), ' ended - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive'));

-- Forsaken Miner Working 2
SET @MINER_GUID := -(@CGUID + 293);
SET @MINER_PATH1 := (((@CGUID + 219) * 10) << 3) + 0;
SET @MINER_PATH2 := (((@CGUID + 219) * 10) << 3) + 1;
SET @MINER_PATH3 := (((@CGUID + 219) * 10) << 3) + 2;
SET @MINER_ID := 2;
SET @ACTIONLIST_START := @ENTRY * 100 + @MINER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 1320, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 1320'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 175121 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @MINER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', (@MINER_PATH2), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH2, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 175121'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@MINER_PATH3), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 3, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH3, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH3), ' ended - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive'));

-- ---------------------------------------------------------------
-- Alliance Mine
-- ---------------------------------------------------------------

SET @ENTRY := 15074;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;

-- Arathi Miner Talking
SET @MINER_GUID := -(@CGUID + 220);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Play emote 1');

-- Arathi Miner Talking
SET @MINER_GUID := -(@CGUID + 221);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 60, 0, 100, 0, 5000, 15000, 5000, 15000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 15 seconds - Self: Play emote 1');

-- Arathi Miner Working 1
SET @MINER_GUID := -(@CGUID + 217);
SET @MINER_PATH1 := (((@CGUID + 217) * 10) << 3) + 0;
SET @MINER_PATH2 := (((@CGUID + 217) * 10) << 3) + 1;
SET @MINER_PATH3 := (((@CGUID + 217) * 10) << 3) + 2;
SET @MINER_ID := 0;
SET @ACTIONLIST_START := @ENTRY * 100 + @MINER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 1320, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 1320'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 175121 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @MINER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', (@MINER_PATH2), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH2, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 175121'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@MINER_PATH3), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 3, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH3, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH3), ' ended - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive'));

-- Arathi Miner Working 2
SET @MINER_GUID := -(@CGUID + 224);
SET @MINER_PATH1 := (((@CGUID + 224) * 10) << 3) + 0;
SET @MINER_PATH2 := (((@CGUID + 224) * 10) << 3) + 1;
SET @MINER_PATH3 := (((@CGUID + 224) * 10) << 3) + 2;
SET @MINER_ID := 1;
SET @ACTIONLIST_START := @ENTRY * 100 + @MINER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 1320, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 1320'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 175121 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @MINER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', (@MINER_PATH2), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH2, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 175121'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@MINER_PATH3), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 3, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH3, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH3), ' ended - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive'));

-- Arathi Miner Working 2
SET @MINER_GUID := -(@CGUID + 219);
SET @MINER_PATH1 := (((@CGUID + 219) * 10) << 3) + 0;
SET @MINER_PATH2 := (((@CGUID + 219) * 10) << 3) + 1;
SET @MINER_PATH3 := (((@CGUID + 219) * 10) << 3) + 2;
SET @MINER_ID := 2;
SET @ACTIONLIST_START := @ENTRY * 100 + @MINER_ID * 2;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @MINER_GUID;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (@ACTIONLIST_START, @ACTIONLIST_START + 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@MINER_GUID, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On respawn - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 1, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH1, 0, 0, 80, @ACTIONLIST_START, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH1), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START), ' (update always) // -inline')),
(@ACTIONLIST_START, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 1320, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 1320'),
(@ACTIONLIST_START, 9, 1, 0, 0, 0, 100, 0, 5000, 10000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 - 10 seconds - Self: Plays Anim with ID 0'),
(@ACTIONLIST_START, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 175121 on Self'),
(@ACTIONLIST_START, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, @MINER_PATH2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 1 seconds - Self: Start path #', (@MINER_PATH2), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 2, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH2, 0, 0, 80, @ACTIONLIST_START + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH2), ' ended - Self: Start timed action list id #', (@ACTIONLIST_START + 1), ' (update always) // -inline')),
(@ACTIONLIST_START + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 175121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Remove aura due to spell 175121'),
(@ACTIONLIST_START + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69'),
(@ACTIONLIST_START + 1, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Set emote state to 0'),
(@ACTIONLIST_START + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @MINER_PATH3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('After 0 seconds - Self: Start path #', (@MINER_PATH3), ', walk, do not repeat, Passive')),
(@MINER_GUID, 0, 3, 0, 58, 0, 100, 0, 0xFFFFFFFF, @MINER_PATH3, 0, 0, 53, 0, @MINER_PATH1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On any waypoint of path #', (@MINER_PATH3), ' ended - Self: Start path #', (@MINER_PATH1), ', walk, do not repeat, Passive'));

-- Elemental Skirmish
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN(150426, 149793);

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN(-(@CGUID+22),-(@CGUID+32),-(@CGUID+52),-(@CGUID+58),-(@CGUID+111),-(@CGUID+112));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+22), 0, 0, 0, 60, 0, 100, 0, 4000, 8000, 4000, 8000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 8 seconds - Self: Play emote 35'),
(-(@CGUID+32), 0, 0, 0, 60, 0, 100, 0, 4000, 8000, 4000, 8000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 8 seconds - Self: Play emote 35'),
(-(@CGUID+52), 0, 0, 0, 60, 0, 100, 0, 4000, 8000, 4000, 8000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 8 seconds - Self: Play emote 35'),
(-(@CGUID+58), 0, 0, 0, 60, 0, 100, 0, 4000, 8000, 4000, 8000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 8 seconds - Self: Play emote 35'),
(-(@CGUID+111), 0, 0, 0, 60, 0, 100, 0, 4000, 8000, 4000, 8000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 8 seconds - Self: Play emote 35'),
(-(@CGUID+112), 0, 0, 0, 60, 0, 100, 0, 4000, 8000, 4000, 8000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 8 seconds - Self: Play emote 35');


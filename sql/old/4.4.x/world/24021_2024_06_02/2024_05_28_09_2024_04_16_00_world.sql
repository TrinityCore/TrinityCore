SET @OGUID := 3000028;
SET @CGUID := 3000009;
SET @TRIGGER_ID_ALLIANCE := 30; -- Trigger ID for capture flag area trigger alliance
SET @TRIGGER_ID_HORDE := 31; -- Trigger ID for capture flag area trigger horde
SET @TRIGGER_SPAWN_ID := 65;

UPDATE `battleground_template` SET `Weight` = 1 WHERE `ID` = 108;

DELETE FROM `graveyard_zone` where `ID` IN (1728, 1729, 1749, 1750);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(1728, 5031, 'Twin Peaks - Horde Base'),
(1729, 5031, 'Twin Peaks - Alliance Base'),
(1749, 5031, 'Twin Peaks - Alliance Center'),
(1750, 5031, 'Twin Peaks - Horde Center');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (1728, 1729, 1749, 1750);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(27, 1729, 5031, 0, 6, 469, 0, 0, 'Graveyard - Twin Peaks - Alliance Base - Team Alliance'),
(27, 1728, 5031, 0, 6, 67, 0, 0, 'Graveyard - Twin Peaks - Horde Base - Team Horde'),
(27, 1749, 5031, 0, 6, 469, 0, 0, 'Graveyard - Twin Peaks - Alliance Center - Team Alliance'),
(27, 1749, 5031, 0, 23, 5775, 0, 1, 'Graveyard - Twin Peaks - Alliance Center - Not near Horde Base'),
(27, 1749, 5031, 0, 23, 5681, 0, 1, 'Graveyard - Twin Peaks - Alliance Center - Not in Horde Base'),
(27, 1729, 5031, 0, 23, 5776, 0, 1, 'Graveyard - Twin Peaks - Alliance Base - Not near Alliance Base'),
(27, 1729, 5031, 0, 23, 5680, 0, 1, 'Graveyard - Twin Peaks - Alliance Base - Not in Alliance Base'),
(27, 1750, 5031, 0, 6, 67, 0, 0, 'Graveyard - Twin Peaks - Horde Center - Team Horde'),
(27, 1750, 5031, 0, 23, 5776, 0, 1, 'Graveyard - Twin Peaks - Horde Center - Not near Alliance Base'),
(27, 1750, 5031, 0, 23, 5680, 0, 1, 'Graveyard - Twin Peaks - Horde Center - Not in Alliance Base'),
(27, 1728, 5031, 0, 23, 5775, 0, 1, 'Graveyard - Twin Peaks - Horde Base - Not near Horde Base'),
(27, 1728, 5031, 0, 23, 5681, 0, 1, 'Graveyard - Twin Peaks - Horde Base - Not in Horde Base');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5907, 5908, 5910, 5909, 5911, 5906);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5908, 'at_battleground_buffs'),
(5907, 'at_battleground_buffs'),
(5910, 'at_battleground_buffs'),
(5909, 'at_battleground_buffs'),
(5911, 'at_battleground_buffs'),
(5906, 'at_battleground_buffs');

DELETE FROM `gameobject` WHERE `guid` IN (216144, 216129, 216143, 220777, 216139, 216138, 216133, 216131, 216137, 216142, 216134);
-- fix buff respawn times
UPDATE `gameobject` SET `spawntimesecs` = 90 WHERE `guid` IN (216130, 216136, 216135, 216132);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+16;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180322, 726, 5031, 5681, '0', '0', 0, 1832.0103759765625, 516.01910400390625, 26.99340248107910156, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 7200, 255, 1, 54205), -- Ghost Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+1, 303120, 726, 5031, 5681, '0', '0', 0, 1953.2412109375, 394.69012451171875, -9.54223155975341796, 0.549776852130889892, 0, 0, 0.271439552307128906, 0.962455451488494873, 7200, 255, 0, 54205), -- Doodad_vr_cookpot_01 (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+2, 180322, 726, 5031, 5681, '0', '0', 0, 1857.8004150390625, 512.55902099609375, 34.93069839477539062, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 7200, 255, 1, 54205), -- Ghost Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+3, 179899, 726, 5031, 5681, '0', '0', 0, 1611.2708740234375, 306.963531494140625, 0.248635083436965942, 4.989840030670166015, 0, 0, -0.60253429412841796, 0.798092961311340332, 90, 255, 1, 54205), -- Speed Buff (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+4, 180322, 726, 5031, 5681, '0', '0', 0, 1846.3992919921875, 513.5538330078125, 30.47980117797851562, 0, 0, 0, 0, 1, 7200, 255, 1, 54205), -- Ghost Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+5, 208205, 726, 5031, 5681, '0', '0', 0, 1556.656005859375, 314.71270751953125, 1.589000582695007324, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 7200, 255, 1, 54205), -- Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+6, 208207, 726, 5031, 5681, '0', '0', 0, 1558.087890625, 372.765380859375, 1.723726868629455566, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 7200, 255, 1, 54205), -- Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+7, 208206, 726, 5031, 5681, '0', '0', 0, 1574.6053466796875, 321.2420654296875, 1.589889883995056152, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 7200, 255, 1, 54205), -- Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+8, 203710, 726, 5031, 5681, '0', '0', 0, 1558.6226806640625, 379.159515380859375, -6.4096693992614746, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 7200, 255, 1, 54205), -- Portcullis (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+9, 180322, 726, 5031, 5681, '0', '0', 0, 1820.470458984375, 517.435791015625, 25.55260086059570312, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 7200, 255, 1, 54205), -- Ghost Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+10, 206653, 726, 5031, 5681, '0', '0', 0, 2135.52490234375, 218.9260101318359375, 43.60945510864257812, 5.75086069107055664, 0, 0, -0.263031005859375, 0.96478736400604248, 7200, 255, 1, 54205), -- Wildhammer Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+11, 206655, 726, 5031, 5681, '0', '0', 0, 2118.087646484375, 154.6754302978515625, 43.57088851928710937, 2.609261274337768554, 0, 0, 0.964786529541015625, 0.263034075498580932, 7200, 255, 1, 54205), -- Wildhammer Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+12, 206654, 726, 5031, 5681, '0', '0', 0, 2156, 219.2058868408203125, 43.62560272216796875, 2.609261274337768554, 0, 0, 0.964786529541015625, 0.263034075498580932, 7200, 255, 1, 54205), -- Wildhammer Gate (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+13, 303119, 726, 5031, 5681, '0', '0', 0, 1986.051025390625, 420.545745849609375, -20.7072296142578125, 5.148722648620605468, 0, 0, -0.53729915618896484, 0.843391716480255126, 7200, 255, 1, 54205), -- Doodad_firewoodpile-indoor-only01 (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+14, 227741, 726, 5031, 5681, '0', '0', 0, 2117.63720703125, 191.6822967529296875, 44.05199050903320312, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 7200, 255, 1, 54205), -- Alliance Flag (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+15, 227740, 726, 5031, 5681, '0', '0', 0, 1578.3367919921875, 344.045135498046875, 2.418408870697021484, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 7200, 255, 1, 54205), -- Horde Flag (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1
(@OGUID+16, 179871, 726, 5031, 5681, '0', '0', 0, 2088.864501953125, 258.630218505859375, 43.79682540893554687, 1.66558992862701416, 0, 0, 0.73981475830078125, 0.672810614109039306, 90, 255, 1, 54205); -- Speed Buff (Area: Dragonmaw Flag Room - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+16;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, 0.390731066465377807, 0.920504868030548095, 0, 0), -- Doodad_vr_cookpot_01
(@OGUID+5, 0, 0, -0.05233581736683845, 0.998629570007324218, 0, 0), -- Gate
(@OGUID+6, 0, 0, -0.05233581736683845, 0.998629570007324218, 0, 0), -- Gate
(@OGUID+7, 0, 0, -0.05233581736683845, 0.998629570007324218, 0, 0), -- Gate
(@OGUID+8, 0, 0, -0.05233581736683845, 0.998629570007324218, 0, 0), -- Portcullis
(@OGUID+10, 0, 0, 0.964787304401397705, 0.263031333684921264, 0, 0), -- Wildhammer Gate
(@OGUID+11, 0, 0, 0.964787304401397705, 0.263031333684921264, 0, 0), -- Wildhammer Gate
(@OGUID+12, 0, 0, 0.964787304401397705, 0.263031333684921264, 0, 0), -- Wildhammer Gate
(@OGUID+13, 0, 0, 0.390731066465377807, 0.920504868030548095, 0, 0); -- Doodad_firewoodpile-indoor-only01

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 13117, 726, 5031, 0, '0', '0', 0, 0, 1, 1818.3055419921875, 153.1302032470703125, 1.889904022216796875, 1.631284713745117187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205); -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @TRIGGER_SPAWN_ID+0 AND @TRIGGER_SPAWN_ID+1 AND `IsCustom` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `ScriptName`, `Comment`) VALUES
(@TRIGGER_SPAWN_ID+0, @TRIGGER_ID_ALLIANCE, 1, 726, 2117.63720703125, 191.6822967529296875, 44.05199050903320312, 6.021387100219726562, 'areatrigger_action_capture_flag', 'Twin Peaks - Capture Flag - Alliance'),
(@TRIGGER_SPAWN_ID+1, @TRIGGER_ID_HORDE, 1, 726, 1578.3367919921875, 344.045135498046875, 2.418408870697021484, 2.792518377304077148, 'areatrigger_action_capture_flag', 'Twin Peaks - Capture Flag - Horde');

-- 75 seconds for quick cap aura
UPDATE `serverside_spell` SET `DurationIndex` = 62 WHERE `Id` = 183317;

DELETE FROM `world_state` WHERE `ID` IN (5746, 5747);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `Comment`) VALUES
(5746, 0, '726', 'Twin Peaks - Double Jeopardy Alliance'),
(5747, 0, '726', 'Twin Peaks - Double Jeopardy Horde');

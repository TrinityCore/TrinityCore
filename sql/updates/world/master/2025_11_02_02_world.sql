SET @CGUID := 6006031;
SET @OGUID := 6003052;
SET @SPAWN_GROUP := 1282;

DELETE FROM `battleground_scripts` WHERE `MapId` = 1504 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(1504, 0, 'arena_black_rook_hold_arena');

DELETE FROM `battleground_template` WHERE `ID` = 808;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(808, 5122, 5121, 0, 1, 'Black Rook Hold');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Black Rook Hold Arena - Shadow sight', 0x20);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+44;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 113180, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1425.5885009765625, 1311.2083740234375, 53.24037933349609375, 4.736895561218261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+1, 113180, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1393.392333984375, 1293.920166015625, 48.62905120849609375, 5.532239437103271484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+2, 113180, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1444.013916015625, 1289.9322509765625, 46.73127365112304687, 4.530204296112060546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+3, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1390.8941650390625, 1301.107666015625, 53.2404022216796875, 5.56732177734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+4, 113180, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1480.515625, 1240.607666015625, 48.62343597412109375, 2.81912851333618164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+5, 113180, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1424.670166015625, 1295.40283203125, 46.7177734375, 4.867033958435058593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+6, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1383.18408203125, 1244.857666015625, 51.522979736328125, 6.10341644287109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+7, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1470.138916015625, 1227.954833984375, 46.72119903564453125, 2.69378519058227539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+8, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1487.642333984375, 1236.12158203125, 53.49858856201171875, 3.073758602142333984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+9, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1453.1458740234375, 1206.1961669921875, 46.722808837890625, 2.401234865188598632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+10, 113180, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1480.5816650390625, 1215.954833984375, 53.24036407470703125, 2.614834308624267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+11, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1372.21533203125, 1207.6771240234375, 53.24039459228515625, 0.763886213302612304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+12, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1379.77783203125, 1276.62158203125, 46.6444091796875, 5.84418344497680664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+13, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1449.6822509765625, 1300.3350830078125, 51.00694656372070312, 4.327450275421142578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+14, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1392.173583984375, 1198.60595703125, 48.61893844604492187, 1.071634650230407714, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+15, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1473.263916015625, 1217.5538330078125, 48.6434783935546875, 2.929628372192382812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+16, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1454.892333984375, 1194.1771240234375, 51.01436996459960937, 2.129171609878540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+17, 114620, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1429.13134765625, 1276.8773193359375, 33.22537994384765625, 5.266579151153564453, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Dusk Spiderling (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1383.579833984375, 1216.6353759765625, 46.71955108642578125, 0.609175741672515869, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+19, 114621, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1465.203369140625, 1245.3006591796875, 32.98969268798828125, 0.957385122776031494, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Cockroach (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1415.4722900390625, 1302.732666015625, 48.64091873168945312, 4.757316112518310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+21, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1376.4722900390625, 1208.2847900390625, 50.97879409790039062, 0.370390832424163818, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+22, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1472.4722900390625, 1242.875, 46.72802352905273437, 3.104459524154663085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+23, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1400.5260009765625, 1289.8853759765625, 46.71635818481445312, 5.375006675720214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+24, 114618, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1435.862548828125, 1304.86865234375, 74.0537567138671875, 5.254535198211669921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Kaldorei Windgryph (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+25, 114617, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1418.9757080078125, 1297.6458740234375, 33.08808517456054687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Risen Saber (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 184387 - Black Rook Hold Ghost Visual)
(@CGUID+26, 114617, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1467.6441650390625, 1218.1302490234375, 33.08701705932617187, 1.057152390480041503, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Risen Saber (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 184387 - Black Rook Hold Ghost Visual)
(@CGUID+27, 114620, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1426.3172607421875, 1194.4637451171875, 32.26053619384765625, 3.108500480651855468, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Dusk Spiderling (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+28, 114621, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1391.90087890625, 1216.066650390625, 33.949127197265625, 4.225357532501220703, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Cockroach (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 114621, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1411.09765625, 1192.5714111328125, 32.26054000854492187, 2.879513740539550781, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Cockroach (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+30, 114620, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1411.875, 1239.3507080078125, 34.19060134887695312, 1.52785956859588623, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Dusk Spiderling (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+31, 113264, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1462.0069580078125, 1203.19970703125, 48.6137542724609375, 1.972630023956298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+32, 114621, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1438.90283203125, 1282.0660400390625, 33.07302093505859375, 4.635184288024902343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Cockroach (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+33, 114618, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1324.19189453125, 1242.88427734375, 63.12650299072265625, 0.003253789152950048, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Kaldorei Windgryph (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+34, 114618, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1350.1671142578125, 1280.3900146484375, 106.6975173950195312, 4.724079132080078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Kaldorei Windgryph (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+35, 114618, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1467.9161376953125, 1219.8092041015625, 110.937652587890625, 1.391187787055969238, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Kaldorei Windgryph (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+36, 114618, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1323.37890625, 1243.4534912109375, 63.3365631103515625, 0.164714828133583068, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Kaldorei Windgryph (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+37, 114621, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1371.8175048828125, 1253.8363037109375, 32.26054000854492187, 5.696830272674560546, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Cockroach (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 114620, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1439.4691162109375, 1217.3165283203125, 33.00476455688476562, 4.563040733337402343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Dusk Spiderling (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 114621, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1460.8739013671875, 1283.9073486328125, 32.2605438232421875, 4.492687225341796875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Cockroach (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 114618, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1318.49658203125, 1204.293701171875, 104.2949752807617187, 5.937742233276367187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Kaldorei Windgryph (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+41, 114618, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1467.460205078125, 1245.385498046875, 107.5664901733398437, 3.9197235107421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Kaldorei Windgryph (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)
(@CGUID+42, 114620, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1474.311279296875, 1263.5736083984375, 32.26054000854492187, 0.768477439880371093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Dusk Spiderling (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 114621, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1469.5416259765625, 1225.5711669921875, 32.736480712890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Cockroach (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@CGUID+44, 113180, 1504, 7816, 7816, '0', '0', 0, 0, 0, 1374.357666015625, 1274.392333984375, 48.64179229736328125, 5.843991756439208984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Ghostly Spectator (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1 (Auras: 225288 - Crowd)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;

DELETE FROM `creature_template_addon` WHERE `entry` IN (114617 /*114617 (Risen Saber) - Black Rook Hold Ghost Visual*/, 114618 /*114618 (Kaldorei Windgryph) - Crowd*/, 114619 /*114619 (Reanimated Archer) - Ride Vehicle Hardcoded, Crowd*/, 113264 /*113264 (Ghostly Spectator) - Crowd*/, 113180 /*113180 (Ghostly Spectator) - Crowd*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(114617, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '184387'), -- 114617 (Risen Saber) - Black Rook Hold Ghost Visual
(114618, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'), -- 114618 (Kaldorei Windgryph) - Crowd
(114619, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '225288'), -- 114619 (Reanimated Archer) - Crowd
(113264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '225288'), -- 113264 (Ghostly Spectator) - Crowd
(113180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '225288'); -- 113180 (Ghostly Spectator) - Crowd

UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114617; -- Risen Saber
UPDATE `creature_template` SET `unit_flags`=0x2000240 WHERE `entry`=114618; -- Kaldorei Windgryph
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114621; -- Cockroach
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114620; -- Dusk Spiderling
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114619; -- Reanimated Archer

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114617 AND `DifficultyID`=0); -- 114617 (Risen Saber) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=114618 AND `DifficultyID`=0); -- 114618 (Kaldorei Windgryph) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114620 AND `DifficultyID`=0); -- 114620 (Dusk Spiderling) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=63305 WHERE (`Entry`=114619 AND `DifficultyID`=0); -- 114619 (Reanimated Archer) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=63305 WHERE (`Entry`=113264 AND `DifficultyID`=0); -- 113264 (Ghostly Spectator) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=63305 WHERE (`Entry`=113180 AND `DifficultyID`=0); -- 113180 (Ghostly Spectator) - Sessile, CanSwim, Floating

DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=0 AND `entry` IN (114618));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(114618, 114619, 0, 0, 'Kaldorei Windgryph - Reanimated Archer', 8, 0); -- Kaldorei Windgryph - Reanimated Archer

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=114618;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(114618, 46598, 1, 0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 245762, 1504, 7816, 7816, '0', '0', 0, 1455.901123046875, 1264.998779296875, 33.27016067504882812, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door001 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+1, 245763, 1504, 7816, 7816, '0', '0', 0, 1464.32177734375, 1254.8792724609375, 33.24254608154296875, 0.842486858367919921, 0, 0, 0.408895492553710937, 0.912581205368041992, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door002 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+2, 245766, 1504, 7816, 7816, '0', '0', 0, 1384.068359375, 1258.20458984375, 33.21187973022460937, 3.464510917663574218, 0, 0, -0.98699378967285156, 0.160758391022682189, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door005 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+3, 245767, 1504, 7816, 7816, '0', '0', 0, 1384.6124267578125, 1232.3526611328125, 33.27019119262695312, 2.866936683654785156, 0, 0, 0.9905853271484375, 0.136896729469299316, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door006 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+4, 245765, 1504, 7816, 7816, '0', '0', 0, 1385.8465576171875, 1245.1883544921875, 33.27016067504882812, 3.163166284561157226, 0, 0, -0.99994182586669921, 0.01078648492693901, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door004 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+5, 245770, 1504, 7816, 7816, '0', '0', 0, 1437.220703125, 1206.748779296875, 33.23869705200195312, 4.436479568481445312, 0, 0, -0.79762840270996093, 0.603149175643920898, 7200, 255, 01, 63305), -- Doodad_7NE_Blackrook_Door009 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+6, 245768, 1504, 7816, 7816, '0', '0', 0, 1411.41845703125, 1206.0908203125, 33.22338104248046875, 5.034043788909912109, 0, 0, -0.58474922180175781, 0.811214148998260498, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door007 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+7, 245769, 1504, 7816, 7816, '0', '0', 0, 1424.419921875, 1208.04345703125, 33.27061080932617187, 4.732609748840332031, 0, 0, -0.6999216079711914, 0.71421968936920166, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door008 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+8, 245781, 1504, 7816, 7816, '0', '0', 0, 1450.7222900390625, 1276.7388916015625, 33.24254608154296875, 0.249075517058372497, 0, 0, 0.124216079711914062, 0.992255210876464843, 7200, 255, 1, 63305), -- Doodad_7NE_Blackrook_Door010 (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+9, 249825, 1504, 7816, 7816, '0', '0', 0, 1185.1163330078125, 1404.4930419921875, 65.18283843994140625, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 7200, 255, 1, 63305), -- Black Rook Anvil (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject1
(@OGUID+10, 184663, 1504, 7816, 7816, '0', '0', 0, 1421.5069580078125, 1286.4600830078125, 32.93923568725585937, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305), -- Shadow Sight (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject2
(@OGUID+11, 184664, 1504, 7816, 7816, '0', '0', 0, 1458.5833740234375, 1225.1180419921875, 33.00343704223632812, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 360, 255, 1, 63305); -- Shadow Sight (Area: Black Rook Hold Arena - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door001
(@OGUID+1, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door002
(@OGUID+2, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door005
(@OGUID+3, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door006
(@OGUID+4, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door004
(@OGUID+5, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door009
(@OGUID+6, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door007
(@OGUID+7, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_7NE_Blackrook_Door008
(@OGUID+8, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0); -- Doodad_7NE_Blackrook_Door010

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+10),
(@SPAWN_GROUP, 1, @OGUID+11);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

SET @MOVERGUID := @CGUID+34;
SET @ENTRY := 114618;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 15.4614, 'Kaldorei Windgryph - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1364.9271, 1256.3837, 100.30972, NULL, 0),
(@PATH, 1, 1479.1528, 1265.2656, 109.30576, NULL, 0),
(@PATH, 2, 1413.2205, 1228.4497, 112.82463, NULL, 0),
(@PATH, 3, 1381.882, 1232.6354, 112.82463, NULL, 0),
(@PATH, 4, 1337.2361, 1298.6459, 112.82463, NULL, 0),
(@PATH, 5, 1394.2535, 1275.2048, 112.82463, NULL, 0);

UPDATE `creature` SET `position_x`=1364.9271, `position_y`=1256.3837, `position_z`=100.30972, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'); -- 114618 (Kaldorei Windgryph) - Crowd

SET @MOVERGUID := @CGUID+41;
SET @ENTRY := 114618;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 5.3049, 'Kaldorei Windgryph - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1469.375, 1247.2031, 107.636, NULL, 0),
(@PATH, 1, 1418.1615, 1202.375, 107.636, NULL, 0),
(@PATH, 2, 1368.4323, 1218.2344, 107.636, NULL, 0),
(@PATH, 3, 1359.6615, 1234.0695, 107.636, NULL, 0),
(@PATH, 4, 1377.8785, 1272.1841, 107.636, NULL, 0),
(@PATH, 5, 1465.5521, 1289.3663, 107.636, NULL, 0),
(@PATH, 6, 1487.4062, 1268.1962, 107.636, NULL, 0),
(@PATH, 7, 1470.0017, 1247.2587, 107.636, NULL, 0);

UPDATE `creature` SET `position_x`=1469.375, `position_y`=1247.2031, `position_z`=107.636, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'); -- 114618 (Kaldorei Windgryph) - Crowd

SET @MOVERGUID := @CGUID+40;
SET @ENTRY := 114618;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 6.8917, 'Kaldorei Windgryph - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1322.368, 1203.224, 102.81925, NULL, 0),
(@PATH, 1, 1347.0764, 1203.1841, 98.73532, NULL, 0),
(@PATH, 2, 1462.8125, 1276.651, 107.32701, NULL, 0),
(@PATH, 3, 1471.007, 1299.507, 100.88754, NULL, 0),
(@PATH, 4, 1362.8993, 1282.4254, 100.47532, NULL, 0),
(@PATH, 5, 1322.9149, 1202.6077, 103.14907, NULL, 0),
(@PATH, 6, 1475.9653, 1333.8993, 112.86004, NULL, 0);

UPDATE `creature` SET `position_x`=1322.368, `position_y`=1203.224, `position_z`=102.81925, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'); -- 114618 (Kaldorei Windgryph) - Crowd

SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 114618;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 5.2373, 'Kaldorei Windgryph - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1318.9271, 1242.9567, 63.158733, NULL, 0),
(@PATH, 1, 1365.5295, 1241.9548, 63.158733, NULL, 0),
(@PATH, 2, 1391.6337, 1230.4115, 63.158733, NULL, 0),
(@PATH, 3, 1390.0226, 1214.1736, 64.40624, NULL, 0),
(@PATH, 4, 1403.4548, 1207.3055, 65.37476, NULL, 0),
(@PATH, 5, 1442.7882, 1207.9254, 65.37476, NULL, 0),
(@PATH, 6, 1467.8385, 1235.7935, 60.263233, NULL, 0),
(@PATH, 7, 1452.8195, 1267.0104, 60.263233, NULL, 0),
(@PATH, 8, 1409.217, 1289.3976, 60.263233, NULL, 0),
(@PATH, 9, 1385.2743, 1265.7153, 66.269875, NULL, 0),
(@PATH, 10, 1344.8004, 1272.1632, 66.269875, NULL, 0),
(@PATH, 11, 1318.7327, 1242.8195, 63.530952, NULL, 0);

UPDATE `creature` SET `position_x`=1318.9271, `position_y`=1242.9567, `position_z`=63.158733, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'); -- 114618 (Kaldorei Windgryph) - Crowd

SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 114618;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 5.5476, 'Kaldorei Windgryph - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1432.7865, 1310.3073, 74.18702, NULL, 0),
(@PATH, 1, 1470.283, 1243.1077, 71.72169, NULL, 0),
(@PATH, 2, 1454.0156, 1209.5851, 71.72169, NULL, 0),
(@PATH, 3, 1425.717, 1209.9236, 71.72169, NULL, 0),
(@PATH, 4, 1387.1459, 1289.1198, 73.643524, NULL, 0),
(@PATH, 5, 1433.8889, 1311.9288, 73.643524, NULL, 0),
(@PATH, 6, 1432.7865, 1310.3073, 74.18702, NULL, 0);

UPDATE `creature` SET `position_x`=1432.7865, `position_y`=1310.3073, `position_z`=74.18702, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'); -- 114618 (Kaldorei Windgryph) - Crowd

SET @MOVERGUID := @CGUID+35;
SET @ENTRY := 114618;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 5.3070, 'Kaldorei Windgryph - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1466.7935, 1258.0435, 112.10487, NULL, 0),
(@PATH, 1, 1405.9601, 1274.4219, 112.10487, NULL, 0),
(@PATH, 2, 1344.5382, 1273.1788, 112.10487, NULL, 0),
(@PATH, 3, 1320.7935, 1250.6528, 112.10487, NULL, 0),
(@PATH, 4, 1339.5295, 1224.3317, 112.10487, NULL, 0),
(@PATH, 5, 1460.6493, 1210.9966, 112.10487, NULL, 0),
(@PATH, 6, 1473.6875, 1236.6267, 112.10487, NULL, 0),
(@PATH, 7, 1466.9635, 1257.8281, 112.10487, NULL, 0),
(@PATH, 8, 1466.7935, 1258.0435, 112.10487, NULL, 0);

UPDATE `creature` SET `position_x`=1466.7935, `position_y`=1258.0435, `position_z`=112.10487, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'); -- 114618 (Kaldorei Windgryph) - Crowd

SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 114618;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 5.3210, 'Kaldorei Windgryph - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1329.5226, 1244.2274, 63.36779, NULL, 0),
(@PATH, 1, 1387.6754, 1245.9983, 63.439243, NULL, 0),
(@PATH, 2, 1419.6805, 1291.8073, 63.439243, NULL, 0),
(@PATH, 3, 1432.8281, 1290.5278, 63.439243, NULL, 0),
(@PATH, 4, 1453.1719, 1266.316, 63.439243, NULL, 0),
(@PATH, 5, 1467.8646, 1235.8351, 63.439243, NULL, 0),
(@PATH, 6, 1441.1823, 1206.1649, 63.439243, NULL, 0),
(@PATH, 7, 1390.0798, 1214.1927, 63.439243, NULL, 0),
(@PATH, 8, 1388.0573, 1240.0156, 67.32278, NULL, 0),
(@PATH, 9, 1329.2223, 1244.1077, 64.03221, NULL, 0);

UPDATE `creature` SET `position_x`=1329.5226, `position_y`=1244.2274, `position_z`=63.36779, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '225288'); -- 114618 (Kaldorei Windgryph) - Crowd

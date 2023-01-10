SET @CGUID := 1250000;

SET @NPCTEXTID := 590000;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 198531, 0, 1519, 5148, '0', 0, 0, 0, 0, -8896.216796875, 572.55731201171875, 93.0708770751953125, 1.087328672409057617, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Zaralash (Area: Trade District - Difficulty: 0)
(@CGUID+1, 198532, 0, 1519, 5148, '0', 0, 0, 0, 0, -8769.7158203125, 650.65625, 109.1414871215820312, 0.798052430152893066, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Zhakloskar (Area: Trade District - Difficulty: 0) (Auras: 397765 - Cosmetic - Reading Book, Standing)
(@CGUID+2, 198533, 0, 1519, 5148, '0', 0, 0, 0, 0, -8817.388671875, 634.18231201171875, 95.976806640625, 0.073968231678009033, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187), -- Nazurathar (Area: Trade District - Difficulty: 0) (Auras: 147164 - Read Scroll, 394957 - Dracthyr Stylish Hat [DNT])
(@CGUID+3, 198551, 0, 1519, 5148, '0', 0, 0, 0, 0, -8821.3896484375, 622.23443603515625, 94.63285064697265625, 5.470208644866943359, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47187); -- Thaza (Area: Trade District - Difficulty: 0)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (198533 /*198533 (Nazurathar) - Read Scroll, Dracthyr Stylish Hat [DNT]*/, 198532 /*198532 (Zhakloskar) - Cosmetic - Reading Book, Standing*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198533, 0, 0, 1, 1, 0, 0, 0, 0, 0, '147164 394957'), -- 198533 (Nazurathar) - Read Scroll, Dracthyr Stylish Hat [DNT]
(198532, 0, 0, 1, 1, 0, 0, 0, 0, 0, '397765'); -- 198532 (Zhakloskar) - Cosmetic - Reading Book, Standing

-- Creature Template
UPDATE `creature_template` SET `gossip_menu_id`=30145, `minlevel`=70, `maxlevel`=70, `faction`=3340, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198533; -- Nazurathar
UPDATE `creature_template` SET `gossip_menu_id`=30143, `minlevel`=70, `maxlevel`=70, `faction`=3340, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198531; -- Zaralash
UPDATE `creature_template` SET `gossip_menu_id`=30140, `minlevel`=70, `maxlevel`=70, `faction`=3340, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198532; -- Zhakloskar
UPDATE `creature_template` SET `gossip_menu_id`=30144, `minlevel`=70, `maxlevel`=70, `faction`=3340, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198551; -- Thaza

-- Scaling & Model
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (50266,50286,189096,198551,15732,13435,48633,15730,198533,198532,198531));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(50266, 0, 0, 0, 56, 47187),
(50286, 0, 0, 0, 56, 47187),
(189096, 0, 0, 0, 371, 47187),
(198551, 0, 0, 0, 864, 47187),
(15732, 0, 0, 0, 417, 47187),
(13435, 0, 0, 0, 417, 47187),
(48633, 0, 0, 0, 987, 47187),
(15730, 0, 0, 0, 417, 47187),
(198533, 0, 0, 0, 864, 47187),
(198532, 0, 0, 0, 864, 47187),
(198531, 0, 0, 0, 864, 47187);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=47187 WHERE (`DifficultyID`=0 AND `Entry` IN (61837,50523,50525,50524,1367,1366,42421,5494,50480,52361,44583,1428,52359,44582,52358,1299,56925,71526,14721,14394,18359,65153,18357,43692,61896,61895,18362,1301,43769,18375,42339,1478,1477,2533,2532,62822,62821,143622,1295,279,483,482,4981,3518,46602,133433,43822,175420,2455,61838,277,43820,1289,133431,43819,3504,61836,1287,6740,49748,44774,35477,44773,2334,1286,1275,61834,1285,1303,12481,1302,12480,29093,141270,162935,15659,1432,49877,1402,1431,8719,13436,8670,5193,48632,1427,1294,2457,2331,2456,2330,1291,32520,50669,4075,1976,133509,188151,6174,49540,4974,175416,3513,179896,29142,1257,3512,15760,3511,3510,3509,51348,18927,3508,1298,3507,111190,51440,1297,82464,3505,68));

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (106604, 110189, 110178, 110176, 110175);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(106604, 0.32188686728477478, 0, 0, 47187),
(110189, 0.722000002861022949, 2, 0, 47187),
(110178, 0.722000002861022949, 2, 0, 47187),
(110176, 0.722000002861022949, 2, 0, 47187),
(110175, 0.722000002861022949, 2, 0, 47187);

UPDATE `creature_model_info` SET `VerifiedBuild`=47187 WHERE `DisplayID` IN (26556, 34116, 42275, 36814, 36816, 36815, 99401, 45881, 99496, 37087, 22769, 99497, 5552, 33303, 99498, 37850, 1447, 39532, 49021, 12923, 14431, 17696, 46026, 17694, 33468, 17717, 1443, 33507, 17703, 15921, 19670, 1519, 1509, 42722, 42720, 77407, 77406, 1445, 5082, 5546, 3246, 5547, 1541, 37372, 82919, 33520, 913, 1450, 42276, 1433, 33519, 1429, 83229, 33518, 42274, 1448, 5444, 36597, 34070, 344, 1440, 1444, 42273, 1434, 1441, 99499, 5567, 25901, 87182, 15594, 5074, 36758, 1438, 5545, 13349, 7992, 13355, 7991, 3133, 36213, 13356, 5551, 1423, 1437, 37310, 99197, 1436, 99196, 1439, 21342, 36839, 1141, 5446, 82973, 106457, 4888, 1418, 2974, 99615, 1526, 33948, 1431, 18801, 262, 99389, 15294, 221, 37311, 18800, 1427, 80, 11686, 99391, 338, 1446, 58170, 257, 3167);
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=47187 WHERE `DisplayID`=36214;

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 232805, 0, 0, 0, 0, 0, 0, 0, 47187), -- 198532 (Zhakloskar)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 232818, 0, 0, 0, 0, 0, 0, 0, 47187), -- 198531 (Zaralash)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 232820, 0, 0, 0, 0, 0, 0, 0, 47187), -- 198551 (Thaza)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 232821, 0, 0, 0, 0, 0, 0, 0, 47187); -- 198533 (Nazurathar)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30140 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30143 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=30144 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=30145 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30140, @NPCTEXTID+0, 47187), -- 198532 (Zhakloskar)
(30143, @NPCTEXTID+1, 47187), -- 198531 (Zaralash)
(30144, @NPCTEXTID+2, 47187), -- 198551 (Thaza)
(30145, @NPCTEXTID+3, 47187); -- 198533 (Nazurathar)

-- Waypoints
SET @PATH := (@CGUID+3) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8828.308, 629.5452, 94.45318, 0.2800242, 8855),
(@PATH, 1, -8798.714, 600.7587, 97.55834, NULL, 18564);

UPDATE `creature` SET `position_x`= -8828.308, `position_y`= 629.5452, `position_z`= 94.45318, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+3, @PATH, 1);

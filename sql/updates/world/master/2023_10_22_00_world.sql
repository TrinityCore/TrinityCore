-- Old spawns
SET @OLDCGUID := 652139;

DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+124;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+124;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+63;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+45;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+81;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+41;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+35;

SET @PATH := ((@OLDCGUID+58) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+38) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+63) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+24) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+12) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+3) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+16) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+45) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+81) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+41) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

SET @PATH := ((@OLDCGUID+35) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;

--
SET @OLDCGUID := 7000028;
SET @OLDOGUID := 7000014;

DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+129;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+129;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+63;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+45;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+81;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+41;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @OLDCGUID+35;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OLDOGUID+0 AND @OLDOGUID+3;

--
SET @OLDCGUID := 7000158;

DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+133;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+133;

--
SET @OLDCGUID := 7000292;

DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+1;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+1;

--
SET @OLDCGUID := 7000294;
SET @OLDOGUID := 7000018;

DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+129;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+129;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OLDOGUID+0 AND @OLDOGUID+7;

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@OLDCGUID+32), -(@OLDCGUID+19), -(@OLDCGUID+38), -(@OLDCGUID+33), -(@OLDCGUID+28), -(@OLDCGUID+31), -(@OLDCGUID+26), -(@OLDCGUID+46), -(@OLDCGUID+37), -(@OLDCGUID+107), -(@OLDCGUID+105), -(@OLDCGUID+111), -(@OLDCGUID+110));

--
SET @OLDCGUID := 7000424;
SET @OLDOGUID := 7000026;

DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+3;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+3;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OLDOGUID+0 AND @OLDOGUID+3;

-- New spawns
SET @CGUID := 6000158;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+124;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1066.6492919921875, 3119.07373046875, 12.07263755798339843, 2.188734292984008789, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+1, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1025.2117919921875, 3047.118896484375, -3.81276512145996093, 1.52768874168395996, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 977.82550048828125, 3122.361572265625, -28.1074886322021484, 2.283657550811767578, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+3, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1046.0435791015625, 3054.01611328125, -8.53504467010498046, 5.47154998779296875, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+4, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1128.6875, 3100.31591796875, -11.062117576599121, 5.19477701187133789, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+5, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 951.18231201171875, 3023.489501953125, -18.1599159240722656, 0.005821669939905405, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+6, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1004.90863037109375, 3135.66162109375, -2.47397232055664062, 3.546729803085327148, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+7, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1205.601318359375, 3136.126708984375, -15.7742252349853515, 3.373074769973754882, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1025.456298828125, 3033.936279296875, -11.987349510192871, 1.013128519058227539, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+9, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1035.2882080078125, 3105.020751953125, 3.478539466857910156, 1.428012490272521972, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+10, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 969.10443115234375, 3112.936767578125, -33.0618362426757812, 3.809101343154907226, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+11, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1044.923828125, 3138.15576171875, 10.6440582275390625, 4.477831840515136718, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1003.2100830078125, 3026.6259765625, -12.8141345977783203, 1.584265947341918945, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+13, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1043.170166015625, 3123.875, 8.298093795776367187, 1.468935728073120117, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+14, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1153.8038330078125, 3040.2197265625, -14.0022878646850585, 5.458607196807861328, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+15, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1193.8472900390625, 3071.624267578125, -15.3278303146362304, 5.861836910247802734, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+16, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1086.8345947265625, 3073.73974609375, -8.5683145523071289, 0.265823811292648315, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1105.4810791015625, 3148.6865234375, 24.10132980346679687, 5.498132705688476562, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+18, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 951.3367919921875, 3030.210205078125, -18.3688526153564453, 0.605075538158416748, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+19, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 961.1875, 3082.1806640625, -23.2998256683349609, 4.437739372253417968, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+20, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1026.54345703125, 3011.51220703125, -3.31593155860900878, 1.91265726089477539, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+21, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 993.935791015625, 3025.263916015625, -11.9025192260742187, 1.285972356796264648, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+22, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1060.484130859375, 3091.828369140625, -1.2409517765045166, 0.30881771445274353, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1067.685791015625, 3096.278564453125, 3.614101886749267578, 3.515080213546752929, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+24, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1053.673583984375, 3091.6142578125, -0.65945005416870117, 0.327153742313385009, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+25, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 972.94305419921875, 3153.470947265625, 2.072075843811035156, 5.363000869750976562, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 988.20379638671875, 3006.6826171875, -19.0753650665283203, 2.246147632598876953, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+27, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1166.986572265625, 3078.33251953125, -14.6779890060424804, 5.786333084106445312, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+28, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1117.301025390625, 3213.109130859375, 41.1098480224609375, 1.168951034545898437, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+29, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 946.2274169921875, 3080.921142578125, -30.2619991302490234, 5.1459197998046875, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+30, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1144.1976318359375, 3042.0078125, -15.422682762145996, 4.093502044677734375, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+31, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1119.2535400390625, 3102.20751953125, -12.1805133819580078, 5.025339126586914062, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+32, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 989.08856201171875, 3061.248291015625, -10.2608261108398437, 0.213856101036071777, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+33, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 988.19598388671875, 3012.00341796875, -17.9232101440429687, 3.784312963485717773, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+34, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1166.84033203125, 3113.950439453125, -7.0181436538696289, 3.30091714859008789, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+35, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1026.646728515625, 3033.972900390625, -11.994028091430664, 5.92498636245727539, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+36, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 948.484375, 3091.006103515625, -32.4343299865722656, 4.938072681427001953, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+37, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 978.1663818359375, 3121.6025390625, -28.81610107421875, 1.61573183536529541, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+38, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1001.61090087890625, 3061.189453125, -7.78473520278930664, 4.073184013366699218, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1025.8177490234375, 3125.017333984375, 7.813099384307861328, 0.903588175773620605, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+40, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1103.851318359375, 3024.375244140625, -14.4080095291137695, 2.037938833236694335, 120, 6, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1008.1605224609375, 3136.475341796875, -1.57657885551452636, 3.171094179153442382, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+42, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1090.3455810546875, 3027.211181640625, -11.9782371520996093, 3.558114290237426757, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+43, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1009.55548095703125, 3100.819580078125, 6.241608142852783203, 0.764264404773712158, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+44, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1065.5694580078125, 3013.974853515625, -10.2582120895385742, 1.294464588165283203, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+45, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1204.6502685546875, 3134.454345703125, -15.5943641662597656, 3.361215591430664062, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1057.921875, 3015.356689453125, -10.3449325561523437, 2.246151685714721679, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+47, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1072.204833984375, 3052.76220703125, -4.22993326187133789, 4.381879329681396484, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+48, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1108.6614990234375, 3088.817626953125, -11.2135467529296875, 4.181923389434814453, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+49, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1061.8663330078125, 2999.71875, -12.2458448410034179, 1.690015912055969238, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+50, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 983.88116455078125, 3006.846435546875, -19.3192863464355468, 3.724256038665771484, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+51, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 884.8836669921875, 3048.217041015625, -33.3857803344726562, 0.005021656397730112, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+52, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 962.4600830078125, 3002.79345703125, -18.3468360900878906, 1.406580448150634765, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+53, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 995.32293701171875, 2980.3291015625, -12.0215797424316406, 1.178008794784545898, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+54, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1221.671875, 3138.932373046875, -19.223947525024414, 3.415702104568481445, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+55, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 901.31597900390625, 3041.146728515625, -30.939004898071289, 6.252474784851074218, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+56, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1228.9149169921875, 3169.116455078125, -19.1225948333740234, 4.347538471221923828, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+57, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1224.8646240234375, 3166.150146484375, -18.9106483459472656, 0.002960902405902743, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+58, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 913.671875, 3044.0498046875, -27.088479995727539, 3.053585290908813476, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+59, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 900.6875, 3047.637939453125, -31.0888805389404296, 6.240606307983398437, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+60, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1006.49481201171875, 2980.8125, -11.5502967834472656, 1.863795161247253417, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+61, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1039.7413330078125, 2896.611083984375, 0.644535064697265625, 2.903236627578735351, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+62, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1229.41845703125, 3163.512939453125, -19.2121219635009765, 2.108534812927246093, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+63, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 968.219482421875, 2976.8291015625, -15.2141351699829101, 1.693212628364562988, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 966.0560302734375, 2976.622802734375, -15.6480474472045898, 1.862907648086547851, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 99218, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1566.32373046875, 1667.2039794921875, 101.852508544921875, 2.752264976501464843, 120, 0, 0, 5647, 0, 0, NULL, NULL, 50791), -- Legion Devastator Missile (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+66, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1143.6441650390625, 2960.038330078125, -18.10174560546875, 0.291081905364990234, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+67, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1118.183349609375, 2969.067138671875, -14.5146846771240234, 5.72319793701171875, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1112.9095458984375, 3080.278076171875, -10.4364538192749023, 4.012024402618408203, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+69, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 991.02423095703125, 3075.5322265625, -4.63933086395263671, 5.559192657470703125, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1062.8411865234375, 2936.14892578125, 2.650860786437988281, 2.319583415985107421, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+71, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1115.7545166015625, 3016.972900390625, -14.9768457412719726, 1.434663295745849609, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+72, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 983.57989501953125, 2950.270751953125, -9.93819808959960937, 2.608306407928466796, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+73, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1130.820068359375, 2917.84375, -5.16224956512451171, 4.895998001098632812, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+74, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1101.1474609375, 2936.935791015625, 2.962290287017822265, 1.778342843055725097, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+75, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1134.875, 2887.343017578125, 0.518563032150268554, 5.597451210021972656, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+76, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1132.1510009765625, 2885.611083984375, 1.025349855422973632, 5.6083831787109375, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+77, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1005.59027099609375, 2934.513916015625, -9.8221282958984375, 4.448792934417724609, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+78, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1103.7276611328125, 2874.849609375, 7.809157371520996093, 3.304334640502929687, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+79, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1030.015625, 2912.1494140625, 3.954517364501953125, 2.781625986099243164, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+80, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1032.3194580078125, 2915.177978515625, 3.935247659683227539, 1.578076362609863281, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+81, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 990.42254638671875, 2904.27294921875, -4.47165489196777343, 1.196795463562011718, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+82, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 949.0399169921875, 2972.342041015625, -13.6139602661132812, 0.322553157806396484, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+83, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1025.75, 2887.884521484375, 1.351847767829895019, 3.360038995742797851, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+84, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1024.3524169921875, 2892.552001953125, 0.766010165214538574, 3.411434173583984375, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+85, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 986.7474365234375, 2889.1767578125, -1.03269028663635253, 4.028651714324951171, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+86, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1053.37109375, 3014.3115234375, -10.3801631927490234, 5.425250530242919921, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+87, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 991.41546630859375, 2902.065673828125, -3.78751969337463378, 1.256146669387817382, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+88, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1115.967041015625, 2949.80908203125, -6.37090015411376953, 0.5180855393409729, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+89, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 979.20489501953125, 2946.421142578125, -8.597930908203125, 2.454389572143554687, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+90, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 938.9820556640625, 2936.572021484375, -16.5490798950195312, 0.412074834108352661, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+91, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 972.76007080078125, 2895.0791015625, -5.01432466506958007, 4.94701242446899414, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+92, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1020.90972900390625, 2849.244873046875, 5.463347911834716796, 2.106653690338134765, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+93, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 912.36981201171875, 2977.4228515625, -18.8523731231689453, 0.232526451349258422, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+94, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 910.98785400390625, 2979.381103515625, -19.2931175231933593, 0.727196395397186279, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+95, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1047.4573974609375, 2944.759765625, 1.209421396255493164, 4.76907968521118164, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+96, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 870.7166748046875, 3020.869873046875, -31.2186241149902343, 0.759161114692687988, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+97, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 979.38946533203125, 3014.989013671875, -15.8197612762451171, 3.363042354583740234, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+98, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 891.34844970703125, 2950.00732421875, -25.0791473388671875, 4.441598892211914062, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+99, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 875.56109619140625, 3019.732177734375, -32.4128303527832031, 2.404566287994384765, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+100, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 876.34423828125, 3019.296142578125, -32.4457969665527343, 0.551974833011627197, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+101, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 943.59552001953125, 2884.419189453125, -4.74745702743530273, 1.241576313972473144, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+102, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 880.92730712890625, 2963.09326171875, -28.9785575866699218, 5.180403709411621093, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+103, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 870.2200927734375, 3019.890869140625, -30.8004894256591796, 2.471730470657348632, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+104, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 870.62542724609375, 2987.74658203125, -34.16192626953125, 0.987667798995971679, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+105, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 889.55035400390625, 2915.895751953125, -19.7112770080566406, 0.253766745328903198, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+106, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 842.03302001953125, 2993.861083984375, -42.4770317077636718, 3.733373403549194335, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+107, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 884.66143798828125, 2921.905517578125, -19.0636634826660156, 0.845570683479309082, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+108, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 918.717041015625, 3086.259521484375, -35.1316604614257812, 5.663859844207763671, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+109, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 919.04864501953125, 3013.45751953125, -18.1423625946044921, 5.058668136596679687, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+110, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 954.638916015625, 2860.4306640625, 4.474199771881103515, 0.770967543125152587, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+111, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 993.3038330078125, 2846.33154296875, 5.44369363784790039, 1.326673388481140136, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+112, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 926.109375, 2858.982666015625, 2.89752817153930664, 1.583675384521484375, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+113, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 966.32562255859375, 2965.5625, -14.4508571624755859, 6.030631065368652343, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+114, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 936.86907958984375, 2910.97265625, -15.9944734573364257, 5.095614910125732421, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+115, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 993.77813720703125, 2864.747314453125, 4.179788112640380859, 1.00878298282623291, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+116, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1048.689208984375, 2879.904541015625, 5.193437576293945312, 1.106329798698425292, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+117, 93762, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1800.392333984375, 1569.828125, 87.13105010986328125, 2.69050002098083496, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Legion Devastator (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+118, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 916.03082275390625, 2879.425537109375, -9.61271476745605468, 5.013759613037109375, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+119, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1061.477294921875, 2814.412109375, 9.723883628845214843, 6.007166862487792968, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+120, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 925.71417236328125, 2821.38623046875, 1.238598227500915527, 2.713753223419189453, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+121, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 853.20660400390625, 2881.8984375, -25.1018600463867187, 0.944859564304351806, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+122, 97142, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 859.06427001953125, 2903.25341796875, -24.5148239135742187, 0, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Fel Spreader (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+123, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 858.6103515625, 2818.7646484375, -20.3763809204101562, 5.803838253021240234, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+124, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 851.1632080078125, 3013.608642578125, -36.104522705078125, 5.615149974822998046, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791); -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1

SET @ENTRY := 98484;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 940.4254, `position_y`= 3049.806, `position_z`= -23.27164, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+58;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+58;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+58, @PATH, 1, 3);

SET @ENTRY := 98484;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 982.3958, `position_y`= 3039.756, `position_z`= -13.04378, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+38;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+38;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+38, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+63;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+63, @CGUID+63, 0, 0, 515, 0, 0),
(@CGUID+63, @CGUID+64, 3, 270, 515, 0, 0);

SET @ENTRY := 98486;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 948.7295, `position_y`= 3000.313, `position_z`= -18.79634, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+63;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+63;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+63, @PATH, 1, 3);

SET @ENTRY := 98486;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1042.313, `position_y`= 3086.181, `position_z`= -1.253485, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+24;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+24, @PATH, 1, 3);

SET @ENTRY := 98486;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1002.361, `position_y`= 2997.689, `position_z`= -12.68121, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+12, @PATH, 1, 3);

SET @ENTRY := 98486;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1047.625, `position_y`= 3052.344, `position_z`= -8.690239, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+3, @PATH, 1, 3);

SET @ENTRY := 98484;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1093.79, `position_y`= 3075.638, `position_z`= -10.08114, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+16;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+16, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+45;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+45, @CGUID+45, 0, 0, 515, 0, 0),
(@CGUID+45, @CGUID+7, 3, 90, 515, 0, 0);

SET @ENTRY := 98486;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1207.326, `position_y`= 3135.052, `position_z`= -16.20279, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+45;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+45;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+45, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+81;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+81, @CGUID+81, 0, 0, 515, 0, 0),
(@CGUID+81, @CGUID+87, 3, 90, 515, 0, 0);

SET @ENTRY := 98486;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 999.9393, `position_y`= 2924.895, `position_z`= -7.272597, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+81;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+81;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+81, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+41;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+41, @CGUID+41, 0, 0, 515, 0, 0),
(@CGUID+41, @CGUID+6, 2, 0, 515, 0, 0);

SET @ENTRY := 98483;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1027.365, `position_y`= 3154.499, `position_z`= 9.815045, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+41;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+41;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+41, @PATH, 1, 3, '200372');

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+35;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+35, @CGUID+35, 0, 0, 515, 0, 0),
(@CGUID+35, @CGUID+8, 2, 0, 515, 0, 0);

SET @ENTRY := 98483;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1032.531, `position_y`= 3028.258, `position_z`= -13.05224, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+35;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+35;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+35, @PATH, 1, 3, '200372');

--
SET @CGUID := 6000283;
SET @OGUID := 6000160;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1066.6492919921875, 3119.07373046875, 12.07263755798339843, 2.188734292984008789, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+1, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1025.2117919921875, 3047.118896484375, -3.81276512145996093, 1.52768874168395996, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 977.82550048828125, 3122.361572265625, -28.1074886322021484, 2.283657550811767578, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+3, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1046.0435791015625, 3054.01611328125, -8.53504467010498046, 5.47154998779296875, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+4, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1128.6875, 3100.31591796875, -11.062117576599121, 5.19477701187133789, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+5, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 951.18231201171875, 3023.489501953125, -18.1599159240722656, 0.005821669939905405, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+6, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1004.90863037109375, 3135.66162109375, -2.47397232055664062, 3.546729803085327148, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+7, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1205.601318359375, 3136.126708984375, -15.7742252349853515, 3.373074769973754882, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1025.456298828125, 3033.936279296875, -11.987349510192871, 1.013128519058227539, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+9, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1035.2882080078125, 3105.020751953125, 3.478539466857910156, 1.428012490272521972, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+10, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 969.10443115234375, 3112.936767578125, -33.0618362426757812, 3.809101343154907226, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+11, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1044.923828125, 3138.15576171875, 10.6440582275390625, 4.477831840515136718, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1003.2100830078125, 3026.6259765625, -12.8141345977783203, 1.584265947341918945, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+13, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1043.170166015625, 3123.875, 8.298093795776367187, 1.468935728073120117, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+14, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1153.8038330078125, 3040.2197265625, -14.0022878646850585, 5.458607196807861328, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+15, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1193.8472900390625, 3071.624267578125, -15.3278303146362304, 5.861836910247802734, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+16, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1086.8345947265625, 3073.73974609375, -8.5683145523071289, 0.265823811292648315, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 99656, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1105.4810791015625, 3148.6865234375, 24.10132980346679687, 5.498132705688476562, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+18, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 951.3367919921875, 3030.210205078125, -18.3688526153564453, 0.605075538158416748, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+19, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 961.1875, 3082.1806640625, -23.2998256683349609, 4.437739372253417968, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+20, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1026.54345703125, 3011.51220703125, -3.31593155860900878, 1.91265726089477539, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+21, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 993.935791015625, 3025.263916015625, -11.9025192260742187, 1.285972356796264648, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+22, 99656, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1060.484130859375, 3091.828369140625, -1.2409517765045166, 0.30881771445274353, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1067.685791015625, 3096.278564453125, 3.614101886749267578, 3.515080213546752929, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+24, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1053.673583984375, 3091.6142578125, -0.65945005416870117, 0.327153742313385009, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+25, 99650, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 972.94305419921875, 3153.470947265625, 2.072075843811035156, 5.363000869750976562, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 988.20379638671875, 3006.6826171875, -19.0753650665283203, 2.246147632598876953, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+27, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1166.986572265625, 3078.33251953125, -14.6779890060424804, 5.786333084106445312, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+28, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1117.301025390625, 3213.109130859375, 41.1098480224609375, 1.168951034545898437, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+29, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 946.2274169921875, 3080.921142578125, -30.2619991302490234, 5.1459197998046875, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+30, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1144.1976318359375, 3042.0078125, -15.422682762145996, 4.093502044677734375, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+31, 98497, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1119.2535400390625, 3102.20751953125, -12.1805133819580078, 5.025339126586914062, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+32, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 989.08856201171875, 3061.248291015625, -10.2608261108398437, 0.213856101036071777, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+33, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 988.19598388671875, 3012.00341796875, -17.9232101440429687, 3.784312963485717773, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+34, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1166.84033203125, 3113.950439453125, -7.0181436538696289, 3.30091714859008789, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+35, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1026.646728515625, 3033.972900390625, -11.994028091430664, 5.92498636245727539, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+36, 98497, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 948.484375, 3091.006103515625, -32.4343299865722656, 4.938072681427001953, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+37, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 978.1663818359375, 3121.6025390625, -28.81610107421875, 1.61573183536529541, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+38, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1001.61090087890625, 3061.189453125, -7.78473520278930664, 4.073184013366699218, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1025.8177490234375, 3125.017333984375, 7.813099384307861328, 0.903588175773620605, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+40, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1103.851318359375, 3024.375244140625, -14.4080095291137695, 2.037938833236694335, 120, 6, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1008.1605224609375, 3136.475341796875, -1.57657885551452636, 3.171094179153442382, 120, 0, 0, 1243, 3801, 0, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+42, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1090.3455810546875, 3027.211181640625, -11.9782371520996093, 3.558114290237426757, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+43, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1009.55548095703125, 3100.819580078125, 6.241608142852783203, 0.764264404773712158, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+44, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1065.5694580078125, 3013.974853515625, -10.2582120895385742, 1.294464588165283203, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+45, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1204.6502685546875, 3134.454345703125, -15.5943641662597656, 3.361215591430664062, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1057.921875, 3015.356689453125, -10.3449325561523437, 2.246151685714721679, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+47, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1072.204833984375, 3052.76220703125, -4.22993326187133789, 4.381879329681396484, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+48, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1108.6614990234375, 3088.817626953125, -11.2135467529296875, 4.181923389434814453, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+49, 98497, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1061.8663330078125, 2999.71875, -12.2458448410034179, 1.690015912055969238, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+50, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 983.88116455078125, 3006.846435546875, -19.3192863464355468, 3.724256038665771484, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+51, 98497, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 884.8836669921875, 3048.217041015625, -33.3857803344726562, 0.005021656397730112, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+52, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 962.4600830078125, 3002.79345703125, -18.3468360900878906, 1.406580448150634765, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+53, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 995.32293701171875, 2980.3291015625, -12.0215797424316406, 1.178008794784545898, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+54, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1221.671875, 3138.932373046875, -19.223947525024414, 3.415702104568481445, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+55, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 901.31597900390625, 3041.146728515625, -30.939004898071289, 6.252474784851074218, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+56, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1228.9149169921875, 3169.116455078125, -19.1225948333740234, 4.347538471221923828, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+57, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1224.8646240234375, 3166.150146484375, -18.9106483459472656, 0.002960902405902743, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+58, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 913.671875, 3044.0498046875, -27.088479995727539, 3.053585290908813476, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+59, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 900.6875, 3047.637939453125, -31.0888805389404296, 6.240606307983398437, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+60, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1006.49481201171875, 2980.8125, -11.5502967834472656, 1.863795161247253417, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+61, 98497, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1039.7413330078125, 2896.611083984375, 0.644535064697265625, 2.903236627578735351, 120, 0, 0, 3479, 3801, 0, NULL, NULL, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+62, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1229.41845703125, 3163.512939453125, -19.2121219635009765, 2.108534812927246093, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+63, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 968.219482421875, 2976.8291015625, -15.2141351699829101, 1.693212628364562988, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 966.0560302734375, 2976.622802734375, -15.6480474472045898, 1.862907648086547851, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 99218, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1566.32373046875, 1667.2039794921875, 101.852508544921875, 2.752264976501464843, 120, 0, 0, 5647, 0, 0, NULL, NULL, 50791), -- Legion Devastator Missile (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+66, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1143.6441650390625, 2960.038330078125, -18.10174560546875, 0.291081905364990234, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+67, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1118.183349609375, 2969.067138671875, -14.5146846771240234, 5.72319793701171875, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 99656, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1112.9095458984375, 3080.278076171875, -10.4364538192749023, 4.012024402618408203, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+69, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 991.02423095703125, 3075.5322265625, -4.63933086395263671, 5.559192657470703125, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1062.8411865234375, 2936.14892578125, 2.650860786437988281, 2.319583415985107421, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+71, 99656, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1115.7545166015625, 3016.972900390625, -14.9768457412719726, 1.434663295745849609, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+72, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 983.57989501953125, 2950.270751953125, -9.93819808959960937, 2.608306407928466796, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+73, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1130.820068359375, 2917.84375, -5.16224956512451171, 4.895998001098632812, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+74, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1101.1474609375, 2936.935791015625, 2.962290287017822265, 1.778342843055725097, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+75, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1134.875, 2887.343017578125, 0.518563032150268554, 5.597451210021972656, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+76, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1132.1510009765625, 2885.611083984375, 1.025349855422973632, 5.6083831787109375, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+77, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1005.59027099609375, 2934.513916015625, -9.8221282958984375, 4.448792934417724609, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+78, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1103.7276611328125, 2874.849609375, 7.809157371520996093, 3.304334640502929687, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+79, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1030.015625, 2912.1494140625, 3.954517364501953125, 2.781625986099243164, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+80, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1032.3194580078125, 2915.177978515625, 3.935247659683227539, 1.578076362609863281, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+81, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 990.42254638671875, 2904.27294921875, -4.47165489196777343, 1.196795463562011718, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+82, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 949.0399169921875, 2972.342041015625, -13.6139602661132812, 0.322553157806396484, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+83, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1025.75, 2887.884521484375, 1.351847767829895019, 3.360038995742797851, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+84, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1024.3524169921875, 2892.552001953125, 0.766010165214538574, 3.411434173583984375, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+85, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 986.7474365234375, 2889.1767578125, -1.03269028663635253, 4.028651714324951171, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+86, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1053.37109375, 3014.3115234375, -10.3801631927490234, 5.425250530242919921, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+87, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 991.41546630859375, 2902.065673828125, -3.78751969337463378, 1.256146669387817382, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+88, 99656, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1115.967041015625, 2949.80908203125, -6.37090015411376953, 0.5180855393409729, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+89, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 979.20489501953125, 2946.421142578125, -8.597930908203125, 2.454389572143554687, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+90, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 938.9820556640625, 2936.572021484375, -16.5490798950195312, 0.412074834108352661, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+91, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 972.76007080078125, 2895.0791015625, -5.01432466506958007, 4.94701242446899414, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+92, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1020.90972900390625, 2849.244873046875, 5.463347911834716796, 2.106653690338134765, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+93, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 912.36981201171875, 2977.4228515625, -18.8523731231689453, 0.232526451349258422, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+94, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 910.98785400390625, 2979.381103515625, -19.2931175231933593, 0.727196395397186279, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+95, 99656, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1047.4573974609375, 2944.759765625, 1.209421396255493164, 4.76907968521118164, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+96, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 870.7166748046875, 3020.869873046875, -31.2186241149902343, 0.759161114692687988, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+97, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 979.38946533203125, 3014.989013671875, -15.8197612762451171, 3.363042354583740234, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+98, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 891.34844970703125, 2950.00732421875, -25.0791473388671875, 4.441598892211914062, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+99, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 875.56109619140625, 3019.732177734375, -32.4128303527832031, 2.404566287994384765, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+100, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 876.34423828125, 3019.296142578125, -32.4457969665527343, 0.551974833011627197, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+101, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 943.59552001953125, 2884.419189453125, -4.74745702743530273, 1.241576313972473144, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+102, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 880.92730712890625, 2963.09326171875, -28.9785575866699218, 5.180403709411621093, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+103, 98483, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 870.2200927734375, 3019.890869140625, -30.8004894256591796, 2.471730470657348632, 120, 6, 0, 1243, 3801, 1, NULL, NULL, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+104, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 870.62542724609375, 2987.74658203125, -34.16192626953125, 0.987667798995971679, 120, 8, 0, 3106, 0, 1, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+105, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 889.55035400390625, 2915.895751953125, -19.7112770080566406, 0.253766745328903198, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+106, 98482, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 842.03302001953125, 2993.861083984375, -42.4770317077636718, 3.733373403549194335, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+107, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 884.66143798828125, 2921.905517578125, -19.0636634826660156, 0.845570683479309082, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+108, 99650, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 918.717041015625, 3086.259521484375, -35.1316604614257812, 5.663859844207763671, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+109, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 919.04864501953125, 3013.45751953125, -18.1423625946044921, 5.058668136596679687, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+110, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 954.638916015625, 2860.4306640625, 4.474199771881103515, 0.770967543125152587, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+111, 98484, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 993.3038330078125, 2846.33154296875, 5.44369363784790039, 1.326673388481140136, 120, 0, 0, 4348, 0, 0, NULL, NULL, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+112, 98486, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 926.109375, 2858.982666015625, 2.89752817153930664, 1.583675384521484375, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+113, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 966.32562255859375, 2965.5625, -14.4508571624755859, 6.030631065368652343, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+114, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 936.86907958984375, 2910.97265625, -15.9944734573364257, 5.095614910125732421, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+115, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 993.77813720703125, 2864.747314453125, 4.179788112640380859, 1.00878298282623291, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+116, 99656, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1048.689208984375, 2879.904541015625, 5.193437576293945312, 1.106329798698425292, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+117, 93762, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1800.392333984375, 1569.828125, 87.13105010986328125, 2.69050002098083496, 120, 0, 0, 3106, 0, 0, NULL, NULL, 50791), -- Legion Devastator (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+118, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 916.03082275390625, 2879.425537109375, -9.61271476745605468, 5.013759613037109375, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+119, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 1061.477294921875, 2814.412109375, 9.723883628845214843, 6.007166862487792968, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+120, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 925.71417236328125, 2821.38623046875, 1.238598227500915527, 2.713753223419189453, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+121, 94655, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 853.20660400390625, 2881.8984375, -25.1018600463867187, 0.944859564304351806, 120, 10, 0, 1129, 0, 1, NULL, NULL, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+122, 99650, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 858.6103515625, 2818.7646484375, -20.3763809204101562, 5.803838253021240234, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+123, 99650, 1481, 7705, 7741, '0', 5310, 0, 0, 0, 851.1632080078125, 3013.608642578125, -36.104522705078125, 5.615149974822998046, 120, 10, 0, 5, 0, 1, NULL, NULL, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+124, 99919, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1011.576171875, 3054.7080078125, -7.65282440185546875, 0.836672544479370117, 120, 0, 0, 27954, 0, 0, NULL, NULL, 50791), -- Sevis Brightflame (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+125, 98458, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1050.2257080078125, 3033.021728515625, -9.85487174987792968, 3.367311477661132812, 120, 0, 0, 34166, 0, 0, NULL, NULL, 50791), -- Jace Darkweaver (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+126, 98459, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 931.69964599609375, 3042.0703125, -23.5038280487060546, 1.900296926498413085, 120, 0, 0, 31060, 0, 0, NULL, NULL, 50791), -- Kayn Sunfury (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+127, 98460, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 987.90972900390625, 2999.62060546875, -17.0935325622558593, 0.836672544479370117, 120, 0, 0, 29507, 0, 0, NULL, NULL, 50791), -- Kor'vas Bloodthorn (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+128, 98456, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 915.560791015625, 2954.718017578125, -20.42730712890625, 4.536273002624511718, 120, 0, 0, 31060, 0, 0, NULL, NULL, 50791), -- Allari the Souleater (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement)
(@CGUID+129, 98457, 1481, 7705, 7741, '0', 5310, 0, 0, 1, 1012.5101318359375, 2902.54296875, -2.32935714721679687, 2.613467693328857421, 120, 0, 0, 31060, 0, 0, NULL, NULL, 50791); -- Cyana Nightglaive (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+124, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Sevis Brightflame - 222589 - Glaive Anim Replacement
(@CGUID+125, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Jace Darkweaver - 222589 - Glaive Anim Replacement
(@CGUID+126, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Kayn Sunfury - 222589 - Glaive Anim Replacement
(@CGUID+127, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Kor'vas Bloodthorn - 222589 - Glaive Anim Replacement
(@CGUID+128, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'), -- Allari the Souleater - 222589 - Glaive Anim Replacement
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589'); -- Cyana Nightglaive - 222589 - Glaive Anim Replacement

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 250560, 1481, 7705, 7741, '0', 5310, 0, 1002.6995849609375, 2955.8125, -10.5557174682617187, 1.554809927940368652, 0, 0, 0.701432228088378906, 0.712736189365386962, 120, 255, 1, 50791), -- Legion Banner (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@OGUID+1, 259043, 1481, 7705, 7741, '0', 5310, 0, 1002.6995849609375, 2955.8125, -10.5557174682617187, 1.554809927940368652, 0, 0, 0.701432228088378906, 0.712736189365386962, 120, 255, 1, 50791), -- Legion Banner 02 (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@OGUID+2, 259043, 1481, 7705, 7741, '0', 0, 0, 1002.6995849609375, 2955.809814453125, -10.5557003021240234, 1.554809927940368652, 0, 0, 0.701432228088378906, 0.712736189365386962, 120, 255, 1, 50791), -- Legion Banner 02 (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@OGUID+3, 250560, 1481, 7705, 7741, '0', 0, 0, 1002.6995849609375, 2955.809814453125, -10.5557003021240234, 1.554809927940368652, 0, 0, 0.701432228088378906, 0.712736189365386962, 120, 255, 1, 50791); -- Legion Banner (Area: Despair Ridge - Difficulty: 0) CreateObject1

SET @ENTRY := 98484;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 940.4254, `position_y`= 3049.806, `position_z`= -23.27164, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+58;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+58;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+58, @PATH, 1, 3);

SET @ENTRY := 98484;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 982.3958, `position_y`= 3039.756, `position_z`= -13.04378, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+38;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+38;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+38, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+63;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+63, @CGUID+63, 0, 0, 515, 0, 0),
(@CGUID+63, @CGUID+64, 3, 270, 515, 0, 0);

SET @ENTRY := 98486;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 948.7295, `position_y`= 3000.313, `position_z`= -18.79634, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+63;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+63;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+63, @PATH, 1, 3);

SET @ENTRY := 98486;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1042.313, `position_y`= 3086.181, `position_z`= -1.253485, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+24;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+24, @PATH, 1, 3);

SET @ENTRY := 98486;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1002.361, `position_y`= 2997.689, `position_z`= -12.68121, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+12, @PATH, 1, 3);

SET @ENTRY := 98486;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1047.625, `position_y`= 3052.344, `position_z`= -8.690239, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+3, @PATH, 1, 3);

SET @ENTRY := 98484;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1093.79, `position_y`= 3075.638, `position_z`= -10.08114, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+16;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+16, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+45;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+45, @CGUID+45, 0, 0, 515, 0, 0),
(@CGUID+45, @CGUID+7, 3, 90, 515, 0, 0);

SET @ENTRY := 98486;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1207.326, `position_y`= 3135.052, `position_z`= -16.20279, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+45;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+45;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+45, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+81;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+81, @CGUID+81, 0, 0, 515, 0, 0),
(@CGUID+81, @CGUID+87, 3, 90, 515, 0, 0);

SET @ENTRY := 98486;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 999.9393, `position_y`= 2924.895, `position_z`= -7.272597, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+81;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+81;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+81, @PATH, 1, 3);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+41;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+41, @CGUID+41, 0, 0, 515, 0, 0),
(@CGUID+41, @CGUID+6, 2, 0, 515, 0, 0);

SET @ENTRY := 98483;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1027.365, `position_y`= 3154.499, `position_z`= 9.815045, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+41;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+41;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+41, @PATH, 1, 3, '200372');

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+35;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+35, @CGUID+35, 0, 0, 515, 0, 0),
(@CGUID+35, @CGUID+8, 2, 0, 515, 0, 0);

SET @ENTRY := 98483;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 1032.531, `position_y`= 3028.258, `position_z`= -13.05224, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+35;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+35;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+35, @PATH, 1, 3, '200372');

--
SET @CGUID := 6000413;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+133;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 97712, 1481, 7705, 7705, '0', 0, 0, 0, 1, 1221.671875, 3138.932373046875, -19.223947525024414, 3.415702104568481445, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+1, 94655, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1166.0989990234375, 3227.25244140625, 56.4152069091796875, 3.331212282180786132, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+2, 97594, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1224.8646240234375, 3166.150146484375, -18.9106483459472656, 0.002960902405902743, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+3, 97594, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1229.41845703125, 3163.512939453125, -19.2121219635009765, 2.108534812927246093, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+4, 99650, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1115.677001953125, 3280.978271484375, 59.1773223876953125, 1.288089752197265625, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+5, 97594, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1228.9149169921875, 3169.116455078125, -19.1225948333740234, 4.347538471221923828, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+6, 99656, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1115.3895263671875, 3217.22412109375, 42.9205780029296875, 4.694036006927490234, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Red Broodling (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+7, 94655, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1115.3411865234375, 3147.675048828125, 14.1425933837890625, 2.014408826828002929, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+8, 99656, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1170.415771484375, 3296.687255859375, 68.05810546875, 6.06864786148071289, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Red Broodling (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1
(@CGUID+9, 97712, 1481, 7705, 7705, '0', 0, 0, 0, 1, 1166.84033203125, 3113.950439453125, -7.0181436538696289, 3.30091714859008789, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+10, 98618, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1046.3680419921875, 3178.25, 15.88236141204833984, 5.15083169937133789, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+11, 97594, 1481, 7705, 7705, '0', 0, 0, 0, 0, 1152.732666015625, 3118.33935546875, -10.388401985168457, 0.901951909065246582, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+12, 97712, 1481, 7705, 7705, '0', 0, 0, 0, 1, 1154.2535400390625, 3116.17626953125, -10.388401985168457, 3.932556867599487304, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Mardum, the Shattered Abyss - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+13, 98621, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1119.6632080078125, 3101.561767578125, -11.3396015167236328, 5.025339126586914062, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+14, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1066.6492919921875, 3119.07373046875, 12.07263755798339843, 2.188734292984008789, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+15, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1128.6875, 3100.31591796875, -11.062117576599121, 5.19477701187133789, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+16, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1043.170166015625, 3123.875, 8.298093795776367187, 1.468935728073120117, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+17, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1025.8177490234375, 3125.017333984375, 7.813099384307861328, 0.903588175773620605, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+18, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1057.7432861328125, 3090.920654296875, -1.02985572814941406, 0.960310399532318115, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1067.685791015625, 3096.278564453125, 3.614101886749267578, 3.515080213546752929, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+20, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1108.6614990234375, 3088.817626953125, -11.2135467529296875, 4.181923389434814453, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+21, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1043.60546875, 3132.6533203125, 7.61134195327758789, 4.352017879486083984, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1035.2882080078125, 3105.020751953125, 3.478539466857910156, 1.428012490272521972, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+23, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1009.55548095703125, 3100.819580078125, 6.241608142852783203, 0.764264404773712158, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+24, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 981.144775390625, 3147.36279296875, 3.495872020721435546, 4.543546199798583984, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 975.328125, 3121.849853515625, -29.471109390258789, 0.222583800554275512, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+26, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 993.0069580078125, 3063.32373046875, -8.86649322509765625, 3.610594511032104492, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+27, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1106.8382568359375, 3078.257080078125, -9.88942813873291015, 3.062952995300292968, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+28, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1025.2117919921875, 3047.118896484375, -3.81276512145996093, 1.52768874168395996, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+29, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1072.204833984375, 3052.76220703125, -4.22993326187133789, 4.381879329681396484, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+30, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1075.0521240234375, 3073.4853515625, -6.13512516021728515, 2.965314865112304687, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+31, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 979.46356201171875, 3118.71435546875, -30.2013072967529296, 0.222583800554275512, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+32, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 989.08856201171875, 3061.248291015625, -10.2608261108398437, 0.213856101036071777, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+33, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 976.52606201171875, 3120.7353515625, -30.291229248046875, 0.222583800554275512, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+34, 99656, 1481, 7705, 7741, '0', 0, 0, 0, 0, 987.351806640625, 3067.897705078125, -9.95508289337158203, 4.83177947998046875, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+35, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 961.1875, 3082.1806640625, -23.2998256683349609, 4.437739372253417968, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+36, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 946.2274169921875, 3080.921142578125, -30.2619991302490234, 5.1459197998046875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+37, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1013.83331298828125, 3029.49560546875, -13.7160549163818359, 5.15083169937133789, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+38, 98621, 1481, 7705, 7741, '0', 0, 0, 0, 0, 947.34893798828125, 3090.786376953125, -31.569915771484375, 5.025339126586914062, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+39, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1003.24481201171875, 3026.689208984375, -12.7263870239257812, 1.525061845779418945, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+40, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1062.4862060546875, 3023.69482421875, -10.080545425415039, 2.483144521713256835, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1026.54345703125, 3011.51220703125, -3.31593155860900878, 1.91265726089477539, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+42, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 993.935791015625, 3025.263916015625, -11.9025192260742187, 1.285972356796264648, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+43, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1065.5694580078125, 3013.974853515625, -10.2582120895385742, 1.294464588165283203, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+44, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1057.921875, 3015.356689453125, -10.3449325561523437, 2.246151685714721679, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+45, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1089.68408203125, 3026.91845703125, -11.8407707214355468, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+46, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1061.2725830078125, 3020.553955078125, -10.0429553985595703, 4.737981319427490234, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+47, 98621, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1063.001708984375, 3002.572998046875, -12.1196117401123046, 1.690015912055969238, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+48, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 985.3975830078125, 3008.28466796875, -19.5347213745117187, 0.819124400615692138, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+49, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1143.404541015625, 3042.46435546875, -15.4612960815429687, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+50, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 988.9617919921875, 3008.260498046875, -19.6527767181396484, 0.819124400615692138, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+51, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 967.8055419921875, 3030.088623046875, -15.5543336868286132, 3.790118694305419921, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+52, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1118.1671142578125, 3014.9541015625, -15.9302120208740234, 0.314649730920791625, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 983.77606201171875, 3008.53564453125, -19.4045143127441406, 0.819124400615692138, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+54, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1107.625, 3011.35498046875, -14.3009405136108398, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+55, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1153.8038330078125, 3040.2197265625, -14.0022878646850585, 5.458607196807861328, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+56, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1165.8194580078125, 3074.470458984375, -14.3558731079101562, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+57, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1116.625, 2970.04248046875, -13.8700857162475585, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+58, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1193.8472900390625, 3071.624267578125, -15.3278303146362304, 5.861836910247802734, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+59, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1143.6441650390625, 2960.038330078125, -18.10174560546875, 0.291081905364990234, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+60, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1057.6417236328125, 2942.308837890625, 2.244654178619384765, 1.552696824073791503, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+61, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1115.967041015625, 2949.80908203125, -6.37090015411376953, 5.471972465515136718, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+62, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1101.7447509765625, 2934.09716796875, 2.397267580032348632, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+63, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1064.87158203125, 2933.96533203125, 3.140287160873413085, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+64, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1006.49481201171875, 2980.8125, -11.5502967834472656, 1.863795161247253417, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+65, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 973.9580078125, 3014.0625, -16.569488525390625, 3.768524169921875, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+66, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 995.32293701171875, 2980.3291015625, -12.0215797424316406, 1.178008794784545898, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+67, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 951.18231201171875, 3023.489501953125, -18.1599159240722656, 0.005821669939905405, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+68, 101704, 1481, 7705, 7741, '0', 0, 0, 0, 0, 849.04339599609375, 3024.181396484375, -34.50360107421875, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Empowered Fel Crystal (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+69, 99656, 1481, 7705, 7741, '0', 0, 0, 0, 0, 987.5, 2962.253173828125, -10.7732677459716796, 1.570796370506286621, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 951.3367919921875, 3030.210205078125, -18.3688526153564453, 0.605075538158416748, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+71, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 962.4600830078125, 3002.79345703125, -18.3468360900878906, 1.406580448150634765, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+72, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 919.205810546875, 3087.196533203125, -33.0394706726074218, 1.089683175086975097, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+73, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 910.609375, 3044.271728515625, -30.3108558654785156, 3.048588752746582031, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+74, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 916.28094482421875, 3015.234619140625, -16.4158802032470703, 0.272933453321456909, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+75, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 901.31597900390625, 3041.146728515625, -30.939004898071289, 6.252474784851074218, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+76, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 949.0399169921875, 2972.342041015625, -13.6139602661132812, 1.622772693634033203, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+77, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 900.6875, 3047.637939453125, -31.0888805389404296, 6.240606307983398437, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+78, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 910.98785400390625, 2979.381103515625, -19.2931175231933593, 0.727196395397186279, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+79, 98621, 1481, 7705, 7741, '0', 0, 0, 0, 0, 887.68231201171875, 3043.114501953125, -33.1467208862304687, 0.092288121581077575, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+80, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 932.6075439453125, 2962.62548828125, -19.626657485961914, 4.612861156463623046, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+81, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 912.36981201171875, 2977.4228515625, -18.8523731231689453, 0.232526451349258422, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+82, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 872.43402099609375, 3018.137939453125, -29.9432640075683593, 0.819124400615692138, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+83, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 874.0555419921875, 3017.88720703125, -30.461496353149414, 0.819124400615692138, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+84, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 877.61981201171875, 3017.86279296875, -32.1287155151367187, 0.819124400615692138, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+85, 98618, 1481, 7705, 7741, '0', 0, 0, 0, 0, 868.74481201171875, 3018.999267578125, -30.2569446563720703, 0.819124400615692138, 120, 0, 0, 1243, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+86, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 869.0225830078125, 2985.31689453125, -34.1116371154785156, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+87, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 866.18707275390625, 3004.581298828125, -32.7259063720703125, 5.739498615264892578, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+88, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 850.71337890625, 3076.230712890625, -31.2867183685302734, 4.527820587158203125, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+89, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 929.25518798828125, 2949.202392578125, -19.1292457580566406, 5.853973388671875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+90, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 928.42535400390625, 2951.302978515625, -19.367462158203125, 5.853973388671875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+91, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 892.14410400390625, 2952.875, -25.3021430969238281, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+92, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 879.58856201171875, 2965.741455078125, -29.3790454864501953, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+93, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 842.03302001953125, 2993.861083984375, -42.4770317077636718, 3.733373403549194335, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+94, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 936.263916015625, 2935.3837890625, -16.7708683013916015, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+95, 101704, 1481, 7705, 7741, '0', 0, 0, 0, 0, 930.13543701171875, 2832.151123046875, 1.374376535415649414, 1.211155056953430175, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Empowered Fel Crystal (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+96, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 884.66143798828125, 2921.905517578125, -19.0636634826660156, 0.845570683479309082, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+97, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 889.55035400390625, 2915.895751953125, -19.7112770080566406, 0.253766745328903198, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+98, 97142, 1481, 7705, 7741, '0', 0, 0, 0, 0, 859.046875, 2903.330810546875, -24.5017356872558593, 0, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Fel Spreader (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+99, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 983.57989501953125, 2950.270751953125, -9.93819808959960937, 2.608306407928466796, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+100, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 979.20489501953125, 2946.421142578125, -8.597930908203125, 2.454389572143554687, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+101, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 914.5328369140625, 2880.2861328125, -11.4270286560058593, 3.932468891143798828, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+102, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 967.6475830078125, 2923.290771484375, -10.5049819946289062, 3.71207737922668457, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+103, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 943.59552001953125, 2884.419189453125, -4.74745702743530273, 1.241576313972473144, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+104, 101704, 1481, 7705, 7741, '0', 0, 0, 0, 0, 851.63018798828125, 2755.415771484375, -24.5067634582519531, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Empowered Fel Crystal (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+105, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 972.22052001953125, 2897.3525390625, -5.58287763595581054, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+106, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 855.88751220703125, 2867.5009765625, -26.6225013732910156, 3.108369350433349609, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+107, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 926.109375, 2858.982666015625, 2.89752817153930664, 1.583675384521484375, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+108, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 954.638916015625, 2860.4306640625, 4.474199771881103515, 0.770967543125152587, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+109, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 978.1083984375, 2883.923095703125, -1.22037875652313232, 6.264632701873779296, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+110, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 928.001953125, 2819.959228515625, 0.890935182571411132, 5.580064773559570312, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+111, 99656, 1481, 7705, 7741, '0', 0, 0, 0, 0, 842.7880859375, 2820.59912109375, -25.432779312133789, 0.082708753645420074, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+112, 94655, 1481, 7705, 7741, '0', 0, 0, 0, 0, 777.6591796875, 2817.2060546875, -34.5493698120117187, 3.527536392211914062, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+113, 98622, 1481, 7705, 7741, '0', 0, 0, 0, 1, 999.22052001953125, 2867.345458984375, 4.241876602172851562, 2.31695866584777832, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+114, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1025.75, 2887.884521484375, 1.351847767829895019, 3.360038995742797851, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+115, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1024.3524169921875, 2892.552001953125, 0.766010165214538574, 3.411434173583984375, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+116, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1005.59027099609375, 2934.513916015625, -9.8221282958984375, 4.448792934417724609, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+117, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1000.25177001953125, 2930.850830078125, -8.583740234375, 3.925262928009033203, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+118, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1003.27777099609375, 2930.6025390625, -8.6909494400024414, 1.06001746654510498, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+119, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 988.60589599609375, 2891.45654296875, -1.26698231697082519, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+120, 99650, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1050.4710693359375, 2878.7060546875, 5.047461509704589843, 2.549515485763549804, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+121, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1032.3194580078125, 2915.177978515625, 3.935247659683227539, 1.578076362609863281, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+122, 97712, 1481, 7705, 7741, '0', 0, 0, 0, 1, 1030.015625, 2912.1494140625, 3.954517364501953125, 2.781625986099243164, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+123, 98621, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1039.43408203125, 2896.639892578125, 0.486016333103179931, 2.903236627578735351, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 51130), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+124, 99656, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1068.0283203125, 2807.62890625, 8.985733985900878906, 1.849577188491821289, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+125, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1106.5711669921875, 2875.31591796875, 7.06386566162109375, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+126, 99656, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1123.0260009765625, 2871.66845703125, 2.39819502830505371, 2.441227912902832031, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51130), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+127, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1132.1510009765625, 2885.611083984375, 1.025349855422973632, 5.6083831787109375, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+128, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1134.875, 2887.343017578125, 0.518563032150268554, 5.597451210021972656, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+129, 97594, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1130.2760009765625, 2920.771728515625, -5.28417682647705078, 0.646911680698394775, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable; Immune))
(@CGUID+130, 101748, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1059.29345703125, 2999.75, -12.1200790405273437, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Fel Geyser (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+131, 101748, 1481, 7705, 7741, '0', 0, 0, 0, 0, 984.61114501953125, 3007.607666015625, -18.3160591125488281, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Fel Geyser (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+132, 101748, 1481, 7705, 7741, '0', 0, 0, 0, 0, 882.65277099609375, 3025.2265625, -32.4641609191894531, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130), -- Fel Geyser (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+133, 101748, 1481, 7705, 7741, '0', 0, 0, 0, 0, 1067.9114990234375, 2888.203125, 1.419333577156066894, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51130); -- Fel Geyser (Area: Despair Ridge - Difficulty: 0) CreateObject1

--
SET @CGUID := 6000547;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 98354, 1481, 7705, 7741, '0', 5305, 0, 0, 1, 1005.67022705078125, 2958.5, -10.4730129241943359, 4.753751754760742187, 120, 0, 0, 29507, 0, 0, NULL, NULL, NULL, NULL, 51237), -- Kor'vas Bloodthorn (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+1, 98229, 1481, 7705, 7741, '0', 5305, 0, 0, 1, 998.9774169921875, 2958.63720703125, -10.4732141494750976, 4.743113517761230468, 120, 0, 0, 31060, 0, 0, NULL, NULL, NULL, NULL, 51237); -- Kayn Sunfury (Area: Despair Ridge - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Kor'vas Bloodthorn
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Kayn Sunfury

--
SET @CGUID := 6000549;
SET @OGUID := 6000164;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 100161, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1514.8004150390625, 2090.989501953125, 242.975738525390625, 2.505118370056152343, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Legion Devastator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+1, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 686.1805419921875, 2548.427978515625, -75.7154006958007812, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+2, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 869.2569580078125, 2578.997314453125, -39.2085800170898437, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+3, 93762, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1800.392333984375, 1569.828125, 87.13105010986328125, 2.614033699035644531, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Legion Devastator (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 703.1475830078125, 2641.513916015625, -71.26806640625, 3.101679325103759765, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+5, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 724.2181396484375, 2626.51123046875, -64.5419769287109375, 2.065718650817871093, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1111.2742919921875, 2680.05908203125, -85.8960113525390625, 4.677201747894287109, 120, 8, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+7, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 726.86260986328125, 2684.57275390625, -56.918060302734375, 3.641484975814819335, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+8, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 676.310791015625, 2533.799560546875, -79.9267730712890625, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+9, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 774.984375, 2541.229248046875, -71.0860824584960937, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+10, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 721.68402099609375, 2602.260498046875, -67.5101318359375, 1.16307222843170166, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+11, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 851.63018798828125, 2755.415771484375, -24.5067634582519531, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+12, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 778.890625, 2570.184814453125, -70.8311691284179687, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+13, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 728.392333984375, 2565.970458984375, -71.2908706665039062, 0.339671969413757324, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 776.12847900390625, 2573.580810546875, -70.8311920166015625, 3.08228611946105957, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+15, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 751.09552001953125, 2570.650146484375, -70.6278839111328125, 5.452545642852783203, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+16, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 743.3955078125, 2542.026611328125, -68.9724655151367187, 0.526438891887664794, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+17, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 720.5509033203125, 2559.158447265625, -69.2248077392578125, 1.717803120613098144, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+18, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 608.8992919921875, 2483.157958984375, -79.7069854736328125, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+19, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 720.59722900390625, 2550.366455078125, -69.839874267578125, 1.352822542190551757, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+20, 97142, 1481, 7705, 7740, '0', 0, 0, 0, 0, 812.545166015625, 2558.103271484375, -50.187835693359375, 0, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Spreader (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+21, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 727.734375, 2504.7373046875, -66.598052978515625, 5.820758342742919921, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+22, 96400, 1481, 7705, 7740, '0', 0, 0, 0, 1, 845.71875, 2560.5009765625, -55.896575927734375, 4.524747848510742187, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Mo'arg Brute (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+23, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 691.3992919921875, 2540.887939453125, -77.6073684692382812, 5.567086696624755859, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+24, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 808.70831298828125, 2442.382080078125, -62.2083282470703125, 3.509678840637207031, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+25, 99351, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1524.5833740234375, 1248.4757080078125, 78.3298492431640625, 0.096725940704345703, 120, 0, 0, 5647, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Legion Devastator Missile (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+26, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 811.607666015625, 2522.239501953125, -55.1407089233398437, 0.037979871034622192, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+27, 94704, 1481, 7705, 7740, '0', 0, 0, 0, 1, 818.98614501953125, 2519.772705078125, -57.7863235473632812, 5.71709442138671875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+28, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 720.01739501953125, 2564.593017578125, -68.738922119140625, 4.81127786636352539, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+29, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 666.2257080078125, 2448.654541015625, -74.3717727661132812, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+30, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 724.23614501953125, 2555.50341796875, -69.9330291748046875, 5.370468616485595703, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+31, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 813.49481201171875, 2511.4697265625, -57.0398368835449218, 0.899337232112884521, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 728.56597900390625, 2549.903564453125, -68.46051025390625, 2.323580026626586914, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+33, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 713.828125, 2559.068603515625, -68.923004150390625, 3.190244197845458984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+34, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 722.65106201171875, 2557.651123046875, -69.5788345336914062, 4.074540138244628906, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+35, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 792.7734375, 2548.352783203125, -70.14190673828125, 6.135212898254394531, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 818.01910400390625, 2449.303955078125, -60.3062362670898437, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+37, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 825.826416015625, 2515.428955078125, -60.3531723022460937, 2.38849496841430664, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+38, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 715.80035400390625, 2553.763916015625, -69.244476318359375, 0.840185761451721191, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+39, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 787.5501708984375, 2540.434326171875, -70.2646331787109375, 1.743853092193603515, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+40, 94377, 1481, 7705, 7740, '0', 4925, 0, 0, 0, 784.80902099609375, 2556.115478515625, -70.4079818725585937, 3.135047674179077148, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Cyana Nightglaive (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+41, 97142, 1481, 7705, 7740, '0', 0, 0, 0, 0, 724.8819580078125, 2508.56689453125, -66.7697906494140625, 0.990418970584869384, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Spreader (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+42, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 900.34552001953125, 2482.36279296875, -66.90435791015625, 3.901273250579833984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+43, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 788.11981201171875, 2521.74658203125, -59.98577880859375, 2.769697189331054687, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+44, 94704, 1481, 7705, 7740, '0', 0, 0, 0, 1, 817.62677001953125, 2518.3818359375, -57.5501632690429687, 2.571193933486938476, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+45, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 754.671875, 2567.015625, -69.21392822265625, 2.003484964370727539, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+46, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 820.87152099609375, 2528.451416015625, -57.4849739074707031, 4.523828506469726562, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+47, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 724.890625, 2511.853271484375, -66.8638076782226562, 1.769054889678955078, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+48, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 758.78125, 2493.59375, -67.560760498046875, 1.705380201339721679, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+49, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 770.4417724609375, 2493.4384765625, -65.6063995361328125, 2.749657154083251953, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 720.8629150390625, 2483.55810546875, -67.2875823974609375, 1.671964406967163085, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+51, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 687.8607177734375, 2496.469482421875, -64.9591140747070312, 5.632848739624023437, 120, 4, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 777.6163330078125, 2488.772705078125, -64.5592880249023437, 5.5130462646484375, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+53, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 671.45660400390625, 2385.857666015625, -73.6159820556640625, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+54, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 748.26043701171875, 2472.088623046875, -62.5730056762695312, 3.935703277587890625, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 93105, 1481, 7705, 7740, '0', 0, 0, 0, 1, 592.58160400390625, 2432.890625, -72.1940078735351562, 3.19030618667602539, 120, 0, 0, 17083, 1534, 0, NULL, NULL, NULL, NULL, 51421), -- Inquisitor Baleful (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 204360 - Cosmetic - Soulgorged)
(@CGUID+56, 94400, 1481, 7705, 7740, '0', 4931, 0, 0, 0, 743.8125, 2467.5625, -62.9644508361816406, 6.068506717681884765, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Belath Dawnblade (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+57, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 699.921875, 2452.022705078125, -67.8506927490234375, 0.245456099510192871, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+58, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 701.40802001953125, 2454.138916015625, -67.4114532470703125, 6.092394351959228515, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+59, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 809.0113525390625, 2456.118408203125, -59.0572853088378906, 2.67821049690246582, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+60, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 805.5399169921875, 2453.045166015625, -58.9226150512695312, 2.841375589370727539, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+61, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 830.32464599609375, 2472.520751953125, -55.8187103271484375, 2.405482053756713867, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+62, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 653.685791015625, 2357.2587890625, -73.8222198486328125, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+63, 97594, 1481, 7705, 7740, '0', 0, 0, 0, 0, 767.99652099609375, 2433.088623046875, -59.9923248291015625, 2.9993743896484375, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+64, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 842.64306640625, 2485.652587890625, -58.456573486328125, 5.412866592407226562, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 97592, 1481, 7705, 7740, '0', 0, 0, 0, 1, 770.890625, 2403.59716796875, -60.2691802978515625, 1.832386016845703125, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+66, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 782.396484375, 2415.90625, -59.0141258239746093, 1.113476037979125976, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+67, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 959.248291015625, 2501.064208984375, -69.051544189453125, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+68, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 867.42706298828125, 2491.817626953125, -58.337371826171875, 1.947656512260437011, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+69, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 712.3975830078125, 2425.47216796875, -66.549835205078125, 0.874155998229980468, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+70, 24021, 1481, 7705, 7740, '0', 0, 0, 0, 0, 774.670166015625, 2388.9462890625, -55.3671035766601562, 1.615941643714904785, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51421), -- ELM General Purpose Bunny (scale x0.01) (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+71, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 850.7530517578125, 2404.57958984375, -52.0062637329101562, 5.874868392944335937, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 747.02740478515625, 2385.611328125, -60.5574264526367187, 2.766393423080444335, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+73, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 711.33160400390625, 2427.62841796875, -67.1776580810546875, 0.779378354549407958, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+74, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 804.15118408203125, 2350.269775390625, -55.878143310546875, 2.533825397491455078, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+75, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 717.2257080078125, 2367.1494140625, -61.5453224182128906, 4.921953201293945312, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+76, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 748.9110107421875, 2350.80859375, -62.1968841552734375, 5.332595348358154296, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+77, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 675.63018798828125, 2454.630126953125, -72.4127273559570312, 0.635104954242706298, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+78, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 700.02642822265625, 2362.47802734375, -66.4420242309570312, 4.207536220550537109, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+79, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 685.33685302734375, 2373.4736328125, -72.5990447998046875, 1.312961578369140625, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+80, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 659.02606201171875, 2475.9462890625, -69.5978775024414062, 3.44576430320739746, 120, 4, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+81, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 671.586669921875, 2383.81103515625, -74.4124679565429687, 3.069761991500854492, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+82, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 673.0185546875, 2376.36376953125, -73.850006103515625, 2.546547889709472656, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+83, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 651.16143798828125, 2416.236083984375, -74.4586334228515625, 4.331264019012451171, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+84, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 680.08502197265625, 2333.3330078125, -65.6512069702148437, 3.141592741012573242, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+85, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 675.77789306640625, 2326.7607421875, -63.2224922180175781, 4.885081768035888671, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+86, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 657.12335205078125, 2332.8291015625, -68.4766082763671875, 5.52264404296875, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+87, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 641.3680419921875, 2357.885498046875, -72.45556640625, 1.653881549835205078, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+88, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 683.1820068359375, 2322.04931640625, -66.9907379150390625, 4.415216922760009765, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+89, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 646.5003662109375, 2327.607666015625, -74.0891952514648437, 1.103636860847473144, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+90, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 649.322998046875, 2485.212646484375, -79.271209716796875, 5.407039165496826171, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 657.01910400390625, 2321.859375, -70.5279388427734375, 5.15083169937133789, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+92, 96400, 1481, 7705, 7740, '0', 0, 0, 0, 1, 622.36456298828125, 2351.5556640625, -72.3597564697265625, 1.20625007152557373, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Mo'arg Brute (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+93, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 587.2965087890625, 2418.483154296875, -70.872833251953125, 4.285918235778808593, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+94, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 595.84027099609375, 2490.647705078125, -73.5553359985351562, 5.15083169937133789, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+95, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 602.310791015625, 2375.43408203125, -71.3903961181640625, 0.46358230710029602, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+96, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 594.9691162109375, 2501.10546875, -84.2200927734375, 1.025486350059509277, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+97, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 580.74444580078125, 2360.3818359375, -72.1720046997070312, 2.612393617630004882, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+98, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 580.3350830078125, 2479.3427734375, -71.425079345703125, 1.350220441818237304, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+99, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 850.4320068359375, 2342.5, -48.8568229675292968, 4.69892740249633789, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+100, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 908.0164794921875, 2479.31787109375, -65.9530258178710937, 0.882936418056488037, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+101, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 920.80206298828125, 2447.88720703125, -69.81585693359375, 5.5778961181640625, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+102, 93230, 1481, 7705, 7740, '0', 4927, 0, 0, 0, 910.38543701171875, 2473.609375, -66.552337646484375, 3.508423566818237304, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Mannethrel Darkstar (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+103, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 900.19964599609375, 2520.203125, -59.2559967041015625, 3.017223119735717773, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+104, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 905.88714599609375, 2467.420166015625, -66.566497802734375, 0.847090303897857666, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+105, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 934.484375, 2541.452392578125, -55.4511299133300781, 6.169494152069091796, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+106, 94704, 1481, 7705, 7740, '0', 0, 0, 0, 1, 945.82293701171875, 2543.856689453125, -53.827239990234375, 3.35019540786743164, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+107, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 933.1475830078125, 2546.431396484375, -57.3190803527832031, 5.860684871673583984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+108, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 895.59552001953125, 2532.501708984375, -58.8618659973144531, 3.754224061965942382, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+109, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 947.54168701171875, 2539.96435546875, -53.701812744140625, 2.714356422424316406, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+110, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 938.890625, 2531.669189453125, -56.1672134399414062, 0.712100505828857421, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+111, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 935.670166015625, 2535.377685546875, -55.98150634765625, 0.369032442569732666, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+112, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 912.632568359375, 2545.12744140625, -59.8159637451171875, 2.462733983993530273, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+113, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 879.1925048828125, 2557.44970703125, -51.7525634765625, 4.235692501068115234, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+114, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 882.07183837890625, 2577.910888671875, -56.2125320434570312, 4.423254013061523437, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+115, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 876.78472900390625, 2576.497314453125, -56.7383956909179687, 1.273130536079406738, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+116, 93117, 1481, 7705, 7740, '0', 4932, 0, 0, 0, 879.36285400390625, 2584.901123046875, -56.706451416015625, 3.992730140686035156, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Izal Whitemoon (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+117, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 997.85418701171875, 2612.895751953125, -60.6213607788085937, 3.093807220458984375, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+118, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 949.125, 2593.734375, -58.4112968444824218, 3.196338653564453125, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+119, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 952.8507080078125, 2588.684814453125, -59.1456108093261718, 3.959872722625732421, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+120, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 980.984375, 2546.1337890625, -46.4631195068359375, 3.774551630020141601, 120, 8, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+121, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1030.361083984375, 2544.067626953125, -39.345489501953125, 0.828900337219238281, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+122, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 982.84893798828125, 2537.442626953125, -44.8555526733398437, 2.840184688568115234, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+123, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 996.00518798828125, 2563.9765625, -41.9175224304199218, 3.720093488693237304, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+124, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 1033.154541015625, 2543.7275390625, -39.0434036254882812, 0.87449049949645996, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+125, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1060.8021240234375, 2554.94970703125, -35.5891799926757812, 2.352654933929443359, 120, 6, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+126, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1062.99658203125, 2661.22998046875, -77.9292984008789062, 0.646911680698394775, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+127, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1042.2413330078125, 2619.85498046875, -69.849822998046875, 0.856969892978668212, 120, 8, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+128, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1024.092041015625, 2633.796875, -62.987518310546875, 1.566091179847717285, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+129, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1060.5416259765625, 2678.30908203125, -75.5465011596679687, 5.168666839599609375, 120, 8, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485); -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+65, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- Felguard Sentry - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 242987, 1481, 7705, 7740, '0', 0, 0, 879.4461669921875, 2584.973876953125, -56.7891921997070312, 3.992181777954101562, 0, 0, -0.91091728210449218, 0.412589073181152343, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+1, 241756, 1481, 7705, 7740, '0', 0, 0, 775.185791015625, 2389.072998046875, -58.26275634765625, 1.698262214660644531, -0.03015041351318359, -0.0547800064086914, 0.748689651489257812, 0.659965097904205322, 120, 255, 1, 51421), -- Legion Gateway Activator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+2, 242990, 1481, 7705, 7740, '0', 0, 0, 910.420166015625, 2473.604248046875, -66.6402816772460937, 3.505491256713867187, 0, 0, -0.98349285125732421, 0.180946916341781616, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+3, 244916, 1481, 7705, 7740, '0', 0, 0, 784.71875, 2556.1728515625, -70.4913177490234375, 3.14776921272277832, 0, 0, -0.99999523162841796, 0.003088161814957857, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+4, 244440, 1481, 7705, 7740, '0', 0, 0, 751.732666015625, 2460.9306640625, -62.3934745788574218, 0.118905484676361083, 0, 0, 0.059417724609375, 0.998233199119567871, 120, 255, 1, 51421), -- Legion Communicator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+5, 242989, 1481, 7705, 7740, '0', 0, 0, 743.80206298828125, 2467.59375, -63.0486335754394531, 6.061135768890380859, 0, 0, -0.11079692840576171, 0.99384307861328125, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+6, 244439, 1481, 7705, 7740, '0', 0, 0, 937.61981201171875, 2835.83154296875, 1.292487740516662597, 1.279170751571655273, 0, 0, 0.59686279296875, 0.802343368530273437, 120, 255, 1, 51421), -- Legion Communicator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+7, 244441, 1481, 7705, 7740, '0', 0, 0, 1246.9132080078125, 2522.4609375, 1.859429240226745605, 3.22068643569946289, 0.08490610122680664, -0.00177192687988281, -0.99562549591064453, 0.038957837969064712, 120, 255, 1, 51421); -- Legion Communicator (Area: Molten Shore - Difficulty: 0) CreateObject1

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+32), -(@CGUID+19), -(@CGUID+38), -(@CGUID+33), -(@CGUID+28), -(@CGUID+31), -(@CGUID+26), -(@CGUID+46), -(@CGUID+37), -(@CGUID+107), -(@CGUID+105), -(@CGUID+111), -(@CGUID+110));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+32), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+19), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+38), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+33), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+28), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+31), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+26), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+46), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+37), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+107), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+105), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+111), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+110), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack');

SET @ENTRY := 95226;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 730.9236, `position_y`= 2635.785, `position_z`= -61.66982, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+15;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+15, @PATH, 1);

SET @ENTRY := 95226;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 718.257, `position_y`= 2523.542, `position_z`= -71.65739, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+16;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+16, @PATH, 1);

SET @ENTRY := 95226;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;

UPDATE `creature` SET `position_x`= 750.0955, `position_y`= 2503.064, `position_z`= -67.21629, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+52;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+52;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+52, @PATH, 1);

SET @ENTRY := 9991400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 137, 25111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays SpellVisual with SpellVisualKitId: 25111, KitType: 0 for 0 ms'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 128, 9256, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 9256'),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 159474, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 159474 on self'),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 191664, 0, 0, 0, 0, 0, 10, @CGUID+70, 24021, 0, 0, 0, 0, 0, 'After 1 seconds - cast: (Enter the Illidari: Shivarra - Soul Missiles 02) - to Entry/Guid'),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 191664, 0, 0, 0, 0, 0, 10, @CGUID+70, 24021, 0, 0, 0, 0, 0, 'After 2 seconds - cast: (Enter the Illidari: Shivarra - Soul Missiles 02) - to Entry/Guid'),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 191664, 0, 0, 0, 0, 0, 10, @CGUID+70, 24021, 0, 0, 0, 0, 0, 'After 1 seconds - cast: (Enter the Illidari: Shivarra - Soul Missiles 02) - to Entry/Guid');

--
SET @CGUID := 6000679;
SET @OGUID := 6000172;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 93759, 1481, 7705, 7740, '0', 5095, 0, 0, 1, 1059.6754150390625, 2576.71533203125, -37.1619338989257812, 0.488393902778625488, 120, 0, 0, 34166, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Jace Darkweaver (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+1, 95049, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1062.0555419921875, 2572.762939453125, -33.839324951171875, 4.638368129730224609, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 195821 - Seat of Command: Jace's Demon Ward Area Trigger)
(@CGUID+2, 95049, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1056.595458984375, 2581.59033203125, -34.9345664978027343, 2.579434394836425781, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 195821 - Seat of Command: Jace's Demon Ward Area Trigger)
(@CGUID+3, 95049, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1067.217041015625, 2581.671875, -33.8557815551757812, 0.874998629093170166, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51536); -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 195821 - Seat of Command: Jace's Demon Ward Area Trigger)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 243059, 1481, 7705, 7740, '0', 0, 0, 1057.0103759765625, 2581.33251953125, -37.8438606262207031, 2.61522531509399414, 0, 0, 0.965566635131835937, 0.260155856609344482, 120, 255, 0, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+1, 243335, 1481, 7705, 7740, '0', 0, 0, 1062.3853759765625, 2578.52783203125, -37.0822486877441406, 5.324192047119140625, -0.01086902618408203, -0.06977558135986328, -0.45883846282958984, 0.885709047317504882, 120, 255, 1, 51536), -- Nether Crucible (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+2, 243059, 1481, 7705, 7740, '0', 0, 0, 1062.078125, 2573.25341796875, -36.7530097961425781, 4.702091217041015625, 0, 0, -0.71073818206787109, 0.703456640243530273, 120, 255, 0, 51536), -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+3, 243059, 1481, 7705, 7740, '0', 0, 0, 1066.875, 2581.322021484375, -36.7869338989257812, 0.751146793365478515, 0, 0, 0.3668060302734375, 0.930297434329986572, 120, 255, 0, 51536); -- Demon Ward (Area: Molten Shore - Difficulty: 0) CreateObject1

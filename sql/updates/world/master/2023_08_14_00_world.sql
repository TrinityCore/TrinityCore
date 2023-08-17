SET @CGUID := 652139;

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+124;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1066.6492919921875, 3119.07373046875, 12.07263755798339843, 2.188734292984008789, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+1, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1025.2117919921875, 3047.118896484375, -3.81276512145996093, 1.52768874168395996, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 977.82550048828125, 3122.361572265625, -28.1074886322021484, 2.283657550811767578, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+3, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1046.0435791015625, 3054.01611328125, -8.53504467010498046, 5.47154998779296875, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+4, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1128.6875, 3100.31591796875, -11.062117576599121, 5.19477701187133789, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+5, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 951.18231201171875, 3023.489501953125, -18.1599159240722656, 0.005821669939905405, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+6, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1004.90863037109375, 3135.66162109375, -2.47397232055664062, 3.546729803085327148, 120, 0, 0, 1243, 3801, 0, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+7, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1205.601318359375, 3136.126708984375, -15.7742252349853515, 3.373074769973754882, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1025.456298828125, 3033.936279296875, -11.987349510192871, 1.013128519058227539, 120, 0, 0, 1243, 3801, 0, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+9, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1035.2882080078125, 3105.020751953125, 3.478539466857910156, 1.428012490272521972, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+10, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 969.10443115234375, 3112.936767578125, -33.0618362426757812, 3.809101343154907226, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+11, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1044.923828125, 3138.15576171875, 10.6440582275390625, 4.477831840515136718, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1003.2100830078125, 3026.6259765625, -12.8141345977783203, 1.584265947341918945, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+13, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1043.170166015625, 3123.875, 8.298093795776367187, 1.468935728073120117, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+14, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1153.8038330078125, 3040.2197265625, -14.0022878646850585, 5.458607196807861328, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+15, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1193.8472900390625, 3071.624267578125, -15.3278303146362304, 5.861836910247802734, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+16, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1086.8345947265625, 3073.73974609375, -8.5683145523071289, 0.265823811292648315, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1105.4810791015625, 3148.6865234375, 24.10132980346679687, 5.498132705688476562, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+18, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 951.3367919921875, 3030.210205078125, -18.3688526153564453, 0.605075538158416748, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+19, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 961.1875, 3082.1806640625, -23.2998256683349609, 4.437739372253417968, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+20, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1026.54345703125, 3011.51220703125, -3.31593155860900878, 1.91265726089477539, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+21, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 993.935791015625, 3025.263916015625, -11.9025192260742187, 1.285972356796264648, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+22, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1060.484130859375, 3091.828369140625, -1.2409517765045166, 0.30881771445274353, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1067.685791015625, 3096.278564453125, 3.614101886749267578, 3.515080213546752929, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+24, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1053.673583984375, 3091.6142578125, -0.65945005416870117, 0.327153742313385009, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+25, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 972.94305419921875, 3153.470947265625, 2.072075843811035156, 5.363000869750976562, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+26, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 988.20379638671875, 3006.6826171875, -19.0753650665283203, 2.246147632598876953, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+27, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1166.986572265625, 3078.33251953125, -14.6779890060424804, 5.786333084106445312, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+28, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1117.301025390625, 3213.109130859375, 41.1098480224609375, 1.168951034545898437, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+29, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 946.2274169921875, 3080.921142578125, -30.2619991302490234, 5.1459197998046875, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+30, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1144.1976318359375, 3042.0078125, -15.422682762145996, 4.093502044677734375, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+31, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1119.2535400390625, 3102.20751953125, -12.1805133819580078, 5.025339126586914062, 120, 0, 0, 3479, 3801, 0, 0, 0, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+32, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 989.08856201171875, 3061.248291015625, -10.2608261108398437, 0.213856101036071777, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+33, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 988.19598388671875, 3012.00341796875, -17.9232101440429687, 3.784312963485717773, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+34, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1166.84033203125, 3113.950439453125, -7.0181436538696289, 3.30091714859008789, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+35, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1026.646728515625, 3033.972900390625, -11.994028091430664, 5.92498636245727539, 120, 0, 0, 1243, 3801, 0, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+36, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 948.484375, 3091.006103515625, -32.4343299865722656, 4.938072681427001953, 120, 0, 0, 3479, 3801, 0, 0, 0, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+37, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 978.1663818359375, 3121.6025390625, -28.81610107421875, 1.61573183536529541, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+38, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1001.61090087890625, 3061.189453125, -7.78473520278930664, 4.073184013366699218, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1025.8177490234375, 3125.017333984375, 7.813099384307861328, 0.903588175773620605, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+40, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1103.851318359375, 3024.375244140625, -14.4080095291137695, 2.037938833236694335, 120, 6, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1008.1605224609375, 3136.475341796875, -1.57657885551452636, 3.171094179153442382, 120, 0, 0, 1243, 3801, 0, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+42, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1090.3455810546875, 3027.211181640625, -11.9782371520996093, 3.558114290237426757, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+43, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1009.55548095703125, 3100.819580078125, 6.241608142852783203, 0.764264404773712158, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+44, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1065.5694580078125, 3013.974853515625, -10.2582120895385742, 1.294464588165283203, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+45, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1204.6502685546875, 3134.454345703125, -15.5943641662597656, 3.361215591430664062, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1057.921875, 3015.356689453125, -10.3449325561523437, 2.246151685714721679, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+47, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1072.204833984375, 3052.76220703125, -4.22993326187133789, 4.381879329681396484, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+48, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1108.6614990234375, 3088.817626953125, -11.2135467529296875, 4.181923389434814453, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+49, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1061.8663330078125, 2999.71875, -12.2458448410034179, 1.690015912055969238, 120, 0, 0, 3479, 3801, 0, 0, 0, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+50, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 983.88116455078125, 3006.846435546875, -19.3192863464355468, 3.724256038665771484, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+51, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 884.8836669921875, 3048.217041015625, -33.3857803344726562, 0.005021656397730112, 120, 0, 0, 3479, 3801, 0, 0, 0, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+52, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 962.4600830078125, 3002.79345703125, -18.3468360900878906, 1.406580448150634765, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+53, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 995.32293701171875, 2980.3291015625, -12.0215797424316406, 1.178008794784545898, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+54, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1221.671875, 3138.932373046875, -19.223947525024414, 3.415702104568481445, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+55, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 901.31597900390625, 3041.146728515625, -30.939004898071289, 6.252474784851074218, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+56, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1228.9149169921875, 3169.116455078125, -19.1225948333740234, 4.347538471221923828, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+57, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1224.8646240234375, 3166.150146484375, -18.9106483459472656, 0.002960902405902743, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+58, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 913.671875, 3044.0498046875, -27.088479995727539, 3.053585290908813476, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+59, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 900.6875, 3047.637939453125, -31.0888805389404296, 6.240606307983398437, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+60, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1006.49481201171875, 2980.8125, -11.5502967834472656, 1.863795161247253417, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+61, 98497, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1039.7413330078125, 2896.611083984375, 0.644535064697265625, 2.903236627578735351, 120, 0, 0, 3479, 3801, 0, 0, 0, 50791), -- Imp Mother (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 188485 - Fel Channelling)
(@CGUID+62, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1229.41845703125, 3163.512939453125, -19.2121219635009765, 2.108534812927246093, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+63, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 968.219482421875, 2976.8291015625, -15.2141351699829101, 1.693212628364562988, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+64, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 966.0560302734375, 2976.622802734375, -15.6480474472045898, 1.862907648086547851, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 99218, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1566.32373046875, 1667.2039794921875, 101.852508544921875, 2.752264976501464843, 120, 0, 0, 5647, 0, 0, 0, 0, 50791), -- Legion Devastator Missile (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+66, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1143.6441650390625, 2960.038330078125, -18.10174560546875, 0.291081905364990234, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+67, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1118.183349609375, 2969.067138671875, -14.5146846771240234, 5.72319793701171875, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1112.9095458984375, 3080.278076171875, -10.4364538192749023, 4.012024402618408203, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+69, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 991.02423095703125, 3075.5322265625, -4.63933086395263671, 5.559192657470703125, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+70, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1062.8411865234375, 2936.14892578125, 2.650860786437988281, 2.319583415985107421, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+71, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1115.7545166015625, 3016.972900390625, -14.9768457412719726, 1.434663295745849609, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+72, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 983.57989501953125, 2950.270751953125, -9.93819808959960937, 2.608306407928466796, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+73, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1130.820068359375, 2917.84375, -5.16224956512451171, 4.895998001098632812, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+74, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1101.1474609375, 2936.935791015625, 2.962290287017822265, 1.778342843055725097, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+75, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1134.875, 2887.343017578125, 0.518563032150268554, 5.597451210021972656, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+76, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1132.1510009765625, 2885.611083984375, 1.025349855422973632, 5.6083831787109375, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+77, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1005.59027099609375, 2934.513916015625, -9.8221282958984375, 4.448792934417724609, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+78, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1103.7276611328125, 2874.849609375, 7.809157371520996093, 3.304334640502929687, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+79, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1030.015625, 2912.1494140625, 3.954517364501953125, 2.781625986099243164, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+80, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1032.3194580078125, 2915.177978515625, 3.935247659683227539, 1.578076362609863281, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+81, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 990.42254638671875, 2904.27294921875, -4.47165489196777343, 1.196795463562011718, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+82, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 949.0399169921875, 2972.342041015625, -13.6139602661132812, 0.322553157806396484, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+83, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1025.75, 2887.884521484375, 1.351847767829895019, 3.360038995742797851, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+84, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1024.3524169921875, 2892.552001953125, 0.766010165214538574, 3.411434173583984375, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+85, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 986.7474365234375, 2889.1767578125, -1.03269028663635253, 4.028651714324951171, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+86, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1053.37109375, 3014.3115234375, -10.3801631927490234, 5.425250530242919921, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+87, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 991.41546630859375, 2902.065673828125, -3.78751969337463378, 1.256146669387817382, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+88, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1115.967041015625, 2949.80908203125, -6.37090015411376953, 0.5180855393409729, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+89, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 979.20489501953125, 2946.421142578125, -8.597930908203125, 2.454389572143554687, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+90, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 938.9820556640625, 2936.572021484375, -16.5490798950195312, 0.412074834108352661, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+91, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 972.76007080078125, 2895.0791015625, -5.01432466506958007, 4.94701242446899414, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+92, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 1020.90972900390625, 2849.244873046875, 5.463347911834716796, 2.106653690338134765, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+93, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 912.36981201171875, 2977.4228515625, -18.8523731231689453, 0.232526451349258422, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+94, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 910.98785400390625, 2979.381103515625, -19.2931175231933593, 0.727196395397186279, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+95, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1047.4573974609375, 2944.759765625, 1.209421396255493164, 4.76907968521118164, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+96, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 870.7166748046875, 3020.869873046875, -31.2186241149902343, 0.759161114692687988, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+97, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 979.38946533203125, 3014.989013671875, -15.8197612762451171, 3.363042354583740234, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+98, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 891.34844970703125, 2950.00732421875, -25.0791473388671875, 4.441598892211914062, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+99, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 875.56109619140625, 3019.732177734375, -32.4128303527832031, 2.404566287994384765, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+100, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 876.34423828125, 3019.296142578125, -32.4457969665527343, 0.551974833011627197, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+101, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 943.59552001953125, 2884.419189453125, -4.74745702743530273, 1.241576313972473144, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+102, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 880.92730712890625, 2963.09326171875, -28.9785575866699218, 5.180403709411621093, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+103, 98483, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 870.2200927734375, 3019.890869140625, -30.8004894256591796, 2.471730470657348632, 120, 6, 0, 1243, 3801, 1, 0, 0, 50791), -- Hellish Imp (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+104, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 870.62542724609375, 2987.74658203125, -34.16192626953125, 0.987667798995971679, 120, 8, 0, 3106, 0, 1, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+105, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 889.55035400390625, 2915.895751953125, -19.7112770080566406, 0.253766745328903198, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+106, 98482, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 842.03302001953125, 2993.861083984375, -42.4770317077636718, 3.733373403549194335, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Foul Felstalker (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+107, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 884.66143798828125, 2921.905517578125, -19.0636634826660156, 0.845570683479309082, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+108, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 918.717041015625, 3086.259521484375, -35.1316604614257812, 5.663859844207763671, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+109, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 919.04864501953125, 3013.45751953125, -18.1423625946044921, 5.058668136596679687, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+110, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 954.638916015625, 2860.4306640625, 4.474199771881103515, 0.770967543125152587, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+111, 98484, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 993.3038330078125, 2846.33154296875, 5.44369363784790039, 1.326673388481140136, 120, 0, 0, 4348, 0, 0, 0, 0, 50791), -- Mo'arg Brute (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+112, 98486, 1481, 7705, 7741, '0', 5311, 0, 0, 1, 926.109375, 2858.982666015625, 2.89752817153930664, 1.583675384521484375, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Wrath Warrior (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+113, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 966.32562255859375, 2965.5625, -14.4508571624755859, 6.030631065368652343, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+114, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 936.86907958984375, 2910.97265625, -15.9944734573364257, 5.095614910125732421, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+115, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 993.77813720703125, 2864.747314453125, 4.179788112640380859, 1.00878298282623291, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+116, 99656, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1048.689208984375, 2879.904541015625, 5.193437576293945312, 1.106329798698425292, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Red Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+117, 93762, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1800.392333984375, 1569.828125, 87.13105010986328125, 2.69050002098083496, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Legion Devastator (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+118, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 916.03082275390625, 2879.425537109375, -9.61271476745605468, 5.013759613037109375, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+119, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 1061.477294921875, 2814.412109375, 9.723883628845214843, 6.007166862487792968, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+120, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 925.71417236328125, 2821.38623046875, 1.238598227500915527, 2.713753223419189453, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+121, 94655, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 853.20660400390625, 2881.8984375, -25.1018600463867187, 0.944859564304351806, 120, 10, 0, 1129, 0, 1, 0, 0, 50791), -- Soul Leech (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+122, 97142, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 859.06427001953125, 2903.25341796875, -24.5148239135742187, 0, 120, 0, 0, 3106, 0, 0, 0, 0, 50791), -- Fel Spreader (Area: Despair Ridge - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+123, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 858.6103515625, 2818.7646484375, -20.3763809204101562, 5.803838253021240234, 120, 10, 0, 5, 0, 1, 0, 0, 50791), -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1
(@CGUID+124, 99650, 1481, 7705, 7741, '0', 5311, 0, 0, 0, 851.1632080078125, 3013.608642578125, -36.104522705078125, 5.615149974822998046, 120, 10, 0, 5, 0, 1, 0, 0, 50791); -- Thornclaw Broodling (Area: Despair Ridge - Difficulty: 0) CreateObject1

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (97142, 98484, 98482, 98483, 98486, 98497);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(97142, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '200681'), -- 97142 (Fel Spreader) - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50]
(98484, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Mo'arg Brute
(98482, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Foul Felstalker
(98483, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '200372'), -- Hellish Imp - 200372 - Hellish
(98486, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Wrath Warrior
(98497, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- Imp Mother

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 98497;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(98497, 0, 0, 1, 1, 0, 0, NULL);

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` = 5311 AND `AreaId` = 7741;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7741, 5311, 'Dispair Ridge Spawns (Quest The Incasion Begins STATE_NONE)');

 -- Imp Mother smart ai
SET @ENTRY := 98497;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 11, 188485, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell  188485 on Self');

-- Waypoints for CGUID+58
SET @PATH := ((@CGUID+58) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 940.4254, 3049.806, -23.27164, NULL, 0),
(@PATH, 1, 947.717, 3057.455, -24.22706, NULL, 0),
(@PATH, 2, 951.6354, 3066.014, -26.52407, NULL, 0),
(@PATH, 3, 951.7761, 3074.648, -28.34278, NULL, 0),
(@PATH, 4, 950.8073, 3079.72, -29.46416, NULL, 13283),
(@PATH, 5, 951.7761, 3074.648, -28.34278, NULL, 0),
(@PATH, 6, 951.6354, 3066.014, -26.52407, NULL, 0),
(@PATH, 7, 947.717, 3057.455, -24.22706, NULL, 0),
(@PATH, 8, 940.4254, 3049.806, -23.27164, NULL, 0),
(@PATH, 9, 935.75, 3046.442, -23.45509, NULL, 0),
(@PATH, 10, 929.8246, 3042.854, -24.00674, NULL, 0),
(@PATH, 11, 921.6406, 3043.346, -25.66765, NULL, 0),
(@PATH, 12, 913.6719, 3044.05, -27.08848, NULL, 13306),
(@PATH, 13, 921.6406, 3043.346, -25.66765, NULL, 0),
(@PATH, 14, 929.8246, 3042.854, -24.00674, NULL, 0),
(@PATH, 15, 935.75, 3046.442, -23.45509, NULL, 0);

UPDATE `creature` SET `position_x`= 940.4254, `position_y`= 3049.806, `position_z`= -23.27164, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+58;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+58;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+58, @PATH, 1, 3);

-- Waypoints for CGUID+38
SET @PATH := ((@CGUID+38) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 982.3958, 3039.756, -13.04378, NULL, 0),
(@PATH, 1, 992.2031, 3048.542, -11.22511, NULL, 0),
(@PATH, 2, 1004.429, 3064.98, -6.665689, NULL, 0),
(@PATH, 3, 1016.563, 3082.635, -2.106032, NULL, 0),
(@PATH, 4, 1022.8, 3090.673, -0.1968752, NULL, 0),
(@PATH, 5, 1025.059, 3097.481, 1.515991, NULL, 0),
(@PATH, 6, 1022.8, 3090.673, -0.1968752, NULL, 0),
(@PATH, 7, 1016.563, 3082.635, -2.106032, NULL, 0),
(@PATH, 8, 1004.429, 3064.98, -6.665689, NULL, 0),
(@PATH, 9, 992.2031, 3048.542, -11.22511, NULL, 0),
(@PATH, 10, 982.3958, 3039.756, -13.04378, NULL, 0),
(@PATH, 11, 967.7535, 3030.117, -15.64392, NULL, 0);

UPDATE `creature` SET `position_x`= 982.3958, `position_y`= 3039.756, `position_z`= -13.04378, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+38;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+38;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+38, @PATH, 1, 3);

-- Waypoints for CGUID+63
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+63;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+63, @CGUID+63, 0, 0, 515, 0, 0),
(@CGUID+63, @CGUID+64, 3, 270, 515, 0, 0);

SET @PATH := ((@CGUID+63) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 948.7295, 3000.313, -18.79634, NULL, 0),
(@PATH, 1, 940.0226, 2999.18, -18.97995, NULL, 0),
(@PATH, 2, 931.6233, 2988.527, -19.35425, NULL, 0),
(@PATH, 3, 926.6511, 2978.193, -19.92125, NULL, 0),
(@PATH, 4, 923.7726, 2966.603, -20.25003, NULL, 0),
(@PATH, 5, 925.0955, 2956.409, -19.95997, NULL, 0),
(@PATH, 6, 928.4473, 2951.435, -19.45864, NULL, 0),
(@PATH, 7, 933.7292, 2946.871, -18.57581, NULL, 0),
(@PATH, 8, 941.2118, 2943.355, -16.99124, NULL, 0),
(@PATH, 9, 950.3646, 2942.653, -15.28169, NULL, 0),
(@PATH, 10, 957.4346, 2946.387, -14.4987, NULL, 0),
(@PATH, 11, 963.408, 2952.542, -13.71672, NULL, 0),
(@PATH, 12, 967.2205, 2959.818, -13.72267, NULL, 0),
(@PATH, 13, 969.0799, 2969.834, -14.34147, NULL, 0),
(@PATH, 14, 967.9531, 2979.025, -15.51998, NULL, 0),
(@PATH, 15, 961.4063, 2985.404, -17.40655, NULL, 0),
(@PATH, 16, 957.0868, 2993.158, -18.28618, NULL, 0);

UPDATE `creature` SET `position_x`= 948.7295, `position_y`= 3000.313, `position_z`= -18.79634, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+63;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+63;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+63, @PATH, 1, 3);

-- Waypoints for CGUID+24
SET @PATH := ((@CGUID+24) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1042.313, 3086.181, -1.253485, NULL, 0),
(@PATH, 1, 1053.521, 3091.563, -0.6553773, NULL, 0),
(@PATH, 2, 1058.967, 3093.411, -0.800682, NULL, 15651),
(@PATH, 3, 1053.521, 3091.563, -0.6553773, NULL, 0),
(@PATH, 4, 1042.313, 3086.181, -1.253485, NULL, 0),
(@PATH, 5, 1031.109, 3081.003, -2.236958, NULL, 0),
(@PATH, 6, 1013.991, 3073.2, -4.254691, NULL, 0),
(@PATH, 7, 1001.052, 3067.207, -6.733655, NULL, 0),
(@PATH, 8, 992.9271, 3063.372, -8.960319, NULL, 18006),
(@PATH, 9, 1001.052, 3067.207, -6.733655, NULL, 0),
(@PATH, 10, 1013.991, 3073.2, -4.254691, NULL, 0),
(@PATH, 11, 1031.109, 3081.003, -2.236958, NULL, 0);

UPDATE `creature` SET `position_x`= 1042.313, `position_y`= 3086.181, `position_z`= -1.253485, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+24;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+24, @PATH, 1, 3);

-- Waypoints for CGUID+12
SET @PATH := ((@CGUID+12) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1002.361, 2997.689, -12.68121, NULL, 0),
(@PATH, 1, 1002.8, 3007.391, -13.32003, NULL, 0),
(@PATH, 2, 1003.299, 3020.098, -13.13114, NULL, 0),
(@PATH, 3, 1003.21, 3026.626, -12.81413, NULL, 12778),
(@PATH, 4, 1003.299, 3020.098, -13.13114, NULL, 0),
(@PATH, 5, 1002.8, 3007.391, -13.32003, NULL, 0),
(@PATH, 6, 1002.361, 2997.689, -12.68121, NULL, 0),
(@PATH, 7, 1001.736, 2985.845, -12.3482, NULL, 18826);

UPDATE `creature` SET `position_x`= 1002.361, `position_y`= 2997.689, `position_z`= -12.68121, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+12, @PATH, 1, 3);

-- Waypoints for CGUID+3
SET @PATH := ((@CGUID+3) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1047.625, 3052.344, -8.690239, NULL, 0),
(@PATH, 1, 1038.04, 3062.451, -6.469887, NULL, 0),
(@PATH, 2, 1024.094, 3065.368, -5.117937, NULL, 0),
(@PATH, 3, 1016.002, 3060.701, -6.443272, NULL, 0),
(@PATH, 4, 1009.052, 3053.022, -8.179962, NULL, 0),
(@PATH, 5, 1003.403, 3043.814, -10.21681, NULL, 0),
(@PATH, 6, 999.1719, 3035.495, -11.87136, NULL, 15332),
(@PATH, 7, 1003.403, 3043.814, -10.21681, NULL, 0),
(@PATH, 8, 1009.052, 3053.022, -8.179962, NULL, 0),
(@PATH, 9, 1016.002, 3060.701, -6.443272, NULL, 0),
(@PATH, 10, 1024.094, 3065.368, -5.117937, NULL, 0),
(@PATH, 11, 1038.04, 3062.451, -6.469887, NULL, 0),
(@PATH, 12, 1047.625, 3052.344, -8.690239, NULL, 0),
(@PATH, 13, 1059.165, 3034.285, -9.872204, NULL, 0),
(@PATH, 14, 1060.984, 3024.898, -10.28156, NULL, 0),
(@PATH, 15, 1061.29, 3020.571, -10.1259, NULL, 12857),
(@PATH, 16, 1059.165, 3034.285, -9.872204, NULL, 0);

UPDATE `creature` SET `position_x`= 1047.625, `position_y`= 3052.344, `position_z`= -8.690239, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+3, @PATH, 1, 3);

-- Waypoints for CGUID+16
SET @PATH := ((@CGUID+16) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1093.79, 3075.638, -10.08114, NULL, 0),
(@PATH, 1, 1083.188, 3072.716, -7.816884, NULL, 0),
(@PATH, 2, 1075.127, 3073.532, -6.225381, NULL, 0),
(@PATH, 3, 1083.088, 3072.72, -7.816884, NULL, 0),
(@PATH, 4, 1093.79, 3075.638, -10.08114, NULL, 0),
(@PATH, 5, 1106.547, 3079.659, -10.07776, NULL, 0),
(@PATH, 6, 1117.747, 3086.152, -10.93019, NULL, 0),
(@PATH, 7, 1129.634, 3091.534, -10.64101, NULL, 0),
(@PATH, 8, 1141.925, 3096.75, -10.54937, NULL, 0),
(@PATH, 9, 1147.679, 3105.055, -10.55538, NULL, 0),
(@PATH, 10, 1141.925, 3096.75, -10.54937, NULL, 0),
(@PATH, 11, 1129.634, 3091.534, -10.64101, NULL, 0),
(@PATH, 12, 1117.747, 3086.152, -10.93019, NULL, 0),
(@PATH, 13, 1106.547, 3079.659, -10.07776, NULL, 0);

UPDATE `creature` SET `position_x`= 1093.79, `position_y`= 3075.638, `position_z`= -10.08114, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+16;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+16, @PATH, 1, 3);

-- Waypoints for CGUID+45
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+45;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+45, @CGUID+45, 0, 0, 515, 0, 0),
(@CGUID+45, @CGUID+7, 3, 90, 515, 0, 0);

SET @PATH := ((@CGUID+45) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1207.326, 3135.052, -16.20279, NULL, 0),
(@PATH, 1, 1199.51, 3133.309, -14.62128, NULL, 0),
(@PATH, 2, 1193.234, 3133.792, -13.93189, NULL, 0),
(@PATH, 3, 1184.682, 3134.511, -11.8483, NULL, 0),
(@PATH, 4, 1178.741, 3133.686, -10.79799, NULL, 0),
(@PATH, 5, 1172.58, 3130.35, -9.682734, NULL, 0),
(@PATH, 6, 1166.455, 3127.036, -10.10742, NULL, 0),
(@PATH, 7, 1161.304, 3123.264, -10.44543, NULL, 0),
(@PATH, 8, 1157.319, 3119.731, -10.4612, NULL, 0),
(@PATH, 9, 1154.469, 3116.368, -10.46975, NULL, 11133),
(@PATH, 10, 1161.304, 3123.264, -10.44543, NULL, 0),
(@PATH, 11, 1166.455, 3127.036, -10.10742, NULL, 0),
(@PATH, 12, 1172.58, 3130.35, -9.682734, NULL, 0),
(@PATH, 13, 1178.589, 3133.666, -10.84853, NULL, 0),
(@PATH, 14, 1184.53, 3134.492, -11.89855, NULL, 0),
(@PATH, 15, 1193.234, 3133.792, -13.93189, NULL, 0),
(@PATH, 16, 1199.51, 3133.309, -14.62128, NULL, 0),
(@PATH, 17, 1207.315, 3135.051, -16.32398, NULL, 0),
(@PATH, 18, 1213.08, 3136.639, -17.92701, NULL, 13639);

UPDATE `creature` SET `position_x`= 1207.326, `position_y`= 3135.052, `position_z`= -16.20279, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+45;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+45;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+45, @PATH, 1, 3);

-- Waypoints for CGUID+81
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+81;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+81, @CGUID+81, 0, 0, 515, 0, 0),
(@CGUID+81, @CGUID+87, 3, 90, 515, 0, 0);

SET @PATH := ((@CGUID+81) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 999.9393, 2924.895, -7.272597, NULL, 0),
(@PATH, 1, 994.7413, 2915.267, -6.145591, NULL, 0),
(@PATH, 2, 990.0712, 2903.378, -4.162011, NULL, 0),
(@PATH, 3, 986.0417, 2888.638, -1.083038, NULL, 0),
(@PATH, 4, 985.6285, 2881.205, 0.7571244, NULL, 0),
(@PATH, 5, 988.1302, 2870.912, 2.992924, NULL, 0),
(@PATH, 6, 991.2708, 2862.776, 4.25096, NULL, 0),
(@PATH, 7, 994.1597, 2856.793, 4.729815, NULL, 0),
(@PATH, 8, 993.8785, 2853.452, 5.402333, NULL, 14739),
(@PATH, 9, 991.2708, 2862.776, 4.25096, NULL, 0),
(@PATH, 10, 988.1302, 2870.912, 2.992924, NULL, 0),
(@PATH, 11, 985.6285, 2881.205, 0.7571244, NULL, 0),
(@PATH, 12, 986.0417, 2888.638, -1.083038, NULL, 0),
(@PATH, 13, 990.0712, 2903.378, -4.162011, NULL, 0),
(@PATH, 14, 994.7413, 2915.267, -6.145591, NULL, 0),
(@PATH, 15, 999.9393, 2924.895, -7.272597, NULL, 0),
(@PATH, 16, 1003.273, 2930.595, -8.772047, NULL, 11206);

UPDATE `creature` SET `position_x`= 999.9393, `position_y`= 2924.895, `position_z`= -7.272597, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+81;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+81;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`) VALUES
(@CGUID+81, @PATH, 1, 3);

-- Waypoints for CGUID+41
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+41;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+41, @CGUID+41, 0, 0, 515, 0, 0),
(@CGUID+41, @CGUID+6, 2, 0, 515, 0, 0);

SET @PATH := ((@CGUID+41) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1027.365, 3154.499, 9.815045, NULL, 0, 1),
(@PATH, 1, 1027.061, 3159.663, 10.85854, NULL, 0, 1),
(@PATH, 2, 1027.884, 3164.355, 11.71556, NULL, 0, 1),
(@PATH, 3, 1030.519, 3168.092, 12.81714, NULL, 0, 1),
(@PATH, 4, 1035.441, 3169.907, 13.86073, NULL, 0, 1),
(@PATH, 5, 1040.231, 3172.425, 14.80667, NULL, 0, 1),
(@PATH, 6, 1043.951, 3175.439, 15.54061, NULL, 0, 1),
(@PATH, 7, 1046.309, 3178.432, 15.77495, NULL, 0, 1),
(@PATH, 8, 1040.231, 3172.425, 14.80667, NULL, 0, 1),
(@PATH, 9, 1035.441, 3169.907, 13.86073, NULL, 0, 1),
(@PATH, 10, 1030.519, 3168.092, 12.81714, NULL, 0, 1),
(@PATH, 11, 1027.884, 3164.355, 11.71556, NULL, 0, 1),
(@PATH, 12, 1027.061, 3159.663, 10.85854, NULL, 0, 1),
(@PATH, 13, 1027.365, 3154.499, 9.815045, NULL, 0, 1),
(@PATH, 14, 1025.861, 3151.044, 8.780029, NULL, 0, 1),
(@PATH, 15, 1021.891, 3147.694, 7.473603, NULL, 0, 1),
(@PATH, 16, 1020.627, 3142.538, 5.822973, NULL, 0, 1),
(@PATH, 17, 1018.29, 3138.72, 3.750393, NULL, 0, 1),
(@PATH, 18, 1011.918, 3136.7, 0.3315203, NULL, 0, 1),
(@PATH, 19, 1004.135, 3133.749, -4.072388, NULL, 0, 1),
(@PATH, 20, 1001.042, 3130.609, -8.436937, NULL, 0, 1),
(@PATH, 21, 1004.135, 3133.749, -4.072388, NULL, 0, 1),
(@PATH, 22, 1011.918, 3136.7, 0.3315203, NULL, 0, 1),
(@PATH, 23, 1018.29, 3138.72, 3.750393, NULL, 0, 1),
(@PATH, 24, 1020.627, 3142.538, 5.822973, NULL, 0, 1),
(@PATH, 25, 1021.891, 3147.694, 7.473603, NULL, 0, 1),
(@PATH, 26, 1025.861, 3151.044, 8.780029, NULL, 0, 1);

UPDATE `creature` SET `position_x`= 1027.365, `position_y`= 3154.499, `position_z`= 9.815045, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+41;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+41;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+41, @PATH, 1, 3, '200372');

-- Waypoints for CGUID+35
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+35;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+35, @CGUID+35, 0, 0, 515, 0, 0),
(@CGUID+35, @CGUID+8, 2, 0, 515, 0, 0);

SET @PATH := ((@CGUID+35) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 1032.531, 3028.258, -13.05224, NULL, 0, 1),
(@PATH, 1, 1035.995, 3030.223, -11.56762, NULL, 0, 1),
(@PATH, 2, 1041.7, 3027.699, -11.44908, NULL, 0, 1),
(@PATH, 3, 1039.983, 3023.179, -11.98451, NULL, 0, 1),
(@PATH, 4, 1042.783, 3019.662, -11.46669, NULL, 0, 1),
(@PATH, 5, 1041.557, 3016.024, -11.68876, NULL, 0, 1),
(@PATH, 6, 1042.691, 3012.13, -11.43744, NULL, 0, 1),
(@PATH, 7, 1048.521, 3010.55, -10.63843, NULL, 0, 1),
(@PATH, 8, 1052.372, 3009.911, -10.71994, NULL, 0, 1),
(@PATH, 9, 1054.714, 3007.809, -10.62968, NULL, 0, 1),
(@PATH, 10, 1048.521, 3010.55, -10.63843, NULL, 0, 1),
(@PATH, 11, 1045.439, 3012.303, -10.94649, NULL, 0, 1),
(@PATH, 12, 1042.691, 3012.13, -11.43744, NULL, 0, 1),
(@PATH, 13, 1041.557, 3016.024, -11.68876, NULL, 0, 1),
(@PATH, 14, 1042.783, 3019.662, -11.46669, NULL, 0, 1),
(@PATH, 15, 1039.983, 3023.179, -11.98451, NULL, 0, 1),
(@PATH, 16, 1041.7, 3027.699, -11.44908, NULL, 0, 1),
(@PATH, 17, 1035.995, 3030.223, -11.56762, NULL, 0, 1),
(@PATH, 18, 1032.531, 3028.258, -13.05224, NULL, 0, 1),
(@PATH, 19, 1029.969, 3032.729, -12.05125, NULL, 0, 1),
(@PATH, 20, 1025.424, 3034.431, -12.09129, NULL, 0, 1),
(@PATH, 21, 1023.401, 3031.849, -13.39231, NULL, 0, 1),
(@PATH, 22, 1019.675, 3029.774, -13.16064, NULL, 0, 1),
(@PATH, 23, 1014.012, 3029.378, -13.7957, NULL, 0, 1),
(@PATH, 24, 1019.675, 3029.774, -13.16064, NULL, 0, 1),
(@PATH, 25, 1023.401, 3031.849, -13.39231, NULL, 0, 1),
(@PATH, 26, 1025.424, 3034.431, -12.09129, NULL, 0, 1),
(@PATH, 27, 1029.969, 3032.729, -12.05125, NULL, 0, 1);

UPDATE `creature` SET `position_x`= 1032.531, `position_y`= 3028.258, `position_z`= -13.05224, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+35;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+35;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+35, @PATH, 1, 3, '200372');

SET @CGUID := 396407;
SET @OGUID := 246935;

-- Gameobject templates
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208165; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208165; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=29002;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29002, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208165;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208165, 29002, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208165 AND `quest`=29002);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208165;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 22816, 1, 17, 1704, '0', 0, 0, 0, 0, 251.0818328857421875, -3048.7744140625, 95.97806549072265625, 3.87861943244934082, 120, 10, 0, 188, 0, 1, 0, 0, 0, 46366); -- Black Cat (Area: Grol'dom Farm - Difficulty: 0) (possible waypoints or random movement)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 228692 AND 228711;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 228692 AND 228711;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 17, 1704, '0', 0, 0, 259.7100830078125, -3033.69091796875, 97.14778900146484375, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+1, 180406, 1, 17, 1704, '0', 0, 0, 275.96875, -3037.59716796875, 97.5806427001953125, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+2, 180407, 1, 17, 1704, '0', 0, 0, 268.892364501953125, -3042.58154296875, 96.72592926025390625, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+3, 180410, 1, 17, 1704, '0', 0, 0, 267.274322509765625, -3033.802001953125, 99.45452117919921875, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+4, 180411, 1, 17, 1704, '0', 0, 0, 258.947906494140625, -3033.251708984375, 102.3009796142578125, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+5, 180415, 1, 17, 1704, '0', 0, 0, 275.592010498046875, -3023.489501953125, 99.21895599365234375, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- CandleBlack01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+6, 180415, 1, 17, 1704, '0', 0, 0, 274.079864501953125, -3025.420166015625, 98.35748291015625, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- CandleBlack01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+7, 180425, 1, 17, 1704, '0', 0, 0, 285.21527099609375, -3024.763916015625, 100.1668930053710937, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 46366), -- SkullCandle01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+8, 180426, 1, 17, 1704, '0', 0, 0, 247.3559112548828125, -3051.53466796875, 95.87291717529296875, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- Bat01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+9, 180426, 1, 17, 1704, '0', 0, 0, 230.6145782470703125, -3056.592041015625, 95.43585968017578125, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- Bat01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+10, 180426, 1, 17, 1704, '0', 0, 0, 246.328125, -3070.310791015625, 95.30218505859375, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- Bat01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+11, 180427, 1, 17, 1704, '0', 0, 0, 247.232635498046875, -3067.1962890625, 95.7902984619140625, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- Bat02 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+12, 180427, 1, 17, 1704, '0', 0, 0, 246.7899322509765625, -3058.21533203125, 95.91086578369140625, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- Bat02 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+13, 180427, 1, 17, 1704, '0', 0, 0, 235.8697967529296875, -3055.520751953125, 95.8309783935546875, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- Bat02 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+14, 180471, 1, 17, 1704, '0', 0, 0, 268.796875, -3036.5869140625, 101.727752685546875, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+15, 180471, 1, 17, 1704, '0', 0, 0, 270.170135498046875, -3038.33154296875, 101.6673202514648437, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+16, 180471, 1, 17, 1704, '0', 0, 0, 268.109375, -3035.510498046875, 101.7501373291015625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+17, 180471, 1, 17, 1704, '0', 0, 0, 270.84027099609375, -3039.204833984375, 101.6610870361328125, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+18, 180472, 1, 17, 1704, '0', 0, 0, 269.536468505859375, -3037.447998046875, 102.5689773559570312, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+19, 180523, 1, 17, 1704, '0', 0, 0, 271.77777099609375, -3029.96875, 97.96080780029296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Apple Bob (Area: Grol'dom Farm - Difficulty: 0)
(@OGUID+20, 208165, 1, 17, 1704, '0', 0, 0, 276.927093505859375, -3027.552001953125, 97.3475799560546875, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 46366); -- Candy Bucket (Area: Grol'dom Farm - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12),
(12, @OGUID+13),
(12, @OGUID+14),
(12, @OGUID+15),
(12, @OGUID+16),
(12, @OGUID+17),
(12, @OGUID+18),
(12, @OGUID+19),
(12, @OGUID+20);

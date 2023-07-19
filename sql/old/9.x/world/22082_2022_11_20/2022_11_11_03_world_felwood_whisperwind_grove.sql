SET @CGUID := 396404;
SET @OGUID := 246004;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208158; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=208158; -- Candy Bucket

-- Quests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=28994;

DELETE FROM `gameobject_queststarter` WHERE `id`=208158;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208158, 28994, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208158 AND `quest`=28994);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208158;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 22816, 1, 361, 5645, '0', 0, 0, 0, 0, 6074.42041015625, -870.1185302734375, 411.9312744140625, 1.104033231735229492, 120, 10, 0, 188, 0, 1, 0, 0, 0, 46366); -- Black Cat (Area: Whisperwind Grove - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 228784 AND 228856;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 228784 AND 228856;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+41;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 361, 5645, '0', 0, 0, 6044.70068359375, -854.79864501953125, 426.23907470703125, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+1, 180405, 1, 361, 5645, '0', 0, 0, 6077.2255859375, -904.217041015625, 414.751800537109375, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+2, 180405, 1, 361, 5645, '0', 0, 0, 6108.91845703125, -861.779541015625, 412.381256103515625, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+3, 180406, 1, 361, 5645, '0', 0, 0, 6075.87158203125, -836.42706298828125, 414.82843017578125, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+4, 180406, 1, 361, 5645, '0', 0, 0, 6068.0380859375, -897.90277099609375, 414.751251220703125, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+5, 180406, 1, 361, 5645, '0', 0, 0, 6111.2021484375, -886.8524169921875, 413.499359130859375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+6, 180407, 1, 361, 5645, '0', 0, 0, 6049.27783203125, -859.342041015625, 426.238861083984375, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+7, 180411, 1, 361, 5645, '0', 0, 0, 6044.845703125, -855.154541015625, 417.24658203125, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+8, 180414, 1, 361, 5645, '0', 0, 0, 6074.19091796875, -890.6319580078125, 412.070953369140625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 46366), -- Cauldron (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+9, 180415, 1, 361, 5645, '0', 0, 0, 6050.953125, -857.404541015625, 414.953521728515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+10, 180415, 1, 361, 5645, '0', 0, 0, 6056.27099609375, -852.85418701171875, 412.649932861328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+11, 180415, 1, 361, 5645, '0', 0, 0, 6050.95068359375, -847.72393798828125, 412.681793212890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+12, 180415, 1, 361, 5645, '0', 0, 0, 6053.85400390625, -855.125, 413.743499755859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+13, 180415, 1, 361, 5645, '0', 0, 0, 6049.0068359375, -849.82989501953125, 413.62890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+14, 180415, 1, 361, 5645, '0', 0, 0, 6046.27880859375, -852.920166015625, 414.981048583984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+15, 180415, 1, 361, 5645, '0', 0, 0, 6076.916015625, -890.1007080078125, 412.16094970703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+16, 180415, 1, 361, 5645, '0', 0, 0, 6073.95751953125, -894.38714599609375, 414.7017822265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+17, 180415, 1, 361, 5645, '0', 0, 0, 6071.61474609375, -897.8350830078125, 415.58111572265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+18, 180415, 1, 361, 5645, '0', 0, 0, 6075.515625, -892.04864501953125, 413.573516845703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+19, 180415, 1, 361, 5645, '0', 0, 0, 6076.3681640625, -900.98089599609375, 415.573760986328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+20, 180415, 1, 361, 5645, '0', 0, 0, 6080.234375, -895.22052001953125, 413.568511962890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+21, 180415, 1, 361, 5645, '0', 0, 0, 6081.609375, -893.19964599609375, 412.11846923828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+22, 180415, 1, 361, 5645, '0', 0, 0, 6078.58251953125, -897.7742919921875, 414.776214599609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+23, 180425, 1, 361, 5645, '0', 0, 0, 6076.36279296875, -888.920166015625, 413.872039794921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- SkullCandle01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+24, 180426, 1, 361, 5645, '0', 0, 0, 6094.3837890625, -863.4444580078125, 427.66961669921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+25, 180426, 1, 361, 5645, '0', 0, 0, 6088.12353515625, -871.203125, 427.66961669921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+26, 180426, 1, 361, 5645, '0', 0, 0, 6086.35595703125, -858.8992919921875, 427.66961669921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+27, 180427, 1, 361, 5645, '0', 0, 0, 6096.9833984375, -864.3125, 431.452972412109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+28, 180427, 1, 361, 5645, '0', 0, 0, 6083.6650390625, -867.373291015625, 431.452972412109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+29, 180427, 1, 361, 5645, '0', 0, 0, 6091.09619140625, -874.11285400390625, 431.452972412109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+30, 180471, 1, 361, 5645, '0', 0, 0, 6084.1181640625, -828.765625, 418.227935791015625, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+31, 180471, 1, 361, 5645, '0', 0, 0, 6085.23974609375, -828.16839599609375, 418.957427978515625, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+32, 180471, 1, 361, 5645, '0', 0, 0, 6086.26025390625, -827.1180419921875, 419.709930419921875, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+33, 180471, 1, 361, 5645, '0', 0, 0, 6088.7177734375, -826.3975830078125, 418.253875732421875, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+34, 180471, 1, 361, 5645, '0', 0, 0, 6087.515625, -826.92535400390625, 419.009674072265625, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+35, 180471, 1, 361, 5645, '0', 0, 0, 6067.7509765625, -910.63543701171875, 418.559478759765625, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+36, 180471, 1, 361, 5645, '0', 0, 0, 6065.3056640625, -909.03643798828125, 418.475494384765625, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+37, 180471, 1, 361, 5645, '0', 0, 0, 6066.53564453125, -909.888916015625, 418.993072509765625, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+38, 180472, 1, 361, 5645, '0', 0, 0, 6107.1494140625, -892.09722900390625, 416.917510986328125, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+39, 180523, 1, 361, 5645, '0', 0, 0, 6071.09912109375, -908.5399169921875, 415.229888916015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Apple Bob (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+40, 185436, 1, 361, 5645, '0', 0, 0, 6074.03564453125, -890.74652099609375, 412.646087646484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Sitting Skeleton 03 (Area: Whisperwind Grove - Difficulty: 0)
(@OGUID+41, 208158, 1, 361, 5645, '0', 0, 0, 6065.92724609375, -905.00177001953125, 414.79315185546875, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 46366); -- Candy Bucket (Area: Whisperwind Grove - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+41;
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
(12, @OGUID+20),
(12, @OGUID+21),
(12, @OGUID+22),
(12, @OGUID+23),
(12, @OGUID+24),
(12, @OGUID+25),
(12, @OGUID+26),
(12, @OGUID+27),
(12, @OGUID+28),
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40),
(12, @OGUID+41);

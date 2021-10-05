SET @CGUID := 1050038;
SET @OGUID := 600000;

-- playercreateinfo for Allied Race Deathknights
DELETE FROM `playercreateinfo` WHERE `race` IN (29, 27, 28, 30, 31, 32, 34, 35, 36, 37, 26, 25) AND `class`=6;
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(29, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(27, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(28, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(30, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(31, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(32, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(34, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(35, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(36, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(37, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(26, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908),
(25, 6, 2297, 481.803009033203125, -2124.659912109375, 840.85699462890625, 3.1104908);

DELETE FROM `scene_template` WHERE (`SceneId`=2394 AND `ScriptPackageID`=2780);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2394, 9, 2780, 0);

-- Update Quest stuff
DELETE FROM `creature_queststarter` WHERE `id` = 163016;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(163016, 58877), -- Deaths Power Grows
(163016, 58902), -- Defender of Azeroth (A)
(163016, 58903); -- Defender of Azeroth (H)

DELETE FROM `creature_questender` WHERE `id` = 163016;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(163016, 58877), -- Deaths Power Grows
(163016, 58902), -- Defender of Azeroth (A)
(163016, 58903); -- Defender of Azeroth (H)

UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `BlobIndex`=0 AND `Idx1`=4); -- Defender of Azeroth
UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `BlobIndex`=1 AND `Idx1`=3); -- Defender of Azeroth
UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `BlobIndex`=0 AND `Idx1`=2); -- Defender of Azeroth
UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `BlobIndex`=0 AND `Idx1`=1); -- Defender of Azeroth
UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `BlobIndex`=0 AND `Idx1`=0); -- Defender of Azeroth
UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58877 AND `BlobIndex`=0 AND `Idx1`=2); -- Death's Power Grows
UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58877 AND `BlobIndex`=0 AND `Idx1`=1); -- Death's Power Grows
UPDATE `quest_poi` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58877 AND `BlobIndex`=0 AND `Idx1`=0); -- Death's Power Grows

UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `Idx1`=4 AND `Idx2`=0); -- Defender of Azeroth
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `Idx1`=3 AND `Idx2`=0); -- Defender of Azeroth
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `Idx1`=2 AND `Idx2`=0); -- Defender of Azeroth
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `Idx1`=1 AND `Idx2`=0); -- Defender of Azeroth
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58902 AND `Idx1`=0 AND `Idx2`=0); -- Defender of Azeroth
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58877 AND `Idx1`=2 AND `Idx2`=0); -- Death's Power Grows
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58877 AND `Idx1`=1 AND `Idx2`=0); -- Death's Power Grows
UPDATE `quest_poi_points` SET `VerifiedBuild`=40120 WHERE (`QuestID`=58877 AND `Idx1`=0 AND `Idx2`=0); -- Death's Power Grows

DELETE FROM `quest_offer_reward` WHERE `ID`=58877;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(58877, 0, 0, 0, 0, 0, 0, 0, 0, 'I accept your pledge. Serve us well.\n\nTo that end, new weapons worthy of a Knight of the Ebon Blade have been forged.\n\nChoose, my champion.', 40120); -- Death's Power Grows

DELETE FROM `quest_details` WHERE `ID` IN (58902 /*Defender of Azeroth*/, 58877 /*Death's Power Grows*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(58902, 0, 0, 0, 0, 0, 0, 0, 0, 40120), -- Defender of Azeroth
(58877, 0, 0, 0, 0, 0, 0, 0, 0, 40120); -- Death's Power Grows

DELETE FROM `quest_request_items` WHERE `ID`=58877;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(58877, 0, 0, 0, 0, 'Swear your fealty, $n.', 40120); -- Death's Power Grows

-- NPC spawns & Addon
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+32;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 514.51739501953125, -2132.288330078125, 840.9403076171875, 1.543633103370666503, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 514.92364501953125, -2116.732666015625, 840.94024658203125, 4.681285858154296875, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+2, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 502.567718505859375, -2116.8525390625, 840.94024658203125, 4.724217414855957031, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 489.935760498046875, -2132.288330078125, 840.9403076171875, 1.562398791313171386, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 512.61456298828125, -2116.71533203125, 840.94024658203125, 4.669904232025146484, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 511.98785400390625, -2132.288330078125, 840.94024658203125, 1.528188347816467285, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 509.392364501953125, -2132.2900390625, 840.9403076171875, 1.523436784744262695, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 161708, 2297, 12952, 12951, '0', '0', 0, 0, 0, 466.701385498046875, -2131.3837890625, 840.9403076171875, 6.238399505615234375, 7200, 0, 0, 36632, 9035, 0, 0, 0, 0, 40120), -- High Inquisitor Whitemane (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 492.51910400390625, -2116.850830078125, 840.94024658203125, 4.720029354095458984, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 507.03472900390625, -2132.288330078125, 840.94024658203125, 1.53494429588317871, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 490.036468505859375, -2116.850830078125, 840.94024658203125, 4.710337162017822265, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 517.3055419921875, -2132.2900390625, 840.94024658203125, 1.551848411560058593, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 161707, 2297, 12952, 12951, '0', '0', 0, 0, 0, 466.701385498046875, -2121.79345703125, 840.9403076171875, 6.238399505615234375, 7200, 0, 0, 32053, 0, 0, 0, 0, 0, 40120), -- King Thoras Trollbane (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 497.791656494140625, -2132.288330078125, 840.94024658203125, 1.568883061408996582, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+14, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 500.114593505859375, -2132.2900390625, 840.9403076171875, 1.567752838134765625, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 161709, 2297, 12952, 12951, '0', '0', 0, 0, 0, 466.701385498046875, -2127.08154296875, 840.9403076171875, 6.238408565521240234, 7200, 0, 0, 114475, 45175, 0, 0, 0, 0, 40120), -- Highlord Darion Mograine (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 495.166656494140625, -2116.8525390625, 840.94024658203125, 4.71814584732055664, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 495.26214599609375, -2132.288330078125, 840.9403076171875, 1.577044129371643066, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 507.4375, -2116.8525390625, 840.94024658203125, 4.692774295806884765, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 487.390625, -2116.850830078125, 840.94024658203125, 4.707186222076416015, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 161706, 2297, 12952, 12951, '0', '0', 0, 0, 0, 466.701385498046875, -2116.763916015625, 840.9403076171875, 6.238399505615234375, 7200, 0, 0, 45790, 1807, 0, 0, 0, 0, 40120), -- Nazgrim (Area: -Unknown- - Difficulty: 0)
(@CGUID+21, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 517.513916015625, -2116.53466796875, 840.94024658203125, 4.703579425811767578, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+22, 163016, 2297, 12952, 12951, '0', '0', 0, 0, 0, 426.432281494140625, -2123.810791015625, 864.97430419921875, 3.191439628601074218, 7200, 0, 0, 9158000, 0, 0, 0, 0, 0, 40120), -- The Lich King (Area: -Unknown- - Difficulty: 0) (Auras: 192032 - Swirling Souls)
(@CGUID+23, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 504.94964599609375, -2132.2900390625, 840.94024658203125, 1.570852279663085937, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+24, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 497.78472900390625, -2116.8525390625, 840.94024658203125, 4.720065116882324218, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 519.9913330078125, -2116.397705078125, 840.9403076171875, 4.726891517639160156, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 487.255218505859375, -2132.288330078125, 840.9403076171875, 1.559023022651672363, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+27, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 520.13543701171875, -2132.3056640625, 840.9403076171875, 1.576829433441162109, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+28, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 492.689239501953125, -2132.2900390625, 840.9403076171875, 1.58624422550201416, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+29, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 502.670135498046875, -2132.2900390625, 840.94024658203125, 1.58245241641998291, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+30, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 510.126739501953125, -2116.713623046875, 840.94024658203125, 4.661986351013183593, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+31, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 504.923614501953125, -2116.8525390625, 840.94024658203125, 4.710828304290771484, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120), -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
(@CGUID+32, 161711, 2297, 12952, 12951, '0', '0', 0, 0, 0, 500.22222900390625, -2116.8525390625, 840.94024658203125, 4.712122440338134765, 7200, 0, 0, 9624, 852, 0, 0, 0, 0, 40120); -- Knight of the Ebon Blade (Area: -Unknown- - Difficulty: 0)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+32;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+7, 0, 70479, 0, 1, 0, 0, 0, 0, ''), -- High Inquisitor Whitemane
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+12, 0, 70480, 0, 1, 0, 0, 0, 0, ''), -- King Thoras Trollbane
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+15, 0, 70478, 0, 1, 0, 0, 0, 0, ''), -- Highlord Darion Mograine
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+20, 0, 70481, 0, 1, 0, 0, 0, 0, ''), -- Nazgrim
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '192032'), -- The Lich King - 192032 - Swirling Souls
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Knight of the Ebon Blade

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 202143, 2297, 12952, 12951, '0', '0', 0, 533.55987548828125, -2152.8310546875, 840.85699462890625, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Doodad_IceShard_standing03 (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 202141, 2297, 12952, 12951, '0', '0', 0, 473.74700927734375, -2096.476806640625, 840.85699462890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 40120), -- Doodad_IceShard_standing02 (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 202190, 2297, 12952, 12951, '0', '0', 0, 503.619140625, -2124.650390625, 840.5247802734375, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 40120), -- Doodad_Icecrown_SnowEdgeWarning01 (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 202144, 2297, 12952, 12951, '0', '0', 0, 533.5592041015625, -2096.475830078125, 840.85699462890625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 40120), -- Doodad_IceShard_standing04 (Area: -Unknown- - Difficulty: 0)
(@OGUID+4, 202188, 2297, 12952, 12951, '0', '0', 0, 503.619140625, -2124.650390625, 836.6099853515625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 0, 40120), -- Doodad_Icecrown_ThroneFrostyWind01 (Area: -Unknown- - Difficulty: 0)
(@OGUID+5, 202142, 2297, 12952, 12951, '0', '0', 0, 473.747650146484375, -2152.83203125, 840.85699462890625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 40120), -- Doodad_IceShard_standing01 (Area: -Unknown- - Difficulty: 0)
(@OGUID+6, 202189, 2297, 12952, 12951, '0', '0', 0, 503.619140625, -2124.650390625, 836.6099853515625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 40120), -- Doodad_Icecrown_ThroneFrostyEdge01 (Area: -Unknown- - Difficulty: 0)
(@OGUID+7, 202189, 2297, 12952, 12951, '0', '0', 0, 503.619140625, -2124.650390625, 836.6099853515625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 40120), -- Doodad_Icecrown_ThroneFrostyEdge01 (Area: -Unknown- - Difficulty: 0)
(@OGUID+8, 341816, 2297, 12952, 12951, '0', '0', 0, 426.432281494140625, -2123.814208984375, 864.89141845703125, 3.191464900970458984, 0, 0, -0.99968910217285156, 0.02493344061076641, 7200, 255, 1, 40120), -- The Lich King (Area: -Unknown- - Difficulty: 0)
(@OGUID+9, 202143, 2297, 12952, 12951, '0', '0', 0, 533.55987548828125, -2152.8310546875, 840.85699462890625, 0, 0, 0, 0, 1, 7200, 255, 1, 40120), -- Doodad_IceShard_standing03 (Area: -Unknown- - Difficulty: 0)
(@OGUID+10, 202141, 2297, 12952, 12951, '0', '0', 0, 473.74700927734375, -2096.476806640625, 840.85699462890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 40120), -- Doodad_IceShard_standing02 (Area: -Unknown- - Difficulty: 0)
(@OGUID+11, 202190, 2297, 12952, 12951, '0', '0', 0, 503.619140625, -2124.650390625, 840.5247802734375, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 1, 40120), -- Doodad_Icecrown_SnowEdgeWarning01 (Area: -Unknown- - Difficulty: 0)
(@OGUID+12, 202144, 2297, 12952, 12951, '0', '0', 0, 533.5592041015625, -2096.475830078125, 840.85699462890625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 40120), -- Doodad_IceShard_standing04 (Area: -Unknown- - Difficulty: 0)
(@OGUID+13, 202188, 2297, 12952, 12951, '0', '0', 0, 503.619140625, -2124.650390625, 836.6099853515625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 7200, 255, 0, 40120), -- Doodad_Icecrown_ThroneFrostyWind01 (Area: -Unknown- - Difficulty: 0)
(@OGUID+14, 202142, 2297, 12952, 12951, '0', '0', 0, 473.747650146484375, -2152.83203125, 840.85699462890625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 40120); -- Doodad_IceShard_standing01 (Area: -Unknown- - Difficulty: 0)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_IceShard_standing03
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_IceShard_standing02
(@OGUID+2, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_Icecrown_SnowEdgeWarning01
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_IceShard_standing04
(@OGUID+4, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_Icecrown_ThroneFrostyWind01
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_IceShard_standing01
(@OGUID+6, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_Icecrown_ThroneFrostyEdge01
(@OGUID+7, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_Icecrown_ThroneFrostyEdge01
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_IceShard_standing03
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_IceShard_standing02
(@OGUID+11, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_Icecrown_SnowEdgeWarning01
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_IceShard_standing04
(@OGUID+13, 0, 0, 0.999961912631988525, -0.00872652977705001, 0, 0), -- Doodad_Icecrown_ThroneFrostyWind01
(@OGUID+14, 0, 0, 1, -0.00000004371138828, 0, 0); -- Doodad_IceShard_standing01

-- creature_template
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `npcflag`=2, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4229120 WHERE `entry`=163016; -- The Lich King
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2050, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161706; -- Nazgrim
UPDATE `creature_template` SET `gossip_menu_id`=25082, `minlevel`=50, `maxlevel`=50, `faction`=2050, `npcflag`=1, `speed_walk`=2.40000009536743164, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161709; -- Highlord Darion Mograine
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2050, `speed_walk`=2.40000009536743164, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161707; -- King Thoras Trollbane
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2050, `speed_walk`=2.40000009536743164, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161708; -- High Inquisitor Whitemane
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction`=2051, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161711; -- Knight of the Ebon Blade

-- GameObject_template
DELETE FROM `gameobject_template` WHERE `entry` IN (341833 /*Death Gate*/, 341816 /*The Lich King*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(341833, 22, 8046, 'Death Gate', 'questinteract', '', '', 1, 317309, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 961, 40120), -- Death Gate
(341816, 5, 60714, 'The Lich King', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40120); -- The Lich King

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (341833 /*Death Gate*/, 341816 /*The Lich King*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(341833, 0, 32, 0, 0), -- Death Gate
(341816, 114, 32, 0, 0); -- The Lich King

-- NPC text
DELETE FROM `npc_text` WHERE `ID`=39541;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(39541, 1, 0, 0, 0, 0, 0, 0, 0, 187069, 0, 0, 0, 0, 0, 0, 0, 40120); -- 39541

-- NPC Gossip
DELETE FROM `gossip_menu` WHERE (`MenuId`=25082 AND `TextId`=39541);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25082, 39541, 40120); -- 161709 (Highlord Darion Mograine)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=25082 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES 
(25082, 0, 0, 'Reporting for duty.', 0, 1, 1, 40120);

-- NPC scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (155345,23482,23511,23510,153931,161709,161708,163016,161706,161707,161711));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(155345, 0, 0, 0, 298, 40120),
(23482, 0, 0, 0, 298, 40120),
(23511, 0, 0, 0, 298, 40120),
(23510, 0, 0, 0, 298, 40120),
(153931, 0, 0, 0, 298, 40120),
(161709, 0, 0, 0, 464, 40120),
(161708, 0, 0, 0, 464, 40120),
(163016, 0, 0, 0, 464, 40120),
(161706, 0, 0, 0, 464, 40120),
(161707, 0, 0, 0, 464, 40120),
(161711, 0, 0, 0, 856, 40120);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=111190 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=68 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=61165 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=883 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=17804 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=40120 WHERE (`Entry`=61080 AND `DifficultyID`=0);

-- Creature Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (94647, 94654, 94660, 94656, 94653, 94661, 95187, 94664, 94663, 94667, 94651, 94648, 94649);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(94647, 0.305999994277954101, 1.5, 0, 40120),
(94654, 1, 1.5, 0, 40120),
(94660, 0.347222000360488891, 1.5, 0, 40120),
(94656, 0.372000008821487426, 1.5, 0, 40120),
(94653, 0.347222000360488891, 1.5, 0, 40120),
(94661, 0.347222000360488891, 1.5, 0, 40120),
(95187, 0.706999957561492919, 0, 0, 40120),
(94664, 0.347222000360488891, 1.5, 0, 40120),
(94663, 0.347222000360488891, 1.5, 0, 40120),
(94667, 0.305999994277954101, 1.5, 0, 40120),
(94651, 0.722000002861022949, 3, 0, 40120),
(94648, 0.347000002861022949, 1.5, 0, 40120),
(94649, 0.347000002861022949, 1.5, 0, 40120);

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=99391;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=5446;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=99389;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=3167;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=654;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=91738;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=347;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=91740;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=91751;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=22394;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=91748;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=91746;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=22628;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=21860;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=91731;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=17250;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=22396;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=91743;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=4626;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=63575;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=40120 WHERE `DisplayID`=72255;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=94657;
UPDATE `creature_model_info` SET `BoundingRadius`=0.447349995374679565, `CombatReach`=1.724999904632568359, `VerifiedBuild`=40120 WHERE `DisplayID`=72264;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=27153;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=94655;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=72258;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=63577;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=71257;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=40120 WHERE `DisplayID`=72261;
UPDATE `creature_model_info` SET `BoundingRadius`=0.351899981498718261, `CombatReach`=1.724999904632568359, `VerifiedBuild`=40120 WHERE `DisplayID`=72265;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=40120 WHERE `DisplayID`=72257;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=70436;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=94658;
UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=63576;
UPDATE `creature_model_info` SET `BoundingRadius`=0.421299993991851806, `CombatReach`=1.65000009536743164, `VerifiedBuild`=40120 WHERE `DisplayID`=72259;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=40120 WHERE `DisplayID`=72262;
UPDATE `creature_model_info` SET `BoundingRadius`=0.44044998288154602, `CombatReach`=1.724999904632568359, `VerifiedBuild`=40120 WHERE `DisplayID`=72260;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=40120 WHERE `DisplayID`=72256;
UPDATE `creature_model_info` SET `BoundingRadius`=0.428399980068206787, `CombatReach`=2.099999904632568359, `VerifiedBuild`=40120 WHERE `DisplayID`=70807;

-- creature equipment
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (161709,161708,161706,161707,161711));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(161709, 1, 40276, 0, 0, 40276, 0, 0, 0, 0, 0), -- Highlord Darion Mograine
(161708, 1, 79321, 0, 0, 0, 0, 0, 0, 0, 0), -- High Inquisitor Whitemane
(161706, 1, 38633, 0, 0, 0, 0, 0, 0, 0, 0), -- Nazgrim
(161707, 1, 129456, 0, 0, 0, 0, 0, 0, 0, 0), -- King Thoras Trollbane
(161711, 1, 117049, 0, 0, 0, 0, 0, 0, 0, 0); -- Knight of the Ebon Blade

DELETE FROM `quest_template_addon` WHERE `ID` IN (58902, 58903);
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(58902, 0, 0, 0, 58877, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(58903, 0, 0, 0, 58877, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 25082;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 25082, 0, 0, 1, 9, 0, 58903, 0, 0, 0, 0, 0, '', 'Show Gossip if Quest 58903 (H) is taken'),
(15, 25082, 0, 0, 1, 48, 0, 161709, 0, 0, 1, 0, 0, '', 'Show Gossip if Credit is not rewarded'),
(15, 25082, 0, 0, 2, 9, 0, 58902, 0, 0, 0, 0, 0, '', 'Show Gossip if Quest 58902 (A) is taken'),
(15, 25082, 0, 0, 2, 48, 0, 161709, 0, 0, 1, 0, 0, '', 'Show Gossip if Credit is not rewarded');

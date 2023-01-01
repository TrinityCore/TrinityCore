SET @CGUID_SL := 1051065;
SET @CGUID_BFA := 850251;
SET @CGUID_WOD := 460678;
SET @OGUID := 600226;

-- Update Position
UPDATE `creature` SET `position_x`= -8798.001953125, `position_y`= 882.82464599609375, `position_z`= 99.6070709228515625, `orientation`= 3.822909116744995117 WHERE `guid` = 314026; -- Lisa McKeever
UPDATE `creature` SET `position_x`= -8850.8681640625, `position_y`= 842.55902099609375, `position_z`= 98.729705810546875, `orientation`= 0.600934863090515136 WHERE `guid` = 314020; -- Robby Flay
UPDATE `creature` SET `position_x`= -8851.642578125, `position_y`= 844.83856201171875, `position_z`= 98.7289276123046875, `orientation`= 6.220456123352050781 WHERE `guid` = 313882; -- Jon Casper

UPDATE `gameobject` SET `position_x`= -8852.763671875, `position_y`= 844.42364501953125, `position_z`= 99.9567108154296875, `orientation`= 1.736326098442077636, `rotation0`= 0.013906478881835937, `rotation1`= 0.007083892822265625, `rotation2`= 0.763106346130371093, `rotation3`= 0.646084487438201904 WHERE `guid` = 220051; -- Cookpot

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID_SL+0 AND @CGUID_SL+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID_SL+0, 188678, 0, 1519, 8411, '0', 0, 0, 0, 1, -8810.4794921875, 839.16143798828125, 99.34540557861328125, 1.355204343795776367, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325), -- Worker (Area: -Unknown- - Difficulty: 0)
(@CGUID_SL+1, 188679, 0, 1519, 8411, '0', 0, 0, 0, 1, -8829.6513671875, 839.015625, 99.6059417724609375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325), -- Worker (Area: -Unknown- - Difficulty: 0)
(@CGUID_SL+2, 188342, 0, 1519, 5390, '0', 0, 0, 0, 0, -8811.3408203125, 827.5867919921875, 100.5854339599609375, 2.220740079879760742, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325); -- Onnesa (Area: The Canals - Difficulty: 0)

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID_BFA+0 AND @CGUID_BFA+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID_BFA+0, 157498, 0, 1519, 5151, '0', 0, 0, 0, 0, -8648.2880859375, 729.56597900390625, 98.29361724853515625, 0.5634002685546875, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325), -- Mrs. Fuzzles (Area: Cathedral Square - Difficulty: 0) (Auras: 307181 - -Unknown-)
(@CGUID_BFA+1, 157496, 0, 1519, 5151, '0', 0, 0, 0, 0, -8648.0908203125, 729.15277099609375, 98.2200469970703125, 0.606558382511138916, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325); -- Mr. Fuzzles (Area: Cathedral Square - Difficulty: 0) (Auras: 307179 - -Unknown-)

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID_WOD+0 AND @CGUID_WOD+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID_WOD+0, 83878, 0, 1519, 5151, '0', 0, 0, 0, 0, -8633.2138671875, 722.08856201171875, 97.06989288330078125, 1.865211844444274902, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325), -- Jennica Holzman (Area: Cathedral Square - Difficulty: 0) (Auras: 167804 - Jennica Visual)
(@CGUID_WOD+1, 83890, 0, 1519, 5151, '0', 0, 0, 0, 0, -8633.2236328125, 722.86456298828125, 96.98580169677734375, 5.055857658386230468, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325), -- Painting (Area: Cathedral Square - Difficulty: 0) (Auras: 167790 - Painting Visual)
(@CGUID_WOD+2, 83882, 0, 1519, 5151, '0', 0, 0, 0, 0, -8632.779296875, 722.232666015625, 97.86815643310546875, 2.823319196701049804, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325), -- Brain (Area: Cathedral Square - Difficulty: 0)
(@CGUID_WOD+3, 83883, 0, 1519, 5151, '0', 0, 0, 0, 0, -8634.2041015625, 720.39776611328125, 97.79681396484375, 1.222634553909301757, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 44325); -- Peeps (Area: Cathedral Square - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID_SL+0 AND @CGUID_SL+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID_SL+0, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Worker
(@CGUID_SL+1, 0, 0, 0, 1, 173, 0, 0, 0, 0, ''); -- Worker

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180007, 0, 1519, 5390, '0', 0, 0, -8828.5283203125, 838.9132080078125, 99.50035858154296875, 0, 0, 0, 0, 1, 120, 255, 1, 44325), -- Excavation Stake (Area: The Canals - Difficulty: 0)
(@OGUID+1, 180007, 0, 1519, 5390, '0', 0, 0, -8833.1025390625, 836.625, 99.5650787353515625, 5.049305915832519531, 0, 0, -0.57854175567626953, 0.815652728080749511, 120, 255, 1, 44325); -- Excavation Stake (Area: The Canals - Difficulty: 0)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (157496 /*157496 (Mr. Fuzzles) - -Unknown-*/, 83890 /*83890 (Painting) - Painting Visual*/, 83878 /*83878 (Jennica Holzman) - Jennica Visual*/, 83882 /*83882 (Brain)*/, 157498 /*157498 (Mrs. Fuzzles) - -Unknown-*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(157496, 0, 0, 0, 257, 0, 0, 0, 0, 0, '307179'), -- 157496 (Mr. Fuzzles) - -Unknown-
(83890, 0, 0, 0, 1, 0, 0, 0, 0, 0, '167790'), -- 83890 (Painting) - Painting Visual
(83882, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- 83882 (Brain)
(83878, 0, 0, 50331648, 1, 426, 0, 0, 0, 0, '167804'), -- 83878 (Jennica Holzman) - Jennica Visual
(157498, 0, 0, 1, 1, 0, 0, 0, 0, 0, '307181'); -- 157498 (Mrs. Fuzzles) - -Unknown-

-- Template Data
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=83883; -- Peeps
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=157496; -- Mr. Fuzzles
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=83882; -- Brain
UPDATE `creature_template` SET `minlevel`=60, `unit_flags3`=16777216 WHERE `entry`=83890; -- Painting
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=83878; -- Jennica Holzman
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=157498; -- Mrs. Fuzzles
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=12, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry` IN (188679, 188678); -- Worker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=12, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=188342; -- Onnesa

-- Model stuff
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (188678,188342,188679,133509));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(188678, 0, 0, 0, 864, 44325),
(188342, 0, 0, 0, 864, 44325),
(188679, 0, 0, 0, 864, 44325),
(133509, 0, 0, 0, 293, 44325);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=44325 WHERE (`DifficultyID`=0 AND `Entry` IN (3505,3520,3513,1350,14497,50424,3512,10782,133441,1444,3511,1405,3510,1349,54117,3504,2331,54026,3509,2330,51348,3508,1646,111190,49540,66876,3507,1976,42339,108180,32520,83883,157496,68,14450,83882,83890,50432,83878,157498));
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-4, `LevelScalingDeltaMax`=-4, `VerifiedBuild`=44325 WHERE (`Entry`=53626 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-3, `LevelScalingDeltaMax`=-2, `VerifiedBuild`=44325 WHERE (`Entry`=14496 AND `DifficultyID`=0);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (83234, 106441, 106457, 83235);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(83234, 1, 1.5, 0, 44325),
(106441, 0.347000002861022949, 1.5, 0, 44325),
(106457, 0.347000002861022949, 1.5, 0, 44325),
(83235, 0.347222000360488891, 1.5, 0, 44325);

DELETE FROM `creature_template_model` WHERE (`Idx`=0 AND `CreatureID` IN (188679,188342,188678));
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(188679, 0, 106457, 1, 1, 44325), -- Worker
(188342, 0, 106441, 1, 1, 44325), -- Onnesa
(188678, 0, 106457, 1, 1, 44325); -- Worker

-- Equip Template
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (188679,188678));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(188679, 1, 157585, 0, 0, 0, 0, 0, 0, 0, 0, 44325), -- Worker
(188678, 1, 157585, 0, 0, 0, 0, 0, 0, 0, 0, 44325); -- Worker

-- NPC Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (157496, 157498);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(157496, 224326, 1, 0),
(157498, 224326, 1, 0);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID`=66390;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(66390, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah! Ye got  seawater on the merchandise! Ah well, I don\'t think the Seabraids will mind too much... long as it\'s intact.', 44325); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID`=66390;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(66390, 0, 0, 0, 0, 0, 0, 0, 0, 44325); -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID`=66390;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(66390, 0, 0, 0, 0, 'Throw the briny seawater at the thief to get the merchandise back.', 44325); -- Missing Merchandise

DELETE FROM `creature_queststarter` WHERE (`id`=188342 AND `quest`=66390);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(188342, 66390, 44325); -- -Unknown- offered Onnesa

DELETE FROM `creature_questender` WHERE (`id`=188342 AND `quest`=66390);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(188342, 66390, 44325); -- -Unknown- ended by Onnesa

DELETE FROM `quest_poi` WHERE (`QuestID`=66390 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=66390 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=66390 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=66390 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(66390, 0, 3, 32, 0, 0, 0, 84, 0, 0, 0, 0, 0, 2189043, 0, 44325), -- Missing Merchandise
(66390, 0, 2, 1, 426863, 188389, 0, 84, 0, 0, 0, 0, 0, 2189143, 0, 44325), -- Missing Merchandise
(66390, 0, 1, 0, 426862, 188371, 0, 84, 0, 0, 0, 0, 0, 2189105, 0, 44325), -- Missing Merchandise
(66390, 0, 0, -1, 0, 0, 0, 84, 0, 0, 0, 0, 0, 2189043, 0, 44325); -- Missing Merchandise

DELETE FROM `quest_poi_points` WHERE (`QuestID`=66390 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=66390 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=66390 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=66390 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(66390, 3, 0, -8831, 837, 100, 44325), -- Missing Merchandise
(66390, 2, 0, -8437, 1226, 5, 44325), -- Missing Merchandise
(66390, 1, 0, -8438, 1226, 5, 44325), -- Missing Merchandise
(66390, 0, 0, -8831, 837, 100, 44325); -- Missing Merchandise

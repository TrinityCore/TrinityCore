SET @NPC_VISION_OF_THE_PAST         := 42693;
SET @NPC_VANESSA_VANCLEEF           := 42371;
SET @NPC_EDWIN_VANCLEEF             := 42697;
SET @NPC_DEFIAS_BLACKGUARD          := 42698;
SET @NPC_ALLIANCE_WARRIOR           := 42699;
SET @NPC_ALLIANCE_ROGUE             := 42700;
SET @NPC_ALLIANCE_PRIEST            := 42703;
SET @NPC_ALLIANCE_HUNTER            := 42701;
SET @NPC_ALLIANCE_MAGE              := 42702;

SET @QUEST_VISION_OF_THE_PAST       := 26320;
SET @GO_ENTRANCE_OF_DEADMINES       := 204039;
SET @GGUID                          := 350000;
SET @CGUID                          := 470051;

UPDATE `creature_template` SET `VehicleId` = 916, `InhabitType` = 3, `MovementType` = 2, `ScriptName` = 'npc_vision_of_the_past' WHERE `entry` = @NPC_VISION_OF_THE_PAST;
UPDATE `quest_template_addon` SET `SpecialFlags` = 2 WHERE `ID` = @QUEST_VISION_OF_THE_PAST;

DELETE FROM `gameobject_template`
WHERE `entry` = @GO_ENTRANCE_OF_DEADMINES;

INSERT INTO `gameobject_template`
 (`entry`, `type`, `displayId`, `name`, `data0`, `data1`, `data2`, `data3`, `size`, `VerifiedBuild`) VALUES
(@GO_ENTRANCE_OF_DEADMINES, 8, 9179, 'Entrance of the Deadmines', 1673, 30, 0, 1, 1, -18019);

DELETE FROM `gameobject` WHERE `guid` = @GGUID+0;
INSERT INTO `gameobject`
    (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`)
VALUES
    (@GGUID+0, @GO_ENTRANCE_OF_DEADMINES, 36, 0, 0, 6, 0, 0, -15.9539, -380.902, 61.71, 2.24677, -0, -0, -0.901571, -0.432632, 300, 255, 1, '', 0);
	


UPDATE `creature_template` SET `ScriptName` = 'npc_dm_alliance_warrior' WHERE `entry` = @NPC_ALLIANCE_WARRIOR;
UPDATE `creature_template` SET `ScriptName` = 'npc_dm_alliance_rogue' WHERE `entry` = @NPC_ALLIANCE_ROGUE;
UPDATE `creature_template` SET `unit_class` = 8, `ScriptName` = 'npc_dm_alliance_priest' WHERE `entry` = @NPC_ALLIANCE_PRIEST;
UPDATE `creature_template` SET `ScriptName` = 'npc_dm_alliance_hunter' WHERE `entry` = @NPC_ALLIANCE_HUNTER;
UPDATE `creature_template` SET `unit_class` = 8, `ScriptName` = 'npc_dm_alliance_mage' WHERE `entry` = @NPC_ALLIANCE_MAGE;
UPDATE `creature_template` SET `ScriptName` = 'npc_dm_edwin_vancleef' WHERE `entry` = @NPC_EDWIN_VANCLEEF;
UPDATE `creature_template` SET `ScriptName` = 'npc_dm_vanessa_vancleef' WHERE `entry` = @NPC_VANESSA_VANCLEEF;
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 128, `type_flags` = `type_flags` | 1048576 WHERE `entry` = @NPC_VISION_OF_THE_PAST;

DELETE FROM `creature_text` WHERE `CreatureID` IN (@NPC_VANESSA_VANCLEEF, @NPC_VISION_OF_THE_PAST, @NPC_EDWIN_VANCLEEF, @NPC_DEFIAS_BLACKGUARD, @NPC_ALLIANCE_WARRIOR);

INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`)
 VALUES
 
    (@NPC_VANESSA_VANCLEEF, 0, 0, 'Father...', 12, 0, 100, 0, 0, 0, 38143,0, 'Vanessa van Cleef to Edwin van Cleef'),
    (@NPC_VISION_OF_THE_PAST, 0, 0, '|cFF768EBDFive years ago, in the heart of the Deadmines...|r |TInterface\\QuestFrame\\UI-QUESTLOG-BOOKICON.BLP:32|t', 42, 0, 100, 0, 0, 0, 42864,0, 'Vision of the past to Player'),
    (@NPC_EDWIN_VANCLEEF, 0, 0, 'None may challenge the Brotherhood!', 14, 0, 100, 0, 0, 5780, 6061,0, 'Edwin van Cleef to Leader of Alliance'),
    (@NPC_EDWIN_VANCLEEF, 1, 1, 'Lapdogs, all of you!', 14, 0, 100, 0, 0, 5782, 6063, 0,'Edwin van Cleef'),
    (@NPC_EDWIN_VANCLEEF, 2, 2, '%s calls more of his allies out of the shadows.', 16, 0, 100, 0, 0, 0, 1048,0, 'Edwin van Cleef'),
    (@NPC_EDWIN_VANCLEEF, 3, 3, 'Fools! Our cause is righteous!', 14, 0, 100, 0, 0, 5783, 6064, 0,'Edwin van Cleef'),
    (@NPC_EDWIN_VANCLEEF, 4, 4, 'The Brotherhood shall prevail!', 14, 0, 100, 0, 0, 5784, 6065,0, 'Edwin van Cleef'),
    (@NPC_DEFIAS_BLACKGUARD, 0, 0, '%s jumps out of the shadows!', 16, 0, 100, 0, 0, 5780, 1327, 0,'Defias Blackguard'),
    (@NPC_ALLIANCE_WARRIOR, 0, 0, 'There''s nowhere left to hide, VanCleef! The Defias are THROUGH!', 14, 0, 100, 22, 0, 0, 42593, 0,'Warrior no hide'),
    (@NPC_ALLIANCE_WARRIOR, 1, 1, 'We''re here to finish this! Face us, coward!', 14, 0, 100, 397, 0, 0, 42594, 0,'Warrior Face us'),
    (@NPC_ALLIANCE_WARRIOR, 2, 2, 'Victory for the Alliance! Glory to Stormwind!', 14, 0, 100, 5, 0, 0, 42602, 0,'Victory speech'),
    (@NPC_ALLIANCE_WARRIOR, 3, 3, 'Let us return to Sentinel Hill, allies, and inform Gryan of VanCleef''s demise!', 12, 0, 100, 396, 0, 0, 42603, 0,'Go home speech');
	
-- remove elite spawn Shattered Hand Assassin from just inside deadmines (should not be there and kills any level 15)
DELETE FROM `creature`
WHERE `guid` = 319266;

DELETE FROM `creature_addon`
WHERE `guid` = 319266;

-- fix up location for quest activation
UPDATE `quest_poi`
SET `WorldMapAreaId` = 756,
`MapID` = 36,
`Floor` = 1,
`ObjectiveIndex` = 0
WHERE `QuestID` = @QUEST_VISION_OF_THE_PAST
AND `BlobIndex` = 1;

UPDATE `quest_poi_points`
SET `X` = -13.1835,
`Y` = -381.492
WHERE QuestID = @QUEST_VISION_OF_THE_PAST
AND `Idx1` = 1;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+72;
INSERT INTO `creature`
    (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`)
VALUES
    (@CGUID+0, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -22.50987, -735.738, 8.686784, 5.323254, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+1, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -96.44043, -721.125, 8.531245, 3.944444, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+2, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -133.0663, -767.8922, 3.543654, 1.361357, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+3, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -76.81461, -788.7315, 38.95218, 0.8377581, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+4, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -15.10335, -724.5633, 8.090608, 1.32645, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+5, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -90.04047, -720.5564, 8.737201, 5.916666, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+6, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -41.06592, -730.6678, 9.128899, 4.625123, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+7, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -60.324, -731.8401, 9.032983, 2.129302, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+8, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -98.68034, -778.7611, 22.38657, 3.036873, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+9, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -79.49192, -782.498, 17.5752, 2.600541, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+10, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -32.14719, -727.7289, 8.616197, 0.5759587, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+11, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -90.15733, -785.6263, 26.98226, 2.96706, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+12, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -140.6695, -760.6517, 4.81889, 1.518436, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+13, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -57.31386, -783.428, 18.19203, 2.565634, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+14, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -48.0472, -684.4057, 4.596326, 1.291544, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+15, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -186.7083, -702.1927, 8.918094, 0.6108652, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+16, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -75.41987, -783.7542, 26.45467, 3.01942, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+17, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -33.80257, -691.1212, 4.71141, 5.410521, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+18, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -103.6993, -722.2738, 8.723626, 4.956735, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+19, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -79.45508, -729.1056, 9.127749, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+20, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -83.13623, -776.0989, 26.92174, 0.2268928, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+21, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -50.13552, -723.3418, 9.07696, 1.48353, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+22, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -120.8559, -698.0835, 8.76521, 4.485496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+23, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -93.48991, -787.3896, 17.21836, 1.815142, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+24, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -124.0684, -683.4753, 10.38857, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+25, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -28.81776, -795.674, 19.39633, 6.021386, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+26, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -99.18131, -803.6932, 30.80697, 2.391101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+27, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -41.9822, -798.9504, 39.49167, 5.916666, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+28, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -9.918023, -740.4199, 9.010332, 2.059489, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+29, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, 6.701226, -766.3807, 9.713189, 2.251475, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+30, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -41.58344, -788.5656, 18.79488, 4.869469, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+31, 646, 36, 1581, 1581, 6, '231', 0, 0, 0, -22.84722, -797.283, 20.37448, 1.047198, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 646 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death, 6433 - Nimble Reflex III)
    (@CGUID+32, 636, 36, 1581, 1581, 6, '231', 0, 0, 0, -0.314236, -783.8108, 10.09053, 1.151917, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 636 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+33, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -77.8201, -797.2148, 38.52706, 3.944444, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+34, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -65.18815, -793.1549, 39.62711, 2.70526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+35, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -51.55382, -789.9189, 38.74467, 2.094395, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+36, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -122.8816, -789.1121, 17.37205, 5.445427, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+37, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -130.5561, -790.1776, 17.52842, 2.80998, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+38, 647, 36, 1581, 1581, 6, '231', 0, 0, 0, -65.44444, -807.1702, 41.15707, 4.502949, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 647 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+39, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -105.6016, -793.749, 28.19328, 5.201081, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+40, 636, 36, 1581, 1581, 6, '231', 0, 0, 0, -5.206597, -778.9323, 9.773645, 0.8377581, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 636 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+41, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -123.1302, -805.6942, 16.98653, 5.201081, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+42, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -71.15972, -808.5364, 40.63942, 2.338741, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+43, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -124.2846, -823.3812, 16.97721, 1.972222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+44, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -110.961, -795.7646, 17.1208, 2.146755, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+45, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -57.48264, -808.0521, 41.88113, 0.3665192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+46, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -47.2258, -784.883, 18.46813, 4.118977, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+47, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -83.38667, -791.3992, 25.8925, 5.811946, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+48, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -21.87397, -802.9406, 19.76329, 1.727876, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+49, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -103.2768, -847.4097, 17.20318, 4.049164, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+50, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -141.8611, -874.6312, 1.583545, 4.031711, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+51, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -116.1847, -837.8405, 17.12631, 3.752458, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+52, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -19.51221, -830.9886, 19.89779, 5.899213, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+53, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -154.9963, -891.8146, 5.643324, 3.054326, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+54, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -153.1819, -908.9996, 8.727186, 2.617994, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+55, 645, 36, 1581, 1581, 6, '231', 0, 0, 0, -69.74132, -849.8871, 17.00283, 2.391101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 645 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+56, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -120.7615, -835.8884, 16.97598, 3.560472, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+57, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -20.79747, -835.3904, 19.74278, 3.630285, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+58, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -149.1771, -918.8044, 12.4227, 2.408554, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+59, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -89.81407, -853.7393, 17.39273, 1.867502, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+60, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -30.58002, -843.1054, 19.32838, 3.822271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+61, 657, 36, 1581, 1581, 6, '231', 0, 0, 0, -146.1408, -906.0359, 8.178946, 4.049164, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 657 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+62, 1732, 36, 1581, 1581, 6, '231', 0, 0, 0, -85.11046, -856.5533, 17.3856, 3.368485, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 1732 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+63, 3947, 36, 1581, 1581, 6, '231', 0, 0, 0, -44.10569, -853.0803, 18.63523, 4.031711, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 3947 (Area: The Deadmines - Difficulty: Normal) (Auras: 29266 - Feign Death)
    (@CGUID+64, 42701, 36, 1581, 0, 6, '231', 0, 0, 0, -61.40104, -821.882, 41.52324, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42701 (Area: 0 - Difficulty: Normal) (Auras: )
    (@CGUID+65, 42697, 36, 1581, 0, 6, '231', 0, 0, 0, -87.36979, -819.8958, 39.30045, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42697 (Area: 0 - Difficulty: Normal) (Auras: )
    (@CGUID+66, 42702, 36, 1581, 0, 6, '231', 0, 0, 0, -58.5382, -819.1337, 41.79993, 3.071779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42702 (Area: 0 - Difficulty: Normal) (Auras: )
    (@CGUID+67, 42698, 36, 1581, 0, 6, '231', 0, 0, 0, -77.80729, -815.0972, 40.01878, 3.263766, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42698 (Area: 0 - Difficulty: Normal) (Auras: 6408 - Faded)
    (@CGUID+68, 42703, 36, 1581, 0, 6, '231', 0, 0, 0, -61.44097, -816.7239, 41.51037, 2.96706, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42703 (Area: 0 - Difficulty: Normal) (Auras: 13864 - Command: Soulstrength)
    (@CGUID+69, 42698, 36, 1581, 0, 6, '231', 0, 0, 0, -78.27952, -824.7847, 40.00071, 2.932153, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42698 (Area: 0 - Difficulty: Normal) (Auras: 6408 - Faded)
    (@CGUID+70, 42700, 36, 1581, 0, 6, '231', 0, 0, 0, -60.69618, -819.1945, 41.58845, 3.054326, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42700 (Area: 0 - Difficulty: Normal) (Auras: 60847 - Slice and Dice)
    (@CGUID+71, 42699, 36, 1581, 0, 6, '231', 0, 0, 0, -63.06597, -819.1649, 41.35357, 3.054326, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015), -- 42699 (Area: 0 - Difficulty: Normal) (Auras: )
    (@CGUID+72, 42371, 36, 1581, 0, 6, '231', 0, 0, 0, -82.74338, -819.6807, 39.63371, 6.253996, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 24015); -- 42371 (Area: 0 - Difficulty: Normal)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+72;
INSERT INTO `creature_addon`
    (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`)
VALUES
    (@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, '29266 6433'), -- 646 - 29266 - Feign Death, 6433 - Nimble Reflex III
    (@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 636 - 29266 - Feign Death
    (@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 647 - 29266 - Feign Death
    (@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 636 - 29266 - Feign Death
    (@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 645 - 29266 - Feign Death
    (@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 657 - 29266 - Feign Death
    (@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 1732 - 29266 - Feign Death
    (@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, '29266'), -- 3947 - 29266 - Feign Death
    (@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 42701
    (@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 42697
    (@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 42702
    (@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '6408'), -- 42698 - 6408 - Faded
    (@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, '13864'), -- 42703 - 13864 - Command: Soulstrength
    (@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, '6408'), -- 42698 - 6408 - Faded
    (@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, '60847'), -- 42700 - 60847 - Slice and Dice
    (@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 42699
    (@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 42371
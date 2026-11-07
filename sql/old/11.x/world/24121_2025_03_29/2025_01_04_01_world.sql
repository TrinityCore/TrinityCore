SET @LCGUID 	:= 6001071;
SET @SLCGUID	:= 8000063;

SET @LOGUID		:= 6000605;
SET @BFAOGUID	:= 7000368;
SET @SLOGUID	:= 8000021;
SET @WWOGUID	:= 10001356;

-- Creature (Legion)
DELETE FROM `creature` WHERE `guid` = @LCGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@LCGUID+0, 126332, 0, 1519, 9171, '0', 0, 0, 0, 0, -8151.033203125, 818.5538330078125, 75.80060577392578125, 3.977140188217163085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Aysa Cloudsinger (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- Creature (Shadowlands)
DELETE FROM `creature` WHERE `guid` = @SLCGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@SLCGUID+0, 167032, 0, 1519, 9171, '0', 0, 0, 0, 0, -8196.3095703125, 745.33856201171875, 78.415435791015625, 1.435181260108947753, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Chromie (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- GameObject (Legion)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @LOGUID+0 AND @LOGUID+24;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@LOGUID+0, 278332, 0, 1519, 9171, '0', 0, 0, -8158.24755859375, 814.6324462890625, 75.7172698974609375, 2.33001255989074707, 0, 0, 0.918790817260742187, 0.394744753837585449, 120, 255, 1, 58238), -- Bench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+1, 232235, 0, 1519, 9171, '0', 0, 0, -8185.623046875, 864.94805908203125, 70.01805877685546875, 3.851733207702636718, 0, 0, -0.9376220703125, 0.34765625, 120, 255, 1, 58238), -- Woodbench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+2, 278333, 0, 1519, 9171, '0', 0, 0, -8161.1572265625, 817.72943115234375, 75.7172698974609375, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 58238), -- Bench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+3, 232224, 0, 1519, 9171, '0', 0, 0, -8182.42578125, 861.87860107421875, 70.01805877685546875, 3.902530431747436523, 0, 0, -0.92849063873291015, 0.371355801820755004, 120, 255, 1, 58238), -- Woodbench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+4, 232225, 0, 1519, 9171, '0', 0, 0, -8185.12548828125, 858.0399169921875, 70.01805877685546875, 0.807585895061492919, 0, 0, 0.392909049987792968, 0.919577360153198242, 120, 255, 1, 58238), -- Woodbench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+5, 227906, 0, 1519, 9171, '0', 0, 0, -8139.892578125, 868.665771484375, 76.43599700927734375, 0.829028248786926269, 0, 0, 0.402745246887207031, 0.915312111377716064, 120, 255, 1, 58238), -- Anvil (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+6, 227907, 0, 1519, 9171, '0', 0, 0, -8141.93701171875, 862.1610107421875, 75.70650482177734375, 4.337140560150146484, 0, 0, -0.82659053802490234, 0.56280374526977539, 120, 255, 1, 58238), -- Keg Stand (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+7, 278324, 0, 1519, 9171, '0', 0, 0, -8166.53955078125, 818.25762939453125, 75.89896392822265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 58238), -- Chair (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+8, 227908, 0, 1519, 9171, '0', 0, 0, -8138.76318359375, 864.8076171875, 76.54122161865234375, 3.586656570434570312, 0, 0, -0.975341796875, 0.220699742436408996, 120, 255, 1, 58238), -- Log Bundle (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+9, 278325, 0, 1519, 9171, '0', 0, 0, -8166.93310546875, 815.52960205078125, 75.89896392822265625, 2.59181070327758789, 0, 0, 0.962454795837402343, 0.271441996097564697, 120, 255, 1, 58238), -- Chair (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+10, 227909, 0, 1519, 9171, '0', 0, 0, -8134.2763671875, 862.94952392578125, 76.27972412109375, 2.068211555480957031, 0, 0, 0.859405517578125, 0.51129460334777832, 120, 255, 1, 58238), -- Forge (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+11, 278326, 0, 1519, 9171, '0', 0, 0, -8155.22314453125, 811.36871337890625, 75.7172698974609375, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 58238), -- Bench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+12, 278327, 0, 1519, 9171, '0', 0, 0, -8152.15087890625, 808.314453125, 75.7172698974609375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 58238), -- Bench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+13, 278310, 0, 1519, 9171, '0', 0, 0, -8173.923828125, 801.70489501953125, 74.3568267822265625, 3.961903095245361328, 0, 0, -0.91705894470214843, 0.398751676082611083, 120, 255, 1, 58238), -- Mailbox (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+14, 278328, 0, 1519, 9171, '0', 0, 0, -8150.18212890625, 823.91436767578125, 75.7172698974609375, 4.3633270263671875, 0, 0, -0.81915092468261718, 0.573578059673309326, 120, 255, 1, 58238), -- Chair (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+15, 278311, 0, 1519, 9171, '0', 0, 0, -8205.126953125, 824.01739501953125, 70.47891998291015625, 5.576327323913574218, 0, 0, -0.34611701965332031, 0.938191354274749755, 120, 255, 1, 58238), -- Bonfire (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+16, 278329, 0, 1519, 9171, '0', 0, 0, -8145.36669921875, 819.0809326171875, 75.7172698974609375, 3.447027206420898437, 0, 0, -0.98836135864257812, 0.152124300599098205, 120, 255, 1, 58238), -- Chair (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+17, 278330, 0, 1519, 9171, '0', 0, 0, -8151.375, 805.238525390625, 75.966461181640625, 1.422442793846130371, 0, 0, 0.652759552001953125, 0.757565200328826904, 120, 255, 1, 58238), -- Chair (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+18, 278331, 0, 1519, 9171, '0', 0, 0, -8148.20556640625, 821.5069580078125, 75.7172698974609375, 3.918267250061035156, 0, 0, -0.92553997039794921, 0.378649920225143432, 120, 255, 1, 58238), -- Chair (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+19, 232234, 0, 1519, 9171, '0', 0, 0, -8187.51416015625, 860.9403076171875, 70.01805877685546875, 0.807509124279022216, 0, 0, 0.392873764038085937, 0.91959238052368164, 120, 255, 1, 58238), -- Woodbench (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+20, 273853, 0, 1519, 9171, '0', 0, 0, -8148.3818359375, 815.60418701171875, 75.4190216064453125, 3.899293422698974609, 0, 0, -0.92909049987792968, 0.369852513074874877, 120, 255, 0, 58238), -- Void Elf (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+21, 273855, 0, 1519, 9171, '0', 0, 0, -8154.42724609375, 822.00518798828125, 75.52974700927734375, 3.899293422698974609, 0, 0, -0.92909049987792968, 0.369852513074874877, 120, 255, 1, 58238), -- Lightforged Draenei (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+22, 218719, 0, 1519, 9171, '0', 0, 0, -8203.171875, 651.4913330078125, 67.15387725830078125, 0, 0, 0, 0, 1, 120, 255, 1, 58238), -- Raft (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+23, 267647, 0, 1519, 9171, '0', 0, 0, -8265.9912109375, 742.64410400390625, 78.39960479736328125, 1.194282293319702148, 0, 0, 0.562280654907226562, 0.826946437358856201, 120, 255, 1, 58238), -- Paladin - Scenario - Cosmetic Item (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@LOGUID+24, 267647, 0, 1519, 9171, '0', 0, 0, -8265.951171875, 744.76043701171875, 78.39960479736328125, 6.018938064575195312, 0, 0, -0.13173961639404296, 0.991284370422363281, 120, 255, 1, 58238); -- Paladin - Scenario - Cosmetic Item (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @LOGUID+0 AND @LOGUID+24;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@LOGUID+0, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Bench
(@LOGUID+1, 0, 0, -0.38671103119850158, 0.922200918197631835, 0, 0), -- Woodbench
(@LOGUID+2, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Bench
(@LOGUID+3, 0, 0, -0.38671103119850158, 0.922200918197631835, 0, 0), -- Woodbench
(@LOGUID+4, 0, 0, -0.38671103119850158, 0.922200918197631835, 0, 0), -- Woodbench
(@LOGUID+5, 0, 0, 0.96814805269241333, -0.2503785490989685, 0, 0), -- Anvil
(@LOGUID+6, 0, 0, 0.96814805269241333, -0.2503785490989685, 0, 0), -- Keg Stand
(@LOGUID+7, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Chair
(@LOGUID+8, 0, 0, 0.96814805269241333, -0.2503785490989685, 0, 0), -- Log Bundle
(@LOGUID+9, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Chair
(@LOGUID+10, 0, 0, 0.96814805269241333, -0.2503785490989685, 0, 0), -- Forge
(@LOGUID+11, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Bench
(@LOGUID+12, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Bench
(@LOGUID+14, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Chair
(@LOGUID+16, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Chair
(@LOGUID+17, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Chair
(@LOGUID+18, 0, 0, 0.925540387630462646, -0.37864893674850463, 0, 0), -- Chair
(@LOGUID+19, 0, 0, -0.38671103119850158, 0.922200918197631835, 0, 0); -- Woodbench

-- Gameobject (Battle for Azeroth)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @BFAOGUID+0 AND @BFAOGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@BFAOGUID+0, 298865, 0, 1519, 9171, '0', 0, 0, -8156.3125, 823.74481201171875, 76.10884857177734375, 3.92230224609375, 0, 0, -0.924774169921875, 0.380516409873962402, 120, 255, 1, 58238), -- Dark Iron Dwarf (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@BFAOGUID+1, 339222, 0, 1519, 9171, '0', 0, 0, -8151.00341796875, 825.953125, 75.7172698974609375, 3.837418556213378906, 0, 0, -0.94008636474609375, 0.34093642234802246, 120, 255, 1, 58238), -- Mechagnome (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@BFAOGUID+2, 316736, 0, 1519, 9171, '0', 0, 0, -8146.38916015625, 814.06597900390625, 75.7172698974609375, 3.893828630447387695, 0, 0, -0.93009757995605468, 0.367312550544738769, 120, 255, 1, 58238); -- Kul Tiran (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- GameObject (Shadowlands)
DELETE FROM `gameobject` WHERE `guid` = @SLOGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@SLOGUID+0, 350063, 0, 1519, 9171, '0', 0, 0, -8196.39453125, 744.904541015625, 76.43845367431640625, 0.205067232251167297, 0, 0, 0.102354049682617187, 0.994748055934906005, 120, 255, 1, 58238); -- Chromie's Hourglass (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- GameObject (War Within)
DELETE FROM `gameobject` WHERE `guid` = @WWOGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@WWOGUID+0, 452030, 0, 1519, 9171, '0', 0, 0, -8143.05908203125, 818.43231201171875, 75.71726226806640625, 3.863133907318115234, 0, 0, -0.93562507629394531, 0.352995336055755615, 120, 255, 1, 58238); -- Earthen (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry`=452030;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(452030, 0, 0x40000, 0, 0); -- Earthen

DELETE FROM `creature_template_addon` WHERE `entry` = 167032; -- 167032 (Chromie)
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(167032, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 167032 (Chromie)

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=126332 AND `MenuID`=22198);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(126332, 22198, 58238); -- Aysa Cloudsinger

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (58214 /*Urgent Care*/, 54706 /*Made in Kul Tiras*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(58214, 1, 0, 0, 0, 0, 0, 0, 0, 58238), -- Urgent Care
(54706, 0, 0, 0, 0, 0, 0, 0, 0, 58238); -- Made in Kul Tiras

UPDATE `quest_details` SET `VerifiedBuild`=58238 WHERE `ID` IN (51813, 49787, 49698, 50239);

DELETE FROM `creature_queststarter` WHERE (`id`=126332 AND `quest` IN (58214,54706,51813,49787,49698,50239));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(126332, 58214, 58238), -- Urgent Care offered by Aysa Cloudsinger
(126332, 54706, 58238), -- Made in Kul Tiras offered by Aysa Cloudsinger
(126332, 51813, 58238), -- Blackrock Depths offered by Aysa Cloudsinger
(126332, 49787, 58238), -- The Ghostlands offered by Aysa Cloudsinger
(126332, 49698, 58238), -- The Lightforged offered by Aysa Cloudsinger
(126332, 50239, 58238); -- A Choice of Allies offered by Aysa Cloudsinger

DELETE FROM `creature_questender` WHERE (`id`=126332 AND `quest` IN (50239,49929));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(126332, 50239, 58238), -- A Choice of Allies ended by Aysa Cloudsinger
(126332, 49929, 58238); -- The Call for Allies ended by Aysa Cloudsinger

DELETE FROM `quest_template_addon` WHERE `ID` IN (50239, 58214, 54706, 51813, 49787, 49698);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(50239, 0, 0, 0, 49929, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- A Choice of Allies
(58214, 0, 0, 0, 50239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Urgent Care
(54706, 0, 0, 0, 50239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Made in Kul Tiras
(51813, 0, 0, 0, 50239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Blackrock Depths
(49787, 0, 0, 0, 50239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Ghostlands
(49698, 0, 0, 0, 50239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Lightforged

SET @CGUID := 396149;
SET @OGUID := 244809;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=34382; -- Chapman
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=34383; -- Catrina
UPDATE `creature_template` SET `gossip_menu_id`=10518 WHERE `entry`=34435; -- Cheerful Human Spirit
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=34770; -- Macabre Marionette
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35249; -- Ghostly Human Celebrant

DELETE FROM `creature_template_addon` WHERE `entry` IN (34382, 34770);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(34382, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 34382 (Chapman)
(34770, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- 34770 (Macabre Marionette)

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35249; -- 35249 (Ghostly Human Celebrant) - Unseen, Shroud of Death
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34435; -- 34435 (Cheerful Human Spirit) - Unseen, Shroud of Death
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=10 WHERE `entry`=34383; -- 34383 (Catrina)

-- Gossips
DELETE FROM `gossip_menu` WHERE `MenuID`=34435;

DELETE FROM `gossip_menu` WHERE (`MenuID`=10518 AND `TextID`=14552);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10518, 14552, 46366); -- 35249 (Ghostly Human Celebrant)

UPDATE `gossip_menu` SET `VerifiedBuild`=46366 WHERE (`MenuID`=10512 AND `TextID`=14543);

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (34382, 34383, 34435, 34770, 35249);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(34382, 0, 0, 0, 414, 46366),
(34383, 0, 0, 0, 414, 46366),
(34435, 0, 0, 0, 414, 46366),
(34770, 0, 0, 0, 371, 46366),
(35249, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (176246,176245,176243,176242,176241,176240,176239,176238,176236,176234,176231,176227,176225,176224,176223,176222,173819,172572,133675,112698,112686,111190,51348,50435,50434,49540,44880,42782,42421,32520,29712,20716,15214,6173,5489,5484,4982,4075,1976,1412,1212,721,376,68));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=0 AND `CreatureID` IN (176243,34435,5489,165516,176246,4982,176238,176245,5484,4075,50435,176242,1412,376,49540,29712,111190,176222,173819,50434,42782,34383,32520,176225,35249,304,112698,65011,176234,176224,176241,71486,176223,51348,176239,133675,35362,176231,44880,40229,172572,721,14505,1212,20716,68,47654,34382,18362,15214,42421,176227,308,176236,112686,1976,305,6173,176240,64993)) OR (`Idx`=2 AND `CreatureID` IN (4075,49540,29712,112698,68,42421,112686)) OR (`Idx`=1 AND `CreatureID` IN (4075,49540,29712,111190,32520,35249,112698,51348,133675,721,68,15214,42421,112686,1976)) OR (`Idx`=3 AND `CreatureID` IN (29712,112698,68));

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (100186, 100185, 100180, 100179, 100178, 100177, 100176, 100175, 100173, 100171, 100169, 100166, 100164, 100163, 100162, 100161, 98599, 98008, 46929, 18890, 18889, 68845, 37311, 37310, 36792, 36791, 2176, 1418, 34160, 1659, 18055, 29226, 29204, 29203, 19732, 4887, 3283, 3282, 262, 99389, 5548, 1495, 5446, 3167, 99391);
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=46366 WHERE `DisplayID` IN (29708, 29707);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=34382 AND `item`=116890 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34382 AND `item`=116891 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34382 AND `item`=116856 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34382 AND `item`=116889 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34382 AND `item`=116888 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34382 AND `item`=188689 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=34382 AND `item`=79048 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(34382, 13, 116890, 0, 0, 1, 0, 0, 46366), -- "Santo's Sun" Contender's Costume
(34382, 12, 116891, 0, 0, 1, 0, 0, 46366), -- "Snowy Owl" Contender's Costume
(34382, 11, 116856, 0, 0, 1, 0, 0, 46366), -- "Blooming Rose" Contender's Costume
(34382, 10, 116889, 0, 0, 1, 0, 0, 46366), -- "Purple Phantom" Contender's Costume
(34382, 9, 116888, 0, 0, 1, 0, 0, 46366), -- "Night Demon" Contender's Costume
(34382, 8, 188689, 0, 0, 1, 0, 0, 46366), -- Marigold Petal Offering Bowl
(34382, 5, 79048, 0, 0, 1, 0, 0, 46366); -- Whimsical Skull Mask

UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=46366 WHERE (`entry`=34382 AND `item`=46861 AND `ExtendedCost`=0 AND `type`=1); -- Bouquet of Orange Marigolds
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=46366 WHERE (`entry`=34382 AND `item`=46710 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Bread of the Dead
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=46366 WHERE (`entry`=34382 AND `item`=46860 AND `ExtendedCost`=0 AND `type`=1); -- Whimsical Skull Mask
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=46366 WHERE (`entry`=34382 AND `item`=46711 AND `ExtendedCost`=0 AND `type`=1); -- Spirit Candle
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=46366 WHERE (`entry`=34382 AND `item`=46718 AND `ExtendedCost`=0 AND `type`=1); -- Orange Marigold
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=46366 WHERE (`entry`=34382 AND `item`=46690 AND `ExtendedCost`=0 AND `type`=1); -- Candy Skull

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=414, `VerifiedBuild`=46366 WHERE `entry`=195087; -- Ghostly Cooking Fire

UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=195066; -- Bread of the Dead
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=195067; -- Mixed Fruit Bowl
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=195068; -- Offering Bowl
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=195069; -- Candy Skulls
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=195087; -- Ghostly Cooking Fire
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=195090; -- Spirit Candle

-- Quests
UPDATE `quest_poi_points` SET `VerifiedBuild`=46366 WHERE (`QuestID`=13952 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13952 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13952 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `Emote1`=3, `VerifiedBuild`=46366 WHERE `ID`=13952; -- The Grateful Dead

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `EmoteOnComplete`=0 WHERE `ID`=13952; -- The Grateful Dead

UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=46366 WHERE `ID`=13952; -- The Grateful Dead

DELETE FROM `creature_queststarter` WHERE (`id`=34435 AND `quest`=13952);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(34435, 13952, 46366); -- The Grateful Dead offered Cheerful Human Spirit

UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE (`id`=34435 AND `quest`=13952);

DELETE FROM `game_event_creature_quest` WHERE `id`=34435;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 144951 AND 145000;
DELETE FROM `creature` WHERE `guid`=145038;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 144951 AND 145000;
DELETE FROM `game_event_creature` WHERE `guid`=145038;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+138;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 0, 1519, 5346, '0', 0, 0, 0, 1, -8295.1201171875, 911.76702880859375, 97.92403411865234375, 3.211405754089355468, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Stormwind City Cemetery - Difficulty: 0)
(@CGUID+1, 34383, 0, 1519, 5346, '0', 0, 0, 0, 1, -8298.0302734375, 905.11297607421875, 98.01833343505859375, 2.28408050537109375, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Stormwind City Cemetery - Difficulty: 0)
(@CGUID+2, 34435, 0, 1519, 5346, '0', 0, 0, 0, 0, -8305.0400390625, 892.47900390625, 98.74683380126953125, 1.553343057632446289, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Cheerful Human Spirit (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+3, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8282.6298828125, 897.31597900390625, 100.50433349609375, 1.117010712623596191, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+4, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8295.66015625, 933.5830078125, 97.8668365478515625, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+5, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8316.9501953125, 909.64801025390625, 97.90453338623046875, 5.096361160278320312, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+6, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8308.33984375, 904.52301025390625, 98.25293731689453125, 4.084070205688476562, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+7, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8282.6396484375, 901.77801513671875, 97.9889373779296875, 4.939281940460205078, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+8, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8272.1298828125, 900.8489990234375, 100.50433349609375, 4.258603572845458984, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+9, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8298.8095703125, 888.51702880859375, 98.8121337890625, 1.919862151145935058, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+10, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8315.76953125, 900.43597412109375, 98.34703826904296875, 3.50811171531677246, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+11, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8312.490234375, 896.32098388671875, 98.60713958740234375, 6.248278617858886718, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+12, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8315.33984375, 905.85601806640625, 100.1633377075195312, 1.605702877044677734, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+13, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8279.73046875, 903.5560302734375, 100.50433349609375, 4.258603572845458984, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+14, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8319.6904296875, 898.89202880859375, 98.31903839111328125, 0.349065840244293212, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+15, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8308.8798828125, 925.2030029296875, 97.50853729248046875, 6.021385669708251953, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+16, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8291.5, 929.280029296875, 97.60933685302734375, 5.567600250244140625, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+17, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8293.009765625, 895.34002685546875, 98.15143585205078125, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+18, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8300.1796875, 891.93597412109375, 98.615936279296875, 5.113814830780029296, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+19, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8287.7099609375, 926.38702392578125, 97.64363861083984375, 2.49582076072692871, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+20, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8310.919921875, 933.0780029296875, 97.36803436279296875, 1.047197580337524414, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+21, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8309.0400390625, 895.91302490234375, 98.63983917236328125, 3.071779489517211914, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+22, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8304.26953125, 923.96697998046875, 97.56223297119140625, 2.879793167114257812, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+23, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8286.8896484375, 890.91802978515625, 98.45673370361328125, 5.044001579284667968, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+24, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8285, 915.4169921875, 97.8285369873046875, 1.692969322204589843, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+25, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8305.48046875, 930.77099609375, 97.5232391357421875, 4.310963153839111328, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+26, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8284.1796875, 889.06097412109375, 99.39813232421875, 2.548180580139160156, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+27, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8282.6201171875, 878.59002685546875, 99.3090362548828125, 3.089232683181762695, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+28, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8272.9296875, 924.6719970703125, 99.17193603515625, 0.541052043437957763, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+29, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8268.8095703125, 910.53997802734375, 98.0460357666015625, 0.157079637050628662, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+30, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8318.3095703125, 931.08197021484375, 97.21953582763671875, 4.502949237823486328, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+31, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8268.3603515625, 889.70001220703125, 100.50433349609375, 1.117010712623596191, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+32, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8328.6396484375, 900.76702880859375, 101.3243331909179687, 4.118977069854736328, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+33, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8282.83984375, 937.70697021484375, 98.50533294677734375, 5.375614166259765625, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+34, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8275.01953125, 886.0889892578125, 98.7057342529296875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+35, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8317.3701171875, 893.28802490234375, 98.62203216552734375, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+36, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8275.5703125, 893.57098388671875, 100.50433349609375, 1.099557399749755859, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+37, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8280.75, 935.427001953125, 98.46883392333984375, 2.338741064071655273, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+38, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8262.2900390625, 909.54901123046875, 97.6244354248046875, 2.984513044357299804, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+39, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8318.6298828125, 926.07501220703125, 98.507537841796875, 1.48352980613708496, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+40, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8317.58984375, 935.3280029296875, 97.16013336181640625, 1.064650893211364746, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+41, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8267.400390625, 928.10101318359375, 97.5677337646484375, 3.700098037719726562, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+42, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8264.83984375, 897.5, 100.50433349609375, 4.258603572845458984, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+43, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8268.6396484375, 937.5, 97.5677337646484375, 0.92502450942993164, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+44, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8279.7197265625, 949.97900390625, 97.5232391357421875, 0.506145477294921875, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+45, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8283.080078125, 956.4739990234375, 97.58223724365234375, 2.234021425247192382, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+46, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8345.7197265625, 904.20697021484375, 97.6923370361328125, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+47, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8262.3896484375, 922.6610107421875, 97.5677337646484375, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+48, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8291.66015625, 875.447998046875, 99.47463226318359375, 0.802851438522338867, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+49, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8262.009765625, 931.677001953125, 98.45623779296875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+50, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8347.16015625, 924.27398681640625, 97.23273468017578125, 0.907571196556091308, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+51, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8253.900390625, 928.98297119140625, 97.5731353759765625, 0.558505356311798095, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+52, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8330.169921875, 898.46697998046875, 101.5113372802734375, 1.01229095458984375, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+53, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8291.2900390625, 948.3179931640625, 97.5232391357421875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+54, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8279.2001953125, 866.32098388671875, 99.65993499755859375, 5.637413501739501953, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+55, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8277.0400390625, 864.74798583984375, 99.6119384765625, 2.478367567062377929, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+56, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8286.1298828125, 960.47601318359375, 98.1645355224609375, 5.358160972595214843, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+57, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8343.900390625, 914.3489990234375, 100.953338623046875, 1.239183783531188964, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+58, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8344.0703125, 928.51898193359375, 98.29523468017578125, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+59, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8272.4296875, 945.36798095703125, 97.55573272705078125, 4.729842185974121093, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+60, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8291.7001953125, 871.59600830078125, 99.47043609619140625, 4.049163818359375, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+61, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8313.2197265625, 946.18798828125, 99.7165374755859375, 4.555309295654296875, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+62, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8248.75, 936.62200927734375, 97.5677337646484375, 0.994837641716003417, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+63, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8342.76953125, 938.7969970703125, 97.84143829345703125, 1.762782573699951171, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+64, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8351.0703125, 909.70697021484375, 97.5684356689453125, 2.635447263717651367, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+65, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8269.58984375, 862.3389892578125, 99.1139373779296875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+66, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8247.900390625, 941.5050048828125, 97.5677337646484375, 4.520402908325195312, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+67, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8253.0302734375, 942.84197998046875, 97.5677337646484375, 3.700098037719726562, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+68, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8353.7802734375, 911.08001708984375, 97.6219329833984375, 5.829399585723876953, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+69, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8280.3203125, 964.9310302734375, 100.172332763671875, 0.366519153118133544, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+70, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8343.75, 944.02801513671875, 96.671234130859375, 4.904375076293945312, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+71, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8245.5400390625, 938.32098388671875, 97.5677337646484375, 2.967059612274169921, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+72, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8272.2001953125, 858.5260009765625, 99.78223419189453125, 0.942477762699127197, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+73, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8343.26953125, 949.5570068359375, 96.56673431396484375, 1.169370532035827636, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+74, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8263.75, 963.45098876953125, 97.5677337646484375, 5.550147056579589843, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+75, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8273.66015625, 967.63897705078125, 99.94423675537109375, 3.525565147399902343, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+76, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8372.8701171875, 914.33001708984375, 98.23743438720703125, 6.161012172698974609, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+77, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8345.7001953125, 959.4219970703125, 96.41143798828125, 2.722713708877563476, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+78, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8367.1201171875, 913.71197509765625, 97.97963714599609375, 3.001966238021850585, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+79, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8357.7998046875, 959.2139892578125, 98.8701324462890625, 3.735004663467407226, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+80, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8355.7998046875, 927.510009765625, 97.2534332275390625, 1.361356854438781738, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+81, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8349.650390625, 960.82098388671875, 96.38193511962890625, 5.916666030883789062, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+82, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8259.5400390625, 959.84197998046875, 97.5677337646484375, 2.443460941314697265, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+83, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8292.23046875, 988.91497802734375, 101.53533935546875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+84, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8294.8203125, 991.34002685546875, 101.53533935546875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+85, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8350.26953125, 947.343994140625, 96.5765380859375, 4.398229598999023437, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+86, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8296.8896484375, 994.18402099609375, 101.53533935546875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+87, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8370.83984375, 970.61297607421875, 96.28963470458984375, 2.967059612274169921, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+88, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8373.1298828125, 971.23101806640625, 96.2620391845703125, 6.091198921203613281, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+89, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8391.76953125, 936.26702880859375, 97.7125396728515625, 2.670353651046752929, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+90, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8393.4501953125, 932.29901123046875, 97.91983795166015625, 5.148721218109130859, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+91, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8395.259765625, 916.0830078125, 98.5576324462890625, 5.06145477294921875, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+92, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8393.9697265625, 922.1199951171875, 98.34633636474609375, 3.560471534729003906, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+93, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8388.2900390625, 920.32598876953125, 98.3975372314453125, 2.408554315567016601, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+94, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8379.6201171875, 980.62799072265625, 96.133636474609375, 3.385938644409179687, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+95, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8381.400390625, 974.5360107421875, 97.6905364990234375, 3.752457857131958007, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+96, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8381.91015625, 978.530029296875, 96.1367340087890625, 1.500983119010925292, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+97, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8383.9599609375, 972.69097900390625, 96.25323486328125, 0.593411922454833984, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+98, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8385.76953125, 957.95697021484375, 97.901336669921875, 3.385938644409179687, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+99, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8384.5400390625, 984.22601318359375, 97.204132080078125, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+100, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8383.900390625, 980.99798583984375, 96.3925323486328125, 5.811946392059326171, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+101, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8392.9296875, 984.47900390625, 96.33113861083984375, 0.575958669185638427, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+102, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8391.48046875, 985.75, 96.29953765869140625, 3.96189737319946289, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+103, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8400.7900390625, 936.9840087890625, 97.95233917236328125, 3.630284786224365234, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+104, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8396.5, 920.89898681640625, 98.41143798828125, 0.436332315206527709, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+105, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8404.1796875, 935.06097412109375, 98.1125335693359375, 0.506145477294921875, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+106, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8397.849609375, 986.9639892578125, 97.2292327880859375, 2.251474618911743164, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+107, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8405.1201171875, 915.20001220703125, 98.5975341796875, 1.588249564170837402, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+108, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8408.6904296875, 930.13397216796875, 99.98553466796875, 2.687807083129882812, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+109, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8408.73046875, 966.01702880859375, 98.2955322265625, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+110, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8414.98046875, 946.70098876953125, 98.1786346435546875, 5.724679946899414062, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+111, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8413.3896484375, 932.29302978515625, 99.63573455810546875, 5.846852779388427734, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+112, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8410.330078125, 949.2919921875, 98.27093505859375, 2.199114799499511718, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+113, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8420.6396484375, 925.22100830078125, 98.78453826904296875, 0.523598790168762207, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+114, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8417.8798828125, 926.89801025390625, 99.426239013671875, 3.647738218307495117, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+115, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8422.8603515625, 937.92401123046875, 99.70743560791015625, 1.378810048103332519, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+116, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8422.259765625, 941.39898681640625, 98.49953460693359375, 4.590215682983398437, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+117, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8412.01953125, 962.68597412109375, 97.83423614501953125, 0.78539818525314331, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+118, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8409.6103515625, 978.61602783203125, 97.45783233642578125, 5.410520553588867187, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+119, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8429.0703125, 944.83001708984375, 101.9763336181640625, 5.445427417755126953, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+120, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8426.919921875, 908.55902099609375, 98.36663818359375, 4.049163818359375, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+121, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8419.830078125, 966.8179931640625, 98.29413604736328125, 2.199114799499511718, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+122, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8428.48046875, 959.67901611328125, 98.62543487548828125, 3.246312379837036132, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+123, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8433.01953125, 910.47601318359375, 102.1563339233398437, 4.834561824798583984, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+124, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8447.6298828125, 943.27398681640625, 98.896636962890625, 5.777040004730224609, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+125, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8432.150390625, 905.19598388671875, 101.4733352661132812, 1.745329260826110839, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+126, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8431.6201171875, 959.427001953125, 98.66713714599609375, 0.174532920122146606, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+127, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8437.5302734375, 916.35601806640625, 100.2913360595703125, 2.775073528289794921, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+128, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8442.0498046875, 941.36602783203125, 98.49463653564453125, 2.792526721954345703, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+129, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8444.3203125, 907.78302001953125, 99.473236083984375, 4.328416347503662109, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+130, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8445.0703125, 904.75, 100.9043350219726562, 1.343903541564941406, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+131, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8456.919921875, 921.4639892578125, 98.79213714599609375, 4.852015495300292968, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+132, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8449.5400390625, 904.947998046875, 99.663238525390625, 5.131268024444580078, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+133, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8461.8798828125, 912.77099609375, 98.82103729248046875, 3.001966238021850585, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+134, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8453.25, 901.11602783203125, 99.8025360107421875, 3.281219005584716796, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+135, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8459.5595703125, 917.6810302734375, 99.2469329833984375, 2.129301786422729492, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+136, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8457.1796875, 899.67401123046875, 99.79323577880859375, 0.383972436189651489, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+137, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8466.5595703125, 913.47900390625, 98.607635498046875, 6.108652114868164062, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+138, 35249, 0, 1519, 5346, '0', 0, 0, 0, 0, -8452.3603515625, 895.50897216796875, 99.83193206787109375, 2.548180580139160156, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Ghostly Human Celebrant (Area: Stormwind City Cemetery - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78478 AND 78480;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78582 AND 78585;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78592 AND 78597;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78668 AND 78670;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78690 AND 78704;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78709 AND 78715;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78755 AND 78757;
DELETE FROM `gameobject` WHERE `guid`=78635;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78478 AND 78480;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78582 AND 78585;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78592 AND 78597;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78668 AND 78670;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78690 AND 78704;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78709 AND 78715;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78755 AND 78757;
DELETE FROM `game_event_gameobject` WHERE `guid`=78635;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+626;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 0, 1519, 5346, '0', 0, 0, -8277.9296875, 865.197998046875, 99.55429840087890625, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+1, 180338, 0, 1519, 5346, '0', 0, 0, -8271.1396484375, 870.4439697265625, 98.90789794921875, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+2, 180338, 0, 1519, 5346, '0', 0, 0, -8257.9599609375, 959.57501220703125, 98.21179962158203125, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+3, 180338, 0, 1519, 5346, '0', 0, 0, -8287.6904296875, 966.82098388671875, 101.3330001831054687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+4, 180338, 0, 1519, 5346, '0', 0, 0, -8309.5703125, 921.239990234375, 98.692901611328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+5, 180338, 0, 1519, 5346, '0', 0, 0, -8238.6396484375, 911.12298583984375, 98.24759674072265625, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+6, 180338, 0, 1519, 5346, '0', 0, 0, -8292.8203125, 870.53497314453125, 99.3209991455078125, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+7, 180338, 0, 1519, 5346, '0', 0, 0, -8296.419921875, 895.03802490234375, 99.50550079345703125, 5.6897735595703125, 0, 0, -0.29237174987792968, 0.956304728984832763, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+8, 180338, 0, 1519, 5346, '0', 0, 0, -8276.1201171875, 949.35400390625, 98.94899749755859375, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+9, 180338, 0, 1519, 5346, '0', 0, 0, -8270.8603515625, 870.2969970703125, 98.70490264892578125, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+10, 180338, 0, 1519, 5346, '0', 0, 0, -8332.919921875, 922.27099609375, 98.39019775390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+11, 180338, 0, 1519, 5346, '0', 0, 0, -8317.7099609375, 892.21197509765625, 98.56600189208984375, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+12, 180338, 0, 1519, 5346, '0', 0, 0, -8317.6396484375, 907.81597900390625, 101.7340011596679687, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+13, 180338, 0, 1519, 5346, '0', 0, 0, -8316.5703125, 936.9439697265625, 96.994903564453125, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+14, 180338, 0, 1519, 5346, '0', 0, 0, -8314.9404296875, 911.614990234375, 98.90579986572265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+15, 180338, 0, 1519, 5346, '0', 0, 0, -8290.6201171875, 948.01702880859375, 97.61499786376953125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+16, 180338, 0, 1519, 5346, '0', 0, 0, -8271.4296875, 879.52398681640625, 99.0614013671875, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+17, 180338, 0, 1519, 5346, '0', 0, 0, -8238.6201171875, 912.87200927734375, 98.359100341796875, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+18, 180338, 0, 1519, 5346, '0', 0, 0, -8297.5, 902.0419921875, 99.1237030029296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+19, 180338, 0, 1519, 5346, '0', 0, 0, -8263.76953125, 924.6610107421875, 97.36710357666015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+20, 180338, 0, 1519, 5346, '0', 0, 0, -8253.9697265625, 943.95098876953125, 100.8300018310546875, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+21, 180338, 0, 1519, 5346, '0', 0, 0, -8238.76953125, 914.77301025390625, 98.2801971435546875, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+22, 180338, 0, 1519, 5346, '0', 0, 0, -8238.58984375, 916.0780029296875, 98.3347015380859375, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+23, 180338, 0, 1519, 5346, '0', 0, 0, -8264.41015625, 871.45098876953125, 99.31610107421875, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+24, 180338, 0, 1519, 5346, '0', 0, 0, -8264.5703125, 871.1939697265625, 99.44159698486328125, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+25, 180338, 0, 1519, 5346, '0', 0, 0, -8319.7998046875, 901.20001220703125, 98.7263031005859375, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+26, 180338, 0, 1519, 5346, '0', 0, 0, -8238.98046875, 912.572998046875, 98.4385986328125, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+27, 180338, 0, 1519, 5346, '0', 0, 0, -8308.4697265625, 927.11297607421875, 99.64730072021484375, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+28, 180338, 0, 1519, 5346, '0', 0, 0, -8283.3798828125, 924.0989990234375, 97.385101318359375, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+29, 180338, 0, 1519, 5346, '0', 0, 0, -8238.740234375, 912.2340087890625, 98.358001708984375, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+30, 180338, 0, 1519, 5346, '0', 0, 0, -8268.3095703125, 912.677001953125, 98.60269927978515625, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+31, 180338, 0, 1519, 5346, '0', 0, 0, -8318.349609375, 892.718994140625, 98.52960205078125, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+32, 180338, 0, 1519, 5346, '0', 0, 0, -8321.48046875, 927.4949951171875, 98.34020233154296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+33, 180338, 0, 1519, 5346, '0', 0, 0, -8257.9501953125, 959.2659912109375, 98.380096435546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+34, 180338, 0, 1519, 5346, '0', 0, 0, -8295.8603515625, 881.37298583984375, 101.3649978637695312, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+35, 180338, 0, 1519, 5346, '0', 0, 0, -8303.16015625, 905.39898681640625, 99.25150299072265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+36, 180338, 0, 1519, 5346, '0', 0, 0, -8239.0595703125, 916.21502685546875, 98.44110107421875, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+37, 180338, 0, 1519, 5346, '0', 0, 0, -8284.6796875, 945.14801025390625, 99.84999847412109375, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+38, 180338, 0, 1519, 5346, '0', 0, 0, -8285.3095703125, 945.8800048828125, 99.852203369140625, 5.654868602752685546, 0, 0, -0.30901622772216796, 0.95105677843093872, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+39, 180338, 0, 1519, 5346, '0', 0, 0, -8346.1904296875, 902.03802490234375, 97.4246978759765625, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+40, 180338, 0, 1519, 5346, '0', 0, 0, -8346.01953125, 905.04498291015625, 97.22229766845703125, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+41, 180338, 0, 1519, 5346, '0', 0, 0, -8342.9599609375, 927.97100830078125, 98.2021026611328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+42, 180338, 0, 1519, 5346, '0', 0, 0, -8299.099609375, 915.625, 99.3697967529296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+43, 180338, 0, 1519, 5346, '0', 0, 0, -8289.3896484375, 950.78802490234375, 97.44409942626953125, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+44, 180338, 0, 1519, 5346, '0', 0, 0, -8276.0302734375, 899.66802978515625, 98.0399017333984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+45, 180338, 0, 1519, 5346, '0', 0, 0, -8287.2099609375, 865.0570068359375, 99.308197021484375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+46, 180338, 0, 1519, 5346, '0', 0, 0, -8327.73046875, 930.82598876953125, 98.15470123291015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+47, 180338, 0, 1519, 5346, '0', 0, 0, -8307.099609375, 892.58697509765625, 101.009002685546875, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+48, 180338, 0, 1519, 5346, '0', 0, 0, -8278.6201171875, 865.64202880859375, 99.57810211181640625, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+49, 180338, 0, 1519, 5346, '0', 0, 0, -8259.4501953125, 961.31597900390625, 98.345001220703125, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+50, 180338, 0, 1519, 5346, '0', 0, 0, -8346.7998046875, 915.98101806640625, 97.2173004150390625, 0.104719325900077819, 0, 0, 0.052335739135742187, 0.998629570007324218, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+51, 180338, 0, 1519, 5346, '0', 0, 0, -8239.3701171875, 911.655029296875, 98.318603515625, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+52, 180338, 0, 1519, 5346, '0', 0, 0, -8344.8095703125, 904.3179931640625, 97.53600311279296875, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+53, 180338, 0, 1519, 5346, '0', 0, 0, -8238.73046875, 915.4320068359375, 98.1822967529296875, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+54, 180338, 0, 1519, 5346, '0', 0, 0, -8238.4404296875, 915.28997802734375, 98.2823028564453125, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+55, 180338, 0, 1519, 5346, '0', 0, 0, -8238.990234375, 913.21502685546875, 98.1847991943359375, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+56, 180338, 0, 1519, 5346, '0', 0, 0, -8291.8603515625, 912.3189697265625, 98.865997314453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+57, 180338, 0, 1519, 5346, '0', 0, 0, -8292.1201171875, 870.12701416015625, 99.35759735107421875, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+58, 180338, 0, 1519, 5346, '0', 0, 0, -8255.900390625, 922.07598876953125, 98.1707000732421875, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+59, 180338, 0, 1519, 5346, '0', 0, 0, -8256.2001953125, 922.37298583984375, 98.15889739990234375, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+60, 180338, 0, 1519, 5346, '0', 0, 0, -8314.58984375, 907.01202392578125, 98.47859954833984375, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+61, 180338, 0, 1519, 5346, '0', 0, 0, -8308, 926.0889892578125, 97.36910247802734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+62, 180338, 0, 1519, 5346, '0', 0, 0, -8338.349609375, 925.52801513671875, 98.196502685546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+63, 180338, 0, 1519, 5346, '0', 0, 0, -8240.6103515625, 929.69598388671875, 101.0579986572265625, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+64, 180338, 0, 1519, 5346, '0', 0, 0, -8279.66015625, 883.78497314453125, 100.2559967041015625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+65, 180338, 0, 1519, 5346, '0', 0, 0, -8294.2900390625, 935.2239990234375, 100.6969985961914062, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+66, 180338, 0, 1519, 5346, '0', 0, 0, -8238.3701171875, 914.66802978515625, 98.36920166015625, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+67, 180338, 0, 1519, 5346, '0', 0, 0, -8281.7802734375, 967.13702392578125, 100.483001708984375, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+68, 180338, 0, 1519, 5346, '0', 0, 0, -8239.0595703125, 911.07598876953125, 98.299102783203125, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+69, 180338, 0, 1519, 5346, '0', 0, 0, -8273.4697265625, 932.74798583984375, 99.69940185546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+70, 180338, 0, 1519, 5346, '0', 0, 0, -8278.26953125, 962.2239990234375, 97.9281005859375, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+71, 180338, 0, 1519, 5346, '0', 0, 0, -8314.6396484375, 907.343994140625, 98.40239715576171875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+72, 180338, 0, 1519, 5346, '0', 0, 0, -8238.580078125, 916.64599609375, 98.4152984619140625, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+73, 180338, 0, 1519, 5346, '0', 0, 0, -8306.2998046875, 892.125, 100.9929962158203125, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+74, 180338, 0, 1519, 5346, '0', 0, 0, -8294.3203125, 889.98602294921875, 99.4188995361328125, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+75, 180338, 0, 1519, 5346, '0', 0, 0, -8344.6103515625, 923.13201904296875, 98.4275970458984375, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+76, 180338, 0, 1519, 5346, '0', 0, 0, -8279.3095703125, 859.17401123046875, 102.2559967041015625, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+77, 180338, 0, 1519, 5346, '0', 0, 0, -8345.8203125, 915.60601806640625, 97.20880126953125, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+78, 180338, 0, 1519, 5346, '0', 0, 0, -8305.8701171875, 919.59002685546875, 99.04799652099609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+79, 180338, 0, 1519, 5346, '0', 0, 0, -8238.6904296875, 914.3330078125, 98.16359710693359375, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+80, 180338, 0, 1519, 5346, '0', 0, 0, -8256.3203125, 921.92401123046875, 98.01349639892578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+81, 180338, 0, 1519, 5346, '0', 0, 0, -8238.9599609375, 913.7919921875, 98.3296966552734375, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+82, 180338, 0, 1519, 5346, '0', 0, 0, -8317.1103515625, 937.22900390625, 96.89369964599609375, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+83, 180338, 0, 1519, 5346, '0', 0, 0, -8279.73046875, 977.13897705078125, 102.9820022583007812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+84, 180338, 0, 1519, 5346, '0', 0, 0, -8325.7900390625, 917.552001953125, 98.574798583984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+85, 180338, 0, 1519, 5346, '0', 0, 0, -8264.2900390625, 871.13897705078125, 99.43109893798828125, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+86, 180338, 0, 1519, 5346, '0', 0, 0, -8319.6796875, 900.88897705078125, 98.87969970703125, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+87, 180338, 0, 1519, 5346, '0', 0, 0, -8282.6396484375, 923.49700927734375, 97.42310333251953125, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+88, 180338, 0, 1519, 5346, '0', 0, 0, -8279.0498046875, 963.22100830078125, 98.1685028076171875, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+89, 180338, 0, 1519, 5346, '0', 0, 0, -8259.419921875, 961.57501220703125, 98.50409698486328125, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+90, 180338, 0, 1519, 5346, '0', 0, 0, -8280.01953125, 859.77801513671875, 102.1480026245117187, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+91, 180338, 0, 1519, 5346, '0', 0, 0, -8313.3603515625, 945.68902587890625, 99.450103759765625, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+92, 180338, 0, 1519, 5346, '0', 0, 0, -8238.599609375, 913.468994140625, 98.3296966552734375, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+93, 180338, 0, 1519, 5346, '0', 0, 0, -8288.51953125, 949.67901611328125, 97.44339752197265625, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+94, 180338, 0, 1519, 5346, '0', 0, 0, -8245.1796875, 925.08197021484375, 101.1200027465820312, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+95, 180338, 0, 1519, 5346, '0', 0, 0, -8313.6298828125, 945.72601318359375, 99.63320159912109375, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+96, 180338, 0, 1519, 5346, '0', 0, 0, -8271.900390625, 913.260009765625, 98.513702392578125, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+97, 180338, 0, 1519, 5346, '0', 0, 0, -8270.8896484375, 870.5989990234375, 98.7191009521484375, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+98, 180338, 0, 1519, 5346, '0', 0, 0, -8319.9599609375, 900.9439697265625, 98.61170196533203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+99, 180338, 0, 1519, 5346, '0', 0, 0, -8259.6103515625, 961.47900390625, 98.205596923828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+100, 180338, 0, 1519, 5346, '0', 0, 0, -8294.3603515625, 890.3179931640625, 99.3986968994140625, 6.03883981704711914, 0, 0, -0.12186908721923828, 0.9925462007522583, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+101, 180338, 0, 1519, 5346, '0', 0, 0, -8238.73046875, 911.6090087890625, 98.35369873046875, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+102, 180338, 0, 1519, 5346, '0', 0, 0, -8288.1298828125, 865.7659912109375, 99.42240142822265625, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+103, 180338, 0, 1519, 5346, '0', 0, 0, -8239.4404296875, 914.12701416015625, 98.4019012451171875, 4.59021615982055664, 0, 0, -0.74895572662353515, 0.662620067596435546, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+104, 180338, 0, 1519, 5346, '0', 0, 0, -8238.51953125, 914.05902099609375, 98.25710296630859375, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+105, 180338, 0, 1519, 5346, '0', 0, 0, -8315.009765625, 924.02801513671875, 98.5301971435546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+106, 180338, 0, 1519, 5346, '0', 0, 0, -8311.7001953125, 904.2239990234375, 99.740997314453125, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+107, 180338, 0, 1519, 5346, '0', 0, 0, -8339.2998046875, 937.010009765625, 97.8972015380859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+108, 180338, 0, 1519, 5346, '0', 0, 0, -8309.08984375, 908.68902587890625, 99.0756988525390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+109, 180338, 0, 1519, 5346, '0', 0, 0, -8291.48046875, 949.13897705078125, 97.54620361328125, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+110, 180338, 0, 1519, 5346, '0', 0, 0, -8249.259765625, 908.33001708984375, 100.8600006103515625, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+111, 180338, 0, 1519, 5346, '0', 0, 0, -8239.169921875, 915.45697021484375, 98.42949676513671875, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+112, 180338, 0, 1519, 5346, '0', 0, 0, -8347.400390625, 902.75, 97.32830047607421875, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+113, 180338, 0, 1519, 5346, '0', 0, 0, -8245.33984375, 904.375, 100.9319992065429687, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+114, 180338, 0, 1519, 5346, '0', 0, 0, -8290.509765625, 925.10601806640625, 98.81189727783203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+115, 180338, 0, 1519, 5346, '0', 0, 0, -8359.8701171875, 912.90802001953125, 98.58350372314453125, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+116, 180338, 0, 1519, 5346, '0', 0, 0, -8348.9404296875, 930.77301025390625, 98.181396484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+117, 180338, 0, 1519, 5346, '0', 0, 0, -8356.099609375, 918.70098876953125, 98.76889801025390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+118, 180338, 0, 1519, 5346, '0', 0, 0, -8340.3203125, 950.22100830078125, 98.72299957275390625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+119, 180338, 0, 1519, 5346, '0', 0, 0, -8352.41015625, 909.70001220703125, 97.193603515625, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+120, 180338, 0, 1519, 5346, '0', 0, 0, -8357.240234375, 927.7449951171875, 98.60250091552734375, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+121, 180338, 0, 1519, 5346, '0', 0, 0, -8353.419921875, 910.2080078125, 97.2572021484375, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+122, 180338, 0, 1519, 5346, '0', 0, 0, -8353.7001953125, 932.51702880859375, 98.10430145263671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+123, 180338, 0, 1519, 5346, '0', 0, 0, -8342.3603515625, 951.77099609375, 97.83100128173828125, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+124, 180338, 0, 1519, 5346, '0', 0, 0, -8353.76953125, 910.16802978515625, 97.22440338134765625, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+125, 180338, 0, 1519, 5346, '0', 0, 0, -8361.8701171875, 908.58197021484375, 97.5697021484375, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+126, 180338, 0, 1519, 5346, '0', 0, 0, -8341.1103515625, 950.62200927734375, 98.73290252685546875, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+127, 180338, 0, 1519, 5346, '0', 0, 0, -8353.01953125, 903.552001953125, 99.6782989501953125, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+128, 180338, 0, 1519, 5346, '0', 0, 0, -8344.4599609375, 945.7449951171875, 99.74019622802734375, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+129, 180338, 0, 1519, 5346, '0', 0, 0, -8364.3603515625, 915.18902587890625, 99.150299072265625, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+130, 180338, 0, 1519, 5346, '0', 0, 0, -8335.3095703125, 956.91802978515625, 97.7295989990234375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+131, 180338, 0, 1519, 5346, '0', 0, 0, -8335.3095703125, 956.91802978515625, 97.7295989990234375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+132, 180338, 0, 1519, 5346, '0', 0, 0, -8343.7001953125, 939.156005859375, 97.72319793701171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+133, 180338, 0, 1519, 5346, '0', 0, 0, -8352.2197265625, 909.37799072265625, 97.389801025390625, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+134, 180338, 0, 1519, 5346, '0', 0, 0, -8348.6201171875, 941.26202392578125, 97.67859649658203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+135, 180338, 0, 1519, 5346, '0', 0, 0, -8349.5703125, 962.04901123046875, 96.15070343017578125, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+136, 180338, 0, 1519, 5346, '0', 0, 0, -8358.3203125, 945.01397705078125, 97.62799835205078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+137, 180338, 0, 1519, 5346, '0', 0, 0, -8347.2099609375, 962.27398681640625, 98.6082000732421875, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+138, 180338, 0, 1519, 5346, '0', 0, 0, -8347.58984375, 953.18597412109375, 96.203399658203125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+139, 180338, 0, 1519, 5346, '0', 0, 0, -8363.2802734375, 930.11798095703125, 99.176300048828125, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+140, 180338, 0, 1519, 5346, '0', 0, 0, -8347.3203125, 953.01202392578125, 96.1837005615234375, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+141, 180338, 0, 1519, 5346, '0', 0, 0, -8364.919921875, 948.0989990234375, 97.5597991943359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+142, 180338, 0, 1519, 5346, '0', 0, 0, -8365.01953125, 937.59197998046875, 98.06459808349609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+143, 180338, 0, 1519, 5346, '0', 0, 0, -8355.5400390625, 958.20697021484375, 97.60359954833984375, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+144, 180338, 0, 1519, 5346, '0', 0, 0, -8349.4697265625, 961.65301513671875, 96.01349639892578125, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+145, 180338, 0, 1519, 5346, '0', 0, 0, -8371.3701171875, 912.0560302734375, 98.91500091552734375, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+146, 180338, 0, 1519, 5346, '0', 0, 0, -8288.66015625, 991.54498291015625, 102.3389968872070312, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+147, 180338, 0, 1519, 5346, '0', 0, 0, -8346.4404296875, 961.89599609375, 98.617401123046875, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+148, 180338, 0, 1519, 5346, '0', 0, 0, -8363.7197265625, 930.072998046875, 99.05139923095703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+149, 180338, 0, 1519, 5346, '0', 0, 0, -8349.1103515625, 961.9580078125, 96.05190277099609375, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+150, 180338, 0, 1519, 5346, '0', 0, 0, -8359.169921875, 935.155029296875, 98.13449859619140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+151, 180338, 0, 1519, 5346, '0', 0, 0, -8353.3095703125, 942.83697509765625, 97.69899749755859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+152, 180338, 0, 1519, 5346, '0', 0, 0, -8387.2900390625, 918.98797607421875, 98.1656036376953125, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+153, 180338, 0, 1519, 5346, '0', 0, 0, -8295.849609375, 996.01702880859375, 102.3870010375976562, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+154, 180338, 0, 1519, 5346, '0', 0, 0, -8376.6904296875, 953.364990234375, 97.53130340576171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+155, 180338, 0, 1519, 5346, '0', 0, 0, -8371.7099609375, 950.98297119140625, 97.6248016357421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+156, 180338, 0, 1519, 5346, '0', 0, 0, -8288.990234375, 992.177001953125, 102.3420028686523437, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+157, 180338, 0, 1519, 5346, '0', 0, 0, -8288.2802734375, 991.968994140625, 102.4670028686523437, 6.073746204376220703, 0, 0, -0.10452842712402343, 0.994521915912628173, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+158, 180338, 0, 1519, 5346, '0', 0, 0, -8295.1796875, 995.3389892578125, 102.3460006713867187, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+159, 180338, 0, 1519, 5346, '0', 0, 0, -8381.2900390625, 943.60400390625, 98.36750030517578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+160, 180338, 0, 1519, 5346, '0', 0, 0, -8369.6796875, 957.11102294921875, 97.57250213623046875, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+161, 180338, 0, 1519, 5346, '0', 0, 0, -8375.6298828125, 942.06298828125, 98.1667022705078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+162, 180338, 0, 1519, 5346, '0', 0, 0, -8288.7900390625, 992.5560302734375, 102.51300048828125, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+163, 180338, 0, 1519, 5346, '0', 0, 0, -8293.2900390625, 997.343994140625, 102.302001953125, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+164, 180338, 0, 1519, 5346, '0', 0, 0, -8293.9501953125, 997.9580078125, 102.2379989624023437, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+165, 180338, 0, 1519, 5346, '0', 0, 0, -8387.3798828125, 944.0689697265625, 98.3975982666015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+166, 180338, 0, 1519, 5346, '0', 0, 0, -8367.080078125, 979.322998046875, 96.09320068359375, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+167, 180338, 0, 1519, 5346, '0', 0, 0, -8373.0595703125, 965.8699951171875, 98.454803466796875, 3.351046562194824218, 0, 0, -0.99452114105224609, 0.104535527527332305, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+168, 180338, 0, 1519, 5346, '0', 0, 0, -8367.419921875, 979.3189697265625, 96.10759735107421875, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+169, 180338, 0, 1519, 5346, '0', 0, 0, -8394.4697265625, 914.9320068359375, 98.441497802734375, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+170, 180338, 0, 1519, 5346, '0', 0, 0, -8389.9501953125, 916.32098388671875, 100.858001708984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+171, 180338, 0, 1519, 5346, '0', 0, 0, -8381.2998046875, 955.34698486328125, 97.59210205078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+172, 180338, 0, 1519, 5346, '0', 0, 0, -8392.3603515625, 930.218994140625, 101.2139968872070312, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+173, 180338, 0, 1519, 5346, '0', 0, 0, -8388.080078125, 918.905029296875, 98.2436981201171875, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+174, 180338, 0, 1519, 5346, '0', 0, 0, -8395.2802734375, 914.6820068359375, 98.33480072021484375, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+175, 180338, 0, 1519, 5346, '0', 0, 0, -8373.5498046875, 966.26397705078125, 99.42890167236328125, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+176, 180338, 0, 1519, 5346, '0', 0, 0, -8370.330078125, 980.37701416015625, 98.48470306396484375, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+177, 180338, 0, 1519, 5346, '0', 0, 0, -8370.01953125, 980.33197021484375, 98.49030303955078125, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+178, 180338, 0, 1519, 5346, '0', 0, 0, -8400.4599609375, 959.677001953125, 97.80460357666015625, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+179, 180338, 0, 1519, 5346, '0', 0, 0, -8404.23046875, 950.16497802734375, 98.7545013427734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+180, 180338, 0, 1519, 5346, '0', 0, 0, -8405.4404296875, 937.9949951171875, 99.22049713134765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+181, 180338, 0, 1519, 5346, '0', 0, 0, -8379.240234375, 981.48297119140625, 96.013397216796875, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+182, 180338, 0, 1519, 5346, '0', 0, 0, -8384.98046875, 960.927001953125, 96.99880218505859375, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+183, 180338, 0, 1519, 5346, '0', 0, 0, -8381.080078125, 973.66302490234375, 96.04399871826171875, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+184, 180338, 0, 1519, 5346, '0', 0, 0, -8386.4296875, 958.15301513671875, 97.84639739990234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+185, 180338, 0, 1519, 5346, '0', 0, 0, -8383.2900390625, 973.93798828125, 96.0718994140625, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+186, 180338, 0, 1519, 5346, '0', 0, 0, -8380.16015625, 981.59698486328125, 95.91539764404296875, 3.054326534271240234, 0, 0, 0.999048233032226562, 0.043619260191917419, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+187, 180338, 0, 1519, 5346, '0', 0, 0, -8382.1103515625, 973.83697509765625, 95.85359954833984375, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+188, 180338, 0, 1519, 5346, '0', 0, 0, -8379.7001953125, 981.4739990234375, 95.9427032470703125, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+189, 180338, 0, 1519, 5346, '0', 0, 0, -8394.4599609375, 942.71697998046875, 98.5863037109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+190, 180338, 0, 1519, 5346, '0', 0, 0, -8384.3095703125, 974.0560302734375, 95.97080230712890625, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+191, 180338, 0, 1519, 5346, '0', 0, 0, -8384.83984375, 961.23297119140625, 97.10900115966796875, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+192, 180338, 0, 1519, 5346, '0', 0, 0, -8385.16015625, 961.2239990234375, 97.0157012939453125, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+193, 180338, 0, 1519, 5346, '0', 0, 0, -8398.16015625, 929.45697021484375, 100.1800003051757812, 0.488691210746765136, 0, 0, 0.241921424865722656, 0.970295846462249755, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+194, 180338, 0, 1519, 5346, '0', 0, 0, -8406.1396484375, 914.90802001953125, 99.94329833984375, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+195, 180338, 0, 1519, 5346, '0', 0, 0, -8408.8095703125, 913.9110107421875, 99.79000091552734375, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+196, 180338, 0, 1519, 5346, '0', 0, 0, -8398.849609375, 941.155029296875, 98.895599365234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+197, 180338, 0, 1519, 5346, '0', 0, 0, -8408.8203125, 921.135009765625, 100.7900009155273437, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+198, 180338, 0, 1519, 5346, '0', 0, 0, -8398.9501953125, 953.4840087890625, 98.4817962646484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+199, 180338, 0, 1519, 5346, '0', 0, 0, -8409.5, 946.53497314453125, 99.206298828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+200, 180338, 0, 1519, 5346, '0', 0, 0, -8408.419921875, 930.40997314453125, 99.55789947509765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+201, 180338, 0, 1519, 5346, '0', 0, 0, -8410.259765625, 934.718994140625, 99.43979644775390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+202, 180338, 0, 1519, 5346, '0', 0, 0, -8408.0302734375, 921.62799072265625, 100.7399978637695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+203, 180338, 0, 1519, 5346, '0', 0, 0, -8399.7900390625, 935.14599609375, 99.218902587890625, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+204, 180338, 0, 1519, 5346, '0', 0, 0, -8409.0498046875, 930.03997802734375, 99.71309661865234375, 1.082102894783020019, 0, 0, 0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+205, 180338, 0, 1519, 5346, '0', 0, 0, -8415.1298828125, 918.35400390625, 99.369903564453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+206, 180338, 0, 1519, 5346, '0', 0, 0, -8411.8701171875, 950.9580078125, 99.14849853515625, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+207, 180338, 0, 1519, 5346, '0', 0, 0, -8415.25, 918.6810302734375, 99.22370147705078125, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+208, 180338, 0, 1519, 5346, '0', 0, 0, -8414.990234375, 918.635009765625, 99.2593994140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+209, 180338, 0, 1519, 5346, '0', 0, 0, -8413.75, 927.197998046875, 99.9141998291015625, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+210, 180338, 0, 1519, 5346, '0', 0, 0, -8416.3798828125, 930.74798583984375, 99.6360015869140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+211, 180338, 0, 1519, 5346, '0', 0, 0, -8399.7998046875, 988.97198486328125, 99.6676025390625, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+212, 180338, 0, 1519, 5346, '0', 0, 0, -8416.0595703125, 942.16497802734375, 99.41950225830078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+213, 180338, 0, 1519, 5346, '0', 0, 0, -8424.2197265625, 941.4429931640625, 98.27069854736328125, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+214, 180338, 0, 1519, 5346, '0', 0, 0, -8427.7802734375, 934.4219970703125, 99.781402587890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+215, 180338, 0, 1519, 5346, '0', 0, 0, -8422.099609375, 938.3070068359375, 99.6027984619140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+216, 180338, 0, 1519, 5346, '0', 0, 0, -8419.509765625, 924.35198974609375, 98.65599822998046875, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+217, 180338, 0, 1519, 5346, '0', 0, 0, -8422.400390625, 926.6510009765625, 99.82430267333984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+218, 180338, 0, 1519, 5346, '0', 0, 0, -8420.3095703125, 923.92401123046875, 98.52469635009765625, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+219, 180338, 0, 1519, 5346, '0', 0, 0, -8425.009765625, 940.7030029296875, 98.3022003173828125, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+220, 180338, 0, 1519, 5346, '0', 0, 0, -8425.7998046875, 910.09002685546875, 99.771697998046875, 1.343901276588439941, 0, 0, 0.622513771057128906, 0.78260880708694458, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+221, 180338, 0, 1519, 5346, '0', 0, 0, -8428.1396484375, 961.12701416015625, 100.6790008544921875, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+222, 180338, 0, 1519, 5346, '0', 0, 0, -8433.5302734375, 910.46697998046875, 101.1460037231445312, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+223, 180338, 0, 1519, 5346, '0', 0, 0, -8434.7900390625, 953.73101806640625, 99.16680145263671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+224, 180338, 0, 1519, 5346, '0', 0, 0, -8449.08984375, 919.45697021484375, 100.141998291015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+225, 180338, 0, 1519, 5346, '0', 0, 0, -8434.490234375, 953.655029296875, 99.00299835205078125, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+226, 180338, 0, 1519, 5346, '0', 0, 0, -8433.1904296875, 919.1939697265625, 100.207000732421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+227, 180338, 0, 1519, 5346, '0', 0, 0, -8444.1103515625, 911.97698974609375, 100.496002197265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+228, 180338, 0, 1519, 5346, '0', 0, 0, -8443.2802734375, 907.07098388671875, 99.01439666748046875, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+229, 180338, 0, 1519, 5346, '0', 0, 0, -8434.66015625, 953.39599609375, 99.033203125, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+230, 180338, 0, 1519, 5346, '0', 0, 0, -8444.2197265625, 906.40802001953125, 99.2223968505859375, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+231, 180338, 0, 1519, 5346, '0', 0, 0, -8438.48046875, 915.56402587890625, 100.2089996337890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+232, 180338, 0, 1519, 5346, '0', 0, 0, -8433.849609375, 940.905029296875, 101.7699966430664062, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+233, 180338, 0, 1519, 5346, '0', 0, 0, -8432.4296875, 931.280029296875, 99.8816986083984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+234, 180338, 0, 1519, 5346, '0', 0, 0, -8437.6904296875, 927.8179931640625, 99.98079681396484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+235, 180338, 0, 1519, 5346, '0', 0, 0, -8445.1796875, 905.6610107421875, 99.30229949951171875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+236, 180338, 0, 1519, 5346, '0', 0, 0, -8443.900390625, 939.9530029296875, 99.25260162353515625, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+237, 180338, 0, 1519, 5346, '0', 0, 0, -8435.01953125, 903.46697998046875, 99.30789947509765625, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+238, 180338, 0, 1519, 5346, '0', 0, 0, -8434.7197265625, 950.16802978515625, 100.5800018310546875, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+239, 180338, 0, 1519, 5346, '0', 0, 0, -8453.4404296875, 916.447998046875, 100.1429977416992187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+240, 180338, 0, 1519, 5346, '0', 0, 0, -8449.7998046875, 908.2239990234375, 100.6149978637695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+241, 180338, 0, 1519, 5346, '0', 0, 0, -8446.0302734375, 905.25701904296875, 99.4470977783203125, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+242, 180338, 0, 1519, 5346, '0', 0, 0, -8458.6796875, 912.97198486328125, 100.0589981079101562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+243, 180338, 0, 1519, 5346, '0', 0, 0, -8463.2900390625, 915.14898681640625, 100.8349990844726562, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+244, 180338, 0, 1519, 5346, '0', 0, 0, -8455.080078125, 904.3909912109375, 100.1569976806640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+245, 180338, 0, 1519, 5346, '0', 0, 0, -8466.580078125, 914.53802490234375, 98.49970245361328125, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+246, 180338, 0, 1519, 5346, '0', 0, 0, -8464.3798828125, 908.97698974609375, 100.2779998779296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+247, 180338, 0, 1519, 5346, '0', 0, 0, -8459.58984375, 901.3330078125, 100.1579971313476562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+248, 180338, 0, 1519, 5346, '0', 0, 0, -8467.5400390625, 913.88201904296875, 98.46469879150390625, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 46366), -- Candle 01 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+249, 180339, 0, 1519, 5346, '0', 0, 0, -8276.2900390625, 899.21697998046875, 98.05899810791015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+250, 180339, 0, 1519, 5346, '0', 0, 0, -8288.5703125, 992.21197509765625, 102.470001220703125, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 46366), -- Candle 02 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+251, 180340, 0, 1519, 5346, '0', 0, 0, -8280.650390625, 900.0889892578125, 97.98439788818359375, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+252, 180340, 0, 1519, 5346, '0', 0, 0, -8304.5703125, 931.87799072265625, 99.72750091552734375, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+253, 180340, 0, 1519, 5346, '0', 0, 0, -8293.8896484375, 910.97100830078125, 98.87020111083984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+254, 180340, 0, 1519, 5346, '0', 0, 0, -8303.6796875, 931.45098876953125, 99.802001953125, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+255, 180340, 0, 1519, 5346, '0', 0, 0, -8279.26953125, 928.83697509765625, 97.4990997314453125, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+256, 180340, 0, 1519, 5346, '0', 0, 0, -8318.849609375, 932.66998291015625, 98.44930267333984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+257, 180340, 0, 1519, 5346, '0', 0, 0, -8276.66015625, 898.6610107421875, 98.07990264892578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+258, 180340, 0, 1519, 5346, '0', 0, 0, -8287.9404296875, 950.72601318359375, 99.82959747314453125, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+259, 180340, 0, 1519, 5346, '0', 0, 0, -8290.5400390625, 930.35101318359375, 97.440399169921875, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+260, 180340, 0, 1519, 5346, '0', 0, 0, -8290.26953125, 988.95001220703125, 101.81500244140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+261, 180340, 0, 1519, 5346, '0', 0, 0, -8395.75, 920.16302490234375, 98.2552032470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+262, 180340, 0, 1519, 5346, '0', 0, 0, -8410.33984375, 979.60198974609375, 99.6320037841796875, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+263, 180340, 0, 1519, 5346, '0', 0, 0, -8420.5595703125, 949.91998291015625, 98.08280181884765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+264, 180340, 0, 1519, 5346, '0', 0, 0, -8429.33984375, 912.9429931640625, 100.1169967651367187, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+265, 180340, 0, 1519, 5346, '0', 0, 0, -8441.8798828125, 900.99798583984375, 98.59600067138671875, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+266, 180340, 0, 1519, 5346, '0', 0, 0, -8458.650390625, 921.385009765625, 99.9163970947265625, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- Candle 03 (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+267, 180757, 0, 1519, 5346, '0', 0, 0, -8306.5, 892.677001953125, 100.0979995727539062, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 46366), -- Human Hero Portrait (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+268, 180885, 0, 1519, 5346, '0', 0, 0, -8293.349609375, 910.5, 97.82959747314453125, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 46366), -- InnTableTiny (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+269, 182807, 0, 1519, 5346, '0', 0, 0, -8308.9296875, 903.593994140625, 98.2100982666015625, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+270, 182807, 0, 1519, 5346, '0', 0, 0, -8301.7900390625, 892.46697998046875, 99.33100128173828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+271, 182807, 0, 1519, 5346, '0', 0, 0, -8309.76953125, 884.3070068359375, 100.4189987182617187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+272, 182807, 0, 1519, 5346, '0', 0, 0, -8241.8896484375, 940.36297607421875, 99.89710235595703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+273, 182807, 0, 1519, 5346, '0', 0, 0, -8280.91015625, 964.92901611328125, 99.21649932861328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+274, 182807, 0, 1519, 5346, '0', 0, 0, -8310.6796875, 934.4739990234375, 97.24859619140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+275, 182807, 0, 1519, 5346, '0', 0, 0, -8288.2900390625, 939.781005859375, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+276, 182807, 0, 1519, 5346, '0', 0, 0, -8253.7802734375, 942.68902587890625, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+277, 182807, 0, 1519, 5346, '0', 0, 0, -8321.9697265625, 889.45501708984375, 98.37960052490234375, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+278, 182807, 0, 1519, 5346, '0', 0, 0, -8262.23046875, 963.97198486328125, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+279, 182807, 0, 1519, 5346, '0', 0, 0, -8277.23046875, 926.47100830078125, 97.50189971923828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+280, 182807, 0, 1519, 5346, '0', 0, 0, -8261.83984375, 910.54302978515625, 97.5272979736328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+281, 182807, 0, 1519, 5346, '0', 0, 0, -8292.740234375, 932.9429931640625, 97.47879791259765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+282, 182807, 0, 1519, 5346, '0', 0, 0, -8279.98046875, 901.76202392578125, 97.9573974609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+283, 182807, 0, 1519, 5346, '0', 0, 0, -8298.8095703125, 887.66802978515625, 101.319000244140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+284, 182807, 0, 1519, 5346, '0', 0, 0, -8285.349609375, 917.20098876953125, 98.252899169921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+285, 182807, 0, 1519, 5346, '0', 0, 0, -8314.2197265625, 907.0889892578125, 98.6927032470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+286, 182807, 0, 1519, 5346, '0', 0, 0, -8283.5302734375, 878.48101806640625, 99.25689697265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+287, 182807, 0, 1519, 5346, '0', 0, 0, -8310.009765625, 943.781005859375, 99.72029876708984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+288, 182807, 0, 1519, 5346, '0', 0, 0, -8244.03125, 929.12677001953125, 97.82627105712890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+289, 182807, 0, 1519, 5346, '0', 0, 0, -8314.900390625, 883.71002197265625, 98.68430328369140625, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+290, 182807, 0, 1519, 5346, '0', 0, 0, -8276.98046875, 882.61297607421875, 100.4260025024414062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+291, 182807, 0, 1519, 5346, '0', 0, 0, -8358.849609375, 929.45697021484375, 97.147796630859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+292, 182807, 0, 1519, 5346, '0', 0, 0, -8343.0703125, 944.06097412109375, 96.5912017822265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+293, 182807, 0, 1519, 5346, '0', 0, 0, -8342.2099609375, 950.739990234375, 96.472503662109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+294, 182807, 0, 1519, 5346, '0', 0, 0, -8359, 907.63702392578125, 97.6204986572265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+295, 182807, 0, 1519, 5346, '0', 0, 0, -8353.0302734375, 904.58697509765625, 97.46050262451171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+296, 182807, 0, 1519, 5346, '0', 0, 0, -8371.990234375, 913.2860107421875, 98.12470245361328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+297, 182807, 0, 1519, 5346, '0', 0, 0, -8358.3203125, 959.06597900390625, 98.78679656982421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+298, 182807, 0, 1519, 5346, '0', 0, 0, -8368.4697265625, 912.43798828125, 97.9683990478515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+299, 182807, 0, 1519, 5346, '0', 0, 0, -8291.1298828125, 989.22198486328125, 101.4520034790039062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+300, 182807, 0, 1519, 5346, '0', 0, 0, -8372.1904296875, 913.52099609375, 98.13120269775390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+301, 182807, 0, 1519, 5346, '0', 0, 0, -8371.4404296875, 972.0570068359375, 96.19879913330078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+302, 182807, 0, 1519, 5346, '0', 0, 0, -8372.0400390625, 972.42401123046875, 96.18759918212890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+303, 182807, 0, 1519, 5346, '0', 0, 0, -8400.849609375, 982.25701904296875, 96.56500244140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+304, 182807, 0, 1519, 5346, '0', 0, 0, -8399.7998046875, 982.87200927734375, 96.500396728515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+305, 182807, 0, 1519, 5346, '0', 0, 0, -8415.099609375, 947.85400390625, 98.07990264892578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+306, 182807, 0, 1519, 5346, '0', 0, 0, -8447.669921875, 942.43597412109375, 97.7826995849609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+307, 182807, 0, 1519, 5346, '0', 0, 0, -8431.4296875, 960.8590087890625, 100.0579986572265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+308, 182807, 0, 1519, 5346, '0', 0, 0, -8427.48046875, 907.89898681640625, 98.19339752197265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+309, 182807, 0, 1519, 5346, '0', 0, 0, -8441.1396484375, 940.78997802734375, 98.46779632568359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+310, 182807, 0, 1519, 5346, '0', 0, 0, -8448.6396484375, 903.94598388671875, 99.54979705810546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+311, 182807, 0, 1519, 5346, '0', 0, 0, -8453.509765625, 900.4639892578125, 99.7285003662109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+312, 182807, 0, 1519, 5346, '0', 0, 0, -8462.599609375, 913.405029296875, 98.70690155029296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+313, 182807, 0, 1519, 5346, '0', 0, 0, -8456.33984375, 898.54498291015625, 99.77490234375, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 46366), -- Bottle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+314, 195063, 0, 1519, 5346, '0', 0, 0, -8318.150390625, 892.364990234375, 98.54869842529296875, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+315, 195063, 0, 1519, 5346, '0', 0, 0, -8270.6796875, 922.42498779296875, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+316, 195063, 0, 1519, 5346, '0', 0, 0, -8287.2099609375, 927.468994140625, 97.5458984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+317, 195063, 0, 1519, 5346, '0', 0, 0, -8278.400390625, 865.30902099609375, 99.57810211181640625, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+318, 195063, 0, 1519, 5346, '0', 0, 0, -8316.7197265625, 937.36102294921875, 97.06349945068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+319, 195063, 0, 1519, 5346, '0', 0, 0, -8261.8896484375, 951.70098876953125, 99.5446014404296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+320, 195063, 0, 1519, 5346, '0', 0, 0, -8275.240234375, 956.95697021484375, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+321, 195063, 0, 1519, 5346, '0', 0, 0, -8301.1396484375, 939.1820068359375, 99.92340087890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+322, 195063, 0, 1519, 5346, '0', 0, 0, -8242.91015625, 940.0159912109375, 97.739898681640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+323, 195063, 0, 1519, 5346, '0', 0, 0, -8237.8095703125, 916.09197998046875, 98.49720001220703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+324, 195063, 0, 1519, 5346, '0', 0, 0, -8238.0703125, 911.47198486328125, 98.49720001220703125, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+325, 195063, 0, 1519, 5346, '0', 0, 0, -8256.580078125, 935.20098876953125, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+326, 195063, 0, 1519, 5346, '0', 0, 0, -8284.9501953125, 961.47100830078125, 98.21700286865234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+327, 195063, 0, 1519, 5346, '0', 0, 0, -8244.5400390625, 929.61297607421875, 97.71289825439453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+328, 195063, 0, 1519, 5346, '0', 0, 0, -8304.48046875, 931.0469970703125, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+329, 195063, 0, 1519, 5346, '0', 0, 0, -8317.0498046875, 930.77398681640625, 97.1638031005859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+330, 195063, 0, 1519, 5346, '0', 0, 0, -8278.51953125, 900.99798583984375, 97.99559783935546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+331, 195063, 0, 1519, 5346, '0', 0, 0, -8322.400390625, 895.6610107421875, 98.26450347900390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+332, 195063, 0, 1519, 5346, '0', 0, 0, -8263.3896484375, 924.10101318359375, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+333, 195063, 0, 1519, 5346, '0', 0, 0, -8344.4599609375, 924.07501220703125, 97.127899169921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+334, 195063, 0, 1519, 5346, '0', 0, 0, -8311.6796875, 895.7030029296875, 98.5561981201171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+335, 195063, 0, 1519, 5346, '0', 0, 0, -8292.580078125, 870.2139892578125, 99.3323974609375, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+336, 195063, 0, 1519, 5346, '0', 0, 0, -8285.73046875, 944.91802978515625, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+337, 195063, 0, 1519, 5346, '0', 0, 0, -8277.8701171875, 975.1939697265625, 100.1999969482421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+338, 195063, 0, 1519, 5346, '0', 0, 0, -8269.73046875, 968.885009765625, 98.07430267333984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+339, 195063, 0, 1519, 5346, '0', 0, 0, -8342.5703125, 943.60400390625, 96.60369873046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+340, 195063, 0, 1519, 5346, '0', 0, 0, -8353.01953125, 909.89898681640625, 97.52469635009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+341, 195063, 0, 1519, 5346, '0', 0, 0, -8345.330078125, 960.2760009765625, 96.32219696044921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+342, 195063, 0, 1519, 5346, '0', 0, 0, -8363.48046875, 929.87799072265625, 99.2751007080078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+343, 195063, 0, 1519, 5346, '0', 0, 0, -8362.26953125, 967.48602294921875, 98.79830169677734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+344, 195063, 0, 1519, 5346, '0', 0, 0, -8296.740234375, 995.405029296875, 101.4520034790039062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+345, 195063, 0, 1519, 5346, '0', 0, 0, -8295.759765625, 994.530029296875, 101.4520034790039062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+346, 195063, 0, 1519, 5346, '0', 0, 0, -8394.900390625, 914.83697509765625, 98.50579833984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+347, 195063, 0, 1519, 5346, '0', 0, 0, -8400.3203125, 935.85400390625, 97.89279937744140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+348, 195063, 0, 1519, 5346, '0', 0, 0, -8400.16015625, 982.53497314453125, 96.52629852294921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+349, 195063, 0, 1519, 5346, '0', 0, 0, -8402.3203125, 956.97900390625, 97.328399658203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+350, 195063, 0, 1519, 5346, '0', 0, 0, -8388.7802734375, 957.239990234375, 97.2776031494140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+351, 195063, 0, 1519, 5346, '0', 0, 0, -8383.7900390625, 973.89202880859375, 96.14369964599609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+352, 195063, 0, 1519, 5346, '0', 0, 0, -8381.7001953125, 973.58697509765625, 96.124603271484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+353, 195063, 0, 1519, 5346, '0', 0, 0, -8406.7197265625, 915.68798828125, 98.55719757080078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+354, 195063, 0, 1519, 5346, '0', 0, 0, -8409.7197265625, 967.39898681640625, 99.63809967041015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+355, 195063, 0, 1519, 5346, '0', 0, 0, -8417.009765625, 925.11602783203125, 100.694000244140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+356, 195063, 0, 1519, 5346, '0', 0, 0, -8415.650390625, 971.97698974609375, 97.94460296630859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+357, 195063, 0, 1519, 5346, '0', 0, 0, -8428.580078125, 943.90802001953125, 98.52030181884765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+358, 195063, 0, 1519, 5346, '0', 0, 0, -8443.8701171875, 906.76202392578125, 99.34490203857421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+359, 195063, 0, 1519, 5346, '0', 0, 0, -8445.6103515625, 905.46697998046875, 99.43090057373046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+360, 195063, 0, 1519, 5346, '0', 0, 0, -8467.01953125, 914.17401123046875, 98.48459625244140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+361, 195063, 0, 1519, 5346, '0', 0, 0, -8293.490234375, 909.92498779296875, 98.87870025634765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+362, 195066, 0, 1519, 5346, '0', 0, 0, -8309.51953125, 884.135009765625, 100.4189987182617187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+363, 195066, 0, 1519, 5346, '0', 0, 0, -8272.330078125, 913.34002685546875, 98.63050079345703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+364, 195066, 0, 1519, 5346, '0', 0, 0, -8282.0498046875, 957.09698486328125, 97.487396240234375, 3.595378875732421875, 0, 0, -0.97437000274658203, 0.224951311945915222, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+365, 195066, 0, 1519, 5346, '0', 0, 0, -8280.259765625, 901.14801025390625, 97.9673004150390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+366, 195066, 0, 1519, 5346, '0', 0, 0, -8293.7001953125, 894.78802490234375, 98.114898681640625, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+367, 195066, 0, 1519, 5346, '0', 0, 0, -8314.3701171875, 883.802001953125, 98.7274017333984375, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+368, 195066, 0, 1519, 5346, '0', 0, 0, -8308.740234375, 903.40301513671875, 98.21700286865234375, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+369, 195066, 0, 1519, 5346, '0', 0, 0, -8268.150390625, 938.32098388671875, 97.48439788818359375, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+370, 195066, 0, 1519, 5346, '0', 0, 0, -8268.400390625, 921.0419921875, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+371, 195066, 0, 1519, 5346, '0', 0, 0, -8259.98046875, 930.031005859375, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+372, 195066, 0, 1519, 5346, '0', 0, 0, -8276.8603515625, 925.86602783203125, 97.5005035400390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+373, 195066, 0, 1519, 5346, '0', 0, 0, -8242.83984375, 927.03802490234375, 98.32939910888671875, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+374, 195066, 0, 1519, 5346, '0', 0, 0, -8280.9599609375, 861.343994140625, 99.87729644775390625, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+375, 195066, 0, 1519, 5346, '0', 0, 0, -8289.6904296875, 875.655029296875, 99.73490142822265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+376, 195066, 0, 1519, 5346, '0', 0, 0, -8250.4296875, 937.05401611328125, 97.48439788818359375, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+377, 195066, 0, 1519, 5346, '0', 0, 0, -8309.330078125, 894.54998779296875, 98.61930084228515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+378, 195066, 0, 1519, 5346, '0', 0, 0, -8308.669921875, 926.40301513671875, 97.42559814453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+379, 195066, 0, 1519, 5346, '0', 0, 0, -8281.0302734375, 964.04901123046875, 98.5652008056640625, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+380, 195066, 0, 1519, 5346, '0', 0, 0, -8288.8603515625, 940.33697509765625, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+381, 195066, 0, 1519, 5346, '0', 0, 0, -8305.25, 940.1719970703125, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+382, 195066, 0, 1519, 5346, '0', 0, 0, -8301.599609375, 892.2760009765625, 99.358001708984375, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+383, 195066, 0, 1519, 5346, '0', 0, 0, -8309.9697265625, 934.0469970703125, 97.31040191650390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+384, 195066, 0, 1519, 5346, '0', 0, 0, -8276.7900390625, 882.4219970703125, 100.4489974975585937, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+385, 195066, 0, 1519, 5346, '0', 0, 0, -8356.8603515625, 912.33502197265625, 97.6082000732421875, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+386, 195066, 0, 1519, 5346, '0', 0, 0, -8359.259765625, 907.98602294921875, 97.63690185546875, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+387, 195066, 0, 1519, 5346, '0', 0, 0, -8357.1103515625, 906.58197021484375, 97.56829833984375, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+388, 195066, 0, 1519, 5346, '0', 0, 0, -8344.7197265625, 944.614990234375, 96.5695037841796875, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+389, 195066, 0, 1519, 5346, '0', 0, 0, -8347.73046875, 925.3800048828125, 97.12290191650390625, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+390, 195066, 0, 1519, 5346, '0', 0, 0, -8361.7998046875, 950.79901123046875, 96.42929840087890625, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+391, 195066, 0, 1519, 5346, '0', 0, 0, -8371.2197265625, 913.31097412109375, 98.08550262451171875, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+392, 195066, 0, 1519, 5346, '0', 0, 0, -8387.830078125, 919.48297119140625, 98.3589019775390625, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+393, 195066, 0, 1519, 5346, '0', 0, 0, -8294.400390625, 992.39398193359375, 101.4520034790039062, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+394, 195066, 0, 1519, 5346, '0', 0, 0, -8370.8701171875, 971.61798095703125, 96.20890045166015625, 5.061456203460693359, 0, 0, -0.57357597351074218, 0.819152355194091796, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+395, 195066, 0, 1519, 5346, '0', 0, 0, -8392.58984375, 915.9639892578125, 98.499298095703125, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+396, 195066, 0, 1519, 5346, '0', 0, 0, -8403.509765625, 934.3280029296875, 98.0319976806640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+397, 195066, 0, 1519, 5346, '0', 0, 0, -8411.83984375, 929.51702880859375, 98.39820098876953125, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+398, 195066, 0, 1519, 5346, '0', 0, 0, -8422.259765625, 956.68902587890625, 98.29650115966796875, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+399, 195066, 0, 1519, 5346, '0', 0, 0, -8430.900390625, 959.7860107421875, 98.59110260009765625, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+400, 195066, 0, 1519, 5346, '0', 0, 0, -8440.8203125, 941.30401611328125, 98.46250152587890625, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+401, 195066, 0, 1519, 5346, '0', 0, 0, -8433.6796875, 911.54302978515625, 98.8303985595703125, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+402, 195066, 0, 1519, 5346, '0', 0, 0, -8449.33984375, 903.82598876953125, 99.57790374755859375, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+403, 195066, 0, 1519, 5346, '0', 0, 0, -8462.0302734375, 913.62701416015625, 98.7400970458984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+404, 195066, 0, 1519, 5346, '0', 0, 0, -8451.9697265625, 894.70501708984375, 99.70909881591796875, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 46366), -- Bread of the Dead (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+405, 195067, 0, 1519, 5346, '0', 0, 0, -8240.6796875, 937.62701416015625, 97.5236968994140625, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+406, 195067, 0, 1519, 5346, '0', 0, 0, -8272.41015625, 944.01702880859375, 97.48439788818359375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+407, 195067, 0, 1519, 5346, '0', 0, 0, -8259.3603515625, 937.20001220703125, 97.48439788818359375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+408, 195067, 0, 1519, 5346, '0', 0, 0, -8293.5400390625, 933.2659912109375, 97.47190093994140625, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+409, 195067, 0, 1519, 5346, '0', 0, 0, -8319.4599609375, 931.760009765625, 97.10399627685546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+410, 195067, 0, 1519, 5346, '0', 0, 0, -8322.509765625, 889.52301025390625, 98.340301513671875, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+411, 195067, 0, 1519, 5346, '0', 0, 0, -8278.6904296875, 950.71197509765625, 97.43990325927734375, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+412, 195067, 0, 1519, 5346, '0', 0, 0, -8262.9296875, 964.22198486328125, 97.48439788818359375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+413, 195067, 0, 1519, 5346, '0', 0, 0, -8270.4697265625, 861.70501708984375, 99.10870361328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+414, 195067, 0, 1519, 5346, '0', 0, 0, -8281.0498046875, 899.530029296875, 97.99829864501953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+415, 195067, 0, 1519, 5346, '0', 0, 0, -8284.0703125, 878.47900390625, 99.26909637451171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+416, 195067, 0, 1519, 5346, '0', 0, 0, -8261.5703125, 909.97900390625, 97.52950286865234375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+417, 195067, 0, 1519, 5346, '0', 0, 0, -8274.5, 914.47698974609375, 97.656097412109375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+418, 195067, 0, 1519, 5346, '0', 0, 0, -8253.0302734375, 929.81298828125, 97.48439788818359375, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+419, 195067, 0, 1519, 5346, '0', 0, 0, -8283.6201171875, 968.18402099609375, 99.74069976806640625, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+420, 195067, 0, 1519, 5346, '0', 0, 0, -8305.830078125, 932.03802490234375, 97.43990325927734375, 1.431168079376220703, 0, 0, 0.656058311462402343, 0.754710197448730468, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+421, 195067, 0, 1519, 5346, '0', 0, 0, -8346.169921875, 916.4110107421875, 97.33499908447265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+422, 195067, 0, 1519, 5346, '0', 0, 0, -8359.3603515625, 929.99700927734375, 97.1349029541015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+423, 195067, 0, 1519, 5346, '0', 0, 0, -8342.849609375, 950.75201416015625, 96.46669769287109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+424, 195067, 0, 1519, 5346, '0', 0, 0, -8352.9599609375, 955.093994140625, 96.3489990234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+425, 195067, 0, 1519, 5346, '0', 0, 0, -8292.01953125, 989.8590087890625, 101.4520034790039062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+426, 195067, 0, 1519, 5346, '0', 0, 0, -8367.650390625, 912.5889892578125, 97.93090057373046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+427, 195067, 0, 1519, 5346, '0', 0, 0, -8370.0703125, 956.03802490234375, 96.33910369873046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+428, 195067, 0, 1519, 5346, '0', 0, 0, -8372.7001953125, 972.23797607421875, 96.17769622802734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+429, 195067, 0, 1519, 5346, '0', 0, 0, -8393.9296875, 920.86798095703125, 98.31400299072265625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+430, 195067, 0, 1519, 5346, '0', 0, 0, -8393.009765625, 931.2659912109375, 97.86840057373046875, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+431, 195067, 0, 1519, 5346, '0', 0, 0, -8402.98046875, 912.0050048828125, 98.42819976806640625, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+432, 195067, 0, 1519, 5346, '0', 0, 0, -8381.8798828125, 981.08197021484375, 96.039703369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+433, 195067, 0, 1519, 5346, '0', 0, 0, -8415.419921875, 947.3179931640625, 98.100799560546875, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+434, 195067, 0, 1519, 5346, '0', 0, 0, -8412.1904296875, 963.95001220703125, 97.75420379638671875, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+435, 195067, 0, 1519, 5346, '0', 0, 0, -8420.580078125, 967.72198486328125, 98.2505035400390625, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+436, 195067, 0, 1519, 5346, '0', 0, 0, -8420.2197265625, 924.67401123046875, 98.70330047607421875, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+437, 195067, 0, 1519, 5346, '0', 0, 0, -8422.6796875, 942.08502197265625, 98.41609954833984375, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+438, 195067, 0, 1519, 5346, '0', 0, 0, -8446.9296875, 942.37799072265625, 97.88159942626953125, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+439, 195067, 0, 1519, 5346, '0', 0, 0, -8457.6298828125, 920.4310302734375, 98.75640106201171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+440, 195067, 0, 1519, 5346, '0', 0, 0, -8454.1904296875, 900.31402587890625, 99.72100067138671875, 0.506144583225250244, 0, 0, 0.250379562377929687, 0.968147754669189453, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+441, 195067, 0, 1519, 5346, '0', 0, 0, -8456.0595703125, 899.11798095703125, 99.76149749755859375, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+442, 195068, 0, 1519, 5346, '0', 0, 0, -8288.8896484375, 940.3179931640625, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+443, 195068, 0, 1519, 5346, '0', 0, 0, -8242.849609375, 927.030029296875, 98.33029937744140625, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+444, 195068, 0, 1519, 5346, '0', 0, 0, -8309.33984375, 894.53802490234375, 98.6197967529296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+445, 195068, 0, 1519, 5346, '0', 0, 0, -8268.16015625, 938.31298828125, 97.48439788818359375, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+446, 195068, 0, 1519, 5346, '0', 0, 0, -8289.7001953125, 875.64202880859375, 99.73439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+447, 195068, 0, 1519, 5346, '0', 0, 0, -8282.0595703125, 957.09197998046875, 97.487701416015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+448, 195068, 0, 1519, 5346, '0', 0, 0, -8268.41015625, 921.03302001953125, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+449, 195068, 0, 1519, 5346, '0', 0, 0, -8287.5, 889.8800048828125, 98.46179962158203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+450, 195068, 0, 1519, 5346, '0', 0, 0, -8302.6298828125, 876.72900390625, 99.34210205078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+451, 195068, 0, 1519, 5346, '0', 0, 0, -8260, 930.02301025390625, 97.48439788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+452, 195068, 0, 1519, 5346, '0', 0, 0, -8276.8896484375, 925.8489990234375, 97.50080108642578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+453, 195068, 0, 1519, 5346, '0', 0, 0, -8317.0400390625, 898.84002685546875, 98.31060028076171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+454, 195068, 0, 1519, 5346, '0', 0, 0, -8290.509765625, 930.36798095703125, 97.5198974609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+455, 195068, 0, 1519, 5346, '0', 0, 0, -8310, 934.02801513671875, 97.30989837646484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+456, 195068, 0, 1519, 5346, '0', 0, 0, -8314.3896484375, 883.8179931640625, 98.72699737548828125, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+457, 195068, 0, 1519, 5346, '0', 0, 0, -8265.6103515625, 911.43902587890625, 97.5597991943359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+458, 195068, 0, 1519, 5346, '0', 0, 0, -8308.7001953125, 926.38397216796875, 97.42459869384765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+459, 195068, 0, 1519, 5346, '0', 0, 0, -8305.2802734375, 940.15301513671875, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+460, 195068, 0, 1519, 5346, '0', 0, 0, -8281.0400390625, 964.0419921875, 98.564697265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+461, 195068, 0, 1519, 5346, '0', 0, 0, -8306.5302734375, 925.31402587890625, 97.43990325927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+462, 195068, 0, 1519, 5346, '0', 0, 0, -8280.7001953125, 900.36602783203125, 97.97730255126953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+463, 195068, 0, 1519, 5346, '0', 0, 0, -8284.76953125, 864.6719970703125, 99.71230316162109375, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+464, 195068, 0, 1519, 5346, '0', 0, 0, -8280.9697265625, 861.34698486328125, 99.877197265625, 0.209439441561698913, 0, 0, 0.104528427124023437, 0.994521915912628173, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+465, 195068, 0, 1519, 5346, '0', 0, 0, -8279.240234375, 928.85400390625, 97.4989013671875, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+466, 195068, 0, 1519, 5346, '0', 0, 0, -8250.4404296875, 937.04498291015625, 97.48439788818359375, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+467, 195068, 0, 1519, 5346, '0', 0, 0, -8293.7197265625, 894.79302978515625, 98.11499786376953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+468, 195068, 0, 1519, 5346, '0', 0, 0, -8344.740234375, 944.58001708984375, 96.5702972412109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+469, 195068, 0, 1519, 5346, '0', 0, 0, -8357.1396484375, 906.58001708984375, 97.5684967041015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+470, 195068, 0, 1519, 5346, '0', 0, 0, -8356.8896484375, 912.3330078125, 97.6089019775390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+471, 195068, 0, 1519, 5346, '0', 0, 0, -8347.75, 925.37799072265625, 97.12329864501953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+472, 195068, 0, 1519, 5346, '0', 0, 0, -8371.240234375, 913.31097412109375, 98.08679962158203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+473, 195068, 0, 1519, 5346, '0', 0, 0, -8361.830078125, 950.780029296875, 96.42980194091796875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+474, 195068, 0, 1519, 5346, '0', 0, 0, -8294.4296875, 992.37701416015625, 101.4520034790039062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+475, 195068, 0, 1519, 5346, '0', 0, 0, -8387.8603515625, 919.50299072265625, 98.357696533203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+476, 195068, 0, 1519, 5346, '0', 0, 0, -8392.6103515625, 915.97601318359375, 98.4987030029296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+477, 195068, 0, 1519, 5346, '0', 0, 0, -8395.76953125, 920.1719970703125, 98.34420013427734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+478, 195068, 0, 1519, 5346, '0', 0, 0, -8370.8896484375, 971.5689697265625, 96.20839691162109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+479, 195068, 0, 1519, 5346, '0', 0, 0, -8403.509765625, 934.31597900390625, 98.032501220703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+480, 195068, 0, 1519, 5346, '0', 0, 0, -8374.400390625, 979.84002685546875, 96.14080047607421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+481, 195068, 0, 1519, 5346, '0', 0, 0, -8411.849609375, 929.53302001953125, 98.397796630859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+482, 195068, 0, 1519, 5346, '0', 0, 0, -8410.3095703125, 979.5830078125, 99.7574005126953125, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+483, 195068, 0, 1519, 5346, '0', 0, 0, -8422.26953125, 956.697998046875, 98.29689788818359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+484, 195068, 0, 1519, 5346, '0', 0, 0, -8420.5595703125, 949.95501708984375, 98.2548980712890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+485, 195068, 0, 1519, 5346, '0', 0, 0, -8424.349609375, 940.86602783203125, 98.47820281982421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+486, 195068, 0, 1519, 5346, '0', 0, 0, -8440.8603515625, 941.302001953125, 98.4613037109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+487, 195068, 0, 1519, 5346, '0', 0, 0, -8434.5302734375, 949.25701904296875, 98.4322967529296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+488, 195068, 0, 1519, 5346, '0', 0, 0, -8441.900390625, 901.031005859375, 98.84909820556640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+489, 195068, 0, 1519, 5346, '0', 0, 0, -8433.6904296875, 911.52801513671875, 98.82990264892578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+490, 195068, 0, 1519, 5346, '0', 0, 0, -8430.919921875, 959.79998779296875, 98.59169769287109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+491, 195068, 0, 1519, 5346, '0', 0, 0, -8462.01953125, 913.62298583984375, 98.740997314453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+492, 195068, 0, 1519, 5346, '0', 0, 0, -8449.349609375, 903.8489990234375, 99.57879638671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+493, 195068, 0, 1519, 5346, '0', 0, 0, -8451.9697265625, 894.71502685546875, 99.70929718017578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+494, 195069, 0, 1519, 5346, '0', 0, 0, -8276.650390625, 900.02301025390625, 98.02500152587890625, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Candy Skulls (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+495, 195069, 0, 1519, 5346, '0', 0, 0, -8293, 910.9639892578125, 98.94989776611328125, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 46366), -- Candy Skulls (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+496, 195069, 0, 1519, 5346, '0', 0, 0, -8293.0703125, 910.20501708984375, 98.94989776611328125, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 46366), -- Candy Skulls (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+497, 195069, 0, 1519, 5346, '0', 0, 0, -8293.5400390625, 991.71697998046875, 101.4520034790039062, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 46366), -- Candy Skulls (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+498, 195087, 0, 1519, 5346, '0', 0, 0, -8287.9501953125, 899.4219970703125, 100.4209976196289062, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+499, 195087, 0, 1519, 5346, '0', 0, 0, -8277.5302734375, 900.49798583984375, 98.0110015869140625, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+500, 195087, 0, 1519, 5346, '0', 0, 0, -8284.5302734375, 906.87799072265625, 100.4209976196289062, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+501, 195090, 0, 1519, 5346, '0', 0, 0, -8279.1103515625, 976.48101806640625, 103.0930023193359375, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+502, 195090, 0, 1519, 5346, '0', 0, 0, -8304.7900390625, 941.07098388671875, 100.9710006713867187, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+503, 195090, 0, 1519, 5346, '0', 0, 0, -8273.6298828125, 856.75201416015625, 100.680999755859375, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+504, 195090, 0, 1519, 5346, '0', 0, 0, -8317.490234375, 897.6409912109375, 100.1389999389648437, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+505, 195090, 0, 1519, 5346, '0', 0, 0, -8256.5, 958.21002197265625, 99.91809844970703125, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+506, 195090, 0, 1519, 5346, '0', 0, 0, -8267.8203125, 959.34197998046875, 99.08789825439453125, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+507, 195090, 0, 1519, 5346, '0', 0, 0, -8277.4404296875, 898.84197998046875, 98.071197509765625, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+508, 195090, 0, 1519, 5346, '0', 0, 0, -8284.8095703125, 925.87799072265625, 98.99210357666015625, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+509, 195090, 0, 1519, 5346, '0', 0, 0, -8287.7802734375, 878.7239990234375, 101.1439971923828125, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+510, 195090, 0, 1519, 5346, '0', 0, 0, -8245.669921875, 932.53497314453125, 99.11699676513671875, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+511, 195090, 0, 1519, 5346, '0', 0, 0, -8266.419921875, 928.97698974609375, 98.97540283203125, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+512, 195090, 0, 1519, 5346, '0', 0, 0, -8285.240234375, 937.5989990234375, 99.99109649658203125, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+513, 195090, 0, 1519, 5346, '0', 0, 0, -8257.349609375, 928.60198974609375, 98.98310089111328125, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+514, 195090, 0, 1519, 5346, '0', 0, 0, -8296.5595703125, 881.760009765625, 101.5839996337890625, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+515, 195090, 0, 1519, 5346, '0', 0, 0, -8260.7900390625, 911.22900390625, 99.93599700927734375, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+516, 195090, 0, 1519, 5346, '0', 0, 0, -8292.2099609375, 926.64801025390625, 98.9210968017578125, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+517, 195090, 0, 1519, 5346, '0', 0, 0, -8284.3095703125, 962.05401611328125, 99.74449920654296875, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+518, 195090, 0, 1519, 5346, '0', 0, 0, -8293.91015625, 910.49298095703125, 98.95269775390625, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+519, 195090, 0, 1519, 5346, '0', 0, 0, -8317.099609375, 884.13897705078125, 98.549102783203125, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+520, 195090, 0, 1519, 5346, '0', 0, 0, -8349.58984375, 947.70501708984375, 98.9579010009765625, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+521, 195090, 0, 1519, 5346, '0', 0, 0, -8385.0302734375, 919.82501220703125, 99.413299560546875, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+522, 195090, 0, 1519, 5346, '0', 0, 0, -8369.0595703125, 963.75701904296875, 97.70349884033203125, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+523, 195090, 0, 1519, 5346, '0', 0, 0, -8369.66015625, 980.34002685546875, 98.74179840087890625, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+524, 195090, 0, 1519, 5346, '0', 0, 0, -8383.650390625, 974.79498291015625, 97.5634002685546875, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+525, 195090, 0, 1519, 5346, '0', 0, 0, -8396.990234375, 913.42401123046875, 99.94770050048828125, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+526, 195090, 0, 1519, 5346, '0', 0, 0, -8414.51953125, 916.95697021484375, 101.1389999389648437, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+527, 195090, 0, 1519, 5346, '0', 0, 0, -8431.8095703125, 905.58001708984375, 100.5029983520507812, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+528, 195090, 0, 1519, 5346, '0', 0, 0, -8443.3203125, 905.97601318359375, 100.6859970092773437, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 46366), -- Spirit Candle (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+529, 195307, 0, 1519, 5346, '0', 0, 0, -8293.830078125, 909.81597900390625, 98.9116973876953125, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+530, 195307, 0, 1519, 5346, '0', 0, 0, -8291.4697265625, 915.41302490234375, 98.67279815673828125, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+531, 195307, 0, 1519, 5346, '0', 0, 0, -8302.650390625, 876.73797607421875, 99.34059906005859375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+532, 195307, 0, 1519, 5346, '0', 0, 0, -8306.169921875, 925.875, 97.9723968505859375, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+533, 195307, 0, 1519, 5346, '0', 0, 0, -8313.2802734375, 889.9310302734375, 99.652099609375, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+534, 195307, 0, 1519, 5346, '0', 0, 0, -8309.4697265625, 943.49798583984375, 99.72039794921875, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+535, 195307, 0, 1519, 5346, '0', 0, 0, -8313.2802734375, 889.9310302734375, 99.652099609375, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+536, 195307, 0, 1519, 5346, '0', 0, 0, -8273.6298828125, 922.76397705078125, 98.241302490234375, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+537, 195307, 0, 1519, 5346, '0', 0, 0, -8340.2998046875, 918.12200927734375, 98.1708984375, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+538, 195307, 0, 1519, 5346, '0', 0, 0, -8269.48046875, 942.34698486328125, 98.42449951171875, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+539, 195307, 0, 1519, 5346, '0', 0, 0, -8317.0595703125, 898.8489990234375, 98.30950164794921875, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+540, 195307, 0, 1519, 5346, '0', 0, 0, -8314.419921875, 927.79498291015625, 97.567901611328125, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+541, 195307, 0, 1519, 5346, '0', 0, 0, -8302.6396484375, 876.74700927734375, 99.341400146484375, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+542, 195307, 0, 1519, 5346, '0', 0, 0, -8282.3798828125, 937.81298828125, 98.38480377197265625, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+543, 195307, 0, 1519, 5346, '0', 0, 0, -8268.7001953125, 911.4439697265625, 97.9459991455078125, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+544, 195307, 0, 1519, 5346, '0', 0, 0, -8276.2099609375, 874.8330078125, 99.43070220947265625, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+545, 195307, 0, 1519, 5346, '0', 0, 0, -8293.759765625, 909.82598876953125, 98.9093017578125, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+546, 195307, 0, 1519, 5346, '0', 0, 0, -8290.0498046875, 949.38897705078125, 97.83100128173828125, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+547, 195307, 0, 1519, 5346, '0', 0, 0, -8306.0498046875, 893.5830078125, 98.93990325927734375, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+548, 195307, 0, 1519, 5346, '0', 0, 0, -8278.9599609375, 962.49700927734375, 98.02159881591796875, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+549, 195307, 0, 1519, 5346, '0', 0, 0, -8280.6103515625, 936.1510009765625, 98.4275970458984375, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+550, 195307, 0, 1519, 5346, '0', 0, 0, -8269.1298828125, 958.1090087890625, 98.2180023193359375, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+551, 195307, 0, 1519, 5346, '0', 0, 0, -8340.2998046875, 918.14801025390625, 98.16970062255859375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+552, 195307, 0, 1519, 5346, '0', 0, 0, -8287.509765625, 889.89801025390625, 98.46089935302734375, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+553, 195307, 0, 1519, 5346, '0', 0, 0, -8291.4599609375, 915.41802978515625, 98.6719970703125, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+554, 195307, 0, 1519, 5346, '0', 0, 0, -8268.0498046875, 877.34197998046875, 100.102996826171875, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+555, 195307, 0, 1519, 5346, '0', 0, 0, -8346.26953125, 903.29498291015625, 97.65630340576171875, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+556, 195307, 0, 1519, 5346, '0', 0, 0, -8278.7001953125, 900.4010009765625, 98.01039886474609375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+557, 195307, 0, 1519, 5346, '0', 0, 0, -8314.3095703125, 927.74798583984375, 97.5625, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+558, 195307, 0, 1519, 5346, '0', 0, 0, -8306.0595703125, 893.57501220703125, 98.936798095703125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+559, 195307, 0, 1519, 5346, '0', 0, 0, -8265.5595703125, 911.45001220703125, 97.5590972900390625, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+560, 195307, 0, 1519, 5346, '0', 0, 0, -8340.2998046875, 918.14801025390625, 98.16970062255859375, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+561, 195307, 0, 1519, 5346, '0', 0, 0, -8254.349609375, 955.34698486328125, 99.93060302734375, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+562, 195307, 0, 1519, 5346, '0', 0, 0, -8278.3798828125, 915.4169921875, 99.187103271484375, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+563, 195307, 0, 1519, 5346, '0', 0, 0, -8306.0498046875, 893.5830078125, 98.93990325927734375, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+564, 195307, 0, 1519, 5346, '0', 0, 0, -8306.66015625, 901.36297607421875, 99.8968963623046875, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+565, 195307, 0, 1519, 5346, '0', 0, 0, -8287.509765625, 889.89801025390625, 98.46089935302734375, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+566, 195307, 0, 1519, 5346, '0', 0, 0, -8276.2099609375, 874.8330078125, 99.43070220947265625, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+567, 195307, 0, 1519, 5346, '0', 0, 0, -8246.7802734375, 942.67901611328125, 98.229400634765625, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+568, 195307, 0, 1519, 5346, '0', 0, 0, -8291.4697265625, 915.41302490234375, 98.67279815673828125, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+569, 195307, 0, 1519, 5346, '0', 0, 0, -8302.6396484375, 876.74700927734375, 99.341400146484375, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+570, 195307, 0, 1519, 5346, '0', 0, 0, -8269.48046875, 942.35198974609375, 98.42459869384765625, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+571, 195307, 0, 1519, 5346, '0', 0, 0, -8285.3095703125, 863.86297607421875, 101.1750030517578125, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+572, 195307, 0, 1519, 5346, '0', 0, 0, -8276.23046875, 874.82501220703125, 99.4297027587890625, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+573, 195307, 0, 1519, 5346, '0', 0, 0, -8309.490234375, 943.61798095703125, 99.72039794921875, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+574, 195307, 0, 1519, 5346, '0', 0, 0, -8269.1201171875, 958.10601806640625, 98.21829986572265625, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+575, 195307, 0, 1519, 5346, '0', 0, 0, -8306.66015625, 901.36297607421875, 99.8968963623046875, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+576, 195307, 0, 1519, 5346, '0', 0, 0, -8317.0400390625, 898.85797119140625, 98.30950164794921875, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+577, 195307, 0, 1519, 5346, '0', 0, 0, -8273.4501953125, 862.54901123046875, 100.2949981689453125, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+578, 195307, 0, 1519, 5346, '0', 0, 0, -8287.5302734375, 889.88897705078125, 98.461700439453125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+579, 195307, 0, 1519, 5346, '0', 0, 0, -8293.900390625, 909.85198974609375, 98.9136962890625, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+580, 195307, 0, 1519, 5346, '0', 0, 0, -8280.6201171875, 936.14599609375, 98.42749786376953125, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+581, 195307, 0, 1519, 5346, '0', 0, 0, -8317.0400390625, 898.85797119140625, 98.30950164794921875, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+582, 195307, 0, 1519, 5346, '0', 0, 0, -8265.5595703125, 911.45001220703125, 97.5590972900390625, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+583, 195307, 0, 1519, 5346, '0', 0, 0, -8354.25, 926.97601318359375, 98.76979827880859375, 1.047197580337524414, 0, 0, 0.5, 0.866025388240814208, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+584, 195307, 0, 1519, 5346, '0', 0, 0, -8350.7802734375, 946.0570068359375, 96.82309722900390625, 0.680676698684692382, 0, 0, 0.333806037902832031, 0.942641794681549072, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+585, 195307, 0, 1519, 5346, '0', 0, 0, -8355.330078125, 904.8280029296875, 98.02719879150390625, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+586, 195307, 0, 1519, 5346, '0', 0, 0, -8364.5, 921.54498291015625, 99.425201416015625, 1.274088263511657714, 0, 0, 0.594821929931640625, 0.80385744571685791, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+587, 195307, 0, 1519, 5346, '0', 0, 0, -8350.6298828125, 955.25299072265625, 97.8516998291015625, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+588, 195307, 0, 1519, 5346, '0', 0, 0, -8366.16015625, 954.9639892578125, 96.930999755859375, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+589, 195307, 0, 1519, 5346, '0', 0, 0, -8393.0400390625, 935.43402099609375, 98.62349700927734375, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+590, 195307, 0, 1519, 5346, '0', 0, 0, -8379.150390625, 965.68402099609375, 96.54309844970703125, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+591, 195307, 0, 1519, 5346, '0', 0, 0, -8395.3701171875, 919.07598876953125, 99.8065032958984375, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+592, 195307, 0, 1519, 5346, '0', 0, 0, -8392.650390625, 935.114990234375, 98.64600372314453125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+593, 195307, 0, 1519, 5346, '0', 0, 0, -8379.16015625, 965.655029296875, 96.55120086669921875, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+594, 195307, 0, 1519, 5346, '0', 0, 0, -8379.16015625, 965.6820068359375, 96.5447998046875, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+595, 195307, 0, 1519, 5346, '0', 0, 0, -8401.6396484375, 964.7760009765625, 98.08390045166015625, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+596, 195307, 0, 1519, 5346, '0', 0, 0, -8387.91015625, 957.01898193359375, 97.51180267333984375, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+597, 195307, 0, 1519, 5346, '0', 0, 0, -8387.919921875, 957.16998291015625, 97.49109649658203125, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+598, 195307, 0, 1519, 5346, '0', 0, 0, -8388.099609375, 956.92401123046875, 97.47769927978515625, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+599, 195307, 0, 1519, 5346, '0', 0, 0, -8393.6103515625, 935.72900390625, 98.58820343017578125, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+600, 195307, 0, 1519, 5346, '0', 0, 0, -8383.75, 982.71002197265625, 98.52570343017578125, 1.239183306694030761, 0, 0, 0.580702781677246093, 0.814115643501281738, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+601, 195307, 0, 1519, 5346, '0', 0, 0, -8403.91015625, 916.18902587890625, 99.03780364990234375, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+602, 195307, 0, 1519, 5346, '0', 0, 0, -8410.8603515625, 949.8909912109375, 98.12359619140625, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+603, 195307, 0, 1519, 5346, '0', 0, 0, -8410.8095703125, 949.8699951171875, 98.1324005126953125, 0.401424884796142578, 0, 0, 0.199367523193359375, 0.979924798011779785, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+604, 195307, 0, 1519, 5346, '0', 0, 0, -8410.8095703125, 949.8699951171875, 98.1316986083984375, 5.84685373306274414, 0, 0, -0.21643924713134765, 0.976296067237854003, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+605, 195307, 0, 1519, 5346, '0', 0, 0, -8412.650390625, 964.60797119140625, 98.33730316162109375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+606, 195307, 0, 1519, 5346, '0', 0, 0, -8420.3798828125, 944.8699951171875, 99.70330047607421875, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+607, 195307, 0, 1519, 5346, '0', 0, 0, -8417.490234375, 961.385009765625, 99.6764984130859375, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+608, 195307, 0, 1519, 5346, '0', 0, 0, -8424.91015625, 964.1409912109375, 98.74829864501953125, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+609, 195307, 0, 1519, 5346, '0', 0, 0, -8425.099609375, 947.3489990234375, 98.96230316162109375, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+610, 195307, 0, 1519, 5346, '0', 0, 0, -8424.8798828125, 941.36102294921875, 99.026397705078125, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+611, 195307, 0, 1519, 5346, '0', 0, 0, -8444.1201171875, 944.7030029296875, 98.49639892578125, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+612, 195307, 0, 1519, 5346, '0', 0, 0, -8444.1201171875, 944.7030029296875, 98.49639892578125, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+613, 195307, 0, 1519, 5346, '0', 0, 0, -8430.3701171875, 914.40301513671875, 99.11299896240234375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+614, 195307, 0, 1519, 5346, '0', 0, 0, -8444.0595703125, 944.66998291015625, 98.508697509765625, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+615, 195307, 0, 1519, 5346, '0', 0, 0, -8433.6904296875, 940.68798828125, 101.0739974975585937, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+616, 195307, 0, 1519, 5346, '0', 0, 0, -8434.5400390625, 949.30902099609375, 98.43070220947265625, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+617, 195307, 0, 1519, 5346, '0', 0, 0, -8434.5498046875, 949.2860107421875, 98.430999755859375, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+618, 195307, 0, 1519, 5346, '0', 0, 0, -8440.75, 910.31097412109375, 99.48809814453125, 4.171337604522705078, 0, 0, -0.87035560607910156, 0.492423713207244873, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+619, 195307, 0, 1519, 5346, '0', 0, 0, -8426.5498046875, 907.47601318359375, 99.533203125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+620, 195307, 0, 1519, 5346, '0', 0, 0, -8440.580078125, 949.364990234375, 99.13800048828125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+621, 195307, 0, 1519, 5346, '0', 0, 0, -8430.349609375, 914.4010009765625, 99.11150360107421875, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+622, 195307, 0, 1519, 5346, '0', 0, 0, -8440.5400390625, 900.9530029296875, 99.1201019287109375, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+623, 195307, 0, 1519, 5346, '0', 0, 0, -8442.2099609375, 899.54498291015625, 100.2220001220703125, 5.201082706451416015, 0, 0, -0.51503753662109375, 0.857167601585388183, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+624, 195307, 0, 1519, 5346, '0', 0, 0, -8460.0400390625, 918.20098876953125, 99.133697509765625, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+625, 195307, 0, 1519, 5346, '0', 0, 0, -8460, 918.1820068359375, 99.13300323486328125, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 120, 255, 1, 46366), -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)
(@OGUID+626, 195307, 0, 1519, 5346, '0', 0, 0, -8460.0302734375, 918.19598388671875, 99.13559722900390625, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 46366); -- Orange Marigolds (Area: Stormwind City Cemetery - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+138;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(51, @CGUID+0), 
(51, @CGUID+1), 
(51, @CGUID+2), 
(51, @CGUID+3), 
(51, @CGUID+4), 
(51, @CGUID+5), 
(51, @CGUID+6), 
(51, @CGUID+7), 
(51, @CGUID+8), 
(51, @CGUID+9), 
(51, @CGUID+10),
(51, @CGUID+11),
(51, @CGUID+12),
(51, @CGUID+13),
(51, @CGUID+14),
(51, @CGUID+15),
(51, @CGUID+16),
(51, @CGUID+17),
(51, @CGUID+18),
(51, @CGUID+19),
(51, @CGUID+20),
(51, @CGUID+21),
(51, @CGUID+22),
(51, @CGUID+23),
(51, @CGUID+24),
(51, @CGUID+25),
(51, @CGUID+26),
(51, @CGUID+27),
(51, @CGUID+28),
(51, @CGUID+29),
(51, @CGUID+30),
(51, @CGUID+31),
(51, @CGUID+32),
(51, @CGUID+33),
(51, @CGUID+34),
(51, @CGUID+35),
(51, @CGUID+36),
(51, @CGUID+37),
(51, @CGUID+38),
(51, @CGUID+39),
(51, @CGUID+40),
(51, @CGUID+41),
(51, @CGUID+42),
(51, @CGUID+43),
(51, @CGUID+44),
(51, @CGUID+45),
(51, @CGUID+46),
(51, @CGUID+47),
(51, @CGUID+48),
(51, @CGUID+49),
(51, @CGUID+50),
(51, @CGUID+51),
(51, @CGUID+52),
(51, @CGUID+53),
(51, @CGUID+54),
(51, @CGUID+55),
(51, @CGUID+56),
(51, @CGUID+57),
(51, @CGUID+58),
(51, @CGUID+59),
(51, @CGUID+60),
(51, @CGUID+61),
(51, @CGUID+62),
(51, @CGUID+63),
(51, @CGUID+64),
(51, @CGUID+65),
(51, @CGUID+66),
(51, @CGUID+67),
(51, @CGUID+68),
(51, @CGUID+69),
(51, @CGUID+70),
(51, @CGUID+71),
(51, @CGUID+72),
(51, @CGUID+73),
(51, @CGUID+74),
(51, @CGUID+75),
(51, @CGUID+76),
(51, @CGUID+77),
(51, @CGUID+78),
(51, @CGUID+79),
(51, @CGUID+80),
(51, @CGUID+81),
(51, @CGUID+82),
(51, @CGUID+83),
(51, @CGUID+84),
(51, @CGUID+85),
(51, @CGUID+86),
(51, @CGUID+87),
(51, @CGUID+88),
(51, @CGUID+89),
(51, @CGUID+90),
(51, @CGUID+91),
(51, @CGUID+92),
(51, @CGUID+93),
(51, @CGUID+94),
(51, @CGUID+95),
(51, @CGUID+96),
(51, @CGUID+97),
(51, @CGUID+98),
(51, @CGUID+99),
(51, @CGUID+100),
(51, @CGUID+101),
(51, @CGUID+102),
(51, @CGUID+103),
(51, @CGUID+104),
(51, @CGUID+105),
(51, @CGUID+106),
(51, @CGUID+107),
(51, @CGUID+108),
(51, @CGUID+109),
(51, @CGUID+110),
(51, @CGUID+111),
(51, @CGUID+112),
(51, @CGUID+113),
(51, @CGUID+114),
(51, @CGUID+115),
(51, @CGUID+116),
(51, @CGUID+117),
(51, @CGUID+118),
(51, @CGUID+119),
(51, @CGUID+120),
(51, @CGUID+121),
(51, @CGUID+122),
(51, @CGUID+123),
(51, @CGUID+124),
(51, @CGUID+125),
(51, @CGUID+126),
(51, @CGUID+127),
(51, @CGUID+128),
(51, @CGUID+129),
(51, @CGUID+130),
(51, @CGUID+131),
(51, @CGUID+132),
(51, @CGUID+133),
(51, @CGUID+134),
(51, @CGUID+135),
(51, @CGUID+136),
(51, @CGUID+137),
(51, @CGUID+138);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+626;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(51, @OGUID+0),
(51, @OGUID+1),
(51, @OGUID+2),
(51, @OGUID+3),
(51, @OGUID+4),
(51, @OGUID+5),
(51, @OGUID+6),
(51, @OGUID+7),
(51, @OGUID+8),
(51, @OGUID+9),
(51, @OGUID+10),
(51, @OGUID+11),
(51, @OGUID+12),
(51, @OGUID+13),
(51, @OGUID+14),
(51, @OGUID+15),
(51, @OGUID+16),
(51, @OGUID+17),
(51, @OGUID+18),
(51, @OGUID+19),
(51, @OGUID+20),
(51, @OGUID+21),
(51, @OGUID+22),
(51, @OGUID+23),
(51, @OGUID+24),
(51, @OGUID+25),
(51, @OGUID+26),
(51, @OGUID+27),
(51, @OGUID+28),
(51, @OGUID+29),
(51, @OGUID+30),
(51, @OGUID+31),
(51, @OGUID+32),
(51, @OGUID+33),
(51, @OGUID+34),
(51, @OGUID+35),
(51, @OGUID+36),
(51, @OGUID+37),
(51, @OGUID+38),
(51, @OGUID+39),
(51, @OGUID+40),
(51, @OGUID+41),
(51, @OGUID+42),
(51, @OGUID+43),
(51, @OGUID+44),
(51, @OGUID+45),
(51, @OGUID+46),
(51, @OGUID+47),
(51, @OGUID+48),
(51, @OGUID+49),
(51, @OGUID+50),
(51, @OGUID+51),
(51, @OGUID+52),
(51, @OGUID+53),
(51, @OGUID+54),
(51, @OGUID+55),
(51, @OGUID+56),
(51, @OGUID+57),
(51, @OGUID+58),
(51, @OGUID+59),
(51, @OGUID+60),
(51, @OGUID+61),
(51, @OGUID+62),
(51, @OGUID+63),
(51, @OGUID+64),
(51, @OGUID+65),
(51, @OGUID+66),
(51, @OGUID+67),
(51, @OGUID+68),
(51, @OGUID+69),
(51, @OGUID+70),
(51, @OGUID+71),
(51, @OGUID+72),
(51, @OGUID+73),
(51, @OGUID+74),
(51, @OGUID+75),
(51, @OGUID+76),
(51, @OGUID+77),
(51, @OGUID+78),
(51, @OGUID+79),
(51, @OGUID+80),
(51, @OGUID+81),
(51, @OGUID+82),
(51, @OGUID+83),
(51, @OGUID+84),
(51, @OGUID+85),
(51, @OGUID+86),
(51, @OGUID+87),
(51, @OGUID+88),
(51, @OGUID+89),
(51, @OGUID+90),
(51, @OGUID+91),
(51, @OGUID+92),
(51, @OGUID+93),
(51, @OGUID+94),
(51, @OGUID+95),
(51, @OGUID+96),
(51, @OGUID+97),
(51, @OGUID+98),
(51, @OGUID+99),
(51, @OGUID+100),
(51, @OGUID+101),
(51, @OGUID+102),
(51, @OGUID+103),
(51, @OGUID+104),
(51, @OGUID+105),
(51, @OGUID+106),
(51, @OGUID+107),
(51, @OGUID+108),
(51, @OGUID+109),
(51, @OGUID+110),
(51, @OGUID+111),
(51, @OGUID+112),
(51, @OGUID+113),
(51, @OGUID+114),
(51, @OGUID+115),
(51, @OGUID+116),
(51, @OGUID+117),
(51, @OGUID+118),
(51, @OGUID+119),
(51, @OGUID+120),
(51, @OGUID+121),
(51, @OGUID+122),
(51, @OGUID+123),
(51, @OGUID+124),
(51, @OGUID+125),
(51, @OGUID+126),
(51, @OGUID+127),
(51, @OGUID+128),
(51, @OGUID+129),
(51, @OGUID+130),
(51, @OGUID+131),
(51, @OGUID+132),
(51, @OGUID+133),
(51, @OGUID+134),
(51, @OGUID+135),
(51, @OGUID+136),
(51, @OGUID+137),
(51, @OGUID+138),
(51, @OGUID+139),
(51, @OGUID+140),
(51, @OGUID+141),
(51, @OGUID+142),
(51, @OGUID+143),
(51, @OGUID+144),
(51, @OGUID+145),
(51, @OGUID+146),
(51, @OGUID+147),
(51, @OGUID+148),
(51, @OGUID+149),
(51, @OGUID+150),
(51, @OGUID+151),
(51, @OGUID+152),
(51, @OGUID+153),
(51, @OGUID+154),
(51, @OGUID+155),
(51, @OGUID+156),
(51, @OGUID+157),
(51, @OGUID+158),
(51, @OGUID+159),
(51, @OGUID+160),
(51, @OGUID+161),
(51, @OGUID+162),
(51, @OGUID+163),
(51, @OGUID+164),
(51, @OGUID+165),
(51, @OGUID+166),
(51, @OGUID+167),
(51, @OGUID+168),
(51, @OGUID+169),
(51, @OGUID+170),
(51, @OGUID+171),
(51, @OGUID+172),
(51, @OGUID+173),
(51, @OGUID+174),
(51, @OGUID+175),
(51, @OGUID+176),
(51, @OGUID+177),
(51, @OGUID+178),
(51, @OGUID+179),
(51, @OGUID+180),
(51, @OGUID+181),
(51, @OGUID+182),
(51, @OGUID+183),
(51, @OGUID+184),
(51, @OGUID+185),
(51, @OGUID+186),
(51, @OGUID+187),
(51, @OGUID+188),
(51, @OGUID+189),
(51, @OGUID+190),
(51, @OGUID+191),
(51, @OGUID+192),
(51, @OGUID+193),
(51, @OGUID+194),
(51, @OGUID+195),
(51, @OGUID+196),
(51, @OGUID+197),
(51, @OGUID+198),
(51, @OGUID+199),
(51, @OGUID+200),
(51, @OGUID+201),
(51, @OGUID+202),
(51, @OGUID+203),
(51, @OGUID+204),
(51, @OGUID+205),
(51, @OGUID+206),
(51, @OGUID+207),
(51, @OGUID+208),
(51, @OGUID+209),
(51, @OGUID+210),
(51, @OGUID+211),
(51, @OGUID+212),
(51, @OGUID+213),
(51, @OGUID+214),
(51, @OGUID+215),
(51, @OGUID+216),
(51, @OGUID+217),
(51, @OGUID+218),
(51, @OGUID+219),
(51, @OGUID+220),
(51, @OGUID+221),
(51, @OGUID+222),
(51, @OGUID+223),
(51, @OGUID+224),
(51, @OGUID+225),
(51, @OGUID+226),
(51, @OGUID+227),
(51, @OGUID+228),
(51, @OGUID+229),
(51, @OGUID+230),
(51, @OGUID+231),
(51, @OGUID+232),
(51, @OGUID+233),
(51, @OGUID+234),
(51, @OGUID+235),
(51, @OGUID+236),
(51, @OGUID+237),
(51, @OGUID+238),
(51, @OGUID+239),
(51, @OGUID+240),
(51, @OGUID+241),
(51, @OGUID+242),
(51, @OGUID+243),
(51, @OGUID+244),
(51, @OGUID+245),
(51, @OGUID+246),
(51, @OGUID+247),
(51, @OGUID+248),
(51, @OGUID+249),
(51, @OGUID+250),
(51, @OGUID+251),
(51, @OGUID+252),
(51, @OGUID+253),
(51, @OGUID+254),
(51, @OGUID+255),
(51, @OGUID+256),
(51, @OGUID+257),
(51, @OGUID+258),
(51, @OGUID+259),
(51, @OGUID+260),
(51, @OGUID+261),
(51, @OGUID+262),
(51, @OGUID+263),
(51, @OGUID+264),
(51, @OGUID+265),
(51, @OGUID+266),
(51, @OGUID+267),
(51, @OGUID+268),
(51, @OGUID+269),
(51, @OGUID+270),
(51, @OGUID+271),
(51, @OGUID+272),
(51, @OGUID+273),
(51, @OGUID+274),
(51, @OGUID+275),
(51, @OGUID+276),
(51, @OGUID+277),
(51, @OGUID+278),
(51, @OGUID+279),
(51, @OGUID+280),
(51, @OGUID+281),
(51, @OGUID+282),
(51, @OGUID+283),
(51, @OGUID+284),
(51, @OGUID+285),
(51, @OGUID+286),
(51, @OGUID+287),
(51, @OGUID+288),
(51, @OGUID+289),
(51, @OGUID+290),
(51, @OGUID+291),
(51, @OGUID+292),
(51, @OGUID+293),
(51, @OGUID+294),
(51, @OGUID+295),
(51, @OGUID+296),
(51, @OGUID+297),
(51, @OGUID+298),
(51, @OGUID+299),
(51, @OGUID+300),
(51, @OGUID+301),
(51, @OGUID+302),
(51, @OGUID+303),
(51, @OGUID+304),
(51, @OGUID+305),
(51, @OGUID+306),
(51, @OGUID+307),
(51, @OGUID+308),
(51, @OGUID+309),
(51, @OGUID+310),
(51, @OGUID+311),
(51, @OGUID+312),
(51, @OGUID+313),
(51, @OGUID+314),
(51, @OGUID+315),
(51, @OGUID+316),
(51, @OGUID+317),
(51, @OGUID+318),
(51, @OGUID+319),
(51, @OGUID+320),
(51, @OGUID+321),
(51, @OGUID+322),
(51, @OGUID+323),
(51, @OGUID+324),
(51, @OGUID+325),
(51, @OGUID+326),
(51, @OGUID+327),
(51, @OGUID+328),
(51, @OGUID+329),
(51, @OGUID+330),
(51, @OGUID+331),
(51, @OGUID+332),
(51, @OGUID+333),
(51, @OGUID+334),
(51, @OGUID+335),
(51, @OGUID+336),
(51, @OGUID+337),
(51, @OGUID+338),
(51, @OGUID+339),
(51, @OGUID+340),
(51, @OGUID+341),
(51, @OGUID+342),
(51, @OGUID+343),
(51, @OGUID+344),
(51, @OGUID+345),
(51, @OGUID+346),
(51, @OGUID+347),
(51, @OGUID+348),
(51, @OGUID+349),
(51, @OGUID+350),
(51, @OGUID+351),
(51, @OGUID+352),
(51, @OGUID+353),
(51, @OGUID+354),
(51, @OGUID+355),
(51, @OGUID+356),
(51, @OGUID+357),
(51, @OGUID+358),
(51, @OGUID+359),
(51, @OGUID+360),
(51, @OGUID+361),
(51, @OGUID+362),
(51, @OGUID+363),
(51, @OGUID+364),
(51, @OGUID+365),
(51, @OGUID+366),
(51, @OGUID+367),
(51, @OGUID+368),
(51, @OGUID+369),
(51, @OGUID+370),
(51, @OGUID+371),
(51, @OGUID+372),
(51, @OGUID+373),
(51, @OGUID+374),
(51, @OGUID+375),
(51, @OGUID+376),
(51, @OGUID+377),
(51, @OGUID+378),
(51, @OGUID+379),
(51, @OGUID+380),
(51, @OGUID+381),
(51, @OGUID+382),
(51, @OGUID+383),
(51, @OGUID+384),
(51, @OGUID+385),
(51, @OGUID+386),
(51, @OGUID+387),
(51, @OGUID+388),
(51, @OGUID+389),
(51, @OGUID+390),
(51, @OGUID+391),
(51, @OGUID+392),
(51, @OGUID+393),
(51, @OGUID+394),
(51, @OGUID+395),
(51, @OGUID+396),
(51, @OGUID+397),
(51, @OGUID+398),
(51, @OGUID+399),
(51, @OGUID+400),
(51, @OGUID+401),
(51, @OGUID+402),
(51, @OGUID+403),
(51, @OGUID+404),
(51, @OGUID+405),
(51, @OGUID+406),
(51, @OGUID+407),
(51, @OGUID+408),
(51, @OGUID+409),
(51, @OGUID+410),
(51, @OGUID+411),
(51, @OGUID+412),
(51, @OGUID+413),
(51, @OGUID+414),
(51, @OGUID+415),
(51, @OGUID+416),
(51, @OGUID+417),
(51, @OGUID+418),
(51, @OGUID+419),
(51, @OGUID+420),
(51, @OGUID+421),
(51, @OGUID+422),
(51, @OGUID+423),
(51, @OGUID+424),
(51, @OGUID+425),
(51, @OGUID+426),
(51, @OGUID+427),
(51, @OGUID+428),
(51, @OGUID+429),
(51, @OGUID+430),
(51, @OGUID+431),
(51, @OGUID+432),
(51, @OGUID+433),
(51, @OGUID+434),
(51, @OGUID+435),
(51, @OGUID+436),
(51, @OGUID+437),
(51, @OGUID+438),
(51, @OGUID+439),
(51, @OGUID+440),
(51, @OGUID+441),
(51, @OGUID+442),
(51, @OGUID+443),
(51, @OGUID+444),
(51, @OGUID+445),
(51, @OGUID+446),
(51, @OGUID+447),
(51, @OGUID+448),
(51, @OGUID+449),
(51, @OGUID+450),
(51, @OGUID+451),
(51, @OGUID+452),
(51, @OGUID+453),
(51, @OGUID+454),
(51, @OGUID+455),
(51, @OGUID+456),
(51, @OGUID+457),
(51, @OGUID+458),
(51, @OGUID+459),
(51, @OGUID+460),
(51, @OGUID+461),
(51, @OGUID+462),
(51, @OGUID+463),
(51, @OGUID+464),
(51, @OGUID+465),
(51, @OGUID+466),
(51, @OGUID+467),
(51, @OGUID+468),
(51, @OGUID+469),
(51, @OGUID+470),
(51, @OGUID+471),
(51, @OGUID+472),
(51, @OGUID+473),
(51, @OGUID+474),
(51, @OGUID+475),
(51, @OGUID+476),
(51, @OGUID+477),
(51, @OGUID+478),
(51, @OGUID+479),
(51, @OGUID+480),
(51, @OGUID+481),
(51, @OGUID+482),
(51, @OGUID+483),
(51, @OGUID+484),
(51, @OGUID+485),
(51, @OGUID+486),
(51, @OGUID+487),
(51, @OGUID+488),
(51, @OGUID+489),
(51, @OGUID+490),
(51, @OGUID+491),
(51, @OGUID+492),
(51, @OGUID+493),
(51, @OGUID+494),
(51, @OGUID+495),
(51, @OGUID+496),
(51, @OGUID+497),
(51, @OGUID+498),
(51, @OGUID+499),
(51, @OGUID+500),
(51, @OGUID+501),
(51, @OGUID+502),
(51, @OGUID+503),
(51, @OGUID+504),
(51, @OGUID+505),
(51, @OGUID+506),
(51, @OGUID+507),
(51, @OGUID+508),
(51, @OGUID+509),
(51, @OGUID+510),
(51, @OGUID+511),
(51, @OGUID+512),
(51, @OGUID+513),
(51, @OGUID+514),
(51, @OGUID+515),
(51, @OGUID+516),
(51, @OGUID+517),
(51, @OGUID+518),
(51, @OGUID+519),
(51, @OGUID+520),
(51, @OGUID+521),
(51, @OGUID+522),
(51, @OGUID+523),
(51, @OGUID+524),
(51, @OGUID+525),
(51, @OGUID+526),
(51, @OGUID+527),
(51, @OGUID+528),
(51, @OGUID+529),
(51, @OGUID+530),
(51, @OGUID+531),
(51, @OGUID+532),
(51, @OGUID+533),
(51, @OGUID+534),
(51, @OGUID+535),
(51, @OGUID+536),
(51, @OGUID+537),
(51, @OGUID+538),
(51, @OGUID+539),
(51, @OGUID+540),
(51, @OGUID+541),
(51, @OGUID+542),
(51, @OGUID+543),
(51, @OGUID+544),
(51, @OGUID+545),
(51, @OGUID+546),
(51, @OGUID+547),
(51, @OGUID+548),
(51, @OGUID+549),
(51, @OGUID+550),
(51, @OGUID+551),
(51, @OGUID+552),
(51, @OGUID+553),
(51, @OGUID+554),
(51, @OGUID+555),
(51, @OGUID+556),
(51, @OGUID+557),
(51, @OGUID+558),
(51, @OGUID+559),
(51, @OGUID+560),
(51, @OGUID+561),
(51, @OGUID+562),
(51, @OGUID+563),
(51, @OGUID+564),
(51, @OGUID+565),
(51, @OGUID+566),
(51, @OGUID+567),
(51, @OGUID+568),
(51, @OGUID+569),
(51, @OGUID+570),
(51, @OGUID+571),
(51, @OGUID+572),
(51, @OGUID+573),
(51, @OGUID+574),
(51, @OGUID+575),
(51, @OGUID+576),
(51, @OGUID+577),
(51, @OGUID+578),
(51, @OGUID+579),
(51, @OGUID+580),
(51, @OGUID+581),
(51, @OGUID+582),
(51, @OGUID+583),
(51, @OGUID+584),
(51, @OGUID+585),
(51, @OGUID+586),
(51, @OGUID+587),
(51, @OGUID+588),
(51, @OGUID+589),
(51, @OGUID+590),
(51, @OGUID+591),
(51, @OGUID+592),
(51, @OGUID+593),
(51, @OGUID+594),
(51, @OGUID+595),
(51, @OGUID+596),
(51, @OGUID+597),
(51, @OGUID+598),
(51, @OGUID+599),
(51, @OGUID+600),
(51, @OGUID+601),
(51, @OGUID+602),
(51, @OGUID+603),
(51, @OGUID+604),
(51, @OGUID+605),
(51, @OGUID+606),
(51, @OGUID+607),
(51, @OGUID+608),
(51, @OGUID+609),
(51, @OGUID+610),
(51, @OGUID+611),
(51, @OGUID+612),
(51, @OGUID+613),
(51, @OGUID+614),
(51, @OGUID+615),
(51, @OGUID+616),
(51, @OGUID+617),
(51, @OGUID+618),
(51, @OGUID+619),
(51, @OGUID+620),
(51, @OGUID+621),
(51, @OGUID+622),
(51, @OGUID+623),
(51, @OGUID+624),
(51, @OGUID+625),
(51, @OGUID+626);

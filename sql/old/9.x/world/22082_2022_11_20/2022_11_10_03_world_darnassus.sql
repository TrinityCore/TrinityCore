SET @CGUID := 396301;
SET @OGUID := 245478;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=10518, `unit_flags`=768 WHERE `entry`=34479; -- Cheerful Night Elf Spirit
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35250; -- Ghostly Night Elf Celebrant
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60 WHERE `entry`=46894; -- Ghostly Worgen Celebrant

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34479; -- 34479 (Cheerful Night Elf Spirit)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35250; -- 35250 (Ghostly Night Elf Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=46894; -- 46894 (Ghostly Worgen Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=46908; -- 46908 (Cheerful Worgen Spirit)

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (46908,46894,35250,34479);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(46908, 0, 0, 0, 414, 46366),
(46894, 0, 0, 0, 414, 46366),
(35250, 0, 0, 0, 414, 46366),
(34479, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (118921,118920,118919,118918,118917,118916,118905,118900,118899,118891,51504,51371,49842,49728,48623,5191,5047,4161,3681,2041));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=3 AND `CreatureID` IN (51371,49842,118900,118899,49728)) OR (`Idx`=2 AND `CreatureID` IN (51371,49842,118900,118899,49728)) OR (`Idx`=1 AND `CreatureID` IN (51371,49842,118900,118899,46894,49728,35250)) OR (`Idx`=0 AND `CreatureID` IN (51371,34479,3681,34770,5047,51504,49842,118900,118899,46894,2041,118917,49728,118921,118916,118891,118918,4161,5191,118920,48623,35250,118905,46908,118919));

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (74962, 74961, 74960, 74959, 74958, 74956, 74955, 74949, 74947, 74948, 74946, 74952, 74950, 74953, 74951, 74941, 37402, 2306, 6302, 35345, 35337, 35336, 29709, 29710, 29231, 3131, 3001, 2216, 10045, 2429);

-- Quests
DELETE FROM `creature_queststarter` WHERE `id` IN (34479, 46908);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(34479, 14170, 46366),
(46908, 27846, 46366);

DELETE FROM `game_event_creature_quest` WHERE `id` IN (34479, 46908);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 144928 AND 144950;
DELETE FROM `creature` WHERE `guid` IN (145029, 145037);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 144928 AND 144950;
DELETE FROM `game_event_creature` WHERE `guid` IN (145029, 145037);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+24;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 1, 1657, 1657, '0', 0, 0, 0, 1, 10047.9189453125, 2119.15625, 1329.7410888671875, 3.176499128341674804, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Darnassus - Difficulty: 0)
(@CGUID+1, 34383, 1, 1657, 1657, '0', 0, 0, 0, 1, 10048.3330078125, 2122.397705078125, 1329.741455078125, 3.141592741012573242, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Darnassus - Difficulty: 0)
(@CGUID+2, 34479, 1, 1657, 1657, '0', 0, 0, 0, 0, 10055.2470703125, 2133.329833984375, 1329.7412109375, 3.159045934677124023, 120, 0, 0, 18771, 2434, 0, 0, 0, 0, 46366), -- Cheerful Night Elf Spirit (Area: Darnassus - Difficulty: 0)
(@CGUID+3, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10060, 2126.340087890625, 1329.743408203125, 3.769911050796508789, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+4, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10055.7001953125, 2118, 1329.743408203125, 0.663225114345550537, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+5, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10043.7001953125, 2113.7099609375, 1329.743408203125, 1.274090290069580078, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+6, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10065.2998046875, 2103.280029296875, 1330.6334228515625, 4.066617012023925781, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+7, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10051.5, 2114.090087890625, 1329.7333984375, 1.29154360294342041, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+8, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10068.2001953125, 2117.389892578125, 1329.743408203125, 1.832595705986022949, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+9, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10067, 2123.39990234375, 1329.743408203125, 2.967059612274169921, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+10, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10045.900390625, 2116.8701171875, 1329.743408203125, 3.909537553787231445, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+11, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10055.5, 2124, 1329.743408203125, 1.274090290069580078, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+12, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10060, 2132.39990234375, 1329.743408203125, 3.839724302291870117, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+13, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10051.7998046875, 2133.110107421875, 1329.743408203125, 3.490658521652221679, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+14, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10067.099609375, 2129, 1329.743408203125, 3.630284786224365234, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+15, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10059.099609375, 2114.840087890625, 1329.743408203125, 0.92502450942993164, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+16, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10052.099609375, 2108.72998046875, 1329.7333984375, 1.378810048103332519, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+17, 35250, 1, 1657, 1657, '0', 0, 0, 0, 0, 10061, 2110.6298828125, 1329.7333984375, 1.29154360294342041, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Night Elf Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+18, 46894, 1, 1657, 1657, '0', 0, 0, 0, 0, 10067.099609375, 2126.0400390625, 1329.743408203125, 2.548180580139160156, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Worgen Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+19, 46894, 1, 1657, 1657, '0', 0, 0, 0, 0, 10061.7001953125, 2118.5400390625, 1329.743408203125, 4.014257431030273437, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Worgen Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+20, 46894, 1, 1657, 1657, '0', 0, 0, 0, 0, 10057.2998046875, 2127.85009765625, 1329.743408203125, 4.398229598999023437, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Worgen Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+21, 46894, 1, 1657, 1657, '0', 0, 0, 0, 0, 10063.900390625, 2133.6298828125, 1329.743408203125, 2.268928050994873046, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Worgen Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+22, 46894, 1, 1657, 1657, '0', 0, 0, 0, 0, 10058.7001953125, 2109.919921875, 1329.7333984375, 3.822271108627319335, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Worgen Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+23, 46894, 1, 1657, 1657, '0', 0, 0, 0, 0, 10055.5, 2107.6201171875, 1329.7333984375, 0.575958669185638427, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Worgen Celebrant (Area: Darnassus - Difficulty: 0)
(@CGUID+24, 46908, 1, 1657, 1657, '0', 0, 0, 0, 0, 10047.400390625, 2111.1201171875, 1329.7333984375, 2.548180580139160156, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Cheerful Worgen Spirit (Area: Darnassus - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78454 AND 78458;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78506 AND 78508;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78533 AND 78537;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78577 AND 78581;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78614 AND 78617;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78652 AND 78654;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78687 AND 78689;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78955 AND 78974;
DELETE FROM `gameobject` WHERE `guid` IN (78415, 78560, 78708, 78733, 78734);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78454 AND 78458;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78506 AND 78508;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78533 AND 78537;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78577 AND 78581;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78614 AND 78617;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78652 AND 78654;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78687 AND 78689;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78955 AND 78974;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (78415, 78560, 78708, 78733, 78734);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+54;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 1, 1657, 1657, '0', 0, 0, 10063.771484375, 2128.635498046875, 1331.26611328125, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+1, 180338, 1, 1657, 1657, '0', 0, 0, 10065.5986328125, 2116.717041015625, 1329.658203125, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+2, 180338, 1, 1657, 1657, '0', 0, 0, 10054.83203125, 2127.24658203125, 1330.3597412109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+3, 180338, 1, 1657, 1657, '0', 0, 0, 10066.9033203125, 2122.2587890625, 1329.6578369140625, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+4, 180338, 1, 1657, 1657, '0', 0, 0, 10053.2685546875, 2105.348876953125, 1330.8856201171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+5, 180338, 1, 1657, 1657, '0', 0, 0, 10065.8408203125, 2118.132080078125, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+6, 180338, 1, 1657, 1657, '0', 0, 0, 10055.1884765625, 2132.31591796875, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+7, 180338, 1, 1657, 1657, '0', 0, 0, 10047.1650390625, 2109.439208984375, 1329.6475830078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+8, 180338, 1, 1657, 1657, '0', 0, 0, 10054.677734375, 2126.60595703125, 1330.202880859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+9, 180338, 1, 1657, 1657, '0', 0, 0, 10047.3310546875, 2107.85595703125, 1331.513427734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+10, 180338, 1, 1657, 1657, '0', 0, 0, 10046.1767578125, 2105.72216796875, 1330.7073974609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+11, 180338, 1, 1657, 1657, '0', 0, 0, 10054.8564453125, 2131.42529296875, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+12, 180338, 1, 1657, 1657, '0', 0, 0, 10049.8095703125, 2111.907958984375, 1330.8720703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+13, 180338, 1, 1657, 1657, '0', 0, 0, 10063.9990234375, 2112.663330078125, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+14, 180338, 1, 1657, 1657, '0', 0, 0, 10050.185546875, 2112.62841796875, 1331.0728759765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+15, 180338, 1, 1657, 1657, '0', 0, 0, 10053.404296875, 2124.880126953125, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+16, 180338, 1, 1657, 1657, '0', 0, 0, 10061.3876953125, 2123.998291015625, 1331.7352294921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+17, 180338, 1, 1657, 1657, '0', 0, 0, 10064.1845703125, 2114.28466796875, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+18, 180338, 1, 1657, 1657, '0', 0, 0, 10060.6005859375, 2122.876708984375, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Darnassus - Difficulty: 0)
(@OGUID+19, 180339, 1, 1657, 1657, '0', 0, 0, 10054.4130859375, 2109.626708984375, 1329.647705078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Darnassus - Difficulty: 0)
(@OGUID+20, 180340, 1, 1657, 1657, '0', 0, 0, 10058.34765625, 2134.9775390625, 1330.780029296875, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 46366), -- Candle 03 (Area: Darnassus - Difficulty: 0)
(@OGUID+21, 180758, 1, 1657, 1657, '0', 0, 0, 10055.2060546875, 2131.84716796875, 1330.3798828125, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, 46366), -- Night Elf Hero Portrait (Area: Darnassus - Difficulty: 0)
(@OGUID+22, 180885, 1, 1657, 1657, '0', 0, 0, 10050.326171875, 2118.060791015625, 1329.6578369140625, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 46366), -- InnTableTiny (Area: Darnassus - Difficulty: 0)
(@OGUID+23, 182807, 1, 1657, 1657, '0', 0, 0, 10062.7314453125, 2129.979248046875, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Darnassus - Difficulty: 0)
(@OGUID+24, 182807, 1, 1657, 1657, '0', 0, 0, 10063.404296875, 2111.8525390625, 1329.65625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Darnassus - Difficulty: 0)
(@OGUID+25, 182807, 1, 1657, 1657, '0', 0, 0, 10054.7939453125, 2132.236083984375, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Darnassus - Difficulty: 0)
(@OGUID+26, 182807, 1, 1657, 1657, '0', 0, 0, 10065.5224609375, 2118.4619140625, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Darnassus - Difficulty: 0)
(@OGUID+27, 182807, 1, 1657, 1657, '0', 0, 0, 10053.69140625, 2125.3056640625, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Darnassus - Difficulty: 0)
(@OGUID+28, 195063, 1, 1657, 1657, '0', 0, 0, 10055.0166015625, 2111.276123046875, 1329.647705078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+29, 195063, 1, 1657, 1657, '0', 0, 0, 10050.3095703125, 2118.569580078125, 1330.7408447265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+30, 195063, 1, 1657, 1657, '0', 0, 0, 10066.3837890625, 2120.482666015625, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+31, 195063, 1, 1657, 1657, '0', 0, 0, 10063.59765625, 2112.157958984375, 1329.65625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+32, 195063, 1, 1657, 1657, '0', 0, 0, 10046.6630859375, 2110.079833984375, 1329.6492919921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+33, 195066, 1, 1657, 1657, '0', 0, 0, 10065.05078125, 2118.71533203125, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Darnassus - Difficulty: 0)
(@OGUID+34, 195066, 1, 1657, 1657, '0', 0, 0, 10053.607421875, 2109.585205078125, 1329.647705078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Darnassus - Difficulty: 0)
(@OGUID+35, 195066, 1, 1657, 1657, '0', 0, 0, 10053.484375, 2128.546875, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Darnassus - Difficulty: 0)
(@OGUID+36, 195067, 1, 1657, 1657, '0', 0, 0, 10059.8408203125, 2122.515625, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Darnassus - Difficulty: 0)
(@OGUID+37, 195067, 1, 1657, 1657, '0', 0, 0, 10047.404296875, 2110.173583984375, 1329.648193359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Darnassus - Difficulty: 0)
(@OGUID+38, 195067, 1, 1657, 1657, '0', 0, 0, 10054.146484375, 2124.819580078125, 1329.65673828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Darnassus - Difficulty: 0)
(@OGUID+39, 195068, 1, 1657, 1657, '0', 0, 0, 10053.5673828125, 2109.588623046875, 1329.647705078125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Darnassus - Difficulty: 0)
(@OGUID+40, 195068, 1, 1657, 1657, '0', 0, 0, 10053.4443359375, 2128.55029296875, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Darnassus - Difficulty: 0)
(@OGUID+41, 195068, 1, 1657, 1657, '0', 0, 0, 10065.0107421875, 2118.71875, 1329.6578369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Darnassus - Difficulty: 0)
(@OGUID+42, 195069, 1, 1657, 1657, '0', 0, 0, 10049.826171875, 2118.114501953125, 1330.7410888671875, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 46366), -- Candy Skulls (Area: Darnassus - Difficulty: 0)
(@OGUID+43, 195069, 1, 1657, 1657, '0', 0, 0, 10050.892578125, 2117.890625, 1330.740234375, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 46366), -- Candy Skulls (Area: Darnassus - Difficulty: 0)
(@OGUID+44, 195069, 1, 1657, 1657, '0', 0, 0, 10050.34765625, 2117.479248046875, 1330.7421875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Candy Skulls (Area: Darnassus - Difficulty: 0)
(@OGUID+45, 195087, 1, 1657, 1657, '0', 0, 0, 10051.26953125, 2122.4306640625, 1329.657958984375, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Darnassus - Difficulty: 0)
(@OGUID+46, 195090, 1, 1657, 1657, '0', 0, 0, 10061, 2124.7744140625, 1329.6578369140625, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Spirit Candle (Area: Darnassus - Difficulty: 0)
(@OGUID+47, 195090, 1, 1657, 1657, '0', 0, 0, 10066.6513671875, 2120.208251953125, 1329.6578369140625, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Spirit Candle (Area: Darnassus - Difficulty: 0)
(@OGUID+48, 195090, 1, 1657, 1657, '0', 0, 0, 10063.31640625, 2129.739501953125, 1329.6578369140625, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Spirit Candle (Area: Darnassus - Difficulty: 0)
(@OGUID+49, 195090, 1, 1657, 1657, '0', 0, 0, 10049.5517578125, 2113.663330078125, 1329.6514892578125, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Spirit Candle (Area: Darnassus - Difficulty: 0)
(@OGUID+50, 195307, 1, 1657, 1657, '0', 0, 0, 10053.81640625, 2127.782958984375, 1329.666259765625, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+51, 195307, 1, 1657, 1657, '0', 0, 0, 10062.8076171875, 2129.416748046875, 1329.6578369140625, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+52, 195307, 1, 1657, 1657, '0', 0, 0, 10054.2431640625, 2129.032958984375, 1329.6583251953125, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+53, 195307, 1, 1657, 1657, '0', 0, 0, 10049.7158203125, 2113.114501953125, 1329.64990234375, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 46366), -- Orange Marigolds (Area: Darnassus - Difficulty: 0)
(@OGUID+54, 195307, 1, 1657, 1657, '0', 0, 0, 10054.6357421875, 2131.958251953125, 1329.6578369140625, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 46366); -- Orange Marigolds (Area: Darnassus - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+24;
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
(51, @CGUID+24);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+54;
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
(51, @OGUID+54);

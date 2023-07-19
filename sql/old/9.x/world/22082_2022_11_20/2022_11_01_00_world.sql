SET @CGUID := 396026;
SET @OGUID := 244120;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=8941, `minlevel`=60, `maxlevel`=60 WHERE `entry`=19173; -- Night Elf Commoner

DELETE FROM `creature_template_addon` WHERE `entry`=19173;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(19173, 0, 0, 0, 257, 0, 0, 0, 0, 0, '33209 33207 33208'); -- 19173 (Night Elf Commoner)

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=190038; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=190038; -- Candy Bucket

-- Quests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=12334;

DELETE FROM `creature_queststarter` WHERE (`id`=19173 AND `quest`=29074);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(19173, 29074, 46366); -- A Season for Celebration offered Night Elf Commoner

DELETE FROM `game_event_creature_quest` WHERE `id`=19173 AND `quest`=29074;

DELETE FROM `gameobject_queststarter` WHERE `id`=190038;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190038, 12334, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=190038 AND `quest`=12334);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190038;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 19173, 1, 1657, 0, '0', 0, 0, 0, 0, 9922.9716796875, 2498.760009765625, 1317.861083984375, 2.443460941314697265, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Night Elf Commoner (Area: 0 - Difficulty: 0)
(@CGUID+1, 19173, 1, 1657, 0, '0', 0, 0, 0, 0, 9921.564453125, 2499.584716796875, 1317.771484375, 5.619960308074951171, 120, 0, 0, 18771, 0, 0, 3, 0, 0, 46366), -- Night Elf Commoner (Area: 0 - Difficulty: 0)
(@CGUID+2, 40435, 1, 1657, 0, '0', 0, 0, 0, 0, 9932.779296875, 2490.90966796875, 1316.70166015625, 1.256637096405029296, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Headless Ghost (Area: 0 - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 1657, 0, '0', 0, 0, 10139.099609375, 2229.2900390625, 1344.300048828125, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+1, 180405, 1, 1657, 0, '0', 0, 0, 10135.5224609375, 2228.1025390625, 1329.60791015625, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+2, 180405, 1, 1657, 0, '0', 0, 0, 9945.0126953125, 2500.426025390625, 1318.03759765625, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+3, 180405, 1, 1657, 0, '0', 0, 0, 9923.931640625, 2512.173095703125, 1318.3348388671875, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0)
(@OGUID+4, 180406, 1, 1657, 0, '0', 0, 0, 10126.6337890625, 2222.048583984375, 1329.6080322265625, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+5, 180406, 1, 1657, 0, '0', 0, 0, 10125.599609375, 2220.140625, 1344.300048828125, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+6, 180406, 1, 1657, 1659, '0', 0, 0, 10152.1396484375, 2238.201416015625, 1344.29541015625, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Craftsmen's Terrace - Difficulty: 0)
(@OGUID+7, 180406, 1, 1657, 1658, '0', 0, 0, 9960.2216796875, 2513.61474609375, 1318.8035888671875, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Cenarion Enclave - Difficulty: 0)
(@OGUID+8, 180406, 1, 1657, 0, '0', 0, 0, 9927.162109375, 2508.964111328125, 1318.3125, 0.226892471313476562, 0, 0, 0.113203048706054687, 0.993571877479553222, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0)
(@OGUID+9, 180407, 1, 1657, 0, '0', 0, 0, 10112.771484375, 2211.4775390625, 1344.29541015625, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+10, 180407, 1, 1657, 1658, '0', 0, 0, 9946.2392578125, 2531.130126953125, 1318.2926025390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Cenarion Enclave - Difficulty: 0)
(@OGUID+11, 180407, 1, 1657, 0, '0', 0, 0, 9950.3955078125, 2499.17333984375, 1317.87939453125, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0)
(@OGUID+12, 180411, 1, 1657, 1658, '0', 0, 0, 9959.142578125, 2515.4853515625, 1349.817626953125, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Cenarion Enclave - Difficulty: 0)
(@OGUID+13, 180411, 1, 1657, 0, '0', 0, 0, 9935.6044921875, 2509.44970703125, 1327.91650390625, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 46366), -- G_Ghost_01 (Area: 0 - Difficulty: 0)
(@OGUID+14, 180411, 1, 1657, 0, '0', 0, 0, 9940.3740234375, 2509.09375, 1327.8707275390625, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 120, 255, 1, 46366), -- G_Ghost_01 (Area: 0 - Difficulty: 0)
(@OGUID+15, 180471, 1, 1657, 1659, '0', 0, 0, 10105.7158203125, 2211.15283203125, 1333.7686767578125, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Craftsmen's Terrace - Difficulty: 0)
(@OGUID+16, 180471, 1, 1657, 1659, '0', 0, 0, 10153.9189453125, 2244.0869140625, 1333.7386474609375, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Craftsmen's Terrace - Difficulty: 0)
(@OGUID+17, 180472, 1, 1657, 0, '0', 0, 0, 10129.4453125, 2226.998291015625, 1334.852294921875, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+18, 180472, 1, 1657, 0, '0', 0, 0, 9937.7626953125, 2510.5546875, 1325.3033447265625, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: 0 - Difficulty: 0)
(@OGUID+19, 180523, 1, 1657, 0, '0', 0, 0, 10139.1826171875, 2223.765625, 1330.244873046875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 46366), -- Apple Bob (Area: 0 - Difficulty: 0)
(@OGUID+20, 190038, 1, 1657, 1659, '0', 0, 0, 10124.0751953125, 2228.78125, 1328.241455078125, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366); -- Candy Bucket (Area: Craftsmen's Terrace - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0),
(12, @CGUID+1),
(12, @CGUID+2);

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

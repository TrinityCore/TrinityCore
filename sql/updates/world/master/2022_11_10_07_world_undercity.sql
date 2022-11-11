SET @CGUID := 396367;
SET @OGUID := 245717;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=10518, `unit_flags`=768 WHERE `entry`=34476; -- Cheerful Forsaken Spirit
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=35244; -- Ghostly Forsaken Celebrant

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35244; -- 35244 (Ghostly Forsaken Celebrant) - Unseen, Shroud of Death
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34476; -- 34476 (Cheerful Forsaken Spirit) - Unseen, Shroud of Death

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (35244,34476));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(35244, 0, 0, 0, 414, 46366),
(34476, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (153285,61905,61829,61366,54244,53591,53517,51384,43359,37574,37543,36226,36224,36213,31146,23103,20725,11048,5821,5754,5728,5726,5707,5706,5705,5704,5703,5702,5701,5674,5669,4603,4580,4577,4571,4570,4076));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=0 AND `CreatureID` IN (5707,3617,5704,4580,54244,4570,53517,36213,5703,4076,5706,20725,34476,51384,11048,23103,61829,5821,43359,4577,35244,5705,5669,4571,5754,153285,37543,61366,5728,5726,5701,36226,4603,5674,36224,53591,37574,31146,5702,61905)) OR (`Idx`=1 AND `CreatureID` IN (54244,43359,35244,37543,61366,53591,37574)) OR (`Idx`=2 AND `CreatureID`=61366);

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (28048, 45952, 2629, 37692, 38376, 1566, 24719, 22769, 30073, 30071, 10699, 29228, 27510, 11466, 4732, 10580, 4381, 4150, 10923, 850, 4064, 4063, 4062, 4061, 4060, 4059, 4058, 3020, 4010, 2643, 2668, 2671, 2640, 2673, 146);
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=46366 WHERE `DisplayID` IN (29699, 29700);

-- Quests
DELETE FROM `creature_queststarter` WHERE `id`=34476;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(34476, 14174, 46366);

DELETE FROM `game_event_creature_quest` WHERE `id`=34476;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 144870 AND 144891;
DELETE FROM `creature` WHERE `guid` IN (145025, 145033);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 144870 AND 144891;
DELETE FROM `game_event_creature` WHERE `guid` IN (145025, 145033);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+21;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 0, 14046, 14046, '0', 0, 0, 0, 1, 1806.5382080078125, 219.423614501953125, 60.46582794189453125, 1.65806281566619873, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+1, 34383, 0, 14046, 14046, '0', 0, 0, 0, 1, 1803.7447509765625, 219.59722900390625, 60.44121551513671875, 1.361356854438781738, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Tirisfal Glades - Difficulty: 0)
(@CGUID+2, 34476, 0, 14046, 14046, '0', 0, 0, 0, 0, 1778.5364990234375, 218.2413177490234375, 59.76784896850585937, 1.082104086875915527, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Cheerful Forsaken Spirit (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+3, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1779.7117919921875, 249.8559112548828125, 59.92548370361328125, 1.378810048103332519, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+4, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1825.2725830078125, 257.40972900390625, 59.95352935791015625, 1.93731546401977539, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+5, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1776.6875, 227.5694427490234375, 59.8570556640625, 0.05235987901687622, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+6, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1781.576416015625, 230.75347900390625, 59.88961410522460937, 5.864306449890136718, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+7, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1825.670166015625, 249.7916717529296875, 60.12625885009765625, 0.48869219422340393, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+8, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1823.607666015625, 218.8819427490234375, 60.47595977783203125, 1.29154360294342041, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+9, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1789.220458984375, 213.685760498046875, 59.9723358154296875, 4.188790321350097656, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+10, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1831.29345703125, 213.154510498046875, 60.45892333984375, 3.647738218307495117, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+11, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1786.8021240234375, 208.7118072509765625, 59.82406997680664062, 1.169370532035827636, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+12, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1808.763916015625, 215.5590362548828125, 65.95556640625, 1.623156189918518066, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+13, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1830.107666015625, 221.470489501953125, 60.79235076904296875, 2.635447263717651367, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+14, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1833.7899169921875, 247.517364501953125, 59.9253387451171875, 2.0245819091796875, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+15, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1802.546875, 215.5625, 65.95556640625, 1.65806281566619873, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+16, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1824.79345703125, 210.56597900390625, 60.20412826538085937, 0.226892799139022827, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+17, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1820.8680419921875, 261.94964599609375, 60.06829833984375, 0.104719758033752441, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+18, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1826.1163330078125, 263.0382080078125, 59.77779006958007812, 3.420845270156860351, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+19, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1835.3680419921875, 257.9600830078125, 59.87485122680664062, 4.049163818359375, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+20, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1781.376708984375, 257.161468505859375, 59.58280181884765625, 4.590215682983398437, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+21, 35244, 0, 14046, 14046, '0', 0, 0, 0, 0, 1780.986083984375, 264.322906494140625, 59.7176513671875, 5.358160972595214843, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Ghostly Forsaken Celebrant (Area: Tirisfal Glades - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78432 AND 78436;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78493 AND 78495;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78801 AND 78864;
DELETE FROM `gameobject` WHERE `guid` IN (78411, 78519, 78520, 78562, 78564, 78604, 78605, 78618, 78642, 78677, 78678, 78723, 78724);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78432 AND 78436;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78493 AND 78495;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78801 AND 78864;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (78411, 78519, 78520, 78562, 78564, 78604, 78605, 78618, 78642, 78677, 78678, 78723, 78724);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+85;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 0, 14046, 14046, '0', 0, 0, 1808.592041015625, 255.6614532470703125, 60.70827102661132812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+1, 180338, 0, 14046, 14046, '0', 0, 0, 1803.3021240234375, 258.369781494140625, 60.86268997192382812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+2, 180338, 0, 14046, 14046, '0', 0, 0, 1812.4322509765625, 240.7135467529296875, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+3, 180338, 0, 14046, 14046, '0', 0, 0, 1810.7379150390625, 249.3802032470703125, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+4, 180338, 0, 14046, 14046, '0', 0, 0, 1801.0885009765625, 244.6041717529296875, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+5, 180338, 0, 14046, 14046, '0', 0, 0, 1809.6910400390625, 244.46875, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+6, 180338, 0, 14046, 14046, '0', 0, 0, 1805.5035400390625, 245.9322967529296875, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+7, 180338, 0, 14046, 14046, '0', 0, 0, 1815.0225830078125, 247.9809112548828125, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+8, 180338, 0, 14046, 14046, '0', 0, 0, 1795.68408203125, 248.31597900390625, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+9, 180338, 0, 14046, 14046, '0', 0, 0, 1794.55908203125, 243.0746612548828125, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+10, 180338, 0, 14046, 14046, '0', 0, 0, 1818.595458984375, 241.8402862548828125, 60.51490020751953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+11, 180338, 0, 14046, 14046, '0', 0, 0, 1809.03125, 251.626739501953125, 60.58866500854492187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+12, 180338, 0, 14046, 14046, '0', 0, 0, 1802.9566650390625, 251.953125, 60.59119415283203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+13, 180338, 0, 14046, 14046, '0', 0, 0, 1808.3072509765625, 258.49652099609375, 60.88347244262695312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+14, 180338, 0, 14046, 14046, '0', 0, 0, 1800.888916015625, 249.3489532470703125, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+15, 180338, 0, 14046, 14046, '0', 0, 0, 1798.232666015625, 240.95660400390625, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+16, 180338, 0, 14046, 14046, '0', 0, 0, 1816.1319580078125, 243.6631927490234375, 60.58345413208007812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+17, 180338, 0, 14046, 14046, '0', 0, 0, 1803.595458984375, 255.8055572509765625, 60.70299530029296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+18, 180338, 0, 14046, 14046, '0', 0, 0, 1790.8663330078125, 241.248260498046875, 60.57669448852539062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+19, 180338, 0, 14046, 14046, '0', 0, 0, 1798.2899169921875, 236.111114501953125, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+20, 180338, 0, 14046, 14046, '0', 0, 0, 1778.5052490234375, 257.79339599609375, 59.5106353759765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+21, 180338, 0, 14046, 14046, '0', 0, 0, 1812.3524169921875, 235.939239501953125, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+22, 180338, 0, 14046, 14046, '0', 0, 0, 1822.6475830078125, 242.013885498046875, 60.74152374267578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+23, 180338, 0, 14046, 14046, '0', 0, 0, 1777.6197509765625, 253.6840362548828125, 59.63698959350585937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+24, 180338, 0, 14046, 14046, '0', 0, 0, 1809.670166015625, 232.265625, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+25, 180338, 0, 14046, 14046, '0', 0, 0, 1778.810791015625, 260.86285400390625, 59.52986526489257812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+26, 180338, 0, 14046, 14046, '0', 0, 0, 1791.1024169921875, 235.263885498046875, 60.57872772216796875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+27, 180338, 0, 14046, 14046, '0', 0, 0, 1819.064208984375, 235.4375, 60.40575408935546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+28, 180338, 0, 14046, 14046, '0', 0, 0, 1800.7708740234375, 232.357635498046875, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+29, 180338, 0, 14046, 14046, '0', 0, 0, 1785.798583984375, 234.814239501953125, 60.4070587158203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+30, 180338, 0, 14046, 14046, '0', 0, 0, 1839.09033203125, 234.689239501953125, 60.58925247192382812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+31, 180338, 0, 14046, 14046, '0', 0, 0, 1780.265625, 242.6875, 60.41016387939453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+32, 180338, 0, 14046, 14046, '0', 0, 0, 1839.0694580078125, 241.923614501953125, 60.5849151611328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+33, 180338, 0, 14046, 14046, '0', 0, 0, 1775.640625, 229.2916717529296875, 60.04336929321289062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+34, 180338, 0, 14046, 14046, '0', 0, 0, 1810.6336669921875, 227.607635498046875, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+35, 180338, 0, 14046, 14046, '0', 0, 0, 1772.9427490234375, 234.9114532470703125, 60.76359176635742187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+36, 180338, 0, 14046, 14046, '0', 0, 0, 1802.8507080078125, 224.4930572509765625, 60.35531234741210937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+37, 180338, 0, 14046, 14046, '0', 0, 0, 1816.1788330078125, 233.5121612548828125, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+38, 180338, 0, 14046, 14046, '0', 0, 0, 1794.3489990234375, 233.2777862548828125, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+39, 180338, 0, 14046, 14046, '0', 0, 0, 1805.2117919921875, 230.9288177490234375, 61.54306411743164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+40, 180338, 0, 14046, 14046, '0', 0, 0, 1828.3541259765625, 235.0364532470703125, 60.73163604736328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+41, 180338, 0, 14046, 14046, '0', 0, 0, 1800.8853759765625, 227.7239532470703125, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+42, 180338, 0, 14046, 14046, '0', 0, 0, 1823.4947509765625, 236.09722900390625, 60.74140167236328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+43, 180338, 0, 14046, 14046, '0', 0, 0, 1803.123291015625, 221.47222900390625, 60.27920913696289062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+44, 180338, 0, 14046, 14046, '0', 0, 0, 1814.470458984375, 228.560760498046875, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+45, 180338, 0, 14046, 14046, '0', 0, 0, 1776.5885009765625, 250.25, 59.94099807739257812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+46, 180338, 0, 14046, 14046, '0', 0, 0, 1808.2274169921875, 220.7395782470703125, 60.25815963745117187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+47, 180338, 0, 14046, 14046, '0', 0, 0, 1834.1649169921875, 235.72222900390625, 60.28042221069335937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+48, 180338, 0, 14046, 14046, '0', 0, 0, 1828.2413330078125, 240.6666717529296875, 60.7401885986328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+49, 180338, 0, 14046, 14046, '0', 0, 0, 1767.43408203125, 242.921875, 60.86443328857421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+50, 180338, 0, 14046, 14046, '0', 0, 0, 1834.045166015625, 240.8645782470703125, 60.27055740356445312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+51, 180338, 0, 14046, 14046, '0', 0, 0, 1795.704833984375, 228.9131927490234375, 60.58672332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+52, 180338, 0, 14046, 14046, '0', 0, 0, 1780.390625, 229.798614501953125, 59.8196563720703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+53, 180338, 0, 14046, 14046, '0', 0, 0, 1779.6475830078125, 236.3506927490234375, 60.41855239868164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+54, 180338, 0, 14046, 14046, '0', 0, 0, 1776.6146240234375, 222.578125, 59.50615310668945312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+55, 180339, 0, 14046, 14046, '0', 0, 0, 1802, 243.1927032470703125, 62.75362014770507812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+56, 180339, 0, 14046, 14046, '0', 0, 0, 1785.0225830078125, 241.592010498046875, 60.40740203857421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+57, 180339, 0, 14046, 14046, '0', 0, 0, 1767.8194580078125, 235.58160400390625, 60.85546112060546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+58, 180339, 0, 14046, 14046, '0', 0, 0, 1772.79345703125, 242.451385498046875, 60.76683807373046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+59, 180339, 0, 14046, 14046, '0', 0, 0, 1808.548583984375, 225.0729217529296875, 60.36491012573242187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+60, 180340, 0, 14046, 14046, '0', 0, 0, 1808.876708984375, 242.9375, 62.75362014770507812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+61, 180340, 0, 14046, 14046, '0', 0, 0, 1799.7447509765625, 236.670135498046875, 62.75362014770507812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+62, 180340, 0, 14046, 14046, '0', 0, 0, 1810.5833740234375, 236.546875, 62.75362014770507812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+63, 180340, 0, 14046, 14046, '0', 0, 0, 1805.38720703125, 232.2725677490234375, 62.67341995239257812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+64, 180760, 0, 14046, 14046, '0', 0, 0, 1777.1180419921875, 219.3489532470703125, 60.5294952392578125, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366), -- Forsaken Hero Portrait (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+65, 180885, 0, 14046, 14046, '0', 0, 0, 1805.888916015625, 217.1336822509765625, 60.60018539428710937, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 46366), -- InnTableTiny (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+66, 182807, 0, 14046, 14046, '0', 0, 0, 1780.1805419921875, 214.78125, 59.85344696044921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+67, 182807, 0, 14046, 14046, '0', 0, 0, 1780.763916015625, 215.611114501953125, 59.79877471923828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+68, 195063, 0, 14046, 14046, '0', 0, 0, 1782.6007080078125, 260.548614501953125, 59.42001724243164062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+69, 195063, 0, 14046, 14046, '0', 0, 0, 1779.51220703125, 268.923614501953125, 59.89298629760742187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+70, 195063, 0, 14046, 14046, '0', 0, 0, 1781.5989990234375, 252.3177032470703125, 59.52621841430664062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+71, 195063, 0, 14046, 14046, '0', 0, 0, 1776.75, 250.7430572509765625, 59.88243484497070312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+72, 195063, 0, 14046, 14046, '0', 0, 0, 1776.3489990234375, 223.173614501953125, 59.50775146484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+73, 195066, 0, 14046, 14046, '0', 0, 0, 1780.1614990234375, 269.7725830078125, 59.87250518798828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+74, 195066, 0, 14046, 14046, '0', 0, 0, 1777.3194580078125, 220.55035400390625, 59.57674789428710937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+75, 195067, 0, 14046, 14046, '0', 0, 0, 1778.8472900390625, 260.072906494140625, 59.49801254272460937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+76, 195068, 0, 14046, 14046, '0', 0, 0, 1780.13720703125, 269.758697509765625, 59.87249755859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+77, 195068, 0, 14046, 14046, '0', 0, 0, 1777.3125, 220.5381927490234375, 59.57676315307617187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+78, 195069, 0, 14046, 14046, '0', 0, 0, 1805.85595703125, 216.814239501953125, 61.588623046875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Candy Skulls (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+79, 195069, 0, 14046, 14046, '0', 0, 0, 1805.326416015625, 217.407989501953125, 61.5327301025390625, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 46366), -- Candy Skulls (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+80, 195069, 0, 14046, 14046, '0', 0, 0, 1806.3541259765625, 217.282989501953125, 61.54374313354492187, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Candy Skulls (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+81, 195087, 0, 14046, 14046, '0', 0, 0, 1803.685791015625, 217.23785400390625, 60.58968734741210937, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+82, 195090, 0, 14046, 14046, '0', 0, 0, 1804.7396240234375, 215.421875, 65.87223052978515625, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 46366), -- Spirit Candle (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+83, 195090, 0, 14046, 14046, '0', 0, 0, 1777.4444580078125, 219.4965362548828125, 59.60799789428710937, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 46366), -- Spirit Candle (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+84, 195307, 0, 14046, 14046, '0', 0, 0, 1792.5086669921875, 241.7743072509765625, 60.58672332763671875, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Tirisfal Glades - Difficulty: 0)
(@OGUID+85, 195307, 0, 14046, 14046, '0', 0, 0, 1780.49658203125, 269.079864501953125, 59.82373046875, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366); -- Orange Marigolds (Area: Tirisfal Glades - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+21;
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
(51, @CGUID+21);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+85;
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
(51, @OGUID+85);

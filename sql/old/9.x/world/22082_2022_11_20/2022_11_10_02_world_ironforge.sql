SET @CGUID := 396288;
SET @OGUID := 245436;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=10518, `unit_flags`=768 WHERE `entry`=34478; -- Cheerful Dwarf Spirit
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35247; -- Ghostly Dwarf Celebrant
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35248; -- Ghostly Gnome Celebrant

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35247; -- 35247 (Ghostly Dwarf Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35248; -- 35248 (Ghostly Gnome Celebrant) - Unseen, Shroud of Death
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34478; -- 34478 (Cheerful Dwarf Spirit)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34481; -- 34481 (Cheerful Gnome Spirit)

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (35248, 35247, 34481, 34478);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(34478, 0, 0, 0, 414, 46366),
(34481, 0, 0, 0, 414, 46366),
(35247, 0, 0, 0, 414, 46366),
(35248, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (122323,53568,52335,48935,6181,5595));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=1 AND `CreatureID` IN (122323,5595,35247,35248,53568)) OR (`Idx`=0 AND `CreatureID` IN (122323,6181,5595,52335,35247,34481,35248,53568,48935,34478)) OR (`Idx`=7 AND `CreatureID`=5595) OR (`Idx`=6 AND `CreatureID`=5595) OR (`Idx`=5 AND `CreatureID`=5595) OR (`Idx`=4 AND `CreatureID`=5595) OR (`Idx`=3 AND `CreatureID`=5595) OR (`Idx`=2 AND `CreatureID` IN (5595,53568));

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (304, 37844, 36342, 29706, 29705, 29703, 29233, 29230, 4893, 3524, 3526, 99837);

-- Quests
DELETE FROM `creature_queststarter` WHERE `id` IN (34478, 34481);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(34478, 14167, 46366),
(34481, 14168, 46366);

DELETE FROM `game_event_creature_quest` WHERE `id` IN (34478, 34481);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 145001 AND 145012;
DELETE FROM `creature` WHERE `guid` IN (145030, 145039);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 145001 AND 145012;
DELETE FROM `game_event_creature` WHERE `guid` IN (145030, 145039);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 0, 1, 809, '0', 0, 0, 0, 1, -5147.53466796875, -853.826416015625, 508.66314697265625, 0.698131680488586425, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+1, 34383, 0, 1, 809, '0', 0, 0, 0, 1, -5145.17041015625, -856.00177001953125, 508.79412841796875, 0.907571196556091308, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+2, 34478, 0, 1, 809, '0', 0, 0, 0, 1, -5160.71533203125, -882.70489501953125, 507.3590087890625, 1.780235767364501953, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Cheerful Dwarf Spirit (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+3, 34481, 0, 1, 809, '0', 0, 0, 0, 0, -5166.08154296875, -881.12677001953125, 507.390594482421875, 1.082104086875915527, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Cheerful Gnome Spirit (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+4, 35247, 0, 1, 809, '0', 0, 0, 0, 0, -5157.13720703125, -875.779541015625, 507.76727294921875, 2.076941728591918945, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Dwarf Celebrant (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+5, 35247, 0, 1, 809, '0', 0, 0, 0, 0, -5162.43603515625, -877.17706298828125, 507.35357666015625, 1.431169986724853515, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Dwarf Celebrant (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+6, 35247, 0, 1, 809, '0', 0, 0, 0, 0, -5167.7275390625, -870.47918701171875, 506.750396728515625, 0.279252678155899047, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Dwarf Celebrant (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+7, 35247, 0, 1, 809, '0', 0, 0, 0, 0, -5165.798828125, -866.6875, 506.89959716796875, 5.829399585723876953, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Dwarf Celebrant (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+8, 35248, 0, 1, 809, '0', 0, 0, 0, 0, -5161.99658203125, -863.6632080078125, 507.281585693359375, 4.834561824798583984, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Gnome Celebrant (Area: Gates of Ironforge - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+9, 35248, 0, 1, 809, '0', 0, 0, 0, 0, -5157.59033203125, -864.23089599609375, 507.502685546875, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Gnome Celebrant (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+10, 35248, 0, 1, 809, '0', 0, 0, 0, 0, -5154.46875, -866.9305419921875, 507.900146484375, 3.420845270156860351, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Gnome Celebrant (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+11, 35248, 0, 1, 809, '0', 0, 0, 0, 0, -5166.62841796875, -874.4444580078125, 507.21295166015625, 0.837758064270019531, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Gnome Celebrant (Area: Gates of Ironforge - Difficulty: 0)
(@CGUID+12, 35248, 0, 1, 809, '0', 0, 0, 0, 0, -5153.845703125, -872.18927001953125, 508.302032470703125, 2.775073528289794921, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Ghostly Gnome Celebrant (Area: Gates of Ironforge - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78481 AND 78486;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78512 AND 78514;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78619 AND 78634;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78705 AND 78707;
DELETE FROM `gameobject` WHERE `guid` IN (78419, 78558, 78559, 78586, 78587, 78598, 78599, 78636, 78637, 78671, 78716, 78717, 78758, 78759);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78481 AND 78486;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78512 AND 78514;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78619 AND 78634;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78705 AND 78707;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (78419, 78558, 78559, 78586, 78587, 78598, 78599, 78636, 78637, 78671, 78716, 78717, 78758, 78759);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+41;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 0, 1, 809, '0', 0, 0, -5170.33837890625, -880.16143798828125, 508.656890869140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+1, 180338, 0, 1, 809, '0', 0, 0, -5156.06787109375, -865.3836669921875, 507.626861572265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+2, 180338, 0, 1, 809, '0', 0, 0, -5167.39404296875, -872.68402099609375, 506.958984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+3, 180338, 0, 1, 809, '0', 0, 0, -5153.62841796875, -869.43927001953125, 508.005706787109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+4, 180338, 0, 1, 809, '0', 0, 0, -5172.0244140625, -874.8038330078125, 508.3946533203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+5, 180338, 0, 1, 809, '0', 0, 0, -5149.16162109375, -854.56427001953125, 509.253265380859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+6, 180338, 0, 1, 809, '0', 0, 0, -5167.5224609375, -868.36285400390625, 506.597869873046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+7, 180338, 0, 1, 809, '0', 0, 0, -5165.08154296875, -876.1961669921875, 507.227874755859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+8, 180338, 0, 1, 809, '0', 0, 0, -5164.0537109375, -865.0399169921875, 507.102447509765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+9, 180338, 0, 1, 809, '0', 0, 0, -5155.45849609375, -873.76910400390625, 507.888824462890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+10, 180338, 0, 1, 809, '0', 0, 0, -5160.16845703125, -876.76043701171875, 507.32470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+11, 180338, 0, 1, 809, '0', 0, 0, -5159.7412109375, -863.796875, 507.2403564453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+12, 180339, 0, 1, 809, '0', 0, 0, -5148.74853515625, -848.9774169921875, 510.060272216796875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+13, 180339, 0, 1, 809, '0', 0, 0, -5166.296875, -884.38018798828125, 508.29791259765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+14, 180340, 0, 1, 809, '0', 0, 0, -5154.09228515625, -851.6649169921875, 509.511627197265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+15, 180340, 0, 1, 809, '0', 0, 0, -5160.5380859375, -885.44793701171875, 508.262542724609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+16, 180340, 0, 1, 809, '0', 0, 0, -5146.814453125, -846.8055419921875, 509.675994873046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+17, 180340, 0, 1, 809, '0', 0, 0, -5151.32666015625, -850.94964599609375, 510.082427978515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+18, 180755, 0, 1, 809, '0', 0, 0, -5162.0400390625, -884.55035400390625, 507.917205810546875, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 120, 255, 1, 46366), -- Dwarf Hero (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+19, 180756, 0, 1, 809, '0', 0, 0, -5166.14599609375, -883.52081298828125, 508.024810791015625, 1.256635904312133789, 0, 0, 0.587784767150878906, 0.809017360210418701, 120, 255, 1, 46366), -- Gnome Hero (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+20, 180885, 0, 1, 809, '0', 0, 0, -5149.5244140625, -854.9305419921875, 508.43206787109375, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 46366), -- InnTableTiny (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+21, 182807, 0, 1, 809, '0', 0, 0, -5161.265625, -870.734375, 507.233123779296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+22, 182807, 0, 1, 809, '0', 0, 0, -5160.73291015625, -871.28302001953125, 507.27001953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+23, 195063, 0, 1, 809, '0', 0, 0, -5162.09912109375, -870.6007080078125, 507.185394287109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+24, 195063, 0, 1, 809, '0', 0, 0, -5158.9443359375, -869.95489501953125, 507.357269287109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+25, 195063, 0, 1, 809, '0', 0, 0, -5160.0537109375, -871.75347900390625, 507.314666748046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+26, 195063, 0, 1, 809, '0', 0, 0, -5149.85791015625, -882.234375, 508.225311279296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+27, 195063, 0, 1, 809, '0', 0, 0, -5161.0400390625, -868.96875, 507.233306884765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+28, 195063, 0, 1, 809, '0', 0, 0, -5149.59033203125, -854.4288330078125, 509.498870849609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+29, 195066, 0, 1, 809, '0', 0, 0, -5159.9931640625, -869.015625, 507.290924072265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+30, 195066, 0, 1, 809, '0', 0, 0, -5159.9130859375, -870.5538330078125, 507.307281494140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+31, 195067, 0, 1, 809, '0', 0, 0, -5161.68603515625, -869.670166015625, 507.202484130859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+32, 195068, 0, 1, 809, '0', 0, 0, -5160.017578125, -869.029541015625, 507.289947509765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+33, 195068, 0, 1, 809, '0', 0, 0, -5159.92041015625, -870.56597900390625, 507.307281494140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+34, 195069, 0, 1, 809, '0', 0, 0, -5150.07470703125, -854.87847900390625, 509.49609375, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 46366), -- Candy Skulls (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+35, 195069, 0, 1, 809, '0', 0, 0, -5149.046875, -855.00347900390625, 509.504302978515625, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Candy Skulls (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+36, 195069, 0, 1, 809, '0', 0, 0, -5149.54541015625, -855.47222900390625, 509.469451904296875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Candy Skulls (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+37, 195087, 0, 1, 809, '0', 0, 0, -5147.767578125, -856.9913330078125, 508.491546630859375, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+38, 195090, 0, 1, 809, '0', 0, 0, -5163.095703125, -880.0538330078125, 507.278106689453125, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 120, 255, 1, 46366), -- Spirit Candle (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+39, 195090, 0, 1, 809, '0', 0, 0, -5160.6162109375, -870.092041015625, 507.264434814453125, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 46366), -- Spirit Candle (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+40, 195307, 0, 1, 809, '0', 0, 0, -5160.8037109375, -869.68402099609375, 507.250640869140625, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)
(@OGUID+41, 195307, 0, 1, 809, '0', 0, 0, -5159.658203125, -869.70831298828125, 507.315155029296875, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366); -- Orange Marigolds (Area: Gates of Ironforge - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+12;
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
(51, @CGUID+12);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+41;
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
(51, @OGUID+41);

SET @CGUID := 396389;
SET @OGUID := 245803;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=34483; -- Cheerful Blood Elf Spirit
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35243; -- Ghostly Blood Elf Celebrant

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35243; -- 35243 (Ghostly Blood Elf Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34483; -- 34483 (Cheerful Blood Elf Spirit)

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (35243,34483));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(35243, 0, 0, 0, 414, 46366),
(34483, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (63080,51796,18926,16924,16277,16276,16272,16269,16267,16266,16262,16259,16221,16186,16185,15649,15501,15433));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=0 AND `CreatureID` IN (16259,16221,16269,16185,16276,16267,16272,18926,16262,35243,15649,16924,63080,16186,51796,15501,34483,63079,15433,16266,16277,416)) OR (`Idx`=7 AND `CreatureID` IN (16221,51796)) OR (`Idx`=6 AND `CreatureID` IN (16221,51796)) OR (`Idx`=5 AND `CreatureID` IN (16221,51796)) OR (`Idx`=4 AND `CreatureID` IN (16221,51796)) OR (`Idx`=3 AND `CreatureID` IN (16221,51796)) OR (`Idx`=2 AND `CreatureID` IN (16221,51796)) OR (`Idx`=1 AND `CreatureID` IN (16221,35243,51796));

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (16918, 20027, 29235, 18334, 16626, 16686, 16707, 16683, 16680, 16677, 16700, 16705, 16687, 89802, 89801, 16690, 16675, 17547, 15531, 15530);
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=46366 WHERE `DisplayID` IN (29698, 29697);

-- Quests
DELETE FROM `creature_queststarter` WHERE `id`=34483;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(34483, 14171, 46366);

DELETE FROM `game_event_creature_quest` WHERE `id`=34483;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 144892 AND 144902;
DELETE FROM `creature` WHERE `guid` IN (144844, 145026, 145034);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 144892 AND 144902;
DELETE FROM `game_event_creature` WHERE `guid` IN (144844, 145026, 145034);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 530, 3430, 3430, '0', 0, 0, 0, 1, 9409.1982421875, -6837.9130859375, 16.3055572509765625, 3.630284786224365234, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Eversong Woods - Difficulty: 0)
(@CGUID+1, 34383, 530, 3430, 3430, '0', 0, 0, 0, 1, 9409.2080078125, -6841.0087890625, 16.17881965637207031, 2.513274192810058593, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Eversong Woods - Difficulty: 0)
(@CGUID+2, 34483, 530, 3430, 3430, '0', 0, 0, 0, 0, 9417.505859375, -6851.2099609375, 15.09478092193603515, 3.420845270156860351, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Cheerful Blood Elf Spirit (Area: Eversong Woods - Difficulty: 0)
(@CGUID+3, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9406.4033203125, -6845.60791015625, 16.06168174743652343, 3.996803998947143554, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+4, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9409.37109375, -6860.70654296875, 14.8249359130859375, 1.640609502792358398, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+5, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9410.404296875, -6856.34033203125, 14.88649463653564453, 4.049163818359375, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+6, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9403.03515625, -6833.92529296875, 16.70704078674316406, 0.541052043437957763, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+7, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9421.55859375, -6836.08349609375, 15.54009628295898437, 3.246312379837036132, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+8, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9411.26953125, -6832.328125, 16.75127601623535156, 3.228859186172485351, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+9, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9417.37890625, -6840.1875, 15.81598854064941406, 2.129301786422729492, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+10, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9417.46875, -6832.5693359375, 16.11979293823242187, 4.084070205688476562, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+11, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9406.1298828125, -6857.921875, 15.11687183380126953, 0.226892799139022827, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+12, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9407.63671875, -6826.66650390625, 17.45138931274414062, 4.450589656829833984, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)
(@CGUID+13, 35243, 530, 3430, 3430, '0', 0, 0, 0, 0, 9403.6708984375, -6849.658203125, 15.91330623626708984, 1.169370532035827636, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366); -- Ghostly Blood Elf Celebrant (Area: Eversong Woods - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 76273 AND 76275;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 76353 AND 76360;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78437 AND 78441;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78496 AND 78498;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78865 AND 78881;
DELETE FROM `gameobject` WHERE `guid` IN (76239, 76253, 76498, 78412, 78521, 78522, 78565, 78566, 78567, 78606, 78607, 78643, 78679, 78680, 78725, 78726);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 76273 AND 76275;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 76353 AND 76360;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78437 AND 78441;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78496 AND 78498;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78865 AND 78881;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (76239, 76253, 76498, 78412, 78521, 78522, 78565, 78566, 78567, 78606, 78607, 78643, 78679, 78680, 78725, 78726);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+37;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 530, 3430, 3430, '0', 0, 0, 9410.9443359375, -6842.8525390625, 15.94073867797851562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+1, 180338, 530, 3430, 3430, '0', 0, 0, 9418.8251953125, -6850.21875, 15.0411376953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+2, 180338, 530, 3430, 3430, '0', 0, 0, 9406.052734375, -6854.35400390625, 15.27330398559570312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+3, 180338, 530, 3430, 3430, '0', 0, 0, 9409.4072265625, -6847.15966796875, 15.59512710571289062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+4, 180338, 530, 3430, 3430, '0', 0, 0, 9411.2158203125, -6835.88525390625, 16.40972328186035156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+5, 180338, 530, 3430, 3430, '0', 0, 0, 9419.4345703125, -6853.58154296875, 14.9740142822265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+6, 180338, 530, 3430, 3430, '0', 0, 0, 9413.1103515625, -6858.1494140625, 14.6807861328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+7, 180338, 530, 3430, 3430, '0', 0, 0, 9407.9482421875, -6858.4306640625, 14.81899833679199218, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+8, 180338, 530, 3430, 3430, '0', 0, 0, 9416.8076171875, -6857.1337890625, 14.83239269256591796, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+9, 180338, 530, 3430, 3430, '0', 0, 0, 9421.068359375, -6849.2568359375, 18.02616310119628906, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+10, 180338, 530, 3430, 3430, '0', 0, 0, 9416.09765625, -6859.70166015625, 17.72371101379394531, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+11, 180338, 530, 3430, 3430, '0', 0, 0, 9421.595703125, -6855.611328125, 20.6723175048828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+12, 180339, 530, 3430, 3430, '0', 0, 0, 9415.57421875, -6844.39404296875, 15.60329914093017578, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+13, 180339, 530, 3430, 3430, '0', 0, 0, 9410.923828125, -6860.234375, 14.66373252868652343, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+14, 180340, 530, 3430, 3430, '0', 0, 0, 9417.8525390625, -6844.64404296875, 15.44192695617675781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+15, 180340, 530, 3430, 3430, '0', 0, 0, 9406.974609375, -6850.43212890625, 15.49679374694824218, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+16, 180340, 530, 3430, 3430, '0', 0, 0, 9412.681640625, -6845.23095703125, 15.64251708984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Eversong Woods - Difficulty: 0)
(@OGUID+17, 180885, 530, 3430, 3430, '0', 0, 0, 9411.2724609375, -6838.46533203125, 16.24826431274414062, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 120, 255, 1, 46366), -- InnTableTiny (Area: Eversong Woods - Difficulty: 0)
(@OGUID+18, 182807, 530, 3430, 3430, '0', 0, 0, 9417.6826171875, -6856.62841796875, 14.8602142333984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Eversong Woods - Difficulty: 0)
(@OGUID+19, 182807, 530, 3430, 3430, '0', 0, 0, 9418.265625, -6855.798828125, 14.89146232604980468, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Eversong Woods - Difficulty: 0)
(@OGUID+20, 195063, 530, 3430, 3430, '0', 0, 0, 9418.0244140625, -6846.97216796875, 15.29443645477294921, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Eversong Woods - Difficulty: 0)
(@OGUID+21, 195063, 530, 3430, 3430, '0', 0, 0, 9416.951171875, -6845.9287109375, 15.41892528533935546, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Eversong Woods - Difficulty: 0)
(@OGUID+22, 195063, 530, 3430, 3430, '0', 0, 0, 9415.4892578125, -6857.064453125, 14.79820919036865234, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Eversong Woods - Difficulty: 0)
(@OGUID+23, 195063, 530, 3430, 3430, '0', 0, 0, 9419.1689453125, -6852.986328125, 14.97407245635986328, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Eversong Woods - Difficulty: 0)
(@OGUID+24, 195063, 530, 3430, 3430, '0', 0, 0, 9414.4443359375, -6857.546875, 14.74676513671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Eversong Woods - Difficulty: 0)
(@OGUID+25, 195066, 530, 3430, 3430, '0', 0, 0, 9418.6708984375, -6849.43603515625, 15.08937931060791015, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Eversong Woods - Difficulty: 0)
(@OGUID+26, 195066, 530, 3430, 3430, '0', 0, 0, 9418.8916015625, -6854.56591796875, 14.94360065460205078, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Eversong Woods - Difficulty: 0)
(@OGUID+27, 195067, 530, 3430, 3430, '0', 0, 0, 9419.5224609375, -6850.59716796875, 15.02394580841064453, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Eversong Woods - Difficulty: 0)
(@OGUID+28, 195068, 530, 3430, 3430, '0', 0, 0, 9418.6474609375, -6849.44970703125, 15.08854198455810546, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Eversong Woods - Difficulty: 0)
(@OGUID+29, 195068, 530, 3430, 3430, '0', 0, 0, 9418.884765625, -6854.578125, 14.94306755065917968, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Eversong Woods - Difficulty: 0)
(@OGUID+30, 195069, 530, 3430, 3430, '0', 0, 0, 9411.83203125, -6838.30908203125, 17.33341217041015625, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Candy Skulls (Area: Eversong Woods - Difficulty: 0)
(@OGUID+31, 195069, 530, 3430, 3430, '0', 0, 0, 9410.8037109375, -6838.18408203125, 17.31257820129394531, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 46366), -- Candy Skulls (Area: Eversong Woods - Difficulty: 0)
(@OGUID+32, 195069, 530, 3430, 3430, '0', 0, 0, 9411.3330078125, -6838.77783203125, 17.290008544921875, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Candy Skulls (Area: Eversong Woods - Difficulty: 0)
(@OGUID+33, 195087, 530, 3430, 3430, '0', 0, 0, 9410.9521484375, -6840.46728515625, 16.09267234802246093, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Eversong Woods - Difficulty: 0)
(@OGUID+34, 195090, 530, 3430, 3430, '0', 0, 0, 9406.931640625, -6839.236328125, 16.12152862548828125, 1.500982880592346191, 0, 0, 0.681998252868652343, 0.731353819370269775, 120, 255, 1, 46366), -- Spirit Candle (Area: Eversong Woods - Difficulty: 0)
(@OGUID+35, 195090, 530, 3430, 3430, '0', 0, 0, 9419.6396484375, -6851.48974609375, 14.99889087677001953, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Spirit Candle (Area: Eversong Woods - Difficulty: 0)
(@OGUID+36, 195307, 530, 3430, 3430, '0', 0, 0, 9416.861328125, -6847.47900390625, 15.28504467010498046, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Eversong Woods - Difficulty: 0)
(@OGUID+37, 195307, 530, 3430, 3430, '0', 0, 0, 9418.82421875, -6851.0537109375, 15.01081657409667968, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366); -- Orange Marigolds (Area: Eversong Woods - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+13;
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
(51, @CGUID+13);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+37;
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
(51, @OGUID+37);

SET @CGUID := 1051413;
SET @OGUID := 600234;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+28;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 454.729156494140625, -2102.0869140625, 130.526397705078125, 3.068993806838989257, 7200, 0, 0, 217, 0, 0, 0, 0, 0, 45114), -- Ogre Brute (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 153581, 2175, 10424, 10530, '0', 0, 0, 0, 1, 509.7882080078125, -1965.4879150390625, 144.52081298828125, 1.031827330589294433, 7200, 0, 0, 279, 0, 0, 0, 0, 0, 45114), -- Grunk (Area: -Unknown- - Difficulty: 0) (Auras: 246849 - -Unknown-)
(@CGUID+2, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 467.7725830078125, -2003.888916015625, 143.8871002197265625, 1.62632906436920166, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 481.30902099609375, -1975.1649169921875, 143.1035308837890625, 4.41829681396484375, 7200, 0, 0, 217, 0, 0, 0, 0, 0, 45114), -- Ogre Brute (Area: -Unknown- - Difficulty: 0)
(@CGUID+4, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 526.701416015625, -2001.1024169921875, 142.98779296875, 0.027794346213340759, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 431.08160400390625, -2025.2257080078125, 132.452880859375, 3.692021131515502929, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0) (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+6, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 498.973968505859375, -2046.9288330078125, 144.2474365234375, 0.442503392696380615, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 457.604156494140625, -2044.4461669921875, 143.176605224609375, 0.766060471534729003, 7200, 10, 0, 217, 0, 1, 0, 0, 0, 45114), -- Ogre Brute (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+8, 153238, 2175, 10424, 10530, '0', 0, 0, 0, 0, 543.55206298828125, -2003.375, 142.649017333984375, 0.492633670568466186, 7200, 0, 0, 50, 0, 0, 0, 0, 0, 45114), -- Tamed Boar (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 533.013916015625, -2079.671875, 158.34222412109375, 5.339074611663818359, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 153238, 2175, 10424, 10530, '0', 0, 0, 0, 0, 542.66668701171875, -1997.77783203125, 142.4593658447265625, 5.80480813980102539, 7200, 0, 0, 50, 0, 0, 0, 0, 0, 45114), -- Tamed Boar (Area: -Unknown- - Difficulty: 0)
(@CGUID+11, 153238, 2175, 10424, 10530, '0', 0, 0, 0, 0, 540.1107177734375, -2001.9852294921875, 142.73614501953125, 5.420380115509033203, 7200, 4, 0, 50, 0, 1, 0, 0, 0, 45114), -- Tamed Boar (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 474.05035400390625, -1932.060791015625, 155.3624725341796875, 5.49060821533203125, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0) (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+13, 153238, 2175, 10424, 10530, '0', 0, 0, 0, 0, 539.99957275390625, -1994.472412109375, 142.8594970703125, 2.248490333557128906, 7200, 4, 0, 50, 0, 1, 0, 0, 0, 45114), -- Tamed Boar (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 479.986114501953125, -2113.833251953125, 132.5481414794921875, 4.657485008239746093, 7200, 0, 0, 217, 0, 0, 0, 0, 0, 45114), -- Ogre Brute (Area: -Unknown- - Difficulty: 0) (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+15, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 578.02777099609375, -1979.513916015625, 171.6934051513671875, 1.193202733993530273, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 578.06768798828125, -2046.3541259765625, 159.592681884765625, 5.034889698028564453, 7200, 0, 0, 217, 0, 0, 0, 0, 0, 45114), -- Ogre Brute (Area: -Unknown- - Difficulty: 0) (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+17, 153582, 2175, 10424, 10530, '0', 0, 0, 0, 1, 591.78302001953125, -2010.626708984375, 175.675933837890625, 0.113099128007888793, 7200, 0, 0, 248, 382, 0, 0, 0, 0, 45114), -- Wug (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 582.30206298828125, -1974.63720703125, 170.8436126708984375, 5.720551013946533203, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0) (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+19, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 559.86456298828125, -2101.833251953125, 161.2359619140625, 1.117576360702514648, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 153238, 2175, 10424, 10530, '0', 0, 0, 0, 0, 595.2257080078125, -2064.536376953125, 161.243377685546875, 0.601261317729949951, 7200, 0, 0, 50, 0, 0, 0, 0, 0, 45114), -- Tamed Boar (Area: -Unknown- - Difficulty: 0) (Auras: 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+21, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 592.87152099609375, -2062.473876953125, 160.633148193359375, 5.45097970962524414, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+22, 154103, 2175, 10424, 10530, '0', 0, 0, 0, 0, 602.060302734375, -2062.95703125, 159.5788421630859375, 2.146738052368164062, 7200, 0, 0, 205, 0, 0, 0, 0, 0, 45114), -- Ogre Chef (Area: -Unknown- - Difficulty: 0) (Auras: 299441 - -Unknown-)
(@CGUID+23, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 571.03643798828125, -2105.01220703125, 160.8884735107421875, 4.798206806182861328, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+24, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 603.23089599609375, -2121.41845703125, 158.9243316650390625, 3.034203290939331054, 7200, 0, 0, 217, 0, 0, 0, 0, 0, 45114), -- Ogre Brute (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 153242, 2175, 10424, 10530, '0', 0, 0, 0, 0, 649.20660400390625, -2064.651123046875, 159.3798828125, 2.090809583663940429, 7200, 0, 0, 149, 382, 0, 0, 0, 0, 45114), -- Ogre Shadowcaster (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 675.47222900390625, -2036.986083984375, 171.5338134765625, 4.335721492767333984, 7200, 0, 0, 217, 0, 0, 0, 0, 0, 45114), -- Ogre Brute (Area: -Unknown- - Difficulty: 0)
(@CGUID+27, 153583, 2175, 10424, 10530, '0', 0, 0, 0, 1, 663.19268798828125, -2127.892333984375, 161.383514404296875, 5.686066150665283203, 7200, 0, 0, 310, 0, 0, 0, 0, 0, 45114), -- Jugnug (Area: -Unknown- - Difficulty: 0) (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+28, 153239, 2175, 10424, 10530, '0', 0, 0, 0, 1, 732.875, -2071.0869140625, 120.14874267578125, 5.224806785583496093, 7200, 0, 0, 217, 0, 0, 0, 0, 0, 45114); -- Ogre Brute (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+28;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, 0, '145953'), -- Ogre Brute - 145953 - Cosmetic - Sleep Zzz
(@CGUID+0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ogre Brute
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '145953'), -- Ogre Shadowcaster - 145953 - Cosmetic - Sleep Zzz
(@CGUID+6, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ogre Brute
(@CGUID+3, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ogre Brute
(@CGUID+2, 0, 0, 0, 0, 28, 0, 0, 0, 0, ''), -- Ogre Shadowcaster
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, 0, '145953'), -- Ogre Shadowcaster - 145953 - Cosmetic - Sleep Zzz
(@CGUID+9, 0, 0, 0, 0, 28, 0, 0, 0, 0, ''), -- Ogre Shadowcaster
(@CGUID+23, 0, 0, 8, 0, 0, 0, 0, 0, 0, ''), -- Ogre Shadowcaster
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, 0, '145953'), -- Ogre Brute - 145953 - Cosmetic - Sleep Zzz
(@CGUID+21, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ogre Brute
(@CGUID+20, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '145363'), -- Tamed Boar - 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+24, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Ogre Brute
(@CGUID+25, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- Ogre Shadowcaster
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, 0, '145953'), -- Ogre Shadowcaster - 145953 - Cosmetic - Sleep Zzz
(@CGUID+15, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- Ogre Shadowcaster
(@CGUID+19, 0, 0, 0, 1, 378, 0, 0, 0, 0, ''), -- Ogre Shadowcaster
(@CGUID+26, 0, 0, 0, 1, 378, 0, 0, 0, 0, ''); -- Ogre Brute

-- Creature Addon Template
DELETE FROM `creature_template_addon` WHERE `entry` IN (153583 /*153583 (Jugnug) - Cosmetic - Sleep Zzz*/, 153582 /*153582 (Wug)*/, 153242 /*153242 (Ogre Shadowcaster)*/, 154103 /*154103 (Ogre Chef) - -Unknown-*/, 153581 /*153581 (Grunk) - -Unknown-*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(153583, 0, 0, 0, 1, 0, 0, 0, 0, 0, '145953'), -- 153583 (Jugnug) - Cosmetic - Sleep Zzz
(153582, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 153582 (Wug)
(153242, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 153242 (Ogre Shadowcaster)
(154103, 0, 0, 0, 1, 0, 0, 0, 0, 0, '299441'), -- 154103 (Ogre Chef) - -Unknown-
(153581, 0, 0, 0, 1, 0, 0, 0, 0, 0, '246849'); -- 153581 (Grunk) - -Unknown-

-- Creature Template
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2057, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153583; -- Jugnug
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2057, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154103; -- Ogre Chef
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2057, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153582; -- Wug
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2057, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153238; -- Tamed Boar
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2057, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153242; -- Ogre Shadowcaster
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2057, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153581; -- Grunk
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2057, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153239; -- Ogre Brute

-- GameObject Template
DELETE FROM `gameobject_template` WHERE `entry`=351477;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(351477, 10, 14627, 'Catapult', 'questinteract', 'Placing', '', 1, 2173, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 35196, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 956, 45114); -- Catapult

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 351477, 2175, 10424, 10530, '0', 0, 0, 463.779510498046875, -1997.0816650390625, 143.712860107421875, 2.96053171157836914, 0, 0, 0.995904922485351562, 0.09040689468383789, 7200, 255, 1, 45114), -- Catapult (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 351477, 2175, 10424, 10530, '0', 0, 0, 489.869781494140625, -2051.572998046875, 143.9427032470703125, 3.69792795181274414, 0, 0, -0.96156024932861328, 0.274594068527221679, 7200, 255, 1, 45114), -- Catapult (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 351477, 2175, 10424, 10530, '0', 0, 0, 610.732666015625, -2118.416748046875, 158.92596435546875, 4.408715248107910156, 0, 0, -0.8059244155883789, 0.592018485069274902, 7200, 255, 1, 45114), -- Catapult (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 351477, 2175, 10424, 10530, '0', 0, 0, 535.9757080078125, -2085.546875, 158.3209686279296875, 4.0296630859375, 0, 0, -0.90302562713623046, 0.429586708545684814, 7200, 255, 1, 45114); -- Catapult (Area: -Unknown- - Difficulty: 0)

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID`= 154103;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(154103, 0, 0, 'This gonna be off hook!', 12, 0, 100, 0, 0, 0, 0, 0, 'Ogre Chef'),
(154103, 1, 0, 'Me gonna take everyone on ride to flavor... flavor... uh. Flavor place!', 12, 0, 100, 0, 0, 0, 0, 0, 'Ogre Chef');

-- Waypoints for CGUID+7
SET @PATH := @CGUID+7 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 433.2153, -2065.714, 131.6825, NULL, 0),
(@PATH, 1, 421.6146, -2073.545, 127.4143, NULL, 4047),
(@PATH, 2, 433.2153, -2065.714, 131.6825, NULL, 0),
(@PATH, 3, 449.408, -2052.332, 140.1065, NULL, 0),
(@PATH, 4, 457.6042, -2044.446, 143.1766, NULL, 3797),
(@PATH, 5, 449.408, -2052.332, 140.1065, NULL, 0);

UPDATE `creature` SET `position_x`= 433.2153, `position_y`= -2065.714, `position_z`= 131.6825, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+7;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+7, @PATH, 1);

-- Waypoints for CGUID+22
SET @PATH := @CGUID+22 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 599.7882, -2059.458, 159.6127, NULL, 0),
(@PATH, 1, 601.1042, -2056.816, 159.5922, NULL, 8568),
(@PATH, 2, 592.4792, -2051.382, 159.6127, NULL, 4460),
(@PATH, 3, 604.8143, -2067.198, 159.5378, NULL, 6575);

UPDATE `creature` SET `position_x`= 599.7882, `position_y`= -2059.458, `position_z`= 159.6127, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+22;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+22, @PATH, 1, '299441');

 -- Ogre Chef smart ai
SET @ENTRY := 154103;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 15410300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #15410300 (update out of combat)'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 15410301, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #15410301 (update out of combat)'),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 15410302, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #15410302 (update out of combat)');

 -- Timed list 15410300 smart ai
SET @ENTRY := 15410300;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 90, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Set stand state to STAND'),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 1 to Self');

 -- Timed list 15410301 smart ai
SET @ENTRY := 15410301;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 0');

 -- Timed list 15410302 smart ai
SET @ENTRY := 15410302;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 69'),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Set emote state to 0'),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 0 to Self');

 -- Ogre Shadowcaster smart ai
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+4);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 153242;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+4), 0, 0, 0, 1, 0, 100, 0, 0, 0, 7000, 7000, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 7 seconds (0s initially) (OOC) - Self: Play emote 11'),
(-(@CGUID+4), 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 7000, 7000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 7 seconds (3s initially) (OOC) - Self: Play emote 25');

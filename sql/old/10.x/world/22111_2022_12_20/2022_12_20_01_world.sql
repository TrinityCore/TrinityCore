SET @CGUID := 1250004;

SET @NPCTEXTID := 590004;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 189602, 0, 1519, 5390, '0', 19125, 0, 0, 0, -8312.267578125, 337.78472900390625, 155.4304962158203125, 4.410583019256591796, 120, 0, 0, 105705, 0, 0, 0, 0, 0, 46702), -- Toddy Whiskers (Area: The Canals - Difficulty: 0)
(@CGUID+1, 189767, 0, 1519, 5150, '0', 19123, 0, 0, 0, -8426.9970703125, 608.70660400390625, 95.23224639892578125, 5.077036380767822265, 120, 0, 0, 105705, 0, 0, 0, 0, 0, 46702), -- Thaelin Darkanvil (Area: Dwarven District - Difficulty: 0)
(@CGUID+2, 198383, 0, 1519, 5150, '0', 19123, 0, 0, 0, -8424.4111328125, 607.34027099609375, 95.21673583984375, 2.991660833358764648, 120, 0, 0, 35235, 2568, 0, 0, 0, 0, 46702), -- Dracthyr Smith (Area: Dwarven District - Difficulty: 0) (Auras: 374209 - -Unknown-)
(@CGUID+3, 198383, 0, 1519, 5150, '0', 19123, 0, 0, 0, -8426.203125, 605.74481201171875, 95.12477874755859375, 1.865920424461364746, 120, 0, 0, 35235, 2568, 0, 0, 0, 0, 46702), -- Dracthyr Smith (Area: Dwarven District - Difficulty: 0)
(@CGUID+4, 189765, 0, 1519, 5148, '0', 19121, 0, 0, 0, -8805.564453125, 622.1961669921875, 94.97937774658203125, 3.336289644241333007, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Cataloger Wulferd (Area: Trade District - Difficulty: 0)
(@CGUID+5, 189763, 0, 1519, 4411, '0', 19122, 0, 0, 0, -8520.466796875, 1058.52783203125, 60.04923248291015625, 3.115431785583496093, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Pathfinder Jeb (Area: Stormwind Harbor - Difficulty: 0) (Auras: 383066 - -Unknown-)
(@CGUID+6, 193812, 0, 1519, 4411, '0', 19122, 0, 0, 0, -8524.607421875, 1057.7569580078125, 60.055908203125, 0.430941015481948852, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Expedition Trainee (Area: Stormwind Harbor - Difficulty: 0) (Auras: 367235 - -Unknown-)
(@CGUID+7, 193812, 0, 1519, 4411, '0', 19122, 0, 0, 0, -8522.419921875, 1059.3853759765625, 58.79501724243164062, 5.030648231506347656, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Expedition Trainee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+8, 198391, 0, 1519, 4411, '0', 19133, 0, 0, 0, -8531.326171875, 1050.48095703125, 63.0379638671875, 3.467262983322143554, 120, 0, 0, 35235, 2568, 0, 0, 0, 0, 46702), -- Dracthyr Belayer (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+9, 193812, 0, 1519, 4411, '0', 19133, 0, 0, 0, -8533.734375, 1050.7100830078125, 63.2564697265625, 5.305318832397460937, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Expedition Trainee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+10, 193812, 0, 1519, 4411, '0', 19133, 0, 0, 0, -8511.376953125, 1042.5728759765625, 78.1812591552734375, 0.671511828899383544, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Expedition Trainee (Area: Stormwind Harbor - Difficulty: 0) (Auras: 174127 - UseKneeling)
(@CGUID+11, 193786, 0, 1519, 5148, '0', 19133, 0, 0, 0, -8809.921875, 619.91668701171875, 95.0310211181640625, 0.435839086771011352, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Cataloguing Enthusiast (Area: Trade District - Difficulty: 0)
(@CGUID+12, 193786, 0, 1519, 5148, '0', 19133, 0, 0, 0, -8806.53515625, 624.14581298828125, 94.62673187255859375, 5.149429798126220703, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Cataloguing Enthusiast (Area: Trade District - Difficulty: 0)
(@CGUID+13, 193786, 0, 1519, 5148, '0', 19133, 0, 0, 0, -8810.9482421875, 621.5086669921875, 94.753662109375, 0.073022812604904174, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Cataloguing Enthusiast (Area: Trade District - Difficulty: 0)
(@CGUID+14, 193786, 0, 1519, 5148, '0', 19133, 0, 0, 0, -8808.576171875, 625.295166015625, 94.54514312744140625, 5.409007072448730468, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Cataloguing Enthusiast (Area: Trade District - Difficulty: 0)
(@CGUID+15, 193786, 0, 1519, 5148, '0', 19133, 0, 0, 0, -8808.0693359375, 620.34027099609375, 95.02405548095703125, 0.866888761520385742, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Cataloguing Enthusiast (Area: Trade District - Difficulty: 0)
(@CGUID+16, 198384, 0, 1519, 5148, '0', 19133, 0, 0, 0, -8812.5849609375, 619.84027099609375, 94.81744384765625, 0.437271863222122192, 120, 0, 0, 35235, 2568, 0, 0, 0, 0, 46702), -- Intrigued Dracthyr (Area: Trade District - Difficulty: 0)
(@CGUID+17, 189075, 0, 1519, 4411, '0', 19176, 0, 0, 0, -8642.677734375, 1288.0416259765625, 10.9043436050415039, 5.2845306396484375, 120, 0, 0, 5, 0, 0, 0, 0, 0, 46702), -- Seagull (Area: Stormwind Harbor - Difficulty: 0) (Auras: )
(@CGUID+18, 189080, 0, 1519, 4411, '0', 19176, 0, 0, 0, -8648.013671875, 1295.9410400390625, 5.683270931243896484, 3.484134197235107421, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Cataloger Wulferd (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+19, 198383, 0, 1519, 4411, '0', 19176, 0, 0, 0, -8638.328125, 1288.9722900390625, 5.316689491271972656, 3.154607534408569335, 120, 0, 0, 35235, 2568, 0, 0, 0, 0, 46702), -- Dracthyr Smith (Area: Stormwind Harbor - Difficulty: 0) (Auras: 374209 - -Unknown-)
(@CGUID+20, 198391, 0, 1519, 4411, '0', 19176, 0, 0, 0, -8640.9892578125, 1288.453125, 5.315905570983886718, 0.257689595222473144, 120, 0, 0, 35235, 2568, 0, 0, 0, 0, 46702), -- Dracthyr Belayer (Area: Stormwind Harbor - Difficulty: 0) (Auras: 374148 - -Unknown-)
(@CGUID+21, 189077, 0, 1519, 4411, '0', 19176, 0, 0, 1, -8640.5625, 1328.111083984375, 5.315807819366455078, 5.048699378967285156, 120, 0, 0, 105705, 0, 0, 0, 0, 0, 46702), -- Toddy Whiskers (Area: Stormwind Harbor - Difficulty: 0) (Auras: 382510 - -Unknown-)
(@CGUID+22, 194015, 0, 1519, 4411, '0', 19176, 0, 0, 0, -8639.2099609375, 1331.1788330078125, 5.315584182739257812, 4.990554332733154296, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Wildfeather (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+23, 189079, 0, 1519, 4411, '0', 19176, 0, 0, 0, -8628.826171875, 1316.1319580078125, 5.31719207763671875, 0.04477626085281372, 120, 0, 0, 105705, 0, 0, 0, 0, 0, 46702), -- Thaelin Darkanvil (Area: Stormwind Harbor - Difficulty: 0) (Auras: 174127 - UseKneeling)
(@CGUID+24, 189076, 0, 1519, 4411, '0', 19176, 0, 0, 0, -8618.22265625, 1315.1510009765625, 5.718079566955566406, 1.310383915901184082, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Pathfinder Jeb (Area: Stormwind Harbor - Difficulty: 0) (Auras: 383066 - -Unknown-)
(@CGUID+25, 198079, 0, 1519, 4411, '0', 0, 0, 0, 0, -8649.5556640625, 1329.876708984375, 5.780003547668457031, 5.346585750579833984, 120, 0, 0, 35235, 0, 0, 0, 0, 0, 46702), -- Chrovo (Area: Stormwind Harbor - Difficulty: 0) (Auras: 392623 - -Unknown-)
(@CGUID+26, 189569, 0, 1519, 4411, '0', 19268, 0, 0, 0, -8647.5732421875, 1329.18408203125, 5.31698465347290039, 2.083447933197021484, 120, 0, 0, 5645950, 0, 0, 0, 0, 0, 46702), -- Wrathion (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+27, 198393, 0, 1519, 8411, '0', 19820, 0, 0, 0, -8781.2236328125, 836.3680419921875, 151.912384033203125, 4.373180866241455078, 120, 0, 0, 19343, 2434, 0, 0, 0, 0, 46702), -- Dracthyr Evoker (Area: Lion's Rest - Difficulty: 0) (Auras: )
(@CGUID+28, 198393, 0, 1519, 8411, '0', 19820, 0, 0, 0, -8776.5537109375, 830.70660400390625, 151.912384033203125, 0.758913874626159667, 120, 0, 0, 19343, 2434, 0, 0, 0, 0, 46702), -- Dracthyr Evoker (Area: Lion's Rest - Difficulty: 0) (Auras: 393746 - -Unknown-)
(@CGUID+29, 198393, 0, 1519, 8411, '0', 19820, 0, 0, 0, -8782.53515625, 832.65106201171875, 151.912384033203125, 1.231587886810302734, 120, 0, 0, 19343, 2434, 0, 0, 0, 0, 46702), -- Dracthyr Evoker (Area: Lion's Rest - Difficulty: 0) (Auras: 393746 - -Unknown-)
(@CGUID+30, 198393, 0, 1519, 8411, '0', 19820, 0, 0, 0, -8773.6943359375, 833.41839599609375, 151.912384033203125, 3.90050673484802246, 120, 0, 0, 19343, 2434, 0, 0, 0, 0, 46702), -- Dracthyr Evoker (Area: Lion's Rest - Difficulty: 0)
(@CGUID+31, 198401, 0, 1519, 8411, '0', 19820, 0, 0, 0, -8776.41015625, 838.30902099609375, 151.912384033203125, 4.206534385681152343, 120, 0, 0, 35235, 2568, 0, 0, 0, 0, 46702), -- Dervishian (Area: Lion's Rest - Difficulty: 0)
(@CGUID+32, 193450, 0, 1519, 4411, '0', 19142, 0, 0, 1, -8646.201171875, 1323.1024169921875, 5.317089557647705078, 5.532693862915039062, 120, 0, 0, 9033500, 7196, 0, 0, 0, 0, 47187), -- Archmage Khadgar (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+33, 189569, 0, 1519, 4411, '0', 19329, 0, 0, 0, -8644.4375, 1324.3836669921875, 5.31765604019165039, 5.30458688735961914, 120, 0, 0, 5645950, 0, 0, 0, 0, 0, 46702); -- Wrathion (Area: Stormwind Harbor - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 69, 0, 0, 0, 0, ''), -- Thaelin Darkanvil
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '374209'), -- Dracthyr Smith - 374209 - -Unknown-
(@CGUID+3, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Dracthyr Smith
(@CGUID+5, 0, 0, 8, 0, 0, 0, 0, 0, 0, '383066'), -- Pathfinder Jeb - 383066 - -Unknown-
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, 0, '367235'), -- Expedition Trainee - 367235 - -Unknown-
(@CGUID+7, 0, 0, 0, 1, 0, 11775, 0, 0, 0, ''), -- Expedition Trainee
(@CGUID+8, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Dracthyr Belayer
(@CGUID+9, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- Expedition Trainee
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, 0, '174127'), -- Expedition Trainee - 174127 - UseKneeling
(@CGUID+15, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Cataloguing Enthusiast
(@CGUID+17, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Seagull
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, 0, '374209'), -- Dracthyr Smith - 374209 - -Unknown-
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, 0, '374148'), -- Dracthyr Belayer - 374148 - -Unknown-
(@CGUID+21, 0, 0, 0, 1, 0, 14931, 0, 0, 0, '382510'), -- Toddy Whiskers - 382510 - -Unknown-
(@CGUID+22, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Wildfeather
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, 0, '174127'), -- Thaelin Darkanvil - 174127 - UseKneeling
(@CGUID+24, 0, 0, 8, 1, 0, 0, 0, 0, 0, '383066'), -- Pathfinder Jeb - 383066 - -Unknown-
(@CGUID+25, 0, 0, 0, 0, 0, 0, 0, 0, 0, '392623'), -- Chrovo - 392623 - -Unknown-
(@CGUID+26, 0, 0, 0, 1, 0, 25296, 0, 0, 0, ''), -- Wrathion
(@CGUID+27, 0, 0, 0, 1, 27, 0, 0, 0, 0, ''), -- Dracthyr Evoker
(@CGUID+28, 0, 0, 0, 1, 27, 0, 0, 0, 0, '393746'), -- Dracthyr Evoker - 393746 - -Unknown-
(@CGUID+29, 0, 0, 0, 1, 27, 0, 0, 0, 0, '393746'), -- Dracthyr Evoker - 393746 - -Unknown-
(@CGUID+30, 0, 0, 0, 1, 27, 0, 0, 0, 0, ''), -- Dracthyr Evoker
(@CGUID+32, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Archmage Khadgar

DELETE FROM `creature_template_addon` WHERE `entry` IN (189602 /*189602 (Toddy Whiskers)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(189602, 0, 0, 0, 0, 0, 0, 0, 0, 3, ''); -- 189602 (Toddy Whiskers)

-- Creature Template
UPDATE `creature_template` SET `gossip_menu_id`=28626, `minlevel`=70, `maxlevel`=70, `faction`=2110, `npcflag`=281474976710659, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=193450; -- Archmage Khadgar
UPDATE `creature_template` SET `gossip_menu_id`=30048, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189077; -- Toddy Whiskers
UPDATE `creature_template` SET `gossip_menu_id`=29955, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198079; -- Chrovo
UPDATE `creature_template` SET `gossip_menu_id`=28735, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189080; -- Cataloger Wulferd
UPDATE `creature_template` SET `gossip_menu_id`=28737, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=189079; -- Thaelin Darkanvil
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189078; -- Scalecommander Azurathel
UPDATE `creature_template` SET `gossip_menu_id`=28736, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189076; -- Pathfinder Jeb
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=195830; -- Expedition Provisioner
UPDATE `creature_template` SET `gossip_menu_id`=30045, `minlevel`=62, `maxlevel`=62, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198401; -- Dervishian
UPDATE `creature_template` SET `gossip_menu_id`=28666, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189569; -- Wrathion
UPDATE `creature_template` SET `gossip_menu_id`=30065, `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189603; -- Scalecommander Azurathel
UPDATE `creature_template` SET `gossip_menu_id`=28720, `minlevel`=63, `maxlevel`=63, `faction`=1733, `npcflag`=1, `speed_walk`=1.60000002384185791, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189600; -- High Exarch Turalyon
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=194015; -- Wildfeather
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189075; -- Seagull
UPDATE `creature_template` SET `gossip_menu_id`=28056, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189763; -- Pathfinder Jeb
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=193812; -- Expedition Trainee
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198391; -- Dracthyr Belayer
UPDATE `creature_template` SET `gossip_menu_id`=28057, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189765; -- Cataloger Wulferd
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=193786; -- Cataloguing Enthusiast
UPDATE `creature_template` SET `gossip_menu_id`=28058, `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=189767; -- Thaelin Darkanvil
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `npcflag`=281474976710658, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=189602; -- Toddy Whiskers
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197070; -- Thaelin Darkanvil
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197069; -- Scalecommander Azurathel
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197068; -- Cataloger Wulferd
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197067; -- Pathfinder Jeb
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197066; -- Toddy Whiskers
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=197283; -- Wildfeather
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198496; -- Scalecommander Emberthal
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=3270, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198408; -- Dervishian
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198393; -- Dracthyr Evoker

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 1519 AND `PhaseId` IN (19125, 19123, 19121, 19176, 19122, 19268, 19329, 19142, 19153, 19133,19820));
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 19125, 'Cosmetic - See Toddy Whiskers at Stormwind Keep'),
(1519, 19123, 'Cosmetic - See Thaelin Darkanvil at Dwarven District'),
(1519, 19121, 'Cosmetic - See Cataloger Wulferd at Trade District'),
(1519, 19176, 'Cosmetic - See Expedition Crew at Stormwind Harbor'),
(1519, 19122, 'Cosmetic - See Pathfinder Jeb at Stormwind Harbor'),
(1519, 19268, 'Cosmetic - See Wrathion at Stormwind Harbor'),
(1519, 19329, 'Cosmetic - See Wrathion meeting Khadgar at Stormwind Harbor'),
(1519, 19142, 'Cosmetic - See Archmage Khadgar at Stormwind Harbor'),
(1519, 19820, 'Cosmetic - See Dervishian and Dracthyr Evoker Trainees'),
(1519, 19133, 'Cosmetic - See Expedtion Trainees in Stormwind');

DELETE FROM `phase_name` WHERE `ID` IN (19125, 19123, 19121, 19176, 19122, 19268, 19329, 19142, 19153, 19133,19820);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(19125, 'Cosmetic - See Toddy Whiskers at Stormwind Keep'),
(19123, 'Cosmetic - See Thaelin Darkanvil at Dwarven District'),
(19121, 'Cosmetic - See Cataloger Wulferd at Trade District'),
(19176, 'Cosmetic - See Expedition Crew at Stormwind Harbor'),
(19122, 'Cosmetic - See Pathfinder Jeb at Stormwind Harbor'),
(19268, 'Cosmetic - See Wrathion at Stormwind Harbor'),
(19329, 'Cosmetic - See Wrathion meeting Khadgar at Stormwind Harbor'),
(19142, 'Cosmetic - See Archmage Khadgar at Stormwind Harbor'),
(19820, 'Cosmetic - See Dervishian and Dracthyr Evoker Trainees'),
(19133, 'Cosmetic - See Expedtion Trainees in Stormwind');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (19125, 19123, 19121, 19176, 19122, 19137, 19268, 19329, 19142, 19153, 19189, 19133, 19820) AND `SourceEntry` = 1519);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
-- Phase 19125 Thoddy Whiskers in Stormwind Keep
(26, 19125, 1519, 0, 0, 47, 0, 65436, 2 | 64, 0, 0, 'Apply Phase 19125 If Quest 65436 is complete | rewarded'),
(26, 19125, 1519, 0, 0, 47, 0, 66589, 2 | 8 | 64, 0, 1, 'Apply Phase 19125 If Quest 66589 is not In Progress | complete | rewarded'),
-- Phase 19133 Expedition Trainees in Stormwind
(26, 19133, 1519, 0, 0, 47, 0, 66589, 2 | 8, 0, 0, 'Apply Phase 19133 If Quest 66589 is In Progress | complete'),
-- Phase 19123 Thaelin Darkanvil at Dwarven District
(26, 19123, 1519, 0, 0, 47, 0, 66589, 2 | 8, 0, 0, 'Apply Phase 19123 If Quest 66589 is In Progress | complete'),
(26, 19123, 1519, 0, 0, 48, 0, 429652, 0, 1, 1, 'Apply Phase 19123 If Questobjective 429652 is not rewarded'),
-- Phase 19121 Cataloger Wulferd at Trade District
(26, 19121, 1519, 0, 0, 47, 0, 66589, 2 | 8, 0, 0, 'Apply Phase 19121 If Quest 66589 is in Progress | complete'),
(26, 19121, 1519, 0, 0, 48, 0, 429654, 0, 1, 1, 'Apply Phase 19121 If Questobjective 429654 is not rewarded'),
-- Phase 19122 Pathfinder Jeb at Stormwind Harbor
(26, 19122, 1519, 0, 0, 47, 0, 66589, 2 | 8, 0, 0, 'Apply Phase 19122 If Quest 66589 is in Progress | complete'),
(26, 19122, 1519, 0, 0, 48, 0, 429653, 0, 1, 1, 'Apply Phase 19122 If Questobjective 429653 is not rewarded'),
-- Phase 19176 Expedtion Crew at Habor
(26, 19176, 1519, 0, 0, 47, 0, 66589, 2 | 64, 0, 0, 'Apply Phase 19176 If Quest 66589 is complete | rewarded'),
(26, 19176, 1519, 0, 0, 47, 0, 67700, 2 | 8 | 64, 0, 1, 'Apply Phase 19176 If Quest 66589 is not in progress | complete | rewarded'),
-- Phase 19268 Wrathion at Stormwind Habor
(26, 19268, 1519, 0, 0, 47, 0, 72240, 2 | 8, 0, 0, 'Apply Phase 19268 If Quest 72240 is in progress | complete'),
-- Phase 19820 Dervishian and Dracthyr Evoker
(26, 19820, 1519, 0, 0, 47, 0, 72240, 8, 0, 0, 'Apply Phase 19820 If Quest 72240 is in progress'),
-- Phase 19142 Khadgar at Stormwind Habor
(26, 19142, 1519, 0, 0, 47, 0, 72240, 64, 0, 0, 'Apply Phase 19142 If Quest 72240 is rewarded'),
(26, 19142, 1519, 0, 0, 47, 0, 67700, 64, 0, 1, 'Apply Phase 19142 If Quest 67700 is not rewarded'),
-- Phase 19329 Wrathion meeting Khadgar
(26, 19329, 1519, 0, 0, 47, 0, 72240, 64, 0, 0, 'Apply Phase 19329 If Quest 72240 is rewarded'),
(26, 19329, 1519, 0, 0, 47, 0, 66596, 64, 0, 0, 'Apply Phase 19329 If Quest 66596 is not rewarded');

-- Creature Equip Template
DELETE FROM `creature_equip_template` WHERE (`CreatureID` IN (189077,193450,193921,189600,197066) AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(189077, 1, 194962, 0, 0, 0, 0, 0, 0, 0, 0, 46702), -- Toddy Whiskers
(193450, 1, 23998, 0, 0, 0, 0, 0, 0, 0, 0, 46702), -- Archmage Khadgar
(193921, 1, 47104, 0, 0, 47104, 0, 0, 0, 0, 0, 46702), -- Master Mathias Shaw
(189600, 1, 150577, 0, 0, 0, 0, 0, 0, 0, 0, 46702), -- High Exarch Turalyon
(197066, 1, 194962, 0, 0, 0, 0, 0, 0, 0, 0, 47187); -- Toddy Whiskers

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureID` = 189075;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(189075, 0, 0, 1, 0, 0, 0, NULL);

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+12;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 225378, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189079 (Thaelin Darkanvil)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 218471, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189763 (Pathfinder Jeb)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 218461, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189765 (Cataloger Wulferd)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 225378, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189767 (Thaelin Darkanvil)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 232381, 0, 0, 0, 0, 0, 0, 0, 46741), -- 198401 (Dervishian)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 231944, 0, 0, 0, 0, 0, 0, 0, 47187), -- 198079 (Chrovo)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 232400, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189077 (Toddy Whiskers)
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 224528, 0, 0, 0, 0, 0, 0, 0, 46741), -- 193450 (Archmage Khadgar)
(@NPCTEXTID+8, 1, 0, 0, 0, 0, 0, 0, 0, 225160, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189600 (High Exarch Turalyon)
(@NPCTEXTID+9, 1, 1, 0, 0, 0, 0, 0, 0, 226287, 224828, 0, 0, 0, 0, 0, 0, 46741), -- 189569 (Wrathion)
(@NPCTEXTID+10, 1, 0, 0, 0, 0, 0, 0, 0, 232496, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189603 (Scalecommander Azurathel)
(@NPCTEXTID+11, 1, 0, 0, 0, 0, 0, 0, 0, 225353, 0, 0, 0, 0, 0, 0, 0, 46741), -- 189080 (Cataloger Wulferd)
(@NPCTEXTID+12, 1, 0, 0, 0, 0, 0, 0, 0, 225354, 0, 0, 0, 0, 0, 0, 0, 46741); -- 189076 (Pathfinder Jeb)

DELETE FROM `gossip_menu` WHERE (`MenuID`=28737 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=28056 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=28057 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=28058 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=30045 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=29955 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=30048 AND `TextID`=@NPCTEXTID+6) OR (`MenuID`=28626 AND `TextID`=@NPCTEXTID+7) OR (`MenuID`=28720 AND `TextID`=@NPCTEXTID+8) OR (`MenuID`=28666 AND `TextID`=@NPCTEXTID+9) OR (`MenuID`=30065 AND `TextID`=@NPCTEXTID+10) OR (`MenuID`=28735 AND `TextID`=@NPCTEXTID+11) OR (`MenuID`=28736 AND `TextID`=@NPCTEXTID+12);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(28737, @NPCTEXTID+0, 46741), -- 189079 (Thaelin Darkanvil)
(28056, @NPCTEXTID+1, 46741), -- 189763 (Pathfinder Jeb)
(28057, @NPCTEXTID+2, 46741), -- 189765 (Cataloger Wulferd)
(28058, @NPCTEXTID+3, 46741), -- 189767 (Thaelin Darkanvil)
(30045, @NPCTEXTID+4, 46741), -- 198401 (Dervishian)
(29955, @NPCTEXTID+5, 47187), -- 198079 (Chrovo)
(30048, @NPCTEXTID+6, 46741), -- 189077 (Toddy Whiskers)
(28626, @NPCTEXTID+7, 46741), -- 193450 (Archmage Khadgar)
(28720, @NPCTEXTID+8, 46741), -- 189600 (High Exarch Turalyon)
(28666, @NPCTEXTID+9, 46741), -- 189569 (Wrathion)
(30065, @NPCTEXTID+10, 46741), -- 189603 (Scalecommander Azurathel)
(28735, @NPCTEXTID+11, 46741), -- 189080 (Cataloger Wulferd)
(28736, @NPCTEXTID+12, 46741); -- 189076 (Pathfinder Jeb)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=1 AND `MenuID`=28666) OR (`OptionID`=0 AND `MenuID` IN (28056,28057,30045,28626,28058,29955));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(55659, 28666, 1, 0, '<Listen to Wrathion and Turalyon.>', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, 0, 46741),
(55649, 28056, 0, 0, 'We need explorers for an expedition to the Dragon Isles. Will you join us?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46741),
(55650, 28057, 0, 0, 'We need scholars for an expedition to the Dragon Isles. Will you join us?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46741),
(107417, 30045, 0, 0, 'Scalecommander Azurathel would like you to meet him at the docks.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46741),
(55739, 28626, 0, 0, '<Ask Khadgar what happened.>', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46741),
(55651, 28058, 0, 0, 'We need artisans for an expedition to the Dragon Isles. Will you join us?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 46741),
(107290, 29955, 0, 0, 'How long until the Rugged Dragonscale docks here?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 47187);

-- Gossip Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (28626, 30045, 28058, 28057, 28056) AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 28666 AND `SourceEntry` = 1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 28626, 0, 0, 0, 47, 0, 66596, 8, 0, 0, 'Show Gossip Menu Option 28626 if Quest: 66596 is in Progress'), -- Khadgar
(15, 28666, 1, 0, 0, 47, 0, 66577, 8, 0, 0, 'Show Gossip Menu Option 28666 if Quest: 66577 is in Progress'), -- Wrathion
(15, 30045, 0, 0, 0, 47, 0, 72240, 8, 0, 0, 'Show Gossip Menu Option 30045 if Quest: 72240 is in Progress'), -- Wrathion
(15, 28058, 0, 0, 0, 48, 0, 429652, 0, 1, 1, 'Show Gossip Menu Option 28058 if Questobjective: 429652 is not rewarded'), -- Thaelin
(15, 28057, 0, 0, 0, 48, 0, 429654, 0, 1, 1, 'Show Gossip Menu Option 28057 if Questobjective: 429654 is not rewarded'), -- Wulferd
(15, 28056, 0, 0, 0, 48, 0, 429653, 0, 1, 1, 'Show Gossip Menu Option 28056 if Questobjective: 429653 is not rewarded'); -- Jeb

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`Entry`=73532 AND `DifficultyID`=0) OR (`DifficultyID`=0 AND `Entry` IN (197609,159783));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(73532, 0, 0, 0, 371, 47187),
(197609, 0, 0, 0, 2523, 47187),
(159783, 0, 0, 0, 371, 47187);

DELETE FROM `creature_model_info` WHERE `DisplayID`=109614;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(109614, 0.305999994277954101, 1.5, 0, 47187);

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID` IN (66596 /*Whispers on the Winds*/, 66589 /*Expeditionary Coordination*/, 72240 /*The Obsidian Warders*/, 66577 /*Aspectral Invitation*/, 65436 /*The Dragon Isles Await*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(66596, 1, 0, 0, 0, 0, 0, 0, 0, 're not present to witness Raszageth\'s release as we were, no', 46741), -- Whispers on the Winds
(66589, 1, 0, 0, 0, 0, 0, 0, 0, 'That was fast!\n\nEager to get to the Dragon Isles, eh? Me too!', 46741), -- Expeditionary Coordination
(72240, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'m pleased the dracthyr are comin\' with us.\n\nCan\'t wait to challenge that scalecommander to a race on ol\' Wildfeather.\n\nMy gryphon will best his leathery ol\' wings any day!', 46741), -- The Obsidian Warders
(66577, 1, 0, 0, 0, 0, 0, 0, 0, 'o the Dragon Isles beyond the Forbidden Reach. I cannot wait for you to see it!\n\nNow then, I believe that diminutive archaeologist said something about put', 46741), -- Aspectral Invitation
(65436, 1, 0, 0, 0, 0, 0, 0, 0, 'The Aspects\' invitation extends to you as well, friend.', 46741); -- The Dragon Isles Await

DELETE FROM `quest_request_items` WHERE `ID` IN (72240, 66577);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(72240, 0, 0, 0, 0, 'Ye think a dracthyr can fly faster than a gryphon?', 46702), -- -Unknown-
(66577, 0, 0, 0, 0, '', 47187); -- Aspectral Invitation

DELETE FROM `creature_queststarter` WHERE (`id`=193450 AND `quest`=66596) OR (`id`=189603 AND `quest`=72240) OR (`id`=189602 AND `quest`=66589) OR (`id`=189569 AND `quest`=66577) OR (`id`=189077 AND `quest`=67700);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(193450, 66596, 46741), -- Whispers on the Winds offered Archmage Khadgar
(189603, 72240, 46741), -- The Obsidian Warders offered Scalecommander Azurathel
(189602, 66589, 46741), -- Expeditionary Coordination offered Toddy Whiskers
(189569, 66577, 46741), -- Aspectral Invitation offered Wrathion
(189077, 67700, 47187); -- To the Dragon Isles! offered Toddy Whiskers

DELETE FROM `creature_questender` WHERE (`id`=189569 AND `quest` IN (66596,66577,65436)) OR (`id`=189077 AND `quest` IN (66589,72240));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(189569, 66596, 46741), -- Whispers on the Winds ended by Wrathion
(189077, 66589, 46741), -- Expeditionary Coordination ended by Toddy Whiskers
(189077, 72240, 46741), -- The Obsidian Warders ended by Toddy Whiskers
(189569, 66577, 46741), -- Aspectral Invitation ended by Wrathion
(189569, 65436, 46741); -- The Dragon Isles Await ended by Wrathion

SET @CGUID := 1051033;
SET @OGUID := 600225;

-- Creature Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 157728, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4204.166015625, -4939.0625, 6544.798828125, 2.232315540313720703, 7200, 6, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Lighthoof Roamer (Area: -Unknown- - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1, 157728, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4189.04345703125, -4944.8037109375, 6542.1376953125, 4.907969474792480468, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Lighthoof Roamer (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+2, 158772, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4164.5693359375, -4954.31103515625, 6542.21533203125, 1.223839640617370605, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Eternal Terrapin (Area: -Unknown- - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+3, 158772, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4113.48291015625, -4967.58837890625, 6544.09326171875, 3.231545448303222656, 7200, 4, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Eternal Terrapin (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+4, 175653, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4122.62841796875, -5053.47216796875, 6542.79541015625, 6.183524608612060546, 7200, 0, 0, 6755, 0, 0, 0, 0, 0, 43345), -- Ephemeral Mistwalker (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+5, 158772, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4084.770751953125, -4992.2744140625, 6542.1591796875, 0.508068263530731201, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Eternal Terrapin (Area: -Unknown- - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+6, 168919, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4063.9013671875, -4974.60400390625, 6584.7314453125, 4.172388076782226562, 7200, 0, 0, 5404, 0, 0, 0, 0, 0, 43345), -- Elysian Owl (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 175777, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4165.21728515625, -4936.17529296875, 6545.20458984375, 0.935697376728057861, 7200, 0, 0, 1125, 0, 0, 0, 0, 0, 43345), -- Crystalsnap (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 157725, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4106.5810546875, -4993.0810546875, 6544.00927734375, 1.437924504280090332, 7200, 4, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Spritely Glimmerfly (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+9, 157725, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4177.279296875, -4986.5693359375, 6542.33056640625, 4.199854373931884765, 7200, 6, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Spritely Glimmerfly (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+10, 157725, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4103.98876953125, -4939.69775390625, 6554.71630859375, 2.50740218162536621, 7200, 4, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Spritely Glimmerfly (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+11, 158772, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4082.5966796875, -4979.26220703125, 6547.58984375, 4.597904205322265625, 7200, 4, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Eternal Terrapin (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+12, 157725, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4165.75927734375, -4974.1328125, 6544.06689453125, 5.445689678192138671, 7200, 6, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Spritely Glimmerfly (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+13, 175653, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4079.973876953125, -4997.1162109375, 6542.9267578125, 5.317731380462646484, 7200, 0, 0, 6755, 0, 0, 0, 0, 0, 43345), -- Ephemeral Mistwalker (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 168624, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4046.800537109375, -5053.28515625, 6565.7041015625, 0.591050148010253906, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 43345), -- Spiritwing Flitter (Area: -Unknown- - Difficulty: 0)
(@CGUID+15, 157728, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4156.89794921875, -4881.537109375, 6546.529296875, 2.161509037017822265, 7200, 6, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Lighthoof Roamer (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+16, 158772, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4242.4287109375, -4997.51025390625, 6542.62109375, 4.499983787536621093, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Eternal Terrapin (Area: -Unknown- - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+17, 157725, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4265.5234375, -4910.025390625, 6503.63623046875, 2.269795894622802734, 7200, 8, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Spritely Glimmerfly (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+18, 157728, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4238.37548828125, -4879.15283203125, 6510.29931640625, 6.142117023468017578, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Lighthoof Roamer (Area: -Unknown- - Difficulty: 0)
(@CGUID+19, 157728, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4183.78125, -4862.861328125, 6541.53857421875, 2.407475233078002929, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Lighthoof Roamer (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 157725, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4237.111328125, -4922.7333984375, 6508.16357421875, 2.361021041870117187, 7200, 8, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Spritely Glimmerfly (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-)
(@CGUID+21, 157725, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4256.52978515625, -4980.04296875, 6547.2802734375, 4.89803314208984375, 7200, 4, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Spritely Glimmerfly (Area: -Unknown- - Difficulty: 0) (Auras: 312748 - -Unknown-) (possible waypoints or random movement)
(@CGUID+22, 171712, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4242.5234375, -4983.34423828125, 6541.3818359375, 6.022012710571289062, 7200, 0, 0, 5, 0, 0, 0, 0, 0, 43345), -- Wader Chick (Area: -Unknown- - Difficulty: 0) (Auras: 308853 - -Unknown-)
(@CGUID+23, 157728, 2222, 10534, 0, '0', 0, 0, 0, 0, -4255.82275390625, -4881.859375, 6503.09228515625, 3.459049463272094726, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Lighthoof Roamer (Area: 0 - Difficulty: 0)
(@CGUID+24, 157277, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4298.7138671875, -4969.0146484375, 6553.2607421875, 5.240857124328613281, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Starved Etherwyrm (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 175653, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4271.15087890625, -4983.4599609375, 6541.50927734375, 1.076701045036315917, 7200, 4, 0, 6755, 0, 1, 0, 0, 0, 43345), -- Ephemeral Mistwalker (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 158772, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4282.94970703125, -4969.681640625, 6543.15673828125, 5.954146385192871093, 7200, 4, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Eternal Terrapin (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+27, 157277, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4310.98828125, -4942.31201171875, 6543.7626953125, 2.331337690353393554, 7200, 4, 0, 6100, 0, 1, 0, 0, 0, 43345), -- Starved Etherwyrm (Area: -Unknown- - Difficulty: 0)
(@CGUID+28, 157728, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4291.9775390625, -4976.55908203125, 6542.30859375, 5.276501655578613281, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Lighthoof Roamer (Area: -Unknown- - Difficulty: 0) (Auras: )
(@CGUID+29, 158772, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4282.16650390625, -4979.70654296875, 6542.748046875, 2.184412479400634765, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345), -- Eternal Terrapin (Area: -Unknown- - Difficulty: 0) (Auras: 120703 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+30, 157274, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4319.5625, -4930.61669921875, 6550.9375, 3.281999111175537109, 7200, 0, 0, 4880, 0, 0, 0, 0, 0, 43345), -- Languishing Etherwyrm (Area: -Unknown- - Difficulty: 0)
(@CGUID+31, 157277, 2222, 10534, 11509, '0', 0, 0, 0, 0, -4359.611328125, -4966.47314453125, 6568.37353515625, 3.573760986328125, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345); -- Starved Etherwyrm (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+31;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'), -- Eternal Terrapin - 120703 - Cosmetic - Sleep Zzz Breakable
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'), -- Eternal Terrapin - 120703 - Cosmetic - Sleep Zzz Breakable
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'), -- Eternal Terrapin - 120703 - Cosmetic - Sleep Zzz Breakable
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, 0, '120703'); -- Eternal Terrapin - 120703 - Cosmetic - Sleep Zzz Breakable

-- GameObject Spawns
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 353378, 2222, 10534, 11509, '0', 0, 0, -4071.80029296875, -4771.1806640625, 6558.79541015625, 0.012649619951844215, 0, 0, 0.00632476806640625, 0.999979972839355468, 7200, 255, 1, 43345); -- Spirit Obelisk (Area: -Unknown- - Difficulty: 0)

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (157277, 157274);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(157277, 1, 0, 1, 0, 0, 0, NULL),
(157274, 1, 0, 1, 0, 0, 0, NULL);

-- Waypoint Data for @CGUID+18
SET @PATH := @CGUID+18 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, -4244.418, -4878.295, 6506.761, 0, 4436, 0, 0, 100, 0),
(@PATH, 1, -4227.584, -4880.686, 6515.164, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -4212.813, -4886.588, 6522.27, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -4203.594, -4893.868, 6528.407, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -4195.768, -4900.45, 6532.62, 0, 3490, 0, 0, 100, 0),
(@PATH, 5, -4203.594, -4893.868, 6528.407, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -4212.813, -4886.588, 6522.27, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -4227.585, -4880.686, 6515.17, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= -4244.418, `position_y`= -4878.295, `position_z`= 6506.761, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+18, @PATH, 1);

-- Waypoint Data for @CGUID+13
SET @PATH := @CGUID+13 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 21, -4091.34, -4979.03, 6543.94, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -4087.66, -4983.22, 6543.89, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -4085.78, -4985.8, 6543.49, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -4083.2, -4990.25, 6543.34, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -4082.26, -4992.47, 6542.94, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -4079.97, -4997.12, 6542.93, 0, 6981, 0, 0, 100, 0),
(@PATH, 15, -4080.62, -4996.17, 6542.93, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -4083.2, -4990.25, 6543.34, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -4084.27, -4988.41, 6543.27, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -4085.78, -4985.8, 6543.49, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -4087.66, -4983.22, 6543.89, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -4091.34, -4979.03, 6543.94, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -4092.68, -4978.56, 6543.66, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -4095.76, -4976.69, 6543.53, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -4097.79, -4974.27, 6543.84, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -4099.43, -4972.79, 6543.98, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -4102.51, -4971.41, 6544.44, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -4106.17, -4972.7, 6542.77, 0, 8148, 0, 0, 100, 0),
(@PATH, 3, -4105.07, -4971.26, 6544.06, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -4102.51, -4971.41, 6544.44, 0, 0, 0, 0, 100, 0),
(@PATH, 1, -4097.79, -4974.27, 6543.84, 0, 0, 0, 0, 100, 0),
(@PATH, 0, -4095.76, -4976.69, 6543.53, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= -4095.76, `position_y`= -4976.688, `position_z`= 6543.528, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+13;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+13, @PATH, 1);

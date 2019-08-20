-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN(51210);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 51210, 0, 0, 29, 0, 28256, 20, 0, 1, 0, 0, '', 'Use Soo-rahms Incense if no Voice of Nozronn is spawned');

UPDATE `smart_scripts` SET `target_type`=23, `target_param1`=0  WHERE `entryorguid` IN (2825600) AND `source_type`=9;

DELETE FROM `event_scripts` WHERE `id`=18481;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(18481, 0, 10, 28256, 30000, 0, 5211.89, 5788.68, -71.0877, 2.1648),
(18481, 1, 10, 28230, 30000, 0, 5219.113, 5779.453, -71.0571, 4.520403),
(18481, 1, 10, 28230, 30000, 0, 5225.277, 5777.674, -67.50936, 5.06145),
(18481, 1, 10, 28230, 30000, 0, 5215.021, 5777.659, -71.13335, 3.75245),
(18481, 1, 10, 28230, 30000, 0, 5220.024, 5771.545, -68.32261, 5.16617),
(18481, 1, 10, 28230, 30000, 0, 5214.409, 5784.443, -62.01576, 0.59341),
(18481, 1, 10, 28230, 30000, 0, 5208.637, 5778.08, -63.04353, 2.565634),
(18481, 0, 9, 9263, 30, 0, 0, 0, 0, 0),
(18481, 1, 15, 39983, 1, 0, 0, 0, 0, 0),
(18481, 1, 10, 28279, 30000, 0, 5240.073, 5784.477, -63.67311, 3.76355),
(18481, 1, 10, 28279, 30000, 0, 5243.024, 5777.95, -65.759511, 2.06222),
(18481, 1, 10, 28279, 30000, 0, 5259.322, 5767.997, -63.73461, 2.75762),
(18481, 1, 10, 28279, 30000, 0, 5242.078, 5740.667, -59.98921, 4.18879),
(18481, 1, 10, 28279, 30000, 0, 5249.261, 5765.971, -59.90691, 6.17846),
(18481, 1, 10, 28279, 30000, 0, 5197.423, 5776.377, -70.25041, 2.09439),
(18481, 1, 10, 28279, 30000, 0, 5207.380, 5800.154, -67.02731, 3.82227),
(18481, 1, 10, 28279, 30000, 0, 5206.194, 5754.944, -71.61551, 2.87979),
(18481, 1, 10, 28279, 30000, 0, 5204.702, 5791.856, -68.11948, 1.62315),
(18481, 1, 10, 28279, 30000, 0, 5214.361, 5743.659, -73.36909, 4.29351),
(18481, 1, 10, 28279, 30000, 0, 5232.818, 5750.225, -63.93412, 3.96189),
(18481, 1, 10, 28279, 30000, 0, 5242.865, 5777.236, -65.67616, 2.42600),
(18481, 1, 10, 28279, 30000, 0, 5232.510, 5731.526, -68.76761, 4.76474),
(18481, 1, 10, 28279, 30000, 0, 5206.439, 5767.634, -68.19739, 3.82227),
(18481, 1, 10, 28279, 30000, 0, 5254.312, 5781.611, -67.96659, 3.42084),
(18481, 1, 10, 28279, 30000, 0, 5223.679, 5794.549, -64.10463, 5.95157),
(18481, 1, 10, 28279, 30000, 0, 5232.002, 5790.667, -68.25787, 1.51843),
(18481, 1, 10, 28279, 30000, 0, 5240.936, 5786.487, -63.58977, 1.22173),
(18481, 1, 10, 28279, 30000, 0, 5198.979, 5768.557, -70.70884, 0.43633),
(18481, 1, 10, 28279, 30000, 0, 5230.022, 5771.104, -56.96051, 1.71042),
(18481, 1, 10, 28279, 30000, 0, 5199.837, 5789.268, -62.45123, 2.77507),
(18481, 1, 10, 28279, 30000, 0, 5215.567, 5799.322, -68.99142, 3.19395),
(18481, 1, 10, 28279, 30000, 0, 5221.603, 5749.741, -63.75953, 3.54301);

UPDATE `creature_template_addon` SET `auras`="46679"WHERE `entry` IN (28230);

DELETE FROM `gameobject` WHERE `guid`=9263 AND `id`=188443;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(9263,188443,571,1,1,5210.02002, 5790.8901, -71.384499,-3.089183,0,0,-0.9996567,0.02620165,-1,255,1);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28279;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28279 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2827900,2827901,2827902,2827903) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28279, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 88, 2827900, 2827903, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - On Just summoned - Random Action list'),
(2827900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33343, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - On Just summoned - Cast spell'),
(2827901, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 33344, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - On Just summoned - Cast spell'),
(2827902, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 32566, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - On Just summoned - Cast spell'),
(2827903, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 35709, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - On Just summoned - Cast spell'),
(28279, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - On Just summoned - Random movement'),
(28279, 0, 2, 0, 1, 0, 100, 1, 5000, 25000, 0, 0, 29, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - Ooc - Move to summoner'),
(28279, 0, 3, 0, 34, 0, 100, 0, 14, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sholazar Witch Light - On movement informer - despawn');

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 28279;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(28279, 0, 0, 1, 0);

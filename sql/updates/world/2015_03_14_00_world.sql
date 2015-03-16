SET @CGUID  := 76001;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=177746;
UPDATE `gameobject` SET `position_x`=-2288.696777, `position_y`=1345.580078, `position_z`=66.123787 WHERE `guid`=99892;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (11560);
DELETE FROM `creature_template_addon` WHERE `entry`=11560;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES 
(11560,1,17327);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11560, 1156000, 177746, 17774600);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(177746, 1, 0, 0, 1, 0, 100, 1, 6000, 6000, 6000, 6000, 50, 177749, 180000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghost Magnet - OOC no repeat - Summon gob'), -- A gob cannot summon a gob
(177746, 1, 1, 0, 1, 0, 100, 0, 6000, 6000, 6000, 6000, 45, 0, 1, 0, 0, 0, 0, 19, 11560, 70, 0, 0, 0, 0, 0, 'Ghost Magnet - ActionList - Set data 0'),
(11560, 0, 0, 1, 38, 0, 100, 1, 0, 1, 0, 0, 28, 34426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - On dataset 0 1 - remove aura'),
(11560, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 80, 1156000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - on link - Start script'),
(1156000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - On script - Set run off'),
(1156000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 20, 177746, 70, 0, 0, 0, 0, 0, 'Magrami Spectre - On script - move to pos'),
(1156000, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - On script - ATTACK'),
(11560, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 70000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - On Link - Despawn'),
(11560, 0, 2, 3, 25, 0, 100, 1, 0, 0, 0, 0, 11, 34426, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - on Reset - add aura'),
(11560, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17327, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - on Reset - add aura'),
(11560, 0, 4, 0, 0, 0, 100, 1, 5000, 5000, 0, 0, 11, 18159, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - on script - add aura'),
(11560, 0, 5, 0, 0, 0, 100, 0, 2000, 2000, 7000, 7000, 11, 12531, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Magrami Spectre - on script - add aura');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 11560, 1, 1, 1,  -2254.859, 1330.685, 63.67144, 5.253441, 120, 0, 0),
(@CGUID+1, 11560, 1, 1, 1,  -2288.117, 1333.648, 63.67144, 5.427974, 120, 0, 0),
(@CGUID+2, 11560, 1, 1, 1,  -2317.772, 1378.803, 63.67144, 2.548181, 120, 0, 0),
(@CGUID+3, 11560, 1, 1, 1,  -2245.802, 1315.414, 63.67144, 3.176499, 120, 0, 0),
(@CGUID+4, 11560, 1, 1, 1,  -2276.162, 1328.752, 63.82001, 5.811946, 120, 0, 0),
(@CGUID+5, 11560, 1, 1, 1,  -2281.066, 1339.434, 63.67144, 2.426008, 120, 0, 0),
(@CGUID+6, 11560, 1, 1, 1,  -2265.949, 1334.62, 63.67144, 3.874631, 120, 0, 0),
(@CGUID+7, 11560, 1, 1, 1,  -2266.548, 1308.922, 64.06808, 2.09432, 120, 0, 0),
(@CGUID+8, 11560, 1, 1, 1,  -2275.962, 1315.779, 63.94889, 5.846853, 120, 0, 0),
(@CGUID+9, 11560, 1, 1, 1,  -2285.754, 1323.675, 63.68898, 5.707227, 120, 0, 0),
(@CGUID+10, 11560, 1, 1, 1,  -2311.181, 1387.165, 63.67143, 4.39823, 120, 0, 0),
(@CGUID+11, 11560, 1, 1, 1,  -2255.519, 1311.52, 63.72472, 5.969026, 120, 0, 0),
(@CGUID+12, 11560, 1, 1, 1,  -2292.626, 1380.353, 63.68015, 3.001966, 120, 0, 0),
(@CGUID+13, 11560, 1, 1, 1,  -2309.959, 1347.675, 63.67144, 1.216367, 120, 0, 0),
(@CGUID+14, 11560, 1, 1, 1,  -2295.897, 1361.538, 63.6894, 2.80998, 120, 0, 0),
(@CGUID+15, 11560, 1, 1, 1,  -2305.648, 1359.731, 63.69492, 4.485496, 120, 0, 0),
(@CGUID+16, 11560, 1, 1, 1,  -2256.498, 1321.57, 63.67144, 5.148721, 120, 0, 0);

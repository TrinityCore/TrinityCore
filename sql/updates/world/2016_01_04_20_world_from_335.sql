-- 
DELETE FROM `event_scripts` WHERE `id` IN (21075,21077,21076);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
-- summon corpes
(21075, 0, 10, 33455, 20000, 0, 8441.057, 452.919, 596.070, 1.643),
(21077, 0, 10, 33439, 20000, 0, 8461.75, 468.926, 596.072, 4.6392),
(21076, 0, 10, 33457, 20000, 0, 8471.463,452.336,596.071,4.710),
-- respawn sword and despawn after 20s
(21076, 0, 9, 67923, 20, 0, 0, 0, 0, 0);

-- set visual dead
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|32, `unit_flags2`=`unit_flags2`|1 WHERE `entry` IN (33439,33455,33457);

-- sword despawn after 20s
UPDATE `gameobject` SET `spawntimesecs`=-20 WHERE  `guid`=67923 LIMIT 1;

DELETE FROM `creature_template_addon` WHERE `entry` IN (33455,33439);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES 
-- posion dummy
(33455, '41290'),
-- burning dummy
(33439, '59216');

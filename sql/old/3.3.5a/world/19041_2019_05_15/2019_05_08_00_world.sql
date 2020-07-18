-- 
UPDATE `smart_scripts`  SET `action_type`=41, `action_param1`=0 WHERE `entryorguid` IN (28330) AND `source_type`=0 AND `id` IN (1);
DELETE FROM `gameobject` WHERE `guid` IN (8954, 8955, 8960, 8961, 8962, 8974);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(8954, 190550, 571, 1, 1, 4774.60, -3146.78, 293.953, 4.88692, 0, 0, 0.675588, -0.737279, 120, 255, 1),
(8955, 190550, 571, 1, 1, 4811.37, -3122.26, 290.908, 3.78736, 0, 0, 0.675588, -0.737279, 120, 255, 1),
(8960, 190550, 571, 1, 1, 4833.34, -3086.81, 290.733, 5.18363, 0, 0, 0.675588, -0.737279, 120, 255, 1),
(8961, 190550, 571, 1, 1, 4834.68, -3024.52, 290.973, 5.77704, 0, 0, 0.675588, -0.737279, 120, 255, 1),
(8962, 190550, 571, 1, 1, 4867.05, -3032.32, 290.277, 0.01745, 0, 0, 0.675588, -0.737279, 120, 255, 1),
(8974, 190550, 571, 1, 1, 4884.58, -2949.40, 291.464, 6.24828, 0, 0, 0.675588, -0.737279, 120, 255, 1);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (28342,28345,28221);
DELETE FROM `smart_scripts`   WHERE `entryorguid` IN (28342,28345,28221) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28342, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, "Trapdoor Ambusher - On Just summoned - Attack"),
(28342, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 7000, 9000, 11, 21067, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Trapdoor Ambusher - IC - Cast Poison Bolt"),
(28345, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, "Drakkari Spirit - On Just summoned - Attack"),
(28221, 0, 1, 0, 0, 0, 100, 0, 2000, 3000, 7000, 9000, 11, 11918, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Trapdoor Crawler - IC - Cast Poison Bolt");

-- 
DELETE FROM `gameobject` WHERE `id`=20920;
DELETE FROM `gameobject_addon` WHERE `guid` IN (56185, 56186, 56187, 56188, 56189, 56190, 56191, 56192, 56193, 56194, 56195, 56196, 56197, 56198, 56199);
UPDATE `gameobject_template` SET `AIName`="" WHERE `entry`=20920;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4781 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (478100,478101) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=20920 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4781, 0, 0, 1, 54, 0, 100, 512, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - On Just Summoned - Say Line 0"),
(4781, 0, 1, 2, 61, 0, 100, 512, 0, 0, 0, 0, 29, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - On Just Summoned - Follow Summoner"),
(4781, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - On Just Summoned - React passif"),
(4781, 0, 3, 0, 8, 0, 100, 512, 8283, 0, 10000, 10000, 80, 478100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - On spell hit - Run Script"),
(478100, 9, 0, 0, 0, 0, 100, 512, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - Action list - Say Line 1"),
(478100, 9, 1, 0, 0, 0, 100, 512, 2000, 2000, 0, 0, 69, 1, 0, 0, 1, 0, 0, 20, 20919, 40, 0, 0, 0, 0, 0, "Snufflenose Gopher - Action list - Move to Blueleaf Tuber"),
(4781, 0, 4, 0, 34, 0, 100, 512, 0, 1, 0, 0, 80, 478101, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - On movement informer - Run Script"),
(478101, 9, 0, 0, 0, 0, 100, 512, 2000, 2000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - Action list - Say Line 2"),
(478101, 9, 1, 0, 0, 0, 100, 512, 0, 0, 0, 0, 11, 6900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - Action list - Cast spell to summon gob"),
(478101, 9, 2, 0, 0, 0, 100, 512, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 20, 20919, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - Action list - Despawn gob"),
(478101, 9, 3, 0, 0, 0, 100, 512, 2000, 2000, 0, 0, 29, 1, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Snufflenose Gopher - Action list - Follow Summoner");

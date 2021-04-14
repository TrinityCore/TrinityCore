--
/*
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(17111,17112,17113);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17111,17112,17113);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17111, 0, 0, 0, 8,  0, 100, 0, 29916, 0, 0, 0, 33, 17111   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Jaguar - On Spellhit - Kill Credit'),
(17112, 0, 0, 0, 8,  0, 100, 0, 29916, 0, 0, 0, 33, 17112   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Tarantula - On Spellhit - Kill Credit'),
(17113, 0, 0, 0, 8,  0, 100, 0, 29916, 0, 0, 0, 33, 17113   , 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Captive Crocolisk - On Spellhit - Kill Credit');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`IN (29916,29917);
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,29917,64,'Ignore LOS on Feed Captured Animal'),
(0,29916,64,'Ignore LOS on Feed Captured Animal');
*/

-- Players spells. Also fixes wrong target type
UPDATE `smart_scripts` SET `action_param2` = 2, `target_type` = 2 WHERE `source_type` = 0 AND `action_type` = 11 AND `action_param1` IN (53,2589,2590,2591,8721);
-- Non-player versions works well without triggered flag
UPDATE `smart_scripts` SET `action_param2` = 0 WHERE `source_type` = 0 AND `action_type` = 11 AND `action_param1` IN (7159,15657) AND `action_param2` = 2;
-- Range event
UPDATE `smart_scripts` SET `event_type` = 0, `event_param1` = 5000, `event_param2` = 5000 WHERE `source_type` = 0 AND `action_type` = 11 AND `action_param1` IN (2590,7159,8721,15582,15657) AND `event_type` = 9;
-- On Behind Target
UPDATE `smart_scripts` SET `event_type` = 0, `event_param3` = 6000, `event_param4` = 9000 WHERE `source_type` = 0 AND `action_type` = 11 AND `action_param1` IN (53,2589,7159,15657,30992,37685,71410) AND `event_type` = 67 AND `event_param3` = 0 AND `event_param4` = 0;
-- Unique cases
UPDATE `smart_scripts` SET `event_type` = 0 WHERE `entryorguid` = 95 AND `source_type` = 0 AND `action_type` = 11 AND `action_param1` = 53;
UPDATE `smart_scripts` SET `event_type` = 0, `event_flags` = 0, `event_param1` = 6000, `event_param2` = 8500 WHERE `entryorguid` IN (3530,3531) AND `source_type` = 0 AND `action_type` = 11 AND `action_param1` = 15657;

DELETE FROM `spell_custom_attr` WHERE `entry` IN (30992,34614,52540,58471,63754,71410);
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(30992,131072),
(34614,131072),
(52540,131072),
(58471,131072),
(63754,131072),
(71410,131072);

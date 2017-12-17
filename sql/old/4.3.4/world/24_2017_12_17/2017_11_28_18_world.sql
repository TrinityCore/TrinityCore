--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-95560) AND `source_type` IN (0) AND id=7;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25636) AND `source_type` IN (0) AND id=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-95560, 0, 7, 0, 40, 0, 100, 0, 3, 0, 0, 0, 2, 1692, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Riplash Myrmidon - On WP 4 Reached - set faction"),
(25636, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 2, 2047, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Captured Tuskarr Prisoner - On reset - set faction");

UPDATE `smart_scripts` SET `action_param2`=1 WHERE `entryorguid`=11216 AND `action_type`=7;

UPDATE `creature_template` SET `minlevel` = 71 WHERE `entry` = 19523;

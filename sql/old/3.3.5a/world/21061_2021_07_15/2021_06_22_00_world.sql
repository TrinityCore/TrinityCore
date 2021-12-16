--
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 253 AND `source_type` = 0 AND `id` = 0 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 2921 AND `source_type` = 0 AND `id` = 0 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 7790 AND `source_type` = 0 AND `id` = 0 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 7853 AND `source_type` = 0 AND `id` = 0 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 15491 AND `source_type` = 0 AND `id` = 8 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 15491 AND `source_type` = 0 AND `id` = 9 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 27199 AND `source_type` = 0 AND `id` = 1 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 27199 AND `source_type` = 0 AND `id` = 3 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 28308 AND `source_type` = 0 AND `id` = 0 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 29261 AND `source_type` = 0 AND `action_type` = 80;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 33522 AND `source_type` = 0 AND `id` = 0 AND `action_type` = 80;

UPDATE `smart_scripts` SET `event_param1` = 5000, `event_param3` = 1, `event_param4` = 0 WHERE `entryorguid` = 17826 AND `source_type` = 0 AND `id` = 10 AND `event_type` = 5;
UPDATE `smart_scripts` SET `action_param1` = 0 WHERE `entryorguid` = 1835100 AND `source_type` = 9 AND `id` = 3 AND `action_type` = 20;
UPDATE `smart_scripts` SET `action_param3` = 0 WHERE `entryorguid` = 2628700 AND `source_type` = 9 AND `id` = 1 AND `action_type` = 53;
UPDATE `smart_scripts` SET `action_param1` = 0, `action_param2` = 0, `action_param3` = 0 WHERE `entryorguid` BETWEEN 3113500 AND 3113505 AND `source_type` = 9 AND `id` = 0 AND `action_type` = 69;
-- No idea what was initial intention, test your scripts.
UPDATE `smart_scripts` SET `target_type` = 19 WHERE `entryorguid` = 12939100 AND `source_type` = 9 AND `id` = 11 AND `action_type` = 1;

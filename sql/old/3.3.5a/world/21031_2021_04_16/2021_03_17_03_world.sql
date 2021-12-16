--
UPDATE `smart_scripts` SET `event_param1` = 4000, `event_param2` = 12000, `event_param3` = 16000, `event_param4` = 24000, `action_param1` = 744, `action_param2` = 32, `comment` = "Muckshell Snapclaw - In Combat - Cast 'Poison'" WHERE `entryorguid` = 4402 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature` SET `wander_distance` = 5, `MovementType` = 1 WHERE `id` = 4402;

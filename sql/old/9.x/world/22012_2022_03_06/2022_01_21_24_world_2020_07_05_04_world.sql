-- 
UPDATE `smart_scripts` SET `event_param2` = 0 WHERE `entryorguid` = 24137 AND `source_type` = 0 AND `event_type` = 61;
UPDATE `smart_scripts` SET `event_flags` = `event_flags` &~ 1 WHERE `event_type` = 11;
